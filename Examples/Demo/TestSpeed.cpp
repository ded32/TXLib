//{===========================================================================
//! @file       Examples\Demo\TestSpeed.cpp
//              (C) Ilya Dedinsky, http://ded32.net.ru, 2009
//!
//! @brief      TXLib Benchmarking
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @version    [Version 0.01 alpha, build 72]
//! @author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)
//! @date       2010
//}===========================================================================

#include "TXLib.h"

double TrySleep (int ms);

int main()
    {
    txCreateWindow (800, 600);

    LARGE_INTEGER f = {};
    QueryPerformanceFrequency (&f);
    double freq = f.QuadPart / 1E9;

    double perf = txQueryPerformance();

    printf ("\n" "QueryPerformanceFrequency(): %.2f GHz\n", freq);
    printf (     "txQueryPerformance(): %.2f\n", perf);

    if (perf < 1) perf = 1;

    int x = 10, y = 10,
       vx = (int) (10/perf), vy = (int) (10/perf);

    txBegin();

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear();

        txSetFillColor (TX_WHITE);
        txCircle (x, y, 10);

        printf ("  \r" "Minimum effective txSleep (%.2f)", TrySleep (1));

        x += vx;
        y += vy;

        if (x < 0 || x > txGetExtentX()) { x -= vx; vx *= -1; }
        if (y < 0 || y > txGetExtentY()) { y -= vy; vy *= -1; }
        }

    return 0;
    }

double TrySleep (int ms)
    {
    static LARGE_INTEGER f = {};
    if (!f.QuadPart) QueryPerformanceFrequency (&f);

    LARGE_INTEGER t0 = {};
    QueryPerformanceCounter (&t0);

    txSleep (ms);

    LARGE_INTEGER t1 = {};
    QueryPerformanceCounter (&t1);

    double time = 1E3 * (t1.QuadPart - t0.QuadPart) / f.QuadPart;

    static double avr[100] = {};
    static unsigned n = 0;

    avr [n++ % sizearr (avr)] = time;
    if  (n   < sizearr (avr)) return time;

    time = 0;
    for (unsigned i = 0; i < sizearr (avr); i++) time += avr[i];
    return time / sizearr (avr);
    }

