//============================================================================================
//           [These sections are for folding control  in Code::Blocks]
//{          [Best viewed with "Fold all on file open" option enabled]
//============================================================================================
//!
//! @file    TXLib.h
//! @brief   ���������� ������ ��������� (The Dumb Artist Library, TX Library, TXLib).
//!
//!          $Version$
//!          $Copyright$
//!          $Date$
//!
//! 	     TX Library - ���������� ���������� ��������� ������� ��� Win32 �� �++.
//!          ��� ��������� "���������" ��� ���������� ����������� � ����� ������ �� � ��������
//!          ���������� ��������� ����������������. ������������ �� ������� �����.
//!
//! 	     ��������� TX Library - ��������� ������ ���� � ����������������
//! 	     � ����������� � ���������� � �����������������.
//!
//!          TX Library is a tiny 2D graphics library for Win32 written in C++. This is a small
//!          sandbox for the very beginners to help them to learn basic programming principles.
//!          The documentation is currently in Russian.
//!
//!          ����������� ���� ����������: <a href=http://ded32.net.ru>ded32.net.ru.</a>
//!
//!          ��. ����� <a href=http://txlib.sourceforge.net>�������� ������� �� SourceForge.</a>
//!
//! @warning <b>��� �����-������.
//!          ��� ������������� ��������� ������������ � ������� ����������.</b> \n\n
//!          ������� ������������� ���������� ���������� � ����� ��. ��
//!          <a href=http://ded32.net.ru/index/0-6> ����������� �����.</a>
//!
//           $Author$
//--------------------------------------------------------------------------------------------
//!
//! @defgroup Drawing   ���������
//! @defgroup Mouse     ��������� ����
//! @defgroup Dialogs   ���������� ����
//! @defgroup Misc      ������
//! @defgroup Service   ���������
//! @defgroup Technical ����������� ������
//}
//============================================================================================

#if !defined (__TXLIB_H) || defined (_TX)
#define       __TXLIB_H

//--------------------------------------------------------------------------------------------
//{          Version information
//--------------------------------------------------------------------------------------------

//! @cond INTERNAL
#define _TX_VERSION_(_1,file,ver,rev,date,auth,_2)  "TXLib [Version " #ver ", Revision " #rev "]"
#define _TX_AUTHOR__(_1,file,ver,rev,date,auth,_2)  "Copyright (C) " auth
#define _TX_VER_____(_1,file,ver,rev,date,auth,_2)  ((0x##ver << 16) | 0x##rev)
//! @endcond

//{-------------------------------------------------------------------------------------------
//! @ingroup   Technical
//! @brief     ������� ������ ����������.
//!
//! @code
//!            #define _TX_VERSION "TXLib [Version: 1.72a, Revision 50]" (������)
//!            #define _TX_AUTHOR  "Copyright (C) Ded (Ilya Dedinsky, http://ded32.net.ru)"
//! @endcode
//!            ��� ��������� ������������� ����������� ��� ���������� ������.
//!
//! @see       txVersion()
//! @hideinitializer
//}-------------------------------------------------------------------------------------------
//! @{

#define _TX_VERSION           _TX_VERSION_ ($versioninfo$)
#define _TX_AUTHOR            _TX_AUTHOR__ ($versioninfo$)

//! @}
//{----------------------------------------------------------------------------
//! @ingroup   Technical
//! @brief     ������ ���������� � ������������� �������.
//!
//!            ������: ������� ����� - ����� ������, ������� - ����� �������,
//!            � �������-���������� �������.
//!            ��������, @c 0x172a0050 - ������ @c 0.172a, ������� @c 50.
//!
//!            ��� ��������� ������������� ����������� ��� ���������� ������.
//!
//! @see       txVersion()
//! @hideinitializer
//}----------------------------------------------------------------------------

#define _TX_VER               _TX_VER_____ ($versioninfo$)

//}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    ��������� � ������������ � ����������
//--------------------------------------------------------------------------------------------
//! @{ @cond INTERNAL

#if !defined (__cplusplus)

    #error TXLib.h: Must use C++ to compile TXLib.h

#endif

#if !defined (WIN32) && !defined (__WIN32__) && !defined(_WIN32) && !defined(_WIN32_WINNT)

    #error TXLib.h: Windows (MSVC/Win32 or GCC/MinGW) is the only supported system, sorry.

#endif

#if defined (__STRICT_ANSI__)     // Try to extend strict ANSI C

    #warning TXLib.h: Trying to extend strict ANSI compatibility
    #undef __STRICT_ANSI__

#endif

//--------------------------------------------------------------------------------------------

#if defined (__GNUC__)

    #if (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 3)

        #pragma GCC optimize         ("no-strict-aliasing")
        #pragma GCC diagnostic ignored "-Wstrict-aliasing"

        #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
        #pragma GCC diagnostic ignored "-Wunreachable-code"
        #pragma GCC diagnostic ignored "-Wunused-label"  // Just for fun in _txCanvas_OnCmdAbout()

    #endif

    #define _TX_CHECK_FORMAT( fmtIdx )  __attribute__ (( format (printf, (fmtIdx), (fmtIdx)+1) ))
    #define _TX_CHECK_RESULT            __attribute__ (( warn_unused_result ))

#else

    #define _TX_CHECK_FORMAT( fmtIdx )
    #define _TX_CHECK_RESULT

#endif

//--------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

    #pragma warning (push, 4)                   // Set maximum warning level

    #pragma warning (disable: 4127)             // conditional expression is constant
    #pragma warning (disable: 4351)             // new behavior: elements of array ... will be default initialized

    #define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200)    // MSVC 6 (1998)

    #define _MSC_VER_6                          // Flag the bad compiler

    #pragma warning (disable: 4511)             // copy constructor could not be generated
    #pragma warning (disable: 4512)             // assignment operator could not be generated
    #pragma warning (disable: 4514)             // unreferenced inline function has been removed
    #pragma warning (disable: 4663)             // C++ language change: to explicitly specialize class template '...'
    #pragma warning (disable: 4710)             // function '...' not inlined

    #if !defined (WINVER)
        #define WINVER   0x0400                 // MSVC 6: Defaults to Windows 95
    #endif

#endif

#if defined (_MSC_VER) && (_MSC_VER <  1400)    // MSVC Pre-8 (Pre-2005)

    #if !defined (_MT)
        #error Must use multithreaded run-time library to use TXLib. Set Project/Settings/C++/Code Generation/Run-time library == Multi-threaded
    #endif

#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1400)    // MSVC 8 (2005) or greater

    #define _TX_USE_SECURE_CRT

#else

    #define _snprintf_s            _snprintf    // MSVC prior to 8 (2005) versions and GCC
    #define _vsnprintf_s           _vsnprintf   //   do NOT have secure variants of these
    #define  ctime_s                ctime       //   functions, so use insecure ones.
    #define  strncpy_s              strncpy     //
    #define  strncat_s              strncat     //   ...
    #define  wcsncpy_s              wcsncpy
    #define  strerror_s(buf,code)               ( (void)(buf), strerror (code) )
    #define  getenv_s(sz,buf,sizeof_buf,name)   ( (void)(sz),  strncpy ((buf), getenv (name), (sizeof_buf)) )
    #define  strtok_s(str,delim,ctx)            ( (void)(ctx), strtok ((str), (delim)) )

#endif

//--------------------------------------------------------------------------------------------

#if defined (__INTEL_COMPILER)

    #pragma warning (disable:  174)             // remark: expression has no effect
    #pragma warning (disable:  304)             // remark: access control not specified ("public" by default)
    #pragma warning (disable:  522)             // remark: function "..." redeclared "inline" after being called
    #pragma warning (disable:  981)             // remark: operands are evaluated in unspecified order
    #pragma warning (disable: 1684)             // conversion from pointer to same-sized integral type (potential portability problem)

#endif

//--------------------------------------------------------------------------------------------

#if !defined (WINVER)
    #define   WINVER         0x0500             // Defaults to Windows 2000
    #define   WINDOWS_ENABLE_CPLUSPLUS          // Allow use of type-limit macros in <basetsd.h>,
#endif                                          //   they allowed by default if WINVER >= 0x0600.

#if !defined (_WIN32_WINNT)
    #define   _WIN32_WINNT   WINVER             // Defaults to the same as WINVER
#endif

#undef   UNICODE                                // Burn Unicode, burn
#undef  _UNICODE

//--------------------------------------------------------------------------------------------

#undef         _TX_NAME
#undef         _TX_NAMED

#if defined   (_TX)
    #define    _TX_NAME      " " TX_QUOTE (_TX) "::TX "
    #define    _TX_NAMED

#else
    #define    _TX_NAME      " "
    #define    _TX

#endif

//--------------------------------------------------------------------------------------------

//! @} @endcond
//}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//{          Includes
//--------------------------------------------------------------------------------------------

#ifdef _MSC_VER_6
    #pragma warning (push, 3)                   // MSVC 6: At level 4, std headers emit warnings
#endif

//--------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <direct.h>
#include <process.h>
#include <signal.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <float.h>
#include <math.h>

#include <assert.h>

#include <iostream>
#include <algorithm>
#include <exception>

#include <conio.h>

#include <windows.h>
#include <tlhelp32.h>
#include <shlobj.h>
#include <shellapi.h>

//--------------------------------------------------------------------------------------------

#ifdef _MSC_VER_6
    #pragma warning (pop)                       // MSVC 6: Restore maximum level
#endif

//}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//{          The namespaces
//--------------------------------------------------------------------------------------------

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������� ������������ ���� ��� ������ �� ���������� ����
//!          ��� ������ �������������� �������.
//!
//!          ���� ��� _TX ���������� � ������� @c #define �� ���������
//!          ����� @c TXLib.h, �� ������������ ���� ��������� ���� ���������
//!          � ����� ��������������� �������� ����������� _TX.
//}-------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
namespace _TX { namespace TX { }}
#endif

//}
//--------------------------------------------------------------------------------------------

/*! @cond INTERNAL */

namespace _TX { namespace TX {    // <<<<<<<<< The main code goes below, unfold the namespaces

/*! @endcond */

//============================================================================================
//{          TXLIB INTERFACE
//           ��������� ����������
//============================================================================================

//============================================================================================
//{          Initialization
//! @name    ������������� ����������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���� ���������
//!
//! @param   sizeX     ������ ���� �� ����������� (� ��������)
//! @param   sizeY     ������ ���� �� ���������   (� ��������)
//! @param   style     ���� 1 (�� ���������), ���� ������������ �� ������.
//!
//! @return  ���������� (��������� �����) ���� TXLib. ���� ���� �� �������, ������������ NULL.
//!
//! @note
//!        - �� ����� ���� �������� @c style ������ ����� ����. ���� ����� ���� �������� WS_SYSMENU
//!	     (�������� �� ���������), ���� ��������� �������.
//!        - ���� <i>������� ��� �����</i> ��������� � 1 (�� ���������), ���� ������������ �� ������.
//!        - ������� ���� ������ ���� ������ ���� � ����������� ������. ��� �������� ��������
//!          ���� ��������� �����������.\n
//!          ��������������� ���� ����� ����������� �� ������ �� ������ ���� ��������������
//!          �������. ��� �� �������� @a �� ���� ��������� WS_SYSMENU. ��� �������� ���������������
//!          ���� ������������ txDestroyWindow().
//!        - ��� �������� ���� � ����� ������������� ����������� ����� WS_POPUP, WS_BORDER � WS_CAPTION.
//!        - ��������������� ��������� ��������� �� ���������, ��. ������� txSetDefaults().
//!
//! @see     txOK()
//! @usage
//! @code
//!          txCreateWindow ( 800,  600);                 // ���� 800�600, �������, ������������
//!          txCreateWindow (1024,  768, WS_SYSMENU | 1); // ���� 800�600, �������, ������������
//!          txCreateWindow (1024,  768, 1);              // ���� 800�600, ���������������, ������������
//!          txCreateWindow (1024,  768, WS_SYSMENU);     // ���� 800�600, �������, �� ������������
//! @endcode
//}-------------------------------------------------------------------------------------------

#ifdef _TX_NAMED

HWND txCreateWindow (int sizeX = 800, int sizeY = 600, unsigned style =              1);

#else

HWND txCreateWindow (int sizeX = 800, int sizeY = 600, unsigned style = WS_SYSMENU | 1);

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ���������� ��������� �� ���������.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ��������� �� ���������:\n
//!          - ����� - ���� ����� (TX_WHITE), ������� 1
//!          - ������� - ���� ����� (TX_WHITE)
//!          - ����� - ��������� �����, ���� ����� (TX_WHITE)
//!          - ���������� ��������� �������� - ����������� ����� (R2_COPYPEN)
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//! @see     txSelectFont(), txSetROP2()
//! @usage
//! @code
//!          txSetDefaults();
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSetDefaults();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������������ ������ ����������
//!
//! @return  ��������� ����������: true - ���������� � �������, false - �� � �������.
//!
//!          "���������� �� � �������" ��������, ��� �� ���������� ������ �������.
//!          ����� ������� ������� - ���������� �� ���������������� (�� ������� ����),
//!          ������ ����� ���� � ������.
//!
//! @see     txCreateWindow()
//! @usage
//! @code
//!          txCreateWindow (800, 600);
//!          if (!txOK())
//!              {
//!              MessageBox (txWindow(), "�� ������ ������� ����", "��������", MB_ICONSTOP);
//!              return;
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
bool txOK();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ��������� � ���� ��������� POINT.
//!
//! @return  ������ ���� ��������� � ���� ��������� POINT.
//!
//! @see     txGetExtentX(), txGetExtentY()
//! @usage
//! @code
//!          POINT size = txGetExtent();
//!          txLine (0, 0,      size.x, size.y);
//!          txLine (0, size.y, size.x, 0);
//! @endcode
//}-------------------------------------------------------------------------------------------

POINT txGetExtent();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ���������.
//!
//! @return  ������ ���� ���������.
//!
//! @see     txGetExtent(), txGetExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_CENTER);
//!          txTextOut (txGetExtentX() / 2, 100, "Oh, oh, you're in the [army]middle now");
//! @endcode
//}-------------------------------------------------------------------------------------------

int txGetExtentX() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ���������.
//!
//! @return  ������ ���� ���������.
//!
//! @see     txGetExtent(), txGetExtentX()
//! @usage
//! @code
//!          void DrawHouse (int height);
//!          ...
//!          DrawHouse (txGetExtentY() / 2);
//! @endcode
//}-------------------------------------------------------------------------------------------

int txGetExtentY() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ���������� ��������� ��������� ������
//!
//! @return  ���������� (��������� �����, handler) ��������� ��������� (device context, DC)
//!          ������ (HDC).
//!
//! @note    HDC ������������ � ���� ������, ��� ��������� ��������� ���. ����� ��������
//!          ���� ��������� ������ ���������� ��� ���������� ��� � ������� txDeleteDC().
//!          �� ������� ��������� ������ ���� ������������� � ������� txLock() �
//!          ����� ������� �������������� txUnlock().
//!
//! @see     txWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txBitBlt (txDC(),   0,   0, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 100,   0, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 0,   100, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 100, 100, 100, 100, txDC(), 0, 0);
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
HDC& txDC() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ���������� ���� ������
//!
//! @return  ���������� (��������� �����, handler) ���� ������
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          SetWindowText (txWindow(), "����� ��������� - ������ � � ����� �����!");
//!          MessageBox (txWindow(), "�����������", "��������", MB_ICONINFORMATION);
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
HWND txWindow() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ������ � ����������� � ������� ������ ����������.
//!
//! @return  ������ � ����������� � ������� ������ ����������.
//!
//! @usage
//! @code
//!          printf ("I personally love %s\n", txVersion());
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
const char* txVersion() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ����� ������ ����������.
//!
//! @return  ����� ������ ����������.
//!
//! @usage
//! @code
//!          printf ("My magic number %x\n", txVersionNumber());
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
unsigned txVersionNumber() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ��� ������������ ����� ��� ����������� ��������� ���� TXLib.
//!
//! @param   fileNameOnly  ���������� ������ ������ ��� ������������ �����, ����������� �����
//!                        Win32 ������� GetFileModuleName (NULL, ...).
//!
//! @return  fileNameOnly = true:  ��� ������������ ����� \n
//!          fileNameOnly = false: ����������� ��������� ���� TXLib
//!
//! @note    ������������ @b ����������� ������.
//!
//! @see     txWindow(), txVersion(), txVersionNumber()
//! @usage
//! @code
//!          for (int percentDone = 0; percentDone <= 100; percentDone++)
//!              {
//!              char title [1024] = "";
//!              sprintf (title, "%s - [%-10.*s] %d%%", txGetModuleFileName (false),
//!                       percentDone/10, "||||||||||", percentDone);
//!
//!              SetWindowText (txWindow(), title);  // ��� ����� ��� progress bar
//!              txSleep (50);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

const char* txGetModuleFileName (bool fileNameOnly = true) _TX_CHECK_RESULT;

//! @}
//}
//============================================================================================

//============================================================================================
//{          Setting the parameters
//! @name    ��������� ������ � ������� ���������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���������������� ������.
//!
//!          ��. TX_BLACK, TX_BLUE � ������ ����� � ������ ����.
//!
//! @see     txSetColor(), txSetFillColor(), txGetColor(), txGetFillColor(), txGetPixel()
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (TX_NULL);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

const COLORREF
#ifdef FOR_DOXYGEN_ONLY
    enum txColors {
#endif

    TX_BLACK         = RGB (  0,   0,   0),   //!< ������ ����.
    TX_BLUE          = RGB (  0,   0, 128),   //!< �����-����� ����.
    TX_GREEN         = RGB (  0, 128,   0),   //!< ������� ����.
    TX_CYAN          = RGB (  0, 128, 128),   //!< ��������� ����.
    TX_RED           = RGB (128,   0,   0),   //!< �����-������� ����.
    TX_MAGENTA       = RGB (128,   0, 128),   //!< �����-��������� ����.
    TX_BROWN         = RGB (128, 128,   0),   //!< ���������� ����. ����������. Do it yourself using RGB().
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
    TX_TRANSPARENT   = 0xFFFFFFFF,            //!< ���������� ����. <i>��������� ���������.</i>
    TX_NULL          = TX_TRANSPARENT,        //!< ���������� ����. <i>��������� ���������.</i>

//  �������� ������ (����������) - ��. txExtractColor(), txRGB2HSL(), txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< �������� ��� ����� � ������ HSL
    TX_SATURATION   = 0x05000000,             //!< ������������ ����� � ������ HSL
    TX_LIGHTNESS    = 0x06000000;             //!< �������� ����� � ������ HSL

#ifdef FOR_DOXYGEN_ONLY
    };
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� (���������) ���� �� ���� ������� ������ (���������).
//!
//! @param   red    ���������� �������� ����� � ��������� [0; 255]
//! @param   green  ���������� �������� ����� � ��������� [0; 255]
//! @param   blue   ���������� ������   ����� � ��������� [0; 255]
//!
//! @return  ��������� ���� � ������� COLORREF.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB()
//! @usage
//! @code
//!          txSetColor (RGB (255, 128, 0));
//!
//!          int red = 20, green = 200, blue = 20;
//!          COLORREF color = RGB (red, green, blue);
//!          txSetFillColor (color);
//! @endcode
//}-------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
COLORREF RGB (int red, int green, int blue);
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� � ������� �����, ���� ������.
//!
//! @param   color      ���� ����� � ������, ��. txColors, RGB()
//! @param   thickness  ������� �����
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), txColors, RGB()
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSetColor (COLORREF color, int thickness = 1);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ����� � ������.
//!
//! @param   red    ���������� �������� ����� � ��������� [0; 1]
//! @param   green  ���������� �������� ����� � ��������� [0; 1]
//! @param   blue   ���������� ������   ����� � ��������� [0; 1]
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()
//! @usage
//! @code
//!          txColor (1.0, 1.0, 0.0);   // ������� + ������� = ������
//!          txColor (1.0, 0.5, 0.25);  // ����� ���������
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txColor (double red, double green, double blue);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� � ������.
//!
//! @return  ������� ���� ����� � ������, ��. txColors, RGB()
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetColor();
//! @endcode
//}-------------------------------------------------------------------------------------------

COLORREF txGetColor() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ���������� �����.
//!
//! @param   color  ���� ����������, ��. txColors, RGB()
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), txColors, RGB()
//! @usage
//! @code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSetFillColor (COLORREF color);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ���������� �����.
//!
//! @param   red    ���������� �������� ����� � ��������� [0; 1]
//! @param   green  ���������� �������� ����� � ��������� [0; 1]
//! @param   blue   ���������� ������   ����� � ��������� [0; 1]
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor()
//! @usage
//! @code
//!          txFillColor (1.0, 0.5, 0.25);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txFillColor (double red, double green, double blue);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ���������� �����.
//!
//! @return  ������� ���� ���������� �����, ��. txColors, RGB()
//!
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), txColors, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetFillColor();
//! @endcode
//}-------------------------------------------------------------------------------------------

COLORREF txGetFillColor() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ����� �������������� ������ ��� ���������.
//!
//!          ��� ��������� ����������� ���������� ����� �� ������ ������� �������
//!          �� ������, � ��������� ����� ������ � ������� ����� ����� � ����������.
//!
//! @param   mode  ����� ���������� ������
//!
//! @return  ���������� ����� �������������� ������, ��. txColors, RGB()
//!
//! @title   ������ �������������� ������:
//! @table   @tr R2_COPYPEN     @td ������� = ����� ����� (����� ���������� ����� :)
//!          @tr R2_NOTCOPYPEN  @td ������� = ~�����
//!          @tbr
//!          @tr R2_BLACK       @td ������� = ������ ���� (���� ����� ������������)
//!          @tr R2_WHITE       @td ������� = �����  ���� (���� ����� ������������)
//!          @tr R2_NOT         @td ������� = ~�������    (���� ����� ������������)
//!          @tbr
//!          @tr R2_XORPEN      @td ������� =    ������� ^  �����
//!          @tr R2_NOTXORPEN   @td ������� = ~ (������� ^  �����)
//!          @tbr
//!          @tr R2_MASKPEN     @td ������� =    ������� &  �����
//!          @tr R2_NOTMASKPEN  @td ������� = ~ (������� &  �����)
//!          @tr R2_MASKNOTPEN  @td ������� =    ������� & ~�����
//!          @tr R2_MASKPENNOT  @td ������� =   ~������� &  �����
//!          @tbr
//!          @tr R2_MERGEPEN    @td ������� =    ������� |  �����
//!          @tr R2_NOTMERGEPEN @td ������� = ~ (������� |  �����)
//!          @tr R2_MERGENOTPEN @td ������� =    ������� | ~�����
//!          @tr R2_MERGEPENNOT @td ������� =   ~������� |  �����
//!          @tbr
//!          @tr R2_NOP         @td ������� ������ �� ����������.
//! @endtable
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txSetColor (TX_WHITE, 5);       // ��� ��������� ����� ������ � ������
//!          txSetROP2 (R2_XORPEN);          //   R2_XORPEN ����� �� ������ �������������
//!
//!          txLine (100, 100, 200, 200);    // ������ ������ ��� - ����� ����������
//!          txSleep (1000);
//!          txLine (100, 100, 200, 200);    // ������ ������ ��� - ����� ��������
//!
//!          txSetROP2 (R2_COPYPEN);         // ��������������� ���������� �����
//!          txLine (100, 100, 200, 200);    // ������ ������ ��� - ����� ����������
//!
//!          txLine (100, 100, 200, 200);    // ������ ������ ��� - ����� ��������
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSetROP2 (int mode = R2_COPYPEN);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �������� ���������� (�������� �����) �� ���������� �����.
//!
//! @param   color      ��������� ����
//! @param   component  ����������� ����������, ��. txColors
//!
//! @return  �������� ����������, ��. txColors
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), txColors
//! @usage
//! @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          ������ ������� ��. � �������� AppearText(), AppearEarth() ������� 5 ("�����").
//! @endcode
//}-------------------------------------------------------------------------------------------

int txExtractColor (COLORREF color, COLORREF component) _TX_CHECK_RESULT;

//{---------------------------------------
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� RGB � ������ HSL.
//!
//! @param   rgbColor  ������������� ���� � ������� @strike ��� @endstrike RGB
//!
//! @return  ��������� ���� � ���� COLORREF.
//!
//!          ������ @b RGB ������������ ���
//!
//!          - ������� ���������� ����� (Red),   �� 0 �� 255.
//!          - ������� ���������� ����� (Green), �� 0 �� 255.
//!          - �����   ���������� ����� (Blue),  �� 0 �� 255.
//!
//!          ������ @b HSL ������������ ���
//!
//!          - �������� ��� (Hue),        �� 0 �� 360.
//!          - ������������ (Saturation), �� 0 �� 255.
//!          - ��������     (Lightness),  �� 0 �� 255.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), txColors
//! @usage
//! @code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! @endcode
//}-------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� HSL � ������ RGB.
//!
//! @param   hslColor  ������������� ���� � ������� HSL
//!
//! @return  ��������� ���� � ���� COLORREF.
//!
//!          ������ @b RGB ������������ ���
//!
//!          - ������� ���������� ����� (Red),   �� 0 �� 255.
//!          - ������� ���������� ����� (Green), �� 0 �� 255.
//!          - �����   ���������� ����� (Blue),  �� 0 �� 255.
//!
//!          ������ @b HSL ������������ ���
//!
//!          - �������� ��� (Hue),        �� 0 �� 360.
//!          - ������������ (Saturation), �� 0 �� 255.
//!          - ��������     (Lightness),  �� 0 �� 255.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), txColors
//! @usage
//! @code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! @endcode
//}-------------------------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor) _TX_CHECK_RESULT;

//! @}
//}
//============================================================================================

//============================================================================================
//{          Drawing
//! @name    ��������� �����
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� ����� ������� ������ ����������.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetFillColor(), txFillColor(), txGetFillColor(), txColors, RGB()
//! @usage
//! @code
//!          txClear();
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txClear();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� (����� �� ������).
//!
//! @param   x      �-���������� �����
//! @param   y      Y-���������� �����
//! @param   color  ���� �����, ��. txColors, RGB()
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txPixel(), txGetPixel(), txColors, RGB()
//! @usage
//! @code
//!          txSetPixel (100, 100, TX_RED);
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
bool txSetPixel (int x, int y, COLORREF color);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� (����� �� ������).
//!
//! @param   x      �-���������� �����
//! @param   y      Y-���������� �����
//! @param   red    ���������� �������� ����� � ��������� [0; 1]
//! @param   green  ���������� �������� ����� � ��������� [0; 1]
//! @param   blue   ���������� ������   ����� � ��������� [0; 1]
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetPixel(), txGetPixel()
//! @usage
//! @code
//!          txSetPixel (100, 100, 1.0, 0.5, 0.25);
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
bool txPixel (int x, int y, double red, double green, double blue);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� (�������) �� ������.
//!
//! @param   x  �-���������� �����
//! @param   y  Y-���������� �����
//!
//! @return  ������� ���� �������, ��. txColors, RGB()
//!
//! @see     txSetPixel(), txPixel(), txColors, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED)
//!              CarCrash (x, y);     // Mess with the red - die like the rest
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
COLORREF txGetPixel (int x, int y) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!
//! @param   x0  X-���������� ��������� �����
//! @param   y0  Y-���������� ��������� �����
//! @param   x1  X-���������� ��������  �����
//! @param   y1  Y-���������� ��������  �����
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txLine (100, 200, 400, 500);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txLine (int x0, int y0, int x1, int y1);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �������������.
//!
//! @param   x0  X-���������� �������� ������  ����
//! @param   y0  Y-���������� �������� ������  ����
//! @param   x1  X-���������� �������  ������� ����
//! @param   y1  Y-���������� �������  ������� ����
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txRectangle (100, 200, 400, 500);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txRectangle (int x0, int y0, int x1, int y1);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� ����� ��� �������������.
//!
//! @param   points     ������ �������� POINT � ������������ �����
//! @param   numPoints  ���������� ����� � �������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          POINT star[6] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}, {150, 300}};
//!          txPolygon (star, 6);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������.
//!
//! @param   x0  X-���������� �������� ������  ���� ���������� ��������������
//! @param   y0  Y-���������� �������� ������  ���� ���������� ��������������
//! @param   x1  X-���������� �������  ������� ���� ���������� ��������������
//! @param   y1  Y-���������� �������  ������� ���� ���������� ��������������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txEllipse (100, 100, 300, 200);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txEllipse (int x0, int y0, int x1, int y1);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���������� ��� ����.
//!
//! @param   x  �-���������� ������
//! @param   y  Y-���������� ������
//! @param   r  ������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txCircle (100, 100, 10);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txCircle (int x, int y, int r);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���� �������.
//!
//! @param   x0          X-���������� �������� ������  ���� ��������������,
//!                        ���������� ������ �������, ����������� ����
//! @param   y0          Y-���������� �������� ������  ���� ��������������
//! @param   x1          X-���������� �������  ������� ���� ��������������
//! @param   y1          Y-���������� �������  ������� ���� ��������������
//! @param   startAngle  ���� ����� ������������ ��� OX � ������� ���� (� ��������)
//! @param   totalAngle  �������� ���� (� ��������)
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txArc (100, 100, 300, 200, 0, 180);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txArc (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������ �������.
//!
//! @param   x0          X-���������� �������� ������  ���� ��������������,
//!                        ���������� ������ �������, ����������� ������
//! @param   y0          Y-���������� �������� ������  ���� ��������������
//! @param   x1          X-���������� �������  ������� ���� ��������������
//! @param   y1          Y-���������� �������  ������� ���� ��������������
//! @param   startAngle  ���� ����� ������������ ��� OX � ������� ������� (� ��������)
//! @param   totalAngle  �������� ������� (� ��������)
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txPie (100, 100, 300, 200, 0, 180);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txPie (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ����� �������.
//!
//! @param   x0          X-���������� �������� ������ ���� ��������������,
//!                        ���������� ������ �������, ����������� �����
//! @param   y0          Y-���������� �������� ������ ���� ��������������
//! @param   x1          X-���������� ������� ������� ���� ��������������
//! @param   y1          Y-���������� ������� ������� ���� ��������������
//! @param   startAngle  ���� ����� ������������ ��� OX � ������� ����� (� ��������)
//! @param   totalAngle  �������� ����� (� ��������)
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txChord (100, 100, 300, 200, 0, 180);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txChord (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������������ ������ ������� ������ ����������.
//!
//! @param   x      �-���������� ����� ������ �������
//! @param   y      Y-���������� ����� ������ �������
//! @param   color  ���� ���������� ������� (TX_TRANSPARENT - ���������������)
//! @param   mode   ����� ������� (FLOODFILLSURFACE - ������� ����������� ����)
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� ���������� �������� �������� txSetFillColor().
//!          �� ������������� ��� ���������� - �������� �������� ��������.
//!
//! @title   ������ �������: @table
//!          @tr FLOODFILLSURFACE @td - �������� �������,    ��������� ������ color.
//!          @tr FLOODFILLBORDER  @td - �������� �� �������, ��������� ������ color.
//!          @endtable
//!
//! @see     txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txFloodFill (100, 100);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txFloodFill (int x, int y, COLORREF color = TX_TRANSPARENT, DWORD mode = FLOODFILLSURFACE);

//! @}
//}
//============================================================================================

//============================================================================================
//{          Drawing text
//! @name    ������ � �������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!
//! @param   x     �-���������� ��������� ����� ������
//! @param   y     Y-���������� ��������� ����� ������
//! @param   text  ��������� ������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� ������ �������� �������� txSetColor(), ������������ - txSetTextAlign().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txSelectFont(), txSetTextAign(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txTextOut (int x, int y, const char text[]);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����, ����������� � ������������� �������.
//!
//! @param   x0     X-���������� �������� ������  ���� �������
//! @param   y0     Y-���������� �������� ������  ���� �������
//! @param   x1     X-���������� �������  ������� ���� �������
//! @param   y1     Y-���������� �������  ������� ���� �������
//! @param   text   ��������� ������
//! @param   format ����� �������������� ������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ���� ������ �������� �������� txSetColor(), ������������ - txSetTextAlign().
//!
//!          ����� �������������� ������ ��. � MSDN (http://msdn.com), ������ "DrawText Function
//!          (Windows)": http://msdn.microsoft.com/en-us/library/dd162498%28VS.85%29.aspx.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "� ����� ����� �� ���� ���� �������.");
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format = DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_WORD_ELLIPSIS);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������� �����.
//!
//! @param   name       �������� ������
//! @param   sizeY      ������ ���� (������ �� Y)
//! @param   sizeX      ������ ����
//! @param   bold       �������� ������ (�� 0 �� 1000)
//! @param   italic     ������
//! @param   underline  �������������
//! @param   strikeout  ������������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txTextOut()
//! @usage
//! @code
//!          txSelectFont ("Comic Sans MS", 20);
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//!          txSelectFont ("Comic Sans MS", 20, 10, false, true, false, true);
//!          txTextOut (100, 200, "�� �� ������-�� ���.");
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSelectFont (const char name[], int sizeY,
                   int  sizeX     = -1,
                   int  bold      = FW_DONTCARE,
                   bool italic    = false,
                   bool underline = false,
                   bool strikeout = false);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������� ��������� �������.
//!
//! @param   text  ��������� ������
//!
//! @return  ������� ������� � ��������� SIZE.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          SIZE size = txGetTextExtent (text);
//!          txTextOut (100 + size.cx / 2, 200 + size.cy / 2, text);
//! @endcode
//}-------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[]);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������ ��������� �������.
//!
//! @param   text  ��������� ������
//!
//! @return  ������ �������.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//}-------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[]) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������ ��������� �������.
//!
//! @param   text  ��������� ������
//!
//! @return  ������ �������.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//}-------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[]) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ������������ ������.
//!
//! @param   align  ����� ������������
//!
//! @return  ���������� ��������� ������������ ������.
//!
//! @title   ����� ������������: @table
//!          @tr TA_BASELINE @td ����� (X,Y) ���������� ������� ����� ������.
//!          @tr TA_BOTTOM   @td ����� (X,Y) ���������� ������ ������� ���������� �������������� \n
//!                              (����� ����� ���� ���� �����).
//!          @tr TA_TOP      @td ����� (X,Y) ���������� ������� ������� ���������� �������������� \n
//!                              (����� ����� ���� ���� �����).
//!          @tbr
//!          @tr TA_CENTER   @td ����� ����� �������� �� ����������� ������������ ����� (X,Y).
//!          @tr TA_LEFT     @td ����� (X,Y) ���������� ����� ������� ���������� �������������� \n
//!                              (����� ����� ������ ���� �����).
//!          @tr TA_RIGHT    @td ����� (X,Y) ���������� ������ ������� ���������� �������������� \n
//!                              (����� ����� ����� ���� �����).
//!          @endtable
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_RIGHT);
//!
//!          txSetTextAlign();
//! @endcode
//}-------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���� ����� �� ��� ��������.
//!
//! @param   name  �������� ������
//!
//! @return  ���������� � ������ � ��������� LOGFONT.
//!          ���� ����� �� ������, ���������� NULL.
//!
//! @see     txTextOut(), txSelectFont()
//! @usage
//! @code
//!          if (txFontExist ("Comic Sans MS")) txSelectFont ("Comic Sans MS", 30);
//!          else                               txSelectFont ("Times", 30);
//! @endcode
//}-------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[]) _TX_CHECK_RESULT;

//! @}
//}
//============================================================================================

//============================================================================================
//{          Drawing to memory DC and image loading
//! @name    ��������� � ������ (�� "����������� ������") � �������� �����������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� �������������� ����� (�������� ���������, Device Context, DC) � ������.
//!
//! @param   sizeX   ������ ������
//! @param   sizeY   ������ ������
//! @param   bitmap  Bitmap to be associated with DC
//!
//! @return  ���������� (��������� �����, �������� Windows) ���������� ������ (��������� ���������).
//!
//! @remarks ��������� �������� ����� ����� ����� ������� ��� ������ txDeleteDC().
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//!
//! @usage
//! @code
//!          HDC save = txCreateCompatibleDC (100, 100);
//!
//!          txBitBlt (backup, 0, 0, 100, 100, txDC(), 0, 0);
//!          txTextOut (20, 20, "Boo!");
//!          txSleep (2000);
//!          txBitBlt (txDC(), 0, 0, 100, 100, save, 0, 0);
//!
//!          txDeleteDC (save);
//! @endcode
//}-------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (int sizeX, int sizeY, HBITMAP bitmap = NULL) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �� ����� ����������� � ������� BMP. ������ ��� �������� ��������.
//!
//! @param   filename  ��� ����� � ������������ � ������� BMP
//!
//! @return  ���������� ���������� ��������� ��������� � ������, � ����������� ������������.
//!          ���� ����������� �� ��������� (�� ������ ����, �������� ������ ����� � �.�.), �� NULL.
//!
//! @note    ����������� ����������� � ����������� �������� ��������� � ������ ("����������� �����"),
//!          ������� ����� ����� ����� <b>�����������</b> ������� ��� ������ txDeleteDC().
//!
//!          ����������� �������������� ������ � ������� BMP. ���� ����� ���� ������� �������, �������� JPG, �
//!          ������������� ��� �� ������ ���������� �� BMP, �� �� ����� ������ �� ���������. ����� �����������
//!          ��������� �� �����.
//!
//!          ���� ������� ������� NULL, �� ���� ������ ����� ��������� ������� ����� �����������
//!          �� ���������� � ��������� ���� � ������ �����. ���� ���� � ����� �� ������ (��� ������
//!          ��� ��������), �� ���� ������������� �� ������� ����� ���������, ������� ����� �� ���������
//!          ������� ������ ����� ����������������. ������� ����� ��������� ����� ���������� ��
//!          ������� About � ��������� ���� (��� ������� ��� ��� "Run from").
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(),
//!          txTransparentBlt()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          if (!background) MessageBox (txWindow(), "Cannot load background", "Epic fail", 0);
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//}-------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[]) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ����� (�������� ���������, DC) � ������.
//!
//! @param   dc     �������� ��������� ��� �����������. \n
//!                 ���� ������� ���������, �� ����� ����������� �� ��������� ������������ NULL.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          if (!background) MessageBox (txWindow(), "Cannot load background", "Oh, not now", 0);
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//}-------------------------------------------------------------------------------------------
//@ {

bool txDeleteDC (HDC  dc);

//! @cond INTERNAL
bool txDeleteDC (HDC* dc);
//! @endcond

//@ }
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������.
//!
//! @param   dest    �������� ���������� (���� ����������)
//! @param   xDest   �-���������� �������� ������ ���� �����������-���������
//! @param   yDest   Y-���������� �������� ������ ���� �����������-���������
//! @param   width   ������ ����������� �����������
//! @param   height  ������ ����������� �����������
//! @param   src     �������� ��������� (������ ����������)
//! @param   xSrc    �-���������� �������� ������ ���� �����������-���������
//! @param   ySrc    Y-���������� �������� ������ ���� �����������-���������
//! @param   rOp     ��������� �������� �����������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @warning ���� ��������� ���������� ��� ��������� ����� NULL, �� ��� �� ���������� � �����������
//!          ������� ������. �������� ������ ������� - ������ ��� �������� ����� ����������� �
//!          ���������� �������� �� ��� ������. ������ � ��������� �� ������������ �������� ��. ����.
//!
//! @title   ������ �����������:
//! @table   @tr SRCCOPY     @td ������ �������� :) - ����� ���������������� �����
//!          @tbr
//!          @tr BLACKNESS   @td ��������� �����-�������� ������ ������ (�����-�������� ������������).
//!          @tr WHITENESS   @td ��������� �����-�������� ����� ������  (�����-�������� ������������).
//!          @tr DSTINVERT   @td ����������� ����� �� ������-���������  (�����-�������� ������������).
//!          @tr PATCOPY     @td �������� ���� ������� ����� ������-���������.
//!          @tbr
//!          @tr MERGECOPY   @td �������� =   �������� & ���� ������� ����� ���������.
//!          @tr MERGEPAINT  @td �������� = ~ �������� | ��������
//!          @tr NOTSRCCOPY  @td �������� = ~ ��������
//!          @tr NOTSRCERASE @td �������� = ~ (�������� | ��������)
//!          @tr PATINVERT   @td �������� =  ����� ��������� ^  ��������
//!          @tr PATPAINT    @td �������� = (����� ��������� | ~��������) | ��������
//!          @tr SRCAND      @td �������� =  �������� & ��������
//!          @tr SRCERASE    @td �������� = ~�������� & ��������
//!          @tr SRCINVERT   @td �������� =  �������� ^ ��������
//!          @tr SRCPAINT    @td �������� =  �������� | ��������
//!          @endtable
//!
//! @see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(),
//!          txColors, RGB()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          if (!background) MessageBox (txWindow(), "Cannot load background", "Once again :(", 0);
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txBitBlt (HDC dest, int xDest, int yDest, int width, int height,
               HDC src,  int xSrc,  int ySrc,  DWORD rOp = SRCCOPY);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������
//!          � ������ ������������.
//!
//! @param   dest        �������� ���������� (���� ����������)
//! @param   xDest       �-���������� �������� ������ ���� �����������-���������
//! @param   yDest       Y-���������� �������� ������ ���� �����������-���������
//! @param   width       ������ ����������� �����������, ���������������
//! @param   height      ������ ����������� �����������, ���������������
//! @param   src         �������� ��������� (������ ����������)
//! @param   xSrc        �-���������� �������� ������ ���� �����������-���������
//! @param   ySrc        Y-���������� �������� ������ ���� �����������-���������
//! @param   transColor  ����, ������� ����� ��������� ����������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @warning ���� ��������� ���������� ��� ��������� ����� NULL, �� ��� �� ���������� � �����������
//!          ������� ������. �������� ������ ������� - ������ ��� �������� ����� ����������� �
//!          ���������� �������� �� ��� ������. ������ � ��������� �� ������������ �������� ��. ����.
//!
//!          ����������� ������� TransparentBlt �� Win32 API ����� �������������� �����������.
//!          � txTransparentBlt ��� ������ ��� ��������� �������������. If you need image scaling,
//!          use original function TransparentBlt and don't mess with stupid TX-based tools.
//!          (See implementation of txTransparentBlt in TXLib.h).
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC superman = txLoadImage ("Resources\\Images\\Superman.bmp");
//!          if (!superman) MessageBox (txWindow(), "Cannot load superman, all the monsters will succeed", "Sorry", 0);
//!
//!          txTransparentBlt (txDC(), 0, 0, 800, 600, superman, 0, 0);
//!          txDeleteDC (superman);  // So pity :(
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, int xDest, int yDest, int width, int height,
                       HDC src,  int xSrc,  int ySrc,  COLORREF transColor = TX_BLACK);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������
//!          � ������ ������������.
//!
//! @param   dest    �������� ���������� (���� ����������)
//! @param   xDest   �-���������� �������� ������ ���� �����������-���������
//! @param   yDest   Y-���������� �������� ������ ���� �����������-���������
//! @param   width   ������ ����������� �����������, ���������������
//! @param   height  ������ ����������� �����������, ���������������
//! @param   src     �������� ��������� (������ ����������).
//!                    ������ ����� 32-������� ������ � �����-����� (��. ����).
//! @param   xSrc    �-���������� �������� ������ ���� �����������-���������,
//!                    ������ ���� � �������� ������� ���������.
//! @param   ySrc    Y-���������� �������� ������ ���� �����������-���������,
//!                    ������ ���� � �������� ������� ���������.
//! @param   alpha   ����� ������������ �����������, � ���������� � �����-������. \n
//!                    (0 - ��� ���������, 1 - ������������ ������ �����-�����)
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @warning ���� ��������� ���������� ��� ��������� ����� NULL, �� ��� �� ���������� � �����������
//!          ������� ������. �������� ������ ������� - ������ ��� �������� ����� ����������� �
//!          ���������� �������� �� ��� ������. ������ � ��������� �� ������������ �������� ��. ����.
//!
//!          �����������-�������� � �����������-�������� �� ����� ���������� ���� �� �����.
//!
//!          ����������� ������ ���� ��������� � ������� txLoadImage() � �����
//!          32-������� RGBA-������. �������������� ����� (�����-�����) �����
//!          ������� �������� �� ������������ �������� �����������.
//!
//!          �����-����� ����� �������, ��������, � Adobe Photoshop, ��������
//!          "����� ����� (New Channel)" � ������� ������� (Channels). ������
//!          ���� � �����-������ ������������� ������ ������������, ����� -
//!          ������ ��������������. ��� ���� � ���������� �������� ���� �����������
//!          (� ������� R, G, B) ������ ���� ������, � ��� ����������, ��� ������.
//!
//!          ������ ������, ���� �������� ������ R,G,B �� �����-�����:
//!          <tt>R,G,B *= A</tt>. ��������� ��� ���:
//!
//!        - ���� �������� �����-������ ��� ���������� ������� ����� 0 (������ ������������),
//!          ����� �������� ������� R,G,B ����� ������ 0 (��� ������ ����).
//!        - ���� �������� �����-������ ����� 255 (������ ��������������),
//!          ����� �������� ������� R,G,B �� ���������.
//!        - ��� ������ �������� �����-������, ������� ����������� ������ ������.
//!
//!          � Photoshop ��� ����� ������� �������� <b>Image @d Apply Image</b> � �����������:
//! @table   @tr Source:     @td <i>��� ����� � ���������</i>
//!          @tr Layer:      @td Background
//!          @tr @b Channel: @td <b> Alpha 1</b>
//!          @tr Blending:   @td Multiply
//!          @tr Opacity:    @td 100%
//! @endtable
//!
//! @note    ����������� ������� AlphaBlend �� Win32 API ����� �������������� �����������.
//!          � txAlphaBlend ��� ������ ��� ��������� �������������. If you still need image
//!          scaling, use original function AlphaBlend and don't mess with stupid TX-based
//!          tools. (See implementation of txAlphaBlend in TXLib.h).
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC batman = txLoadImage ("Resources\\Images\\Batman.bmp");
//!          if (!batman) MessageBox (txWindow(), "Your call to batman failed", "Help yourself out", 0);
//!
//!          txAlphaBlend (txDC(), 0, 0, 800, 600, batman, 0, 0);
//!          txDeleteDC (batman);  // Don't worry, batman will return in "Batman returns" movie
//!          ...
//!
//!          return batman;        // ...and there he comes
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, int xDest, int yDest, int width, int height,
                   HDC src,  int xSrc,  int ySrc,  double alpha = 1.0);
//! @}
//}

//============================================================================================
//{          Utility functions
//! @name    ��������������� �������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ���������� ����������� ����, �� ��������� �������.
//!
//!          ��� ������ ���������� ������������ ������� txEnd().
//!
//! @warning ��������� ������������ �� ������ �����. ��� ����� �������� � ��������
//!          ����������� � ����. ���� � ��������� ��������� ��������, �� �����������
//!          ������� txSleep(), ��� ��� ��� ������������� ��������� �����������,
//!          ���������� �� ��������� ����������.
//!
//! @return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//!
//! @see     txEnd(), txSleep(), txUpdateWindow(), txTextCursor()
//! @usage
//! @code
//!          txBegin();                        // ����� ����������� "���������"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                        // ��� ������� �� ������� ��� txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                          // ����� �� ����� ������ ������������� �������
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txBegin();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������ ���������� ����, ��������������� �������� txBegin().
//!
//! @warning ���� txBegin() ���������� ��������� ���, �� ��� ������ ����������
//!          ��������� ������� �� ��� ������� txEnd().
//!
//! @return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//!
//! @see     txBegin(), txSleep(), txUpdateWindow(), txTextCursor()
//! @usage
//! @code
//!          txBegin();                        // ����� ����������� "���������"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                        // ��� ������� �� ������� ��� txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                          // ����� �� ����� ������ ������������� �������
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txEnd();

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ���������� ��������� �� ������������ �����.
//!
//! @param   time  �������� � �������������.
//!
//! @return  ��������� ���������� ���������� ����.
//!
//! @note    <b>�� ����� �������� ����������� � ���� ������ �����������.</b>
//!
//! @see     txBegin(), txEnd(), txUpdateWindow()
//! @usage
//! @code
//!          txSleep (500); // ������� ����������
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSleep (int time);

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ��������� ��� ��������� �������������� ���������� ����������� � ����.
//!
//! @param   update  ����� ���������� (true - ���������, false - ���������).
//!
//! @return  ���������� ��������� ������ ����������.
//!
//!          � ������� �� txBegin() � txEnd(), ������� ������������ ��������� ������
//!          � �������� ��� "������ ��� ���������� ��������", txUpdateWindow()
//!          ��������� ���� ���������� ��� ����� ���������� ��������������� ����������.
//!
//!          ����� ������ ���������� � ���������� ��. � �������� txBegin(), txEnd() � txSleep().
//!
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(),
//!          txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txUpdateWindow (int update = true);

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� ������� ������ GDI.
//!
//! @param   obj  ���������� ������� GDI
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txSelectFont()
//! @usage
//! @code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ���� TXlib.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @warning ���� ������������ ������� ���� TXLib, ������� main() ����������� � ���������
//!          ������������� �����������. ��� ���� @b �� ������������� ���������� ����������
//!          ���������, ������� ��� ������ @b �� �������������.
//!
//! @see     txCreateWindow()
//! @usage
//! @code
//!          txDestroyWindow();  // Farewell to the world
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txDestroyWindow();

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������ ����� ������ �������. ��. �������� �������.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          � ���� ������� ���� ������� � ������� �������� ���������, ������� ��� � �����
//!          ����������, ����� @a ����������� ���� �������. ��� ����� [�����������]�������
//!          ��� ������������ ��� � ����������, ��� ���������.
//!
//! @see     txCreateWindow(), txSleep()
//! @usage
//! @code
//!          int main()
//!              {
//!              txCreateWindow (800, 600);
//!
//!              txSetTextAlign (TA_CENTER);
//!              txTextOut (txGetExtentX()/2, txGetExtentY()/2, "Press any key to exit!");
//!
//!              txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture();
//!              return 0;
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

// See definition of this function below in this file.

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture();

//! @}
//}

//============================================================================================
//{          Mouse
//! @name    ������ � �����
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� ������� ����!
//!
//! @return  ������� ���� ��� ��������� POINT.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//! @usage
//! @code
//!          RECT area = { 100, 100, 110, 110 };
//!
//!          while (txMouseButtons() != 1)
//!              {
//!              if (In (txMousePos(), area)) txTextOut (100, 100, "What are you doing here?!");
//!              txSleep (0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
POINT txMousePos();

//{-------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� �-���������� ����!
//!
//! @return  �-���������� ����.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//! @usage
//! @code
//!          while (txMouseButtons() != 1)
//!              {
//!              txCircle (txMouseX(), txMouseY(), 20);
//!              txSleep (0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txMouseX() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� Y-���������� ����!
//!
//! @return  Y-���������� ����.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//! @usage
//! @code
//!          while (txMouseButtons() != 1)
//!              {
//!              txCircle (txMouseX(), txMouseY(), 20);
//!              txSleep (0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txMouseY() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� ��������� ������ ����!
//!
//! @return  ��������� ������ ����!
//!
//!          � ������������ �������� ������������ � ������� 1-� (�������)
//!          ��� �������� ������� ����� ������ ����, 2-� - ������, 3-� - �������. \n
//!          ��������, ������������ ����� 5 (�������� 101) �������� �������������
//!          ������� ������� � ����� ������, �� �� ������ ������.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//! @usage
//! @code
//!          while (txMouseButtons() != 3)
//!              {
//!              if (txMouseButtons() & 1) txCircle (txMouseX(), txMouseY(), 20);
//!              if (txMouseButtons() & 2) txLine   (txMouseX(), txMouseY(), 0, 0);
//!              txSleep (0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txMouseButtons() _TX_CHECK_RESULT;

//! @}
//}
//============================================================================================

//============================================================================================
//{          Console functions
//! @name    ������� �������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� �������� �������� �������.
//!
//! @param   colors  �������� �������� �������.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          @b �������� - ��� ���� ������ (colorText) � ���� ���� (colorBackground),
//!          ������������ ������: \n\n
//!          <tt>colors = colorText + colorBackground * 16</tt> \n\n
//!          ���� \n\n
//!          <tt>colors = colorText | (colorBackground \<\< 4)</tt> \n\n
//!          ����� ��������� @b �� ����� �������� ��������� � ������ ���������,
//!          ����������� @ref txColors "TX_..." �����������, RGB(), txSetColor(), txColor(),
//!          txSetFillColor(), txFillColor() � �.�. �������� ������ ��. ����.
//!
//! @title   �������� ������ ���������
//! @table   @tr  Dec @td @c Hex @td                 @td Dec  @td @c Hex @td
//!          @tbr
//!          @tr  0 = @td @c 0x0 @td = ������,       @td  8 = @td @c 0x8 @td = �����-�����,
//!          @tr  1 = @td @c 0x1 @td = �����,        @td  9 = @td @c 0x9 @td = ������-�����,
//!          @tr  2 = @td @c 0x2 @td = �������,      @td 10 = @td @c 0xA @td = ������-�������,
//!          @tr  3 = @td @c 0x3 @td = ����-�������, @td 11 = @td @c 0xB @td = ������-����-�������,
//!          @tr  4 = @td @c 0x4 @td = �������,      @td 12 = @td @c 0xC @td = ������-�������,
//!          @tr  5 = @td @c 0x5 @td = ���������,    @td 13 = @td @c 0xD @td = ������-���������,
//!          @tr  6 = @td @c 0x6 @td = �����-������, @td 14 = @td @c 0xE @td = ������,
//!          @tr  7 = @td @c 0x7 @td = �����,        @td 15 = @td @c 0xF @td = �����.
//! @endtable
//!
//!          � ����������������� ������� ��������� �������� �������� ����� �����: ���� �����,
//!          ������, ������ ���� �� ����� ����, �� ��� ��� ����� @c 0x1e (������� ����� - ������� 4
//!          ���� - ��� ���� ����, ������� ����� - ������� 4 ���� - ��� ���� ������).
//!
//! @see     txTextCursor(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          txSetConsoleAttr (0x1e);
//!          printf ("� � ���� ������� ���� ����� �������");
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSetConsoleAttr (WORD colors = 0x07);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� �������� �������� �������.
//!
//! @return  ������� �������� �������� �������. ��. txSetConsoleAttr().
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          unsigned attr = txGetConsoleAttr();
//! @endcode
//}-------------------------------------------------------------------------------------------

WORD txGetConsoleAttr() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� ����� �������.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//!          ��� �������� ������������ ������� �������� (����� ������ � ����) �������.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          txClearConsole();  // �� ��� � ���, ������
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txClearConsole();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ��������� ������� �������.
//!
//! @param   x  X-���������� ������� � ��������.
//! @param   y  Y-���������� ������� � ��������.
//!
//! @return  ���������� ��������� ��������� ������� � ��������� POINT.
//!
//! @note    ������ ���������� ������ ����� �������. ����� � ������� ���������� �� �������������
//!          �����, ������ ������� ������� �� �������� ������ �������. ��������������� �������
//!          �����������, ����� ������ ����� � ������ �����. ��. ������ � ������� txGetConsoleFontSize().
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          txSetConsoleCursorPos (txGetExtentX(), txGetExtentY());  // ����� ���������
//! @endcode
//}-------------------------------------------------------------------------------------------

POINT txSetConsoleCursorPos (int x, int y);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ��������� ������� �������.
//!
//! @return  ��������� ��������� ������� � ��������� POINT.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          POINT pos = txGetConsoleCursorPos();
//! @endcode
//}-------------------------------------------------------------------------------------------

POINT txGetConsoleCursorPos();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ������ �������.
//!
//! @return  ������� ������ ������� � ��������, � ��������� POINT.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          POINT size = txGetConsoleFontSize();
//!          txSetConsoleCursorPos (5 * size.x, 10 * size.y);  // ������ ����� ���
//! @endcode
//}-------------------------------------------------------------------------------------------

POINT txGetConsoleFontSize();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ��� ��������� ��������� ��������� ������� � ����.
//!
//! @param   blink  false - ��������� �������� ������
//!
//! @return  ���������� �������� ����������.
//!
//! @see     txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole(), txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txTextCursor (bool blink = true);

//! @}
//}
//============================================================================================

//============================================================================================
//{          Other staff not related to drawing
//! @name    ������ �������� �������, �� ��������� � ����������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� �������� ����.
//!
//! @param   filename  ��� ��������� �����. ���� NULL - ������������� ����.
//! @param   mode      ����� ���������������
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @title   ������ ���������������: @table
//!          @tr SND_ASYNC       @td ���� ������������� ������������ � ������� ���������. \n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL).
//!          @tr SND_SYNC        @td ���������� ��������� ������������������ �� ���������
//!                                  ��������������� �����.
//!          @tr SND_LOOP        @td ����������� ���� ��� ���������������. \n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL).
//!          @tbr
//!          @tr SND_NODEFAULT   @td �� ������������ ���� �� ���������, ���� ������ ���������
//!                                  ��������� �������� ����.
//!          @tr SND_NOSTOP      @td ���� �����-���� ���� ��� �������������, �� �������������
//!                                  ��� ��� ��������������� ���������� �����.
//!          @tr SND_APPLICATION @td ����������� ����, ��������� ���������, ������������������
//!                                  ��� ������� ���� �������� ������.
//!          @endtable
//!
//! @note    �������������� ������ ����� � ������� WAV. ��������� ������� (MP3 � ��.) ����
//!          ��������������. �������������� �� ������ ���������� �� �������, ��� � � ������
//!          � �������� �������� � txLoadImage().
//! @usage
//! @code
//!          txPlaySound ("tada.wav"); // so happy that this always exists
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC);

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� �������� ������ ����������.
//!
//! @return  �������� ������ � �������� ��������.
//!
//! @see     txSleep()
//! @usage
//! @code
//!          if (txQueryPerformance() < 1) printf ("������� ����� ���������");
//! @endcode
//}-------------------------------------------------------------------------------------------

double txQueryPerformance() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������� ������� � ���������
//!
//! @param   arr  ��� �������
//!
//! @return  ������ ������� � ��������� (�� � ������).
//!
//!          ������ SIZEARR() ��������� ������ ������� � ���������, ��������, ����� �� ���
//!          ��������� ��������� ��� ����������.
//!
//!          ������ sizearr() ������ ����� ������ ����� ������� � ������ �� ������ ��� ��������,
//!          ���������� ������ ������� � ���������. �� �� ���������, ����� �� ��� ���������
//!          ���������, � ��� ������������ ������������� ������ �������� ������.
//!
//! @warning sizearr() ������ �������� ������, ���� ����������� ������� ������ � ��� ��������,
//!          ��������� ��� ����������, ���������� � ����� ������������� sizearr(). ��. ������ ����.
//!
//! @note    � Microsoft Visual Studio 6 ������ SIZEARR() ����������.
//!
//! @usage
//! @code
//!          void test()
//!              {
//!              // ������ ����� �������, ���� � �� ������, �� ����� ���� ������������� ���������
//!              // ������������ ��� ���������� ���������. �� ����� 4 (������ ��������� POINT).
//!
//!              POINT coord[] = { {110, 110}, {120, 120}, {130, 110}, {140, 120} };
//!
//!              // ����� ������ ������� �������� ��� ����������, �.�. �� ��������� ����� ��.
//!
//!              for (int i = 0; i < SIZEARR (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!
//!              DrawLines1 (coord);                  // ������� �������� ������ ��� �������� �������.
//!              DrawLines2 (coord, SIZEARR (coord)); // ���������� �������� ������� �������.
//!
//!              DrawLines3 (coord);                  // � ��������, ����� � ���, �� ��� ������� �������.
//!              }
//!
//!          // ������� DrawLines1 � DrawLines2 ���������� ���:
//!
//!          void DrawLines1 (const POINT coord[])
//!              {
//!              // ������� � �� ���������� ��� ��������� �� ������ �������. �������:
//!              // 1) SIZEARR ����� ������ ������ ����������, � �� ����� ����� �����.
//!              // 2) sizearr ����� ����������� ��������� ������, ��� ������� ����,
//!              //      �.�. �� ����� ����� sizeof (POINT*) / sizeof (POINT) == 4/8 == 0.
//!
//!              for (int i = 0; i < SIZEARR (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//!
//!          void DrawLines2 (const POINT coord[], int n)
//!              {
//!              // ����� ������ �������� ��� ������������� �������� n, ��� ��� ��� ������.
//!
//!              for (int i = 0; i < n - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//!
//!          // HIC SVNT TEMPLATES
//!
//!          template <int size>
//!          void DrawLines3 (const POINT (&coord) [size])
//!              {
//!              for (int i = 0; i < size - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------
//! @{

#ifndef _MSC_VER_6

    #define SIZEARR( arr )    ( sizeof (get_size_of_an_array_with_unknown_or_nonconst_size_ (arr)) )

    //! @cond INTERNAL
    template <typename T, int N> char (&get_size_of_an_array_with_unknown_or_nonconst_size_ (T (&) [N])) [N]; // ;)
    //! @endcond

#endif

//! ������ ������� SIZEARR() ��� ������ � Microsoft Visual Studio 6

#define sizearr( arr )        ( sizeof (arr) / sizeof (arr)[0] )

//! @}
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������, ��������� �� �������� � ������ ���������� ��������� [a; b]
//!
//! @param   x  ����������� ��������
//! @param   a  �����  ������� (������������)
//! @param   b  ������ ������� (������������)
//!
//! @return  ���� a <= x && x <= b, �� ������, ���� ��� - ����
//!
//! @usage
//! @code
//!          while (txMouseButtons() != 1)
//!              {
//!              if (In (txMouseX(), 110, 120)) txTextOut (100, 100, "Meet the wall!");
//!              txSleep (0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

template <typename T> inline
bool In (T x, T a, T b) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������, ��������� �� ����� pt ������ �������������� rect
//!
//! @param   pt    ����������� ����� � ���� <tt> POINT {x, y} </tt>
//! @param   rect  �������������     � ���� <tt> RECT  {left, top, right, bottom} </tt>
//!
//! @return  ��������� ��������
//!
//!          ������ ��� ���������� ������.
//!
//! @usage
//! @code
//!          RECT button = { 100, 100, 150, 120 };
//!
//!          txSetFillColor (TX_LIGHTGRAY);
//!          txRectangle (button.left, button.top, button.right, button.bottom);
//!
//!          txSetTextAlign();
//!          txSetFillColor (TX_WHITE);
//!          txTextOut (125, 115, "Cookie");
//!
//!          for (;;)
//!              {
//!              if (In (txMousePos(), button))
//!                  {
//!                  txSetFillColor (TX_TRANSPARENT);
//!                  txRectangle (button.left, button.top, button.right, button.bottom);
//!
//!                  if (txMouseButtons())
//!                      {
//!                      txSetFillColor (TX_DARKGRAY);
//!                      txRectangle (button.left, button.top, button.right, button.bottom);
//!
//!                      txSetFillColor (TX_WHITE);
//!                      txTextOut (125, 115, "You got cookie");
//!
//!                      break;
//!                      }
//!                  }
//!
//!              txSleep (0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------
//! @{

inline
bool In (const POINT& pt, const RECT& rect)       _TX_CHECK_RESULT;

inline
bool In (const COORD& pt, const SMALL_RECT& rect) _TX_CHECK_RESULT;

//! @}
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��������� �����
//!
//! @param   range  ������ ������� ��������� (@b �� ������� ���� �������).
//!
//! @return  ��������� ����� ����� � ��������� [0; range).
//!
//!          �� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//! @usage
//! @code
//!          char message[100] = "Maybe...";
//!          sprintf ("You SUDDENLY got %d bucks now. But note that tax rate is $%d.", random (100), 100);
//!          MessageBox (txWindow(), message, "Lottery", 0);
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int random (int range) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��������� �����
//!
//! @param   left   ������ ������� ��������� (@b ������� ���� �������).
//! @param   right  ������ ������� ��������� (@b ������� ���� �������).
//!
//! @return  ��������� ����� ����� � ��������� [left; right].
//!
//!          �� ��� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//! @usage
//! @code
//!          int money = random (-100, +100);
//!          if (money < 0)
//!              {
//!              char message[100] = "Maybe...";
//!              sprintf ("������ � �������? ������� %d ������", -money);
//!              MessageBox (txWindow(), message, "������!", 0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
double random (double left, double right) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������������ �� ���� �����
//!
//! @param   a  ���� �� ����� :)
//! @param   b  ������ �� ����� :)
//!
//! @return  ������������ �� ���� ����� a � b
//!
//! @see     MIN()
//! @usage
//! @code
//!          if (MAX (3, 7) != 7) printf ("Your CPU is broken, throw it away.");
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define MAX( a, b )    ( (a) > (b) ? (a) : (b) )

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ����������� �� ���� �����
//!
//! @param   a  ���� �� ����� :)
//! @param   b  ������ �� ����� :)
//!
//! @return  ����������� �� ���� ����� a � b
//!
//! @see     MAX()
//! @usage
//! @code
//!          if (MIN (3, 7) != 3) printf ("Your CPU is still broken, throw it away again.");
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define MIN( a, b )    ( (a) < (b) ? (a) : (b) )

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����� ��
//!
//! @return  ����� ��
//!
//! @usage
//! @code
//!          if (txPI == 1) MessageBox (txWindow(), "�� ������ � ������ ���������.", "�����������", MB_ICONSTOP);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� �����, �� ������� �������������
//!
//! @param   type  ��� ����
//!
//! @return  �������� ���� @c type, ������������� ������������������ �� ���������
//!          (��� ���������� ����� C++ - �����).
//!
//! @usage
//! @code
//!          void f (POINT p);
//!          ...
//!
//!          POINT z = {}; f (z);  // ��� ��� ZERO
//!
//!          f (ZERO (POINT));     // ��� � ZERO
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define ZERO( type )    zero <type> ()

//! @cond INTERNAL
template <typename T> inline T zero();
//! @endcond

//! @}
//}
//============================================================================================

//============================================================================================
//{          Back-hole (I hope, not an ass-hole:) of the library)
//! @name    ����� ��������� �������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� �������������� ���������� ������� ��������� Windows.
//!
//! @param   handler  ����� �������������� ���������� ������� ����. \n
//!                   ���� NULL, �� �������������� ���������� ���������.
//!
//! @return  ����� ����������� ��������������� ����������� ��������� ����.
//!
//!          ���������� ����� ���������� @b �� ��������� ������� ���������� TXLib.
//!          �� ������ ���� �������� �� ��������� ����������:
//! @code
//!          LRESULT CALLBACK NewWndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam);
//! @endcode
//!
//! @warning ���������� ���������� �� ���������������� (�������) ������, ������������
//!          \ref txCreateWindow(). ��� @b �� ��� �� ����� �����, � ������� �����������
//!          main(). � ����� � ���� ������ ����������� ��� ������ � ����������� �����������
//!          ��� �� ���������, �.�. ����� ���������� "����� �� �������" (race condition).
//!
//! @warning ���� ���������� ������ ��������, �� ������ 0, ����������� ���������
//!          ��������� ���������� TXLib �� ������������. ��������, ��� ���� ��
//!          ������ ��������� ���������. �������� ��������� ��������� � �������
//!          Alt-Ctrl-Del �� ���������� �����, ��� �� ����� ������������ ����������
//!          <a href=http://technet.microsoft.com/en-us/sysinternals/bb896653.aspx>
//!          Process Explorer</a>. ���� �� ������ �� ���� ��������� �������� ���������,
//!          ������� �� �� �������� Win32 (��. MSDN), ������� ����� DefWindowProc().
//!
//! @note    ������ �������� ������� ������� ����� � ������� SetWindowLong() ��� SetWindowLongPtr():
//! @code
//!          WNDPROC OldWndProc = (WNDPROC) SetWindowLongPtr (txWindow(), GWL_WNDPROC, (LONG_PTR) NewWndProc);
//! @endcode
//!          ��� ���� ���� ����������� ������ �������� ������ ������� ������� � ������� CallWindowProc(),
//!          (��. MSDN), ����� ����������� ����� ������ �� ����������, ��� ������� ����.
//!
//! @see     txCreateWindow(), txDialog, txInputBox()
//! @usage
//! @code
//!          LRESULT CALLBACK MyWndHandler (HWND window, UINT message, WPARAM wParam, LPARAM lParam);
//!
//!          int main()
//!              {
//!              txCreateWindow (800, 600);
//!
//!              txSetWindowProc (MyWndHandler);
//!
//!              txCircle (txGetExtentX()/2, txGetExtentY()/2, 100);
//!
//!              printf ("\n" "Still working ");
//!              }
//!
//!          LRESULT CALLBACK MyWndHandler (HWND window, UINT message, WPARAM wParam, LPARAM lParam)
//!              {
//!              static int i = 0;
//!              if (i++ % 10 == 0) printf ("\b" "%c", "-\\|/" [i/10 % 4]);
//!              return 0;
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

WNDPROC txSetWindowHandler (WNDPROC handler = NULL);

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ���������� ������ (��������� ���������).
//!
//! @param   wait  ������� ����� ����������� ���� ��������������� �������
//!
//! @return  ��������� ����������
//!
//!          ����� ������� ����� ������� Win32 GDI ���������� �������������
//!          ����� �������� txLock() � ����� �������������� � ������� txUnlock().
//!          ��� ������� � ���, ��� ���������� ����������� ���� (��� ���, ��� ����� -
//!          ��������� ��������� WM_PAINT � ���������� TXlib ���������� � ���������
//!          ��������������� ������. ������� ����������� ������ - ��� ���������������
//!          ������ ���� �� �����������.
//!
//!          txLock() ���������� EnterCriticalSection(), � ��������� ����������������
//!          �����, ����������� ����, ��� ��� ������� ����������� ������. ����� ����������
//!          ��������� ������� ���������, ���� ��������� ����������� �� �������� ������������
//!          � ����������������. ������ ����� �������� txSleep() ��� Sleep() ��� ���������������
//!          ������.
//!
//!          txLock() / txUnlock() - �������������� ��������. �� ���������� �� ����� ��������
//!          ���������������� ��������� txBegin() / txEnd() / txUpdateWindow(),
//!          ������� �� ���������������� �����, � ������ ��������� �������� �� ���������� ����.
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//!          ��. �������� ����� ������� _txCanvas_OnPaint() � _txConsole_Draw() � TXLib.h.
//}-------------------------------------------------------------------------------------------

bool txLock (bool wait = true);

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� ������
//!
//! @return  ��������� ���������� (������ false).
//!
//!          ����� �������� ��. � �������� txLock().
//!
//! @see     txDC(), txLock(), txGDI()
//! @usage
//!          ��. �������� ����� ������� _txCanvas_OnPaint() � _txConsole_Draw() � TXLib.h.
//}-------------------------------------------------------------------------------------------
//! @{

bool txUnlock();

//! @cond INTERNAL
template <typename T> inline T txUnlock (T value);
//! @endcond

//! @}

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ����� ������� Win32 GDI � �������������� ����������� � ��������������.
//!
//! @param   command  ������� GDI (��������, ������������ ��������)
//!
//! @return  ��������, ������������ ���������� �������� GDI.
//!          ���� ������� ��������� �� ������, ������������ �������� false.
//!
//! @note    ���� ������� ��������� �� ������ (txDC() ���������� NULL),
//!          �� ������� GDI �� �����������, � txGDI() ���������� �������� false.
//!
//! @note    ���� � ������ ������� GDI ������������ �������, �� ����������� �������
//!          ������, ����� ��������� ���� ��������, ��� ��� txGDI() ���-���� ������.
//!
//! @see     txDC(), txLock(), txUnlock()
//! @usage
//! @code
//!          txGDI (( Rectangle (txDC(), x1, y1, x2, y2) )); // �� �������� ��� ��� ������
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define txGDI( command )  txUnlock ( (txLock(), (command)) )

//! @}
//}
//============================================================================================

//============================================================================================
//{          Tune-up constants
//! @name    ����������� ���������
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������ ����������� ������������� TXLib
//!
//!          ���� ��������� ���������� � ������� #define �� ��������� TXLib.h � ���������,
//!          ����������� ������������� �� ����������. �� ��������� ��� ����������.
//!
//! @note    ����������� ������������� ��������:
//!        - �������� ���� �������,
//!        - ��������� ������� �������� 1251 ������� ��� ��������� �������� �����,
//!        - ��������� ������� ������ ����������� ����������,
//!        - ����������������� ��������� stdio � iostream �� ������, ���� ����������
//!          �� ������������ ��� ���������� � ���������� �������� ������������������,
//!        - �������� ��������� �������� (������� �� 0, ��������� �� ��������� ������ � �.�.),
//!        - �������� �������������� ����������,
//!        - ����� ��������� ����������� ����,
//!        - ��������� ������ ����� �� ���������� ���������, ����� ���� ����������� �� �����,
//!        - ���������� ����� �� ���� ����������������, ������������ �������� �� ������� ��� ����.
//!          <br><br>
//! @note    ���� ����������� ������������� ���������, �� ��������� ���� TXLib � �������
//!          txCreateWindow(), �� ���������� ��� ����� ����� ����������������.
//!
//!          ����� ���������� ����� ���������� TXLib.h � ���������.
//! @see     txCreateWindow(), _TX_ALLOW_KILL_PARENTS, _TX_WAITABLE_PARENTS, _TX_CONSOLE_MODE
//! @usage
//! @code
//!          #define _TX_NOINIT
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if  defined  (_TX_NOINIT)

    #undef     _TX_NOINIT
    #define    _TX_NOINIT                 1

#else

    #define    _TX_NOINIT                 0

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������ ����������� ��������, ������� ���� ������� ������� ����� ���������� ��������
//!          TXLib.
//!
//!          ���� ��������� ����������� � ������ � TXLib �������� �� ���, �� ��� ���������� TXLib
//!          ��������� ��������� ����� �������. (��� ����������, ���� �� ������� ����������� ����
//!          TXLib, � ���� ������ ���� �������.)
//!
//!          ��������� ����������� �������� ��� �������. ����������� �������� �������� �����������
//!          ���������, ����� ���������.
//!
//!          ����� ���������� ����� ���������� TXLib.h � ���������.
//!
//! @see     _TX_ALLOW_KILL_PARENTS, _TX_NOINIT
//}-------------------------------------------------------------------------------------------

            // TX_VEGETABLE_PRINTERS
#if !defined  (_TX_WAITABLE_PARENTS)
    #define    _TX_WAITABLE_PARENTS       "cmd.exe:devenv.exe, cb_console_runner.exe:codeblocks.exe, starter.exe:eclipse.exe"
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������� �������������� ���������� ���������� ��������, ������ ������� ������ �����
//!          ���������� TXLib.
//!
//!          ����� ���������� ����������� ����� �� ������� �������, ���������� � TXLib, � �����
//!          ����� ����� ������ ���������� �������.
//!
//!          ������ ���������� ��������, ������� ����� ������ ����� �����, �������� � _TX_WAITABLE_PARENTS.
//!
//!          ����� ���������� ����� ���������� TXLib.h � ���������.
//!
//! @see     _TX_WAITABLE_PARENTS, _TX_NOINIT
//! @usage
//! @code
//!          #define _TX_ALLOW_KILL_PARENT false
//!          #include "TXLib.h"
//! @endcode
//}-------------------------------------------------------------------------------------------

#if !defined (_TX_ALLOW_KILL_PARENT)
#define       _TX_ALLOW_KILL_PARENT       true  // ���, ��� ��������� ����������� ���������! ������ ���.
#endif                                          // � ��, � �� �������� � �������� ���������. ��� ����������� ������.

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� ����������� ����������� ����. ��������� ����� ����� ������� SetWindowPos.
//!
//!          �� ����������: @c SWP_HIDEWINDOW @d �������� ���������� ����.
//!
//!          ����� ���������� ����� ���������� TXLib.h � ���������.
//!
//! @see     _TX_NOINIT
//! @usage
//! @code
//!          #define _TX_CONSOLE_MODE SWP_SHOWWINDOW // ��������, �������� ����
//!          #include "TXLib.h"
//! @endcode
//}-------------------------------------------------------------------------------------------

#if !defined  (_TX_CONSOLE_MODE)
    #define    _TX_CONSOLE_MODE           SWP_HIDEWINDOW
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� �������
//}-------------------------------------------------------------------------------------------

const char     _TX_CONSOLE_FONT[]         = "Lucida Console";

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���� ������ �������
//}-------------------------------------------------------------------------------------------

const COLORREF _TX_CONSOLE_COLOR          = TX_LIGHTGRAY;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ������� ������� ������� (��)
//}-------------------------------------------------------------------------------------------

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ���������� ������ (��)
//}-------------------------------------------------------------------------------------------

const int      _TX_WINDOW_UPDATE_INTERVAL = 10;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� �������� �������� (��)
//}-------------------------------------------------------------------------------------------

const int      _TX_TIMEOUT                = 1000;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� ���������� ����������� ��������� ������� TXLib
//}-------------------------------------------------------------------------------------------

const int      _TX_BUFSIZE                = 1024;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� ���������� ����������� ��������� ������� TXLib
//}-------------------------------------------------------------------------------------------

const int      _TX_BIGBUFSIZE             = 2048;

//! @}
//}
//============================================================================================

//============================================================================================
//{          Diagnostics and Tools
//! @name    ����������� � �������
//============================================================================================
//! @{ @cond INTERNAL

#define  TX_QUOTE( symbol )   _TX_QUOT2 (symbol)
#define _TX_QUOT2( symbol )   #symbol

//! @endcond
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��� � ������ �������� �����������
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if   defined (__GNUC__)
    #define __TX_COMPILER__   "GNU C++ "            TX_QUOTE (__GNUC__)       "."  \
                                                    TX_QUOTE (__GNUC_MINOR__) "."  \
                                                    TX_QUOTE (__GNUC_PATCHLEVEL__) \
                                         ", C++ = " TX_QUOTE (__cplusplus)
#elif defined (_MSC_VER)
    #define __TX_COMPILER__   "Microsoft C++ "      TX_QUOTE (_MSC_VER) \
                                         ", C++ = " TX_QUOTE (__cplusplus)

#elif defined (__INTEL_COMPILER)
    #define __TX_COMPILER__   "Intel C++ Compiler " TX_QUOTE (__INTEL_COMPILER) \
                                         ", C++ = " TX_QUOTE (__cplusplus)

#else
    #define __TX_COMPILER__   "Unknown compiler" \
                                         ", C++ = " TX_QUOTE (__cplusplus)

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, �������������� � ��� ����� � ����� ������ �����, ��� �� ����������.
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define __TX_FILELINE__       __FILE__ " (" TX_QUOTE (__LINE__) ")"

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��� ������� �������
//!
//! @warning ���� ����������� ����� ������� �� �������������� ������������, �� __TX_FUNCTION__
//!          ������������ � ��� ��������� ����� � ����� ������.
//!
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if defined (__GNUC__)
    #define __TX_FUNCTION__   __PRETTY_FUNCTION__

#elif defined (__FUNCSIG__)
    #define __TX_FUNCTION__   __FUNCSIG__

#elif defined (__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)
    #define __TX_FUNCTION__   __FUNCTION__

#elif defined (__BORLANDC__) && (__BORLANDC__ >= 0x550)
    #define __TX_FUNCTION__   __FUNC__

#elif defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
    #define __TX_FUNCTION__   __func__

#else
    #define __TX_FUNCTION__   "(" __TX_FILELINE__ ")"

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��� ������ ������
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if   !defined (NDEBUG) &&  defined (_DEBUG)
    #define _TX_BUILDMODE     "DEBUG"

#elif !defined (NDEBUG) && !defined (_DEBUG)
    #define _TX_BUILDMODE     "Debug"

#elif  defined (NDEBUG)
    #define _TX_BUILDMODE     "Release"
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ������������ ������� assert(), � ������� ��������� ����� MessageBox(),
//!          ������� � OutputDebugString().
//!
//! @param   cond  ������� ��� ��������
//!
//! @return  ������ 0
//!
//!          ���� �������, ����������� assert(), �������, �� ������ ������ �� ������. \n
//!          ���� ������� ����������� �����, �� ��������� ��������������� ��������� �
//!          ��������� �������� �����������.
//!
//! @note    <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) assert
//!          ������������ � ������ ��������.</b> \n
//!          �� ���� �������� � assert() ��������, ������� ����� ��� ������ ��������.
//!
//! @see     asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_DEBUG_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          assert (0 <= i && i < ARRAY_SIZE);
//!
//!          FILE* input = fopen ("a.txt", "r");
//!          assert (input);
//!
//!          // ���� ����� fgets() �� ����� �������� � ������ Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          // ����� ��� ����� ���������:
//!          bool ok = (fclose (input) == 0);
//!          assert (ok);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#undef  assert

#if !defined (NDEBUG)
    #define assert( cond )    ( !(cond)? (TX_ERROR ("\a" "��������: ���������� ������: �������, ��� \"%s\"" _ #cond), 0) : _txNOP (0) )

#else
    #define assert( cond )    ( 0 )

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��������������� ��������� � ������ �������� ��� ������� ����������.
//!
//! @return  ������ 0
//!
//!          ���������� ����� ������� assert(), �� �������� � ������ Release
//!          ���������� ���������.
//!
//! @note    <b>��������������, ��� �������� � ������ �������� ���������� 0 ��� false.</b> \n\n
//!          <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) asserted
//!          ������������ � ������ �����.</b>
//!
//! @see     assert(), __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_DEBUG_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          FILE* input = fopen ("a.txt", "r"); assert (input);
//!
//!          // ���� ����� fgets() ����� �������� � ����� ������:
//!          fgets (str, sizeof (str) - 1, input) asserted;
//!
//!          // ���� ����� fgets() �� ����� �������� � ������ Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          (fclose (input) != 0) asserted;
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define asserted          || TX_ERROR ("\a" "��������� ������� ��� ������ ���������")

#else
    #define asserted          || 0

#endif

//! @cond INTERNAL
#define TX_NEEDED             asserted  //!< For compatibility with earlier releases
//! @endcond

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ����������� ��������������� ���������.
//!
//! @param   msg  ��������� � ������������ ����������� ���������� � ����� ������� @c printf().
//!               ���� ���������� ���������, ��� ����������� _ (@ref _ "�������� �������������",
//!               ���������������� � �������) ������ ��������� �������, �.�. TX_ERROR - ������.
//!
//! @return  ������ false
//!
//! @see     _, assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_DEBUG_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          TX_ERROR ("�� ���� ��������� '����� � ���'. ������� %d: �� ����� '%s'" _ reasonNum _ fileName);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define TX_ERROR( msg )       ( _txError (__FILE__, __LINE__, __TX_FUNCTION__,                \
                                         (DWORD)(-1), -1, -1, msg), _txNOP (0) )

//! @cond INTERNAL
#define TX_THROW              TX_ERROR  //!< For compatibility with earlier releases
//! @endcond

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ����������� ��������������� ��������� � ���������� ������.
//!
//! @param   msg  ��������� � ������������ ����������� ���������� � ����� ������� @c printf().
//!               ���� ���������� ���������, ��� ����������� _ (@ref _ "�������� �������������",
//!               ���������������� � ������� ������ ��������� �������, �.�. TX_DEBUG_ERROR - ������.
//!
//! @return  ������ false
//!
//! @note    � ������ Release ���� ������ �� ������� ������.
//!
//! @see     _, assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          TX_DEBUG_ERROR ("��� � �� ���� ��������� '����� � ���'. ������� %d: ������� '%s'" _ reasonNum _ fileName);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define  TX_DEBUG_ERROR         TX_ERROR

#else
    #define  TX_DEBUG_ERROR(msg)    ( 0 )

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ����������� ��������������� ��������� � ���������� ������.
//!
//! @param   msg  ��������� � ������������ ����������� ���������� � ����� ������� @c printf().
//!               ���� ���������� ���������, ��� ����������� _ (@ref _ "�������� �������������",
//!               ���������������� � ������� ������ ��������� �������, �.�. TX_DEBUG_ERROR - ������.
//!
//! @return  ������ false
//!
//! @note    � ������ Release ���� ������ �� ������� ������.
//!
//! @see     _, assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          TX_DEBUG_ERROR ("��� � �� ���� ��������� '����� � ���'. ������� %d: ������� '%s'" _ reasonNum _ fileName);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define  TX_DEBUG_ERROR         TX_ERROR

#else
    #define  TX_DEBUG_ERROR(msg)    ( 0 )

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��������� � ���������.
//!
//! @param   format  ������ ��� ������, ��� � printf().
//!
//! @return  ���������� ������������ ��������.
//!
//!          ������� ��������� ��������� �� �������� printf() � �������� ��� OutputDebugString().
//!          �� ����� ����� ����������� ���������-���������, ��������,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>DebugView</a>.
//!          ���� ����� �� �������, � �� ������ ������ ������ @c '\a' (��. ����), �� � ��������� ����� �� ������.
//!
//! @note    ���� ������ ������ � ������ @c '\a', �� ��������� ����� ���������� MessageBox().
//!
//! @warning ��������� �� ������ ��������� _TX_BIGBUFSIZE ��������, ����� ��� ����������.
//!
//! @see     TX_ERROR, TX_DEBUG_ERROR
//! @usage
//! @code
//!          int x = 5821;
//!          ...
//!          txOutputDebugPrintf ("����� �� ������, ��� %d.", x);
//! @endcode
//}-------------------------------------------------------------------------------------------

int txOutputDebugPrintf (const char format[], ...) _TX_CHECK_FORMAT (1);

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, ����������� �������� ���������� ����� ���������� � �����-���� ������ ������.
//!
//! @note    <b>������ ������������� ������ ���������������� � �������.</b>
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR()
//! @usage
//! @code
//!          TX_ERROR ("������� ����� �����: ����� '����� � ���', ���� '%s', ������ %d" _ fileName _ lineNum);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define _                     ,

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��� �����, ����� ������ � ��� �������, ��� ��������� ����� TX_PRINT_HERE().
//!
//! @see     assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          TX_PRINT_HERE();
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define TX_PRINT_HERE()   printf ("[%s %s]\n", __TX_FILELINE__, (*__TX_FUNCTION__? __TX_FUNCTION__ : "?"))

#else
    #define TX_PRINT_HERE()   ;

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������/��������� ���������� ����������� ���������� ���� ����������.
//!
//!          ����������� ���� ����� ������ _TX_TRACE, ������� ������������� �����
//!          ������ ���������� (statement). �� ��������� ����������� ���������.
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(),
//!          �� ����� ����� ����������� ���������-���������, ��������,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a>. ��� ����� ��������, ������������� ������ _TX_TRACE.
//!
//! @warning ����������� @b ����� �������� ���������� ���������, �������� ��� ������� �
//!          Microsoft Visual Studio. � ���� ������ ����� ������������ DebugView (��. ����)
//!          � ��������� ������������ ��������� ��������, � �� ��-��� ��������� Visual Studio.
//!
//!          _TX_ALLOW_TRACE � _TX_TRACE �������� ����� ���������� TXLib.h � ���������.
//! @usage
//! @code
//!          #define  _TX_ALLOW_TRACE  // ��� ��������� ������ ��������� DebugView
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------
//! @{

#ifdef FOR_DOXYGEN_ONLY
#define      _TX_ALLOW_TRACE
#endif

#if defined (_TX_ALLOW_TRACE)
    #undef  $
    #define $                 { _TX_TRACE; }

#elif !defined (NDEBUG)
    #undef  $
    #define $                 { _txSrcLocFile = __FILE__; _txSrcLocLine = __LINE__; _txSrcLocFunc = __TX_FUNCTION__; }

#else
    #undef  $
    #define $                 ;

#endif

//! @cond _OFF

extern const char* _txSrcLocFile;
extern int         _txSrcLocLine;
extern const char* _txSrcLocFunc;

//! @endcond

//! @}
//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ���������� ���� ���������� ����� OutputDebugString().
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(),
//!          �� ����� ����� ����������� ���������-���������, ��������,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> ��� WinTail.
//!
//!          _TX_TRACE ����� �������������� � ���� ���, ����� �� ����� ����������
//!          ����� ������ ������� ���� TXLib.
//!
//!          ����������� ����� �������������� ��������� ���� ����� ������ _TX_ALLOW_TRACE.
//!          �� ��������� ��� ���������.
//!
//!          _TX_TRACE � _TX_ALLOW_TRACE �������� ����� ���������� TXLib.h � ���������.
//! @usage
//! @code
//!          #define  _TX_TRACE  printf (__LINE__ " ");
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------
//! @{

#ifdef FOR_DOXYGEN_ONLY
#define       _TX_TRACE
#endif

#if !defined (_TX_TRACE)

    #define   _TX_TRACE       OutputDebugString (__TX_FILELINE__ ": ")

#endif

//! @}

//! @}
//}
//============================================================================================

//============================================================================================
//{          Dialogs: class txDialog
//! @name    ������ � ����������� ������. ����� txDialog
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
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
//}-------------------------------------------------------------------------------------------

struct txDialog
    {

//{-------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ��������� ��� ������� ���� ��������.
//!
//!          ������ �������� ����� ������������ �������� ������� �������,
//!          ��������������� � ���� txDialog::CONTROL.
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

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

//{-------------------------------------------------------------------------------------------
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
//}-------------------------------------------------------------------------------------------

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

//{-------------------------------------------------------------------------------------------
//! @brief   �����������.
//! @see     txDialog::txDialog (const txDialog::Layout*)
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    public:
    txDialog();

//{-------------------------------------------------------------------------------------------
//! @brief   �����������.
//!
//! @param   layout  ����� ����������� ����
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    txDialog (const Layout* layout);

//{-------------------------------------------------------------------------------------------
//! @brief   ����������.
//}-------------------------------------------------------------------------------------------

    virtual ~txDialog() {};

//{-------------------------------------------------------------------------------------------
//! @brief   ������������� ������� ����� ����������� ����.
//!
//! @param   layout  ����� ����������� ����
//!
//! @return  ���������� �����.
//!
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*)
//! @see     txDialog::dialogBox()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    const Layout* setLayout (const Layout *layout);

//{-------------------------------------------------------------------------------------------
//! @brief   ������� ��������� ��������� ����������� ����.
//!
//! @param   _wnd     ����������
//! @param   _msg     ����� ���������
//! @param   _wParam  1-� �������� ��������� (WORD)
//! @param   _lParam  2-� �������� ��������� (DWORD)
//!
//! @return  � ����������� ������� false, ��������� ��. DialogProc
//!          � <a href=msdn.com>MSDN</a>.
//!
//!          ��� ������� ���� �������������� ��� ��������� ������� ����,
//!          ��� ��������� �� � ������� �������� TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @see     txDialog::dialogBox()
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

//{-------------------------------------------------------------------------------------------
//! @brief   ��������� ���������� ����.
//!
//! @param   layout   ����� ����������� ����. \n
//!                     ���� �� ������ - ������������ ��������, �������� txDialog::setLayout()
//!                     ��� ������������� txDialog::txDialog (const txDialog::Layout*).
//! @param   bufsize  ������ ������ ��� �������� ������� ������� (���� �� ������ - ������ ��
//!                     ���������)
//!
//! @return  ��������, ��������� � ������� EndDialog(). \n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    INT_PTR dialogBox (const Layout* layout = NULL, size_t bufsize = 0);

//{-------------------------------------------------------------------------------------------
//! @brief   ��������� ���������� ����.
//!
//! @param   resource  ������������� ����������� �������
//!
//! @return  ��������, ��������� � ������� EndDialog(). \n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource);

//{-------------------------------------------------------------------------------------------
//! @brief   �������� ����������� ����������� � �������� ������������.
//}-------------------------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//{-------------------------------------------------------------------------------------------
//! ��������� ���������� ������� (�� txDialog::dialogProc(), �.�. ������� ����
//! Win32 ������ ���� �����������).
//}-------------------------------------------------------------------------------------------

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//{-------------------------------------------------------------------------------------------
//! ������� ����� �������.
//}-------------------------------------------------------------------------------------------

    private:
    const Layout* layout_;
    };

//! @}
//}
//============================================================================================

//============================================================================================
//{          Dialogs: Message Map macros
//! @name    ������� ��� ���������� ����������� ����� ��������� (Message Map)
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����� ��������� (Message Map).
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define TX_BEGIN_MESSAGE_MAP()                                                     \
    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)  \
        {                                                                          \
        (void)_wnd; (void)_msg; (void)_wParam; (void)_lParam;                      \
                                                                                   \
        switch (_msg)                                                              \
            {                                                                      \
            case WM_NULL:

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����������� ��������� (Message handler) ����� ���������.
//!
//! @param   id  ������������� ���������
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ����� ������ (Command map) � ����� ���������.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define TX_COMMAND_MAP                                                             \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        if (_msg == WM_COMMAND) switch (LOWORD (_wParam))                          \
            {                                                                      \
            case 0:

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ����� ���������.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define TX_END_MESSAGE_MAP                                                         \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        return FALSE;                                                              \
        }

//! @}
//}
//============================================================================================

//============================================================================================
//{          Dialogs: txDialog example: txInputBox()
//! @name    ������ ������������� ������ �������: ������� txInputBox()
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ���� ������ � ��������� ����.
//!
//! @param   text     ����� � ��������
//! @param   caption  ��������� ����
//! @param   input    �������� ������ �� ���������
//!
//! @return  ��������� ������ (����������� ���������� �������).
//!
//! @warning ������������ ������ - �����������, � ����������� ��� ������ ������ �������.
//!          ���� txInputBox() ����� ���������� ��������� ���, �� ��� ���������� ������
//!          �� ���������� ���������� � ������ ������ ��� ������ <i>strcpy()</i>.
//! @see     txDialog, TX_BEGIN_MESSAGE_MAP, TX_BEGIN_COMMAND_MAP, TX_HANDLE, TX_END_MESSAGE_MAP
//! @usage
//! @code
//!          const char* name = txInputBox ("So what's ur name??!", "System", "Sorry I'm Vasya Pupkin");
//!          MessageBox (txWindow(), name, "Aaand nooowww.. the winner iiis...", 0);
//! @endcode
//}-------------------------------------------------------------------------------------------

const char* txInputBox (const char* text = NULL, const char* caption = NULL, const char* input = NULL);

const char* txInputBox (const char* text, const char* caption, const char* input)
    {
    //----------------------------------------------------------------------------------------
    // ���� �� ������� ���������, ���������� ������������ ���� �����-�� �������.
    // txGetModuleFileName() - ��� EXE-�����, �� ������, ���� ���-��� ��������� ������ ��������.
    //----------------------------------------------------------------------------------------

$   if (!text)    text    = "������� ������:";
$   if (!caption) caption = txGetModuleFileName (false);
$   if (!input)   input   = "";

    //----------------------------------------------------------------------------------------
    // �������������� ��������� �������. ��� ��������� � GetDlgItemText().
    // ���� ������ �������� �� �������, � ���������� ��������, �� ��� �������� � ��� �������������.
    // � ��� �� ��� - ������� �����, � ���������. ������� � ���, ��� � ������ ���� ����������������
    // ������ ��������� �������� � ������� ������. ������� ��� ������������� �� ��� ��� �����
    // ��������� �� ����� ����������, �����������. �� ��� ����������, ��� ��� ����� �����������
    // � txDialog::dialogBox() � _tx_DLGTEMPLATE_()... �_�
    //----------------------------------------------------------------------------------------

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    //----------------------------------------------------------------------------------------
    // ������� ������ (����) ������� � ���� ������� ��������.
    // � ������� ������� ������� ����� � ��������� txDialog::Layout � �������� �� ������
    // txDialog ���� ������ ���������� ����� �� �������� ������� ������� � .rc - �����.
    // ��. �������� ���������� rc-����� � ������������ �� Win32 (MSDN, http://msdn.com).
    //----------------------------------------------------------------------------------------

$   txDialog::Layout layout[] =

    //----------------------+-----------+-------------+-----------------+---------------------
    //     ��� ��������     | ���       | ����������- |   ����������    | ����� ���������
    //     �������          | ��������  | ���, ������-|-----------------| (��. �������� ��������� ������� � MSDN).
    //                      |           | ��� � ���   | X | Y |���.|���.|
    //----------------------+-----------+-------------+---+---+----+----+---------------------
    //                      |           |             |   |   |    |    |
        {{ txDialog::DIALOG,   caption,   0,             0,  0, 240,  85                                                     },
         { txDialog::STATIC,   text,      ID_TEXT_,     10, 10, 150,  40, SS_LEFT                                            },
         { txDialog::EDIT,     input,     ID_INPUT_,    10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP  },
         { txDialog::BUTTON,   "&OK",     IDOK,        180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP  },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL,    180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP  },
         { txDialog::END                                                                                                     }};

    //----------------------------------------------------------------------------------------
    // ����� ������� ��� InputBox. ����������, �.�. ����� ��� ���� �������.
    // ����� � �������� ��� ������� ������ ����� (str) � ������� ������� ����������� ����,
    // ��������� Win32 (��� ��������� ��������� TX_BEGIN_MESSAGE_MAP � �������). ����� �� ������
    // ����������� ������, �� ����� ������� ������� �������� ������ � ���������� ������� ���������,
    // � str ��������� ��������� ���� (��� ���������� �� ����� ����� DialogBoxParam � ����������
    // ��� � ����� �� ����� ��������� WM_INITDIALOG).
    //----------------------------------------------------------------------------------------

    struct inputDlg : txDialog
        {
        char str [1024];

        //------------------------------------------------------------------------------------

        inputDlg() :
            str()                               // ��������� ���� ������. �� �������� �� ������
            {                                   //     ������������, ������� ��� ���:
$           memset (str, 0, sizeof (str) - 1);  // ��������� ���� ������
            }

        //------------------------------------------------------------------------------------

        TX_BEGIN_MESSAGE_MAP()    // ����� ���������. �� ����� ���� ��� ������ ������� �������.

            TX_COMMAND_MAP        // ����� �������������� WM_COMMAND. �� ����� ���� ��� switch.

                //----------------------------------------------------------------------------
                // ��� ������� ������ OK �������� ������ �� ���� ����� � ���� ���������� str,
                // �.�. ����� �������� ������� ������ ����� ����� � ����� ��� �� ��� ��������.
                // ���� ������ �� ����� ���� ������������ � case �� ��������� switch.
                // _wnd - ��� �������� ������� �������, ��. ����������� ������� TX_BEGIN_MESSAGE_MAP().
                //----------------------------------------------------------------------------

                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP

        //------------------------------------------------------------------------------------
        // ����� ����������� ������ �������
        //------------------------------------------------------------------------------------

        };

    //----------------------------------------------------------------------------------------
    // ������� �������, ����� ����� �� ������.
    // �� ����� ��� ���������� "���������� ��������", ��� ����� � ��� ���� �� ������� ��������� -
    // �������. �� ����� ���� ��� ������� ������� ����� #undef. ����� ����������� �� ���������
    // �������, � ��� ����� ������������� �� _. ����� �������� ����� �� ����������� ���� ��� �����
    // ���� ���, ����������, ����� ��� �� �����.
    //----------------------------------------------------------------------------------------

    #undef ID_TEXT_
    #undef ID_INPUT_

    //----------------------------------------------------------------------------------------
    // ��� ����������� ������, ������ ��� ������ � ��� ������ ���� ����� ���������� �������.
    //----------------------------------------------------------------------------------------

$   static inputDlg dlg;

    //----------------------------------------------------------------------------------------
    // �������� layout � ��������� ���� �������
    //----------------------------------------------------------------------------------------

$   dlg.dialogBox (layout);

    //----------------------------------------------------------------------------------------
    // ���������� ����� ������ �� ������������ �������. ��� ����� ������, ������ ��� �����������
    // ������ �� ����� ��� ������ �� ������� � ������ � ���, ��������������, ����. �����
    // ������������� ���������� ���������� ������������� �����, �� ����� � ��������� �������.
    //----------------------------------------------------------------------------------------

$   return dlg.str;
    }

//! @}
//}
//============================================================================================

//}
//============================================================================================

//============================================================================================
//{          TXLIB IMPLEMENTATION
//           ���������� ������� ����������
//============================================================================================
//! @cond INTERNAL

//============================================================================================
//{          [Internal] Function prototypes, macros and constants
//           ��������� ���������� �������, ������� � ���������
//============================================================================================

int              _txInitialize();
void             _txOnExit();

HWND             _txCanvas_CreateWindow (CREATESTRUCT* from);
inline bool      _txCanvas_OK();

int              _txCanvas_SetRefreshLock (int count);

bool             _txCanvas_OnCREATE     (HWND wnd);
bool             _txCanvas_OnDESTROY    (HWND wnd);
bool             _txCanvas_OnCLOSE      (HWND);
bool             _txCanvas_OnPAINT      (HWND wnd);
bool             _txCanvas_OnCHAR       (HWND wnd, WPARAM ch);
bool             _txCanvas_OnTIMER      (HWND wnd, WPARAM id);
bool             _txCanvas_OnMOUSEMOVE  (HWND wnd, WPARAM buttons, LPARAM coords);
bool             _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd);
bool             _txCanvas_OnCmdABOUT   (HWND wnd, WPARAM cmd);

void             _txCanvas_ThreadProc   (void* data);
LRESULT CALLBACK _txCanvas_WndProc      (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

HDC              _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL) _TX_CHECK_RESULT;
bool             _txBuffer_Delete (HDC* dc);
bool             _txBuffer_Select (HGDIOBJ obj, HDC dc = txDC());

HWND             _txConsole_Attach (bool forceRealloc);
bool             _txConsole_OK();
bool             _txConsole_Detach (bool restorePos);
bool             _txConsole_Draw (HDC dc);
bool             _txConsole_SetUnicodeFont();

bool            _txIsParentWaitable (DWORD* parentPID);
PROCESSENTRY32* _txFindProcess (unsigned pid = GetCurrentProcessId()) _TX_CHECK_RESULT;
bool            _txKillProcess (DWORD pid);

bool            _txCreateShortcut (const char shortcutName[],
                                   const char fileToLink[], const char args[] = NULL, const char workDir[] = NULL,
                                   const char description[] = NULL, int cmdShow = SW_SHOWNORMAL,
                                   const char iconFile[] = NULL, int iconIndex = 0, int fontSize = 0,
                                   COORD bufSize = ZERO (COORD), COORD wndSize = ZERO (COORD), COORD wndOrg = ZERO (COORD));

void*           _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                                        WORD controls, short x, short y, short cx, short cy,
                                        const char caption[], const char font[], WORD fontsize,
                                        HANDLE menu = NULL) _TX_CHECK_RESULT;
void*           _tx_DLGTEMPLATE_Add    (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                                        short x, short y, short cx, short cy,
                                        WORD id, const char wclass[], const char caption[]) _TX_CHECK_RESULT;

bool            _txError (const char file[], int line, const char func[],
                          DWORD getlasterror_value, int errno_value, int doserrno_value,
                          const char msg[], ...) _TX_CHECK_FORMAT (7);

void            _txOnSignal (int signal = 0, int fpe = 0);
void            _txOnTerminate();
void            _txOnUnexpected();

//--------------------------------------------------------------------------------------------

FARPROC      _txDllImport (const char dllFileName[], const char funcName[], bool required = true) _TX_CHECK_RESULT;

#define      _TX_SAFECALL(func)     (func) && func

//--------------------------------------------------------------------------------------------

// These are macros for __FILE__ and __LINE__ to work properly.
// Warning: if failed, _txAssert() aborts the program by setting '\a' flag in TX_ERROR().

#if !defined (NDEBUG)
    #define  _txAssertOK()          ( txOK() || TX_ERROR ("\a" "���� ��������� �� �������") )
#else
    #define  _txAssertOK()          ( 0 )
#endif

// This is a macro because cond is an expression and not always a function. Lack of lambdas in pre-C++0x.

#define      _txWaitFor(cond)       { for (DWORD _t = GetTickCount() + _TX_TIMEOUT; \
                                           !(cond) && GetTickCount() < _t;          \
                                           Sleep (_TX_WINDOW_UPDATE_INTERVAL)) ; }

// To suppress warnings in assert() and TX_ERROR() macros ("right-hand of comma operator has no effect")

template <typename T>
inline T     _txNOP (T value)       { return value; }

//--------------------------------------------------------------------------------------------

const int    _TX_IDM_ABOUT          = 40000;  // �������������� ���������� ���� ����
const int    _TX_IDM_CONSOLE        = 40001;

//}
//============================================================================================

//============================================================================================
//{          [Internal] DLL functions import
//! @name    ������ ������� ���������
//============================================================================================
//! @{

FARPROC _txDllImport (const char dllFileName[], const char funcName[], bool required /*= true*/)
    {
    HMODULE   dll = GetModuleHandle (dllFileName);
    if (!dll) dll = LoadLibrary     (dllFileName);
    if (!dll && required)  TX_ERROR ("\a" "Cannot load library \"%s\"" _ dllFileName);

    if (!dll) return NULL;

    FARPROC addr = GetProcAddress (dll, funcName);
    if (!addr && required) TX_ERROR ("\a" "Cannot import \"%s\" from library \"%s\""_ funcName _ dllFileName);

    return addr;
    }

//--------------------------------------------------------------------------------------------
//           Import helpers
//           ����� �����������
//--------------------------------------------------------------------------------------------

#define _TX_DLLIMPORT(     lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txDllImport (lib ".dll", #name, true)

#define _TX_DLLIMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txDllImport (lib ".dll", #name, false)

//--------------------------------------------------------------------------------------------
// Some IDEs don't link with these libs by default in console projects, so do sunrise by hand. :(
//{ <tears>

namespace Win32 {

#ifdef _MSC_VER_6
struct CONSOLE_FONT_INFO;
#endif

struct NT_CONSOLE_PROPS;
struct CONSOLE_FONT_INFOEX;

_TX_DLLIMPORT     ("GDI32",    int,      GetDeviceCaps,          (HDC dc, int index));
_TX_DLLIMPORT     ("GDI32",    HDC,      CreateCompatibleDC,     (HDC dc));
_TX_DLLIMPORT     ("GDI32",    HBITMAP,  CreateCompatibleBitmap, (HDC dc, int width, int height));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  GetStockObject,         (int object));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  SelectObject,           (HDC dc, HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  GetCurrentObject,       (HDC dc, UINT objectType));
_TX_DLLIMPORT     ("GDI32",    int,      GetObjectA,             (HGDIOBJ obj, int bufsize, LPVOID buffer));
_TX_DLLIMPORT     ("GDI32",    DWORD,    GetObjectType,          (HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    BOOL,     DeleteDC,               (HDC dc));
_TX_DLLIMPORT     ("GDI32",    BOOL,     DeleteObject,           (HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetTextColor,           (HDC dc, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetBkColor,             (HDC dc, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    int,      SetBkMode,              (HDC dc, int bkMode));
_TX_DLLIMPORT     ("GDI32",    HFONT,    CreateFontA,            (int height, int width, int escapement, int orientation,
                                                                  int weight, DWORD italic, DWORD underline, DWORD strikeout,
                                                                  DWORD charSet, DWORD outputPrec, DWORD clipPrec,
                                                                  DWORD quality, DWORD pitchAndFamily, LPCTSTR face));
_TX_DLLIMPORT     ("GDI32",    int,      EnumFontFamiliesExA,    (HDC dc, LPLOGFONT logFont, FONTENUMPROC enumProc,
                                                                  LPARAM lParam, DWORD reserved));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetPixel,               (HDC dc, int x, int y, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    COLORREF, GetPixel,               (HDC dc, int x, int y));
_TX_DLLIMPORT     ("GDI32",    HPEN,     CreatePen,              (int penStyle, int width, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    HBRUSH,   CreateSolidBrush,       (COLORREF color));
_TX_DLLIMPORT     ("GDI32",    BOOL,     MoveToEx,               (HDC dc, int x, int y, LPPOINT point));
_TX_DLLIMPORT     ("GDI32",    BOOL,     LineTo,                 (HDC dc, int x, int y));
_TX_DLLIMPORT     ("GDI32",    BOOL,     Polygon,                (HDC dc, CONST POINT points[], int count));
_TX_DLLIMPORT     ("GDI32",    BOOL,     Rectangle,              (HDC dc, int x0, int y0, int x1, int y1));
_TX_DLLIMPORT     ("GDI32",    BOOL,     Ellipse,                (HDC dc, int x0, int y0, int x1, int y1));
_TX_DLLIMPORT     ("GDI32",    BOOL,     Arc,                    (HDC dc, int x0, int y0, int x1, int y1,
                                                                  int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    BOOL,     Pie,                    (HDC dc, int x0, int y0, int x1, int y1,
                                                                  int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    BOOL,     Chord,                  (HDC dc, int x0, int y0, int x1, int y1,
                                                                  int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    BOOL,     TextOutA,               (HDC dc, int x, int y, LPCTSTR string, int length));
_TX_DLLIMPORT     ("GDI32",    UINT,     SetTextAlign,           (HDC dc, UINT mode));
_TX_DLLIMPORT     ("GDI32",    BOOL,     GetTextExtentPoint32A,  (HDC dc, LPCTSTR string, int length, LPSIZE size));
_TX_DLLIMPORT     ("GDI32",    BOOL,     ExtFloodFill,           (HDC dc, int x, int y, COLORREF color, UINT type));
_TX_DLLIMPORT     ("GDI32",    BOOL,     BitBlt,                 (HDC dest, int xDest, int yDest, int width, int height,
                                                                  HDC src,  int xSrc,  int ySrc,  DWORD rOp));
_TX_DLLIMPORT     ("GDI32",    int,      SetDIBitsToDevice,      (HDC dc, int xDest, int yDest, DWORD width, DWORD height,
                                                                  int xSrc, int ySrc, UINT startLine, UINT numLines,
                                                                  const VOID* data, const BITMAPINFO* info, UINT colorUse));
_TX_DLLIMPORT     ("GDI32",    BOOL,     PatBlt,                 (HDC dc, int x0, int y0, int width, int height, DWORD rOp));
_TX_DLLIMPORT     ("GDI32",    int,      SetROP2,                (HDC dc, int mode));
_TX_DLLIMPORT     ("GDI32",    HRGN,     CreateRectRgn,          (int x0, int y0, int x1, int y1));
_TX_DLLIMPORT     ("GDI32",    BOOL,     GetBitmapDimensionEx,   (HBITMAP bitmap, LPSIZE dimensions));
_TX_DLLIMPORT     ("User32",   int,      DrawTextA,              (HDC dc, LPCTSTR text, int length, LPRECT rect, UINT format));
_TX_DLLIMPORT     ("User32",   HANDLE,   LoadImageA,             (HINSTANCE inst, LPCTSTR name, UINT type,
                                                                  int sizex, int sizey, UINT mode));
_TX_DLLIMPORT     ("WinMM",    BOOL,     PlaySound,              (LPCSTR sound, HMODULE mod, DWORD mode));

_TX_DLLIMPORT_OPT ("MSImg32",  BOOL,     TransparentBlt,         (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                                  HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                                  UINT transparentColor));
_TX_DLLIMPORT_OPT ("MSImg32",  BOOL,     AlphaBlend,             (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                                  HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                                  BLENDFUNCTION blending));

_TX_DLLIMPORT     ("Kernel32", HWND,     GetConsoleWindow,       (void));
_TX_DLLIMPORT     ("Kernel32", BOOL,     SetConsoleFont,         (HANDLE console, DWORD fontIndex));
_TX_DLLIMPORT     ("Kernel32", BOOL,     GetConsoleFontInfo,     (HANDLE console, BOOL fullScreen, DWORD numFonts, CONSOLE_FONT_INFO* fontsInfo));
_TX_DLLIMPORT     ("Kernel32", DWORD,    GetNumberOfConsoleFonts,(void));
_TX_DLLIMPORT     ("Kernel32", COORD,    GetConsoleFontSize,     (HANDLE hConsoleOutput, DWORD nFont));
_TX_DLLIMPORT_OPT ("Kernel32", BOOL,     GetCurrentConsoleFont,  (HANDLE console, BOOL maxWnd, CONSOLE_FONT_INFO* curFont));
_TX_DLLIMPORT_OPT ("Kernel32", BOOL,     GetCurrentConsoleFontEx,(HANDLE console, BOOL maxWnd, CONSOLE_FONT_INFOEX* curFont));
_TX_DLLIMPORT_OPT ("Kernel32", BOOL,     SetCurrentConsoleFontEx,(HANDLE console, BOOL maxWnd, CONSOLE_FONT_INFOEX* curFont));

_TX_DLLIMPORT     ("OLE32",    HRESULT,  CoInitialize,           (void*));
_TX_DLLIMPORT     ("OLE32",    HRESULT,  CoCreateInstance,       (REFCLSID clsid, LPUNKNOWN, DWORD, REFIID iid, PVOID* value));
_TX_DLLIMPORT     ("OLE32",    void,     CoUninitialize,         (void));

_TX_DLLIMPORT     ("Shell32",  HINSTANCE,ShellExecuteA,          (HWND wnd, LPCTSTR operation, LPCTSTR file,
                                                                  LPCTSTR parameters, LPCTSTR directory, INT showCmd));

//--------------------------------------------------------------------------------------------
// Another issue, some of structs, consts and interfaces aren't defined in MinGW some ealry headers.
// Copied from Windows SDK 7.0a.

#ifndef AC_SRC_ALPHA
#define AC_SRC_ALPHA          0x01
#endif

#ifndef SMTO_ERRORONEXIT
#define SMTO_ERRORONEXIT      0x0020
#endif

#ifndef NT_CONSOLE_PROPS_SIG
#define NT_CONSOLE_PROPS_SIG  0xA0000002
#endif

#pragma pack (push, 1)

#ifdef _MSC_VER_6

struct CONSOLE_FONT_INFO
    {
    DWORD  nFont;
    COORD  dwFontSize;
    };

#endif

struct CONSOLE_FONT_INFOEX
    {
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
    };

struct DATABLOCK_HEADER
    {
    DWORD cbSize;
    DWORD dwSignature;
    };

struct NT_CONSOLE_PROPS
    {
    DATABLOCK_HEADER dbh;

    WORD  wFillAttribute;
    WORD  wPopupFillAttribute;
    COORD dwScreenBufferSize;
    COORD dwWindowSize;
    COORD dwWindowOrigin;
    DWORD nFont;
    DWORD nInputBufferSize;
    COORD dwFontSize;
    UINT  uFontFamily;
    UINT  uFontWeight;
    WCHAR FaceName[LF_FACESIZE];
    UINT  uCursorSize;
    BOOL  bFullScreen;
    BOOL  bQuickEdit;
    BOOL  bInsertMode;
    BOOL  bAutoPosition;
    UINT  uHistoryBufferSize;
    UINT  uNumberOfHistoryBuffers;
    BOOL  bHistoryNoDup;

    COLORREF ColorTable[16];
    };

#pragma pack (pop)

#undef  INTERFACE
#define INTERFACE IShellLinkDataList

DECLARE_INTERFACE_ (IShellLinkDataList, IUnknown)
    {
    // *** IUnknown methods ***
    STDMETHOD (QueryInterface)  (THIS_ REFIID iid, void** value)    PURE;
    STDMETHOD_(ULONG, AddRef)   (THIS)                              PURE;
    STDMETHOD_(ULONG, Release)  (THIS)                              PURE;

    // *** IShellLinkDataList methods ***
    STDMETHOD (AddDataBlock)    (THIS_ void* dataBlock)             PURE;
    STDMETHOD (CopyDataBlock)   (THIS_ DWORD sig, void** dataBlock) PURE;
    STDMETHOD (RemoveDataBlock) (THIS_ DWORD sig)                   PURE;
    STDMETHOD (GetFlags)        (THIS_ DWORD* flags)                PURE;
    STDMETHOD (SetFlags)        (THIS_ DWORD  flags)                PURE;

    private:
    virtual ~IShellLinkDataList();
    };

const GUID IID_IShellLinkDataList = {0x45e2b4ae, 0xb1c3, 0x11d0, {0xb9,0x2f,0x00,0xa0,0xc9,0x03,0x12,0xe1}};
const GUID IID_IPersistFile       = {0x0000010b, 0x0000, 0x0000, {0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

#undef  INTERFACE

}  // namespace Win32
using namespace Win32;

//} </tears>

//! @}
//}
//============================================================================================

//============================================================================================
//{          [Internal] Global data
//! @name    ���������� ������
//           �� ��������� � ��������� ��� �����, ��� ����, ����� ��� ������� �� ���� :)
//============================================================================================
//! @{

unsigned         _txMainThreadId        = 0;      // ID ������, ��� ����������� main()
unsigned         _txCanvas_ThreadId     = 0;      // ID ������, ���������� ����� ������ TXLib

HWND             _txCanvas_Window       = NULL;   // ���������� ���� ������ TXLib

HDC              _txCanvas_BackBuf[2]   = {NULL,  // [0] Main TXLib memory DC, where user picture lies
                                           NULL}; // [1] Intermediate buffer for console text, also
                                                  //     used in WM_PAINT handling when user frozen
                                                  //     screen auto-update by txBegin()... call.

CRITICAL_SECTION _txCanvas_LockBackBuf  = {0};    // Prevent simultaneous access to back buffer,
                                                  //   see txLock()/txUnlock()

UINT             _txCanvas_RefreshTimer = 0;      // Timer to redraw TXLib window

int              _txCanvas_RefreshLock  = 0;      // Blocks automatic on-timer canvas update,
                                                  //   see txBegin()/txEnd()

bool             _txConsole_IsBlinking  = true;   // To blink or not to blink, that is the question.
bool             _txConsole_Active      = true;
RECT             _txConsole_Pos         = {0};

bool             _txRunning             = false;  // Indicate that main() is still running
bool             _txExit                = false;  // Indicate that exit() is active

POINT            _txMousePos            = {0};
int              _txMouseButtons        =  0;

WNDPROC          _txAltWndProc          = NULL;   // �������������� ������� �������. ��. txSetWindowHandler().

const char*      _txSrcLocFile          = NULL;
int              _txSrcLocLine          = 0;
const char*      _txSrcLocFunc          = NULL;

int              _txStaticInitialized   = _TX_NOINIT || _txInitialize();

//! @}
//}
//============================================================================================

//============================================================================================
//{          TXLib engine init/check/cleanup
//! @name    �������������/��������/���������� TXLib
//============================================================================================
//! @{

//--------------------------------------------------------------------------------------------
//{          Static initialization
//--------------------------------------------------------------------------------------------

int _txInitialize()
    {
    #ifndef NDEBUG
    OutputDebugString ("\n");
    OutputDebugString ("The Dumb Artist Library - " _TX_VERSION " " _TX_AUTHOR ": "
                       "\"" __FILE__ "\"" _TX_NAME
                       "compiled " __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode\n");
    OutputDebugString ("\n");
    #endif

$   _txMainThreadId = GetCurrentThreadId();

$   _txOnSignal();
$   SetErrorMode (SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);

    #ifndef _MSC_VER_6
$   std::set_unexpected (_txOnUnexpected);
$   std::set_terminate  (_txOnTerminate);
    #endif

$   HWND console = _txConsole_Attach (true);
$   if (console) SetWindowTextA (console, txGetModuleFileName (false));

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   atexit (_txOnExit);

$   (void) _txStaticInitialized;        // Just for warning "defined but not used" suppression
$   (void) Win32::SetDIBitsToDevice;
$   (void) Win32::CreateRectRgn;
$   (void) Win32::GetBitmapDimensionEx;

$   return 1;
    }

//}

//--------------------------------------------------------------------------------------------

HWND txCreateWindow (int sizeX, int sizeY, unsigned style /*= WS_SYSMENU | 1*/)
    {
$   if (txOK()) return 0;

$   if (!_txStaticInitialized) _txStaticInitialized = _txInitialize();

$   _txRunning = false;

$   if (style & 1) { sizeX *= -1; sizeY *= -1; }

$   static CREATESTRUCT from = { NULL, NULL, NULL, NULL,
                                 sizeY, sizeX, CW_USEDEFAULT, CW_USEDEFAULT,
                                 style & ~1, NULL, NULL, 0 };

    // In Thread, where REAL creation lies...

$   HANDLE thread = (HANDLE) _beginthread (_txCanvas_ThreadProc, 0, &from);
$       if (thread == (HANDLE)(-1)) return TX_DEBUG_ERROR ("\a" "Cannot start canvas thread"), (HWND)NULL;

$   _txWaitFor (_txRunning);
$       if (!_txRunning || !txOK()) return TX_DEBUG_ERROR ("\a" "Cannot create canvas window"),(HWND)NULL;

$   errno = _doserrno = 0;
$   SetLastError (0);

$   return txWindow();
    }

//--------------------------------------------------------------------------------------------

bool txSetDefaults()
    {
$   _txAssertOK();

$   txUpdateWindow (false);
$   txLock();

//{  Set defaults for graphics layer

$   RECT r = {0};

$   GetClientRect (_txCanvas_Window,  &r) asserted;
$   SIZE szCanvas = { r.right - r.left, r.bottom - r.top };

$   GetClientRect (Win32::GetConsoleWindow(), &r) asserted;
$   SIZE szCon    = { r.right - r.left, r.bottom - r.top };

$   _txBuffer_Select (GetStockObject (WHITE_PEN),   txDC()) asserted;
$   _txBuffer_Select (GetStockObject (WHITE_BRUSH), txDC()) asserted;
$   _txBuffer_Select (CreateFont (szCon.cy/25, szCon.cx/80, 0, 0,
                                  FW_REGULAR, FALSE, FALSE, FALSE, RUSSIAN_CHARSET,
                                  OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, DEFAULT_PITCH, _TX_CONSOLE_FONT),
                                  txDC()) asserted;

$   (Win32::SetTextColor (txDC(), TX_WHITE) != CLR_INVALID) asserted;
$    Win32::SetBkMode    (txDC(), TRANSPARENT)              asserted;

$    Win32::SetROP2      (txDC(), R2_COPYPEN)               asserted;

//}

//{  Set defaults for console  layer

$   _txConsole_Attach (false);

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}, {0}, 0, {0, 0, 80, 25}, {80, 25}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);

$   SIZE szChr  = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
                    (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

$   SIZE szFont = { (short) ((1.0 * szCon.cx / szChr.cx) / (1.0 * szCon.cx / szCanvas.cx) + 0.5),
                    (short) ((1.0 * szCon.cy / szChr.cy) / (1.0 * szCon.cy / szCanvas.cy) + 0.5) };

$   _txBuffer_Select (txFontExist (_TX_CONSOLE_FONT)? CreateFont (szFont.cy, szFont.cx, 0, 0,
                                                                  FW_REGULAR, FALSE, FALSE, FALSE, RUSSIAN_CHARSET,
                                                                  OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                                                  DEFAULT_QUALITY, FIXED_PITCH,
                                                                  _TX_CONSOLE_FONT)
                                                    :
                                                      GetStockObject (SYSTEM_FIXED_FONT),
                      _txCanvas_BackBuf[1]) asserted;
//}

$   txUnlock();
$   txUpdateWindow (true);

    return true;
    }

//--------------------------------------------------------------------------------------------

inline
bool txOK()
    {
$   return _txCanvas_OK();
    }

//--------------------------------------------------------------------------------------------

void _txOnExit()
    {
$   if (!_txStaticInitialized) return;

$   _txRunning = false;
$   _txConsole_IsBlinking = false;

$   HWND canvas  = _txCanvas_Window;
$   HWND console = GetConsoleWindow();

$   HWND wnd     = (canvas)? canvas : console;
$   int isMaster = (canvas)? (GetWindowLong (canvas, GWL_STYLE) & WS_SYSMENU) : true;

$   static char title [_TX_BUFSIZE] = "";
$   if (wnd) GetWindowText (wnd, title, sizeof (title));
$   strncat_s (title, " [���������]", sizeof (title) - 1);
$   if (wnd) SetWindowText (wnd, title);

$   DWORD parent = 0;
$   bool waitable = _txIsParentWaitable (&parent);
$   bool waitKey  = !waitable || _TX_ALLOW_KILL_PARENT;

$   if (isMaster && !_txExit && GetCurrentThreadId() == _txMainThreadId)
        {
$       if (!canvas && waitKey)
            printf ("\n" "[������� ����� ������� ��� ����������]");

$       while (_kbhit()) (void)_getch();

$       for (int i = 1; ; i++)
            {
$           if (_kbhit()) break;

            if ( canvas && !_txCanvas_ThreadId) break;
            if (!canvas && !waitKey)            break;

            Sleep (_TX_WINDOW_UPDATE_INTERVAL);

            if (!(i % 100500))
                printf ("\r" "[������� �� �����-������ ������� ��� ����� ����������]");
            }

$       while (_kbhit()) (void)_getch();

$       printf ("\n");
        }

$   if (_txCanvas_Window) SendNotifyMessage (_txCanvas_Window, WM_DESTROY, 0, 0);

$   _txWaitFor (!_txCanvas_Window);

$   if (!_txCanvas_Window)
        { $ DeleteCriticalSection (&_txCanvas_LockBackBuf); }

$   _txConsole_Detach (!waitable);

$   if (waitable && _TX_ALLOW_KILL_PARENT) _txKillProcess (parent);

$   _txStaticInitialized = false;

    #ifndef NDEBUG
    OutputDebugString ("\n");
    OutputDebugString (_TX_VERSION ": \"" __FILE__ "\"" _TX_NAME "-- FINISHED\n");
    OutputDebugString ("\n");
    #endif
    }

//-----------------------------------------------------------------------------

bool _txIsParentWaitable (DWORD* parentPID)
    {
$   PROCESSENTRY32* info = _txFindProcess();
$   if (!info) return false;

$   info = _txFindProcess (info->th32ParentProcessID);
$   if (!info) return false;

$   char parent [MAX_PATH] = "";
$   strncpy_s (parent, info->szExeFile, sizeof (parent) - 1);
$   if (parentPID) *parentPID = info->th32ProcessID;

$   info = _txFindProcess (info->th32ParentProcessID);  // info: grandparent

$   static char list[_TX_BUFSIZE] = _TX_WAITABLE_PARENTS;
$   char* ctx = NULL;

$   for (char* p = strtok_s (list, ", ", &ctx); p; p = strtok_s (NULL, ", ", &ctx))
        {
$       char* gp = strchr (p, ':');

$       if (gp)
            {
$           *gp++ = 0;

$           if (_stricmp (p, parent) != 0) continue;

$           if (info) if (_stricmp (gp, info->szExeFile) == 0)  // Was &&, but OMG MSVC /analyze..
                { $ return true; }
            }
        else
            {
$           if (_stricmp (p, parent) == 0)
                { $ return true; }
            }
        }

$   return false;
    }

//-----------------------------------------------------------------------------

PROCESSENTRY32* _txFindProcess (unsigned pid /*= GetCurrentProcessId()*/)
    {
$   static PROCESSENTRY32 info = { sizeof (info) };
$   if (!pid) return &info;

$   HANDLE sshot = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, 0); assert (sshot);
$   if (!sshot) return NULL;

$   for (Process32First (sshot, &info); Process32Next (sshot, &info); )
        if (info.th32ProcessID == pid) break;

$   CloseHandle (sshot);

$   return &info;
    }

//-----------------------------------------------------------------------------

// You are here, little hacker?

bool _txKillProcess (DWORD pid)
    {
$   if (!pid) return false;

$   HANDLE token = INVALID_HANDLE_VALUE;
$   OpenProcessToken (GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token) asserted;

$   LUID luid = {0};
$   LookupPrivilegeValue (NULL, SE_DEBUG_NAME, &luid) asserted;

$   TOKEN_PRIVILEGES priv = { 1, {{{ luid.LowPart, luid.HighPart}, SE_PRIVILEGE_ENABLED }}};
$   TOKEN_PRIVILEGES old  = {0};

$   DWORD oldSz = 0;
$   AdjustTokenPrivileges (token, false, &priv, sizeof (priv), &old, &oldSz) asserted;

$   HANDLE proc = OpenProcess (PROCESS_ALL_ACCESS, 0, pid);
$   if (!proc) return false;

$   bool ok = !!TerminateProcess (proc, 0);
$   CloseHandle (proc);

$   return ok;
    }

//--------------------------------------------------------------------------------------------

const char* txGetModuleFileName (bool fileNameOnly /*= true*/)
    {
$   static char name[MAX_PATH] = "";

$   if (!*name) GetModuleFileName (NULL, name, sizeof (name) - 1) asserted;
$   if (fileNameOnly) return name;

$   static char fullName[MAX_PATH] = "";
$   strncpy_s (fullName, name, sizeof (fullName) - 1);

$   char* title = strrchr (fullName, '\\'); assert (title);

    #ifndef _MSC_VER_6

$   char* ext   = strrchr (fullName,  '.'); assert (ext);
$   if (!ext) ext = fullName + strlen (fullName);

$   strncpy_s ((char(&)[sizeof (fullName)]) (*ext),       // In size we trust
               _TX_NAME "- TXLib",
               sizeof (fullName) - (ext - fullName) - 1); // ...don't worry about it
    #endif

$   return title + 1;
    }

//! @}
//}
//============================================================================================

//============================================================================================
//{          [Internal] TXLib window functions      (_txCanvas...)
//! @name    ������� ���� TXLib                     (_txCanvas...)
//============================================================================================

void _txCanvas_ThreadProc (void* data)
    {
$   _txCanvas_ThreadId = GetCurrentThreadId();

$   if (!data) return;

$   _txCanvas_Window = _txCanvas_CreateWindow ((CREATESTRUCT*) data);
$       if (!_txCanvas_Window) { TX_DEBUG_ERROR ("\a" "Cannot create canvas"); return; }

$   bool masterWnd = !!(GetWindowLong (txWindow(), GWL_STYLE) & WS_SYSMENU);

    #ifndef NDEBUG
    OutputDebugString (_TX_VERSION _TX_NAME "-- STARTED\n");
    #endif

$   _txRunning = true;

$   MSG msg = {0};
$   while (GetMessage (&msg, NULL, 0, 0))
        {
$       TranslateMessage (&msg);
$       DispatchMessage  (&msg);
$       Sleep (0);
        }

$   if (_txRunning && masterWnd)  // Master window is destroyed but main() is still running.
        {                         // No chances for good termination, so use exit().
$       exit ((int)(ptrdiff_t) msg.wParam);
        }

    #ifndef NDEBUG
    OutputDebugString (_TX_VERSION _TX_NAME "-- STOPPED\n");
    #endif

$   _txCanvas_ThreadId = 0;
    }

//--------------------------------------------------------------------------------------------

HWND _txCanvas_CreateWindow (CREATESTRUCT* from)
    {
$   if (!from) return false;

$   static char className[_TX_BUFSIZE] = "";
$   _snprintf_s (className, sizeof (className) - 1,
                 ">>>>>>>>>> " _TX_VERSION "  " __FILE__ _TX_NAME " WndClass %08X <<<<<<<<<<",
                 GetTickCount());

$   WNDCLASSEX wc    = {0};
$   wc.cbSize        = sizeof (wc);
$   wc.style         = CS_HREDRAW | CS_VREDRAW;
$   wc.lpfnWndProc   = _txCanvas_WndProc;
$   wc.hInstance     = NULL;
$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) GetStockObject (HOLLOW_BRUSH);
$   wc.lpszClassName = className;

$   ATOM wndclass = RegisterClassEx (&wc);
$       if (!wndclass) return TX_DEBUG_ERROR ("RegisterClass (\"%s\") failed"_ className), (HWND) NULL;

$   int centered = false;
$   if (from->cx < 0 && from->cy < 0) { from->cx *= -1; from->cy *= -1; centered = true; }

$   SIZE scr     = { GetSystemMetrics (SM_CXSCREEN),     GetSystemMetrics (SM_CYSCREEN)     };
$   SIZE frame   = { GetSystemMetrics (SM_CXFIXEDFRAME), GetSystemMetrics (SM_CYFIXEDFRAME) };
$   SIZE caption = { 0, GetSystemMetrics (SM_CYCAPTION) };
$   SIZE size    = { from->cx + 2*frame.cx, from->cy + 2*frame.cy + caption.cy };
$   POINT center = { scr.cx / 2, scr.cy / 2 };

$   HWND console = GetConsoleWindow();
$   GetWindowRect (console, &_txConsole_Pos);

$   if (!centered)
        {
$       center.x = (_txConsole_Pos.right  + _txConsole_Pos.left) / 2;
$       center.y = (_txConsole_Pos.bottom + _txConsole_Pos.top)  / 2;
        }

$   _txCanvas_Window = CreateWindowEx (from->dwExStyle, className,
                                       from->lpszName? from->lpszName : txGetModuleFileName (false),
                                       from->style | WS_POPUP | WS_BORDER | WS_CAPTION,
                                       center.x - size.cx/2, center.y - size.cy/2, size.cx, size.cy,
                                       NULL, from->hMenu, NULL, from->lpCreateParams);

$   if (!_txCanvas_Window) return TX_DEBUG_ERROR ("Cannot create canvas: CreateWindowEx (\"%s\") failed"_
                                                   className), (HWND) NULL;
$   if (console)
        { $ SetWindowPos (console, HWND_NOTOPMOST, center.x - size.cx*2/5, center.y - size.cy*2/5, 0, 0,
                          SWP_NOSIZE | SWP_NOACTIVATE | _TX_CONSOLE_MODE) asserted; }

$   ShowWindow          (_txCanvas_Window, SW_SHOW);
$   SetForegroundWindow (_txCanvas_Window);
$   UpdateWindow        (_txCanvas_Window);

$   HMENU menu = GetSystemMenu (_txCanvas_Window, false);
$   if (!menu) return _txCanvas_Window;

$   AppendMenu (menu, MF_SEPARATOR, 0, NULL)                      asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_CONSOLE, "Show Console") asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_ABOUT,   "About...")     asserted;

$   CheckMenuItem (menu, _TX_IDM_CONSOLE,
                   console? (IsWindowVisible (console)? MF_CHECKED : 0) : MF_DISABLED);

$   return _txCanvas_Window;
    }

//--------------------------------------------------------------------------------------------

inline
bool _txCanvas_OK()
    {
$   return _txCanvas_ThreadId   &&
           _txCanvas_Window     &&
           _txCanvas_BackBuf[0] &&
           _txCanvas_BackBuf[1];
    }

//--------------------------------------------------------------------------------------------

int _txCanvas_SetRefreshLock (int count)
    {
$   int oldCount = _txCanvas_RefreshLock;

$   _txCanvas_RefreshLock = count;

$   if (_txCanvas_RefreshLock <= 0 || oldCount <= 0)
        if (_txCanvas_Window)
            {
$           InvalidateRect (_txCanvas_Window, NULL, false);
$           UpdateWindow   (_txCanvas_Window);
            }

$   return oldCount;
    }

//! @}
//}
//============================================================================================

//============================================================================================
//{          [Internal] Main window event handlers (_txCanvas_On...)
//! @name    ������� ��������� ����                (_txCanvas_On...)
//============================================================================================
//! @{

bool _txCanvas_OnCREATE (HWND wnd)
    {
$   assert (wnd);

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); _txCanvas_BackBuf[0] asserted;
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); _txCanvas_BackBuf[1] asserted;

$   SetTimer (wnd, _txCanvas_RefreshTimer, _TX_WINDOW_UPDATE_INTERVAL, NULL) asserted;

$   _txCanvas_Window = wnd;

$   txSetDefaults();

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnDESTROY (HWND wnd)
    {
    assert (wnd);

    // ���������� ��������� ����� ���������

$   PostQuitMessage (_txRunning? WM_DESTROY : EXIT_SUCCESS);

$   if (!_txCanvas_Window) return false;

    // Indicate that we are about to manually terminate

$   _txExit = true;

    // Lock GDI resources

$   bool locked = false;
$   _txWaitFor ((locked = txLock (false), locked));
$   if (!locked) TX_DEBUG_ERROR ("Cannot lock GDI to free resources");

    // ����������� �������, ��������� � �����

$   if (_txCanvas_BackBuf[0]) _txBuffer_Delete (&_txCanvas_BackBuf[0])  asserted;
$   if (_txCanvas_BackBuf[1]) _txBuffer_Delete (&_txCanvas_BackBuf[1])  asserted;

$   if (_txCanvas_RefreshTimer) KillTimer (wnd, _txCanvas_RefreshTimer) asserted;

    // Indicate that we are destroyed

$   _txCanvas_Window = NULL;

$   txUnlock();

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnCLOSE (HWND wnd)
    {
$   if (!wnd || !_txCanvas_OK()) return false;

$   if (_txRunning &&
        MessageBox (wnd, "������� main() �� ���������. ��������� ��� ��� ��������. �������� �� ��������?    \n\n"
                         "��������: ������� �� ����� �����������, ��� ����� �������� ������ Windows.\n"
                         "����� ���������, ����� main() ���������� - ��� ������������ � ��������� ����.",
                    txGetModuleFileName (false), MB_OKCANCEL | MB_ICONSTOP) != IDOK) return false;
$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnPAINT (HWND wnd)
    {
$   if (!wnd || !_txCanvas_OK()) return false;

$   if (!txLock (false)) return false;

$   PAINTSTRUCT ps = {0};
$   HDC dc = BeginPaint (wnd, &ps);
$   if (!dc) { txUnlock(); return false; }

$   RECT r = {0};
$   GetClientRect (wnd, &r) asserted;
$   POINT size = { r.right - r.left, r.bottom - r.top };

$   if (_txCanvas_RefreshLock <= 0)
        {
$       Win32::BitBlt   (_txCanvas_BackBuf[1], 0, 0, size.x, size.y, txDC(), 0, 0, SRCCOPY);

$       _txConsole_Draw (_txCanvas_BackBuf[1]);
        }

    // Magic 100500 value is used to completely block screen refresh.
    // Since no value can be 100500 or above, this condition is always true and
    // the refresh cannot be blocked IRL. Do not use 100501 because it may lead
    // to errors on some compilers and possible may crash the compilers themselves.
    // Yes guys, with all your software installed.

$   if (_txCanvas_RefreshLock != 100500)
        { $ Win32::BitBlt (dc, 0, 0, size.x, size.y, _txCanvas_BackBuf[1], 0, 0, SRCCOPY); }

$   EndPaint (wnd, &ps) asserted;

$   txUnlock();

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnCHAR (HWND, WPARAM ch)
    {
$   INPUT_RECORD evt = {0};

$   evt.EventType                        = KEY_EVENT;
$   evt.Event.KeyEvent.bKeyDown          = true;
$   evt.Event.KeyEvent.wRepeatCount      = 1;
$   evt.Event.KeyEvent.wVirtualKeyCode   = 0;
$   evt.Event.KeyEvent.wVirtualScanCode  = 0;
$   evt.Event.KeyEvent.uChar.AsciiChar   = (unsigned char) ch;
$   evt.Event.KeyEvent.dwControlKeyState = 0;

$   DWORD written = 0;
$   WriteConsoleInput (GetStdHandle (STD_INPUT_HANDLE), &evt, 1, &written);

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnMOUSEMOVE (HWND, WPARAM buttons, LPARAM coords)
    {
$   if (!_txCanvas_OK()) return false;

$   _txMousePos.x   = LOWORD (coords);
$   _txMousePos.y   = HIWORD (coords);
$   _txMouseButtons = (int) buttons;

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnTIMER (HWND wnd, WPARAM)
    {
$   if (!wnd)                      return false;
$   if (_txCanvas_RefreshLock > 0) return false;

$   InvalidateRect (wnd, NULL, false) asserted;
$   UpdateWindow   (wnd)              asserted;

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd)
    {
$   if (!wnd) return false;

$   HWND console = GetConsoleWindow();
$   if (!console) return false;

$   bool visible = !!IsWindowVisible (console);

$   ShowWindow (console, visible? SW_HIDE : SW_SHOW);

$   visible = !!IsWindowVisible (console);
$   CheckMenuItem (GetSystemMenu (wnd, false), (int)cmd, visible? MF_CHECKED : MF_UNCHECKED);

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txCanvas_OnCmdABOUT (HWND, WPARAM)
    {
    //{ Overriding the missing names, if the set is uncomplete

    #if defined (__MODULE)
        #define ABOUT_NAME_    __MODULE
    #else
        #define ABOUT_NAME_    "TXLib"
    #endif

    #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__AUTHOR)

        #ifndef __MODULE
        #define __MODULE       "TXLib"                       " \t\t"  "#define __MODULE to set the name."
        #endif

        #ifndef __VERSION
        #define __VERSION      "(0.000000000)."              " \t\t" "#define __VERSION to set the string value."
        #endif

        #ifndef __DESCRIPTION
        #define __DESCRIPTION  "(��� ���� ������ ��������)." " \t\t" "#define __DESCRIPTION to override project role."
        #endif

        #ifndef __AUTHOR
        #define __AUTHOR       "(��������� ���)."            " \t\t" "#define __AUTHOR to override this name."
        #endif

    #endif
    //}

$   time_t timeT     = time (NULL) - clock()/CLOCKS_PER_SEC;
$   char   timeS[32] = "";

    #ifdef  _TX_USE_SECURE_CRT
$   ctime_s  (timeS, sizeof (timeS), &timeT);
    #else
$   strncpy (timeS, ctime (&timeT), sizeof (timeS) - 1);
    #endif

$   static char text[_TX_BUFSIZE] = "";
$   char cwd [MAX_PATH] = "";

    #define EOL_ "    \n"

$   _snprintf_s (text, sizeof (text) - 1,
                 #ifdef _TX_USE_SECURE_CRT
                 _TRUNCATE,
                 #endif

                 "Application:" EOL_ "\n"

                 #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__PROGRAMMER)
                     __MODULE " version " __VERSION EOL_
                     __DESCRIPTION EOL_
                     "Copyright (c) " __AUTHOR EOL_
                 #else
                     "����� ����� �� ���� ���� �������:)" EOL_
                     "#define __MODULE to \"your program name\" before including TXLib.h to use this billboard..." EOL_
                 #endif

                 "\n" "Developed with:" EOL_ "\n"
                 "The Dumb Artist Library (TX Library) - " _TX_VERSION EOL_
                 _TX_AUTHOR ", see license on: http://ded32.net.ru/index/0-6" EOL_ "\n"

                 "TXLib file:" "\t" __FILE__ _TX_NAME EOL_
                 "Compiled:"   "\t" __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode, by " __TX_COMPILER__ EOL_
                 "Started:"    "\t" "%.6s %.4s %.8s" EOL_ "\n"

                 "Running:"    "\t" "%s" EOL_
                 "Directory:"  "\t" "%s",

                 timeS + 4, timeS + 20, timeS + 11,  // These offsets are ANSI standardized
                 txGetModuleFileName(),
                 _getcwd (cwd, sizeof (cwd) - 1));
    #undef EOL_

$   MessageBox (txWindow(), text, "About " ABOUT_NAME_, MB_ICONINFORMATION);

//  And a bit of HTTP-code in C++ function:

    goto http;
    http://ded32.net.ru                               // See valuable refs here :)

$   return true;

    #undef ABOUT_NAME_
    }

//--------------------------------------------------------------------------------------------

LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
    {
    if (msg == WM_KEYDOWN && wpar == VK_F12 &&
        GetKeyState (VK_SHIFT) && GetKeyState (VK_CONTROL) && GetKeyState (VK_MENU))
        {
$       _txCanvas_OnCmdABOUT (wnd,      wpar);
$       return DefWindowProc (wnd, msg, wpar, lpar);
        }

    WNDPROC altWndProc = _txAltWndProc;
    if (altWndProc)
        {
$       LRESULT res = altWndProc (wnd, msg, wpar, lpar);
$       if (res) return res;
        }

    switch (msg)
        {
        case WM_CREATE:  $      _txCanvas_OnCREATE     (wnd);             break;

        case WM_CLOSE:   $ if (!_txCanvas_OnCLOSE      (wnd))             return 0;
        case WM_DESTROY: $      _txCanvas_OnDESTROY    (wnd);             break;

        case WM_PAINT:   $      _txCanvas_OnPAINT      (wnd);             break;
        case WM_CHAR:    $      _txCanvas_OnCHAR       (wnd, wpar);       break;
        case WM_TIMER:   $      _txCanvas_OnTIMER      (wnd, wpar);       break;

        case WM_LBUTTONUP:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MOUSEMOVE:    $ _txCanvas_OnMOUSEMOVE  (wnd, wpar, lpar); break;
        default:              $ break;
        }

    if (msg == WM_SYSCOMMAND) switch (wpar)
        {
        case _TX_IDM_ABOUT:   $ _txCanvas_OnCmdABOUT   (wnd, wpar);       break;
        case _TX_IDM_CONSOLE: $ _txCanvas_OnCmdCONSOLE (wnd, wpar);       break;
        default:              $ break;
        }

    return DefWindowProc (wnd, msg, wpar, lpar);

    #undef IS_TXLIB_HOTKEY_
    }

//! @}
//}
//============================================================================================

//============================================================================================
//{          [Internal] Console-support functions  (_txConsole...)
//! @name    ������� ����������� ����              (_txConsole...)
//============================================================================================
//! @{

HWND _txConsole_Attach (bool forceRealloc)
    {
$   HWND console = GetConsoleWindow();

$   GetWindowRect (console, &_txConsole_Pos);
$   _txConsole_Active = (console && GetForegroundWindow() == console);

$   if (forceRealloc && !console)
        {
$       FreeConsole();
$       AllocConsole();
        }

$   console = GetConsoleWindow();
$   if (!console) return NULL;

$   SetConsoleCP       (1251);
$   SetConsoleOutputCP (1251);

$     setlocale (LC_CTYPE,  "Russian");
$   _wsetlocale (LC_CTYPE, L"Russian_Russia.ACP");

$   static bool done = false;
$   if (done) return console;

$   _txConsole_SetUnicodeFont();

$   fflush (stdin);  *stdin  = *_fdopen (_open_osfhandle ((unsigned) GetStdHandle (STD_INPUT_HANDLE),  _O_TEXT), "r");
$   fflush (stdout); *stdout = *_fdopen (_open_osfhandle ((unsigned) GetStdHandle (STD_OUTPUT_HANDLE), _O_TEXT), "w");
$   fflush (stderr); *stderr = *_fdopen (_open_osfhandle ((unsigned) GetStdHandle (STD_ERROR_HANDLE),  _O_TEXT), "w");

$   setvbuf (stdin,  NULL, _IONBF, 0);
$   setvbuf (stdout, NULL, _IONBF, 0);
$   setvbuf (stderr, NULL, _IONBF, 0);

$   std::ios::sync_with_stdio();

$   done = true;
$   return console;
    }

//--------------------------------------------------------------------------------------------

bool _txConsole_SetUnicodeFont()
    {
$   if (Win32::GetCurrentConsoleFontEx &&
        Win32::SetCurrentConsoleFontEx)
        {
$       HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$       Win32::CONSOLE_FONT_INFOEX info = { sizeof (info) };
$       Win32::GetCurrentConsoleFontEx (out, false, &info) asserted;

$       info.FontFamily = 0x36;  // Unicode fixed-pitch

$       Win32::SetCurrentConsoleFontEx (out, false, &info) asserted;

$       return true;
        }

$   const unsigned uniFont = 10;

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   if (Win32::GetNumberOfConsoleFonts() <= uniFont)
        {
$       HRESULT init = Win32::CoInitialize (NULL);
$       size_t sz = 0;

$       char link [MAX_PATH] = "";
$       getenv_s (&sz, link, sizeof (link), "TEMP");
$       strncat_s (link, "\\_txLink.lnk", sizeof (link));

$       char comspec [MAX_PATH] = "";
$       getenv_s (&sz, comspec, sizeof (comspec), "COMSPEC");

$       CONSOLE_FONT_INFO font = { Win32::GetNumberOfConsoleFonts() - 1 };
$       font.dwFontSize = Win32::GetConsoleFontSize (out, font.nFont);

$       _txCreateShortcut (link, comspec, "/c exit", NULL, NULL,
                           SW_SHOWMINNOACTIVE, NULL, 0, font.dwFontSize.Y + 2) asserted;

$       (ptrdiff_t) ShellExecute (NULL, NULL, link, NULL, NULL, SW_SHOWMINNOACTIVE) > 32 asserted;
$       _txWaitFor (FindWindow (NULL, "_txLink"));

$       _unlink (link) == 0 asserted;

$       if (init == S_OK) Win32::CoUninitialize();
        }

$   CONSOLE_FONT_INFO cur = {0, {-1, -1}};
$   Win32::GetCurrentConsoleFont (out, false, &cur);

$   bool ok = (cur.nFont >= uniFont) || !!Win32::SetConsoleFont (out, uniFont);

$   HWND console = Win32::GetConsoleWindow();
$   InvalidateRect (console, NULL, false);
$   UpdateWindow   (console);

$   return ok;
    }

//--------------------------------------------------------------------------------------------

inline
bool _txConsole_OK()
    {
$   return GetConsoleWindow() != NULL;
    }

//--------------------------------------------------------------------------------------------

bool _txConsole_Detach (bool restorePos)
    {
$   HWND console = Win32::GetConsoleWindow();
$   if (!console) return false;

$   if (restorePos)
        {
$       RECT r = {0};
$       GetWindowRect (console, &r);

$       MoveWindow (console, _txConsole_Pos.left, _txConsole_Pos.top,
                    r.right - r.left, r.bottom - r.top, true);
        }

$   if (_TX_CONSOLE_MODE & SWP_HIDEWINDOW) ShowWindow (console, SW_SHOW);
$   if (_txConsole_Active)                 SetForegroundWindow (console);

$   return !!FreeConsole();
    }

//--------------------------------------------------------------------------------------------

bool _txConsole_Draw (HDC dc)
    {
$   assert (_txCanvas_OK());

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   BOOL ok = GetConsoleScreenBufferInfo (out, &con);
    if (!ok) return false;

$   SIZE fontSz = { 12, 16 };
$   Win32::GetTextExtentPoint32 (dc, "W", 1, &fontSz) asserted;

$   POINT size = { con.srWindow.Right  - con.srWindow.Left + 1,
                   con.srWindow.Bottom - con.srWindow.Top  + 1 };

$   COLORREF pal [16] = { 0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080, 0xC0C0C0,
                          0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF };

$   for (int y = 0; y < size.y; y++)
        {
$       static char chr [_TX_BUFSIZE + 1] = "";  // [con.dwSize.X + 1]
$       static WORD atr [_TX_BUFSIZE + 1] = {0}; // [con.dwSize.X + 1]
$       COORD coord = { (short) (con.srWindow.Left), (short) (y + con.srWindow.Top) };
$       DWORD read  = 0;

$       if (!ReadConsoleOutputCharacter (out, chr, sizearr (chr), coord, &read)) continue;
$       if (!ReadConsoleOutputAttribute (out, atr, sizearr (atr), coord, &read)) continue;

$       for (int x = 0, xEnd = size.x; x < size.x; x = xEnd)
            {
            Win32::SetTextColor (dc, pal [ atr[x]       & 0x0F]);
            Win32::SetBkColor   (dc, pal [(atr[x] >> 4) & 0x0F]);
            Win32::SetBkMode    (dc,      (atr[x]       & 0xF0)? OPAQUE : TRANSPARENT);

            for (xEnd = x+1; atr[xEnd] == atr[x] && xEnd < size.x; xEnd++) ;

            Win32::TextOut (dc, (x + con.srWindow.Left) * fontSz.cx, y * fontSz.cy,
                            chr + x, xEnd - x) asserted;
            }
        }

$   Win32::SetTextColor (dc, pal [ con.wAttributes       & 0x0F]);
$   Win32::SetBkColor   (dc, pal [(con.wAttributes >> 4) & 0x0F]);
$   Win32::SetBkMode    (dc, TRANSPARENT);

$   if (_txConsole_IsBlinking &&
        In (con.dwCursorPosition, con.srWindow) &&
        GetTickCount() % _TX_CURSOR_BLINK_INTERVAL*2 > _TX_CURSOR_BLINK_INTERVAL &&
        GetForegroundWindow() == txWindow())
        {
$       Win32::TextOut (dc, (con.dwCursorPosition.X - con.srWindow.Left) * fontSz.cx,
                            (con.dwCursorPosition.Y - con.srWindow.Top)  * fontSz.cy + 1,
                            "_", 1) asserted;
        }

$   return true;
    }

//--------------------------------------------------------------------------------------------

#define      _TX_TRY                { goto __tx_try; } __tx_try: { int __tx_error = S_OK; (void)__tx_error;
#define      _TX_CHECKED( cmd )     { if (FAILED (__tx_error = (cmd))) goto __tx_catch; }
#define      _TX_FAIL               { __tx_error = E_FAIL; goto __tx_catch; }
#define      _TX_RETRY              { __tx_error = S_OK;   goto __tx_try;   }
#define      _TX_OK                 ( SUCCEEDED (__tx_error) )
#define      _TX_CATCH              goto __tx_finally; __tx_catch:
#define      _TX_RETURN             goto __tx_finally;
#define      _TX_FINALLY            __tx_finally:
#define      _TX_ENDTRY             }

//--------------------------------------------------------------------------------------------

bool _txCreateShortcut (const char shortcutName[],
                        const char fileToLink[], const char args[] /*= NULL*/, const char workDir[] /*= NULL*/,
                        const char description[] /*= NULL*/, int cmdShow /*= SW_SHOWNORMAL*/, const char iconFile[] /*= NULL*/, int iconIndex /*= 0*/,
                        int fontSize /*= 0*/, COORD bufSize /*= ZERO (COORD)*/, COORD wndSize /*= ZERO (COORD)*/, COORD wndOrg /*=ZERO (COORD)*/)
    {
$   IShellLink* shellLink = NULL;
$   Win32::IShellLinkDataList* dataList = NULL;
$   IPersistFile* file = NULL;

$   HRESULT init = Win32::CoInitialize (NULL);

    _TX_TRY
        {
$       _TX_CHECKED (Win32::CoCreateInstance (CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, IID_IShellLink, (void**) &shellLink));
$       if (!shellLink) _TX_FAIL;

$       shellLink->SetPath (fileToLink);
$       shellLink->SetArguments (args);
$       shellLink->SetWorkingDirectory (workDir);
$       shellLink->SetDescription (description);
$       shellLink->SetShowCmd (cmdShow);
$       shellLink->SetIconLocation (iconFile, iconIndex);

$       _TX_CHECKED (shellLink->QueryInterface (Win32::IID_IShellLinkDataList, (void**) &dataList));
$       if (!dataList) _TX_FAIL;

$       Win32::NT_CONSOLE_PROPS props =
          {{sizeof (props), NT_CONSOLE_PROPS_SIG},

            0x07, 0xF5,                                 // wFillAttribute, wPopupFillAttribute
           {bufSize.X, bufSize.Y},                      // dwScreenBufferSize
           {wndSize.X, wndSize.Y},                      // dwWindowSize
           {wndOrg.X,  wndOrg.Y},                       // dwWindowOrigin
            0,                                          // nFont
            0,                                          // nInputBufferSize
           {0, (short) fontSize},                       // dwFontSize
            0x36, 0, L"",                               // uFontFamily, uFontWeight, FaceName
            15,                                         // UINT  uCursorSize;
            0,  1, 1, 0,                                // bFullScreen, bQuickEdit, bInsertMode, bAutoPosition
            50, 4, 0,                                   // uHistoryBufferSize, uNumberOfHistoryBuffers, bHistoryNoDup

           {0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080, 0xC0C0C0,
            0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF}
            };

$       _TX_CHECKED (dataList->AddDataBlock (&props));

$       _TX_CHECKED (shellLink->QueryInterface (Win32::IID_IPersistFile, (void**) &file));
$       if (!file) _TX_FAIL;

$       wchar_t wName[MAX_PATH] = L"";
$       MultiByteToWideChar (CP_ACP, MB_PRECOMPOSED, shortcutName, -1, wName, MAX_PATH);

$       _TX_CHECKED (file->Save (wName, true));
        }

$   _TX_CATCH
$   _TX_FINALLY

$   if (file)      file     ->Release();
$   if (dataList)  dataList ->Release();
$   if (shellLink) shellLink->Release();

$   if (init == S_OK) Win32::CoUninitialize();

$   return _TX_OK;
    _TX_ENDTRY
    }

//! @}
//}
//============================================================================================

//============================================================================================
//{          [Internal] Memory DC functions        (_txBuffer...)
//! @name    ������� "������������ ������" (������������ ������, _txBuffer...)
//============================================================================================
//! @{

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bitmap)
    {
$   txLock();

$   HDC wndDC = GetDC (wnd);
$   if (!wndDC) return NULL;

$   if (!(Win32::GetDeviceCaps (wndDC, RASTERCAPS) & RC_BITBLT)) TX_DEBUG_ERROR ("RC_BITBLT not supported");

$   RECT r = {0};
$   GetClientRect (wnd, &r) asserted;
$   POINT sz = { r.right - r.left, r.bottom - r.top };
$   if (!size) size = &sz;

$   HDC dc = Win32::CreateCompatibleDC (wndDC);
$       if (!dc) TX_DEBUG_ERROR ("Cannot create buffer: CreateCompatibleDC() failed");

$   HBITMAP bmap = bitmap? bitmap : Win32::CreateCompatibleBitmap (wndDC, size->x, size->y);
$       if (!bmap) TX_DEBUG_ERROR ("Cannot create buffer: CreateCompatibleBitmap() failed");

$   Win32::SelectObject (dc, bmap) asserted;

$   if (!bitmap) Win32::PatBlt (dc, 0, 0, size->x, size->y, BLACKNESS) asserted;

$   ReleaseDC (wnd, wndDC) asserted;

$   txUnlock();
$   return dc;
    }

//--------------------------------------------------------------------------------------------

bool _txBuffer_Delete (HDC* dc)
    {
$   assert (dc);
$   if (!dc || !*dc) return false;

$   txLock();

$   _txBuffer_Select (Win32::GetStockObject         (NULL_PEN),    *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject         (NULL_BRUSH),  *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject         (SYSTEM_FONT), *dc) asserted;
$   _txBuffer_Select (Win32::CreateCompatibleBitmap (*dc, 0, 0),   *dc) asserted;

$   Win32::DeleteObject (Win32::GetCurrentObject (*dc, OBJ_BITMAP)) asserted;

$   Win32::DeleteDC (*dc) asserted;

$   *dc = NULL;

$   txUnlock();
$   return true;
    }

//--------------------------------------------------------------------------------------------

bool _txBuffer_Select (HGDIOBJ obj, HDC dc /*= txDC()*/)
    {
$   assert (obj); assert (dc);

$   if (!obj || !Win32::GetObjectType (obj)) TX_DEBUG_ERROR ("Invalid GDI object type");

$   txLock();

$   obj = Win32::SelectObject (dc, obj);
$   if (obj) Win32::DeleteObject (obj) asserted;

$   txUnlock();

$   return obj != NULL;
    }

//! @}
//}
//============================================================================================

//============================================================================================
//{          Diagnostics
//! @name    �����������
//============================================================================================
//! @{

void _txOnSignal (int sig/* = 0*/, int fpe/* = 0*/)
    {
    if (!sig && !fpe)
        {
$       signal (SIGSEGV, (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGFPE,  (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGABRT, (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGILL,  (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGTERM, (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       return;
        }

    const char* sSig = ": ����������� ��� �������";
    const char* sFPE = ": ����������� ��� ����������";

    #define GET_DESCR_( str, code, descr )  case (code): { (str) = #code ": " descr; break; }

    switch (sig)
        {
        GET_DESCR_ (sSig, SIGSEGV, "������ �� ��������� ���������. ������� �������!")
        GET_DESCR_ (sSig, SIGILL,  "������� ��������� ������������ ��������. ��������� ��������� �� �������.")
        GET_DESCR_ (sSig, SIGABRT, "��������� ���������� ���������, ������� ������� abort.")
        GET_DESCR_ (sSig, SIGTERM, "������� ������ ��������������� ���������� ���������")
        GET_DESCR_ (sSig, SIGFPE,  "������ ������ � �����������, ������� �� 0 ��� ���-�� ���")
        default:   break;
        }

    if (sig == SIGFPE) switch (fpe)
        {
        #ifdef _FPE_INVALID
        GET_DESCR_ (sFPE, _FPE_INVALID,        "��������� �������")
        GET_DESCR_ (sFPE, _FPE_DENORMAL,       "��������������")
        GET_DESCR_ (sFPE, _FPE_ZERODIVIDE,     "������� �� ����")
        GET_DESCR_ (sFPE, _FPE_OVERFLOW,       "������������ ����������")
        GET_DESCR_ (sFPE, _FPE_UNDERFLOW,      "���������������� ����������")
        GET_DESCR_ (sFPE, _FPE_INEXACT,        "�������� ���������")
        GET_DESCR_ (sFPE, _FPE_UNEMULATED,     "�������� �� �����������")
        GET_DESCR_ (sFPE, _FPE_SQRTNEG,        "���������� ������ �� -1")
        GET_DESCR_ (sFPE, _FPE_STACKOVERFLOW,  "������������ �����")
        GET_DESCR_ (sFPE, _FPE_STACKUNDERFLOW, "���������������� �����")
        GET_DESCR_ (sFPE, _FPE_EXPLICITGEN,    "����� ����� ����������")
        #endif
        default:   break;
        }

    #undef GET_DESCR_

    if (sig == SIGFPE && fpe)
        _txError (NULL, 0, NULL, 0,0,0, "signal (%d, 0x%02X): %s, %s"_ sig _ fpe _ sSig _ sFPE);
    else
        _txError (NULL, 0, NULL, 0,0,0, "signal (%d): %s"            _ sig _ sSig);
    }

//--------------------------------------------------------------------------------------------

void _txOnUnexpected()
    {
    _txError (NULL, 0, NULL, (DWORD)-1,-1,-1,
              "std::unexpected(): �������������� ����������. ��������� ���� catch-�����. ����������� catch (...).    \n"
              "���������, �� �������� �� ������������ ���������� �����-���� �������, ���� �� �� (���) �����������.");
    }

//--------------------------------------------------------------------------------------------

void _txOnTerminate()
    {
    _txError (NULL, 0, NULL, (DWORD)-1,-1,-1,
              "std::terminate(): ��������� ����� ��������� ��-�� ���������������� ���������� � ������� main()    \n"
              "��� � �����������. ����������� try/catch �����, �������������� catch (...), ������������, � ��� ����.");
    }

//--------------------------------------------------------------------------------------------

int txOutputDebugPrintf (const char format[], ...)
    {
    bool msgbox = (*format == '\a')? (format++, true) : false;

    static char str[_TX_BIGBUFSIZE] = "";

    va_list arg; va_start (arg, format);

    #ifdef _TX_USE_SECURE_CRT
        #define _TRUNCATE_    , _TRUNCATE
    #else
        #define _TRUNCATE_
    #endif

    int n = _vsnprintf_s (str, sizeof (str) _TRUNCATE_, format, arg);

    #undef _TRUNCATE_
    va_end (arg);

    OutputDebugString (str);

    if (msgbox)
        {
        HWND wnd = (txWindow())? txWindow() : Win32::GetConsoleWindow();

        MessageBox (wnd, str, "�����������, ���", MB_ICONEXCLAMATION | MB_TOPMOST);
        }

    return n;
    }

//--------------------------------------------------------------------------------------------

bool _txError (const char file[], int line, const char func[],
               DWORD winerr, int crterr, int doserr,
               const char msg[], ...)
    {
    static int nCalls = 0;

    if (winerr == (DWORD) -1) winerr = GetLastError();
    if (crterr ==         -1) crterr = errno;
    if (doserr ==         -1) doserr = _doserrno;
    nCalls++;

    unsigned threadId = GetCurrentThreadId();

    bool fatal = (msg && *msg == '\a')? (msg++, true) : false;

    va_list arg; va_start (arg, msg);

    #ifdef  _TX_USE_SECURE_CRT
        #define SZARG_(n)  sizeof (str[0]) - (n) - (s-str[0]), _TRUNCATE

    #else
        #define SZARG_(n)  sizeof (str[0]) - (n) - (s-str[0])

    #endif

    static char str[2][_TX_BIGBUFSIZE] = {""}, *s = str[0];

                s +=  _snprintf_s  (s, SZARG_ (1), "TX_ERROR() ��������:" "\v\v");

    if (file)   s +=  _snprintf_s  (s, SZARG_ (1), "����: %s," _TX_NAME, file);
    if (line)   s +=  _snprintf_s  (s, SZARG_ (1), "������: %d, ",       line);
    if (func)   s +=  _snprintf_s  (s, SZARG_ (1), "�������: %s   \v\v", func);

    if (msg)    s +=  _snprintf_s  (s, SZARG_ (1), "%s: ", (file || line || func)? "���������" : "��������"),
                s += _vsnprintf_s  (s, SZARG_ (1), msg, arg),
                s +=  _snprintf_s  (s, SZARG_ (1), "    \v\v");

                s +=  _snprintf_s  (s, SZARG_ (1), "#%d: %s: Thread: 0x%08X%s",
                                                   nCalls, txVersion(), threadId,
                                                   (threadId == _txMainThreadId)?    " (Main)"   :
                                                   (threadId == _txCanvas_ThreadId)? " (Canvas)" : "");
    if (_txSrcLocFile && _txSrcLocLine &&
        _txSrcLocLine != line && _stricmp (_txSrcLocFile, file) != 0)
                s +=  _snprintf_s  (s, SZARG_ (1), ", Last TXLib loc: %s (%d) %s",
                                                   _txSrcLocFile, _txSrcLocLine, _txSrcLocFunc);

    if (winerr) s +=  _snprintf_s  (s, SZARG_ (0), ", GetLastError(): %lu (", winerr),
                s += FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                    NULL, winerr, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                                    s, (DWORD) (sizeof (str[0]) - (s-str[0])), NULL) - 3,
                s +=  _snprintf_s  (s, SZARG_ (1), ")");

    if (crterr) s +=  _snprintf_s  (s, SZARG_ (1), ", errno: %lu (%s)",
                                    crterr, (strerror_s (str[1], crterr), str[1]));

    if (doserr) s +=  _snprintf_s  (s, SZARG_ (1), ", _doserrno: %lu (%s)",
                                    doserr, (strerror_s (str[1], doserr), str[1]));

                s +=  _snprintf_s  (s, SZARG_ (1), ".%s    \n",
                                    std::uncaught_exception()? "std::uncaught_exception(): true." : "");
    #undef SZARG_

    OutputDebugString (str[0]);

    for (char* p = strchr (str[0], '\v'); p; p = strchr (p+1, '\v')) *p = '\n';

    printf ("\n" "--------------------------------------------------" "\n"
                 "%s"
                 "--------------------------------------------------" "\n", str[0]);

    MessageBox (NULL, str[0], fatal? "��������� ������" : "������ � ���������",
                MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

    va_end (arg);

    if (fatal)
        {
        if (!IsDebuggerPresent()) exit (EXIT_FAILURE);

/* > */ DebugBreak(); // >>> �� � ���������, ���� ���� ���������� ���������� � �����������.
        }             //     �������� �� ������� ��������� ��������. �������� �� ���� �������.

    return false;
    }

//! @}
//}
//============================================================================================

//============================================================================================
//{          TXLib API implementation
//           ���������� TXLib API
//============================================================================================

inline
const char* txVersion()
    {
$   return _TX_VERSION;
    }

//--------------------------------------------------------------------------------------------

inline
unsigned txVersionNumber()
    {
$   return _TX_VER;
    }

//--------------------------------------------------------------------------------------------

POINT txGetExtent()
    {
$   _txAssertOK();

$   RECT r = {0};
$   GetClientRect (txWindow(), &r);

$   POINT size = { r.right - r.left, r.bottom - r.top };
$   return size;
    }

//--------------------------------------------------------------------------------------------

int txGetExtentX()
    {
$   return txGetExtent().x;
    }

//--------------------------------------------------------------------------------------------

int txGetExtentY()
    {
$   return txGetExtent().y;
    }

//--------------------------------------------------------------------------------------------

inline
HDC& txDC()
    {
$   return _txCanvas_BackBuf[0];
    }

//--------------------------------------------------------------------------------------------

inline
HWND txWindow()
    {
$   return _txCanvas_Window;
    }

//--------------------------------------------------------------------------------------------

bool txDestroyWindow()
    {
$   if (!txWindow()) return false;

$   if (SendNotifyMessage (txWindow(), WM_DESTROY, 0, 0) == 0) return false;

$   _txWaitFor (!_txCanvas_Window);

$   return _txCanvas_Window == NULL;
    }

//--------------------------------------------------------------------------------------------

bool txSetColor (COLORREF color, int thickness /*= 1*/)
    {
$   _txAssertOK();

$   return _txBuffer_Select (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), thickness, color)) &&
            txGDI        ((Win32::SetTextColor (txDC(), color)));
    }

//--------------------------------------------------------------------------------------------

bool txColor (double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetColor (RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

//--------------------------------------------------------------------------------------------

COLORREF txGetColor()
    {
$   _txAssertOK();

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_PEN))); assert (obj);

$   union { EXTLOGPEN extLogPen; LOGPEN LogPen; } buf = {{0}};

$   int size = GetObject (obj, 0, NULL);
$   GetObject (obj, sizeof (buf), &buf) asserted;

$   return (size == sizeof (LOGPEN))? buf.LogPen.lopnColor : buf.extLogPen.elpColor;
    }

//--------------------------------------------------------------------------------------------

bool txSetFillColor (COLORREF color)
    {
$   _txAssertOK();

$   return _txBuffer_Select ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                                        Win32::CreateSolidBrush (color));
    }

//--------------------------------------------------------------------------------------------

bool txFillColor (double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetFillColor (RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

//--------------------------------------------------------------------------------------------

COLORREF txGetFillColor()
    {
$   _txAssertOK();

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); assert (obj);

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) asserted;

$   return buf.lbColor;
    }

//--------------------------------------------------------------------------------------------

bool txSetROP2 (int mode /*= R2_COPYPEN*/)
    {
$   _txAssertOK();

$   return txGDI (!!(Win32::SetROP2 (txDC(), mode)));
    }

//--------------------------------------------------------------------------------------------

bool txClear()
    {
$   _txAssertOK();

$   POINT size = txGetExtent();
$   return txGDI (!!(Win32::PatBlt (txDC(), 0, 0, size.x, size.y, PATCOPY)));
    }

//--------------------------------------------------------------------------------------------

inline
bool txSetPixel (int x, int y, COLORREF color)
    {
$   _txAssertOK();

$   txGDI ((Win32::SetPixel (txDC(), x, y, color)));

$   return true;
    }

//--------------------------------------------------------------------------------------------

inline
bool txPixel (int x, int y, double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetPixel (x, y, RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

//--------------------------------------------------------------------------------------------

inline
COLORREF txGetPixel (int x, int y)
    {
$   _txAssertOK();

$   return txGDI ((Win32::GetPixel (txDC(), x, y)));
    }

//--------------------------------------------------------------------------------------------

bool txLine (int x0, int y0, int x1, int y1)
    {
$   _txAssertOK();

$   txGDI ((Win32::MoveToEx (txDC(), x0, y0, NULL))) asserted;
$   txGDI ((Win32::LineTo   (txDC(), x1, y1      ))) asserted;

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool txRectangle (int x0, int y0, int x1, int y1)
    {
$   _txAssertOK();

$   txGDI ((Win32::Rectangle (txDC(), x0, y0, x1, y1))) asserted;

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints)
    {
$   _txAssertOK();

$   return txGDI (!!(Win32::Polygon (txDC(), points, numPoints)));
    }

//--------------------------------------------------------------------------------------------

bool txEllipse (int x0, int y0, int x1, int y1)
    {
$   _txAssertOK();

$   txGDI ((Win32::Ellipse (txDC(), x0, y0, x1, y1))) asserted;

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool txCircle (int x, int y, int r)
    {
$   return txEllipse (x-r, y-r, x+r, y+r);
    }

//--------------------------------------------------------------------------------------------

bool txArc (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txAssertOK();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Arc (txDC(), x0, y0, x1, y1,
                                (int) (center.x + 100 * cos (start) + 0.5),
                                (int) (center.y - 100 * sin (start) + 0.5),
                                (int) (center.x + 100 * cos (end)   + 0.5),
                                (int) (center.y - 100 * sin (end)   + 0.5))));
    }

//--------------------------------------------------------------------------------------------

bool txPie (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txAssertOK();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Pie (txDC(), x0, y0, x1, y1,
                                (int) (center.x + 100 * cos (start) + 0.5),
                                (int) (center.y - 100 * sin (start) + 0.5),
                                (int) (center.x + 100 * cos (end)   + 0.5),
                                (int) (center.y - 100 * sin (end)   + 0.5))));
    }

//--------------------------------------------------------------------------------------------

bool txChord (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txAssertOK();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Chord (txDC(), x0, y0, x1, y1,
                                  (int) (center.x + 100 * cos (start) + 0.5),
                                  (int) (center.y - 100 * sin (start) + 0.5),
                                  (int) (center.x + 100 * cos (end)   + 0.5),
                                  (int) (center.y - 100 * sin (end)   + 0.5))));
    }

//--------------------------------------------------------------------------------------------

bool txFloodFill (int x, int y,
                  COLORREF color /*= TX_TRANSPARENT*/, DWORD mode /*= FLOODFILLSURFACE*/)
    {
$   _txAssertOK();

$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y);

$   return txGDI (!!(Win32::ExtFloodFill (txDC(), x, y, color, mode)));
    }

//--------------------------------------------------------------------------------------------

bool txTextOut (int x, int y, const char text[])
    {
$   _txAssertOK();

$   int len = (int) strlen (text);
$   txGDI (!!(Win32::TextOut (txDC(), x, y, text, len))) asserted;

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, len, &size))) asserted;

$   RECT r = { x, y, x + size.cx, y + size.cy };
$   InvalidateRect (txWindow(), &r, false) asserted;

$   return true;
    }

//--------------------------------------------------------------------------------------------

bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format /*= DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_WORD_ELLIPSIS*/)
{
$   _txAssertOK();

$   RECT r = { x0, y0, x1, y1 };

$   if (!strchr (text, '\n')) format |= DT_SINGLELINE;

$   unsigned prev = txSetTextAlign (TA_LEFT | TA_TOP | TA_NOUPDATECP);
$   if (Win32::DrawText) txGDI ((Win32::DrawText (txDC(), text, -1, &r, format))) asserted;
$   txSetTextAlign (prev);

$   return true;
}

//--------------------------------------------------------------------------------------------

bool txSelectFont (const char name[], int sizeY,
                   int sizeX      /*= -1*/,
                   int  bold      /*= FW_DONTCARE*/,
                   bool italic    /*= false*/,
                   bool underline /*= false*/,
                   bool strikeout /*= false*/)
    {
$   _txAssertOK();

$   _txBuffer_Select (txFontExist (name)? CreateFont (sizeY, (int) ((sizeX != -1)? sizeX : sizeY/3), 0, 0,
                                                      bold, italic, underline, strikeout, RUSSIAN_CHARSET,
                                                      OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                                      DEFAULT_QUALITY, FIXED_PITCH, name)
                                        :
                                          GetStockObject (SYSTEM_FIXED_FONT));
$   return true;
    }

//--------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[])
    {
$   _txAssertOK();

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, (int) strlen (text), &size))) asserted;

$   return size;
    }

//--------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[])
    {
$   return txGetTextExtent (text) .cx;
    }

//--------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[])
    {
$   return txGetTextExtent (text) .cy;
    }

//--------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align /*= TA_CENTER | TA_BASELINE*/)
    {
$   _txAssertOK();

$   return txGDI ((Win32::SetTextAlign (txDC(), align)));
    }

//--------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[])
    {
$   _txAssertOK();

$   static LOGFONT font = {0};
$   font.lfCharSet = DEFAULT_CHARSET;
$   strncpy_s (font.lfFaceName, name, sizeof (font.lfFaceName) - 1);

    struct enumFonts
        {
        static int CALLBACK Proc (const LOGFONT* fnt, const TEXTMETRIC*, DWORD, LPARAM data)
            {
$           if (!data || !fnt) return 0;

            #ifndef __STRICT_ANSI__
$           return _strnicmp (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE);
            #else
$           return  strncmp  (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE);
            #endif
            }
        };

$   return txGDI ((Win32::EnumFontFamiliesEx (txDC(), &font, enumFonts::Proc,
                                             (LPARAM)&font, 0) == 0? &font : NULL));
    }

//--------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj)
    {
$   _txAssertOK();

$   return _txBuffer_Select (obj);
    }

//--------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (int sizeX, int sizeY, HBITMAP bitmap /*= NULL*/)
    {
$   _txAssertOK();

$   POINT size = { sizeX, sizeY };
$   HDC dc = _txBuffer_Create (txWindow(), &size, bitmap); assert (dc);

$   return dc;
    }

//--------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[])
    {
$   _txAssertOK();

$   HBITMAP image = (HBITMAP) LoadImage (NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
$   if (!image) return NULL;

$   HDC dc = txCreateCompatibleDC (0, 0, image);

$   return dc;
    }

//--------------------------------------------------------------------------------------------

bool txDeleteDC (HDC dc)
    {
$   _txAssertOK();

$   return _txBuffer_Delete (&dc);
    }

//--------------------------------------------------------------------------------------------

bool txDeleteDC (HDC* dc)
    {
$   _txAssertOK();

$   return _txBuffer_Delete (dc);
    }

//--------------------------------------------------------------------------------------------

bool txBitBlt (HDC dest, int xDest, int yDest, int width, int height,
               HDC src,  int xSrc,  int ySrc,  DWORD rOp /*= SRCCOPY*/)
    {
$   _txAssertOK();

$   return txGDI (!!(Win32::BitBlt (dest, xDest, yDest, width, height, src, xSrc, ySrc, rOp)));
    }

//--------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, int xDest, int yDest, int width, int height,
                       HDC src,  int xSrc,  int ySrc,  COLORREF transColor /*= TX_BLACK*/)
    {
$   _txAssertOK();

$   if (!Win32::TransparentBlt) return false;

$   return txGDI (!!(Win32::TransparentBlt (dest, xDest, yDest, width, height, src, xSrc, ySrc, width, height, transColor)));
    }

//--------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, int xDest, int yDest, int width, int height,
                   HDC src,  int xSrc,  int ySrc,  double alpha /*= 1.0*/)
    {
$   _txAssertOK();

$   if (!Win32::AlphaBlend) return false;

$   if (alpha < 0) alpha = 0;
$   if (alpha > 1) alpha = 1;

$   BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) (alpha * 255 + 0.5), AC_SRC_ALPHA };

$   return txGDI (!!(Win32::AlphaBlend (dest, xDest, yDest, width, height, src, xSrc, ySrc, width, height, blend)));
    }

//--------------------------------------------------------------------------------------------

inline
int txUpdateWindow (int update /*= true*/)
    {
$   return _txCanvas_SetRefreshLock (update >= 0? !update : -update);
    }

//--------------------------------------------------------------------------------------------

inline
int txBegin()
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock + 1);

$   return _txCanvas_RefreshLock;
    }

//--------------------------------------------------------------------------------------------

inline
int txEnd()
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock - 1);

$   return _txCanvas_RefreshLock;
    }

//--------------------------------------------------------------------------------------------

inline
bool txSleep (int time)
    {
    _txAssertOK();

$   int old = _txCanvas_SetRefreshLock (0);

$   Sleep (time);

$   _txCanvas_SetRefreshLock (old);

$   return old != 0;
    }

//--------------------------------------------------------------------------------------------

bool txLock (bool wait /*= true*/)
    {
$   if (_txExit) Sleep (0);

$   if (wait) { $ return      EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { $ return !!TryEnterCriticalSection (&_txCanvas_LockBackBuf);       }
    }

//--------------------------------------------------------------------------------------------

bool txUnlock()
    {
$   LeaveCriticalSection (&_txCanvas_LockBackBuf);

$   if (_txExit) Sleep (0);
$   return false;
    }

//--------------------------------------------------------------------------------------------

template <typename T> inline
T txUnlock (T value)
    {
$   txUnlock();
$   return value;
    }

//--------------------------------------------------------------------------------------------

inline
POINT txMousePos()
    {
$   return _txMousePos;
    }

//--------------------------------------------------------------------------------------------

inline
int txMouseX()
    {
$   return _txMousePos.x;
    }

//--------------------------------------------------------------------------------------------

inline
int txMouseY()
    {
$   return _txMousePos.y;
    }

//--------------------------------------------------------------------------------------------

inline
int txMouseButtons()
    {
$   return _txMouseButtons;
    }

//--------------------------------------------------------------------------------------------

bool txSetConsoleAttr (WORD color /*= 0x07*/)
    {
$   return !!SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
    }

//--------------------------------------------------------------------------------------------

WORD txGetConsoleAttr()
    {
$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);

$   return con.wAttributes;
    }

//--------------------------------------------------------------------------------------------

POINT txSetConsoleCursorPos (int x, int y)
    {
$   POINT fontSz = txGetConsoleFontSize();

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   COORD pos = { (short) (1.0 * x / fontSz.x + 0.5 + con.srWindow.Left),
                  (short) (1.0 * y / fontSz.y + 0.5 + con.srWindow.Top) };

$   SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos) asserted;

$   POINT prev = { (int) (1.0 * (con.dwCursorPosition.X - con.srWindow.Left) / fontSz.x + 0.5),
                   (int) (1.0 * (con.dwCursorPosition.Y - con.srWindow.Top ) / fontSz.y + 0.5) };
$   return prev;
    }

//--------------------------------------------------------------------------------------------

POINT txGetConsoleCursorPos()
    {
$   POINT fontSz = txGetConsoleFontSize();

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   POINT pos = { (int) (1.0 * (con.dwCursorPosition.X - con.srWindow.Left) / fontSz.x + 0.5),
                  (int) (1.0 * (con.dwCursorPosition.Y - con.srWindow.Top ) / fontSz.y + 0.5) };
$   return pos;
    }

//--------------------------------------------------------------------------------------------

bool txClearConsole()
    {
$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (out, &con) asserted;

$   COORD start = {con.srWindow.Left, con.srWindow.Top};

$   DWORD len   = (con.srWindow.Right  - con.srWindow.Left + 1) *
                  (con.srWindow.Bottom - con.srWindow.Top  + 1);

$   DWORD written = 0;
$   FillConsoleOutputCharacter (out, 0x20 /*' '*/,    len, start, &written) asserted;
$   FillConsoleOutputAttribute (out, con.wAttributes, len, start, &written) asserted;

$   SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), start) asserted;

$   return written == len;
    }

//--------------------------------------------------------------------------------------------

POINT txGetConsoleFontSize()
    {
$   CONSOLE_FONT_INFO font = {0, {8, 16}};

$   if (Win32::GetCurrentConsoleFont)
        Win32::GetCurrentConsoleFont (GetStdHandle (STD_OUTPUT_HANDLE), false, &font) asserted;

$   SIZE size = { font.dwFontSize.X, font.dwFontSize.Y };
$   txGDI (Win32::GetTextExtentPoint32 (_txCanvas_BackBuf[1], "W", 1, &size));

$   POINT sizeFont = { size.cx, size.cy };
$   return sizeFont;
    }

//--------------------------------------------------------------------------------------------

bool txTextCursor (bool blink /*= true*/)
    {
$   bool old = _txConsole_IsBlinking;

$   _txConsole_IsBlinking = blink;

$   return old;
    }

//--------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] /*= NULL*/, DWORD mode /*= SND_ASYNC*/)
    {
$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;

$   if (!filename) mode = SND_PURGE;

$   return !!PlaySound (filename, NULL, mode);
    }

//--------------------------------------------------------------------------------------------

WNDPROC txSetWindowHandler (WNDPROC handler /*= NULL*/)
    {
$   WNDPROC old = _txAltWndProc; _txAltWndProc = handler;
$   return  old;
    }

//--------------------------------------------------------------------------------------------

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()
    {
$   MessageBox (txWindow(),
                "��� ��������������� ������. ����� ������. �� ������ �������:" "\n\n"
                "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()" "\n\n"
                "���� �� ����� [����������]�������� ��� ���, �� ����� ���� ��� ������� �� ��������." "\n"
                "�� ��� ��� ���� ���������� �������. ��. ����������� ���� ������� � �������� ������� ����������."    "\n\n",
                "�� ����������", MB_ICONSTOP);

    // The truth is out there...

$   return false;
    }

//--------------------------------------------------------------------------------------------

// Bingo! Now you are learned to use the Sources, Luke. And may the Source be with you.

inline
bool txDisableAutoPause()
    {
$   _txExit = true;
$   return true;
    }

//--------------------------------------------------------------------------------------------

double txQueryPerformance()
    {
$   _txAssertOK();

$   int maxTime    = 500;
$   int maxSamples = 100;
$   int size       = 500;

$   HDC dc = txCreateCompatibleDC (size, size);
$   assert (dc);

$   DWORD_PTR mask = SetThreadAffinityMask (GetCurrentThread(), 1);
$   assert (mask);

$   LARGE_INTEGER freq = {{0}};
$   QueryPerformanceFrequency (&freq) asserted;

$   LARGE_INTEGER start = {{0}};
$   QueryPerformanceCounter (&start) asserted;

$   int samples = 0;
$   while (samples++ < maxSamples)
        {
$       LARGE_INTEGER cur = {{0}};
$       QueryPerformanceCounter (&cur) asserted;

$       double t = 1000.0 * (cur.QuadPart - start.QuadPart) / freq.QuadPart;
$       if (t > maxTime) break;

        // Draw test scene

$       for (int y = 0; y < size; y += 10)
        for (int x = 0; x < size; x += 10)
           Win32::TextOut (dc, x, y, "*", 1);

$       Win32::Ellipse (dc, 0, 0, size, size);
$       Win32::ExtFloodFill (dc, size/2, size/2, TX_TRANSPARENT, FLOODFILLSURFACE);

$       txBitBlt (dc, size/2,      0, size/2, size/2, dc,      0,      0) asserted;
$       txBitBlt (dc, size/2, size/2, size/2, size/2, dc,      0, size/2) asserted;
$       txBitBlt (dc,      0, size/2, size/2, size/2, dc,      0,      0) asserted;
$       txBitBlt (dc, size/2, size/2, size/2, size/2, dc, size/2,      0) asserted;
        }

$   mask = SetThreadAffinityMask (GetCurrentThread(), mask);
$   assert (mask);

$   txDeleteDC (&dc);

$   return 15.0 * samples / size;
    }

//--------------------------------------------------------------------------------------------

int txExtractColor (COLORREF color, COLORREF component)
    {
$   switch (component)
        {
        case TX_RED:
        case TX_HUE:        $ return (color >>  0) & 0xFF;

        case TX_GREEN:
        case TX_SATURATION: $ return (color >>  8) & 0xFF;

        case TX_BLUE:
        case TX_LIGHTNESS:  $ return (color >> 16) & 0xFF;

        default:            $ return CLR_INVALID;
        }
    }

//--------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor)
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

$   return RGB (((ih >= 0)? ih*60 : ih*60 + 360) + 0.5, is*255 + 0.5, il*255 + 0.5);
    }

//--------------------------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor)
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

$   return RGB (ir * 255 + 0.5, ig * 255 + 0.5, ib * 255 + 0.5);
    }

//--------------------------------------------------------------------------------------------

template <typename T>
inline
bool In (T x, T a, T b)
    {
    return a <= x && x <= b;
    }

//--------------------------------------------------------------------------------------------

inline
bool In (const POINT& pt, const RECT& rect)
    {
    return In (pt.x, rect.left, rect.right) &&
           In (pt.y, rect.top,  rect.bottom);
    }

//--------------------------------------------------------------------------------------------

inline
bool In (const COORD& pt, const SMALL_RECT& rect)
    {
    return In (pt.X, rect.Left, rect.Right) &&
           In (pt.Y, rect.Top,  rect.Bottom);
    }

//--------------------------------------------------------------------------------------------

inline
int random (int range)
    {
    return rand() % range;
    }

//--------------------------------------------------------------------------------------------

inline
double random (double left, double right)
    {
    return left + (right - left) * ((double) rand() / RAND_MAX);
    }

//--------------------------------------------------------------------------------------------

template <typename T> inline
T zero()
#ifdef _MSC_VER_6
    { T z = {0}; return z; }

#else
    { T z = { }; return z; }

#endif

//}
//============================================================================================

//============================================================================================
//{          txDialog methods implementation
//           ���������� ������� ������ txDialog
//============================================================================================

txDialog::txDialog () :
    layout_ (NULL)
    {$}

//--------------------------------------------------------------------------------------------

txDialog::txDialog (const Layout* layout) :
    layout_ (layout)
    {$}

//--------------------------------------------------------------------------------------------

const txDialog::Layout* txDialog::setLayout (const Layout* layout)
    {
$   return std::swap (layout_, layout), layout;
    }

//--------------------------------------------------------------------------------------------

INT_PTR txDialog::dialogBox (WORD resourceID)
    {
$   const char* resName = (char*)(ptrdiff_t)resourceID;

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_DEBUG_ERROR ("�� ������ ������ ������� %d" _
                                                                          resourceID);
$   return DialogBoxParam (NULL, resName, NULL, dialogProc__, (LPARAM) this);
    }

//--------------------------------------------------------------------------------------------

INT_PTR txDialog::dialogBox (const txDialog::Layout* layout /*= NULL*/, size_t bufsize /*= 0*/)
    {
$   if (!layout)  layout = layout_;
$   if (!layout)  return TX_DEBUG_ERROR ("�� ���������� ������������ ������ �������");

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_DEBUG_ERROR ("GlobalAlloc(): ��� ������ ��� ������� �������");

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

//--------------------------------------------------------------------------------------------

int txDialog::dialogProc (HWND, UINT, WPARAM, LPARAM)
    {
$   return FALSE;
    }

//--------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                              WORD controls, short x, short y, short cx, short cy,
                              const char caption[], const char font[], WORD fontsize,
                              HANDLE menu /*= NULL*/)
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

//--------------------------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                           short x, short y, short cx, short cy,
                           WORD id, const char wclass[], const char caption[])
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

//}
//============================================================================================

//============================================================================================
//{          Cleaning up the utility macros
//           ������� ��������� ��������
//============================================================================================

#undef       $

//}
//============================================================================================

//! @endcond
//}
//============================================================================================

//============================================================================================

/*! @cond INTERNAL */

} }  // namespace TX, namespace _TX

/*! @endcond */

//--------------------------------------------------------------------------------------------
//{          Easy using of TX:: and some of std::
//--------------------------------------------------------------------------------------------

#ifndef _TX_NAMED
using namespace TX;            // Allow easy usage of TXLib functions
using namespace TX::Win32;     // Simulate linkage with Win32 libs
#endif

using ::std::cin;              // Predefined usings to avoid "using namespace std"
using ::std::cout;
using ::std::cerr;
using ::std::string;

//}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//           ��������� � ������������ � ����������
//--------------------------------------------------------------------------------------------
//! @cond INTERNAL

#if defined (__GNUC__) && (__GNUC__ >= 4) && (__GNUC_MINOR__ >= 3)

    #pragma GCC optimize            ("strict-aliasing")
    #pragma GCC diagnostic warning "-Wstrict-aliasing"

    // Still block this warning to avoid reporting about "= {0}" or "= {}" initialization.

    #if 0
    #pragma GCC diagnostic warning "-Wmissing-field-initializers"
    #endif

    // These warnings really occur at end of compilation, so do not restore them.

    #if 0
    #pragma GCC diagnostic warning "-Wunreachable-code"
    #pragma GCC diagnostic warning "-Wunused-label"
    #endif

#endif

//--------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

    #pragma warning (default: 4127)             // conditional expression is constant
    #pragma warning (default: 4351)             // new behavior: elements of array ... will be default initialized

    #pragma warning (default: 4511)             // copy constructor could not be generated
    #pragma warning (default: 4512)             // assignment operator could not be generated
    #pragma warning (disable: 4514)             // unreferenced inline function has been removed
    #pragma warning (default: 4663)             // C++ language change: to explicitly specialize class template '...'

    // This warning really occur at end of compilation, so do not restore it.

    #if 0
    #pragma warning (default: 4710)             // function '...' not inlined
    #endif

#endif

#if defined (__INTEL_COMPILER)

    #pragma warning (default:  174)             // remark: expression has no effect
    #pragma warning (default:  304)             // remark: access control not specified ("public" by default)
    #pragma warning (default:  522)             // remark: function "..." redeclared "inline" after being called
    #pragma warning (default:  981)             // remark: operands are evaluated in unspecified order
    #pragma warning (default: 1684)             // conversion from pointer to same-sized integral type (potential portability problem)

#endif

//! @endcond
//}
//--------------------------------------------------------------------------------------------

#endif // __TXLIB_H

//============================================================================================
// EOF
//============================================================================================

