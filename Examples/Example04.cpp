//{===========================================================================
//! @file       Examples\Example04.cpp
//              Пример с функциями с параметрами, после рефакторинга примера 3
//!
//! @brief      Пример с функциями с параметрами, после рефакторинга примера 3
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @version    [Version 0.01 alpha, build 72]
//! @author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)
//! @date       2005
//}===========================================================================

#include "TXLib.h"

//----------------------------------------------------------------------------

void DrawMan    (int x, int y, int sizeX, int sizeY, COLORREF color,
                 double hand = 0, double legs = 0, double head = 0, double twist = 0);
void DrawEarth  (int x, int y, int sizeX, int sizeY, COLORREF color);
void DrawFlag   (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor);
void DrawHello  (int x, int y, const char* text, int size, COLORREF color);
void DrawFrame  (int sizeX, int sizeY, int size, COLORREF color);
void DrawLine   (double x0, double y0, double x1, double y1);
void DrawCircle (double x, double y, double r);

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

    DrawLine (x, y - (int)(0.35 + twist) * sizeY, x, y - (int)(0.7*sizeY));

    DrawLine (x, y - (int)(0.35 + twist) * sizeY, x - (int)(0.5 + legs) * sizeX, y);
    DrawLine (x, y - (int)(0.35 + twist) * sizeY, x + (0.5 + legs) * sizeX, y);

    DrawLine (x, y - (int)0.65*sizeY, x - sizeX/2,   y - 0.4*sizeY);
    DrawLine (x, y - (int)0.65*sizeY, x + sizeX/1.2, y - (0.7 + hand) * sizeY);

    DrawCircle (x, y - sizeY + (0.3 + head) * sizeX, 0.3*sizeX);
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

    DrawLine (x - sizeX/2, y, x + sizeX/2, y);
    }

//----------------------------------------------------------------------------

void DrawFlag (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor)
    {
    txSetColor     (color);
    txSetFillColor (bkColor);
    DrawLine    (x, y, x, y - sizeY);
    txRectangle (x, y - sizeY/2, x + sizeX, y - sizeY);
    txSelectFont ("Times", 20);
    txTextOut (x + sizeX/2, y - sizeY*7/8, "C++");
    }

//----------------------------------------------------------------------------

void DrawHello (int x, int y, const char* text, int size, COLORREF color)
    {
    txSetColor (color);
    txSelectFont ("Times", size);
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

//----------------------------------------------------------------------------

void DrawLine (double x0, double y0, double x1, double y1)
    {
    txLine ((int) (x0 + 0.5), (int) (y0 + 0.5), (int) (x1 + 0.5), (int) (y1 + 0.5));
    }

//----------------------------------------------------------------------------

void DrawCircle (double x, double y, double r)
    {
    txCircle ((int) (x + 0.5), (int) (y + 0.5), (int) (r + 0.5));
    }
