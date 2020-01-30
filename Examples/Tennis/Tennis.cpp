//{===========================================================================
//! @file       Examples\Tennis\Tennis.cpp
//!
//! @brief      ������ ������������� ������� txLoadImage(), txDeleteDC(),
//!             txBitBlt(), txTransparentBlt(), txAlphaBlend().
//!
//!             ���������� ������ ��������� (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 164 $
//!             $Date: 2020-01-30 05:00:00 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);

    // ��������� ����������� ���� ���, � ������ ���������
    
    HDC table  = txLoadImage ("Resources\\Images\\Table.bmp");  // ������ �������� ��������
    HDC racket = txLoadImage ("Resources\\Images\\Racket.bmp"); // ������ �������� ��������

    txSetFillColor (TX_RED);

    int    mode  = 1;
    double alpha = 1;

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        int x = txMouseX(), y = txMouseY();

        txBitBlt (txDC(), 0, 0, 800, 600, table, 0, 0);

        if (GetAsyncKeyState ('1'))     mode   = 1;
        if (GetAsyncKeyState ('2'))     mode   = 2;
        if (GetAsyncKeyState ('3'))     mode   = 3;

        if (GetAsyncKeyState (VK_UP))   alpha += 0.05;
        if (GetAsyncKeyState (VK_DOWN)) alpha -= 0.05;
        if (alpha < 0) alpha = 0;
        if (alpha > 1) alpha = 1;

        // ����������� �� ����� ������� ���������

        switch (mode)
            {
            case 1: txBitBlt         (txDC(), x-200/2, y-150/2, 200, 150, racket, 0, 0);        break; // ������ �����������
            case 2: txTransparentBlt (txDC(), x-200/2, y-150/2, 200, 150, racket, 0, 0);        break; // ������ ����������� � ���������� ������
            case 3: txAlphaBlend     (txDC(), x-200/2, y-150/2, 200, 150, racket, 0, 0, alpha); break; // ������ ����������� � �����������������
            default: break;
            }

        txSleep (20);
        }

    // ������� �������� DC, ���������� ��������� ������� 

    txDeleteDC (table);
    txDeleteDC (racket);

    return 0;
    }



