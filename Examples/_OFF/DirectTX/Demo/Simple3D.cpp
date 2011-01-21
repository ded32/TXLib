//{===========================================================================
//           Библиотека DirectTX - Demo/Simple3D.cpp
//           Copyright (C) Nikita Uvarov, 7 класс
//}===========================================================================

/**\file     Demo/Simple3D.cpp
 *
 * \brief    Пример для DirectTX - Simple 3D
 *
 * \version  [v 0.2]
 *
 * \author   Copyright (C) Nikita Uvarov, 7 класс
 * \date     2009
 */

#include "..\DirectTX.cpp"

const int Size     = 300;
      int Distance = 100;

struct Point
    {
    float x, y;

    Point() :
        x (0),
        y (0)
        {}

    Point (float xx, float yy) :
        x (xx),
        y (yy)
        {}

    Point operator + (Point p)
        {
        return Point (x + p.x, y + p.y);
        }

    Point operator - (Point p)
        {
        return Point (x - p.x, y - p.y);
        }

    POINT GetPOINT()
        {
        POINT p = { (LONG) x, (LONG) y };
        return p;
        }
    };

struct Vector
    {
    float x, y, z;

    Vector() :
        x (0),
        y (0),
        z (0)
        {}

    Vector (float xx, float yy, float zz) :
        x (xx),
        y (yy),
        z (zz)
        {}

    Vector operator + (Vector v)
        {
        return Vector (x + v.x, y + v.y, z + v.z);
        }

    Vector operator - (Vector v)
        {
        return Vector (x - v.x, y - v.y, z - v.z);
        }
    };

Point VectorToPoint (Vector v)
    {
    return Point (txGetExtentX () / 2 + v.x * Distance / (v.z + Distance),
                  txGetExtentY () / 2 + v.y * Distance / (v.z + Distance));
    }

void Set3DPixel (Vector v, DirectTXColor c)
    {
    Point p = VectorToPoint (v);

    DirectTXPutPixel ((int)p.x, (int)p.y, c);
    }

void Set3DLine (Vector v1, Vector v2)
    {
    Point p1 = VectorToPoint (v1);
    Point p2 = VectorToPoint (v2);

    DirectTXDrawLine ((int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
    }

#define FORMULA  ( sin (x + z / t) * (x + z - t) )

int main ()
    {
    DirectTXCreateWindow (Size, Size, "3D for noobs... [Esc] to exit");

    DirectTXSetFillColor (TX_BLACK);

    for (double t = 0; !GetAsyncKeyState (VK_ESCAPE); )
        {
        DirectTXBegin();
        DirectTXDrawRectangle (0, 0, Size, Size);
        t++;

        float lastX = -Size/2, lastZ = 0;

        for (float x = -Size/2; x < Size/2;   x += GetAsyncKeyState (VK_SPACE)?  1 : 10)
        for (float z =       0; z < Distance; z += GetAsyncKeyState (VK_SPACE)? 10 : 1 )
            {
            DirectTXSetColor (RGB (0, 255, 0));
            Set3DLine (Vector (lastX, FORMULA + 100, lastZ),
                       Vector (x,     FORMULA + 100, z));
            lastX = x;
            lastZ = z;
            }

        t++;
        DirectTXFlush();
        DirectTXDrawFPS (true);
        DirectTXEnd();
        }
    }
