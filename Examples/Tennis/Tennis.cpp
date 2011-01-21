//{===========================================================================
//! @file       Examples\Tennis\Tennis.cpp
//              Пример использования функций txLoadImage(), txDeleteDC(),
//              txBitBlt(), txTransparentBlt(), txAlphaBlend()
//!
//! @brief      Пример использования функций txLoadImage(), txDeleteDC(),
//!             txBitBlt(), txTransparentBlt(), txAlphaBlend()
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @version    [Version 0.01 alpha, build 72]
//! @author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)
//! @date       2005
//}===========================================================================

#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);

    HDC table  = txLoadImage ("Resources\\Images\\Table.bmp");
    HDC racket = txLoadImage ("Resources\\Images\\Racket.bmp");
    
    txSetFillColor (TX_RED);
    
    int mode = 1;
    
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        int x = txMouseX(), y = txMouseY();
        
        txClear();
        txBitBlt (txDC(), 0, 0, 800, 600, table, 0, 0);
    
        if (GetAsyncKeyState ('1')) mode = 1;    
        if (GetAsyncKeyState ('2')) mode = 2;    
        if (GetAsyncKeyState ('3')) mode = 3;    

        switch (mode)
            {
            case 1: txBitBlt         (txDC(), x-200/2, y-150/2, 200, 150, racket, 0, 0); break;
            case 2: txTransparentBlt (txDC(), x-200/2, y-150/2, 200, 150, racket, 0, 0); break;
            case 3: txAlphaBlend     (txDC(), x-200/2, y-150/2, 200, 150, racket, 0, 0); break;
            default: break;
            }
        
        txSleep (20);
        }
    
    txDeleteDC (table);
    txDeleteDC (racket);

    return 0;
    }

