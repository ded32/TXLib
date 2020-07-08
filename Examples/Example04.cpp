//{=========================================================================== 
//! @file       Examples\Example04.cpp
//!
//! @brief      Пример с функциями с параметрами, после рефакторинга примера 3.
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:51:05 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include "TXLib.h"

//----------------------------------------------------------------------------

void DrawMan    (int x, int y, int sizeX, int sizeY, COLORREF color,
                 double hand = 0, double legs = 0, double head = 0, double twist = 0);
void DrawEarth  (int x, int y, int sizeX, int sizeY, COLORREF color);
void DrawFlag   (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor);
void DrawHello  (int x, int y, const char* text, int size, COLORREF color);
void DrawFrame  (int sizeX, int sizeY, int size, COLORREF color);

//----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);

    DrawFrame (800, 600, 10, TX_WHITE);
    DrawHello (400, 480, "Hello, world!", 60, TX_LIGHTGREEN);

    DrawEarth (400, 300, 400, 300, TX_LIGHTCYAN);

    DrawFlag  (400, 150, 50, 75, TX_YELLOW, TX_TRANSPARENT);
    DrawMan   (385, 150, 20, 40, TX_YELLOW, 0, 0, 0);

    txTextCursor (false);
    return 0;
    }

//----------------------------------------------------------------------------

void DrawMan   (int x, int y, int sizeX, int sizeY, COLORREF color,
                double hand, double legs, double head, double twist)
    {
    txSetColor     (color);
    txSetFillColor (color);

    txLine (x, y - (0.35 + twist) * sizeY, x, y - 0.7*sizeY);

    txLine (x, y - (0.35 + twist) * sizeY, x - (0.5 + legs) * sizeX, y);
    txLine (x, y - (0.35 + twist) * sizeY, x + (0.5 + legs) * sizeX, y);

    txLine (x, y - 0.65*sizeY, x - sizeX/2,   y - 0.4*sizeY);
    txLine (x, y - 0.65*sizeY, x + sizeX/1.2, y - (0.7 + hand) * sizeY);

    txCircle (x, y - sizeY + (0.3 + head) * sizeX, 0.3*sizeX);
    }

//----------------------------------------------------------------------------

void DrawEarth (int x, int y, int sizeX, int sizeY, COLORREF color)
    {
    txSetColor (color);

    int r = sizeX/2;
    while (r >= 0)
        {
        txEllipse (x-r, y-sizeY/2, x+r, y+sizeY/2);
        r -= sizeX/9;
        }

    r = sizeY/2;
    while (r >= 0)
        {
        txEllipse (x-sizeX/2, y-r, x+sizeX/2, y+r);
        r -= sizeY/6;
        }

    txLine (x - sizeX/2, y, x + sizeX/2, y);
    }

//----------------------------------------------------------------------------

void DrawFlag (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor)
    {
    txSetColor     (color);
    txSetFillColor (bkColor);

    txLine      (x, y, x, y - sizeY);
    txRectangle (x, y - sizeY/2, x + sizeX, y - sizeY);
    
    txSelectFont ("Times New Roman", 20);
    txTextOut (x + sizeX/2, y - sizeY*7/8, "C++");
    }

//----------------------------------------------------------------------------

void DrawHello (int x, int y, const char* text, int size, COLORREF color)
    {
    txSetColor (color);

    txSelectFont ("Times New Roman", size);
    txSetTextAlign (TA_CENTER);
    
    txTextOut (x, y, text);
    }

//----------------------------------------------------------------------------

void DrawFrame (int sizeX, int sizeY, int size, COLORREF color)
    {
    txSetColor (color);
    txSetFillColor (TX_TRANSPARENT);
    
    txRectangle (size, size, sizeX-size, sizeY-size);
    }





