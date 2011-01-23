//{=========================================================================== 
//! @file       Examples\Example06.cpp
//!
//! @brief      Расширенный пример с циклами.
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version$
//!             $Date$
//!             $Copyright$
//              $Author$
//}===========================================================================

#include <conio.h>
#include "TXLib.h"

//----------------------------------------------------------------------------

void DanceMan    (int x, int y, int sizeX, int sizeY, double jump,
                  COLORREF color, COLORREF bkColor, int delay);

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

void DrawLine    (double x0, double y0, double x1, double y1);

void DrawCircle  (double x, double y, double r);

int  kbget();

//----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);
    txTextCursor (false);

    int sizeX   = txGetExtentX(), sizeY   = txGetExtentY();
    int centerX = (sizeX+1)/2,    centerY = (sizeY+1)/2;

    DrawFrame (sizeX, sizeY, 10, TX_WHITE);

    txSelectFont ("Times", 60);
    txSetTextAlign (TA_CENTER);

    AppearText  (centerX, sizeY*4/5, "\"Hello, world!\\n\" :)",                                TX_BLACK,  TX_LIGHTGREEN, 5000, 100);
    AppearEarth (centerX, centerY, sizeX/2, sizeY/2,                                           TX_BLACK,  TX_LIGHTCYAN,  5000, 100);

    MoveMan (20, centerY - sizeY/4, centerX - sizeX/50, centerY - sizeY/4, sizeX/40, sizeY/15, TX_YELLOW, TX_BLACK,      3000, 100);
    txSleep (150);
    JumpMan (centerX - sizeX/50, centerY - sizeY/4, sizeX/40, sizeY/15, 0.25,                  TX_YELLOW, TX_BLACK,        10, 100);

    txPlaySound ("tada.wav");
    UnwindFlag (centerX, centerY - sizeY/4, 0, sizeX/20, sizeY/10,                             TX_YELLOW, TX_BLACK,       500, 100);

    DanceMan   (centerX - sizeX/50, centerY - sizeY/4, sizeX/40, sizeY/15, 0.25,               TX_YELLOW, TX_BLACK,       200);

    return 0;
    }

//----------------------------------------------------------------------------

void JumpMan (int x, int y, int sizeX, int sizeY, double jump,
              COLORREF color, COLORREF bkColor, int jumps, int delay)
    {
    DrawMan (x, y, sizeX, sizeY, TX_BLACK, 0, 0, 0, 0);

    txBegin();

    for (int i = 0; i < jumps && !kbhit(); i++)
        {
        DrawMan (x, y - (int)(i%2 * jump*10), sizeX, sizeY, color,
                (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, 0);

        txSleep (delay);

        DrawMan (x, y - (int)(i%2 * jump*10), sizeX, sizeY, bkColor,
                (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, 0);
        }

    kbget();

    DrawMan (x, y - (int)(jumps%2 * jump*10), sizeX, sizeY, color,
            (jumps%2-0.5) * jump/3, 0, (jumps%2-0.5) * -jump/3, 0);

    txEnd();
    }

//----------------------------------------------------------------------------

void DanceMan (int x, int y, int sizeX, int sizeY, double jump,
               COLORREF color, COLORREF bkColor, int delay)
    {
    DrawMan (x, y, sizeX, sizeY, TX_BLACK, 0, 0, 0, 0);

    txBegin();

    int i = 0;
    for (; !kbhit(); i++)
        {
        DrawMan  (x, y - (int)(i%2 * jump*10), sizeX, sizeY, color,
                 (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, (i%2-0.5) * jump);

        txSleep (delay);

        DrawMan  (x, y - (int)(i%2 * jump*10), sizeX, sizeY, bkColor,
                 (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, (i%2-0.5) * jump);
        }

    kbget();

    DrawMan (x, y - (int)(i%2 * jump*10), sizeX, sizeY, color,
            (i%2-0.5) * jump/3, 0, (i%2-0.5) * -jump/3, (i%2-0.5) * jump);

    txEnd();
    }

//----------------------------------------------------------------------------

void MoveMan (int fromX, int fromY, int toX, int toY,
              int sizeX, int sizeY, COLORREF color, COLORREF bkColor,
              int time, int steps)
    {
    txBegin();

    for (int i = 0; i <= steps && !kbhit(); i++)
        {
        int x = fromX + (toX - fromX) * i/steps,
            y = fromY + (toY - fromY) * i/steps;

        DrawMan (x, y - i%6, sizeX, sizeY, color,   i%3*0.02, i%3*-0.1, i%3*0.1, 0);

        txSleep (time / steps);

        DrawMan (x, y - i%6, sizeX, sizeY, bkColor, i%3*0.02, i%3*-0.1, i%3*0.1, 0);
        }

    kbget();

    DrawMan (toX, toY, sizeX, sizeY, color, 0, 0, 0);

    txEnd();
    }

//----------------------------------------------------------------------------

void UnwindFlag (int x, int y, int fromSizeX, int toSizeX, int sizeY,
                 COLORREF color, COLORREF bkColor, int time, int steps)
    {
    txBegin();

    for (int i = 0; i <= steps && !kbhit(); i++)
        {
        int sizeX = fromSizeX + (toSizeX - fromSizeX) * i/steps;

        DrawFlag (x, y, sizeX, sizeY, color,   bkColor);

        txSleep  (time / steps);

        DrawFlag (x, y, sizeX, sizeY, bkColor, bkColor);
        }

    kbget();

    DrawFlag (x, y, toSizeX, sizeY, color, bkColor);

    txEnd();
    }

//----------------------------------------------------------------------------

void DrawMan (int x, int y, int sizeX, int sizeY, COLORREF color,
              double hand, double legs, double head, double twist)
    {
    txSetColor     (color);
    txSetFillColor (color);

    DrawLine (x + twist*sizeX, y - 0.35*sizeY, x, y - 0.7*sizeY);

    DrawLine (x + twist*sizeX, y - 0.35*sizeY, x - (0.5 + legs) * sizeX, y);
    DrawLine (x + twist*sizeX, y - 0.35*sizeY, x + (0.5 + legs) * sizeX, y);

    DrawLine (x, y - 0.65*sizeY, x - sizeX/2,   y - 0.4*sizeY);
    DrawLine (x, y - 0.65*sizeY, x + sizeX/1.2, y - (0.7 + hand) * sizeY);

    DrawCircle (x, y - sizeY + (0.3 + head) * sizeX, 0.3*sizeX);
    }

//----------------------------------------------------------------------------

void DrawEarth (int x, int y, int sizeX, int sizeY, COLORREF color)
    {
    txSetColor (color);
    for (int rx = sizeX/2; rx >= 0; rx -= sizeX/9) txEllipse (x-rx,   y-sizeY/2, x+rx,   y+sizeY/2);
    for (int ry = sizeY/2; ry >= 0; ry -= sizeY/6) txEllipse (x-sizeX/2, y-ry,   x+sizeX/2, y+ry);
    DrawLine (x - sizeX/2, y, x + sizeX/2, y);
    }

//----------------------------------------------------------------------------

void AppearEarth (int x, int y, int sizeX, int sizeY, COLORREF from, COLORREF to,
                  int time, int steps)
    {
    int r0 = txExtractColor (from, TX_RED),   r1 = txExtractColor (to, TX_RED),
        g0 = txExtractColor (from, TX_GREEN), g1 = txExtractColor (to, TX_GREEN),
        b0 = txExtractColor (from, TX_BLUE),  b1 = txExtractColor (to, TX_BLUE);

    for (int i = 0; i <= steps && !kbhit(); i++)
        {
        int r = r0 + (r1 - r0) * i/steps,
            g = g0 + (g1 - g0) * i/steps,
            b = b0 + (b1 - b0) * i/steps;

        DrawEarth (x, y, sizeX, sizeY, RGB (r, g, b));

        Sleep (time / steps);
        }

    kbget();

    DrawEarth (x, y, sizeX, sizeY, to);
    }

//----------------------------------------------------------------------------

void AppearText (int x, int y, const char* text, COLORREF from, COLORREF to,
                 int time, int steps)
    {
    int r0 = txExtractColor (from, TX_RED),   r1 = txExtractColor (to, TX_RED),
        g0 = txExtractColor (from, TX_GREEN), g1 = txExtractColor (to, TX_GREEN),
        b0 = txExtractColor (from, TX_BLUE),  b1 = txExtractColor (to, TX_BLUE);

    for (int i = 0; i <= steps && !kbhit(); i++)
        {
        int r = r0 + (r1 - r0) * i/steps,
            g = g0 + (g1 - g0) * i/steps,
            b = b0 + (b1 - b0) * i/steps;

        txSetColor (RGB (r, g, b));
        txTextOut (x, y, text);

        Sleep (time / steps);
        }

    kbget();

    txSetColor (to);
    txTextOut (x, y, text);
    }

//----------------------------------------------------------------------------

void DrawFlag (int x, int y, int sizeX, int sizeY, COLORREF color, COLORREF bkColor)
    {
    txSetColor     (color);
    txSetFillColor (bkColor);
    DrawLine    (x, y, x, y - sizeY);
    txRectangle (x, y - sizeY/2, x + sizeX, y - sizeY);
    txSelectFont ("Times", sizeX/2 + 1);
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

//----------------------------------------------------------------------------

int kbget()
    {
    int ch = 0;
    while (kbhit()) ch = getch();
    return ch;
    }
