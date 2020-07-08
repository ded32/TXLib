//{=========================================================================== 
//! @file       Examples\Example05.cpp
//!
//! @brief      Пример с циклами.
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:51:06 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include <conio.h>
#include "TXLib.h"

//----------------------------------------------------------------------------

void JumpMan     (int x, int y, int sizeX, int sizeY, double jump,
                  COLORREF color, COLORREF bkColor, int jumps, int delay);

void MoveMan     (int fromX, int fromY, int toX, int toY,
                  int sizeX, int sizeY, COLORREF color, COLORREF bkColor,
                  int time, int steps);

void DrawMan     (int x, int y, int sizeX, int sizeY, COLORREF color,
                  double hand = 0, double legs = 0, double head = 0, double twist = 0);

void AppearEarth (int x, int y, int sizeX, int sizeY, COLORREF from, COLORREF to,
                  int time, int steps);

void DrawEarth   (int x, int y, int sizeX, int sizeY, COLORREF color);

void AppearText  (int x, int y, const char* text, COLORREF from, COLORREF to,
                  int time, int steps);

void DrawHello   (int x, int y, const char* text, int size, COLORREF color);

void UnwindFlag  (int x, int y, int fromSizeX, int toSizeX, int sizeY,
                  COLORREF color, COLORREF bkColor, int time, int steps);

void DrawFlag    (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor);

void DrawFrame   (int sizeX, int sizeY, int size, COLORREF color);

//----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);
    txTextCursor (false);

    DrawFrame (800, 600, 10, TX_WHITE);

    txSelectFont ("Times New Roman", 60);
    txSetTextAlign (TA_CENTER);

    AppearText  (400, 480, "Hello, world!", TX_BLACK, TX_LIGHTGREEN, 5000, 100);
    AppearEarth (400, 300, 400, 300,        TX_BLACK, TX_LIGHTCYAN,  5000, 100);

    MoveMan    (20, 150, 385, 150, 20, 40,  TX_YELLOW, TX_BLACK,     3000, 100);
    JumpMan    (385, 150, 20, 40, 0.25,     TX_YELLOW, TX_BLACK,       10, 100);
    UnwindFlag (400, 150, 0, 40, 60,        TX_YELLOW, TX_BLACK,      500, 100);

    return 0;
    }

//----------------------------------------------------------------------------

void JumpMan (int x, int y, int sizeX, int sizeY, double jump,
              COLORREF color, COLORREF bkColor, int jumps, int delay)
    {
    DrawMan (x, y, sizeX, sizeY, TX_BLACK, 0, 0, 0, 0);

    txBegin();

    int i = 0;
    while (i < jumps)
        {
        DrawMan (x, y - (int)(i%2 * jump*10), sizeX, sizeY, color,
                (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, 0);

        txSleep (delay);

        DrawMan (x, y - (int)(i%2 * jump*10), sizeX, sizeY, bkColor,
                (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, 0);
        i++;
        }

    DrawMan (x, y - (int)(jumps%2 * jump*10), sizeX, sizeY, color,
            (jumps%2-0.5) * jump/3, 0, (jumps%2-0.5) * -jump/3, 0);

    txEnd();
    }

//----------------------------------------------------------------------------

void MoveMan (int fromX, int fromY, int toX, int toY,
              int sizeX, int sizeY, COLORREF color, COLORREF bkColor,
              int time, int steps)
    {
    txBegin();

    int i = 0;
    while (i <= steps)
        {
        int x = fromX + (toX - fromX) * i/steps,
            y = fromY + (toY - fromY) * i/steps;

        DrawMan (x, y - i%6, sizeX, sizeY, color,   i%3*0.02, i%3*-0.1, i%3*0.1, 0);

        txSleep (time / steps);

        DrawMan (x, y - i%6, sizeX, sizeY, bkColor, i%3*0.02, i%3*-0.1, i%3*0.1, 0);
        i++;
        }

    DrawMan (toX, toY, sizeX, sizeY, color, 0, 0, 0);

    txEnd();
    }

//----------------------------------------------------------------------------

void UnwindFlag (int x, int y, int fromSizeX, int toSizeX, int sizeY,
                 COLORREF color, COLORREF bkColor, int time, int steps)
    {
    txBegin();

    int i = 0;
    while (i <= steps)
        {
        int sizeX = fromSizeX + (toSizeX - fromSizeX) * i/steps;

        DrawFlag (x, y, sizeX, sizeY, color,   bkColor);

        txSleep  (time / steps);

        DrawFlag (x, y, sizeX, sizeY, bkColor, bkColor);
        i++;
        }

    DrawFlag (x, y, toSizeX, sizeY, color, bkColor);

    txEnd();
    }

//----------------------------------------------------------------------------

void DrawMan (int x, int y, int sizeX, int sizeY, COLORREF color,
              double hand, double legs, double head, double twist)
    {
    txSetColor     (color);
    txSetFillColor (color);

    txLine (x + twist*sizeX, y - 0.35*sizeY, x, y - 0.7*sizeY);

    txLine (x + twist*sizeX, y - 0.35*sizeY, x - (0.5 + legs) * sizeX, y);
    txLine (x + twist*sizeX, y - 0.35*sizeY, x + (0.5 + legs) * sizeX, y);

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

void AppearEarth (int x, int y, int sizeX, int sizeY, COLORREF from, COLORREF to,
                  int time, int steps)
    {
    int r0 = txExtractColor (from, TX_RED),   r1 = txExtractColor (to, TX_RED),
        g0 = txExtractColor (from, TX_GREEN), g1 = txExtractColor (to, TX_GREEN),
        b0 = txExtractColor (from, TX_BLUE),  b1 = txExtractColor (to, TX_BLUE);

    int i = 0;
    while (i <= steps)
        {
        int r = r0 + (r1 - r0) * i/steps,
            g = g0 + (g1 - g0) * i/steps,
            b = b0 + (b1 - b0) * i/steps;

        DrawEarth (x, y, sizeX, sizeY, RGB (r, g, b));

        Sleep (time / steps);
        i++;
        }
    }

//----------------------------------------------------------------------------

void AppearText (int x, int y, const char* text, COLORREF from, COLORREF to,
                 int time, int steps)
    {
     int r0 = txExtractColor (from, TX_RED),   r1 = txExtractColor (to, TX_RED),
         g0 = txExtractColor (from, TX_GREEN), g1 = txExtractColor (to, TX_GREEN),
         b0 = txExtractColor (from, TX_BLUE),  b1 = txExtractColor (to, TX_BLUE);

    for (int i = 0; i <= steps; i++)
        {
        int r = r0 + (r1 - r0) * i/steps,
            g = g0 + (g1 - g0) * i/steps,
            b = b0 + (b1 - b0) * i/steps;

        txSetColor (RGB (r, g, b));
        txTextOut (x, y, text);

        Sleep (time / steps);
        }
    }

//----------------------------------------------------------------------------

void DrawFlag (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor)
    {
    txSetColor     (color);
    txSetFillColor (bkColor);
    
    txLine (x, y, x, y - sizeY);
    txRectangle (x, y - sizeY/2, x + sizeX, y - sizeY);
    
    txSelectFont ("Times New Roman", sizeX/2 + 1);
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




