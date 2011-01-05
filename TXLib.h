//===============================================================================================================================
//              [These sections are for folding control  in Code::Blocks]
//{             [Best viewed with "Fold all on file open" option enabled]
//===============================================================================================================================
//!
//! @file       TXLib.h
//! @brief      ������� ����
//!
//! @mainpage
//!
//! @brief      ���������� ������ ��������� (The Dumb Artist Library, TX Library, TXLib).
//!
//! @version    [Version 0.01 alpha, build 72]
//! @author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)
//! @date       2010
//!
//! @include    "Doc/MainPage.txt"
//! @include    "Doc/Examples.txt"
//!
//-------------------------------------------------------------------------------------------------------------------------------
//!
//! @defgroup Drawing   ���������
//! @defgroup Mouse     ��������� ����
//! @defgroup Dialogs   ���������� ����
//! @defgroup Misc      ������
//! @defgroup Service   ���������
//! @defgroup Technical ����������� ������
//}
//===============================================================================================================================

#ifndef   __TXLIB_H
#define   __TXLIB_H

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� ������ ����������.
//!
//!          ��� ��������� ������������� ����������� ��� ���������� ������.
//!
//! @see     txVersion()
//-------------------------------------------------------------------------------------------------------------------------------
//! @{

#define _TX_VERSION           "TXLib [Version 0.01 alpha, build 72]"
#define _TX_AUTHOR            "Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)"

#define _TX                   0x0001720a        //!< ������ ���������� � ������������� �������

//! @}
//}------------------------------------------------------------------------------------------------------------------------------

//{ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< All the code is here, unfold it

//-------------------------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    ��������� � ������������ � ����������
//-------------------------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#ifndef __cplusplus
#error TXLib.h: Must use C++ to compile this
#endif

#ifdef __STRICT_ANSI__                          // Try to extend strict ANSI C
#warning TXLib.h: Trying to extend strict ANSI compatibility
#undef __STRICT_ANSI__
#endif

#if defined (__GNUC__)

    #if (__GNUC__ >= 4)
        #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
        #pragma GCC diagnostic ignored "-Wstrict-aliasing"
        #pragma GCC diagnostic ignored "-Wunreachable-code"
        #pragma GCC diagnostic ignored "-Wunused-value"
        #pragma GCC diagnostic ignored "-Wunused-function"
        #pragma GCC diagnostic ignored "-Wunused-label"  // Just for fun in _txCanvas_OnCmdAbout()
    #endif

    #define _TX_CHECK_FORMAT( fmtIdx )  __attribute__ (( format (printf, (fmtIdx), (fmtIdx)+1) ))
    #define _TX_CHECK_USAGE             __attribute__ (( warn_unused_result ))

#else

    #define _TX_CHECK_FORMAT( fmtIdx )
    #define _TX_CHECK_USAGE

#endif

#if defined (_MSC_VER)

    #pragma warning (push, 4)                   // Set maximum warning level

    #pragma warning (disable: 4127)             // conditional expression is constant
//!!!    #pragma warning (disable: 4245)             // conversion from... to..., signed/unsigned mismatch
    #pragma warning (disable: 4351)             // new behavior: elements of array ... will be default initialized
//!!!    #pragma warning (disable: 6031)             // return value ignored: '...'

    #define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200)    // MSVC 6 (1998)

    #pragma warning (push, 3)                   // At level 4, std headers emit warnings

//!!!    #pragma warning (disable: 4018)             // '<': signed/unsigned mismatch
    #pragma warning (disable: 4100)             // unreferenced formal parameter
    #pragma warning (disable: 4511)             // copy constructor could not be generated
    #pragma warning (disable: 4512)             // assignment operator could not be generated
    #pragma warning (disable: 4663)             // C++ language change: to explicitly specialize class template '...'

    #if !defined (WINVER)
        #define WINVER   0x0400                 // MSVC 6: Defaults to Windows 95
    #endif

#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1400)    // MSVC 8 (2005) or greater

    #define _TX_USE_SECURE_CRT

#else

    #define  strncpy_s    strncpy               // MSVC prior to 8(2005) versions
    #define  strncat_s    strncat               //   do NOT have secure variants of these
    #define  ctime_s      ctime                 //   these functions, so use unsecure ones.
    #define _snprintf_s  _snprintf              //
    #define _vsnprintf_s _vsnprintf             //

#endif

#if defined (__INTEL_COMPILER)

//  remark #174                                 // expression has no effect
//  remark #304                                 // access control not specified ("public" by default)
//  remark #522                                 // function "..." redeclared "inline" after being called
//  remark #981                                 // operands are evaluated in unspecified order
//  warning #1684                               // conversion from pointer to same-sized integral type (portability problem)

#endif

#if !defined (WINVER)
    #define WINVER       0x0500                 // Defaults to Windows 2000
#endif

#if !defined (_WIN32_WINNT)
    #define _WIN32_WINNT WINVER
#endif

#undef   UNICODE                                // Drop the Unicode
#undef  _UNICODE

//! @endcond
//}

//-------------------------------------------------------------------------------------------------------------------------------
//{          Includes
//-------------------------------------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <direct.h>
#include <process.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <assert.h>

#include <iostream>
#include <algorithm>

#include <conio.h>

#include <windows.h>
#include <tlhelp32.h>

//}

//-------------------------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    ��������� � ������������ � ����������
//-------------------------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#if defined (_MSC_VER) && (_MSC_VER == 1200)    // MSVC 6 (1998)

    #pragma warning (push, 4)                   // Restore maximum level

#endif

//! @endcond
//}

//===============================================================================================================================

//! @cond INTERNAL
/*! @cond OFF   */ namespace { /*! @endcond */ namespace TX { // <<< Code is here
//! @endcond

//===============================================================================================================================

//===============================================================================================================================
//{          TXLib interface
//! @name    ��������� ����������
//===============================================================================================================================

//===============================================================================================================================
//{          Colors
//! @name    �����
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���������������� ������.
//!
//!          ��. @ref TX_BLACK, @ref TX_BLUE � ������ ����� � ������ ����.
//!
//! @see     txSetColor(), txSetFillColor(), txGetColor(), txGetFillColor(), txGetPixel()
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (TX_NULL);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

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
    TX_TRANSPARENT   = 0xFFFFFFFF,            //!< ���������� ����. <i>��������� ���������.</i>
    TX_NULL          = TX_NULL,               //!< ���������� ����. <i>��������� ���������.</i>

//  �������� ������ (����������) - ��. @ref txExtractColor(), @ref txRGB2HSL(), @ref txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< �������� ��� ����� � ������ HSL
    TX_SATURATION   = 0x05000000,             //!< ������������ ����� � ������ HSL
    TX_LIGHTNESS    = 0x06000000;             //!< �������� ����� � ������ HSL

//}

//===============================================================================================================================
//{          Tune-up constants
//! @name    ����������� ���������
//===============================================================================================================================

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� ����������� ����������� ����
//!
//!          ����� ���������� ����� ���������� TXLib.h � ���������. ���� �������� ����������
//!          � SetWindowPos() ��� ����������� ����.
//!
//!          SWP_HIDEWINDOW - �������� ���������� ���� ��� �������
//!
//-------------------------------------------------------------------------------------------------------------------------------

#ifndef      _TX_CONSOLE_MODE
#define      _TX_CONSOLE_MODE             SWP_HIDEWINDOW
#endif

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� �������
//-------------------------------------------------------------------------------------------------------------------------------

const char   _TX_CONSOLE_FONT[]           = "Lucida Console";

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���� ������ �������
//-------------------------------------------------------------------------------------------------------------------------------

const COLORREF _TX_CONSOLE_COLOR          = TX_LIGHTGRAY;

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ������� ������� ������� (��)
//-------------------------------------------------------------------------------------------------------------------------------

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ���������� ������ (��)
//-------------------------------------------------------------------------------------------------------------------------------

const int    _TX_WINDOW_UPDATE_INTERVAL   = 10;

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� �������� �������� (��)
//-------------------------------------------------------------------------------------------------------------------------------

const int    _TX_TIMEOUT                  = 1000;

//! @endcond

//}

//===============================================================================================================================
//{          Diagnostics and Tools
//! @name    ����������� � �������
//===============================================================================================================================

//! @cond INTERNAL
#define  TX_QUOTE( symbol )   _TX_QUOTE (symbol)
#define _TX_QUOTE( symbol )   #symbol
//! @endcond

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��� � ������ �������� �����������
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

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

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��� ������ ������
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#if   !defined (NDEBUG) &&  defined (_DEBUG)
    #define _TX_BUILDMODE     "DEBUG"

#elif !defined (NDEBUG) && !defined (_DEBUG)
    #define _TX_BUILDMODE     "Debug"

#elif  defined (NDEBUG)
    #define _TX_BUILDMODE     "Release"
#endif

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, �������������� � ��� ����� � ����� ������ �����, ��� �� ����������.
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

#define __TX_FILELINE__       __FILE__ " (" TX_QUOTE (__LINE__) ")"

//! @}
//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��� ������� �������
//! @warning ���� ����������� ����� ������� �� �������������� ������������, �� __TX_FUNCTION__
//!          ������������ � ��� ��������� ����� � ����� ������.
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

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

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ������������ ������� assert(), � ������� ��������� ����� MessageBox(),
//!          ������� � OutputDebugString().
//!
//! @param   condition ������� ��� ��������
//!
//!          ���� �������, ����������� assert(), �������, �� ������ ������ �� ������.\n
//!          ���� ������� ����������� �����, �� ��������� ��������������� ��������� �
//!          ��������� �������� �����������.
//!
//! @return  ������ 0
//!
//! @note    <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) assert
//!          ������������ � ������ ��������.</b> �� ���� �������� � assert() ��������,
//!          ������� ����� ��� ������ ��������.
//!
//! @see     asserted, __TX_FILELINE__, __TX_FUNCTION__
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
//!          // ���� �� ����� ������ � ������ Release:
//!          assert (fclose (input) != 0);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#undef  assert

#ifndef NDEBUG
    #define assert( cond )    ( !!(cond) || TX_ERROR ("\a" "���������� ������: �������, ��� \"%s\"" _ #cond), 0 )

#else
    #define assert( cond )    ( 0 )

#endif

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��������������� ��������� � ������ �������� ��� ������� ����������.
//!
//! @return  ������ 0
//!
//!          ���������� ����� ������� assert(), �� �������� � ������ Release
//!          ���������� ���������.
//!
//! @note    <b>��������������, ��� �������� � ������ �������� ���������� 0 ��� false.</b>\n\n
//!          <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) asserted
//!          ������������ � ������ �����.</b>
//!
//! @see     assert(), __TX_FILELINE__, __TX_FUNCTION__
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
//}------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG
    #define asserted        || TX_ERROR ("\a" "��������� ������� ��� ������ ���������")

#else
    #define asserted

#endif

#define TX_NEEDED             asserted  // For compatibility with earlier releases

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ����������� ��������������� ���������.
//!
//! @return  ������ false
//!
//! @see     assert(), asserted(), _
//! @usage
//! @code
//!          TX_ERROR ("�� ���� ��������� '����� � ���'! ������ ������ '%s'" _ fileName);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG
    #define TX_ERROR( msg )   ( _txError (__FILE__, __LINE__, 									  \
                                          ((__TX_FUNCTION__[0] != '(')? __TX_FUNCTION__ : NULL),  \
                                          (DWORD)(-1), -1, -1, msg) )

#else
    #define TX_ERROR(msg)     ( 0 )

#endif

#define TX_THROW              TX_ERROR  // For compatibility with earlier releases

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, ����������� �������� ���������� ����� ���������� � �����-���� ������ ������.
//!
//! @note    <b>������ ������������� ������ ���������������� � �������.</b>
//!
//! @see     TX_ERROR()
//! @usage
//! @code
//!          TX_ERROR ("������� ����� �����: ����� '����� � ���', ���� '%s', ������ %d" _ fileName _ lineNum);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#define _                     ,

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��� ����� � ����� ������, ��� ��������� ����� TX_PRINT_HERE().
//!
//! @see     TX_ERROR()
//! @usage
//! @code
//!          TX_PRINT_HERE();
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG
    #define TX_PRINT_HERE()   printf ("%s (%d) %s: � ����� :)\n", __FILE__, __LINE__, __TX_FUNCTION__)

#else
    #define TX_PRINT_HERE()

#endif

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������/��������� ���������� ����������� ���������� ���� ����������.
//!
//!          ����������� ���� ����� ������ @ref TX_TRACE, ������� ������������� �����
//!          ������ ���������� (statement). �� ��������� ����������� ���������.
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(),
//!          �� ����� ����� ����������� ���������-���������, ��������,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> ��� WinTail. ��� ����� ��������, ������������� ������ @ref TX_TRACE.
//!
//!          _TX_ALLOW_TRACE � @ref TX_TRACE �������� ����� ���������� TXLib.h � ���������.
//! @usage
//! @code
//!          #define  _TX_ALLOW_TRACE   // ��� ��������� ������ ��������� DebugView
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

#ifdef FOR_DOXYGEN_ONLY
#define _TX_ALLOW_TRACE
#endif

#ifdef _TX_ALLOW_TRACE
    #define $                 TX_TRACE

#else
    #define $

#endif

//! @}
//{------------------------------------------------------------------------------------------------------------------------------
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
//!          ����������� ����� �������������� ��������� ���� ����� ������ @ref _TX_ALLOW_TRACE.
//!          �� ��������� ��� ���������.
//!
//!          TX_TRACE � @ref _TX_ALLOW_TRACE �������� ����� ���������� TXLib.h � ���������.
//! @usage
//! @code
//!          #define  TX_TRACE  printf (__LINE__ " ");
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

#ifdef FOR_DOXYGEN_ONLY
#define TX_TRACE
#endif

#ifndef TX_TRACE

    #define TX_TRACE          OutputDebugString (__TX_FILELINE__ ": ")

#endif

//! @}
//}

//===============================================================================================================================
//{          Initialization
//! @name    ������������� ����������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���� ���������
//!
//! @param   sizeX     ������ ���� �� ����������� (� ��������)
//! @param   sizeY     ������ ���� �� ���������   (� ��������)
//! @param   centered  ������������� ���� �� �������
//!
//!          ��� �������� ���� ��������������� ��������� ��������� �� ���������,
//!          ��. ������� @ref txSetDefaults().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txOK()
//! @usage
//! @code
//!          txCreateWindow ( 800,  600);
//!          txCreateWindow (1024,  768, false);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txCreateWindow (int sizeX, int sizeY, bool centered = true)
    {
    return txObject()->txCreateWindow (sizeX, sizeY, centered);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txSelectFont(), txSelectRegion(), txSetROP2()
//! @usage
//! @code
//!          txSetDefaults();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetDefaults()
    {
    return txObject()->txSetDefaults();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
bool txOK()
    {
    return txObject()->txOK();
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ������ � ����������� � ������� ������ ����������.
//!
//! @return  ������ � ����������� � ������� ������ ����������.
//!
//! @usage
//! @code
//!          printf ("I personally love %s\n", txVersion());
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline
const char* txVersion()
    {
    return txObject()->txVersion();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

POINT txGetExtent()
    {
    return txObject()->txGetExtent();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetExtentX()
    {
    return txObject()->txGetExtentX();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetExtentY()
    {
    return txObject()->txGetExtentY();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
HDC& txDC()
    {
    return txObject()->txDC();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
HWND txWindow()
    {
    return txObject()->txWindow();
    }

//}

//===============================================================================================================================
//{          Setting the parameters
//! @name    ��������� ������ � ������� ���������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� � ������� �����, ���� ������.
//!
//! @param   color      ���� ����� � ������, ��. @ref TX_BLACK "�����", RGB()
//! @param   thickness  ������� �����
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetColor (COLORREF color, int thickness = 1)
    {
    return txObject()->txSetColor (color, thickness);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          txColor (1.0, 0.5, 0.25);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txColor (double red, double green, double blue)
    {
    return txObject()->txColor (red, green, blue);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� � ������.
//!
//! @return  ������� ���� ����� � ������, ��. @ref TX_BLACK "�����", RGB()
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          COLORREF color = txGetColor();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txGetColor()
    {
    return txObject()->txGetColor();
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ���������� �����.
//!
//! @param   color  ���� ����������, ��. @ref TX_BLACK "�����", RGB()
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetFillColor (COLORREF color)
    {
    return txObject()->txSetFillColor (color);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txFillColor (double red, double green, double blue)
    {
    return txObject()->txFillColor (red, green, blue);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ���������� �����.
//!
//! @return  ������� ���� ���������� �����, ��. @ref TX_BLACK "�����", RGB()
//!
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          COLORREF color = txGetFillColor();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txGetFillColor()
    {
    return txObject()->txGetFillColor();
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ����� �������������� ������ ��� ���������.
//!
//!          ��� ��������� ����������� ���������� ����� �� ������ ������� �������
//!          �� ������, � ��������� ����� ������ � ������� ����� ����� � ����������.
//!
//! @param   mode  ����� ���������� ������
//!
//! @title   ������ �������������� ������:
//! @table   @tr R2_COPYPEN     @td ������� = ����� ����� (����� ���������� ����� :) @endtr
//!          @tr R2_NOTCOPYPEN  @td ������� = ~�����\n @endtr
//!          @tr @endtr
//!          @tr R2_BLACK       @td ������� = ������ ���� (���� ����� ������������)    @endtr
//!          @tr R2_WHITE       @td ������� = �����  ���� (���� ����� ������������)    @endtr
//!          @tr R2_NOT         @td ������� = ~�������    (���� ����� ������������)\n  @endtr
//!          @tbr
//!          @tr R2_XORPEN      @td ������� =    ������� ^  �����    @endtr
//!          @tr R2_NOTXORPEN   @td ������� = ~ (������� ^  �����)\n @endtr
//!          @tbr
//!          @tr R2_MASKPEN     @td ������� =    ������� &  �����    @endtr
//!          @tr R2_NOTMASKPEN  @td ������� = ~ (������� &  �����)   @endtr
//!          @tr R2_MASKNOTPEN  @td ������� =    ������� & ~�����    @endtr
//!          @tr R2_MASKPENNOT  @td ������� =   ~������� &  �����\n  @endtr
//!          @tbr
//!          @tr R2_MERGEPEN    @td ������� =    ������� |  �����    @endtr
//!          @tr R2_NOTMERGEPEN @td ������� = ~ (������� |  �����)   @endtr
//!          @tr R2_MERGENOTPEN @td ������� =    ������� | ~�����    @endtr
//!          @tr R2_MERGEPENNOT @td ������� =   ~������� |  �����\n  @endtr
//!          @tbr
//!          @tr R2_NOP         @td ������� ������ �� ����������.    @endtr
//! @endtable
//!
//! @return  ���������� ����� �������������� ������, ��. @ref TX_BLACK "�����", RGB()
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetROP2 (int mode = R2_COPYPEN)
    {
    return txObject()->txSetROP2 (mode);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� (���������) ���� �� ���� ������� ������ (���������).
//!
//! @param   red    ���������� �������� ����� � ��������� [0; 255]
//! @param   green  ���������� �������� ����� � ��������� [0; 255]
//! @param   blue   ���������� ������   ����� � ��������� [0; 255]
//!
//! @return  ��������� ���� � ������� COLORREF.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����"
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB()
//! @usage
//! @code
//!          txSetColor (RGB (255, 128, 0));
//!
//!          int red = 20, green = 200, blue = 20;
//!          COLORREF color = RGB (red, green, blue);
//!          txSetFillColor (color);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
COLORREF RGB (int red, int green, int blue);
#endif

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �������� ���������� (�������� �����) �� ���������� �����.
//!
//! @param   color      ��������� ����
//! @param   component  ����������� ����������, ��. @ref TX_BLACK "�����"
//!
//! @return  �������� ����������, ��. @ref TX_BLACK "�����"
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), TX_BLACK "�����"
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_BLACK "�����"
//! @usage
//! @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          ������ ������� ��. � �������� AppearText(), AppearEarth() ������� 5 ("�����").
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

int txExtractColor (COLORREF color, COLORREF component)
    {
    return txObject()->txExtractColor (color, component);
    }

//{--------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� RGB � ������ HSL.
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
//! @param   rgbColor  ������������� ���� � ������� @ref RGB
//!
//! @return  ��������� ���� � ���� COLORREF.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����"
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_BLACK "�����"
//! @usage
//! @code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor)
    {
    return txObject()->txRGB2HSL (rgbColor);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� HSL � ������ @ref RGB.
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
//! @param   hslColor  ������������� ���� � ������� HSL
//!
//! @return  ��������� ���� � ���� COLORREF.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����"
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_BLACK "�����"
//! @usage
//! @code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor)
    {
    return txObject()->txHSL2RGB (hslColor);
    }

//}

//===============================================================================================================================
//{          Drawing
//! @name    ��������� �����
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� ����� ������� ������ ����������.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetFillColor(), txFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          txClear();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txClear()
    {
    return txObject()->txClear();
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� (����� �� ������).
//!
//! @param   x      �-���������� �����
//! @param   y      Y-���������� �����
//! @param   color  ���� �����, ��. @ref TX_BLACK "�����", RGB()
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txPixel(), txGetPixel(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          txSetPixel (100, 100, TX_RED);
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline
bool txSetPixel (int x, int y, COLORREF color)
    {
    return txObject()->txSetPixel (x, y, color);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
bool txPixel (int x, int y, int red, double green, double blue)
    {
    return txObject()->txPixel (x, y, red, green, blue);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� (�������) �� ������.
//!
//! @param   x  �-���������� �����
//! @param   y  Y-���������� �����
//!
//! @return  ������� ���� �������, ��. @ref TX_BLACK "�����", RGB()
//!
//! @see     txSetPixel(), txPixel(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED) CarCrash (x, y);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline
COLORREF txGetPixel (int x, int y)
    {
    return txObject()->txGetPixel (x, y);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!
//! @param   x0  X-���������� ��������� �����
//! @param   y0  Y-���������� ��������� �����
//! @param   x1  X-���������� ��������  �����
//! @param   y1  Y-���������� ��������  �����
//!
//!          ���� � ������� ����� �������� �������� txSetColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txLine (100, 200, 400, 500);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txLine (int x0, int y0, int x1, int y1)
    {
    return txObject()->txLine (x0, y0, x1, y1);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �������������.
//!
//! @param   x0  X-���������� �������� ������  ����
//! @param   y0  Y-���������� �������� ������  ����
//! @param   x1  X-���������� �������  ������� ����
//! @param   y1  Y-���������� �������  ������� ����
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txRectangle (100, 200, 400, 500);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txRectangle (int x0, int y0, int x1, int y1)
    {
    return txObject()->txRectangle (x0, y0, x1, y1);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� ����� ��� �������������.
//!
//! @param   points     ������ �������� POINT � ������������ �����
//! @param   numPoints  ���������� ����� � �������
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          POINT star[6] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}, {150, 300}};
//!          txPolygon (star, 6);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints)
    {
    return txObject()->txPolygon (points, numPoints);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������.
//!
//! @param   x0  X-���������� �������� ������  ���� ���������� ��������������
//! @param   y0  Y-���������� �������� ������  ���� ���������� ��������������
//! @param   x1  X-���������� �������  ������� ���� ���������� ��������������
//! @param   y1  Y-���������� �������  ������� ���� ���������� ��������������
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txEllipse (100, 100, 300, 200);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txEllipse (int x0, int y0, int x1, int y1)
    {
    return txObject()->txEllipse (x0, y0, x1, y1);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���������� ��� ����.
//!
//! @param   x  �-���������� ������
//! @param   y  Y-���������� ������
//! @param   r  ������
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txCircle (100, 100, 10);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txCircle (int x, int y, int r)
    {
    return txObject()->txCircle (x, y, r);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txArc (100, 100, 300, 200, 0, 180);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txArc (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
    return txObject()->txArc (x0, y0, x1, y1, startAngle, totalAngle);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txPie (100, 100, 300, 200, 0, 180);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txPie (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
    return txObject()->txPie (x0, y0, x1, y1, startAngle, totalAngle);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� - txSetFillColor().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txChord (100, 100, 300, 200, 0, 180);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txChord (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
    return txObject()->txChord (x0, y0, x1, y1, startAngle, totalAngle);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������������ ������ ������� ������ ����������.
//!
//! @param   x      �-���������� ����� ������ �������
//! @param   y      Y-���������� ����� ������ �������
//! @param   color  ���� ���������� ������� (TX_TRANSPARENT - ���������������)
//! @param   mode   ����� ������� (FLOODFILLSURFACE - ������� ����������� ����)
//!
//!          ���� ���������� �������� �������� txSetFillColor().
//!          �� ������������� ��� ���������� - �������� �������� ��������.
//!
//! @title   ������ �������: @table
//!          @tr FLOODFILLSURFACE @td - �������� �������,    ��������� ������ color. @endtr
//!          @tr FLOODFILLBORDER  @td - �������� �� �������, ��������� ������ color. @endtr
//!          @endtable
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txFloodFill (100, 100);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txFloodFill (int x, int y, 
                  COLORREF color = TX_TRANSPARENT, DWORD mode = FLOODFILLSURFACE)
    {
    return txObject()->txFloodFill (x, y, color, mode);
    }

//}

//===============================================================================================================================
//{          Drawing text
//! @name    ������ � �������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!
//! @param   x     �-���������� ��������� ����� ������
//! @param   y     Y-���������� ��������� ����� ������
//! @param   text  ��������� ������
//!
//!          ���� ������ �������� �������� txSetColor(), ������������ - txSetTextAlign().
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txTextOut (int x, int y, const char text[])
    {
    return txObject()->txTextOut (x, y, text);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          ���� ������ �������� �������� txSetColor(), ������������ - txSetTextAlign().
//!
//!          ����� �������������� ������ ��. � MSDN (http://msdn.com), ������ "DrawText Function
//!          (Windows)": http://msdn.microsoft.com/en-us/library/dd162498%28VS.85%29.aspx.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format = DT_CENTER | DT_VCENTER | DT_WORDBREAK |
                                   DT_MODIFYSTRING | DT_PATH_ELLIPSIS)
    {
    return txObject()->txDrawText (x0, y0, x1, y1, text, format);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txSelectFont (const char name[], int sizeY,
                   int  sizeX     = -1,
                   int  bold      = FW_DONTCARE,
                   bool italic    = false,
                   bool underline = false,
                   bool strikeout = false)
    {
    return txObject()->txSelectFont (name, sizeY, sizeX, bold, italic, underline, strikeout);
    }
    		   
//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[])
    {
    return txObject()->txGetTextExtent (text);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[])
    {
    return txObject()->txGetTextExtentX (text);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[])
    {
    return txObject()->txGetTextExtentY (text);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ������������ ������.
//!
//! @param   align  ����� ������������
//!
//! @title   ����� ������������: @table
//!          @tr TA_BASELINE @td ����� (X,Y) ���������� ������� ����� ������. @endtr
//!          @tr TA_BOTTOM   @td ����� (X,Y) ���������� ������ ������� ���������� ��������������\n
//!                              (����� ����� ���� ���� �����).   @endtr
//!          @tr TA_TOP      @td ����� (X,Y) ���������� ������� ������� ���������� ��������������\n
//!                              (����� ����� ���� ���� �����).\n @endtr
//!          @tbr
//!          @tr TA_CENTER   @td ����� ����� �������� �� ����������� ������������ ����� (X,Y). @endtr
//!          @tr TA_LEFT     @td ����� (X,Y) ���������� ����� ������� ���������� ��������������\n
//!                              (����� ����� ������ ���� �����). @endtr
//!          @tr TA_RIGHT    @td ����� (X,Y) ���������� ������ ������� ���������� ��������������\n
//!                              (����� ����� ����� ���� �����).  @endtr
//!          @endtable
//!
//! @return  ���������� ��������� ������������ ������.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_RIGHT);
//!
//!          txSetTextAlign();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE)
    {
    return txObject()->txSetTextAlign (align);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          if (txFontExists ("Comic Sans MS")) txSelectFont ("Comic Sans MS", 30);
//!          else                                txSelectFont ("Times", 30);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

LOGFONT* txFontExists (const char name[])
    {
    return txObject()->txFontExists (name);
    }

// For compatibility with typo in earlier releases

LOGFONT* txFontExist  (const char name[]) 
    {
    return txFontExists (name); 
    }

//}

//===============================================================================================================================
//{          Drawing to memory DC and image loading
//! @name    ��������� � ������ (�� "����������� ������") � �������� �����������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (int sizeX, int sizeY, HBITMAP bitmap = NULL)
    {
    return txObject()->txCreateCompatibleDC (sizeX, sizeY, bitmap);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[])
    {
    return txObject()->txLoadImage (filename);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ����� (�������� ���������, DC) � ������.
//!
//! @param   dc     �������� ��������� ��� �����������
//! @param   dcPtr  ��������� �� �������� ��������� ��� �����������.
//!                 ����� ����������� �� ��������� ������������ NULL.
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
//}------------------------------------------------------------------------------------------------------------------------------
//@ {

bool txDeleteDC (HDC* dcPtr)
    {
    return txObject()->txDeleteDC (dcPtr);
    }

bool txDeleteDC (HDC  dc) 
    {
    return txDeleteDC (&dc); 
    }

//@ }
//{------------------------------------------------------------------------------------------------------------------------------
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
//! @table   @tr SRCCOPY     @td ������ �������� :) - ����� ���������������� �����\n @endtr
//!          @tbr
//!          @tr BLACKNESS   @td ��������� �����-�������� ������ ������ (�����-�������� ������������). @endtr
//!          @tr WHITENESS   @td ��������� �����-�������� ����� ������  (�����-�������� ������������). @endtr
//!          @tr DSTINVERT   @td ����������� ����� �� ������-���������  (�����-�������� ������������). @endtr
//!          @tr PATCOPY     @td �������� ���� ������� ����� ������-���������.\n @endtr
//!          @tbr
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
//! @see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(),
//!          @ref TX_BLACK "�����", RGB()
//! @usage
//!          ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          if (!background) MessageBox (txWindow(), "Cannot load background", "Once again :(", 0);
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txBitBlt (HDC dest, int xDest, int yDest, int width, int height, 
               HDC src,  int xSrc,  int ySrc,  DWORD rOp = SRCCOPY)
    {
    return txObject()->txBitBlt (dest, xDest, yDest, width, height, src, int, ySrc, rOp);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, int xDest, int yDest, int width, int height,
                       HDC src,  int xSrc,  int ySrc,  COLORREF transColor = TX_BLACK)
    {
    return txObject()->txTransparentBlt (dest, xDest, yDest, width, height, src, xSrc, ySrc, transColor);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @param   alpha   ����� ������������ �����������, � ���������� � �����-������.\n
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
//!          (� ������� R, G, B) ������ ���� ������.
//!
//!          ����������� ������� AlphaBlend �� Win32 API ����� �������������� �����������.
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
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, int xDest, int yDest, int width, int height,
                   HDC src,  int xSrc,  int ySrc,  double alpha = 1.0)
    {
    return txObject()->txAlphaBlend (dest, xDest, yDest, width, height, src, xSrc, ySrc, alpha);
    }

//}

//===============================================================================================================================
//{          Drawing utilities
//! @name    ������ ������� ���������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ���������� ����������� ����, �� ��������� �������.
//!
//!          ��� ������ ���������� ������������ ������� @ref txEnd().
//!
//! @warning ��������� ������������ �� ������ �����. ��� ����� �������� � ��������
//!          ����������� � ����. ���� � ��������� ��������� ��������, �� �����������
//!          ������� @ref txSleep(), ��� ��� ��� ������������� ��������� �����������,
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
//}------------------------------------------------------------------------------------------------------------------------------

int txBegin()
    {
    return txObject()->txBegin();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txEnd()
    {
    return txObject()->txEnd();
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ���������� ��������� �� ������������ �����.
//!
//! @param   time  �������� � �������������.
//!
//!          <b>�� ����� �������� ����������� � ���� ������ �����������.</b>
//!
//! @return  ��������� ���������� ���������� ����.
//!
//! @see     txBegin(), txEnd(), txUpdateWindow()
//! @usage
//! @code
//!          txSleep (500); // ������� ����������
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSleep (int time)
    {
    return txObject()->txSleep (time);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ��������� ��� ��������� �������������� ���������� ����������� � ����.
//!
//! @param   update  ����� ���������� (true - ���������, false - ���������).
//!
//!          � ������� �� txBegin() � txEnd(), ������� ������������ ��������� ������
//!          � �������� ��� "������ ��� ���������� ��������", txUpdateWindow()
//!          ��������� ���� ���������� ��� ����� ���������� ��������������� ����������.
//!
//!          ����� ������ ���������� � ���������� ��. � �������� @ref txBegin(), @ref txEnd() � @ref txSleep().
//!
//! @return  ���������� ��������� ������ ����������.
//!
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(),
//!          txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline int txUpdateWindow (int update = true)
    {
    return txObject()->int txUpdateWindow (update);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ��� ��������� ��������� ��������� ������� � ����.
//!
//! @param   blink  false - ��������� �������� ������
//!
//! @return  ���������� �������� ����������.
//!
//! @see     txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txTextCursor (bool blink = true)
    {
    return txObject()->txTextCursor (blink);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ������������� ������ ���������.
//!
//! @param   x0  X-���������� �������� ������  ����
//! @param   y0  Y-���������� �������� ������  ����
//! @param   x1  X-���������� �������  ������� ����
//! @param   y1  Y-���������� �������  ������� ����
//!
//!          ���, ��� ����������� ��� ������� ���������, �� ��������.
//!
//!          ��������������� ������� TXLib �� ������������, �������������� ��
//!          ���� ����� ����������� ������� ������ � ��������� �� Win32 API.
//!
//! @return  ����������� �������������� �������. ���� ������ �� ������ ��� �� ���������� - NULL.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//! @usage
//! @code
//!          txSelectRegion (100, 100, 300, 400);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

HRGN txSelectRegion (int x0, int y0, int x1, int y1)
    {
    return txObject()->txSelectRegion (x0, y0, x1, y1);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� ������� ������ GDI.
//!
//! @param   obj  ���������� ������� GDI
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "�����", RGB()
//!          txSelectFont(), txSelectRegion()
//! @usage
//! @code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj)
    {
    return txObject()->txSelectObject (obj);
    }

//}

//===============================================================================================================================
//{          Mouse
//! @name    ������ � �����
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

POINT txMousePos()
    {
    return txObject()->txMousePos();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txMouseX()
    {
    return txObject()->txMouseX();
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txMouseY()
    {
    return txObject()->txMouseY();
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� ��������� ������ ����!
//!
//!          � ������������ �������� ������������ � ������� 1-� (�������)
//!          ��� �������� ������� ����� ������ ����, 2-� - ������, 3-� -
//!          �������.\n ��������, ������������ ����� 5 (�������� 101) ��������
//!          ������������� ������� ������� � ����� ������, �� �� ������ ������.
//!
//! @return  ��������� ������ ����!
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
//}------------------------------------------------------------------------------------------------------------------------------

int txMouseButtons()
    {
    return txObject()->txMouseButtons();
    }

//}

//===============================================================================================================================
//{          Other staff
//! @name    ������ �������� �������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������� ������� � ���������
//!
//! @param   arr  ��� �������
//!
//!          ������ sizearr() ����� ������ ������� � ������ �� ������ �������� �������,
//!          ���������� ������ ������� � ���������.
//!
//! @return  ������ ������� � ���������
//!
//! @warning ����������� ������� ������ � ��� �������� ������ ���� ��������
//!          � ����� ������������� sizearr(). ������ ������� � ������ ������ ����
//!          �������� ��� ����������.
//! @usage
//! @code
//!          POINT coord[] = { {110, 110}, {120, 120}, {130, 110}, {140, 120} };
//!
//!          for (int i = 0; i < sizearr (coord) - 1; i++)
//!              txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#define sizearr( arr )   ( sizeof (arr) / sizeof (arr)[0] )

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

template <typename T>
inline
bool In (T x, T a, T b)
    {
    return a <= x && x <= b;
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������, ��������� �� ����� pt ������ �������������� rect
//!
//! @param   pt    ����������� ����� � ���� <tt> POINT {x, y} </tt>
//! @param   rect  �������������     � ���� <tt> RECT  {left, top, right, bottom} </tt>
//!
//!          ������ ��� ���������� ������.
//!
//! @return  ��������� ��������
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
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

inline
bool In (const POINT& pt, const RECT& rect)
    {
    return In (pt.x, rect.left, rect.right) &&
           In (pt.y, rect.top,  rect.bottom);
    }

inline
bool In (const COORD& pt, const SMALL_RECT& rect)
    {
    return In (pt.X, rect.Left, rect.Right) &&
           In (pt.Y, rect.Top,  rect.Bottom);
    }

//! @}

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��������� �����
//!
//! @param   range  ������ ������� ��������� (@b �� ������� ���� �������).
//!
//! @return  ��������� ����� ����� � ��������� [0; range).\n
//!
//!          �� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//! @usage
//! @code
//!          char message[100] = "Maybe...";
//!          sprintf ("You SUDDENLY got %d bucks now. But note that tax rate is $%d.", random (100), 100);
//!          MessageBox (txWindow(), message, "Lottery", 0);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

inline
int random (int range)
    {
    return rand() % range;
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��������� �����
//!
//! @param   left   ������ ������� ��������� (@b ������� ���� �������).
//! @param   right  ������ ������� ��������� (@b ������� ���� �������).
//!
//! @return  ��������� ����� ����� � ��������� [left; right].\n
//!
//!          �� ��� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//! @usage
//! @code
//!          int money = random (-100, +100);
//!          if (money < 0)
//!              {
//!              char message[100] = "Maybe...";
//!              sprintf ("������ � �������? ������� %d ������!", -money);
//!              MessageBox (txWindow(), message, "������", 0);
//!              }
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

template <typename T, typename T1, typename T2>
inline
T random (T1 left, T2 right)
    {
    return left + (right - left) * ((double) rand() / RAND_MAX);
    }

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

#define MAX( a, b )           ( (a) > (b) ? (a) : (b) )

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

#define MIN( a, b )           ( (a) < (b) ? (a) : (b) )

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� �������� ����.
//!
//! @param   filename  ��� ��������� �����. ���� NULL - ������������� ����.
//! @param   mode      ����� ���������������
//!
//! @title   ������ ���������������: @table
//!          @tr SND_ASYNC       @td ���� ������������� ������������ � ������� ���������.\n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL). @endtr
//!          @tr SND_SYNC        @td ���������� ��������� ������������������ �� ���������
//!                                  ��������������� �����. @endtr
//!          @tr SND_LOOP        @td ����������� ���� ��� ���������������.\n
//!                                  ����� �������� ��������, �������� txPlaySound (NULL).\n @endtr
//!          @tbr
//!          @tr SND_NODEFAULT   @td �� ������������ ���� �� ���������, ���� ������ ���������
//!                                  ��������� �������� ����. @endtr
//!          @tr SND_NOSTOP      @td ���� �����-���� ���� ��� �������������, �� �������������
//!                                  ��� ��� ��������������� ���������� �����. @endtr
//!          @tr SND_APPLICATION @td ����������� ����, ��������� ���������, ������������������
//!                                  ��� ������� ���� �������� ������. @endtr
//!          @endtable
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
//!
//! @note    �������������� ������ ����� � ������� WAV. ��������� ������� (MP3 � ��.) ����
//!          ��������������. �������������� �� ������ ���������� �� �������, ��� � � ������
//!          � �������� �������� � txLoadImage().
//! @usage
//! @code
//!          txPlaySound ("tada.wav"); // so happy that this always exists
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC)
    {
    return txObject()->txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������ ����� ������ �������. ��. �������� �������.
//!
//!          � ���� ������� ���� ������� � ������� �������� ���������, ������� ��� � �����
//!          ����������, ����� @a ����������� ���� �������. ��� ����� [�����������]�������
//!          ��� ������������ ��� � ����������, ��� ���������.
//!
//! @return  ���� �������� ���� ������� - true, ����� - false.
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()
    {
$   MessageBox (txWindow(),
                "��� ��������������� ������. ����� ������. �� ������ �������:" "\n\n"
                "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()" "\n\n"
                "���� �� ����� [����������]�������� ��� ���, �� ����� ���� ��� ������� �� ��������." "\n"
                "�� ��� ��� ���� ���������� �������. ��. ����������� ���� ������� � �������� ������� ����������." "\n\n",
                "�� ����������", MB_ICONSTOP);

    // The truth is out there...

$   return false;
    }

//! @cond INTERNAL

inline                    // Bingo! Now you are learned to use the Sources, Luke.
bool txDisableAutoPause() // And may the Source be with you.
    {
$   _txExit = true;
$   return true;
    }

//! @endcond

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ��������� �������� ������ ����������.
//!
//! @return  �������� ������ � �������� ��������.
//!
//! @see     txSleep()
//! @usage
//! @code
//!          if (txQueryPerformance() < 1) printf ("������� ����� ���������");
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

double txQueryPerformance()
    {
    return txObject()->txQueryPerformance();
    }

//}

//===============================================================================================================================
//{          Back-hole (I hope, not an ass-hole:) of the library)
//! @name    ����� ��������� �������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� �������������� ���������� ������� ��������� Windows.
//!
//! @param   handler  ����� �������������� ���������� ������� ����.\n
//!                   ���� NULL, �� �������������� ���������� ���������.
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
//! @return  ����� ����������� ��������������� ����������� ��������� ����.
//!
//! @note    ������ �������� ������� ������� ����� � ������� SetWindowLong/SetWindowLongPtr:
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
//}------------------------------------------------------------------------------------------------------------------------------

WNDPROC txSetWindowHandler (WNDPROC handler = NULL)
    {
    return txObject()->txSetWindowHandler (handler);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ���������� ������ (��������� ���������).
//!
//! @param   wait  ������� ����� ����������� ���� ��������������� �������
//!
//!          ����� ������� ����� ������� Win32 GDI ���������� �������������
//!          ����� �������� txLock() � ����� �������������� � ������� @ref txUnlock().
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
//!          txLock() /@ref txUnlock() - �������������� ��������. �� ���������� ��
//!          ���������������� ��������� @ref txBegin() / @ref txEnd() /@ref txUpdateWindow(),
//!          ������� �� ���������������� �����, � ������ ��������� �������� ��
//!          ���������� ����. � ������� �� @ref txBegin() / @ref txEnd(), ��������
//!          txLock() /@ref txUnlock() �� ������������ ��������� ������.
//!
//! @return  ��������� ����������
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage   ��. �������� ����� ������� _txCanvas_OnPaint() � _txConsole_Draw() � TXLib.h.
//!
//}------------------------------------------------------------------------------------------------------------------------------

inline
bool txLock (bool wait = true)
    {
    return txObject()->txLock (wait);
    }

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ������������� ������
//!
//!          ����� �������� ��. � @ref txLock().
//!
//! @return  ��������� ���������� (������ false).
//!
//! @see     txDC(), txLock(), txGDI()
//! @usage
//! @code
//! @usage   ��. �������� ����� ������� _txCanvas_OnPaint() � _txConsole_Draw() � TXLib.h.
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

inline
bool txUnlock()
    {
    return txObject()->txUnlock();
    }

template <typename T>
inline
T txUnlock (T value)
    {
    txObject->txUnlock();
    return value;
    }

//! @}

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   ����� ������� Win32 GDI � �������������� ����������� � ��������������.
//!
//! @param   command  ������� GDI (��������, ������������ ��������)
//!
//! @return  ��������, ������������ ���������� �������� GDI.
//!          ���� ������� ��������� �� ������, ������������ �������� false.
//!
//! @note    ���� ������� ��������� �� ������ (@ref txDC() ���������� NULL),
//!          �� ������� GDI �� �����������, � @ref txGDI() ���������� �������� false.
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
//}------------------------------------------------------------------------------------------------------------------------------

#define txGDI( command )  txUnlock ( (txLock(), (command)) )

//}

//===============================================================================================================================
//{          Dialogs
//! @name    ������ � ����������� ������
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

struct txDialog
    {

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

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

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

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

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   �����������.
//! @see     txDialog::txDialog (const txDialog::Layout*)
//!
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    public:
    txDialog();

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   �����������.
//!
//! @param   layout  ����� ����������� ����
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    txDialog (const Layout* layout);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   ����������.
//}------------------------------------------------------------------------------------------------------------------------------

    virtual ~txDialog() {};

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   ������������� ������� ����� ����������� ����.
//!
//! @param   layout  ����� ����������� ����
//!
//! @return  ���������� �����.
//!
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    const Layout* setLayout (const Layout *layout);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   ������� ��������� ��������� ����������� ����.
//!
//! @param   _wnd     ����������
//! @param   _msg     ����� ���������
//! @param   _wParam  1-� �������� ��������� (WORD)
//! @param   _lParam  2-� �������� ��������� (DWORD)
//!
//!          ��� ������� ���� �������������� ��� ��������� ������� ����,
//!          ��� ��������� �� � ������� �������� TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @return  � ����������� ������� false, ��������� ��. DialogProc
//!          � <a href=msdn.com>MSDN</a>.
//!
//! @see     txDialog::dialogBox()
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   ��������� ���������� ����.
//!
//! @param   layout   ����� ����������� ����.\n
//!                     ���� �� ������ - ������������ ��������, �������� txDialog::setLayout()
//!                     ��� ������������� txDialog::txDialog (const txDialog::Layout*).
//! @param   bufsize  ������ ������ ��� �������� ������� ������� (���� �� ������ - ������ �� ���������)
//!
//! @return  ��������, ��������� � ������� EndDialog().\n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    INT_PTR dialogBox (const Layout* layout = NULL, size_t bufsize = 0);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   ��������� ���������� ����.
//!
//! @param   resource  ������������� ����������� �������
//!
//! @return  ��������, ��������� � ������� EndDialog().\n
//!          �� ��������� - ����� ������� <i>(this),</i> ��� �������� ����
//!          �������� txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc()
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   �������� ����������� ����������� � �������� ������������.
//}------------------------------------------------------------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//{------------------------------------------------------------------------------------------------------------------------------
//! ��������� ���������� ������� (�� @ref txDialog::dialogProc(), �.�. ������� ����
//! Win32 ������ ���� �����������).
//}------------------------------------------------------------------------------------------------------------------------------

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//{------------------------------------------------------------------------------------------------------------------------------
//! ������� ����� �������.
//}------------------------------------------------------------------------------------------------------------------------------

    private:
    const Layout* layout_;
    };

//}

//===============================================================================================================================
//{          Message Map macros
//! @name    ������� ��� ���������� ����������� ����� ��������� (Message Map)
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����� ��������� (Message Map).
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#define TX_BEGIN_MESSAGE_MAP()                                                     \
    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)  \
        {                                                                          \
        (void)_wnd; (void)_msg; (void)_wParam; (void)_lParam;                      \
                                                                                   \
        switch (_msg)                                                              \
            {                                                                      \
            case WM_NULL:

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ����� ������ (Command map) � ����� ���������.
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#define TX_COMMAND_MAP                                                             \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        if (_msg == WM_COMMAND) switch (LOWORD (_wParam))                          \
            {                                                                      \
            case 0:

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ����� ���������.
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#define TX_END_MESSAGE_MAP                                                         \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        return FALSE;                                                              \
        }
//}

//===============================================================================================================================
//{          txDialog example: txInputBox()
//! @name    ������ ������������� ������ �������: ������� txInputBox()
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

const char* txInputBox (const char* text = NULL, const char* caption = NULL, const char* input = NULL)
    {
    //---------------------------------------------------------------------------------------------------------------------------
    // ��������� ����� EXE-�����, �� ������, ���� ���-��� ��������� ������ �������� �������
    //---------------------------------------------------------------------------------------------------------------------------

$   char name[256] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1);

    //---------------------------------------------------------------------------------------------------------------------------
    // ���� �� ������� ���������, ������������ �����-����� ������� �������. � ��� ������?..
    //---------------------------------------------------------------------------------------------------------------------------

$   if (!text)    text    = "������� ������:";
$   if (!caption) caption = name;
$   if (!input)   input   = "";

    //---------------------------------------------------------------------------------------------------------------------------
    // �������������� ��������� �������. ��� ��������� � GetDlgItemText().
    // ���� ������ �������� �� �������, � ���������� ��������, �� ��� �������� � ��� �������������.
    // � ��� �� ��� - ������� �����, � ���������. ������� � ���, ��� � ������ ���� ����������������
    // ������ ��������� �������� � ������� ������. ������� ��� ������������� �� ��� ��� �����
    // ��������� �� ����� ����������, �����������. �� ��� ����������, ��� ��� ����� �����������
    // � txDialog::dialogBox() � _tx_DLGTEMPLATE_()... �_�
    //---------------------------------------------------------------------------------------------------------------------------

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    //---------------------------------------------------------------------------------------------------------------------------
    // ������� ������ (����) ������� � ���� ������� ��������.
    // � ������� ������� ������� ����� � ��������� txDialog::Layout � �������� �� ������
    // txDialog ���� ������ ���������� ����� �� �������� ������� ������� � .rc - �����.
    // ��. �������� ���������� rc-����� � ������������ �� Win32 (MSDN, http://msdn.com).
    //---------------------------------------------------------------------------------------------------------------------------

$   txDialog::Layout layout[] =

    //----------------------+-----------+-------------+-----------------+--------------------------------------------------------
    //     ��� ��������     | ���       | ����������- |   ����������    | ����� ���������
    //     �������          | ��������  | ���, ������-|-----------------| (��. �������� ��������� ������� � MSDN).
    //                      |           | ��� � ���   | X | Y |���.|���.|
    //----------------------+-----------+-------------+---+---+----+----+--------------------------------------------------------
    //                      |           |             |   |   |    |    |
        {{ txDialog::DIALOG,   caption,   0,             0,  0, 240,  85                                                     },
         { txDialog::STATIC,   text,      ID_TEXT_,     10, 10, 150,  40, SS_LEFT                                            },
         { txDialog::EDIT,     input,     ID_INPUT_,    10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP  },
         { txDialog::BUTTON,   "&OK",     IDOK,        180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP  },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL,    180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP  },
         { txDialog::END                                                                                                     }};

    //---------------------------------------------------------------------------------------------------------------------------
    // ����� ������� ��� InputBox. ����������, �.�. ����� ��� ���� �������.
    // ����� � �������� ��� ������� ������ ����� (str) � ������� ������� ����������� ����,
    // ��������� Win32 (��� ��������� ��������� TX_BEGIN_MESSAGE_MAP � �������). ����� �� ������
    // ����������� ������, �� ����� ������� ������� �������� ������ � ���������� ������� ���������,
    // � str ��������� ��������� ���� (��� ���������� �� ����� ����� DialogBoxParam � ����������
    // ��� � ����� �� ����� ��������� WM_INITDIALOG).
    //---------------------------------------------------------------------------------------------------------------------------

    struct inputDlg : txDialog
        {
        char str [1024];

        //-----------------------------------------------------------------------------------------------------------------------

        inputDlg() :
            str()                               // ��������� ���� ������. �� �������� �� ������
            {                                   //     ������������, ������� ��� ���:
$           memset (str, 0, sizeof (str) - 1);  // ��������� ���� ������
            }

        //-----------------------------------------------------------------------------------------------------------------------

        TX_BEGIN_MESSAGE_MAP()    // ����� ���������. �� ����� ���� ��� ������ ������� �������.

            TX_COMMAND_MAP        // ����� �������������� WM_COMMAND. �� ����� ���� ��� switch.

                //---------------------------------------------------------------------------------------------------------------
                // ��� ������� ������ OK �������� ������ �� ���� ����� � ���� ���������� str,
                // �.�. ����� �������� ������� ������ ����� ����� � ����� ��� �� ��� ��������.
                // ���� ������ �� ����� ���� ������������ � case �� ��������� switch.
                // _wnd - ��� �������� ������� �������, ��. ����������� ������� TX_BEGIN_MESSAGE_MAP().
                //---------------------------------------------------------------------------------------------------------------

                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP

        //-----------------------------------------------------------------------------------------------------------------------
        // ����� ����������� ������ �������
        //-----------------------------------------------------------------------------------------------------------------------

        };

    //---------------------------------------------------------------------------------------------------------------------------
    // ������� �������, ����� ����� �� ������.
    // �� ����� ��� ���������� "���������� ��������", ��� ����� � ��� ���� �� ������� ��������� -
    // �������. �� ����� ���� ��� ������� ������� ����� #undef. ����� ����������� �� ���������
    // �������, � ��� ����� ������������� �� _. ����� �������� ����� �� ����������� ���� ��� �����
    // ���� ���, ����������, ����� ��� �� �����.
    //---------------------------------------------------------------------------------------------------------------------------

    #undef ID_TEXT_
    #undef ID_INPUT_

    //---------------------------------------------------------------------------------------------------------------------------
    // ��� ����������� ������, ������ ��� ������ � ��� ������ ���� ����� ���������� �������.
    //---------------------------------------------------------------------------------------------------------------------------

$   static inputDlg dlg;

    //---------------------------------------------------------------------------------------------------------------------------
    // �������� layout � ��������� ���� �������
    //---------------------------------------------------------------------------------------------------------------------------

$   dlg.dialogBox (layout);

    //---------------------------------------------------------------------------------------------------------------------------
    // ���������� ����� ������ �� ������������ �������. ��� ����� ������, ������ ��� �����������
    // ������ �� ����� ��� ������ �� ������� � ������ � ���, ��������������, ����. �����
    // ������������� ���������� ���������� ������������� �����, �� ����� � ��������� �������.
    //---------------------------------------------------------------------------------------------------------------------------

$   return dlg.str;
    }

//}

//}

//===============================================================================================================================
//{          TXLib implementation
//! @name    ���������� ������� ����������
//===============================================================================================================================
//! @cond    INTERNAL

//===============================================================================================================================
//{          [Internal] txObject_t class
//! @name    ����� txObject_t
//===============================================================================================================================

struct txObject_t
    {
    bool         _txCleanup();
    void         _txOnExit();

    HWND         _txCanvas_CreateWindow (SIZE size);
    bool         _txCanvas_OK();
    bool         _txConsole_InitSTDIO();
    int          _txCanvas_SetRefreshLock (int count);

    bool         _txCanvas_OnCREATE     (HWND wnd);
    bool         _txCanvas_OnDESTROY    (HWND wnd);
    bool         _txCanvas_OnCLOSE      (HWND);
    bool         _txCanvas_OnPAINT      (HWND wnd);
    bool         _txCanvas_OnCHAR       (HWND wnd, WPARAM ch);
    bool         _txCanvas_OnTIMER      (HWND wnd, WPARAM id);
    bool         _txCanvas_OnMOUSEMOVE  (HWND wnd, WPARAM buttons, LPARAM coords);
    bool         _txCanvas_OnCmdABOUT   (HWND wnd, WPARAM cmd);
    bool         _txCanvas_OnCmdSOURCE  (HWND wnd, WPARAM cmd);

    static unsigned CALLBACK _txCanvas_ThreadProc (void* data);
    static LRESULT  CALLBACK _txCanvas_WndProc    (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);
    };

HDC          _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL);
bool         _txBuffer_Delete (HDC* dc);
bool         _txBuffer_Select (HGDIOBJ obj, HDC dc = txDC());

bool         _txConsole_Attach();
bool         _txConsole_OK();
bool         _txConsole_Detach();
bool         _txConsole_Draw (HDC dc);
HWND         _txConsole_GetWindow();

void*        _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                                     WORD controls, short x, short y, short cx, short cy,
                                     const char caption[], const char font[], WORD fontsize,
                                     HANDLE menu = NULL);
void*        _tx_DLGTEMPLATE_Add    (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                                     short x, short y, short cx, short cy,
                                     WORD id, const char wclass[], const char caption[]);

bool         _txError (const char file[], int line, const char func[],
                       DWORD getlasterror_value, int errno_value, int doserrno_value,
                       const char msg[], ...) _TX_CHECK_FORMAT (7);

#define      _txCheck()         ( txOK() || TX_ERROR ("\a" "���� ��������� �� �������") )

#define      _txWaitFor(cond)   { for (DWORD __t##__LINE__ = GetTickCount() + _TX_TIMEOUT; GetTickCount() < __t##__LINE__; ) \
                                    { $ if ((cond) != 0) break; Sleep (_TX_WINDOW_UPDATE_INTERVAL); } }
//}

//===============================================================================================================================
//{          [Internal] DLL functions import
//! @name    ������ ������� ���������
//===============================================================================================================================

FARPROC _txImport (const char lib[], const char name[], int required = true)
    {
$   HMODULE dll  = LoadLibrary (lib);
$   if (!dll  && required) TX_ERROR ("\a" "Cannot load library \"%s\"" _ lib);
$   if (!dll) return NULL;

$   FARPROC addr = GetProcAddress (dll, name);
$   if (!addr && required) TX_ERROR ("\a" "Cannot import \"%s\" from library \"%s\"" _ name _ lib);

$   return addr;
    }

//-------------------------------------------------------------------------------------------------------------------------------
//{          Import helpers
//! @name    ����� �����������
//-------------------------------------------------------------------------------------------------------------------------------

#define _TX_IMPORT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, true)

#define _TX_IMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, false)

//}

//----------------------------------------------------------------------------
// Some IDEs don't link with these libs by default in console projects, so do sunrise by hand. :(
//{ <tears>

namespace Win32 {

_TX_IMPORT ("GDI32", int,      GetDeviceCaps,          (HDC dc, int index));
_TX_IMPORT ("GDI32", HDC,      CreateCompatibleDC,     (HDC dc));
_TX_IMPORT ("GDI32", HBITMAP,  CreateCompatibleBitmap, (HDC dc, int width, int height));
_TX_IMPORT ("GDI32", HGDIOBJ,  GetStockObject,         (int object));
_TX_IMPORT ("GDI32", HGDIOBJ,  SelectObject,           (HDC dc, HGDIOBJ object));
_TX_IMPORT ("GDI32", HGDIOBJ,  GetCurrentObject,       (HDC dc, UINT objectType));
_TX_IMPORT ("GDI32", int,      GetObjectA,             (HGDIOBJ obj, int bufsize, LPVOID buffer));
_TX_IMPORT ("GDI32", DWORD,    GetObjectType,          (HGDIOBJ object));
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
_TX_IMPORT ("GDI32", BOOL,     Polygon,                (HDC dc, CONST POINT points[], int count));
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

_TX_IMPORT ("USER32",int,      DrawTextA,              (HDC dc, LPCTSTR text, int length, LPRECT rect, UINT format));
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

//} </tears>

//}

//===============================================================================================================================
//{          [Internal] Global data
//! @name    ���������� ������
//           �� ��������� � ��������� ��� �����, ��� ����, ����� ��� ������� �� ���� :)
//===============================================================================================================================

HANDLE           _txMainThread          = NULL;   // ����� ����������� ������ � main()
unsigned         _txMainThreadId        = 0;      // ID ����� ������

HANDLE           _txCanvas_Thread       = NULL;   // ���������� ������, ���������� ����� ������ TXLib
unsigned         _txCanvas_ThreadId     = 0;      // ID ����� ������

HWND             _txCanvas_Wnd          = NULL;   // ���������� ���� ������ TXLib

HDC              _txCanvas_BackBuf[2]   = {NULL,  // [0] Main TXLib memory DC, where user picture lies
                                           NULL}; // [1] Intermediate buffer for console text, also
                                                  //     used in WM_PAINT handling when user frozen
                                                  //     screen auto-update by txBegin()... call.

CRITICAL_SECTION _txCanvas_LockBackBuf  = {0};    // Prevent simultaneous access to back buffer,
                                                  //   see txLock()/txUnlock()

UINT             _txCanvas_RefreshTimer = 0;      // Timer to redraw TXLib window

int              _txCanvas_RefreshLock  = 0;      // Blocks automatic on-timer canvas update,
                                                  //   see txBegin()/txEnd()

HWND             _txConsole_Wnd         = NULL;   // Console window associated to process
bool             _txConsole_IsBlinking  = true;   // To blink or not to blink, that is the question.

bool             _txRunning             = false;  // main() is still running
bool             _txExit                = false;  // exit() is active

POINT            _txMousePos            = {0};
int              _txMouseButtons        =  0;

WNDPROC          _txAltWndProc          = NULL;   // �������������� ������� �������. ��. @ref txSetWindowHandler().

const int        _TX_IDM_ABOUT          = 40000;  // �������������� ���������� ���� ����
const int        _TX_IDM_CONSOLE        = 40001;

//}

//===============================================================================================================================
//{          TXLib engine init/check/cleanup
//! @name    �������������/��������/���������� TXLib
//===============================================================================================================================

//-------------------------------------------------------------------------------------------------------------------------------
//{          Start tracing output
//-------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG

int _txInitTrace = (OutputDebugString ("\n"),
                    OutputDebugString ("The Dumb Artist Library - " _TX_VERSION " " _TX_AUTHOR ": "
                                       "\"" __FILE__ "\", compiled " __DATE__ " " __TIME__ ", "
                                       _TX_BUILDMODE " mode\n"),
                    OutputDebugString ("\n"), 1);
#endif

//}

//-------------------------------------------------------------------------------------------------------------------------------

bool txCreateWindow (int sizeX, int sizeY, bool centered /*= true*/)
    {
$   if (txOK()) return false;

$   atexit (_txOnExit);

$   assert (!_txRunning);
$   _txRunning = false;
$   _txExit    = false;

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   assert (!_txMainThread);
$   DuplicateHandle (GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &_txMainThread,
                     THREAD_SUSPEND_RESUME, FALSE, DUPLICATE_SAME_ACCESS) asserted;
$   assert ( _txMainThread);

$   assert (!_txMainThreadId);
$   _txMainThreadId = GetCurrentThreadId();
$   assert ( _txMainThreadId);

$   _txConsole_Attach() asserted;

$   SIZE size = { sizeX, sizeY };
$   if (centered) { size.cx *= -1; size.cy *= -1; }

    // In Thread, where REAL creation lies...

$   assert (!_txCanvas_Thread); assert (!_txCanvas_ThreadId);
$   _txCanvas_Thread = (HANDLE) _beginthreadex (NULL, 0, _txCanvas_ThreadProc, &size,
                                                CREATE_SUSPENDED, &_txCanvas_ThreadId);

$   _txCanvas_Thread || _txCanvas_ThreadId || TX_ERROR ("\a" "Cannot start canvas thread");
$   if (!_txCanvas_Thread) return false;

$   SetThreadPriority (GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL) asserted;
$   SetThreadPriority (_txCanvas_Thread,   THREAD_PRIORITY_BELOW_NORMAL) asserted;
$   ResumeThread      (_txCanvas_Thread)   asserted;

$   _txWaitFor (_txCanvas_OK());
$   _txCanvas_OK() || TX_ERROR ("\a" "Cannot create canvas window");

$   txSetDefaults();

$   errno = _doserrno = 0;
$   SetLastError (0);
$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txSetDefaults()
    {
$   _txCheck();

$   txUpdateWindow (false);
$   txLock();

//{  Set defaults for graphics layer

$   RECT r = {0};

$   GetClientRect (_txCanvas_Wnd,  &r) asserted;
$   SIZE szCanvas = { r.right - r.left, r.bottom - r.top };

$   GetClientRect (_txConsole_Wnd, &r) asserted;
$   SIZE szCon    = { r.right - r.left, r.bottom - r.top };

$   _txBuffer_Select (GetStockObject (WHITE_PEN),   txDC()) asserted;
$   _txBuffer_Select (GetStockObject (WHITE_BRUSH), txDC()) asserted;
$   _txBuffer_Select (CreateFont (szCon.cy/25, szCon.cx/80, 0, 0,
                                  FW_REGULAR, FALSE, FALSE, FALSE,
                                  DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, DEFAULT_PITCH, _TX_CONSOLE_FONT),
                                  txDC()) asserted;

$   (Win32::SetTextColor (txDC(), TX_WHITE) != CLR_INVALID) asserted;
$    Win32::SetBkMode    (txDC(), TRANSPARENT)              asserted;

$    Win32::SetROP2      (txDC(), R2_COPYPEN)               asserted;

//}

//{  Set defaults for console  layer

$   HDC dc = _txCanvas_BackBuf[1]; dc asserted;

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   SIZE szChr  = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
                    (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

$   SIZE szFont = { (short) ((1.0 * szCon.cx / szChr.cx) / (1.0 * szCon.cx / szCanvas.cx)),
                    (short) ((1.0 * szCon.cy / szChr.cy) / (1.0 * szCon.cy / szCanvas.cy)) };

$   _txBuffer_Select (txFontExist (_TX_CONSOLE_FONT)? CreateFont (szFont.cy, szFont.cx, 0, 0,
                                                                  FW_REGULAR, FALSE, FALSE, FALSE,
                                                                  DEFAULT_CHARSET,
                                                                  OUT_DEFAULT_PRECIS,
                                                                  CLIP_DEFAULT_PRECIS,
                                                                  DEFAULT_QUALITY, FIXED_PITCH,
                                                                  _TX_CONSOLE_FONT)
                                              :
                                              GetStockObject (SYSTEM_FIXED_FONT),
               dc) asserted;

$   Win32::SetTextColor (dc, _TX_CONSOLE_COLOR);
$   Win32::SetBkMode    (dc, TRANSPARENT) asserted;

//}

$   txUnlock();
$   txUpdateWindow (true);

    return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool txOK()
    {
$   return _txCanvas_OK() && _txConsole_OK();
    }

//-------------------------------------------------------------------------------------------------------------------------------

void _txOnExit()
    {
$   _txRunning = false;

$   char title [1024] = "";
$   GetWindowText (txWindow(), title, sizeof (title) - 1);
$   strncat_s (title, " [���������]", sizeof (title) - 1);
$   SetWindowTextA (txWindow(), title);

$   if (GetCurrentThreadId() != _txCanvas_ThreadId)
        { $ (WaitForSingleObject (_txCanvas_Thread, INFINITE) == WAIT_OBJECT_0) asserted; }

$   if (_txMainThread)    CloseHandle (_txMainThread)    asserted; _txMainThread    = NULL;
$   if (_txCanvas_Thread) CloseHandle (_txCanvas_Thread) asserted; _txCanvas_Thread = NULL;

$   _txConsole_Detach();

$   DeleteCriticalSection (&_txCanvas_LockBackBuf);

#ifndef NDEBUG
    OutputDebugString ("\n");
    OutputDebugString (_TX_VERSION " -- FINISHED\n");
    OutputDebugString ("\n");
#endif
    }

//}

//===============================================================================================================================
//{          [Internal] Main window functions      (_txCanvas...)
//! @name    ������� ��������� ����                (_txCanvas...)
//===============================================================================================================================

unsigned CALLBACK _txCanvas_ThreadProc (void* data)
    {
$   assert (data);
$   if (!data) return WM_SIZE;

$   _txCanvas_Wnd = _txCanvas_CreateWindow (*(SIZE*) data);
$   _txCanvas_Wnd || TX_ERROR ("\a" "Cannot create canvas: _txCanvas_CreateWindow() failed");

$   _txRunning = true;

$   MSG msg = {0};
$   while (GetMessage (&msg, NULL, 0, 0))
        {
$       TranslateMessage (&msg);
$       DispatchMessage  (&msg);
$       Sleep (0);

        // main() finished, but we don't need to pause, so destroying ourselves.
        // See txDisableAutoPause().

$       if (!_txRunning && _txExit && _txCanvas_Wnd)
            { $ DestroyWindow (_txCanvas_Wnd) asserted; }
        }

    // The window is destroyed but main() is still running.
    // No chances for good termination, so use exit().

$   if (_txRunning)
        { $ exit (msg.wParam); }

$   _txCanvas_ThreadId = 0;
$   return msg.wParam;
    }

//-------------------------------------------------------------------------------------------------------------------------------

HWND _txCanvas_CreateWindow (SIZE clientSize)
    {
$   const char className[] = ">>>>> " _TX_VERSION " - " __FILE__ " - _txCanvas Class" " <<<<<";

$   WNDCLASSEX wc    = {0};
$   wc.cbSize        = sizeof (wc);
$   wc.style         = CS_HREDRAW | CS_VREDRAW;
$   wc.lpfnWndProc   = _txCanvas_WndProc;
$   wc.hInstance     = NULL;
$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) GetStockObject (HOLLOW_BRUSH);
$   wc.lpszClassName = className;
$   RegisterClassEx (&wc) || TX_ERROR ("\a" "RegisterClass (\"%s\") failed"_ className);

$   char name[256] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1) asserted;
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
$       RECT r = {0}; GetWindowRect (_txConsole_Wnd, &r) asserted;
$       center.x = (r.right + r.left) / 2;
$       center.y = (r.bottom + r.top) / 2;
        }

$   assert (!_txCanvas_Wnd);

$   _txCanvas_Wnd = CreateWindowEx (0, className, title, WS_POPUP | WS_BORDER | WS_CAPTION | WS_SYSMENU,
                    center.x - size.cx/2, center.y - size.cy/2, size.cx, size.cy,
                    NULL, NULL, NULL, NULL);

$   _txCanvas_Wnd || TX_ERROR ("\a" "Cannot create canvas: CreateWindowEx (\"%s\") failed"_ className);

$   ShowWindow          (_txCanvas_Wnd, SW_SHOW);
$   SetForegroundWindow (_txCanvas_Wnd) asserted;
$   UpdateWindow        (_txCanvas_Wnd) asserted;

$   if (_txConsole_OK())
        { $ SetWindowPos (_txConsole_Wnd, HWND_NOTOPMOST, center.x - size.cx*2/5, center.y - size.cy*2/5, 0, 0,
                          SWP_NOSIZE | SWP_NOACTIVATE | _TX_CONSOLE_MODE) asserted; }

$   HMENU menu = GetSystemMenu (_txCanvas_Wnd, false);       menu asserted;
$   AppendMenu (menu, MF_SEPARATOR, 0, NULL)                      asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_CONSOLE, "Show Console") asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_ABOUT,   "About...")     asserted;

$   CheckMenuItem (menu, _TX_IDM_CONSOLE,
                   _txConsole_OK()? (IsWindowVisible (_txConsole_Wnd)? MF_CHECKED : 0) : MF_DISABLED);

$   return _txCanvas_Wnd;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool _txCanvas_OK()
    {
$   return _txCanvas_Thread     &&
           _txCanvas_Wnd        &&
           _txCanvas_BackBuf[0] &&
           _txCanvas_BackBuf[1];
    }

//-------------------------------------------------------------------------------------------------------------------------------

int _txCanvas_SetRefreshLock (int count)
    {
$   int oldCount = _txCanvas_RefreshLock;

$   _txCanvas_RefreshLock = count;

$   if (_txCanvas_RefreshLock <= 0 || oldCount <= 0)
        if (_txCanvas_Wnd)
            {
$           InvalidateRect (_txCanvas_Wnd, NULL, false);
$           UpdateWindow   (_txCanvas_Wnd);
            }

$   return oldCount;
    }

//}

//===============================================================================================================================
//{          [Internal] Main window event handlers (_txCanvas_On...)
//! @name    ������� ��������� ����                (_txCanvas_On...)
//===============================================================================================================================

bool _txCanvas_OnCREATE (HWND wnd)
    {
$   assert (wnd); assert (!_txCanvas_Wnd);

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); _txCanvas_BackBuf[0] asserted;
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); _txCanvas_BackBuf[1] asserted;

$   SetTimer (wnd, _txCanvas_RefreshTimer, _TX_WINDOW_UPDATE_INTERVAL, NULL) asserted;

$   _txCanvas_Wnd = wnd;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnDESTROY (HWND wnd)
    {
$   assert (wnd);

    // ���������� ��������� ����� ���������

$   PostQuitMessage (_txRunning? WM_DESTROY : EXIT_SUCCESS);

$   if (!_txCanvas_Wnd) return false;

    // Indicate that we are about to terminate

$   _txExit = true;
$   SetThreadPriority (GetCurrentThread(), THREAD_PRIORITY_NORMAL) asserted;
$   SetThreadPriority (_txMainThread,      THREAD_PRIORITY_NORMAL) asserted;

    // Lock GDI resources

$   bool locked = false;
$   _txWaitFor (locked = txLock (false));

$   if (!locked) TX_ERROR ("Cannot lock GDI to free resources");

    // Prevent drawing operations by suspending main thread. If the GDI resources
    // were not locked, allow the thread to run, possible causing error messages
    // when the resources will be destroyed. Suspending a thread which keep
    // the resources locked will lead to deadlock.

$   if (_txRunning && locked)
        { $ (SuspendThread (_txMainThread) != -1U) asserted; }

    // ����������� �������, ��������� � �����

$   if (_txCanvas_BackBuf[0]) _txBuffer_Delete (&_txCanvas_BackBuf[0])  asserted;
$   if (_txCanvas_BackBuf[1]) _txBuffer_Delete (&_txCanvas_BackBuf[1])  asserted;

$   if (_txCanvas_RefreshTimer) KillTimer (wnd, _txCanvas_RefreshTimer) asserted;

    // Indicate that we are destroyed

$   _txCanvas_Wnd = NULL;

$   txUnlock();

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCLOSE (HWND wnd)
    {
$   assert (wnd); assert (wnd == _txCanvas_Wnd);
$   assert (_txCanvas_OK());

$   if (!wnd || !_txCanvas_OK()) return false;

$   char name[256] = __FILE__;
$   GetModuleFileName (NULL, name, sizeof (name) - 1) asserted;

$   if (_txRunning &&
        MessageBox (wnd, "������� main() �� ���������. "
                    "��������� ��� ��� ��������. ��������?    ", name,
                     MB_OKCANCEL | MB_ICONSTOP) != IDOK) return false;
$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnPAINT (HWND wnd)
    {
$   assert (wnd); assert (wnd == _txCanvas_Wnd);
$   assert (_txCanvas_OK());

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
$     Win32::BitBlt (_txCanvas_BackBuf[1], 0, 0, size.x, size.y, txDC(), 0, 0, SRCCOPY);

$     if (_txConsole_OK())
          { $ _txConsole_Draw (_txCanvas_BackBuf[1]); }
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

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCHAR (HWND, WPARAM ch)
    {
$   assert (_txCanvas_OK());

$   INPUT_RECORD evt = {0};

$   evt.EventType                        = KEY_EVENT;
$   evt.Event.KeyEvent.bKeyDown          = true;
$   evt.Event.KeyEvent.wRepeatCount      = 1;
$   evt.Event.KeyEvent.wVirtualKeyCode   = 0;
$   evt.Event.KeyEvent.wVirtualScanCode  = 0;
$   evt.Event.KeyEvent.uChar.AsciiChar   = (unsigned char) ch;
$   evt.Event.KeyEvent.dwControlKeyState = 0;

$   DWORD written = 0;
$   WriteConsoleInput (GetStdHandle (STD_INPUT_HANDLE), &evt, 1, &written) asserted;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnMOUSEMOVE (HWND, WPARAM buttons, LPARAM coords)
    {
$   assert (_txCanvas_OK());

$   if (_txCanvas_OK()) return false;

$   _txMousePos.x   = LOWORD (coords);
$   _txMousePos.y   = HIWORD (coords);
$   _txMouseButtons = (int) buttons;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnTIMER (HWND wnd, WPARAM)
    {
$   assert (wnd); assert (wnd == _txCanvas_Wnd);
$   assert (_txCanvas_OK());

$   if (!wnd || !_txCanvas_OK())   return false;

$   if (_txCanvas_RefreshLock > 0) return false;

$   InvalidateRect (_txCanvas_Wnd, NULL, false) asserted;
$   UpdateWindow   (_txCanvas_Wnd)              asserted;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd)
    {
$   assert (wnd); assert (wnd == _txCanvas_Wnd);
$   assert (_txCanvas_OK());

$   if (!wnd || !_txCanvas_OK()) return false;

$   assert (_txConsole_OK());

$   bool visible = IsWindowVisible (_txConsole_Wnd) != 0;

$   ShowWindow (_txConsole_Wnd, visible? SW_HIDE : SW_SHOW);

$   visible = IsWindowVisible (_txConsole_Wnd) != 0;
$   CheckMenuItem (GetSystemMenu (wnd, false), (int)cmd, visible? MF_CHECKED : MF_UNCHECKED);

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

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

$   time_t timeT      = time (NULL) - clock()/CLOCKS_PER_SEC;
$   char   timeS[100] = "";

#ifdef  _TX_USE_SECURE_CRT
$   ctime_s  (timeS, sizeof (timeS), &timeT);
#else
$   strncpy (timeS, ctime (&timeT), sizeof (timeS) - 1);
#endif

$   char name[1024] = ""; (GetModuleFileName (NULL, name, sizeof (name) - 1))         asserted;
$   char cwd [1024] = ""; (_getcwd           (cwd,        sizeof (cwd)  - 1) && true) asserted;
$   char text[1024] = "";

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
                 _TX_AUTHOR EOL_
                 "See license and more on: http://ded32.net.ru" EOL_ "\n"

                 "TXLib file:" "\t" __FILE__ EOL_
                 "Compiler:"   "\t" __TX_COMPILER__ EOL_
                 "Compiled:"   "\t" __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode" EOL_ "\n"

                 "Run file:"   "\t" "%s" EOL_
                 "From dir:"   "\t" "%s" EOL_
                 "Started:"    "\t" "%.6s %.4s %.8s",

                 name, cwd,
                 timeS + 4, timeS + 20, timeS + 11);  // These offsets are standardized by ANSI
    #undef EOL_

$   MessageBox (txWindow(), text, "About " ABOUT_NAME_, MB_ICONINFORMATION);

//  And a bit of HTTP-code in C++ function:

    goto http;
    http://ded32.net.ru                               // See valuable refs here :)

$   return true;

    #undef ABOUT_NAME_
    }

//-------------------------------------------------------------------------------------------------------------------------------

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

//}

//===============================================================================================================================
//{          [Internal] Console-support functions  (_txConsole...)
//! @name    ������� ����������� ����              (_txConsole...)
//===============================================================================================================================

bool _txConsole_Attach()
    {
$   assert (!_txConsole_Wnd);

#if (_TX_CONSOLE_MODE != SWP_HIDEWINDOW)
$   if (!_txConsole_GetWindow())
#endif
        {
$       FreeConsole();
$       AllocConsole();

$       HANDLE con = GetStdHandle (STD_OUTPUT_HANDLE); con asserted;
$       COORD size = { 80, 25 };
$       if (con) SetConsoleScreenBufferSize (con, size);
        }

$   _txConsole_Wnd = _txConsole_GetWindow();

$   _txConsole_InitSTDIO() asserted;

$   return _txConsole_Wnd != NULL;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txConsole_InitSTDIO()
    {
$   static bool done = false;
$   if (done) return false;

$   int crtIn  = _open_osfhandle ((ptrdiff_t) GetStdHandle (STD_INPUT_HANDLE),  _O_TEXT);
$   int crtOut = _open_osfhandle ((ptrdiff_t) GetStdHandle (STD_OUTPUT_HANDLE), _O_TEXT);

$   *stdin  = * _fdopen (crtIn,  "r");
$   *stdout = * _fdopen (crtOut, "w");

$   setvbuf (stdin,  NULL, _IONBF, 0);
$   setvbuf (stdout, NULL, _IONBF, 0);

$   std::ios::sync_with_stdio();

$   SetConsoleCP       (1251);
$   SetConsoleOutputCP (1251);

$     setlocale (LC_CTYPE,  "Russian");
$   _wsetlocale (LC_CTYPE, L"Russian_Russia.ACP");

$   done = true;

$   return !ferror (stdin)  &&
           !ferror (stdout) &&
           std::cin.good()  &&
           std::cout.good();
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool _txConsole_OK()
    {
$   return _txConsole_Wnd != NULL;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txConsole_Detach()
    {
$   FreeConsole();
$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txConsole_Draw (HDC dc)
    {
$   assert (_txConsole_OK()); assert (_txCanvas_OK());

$   if (!txLock (false)) return false;

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   SIZE fontSz = {0};
$   txGDI (Win32::GetTextExtentPoint32 (dc, "W", 1, &fontSz)) asserted;

$   int sizeX = con.srWindow.Right - con.srWindow.Left + 1;
$   for (SHORT y = con.srWindow.Top; y <= con.srWindow.Bottom; y++)
        {
        static TCHAR buf [1024 + 1] = ""; // [con.dwSize.X + 1]
        COORD coord = { 0, y };
        DWORD read  =   0;

        ReadConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
                                    buf, sizeof (buf), coord, &read) asserted;

        Win32::TextOut (dc, 0, y*fontSz.cy, buf + con.srWindow.Left, sizeX) asserted;
        }

$   if (_txConsole_IsBlinking &&
        GetTickCount() % _TX_CURSOR_BLINK_INTERVAL*2 > _TX_CURSOR_BLINK_INTERVAL &&
        In (con.dwCursorPosition, con.srWindow))
        {
$       Win32::TextOut (dc, (con.dwCursorPosition.X - con.srWindow.Left)*fontSz.cx,
                            (con.dwCursorPosition.Y - con.srWindow.Top) *fontSz.cy + 1, "_", 1)
                        asserted;
        }

$   txUnlock();

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

HWND _txConsole_GetWindow()
    {
$   static _TX_IMPORT_OPT ("Kernel32", HWND, GetConsoleWindow, ());
$   if (GetConsoleWindow) return GetConsoleWindow();

$   SetLastError (0);

$   char title[1024] = "";
$   GetConsoleTitle (title, sizeof (title) - 1);

$   char unique [128] = "";
$   LARGE_INTEGER time = {{0}};
$   QueryPerformanceCounter (&time) asserted;

$   _snprintf_s (unique, sizeof (unique) - 1, __FILE__ "%s (%d) Temp Title %08lx%08lx",
                 __FILE__, __LINE__, time.HighPart, time.LowPart);

$   SetConsoleTitle (unique) asserted;

$   HWND con = NULL;
$   _txWaitFor (con = FindWindow (NULL, unique));

$   SetConsoleTitle (title) asserted;

$   con || TX_ERROR ("Cannot find console window");

$   SetLastError (0);
$   return con;
    }

//}

//===============================================================================================================================
//{          [Internal] Memory DC functions        (_txBuffer...)
//! @name    ������� "������������ ������" (������������ ������, _txBuffer...)
//===============================================================================================================================

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bitmap)
    {
$   txLock();

$   HDC wndDC = GetDC (wnd); wndDC asserted; if (!wndDC) return NULL;

$   (Win32::GetDeviceCaps (wndDC, RASTERCAPS) & RC_BITBLT) || TX_ERROR ("GetDeviceCaps(): RASTERCAPS: RC_BITBLT not supported");

$   RECT r = {0};
$   GetClientRect (wnd, &r) asserted;
$   POINT sz = { r.right - r.left, r.bottom - r.top };
$   if (!size) size = &sz;

$   HDC dc = Win32::CreateCompatibleDC (wndDC);
$   dc || TX_ERROR ("Cannot create buffer: CreateCompatibleDC() failed");

$   HBITMAP bmap = bitmap? bitmap : Win32::CreateCompatibleBitmap (wndDC, size->x, size->y);
$   bmap || TX_ERROR ("Cannot create buffer: CreateCompatibleBitmap() failed");

$   Win32::SelectObject (dc, bmap) asserted;

$   if (!bitmap) Win32::PatBlt (dc, 0, 0, size->x, size->y, BLACKNESS) asserted;

$   ReleaseDC (wnd, wndDC) asserted;

$   txUnlock();
$   return dc;
    }

//-------------------------------------------------------------------------------------------------------------------------------

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
$   Win32::DeleteObject (Win32::GetCurrentObject (*dc, OBJ_REGION));

$   Win32::DeleteDC (*dc) asserted;

$   *dc = NULL;

$   txUnlock();
$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txBuffer_Select (HGDIOBJ obj, HDC dc /*= txDC()*/)
    {
$   assert (obj); assert (dc);
$   (obj && GetObjectType (obj)) || TX_ERROR ("Invalid GDI object type");

$   txLock();

$   obj = Win32::SelectObject (dc, obj);
$   if (obj) Win32::DeleteObject (obj) asserted;

$   txUnlock();

$   return obj != NULL;
    }

//}

//===============================================================================================================================
//{          Diagnostics
//! @name    �����������
//===============================================================================================================================

bool _txError (const char file[], int line, const char func[],
               DWORD winerr, int crterr, int doserr,
               const char msg[], ...)
    {
    const size_t MAXSTR = 1024;

    if (winerr == (DWORD) -1) winerr = GetLastError();
    if (crterr ==         -1) crterr = errno;
    if (doserr ==         -1) doserr = _doserrno;

    unsigned threadId = GetCurrentThreadId();

    if (!_txRunning) _txConsole_InitSTDIO();

    bool fatal = (msg && *msg == '\a')? (msg++, true) : false;

    va_list arg; va_start (arg, msg);

    #ifdef  _TX_USE_SECURE_CRT
        #define SZARG_(n)  sizeof (str) - (n) - (s-str), _TRUNCATE

    #else
        #define SZARG_(n)  sizeof (str) - (n) - (s-str)

    #endif

    char str[MAXSTR] = "", *s = str;

                s +=  _snprintf_s (s, SZARG_ (1), "TX_ERROR() ��������:" "\v\v");

    if (file)   s +=  _snprintf_s (s, SZARG_ (1), "����: %s"    ", ",     file);
    if (line)   s +=  _snprintf_s (s, SZARG_ (1), "������: %d"  "    \v", line);
    if (func)   s +=  _snprintf_s (s, SZARG_ (1), "�������: %s" "    \v", func);

                s +=  _snprintf_s (s, SZARG_ (1), "\v");

    if (msg)    s +=  _snprintf_s (s, SZARG_ (1), "���������: "),
                s += _vsnprintf_s (s, SZARG_ (1), msg, arg),
                s +=  _snprintf_s (s, SZARG_ (1), "    \v\v");

                s +=  _snprintf_s  (s, SZARG_ (1), "Thread: 0x%08X%s", threadId,
                                                    threadId == _txMainThreadId?    " (Main thread)"   :
                                                    threadId == _txCanvas_ThreadId? " (Canvas thread)" :
                                                                                    "");

    if (winerr) s +=  _snprintf_s  (s, SZARG_ (0), ", GetLastError(): %lu (", winerr),
                s += FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                    NULL, winerr, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                                    s, (DWORD) (sizeof (str) - (s-str)), NULL) - 3,
                s +=  _snprintf_s  (s, SZARG_ (1), ")");

    if (crterr) s +=  _snprintf_s  (s, SZARG_ (1), ", errno: %lu (%s)",
                                    crterr, strerror (crterr));

    if (doserr) s +=  _snprintf_s  (s, SZARG_ (1), ", _doserrno: %lu (%s)",
                                    doserr, strerror (doserr));

                s +=  _snprintf_s  (s, SZARG_ (1), ".%s    \n",
                                    std::uncaught_exception()? "std::uncaught_exception(): true." : "");
    #undef SZARG_

    OutputDebugString (str);

    for (char* p = strchr (str, '\v'); p; p = strchr (p+1, '\v')) *p = '\n';

    printf ("\n" "--------------------------------------------------" "\n"
                 "%s"
                 "--------------------------------------------------" "\n", str);

    MessageBox (NULL, str, fatal? "��������� ������" : "������ � ���������",
                MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

    va_end (arg);

    if (fatal)
        {
        if (!IsDebuggerPresent()) exit (EXIT_FAILURE);

/* > */ DebugBreak(); // >>> �� � ���������, ���� ���� ���������� ���������� � �����������.
        }             //     �������� �� ������� ��������� ��������. �������� �� ���� �������.

    return false;
    }

//}

//===============================================================================================================================
//{          TXLib API implementation
//! @name    ���������� TXLib API
//===============================================================================================================================

inline
const char* txVersion()
    {
$   return _TX_VERSION;
    }

//-------------------------------------------------------------------------------------------------------------------------------

POINT txGetExtent()
    {
$   _txCheck();

$   RECT r = {0};
$   GetClientRect (txWindow(), &r);
$   POINT size = { r.right - r.left, r.bottom - r.top };
$   return size;
    }

//-------------------------------------------------------------------------------------------------------------------------------

int txGetExtentX()
    {
$   return txGetExtent().x;
    }

//-------------------------------------------------------------------------------------------------------------------------------

int txGetExtentY()
    {
$   return txGetExtent().y;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
HDC& txDC()
    {
$   return _txCanvas_BackBuf[0];
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
HWND txWindow()
    {
$   return _txCanvas_Wnd;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txSetColor (COLORREF color, int thickness /*= 1*/)
    {
$   _txCheck();

$   return _txBuffer_Select (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), thickness, color)) &&
            txGDI          ((Win32::SetTextColor (txDC(), color) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txColor (double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetColor (RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

//-------------------------------------------------------------------------------------------------------------------------------

COLORREF txGetColor()
    {
$   _txCheck();

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_PEN))); obj asserted;

$   char buf [MAX (sizeof (LOGPEN), sizeof (EXTLOGPEN))] = {0};

$   int size = GetObject (obj, 0, NULL);
$   GetObject (obj, sizeof (buf), buf) asserted;

$   return (size == sizeof (LOGPEN))? ((LOGPEN*)buf)->lopnColor : ((EXTLOGPEN*)buf)->elpColor;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txSetFillColor (COLORREF color)
    {
$   _txCheck();

$   return _txBuffer_Select ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                                 Win32::CreateSolidBrush (color));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txFillColor (double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetFillColor (RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

//-------------------------------------------------------------------------------------------------------------------------------

COLORREF txGetFillColor()
    {
$   _txCheck();

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); obj asserted;

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) asserted;

$   return buf.lbColor;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txSetROP2 (int mode /*= R2_COPYPEN*/)
    {
$   _txCheck();

$   return txGDI ((Win32::SetROP2 (txDC(), mode) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txClear()
    {
$   _txCheck();

$   POINT size = txGetExtent();
$   return txGDI ((Win32::PatBlt (txDC(), 0, 0, size.x, size.y, PATCOPY) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool txSetPixel (int x, int y, COLORREF color)
    {
$   _txCheck();

$   txGDI ((Win32::SetPixel (txDC(), x, y, color)));

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool txPixel (int x, int y, double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetPixel (x, y, RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
COLORREF txGetPixel (int x, int y)
    {
$   _txCheck();

$   return txGDI ((Win32::GetPixel (txDC(), x, y)));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txLine (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   txGDI ((Win32::MoveToEx (txDC(), x0, y0, NULL))) asserted;
$   txGDI ((Win32::LineTo   (txDC(), x1, y1      ))) asserted;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txRectangle (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   txGDI ((Win32::Rectangle (txDC(), x0, y0, x1, y1))) asserted;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints)
    {
$   _txCheck();

$   return txGDI ((Win32::Polygon (txDC(), points, numPoints) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txEllipse (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   txGDI ((Win32::Ellipse (txDC(), x0, y0, x1, y1))) asserted;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txCircle (int x, int y, int r)
    {
$   return txEllipse (x-r, y-r, x+r, y+r);
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txArc (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txCheck();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI ((Win32::Arc (txDC(), x0, y0, x1, y1,
                                       (int) (center.x + 100 * cos (start) + 0.5),
                                       (int) (center.y - 100 * sin (start) + 0.5),
                                       (int) (center.x + 100 * cos (end)   + 0.5),
                                       (int) (center.y - 100 * sin (end)   + 0.5)) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txPie (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txCheck();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI ((Win32::Pie (txDC(), x0, y0, x1, y1,
                                       (int) (center.x + 100 * cos (start) + 0.5),
                                       (int) (center.y - 100 * sin (start) + 0.5),
                                       (int) (center.x + 100 * cos (end)   + 0.5),
                                       (int) (center.y - 100 * sin (end)   + 0.5)) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txChord (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txCheck();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI ((Win32::Chord (txDC(), x0, y0, x1, y1,
                                         (int) (center.x + 100 * cos (start) + 0.5),
                                         (int) (center.y - 100 * sin (start) + 0.5),
                                         (int) (center.x + 100 * cos (end)   + 0.5),
                                         (int) (center.y - 100 * sin (end)   + 0.5)) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txFloodFill (int x, int y,
                  COLORREF color /*= TX_TRANSPARENT*/, DWORD mode /*= FLOODFILLSURFACE*/)
    {
$   _txCheck();

$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y);

$   return txGDI ((Win32::ExtFloodFill (txDC(), x, y, color, mode) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txTextOut (int x, int y, const char text[])
    {
$   _txCheck();

$   txGDI ((Win32::TextOut (txDC(), x, y, text, (int) strlen (text)))) asserted;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format /*= DT_CENTER | DT_VCENTER | DT_WORDBREAK |
                                   DT_MODIFYSTRING | DT_PATH_ELLIPSIS*/)
{
$   _txCheck();

$   RECT r = { x0, y0, x1, y1 };

$   if (!strchr (text, '\n')) format |= DT_SINGLELINE;

$   unsigned prev = txSetTextAlign (TA_LEFT | TA_TOP | TA_NOUPDATECP);
$   txGDI ((Win32::DrawText (txDC(), text, -1, &r, format))) asserted;
$   txSetTextAlign (prev);

$   return true;
}

//-------------------------------------------------------------------------------------------------------------------------------

bool txSelectFont (const char name[], int sizeY,
                   int sizeX      /*= -1*/,
                   int  bold      /*= FW_DONTCARE*/,
                   bool italic    /*= false*/,
                   bool underline /*= false*/,
                   bool strikeout /*= false*/)
    {
$   _txCheck();

$   _txBuffer_Select (txFontExist (name)? CreateFont (sizeY, (int) ((sizeX != -1)? sizeX : sizeY/3), 0, 0,
                                               bold, italic, underline, strikeout,
                                               DEFAULT_CHARSET,
                                               OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                               DEFAULT_QUALITY, FIXED_PITCH, name)
                                   :
                                   GetStockObject (SYSTEM_FIXED_FONT));
$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[])
    {
$   _txCheck();

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, (int) strlen (text), &size))) asserted;

$   return size;
    }

//-------------------------------------------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[])
    {
$   return txGetTextExtent (text) .cx;
    }

//-------------------------------------------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[])
    {
$   return txGetTextExtent (text) .cy;
    }

//-------------------------------------------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align /*= TA_CENTER | TA_BASELINE*/)
    {
$   _txCheck();

$   return txGDI ((Win32::SetTextAlign (txDC(), align)));
    }

//-------------------------------------------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[])
    {
$   _txCheck();

$   static LOGFONT font = {0};
$   font.lfCharSet = DEFAULT_CHARSET;
$   strncpy_s (font.lfFaceName, name, sizeof (font.lfFaceName) - 1);

    struct enumFonts
        {
        static int CALLBACK Proc (const LOGFONT* fnt, const TEXTMETRIC*, DWORD, LPARAM data)
            {
$           assert (fnt); assert (data); if (! (data && fnt)) return 0;
#ifndef __STRICT_ANSI__
$           return _strnicmp (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
#else
$           return  strncmp  (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
#endif
            }
        };

$   return txGDI ((Win32::EnumFontFamiliesEx (txDC(), &font, enumFonts::Proc, (LPARAM)&font, 0) == 0? &font : NULL));
    }

//-------------------------------------------------------------------------------------------------------------------------------

HRGN txSelectRegion (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   HRGN rgn = Win32::CreateRectRgn (x0, y0, x1, y1);

$   txSelectObject (rgn) asserted;

$   return rgn;
    }
//-------------------------------------------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj)
    {
$   _txCheck();

$   return _txBuffer_Select (obj);
    }

//-------------------------------------------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (int sizeX, int sizeY, HBITMAP bitmap /*= NULL*/)
    {
$   _txCheck();

$   POINT size = { sizeX, sizeY };
$   HDC dc = _txBuffer_Create (txWindow(), &size, bitmap); dc asserted;

$   return dc;
    }

//-------------------------------------------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[])
    {
$   _txCheck();

$   HBITMAP image = (HBITMAP) LoadImage (NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
$   if (!image) return NULL;

$   HDC dc = txCreateCompatibleDC (0, 0, image);

$   return dc;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txDeleteDC (HDC dc)
    {
$   _txCheck();

$   return _txBuffer_Delete (&dc);
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txDeleteDC (HDC* dc)
    {
$   _txCheck();

$   return _txBuffer_Delete (dc);
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txBitBlt (HDC dest, int xDest, int yDest, int width, int height,
               HDC src,  int xSrc,  int ySrc,  DWORD rOp /*= SRCCOPY*/)
    {
$   _txCheck();

$   return txGDI ((Win32::BitBlt (dest, xDest, yDest, width, height,
                                  src,  xSrc,  ySrc, rOp) != 0));
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, int xDest, int yDest, int width, int height,
                       HDC src,  int xSrc,  int ySrc,  COLORREF transColor /*= TX_BLACK*/)
    {
$   _txCheck();

$   if (!TransparentBlt) return false;

$   return Win32::TransparentBlt (dest, xDest, yDest, width, height,
                                  src,  xSrc,  ySrc,  width, height, transColor) != 0;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, int xDest, int yDest, int width, int height,
                   HDC src,  int xSrc,  int ySrc,  double alpha /*= 1.0*/)
    {
$   _txCheck();

$   if (!AlphaBlend) return false;

$   if (alpha < 0) alpha = 0;
$   if (alpha > 1) alpha = 1;

    #ifndef AC_SRC_ALPHA
    #define AC_SRC_ALPHA 0x01   // On some old MinGW/MSVC versions, this is not defined.
    #endif

$   BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) (alpha * 255 + 0.5), AC_SRC_ALPHA };

$   return Win32::AlphaBlend (dest, xDest, yDest, width, height,
                              src,  xSrc,  ySrc,  width, height, blend) != 0;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
int txUpdateWindow (int update /*= true*/)
    {
$   return _txCanvas_SetRefreshLock (update >= 0? !update : -update);
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
int txBegin()
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock + 1);

$   return _txCanvas_RefreshLock;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
int txEnd()
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock - 1);

$   return _txCanvas_RefreshLock;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool txSleep (int time)
    {
    _txCheck();

$   int old = _txCanvas_SetRefreshLock (0);

$   Sleep (time);

$   _txCanvas_SetRefreshLock (old);

$   return old != 0;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool txLock (bool wait /*= true*/)
    {
$   if (_txExit) Sleep (0);

$   if (wait) { $ return    EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { $ return TryEnterCriticalSection (&_txCanvas_LockBackBuf) != 0;  }
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool txUnlock()
    {
$   LeaveCriticalSection (&_txCanvas_LockBackBuf);

$   if (_txExit) Sleep (0);
$   return false;
    }

//-------------------------------------------------------------------------------------------------------------------------------

template <typename T>
inline
T txUnlock (T value)
    {
$   txUnlock();
$   return value;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
POINT txMousePos()
    {
$   return _txMousePos;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
int txMouseX()
    {
$   return _txMousePos.x;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
int txMouseY()
    {
$   return _txMousePos.y;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
int txMouseButtons()
    {
$   return _txMouseButtons;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] /*= NULL*/, DWORD mode /*= SND_ASYNC*/)
    {
$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;

$   if (!filename) mode = SND_PURGE;

$   return PlaySound (filename, NULL, mode) != 0;
    }

//-------------------------------------------------------------------------------------------------------------------------------

WNDPROC txSetWindowHandler (WNDPROC handler /*= NULL*/)
    {
$   WNDPROC old = _txAltWndProc; _txAltWndProc = handler;
$   return  old;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txTextCursor (bool blink /*= true*/)
    {
$   bool old = _txConsole_IsBlinking;

$   _txConsole_IsBlinking = blink;

$   return old;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()
    {
$   MessageBox (txWindow(),
                "��� ��������������� ������. ����� ������. �� ������ �������:" "\n\n"
                "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()" "\n\n"
                "���� �� ����� [����������]�������� ��� ���, �� ����� ���� ��� ������� �� ��������." "\n"
                "�� ��� ��� ���� ���������� �������. ��. ����������� ���� ������� � �������� ������� ����������." "\n\n",
                "�� ����������", MB_ICONSTOP);

    // The truth is out there...

$   return false;
    }

//-------------------------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

// Bingo! Now you are learned to use the Sources, Luke. And may the Source be with you.

inline
bool txDisableAutoPause()
    {
$   _txExit = true;
$   return true;
    }

//! @endcond
//-------------------------------------------------------------------------------------------------------------------------------

double txQueryPerformance()
    {
    double time = 0;

    for (int i = 0; i < 10; i++)
        {
        LARGE_INTEGER ticks0 = {{0}}, ticks1 = {{0}};

        QueryPerformanceCounter (&ticks0) asserted;
        Sleep (_TX_WINDOW_UPDATE_INTERVAL);
        QueryPerformanceCounter (&ticks1) asserted;

        time += ticks1.QuadPart - ticks0.QuadPart;
        }

    return time / double (10 * _TX_WINDOW_UPDATE_INTERVAL) / 1024/1024;
    }

//-------------------------------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------------------------

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

//}

//===============================================================================================================================
//{          txDialog methods implementation
//! @name    ���������� ������� ������ txDialog
//===============================================================================================================================

txDialog::txDialog () :
    layout_ (NULL)
    {$}

//-------------------------------------------------------------------------------------------------------------------------------

txDialog::txDialog (const Layout* layout) :
    layout_ (layout)
    {$}

//-------------------------------------------------------------------------------------------------------------------------------

const txDialog::Layout* txDialog::setLayout (const Layout* layout)
    {
$   return std::swap (layout_, layout), layout;
    }

//-------------------------------------------------------------------------------------------------------------------------------

INT_PTR txDialog::dialogBox (const txDialog::Layout* layout /*= NULL*/, size_t bufsize /*= 0*/)
    {
$   if (!layout)  layout = layout_;
$   if (!layout)  return TX_ERROR ("�� ���������� ������������ ������ �������    ");

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_ERROR ("GlobalAlloc(): ��� ������ ��� ������� �������    ");

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

//-------------------------------------------------------------------------------------------------------------------------------

INT_PTR txDialog::dialogBox (WORD resourceID)
    {
$   const char* resName = (char*)(ptrdiff_t)resourceID;

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_ERROR ("�� ������ ������ ������� %d   " _ resourceID);

$   return DialogBoxParam (NULL, resName, NULL, dialogProc__, (LPARAM) this);
    }

//-------------------------------------------------------------------------------------------------------------------------------

int txDialog::dialogProc (HWND, UINT, WPARAM, LPARAM)
    {
$   return FALSE;
    }

//-------------------------------------------------------------------------------------------------------------------------------

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

//}

//===============================================================================================================================
//{          Low-level txDialog functions
//! @name    ������� �������������� ������ � ����������� ������
//===============================================================================================================================

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

//-------------------------------------------------------------------------------------------------------------------------------

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

//! @endcond
//}

//===============================================================================================================================

//! @cond INTERNAL
/*! @cond OFF   */ } /*! @endcond */ } // namespace TX, anonymous namespace
//! @endcond

//-------------------------------------------------------------------------------------------------------------------------------
//{          Easy using of TX:: and some of std::
//-------------------------------------------------------------------------------------------------------------------------------

using namespace TX;                  // Allow easy usage of TXLib functions
using namespace TX::Win32;           // Simulate linkage with Win32 libs

using std::cin;                      // Predefined usings to avoid "using namespace std"
using std::cout;

//}

//===============================================================================================================================

//-------------------------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    ��������� � ������������ � ����������
//-------------------------------------------------------------------------------------------------------------------------------
//! @cond    INTERNAL

#if defined (__GNUC__) && (__GNUC__ >= 4)

    #pragma GCC diagnostic warning "-Wstrict-aliasing"

    // Still block this warning to avoid reporting about "= {}" initialization.

    #if 0
    #pragma GCC diagnostic warning "-Wmissing-field-initializers"
    #endif

    // These warnings really occur at end of compilation, so do not restore them.

    #if 0
    #pragma GCC diagnostic warning "-Wunreachable-code"
    #pragma GCC diagnostic warning "-Wunused-value"
    #pragma GCC diagnostic warning "-Wunused-function"
    #pragma GCC diagnostic warning "-Wunused-label"
    #endif

#endif

#if defined (_MSC_VER)

    #pragma warning (default: 4127)             // conditional expression is constant
//!!!    #pragma warning (default: 4245)             // conversion from... to..., signed/unsigned mismatch
    #pragma warning (default: 4351)             // new behavior: elements of array ... will be default initialized

//!!!    #pragma warning (default: 4018)             // '<': signed/unsigned mismatch
    #pragma warning (default: 4100)             // unreferenced formal parameter
    #pragma warning (default: 4511)             // copy constructor could not be generated
    #pragma warning (default: 4512)             // assignment operator could not be generated
    #pragma warning (default: 4663)             // C++ language change: to explicitly specialize class template '...'
//!!!    #pragma warning (default: 6031)             // return value ignored: '...'

    // This warning really occur at end of compilation, so do not restore it.

    #if 0
//!!!    #pragma warning (default: 4710)             // function '...' not inlined
    #endif

#endif

//-------------------------------------------------------------------------------------------------------------------------------

#undef $

//! @endcond
//}

//===============================================================================================================================

//}

#endif // __TXLIB_H

//===============================================================================================================================
// EOF
//===============================================================================================================================

