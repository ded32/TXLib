//{=========================================================================== 
//! @file       Examples\Demo\AR.cpp
//!
//! @brief      TXLib AR;) Demo
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:50:10 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include "TXLib.h"

#if !defined (_TX_VER) || (_TX_VER < 0x173a0165)
#error Must use TXLib.h version >= 1.73 and revision >= 165 to compile this. -- Ded
#endif

//============================================================================

HWND txCreateAR (POINT pos, HDC image, bool visible = true, int round = 10);
void txDeleteAR (HWND wnd);
void txMoveAR   (HWND wnd, int x = INT_MIN, int y = INT_MIN);
void txSetAR    (HWND wnd, HDC image = NULL);

//============================================================================

namespace { namespace TX { namespace Win32 {
_TX_DLLIMPORT ("GDI32", HRGN, CreatePolygonRgn,   (const POINT* points, int nPoints, int mode));
_TX_DLLIMPORT ("GDI32", HRGN, CreateRoundRectRgn, (int x1, int y1, int x2, int y2, int width, int height));
}}}

LRESULT CALLBACK _txAR_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

//----------------------------------------------------------------------------

HWND txCreateAR (POINT pos, HDC image, bool visible /*= true*/, int round /*= 10*/)
    {
    POINT size = txGetExtent (image);

    CREATESTRUCT createData = { NULL, NULL, NULL, txWindow(), size.y, size.x, pos.y, pos.x, WS_CHILD | WS_CLIPCHILDREN, "_txAR_Window",
                                txRegisterClass ("_txAR_Class", _txAR_WndProc, CS_OWNDC, HOLLOW_BRUSH, 1) };
    
    HWND wnd = txCreateExtraWindow (createData);
    
    int sz = MIN (size.x, size.y) / round;
    HRGN region = Win32::CreateRoundRectRgn (0, 0, size.x, size.y, sz, sz);
    SetWindowRgn (wnd, region, true);
    
    txSetAR (wnd, image);

    BringWindowToTop (wnd);
    if (visible) ShowWindow (wnd, SW_SHOW);

    return wnd;
    }

//----------------------------------------------------------------------------

void txDeleteAR (HWND wnd)
    {
    txSetAR (wnd, NULL);
    DestroyWindow (wnd);
    }

//----------------------------------------------------------------------------

void txMoveAR (HWND wnd, int x /*= INT_MIN*/, int y /*= INT_MIN*/)
    {
    RECT rect = {}; GetClientRect (wnd, &rect);
    
    if (x != INT_MIN && y != INT_MIN)
        MoveWindow (wnd, x, y, rect.right, rect.bottom, false);
    
    InvalidateRect (wnd, NULL, false);
    }

//----------------------------------------------------------------------------

void txSetAR (HWND wnd, HDC image /*= NULL*/)
    {
    SetWindowLongPtr (wnd, GWLP_USERDATA, (LONG_PTR) image);
    }

//----------------------------------------------------------------------------

LRESULT CALLBACK _txAR_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
    {
    if (msg == WM_PAINT)
        {
        PAINTSTRUCT ps = {};
        HDC dc = BeginPaint (wnd, &ps);

        RECT rect = {}; GetClientRect (wnd, &rect);

        HDC image = (HDC)(uintptr_t) GetWindowLongPtr (wnd, GWLP_USERDATA);
        if (image) Win32::BitBlt (dc, 0, 0, rect.right, rect.bottom, image, 0, 0, SRCCOPY);
        
        EndPaint (wnd, &ps);
        return true;
        }

    return DefWindowProc (wnd, msg, wpar, lpar);
    }

//============================================================================

int main()
    {
    txCreateWindow (800, 600);
    txBegin();

    txPlayVideo ("\a" "http://ded32.net.ru/www.youtube.com-watch-z_AbfPXTKms");
    
    HDC   info    = txCreateCompatibleDC (200, 30);
    POINT infoSz  = txGetExtent (info);
    POINT infoPos = {txGetExtentX()/2 - infoSz.x/2, txGetExtentY()/5*4};
    HWND  arInfo  = txCreateAR (infoPos, info);
    
    txSetTextAlign (TA_CENTER, info);
    txSetColor (TX_WHITE, 1, info);
    txTextOut (infoSz.x/2, 5, "[Move the mouse]", info);
    
    HDC   racket = txLoadImage ("Mouse.bmp"); 
    POINT arSz   = txGetExtent (racket);
    HWND  ar     = txCreateAR  (txMousePos(), racket);

    while (!txGetAsyncKeyState (VK_ESCAPE))
        {
        POINT pos = txMousePos();

        pos.x -= arSz.x/2;
        pos.y -= arSz.y/2;

        char str [100] = "";
        _snprintf_s (str, sizeof (str), "[%03ld %03ld]", pos.x, pos.y);
        
        txSetAR (ar);
        txSetColor (TX_BLACK, 1, racket);
        txSetFillColor (TX_BLACK, racket);
        txRectangle (0, arSz.y-25, 200, arSz.y, racket);
        txSetTextAlign (TA_CENTER, racket);
        txSetColor (TX_WHITE, 1, racket);
        txTextOut (arSz.x/2, arSz.y-23, str, racket);
        txSetAR (ar, racket);

        txMoveAR (arInfo);
        txMoveAR (ar, pos.x, pos.y);
        
        Sleep (0);
        }

    txDeleteAR (ar);
    txDeleteAR (arInfo);

    txDeleteDC (racket);
    txDeleteDC (info);
    }

