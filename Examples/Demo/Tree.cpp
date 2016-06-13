//{=========================================================================== 
//! @file       Examples\Demo\Tree.cpp
//!
//! @brief      Этюд "Дерево"
//!
//! @date       2010
//! @author     Кирилл Кулешов, 7 класс
//          (C) Кирилл Кулешов, 7 класс, 2010
//}===========================================================================

#include "TXLib.h"

//----------------------------------------------------------------------------

void DrawTree (double x, double y, double length, double angle);
double Random (double min, double max);

//----------------------------------------------------------------------------

int main ()
    {
    txCreateWindow (800, 600);
    txBegin();

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear();

        DrawTree (400, 0, 100, txPI/2);

        txSleep (100);
        }

    txEnd();
    return 0;
    }

//----------------------------------------------------------------------------

void DrawTree (double x, double y, double length, double angle)
    {
    if (length <= 0) return;

    double wind = 0;
    int  height = 0;

    if (GetAsyncKeyState (VK_LEFT))  wind   =               +0.2;
    if (GetAsyncKeyState (VK_RIGHT)) wind   =               -0.2;
    if (GetAsyncKeyState (VK_SHIFT)) wind   = Random (-0.7, +0.7);
    if (GetAsyncKeyState (VK_UP))    height =               +5;
    if (GetAsyncKeyState (VK_DOWN))  height =               -5;

    double leaves = 0;
    if (height ==  0) leaves = 20;
    if (height ==  5) leaves = 25;
    if (height == -5) leaves = 15;

    txSetColor ((length > leaves)? RGB (115, 65, 10) : RGB (35, 255, 10),
                (int) (pow (length/7, 0.9) + 0.5));

    // Here comes the tree
                
    double x1 = x + length * cos (angle),
           y1 = y + length * sin (angle);

    txLine (x, 600 - y, x1, 600 - y1);

    DrawTree (x1, y1, length - 10 + Random (-1, +1) + height, angle + 0.35 + Random (-0.2, +0.2) + wind);
    DrawTree (x1, y1, length - 10                           , angle - 0.35 - Random (-0.2, +0.2) + wind);
    }

//----------------------------------------------------------------------------

inline double Random (double min, double max)
    {
    return min + (max - min) * rand() / RAND_MAX;
    }
