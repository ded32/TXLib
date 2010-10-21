//=============================================================================
//! \file       TXLib.h
//! \brief      ������� ����
//!
//! \mainpage
//!
//! \brief      ���������� ������ ��������� (The Dumb Artist Library).
//!
//! \version    [Version 0.01 alpha, build 72]
//! \author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky <ded@concord.ru>)
//! \date       2010
//!
//! \warning
//!           - <b>��� �����-������.
//!             ��� ������������� ��������� ������������ � ������� ����������.</b><br><br>
//!           - <b>��� ���������� � Visual Studio ����� ����������� �� �����
//!             ����������: ���� msvcrt.dll</b><br><br>
//!           - ���� ������� �������� ��� ������� ����������� �������, ������� �����
//!             ����� ������������ �����������. ��� �������� ������������� ���������
//!             ���������� ����������. ��� ����������� ����� � ������� ���������
//!             ������� � ����� "LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage"
//!             �������� �������� ����� "1252" �� "c_1251.nls", ���� ��������� ����
//!             "Wizard\CodePage.reg". ����� ���� ��������� ����������� ������������.
//!             (<b>�����:</b> ���� �� �� �� ����� ������ ��� ������, �� �������� ��,
//!             � �������� ������� ����� �� ����� ������ � ������� ������� \ref txTextOut).
//!
//! \par        ��������������
//!           - �����������
//!             - Dev-CPP 4.9.9.2   + MinGW GCC 3.4.2
//!             - CodeBlocks 1.0rc2 + MinGW GCC 3.4.4
//!             - CodeBlocks 8.02   + MinGW GCC 3.4.5
//!             - CodeBlocks 10.05  + MinGW GCC 4.4.1
//!             - Microsoft Visual Studio  6.0
//!             - Microsoft Visual Studio  7.1 (2003)
//!             - Microsoft Visual Studio  8.0 (2005)
//!             - Microsoft Visual Studio  9.0 (2008)
//!             - Microsoft Visual Studio 10.0 (2010)
//!           - ������������ �������
//!             - Windows 2000 SP4 ru/en
//!             - Windows XP SP2/SP3 ru/en
//!             - Windows 2003 SP1 R2
//!             - Windows Vista
//!             - Windows 7
//!
//! \par        ������� ���������
//! - Build 72
//!          -# ������������ ��������� C++0x � GCC 4.5 � ������ ���������� -Wall -Wextra
//! - Build 71
//!          -# ������������ ���������� MS SAL � ������ ���������� /analyze � MSVS 2005, 2008.
//!          -# ������������ �������� ���������� �� �������.
//!          -# ������� ���� � ������� � _txThrow().
//! - Build 70
//!          -# ����������� ������ _txCanvas_OnPaint (NULL DC).
//!          -# ������� �������� ��������� ��������� ��� ���������� ������.
//!          -# ��������� ����������� (\ref TX_TRACE).
//! - Build 69
//!          -# ��������� ������ � ����������� ������ (still experimental).
//! - Build 66
//!          -# ���������� ������ ��� ������������� ���������� �� ���������� Win2000, WinXP.
//!          -# ��������������� ���������� ������� � �������.
//! - Build 65
//!          -# ��������� ������� �������� ��� VS6, VS2003-2008, CodeBlocks, DevCPP.
//!          -# ��������� ���������� � �������� ������ ��� ��� VS2003-2008.
//! - Build 64
//!          -# ��������� c������������ � Visual Studio 2005.\n
//!             ��������!\n
//!             -# ������������� ����������� ����� UNICODE (����� ��������� ��������
//!                Visual Studio). ��� ����� ������ � UNICODE-��������� ����������� ������� W.\n
//!             -# ������������� ����������  ����� _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES.\n
//!          -# ������� ������ ������ ������� � ������, ���������� �� ���������.
//! - Build 50
//!          -# ��������� txTransparentBlt(), txAlphaBlend() - Win98 � ������.
//!          -# ��������! ������� txSetBkColor(), txBkColor(), txGetBkColor()
//!             ������ ���������� txSetFillColor(), txFillColor(), txGetFillColor()
//!             (������������� �� ������� �������� - � Graphics.h).
//! - Build 45
//!          -# ��������� txPlaySound().
//! - Build 44
//!          -# ��������� ��� � txMouseButtons().
//!
//-----------------------------------------------------------------------------
//! \defgroup Drawing   ���������
//! \defgroup Mouse     ��������� ����
//! \defgroup Dialogs   ���������� ����
//! \defgroup Service   ���������
//! \defgroup Misc      ������
//! \defgroup Technical ����������� ������
//! \cond     Internal
//! \defgroup Internal  ����������
//! \endcond
//=============================================================================

#ifndef __TXLIB_H
#define __TXLIB_H

//-----------------------------------------------------------------------------
// ��������� � ������������ � ����������
//-----------------------------------------------------------------------------
//! \cond Internal

#undef  UNICODE

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400
#endif

#if defined (__GNUC__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wunreachable-code"
#endif

#if defined (_MSC_VER)
#pragma warning (push, 4)
#pragma warning (disable: 4127)				 // conditional expression is constant
#pragma warning (disable: 4245)				 // 'argument': conversion from A to B, signed/unsigned mismatch
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1
#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200) // MSVC 6
#pragma warning (disable: 4100)              // 'parameter': unreferenced formal parameter
#pragma warning (disable: 4511)              // 'class': copy constructor could not be generated
#pragma warning (disable: 4512)				 // 'class': assignment operator could not be generated
#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1400) // MSVC 8 (2005)
#define _TX_USE_SECURE_CRT
#else
#define  strncpy_s    strncpy				 // Prevous MSVC versions do not
#define _snprintf_s  _snprintf                           // have secure variants of these
#define _vsnprintf_s _vsnprintf                          // functions, so use unsecure ones
#endif

//! \endcond Internal
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <locale.h>

#include <algorithm>

#include <windows.h>

//=============================================================================
//! \cond Namespaces

namespace {
namespace TX {

//! \endcond Namespaces
//=============================================================================

// Function prototypes for actual library code. Most of TX::tx... calls are
// only wrappers. This is done so because when a programmer calls some function
// wrong, GCC generates error in three lines: (1) name of function containing
// the error, (2) location of function which is called wrong, (3) "at this point
// in file" message pointing to actual error line. In some frequently used IDEs,
// when a programmer clicks to line (2), IDE opens TXLib.h code opens and points
// to function declaration. This is frequently makes a programmer to think that
// he found error in TXLib.h. So, the wrappers contain specific comments about
// this is actually his error, not TXLib.h. A programmer should always click
// to "at this point in file" message, but beginners don't know about this.

int         _txExtractColor (COLORREF color, COLORREF component);
COLORREF    _txRGB2HSL (COLORREF rgbColor);
COLORREF    _txHSL2RGB (COLORREF hslColor);
bool        _txCreateWindow (double sizeX, double sizeY, bool centered);
bool        _txOK();
POINT       _txGetExtent();
int         _txGetExtentX();
int         _txGetExtentY();
bool        _txSetDefaults();
bool        _txSetColor (COLORREF color, int thickness);
bool        _txColor (double red, double green, double blue);
COLORREF    _txGetColor();
bool        _txSetFillColor (COLORREF color);
bool        _txFillColor (double red, double green, double blue);
COLORREF    _txGetFillColor();
bool        _txSetROP2 (int mode);
bool        _txClear();
bool        _txSetPixel (double x, double y, COLORREF color);
bool        _txPixel (double x, double y, double red, double green, double blue);
COLORREF    _txGetPixel (double x, double y);
bool        _txLine (double x0, double y0, double x1, double y1);
bool        _txRectangle (double x0, double y0, double x1, double y1);
bool        _txPolygon (POINT* points, int numPoints);
bool        _txEllipse (double x0, double y0, double x1, double y1);
bool        _txCircle (double x, double y, double r); bool       txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle);
bool        _txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle);
bool        _txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle);
bool        _txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle);
bool        _txTextOut (double x, double y, const char text[]);
bool        _txSelectFont (const char* name, double sizeY, double sizeX, int bold, bool italic, bool underline, bool strikeout);
SIZE        _txGetTextExtent (const char* text);
int         _txGetTextExtentX (const char* text);
int         _txGetTextExtentY (const char* text);
bool        _txSetTextAlign (unsigned align);
LOGFONT*    _txFontExist (const char* name);
bool        _txFloodFill (double x, double y, COLORREF color, DWORD mode);
bool        _txSelectRegion (double x0, double y0, double x1, double y1);
bool        _txSelectObject (HGDIOBJ obj);
int         _txBegin();
int         _txEnd();
bool        _txUpdateWindow (bool update);
bool        _txTextCursor (bool blink);
HDC         _txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap);
HDC         _txLoadImage (LPCTSTR filename);
bool        _txDeleteDC (HDC dc);
bool        _txBitBlt (HDC dest, double xDest, double yDest, double width, double height, HDC src, double xSrc, double ySrc, DWORD rOp);
bool        _txTransparentBlt (HDC dest, double xDest, double yDest, double width, double height,
                               HDC src, double xSrc, double ySrc, COLORREF transColor);
bool        _txAlphaBlend (HDC dest, double xDest, double yDest, double width, double height,
                           HDC src, double xSrc, double ySrc, double alpha);
double      _txMouseX();
double      _txMouseY();
int         _txMouseButtons();
const char* _txInputBox (const char* text, const char* caption, const char* input);
HDC         _txDC();
HWND        _txWindow();
bool        _txLock (bool wait);
bool        _txUnlock();
const char* _txVersion();
bool        _txSleep (int time);
bool        _txPlaySound (const char* filename, DWORD mode);

//=============================================================================
//! \name    �����
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ���������������� ������
//  \note    The TX_* constants are the wrappers around my teacher's bug at 20050915 :)
//! \see     txSetColor(), txSetFillColor(), txGetColor(), txGetFillColor(), txGetPixel()
//! \examples
//! \code
//!          txSetColor (TX_RED);
//!          txSetColor (TX_NULL);
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
enum txColors {
#endif

    const COLORREF
    txBLACK        = RGB (  0,   0,   0), TX_BLACK         = txBLACK,        //!< ������ ����
    txBLUE         = RGB (  0,   0, 128), TX_BLUE          = txBLUE,         //!< ����� ����
    txGREEN        = RGB (  0, 128,   0), TX_GREEN         = txGREEN,        //!< ������� ����
    txCYAN         = RGB (  0, 128, 128), TX_CYAN          = txCYAN,         //!< ��������� ����
    txRED          = RGB (128,   0,   0), TX_RED           = txRED,          //!< ������� ����
    txMAGENTA      = RGB (128,   0, 128), TX_MAGENTA       = txMAGENTA,      //!< ��������� ����
    txBROWN        = RGB (128, 128,   0), TX_BROWN         = txBROWN,        //!< ���������� ����
    txORANGE       = RGB (255, 128,   0), TX_ORANGE        = txORANGE,       //!< ��������� ����
    txGRAY         = RGB (160, 160, 160), TX_GRAY          = txGRAY,         //!< ����� ����
    txDARKGRAY     = RGB (128, 128, 128), TX_DARKGRAY      = txDARKGRAY,     //!< �����-����� ����
    txLIGHTGRAY    = RGB (192, 192, 192), TX_LIGHTGRAY     = txLIGHTGRAY,    //!< ������-����� ����
    txLIGHTBLUE    = RGB (  0,   0, 255), TX_LIGHTBLUE     = txLIGHTBLUE,    //!< ������-����� ����
    txLIGHTGREEN   = RGB (  0, 255, 128), TX_LIGHTGREEN    = txLIGHTGREEN,   //!< ������-������� ����
    txLIGHTCYAN    = RGB (  0, 255, 255), TX_LIGHTCYAN     = txLIGHTCYAN,    //!< ������-��������� ����
    txLIGHTRED     = RGB (255,   0, 128), TX_LIGHTRED      = txLIGHTRED,     //!< ������-������� ����
    txLIGHTMAGENTA = RGB (255,   0, 255), TX_LIGHTMAGENTA  = txLIGHTMAGENTA, //!< ������-��������� ����
    txPINK         = RGB (255, 128, 255), TX_PINK          = txPINK,         //!< ������� ���������:)
    txYELLOW       = RGB (255, 255, 128), TX_YELLOW        = txYELLOW,       //!< ������ ����
    txWHITE        = RGB (255, 255, 255), TX_WHITE         = txWHITE,        //!< ����� ����
    txTRANSPARENT  = 0xFFFFFFFF,          TX_TRANSPARENT   = txTRANSPARENT,  //!< ���������� ����
    txNULL         = txTRANSPARENT,       TX_NULL          = txNULL,         //!< ���������� ����

// �������� ������ (����������) - ��. \ref txExtractColor(), \ref txRGB2HSL(), \ref txHSL2RGB()

    txHUE          = 0x04000000,          TX_HUE           = txHUE,          //!< �������� ���
    txSATURATION   = 0x05000000,          TX_SATURATION    = txSATURATION,   //!< ������������
    txLIGHTNESS    = 0x06000000,          TX_LIGHTNESS     = txLIGHTNESS;    //!< ��������

#ifdef FOR_DOXYGEN_ONLY
    }
#endif

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������� (���������) ���� �� ���� ������� ������ (���������).
//! \return  ��������� ���� � ������� COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB()
//! \examples
//! \code
//!          txSetColor (RGB (255, 128, 0));
//!
//!          int red = 20, green = 200, blue = 20;
//!          COLORREF color = RGB (red, green, blue);
//!          txSetFillColor (color);
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
COLORREF RGB (red,       //!< ���������� �������� ����� � ��������� [0; 255]
              green,     //!< ���������� �������� ����� � ��������� [0; 255]
              blue       //!< ���������� ������ ����� � ��������� [0; 255]
              );
#endif

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� �������� ���������� (�������� �����) �� ���������� �����.
//! \return  �������� ����������, ��. \ref txColors
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors
//! \examples
//! \code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          ������ ������� ��. � �������� AppearText(), AppearEarth() ������� 5 ("�����").
//! \endcode
//-----------------------------------------------------------------------------

int txExtractColor // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                   (COLORREF color,     //!< ��������� ����
                    COLORREF component  //!< ����������� ����������, ��. \ref txColors
                    )
    {
    return _txExtractColor (color, component);
    }

//---------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ����������� ���� �� ������� RGB � ������ HSL.
//!
//!          ������ RGB ������������ ���
//!
//!          - ������� ���������� ����� (Red), �� 0 �� 255.
//!          - ������� ���������� ����� (Green), �� 0 �� 255.
//!          - ����� ���������� ����� (Blue), �� 0 �� 255.
//!
//!          ������ HSL ������������ ���
//!
//!          - �������� ��� (Hue), �� 0 �� 360.
//!          - ������������ (Saturation), �� 0 �� 255.
//!          - �������� (Lightness), �� 0 �� 255.
//!
//! \return  ��������� ���� � ���� COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors
//! \examples
//! \code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txRGB2HSL // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                   (COLORREF rgbColor   //!< ������������� ���� � ������� RGB
                    )
    {
    return _txRGB2HSL (rgbColor);
    }

//---------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ����������� ���� �� ������� HSL � ������ RGB.
//!
//!          ������ RGB ������������ ���
//!
//!          - ������� ���������� ����� (Red), �� 0 �� 255.
//!          - ������� ���������� ����� (Green), �� 0 �� 255.
//!          - ����� ���������� ����� (Blue), �� 0 �� 255.
//!
//!          ������ HSL ������������ ���
//!
//!          - �������� ��� (Hue), �� 0 �� 360.
//!          - ������������ (Saturation), �� 0 �� 255.
//!          - �������� (Lightness), �� 0 �� 255.
//!
//! \return  ��������� ���� � ���� COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors
//! \examples
//! \code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txHSL2RGB // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                   (COLORREF hslColor   //!< ������������� ���� � ������� HSL
                    )
    {
    return _txHSL2RGB (hslColor);
    }

//=============================================================================
//  \name    ������������� ���������� � ��������� ���������
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ���� ���������
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txOk()
//! \examples
//! \code
//!          txCreateWindow ( 800,  600);
//!          txCreateWindow (1024,  768, false);
//! \endcode
//-----------------------------------------------------------------------------

bool txCreateWindow // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                    (double sizeX,        //!< ������ ���� �� ����������� (� ��������)
                     double sizeY,        //!< ������ ���� �� ����������� (� ��������)
                     bool centered = true //!< ������������� ���� �� �������
                     )
    {
    return _txCreateWindow (sizeX, sizeY, centered);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ������������ ������ ����������
//! \return  ��������� ����������
//! \see     txCreateWindow()
//! \examples
//! \code
//!          txCreateWindow (800, 600);
//!          if (!txOK())
//!              {
//!              MessageBox (NULL, "�� ���� ������� ����", "������!", MB_ICONSTOP);
//!              return;
//!              }
//! \endcode
//-----------------------------------------------------------------------------

bool txOK() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txOK();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���������� ������ ���� ��������� � ���� ��������� POINT.
//! \return  ������ ���� ��������� � ���� ��������� POINT.
//! \see     txGetExtentX(), txGetExtentY()
//! \examples
//! \code
//!          POINT size = txGetExtent();
//!          txLine (0, 0,      size.x, size.y);
//!          txLine (0, size.y, size.x, 0);
//! \endcode
//-----------------------------------------------------------------------------

POINT txGetExtent() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txGetExtent();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���������� ������ ���� ���������.
//! \return  ������ ���� ���������.
//! \see     txGetExtent(), txGetExtentY()
//! \examples
//! \code
//!          txSetTextAlign (TA_CENTER);
//!          txTextOut (txGetExtentX() / 2, 100, "O-o-o, you are in the middle now");
//! \endcode
//-----------------------------------------------------------------------------

int txGetExtentX() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txGetExtentX();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���������� ������ ���� ���������.
//! \return  ������ ���� ���������.
//! \see     txGetExtent(), txGetExtentX()
//! \examples
//! \code
//!          void DrawHouse (int height);
//!          ...
//!          DrawHouse (txGetExtentY() / 2);
//! \endcode
//-----------------------------------------------------------------------------

int txGetExtentY() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txGetExtentY();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� ���������� ��������� �� ���������.
//!
//!          ��������� �� ���������:\n
//!          - ����� - ���� ����� (TX_WHITE), ������� 1
//!          - ������� - ���� ����� (TX_WHITE)
//!          - ����� - ��������� �����, ���� ����� (TX_WHITE)
//!          - ���������� ��������� �������� - ����������� ����� (R2_COPYPEN)
//!
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txSelectFont(), txSelectRegion(), txSetROP2()
//! \examples
//! \code
//!          txSetDefaults();
//! \endcode
//-----------------------------------------------------------------------------

bool txSetDefaults() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txSetDefaults();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������� ������� ���� � ������� �����, ���� ������.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples
//! \code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! \endcode
//-----------------------------------------------------------------------------

bool txSetColor // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                (COLORREF color,   //!< ���� ����� � ������, ��. \ref txColors, RGB()
                 int thickness = 1 //!< ������� �����
                 )
    {
    return _txSetColor (color, thickness);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������� ������� ���� ����� � ������.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()
//! \examples
//! \code
//!          txColor (1.0, 0.5, 0.25);
//! \endcode
//-----------------------------------------------------------------------------

bool txColor // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
             (double red,     //!< ���������� �������� ����� � ��������� [0; 1]
              double green,   //!< ���������� �������� ����� � ��������� [0; 1]
              double blue     //!< ���������� ������ ����� � ��������� [0; 1]
              )
    {
    return _txColor (red, green, blue);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���������� ������� ���� ����� � ������.
//! \return  ������� ���� ����� � ������, ��. \ref txColors, RGB()
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples
//! \code
//!          COLORREF color = txGetColor();
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txGetColor() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txGetColor();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������� ������� ���� ���������� �����.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), \ref txColors, RGB()
//! \examples
//! \code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! \endcode
//-----------------------------------------------------------------------------

bool txSetFillColor // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                    (COLORREF color  //!< ���� ����������, ��. \ref txColors, RGB()
                     )
    {
    return _txSetFillColor (color);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������� ������� ���� ���������� �����.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor()
//! \examples
//! \code
//!          txFillColor (1.0, 0.5, 0.25);
//! \endcode
//-----------------------------------------------------------------------------

bool txFillColor // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                 (double red,   //!< ���������� �������� ����� � ��������� [0; 1]
                  double green, //!< ���������� �������� ����� � ��������� [0; 1]
                  double blue   //!< ���������� ������ ����� � ��������� [0; 1]
                  )
    {
    return _txFillColor (red, green, blue);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���������� ������� ���� ���������� �����.
//! \return  ������� ���� ���������� �����, ��. \ref txColors, RGB()
//! \see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), \ref txColors, RGB()
//! \examples
//! \code
//!          COLORREF color = txGetFillColor();
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txGetFillColor() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txGetFillColor();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������� ����� �������������� ������ ��� ���������.
//!
//!          ��� ��������� ����������� ���������� ����� �� ������ ������� �������
//!          �� ������, � ��������� ����� ������ � ������� ����� ����� � ����������.
//!
//!          ������ �������������� ������:
//!
//!          \table
//!          \tr R2_COPYPEN     \td ������� = ����� ����� (����� ���������� ����� :) \endtr
//!          \tr R2_NOTCOPYPEN  \td ������� = ~�����\n \endtr
//!
//!          \tr R2_BLACK       \td ������� = ������ ���� (���� ����� ������������)    \endtr
//!          \tr R2_WHITE       \td ������� = �����  ���� (���� ����� ������������)    \endtr
//!          \tr R2_NOT         \td ������� = ~�������    (���� ����� ������������)\n  \endtr
//!
//!          \tr R2_XORPEN      \td ������� =    ������� ^  �����    \endtr
//!          \tr R2_NOTXORPEN   \td ������� = ~ (������� ^  �����)\n \endtr
//!
//!          \tr R2_MASKPEN     \td ������� =    ������� &  �����    \endtr
//!          \tr R2_NOTMASKPEN  \td ������� = ~ (������� &  �����)   \endtr
//!          \tr R2_MASKNOTPEN  \td ������� =    ������� & ~�����    \endtr
//!          \tr R2_MASKPENNOT  \td ������� =   ~������� &  �����\n  \endtr
//!
//!          \tr R2_MERGEPEN    \td ������� =    ������� |  �����    \endtr
//!          \tr R2_NOTMERGEPEN \td ������� = ~ (������� |  �����)   \endtr
//!          \tr R2_MERGENOTPEN \td ������� =    ������� | ~�����    \endtr
//!          \tr R2_MERGEPENNOT \td ������� =   ~������� |  �����\n  \endtr
//!
//!          \tr R2_NOP         \td ������� ������ �� ����������.    \endtr
//!          \endtable
//!
//! \return  ���������� ����� �������������� ������, ��. \ref txColors, RGB()
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txSetROP2 (R2_XORPEN);
//!          txSetROP2 (R2_COPYPEN);
//! \endcode
//-----------------------------------------------------------------------------

bool txSetROP2 // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
               (int mode         //!< ����� ���������� ������
                )
    {
    return _txSetROP2 (mode);
    }

//=============================================================================
//  \name    ������
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������� ����� ������� ������ ����������.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetFillColor(), txFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples
//! \code
//!          txClear();
//! \endcode
//-----------------------------------------------------------------------------

bool txClear() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txClear();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ������� (����� �� ������).
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txPixel(), txGetPixel(), \ref txColors, RGB()
//! \examples
//! \code
//!          txSetPixel (100, 100, TX_RED);
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! \endcode
//-----------------------------------------------------------------------------

bool txSetPixel // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                (double x,      //!< �-���������� �����
                 double y,      //!< Y-���������� �����
                 COLORREF color //!< ���� �����, ��. \ref txColors, RGB()
                 )
    {
    return _txSetPixel (x, y, color);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ������� (����� �� ������).
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetPixel(), txGetPixel()
//! \examples
//! \code
//!          txSetPixel (100, 100, 1.0, 0.5, 0.25);
//! \endcode
//-----------------------------------------------------------------------------

bool txPixel // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
             (double x,         //!< �-���������� �����
              double y,         //!< Y-���������� �����
              double red,       //!< ���������� �������� ����� � ��������� [0; 1]
              double green,     //!< ���������� �������� ����� � ��������� [0; 1]
              double blue       //!< ���������� ������ ����� � ��������� [0; 1]
              )
    {
    return _txPixel (x, y, red, green, blue);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���������� ������� ���� ����� (�������) �� ������.
//! \return  ������� ���� �������, ��. \ref txColors, RGB()
//! \see     txSetPixel(), txPixel(), \ref txColors, RGB()
//! \examples
//! \code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED) CarCrash (x, y);
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txGetPixel // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                    (double x,  //!< �-���������� �����
                     double y   //!< Y-���������� �����
                     )
    {
    return _txGetPixel (x, y);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ �����.
//!          ���� � ������� ����� �������� �������� txSetColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txLine (100, 200, 400, 500);
//! \endcode
//-----------------------------------------------------------------------------

bool txLine // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
            (double x0,        //!< X-���������� ��������� �����
             double y0,        //!< Y-���������� ��������� �����
             double x1,        //!< X-���������� ��������  �����
             double y1         //!< Y-���������� ��������  �����
             )
    {
    return _txLine (x0, y0, x1, y1);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ �������������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txRectangle (100, 200, 400, 500);
//! \endcode
//-----------------------------------------------------------------------------

bool txRectangle // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                 (double x0,   //!< X-���������� �������� ������ ����
                  double y0,   //!< Y-���������� �������� ������ ����
                  double x1,   //!< X-���������� ������� ������� ����
                  double y1    //!< Y-���������� ������� ������� ����
                  )
    {
    return _txRectangle (x0, y0, x1, y1);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ������� ����� ��� �������������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          POINT star[6] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}, {150, 300}};
//!          txPolygon (star, 6);
//! \endcode
//-----------------------------------------------------------------------------

bool txPolygon // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
               (POINT* points, //!< ������ �������� POINT � ������������ �����
                int numPoints  //!< ���������� ����� � �������
                )
    {
    return _txPolygon (points, numPoints);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txEllipse (100, 100, 300, 200);
//! \endcode
//-----------------------------------------------------------------------------

bool txEllipse // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
               (double x0,     //!< X-���������� �������� ������ ���� ���������� ��������������
                double y0,     //!< Y-���������� �������� ������ ���� ���������� ��������������
                double x1,     //!< X-���������� ������� ������� ���� ���������� ��������������
                double y1      //!< Y-���������� ������� ������� ���� ���������� ��������������
                )
    {
    return _txEllipse (x0, y0, x1, y1);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ���������� ��� ����.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txCircle (100, 100, 10);
//! \endcode
//-----------------------------------------------------------------------------

bool txCircle // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
              (double x,       //!< �-���������� ������
               double y,       //!< Y-���������� ������
               double r        //!< ������
               )
    {
    return _txCircle (x, y, r);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ���� �������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txArc (100, 100, 300, 200, 0, 180);
//! \endcode
//-----------------------------------------------------------------------------

bool txArc // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
           (double x0,         //!< X-���������� �������� ������ ���� ��������������,
                               //!<   ���������� ������ �������, ����������� ����
            double y0,         //!< Y-���������� �������� ������ ���� ��������������
            double x1,         //!< X-���������� ������� ������� ���� ��������������
            double y1,         //!< Y-���������� ������� ������� ���� ��������������
            double startAngle, //!< ���� ����� ������������ ��� OX � ������� ���� (� ��������)
            double totalAngle  //!< �������� ���� (� ��������)
            )
    {
    return _txArc (x0, y0, x1, y1, startAngle, totalAngle);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ������ �������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txPie (100, 100, 300, 200, 0, 180);
//! \endcode
//-----------------------------------------------------------------------------

bool txPie // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
           (double x0,         //!< X-���������� �������� ������ ���� ��������������,
                               //!<   ���������� ������ �������, ����������� ������
            double y0,         //!< Y-���������� �������� ������ ���� ��������������
            double x1,         //!< X-���������� ������� ������� ���� ��������������
            double y1,         //!< Y-���������� ������� ������� ���� ��������������
            double startAngle, //!< ���� ����� ������������ ��� OX � ������� ������� (� ��������)
            double totalAngle  //!< �������� ������� (� ��������)
            )
    {
    return _txPie (x0, y0, x1, y1, startAngle, totalAngle);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ ����� �������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txChord (100, 100, 300, 200, 0, 180);
//! \endcode
//-----------------------------------------------------------------------------

bool txChord // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
             (double x0,         //!< X-���������� �������� ������ ���� ��������������,
                                 //!<   ���������� ������ �������, ����������� �����
              double y0,         //!< Y-���������� �������� ������ ���� ��������������
              double x1,         //!< X-���������� ������� ������� ���� ��������������
              double y1,         //!< Y-���������� ������� ������� ���� ��������������
              double startAngle, //!< ���� ����� ������������ ��� OX � ������� ����� (� ��������)
              double totalAngle  //!< �������� ����� (� ��������)
              )
    {
    return _txChord (x0, y0, x1, y1, startAngle, totalAngle);
    }

//=============================================================================
//  \name    ������ � �������
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������ �����.
//!          ���� ������ �������� �������� txSetColor().
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples
//! \code
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//! \endcode
//-----------------------------------------------------------------------------

bool txTextOut // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
               (double x,         //!< �-���������� ��������� ����� ������
                double y,         //!< Y-���������� ��������� ����� ������
                const char text[] //!< ��������� ������
                )
    {
    return _txTextOut (x, y, text);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ������� �����.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txTextOut()
//! \examples
//! \code
//!          txSelectFont ("Comic Sans MS", 20);
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//!          txSelectFont ("Comic Sans MS", 20, 10, false, true, false, true);
//!          txTextOut (100, 200, "�� �� ������-�� ���.");
//! \endcode
//-----------------------------------------------------------------------------

bool txSelectFont // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                  (const char* name,       //!< �������� ������
                   double sizeY,           //!< ������ ���� (������ �� Y)
                   double sizeX = 0,       //!< ������ ����
                   int bold = FW_DONTCARE, //!< �������� ������ (�� 0 �� 1000)
                   bool italic = false,    //!< ������
                   bool underline = false, //!< �������������
                   bool strikeout = false  //!< ������������
                   )
    {
    return _txSelectFont (name, sizeY, sizeX, bold, italic, underline, strikeout);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� ������� ��������� �������.
//! \return  ������� ������� � ��������� SIZE.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples
//! \code
//!          SIZE size = txGetTextExtent (text);
//!          txTextOut (100 + size.cx / 2, 200 + size.cy / 2, text);
//! \endcode
//-----------------------------------------------------------------------------

SIZE txGetTextExtent // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                     (const char* text     //!< ��������� ������
                     )
    {
    return _txGetTextExtent (text);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� ������ ��������� �������.
//! \return  ������ �������.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples
//! \code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! \endcode
//-----------------------------------------------------------------------------

int txGetTextExtentX // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                     (const char* text      //!< ��������� ������
                     )
    {
    return _txGetTextExtentX (text);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� ������ ��������� �������.
//! \return  ������ �������.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples
//! \code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! \endcode
//-----------------------------------------------------------------------------

int txGetTextExtentY // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                     (const char* text      //!< ��������� ������
                     )
    {
    return _txGetTextExtentY (text);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������� ������� ������������ ������.
//!
//!          ����� ������������:
//!
//!          \table
//!          \tr TA_BASELINE \td ����� (X,Y) ���������� ������� ����� ������. \endtr
//!          \tr TA_BOTTOM   \td ����� (X,Y) ���������� ������ ������� ���������� ��������������\n
//!                              (����� ����� ���� ���� �����).   \endtr
//!          \tr TA_TOP      \td ����� (X,Y) ���������� ������� ������� ���������� ��������������\n
//!                              (����� ����� ���� ���� �����).\n \endtr
//!
//!          \tr TA_CENTER   \td ����� ����� �������� �� ����������� ������������ ����� (X,Y). \endtr
//!          \tr TA_LEFT     \td ����� (X,Y) ���������� ����� ������� ���������� ��������������\n
//!                              (����� ����� ������ ���� �����). \endtr
//!          \tr TA_RIGHT    \td ����� (X,Y) ���������� ������ ������� ���������� ��������������\n
//!                              (����� ����� ����� ���� �����).  \endtr
//!          \endtable
//!
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples
//! \code
//!          txSetTextAlign (TA_RIGHT);
//!
//!          txSetTextAlign();
//! \endcode
//-----------------------------------------------------------------------------

bool txSetTextAlign // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                    (unsigned align = TA_CENTER | TA_BASELINE //!< ����� ������������
                     )
    {
    return _txSetTextAlign (align);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���� ����� �� ��� ��������.
//! \return  ���������� � ������ � ��������� LOGFONT.
//!          ���� ����� �� ������, ���������� NULL.
//! \see     txTextOut(), txSelectFont()
//! \examples
//! \code
//!          if (txFontExist ("Comic Sans MS")) txSelectFont ("Comic Sans MS", 30);
//!          else                               txSelectFont ("Times", 30);
//! \endcode
//-----------------------------------------------------------------------------

LOGFONT* txFontExist // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                     (const char* name      //!< �������� ������
                     )
    {
    return _txFontExist (name);
    }

//=============================================================================
//  \name    ������
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ������������ ������ ������� ������ ����������.
//!          ���� ���������� �������� �������� txSetFillColor().
//!          �� ������������� ��� ���������� - �������� �������� ��������.
//!
//!          ������ �������:
//!
//!          FLOODFILLSURFACE - �������� �������, ��������� ������ color.\n
//!          FLOODFILLBORDER  - �������� �� �������, ��������� ������ color.
//!
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples
//! \code
//!          txFloodFill (100, 100);
//! \endcode
//-----------------------------------------------------------------------------

bool txFloodFill // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                 (double x,                        //!< �-���������� ����� ������ �������
                  double y,                        //!< Y-���������� ����� ������ �������
                  COLORREF color = TX_TRANSPARENT, //!< ���� ���������� ������� (TX_TRANSPARENT - ���������������)
                  DWORD mode = FLOODFILLSURFACE    //!< ����� ������� (FLOODFILLSURFACE - ������� ����������� ����)
                  )
    {
    return _txFloodFill (x, y, color, mode);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������� ������� ������������� ������ ���������.
//!          ��, ��� ����������� ��� ������� ���������, �� ��������.
//!
//!          ��������������� ������� �������������� ��������������
//!          ����� ����������� ������� ������ � ��������� �� Win32 API.
//!
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples
//! \code
//!          txSelectRegion (100, 100, 300, 400);
//! \endcode
//-----------------------------------------------------------------------------

bool txSelectRegion // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                    (double x0,   //!< X-���������� �������� ������ ����
                     double y0,   //!< Y-���������� �������� ������ ����
                     double x1,   //!< X-���������� ������� ������� ����
                     double y1    //!< Y-���������� ������� ������� ����
                     )
    {
    return _txSelectRegion (x0, y0, x1, y1);
    }

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ������������� ������� ������ GDI.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txSelectFont(), txSelectRegion()
//! \examples
//! \code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! \endcode
//-----------------------------------------------------------------------------

bool txSelectObject // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                    (HGDIOBJ obj     //!< ���������� ������� GDI
                     )
    {
    return _txSelectObject (obj);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� ���������� ����������� ����, �� ��������� �������.
//!
//! \warning ��������� ������������ �� ������ �����. ��� ����� �������� �
//!          �������� ����������� � ����. ���� ��������� ��������, �� �����������
//!          txSleep() ������ ������� ������� Sleep().
//!
//! \return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//! \see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor()
//! \examples
//! \code
//!          txBegin();
//!          txSetFillColor (TX_WHITE);
//!          txClear();
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();
//! \endcode
//-----------------------------------------------------------------------------

int txBegin() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txBegin();
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������������ ���������� ����, ��������������� �������� txBegin().
//!
//! \warning ���� txBegin() ���������� ��������� ���, �� ��� ������ ����������
//!          ��������� ������� �� ��� ������� txEnd().
//!
//! \return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//! \see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor()
//! \examples
//! \code
//!          txBegin();
//!          txSetFillColor (TX_WHITE);
//!          txClear();
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();
//! \endcode
//-----------------------------------------------------------------------------

int txEnd() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txEnd();
    }

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ��������� ��� ������������ ���������� ����������� � ����.
//!
//!          � ������� �� txBegin() � txEnd(), ��������� ���� ���������� ���
//!          ����� ����������.
//!
//! \warning ��������� ������������ �� ������ �����. ��� ����� �������� �
//!          �������� ����������� � ����. ���� ��������� ��������, �� �����������
//!          txSleep() ������ ������� ������� Sleep().
//!
//! \return  ���������� ��������� ������ ����������.
//! \see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(), txLock(), txUnlock(), txGDI()
//! \examples
//! \code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! \endcode
//-----------------------------------------------------------------------------

bool txUpdateWindow // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                    (bool update = true //!< ����� ���������� (false - ��������� ����������)
                     )
    {
    return _txUpdateWindow (update);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� ��� ������������ ��������� ��������� ������� � ����.
//! \return  ���������� �������� ����������.
//! \see     txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//! \examples
//! \code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! \endcode
//-----------------------------------------------------------------------------

bool txTextCursor // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                  (bool blink = true    //!< false - ����������� �������� ������
                   )
    {
    return _txTextCursor (blink);
    }

//=============================================================================
//  \name    ��������� � ������ (�� "����������� ������") � �������� �����������
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ������� �������������� ����� (�������� ���������, Device Context, DC) � ������.
//! \return  ���������� (��������� �����, �������� Windows) ���������� ������ (��������� ���������).
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//!
//! \remarks ��������� �������� ����� ����� ����� ������� ��� ������ txDeleteDC().
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HDC txCreateCompatibleDC // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                         (double sizeX,            //!< ������ ������
                          double sizeY,            //!< ������ ������
                          HBITMAP bitmap = NULL    //!< Bitmap associated with DC
                          )
    {
    return _txCreateCompatibleDC (sizeX, sizeY, bitmap);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ��������� �� ����� ����������� � ������� BMP.
//! \return  ���������� ���������� ��������� ��������� � ������, � ����������� ������������.
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(), txTransparentBlt(),
//!
//! \remarks ����������� ����������� � ����������� �������� ��������� � ������ ("����������� �����"),
//!          ������� ����� ����� ����� ����������� ������� ��� ������ txDeleteDC().
//!
//!          ����������� �������������� ������ � ������� BMP. ���� ����� ���� ������� �������, �������� JPG, � �������������
//!          ��� �� ������ ���������� �� BMP, �� �� ����� ������ �� ���������. ����� ����������� ��������� �� �����.
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HDC txLoadImage // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                (LPCTSTR filename  //!< ��� ����� � ������������ � ������� BMP
                 )
    {
    return _txLoadImage (filename);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   ���������� ����� (�������� ���������, DC) � ������.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txDeleteDC // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                (HDC dc            //!< �������� ��������� ��� �����������
                 )
    {
    return _txDeleteDC (dc);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������.
//!
//!          ������ �����������:
//!
//!          \table
//!          \tr SRCCOPY     \td ������ �������� :) - ����� ���������������� �����\n \endtr
//!
//!          \tr BLACKNESS   \td ��������� �����-�������� ������ ������ (�����-�������� ������������). \endtr
//!          \tr WHITENESS   \td ��������� �����-�������� ����� ������ (�����-�������� ������������). \endtr
//!          \tr DSTINVERT   \td ����������� ����� �� ������-��������� (�����-�������� ������������). \endtr
//!          \tr PATCOPY     \td �������� ���� ������� ����� ������-���������.\n \endtr
//!
//!          \tr MERGECOPY   \td �������� =   �������� & ���� ������� ����� ���������. \endtr
//!          \tr MERGEPAINT  \td �������� = ~ �������� | �������� \endtr
//!          \tr NOTSRCCOPY  \td �������� = ~ �������� \endtr
//!          \tr NOTSRCERASE \td �������� = ~ (�������� | ��������) \endtr
//!          \tr PATINVERT   \td �������� =  ����� ��������� ^  �������� \endtr
//!          \tr PATPAINT    \td �������� = (����� ��������� | ~��������) | �������� \endtr
//!          \tr SRCAND      \td �������� =  �������� & �������� \endtr
//!          \tr SRCERASE    \td �������� = ~�������� & �������� \endtr
//!          \tr SRCINVERT   \td �������� =  �������� ^ �������� \endtr
//!          \tr SRCPAINT    \td �������� =  �������� | �������� \endtr
//!          \endtable
//!
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txBitBlt // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
              (HDC dest,           //!< �������� ���������� (���� ����������)
               double xDest,       //!< �-���������� �������� ������ ���� �����������-���������
               double yDest,       //!< Y-���������� �������� ������ ���� �����������-���������
               double width,       //!< ������ ����������� �����������
               double height,      //!< ������ ����������� �����������
               HDC src,            //!< �������� ��������� (������ ����������)
               double xSrc,        //!< �-���������� �������� ������ ���� �����������-���������
               double ySrc,        //!< Y-���������� �������� ������ ���� �����������-���������
               DWORD rOp = SRCCOPY //!< ��������� �������� �����������
               )
    {
    return _txBitBlt (dest, xDest, yDest, width, height,
                      src,  xSrc,  ySrc,
                      rOp);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������
//! \brief   � ������ ������������.
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txTransparentBlt // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                      (HDC dest,                 //!< �������� ���������� (���� ����������)
                       double xDest,             //!< �-���������� �������� ������ ���� �����������-���������
                       double yDest,             //!< Y-���������� �������� ������ ���� �����������-���������
                       double width,             //!< ������ ����������� �����������
                       double height,            //!< ������ ����������� �����������
                       HDC src,                  //!< �������� ��������� (������ ����������)
                       double xSrc,              //!< �-���������� �������� ������ ���� �����������-���������
                       double ySrc,              //!< Y-���������� �������� ������ ���� �����������-���������
                       COLORREF transColor = TX_BLACK //!< ����, ������� ����� ��������� ����������
                       )
    {
    return _txTransparentBlt (dest, xDest, yDest, width, height,
                              src,  xSrc,  ySrc,
                              transColor);
    }

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������
//! \brief   � ������ ������������.
//!
//!          ����������� ������ ���� ��������� � ������� txLoadImage() � �����
//!          32-������� RGBA-������. �������������� ����� (�����-�����) �����
//!          ������� �������� �� ������������ �������� �����������.
//!
//!          �����-����� ����� �������, ��������, � Adobe Photoshop, ��������
//!          "����� ����� (New Channel)" � ������� ������� (Channels). ������
//!          ���� � �����-������ ������������� ������ ������������, ����� -
//!          ������ ��������������. ��� ���� � ���������� �������� ���� �����������
//!          (� ������ RGB) ������ ���� ������.
//!
//!          ����������� ������� AlphaBlend �� Win32 API ����� �������������� �����������.
//!          � txAlphaBlend ��� ������ ��� ��������� �������������. ���� ��������������� �����,
//!          ����������� ����������� ������� AlphaBlend (��. ���������� ������� \ref _txAlhaBlend).
//!
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txAlphaBlend // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                  (HDC dest,                     //!< �������� ���������� (���� ����������)
                   double xDest,                 //!< �-���������� �������� ������ ���� �����������-���������
                   double yDest,                 //!< Y-���������� �������� ������ ���� �����������-���������
                   double width,                 //!< ������ ����������� �����������
                   double height,                //!< ������ ����������� �����������
                   HDC src,                      //!< �������� ��������� (������ ����������)
                   double xSrc,                  //!< �-���������� �������� ������ ���� �����������-���������
                   double ySrc,                  //!< Y-���������� �������� ������ ���� �����������-���������
                   double alpha = 1.0            //!< ����� ������������ �����������, � ���������� � �����-������.\n
                                                 //!<   (0 - ��� ���������, 1 - ������������ ������ �����-�����)
                   )
    {
    return _txBitBlt (dest, xDest, yDest, width, height,
                      src,  xSrc,  ySrc,
                      alpha);
    }

//=============================================================================
//
//  \name    ������ � �����
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   ���������� �-���������� ����!
//! \return  �-���������� ����.
//! \see     txMouseX(), txMouseY(), txMouseButtons()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

double txMouseX() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txMouseX();
    }

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   ���������� Y-���������� ����!
//! \return  Y-���������� ����.
//! \see     txMouseX(), txMouseY(), txMouseButtons()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

double txMouseY() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txMouseY();
    }

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   ���������� ��������� ������ ����!
//!
//!          � ������������ �������� ������������ � ������� 1-� (�������)
//!          ��� �������� ������� ����� ������ ����, 2-� - ������, 3-� -
//!          �������. ��������, ������������ ����� 5 (�������� 101) ��������
//!          ������������� ������� ������� � ����� ������, �� �� ������ ������.
//!
//! \return  ��������� ������ ����!
//! \see     txMouseX(), txMouseY(), txMouseButtons()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

int txMouseButtons() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txMouseButtons();
    }

//=============================================================================
//
//  \name    ������ � ����������� ������
//! \ingroup Dialogs
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \brief   ���� ������ � ��������� ����.
//! \return  ��������� ������ (����������� ���������� �������).
//! \warning ������������ ������ ����������� ��� ������ ������ �������!
//!          ��� ���������� �� ���������� ���������� ��� ������ <i>strcpy()</i>.
//! \see     txDialog
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

const char* txInputBox // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                       (const char* text    = NULL, //!< ����� � ��������
                        const char* caption = NULL, //!< ��������� ����
                        const char* input   = NULL  //!< �������� ������ �� ���������
                        )
    {
    return _txInputBox (text, caption, input);
    }

//-----------------------------------------------------------------------------
//! \brief   ������� ����� ��� ���������� ����.
//!
//!          ��� �������� ������ ����������� ���� �����:
//!           -# ������������ ���� ����� �� ����� �������� ������;
//!           -# ������ ������ � ������������ ��������� ���������� (���������)
//!              �������� txDialog::setLayout(), ��� ������� ����� ������������
//!              ��� ������ ����������� ���� �������� txDialog::dialogBox();
//!           -# �������������� � ����� ������ ������� txDialog::dialogProc() ���
//!              ��������� ������� ����������� ���� ��� ��������� ����� �������
//!              �� ������� � ������� �������� TX_BEGIN_MESSAGE_MAP(),
//!              TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! \see     txDialog::setLayout(), txDialog::dialogProc(), txDialog::Layout,
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

struct txDialog
    {

//-----------------------------------------------------------------------------
//! \brief   ��������� ��� ������� ���� ��������.
//!
//!          ������ �������� ����� ������������ �������� ������� �������,
//!          ��������������� � ���� txDialog::CONTROL.
//!
//! \see     txDialog::Layout, txDialog::setLayout()
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    public:
    enum CONTROL
        {
        DIALOG    = 0x00000000,                  //!< ������ �������� �������
        BUTTON    = 0xFFFF0080,                  //!< ������
        EDIT      = 0xFFFF0081,                  //!< ������������� �����
        STATIC    = 0xFFFF0082,                  //!< ��������������� ������� (�����, �������� � �.�.)
        LISTBOX   = 0xFFFF0083,                  //!< ������ � ����������
        SCROLLBAR = 0xFFFF0084,                  //!< ������ ���������
        COMBOBOX  = 0xFFFF0085,                  //!< ��������������� ������
        END       = 0x00000000                   //!< ����� �������� �������
        };

//-----------------------------------------------------------------------------
//! \brief   ��������� ��� �������� �������� ����������� ���� (��������)
//!
//!          ������ ����� �������� ������ �������� ������ ����������� ����.
//!          ��� �������� ������ �� ������� ������� � ��������� ������� (.rc):
//!
//!           - ������� ������� ��������� ���������� ���� � �����
//!           - ��������� �������� ��������� ��������
//!           - ��������� ������� - txDialog::END ��� {NULL}
//!
//! \see     txDialog::setLayout(), txDialog::dialogBox(), txDialog::dialogProc()
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    public:
    struct Layout
        {
        CONTROL     wndclass;                    //!< ��� ��������
        const char* caption;                     //!< �������� ��� �����
        WORD        id;                          //!< ������������� ��������
        short        x;                          //!< ���������� �������� ������ ����
        short        y;                          //!< ���������� ������� ������� ����
        short       sx;                          //!< ������ �� X
        short       sy;                          //!< ������ �� Y
        DWORD       style;                       //!< ����� ��������

        const char* font;                        //!< ����� ����������� ����
        WORD        fontsize;                    //!< ������ ������ ����������� ����
        };

//-----------------------------------------------------------------------------
//! \brief   �����������.
//! \see     txDialog::txDialog (const txDialog::Layout*)
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    public:
    txDialog ();

//-----------------------------------------------------------------------------
//! \brief   �����������.
//! \see     txDialog::Layout, txDialog::setLayout()
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    txDialog (const Layout* layout               //!< ����� ����������� ����
             );

//-----------------------------------------------------------------------------
//! \brief   ����������.
//-----------------------------------------------------------------------------

    virtual ~txDialog () {};

//-----------------------------------------------------------------------------
//! \brief   ������������� ������� ����� ����������� ����.
//! \return  ���������� �����.
//! \see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    const Layout* setLayout (const Layout* layout //!< ����� ����������� ����
                            );

//-----------------------------------------------------------------------------
//! \brief   ������� ��������� ��������� ����������� ����.
//!
//!          ��� ������� ���� �������������� ��� ��������� ������� ����,
//!          ��� ��������� �� � ������� �������� TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! \return  � ����������� ������� false, ��������� ��. DialogProc
//!          � <a href=msdn.com>MSDN</a>.
//! \see     txDialog::dialogBox()
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd,           //!< ����������
                            UINT _msg,           //!< ����� ���������
                            WPARAM _wParam,      //!< 1-� �������� ��������� (WORD)
                            LPARAM _lParam       //!< 2-� �������� ��������� (DWORD)
                            );

//-----------------------------------------------------------------------------
//! \brief   ��������� ���������� ����.
//! \return  ��������, ��������� � ������� EndDialog().\n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//! \see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    INT_PTR dialogBox
        (const Layout* layout = NULL, //!< ����� ����������� ����.\n
                                      //!< ���� �� ������ - ������������ ��������,
                                      //!< �������� txDialog::setLayout() ��� �������������
                                      //!< txDialog::txDialog (const txDialog::Layout*)
         size_t bufsize = 0           //!< ������ ������ ��� �������� ������� �������
                                      //!< (���� �� ������ - ������ �� ���������)
         );

//-----------------------------------------------------------------------------
//! \brief   ��������� ���������� ����.
//! \return  ��������, ��������� � ������� EndDialog().\n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//! \see     txDialog::dialogProc()
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource  //!< ������������� ����������� �������
                       );

//-----------------------------------------------------------------------------
//! \brief   �������� ����������� ����������� � �������� ������������.
//-----------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//-----------------------------------------------------------------------------
//! ��������� ���������� ������� (�.�. ������ ���� �����������).

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//-----------------------------------------------------------------------------
//! ������� ����� �������.

    private:
    const Layout* layout_;
    };

//-----------------------------------------------------------------------------
//! \brief   ��������� ����� ��������� (Message map).
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! \see     txDialog::dialogProc(), txDialog
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//! \hideinitializer
//-----------------------------------------------------------------------------

#define TX_BEGIN_MESSAGE_MAP()                                                      \
	virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)   \
		{                                                                           \
		_wnd = _wnd; _msg = _msg; _wParam = _wParam; _lParam = _lParam;				\
																					\
		switch (_msg)                                                               \
			{																		\
			case WM_NULL:

//-----------------------------------------------------------------------------
//! \brief   ��������� ����������� ��������� (Message handler) ����� ���������.
//! \param   id ������������� ���������
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! \see     txDialog::dialogProc(), txDialog
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//! \hideinitializer
//-----------------------------------------------------------------------------

#define TX_HANDLE( id )																\
            break;																	\
            case (id):

//-----------------------------------------------------------------------------
//! \brief   ������ ����� ������ (Command map) � ����� ���������.
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! \see     txDialog::dialogProc(), txDialog
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//! \hideinitializer
//-----------------------------------------------------------------------------

#define TX_COMMAND_MAP																\
            default: break;															\
			}																		\
																					\
        if (_msg == WM_COMMAND) switch (LOWORD (_wParam))							\
            {

//-----------------------------------------------------------------------------
//! \brief   ����������� ����� ���������.
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! \see     txDialog::dialogProc(), txDialog
//! \examples
//! \code
//!          C�. ���������� ������� txInputBox().
//! \endcode
//! \hideinitializer
//-----------------------------------------------------------------------------

#define TX_END_MESSAGE_MAP															\
			default: break;															\
			}																		\
																					\
        return FALSE;																\
        }

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   �������� ������� ������� DLGTEMPLATE ��� �������
//!          DialogBoxIndirect() � DialogBoxIndirectParam().
//!
//!          �������������� ������ � ����������� ������. ��� ��������� �����.
//!
//! \return  ��������� �� ����� ����������� �������� ����� ������.
//! \see     _tx_DLGTEMPLATE_Add(), txDialog::run(), CreateWindowEx()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Create (void* globalMem,     //!< ����� ������ ��� ����������
                              size_t bufsize,      //!< ������ ������ (0 - �� �����������)
                              DWORD style,         //!< ����� ����������� ����
                              DWORD exStyle,       //!< ����������� �����
                              WORD controls,       //!< ���������� ���������
                              short x,             //!< ���������� �������� ������ ����
                              short y,             //!< ���������� ������� ������� ����
                              short cx,            //!< ������ �� X
                              short cy,            //!< ������ �� Y
                              const char* caption, //!< ��������� �������
                              const char* font,    //!< ����� (������ ���� ��������� DS_SETFONT � style)
                              WORD fontsize,       //!< ������ ������ (������ ���� ��������� DS_SETFONT � style)
                              HANDLE menu = NULL   //!< ���� ����������� ����, ���� ����
                              );

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ���������� �������� ���� (��������) � ������ ������� ��� �������
//!          DialogBoxIndirect() � DialogBoxIndirectParam().
//!
//!          �������������� ������ � ����������� ������. ��� ��������� �����.
//!
//! \return  ��������� �� ����� ����������� �������� ����� ������.
//! \see     _tx_DLGTEMPLATE_Create(), txDialog::run()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr,   //!< ����� ������ ��� ����������
                           size_t bufsize,         //!< ������ ������ (0 - �� �����������)
                           DWORD style,            //!< ����� ��������
                           DWORD exStyle,          //!< ����������� ����� ��������
                           short x,                //!< ���������� �������� ������ ����
                           short y,                //!< ���������� ������� ������� ����
                           short cx,               //!< ������ �� X
                           short cy,               //!< ������ �� Y
                           WORD id,                //!< ������������� ��������
                           const char* wclass,     //!< ��� �������� (������� �����)
                           const char* caption     //!< ����� ��������
                           );

//=============================================================================
//
// \name     Back-hole (I hope, not an ass-hole:) of the library)
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ���������� ���������� ��������� ��������� (DC) ������
//! \return  ���������� ��������� ��������� ������
//! \see     txWindow(), txLock(), txUnlock(), txGDI()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HDC txDC() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txDC();
    }

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ���������� ���������� ���� ������
//! \return  ���������� ���� ������
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HWND txWindow() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txWindow();
    }

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ���������� ������ (��������� ���������).
//!
//!          ����� ������� ����� ������� Win32 GDI ���������� �������������
//!          ����� �������� txLock() � ����� �������������� � ������� txUnlock().
//!          ��� ������� � ���, ��� ���������� ����������� ���� (��� ���, ���
//!          ����� - ��������� ��������� WM_PAINT :) ���������� � ���������
//!          ��������������� ������. ������� ����������� ������ - ���
//!          ��������������� ������ ���� �� �����������.
//!
//!          txLock() ���������� EnterCriticalSection(), � ���������
//!          ���������������� �����, ����������� ����, ��� ��� �������
//!          ����������� ������. ����� ���������� ��������� ������� ���������
//!          � ���� ��������� ����������� �� �������� ������������.
//!
//!          txLock()/txUnlock() - �������������� ��������, �� ���������� ��
//!          ���������������� ��������� txBegin()/txEnd()/txUpdateWindow(),
//!          ������� �� ���������������� �����, � ������ ��������� ��������
//!          �� ���������� ����.
//!
//! \return  ��������� ����������
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txLock // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
            (bool wait = true          //!< ������� ����� ����������� ����
                                       //!< ��������������� �������
            )
    {
    return _txLock (wait);
    }

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ������������� ������
//! \return  ��������� ����������
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txUnlock() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txUnlock();
    }

//! \cond    Internal
template <typename T> inline T _txUnlock (T value); // Needed for txGDI() macro
//! \endcond Internal

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   ����� ������� Win32 GDI � �������������� ����������� � ��������������
//! \return  ��������, ������������ ���������� �������� GDI.
//! \param   cmd ������� GDI (��������, ������������ ��������)
//! \note    ���� � ������ ������� GDI ������������ �������, �� ����������� �������
//!          ������, ����� ��������� ���� ��������, ��� ��� txGDI() ���-���� ������.
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \hideinitializer
//! \examples
//! \code
//!          txGDI <b>((</b> Rectangle (txDC(), x1, y1, x2, y2) <b>))</b>;
//! \endcode
//-----------------------------------------------------------------------------

#define txGDI( cmd ) _txUnlock ( (_txLock (true), (cmd)) )

//-----------------------------------------------------------------------------
//! \ingroup Technical
//! \brief   ���������� ������ � ����������� � ������� ������ ����������.
//! \return  ������ � ����������� � ������� ������ ����������.
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

const char* txVersion() // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
    {
    return _txVersion();
    }

//=============================================================================
//
// \name     Miscellanous functions
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ���������� ������� �������
//! \param   arr ��� �������
//! \return  ������ �������
//! \warning ����������� ������� ������ � ��� �������� ������ ���� ��������
//!          � ����� ������������� sizearr().
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define sizearr( arr )   ( sizeof (arr) / sizeof (arr)[0] )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ��������, ��������� �� �������� � ������ ���������� ��������� [a; b]
//! \return  ���� a <= x && x <= b, �� ������, ���� ��� - ����
//! \hideinitializer
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

template <typename T>
inline
bool In // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
        (T x, //!< ����������� ��������
         T a, //!< ����� ������� (������������)
         T b  //!< ������ ������� (������������)
         )
    {
    return a <= x && x <= b;
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ��������, ��������� �� ����� pt ������ �������������� rect
//! \return  ��������� ��������
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

inline bool In // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
               (const COORD& pt,       //!< ����������� �����
                const SMALL_RECT& rect //!< �������������
                )
    {
    return In (pt.X, rect.Left, rect.Right) &&
           In (pt.Y, rect.Top,  rect.Bottom);
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ���������� ������������ �� ���� �����
//! \param   a ���� �� ����� :)
//! \param   b ������ �� ����� :)
//! \return  ������������ �� ���� ����� a � b
//! \hideinitializer
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define MAX( a, b )      ( (a) > (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ���������� ����������� �� ���� �����
//! \param   a ���� �� ����� :)
//! \param   b ������ �� ����� :)
//! \return  ����������� �� ���� ����� a � b
//! \hideinitializer
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define MIN( a, b )      ( (a) < (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ��������� ��������� �����
//! \param   range ������ ������� ��������� (�� ������� ���� �������).
//! \return  ��������� ����� ����� � ��������� [0; range).\n
//!          �� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//! \hideinitializer
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define random( range )  ( rand() % (range) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ����������� ���������� ��������� �� ������������ �����.
//!
//!          �� ����� �������� ���������� ����������� � ���� ������
//!          ������������� ��������������.
//!
//! \return  ��������� ���������� ���������� ����.
//! \see     txUpdateWindow()
//! \examples
//! \code
//!          txSleep (500); // ������� ����������
//! \endcode
//-----------------------------------------------------------------------------

bool txSleep // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
             (int time   //!< �������� � �������������
              )
    {
    return _txSleep (time);
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ������������� �������� ����.
//!
//!          ������ ���������������:
//!
//!          \table
//!          \tr SND_ASYNC       \td ���� ������������� ������������ � ������� ���������.\n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL). \endtr
//!          \tr SND_SYNC        \td ���������� ��������� ������������������ �� ���������
//!                                  ��������������� �����. \endtr
//!          \tr SND_LOOP        \td ����������� ���� ��� ���������������.\n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL).\n \endtr
//!
//!          \tr SND_NODEFAULT   \td �� ������������ ���� �� ���������, ���� ������ ���������
//!                                  ��������� �������� ����. \endtr
//!          \tr SND_NOSTOP      \td ���� �����-���� ���� ��� �������������, �� �������������
//!                                  ��� ��� ��������������� ���������� �����. \endtr
//!          \tr SND_APPLICATION \td ����������� ����, ��������� ���������, ������������������
//!                                  ��� ������� ���� �������� ������. \endtr
//!          \endtable
//!
//! \return  ���� �������� ���� ������� - true, ����� - false.
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txPlaySound // ��� �� ������ � TXLib.h! ��. "�������� - ������: ����������" � TXLib Help!
                 (const char* filename = NULL, //!< ��� ��������� �����.
                                               //!< ���� NULL - ������������� ����.
                  DWORD mode = SND_ASYNC       //!< ����� ���������������
                  )
    {
    return _txPlaySound (filename, mode);
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ������� ����������� ���������������� ��������������� ���������.
//! \return  ������ false
//! \see     TX_NEEDED(), _
//! \examples
//! \code
//!          TX_THROW ("������ �������� ����� '%s'" _ fileName);
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY

bool TX_THROW (msg                             //!< ��������� � ������� printf().\n
                                               //!< ����� ������������ %d, %s � �.�., ��� ����
                                               //!< ����� ��������� <b>����������� ��������
                                               //!< ������������� "_" � �� �������.</b>
                                               //!<
                                               //!< msg ����� ���� NULL.
         );

#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ������� ��� ����� � ����� ������, ��� ��������� ����� TX_PRINT_HERE().
//! \examples
//! \code
//!          TX_PRINT_HERE();
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
int TX_PRINT_HERE();
#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ������, ����������� �������� ���������� ����� ���������� � �����-���� ������ ������.
//! \note    <b>������ ������������� ������ ���������������� � �������.</b>
//! \see     TX_THROW()
//! \examples
//! \code
//!          TX_THROW ("������ ������ ������ %d ����� '%s'" _ lineNum _ fileName);
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define _ ,
#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ������� ��������������� ��������� � ������ �������� ��������.
//! \brief   ������������, ���� ���� ������ if() :)
//! \note    <b>��������������, ��� �������� � ������ �������� ���������� 0 ��� false.</b>
//! \note    <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) ������������
//!          � ������ ��������.</b>
//! \return  ������ false
//! \examples
//! \code
//!          FILE* input = fopen ("a.txt", "r"); input TX_NEEDED;
//!          fgets (str, sizeof (str) - 1, input) TX_NEEDED;
//!          (fclose (input) != 0) TX_NEEDED;
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
bool TX_NEEDED;
#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ������, ��������������� ����� ������� �������, ��� ��� ��������� ����� �
//! \brief   ����� ������, ���� ����������� ����� ������� �� �������������� ������������.
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
const char __TX_FUNCTION__[];
#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   ����� ��
//! \return  ����� ��
//! \examples
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//=============================================================================
// ����������� ���������
//=============================================================================

//! \ingroup Technical
//! \brief   �������� ������� ������� ������� (��)

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//! \ingroup Technical
//! \brief   ����� �������

const char   _TX_CONSOLE_FONT[]           = "Lucida Console";

//! \ingroup Technical
//! \brief   ���� ������ �������

const COLORREF _TX_CONSOLE_COLOR          = txLIGHTGRAY;

//! \ingroup Technical
//! \brief   ������� �������� �������� (��)

const int    _TX_TIMEOUT                  = 1000;

//! \ingroup Technical
//! \brief   �������� ���������� ������ (��)

const int    _TX_WINDOW_UPDATE_INTERVAL   = 10;

//! \ingroup Technical
//! \brief   �� �������� ������������� ���������� ����
//!
//!          �������� ����� ���������� TXLib.h � ���������.

#ifdef FOR_DOXYGEN_ONLY
#define      _TX_NO_HIDE_CONSOLE
#endif

//! \ingroup Technical
//! \brief   ��� ����� � ����� ������, ��������� ������� ����������.

#ifdef FOR_DOXYGEN_ONLY
#define      __TX_FILELINE__                __FILE__ ( __LINE__ )
#endif

//! \ingroup Technical
//! \brief   �������� ���������� ����������� ���������� ����������.
//!
//!          ����������� ���� ����� ������ TX_TRACE, ������� ������������� �����
//!          ������ ���������� (statement). �� ��������� ����������� ���������.
//!
//!          �������� ����� ���������� TXLib.h � ���������.

#ifdef FOR_DOXYGEN_ONLY
#define      _TX_TRACE
#endif

//! \ingroup Technical
//! \brief   ������ ��� �����������.
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(),
//!          �� ����� ����� ����������� ���������-���������, ��������, WinTail.
//!
//!          �������� ����� ���������� TXLib.h � ���������.

#ifdef FOR_DOXYGEN_ONLY
#define      TX_TRACE                       OutputDebugString (__TX_FILELINE__ ": ");
#endif

//! \ingroup Technical
//! \brief   ������� ������ ����������.
//!          ��� ��������� ������������� ����������� ��� ���������� ������.
//! \see     txVersion()

#define      _TX_VERSION                    "[Version 0.01 alpha, build 72]"

//=============================================================================
//
// ����������
//
//=============================================================================
//! \cond    Internal
//@{

bool _txInitialize (int sizeX, int sizeY, bool centered);
bool _txCleanup();
void _txOnExit();
bool _txCheck (const char msg[] = "");

bool _txCanvas_SetDefaults();
bool _txConsole_SetDefaults();

HWND _txCanvas_CreateWindow (POINT size);
bool _txCanvas_OK();
bool _txCanvas_DestroyWindow();
int  _txCanvas_SetLockRefresh (int count);
bool _txCanvas_OnCreate (HWND wnd);
bool _txCanvas_OnDestroy (HWND wnd);
bool _txCanvas_OnClose (HWND);
bool _txCanvas_OnPaint (HWND wnd);
bool _txCanvas_OnChar (HWND wnd, WPARAM ch);
bool _txCanvas_OnTimer (HWND wnd, WPARAM id);
bool _txCanvas_OnMouse (HWND wnd, WPARAM buttons, LPARAM coords);
bool _txCanvas_OnCmdAbout (HWND wnd, WPARAM cmd);
bool _txCanvas_OnCmdConsole (HWND wnd, WPARAM cmd);
DWORD WINAPI _txCanvas_ThreadProc (LPVOID data);
LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

HDC  _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL);
bool _txBuffer_Delete (HDC dc);
bool _txSelect (HGDIOBJ obj, HDC dc);

bool _txConsole_Attach();
bool _txConsole_OK();
bool _txConsole_Detach();
bool _txConsole_Draw (HDC dc);
HWND _txConsole_GetWindow();

inline
int  _txReturn1()        { return 1; }

#define _txWaitFor(p)    { for (int __i##__LINE__ = 0; __i##__LINE__ < _TX_TIMEOUT/10; __i##__LINE__++) \
                             { if ((p) != 0) break; Sleep (10); } }

//=============================================================================
// �����������
//=============================================================================

#define __TX_FILELINE__                      __TX_FILELINE__1 (__FILE__, __LINE__)
#define __TX_FILELINE__1(__file__, __line__) __TX_FILELINE__2 (__file__, __line__)
#define __TX_FILELINE__2(__file__, __line__) __file__ " (" #__line__ ")"

#if defined (__GNUC__)
#define __TX_FUNCTION__   __PRETTY_FUNCTION__

#elif defined (__FUNCSIG__)
#define __TX_FUNCTION__   __FUNCSIG__

#elif defined (__BORLANDC__) && (__BORLANDC__ >= 0x550)
#define __TX_FUNCTION__   __FUNC__

#elif defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define __TX_FUNCTION__   __func__

#else
#define __TX_FUNCTION__   __TX_FILELINE__
#endif

#define _                ,

#ifndef NDEBUG

#undef  assert
#define assert(p)         ( !(p)? (TX_THROW ("\aAssertion failed: \"%s\"" _ #p), 0) : _txReturn1() )
#define TX_NEEDED         || TX_THROW (NULL)

#define TX_THROW( msg )   _txThrow (__FILE__, __LINE__, __TX_FUNCTION__, (DWORD)(-1), msg)
#define TX_PRINT_HERE()   printf ("%s (%d) %s(): Here... :)\n", __FILE__, __LINE__, __TX_FUNCTION__)

#else

#undef  assert
#define assert(p)         ( 1 )
#define TX_NEEDED

#define TX_THROW(msg)
#define TX_PRINT_HERE()

#endif

#ifndef TX_TRACE
#define TX_TRACE          OutputDebugString (__TX_FILELINE__ ": ");
#endif

#ifdef  _TX_TRACE
#define $                 TX_TRACE
#else
#define $
#endif

bool _txThrow (const char file[], int line, const char func[], DWORD error, const char msg[], ...);

#ifndef NDEBUG
int  _txInitTrace = (OutputDebugString ("\n"),
                     OutputDebugString ("The Dumb Artist Library (TXLib) "
                                        _TX_VERSION " (c) Ded, 2005-08 (Ilya Dedinsky <ded@concord.ru>, http://ded32.net.ru): "
                                        "\"" __FILE__ "\", compiled "__DATE__ " " __TIME__ "\n"),
                     OutputDebugString ("\n"), 1);
#endif

//=============================================================================
// ������ ������� ���������
//=============================================================================

#define _TX_IMPORT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, true)

#define _TX_IMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, false)

FARPROC _txImport (const char lib[], const char name[], int required = true);

//-----------------------------------------------------------------------------
// Dev-CPP doesn't link with GDI32 by default, so do sunrise by hand. :(
// <tears>

//! \cond Namespaces
namespace Win32 {
//! \endcond Namespaces

_TX_IMPORT ("GDI32", int,      GetDeviceCaps,          (HDC dc, int index));
_TX_IMPORT ("GDI32", HDC,      CreateCompatibleDC,     (HDC dc));
_TX_IMPORT ("GDI32", HBITMAP,  CreateCompatibleBitmap, (HDC dc, int width, int height));
_TX_IMPORT ("GDI32", HGDIOBJ,  GetStockObject,         (int object));
_TX_IMPORT ("GDI32", HGDIOBJ,  SelectObject,           (HDC dc, HGDIOBJ object));
_TX_IMPORT ("GDI32", HGDIOBJ,  GetCurrentObject,       (HDC dc, UINT objectType));
_TX_IMPORT ("GDI32", int,      GetObjectA,             (HGDIOBJ obj, int bufsize, LPVOID buffer));
_TX_IMPORT ("GDI32", BOOL,     DeleteDC,               (HDC dc));
_TX_IMPORT ("GDI32", BOOL,     DeleteObject,           (HGDIOBJ object));
_TX_IMPORT ("GDI32", COLORREF, SetTextColor,           (HDC dc, COLORREF color));
_TX_IMPORT ("GDI32", int,      SetBkMode,              (HDC dc, int bkMode));
_TX_IMPORT ("GDI32", HFONT,    CreateFontA,            (int height, int width, int escapement, int orientation,
                                                        int weight, DWORD italic, DWORD underline, DWORD strikeout,
                                                        DWORD charSet, DWORD outputPrec, DWORD clipPrec,
                                                        DWORD quality, DWORD pitchAndFamily, LPCTSTR face));
_TX_IMPORT ("GDI32", int,      EnumFontFamiliesExA,    (HDC dc, LPLOGFONT logFont, FONTENUMPROC enumProc,
                                                        LPARAM lParam, DWORD reserved));
_TX_IMPORT ("GDI32", COLORREF, SetPixel,               (HDC dc, int x, int y, COLORREF color));
_TX_IMPORT ("GDI32", COLORREF, GetPixel,               (HDC dc, int x, int y));
_TX_IMPORT ("GDI32", HPEN,     CreatePen,              (int penStyle, int width, COLORREF color));
_TX_IMPORT ("GDI32", HBRUSH,   CreateSolidBrush,       (COLORREF color));
_TX_IMPORT ("GDI32", BOOL,     MoveToEx,               (HDC dc, int x, int y, LPPOINT point));
_TX_IMPORT ("GDI32", BOOL,     LineTo,                 (HDC dc, int x, int y));
_TX_IMPORT ("GDI32", BOOL,     Polygon,                (HDC dc, CONST POINT* points, int n));
_TX_IMPORT ("GDI32", BOOL,     Rectangle,              (HDC dc, int x0, int y0, int x1, int y1));
_TX_IMPORT ("GDI32", BOOL,     Ellipse,                (HDC dc, int x0, int y0, int x1, int y1));
_TX_IMPORT ("GDI32", BOOL,     Arc,                    (HDC dc, int x0, int y0, int x1, int y1,
                                                        int xStart, int yStart, int xEnd, int yEnd));
_TX_IMPORT ("GDI32", BOOL,     Pie,                    (HDC dc, int x0, int y0, int x1, int y1,
                                                        int xStart, int yStart, int xEnd, int yEnd));
_TX_IMPORT ("GDI32", BOOL,     Chord,                  (HDC dc, int x0, int y0, int x1, int y1,
                                                        int xStart, int yStart, int xEnd, int yEnd));
_TX_IMPORT ("GDI32", BOOL,     TextOutA,               (HDC dc, int x, int y, LPCTSTR string, int length));
_TX_IMPORT ("GDI32", UINT,     SetTextAlign,           (HDC dc, UINT mode));
_TX_IMPORT ("GDI32", BOOL,     GetTextExtentPoint32A,  (HDC dc, LPCTSTR string, int length, LPSIZE size));
_TX_IMPORT ("GDI32", BOOL,     ExtFloodFill,           (HDC dc, int x, int y, COLORREF color, UINT type));
_TX_IMPORT ("GDI32", BOOL,     BitBlt,                 (HDC dest, int xDest, int yDest, int width, int height,
                                                        HDC src,  int xSrc,  int ySrc,  DWORD rOp));
_TX_IMPORT ("GDI32", BOOL,     PatBlt,                 (HDC dc, int x0, int y0, int width, int height, DWORD rOp));
_TX_IMPORT ("GDI32", int,      SetROP2,                (HDC dc, int mode));
_TX_IMPORT ("GDI32", HRGN,     CreateRectRgn,          (int x0, int y0, int x1, int y1));
//_TX_IMPORT ("GDI32", BOOL,   GetBitmapDimensionEx,   (HBITMAP bitmap, LPSIZE dimensions));

_TX_IMPORT ("USER32",HANDLE,   LoadImageA,             (HINSTANCE inst, LPCTSTR name, UINT type,
                                                        int sizex, int sizey, UINT mode));

_TX_IMPORT ("WinMM", BOOL,     PlaySound,              (LPCSTR sound, HMODULE mod, DWORD mode));

_TX_IMPORT_OPT ("MSImg32",BOOL,TransparentBlt,         (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                        HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                        UINT transparentColor));
_TX_IMPORT_OPT ("MSImg32",BOOL,AlphaBlend,             (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                        HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                        BLENDFUNCTION blending));
//! \cond Namespaces
}  // namespace Win32
using namespace Win32;
//! \endcond Namespaces

// </tears>
//=============================================================================
// ���������� ������
//=============================================================================

HWND             _txCanvas_Wnd         = NULL;
HDC              _txCanvas_BackBuf[2]  = {NULL, NULL};
UINT             _txCanvas_Timer       = 0;
HANDLE           _txCanvas_Thread      = NULL;
CRITICAL_SECTION _txCanvas_LockBackBuf = {0};
int              _txCanvas_LockRefresh = 0;

HWND             _txConsole_Wnd        = NULL;
bool             _txConsole_CursorMode = true;

bool             _txRunning            = false;
bool             _txExit               = false;

int              _txCurMouseX          = 0;
int              _txCurMouseY          = 0;
int              _txCurMouseButtons    = 0;

//=============================================================================
// �������������� �������������� ������� ���������� ���� ���� TXLib
//=============================================================================

#define _txIDM_ABOUT        40000
#define _txIDM_CONSOLE      40001

//=============================================================================
// ���������� ������� ����������
//=============================================================================

bool _txCreateWindow (double sizeX, double sizeY, bool centered)
    {
$   if (_txOK()) return false;
$   return _txInitialize ((int)sizeX, (int)sizeY, centered);
    }

//-----------------------------------------------------------------------------

inline
bool _txOK()
    {
$   return _txConsole_OK() &&
           _txCanvas_OK();
    }

//-----------------------------------------------------------------------------

const char* _txVersion()
    {
$   return _TX_VERSION;
    }

//-----------------------------------------------------------------------------

inline
HDC _txDC()
    {
$   return _txCanvas_BackBuf[0];
    }

//-----------------------------------------------------------------------------

inline
HWND _txWindow()
    {
$   return _txCanvas_Wnd;
    }

//-----------------------------------------------------------------------------

POINT _txGetExtent()
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   RECT r = {0};
$   GetClientRect (_txWindow(), &r);
$   POINT size = { r.right - r.left, r.bottom - r.top };
$   return size;
    }

inline int _txGetExtentX() { $ return _txGetExtent().x; }
inline int _txGetExtentY() { $ return _txGetExtent().y; }

//-----------------------------------------------------------------------------

bool _txClear()
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());
$   POINT size = _txGetExtent();

$   return txGDI ((Win32::PatBlt (_txDC(), 0, 0, size.x, size.y, PATCOPY) != 0));
    }

//-----------------------------------------------------------------------------

bool _txSetColor (COLORREF color, int thickness)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   return _txSelect (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), thickness, color), _txDC()) &&
            txGDI   ((Win32::SetTextColor (_txDC(), color) != 0));
    }

//-----------------------------------------------------------------------------

bool _txColor (double r, double g, double b)
    {
$   if (r > 1) r = 1; if (r < 0) r = 0;
$   if (g > 1) g = 1; if (g < 0) g = 0;
$   if (b > 1) b = 1; if (b < 0) b = 0;
$   return _txSetColor (RGB (r*255, g*255, b*255), 1);
    }

//-----------------------------------------------------------------------------

COLORREF _txGetColor()
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (_txDC(), OBJ_PEN))); obj TX_NEEDED;

$   char buf [MAX (sizeof (LOGPEN), sizeof (EXTLOGPEN))] = {0};

$   int size = GetObject (obj, 0, NULL);
$   GetObject (obj, sizeof (buf), buf) TX_NEEDED;

$   return (size == sizeof (LOGPEN))? ((LOGPEN*)buf)->lopnColor : ((EXTLOGPEN*)buf)->elpColor;
    }

//-----------------------------------------------------------------------------

bool _txSetFillColor (COLORREF color)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   return _txSelect ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                                 Win32::CreateSolidBrush (color),
                      _txDC());
    }

//-----------------------------------------------------------------------------

bool _txFillColor (double r, double g, double b)
    {
$   if (r > 1) r = 1; if (r < 0) r = 0;
$   if (g > 1) g = 1; if (g < 0) g = 0;
$   if (b > 1) b = 1; if (b < 0) b = 0;
$   return _txSetFillColor (RGB (r*255, g*255, b*255));
    }

//-----------------------------------------------------------------------------

COLORREF _txGetFillColor()
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (_txDC(), OBJ_BRUSH))); obj TX_NEEDED;

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) TX_NEEDED;

$   return buf.lbColor;
    }

//-----------------------------------------------------------------------------

int _txExtractColor (COLORREF color, COLORREF component)
    {
$   switch (component)
        {
        case TX_RED:
        case TX_HUE:        $ return (BYTE)(color >>  0);

        case TX_GREEN:
        case TX_SATURATION: $ return (BYTE)(color >>  8);

        case TX_BLUE:
        case TX_LIGHTNESS:  $ return (BYTE)(color >> 16);

        default:            $ return -1;
        }
    }

//---------------------------------------------------------------------------

COLORREF _txRGB2HSL (COLORREF color)
    {
$   int r = _txExtractColor (color, TX_RED),
        g = _txExtractColor (color, TX_GREEN),
        b = _txExtractColor (color, TX_BLUE);

$   double m1 = MAX (MAX (r, g), b) / 255.0,
           m2 = MIN (MIN (r, g), b) / 255.0,
           dm = m1 - m2,
           sm = m1 + m2,

           ir = r / 255.0,
           ig = g / 255.0,
           ib = b / 255.0,

           ih = 0,
           is = 0,
           il = sm / 2;

$   const double prec = 0.001;

$   if (fabs (dm) < prec)
        {
$       is = dm / ((sm <= 1)? sm : (2-sm));

$       double cr = (m1 - ir) / dm,
               cg = (m1 - ig) / dm,
               cb = (m1 - ib) / dm;

$       if (fabs (ir - m1) < prec) ih =     cb - cg;
$       if (fabs (ig - m1) < prec) ih = 2 + cr - cb;
$       if (fabs (ib - m1) < prec) ih = 4 + cg - cr;
        }

$   return RGB ((int)(ih >= 0? ih*60 : ih*60 + 360), (int)(is*255), (int)(il*255));
    }

//---------------------------------------------------------------------------

COLORREF _txHSL2RGB (COLORREF color)
    {
    struct xRGB
        {
        static double calc (double h, double m1, double m2)
            {
$           if (h < 0)   h += 360;
$           if (h > 360) h -= 360;

$           return (h <  60)? m1 + (m2-m1) *      h  / 60 :
                   (h < 180)? m2 :
                   (h < 240)? m1 + (m2-m1) * (240-h) / 60 :
                              m1;
            }
        };

$   int h = _txExtractColor (color, TX_HUE),
        s = _txExtractColor (color, TX_SATURATION),
        l = _txExtractColor (color, TX_LIGHTNESS);

$   double ih = h,
           il = l / 100.0,
           is = s / 100.0,

           m2 = (il <= 0.5)? il * (1 + is) : il + is - il * is,
           m1 = 2 * il - m2,

           ir = s? xRGB::calc (ih + 120, m1, m2) : il,
           ig = s? xRGB::calc (ih,       m1, m2) : il,
           ib = s? xRGB::calc (ih - 120, m1, m2) : il;

$   return RGB (ir * 255, ig * 255, ib * 255);
    }

//-----------------------------------------------------------------------------

bool _txSetPixel (double x, double y, COLORREF color)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   txGDI ((Win32::SetPixel (_txDC(), (int)x, (int)y, color)));

$   RECT r = { (int)x, (int)y, (int)x, (int)y };
$   InvalidateRect (_txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txPixel (double x, double y, double r, double g, double b)
    {
$   if (r > 1) r = 1; if (r < 0) r = 0;
$   if (g > 1) g = 1; if (g < 0) g = 0;
$   if (b > 1) b = 1; if (b < 0) b = 0;
$   return _txSetPixel (x, y, RGB (r*255, g*255, b*255));
    }

//-----------------------------------------------------------------------------

COLORREF _txGetPixel (double x, double y)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   return txGDI ((Win32::GetPixel (_txDC(), (int)x, (int)y)));
    }

//-----------------------------------------------------------------------------

bool _txLine (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   txGDI ((Win32::MoveToEx (_txDC(), (int)x0, (int)y0, NULL))) TX_NEEDED;
$   txGDI ((Win32::LineTo   (_txDC(), (int)x1, (int)y1)))       TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (_txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txRectangle (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   txGDI ((Win32::Rectangle (_txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (_txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txPolygon (POINT* points, int npoints)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   return txGDI ((Win32::Polygon (_txDC(), points, npoints) != 0));
    }

//-----------------------------------------------------------------------------

bool _txEllipse (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   txGDI ((Win32::Ellipse (_txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (_txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCircle (double x, double y, double r)
    {
$   return _txEllipse (x-r, y-r, x+r, y+r);
    }

//-----------------------------------------------------------------------------

bool _txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Arc (_txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                        center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                        center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------

bool _txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Pie (_txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                        center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                        center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------

bool _txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Chord (_txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                          center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                          center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------

bool _txTextOut (double x, double y, const char text[])
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   int len = (int) strlen (text);
$   txGDI ((Win32::TextOut (_txDC(), (int)x, (int)y, text, len))) TX_NEEDED;

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (_txDC(), text, len, &size))) TX_NEEDED;

$   RECT r = { (int)x, (int)y, (int)x + size.cx, (int)y + size.cy };
$   InvalidateRect (_txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

SIZE _txGetTextExtent (const char* text)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (_txDC(), text, (int) strlen (text), &size))) TX_NEEDED;

$   return size;
    }

inline int _txGetTextExtentX (const char* text) { $ return _txGetTextExtent (text) . cx; }
inline int _txGetTextExtentY (const char* text) { $ return _txGetTextExtent (text) . cy; }

//-----------------------------------------------------------------------------

bool _txSelectFont (const char* name, double sizeY, double sizeX,
                    int bold, bool italic, bool underline, bool strikeout)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   _txSelect (_txFontExist (name)? CreateFont ((int)sizeY, (int) ((int)sizeX? sizeX : sizeY/3), 0, 0,
                                                bold, italic, underline, strikeout,
                                                DEFAULT_CHARSET,
                                                OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                                DEFAULT_QUALITY, FIXED_PITCH, name)
                                   :
                                   GetStockObject (SYSTEM_FIXED_FONT),
               _txDC());

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txSetTextAlign (unsigned align)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   txGDI ((Win32::SetTextAlign (_txDC(), align)));
$   return true;
    }

//-----------------------------------------------------------------------------

LOGFONT* _txFontExist (const char* name)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   static LOGFONT font = {0};
$   font.lfCharSet = DEFAULT_CHARSET;
$   strncpy_s (font.lfFaceName, name, sizeof (font.lfFaceName) - 1);

    struct enumFonts
        {
        static int CALLBACK Proc (const LOGFONT* fnt, const TEXTMETRIC*, DWORD, LPARAM data)
            {
$           assert (fnt); assert (data);
#ifndef __STRICT_ANSI__
$           return _strnicmp (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
#else
$           return  strncmp  (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
#endif
            }
        };

$   return txGDI ((Win32::EnumFontFamiliesEx (_txDC(), &font, enumFonts::Proc, (LPARAM)&font, 0) == 0? &font : NULL));
    }

//-----------------------------------------------------------------------------

bool _txFloodFill (double x, double y, COLORREF color, DWORD mode)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());
$   if (color == TX_TRANSPARENT) color = _txGetPixel (x, y);

$   return txGDI ((Win32::ExtFloodFill (_txDC(), (int)x, (int)y, color, mode) != 0));
    }

//-----------------------------------------------------------------------------

bool _txSetROP2 (int mode)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   return txGDI ((Win32::SetROP2 (_txDC(), mode) != 0));
    }

//-----------------------------------------------------------------------------

HDC _txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());
$   POINT size = { (int)sizeX, (int)sizeY };
$   HDC dc = _txBuffer_Create (_txWindow(), &size, bitmap); dc TX_NEEDED;
$   return dc;
    }

//-----------------------------------------------------------------------------

HDC _txLoadImage (LPCTSTR name)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   HBITMAP image = (HBITMAP) LoadImage (NULL, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
$   if (!image) return NULL;

$   HDC dc = _txCreateCompatibleDC (0, 0, image);

$   return dc;
    }

//-----------------------------------------------------------------------------

bool _txDeleteDC (HDC dc)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());
$   return _txBuffer_Delete (dc);
    }

//-----------------------------------------------------------------------------

bool _txBitBlt (HDC dest, double xDest, double yDest, double width, double height,
                HDC src,  double xSrc,  double ySrc,  DWORD rOp)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   return txGDI ((Win32::BitBlt (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                                  src,  (int)xSrc,  (int)ySrc, rOp) != 0));
    }

//-----------------------------------------------------------------------------

bool _txTransparentBlt (HDC dest, double destX, double destY, double sizeX, double sizeY,
                        HDC src,  double srcX,  double srcY,  COLORREF transColor)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());
$   if (!TransparentBlt) return false;

$   return Win32::TransparentBlt (dest, (int)destX, (int)destY, (int)sizeX, (int)sizeY,
                                  src,  (int)srcX,  (int)srcY,  (int)sizeX, (int)sizeY, transColor) != 0;
    }

//-----------------------------------------------------------------------------

bool _txAlphaBlend (HDC dest, double destX, double destY, double sizeX, double sizeY,
                    HDC src,  double srcX,  double srcY,  double alpha)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());
$   if (!AlphaBlend) return false;

$   if (alpha < 0) alpha = 0;
$   if (alpha > 1) alpha = 1;

#ifndef AC_SRC_ALPHA
#define AC_SRC_ALPHA 0x01   // On some old MinGW versions, this is not defined.
#endif

$   BLENDFUNCTION blend = {AC_SRC_OVER, 0, (BYTE) (alpha * 255), AC_SRC_ALPHA};

$   return Win32::AlphaBlend (dest, (int)destX, (int)destY, (int)sizeX, (int)sizeY,
                              src,  (int)srcX,  (int)srcY,  (int)sizeX, (int)sizeY, blend) != 0;
    }

//-----------------------------------------------------------------------------

bool _txSelectRegion (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   HRGN rgn = CreateRectRgn ((int)x0, (int)y0, (int)x1, (int)y1);
$   return _txSelectObject (rgn);
    }

//-----------------------------------------------------------------------------

bool _txSelectObject (HGDIOBJ obj)
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());
$   return _txSelect (obj, _txDC());
    }

//-----------------------------------------------------------------------------

inline
int _txBegin()
    {
$   _txCanvas_SetLockRefresh (_txCanvas_LockRefresh + 1);
$   return _txCanvas_LockRefresh;
    }

//-----------------------------------------------------------------------------

inline
int _txEnd()
    {
$   _txCanvas_SetLockRefresh (_txCanvas_LockRefresh - 1);
$   return _txCanvas_LockRefresh;
    }

//-----------------------------------------------------------------------------

inline
bool _txUpdateWindow (bool update)
    {
$   return _txCanvas_SetLockRefresh (update? 0 : 1) != 0;
    }

//-----------------------------------------------------------------------------

inline
bool _txSleep (int time)
    {
$   int old = _txCanvas_SetLockRefresh (0);

$   Sleep (time);

$   _txCanvas_SetLockRefresh (old);
$   return old != 0;
    }

//-----------------------------------------------------------------------------

bool _txTextCursor (bool mode)
    {
$   bool old = _txConsole_CursorMode;

$   _txConsole_CursorMode = mode;

$   return old;
    }

//-----------------------------------------------------------------------------

inline
bool _txLock (bool wait)
    {
$   if (wait) { return    EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { return TryEnterCriticalSection (&_txCanvas_LockBackBuf) != 0;  }
    }

//-----------------------------------------------------------------------------

inline
bool _txUnlock()
    {
$   LeaveCriticalSection (&_txCanvas_LockBackBuf);
$   return true;
    }

//-----------------------------------------------------------------------------

template <typename T> inline
T _txUnlock (T value)
    {
$   _txUnlock();
$   return value;
    }

//-----------------------------------------------------------------------------

inline double  _txMouseX()       { $ return _txCurMouseX;       }
inline double  _txMouseY()       { $ return _txCurMouseY;       }
inline int     _txMouseButtons() { $ return _txCurMouseButtons; }

//-----------------------------------------------------------------------------

bool _txPlaySound (const char* filename, DWORD mode)
    {
$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;
$   if (!filename) mode = SND_PURGE;

$   return PlaySound (filename, NULL, mode) != 0;
    }

//-----------------------------------------------------------------------------

bool _txSetDefaults()
    {
$   _txCheck (__TX_FUNCTION__); assert (_txOK());

$   return _txCanvas_SetDefaults() &&
           _txConsole_SetDefaults();
    }

//=============================================================================
// ������ � ����������� ������
//=============================================================================

const char* _txInputBox (const char* text, const char* caption, const char* input)
    {

    // ��������� ����� EXE-�����, �� ������, ���� ���-��� ��������� ������ �������� �������

$   char name[256] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1) TX_NEEDED;

    // ���� �� ������� ���������, ������������ �����-����� ������� �������. � ��� ������?!..

$   if (!text)    text    = "������� ������:";
$   if (!caption) caption = name;
$   if (!input)   input   = "";

    // �������������� ��������� �������. ��� ��������� � GetDlgItemText().
    // ���� ������ �������� �� �������, � ���������� ��������, �� ��� �������� � ��� �������������.
    // � ��� �� ��� ������� ������� �����. � ��� ������? ��������� �������� ������ � ������ ����
    // ����������������. ������� ��� ������������� �� ��� ��� ����� ��������� �� ����� ����������,
    // �����������. ��-��, �� ��� ����������, ��� � txDialog::dialogBox() � _tx_DLGTEMPLATE_...()
    // ��� ��� ����� ���������... �_�

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    // ������� ������ (����) ������� � ���� ������� ��������.
    // � ������� ������� ������� ����� � ��������� txDialog::Layout � �������� �� ������
    // txDialog ���� ������ ���������� ����� �� �������� ������� ������� � .rc - �����.
    // ��. �������� ���������� rc-����� � ������������ �� Win32 (MSDN, http://msdn.com).

$   txDialog::Layout layout[] =

    //----------------------+-----------+-------------+-----------------+-----------------------------------------------------
    //     ��� ��������     | ���       | ����������- |   ����������    | ����� ���������
    //     �������          | ��������  | ���, ������-|-----------------| (��. �������� ��������� ������� � MSDN).
    //                      |           | ��� � ���   | X | Y |���.|���.|
    //----------------------+-----------+-------------+---+---+----+----+-----------------------------------------------------
    //                      |           |             |   |   |    |    |
        {{ txDialog::DIALOG,   caption,   0,             0,  0, 240,  85                                                     },
         { txDialog::STATIC,   text,      ID_TEXT_,     10, 10, 150,  40, SS_LEFT                                            },
         { txDialog::EDIT,     input,     ID_INPUT_,    10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP  },
         { txDialog::BUTTON,   "&OK",     IDOK,        180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP  },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL,    180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP  },
         { txDialog::END                                                                                                     }};

    // ����� ������� ��� InputBox. ����������, �.�. ����� ��� ���� �������.
    // ����� � �������� ��� ������� ������ ����� (str) � ������� ������� ����������� ����,
    // ��������� Win32 (��� ��������� ��������� TX_BEGIN_MESSAGE_MAP � �������). ����� �� ������
    // ����������� ������, �� ����� ������� ������� �������� ������ � ���������� ������� ���������,
    // � str ��������� ��������� ���� (��� ���������� �� ����� ����� DialogBoxParam � ����������
    // ��� � ����� �� ����� ��������� WM_INITDIALOG).

    struct inputDlg : txDialog
        {
        char str [1024];

        inputDlg()
            {
$           memset (str, 0, sizeof (str) - 1);          // ��������� ���� ������
            }

        TX_BEGIN_MESSAGE_MAP()    // �� ����� ���� ��� ������ ������� �������!

            TX_COMMAND_MAP        // ����� �������������� WM_COMMAND. �� ����� ���� ��� switch

                // ��� ������� ������ OK �������� ������ �� ���� ����� � ���� ���������� str, �.�.
                // ����� �������� ������� ������ ����� ����� � ����� ��� �� ��� ��������.
                // ���� ������ �� ����� ���� ������������ � case �� ��������� switch.
                // _wnd - ��� �������� ������� �������, ��. ����������� ������� TX_BEGIN_MESSAGE_MAP().

                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP
        };

    // ������� �������, ����� ����� �� ������.
    // �� ����� ��� ���������� "���������� ��������", ��� ����� � ��� ���� �� ������� ��������� -
    // �������. �� ����� ���� ��� ������� ������� ����� #undef. ����� ����������� �� ���������
    // �������, � ��� ����� ������������� �� _.

    #undef ID_TEXT_
    #undef ID_INPUT_

    // ��� ����������� ������, ������ ��� ������ � ��� ������ ���� ����� ���������� ������� txInputBox.

$   static inputDlg dlg;

    // �������� layout � ��������� ���� �������

$   dlg.dialogBox (layout);

    // ���������� ����� ������ �� ������������ �������. ��� ����� ltkfnm, ������ ��� �����������
    // ������ �� ����� ��� ������ �� ������� � ������ � ���, ��������������, ����.

$   return dlg.str;
    }

//=============================================================================
// ������ ������ txDialog
//=============================================================================

txDialog::txDialog () :
    layout_ (NULL)
    {$}

//--------------------------------------------------------------------------------

txDialog::txDialog (const Layout* layout) :
    layout_ (layout)
    {$}

//--------------------------------------------------------------------------------

const txDialog::Layout* txDialog::setLayout (const Layout* layout)
    {
$   return std::swap (layout_, layout), layout;
    }

//--------------------------------------------------------------------------------

INT_PTR txDialog::dialogBox (const txDialog::Layout* layout, size_t bufsize)
    {
$   if (!layout)  layout = layout_;
$   if (!layout)  return TX_THROW ("�� ���������� ������������ ������ �������    ");

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_THROW ("GlobalAlloc(): ��� ������ ��� ������� �������    ");

$   const Layout* dlg = &layout[0];

$   const Layout  def = { DIALOG, NULL, 0,    0, 0, 0, 0,
                                  WS_CAPTION | WS_SYSMENU | DS_MODALFRAME | DS_CENTER,
                                  "MS Shell Dlg", 8 };

$   void* ptr = _tx_DLGTEMPLATE_Create (tmpl, bufsize,
                                       (dlg->style? dlg->style : def.style) | DS_SETFONT, 0, 0,
                                        dlg->x, dlg->y, dlg->sx, dlg->sy,
                                        dlg->caption?  dlg->caption  : def.caption,
                                        dlg->font?     dlg->font     : def.font,
                                        dlg->fontsize? dlg->fontsize : def.fontsize);
$   WORD i = 0;
$   for (i = 1; layout[i].wndclass != END; ++i)
        {
$       const Layout* item = &layout[i];

$       ptr = _tx_DLGTEMPLATE_Add (ptr, bufsize - ((char*)ptr - (char*)tmpl),
                                   item->style | WS_VISIBLE, 0,
                                   item->x, item->y, item->sx, item->sy,
                                   item->id, (const char*)item->wndclass,
                                   item->caption);
        }

$   tmpl->cdit = (unsigned short) (i-1);
$   INT_PTR res = DialogBoxIndirectParam (NULL, tmpl, NULL, dialogProc__, (LPARAM) this);

$   GlobalFree (tmpl);
$   return res;
    }

//--------------------------------------------------------------------------------

INT_PTR txDialog::dialogBox (WORD resourceID)
    {
$   const char* resName = (char*)(ptrdiff_t)resourceID;

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_THROW ("�� ������ ������ ������� %d   " _ resourceID);

$   return DialogBoxParam (NULL, resName, NULL, dialogProc__, (LPARAM) this);
    }

//--------------------------------------------------------------------------------

int txDialog::dialogProc (HWND, UINT, WPARAM, LPARAM)
    {
$   return FALSE;
    }

//--------------------------------------------------------------------------------

int CALLBACK txDialog::dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
$   static txDialog* this__ = NULL;

$   if (msg == WM_INITDIALOG) this__ = (txDialog*) lParam;
$   if (!this__) return FALSE;

$   switch (msg)
        {
        case WM_INITDIALOG: $ SetForegroundWindow (wnd);         break;

        case WM_COMMAND:    $ switch (LOWORD (wParam))
            {
            case IDOK:
            case IDCANCEL:  $ SetForegroundWindow (_txWindow());
                            $ EndDialog (wnd, (INT_PTR) this__); break;
            default:        $ break;
            }

        default:            $ break;
        }

$   return this__-> dialogProc (wnd, msg, wParam, lParam);
    }

//=============================================================================
// ������� �������������� ������ � ����������� ������
//=============================================================================

void* _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize,
                              DWORD style, DWORD exStyle, WORD controls,
                              short x, short y, short cx, short cy,
                              const char* caption,
                              const char* font, WORD fontsize,
                              HANDLE menu
                              )
    {
$   if (!globalMem) return NULL;

$   WORD* pw = (WORD*) globalMem;

$   DLGTEMPLATE* tmpl = ((DLGTEMPLATE*&) pw)++;

$   tmpl->style = style;
$   tmpl->dwExtendedStyle = exStyle;
$   tmpl->cdit  = controls;
$   tmpl->x     = x;
$   tmpl->y     = y;
$   tmpl->cx    = cx;
$   tmpl->cy    = cy;

$   *pw++ = (WORD)(ptrdiff_t) NULL;
$   *pw++ = (WORD)(ptrdiff_t) menu;

$   if (caption)
        {
$       pw  += MultiByteToWideChar (CP_ACP, 0, caption? caption : "", -1, (wchar_t*) pw,
                                   (int) (bufsize? bufsize - ((char*)pw - (char*)globalMem) : 0xFFFF));
        }

$   if (style & DS_SETFONT)
         {
$        *pw++ = fontsize;
$         pw  += MultiByteToWideChar (CP_ACP, 0, font?    font    : "", -1, (wchar_t*) pw,
                                     (int) (bufsize? bufsize - ((char*)pw - (char*)globalMem) : 0xFFFF));
         }

$   return pw;
    }

//------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr, size_t bufsize,
                           DWORD style, DWORD exStyle,
                           short x, short y, short cx, short cy,
                           WORD id, const char* wclass,
                           const char* caption)
    {
$   if (!dlgTemplatePtr) return NULL;

$   WORD* pw = (LPWORD) dlgTemplatePtr;  // Force align at word boundary
$   (ULONG&) pw  += 3;
$   (ULONG&) pw >>= 2;
$   (ULONG&) pw <<= 2;

$   DLGITEMTEMPLATE* tmpl = ((DLGITEMTEMPLATE*&) pw)++;

$   tmpl->style = style;
$   tmpl->dwExtendedStyle = exStyle;
$   tmpl->x     = x;
$   tmpl->y     = y;
$   tmpl->cx    = cx;
$   tmpl->cy    = cy;
$   tmpl->id    = id;

$   if (HIWORD (wclass) == 0xFFFF)
        {
$       *pw++ = (WORD) (HIWORD (wclass));
$       *pw++ = (WORD) (LOWORD (wclass));
        }
    else if (wclass)
        {
$       pw  += MultiByteToWideChar (CP_ACP, 0, (char*) wclass, -1, (wchar_t*) pw,
                                   (int) (bufsize? bufsize - ((char*)pw - (char*)dlgTemplatePtr) : 0xFFFF));
        }
    else
        {
$       *pw++ = 0;
        }

$   if (caption)
         {
$        pw  += MultiByteToWideChar (CP_ACP, 0, caption, -1, (wchar_t*) pw,
                                    (int) (bufsize? bufsize - ((char*)pw - (char*)dlgTemplatePtr) : 0xFFFF));
         }
    else
        {
$       *pw++ = 0;
        }

$   *pw++ = 0;

$   return pw;
    }

//=============================================================================
//
// ������ ����������
//
//=============================================================================

//=============================================================================
// �������������/��������/����������
//=============================================================================

bool _txInitialize (int sizeX, int sizeY, bool centered)
    {
$   atexit (_txOnExit);

$   _txExit    = false;
$   _txRunning = false;

$   _txUpdateWindow (false);

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   _txConsole_Attach();

/*
!!!
setlocale (LC_CTYPE, "");      // for active CP
setlocale (LC_CTYPE, ".OEM");  // for CP866

setlocale (LC_CTYPE, ".1251")
setlocale (LC_CTYPE, "Russian");
std::locale::global (std::locale ("rus"));
_wsetlocale (LC_CTYPE, L"Russian_Russia.ACP");

system ("mode con cp select=1251");
*/

$   SetConsoleCP (1251);
$   SetConsoleOutputCP (1251);

$   POINT size = { sizeX, sizeY };
$   if (centered) { size.x *= -1; size.y *= -1; }

$   DWORD id = 0;
$   _txCanvas_Thread = CreateThread (NULL, 0, _txCanvas_ThreadProc, &size, 0, &id);
$   _txCanvas_Thread || TX_THROW ("Cannot create _txCanvas_Thread: CreateThread() failed");
$   _txWaitFor (_txCanvas_OK());
$   _txCanvas_OK() || TX_THROW ("Cannot create canvas");

$   _txSetDefaults();

$   _txUpdateWindow (true);

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCheck (const char msg[])
    {
$   if (_txOK()) return true;

$   MessageBox (NULL, "������: ���� ��������� �� �������!    ", (msg && *msg)? msg : "������ ���������", MB_ICONSTOP);

//  �� ��������� ������ �������� � ����� ������� � ���������� ���������� ������ ���. :(

$   exit (1);
//  return false;
    }

//-----------------------------------------------------------------------------

void _txOnExit()
    {
$   _txRunning = false;

$   Sleep (10);
$   if (!_txExit) WaitForSingleObject (_txCanvas_Thread, INFINITE);

$   _txCleanup();

#ifndef NDEBUG
    OutputDebugString ("\n");
    OutputDebugString ("TXLib " _TX_VERSION " -- FINISHED\n");
    OutputDebugString ("\n");
#endif
    }

//-----------------------------------------------------------------------------

bool _txCleanup()
    {
$   if (_txCanvas_Thread)
        {
$       CloseHandle (_txCanvas_Thread) TX_NEEDED;
$       _txCanvas_Thread = NULL;
        }

$   _txConsole_Detach();

$   DeleteCriticalSection (&_txCanvas_LockBackBuf);

$   return true;
    }

//=============================================================================
// ��������� �������� �� ���������
//=============================================================================

bool _txCanvas_SetDefaults()
    {
$   assert (_txOK());

$   _txLock (true);

$   RECT r = {0};
$   GetClientRect (_txConsole_Wnd, &r) TX_NEEDED;
$   SIZE size = { r.right - r.left, r.bottom - r.top };

$   _txSelect (GetStockObject (WHITE_PEN),   _txDC()) TX_NEEDED;
$   _txSelect (GetStockObject (WHITE_BRUSH), _txDC()) TX_NEEDED;
$   _txSelect (CreateFont (size.cy/25, size.cx/80, 0, 0,
                         FW_REGULAR, FALSE, FALSE, FALSE,
                         DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                         DEFAULT_QUALITY, DEFAULT_PITCH, _TX_CONSOLE_FONT),
                         _txDC()) TX_NEEDED;

$   Win32::SetTextColor (_txDC(), RGB (255, 255, 255));
$   Win32::SetBkMode    (_txDC(), TRANSPARENT) TX_NEEDED;

$   Win32::SetROP2      (_txDC(), R2_COPYPEN) TX_NEEDED;

$   _txUnlock();
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txConsole_SetDefaults()
    {
$   assert (_txOK());

$   _txLock (true);

$   HDC dc = _txCanvas_BackBuf[1];

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) TX_NEEDED;

$   RECT r = {0};
$   GetClientRect (_txConsole_Wnd, &r) TX_NEEDED;

$   POINT phy = { r.right - r.left, r.bottom - r.top };
$   COORD log = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
                           (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

$   GetClientRect (_txCanvas_Wnd, &r) TX_NEEDED;
$   POINT size = { r.right - r.left, r.bottom - r.top };

$   POINT fontSize = { (SHORT) ((1.0 * phy.x / log.X) / (1.0 * phy.x / size.x)),
                                (SHORT) ((1.0 * phy.y / log.Y) / (1.0 * phy.y / size.y)) };

$   _txSelect (_txFontExist (_TX_CONSOLE_FONT)? CreateFont (fontSize.y * 8/10, fontSize.x, 0, 0,
                                                            FW_REGULAR, FALSE, FALSE, FALSE,
                                                            DEFAULT_CHARSET,
                                                            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                                            DEFAULT_QUALITY, FIXED_PITCH, _TX_CONSOLE_FONT)
                                              :
                                              GetStockObject (SYSTEM_FIXED_FONT),
               dc) TX_NEEDED;

$   Win32::SetTextColor (dc, _TX_CONSOLE_COLOR);
$   Win32::SetBkMode    (dc, TRANSPARENT) TX_NEEDED;

$   _txUnlock();
$   return true;
    }

//=============================================================================
// ������� ��������� ���� (_txCanvas...)
//=============================================================================

DWORD WINAPI _txCanvas_ThreadProc (LPVOID data)
    {
$   assert (data);

$   _txCanvas_CreateWindow (*(POINT*) data);
$   _txCanvas_Wnd || TX_THROW ("Cannot create canvas: _txCanvas_CreateWindow() failed");

$   MSG msg = {0};

$   for (;;)
        {
$ //    if (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
$       if (GetMessage  (&msg, NULL, 0, 0))
            {
$           TranslateMessage (&msg);
$           DispatchMessage  (&msg);

$           Sleep (0);
$           continue;
            }
        else
            break;

$ //    if (_txCanvas_Wnd)
  //        {
$ //        InvalidateRect (_txCanvas_Wnd, NULL, false);
$ //        UpdateWindow   (_txCanvas_Wnd);
  //        }
  //
$ //    Sleep (_TX_WINDOW_UPDATE_INTERVAL);
        }

$   return (DWORD) msg.wParam;
    }

//-----------------------------------------------------------------------------

HWND _txCanvas_CreateWindow (POINT clientSize)
    {
$   const char className[] = __FILE__ "\\_txCanvas\\Class";

$   WNDCLASSEX wc    = {0};
$   wc.cbSize        = sizeof (wc);
$   wc.style         = CS_HREDRAW | CS_VREDRAW;
$   wc.lpfnWndProc   = _txCanvas_WndProc;
$   wc.hInstance     = NULL;
$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
$   wc.lpszClassName = className;
$   RegisterClassEx (&wc) || TX_THROW ("RegisterClass (\"%s\") failed"_ className);

$   char name[256] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1) TX_NEEDED;

$   int centered = false;
$   if (clientSize.x < 0 && clientSize.y < 0) { clientSize.x *= -1; clientSize.y *= -1; centered = true; }

$   POINT scr     = { GetSystemMetrics (SM_CXSCREEN),     GetSystemMetrics (SM_CYSCREEN) };
$   POINT frame   = { GetSystemMetrics (SM_CXFIXEDFRAME), GetSystemMetrics (SM_CYFIXEDFRAME) };
$   POINT caption = { 0, GetSystemMetrics (SM_CYCAPTION) };
$   POINT size    = { clientSize.x + 2*frame.x, clientSize.y + 2*frame.y + caption.y };
$   POINT center  = { scr.x / 2, scr.y / 2};

$   if (!centered)
        {
$       RECT r = {0}; GetWindowRect (_txConsole_Wnd, &r) TX_NEEDED;
$       center.x = (r.right + r.left) / 2;
$       center.y = (r.bottom + r.top) / 2;
        }

$   _txCanvas_Wnd = CreateWindowEx (0, className, name, WS_POPUP | WS_BORDER | WS_CAPTION | WS_SYSMENU,
                                    center.x - size.x/2, center.y - size.y/2, size.x, size.y,
                                    NULL, NULL, NULL, NULL);
$   _txCanvas_Wnd || TX_THROW ("Cannot create canvas: CreateWindowEx (\"%s\") failed"_ className);

$   ShowWindow   (_txCanvas_Wnd, SW_SHOW);
$   UpdateWindow (_txCanvas_Wnd) TX_NEEDED;

$   if (_txConsole_Wnd)
        {
$       int hide = 0;

        #ifndef _TX_NO_HIDE_CONSOLE
$       hide = SWP_HIDEWINDOW;
        #endif

$       SetWindowPos (_txConsole_Wnd, HWND_NOTOPMOST, center.x - size.x*2/5, center.y - size.y*2/5, 0, 0,
                      SWP_NOSIZE | SWP_NOACTIVATE | hide) TX_NEEDED;

$       HMENU menu = GetSystemMenu (_txCanvas_Wnd, false); menu TX_NEEDED;
$       AppendMenu (menu, MF_SEPARATOR, 0, NULL) TX_NEEDED;
$       AppendMenu (menu, MF_STRING | MF_UNCHECKED, _txIDM_CONSOLE, "Show Console")     TX_NEEDED;
$       AppendMenu (menu, MF_STRING | MF_UNCHECKED, _txIDM_ABOUT,   "About Library...") TX_NEEDED;
$       CheckMenuItem (menu,  _txIDM_CONSOLE, (IsWindowVisible (_txConsole_Wnd))? MF_CHECKED : MF_UNCHECKED);
        }

$   return _txCanvas_Wnd;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OK()
    {
$   return _txCanvas_Thread &&
           _txCanvas_Wnd &&
           _txCanvas_BackBuf[0] &&
           _txCanvas_BackBuf[1];
    }

//-----------------------------------------------------------------------------

bool _txCanvas_DestroyWindow()
    {
$   if (!_txCanvas_Wnd) return false;

$   char className[128] = "";
$   GetClassName (_txCanvas_Wnd, className, sizeof (className) - 1) TX_NEEDED;

$   DestroyWindow (_txCanvas_Wnd) TX_NEEDED;

$   HMODULE exe = GetModuleHandle (NULL);
$   if (exe) UnregisterClass (className, exe) TX_NEEDED;

$   _txCanvas_Wnd = NULL;
$   return true;
    }

//-----------------------------------------------------------------------------

int _txCanvas_SetLockRefresh (int count)
    {
$   int old = _txCanvas_LockRefresh;

$   _txCanvas_LockRefresh = count;

$   if (!_txCanvas_LockRefresh || !old)
        if (_txCanvas_Wnd)
        {
$       InvalidateRect (_txCanvas_Wnd, NULL, false);
$       UpdateWindow   (_txCanvas_Wnd);
        }

$   return old;
    }

//=============================================================================
// ������� ��������� ���� (_txCanvas_On...)
//=============================================================================

bool _txCanvas_OnCreate (HWND wnd)
    {
$   _txRunning = true;

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); _txCanvas_BackBuf[0] TX_NEEDED;
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); _txCanvas_BackBuf[1] TX_NEEDED;

$   SetTimer (wnd, _txCanvas_Timer, _TX_WINDOW_UPDATE_INTERVAL, NULL)   TX_NEEDED;

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnDestroy (HWND wnd)
    {
$   if (_txCanvas_Timer) KillTimer (wnd, _txCanvas_Timer) TX_NEEDED;

$   if (_txCanvas_BackBuf[0]) _txBuffer_Delete (_txCanvas_BackBuf[0]); _txCanvas_BackBuf[0] = NULL;
$   if (_txCanvas_BackBuf[1]) _txBuffer_Delete (_txCanvas_BackBuf[1]); _txCanvas_BackBuf[1] = NULL;

$   PostQuitMessage (0);

//  Should terminate user process (main() etc.) even if they are not finished.
//  So, use exit().

$   if (_txRunning) { _txExit = true; exit (0); }

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnClose (HWND)
    {
$   assert (_txCanvas_OK());

$   char name[256] = __FILE__;
$   GetModuleFileName (NULL, name, sizeof (name) - 1) TX_NEEDED;

$   if (_txRunning &&
        MessageBox (_txCanvas_Wnd, "������� main() �� ���������. "
                    "��������� ��� ��� ��������. ��������?    ", name,
                     MB_OKCANCEL | MB_ICONSTOP) != IDOK) return false;
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnPaint (HWND wnd)
    {
$   assert (wnd);
$   if (!_txCanvas_OK()) return false;

$   PAINTSTRUCT ps = {0};
$   HDC dc = BeginPaint (wnd, &ps);
$   if (!dc) return false;

$   if (!_txLock (false))
      {
$     EndPaint (wnd, &ps) TX_NEEDED;
$     return false;
      }

$   RECT r = {0};
$   GetClientRect (wnd, &r) TX_NEEDED;
$   POINT size = { r.right - r.left, r.bottom - r.top };

$   if (!_txCanvas_LockRefresh)
      {
$     Win32::BitBlt (_txCanvas_BackBuf[1], 0, 0, size.x, size.y, _txDC(), 0, 0, SRCCOPY);

$     if (_txConsole_OK())
          {
$         _txConsole_Draw (_txCanvas_BackBuf[1]);
          }
      }

$   Win32::BitBlt (dc, 0, 0, size.x, size.y, _txCanvas_BackBuf[1], 0, 0, SRCCOPY);

$   _txUnlock();

$   EndPaint (wnd, &ps) TX_NEEDED;

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnChar (HWND, WPARAM ch)
    {
$   if (!_txCanvas_OK()) return false;

$   INPUT_RECORD evt = {0};

$   evt.EventType                        = KEY_EVENT;
$   evt.Event.KeyEvent.bKeyDown          = true;
$   evt.Event.KeyEvent.wRepeatCount      = 1;
$   evt.Event.KeyEvent.wVirtualKeyCode   = 0;
$   evt.Event.KeyEvent.wVirtualScanCode  = 0;
$   evt.Event.KeyEvent.uChar.AsciiChar   = (unsigned char) ch;
$   evt.Event.KeyEvent.dwControlKeyState = 0;

$   DWORD written = 0;
$   WriteConsoleInput (GetStdHandle (STD_INPUT_HANDLE), &evt, 1, &written) TX_NEEDED;

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnMouse (HWND, WPARAM buttons, LPARAM coords)
    {
$   if (!_txCanvas_OK()) return false;

$   _txCurMouseX       = LOWORD (coords);
$   _txCurMouseY       = HIWORD (coords);
$   _txCurMouseButtons = (int) buttons;

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnTimer (HWND, WPARAM)
    {
$   if (!_txCanvas_OK()) return false;

$   InvalidateRect (_txCanvas_Wnd, NULL, false) TX_NEEDED;
$   UpdateWindow   (_txCanvas_Wnd)              TX_NEEDED;

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnCmdConsole (HWND wnd, WPARAM cmd)
    {
$   assert (wnd); assert (_txCanvas_OK()); assert (_txConsole_OK());

$   bool visible = IsWindowVisible (_txConsole_Wnd) != 0;

$   ShowWindow (_txConsole_Wnd, visible? SW_HIDE : SW_SHOW);

$   visible = IsWindowVisible (_txConsole_Wnd) != 0;
$   CheckMenuItem (GetSystemMenu (wnd, false), (int)cmd, visible? MF_CHECKED : MF_UNCHECKED);

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnCmdAbout (HWND, WPARAM)
    {
$   MessageBox (NULL, "\nThe Dumb Artist Library (TXLib)\n\n"
                _TX_VERSION "  (c) Ded, 2005-08 (Ilya Dedinsky <ded@concord.ru>, http://ded32.net.ru)    \n\n"
                "Compiled with: " __FILE__ ", at "__DATE__ " " __TIME__"      \n",
                "About TX Library",
                MB_ICONINFORMATION);
$   return true;
    }

//-----------------------------------------------------------------------------

LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
    {
    switch (msg)
        {
        case WM_CREATE:       $ _txCanvas_OnCreate     (wnd);         break;

        case WM_CLOSE:        $ if (!_txCanvas_OnClose (wnd))         return 0;
        case WM_DESTROY:      $ _txCanvas_OnDestroy    (wnd);         break;

        case WM_PAINT:        $ _txCanvas_OnPaint      (wnd);         break;
        case WM_CHAR:         $ _txCanvas_OnChar       (wnd, wpar);   break;
        case WM_TIMER:        $ _txCanvas_OnTimer      (wnd, wpar);   break;

        case WM_LBUTTONUP:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MOUSEMOVE:    $ _txCanvas_OnMouse  (wnd, wpar, lpar); break;
        default:              $ break;
        }

    if (msg == WM_SYSCOMMAND) switch (wpar)
        {
        case _txIDM_ABOUT:    $ _txCanvas_OnCmdAbout   (wnd, wpar);   break;
        case _txIDM_CONSOLE:  $ _txCanvas_OnCmdConsole (wnd, wpar);   break;
        default:              $ break;
        }

    if (msg == WM_KEYDOWN &&
        wpar == VK_F12 && GetKeyState (VK_CONTROL) && GetKeyState (VK_SHIFT) && GetKeyState (VK_MENU))
        {
$       _txCanvas_OnCmdAbout (wnd, wpar);
        }

    return DefWindowProc (wnd, msg, wpar, lpar);
    }

//=============================================================================
// ������� ����������� ���� (_txConsole...)
//=============================================================================

bool _txConsole_Attach()
    {
$   FreeConsole();
$   AllocConsole();

$   HANDLE con = GetStdHandle (STD_OUTPUT_HANDLE); con TX_NEEDED;
$   COORD size = { 80, 25 };
$   SetConsoleScreenBufferSize (con, size);

$   _txConsole_Wnd = _txConsole_GetWindow();

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txConsole_OK()
    {
$   return _txConsole_Wnd != NULL;
    }

//-----------------------------------------------------------------------------

bool _txConsole_Detach()
    {
$   FreeConsole();
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txConsole_Draw (HDC dc)
    {
$   assert (_txConsole_OK()); assert (_txCanvas_OK());

$   if (!_txLock (false)) return false;

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) TX_NEEDED;

$   TCHAR* buf = new TCHAR [con.dwSize.X * con.dwSize.Y + 1]; buf TX_NEEDED;

$   COORD zero = {0};
$   DWORD read = 0;
$   ReadConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE), buf,
                                con.dwSize.X * con.dwSize.Y * sizeof (TCHAR),
                                zero, &read) TX_NEEDED;
$   SIZE fontSz = {0};
$   Win32::GetTextExtentPoint32 (dc, "W", 1, &fontSz) TX_NEEDED;

$   int sizeX = con.srWindow.Right - con.srWindow.Left + 1;
$   for (int y = con.srWindow.Top; y <= con.srWindow.Bottom; y++)
        Win32::TextOut (dc, 0, y*fontSz.cy * 10/8, buf + y*con.dwSize.X + con.srWindow.Left, sizeX) TX_NEEDED;

$   delete[] buf;

$   if (_txConsole_CursorMode &&
      GetTickCount() % _TX_CURSOR_BLINK_INTERVAL*2 > _TX_CURSOR_BLINK_INTERVAL &&
      In (con.dwCursorPosition, con.srWindow))
      {
$     Win32::TextOut (dc,
                     (con.dwCursorPosition.X - con.srWindow.Left)*fontSz.cx,
                     (con.dwCursorPosition.Y - con.srWindow.Top) *fontSz.cy * 10/8+ 1,
                      "_", 1);
      }

$   _txUnlock();

$   return true;
    }

//-----------------------------------------------------------------------------

HWND _txConsole_GetWindow()
    {
$   static _TX_IMPORT_OPT ("Kernel32", HWND, GetConsoleWindow, ());
$   if (GetConsoleWindow) return GetConsoleWindow();

$   SetLastError (0);

$   char title[1024] = "";
$   GetConsoleTitle (title, sizeof (title) - 1);

$   char unique [128] = "";
$   LARGE_INTEGER time = {{0}};
$   QueryPerformanceCounter (&time) TX_NEEDED;

$   _snprintf_s (unique, sizeof (unique) - 1, __FILE__ "(%d)\\Temp Title %08lx%08lx", __LINE__, time.HighPart, time.LowPart);

$   SetConsoleTitle (unique) TX_NEEDED;

$   HWND con = NULL;
$   _txWaitFor (con = FindWindow (NULL, unique));

$   SetConsoleTitle (title) TX_NEEDED;

$   con || TX_THROW ("Cannot find console window");
$   return con;
    }

//=============================================================================
// ������� ������������ ������ (_txBuffer...)
//=============================================================================

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bitmap)
    {
$   assert (wnd);

$   _txLock (true);

$   HDC wndDC = GetDC (wnd); wndDC TX_NEEDED;
$   (Win32::GetDeviceCaps (wndDC, RASTERCAPS) & RC_BITBLT) || TX_THROW ("GetDeviceCaps(): RASTERCAPS: RC_BITBLT not supported");

$   RECT r = {0};
$   GetClientRect (wnd, &r) TX_NEEDED;
$   POINT sz = { r.right - r.left, r.bottom - r.top };
$   if (!size) size = &sz;

$   HDC dc = Win32::CreateCompatibleDC (wndDC);
$   dc || TX_THROW ("Cannot create buffer: CreateCompatibleDC() failed");

$   HBITMAP bmap = bitmap? bitmap : Win32::CreateCompatibleBitmap (wndDC, size->x, size->y);
$   bmap || TX_THROW ("Cannot create buffer: CreateCompatibleBitmap() failed");

$   Win32::SelectObject (dc, bmap) TX_NEEDED;

$   if (!bitmap) Win32::PatBlt (dc, 0, 0, size->x, size->y, BLACKNESS) TX_NEEDED;

$   ReleaseDC (wnd, wndDC) TX_NEEDED;

$   _txUnlock();
$   return dc;
    }

//-----------------------------------------------------------------------------

bool _txBuffer_Delete (HDC dc)
    {
$   if (!dc) return false;

$   _txLock (true);

$   _txSelect (Win32::GetStockObject (NULL_PEN),    dc) TX_NEEDED;
$   _txSelect (Win32::GetStockObject (NULL_BRUSH),  dc) TX_NEEDED;
$   _txSelect (Win32::GetStockObject (SYSTEM_FONT), dc) TX_NEEDED;

$   Win32::DeleteObject (Win32::GetCurrentObject (dc, OBJ_BITMAP));
$   Win32::DeleteObject (Win32::GetCurrentObject (dc, OBJ_REGION));

$   Win32::DeleteDC (dc) TX_NEEDED;

$   _txUnlock();
$   return true;
    }

//=============================================================================

bool _txSelect (HGDIOBJ obj, HDC dc)
    {
$   _txLock (true);

$   obj = Win32::SelectObject (dc, obj); obj TX_NEEDED;
$   if (obj) Win32::DeleteObject (obj);

$   _txUnlock();

$   return obj != NULL;
    }

//=============================================================================
// ������ ������������ �������
//=============================================================================

FARPROC _txImport (const char lib[], const char name[], int required)
    {
$   HMODULE dll  = LoadLibrary (lib);
$   if (!dll  && required) TX_THROW ("\aCannot load %s" _ lib);
$   if (!dll) return NULL;

$   FARPROC addr = GetProcAddress (dll, name);
$   if (!addr && required) TX_THROW ("\aCannot import %s\\%s" _ lib _ name);

$   return addr;
    }

//=============================================================================
// �����������
//=============================================================================

bool _txThrow (const char file[], int line, const char func[], DWORD error,
               const char msg[], ...)
    {
    const size_t MAXSTR = 1024;

    bool fatal = (msg && *msg == '\a')? (msg++, true) : false;
    va_list arg; va_start (arg, msg);
    char str[MAXSTR] = "", *s = str;

    #ifdef  _TX_USE_SECURE_CRT
    #define TR_ ,_TRUNCATE
    #else
    #define TR_
    #endif

    if (file)
        s += _snprintf_s (s, sizeof (str) - 1 - (s-str) TR_, "TX_THROW(): %s", file);

    if (line)
        s += _snprintf_s (s, sizeof (str) - 1 - (s-str) TR_, " (%d)", line);

    if (func)
        s += _snprintf_s (s, sizeof (str) - 1 - (s-str) TR_, " %s()", func);

    if (error == (DWORD)(-1))
        error = GetLastError();

    if (error)
        s += _snprintf_s (s, sizeof (str) - (s-str) TR_, ": Error %lu: ", error),
        s += FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                            NULL, error, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                            s, (DWORD) (sizeof (str) - (s-str)), NULL) - 3;
    if (msg && *msg)
        s +=  _snprintf_s (s, sizeof (str) - 1 - (s-str) TR_, ": "),
        s += _vsnprintf_s (s, sizeof (str) - 1 - (s-str) TR_, msg, arg);

        s += _snprintf_s  (s, sizeof (str) - 1 - (s-str) TR_, "    \n");

    #undef TR_

    char strOem[MAXSTR] = "";
    AnsiToOem (str, strOem);
    printf (strOem);

    OutputDebugString (str);
    MessageBox (NULL, str, fatal? "��������� ������" : "������ ���������",
                MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

    if (fatal) abort();

    va_end (arg);
    return false;
    }

//@}
//! \endcond Internal
//=============================================================================
//! \cond Namespaces

} // namespace TX
} // anonymous namespace

using namespace TX;
using namespace TX::Win32;

//! \endcond Namespaces
//=============================================================================

//------------------------------------------------------------------------
// ��������� � ������������
//------------------------------------------------------------------------
//! \cond Internal

#if defined (_MSC_VER)
#pragma warning (default: 4127)              // conditional expression is constant
#pragma warning (default: 4245)              // 'argument': conversion from A to B, signed/unsigned mismatch

#pragma warning (default: 4100)              // 'parameter': unreferenced formal parameter
#pragma warning (default: 4511)              // 'class': copy constructor could not be generated
#pragma warning (default: 4512)              // 'class': assignment operator could not be generated
#endif

#undef $

//! \endcond Internal
//=============================================================================

#endif // __TXLIB_H

//=============================================================================
//
//  \name    ������� �������������
//
//=============================================================================

//-----------------------------------------------------------------------------
/*! \page    Tutorial_1st ������: ����������

    \section Tutorial_1st_01 ��������� ���������� ���������

    ���������� ��������� �� � (��� �++) ������� �� ���� ������: �������
    ����������� ��������� � ������� ������� ���������. ���������� ������,
    � ������� �������� �� ������ ������� �������.

    \section Tutorial_1st_02 ������ ����������� ���������

    ��������� (�������) ����������� ��������� ��������� ������ � ������
    ����� ��������� � �������� ������ ���:

    \code
    #include <stdlib.h>
    #include "TXLib.h"
    \endcode

    \c Stdlib.h � \c TXLib.h - ����� ���������, ������� ������������ � �����
    ���������. ����� ����� �� ������ ������������ �������, ������� � ����������,
    ����������� � ���� ������. ������, ��� �����, ��������� ���������� �� �����,
    ���� ��� � �� ������. ����� ������������ ����� ���������, ������ ����� ����
    ����� �������.

    \section Tutorial_1st_03 ������� ������� ���������

    ��������� �� � (�++) ������� �� �������. ������� - ��� �������� �����-����
    �������� � �������� ������ (���������).

    ��������,

    \code
    int main()
        {
        txCreateWindow (800, 600);
        txLine (320, 290, 320, 220);
        return 0;
        }
    \endcode

    ������� ������� - ��� �������, � ������� ���������� ���������� ���������.
    �� ��� - \c main(). ������ ����������, ��� ���� ���� ������ � �������, �.�.,
    �� �������� �����-�� ��������. ��� ����, ����� ������� ������ ������, ��
    ����� \a �������. ������� \c main() �������� ���� ������������ �������
    ����������. ����� \c int ��������, ��� \c main() � ����� ������ ��������
    ����, ��� �� ������� (������������ �������), ����� ����� �����. ��� �����
    ��� ������� main() �������� ��� ���������� ����� ���������. ���� �� ����� 0,
    �� ������ ��������� ��������� ��������.

    ��������, ���������� � �������, ����������� � �������� ������ \c { � \c }.
    ��� ���������� ������ � ����� �������.

    ������ ������� �������� ������ ������, ������� ���-�� ������ �� ������.
    ����� ���������, ���, ��� ��� ��������� ����������, ����� ������ ������,
    ���������� ���� ����� ��������� �� ������. ��� ������������ �������
    ���������� ���������. ������ ������ � ���������������� �������������
    ������ ������ ������ � ������� �����.

    ��� ��������� ��������� � ����, ����� � ��� �� ���������� ������, �����
    �����, ����� � ������ ������ � ��� ������ �������. ������ �� ������ ��
    ����������� ������� ������, ����� �������, �� � ����� ������ ��������.
    ������� �������� ������ ��������� �������� �� ���, � �������������
    ���������� ���� ��� ������ � �����������. ������ � ����� �����������
    ������� ��������� ����� ������� ���� ������, ������� ������.

    ������ ����� ���������� ���������:

    \code
    #include "TXLib.h"
    int   main(){
    txCreateWindow(800,600);  // ��-�����, ��� ������ ��� ����. :)
    txLine(320,290,320,220);
     txLine (320, 290,280,350);
      txLine(320, 290,360,350);
     txLine(320,230,270,275);
    txLine(320,230, 400,220);
    txCircle(320,190,30);
      txSelectFont( "Times",60);
    txTextOut(240,400,"Hello, world!");
              return        0;
    }
    \endcode

    ��� ������� ��������� �������� ����� ������������ ������������ �������,
    � ������� ������� ����� ���� ���������� �����-������, � ��� OY �������
    ����. ��� ��������� ����������, �� �������� ������. :) ��������, �������

    \code
    txLine (320, 290, 320, 220);
    \endcode

    �������� ����� �� ����� x=320 � �=290 � ����� � x=320 � y=220.

    ������ ������� ������������� ������ � �������. ��� - ������ ����� � �������
    �����. ����� � ������� �������� � ����� ������� \a ������������ ��������
    ��� ����������. ��������, � ������ � \c txCreateWindow (800, 600) ����� �
    ������� ��������, �.�. � ���� ������ "��������� �����" � ���, ��� ����
    ������� ���� ��� ���������. � ������ � <tt>int main()</tt> - �� ��������,
    �.�. �������� ������� \c main() �� ��������� (�� ����� ����, ��� ��� ������
    ������).

    ���� � ��������� ������������ ������, ��� ����������� � ������� �������,
    ��������:

    \code
    txTextOut (240, 400, "Hello, world!");
    \endcode

    ���� � ��������� ����������� ����� � ������� ������, �� ��� �����
    ���������� �� ����� ����� ������, � �� �������, ��� � ������� �����.

    \section Tutorial_1st_04 ���������������� ������

    � ������� ���������� ������ ������ ���� �����:

    - ������ ������ (����������, ����������) - �� �������� ���������������
      �������� <i>(syntax error).</i> ��� ���������� �� ������� ���������,
      �� ������ �������� ��������� � �������� ��� (������ ����������). �������
      �� �������� �������� ������� ����������. ����������� ���� ��� ���� ��
      ��������� � ��������� �� �����������.

    - ���������� ������ - ��� ���������� ����� ������� ���������, ��� ����
      ��� ���������� ������ ��� (������ ������� ��������������, \a warnings).
      �� �������� �������� ������� ����������.

    ����������� ��� �������������� ������ �� ���� ������ ���������� ��-��
    ����������������. ���������������� �������������� ������:

    - ������ �������� �����, �������� ��������� � ������:
      \code
      #iclude "TX lib.h"
      in maim()
      tx Line (10, 10, 20, 20)
      \endcode

    - ������ ������� � ��������� �����:
      \code
      txcircle (100, 100, 10)
      \endcode

    - �� ������ ������:
      \code
      int main
      \endcode

    - �������� �������:
      \code
      tx�ircle (100 100 10)
      \endcode

    - �������� ����� � �������:
      \code
      txSelectFont ("Times", 60)
      \endcode

    - �������� ��� ������ �������:
      \code
      txSelectFont (Times, 60)
      txSelectFont ('Times', 60)
      \endcode

    - ������ ������ ����� � �������:
      \code
      int main();
      \endcode

    - �������� ������� ����� ����� ����� �������:
      \code
      3,1415
      \endcode

    - �������� �������� ������:
      \code
      int main()
      txCreateWindow (800, 600);
      txLine (320, 290, 320, 220);
      return 0;
      \endcode

    - �������� ������ ����������� ��� ����������� ������, ��� ����� ������,
      ������ ���������� �������� ������, ��� ������ ���� ������:
      \code
      int main()
          {
          txCreateWindow (800, 600);

          txLine (320, 290, 320, 220;  // �� ������� ������� ������
          return 0;
          }
      \endcode
      \code
      int main()
      {
      txCreateWindow {800, 600};   // �������� ������ ������ �������
      return 0;
      }

      txLine (320, 290, 320, 220;  // ������� �� ��������� ������� main()
      }                            // ������ ������
      \endcode

    - �������� ������� �� ������� �������� ������
      \code
      int main()
      {
      txCreateWindow (800, 600);
      return 0;
      }

      txLine (320, 290, 320, 220); // ������� �� ��������� ������� main()
      \endcode

    ������ � ���������� ������. ��������, �� �� ������� ������ ���� ���������
    (�� ��������� �� �����), ��� ���������� ���� ������ ������ ������, � ���
    ������� ����������, ��� ������ �������� ����������. ��� ������ ����������
    ����� ������� ���������. �� ����� ������, ���� ��������� �� ����� ������
    ��� ������� ���� �� ������, � ��� �������, � ������� ��� ������ � ���������.

    \section Tutorial_1st_Code ����������� ������
    \include "Examples\TXEx01.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_1stEx ������: ���������� :)

    \section Tutorial_1stEx_Code ����������� ������
    \include "Examples\TXEx02.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_Functions ������: �������

    \section Tutorial_Functions_Code ����������� ������
    \include "Examples\TXEx03.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_Parameters ������: ������� � �����������

    \section Tutorial_Parameters_Code ����������� ������
    \include "Examples\TXEx04.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_While ������: �����

    \section Tutorial_While_Code ����������� ������
    \include "Examples\TXEx05.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_For ������: ����� (2)

    \section Tutorial_For_Code ����������� ������
    \include "Examples\TXEx06.cpp"
*/

//=============================================================================
// EOF
//=============================================================================
