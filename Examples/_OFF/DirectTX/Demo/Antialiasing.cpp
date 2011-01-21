//{===========================================================================
//           ���������� DirectTX - Demo/Antialiasing.cpp
//           Copyright (C) Nikita Uvarov, 7 �����
//}===========================================================================

/**\file     Demo/Antialiasing.cpp
 *
 * \brief    ������ ��� DirectTX - Antialiasing Demo
 *
 * \version  [v 0.2]
 *
 * \author   Copyright (C) Nikita Uvarov, 7 �����
 * \date     2009
 */

#include "..\DirectTX.cpp"

const int Size = 300;

DirectTXColor Palette [Size]        = {};
unsigned char Plasma  [Size] [Size] = {};

void FillPalette()
    {
    for (int i = 0; i < Size; i++)
        Palette [i] = DirectTXColor (i, 0, 0);
    }

float Dist (float x0, float y0, float x1, float y1)
    {
    return sqrt ((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
    }

void DrawPlasma()
    {
    static int t = 0;
    t++;

    for (int y = 0; y < Size; y++)
    for (int x = 0; x < Size; x++)
        {
        DirectTXColor c = Palette [(int) (sin (Dist (x, y, Size/2, Size/2) + t) * 128.0) + 127];

        DirectTXPutPixel (x, y, c);
        }
    }

int main()
    {
    DirectTXCreateWindow (Size, Size, "DirectTX Demo... [Esc] to exit");

    FillPalette();

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        DirectTXBegin();

        DrawPlasma();

        DirectTXFlush();
        DirectTXEnd();
        }
    }
