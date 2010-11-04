
TODO

int main()
{
    http://users.livejournal.com/sizeof/
    return 0;
}

//=============================================================================
//!
//! @file       TXLib.h
//! @brief      ������� ����
//!
//! @mainpage
//!
//! @brief      ���������� ������ ��������� (The Dumb Artist Library, TX Library, TXLib).
//!
//! @version    [Version 0.01 alpha, build 72]
//! @author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky <ded@concord.ru>, http://ded32.net.ru)
//! @date       2010
//!
//! @par        ��������������
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
//! @warning
//!           - <b>��� �����-������.
//!             ��� ������������� ��������� ������������ � ������� ����������.</b>\n\n
//!           - <b>��� ���������� � Visual Studio ����� ����������� �� �����
//!             ����������: ���� msvcrt.dll</b>\n\n
//!           - ���� ������� �������� ��� ������� ����������� �������, ������� �����
//!             ����� ������������ �����������. ��� �������� ������������� ���������
//!             ���������� ����������. ��� ����������� ����� � ������� ���������
//!             ������� � ����� "LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage"
//!             �������� �������� ����� "1252" �� "c_1251.nls", ���� ��������� ����
//!             "Wizard\CodePage.reg". ����� ���� ��������� ����������� ������������.
//!             (<b>�����:</b> ���� �� �� �� ����� ������ ��� ������, �� �������� ��,
//!             � �������� ������� ����� �� ����� ������ � ������� ������� @ref txTextOut).
//!
//! @par        ������� ���������
//! - Build 72
//!          -# ������������ ��������� C++0x � GCC 4.5 � ������ ���������� -Wall -Wextra.
//! - Build 71
//!          -# ������������ ���������� MS SAL � ������ ���������� /analyze � MSVS 2005, 2008.
//!          -# ������������ �������� ���������� �� �������.
//!          -# ������� ���� � ������� � _txThrow().
//! - Build 70
//!          -# ����������� ������ _txCanvas_OnPaint (NULL DC).
//!          -# ������� �������� ��������� ��������� ��� ���������� ������.
//!          -# ��������� ����������� (@ref TX_TRACE).
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
//! @defgroup Drawing   ���������
//! @defgroup Mouse     ��������� ����
//! @defgroup Dialogs   ���������� ����
//! @defgroup Misc      ������
//! @defgroup Service   ���������
//! @defgroup Technical ����������� ������
//=============================================================================

#ifndef __TXLIB_H
#define __TXLIB_H

//-----------------------------------------------------------------------------
//
// ��������� � ������������ � ����������
//
//-----------------------------------------------------------------------------

#undef  UNICODE

#ifndef _WIN32_WINNT
    #define _WIN32_WINNT 0x0400
#endif

#if defined (__GNUC__)

    #if (__GNUC__ >= 4)
        #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
        #pragma GCC diagnostic ignored "-Wunreachable-code"

        #pragma GCC diagnostic ignored "-Wunused-value"
    #endif

    #define _TX_CHECK_FORMAT( fmtIdx )  __attribute__ (( format (printf, (fmtIdx), (fmtIdx)+1) ))
    #define _TX_CHECK_USAGE             __attribute__ (( warn_unused_result ))

#else

    #define _TX_CHECK_FORMAT( fmtIdx )
    #define _TX_CHECK_USAGE

#endif

#if defined (_MSC_VER)

    #pragma warning (push, 4)
    #pragma warning (disable: 4127)             // conditional expression is constant
    #pragma warning (disable: 4245)             // 'argument': conversion from A to B, signed/unsigned mismatch
    #define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200)    // MSVC 6

    #pragma warning (disable: 4100)             // 'parameter': unreferenced formal parameter
    #pragma warning (disable: 4511)             // 'class': copy constructor could not be generated
    #pragma warning (disable: 4512)             // 'class': assignment operator could not be generated

#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1400)    // MSVC 8 (2005)

    #define _TX_USE_SECURE_CRT

#else

    #define  strncpy_s    strncpy               // Prevous MSVC versions do not
    #define  strncat_s    strncat               // have secure variants of these
    #define _snprintf_s  _snprintf              // functions, so use unsecure ones
    #define _vsnprintf_s _vsnprintf             //

#endif

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
#include <tlhelp32.h>

//=============================================================================
//! @cond NOT_FOR_DOXYGEN

namespace {
namespace TX {

//! @endcond
//=============================================================================

//=============================================================================
//
//! @name    �����
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���������������� ������.
//! @see     txSetColor(), txSetFillColor(), txGetColor(), txGetFillColor(), txGetPixel()
//! @hideinitializer
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (TX_NULL);
//! @endcode
//-----------------------------------------------------------------------------

const COLORREF
#ifdef FOR_DOXYGEN_ONLY
    TX_COLOR_NAMES   = 0,
#endif
    TX_BLACK         = RGB (  0,   0,   0),   //!< ������ ����.
    TX_BLUE          = RGB (  0,   0, 128),   //!< �����-����� ����.
    TX_GREEN         = RGB (  0, 128,   0),   //!< ������� ����.
    TX_CYAN          = RGB (  0, 128, 128),   //!< ��������� ����.
    TX_RED           = RGB (128,   0,   0),   //!< �����-������� ����.
    TX_MAGENTA       = RGB (128,   0, 128),   //!< �����-��������� ����.
    TX_BROWN         = RGB (128, 128,   0),   //!< ���������� ����. ����������. Do it yourself using @ref RGB().
    TX_ORANGE        = RGB (255, 128,   0),   //!< ��������� ����.
    TX_GRAY          = RGB (160, 160, 160),   //!< ����� ����.
    TX_DARKGRAY      = RGB (128, 128, 128),   //!< �����-����� ����.
    TX_LIGHTGRAY     = RGB (192, 192, 192),   //!< ������-����� ����.
    TX_LIGHTBLUE     = RGB (  0,   0, 255),   //!< ������-����� ����.
    TX_LIGHTGREEN    = RGB (  0, 255, 128),   //!< ������-������� ����.
    TX_LIGHTCYAN     = RGB (  0, 255, 255),   //!< ������-��������� ����.
    TX_LIGHTRED      = RGB (255,   0, 128),   //!< ������-������� ����.
    TX_LIGHTMAGENTA  = RGB (255,   0, 255),   //!< ������-��������� ����.
    TX_PINK          = RGB (255, 128, 255),   //!< ������� ���������:)
    TX_YELLOW        = RGB (255, 255, 128),   //!< ������ ����.
    TX_WHITE         = RGB (255, 255, 255),   //!< ����� ����.
    TX_TRANSPARENT   = 0xFFFFFFFF,            //!< ���������� ����. ���� ��� �������, <i>������ �� ��������.</i>
    TX_NULL          = TX_NULL,               //!< ���������� ����. ���� ��� �������, <i>������ �� ��������.</i>

//  �������� ������ (����������) - ��. @ref txExtractColor(), @ref txRGB2HSL(), @ref txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< �������� ��� ����� � ������ HSL
    TX_SATURATION   = 0x05000000,             //!< ������������ ����� � ������ HSL
    TX_LIGHTNESS    = 0x06000000;             //!< �������� ����� � ������ HSL

//=============================================================================
//
//! @name    ����������� ���������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �� �������� ������������� ���������� ����
//!
//!          �������� ����� ���������� TXLib.h � ���������.
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define  _TX_NO_HIDE_CONSOLE
#endif

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� �������
//-----------------------------------------------------------------------------

const char   _TX_CONSOLE_FONT[]           = "Lucida Console";

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���� ������ �������
//-----------------------------------------------------------------------------

const COLORREF _TX_CONSOLE_COLOR          = TX_LIGHTGRAY;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ������� ������� ������� (��)
//-----------------------------------------------------------------------------

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ���������� ������ (��)
//-----------------------------------------------------------------------------

const int    _TX_WINDOW_UPDATE_INTERVAL   = 10;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� �������� �������� (��)
//-----------------------------------------------------------------------------

const int    _TX_TIMEOUT                  = 1000;

//-----------------------------------------------------------------------------
//  @ingroup Internal
//  @brief   �������������� �������������� ������� ���������� ���� ���� TXLib
//-----------------------------------------------------------------------------

const int    _TX_IDM_ABOUT                = 40000;
const int    _TX_IDM_CONSOLE              = 40001;

//=============================================================================
//
//! @name    ����������� � �������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� ������ ����������.
//!          ��� ��������� ������������� ����������� ��� ���������� ������.
//! @see     txVersion()
//-----------------------------------------------------------------------------

#define      _TX_VERSION                  "[Version 0.01 alpha, build 72]"

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, �������������� � ��� ����� � ����� ������ �����, ��� �� ����������.
//! @hideinitializer
//-----------------------------------------------------------------------------

#define __TX_FILELINE__                      __TX_FILELINE__1 (__FILE__, __LINE__)

//! @cond NOT_FOR_DOXYGEN
#define __TX_FILELINE__1(__file__, __line__) __TX_FILELINE__2 (__file__, __line__)
#define __TX_FILELINE__2(__file__, __line__) __file__ " (" #__line__ ")"
//! @endcond

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, ��������������� ����� ������� �������, ��� ��� ��������� ����� �
//!          ����� ������, ���� ����������� ����� ������� �� �������������� ������������.
//! @hideinitializer
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ������������ ������� assert(), � ������� ��������� ����� MessageBox(),
//!          ������� � OutputDebugString().
//!
//!          ���� �������, ����������� assert(), �������, �� ������ ������ �� ������.\n
//!          ���� ������� ����������� �����, �� ��������� ��������������� ��������� �
//!          ��������� �������� �����������.
//!
//! @param   cond ������� ��� ��������
//! @return  1, ���� assert() �� ��������, � 0, ���� �� �������� (�� � ���� ������
//!          ���������� ������ �� ��������, �.�. ��������� ����� ��������).
//! @hideinitializer
//! @usage
//! @code
//!          assert (0 <= i && i < ARRAY_SIZE);
//! @endcode
//-----------------------------------------------------------------------------

#undef  assert

#ifndef NDEBUG
    #define assert(cond)  ( !(cond)? (TX_THROW ("\aAssertion failed: \"%s\"" _ #cond), 0) : txReturn1() )

#else
    #define assert(cond)  ( 1 )

#endif

//! @cond NOT_FOR_DOXYGEN
inline int txReturn1()    { return 1; }   // To disable warning "right-hand operand of comma has no effect"
//! @endcond

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, ����������� �������� ���������� ����� ���������� � �����-���� ������ ������.
//! @note    <b>������ ������������� ������ ���������������� � �������.</b>
//! @see     TX_THROW()
//! @usage
//! @code
//!          TX_THROW ("������ ������ ������ '����� � ���', ������ %d ����� '%s'" _ lineNum _ fileName);
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#define _                ,

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ����������� ���������������� ��������������� ���������.
//! @return  ������ false
//! @see     TX_NEEDED(), _
//! @usage
//! @code
//!          TX_THROW ("�� ���� ������ '����� � ���', ������ �������� '%s'" _ fileName);
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#ifndef NDEBUG
    #define TX_THROW( msg )   ( _txThrow (__FILE__, __LINE__, __TX_FUNCTION__, (DWORD)(-1), msg) )

#else
    #define TX_THROW(msg)     ( 0 )

#endif

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��� ����� � ����� ������, ��� ��������� ����� TX_PRINT_HERE().
//! @usage
//! @code
//!          TX_PRINT_HERE();
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#ifndef NDEBUG
    #define TX_PRINT_HERE()   printf ("%s (%d) %s(): Here... :)\n", __FILE__, __LINE__, __TX_FUNCTION__)

#else
    #define TX_PRINT_HERE()

#endif

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��������������� ��������� � ������ �������� ��������.
//!          ������������, ���� ���� ������ if() :)
//! @note    <b>��������������, ��� �������� � ������ �������� ���������� 0 ��� false.</b>\n\n
//!          <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) TX_NEEDED
//!          ������������ � ������ ��������.</b>
//! @return  ������ false
//! @usage
//! @code
//!          FILE* input = fopen ("a.txt", "r"); input TX_NEEDED;
//!          fgets (str, sizeof (str) - 1, input) TX_NEEDED;
//!          (fclose (input) != 0) TX_NEEDED;
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#ifndef NDEBUG
    #define TX_NEEDED     || TX_THROW (NULL)

#else
    #define TX_NEEDED

#endif

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������������ �� ���� �����
//! @param   a ���� �� ����� :)
//! @param   b ������ �� ����� :)
//! @return  ������������ �� ���� ����� a � b
//! @hideinitializer
//! @usage
//! @code
//!          if (MAX (3, 7) != 7) printf ("Your CPU is broken, throw it away.");
//! @endcode
//-----------------------------------------------------------------------------

#define MAX( a, b )      ( (a) > (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ����������� �� ���� �����
//! @param   a ���� �� ����� :)
//! @param   b ������ �� ����� :)
//! @return  ����������� �� ���� ����� a � b
//! @hideinitializer
//! @usage
//! @code
//!          if (MIN (3, 7) != 3) printf ("Your CPU is still broken, throw it away again.");
//! @endcode
//-----------------------------------------------------------------------------

#define MIN( a, b )      ( (a) < (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����� ��
//! @return  ����� ��
//! @hideinitializer
//! @usage
//! @code
//!          if (txPI == 1) MessageBox (txWindow(), "�� ������ � ������ ���������.", "�����������", MB_ICONSTOP);
//! @endcode
//-----------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������/��������� ���������� ����������� ���������� ���� ����������.
//!
//!          ����������� ���� ����� ������ TX_TRACE, ������� ������������� �����
//!          ������ ���������� (statement). �� ��������� ����������� ���������.
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(),
//!          �� ����� ����� ����������� ���������-���������, ��������,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> ��� WinTail.
//!
//!          �������� ����� ���������� TXLib.h � ���������.
//! @usage
//! @code
//!          #define  _TX_TRACE   // ��� ��������� ������ ��������� DebugView
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#ifdef  _TX_TRACE
    #define $             TX_TRACE

#else
    #define $

#endif

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ���������� ���� ���������� ����� OutputDebugString().
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(),
//!          �� ����� ����� ����������� ���������-���������, ��������,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> ��� WinTail.
//!
//!          TX_TRACE ����� �������������� � ���� ���, ����� �� ����� ����������
//!          ����� ������ ������� ���� TXLib.
//!
//!          �������� ����� ���������� TXLib.h � ���������.
//! @usage
//! @code
//!          #define  TX_TRACE  printf (__LINE__ " ");
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#ifndef TX_TRACE

    #define TX_TRACE         OutputDebugString (__TX_FILELINE__ ": ");

    //! @cond NOT_FOR_DOXYGEN

    #ifndef NDEBUG
        int  _txInitTrace = (OutputDebugString ("\n"),
                             OutputDebugString ("The Dumb Artist Library (TXLib) "
                                                _TX_VERSION " (c) Ded, 2005-10 (Ilya Dedinsky <ded@concord.ru>, http://ded32.net.ru): "
                                                "\"" __FILE__ "\", compiled "__DATE__ " " __TIME__ "\n"),
                             OutputDebugString ("\n"), 1);
    #endif

    //! @endcond

#endif

//=============================================================================
//
//! @name    ��������� ������� ����������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @name    TXLib API. ������������ ��. ���� � ������������ �������.
//-----------------------------------------------------------------------------
//! @cond NOT_FOR_DOXYGEN

bool         txCreateWindow (double sizeX, double sizeY, bool centered = true);
bool         txSetDefaults();
bool         txOK();
POINT        txGetExtent();
int          txGetExtentX();
int          txGetExtentY();
bool         txSetColor (COLORREF color, double thickness = 1);
bool         txColor (double red, double green, double blue);
COLORREF     txGetColor();
bool         txSetFillColor (COLORREF color);
bool         txFillColor (double red, double green, double blue);
COLORREF     txGetFillColor();
int          txExtractColor (COLORREF color, COLORREF component);
COLORREF     txRGB2HSL (COLORREF rgbColor);
COLORREF     txHSL2RGB (COLORREF hslColor);
bool         txSetROP2 (int mode);
bool         txClear();
bool         txSetPixel (double x, double y, COLORREF color);
bool         txPixel (double x, double y, double red, double green, double blue);
COLORREF     txGetPixel (double x, double y);
bool         txLine (double x0, double y0, double x1, double y1);
bool         txRectangle (double x0, double y0, double x1, double y1);
bool         txPolygon (const POINT points[], int numPoints);
bool         txEllipse (double x0, double y0, double x1, double y1);
bool         txCircle (double x, double y, double r);
bool         txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle);
bool         txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle);
bool         txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle);
bool         txTextOut (double x, double y, const char text[]);
bool         txSelectFont (const char name[], double sizeY, double sizeX, int bold, bool italic, bool underline, bool strikeout);
SIZE         txGetTextExtent (const char text[]);
int          txGetTextExtentX (const char text[]);
int          txGetTextExtentY (const char text[]);
bool         txSetTextAlign (unsigned align);
LOGFONT*     txFontExist (const char name[]);
bool         txFloodFill (double x, double y, COLORREF color, DWORD mode);
HRGN         txSelectRegion (double x0, double y0, double x1, double y1);
bool         txSelectObject (HGDIOBJ obj);
int          txBegin();
int          txEnd();
bool         txUpdateWindow (bool update = true);
bool         txTextCursor (bool blink = true);
HDC          txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap = NULL);
HDC          txLoadImage (LPCTSTR filename);
bool         txDeleteDC (HDC dc);
bool         txBitBlt         (HDC dest, double xDest, double yDest, double width, double height,
                               HDC src,  double xSrc,  double ySrc,  DWORD rOp = SRCCOPY);
bool         txTransparentBlt (HDC dest, double xDest, double yDest, double width, double height,
                               HDC src,  double xSrc,  double ySrc,  COLORREF transColor = TX_BLACK);
bool         txAlphaBlend     (HDC dest, double xDest, double yDest, double width, double height,
                               HDC src,  double xSrc,  double ySrc,  double alpha = 1.0);
int          txMouseX();
int          txMouseY();
int          txMouseButtons();
const char*  txInputBox (const char* text, const char* caption, const char* input);
HDC          txDC();
HWND         txWindow();
bool         txLock (bool wait = true);
bool         txUnlock();
template <typename T> inline
T            txUnlock (T value);
const char*  txVersion();
bool         txSleep (int time);
bool         txPlaySound (const char* filename, DWORD mode);
void* _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle, WORD controls,
                              short x, short y, short cx, short cy,
                              const char caption[], const char font[], WORD fontsize, HANDLE menu = NULL);
void* _tx_DLGTEMPLATE_Add    (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                              short x, short y, short cx, short cy,
                              WORD id, const char wclass[], const char caption[]);

//-----------------------------------------------------------------------------
//! @name    ���������� �������
//-----------------------------------------------------------------------------

bool    _txCleanup();
void    _txOnExit();

HWND    _txCanvas_CreateWindow (SIZE size);
bool    _txCanvas_OK();
bool    _txCanvas_DestroyWindow();
int     _txCanvas_SetRefreshLock (int count);
bool    _txCanvas_OnCreate (HWND wnd);
bool    _txCanvas_OnDestroy (HWND wnd);
bool    _txCanvas_OnClose (HWND);
bool    _txCanvas_OnPaint (HWND wnd);
bool    _txCanvas_OnChar (HWND wnd, WPARAM ch);
bool    _txCanvas_OnTimer (HWND wnd, WPARAM id);
bool    _txCanvas_OnMouse (HWND wnd, WPARAM buttons, LPARAM coords);
bool    _txCanvas_OnCmdAbout (HWND wnd, WPARAM cmd);
bool    _txCanvas_OnCmdConsole (HWND wnd, WPARAM cmd);
DWORD   WINAPI   _txCanvas_ThreadProc (LPVOID data);
LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

HDC     _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL);
bool    _txBuffer_Delete (HDC dc);
bool    _txSelect (HGDIOBJ obj, HDC dc = txDC());

bool    _txConsole_Attach();
bool    _txConsole_OK();
bool    _txConsole_Detach();
bool    _txConsole_Draw (HDC dc);
HWND    _txConsole_GetWindow();

bool    _txThrow (const char file[], int line, const char func[], DWORD error, const char msg[], ...) _TX_CHECK_FORMAT (5);
bool    _txCheck (const char msg[]);

#define _txWaitFor(p) { for (int __i##__LINE__ = 0; __i##__LINE__ < _TX_TIMEOUT/10; __i##__LINE__++) \
                                 { if ((p) != 0) break; Sleep (10); } }
//! @endcond

//=============================================================================
//
//! @name    ������ ������� ���������
//
//=============================================================================

FARPROC _txImport (const char lib[], const char name[], int required = true)
    {
$   HMODULE dll  = LoadLibrary (lib);
$   if (!dll  && required) TX_THROW ("\aCannot load %s" _ lib);
$   if (!dll) return NULL;

$   FARPROC addr = GetProcAddress (dll, name);
$   if (!addr && required) TX_THROW ("\aCannot import %s\\%s" _ lib _ name);

$   return addr;
    }

//-----------------------------------------------------------------------------

#define _TX_IMPORT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, true)

#define _TX_IMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, false)

//-----------------------------------------------------------------------------
// Dev-CPP doesn't link with GDI32 by default, so do sunrise by hand. :(
// <tears>

namespace Win32 {

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
_TX_IMPORT ("GDI32", BOOL,     GetBitmapDimensionEx,   (HBITMAP bitmap, LPSIZE dimensions));

_TX_IMPORT ("USER32",HANDLE,   LoadImageA,             (HINSTANCE inst, LPCTSTR name, UINT type,
                                                        int sizex, int sizey, UINT mode));

_TX_IMPORT ("WinMM", BOOL,     PlaySound,              (LPCSTR sound, HMODULE mod, DWORD mode));

_TX_IMPORT_OPT ("MSImg32",BOOL,TransparentBlt,         (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                        HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                        UINT transparentColor));
_TX_IMPORT_OPT ("MSImg32",BOOL,AlphaBlend,             (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                        HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                        BLENDFUNCTION blending));
}  // namespace Win32
using namespace Win32;

// </tears>

//=============================================================================
//
//! @name    ���������� ������.
//           �� ��������� � ��������� ��� �����, ��� ����, ����� ��� ������� �� ���� :)
//
//=============================================================================

HANDLE           _txMainThread          = NULL;   // The thread that contains main()

HANDLE           _txCanvas_Thread       = NULL;   // The thread that owns the TXLib window
HWND             _txCanvas_Wnd          = NULL;

// To make background screen updating smooth, screen refresh process is:
// 1) BackBuf [0 == Main TXLib memory DC] --copied to--> BackBuf [1 == intermediate buffer].
// 2) Console text is drawing on BackBuf [1 == intermediate buffer].
// 3) BackBuf [1 == intermediate buffer]  --copied to--> Screen DC.

HDC              _txCanvas_BackBuf[2]   = {NULL,  // [0] Main TXLib memory DC
                                           NULL}; // [1] intermediate buffer for console text

CRITICAL_SECTION _txCanvas_LockBackBuf  = {0};    // Prevent simultanuous asccess to back buffer,
                                                  //     see txLock()/txUnlock()

UINT             _txCanvas_RefreshTimer = 0;      // Timer to redraw TXLib window

int              _txCanvas_RefreshLock  = 0;      // Blocks automatic on-timer redraw,
                                                  //     see txBegin()/txEnd()

HWND             _txConsole_Wnd         = NULL;   // Console window associated to process
bool             _txConsole_CursorMode  = true;   // To blink or not to blink, that is the question.

bool             _txRunning             = false;
bool             _txExit                = false;  // Setting this to true just before return from
                                                  //     main(), automatically closes the window.
POINT            _txMousePos            = {0};
int              _txMouseButtons        =  0;

//=============================================================================
//
//! @name    ������������� ����������, ��������� ����������, ��������� ����������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���� ���������
//!
//!          ��� �������� ���� ��������������� ��������� ��������� �� ���������,
//!          ��. ������� @ref txSetDefaults().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txOk()
//! @usage
//! @code
//!          txCreateWindow ( 800,  600);
//!          txCreateWindow (1024,  768, false);
//! @endcode
//-----------------------------------------------------------------------------

bool txCreateWindow // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                    (double sizeX,        //!< ������ ���� �� ����������� (� ��������)
                     double sizeY,        //!< ������ ���� �� ���������   (� ��������)
                     bool centered        //!< ������������� ���� �� �������
                     )
    {
$   if (txOK()) return false;

$   atexit (_txOnExit);

$   _txExit     = false;
$   _txRunning  = false;  // _txCanvas_OnCreate will set it to true

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   _txConsole_Attach();

$     setlocale (LC_CTYPE,  "Russian");
$   _wsetlocale (LC_CTYPE, L"Russian_Russia.ACP");

$   SetConsoleCP       (1251);
$   SetConsoleOutputCP (1251);

$   SIZE size = { (int)sizeX, (int)sizeY };
$   if (centered) { size.cx *= -1; size.cy *= -1; }

$   DuplicateHandle (GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(),
                     &_txMainThread, THREAD_SUSPEND_RESUME, FALSE, DUPLICATE_SAME_ACCESS) TX_NEEDED;
$   DWORD id = 0;
$   _txCanvas_Thread = CreateThread (NULL, 0, _txCanvas_ThreadProc, &size, 0, &id);  // Where REAL creation is...
$   _txCanvas_Thread || TX_THROW ("Cannot create _txCanvas_Thread: CreateThread() failed");
$   _txWaitFor (_txCanvas_OK());
$   _txCanvas_OK()   || TX_THROW ("Cannot create canvas");

$   txSetDefaults();

$   SetLastError (0);
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ���������� ��������� �� ���������.
//!
//!          ��������� �� ���������:\n
//!          - ����� - ���� ����� (TX_WHITE), ������� 1
//!          - ������� - ���� ����� (TX_WHITE)
//!          - ����� - ��������� �����, ���� ����� (TX_WHITE)
//!          - ���������� ��������� �������� - ����������� ����� (R2_COPYPEN)
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txSelectFont(), txSelectRegion(), txSetROP2()
//! @usage
//! @code
//!          txSetDefaults();
//! @endcode
//-----------------------------------------------------------------------------

bool txSetDefaults() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txUpdateWindow (false);
$   txLock();

//  Set defaults for graphics layer

$   RECT r = {0};

$   GetClientRect (_txCanvas_Wnd,  &r) TX_NEEDED;
$   SIZE szCanvas = { r.right - r.left, r.bottom - r.top };

$   GetClientRect (_txConsole_Wnd, &r) TX_NEEDED;
$   SIZE szCon    = { r.right - r.left, r.bottom - r.top };

$   _txSelect (GetStockObject (WHITE_PEN),   txDC()) TX_NEEDED;
$   _txSelect (GetStockObject (WHITE_BRUSH), txDC()) TX_NEEDED;
$   _txSelect (CreateFont (szCon.cy/25, szCon.cx/80, 0, 0,
                           FW_REGULAR, FALSE, FALSE, FALSE,
                           DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                           DEFAULT_QUALITY, DEFAULT_PITCH, _TX_CONSOLE_FONT),
                           txDC()) TX_NEEDED;

$   Win32::SetTextColor (txDC(), TX_WHITE);
$   Win32::SetBkMode    (txDC(), TRANSPARENT) TX_NEEDED;

$   Win32::SetROP2      (txDC(), R2_COPYPEN) TX_NEEDED;

//  Set defaults for console layer

$   HDC dc = _txCanvas_BackBuf[1]; dc TX_NEEDED;

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) TX_NEEDED;

$   SIZE szChr  = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
                    (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

$   SIZE szFont = { (short) ((1.0 * szCon.cx / szChr.cx) / (1.0 * szCon.cx / szCanvas.cx)),
                    (short) ((1.0 * szCon.cy / szChr.cy) / (1.0 * szCon.cy / szCanvas.cy)) };

$   _txSelect (txFontExist (_TX_CONSOLE_FONT)? CreateFont (szFont.cy, szFont.cx, 0, 0,
                                                           FW_REGULAR, FALSE, FALSE, FALSE,
                                                           DEFAULT_CHARSET,
                                                           OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                                           DEFAULT_QUALITY, FIXED_PITCH, _TX_CONSOLE_FONT)
                                              :
                                              GetStockObject (SYSTEM_FIXED_FONT),
               dc) TX_NEEDED;

$   Win32::SetTextColor (dc, _TX_CONSOLE_COLOR);
$   Win32::SetBkMode    (dc, TRANSPARENT) TX_NEEDED;

$   txUnlock();
$   txUpdateWindow (true);

    return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������������ ������ ����������
//! @return  ��������� ����������
//! @see     txCreateWindow()
//! @usage
//! @code
//!          txCreateWindow (800, 600);
//!          if (!txOK())
//!              {
//!              MessageBox (txWindow(), "�� ���� ������� ����", "��������", MB_ICONSTOP);
//!              return;
//!              }
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txOK() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return _txConsole_OK() &&
           _txCanvas_OK();
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ��������� � ���� ��������� POINT.
//! @return  ������ ���� ��������� � ���� ��������� POINT.
//! @see     txGetExtentX(), txGetExtentY()
//! @usage
//! @code
//!          POINT size = txGetExtent();
//!          txLine (0, 0,      size.x, size.y);
//!          txLine (0, size.y, size.x, 0);
//! @endcode
//-----------------------------------------------------------------------------

POINT txGetExtent() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   RECT r = {0};
$   GetClientRect (txWindow(), &r);
$   POINT size = { r.right - r.left, r.bottom - r.top };
$   return size;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ���������.
//! @return  ������ ���� ���������.
//! @see     txGetExtent(), txGetExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_CENTER);
//!          txTextOut (txGetExtentX() / 2, 100, "O-o-o, you are in the middle now");
//! @endcode
//-----------------------------------------------------------------------------

inline
int txGetExtentX() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return txGetExtent().x;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ���������.
//! @return  ������ ���� ���������.
//! @see     txGetExtent(), txGetExtentX()
//! @usage
//! @code
//!          void DrawHouse (int height);
//!          ...
//!          DrawHouse (txGetExtentY() / 2);
//! @endcode
//-----------------------------------------------------------------------------

inline
int txGetExtentY() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return txGetExtent().y;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ����� ������� Win32 GDI � �������������� ����������� � ��������������
//! @return  ��������, ������������ ���������� �������� GDI.
//! @param   cmd ������� GDI (��������, ������������ ��������)
//! @note    ���� � ������ ������� GDI ������������ �������, �� ����������� �������
//!          ������, ����� ��������� ���� ��������, ��� ��� txGDI() ���-���� ������.
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @hideinitializer
//! @usage
//! @code
//!          txGDI (( Rectangle (txDC(), x1, y1, x2, y2) )); // �� �������� ��� 2 ������
//! @endcode
//-----------------------------------------------------------------------------

#define txGDI( cmd ) txUnlock ( (txLock(), (cmd)) )

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� � ������� �����, ���� ������.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! @endcode
//-----------------------------------------------------------------------------

bool txSetColor // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                (COLORREF color,   //!< ���� ����� � ������, ��. @ref TX_COLOR_NAMES, RGB()
                 double thickness  //!< ������� �����
                 )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), (int)thickness, color)) &&
            txGDI   ((Win32::SetTextColor (txDC(), color) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ����� � ������.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()
//! @usage
//! @code
//!          txColor (1.0, 0.5, 0.25);
//! @endcode
//-----------------------------------------------------------------------------

bool txColor // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
             (double red,     //!< ���������� �������� ����� � ��������� [0; 1]
              double green,   //!< ���������� �������� ����� � ��������� [0; 1]
              double blue     //!< ���������� ������ ����� � ��������� [0; 1]
              )
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetColor (RGB (red * 255, green * 255, blue * 255));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� � ������.
//! @return  ������� ���� ����� � ������, ��. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetColor();
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txGetColor() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_PEN))); obj TX_NEEDED;

$   char buf [MAX (sizeof (LOGPEN), sizeof (EXTLOGPEN))] = {0};

$   int size = GetObject (obj, 0, NULL);
$   GetObject (obj, sizeof (buf), buf) TX_NEEDED;

$   return (size == sizeof (LOGPEN))? ((LOGPEN*)buf)->lopnColor : ((EXTLOGPEN*)buf)->elpColor;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ���������� �����.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! @endcode
//-----------------------------------------------------------------------------

bool txSetFillColor // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                    (COLORREF color  //!< ���� ����������, ��. @ref TX_COLOR_NAMES, RGB()
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                                 Win32::CreateSolidBrush (color));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ���������� �����.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor()
//! @usage
//! @code
//!          txFillColor (1.0, 0.5, 0.25);
//! @endcode
//-----------------------------------------------------------------------------

bool txFillColor // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                 (double red,   //!< ���������� �������� ����� � ��������� [0; 1]
                  double green, //!< ���������� �������� ����� � ��������� [0; 1]
                  double blue   //!< ���������� ������   ����� � ��������� [0; 1]
                  )
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetFillColor (RGB (red * 255, green * 255, blue * 255));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ���������� �����.
//! @return  ������� ���� ���������� �����, ��. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetFillColor();
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txGetFillColor() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); obj TX_NEEDED;

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) TX_NEEDED;

$   return buf.lbColor;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ����� �������������� ������ ��� ���������.
//!
//!          ��� ��������� ����������� ���������� ����� �� ������ ������� �������
//!          �� ������, � ��������� ����� ������ � ������� ����� ����� � ����������.
//!
//!          ������ �������������� ������:
//!
//!          @table
//!          @tr R2_COPYPEN     @td ������� = ����� ����� (����� ���������� ����� :) @endtr
//!          @tr R2_NOTCOPYPEN  @td ������� = ~�����\n @endtr
//!
//!          @tr R2_BLACK       @td ������� = ������ ���� (���� ����� ������������)    @endtr
//!          @tr R2_WHITE       @td ������� = �����  ���� (���� ����� ������������)    @endtr
//!          @tr R2_NOT         @td ������� = ~�������    (���� ����� ������������)\n  @endtr
//!
//!          @tr R2_XORPEN      @td ������� =    ������� ^  �����    @endtr
//!          @tr R2_NOTXORPEN   @td ������� = ~ (������� ^  �����)\n @endtr
//!
//!          @tr R2_MASKPEN     @td ������� =    ������� &  �����    @endtr
//!          @tr R2_NOTMASKPEN  @td ������� = ~ (������� &  �����)   @endtr
//!          @tr R2_MASKNOTPEN  @td ������� =    ������� & ~�����    @endtr
//!          @tr R2_MASKPENNOT  @td ������� =   ~������� &  �����\n  @endtr
//!
//!          @tr R2_MERGEPEN    @td ������� =    ������� |  �����    @endtr
//!          @tr R2_NOTMERGEPEN @td ������� = ~ (������� |  �����)   @endtr
//!          @tr R2_MERGENOTPEN @td ������� =    ������� | ~�����    @endtr
//!          @tr R2_MERGEPENNOT @td ������� =   ~������� |  �����\n  @endtr
//!
//!          @tr R2_NOP         @td ������� ������ �� ����������.    @endtr
//!          @endtable
//!
//! @return  ���������� ����� �������������� ������, ��. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txSetROP2 (R2_XORPEN);
//!          txSetROP2 (R2_COPYPEN);
//! @endcode
//-----------------------------------------------------------------------------

bool txSetROP2 // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
               (int mode         //!< ����� ���������� ������
                )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::SetROP2 (txDC(), mode) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� (���������) ���� �� ���� ������� ������ (���������).
//! @return  ��������� ���� � ������� COLORREF.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB()
//! @usage
//! @code
//!          txSetColor (RGB (255, 128, 0));
//!
//!          int red = 20, green = 200, blue = 20;
//!          COLORREF color = RGB (red, green, blue);
//!          txSetFillColor (color);
//! @endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
COLORREF RGB (red,       //!< ���������� �������� ����� � ��������� [0; 255]
              green,     //!< ���������� �������� ����� � ��������� [0; 255]
              blue       //!< ���������� ������   ����� � ��������� [0; 255]
              );
#endif

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �������� ���������� (�������� �����) �� ���������� �����.
//! @return  �������� ����������, ��. @ref TX_COLOR_NAMES
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_COLOR_NAMES
//! @usage
//! @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          ������ ������� ��. � �������� AppearText(), AppearEarth() ������� 5 ("�����").
//! @endcode
//-----------------------------------------------------------------------------

int txExtractColor // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                   (COLORREF color,     //!< ��������� ����
                    COLORREF component  //!< ����������� ����������, ��. @ref TX_COLOR_NAMES
                    )
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
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� RGB � ������ HSL.
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
//! @return  ��������� ���� � ���� COLORREF.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_COLOR_NAMES
//! @usage
//! @code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txRGB2HSL // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                   (COLORREF rgbColor   //!< ������������� ���� � ������� RGB
                    )
    {
$   int r = txExtractColor (rgbColor, TX_RED),
        g = txExtractColor (rgbColor, TX_GREEN),
        b = txExtractColor (rgbColor, TX_BLUE);

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
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� HSL � ������ RGB.
//!
//!          ������ RGB ������������ ���
//!
//!          - ������� ���������� ����� (Red),   �� 0 �� 255.
//!          - ������� ���������� ����� (Green), �� 0 �� 255.
//!          - �����   ���������� ����� (Blue),  �� 0 �� 255.
//!
//!          ������ HSL ������������ ���
//!
//!          - �������� ��� (Hue),        �� 0 �� 360.
//!          - ������������ (Saturation), �� 0 �� 255.
//!          - ��������     (Lightness),  �� 0 �� 255.
//!
//! @return  ��������� ���� � ���� COLORREF.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_COLOR_NAMES
//! @usage
//! @code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txHSL2RGB // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                   (COLORREF hslColor   //!< ������������� ���� � ������� HSL
                    )
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

$   int h = txExtractColor (hslColor, TX_HUE),
        s = txExtractColor (hslColor, TX_SATURATION),
        l = txExtractColor (hslColor, TX_LIGHTNESS);

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

//=============================================================================
//
//! @name    ��������� �����
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� ����� ������� ������ ����������.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetFillColor(), txFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txClear();
//! @endcode
//-----------------------------------------------------------------------------

bool txClear() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   POINT size = txGetExtent();

$   return txGDI ((Win32::PatBlt (txDC(), 0, 0, size.x, size.y, PATCOPY) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� (����� �� ������).
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txPixel(), txGetPixel(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSetPixel (100, 100, TX_RED);
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! @endcode
//-----------------------------------------------------------------------------

bool txSetPixel // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                (double x,      //!< �-���������� �����
                 double y,      //!< Y-���������� �����
                 COLORREF color //!< ���� �����, ��. @ref TX_COLOR_NAMES, RGB()
                 )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::SetPixel (txDC(), (int)x, (int)y, color)));

$   RECT r = { (int)x, (int)y, (int)x, (int)y };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� (����� �� ������).
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetPixel(), txGetPixel()
//! @usage
//! @code
//!          txSetPixel (100, 100, 1.0, 0.5, 0.25);
//! @endcode
//-----------------------------------------------------------------------------

bool txPixel // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
             (double x,         //!< �-���������� �����
              double y,         //!< Y-���������� �����
              double red,       //!< ���������� �������� ����� � ��������� [0; 1]
              double green,     //!< ���������� �������� ����� � ��������� [0; 1]
              double blue       //!< ���������� ������ ����� � ��������� [0; 1]
              )
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetPixel (x, y, RGB (red * 255, green * 255, blue * 255));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� (�������) �� ������.
//! @return  ������� ���� �������, ��. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetPixel(), txPixel(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED) CarCrash (x, y);
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txGetPixel // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                    (double x,  //!< �-���������� �����
                     double y   //!< Y-���������� �����
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::GetPixel (txDC(), (int)x, (int)y)));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!          ���� � ������� ����� �������� �������� txSetColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txLine (100, 200, 400, 500);
//! @endcode
//-----------------------------------------------------------------------------

bool txLine // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
            (double x0,        //!< X-���������� ��������� �����
             double y0,        //!< Y-���������� ��������� �����
             double x1,        //!< X-���������� ��������  �����
             double y1         //!< Y-���������� ��������  �����
             )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::MoveToEx (txDC(), (int)x0, (int)y0, NULL))) TX_NEEDED;
$   txGDI ((Win32::LineTo   (txDC(), (int)x1, (int)y1)))       TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �������������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txRectangle (100, 200, 400, 500);
//! @endcode
//-----------------------------------------------------------------------------

bool txRectangle // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                 (double x0,   //!< X-���������� �������� ������ ����
                  double y0,   //!< Y-���������� �������� ������ ����
                  double x1,   //!< X-���������� ������� ������� ����
                  double y1    //!< Y-���������� ������� ������� ����
                  )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::Rectangle (txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� ����� ��� �������������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          POINT star[6] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}, {150, 300}};
//!          txPolygon (star, 6);
//! @endcode
//-----------------------------------------------------------------------------

bool txPolygon // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
               (POINT* points, //!< ������ �������� POINT � ������������ �����
                int numPoints  //!< ���������� ����� � �������
                )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::Polygon (txDC(), points, numPoints) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txEllipse (100, 100, 300, 200);
//! @endcode
//-----------------------------------------------------------------------------

bool txEllipse // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
               (double x0,     //!< X-���������� �������� ������ ���� ���������� ��������������
                double y0,     //!< Y-���������� �������� ������ ���� ���������� ��������������
                double x1,     //!< X-���������� ������� ������� ���� ���������� ��������������
                double y1      //!< Y-���������� ������� ������� ���� ���������� ��������������
                )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::Ellipse (txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���������� ��� ����.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txCircle (100, 100, 10);
//! @endcode
//-----------------------------------------------------------------------------

bool txCircle // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
              (double x,       //!< �-���������� ������
               double y,       //!< Y-���������� ������
               double r        //!< ������
               )
    {
$   return txEllipse (x-r, y-r, x+r, y+r);
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���� �������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txArc (100, 100, 300, 200, 0, 180);
//! @endcode
//-----------------------------------------------------------------------------

bool txArc // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
           (double x0,         //!< X-���������� �������� ������ ���� ��������������,
                               //!<   ���������� ������ �������, ����������� ����
            double y0,         //!< Y-���������� �������� ������ ���� ��������������
            double x1,         //!< X-���������� ������� ������� ���� ��������������
            double y1,         //!< Y-���������� ������� ������� ���� ��������������
            double startAngle, //!< ���� ����� ������������ ��� OX � ������� ���� (� ��������)
            double totalAngle  //!< �������� ���� (� ��������)
            )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Arc (txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                        center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                        center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������ �������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txPie (100, 100, 300, 200, 0, 180);
//! @endcode
//-----------------------------------------------------------------------------

bool txPie // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
           (double x0,         //!< X-���������� �������� ������ ���� ��������������,
                               //!<   ���������� ������ �������, ����������� ������
            double y0,         //!< Y-���������� �������� ������ ���� ��������������
            double x1,         //!< X-���������� ������� ������� ���� ��������������
            double y1,         //!< Y-���������� ������� ������� ���� ��������������
            double startAngle, //!< ���� ����� ������������ ��� OX � ������� ������� (� ��������)
            double totalAngle  //!< �������� ������� (� ��������)
            )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Pie (txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                        center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                        center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ����� �������.
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txChord (100, 100, 300, 200, 0, 180);
//! @endcode
//-----------------------------------------------------------------------------

bool txChord // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
             (double x0,         //!< X-���������� �������� ������ ���� ��������������,
                                 //!<   ���������� ������ �������, ����������� �����
              double y0,         //!< Y-���������� �������� ������ ���� ��������������
              double x1,         //!< X-���������� ������� ������� ���� ��������������
              double y1,         //!< Y-���������� ������� ������� ���� ��������������
              double startAngle, //!< ���� ����� ������������ ��� OX � ������� ����� (� ��������)
              double totalAngle  //!< �������� ����� (� ��������)
              )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Chord (txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                          center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                          center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������������ ������ ������� ������ ����������.
//!          ���� ���������� �������� �������� txSetFillColor().
//!          �� ������������� ��� ���������� - �������� �������� ��������.
//!
//!          ������ �������:
//!
//!          FLOODFILLSURFACE - �������� �������, ��������� ������ color.\n
//!          FLOODFILLBORDER  - �������� �� �������, ��������� ������ color.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txFloodFill (100, 100);
//! @endcode
//-----------------------------------------------------------------------------

bool txFloodFill // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                 (double x,                        //!< �-���������� ����� ������ �������
                  double y,                        //!< Y-���������� ����� ������ �������
                  COLORREF color = TX_TRANSPARENT, //!< ���� ���������� ������� (TX_TRANSPARENT - ���������������)
                  DWORD mode = FLOODFILLSURFACE    //!< ����� ������� (FLOODFILLSURFACE - ������� ����������� ����)
                  )
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y);

$   return txGDI ((Win32::ExtFloodFill (txDC(), (int)x, (int)y, color, mode) != 0));
    }

//=============================================================================
//
//! @name    ������ � �������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!          ���� ������ �������� �������� txSetColor().
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//! @endcode
//-----------------------------------------------------------------------------

bool txTextOut // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
               (double x,         //!< �-���������� ��������� ����� ������
                double y,         //!< Y-���������� ��������� ����� ������
                const char text[] //!< ��������� ������
                )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   int len = (int) strlen (text);
$   txGDI ((Win32::TextOut (txDC(), (int)x, (int)y, text, len))) TX_NEEDED;

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, len, &size))) TX_NEEDED;

$   RECT r = { (int)x, (int)y, (int)x + size.cx, (int)y + size.cy };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������� �����.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txTextOut()
//! @usage
//! @code
//!          txSelectFont ("Comic Sans MS", 20);
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//!          txSelectFont ("Comic Sans MS", 20, 10, false, true, false, true);
//!          txTextOut (100, 200, "�� �� ������-�� ���.");
//! @endcode
//-----------------------------------------------------------------------------

bool txSelectFont // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                  (const char* name,       //!< �������� ������
                   double sizeY,           //!< ������ ���� (������ �� Y)
                   double sizeX = 0,       //!< ������ ����
                   int bold = FW_DONTCARE, //!< �������� ������ (�� 0 �� 1000)
                   bool italic = false,    //!< ������
                   bool underline = false, //!< �������������
                   bool strikeout = false  //!< ������������
                   )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   _txSelect (txFontExist (name)? CreateFont ((int)sizeY, (int) ((int)sizeX? sizeX : sizeY/3), 0, 0,
                                               bold, italic, underline, strikeout,
                                               DEFAULT_CHARSET,
                                               OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                               DEFAULT_QUALITY, FIXED_PITCH, name)
                                   :
                                   GetStockObject (SYSTEM_FIXED_FONT));
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������� ��������� �������.
//! @return  ������� ������� � ��������� SIZE.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          SIZE size = txGetTextExtent (text);
//!          txTextOut (100 + size.cx / 2, 200 + size.cy / 2, text);
//! @endcode
//-----------------------------------------------------------------------------

SIZE txGetTextExtent // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                     (const char* text     //!< ��������� ������
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, (int) strlen (text), &size))) TX_NEEDED;

$   return size;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������ ��������� �������.
//! @return  ������ �������.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//-----------------------------------------------------------------------------

int txGetTextExtentX // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                     (const char text[]     //!< ��������� ������
                      )
    {
$   return txGetTextExtent (text) .cx;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������ ��������� �������.
//! @return  ������ �������.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//-----------------------------------------------------------------------------

int txGetTextExtentY // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                     (const char text[]     //!< ��������� ������
                      )
    {
$   return txGetTextExtent (text) .cy;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ������������ ������.
//!
//!          ����� ������������:
//!
//!          @table
//!          @tr TA_BASELINE @td ����� (X,Y) ���������� ������� ����� ������. @endtr
//!          @tr TA_BOTTOM   @td ����� (X,Y) ���������� ������ ������� ���������� ��������������\n
//!                              (����� ����� ���� ���� �����).   @endtr
//!          @tr TA_TOP      @td ����� (X,Y) ���������� ������� ������� ���������� ��������������\n
//!                              (����� ����� ���� ���� �����).\n @endtr
//!
//!          @tr TA_CENTER   @td ����� ����� �������� �� ����������� ������������ ����� (X,Y). @endtr
//!          @tr TA_LEFT     @td ����� (X,Y) ���������� ����� ������� ���������� ��������������\n
//!                              (����� ����� ������ ���� �����). @endtr
//!          @tr TA_RIGHT    @td ����� (X,Y) ���������� ������ ������� ���������� ��������������\n
//!                              (����� ����� ����� ���� �����).  @endtr
//!          @endtable
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_RIGHT);
//!
//!          txSetTextAlign();
//! @endcode
//-----------------------------------------------------------------------------

bool txSetTextAlign // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                    (unsigned align = TA_CENTER | TA_BASELINE //!< ����� ������������
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::SetTextAlign (txDC(), align)));
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���� ����� �� ��� ��������.
//! @return  ���������� � ������ � ��������� LOGFONT.
//!          ���� ����� �� ������, ���������� NULL.
//! @see     txTextOut(), txSelectFont()
//! @usage
//! @code
//!          if (txFontExist ("Comic Sans MS")) txSelectFont ("Comic Sans MS", 30);
//!          else                               txSelectFont ("Times", 30);
//! @endcode
//-----------------------------------------------------------------------------

LOGFONT* txFontExist // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                     (const char* name      //!< �������� ������
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

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

$   return txGDI ((Win32::EnumFontFamiliesEx (txDC(), &font, enumFonts::Proc, (LPARAM)&font, 0) == 0? &font : NULL));
    }

//=============================================================================
//
//! @name    ������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ������������� ������ ���������.
//!          ��, ��� ����������� ��� ������� ���������, �� ��������.
//!
//!          ��������������� ������� �������������� ��������������
//!          ����� ����������� ������� ������ � ��������� �� Win32 API.
//!
//! @return  ����������� �������������� �������. ���� ������ �� ������ ��� �� ���������� - NULL.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSelectRegion (100, 100, 300, 400);
//! @endcode
//-----------------------------------------------------------------------------

HRGN txSelectRegion // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                    (double x0,   //!< X-���������� �������� ������ ����
                     double y0,   //!< Y-���������� �������� ������ ����
                     double x1,   //!< X-���������� ������� ������� ����
                     double y1    //!< Y-���������� ������� ������� ����
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HRGN rgn = CreateRectRgn ((int)x0, (int)y0, (int)x1, (int)y1);

$   txSelectObject (rgn) || (Win32::DeleteObject (rgn), rgn = NULL);

$   return rgn;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� ������� ������ GDI.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txSelectFont(), txSelectRegion()
//! @usage
//! @code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! @endcode
//-----------------------------------------------------------------------------

bool txSelectObject // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                    (HGDIOBJ obj   //!< ���������� ������� GDI
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect (obj);
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ���������� ����������� ����, �� ��������� �������.
//!
//! @warning ��������� ������������ �� ������ �����. ��� ����� �������� �
//!          �������� ����������� � ����. ���� ��������� ��������, �� �����������
//!          txSleep() ������ ������� ������� Sleep().
//!
//! @return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor()
//! @usage
//! @code
//!          txBegin();
//!          txSetFillColor (TX_WHITE);
//!          txClear();
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();
//! @endcode
//-----------------------------------------------------------------------------

inline
int txBegin() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock + 1);

$   return _txCanvas_RefreshLock;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������ ���������� ����, ��������������� �������� txBegin().
//!
//! @warning ���� txBegin() ���������� ��������� ���, �� ��� ������ ����������
//!          ��������� ������� �� ��� ������� txEnd().
//!
//! @return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor()
//! @usage
//! @code
//!          txBegin();
//!          txSetFillColor (TX_WHITE);
//!          txClear();
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();
//! @endcode
//-----------------------------------------------------------------------------

inline
int txEnd() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock - 1);

$   return _txCanvas_RefreshLock;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ��������� ��� ������������ ���������� ����������� � ����.
//!
//!          � ������� �� txBegin() � txEnd(), ��������� ���� ���������� ���
//!          ����� ����������.
//!
//! @warning ��������� ������������ �� ������ �����. ��� ����� �������� �
//!          �������� ����������� � ����. ���� ��������� ��������, �� �����������
//!          txSleep() ������ ������� ������� Sleep().
//!
//! @return  ���������� ��������� ������ ����������.
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txUpdateWindow // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                    (bool update   //!< ����� ���������� (false - ��������� ����������)
                     )
    {
$   return _txCanvas_SetRefreshLock (update? 0 : 1) != 0;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ��� ������������ ��������� ��������� ������� � ����.
//! @return  ���������� �������� ����������.
//! @see     txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! @endcode
//-----------------------------------------------------------------------------

bool txTextCursor // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                  (bool blink   //!< false - ����������� �������� ������
                   )
    {
$   bool old = _txConsole_CursorMode;

$   _txConsole_CursorMode = blink;

$   return old;
    }

//=============================================================================
//
//! @name    ��������� � ������ (�� "����������� ������") � �������� �����������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� �������������� ����� (�������� ���������, Device Context, DC) � ������.
//! @return  ���������� (��������� �����, �������� Windows) ���������� ������ (��������� ���������).
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//!
//! @remarks ��������� �������� ����� ����� ����� ������� ��� ������ txDeleteDC().
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

HDC txCreateCompatibleDC // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                         (double sizeX,     //!< ������ ������
                          double sizeY,     //!< ������ ������
                          HBITMAP bitmap    //!< Bitmap associated with DC
                          )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   POINT size = { (int)sizeX, (int)sizeY };
$   HDC dc = _txBuffer_Create (txWindow(), &size, bitmap); dc TX_NEEDED;
$   return dc;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �� ����� ����������� � ������� BMP. ������ ��� �������� ��������.
//!
//!          ����������� ����������� � ����������� �������� ��������� � ������ ("����������� �����"),
//!          ������� ����� ����� ����� <b>�����������</b> ������� ��� ������ txDeleteDC().
//!
//!          ����������� �������������� ������ � ������� BMP. ���� ����� ���� ������� �������, �������� JPG, � �������������
//!          ��� �� ������ ���������� �� BMP, �� �� ����� ������ �� ���������. ����� ����������� ��������� �� �����.
//!
//! @return  ���������� ���������� ��������� ��������� � ������, � ����������� ������������.
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(), txTransparentBlt(),
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//-----------------------------------------------------------------------------

HDC txLoadImage // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                (LPCTSTR filename  //!< ��� ����� � ������������ � ������� BMP
                 )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HBITMAP image = (HBITMAP) LoadImage (NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
$   if (!image) return NULL;

$   HDC dc = txCreateCompatibleDC (0, 0, image);

$   return dc;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ����� (�������� ���������, DC) � ������.
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//-----------------------------------------------------------------------------

bool txDeleteDC // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                (HDC dc            //!< �������� ��������� ��� �����������
                 )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txBuffer_Delete (dc);
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������.
//!
//!          ������ �����������:
//!
//!          @table
//!          @tr SRCCOPY     @td ������ �������� :) - ����� ���������������� �����\n @endtr
//!
//!          @tr BLACKNESS   @td ��������� �����-�������� ������ ������ (�����-�������� ������������). @endtr
//!          @tr WHITENESS   @td ��������� �����-�������� ����� ������  (�����-�������� ������������). @endtr
//!          @tr DSTINVERT   @td ����������� ����� �� ������-���������  (�����-�������� ������������). @endtr
//!          @tr PATCOPY     @td �������� ���� ������� ����� ������-���������.\n @endtr
//!
//!          @tr MERGECOPY   @td �������� =   �������� & ���� ������� ����� ���������. @endtr
//!          @tr MERGEPAINT  @td �������� = ~ �������� | �������� @endtr
//!          @tr NOTSRCCOPY  @td �������� = ~ �������� @endtr
//!          @tr NOTSRCERASE @td �������� = ~ (�������� | ��������) @endtr
//!          @tr PATINVERT   @td �������� =  ����� ��������� ^  �������� @endtr
//!          @tr PATPAINT    @td �������� = (����� ��������� | ~��������) | �������� @endtr
//!          @tr SRCAND      @td �������� =  �������� & �������� @endtr
//!          @tr SRCERASE    @td �������� = ~�������� & �������� @endtr
//!          @tr SRCINVERT   @td �������� =  �������� ^ �������� @endtr
//!          @tr SRCPAINT    @td �������� =  �������� | �������� @endtr
//!          @endtable
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//-----------------------------------------------------------------------------

bool txBitBlt // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
              (HDC dest,        //!< �������� ���������� (���� ����������)
               double xDest,    //!< �-���������� �������� ������ ���� �����������-���������
               double yDest,    //!< Y-���������� �������� ������ ���� �����������-���������
               double width,    //!< ������ ����������� �����������
               double height,   //!< ������ ����������� �����������
               HDC src,         //!< �������� ��������� (������ ����������)
               double xSrc,     //!< �-���������� �������� ������ ���� �����������-���������
               double ySrc,     //!< Y-���������� �������� ������ ���� �����������-���������
               DWORD rOp        //!< ��������� �������� �����������
               )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::BitBlt (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                                  src,  (int)xSrc,  (int)ySrc, rOp) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������
//! @brief   � ������ ������������.
//!
//!          ����������� ������� TransparentBlt �� Win32 API ����� �������������� �����������.
//!          � txTransparentBlt ��� ������ ��� ��������� �������������. If you need image scaling,
//!          use original function TransparentBlt and don't mess with stupid TX-based tools.
//!          (See implementation of txTransparentBlt in TXLib.h).
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC superman = txLoadImage ("Resources\\Images\\SuperMan.bmp");
//!          txTransparentBlt (txDC(), 0, 0, 800, 600, superman, 0, 0);
//!          txDeleteDC (superman);  // So pity :(
//! @endcode
//-----------------------------------------------------------------------------

bool txTransparentBlt // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                      (HDC dest,             //!< �������� ���������� (���� ����������)
                       double xDest,         //!< �-���������� �������� ������ ���� �����������-���������
                       double yDest,         //!< Y-���������� �������� ������ ���� �����������-���������
                       double width,         //!< ������ ����������� �����������
                       double height,        //!< ������ ����������� �����������
                       HDC src,              //!< �������� ��������� (������ ����������)
                       double xSrc,          //!< �-���������� �������� ������ ���� �����������-���������
                       double ySrc,          //!< Y-���������� �������� ������ ���� �����������-���������
                       COLORREF transColor   //!< ����, ������� ����� ��������� ����������
                       )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   if (!TransparentBlt) return false;

$   return Win32::TransparentBlt (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                                  src,  (int)xSrc,  (int)ySrc,  (int)width, (int)height, transColor) != 0;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������
//! @brief   � ������ ������������.
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
//!          � txAlphaBlend ��� ������ ��� ��������� �������������. If you still need image
//!          scaling, use original function AlphaBlend and don't mess with stupid TX-based
//!          tools. (See implementation of txAlphaBlend in TXLib.h).
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC superman = txLoadImage ("Resources\\Images\\SuperMan.bmp");
//!          txAlphaBlend (txDC(), 0, 0, 800, 600, superman, 0, 0);
//!          txDeleteDC (superman);  // Don't worry, he'll come back in future series
//! @endcode
//-----------------------------------------------------------------------------

bool txAlphaBlend // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                  (HDC dest,        //!< �������� ���������� (���� ����������)
                   double xDest,    //!< �-���������� �������� ������ ���� �����������-���������
                   double yDest,    //!< Y-���������� �������� ������ ���� �����������-���������
                   double width,    //!< ������ ����������� �����������
                   double height,   //!< ������ ����������� �����������
                   HDC src,         //!< �������� ��������� (������ ����������)
                   double xSrc,     //!< �-���������� �������� ������ ���� �����������-���������
                   double ySrc,     //!< Y-���������� �������� ������ ���� �����������-���������
                   double alpha     //!< ����� ������������ �����������, � ���������� � �����-������.\n
                                    //!<   (0 - ��� ���������, 1 - ������������ ������ �����-�����)
                   )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   if (!AlphaBlend) return false;

$   if (alpha < 0) alpha = 0;
$   if (alpha > 1) alpha = 1;

#ifndef     AC_SRC_ALPHA
    #define AC_SRC_ALPHA 0x01   // On some old MinGW versions, this is not defined.
#endif

$   BLENDFUNCTION blend = {AC_SRC_OVER, 0, (BYTE) (alpha * 255), AC_SRC_ALPHA};

$   return Win32::AlphaBlend (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                              src,  (int)xSrc,  (int)ySrc,  (int)width, (int)height, blend) != 0;
    }

//=============================================================================
//
//! @name    ������ � �����
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� �-���������� ����!
//! @return  �-���������� ����.
//! @see     txMouseX(), txMouseY(), txMouseButtons()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
int txMouseX() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return _txMousePos.x;
    }

//-----------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� Y-���������� ����!
//! @return  Y-���������� ����.
//! @see     txMouseX(), txMouseY(), txMouseButtons()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
int txMouseY() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return _txMousePos.y;
    }

//-----------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� ��������� ������ ����!
//!
//!          � ������������ �������� ������������ � ������� 1-� (�������)
//!          ��� �������� ������� ����� ������ ����, 2-� - ������, 3-� -
//!          �������.\n ��������, ������������ ����� 5 (�������� 101) ��������
//!          ������������� ������� ������� � ����� ������, �� �� ������ ������.
//!
//! @return  ��������� ������ ����!
//! @see     txMouseX(), txMouseY(), txMouseButtons()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

int txMouseButtons() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return _txMouseButtons;
    }

//=============================================================================
//
//! @name    ������ � ����������� ������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ������� ����� ��� ���������� ����.
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
//! @see     txDialog::setLayout(), txDialog::dialogProc(), txDialog::Layout,
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

struct txDialog
    {

//-----------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ��������� ��� ������� ���� ��������.
//!
//!          ������ �������� ����� ������������ �������� ������� �������,
//!          ��������������� � ���� txDialog::CONTROL.
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @hideinitializer
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
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
//! @ingroup Dialogs
//! @brief   ����� ��� �������� �������� ����������� ���� (��������)
//!
//!          ������ ����� �������� ������ �������� ������ ����������� ����.
//!          ��� �������� ������ �� ������� ������� � ��������� ������� (.rc):
//!
//!           - ������� ������� ��������� ���������� ���� � �����
//!           - ��������� �������� ��������� ��������
//!           - ��������� ������� - txDialog::END ��� {NULL}
//!
//! @see     txDialog::setLayout(), txDialog::dialogBox(), txDialog::dialogProc()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
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
//! @brief   �����������.
//! @see     txDialog::txDialog (const txDialog::Layout*)
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    public:
    txDialog ();

//-----------------------------------------------------------------------------
//! @brief   �����������.
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    txDialog (const Layout* layout               //!< ����� ����������� ����
             );

//-----------------------------------------------------------------------------
//! @brief   ����������.
//-----------------------------------------------------------------------------

    virtual ~txDialog () {};

//-----------------------------------------------------------------------------
//! @brief   ������������� ������� ����� ����������� ����.
//! @return  ���������� �����.
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    const Layout* setLayout (const Layout* layout //!< ����� ����������� ����
                            );

//-----------------------------------------------------------------------------
//! @brief   ������� ��������� ��������� ����������� ����.
//!
//!          ��� ������� ���� �������������� ��� ��������� ������� ����,
//!          ��� ��������� �� � ������� �������� TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @return  � ����������� ������� false, ��������� ��. DialogProc
//!          � <a href=msdn.com>MSDN</a>.
//! @see     txDialog::dialogBox()
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd,           //!< ����������
                            UINT _msg,           //!< ����� ���������
                            WPARAM _wParam,      //!< 1-� �������� ��������� (WORD)
                            LPARAM _lParam       //!< 2-� �������� ��������� (DWORD)
                            );

//-----------------------------------------------------------------------------
//! @brief   ��������� ���������� ����.
//! @return  ��������, ��������� � ������� EndDialog().\n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
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
//! @brief   ��������� ���������� ����.
//! @return  ��������, ��������� � ������� EndDialog().\n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//! @see     txDialog::dialogProc()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource  //!< ������������� ����������� �������
                       );

//-----------------------------------------------------------------------------
//! @brief   �������� ����������� ����������� � �������� ������������.
//-----------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//-----------------------------------------------------------------------------
//! ��������� ���������� ������� (�� @ref txDialog::dialogProc(), �.�. ������� ����
//! Win32 ������ ���� �����������).

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//-----------------------------------------------------------------------------
//! ������� ����� �������.

    private:
    const Layout* layout_;
    };

//=============================================================================
//
//! @name    ���������� ������� ������ txDialog
//
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
            case IDCANCEL:  $ SetForegroundWindow (txWindow());
                            $ EndDialog (wnd, (INT_PTR) this__); break;
            default:        $ break;
            }

        default:            $ break;
        }

$   return this__-> dialogProc (wnd, msg, wParam, lParam);
    }

//=============================================================================
//
//! @name    ������� ��� ���������� ����������� ����� ��������� (Message Map)
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����� ��������� (Message Map).
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#define TX_BEGIN_MESSAGE_MAP()                                                     \
    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)  \
        {                                                                          \
        _wnd = _wnd; _msg = _msg; _wParam = _wParam; _lParam = _lParam;            \
                                                                                   \
        switch (_msg)                                                              \
            {                                                                      \
            case WM_NULL:

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����������� ��������� (Message handler) ����� ���������.
//! @param   id ������������� ���������
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ����� ������ (Command map) � ����� ���������.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#define TX_COMMAND_MAP                                                             \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        if (_msg == WM_COMMAND) switch (LOWORD (_wParam))                          \
            {

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ����� ���������.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#define TX_END_MESSAGE_MAP                                                         \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        return FALSE;                                                              \
        }

//=============================================================================
//
//! @name    ������ ������������� ������ �������: ������� txInputBox()
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ���� ������ � ��������� ����.
//! @return  ��������� ������ (����������� ���������� �������).
//! @warning ������������ ������ - �����������, � ����������� ��� ������ ������ �������!
//!          ��� ���������� �� ���������� ���������� ��� ������ <i>strcpy()</i>.
//! @see     txDialog, TX_BEGIN_MESSAGE_MAP, TX_BEGIN_COMMAND_MAP, TX_HANDLE, TX_END_MESSAGE_MAP
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

const char* txInputBox // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                       (const char* text    = NULL, //!< ����� � ��������
                        const char* caption = NULL, //!< ��������� ����
                        const char* input   = NULL  //!< �������� ������ �� ���������
                        )
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
//
//! @name    Back-hole (I hope, not an ass-hole:) of the library)
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ���������� ���������� ��������� ��������� (DC) ������
//! @return  ���������� ��������� ��������� ������
//! @see     txWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
HDC txDC() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return _txCanvas_BackBuf[0];
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ���������� ���������� ���� ������
//! @return  ���������� ���� ������
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
HWND txWindow() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return _txCanvas_Wnd;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ���������� ������ (��������� ���������).
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
//! @return  ��������� ����������
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txLock // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
            (bool wait   //!< ������� ����� ����������� ���� ��������������� �������
            )
    {
$   if (wait) { return    EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { return TryEnterCriticalSection (&_txCanvas_LockBackBuf) != 0;  }
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� ������
//! @return  ��������� ���������� (������ false)
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------
//! @{

template <typename T>
inline
T    txUnlock ( // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
            T value      //!< ��������, ������������ ������ txUnlock()
            )
    {
$   txUnlock();
$   return value;
    }

inline
bool txUnlock() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   LeaveCriticalSection (&_txCanvas_LockBackBuf);
$   return false;
    }

//! @}

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ������ � ����������� � ������� ������ ����������.
//! @return  ������ � ����������� � ������� ������ ����������.
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
const char* txVersion() // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
    {
$   return _TX_VERSION;
    }

//=============================================================================
//
//! @name    ������ �������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������� ������� � ���������
//!
//!          ������ sizearr() ����� ������ ������� � ������ �� ������ �������� �������,
//!          ���������� ������ ������� � ���������.
//!
//! @param   arr ��� �������
//! @return  ������ ������� � ���������
//! @warning ����������� ������� ������ � ��� �������� ������ ���� ��������
//!          � ����� ������������� sizearr(). ������ ������� � ������ ������ ����
//!          �������� ��� ����������.
//! @hideinitializer
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

#define sizearr( arr )   ( sizeof (arr) / sizeof (arr)[0] )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������, ��������� �� �������� � ������ ���������� ��������� [a; b]
//! @return  ���� a <= x && x <= b, �� ������, ���� ��� - ����
//! @hideinitializer
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

template <typename T>
inline
bool In // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
        (T x, //!< ����������� ��������
         T a, //!< �����  ������� (������������)
         T b  //!< ������ ������� (������������)
         )
    {
    return a <= x && x <= b;
    }

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������, ��������� �� ����� pt ������ �������������� rect
//! @return  ��������� ��������
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
bool In // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
        (const COORD& pt,       //!< ����������� �����
         const SMALL_RECT& rect //!< �������������
         )
    {
    return In (pt.X, rect.Left, rect.Right) &&
           In (pt.Y, rect.Top,  rect.Bottom);
    }

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��������� �����
//! @param   range ������ ������� ��������� (�� ������� ���� �������).
//! @return  ��������� ����� ����� � ��������� [0; range).\n
//!          �� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//! @hideinitializer
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

#define random( range )  ( rand() % (range) )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ���������� ��������� �� ������������ �����.
//!
//!          �� ����� �������� ���������� ����������� � ���� ������
//!          ������������� ��������������.
//!
//! @return  ��������� ���������� ���������� ����.
//! @see     txUpdateWindow()
//! @usage
//! @code
//!          txSleep (500); // ������� ����������
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txSleep // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
             (int time   //!< �������� � �������������
              )
    {
    _txCheck (__TX_FUNCTION__); assert (txOK());

$   int old = _txCanvas_SetRefreshLock (0);

$   Sleep (time);

$   _txCanvas_SetRefreshLock (old);
$   return old != 0;
    }

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� �������� ����.
//!
//!          ������ ���������������:
//!
//!          @table
//!          @tr SND_ASYNC       @td ���� ������������� ������������ � ������� ���������.\n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL). @endtr
//!          @tr SND_SYNC        @td ���������� ��������� ������������������ �� ���������
//!                                  ��������������� �����. @endtr
//!          @tr SND_LOOP        @td ����������� ���� ��� ���������������.\n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL).\n @endtr
//!
//!          @tr SND_NODEFAULT   @td �� ������������ ���� �� ���������, ���� ������ ���������
//!                                  ��������� �������� ����. @endtr
//!          @tr SND_NOSTOP      @td ���� �����-���� ���� ��� �������������, �� �������������
//!                                  ��� ��� ��������������� ���������� �����. @endtr
//!          @tr SND_APPLICATION @td ����������� ����, ��������� ���������, ������������������
//!                                  ��� ������� ���� �������� ������. @endtr
//!          @endtable
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

bool txPlaySound // ��� �� ������ � TXLib.h! ��. TXLib Help, ��������, ������ � ��������
                 (const char* filename = NULL, //!< ��� ��������� �����.
                                               //!< ���� NULL - ������������� ����.
                  DWORD mode = SND_ASYNC       //!< ����� ���������������
                  )
    {
$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;
$   if (!filename) mode = SND_PURGE;

$   return PlaySound (filename, NULL, mode) != 0;
    }

//=============================================================================
//
//! @name    ���������� ������� TXLib
//
//=============================================================================

bool _txCheck (const char msg[])
    {
$   if (txOK()) return true;

$   MessageBox (txWindow(), "������: ���� ��������� �� �������!    ", (msg && *msg)? msg : "TXLib", MB_ICONSTOP);

$   exit (1); //  �� ��������� ������ �������� � ����� ������� � ���������� ���������� ������ ���. :(

//  return false;
    }

//-----------------------------------------------------------------------------

void _txOnExit()
    {
$   _txRunning = false;

$   Sleep (10);
$   if (!_txExit) WaitForSingleObject (_txCanvas_Thread, INFINITE);

$   if (_txCanvas_Thread)
        {
$       CloseHandle (_txCanvas_Thread) TX_NEEDED;
$       _txCanvas_Thread = NULL;
        }

$   _txConsole_Detach();

$   DeleteCriticalSection (&_txCanvas_LockBackBuf);

#ifndef NDEBUG
    OutputDebugString ("\n");
    OutputDebugString ("TXLib " _TX_VERSION " -- FINISHED\n");
    OutputDebugString ("\n");
#endif
    }

//=============================================================================
//
//! @name    ������� ��������� ���� (_txCanvas...)
//
//=============================================================================

DWORD WINAPI _txCanvas_ThreadProc (LPVOID data)
    {
$   assert (data);

$   _txCanvas_CreateWindow (*(SIZE*) data);
$   _txCanvas_Wnd || TX_THROW ("Cannot create canvas: _txCanvas_CreateWindow() failed");

$   MSG msg = {0};
$   while (GetMessage  (&msg, NULL, 0, 0))
        {
$       TranslateMessage (&msg);
$       DispatchMessage  (&msg);

$       Sleep (0);
        }

$   return (DWORD) msg.wParam;
    }

//-----------------------------------------------------------------------------

HWND _txCanvas_CreateWindow (SIZE clientSize)
    {
$   const char className[] = __FILE__ "\\_txCanvas\\Class";

$   WNDCLASSEX wc    = {0};
$   wc.cbSize        = sizeof (wc);
$   wc.style         = CS_HREDRAW | CS_VREDRAW;
$   wc.lpfnWndProc   = _txCanvas_WndProc;
$   wc.hInstance     = NULL;
$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) GetStockObject (HOLLOW_BRUSH);
$   wc.lpszClassName = className;
$   RegisterClassEx (&wc) || TX_THROW ("RegisterClass (\"%s\") failed"_ className);

$   char name[256] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1) TX_NEEDED;
$   strncat_s (name, " - TXLib", sizeof (name));
$   const char* title = strrchr (name, '\\'); title = title? title+1 : name;

$   int centered = false;
$   if (clientSize.cx < 0 && clientSize.cy < 0) { clientSize.cx *= -1; clientSize.cy *= -1; centered = true; }

$   SIZE scr     = { GetSystemMetrics (SM_CXSCREEN),     GetSystemMetrics (SM_CYSCREEN)     };
$   SIZE frame   = { GetSystemMetrics (SM_CXFIXEDFRAME), GetSystemMetrics (SM_CYFIXEDFRAME) };
$   SIZE caption = { 0, GetSystemMetrics (SM_CYCAPTION) };
$   SIZE size    = { clientSize.cx + 2*frame.cx, clientSize.cy + 2*frame.cy + caption.cy };
$   POINT center = { scr.cx / 2, scr.cy / 2 };

$   if (!centered)
        {
$       RECT r = {0}; GetWindowRect (_txConsole_Wnd, &r) TX_NEEDED;
$       center.x = (r.right + r.left) / 2;
$       center.y = (r.bottom + r.top) / 2;
        }

$   _txCanvas_Wnd = CreateWindowEx (0, className, title, WS_POPUP | WS_BORDER | WS_CAPTION | WS_SYSMENU,
                                    center.x - size.cx/2, center.y - size.cy/2, size.cx, size.cy,
                                    NULL, NULL, NULL, NULL);
$   _txCanvas_Wnd || TX_THROW ("Cannot create canvas: CreateWindowEx (\"%s\") failed"_ className);

$   ShowWindow          (_txCanvas_Wnd, SW_SHOW);
$   SetForegroundWindow (_txCanvas_Wnd) TX_NEEDED;
$   UpdateWindow        (_txCanvas_Wnd) TX_NEEDED;

$   if (_txConsole_Wnd)
        {
$       int hide = 0;

        #ifndef _TX_NO_HIDE_CONSOLE
$       hide = SWP_HIDEWINDOW;
        #endif

$       SetWindowPos (_txConsole_Wnd, HWND_NOTOPMOST, center.x - size.cx*2/5, center.y - size.cy*2/5, 0, 0,
                      SWP_NOSIZE | SWP_NOACTIVATE | hide) TX_NEEDED;

$       HMENU menu = GetSystemMenu (_txCanvas_Wnd, false); menu TX_NEEDED;
$       AppendMenu (menu, MF_SEPARATOR, 0, NULL) TX_NEEDED;
$       AppendMenu (menu, MF_STRING | MF_UNCHECKED, _TX_IDM_CONSOLE, "Show Console")     TX_NEEDED;
$       AppendMenu (menu, MF_STRING | MF_UNCHECKED, _TX_IDM_ABOUT,   "About Library...") TX_NEEDED;
$       CheckMenuItem (menu,  _TX_IDM_CONSOLE, (IsWindowVisible (_txConsole_Wnd))? MF_CHECKED : MF_UNCHECKED);
        }

$   return _txCanvas_Wnd;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OK()
    {
$   return _txCanvas_Thread     &&
           _txCanvas_Wnd        &&
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

int _txCanvas_SetRefreshLock (int count)
    {
$   int oldCount = _txCanvas_RefreshLock;

$   _txCanvas_RefreshLock = count;

$   if (!_txCanvas_RefreshLock || !oldCount)
        if (_txCanvas_Wnd)
            {
$           InvalidateRect (_txCanvas_Wnd, NULL, false);
$           UpdateWindow   (_txCanvas_Wnd);
            }

$   return oldCount;
    }

//=============================================================================
//
//! @name    ������� ��������� ���� (_txCanvas_On...)
//
//=============================================================================

bool _txCanvas_OnCreate (HWND wnd)
    {
$   _txRunning = true;

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); _txCanvas_BackBuf[0] TX_NEEDED;
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); _txCanvas_BackBuf[1] TX_NEEDED;

$   SetTimer (wnd, _txCanvas_RefreshTimer, _TX_WINDOW_UPDATE_INTERVAL, NULL)   TX_NEEDED;

$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCanvas_OnDestroy (HWND wnd)
    {
$   if (_txCanvas_RefreshTimer) KillTimer (wnd, _txCanvas_RefreshTimer) TX_NEEDED;

$   if (_txCanvas_BackBuf[0]) _txBuffer_Delete (_txCanvas_BackBuf[0]); _txCanvas_BackBuf[0] = NULL;
$   if (_txCanvas_BackBuf[1]) _txBuffer_Delete (_txCanvas_BackBuf[1]); _txCanvas_BackBuf[1] = NULL;

$   PostQuitMessage (0);

//  Should terminate user process (main() etc.) even if they are not finished.
//  So, use exit(). Assume pressing [X] to be normal exit, so exit (0).

$   CloseHandle (_txMainThread) TX_NEEDED;

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
        MessageBox (txWindow(), "������� main() �� ���������. "
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

$   if (!txLock (false))
      {
$     EndPaint (wnd, &ps) TX_NEEDED;
$     return false;
      }

$   RECT r = {0};
$   GetClientRect (wnd, &r) TX_NEEDED;
$   POINT size = { r.right - r.left, r.bottom - r.top };

$   if (!_txCanvas_RefreshLock)
      {
$     Win32::BitBlt (_txCanvas_BackBuf[1], 0, 0, size.x, size.y, txDC(), 0, 0, SRCCOPY);

$     if (_txConsole_OK())
          {
$         _txConsole_Draw (_txCanvas_BackBuf[1]);
          }
      }

$   Win32::BitBlt (dc, 0, 0, size.x, size.y, _txCanvas_BackBuf[1], 0, 0, SRCCOPY);

$   txUnlock();

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

$   _txMousePos.x   = LOWORD (coords);
$   _txMousePos.y   = HIWORD (coords);
$   _txMouseButtons = (int) buttons;

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

#if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__PROGRAMMER)

    #ifndef __MODULE
    #define __MODULE       "TXLib"              " \t"   "#define __MODULE to set the name."
    #endif

    #ifndef __VERSION
    #define __VERSION      "0.(0)0."            " \t\t" "#define __VERSION to set the value."
    #endif

    #ifndef __DESCRIPTION
    #define __DESCRIPTION  "Some useless code." " \t\t" "#define __DESCRIPTION to override this meaning."
    #endif

    #ifndef __PROGRAMMER
    #define __PROGRAMMER   "Unknown lamer."     " \t"   "#define __PROGRAMMER to override this name."
    #endif

#endif

//-----------------------------------------------------------------------------

bool _txCanvas_OnCmdAbout (HWND, WPARAM)
    {
$   char name[1024] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1) TX_NEEDED;

$   char text[1024] = "";

$   _snprintf_s (text, sizeof (text) - 1,
                 #ifdef  _TX_USE_SECURE_CRT
                 _TRUNCATE,
                 #endif

                 #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__PROGRAMMER)
                 "\n" "Application:\n\n"
                      __MODULE " version " __VERSION "    \n"
                      __DESCRIPTION                  "    \n"
                      "Copyright (c) " __PROGRAMMER  "    \n"
                 "\n" "Developed with:\n"
                 #endif

                 "\n" "The Dumb Artist Library (TX Library, TXLib) " _TX_VERSION "    \n\n"
                 "Copyright (c) Ded, 2005-10 (Ilya Dedinsky <ded@concord.ru>, http://ded32.net.ru)" "    \n"
                 "Compiled with: " __FILE__ "    \n\n"

                 "Executable file: " "%s" "    \n"
                 "Compiled: " __DATE__ ", " __TIME__ "    \n",
                 name);

$   MessageBox (txWindow(), text, "About "
                                           #ifdef __MODULE
                                           __MODULE
                                           #else
                                           "TXLib"
                                           #endif
                                                   , MB_ICONINFORMATION);

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
        case _TX_IDM_ABOUT:   $ _txCanvas_OnCmdAbout   (wnd, wpar);   break;
        case _TX_IDM_CONSOLE: $ _txCanvas_OnCmdConsole (wnd, wpar);   break;
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
//
//! @name    ������� ����������� ���� (_txConsole...)
//
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

$   if (!txLock (false)) return false;

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
        Win32::TextOut (dc, 0, y*fontSz.cy, buf + y*con.dwSize.X + con.srWindow.Left, sizeX) TX_NEEDED;

$   delete[] buf;

$   if (_txConsole_CursorMode &&
      GetTickCount() % _TX_CURSOR_BLINK_INTERVAL*2 > _TX_CURSOR_BLINK_INTERVAL &&
      In (con.dwCursorPosition, con.srWindow))
      {
$     Win32::TextOut (dc,
                     (con.dwCursorPosition.X - con.srWindow.Left)*fontSz.cx,
                     (con.dwCursorPosition.Y - con.srWindow.Top) *fontSz.cy + 1,
                      "_", 1);
      }

$   txUnlock();

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

$   SetLastError (0);
$   return con;
    }

//=============================================================================
//
//! @name    ������� "������������ ������" (������������ ������, _txBuffer...)
//
//=============================================================================

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bitmap)
    {
$   assert (wnd);

$   txLock();

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

$   txUnlock();
$   return dc;
    }

//-----------------------------------------------------------------------------

bool _txBuffer_Delete (HDC dc)
    {
$   if (!dc) return false;

$   txLock ();

$   _txSelect (Win32::GetStockObject (NULL_PEN),    dc) TX_NEEDED;
$   _txSelect (Win32::GetStockObject (NULL_BRUSH),  dc) TX_NEEDED;
$   _txSelect (Win32::GetStockObject (SYSTEM_FONT), dc) TX_NEEDED;

$   Win32::DeleteObject (Win32::GetCurrentObject (dc, OBJ_BITMAP));
$   Win32::DeleteObject (Win32::GetCurrentObject (dc, OBJ_REGION));

$   Win32::DeleteDC (dc) TX_NEEDED;

$   txUnlock();
$   return true;
    }

//=============================================================================
//
//! @name    ������
//
//=============================================================================

bool _txSelect (HGDIOBJ obj, HDC dc)
    {
$   txLock ();

$   obj = Win32::SelectObject (dc, obj); obj TX_NEEDED;
$   if (obj) Win32::DeleteObject (obj);

$   txUnlock();

$   return obj != NULL;
    }

//=============================================================================
//
//! @name    ������� �������������� ������ � ����������� ������
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   �������� ������� ������� DLGTEMPLATE ��� �������
//!          DialogBoxIndirect() � DialogBoxIndirectParam().
//!
//!          �������������� ������ � ����������� ������. ��� ��������� �����.
//!
//! @return  ��������� �� ����� ����������� �������� ����� ������.
//! @see     _tx_DLGTEMPLATE_Add(), txDialog::run(), CreateWindowEx()
//! @usage
//! @code
//!          [example]
//! @endcode
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
                              HANDLE menu          //!< ���� ����������� ����, ���� ����
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
//! @ingroup Service
//! @brief   ���������� �������� ���� (��������) � ������ ������� ��� �������
//!          DialogBoxIndirect() � DialogBoxIndirectParam().
//!
//!          �������������� ������ � ����������� ������. ��� ��������� �����.
//!
//! @return  ��������� �� ����� ����������� �������� ����� ������.
//! @see     _tx_DLGTEMPLATE_Create(), txDialog::run()
//! @usage
//! @code
//!          [example]
//! @endcode
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
                           )
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
//! @name    �����������
//
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
        s += _snprintf_s (s, sizeof (str) - 1 - (s-str) TR_, " %s",   func);

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

    printf (str);

    OutputDebugString (str);
    MessageBox (NULL, str, fatal? "��������� ������" : "������ � ���������",
                MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

    if (fatal) abort();

    va_end (arg);
    return false;
    }

//=============================================================================
//! @cond NOT_FOR_DOXYGEN

} // namespace TX
} // anonymous namespace

using namespace TX;
using namespace TX::Win32;

//! @endcond
//=============================================================================

//------------------------------------------------------------------------
//
//! @name    ��������� � ������������
//
//------------------------------------------------------------------------

#if defined (__GNUC__)

    #if (__GNUC__ >= 4)
        #pragma GCC diagnostic warning "-Wmissing-field-initializers"
    #endif

#endif

#if defined (_MSC_VER)

    #pragma warning (default: 4127)          // conditional expression is constant
    #pragma warning (default: 4245)          // 'argument': conversion from A to B, signed/unsigned mismatch

    #pragma warning (default: 4100)          // 'parameter': unreferenced formal parameter
    #pragma warning (default: 4511)          // 'class': copy constructor could not be generated
    #pragma warning (default: 4512)          // 'class': assignment operator could not be generated

#endif

#undef $

//=============================================================================

#endif // __TXLIB_H

//=============================================================================
//
//! @name    ������������ �� ��������
//
//=============================================================================

//! @include "Examples/Examples.dox"

//=============================================================================
//
// EOF
//
//=============================================================================
