//============================================================================================
//           [These sections are for folding control  in Code::Blocks]
//{          [Best viewed with "Fold all on file open" option enabled]
//============================================================================================
//!
//! @file    TXLib.h
//! @brief   Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!          $Version$
//!          $Copyright$
//!          $Date$
//!
//! 	     TX Library - компактная библиотека двумерной графики для Win32 на С++.
//!          Это небольшая "песочница" для начинающих реализована с целью помочь им в изучении
//!          простейших принципов программирования. Документация на русском языке.
//!
//! 	     Философия TX Library - облегчить первые шаги в программировании
//! 	     и подтолкнуть к творчеству и самостоятельности.
//!
//!          TX Library is a tiny 2D graphics library for Win32 written in C++. This is a small
//!          sandbox for the very beginners to help them to learn basic programming principles.
//!          The documentation is currently in Russian.
//!
//!          Официальный сайт библиотеки: <a href=http://ded32.net.ru>ded32.net.ru.</a>
//!
//!          См. также <a href=http://txlib.sourceforge.net>страницу проекта на SourceForge.</a>
//!
//! @warning <b>Это альфа-версия.
//!          Для использования требуется согласование с автором библиотеки.</b> \n\n
//!          Правила использования материалов библиотеки и сайта см. на
//!          <a href=http://ded32.net.ru/index/0-6> официальном сайте.</a>
//!
//           $Author$
//--------------------------------------------------------------------------------------------
//!
//! @defgroup Drawing   Рисование
//! @defgroup Mouse     Поддержка мыши
//! @defgroup Dialogs   Диалоговые окна
//! @defgroup Misc      Разное
//! @defgroup Service   Служебное
//! @defgroup Technical Технические детали
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
//! @brief     Текущая версия библиотеки.
//!
//! @code
//!            #define _TX_VERSION "TXLib [Version: 1.72a, Revision 50]" (пример)
//!            #define _TX_AUTHOR  "Copyright (C) Ded (Ilya Dedinsky, http://ded32.net.ru)"
//! @endcode
//!            Эти константы автоматически обновляется при обновлении версии.
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
//! @brief     Версия библиотеки в целочисленном формате.
//!
//!            Формат: старшее слово - номер версии, младшее - номер ревизии,
//!            в двоично-десятичном формате.
//!            Например, @c 0x172a0050 - версия @c 0.172a, ревизия @c 50.
//!
//!            Эта константа автоматически обновляется при обновлении версии.
//!
//! @see       txVersion()
//! @hideinitializer
//}----------------------------------------------------------------------------

#define _TX_VER               _TX_VER_____ ($versioninfo$)

//}
//--------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    Адаптация к компиляторам и платформам
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
//! @brief   Анонимное пространство имен для защиты от конфликтов имен
//!          при сборке многофайлового проекта.
//!
//!          Если имя _TX определено с помощью @c #define до включения
//!          файла @c TXLib.h, то пространство имен перестает быть анонимным
//!          и будет соответствовать значению определения _TX.
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
//           Интерфейс библиотеки
//============================================================================================

//============================================================================================
//{          Initialization
//! @name    Инициализация библиотеки
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создание окна рисования
//!
//! @param   sizeX     Размер окна по горизонтали (в пикселях)
//! @param   sizeY     Размер окна по вертикали   (в пикселях)
//! @param   style     Если 1 (по умолчанию), окно центрируется на экране.
//!
//! @return  Дескриптор (системный номер) окна TXLib. Если окно не открыто, возвращается NULL.
//!
//! @note
//!        - На самом деле параметр @c style задает стиль окна. Если стиль окна содержит WS_SYSMENU
//!	     (значение по умолчанию), окно считается главным.
//!        - Если <i>младший бит стиля</i> выставлен в 1 (по умолчанию), окно центрируется на экране.
//!        - Главное окно должно быть только одно и создаваться первым. При закрытии главного
//!          окна программа завершается.\n
//!          Вспомогательные окна могут создаваться по одному на каждый файл многофайлового
//!          проекта. При их создании @a не надо указывать WS_SYSMENU. Для закрытия вспомогательных
//!          окон используется txDestroyWindow().
//!        - При создании окна к стилю автоматически добавляются стили WS_POPUP, WS_BORDER и WS_CAPTION.
//!        - Устанавливаются параметры рисования по умолчанию, см. функцию txSetDefaults().
//!
//! @see     txOK()
//! @usage
//! @code
//!          txCreateWindow ( 800,  600);                 // Окно 800х600, главное, центрировано
//!          txCreateWindow (1024,  768, WS_SYSMENU | 1); // Окно 800х600, главное, центрировано
//!          txCreateWindow (1024,  768, 1);              // Окно 800х600, вспомогательное, центрировано
//!          txCreateWindow (1024,  768, WS_SYSMENU);     // Окно 800х600, главное, не центрировано
//! @endcode
//}-------------------------------------------------------------------------------------------

#ifdef _TX_NAMED

HWND txCreateWindow (int sizeX = 800, int sizeY = 600, unsigned style =              1);

#else

HWND txCreateWindow (int sizeX = 800, int sizeY = 600, unsigned style = WS_SYSMENU | 1);

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Установка параметров рисования по умолчанию.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Параметры по умолчанию:\n
//!          - Линии - цвет белый (TX_WHITE), толщина 1
//!          - Заливка - цвет белый (TX_WHITE)
//!          - Шрифт - Системный шрифт, цвет белый (TX_WHITE)
//!          - Логическая растровая операция - копирование цвета (R2_COPYPEN)
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
//! @brief   Проверка правильности работы библиотеки
//!
//! @return  Состояние библиотеки: true - библиотека в порядке, false - не в порядке.
//!
//!          "Библиотека не в порядке" означает, что ее внутренние данные неверны.
//!          Самая простая причина - библиотека не инициализирована (не открыто окно),
//!          однако могут быть и другие.
//!
//! @see     txCreateWindow()
//! @usage
//! @code
//!          txCreateWindow (800, 600);
//!          if (!txOK())
//!              {
//!              MessageBox (txWindow(), "Не смогла создать окно", "Извините", MB_ICONSTOP);
//!              return;
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
bool txOK();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает размер окна рисования в виде структуры POINT.
//!
//! @return  Размер окна рисования в виде структуры POINT.
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
//! @brief   Возвращает ширину окна рисования.
//!
//! @return  Ширина окна рисования.
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
//! @brief   Возвращает высоту окна рисования.
//!
//! @return  Высота окна рисования.
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
//! @brief   Возвращает дескриптор контекста рисования холста
//!
//! @return  Дескриптор (системный номер, handler) контекста рисования (device context, DC)
//!          холста (HDC).
//!
//! @note    HDC возвращается в виде ссылки, что позволяет подменить его. Перед подменой
//!          надо сохранить старый дескриптор или освободить его с помощью txDeleteDC().
//!          До подмены рисование должно быть заблокировано с помощью txLock() и
//!          после подмены разблокировано txUnlock().
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
//! @brief   Возвращает дескриптор окна холста
//!
//! @return  Дескриптор (системный номер, handler) окна холста
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          SetWindowText (txWindow(), "Новые заголовки - теперь и в ваших окнах!");
//!          MessageBox (txWindow(), "Распишитесь", "Получите", MB_ICONINFORMATION);
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
HWND txWindow() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Возвращает строку с информацией о текущей версии библиотеки.
//!
//! @return  Строка с информацией о текущей версии библиотеки.
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
//! @brief   Возвращает номер версии библиотеки.
//!
//! @return  Номер версии библиотеки.
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
//! @brief   Возвращает имя исполняемого файла или изначальный заголовок окна TXLib.
//!
//! @param   fileNameOnly  Возвратить только полное имя исполняемого файла, полученного через
//!                        Win32 функцию GetFileModuleName (NULL, ...).
//!
//! @return  fileNameOnly = true:  Имя исполняемого файла \n
//!          fileNameOnly = false: Изначальный заголовок окна TXLib
//!
//! @note    Возвращается @b статическая строка.
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
//!              SetWindowText (txWindow(), title);  // Вот такой вот progress bar
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
//! @name    Установка цветов и режимов рисования
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Названия предопределенных цветов.
//!
//!          См. TX_BLACK, TX_BLUE и другие цвета в списке выше.
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

    TX_BLACK         = RGB (  0,   0,   0),   //!< Черный цвет.
    TX_BLUE          = RGB (  0,   0, 128),   //!< Темно-синий цвет.
    TX_GREEN         = RGB (  0, 128,   0),   //!< Зеленый цвет.
    TX_CYAN          = RGB (  0, 128, 128),   //!< Бирюзовый цвет.
    TX_RED           = RGB (128,   0,   0),   //!< Темно-красный цвет.
    TX_MAGENTA       = RGB (128,   0, 128),   //!< Темно-малиновый цвет.
    TX_BROWN         = RGB (128, 128,   0),   //!< Коричневый цвет. Некрасивый. Do it yourself using RGB().
    TX_ORANGE        = RGB (255, 128,   0),   //!< Оранжевый цвет.
    TX_GRAY          = RGB (160, 160, 160),   //!< Серый цвет.
    TX_DARKGRAY      = RGB (128, 128, 128),   //!< Темно-серый цвет.
    TX_LIGHTGRAY     = RGB (192, 192, 192),   //!< Светло-серый цвет.
    TX_LIGHTBLUE     = RGB (  0,   0, 255),   //!< Светло-синий цвет.
    TX_LIGHTGREEN    = RGB (  0, 255, 128),   //!< Светло-зеленый цвет.
    TX_LIGHTCYAN     = RGB (  0, 255, 255),   //!< Светло-бирюзовый цвет.
    TX_LIGHTRED      = RGB (255,   0, 128),   //!< Светло-красный цвет.
    TX_LIGHTMAGENTA  = RGB (255,   0, 255),   //!< Светло-малиновый цвет.
    TX_PINK          = RGB (255, 128, 255),   //!< Розовый гламурный:)
    TX_YELLOW        = RGB (255, 255, 128),   //!< Желтый цвет.
    TX_WHITE         = RGB (255, 255, 255),   //!< Белый цвет.
    TX_TRANSPARENT   = 0xFFFFFFFF,            //!< Прозрачный цвет. <i>Отключает рисование.</i>
    TX_NULL          = TX_TRANSPARENT,        //!< Прозрачный цвет. <i>Отключает рисование.</i>

//  Цветовые каналы (компоненты) - см. txExtractColor(), txRGB2HSL(), txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< Цветовой тон цвета в модели HSL
    TX_SATURATION   = 0x05000000,             //!< Насыщенность цвета в модели HSL
    TX_LIGHTNESS    = 0x06000000;             //!< Светлота цвета в модели HSL

#ifdef FOR_DOXYGEN_ONLY
    };
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает (смешивает) цвет из трех базовых цветов (компонент).
//!
//! @param   red    Количество красного цвета в интервале [0; 255]
//! @param   green  Количество зеленого цвета в интервале [0; 255]
//! @param   blue   Количество синего   цвета в интервале [0; 255]
//!
//! @return  Созданный цвет в формате COLORREF.
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
//! @brief   Устанавливает текущий цвет и толщину линий, цвет текста.
//!
//! @param   color      Цвет линий и текста, см. txColors, RGB()
//! @param   thickness  Толщина линий
//!
//! @return  Если операция была успешна - true, иначе - false.
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
//! @brief   Устанавливает текущий цвет линий и текста.
//!
//! @param   red    Количество красного цвета в интервале [0; 1]
//! @param   green  Количество зеленого цвета в интервале [0; 1]
//! @param   blue   Количество синего   цвета в интервале [0; 1]
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()
//! @usage
//! @code
//!          txColor (1.0, 1.0, 0.0);   // Красный + зеленый = желтый
//!          txColor (1.0, 0.5, 0.25);  // Нечто оранжевое
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txColor (double red, double green, double blue);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет линий и текста.
//!
//! @return  Текущий цвет линий и текста, см. txColors, RGB()
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
//! @brief   Устанавливает текущий цвет заполнения фигур.
//!
//! @param   color  Цвет заполнения, см. txColors, RGB()
//!
//! @return  Если операция была успешна - true, иначе - false.
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
//! @brief   Устанавливает текущий цвет заполнения фигур.
//!
//! @param   red    Количество красного цвета в интервале [0; 1]
//! @param   green  Количество зеленого цвета в интервале [0; 1]
//! @param   blue   Количество синего   цвета в интервале [0; 1]
//!
//! @return  Если операция была успешна - true, иначе - false.
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
//! @brief   Возвращает текущий цвет заполнения фигур.
//!
//! @return  Текущий цвет заполнения фигур, см. txColors, RGB()
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
//! @brief   Устанавливает режим взаимодействия цветов при рисовании.
//!
//!          При рисовании графическая библиотека может не просто красить пиксели
//!          на экране, а смешивать цвета экрана и текущие цвета линий и заполнения.
//!
//! @param   mode  Режим смешивания цветов
//!
//! @return  Предыдущий режим взаимодействия цветов, см. txColors, RGB()
//!
//! @title   Режимы взаимодействия цветов:
//! @table   @tr R2_COPYPEN     @td Пиксели = цвета кисти (самый нормальный режим :)
//!          @tr R2_NOTCOPYPEN  @td Пиксели = ~кисть
//!          @tbr
//!          @tr R2_BLACK       @td Пиксели = черный цвет (цвет кисти игнорируется)
//!          @tr R2_WHITE       @td Пиксели = белый  цвет (цвет кисти игнорируется)
//!          @tr R2_NOT         @td Пиксели = ~пиксели    (цвет кисти игнорируется)
//!          @tbr
//!          @tr R2_XORPEN      @td Пиксели =    пиксели ^  кисть
//!          @tr R2_NOTXORPEN   @td Пиксели = ~ (пиксели ^  кисть)
//!          @tbr
//!          @tr R2_MASKPEN     @td Пиксели =    пиксели &  кисть
//!          @tr R2_NOTMASKPEN  @td Пиксели = ~ (пиксели &  кисть)
//!          @tr R2_MASKNOTPEN  @td Пиксели =    пиксели & ~кисть
//!          @tr R2_MASKPENNOT  @td Пиксели =   ~пиксели &  кисть
//!          @tbr
//!          @tr R2_MERGEPEN    @td Пиксели =    пиксели |  кисть
//!          @tr R2_NOTMERGEPEN @td Пиксели = ~ (пиксели |  кисть)
//!          @tr R2_MERGENOTPEN @td Пиксели =    пиксели | ~кисть
//!          @tr R2_MERGEPENNOT @td Пиксели =   ~пиксели |  кисть
//!          @tbr
//!          @tr R2_NOP         @td Пиксели вообще не изменяются.
//! @endtable
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txSetColor (TX_WHITE, 5);       // При рисовании белым цветом в режиме
//!          txSetROP2 (R2_XORPEN);          //   R2_XORPEN цвета на экране инвертируются
//!
//!          txLine (100, 100, 200, 200);    // Рисуем первый раз - линия появляется
//!          txSleep (1000);
//!          txLine (100, 100, 200, 200);    // Рисуем второй раз - линия исчезает
//!
//!          txSetROP2 (R2_COPYPEN);         // Восстанавливаем нормальный режим
//!          txLine (100, 100, 200, 200);    // Рисуем первый раз - линия появляется
//!
//!          txLine (100, 100, 200, 200);    // Рисуем первый раз - линия остается
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSetROP2 (int mode = R2_COPYPEN);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Извлекает цветовую компоненту (цветовой канал) из смешанного цвета.
//!
//! @param   color      Смешанный цвет
//! @param   component  Извлекаемая компонента, см. txColors
//!
//! @return  Цветовая компонента, см. txColors
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), txColors
//! @usage
//! @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          Другие примеры см. в функциях AppearText(), AppearEarth() Примера 5 ("Циклы").
//! @endcode
//}-------------------------------------------------------------------------------------------

int txExtractColor (COLORREF color, COLORREF component) _TX_CHECK_RESULT;

//{---------------------------------------
//! @ingroup Drawing
//! @brief   Преобразует цвет из формата RGB в формат HSL.
//!
//! @param   rgbColor  Преобразуемый цвет в формате @strike ЕГЭ @endstrike RGB
//!
//! @return  Созданный цвет в виде COLORREF.
//!
//!          Формат @b RGB определяется как
//!
//!          - Красная компонента цвета (Red),   от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя   компонента цвета (Blue),  от 0 до 255.
//!
//!          Формат @b HSL определяется как
//!
//!          - Цветовой тон (Hue),        от 0 до 360.
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота     (Lightness),  от 0 до 255.
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
//! @brief   Преобразует цвет из формата HSL в формат RGB.
//!
//! @param   hslColor  Преобразуемый цвет в формате HSL
//!
//! @return  Созданный цвет в виде COLORREF.
//!
//!          Формат @b RGB определяется как
//!
//!          - Красная компонента цвета (Red),   от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя   компонента цвета (Blue),  от 0 до 255.
//!
//!          Формат @b HSL определяется как
//!
//!          - Цветовой тон (Hue),        от 0 до 360.
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота     (Lightness),  от 0 до 255.
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
//! @name    Рисование фигур
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Стирает холст текущим цветом заполнения.
//!
//! @return  Если операция была успешна - true, иначе - false.
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
//! @brief   Рисует пиксель (точку на экране).
//!
//! @param   x      Х-координата точки
//! @param   y      Y-координата точки
//! @param   color  Цвет точки, см. txColors, RGB()
//!
//! @return  Если операция была успешна - true, иначе - false.
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
//! @brief   Рисует пиксель (точку на экране).
//!
//! @param   x      Х-координата точки
//! @param   y      Y-координата точки
//! @param   red    Количество красного цвета в интервале [0; 1]
//! @param   green  Количество зеленого цвета в интервале [0; 1]
//! @param   blue   Количество синего   цвета в интервале [0; 1]
//!
//! @return  Если операция была успешна - true, иначе - false.
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
//! @brief   Возвращает текущий цвет точки (пикселя) на экране.
//!
//! @param   x  Х-координата точки
//! @param   y  Y-координата точки
//!
//! @return  Текущий цвет пикселя, см. txColors, RGB()
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
//! @brief   Рисует линию.
//!
//! @param   x0  X-координата начальной точки
//! @param   y0  Y-координата начальной точки
//! @param   x1  X-координата конечной  точки
//! @param   y1  Y-координата конечной  точки
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линии задается функцией txSetColor().
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
//! @brief   Рисует прямоугольник.
//!
//! @param   x0  X-координата верхнего левого  угла
//! @param   y0  Y-координата верхнего левого  угла
//! @param   x1  X-координата нижнего  правого угла
//! @param   y1  Y-координата нижнего  правого угла
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
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
//! @brief   Рисует ломаную линию или многоугольник.
//!
//! @param   points     Массив структур POINT с координатами точек
//! @param   numPoints  Количество точек в массиве
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
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
//! @brief   Рисует эллипс.
//!
//! @param   x0  X-координата верхнего левого  угла описанного прямоугольника
//! @param   y0  Y-координата верхнего левого  угла описанного прямоугольника
//! @param   x1  X-координата нижнего  правого угла описанного прямоугольника
//! @param   y1  Y-координата нижнего  правого угла описанного прямоугольника
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
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
//! @brief   Рисует окружность или круг.
//!
//! @param   x  Х-координата центра
//! @param   y  Y-координата центра
//! @param   r  Радиус
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
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
//! @brief   Рисует дугу эллипса.
//!
//! @param   x0          X-координата верхнего левого  угла прямоугольника,
//!                        описанного вокруг эллипса, содержащего дугу
//! @param   y0          Y-координата верхнего левого  угла прямоугольника
//! @param   x1          X-координата нижнего  правого угла прямоугольника
//! @param   y1          Y-координата нижнего  правого угла прямоугольника
//! @param   startAngle  Угол между направлением оси OX и началом дуги (в градусах)
//! @param   totalAngle  Величина дуги (в градусах)
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
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
//! @brief   Рисует сектор эллипса.
//!
//! @param   x0          X-координата верхнего левого  угла прямоугольника,
//!                        описанного вокруг эллипса, содержащего сектор
//! @param   y0          Y-координата верхнего левого  угла прямоугольника
//! @param   x1          X-координата нижнего  правого угла прямоугольника
//! @param   y1          Y-координата нижнего  правого угла прямоугольника
//! @param   startAngle  Угол между направлением оси OX и началом сектора (в градусах)
//! @param   totalAngle  Величина сектора (в градусах)
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
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
//! @brief   Рисует хорду эллипса.
//!
//! @param   x0          X-координата верхнего левого угла прямоугольника,
//!                        описанного вокруг эллипса, содержащего хорду
//! @param   y0          Y-координата верхнего левого угла прямоугольника
//! @param   x1          X-координата нижнего правого угла прямоугольника
//! @param   y1          Y-координата нижнего правого угла прямоугольника
//! @param   startAngle  Угол между направлением оси OX и началом хорды (в градусах)
//! @param   totalAngle  Величина хорды (в градусах)
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
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
//! @brief   Заливает произвольный контур текущим цветом заполнения.
//!
//! @param   x      Х-координата точки начала заливки
//! @param   y      Y-координата точки начала заливки
//! @param   color  Цвет заливаемой области (TX_TRANSPARENT - автоопределение)
//! @param   mode   Режим заливки (FLOODFILLSURFACE - заливка однородного фона)
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет заполнения задается функцией txSetFillColor().
//!          Не рекомендуется для применения - довольно медленно работает.
//!
//! @title   Режимы заливки: @table
//!          @tr FLOODFILLSURFACE @td - Заливать область,    указанную цветом color.
//!          @tr FLOODFILLBORDER  @td - Заливать до границы, указанной цветом color.
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
//! @name    Работа с текстом
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует текст.
//!
//! @param   x     Х-координата начальной точки текста
//! @param   y     Y-координата начальной точки текста
//! @param   text  Текстовая строка
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет текста задается функцией txSetColor(), выравнивание - txSetTextAlign().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txSelectFont(), txSetTextAign(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txTextOut (int x, int y, const char text[]);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует текст, размещенный в прямоугольной области.
//!
//! @param   x0     X-координата верхнего левого  угла области
//! @param   y0     Y-координата верхнего левого  угла области
//! @param   x1     X-координата нижнего  правого угла области
//! @param   y1     Y-координата нижнего  правого угла области
//! @param   text   Текстовая строка
//! @param   format Флаги форматирования текста
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет текста задается функцией txSetColor(), выравнивание - txSetTextAlign().
//!
//!          Флаги форматирования текста см. в MSDN (http://msdn.com), искать "DrawText Function
//!          (Windows)": http://msdn.microsoft.com/en-us/library/dd162498%28VS.85%29.aspx.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "И здесь могла бы быть Ваша реклама.");
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format = DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_WORD_ELLIPSIS);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Выбирает текущий шрифт.
//!
//! @param   name       Название шрифта
//! @param   sizeY      Высота букв (размер по Y)
//! @param   sizeX      Ширина букв
//! @param   bold       Жирность шрифта (от 0 до 1000)
//! @param   italic     Курсив
//! @param   underline  Подчеркивание
//! @param   strikeout  Зачеркивание
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txTextOut()
//! @usage
//! @code
//!          txSelectFont ("Comic Sans MS", 20);
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//!          txSelectFont ("Comic Sans MS", 20, 10, false, true, false, true);
//!          txTextOut (100, 200, "Но ее почему-то нет.");
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
//! @brief   Вычисляет размеры текстовой надписи.
//!
//! @param   text  Текстовая строка
//!
//! @return  Размеры надписи в структуре SIZE.
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
//! @brief   Вычисляет ширину текстовой надписи.
//!
//! @param   text  Текстовая строка
//!
//! @return  Ширина надписи.
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
//! @brief   Вычисляет высоту текстовой надписи.
//!
//! @param   text  Текстовая строка
//!
//! @return  Высота надписи.
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
//! @brief   Устанавливает текущее выравнивание текста.
//!
//! @param   align  Флаги выравнивания
//!
//! @return  Предыдущее состояние выравнивания текста.
//!
//! @title   Флаги выравнивания: @table
//!          @tr TA_BASELINE @td Точка (X,Y) определяет базовую линию текста.
//!          @tr TA_BOTTOM   @td Точка (X,Y) определяет нижнюю сторону описанного прямоугольника \n
//!                              (текст лежит выше этой точки).
//!          @tr TA_TOP      @td Точка (X,Y) определяет верхнюю сторону описанного прямоугольника \n
//!                              (текст лежит ниже этой точки).
//!          @tbr
//!          @tr TA_CENTER   @td Текст будет выровнен по горизонтали относительно точки (X,Y).
//!          @tr TA_LEFT     @td Точка (X,Y) определяет левую сторону описанного прямоугольника \n
//!                              (текст лежит правее этой точки).
//!          @tr TA_RIGHT    @td Точка (X,Y) определяет правую сторону описанного прямоугольника \n
//!                              (текст лежит левее этой точки).
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
//! @brief   Ищет шрифт по его названию.
//!
//! @param   name  Название шрифта
//!
//! @return  Информация о шрифте в структуре LOGFONT.
//!          Если шрифт не найден, возвращает NULL.
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
//! @name    Рисование в памяти (на "виртуальном холсте") и загрузка изображений
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает дополнительный холст (контекст рисования, Device Context, DC) в памяти.
//!
//! @param   sizeX   Ширина холста
//! @param   sizeY   Высота холста
//! @param   bitmap  Bitmap to be associated with DC
//!
//! @return  Дескриптор (системный номер, выданный Windows) созданного холста (контекста рисования).
//!
//! @remarks Созданный контекст затем будет нужно удалить при помощи txDeleteDC().
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
//! @brief   Загружает из файла изображение в формате BMP. Делает это довольно медленно.
//!
//! @param   filename  Имя файла с изображением в формате BMP
//!
//! @return  Дескриптор созданного контекста рисования в памяти, с загруженным изображением.
//!          Если изображение не загружено (не найден файл, неверный формат файла и т.д.), то NULL.
//!
//! @note    Изображение загружается в создаваемый контекст рисования в памяти ("виртуальный холст"),
//!          который затем будет нужно <b>обязательно</b> удалить при помощи txDeleteDC().
//!
//!          Изображения поддерживаются только в формате BMP. Если взять файл другого формата, например JPG, и
//!          переименовать его со сменой расширения на BMP, то от этого формат не изменится. Такое изображение
//!          загружено не будет.
//!
//!          Если функция вернула NULL, то надо прежде всего проверить наличие файла изображения
//!          по указанному в программе пути и формат файла. Если путь к файлу не указан (или указан
//!          как неполный), то путь отсчитывается от текущей папки программы, которая может не совпадать
//!          текущей папкой среды программирования. Текущую папку программы можно посмотреть по
//!          команде About в системном меню (она указана там как "Run from").
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(),
//!          txTransparentBlt()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
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
//! @brief   Уничтожает холст (контекст рисования, DC) в памяти.
//!
//! @param   dc     Контекст рисования для уничтожения. \n
//!                 Если передан указатель, то после уничтожения по указателю записывается NULL.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
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
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой.
//!
//! @param   dest    Контекст назначения (куда копировать)
//! @param   xDest   Х-координата верхнего левого угла изображения-приемника
//! @param   yDest   Y-координата верхнего левого угла изображения-приемника
//! @param   width   Ширина копируемого изображения
//! @param   height  Высота копируемого изображения
//! @param   src     Контекст источника (откуда копировать)
//! @param   xSrc    Х-координата верхнего левого угла изображения-источника
//! @param   ySrc    Y-координата верхнего левого угла изображения-источника
//! @param   rOp     Растровая операция копирования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если контексты назначения или источника равны NULL, то они не существуют и копирование
//!          вызовет ошибку. Наиболее частая причина - ошибка при загрузке файла изображения и
//!          отсутствие проверки на эту ошибку. Пример с проверкой на правильность загрузки см. ниже.
//!
//! @title   Режимы копирования:
//! @table   @tr SRCCOPY     @td Просто копирует :) - самый распространенный режим
//!          @tbr
//!          @tr BLACKNESS   @td Заполняет холст-приемник черным цветом (холст-источник игнорируется).
//!          @tr WHITENESS   @td Заполняет холст-приемник белым цветом  (холст-источник игнорируется).
//!          @tr DSTINVERT   @td Инвертирует цвета на холсте-приемнике  (холст-источник игнорируется).
//!          @tr PATCOPY     @td Копирует цвет текущей кисти холста-приемника.
//!          @tbr
//!          @tr MERGECOPY   @td Приемник =   приемник & цвет текущей кисти источника.
//!          @tr MERGEPAINT  @td Приемник = ~ приемник | источник
//!          @tr NOTSRCCOPY  @td Приемник = ~ источник
//!          @tr NOTSRCERASE @td Приемник = ~ (приемник | источник)
//!          @tr PATINVERT   @td Приемник =  кисть приемника ^  приемник
//!          @tr PATPAINT    @td Приемник = (кисть приемника | ~источник) | приемник
//!          @tr SRCAND      @td Приемник =  приемник & источник
//!          @tr SRCERASE    @td Приемник = ~приемник & источник
//!          @tr SRCINVERT   @td Приемник =  приемник ^ источник
//!          @tr SRCPAINT    @td Приемник =  приемник | источник
//!          @endtable
//!
//! @see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(),
//!          txColors, RGB()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
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
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//!          с учетом прозрачности.
//!
//! @param   dest        Контекст назначения (куда копировать)
//! @param   xDest       Х-координата верхнего левого угла изображения-приемника
//! @param   yDest       Y-координата верхнего левого угла изображения-приемника
//! @param   width       Ширина копируемого изображения, неотрицательная
//! @param   height      Высота копируемого изображения, неотрицательная
//! @param   src         Контекст источника (откуда копировать)
//! @param   xSrc        Х-координата верхнего левого угла изображения-источника
//! @param   ySrc        Y-координата верхнего левого угла изображения-источника
//! @param   transColor  Цвет, который будет считаться прозрачным
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если контексты назначения или источника равны NULL, то они не существуют и копирование
//!          вызовет ошибку. Наиболее частая причина - ошибка при загрузке файла изображения и
//!          отсутствие проверки на эту ошибку. Пример с проверкой на правильность загрузки см. ниже.
//!
//!          Стандартная функция TransparentBlt из Win32 API может масштабировать изображение.
//!          В txTransparentBlt это убрано для упрощения использования. If you need image scaling,
//!          use original function TransparentBlt and don't mess with stupid TX-based tools.
//!          (See implementation of txTransparentBlt in TXLib.h).
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
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
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//!          с учетом прозрачности.
//!
//! @param   dest    Контекст назначения (куда копировать)
//! @param   xDest   Х-координата верхнего левого угла изображения-приемника
//! @param   yDest   Y-координата верхнего левого угла изображения-приемника
//! @param   width   Ширина копируемого изображения, неотрицательная
//! @param   height  Высота копируемого изображения, неотрицательная
//! @param   src     Контекст источника (откуда копировать).
//!                    Должен иметь 32-битовый формат и альфа-канал (см. ниже).
//! @param   xSrc    Х-координата верхнего левого угла изображения-источника,
//!                    должна быть в пределах размера источника.
//! @param   ySrc    Y-координата верхнего левого угла изображения-источника,
//!                    должна быть в пределах размера источника.
//! @param   alpha   Общая прозрачность изображения, в дополнение к альфа-каналу. \n
//!                    (0 - все прозрачно, 1 - использовать только альфа-канал)
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если контексты назначения или источника равны NULL, то они не существуют и копирование
//!          вызовет ошибку. Наиболее частая причина - ошибка при загрузке файла изображения и
//!          отсутствие проверки на эту ошибку. Пример с проверкой на правильность загрузки см. ниже.
//!
//!          Изображение-источник и изображение-приемник не могут налагаться друг на друга.
//!
//!          Изображение должно быть загружено с помощью txLoadImage() и иметь
//!          32-битовый RGBA-формат. Дополнительный канал (альфа-канал) этого
//!          формата отвечает за прозрачность участков изображения.
//!
//!          Альфа-канал можно сделать, например, в Adobe Photoshop, командой
//!          "Новый канал (New Channel)" в палитре каналов (Channels). Черный
//!          цвет в альфа-канале соответствует полной прозрачности, белый -
//!          полной непрозрачности. При этом в прозрачных областях само изображение
//!          (в каналах R, G, B) должно быть черным, и чем прозрачнее, тем чернее.
//!
//!          Строго говоря, надо умножить каналы R,G,B на альфа-канал:
//!          <tt>R,G,B *= A</tt>. Получится вот что:
//!
//!        - Если значение альфа-канала для некоторого пикселя равно 0 (полная прозрачность),
//!          тогда значения каналов R,G,B также станут 0 (это черный цвет).
//!        - Если значение альфа-канала равно 255 (полная непрозрачность),
//!          тогда значения каналов R,G,B не изменятся.
//!        - Для других значений альфа-канала, пиксели изображения станут темнее.
//!
//!          В Photoshop это можно сделать командой <b>Image @d Apply Image</b> с параметрами:
//! @table   @tr Source:     @td <i>Имя файла с картинкой</i>
//!          @tr Layer:      @td Background
//!          @tr @b Channel: @td <b> Alpha 1</b>
//!          @tr Blending:   @td Multiply
//!          @tr Opacity:    @td 100%
//! @endtable
//!
//! @note    Стандартная функция AlphaBlend из Win32 API может масштабировать изображение.
//!          В txAlphaBlend это убрано для упрощения использования. If you still need image
//!          scaling, use original function AlphaBlend and don't mess with stupid TX-based
//!          tools. (See implementation of txAlphaBlend in TXLib.h).
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
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
//! @name    Вспомогательные функции
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Блокирует обновление изображения окна, во избежание мигания.
//!
//!          Для снятия блокировки используется функция txEnd().
//!
//! @warning Избегайте блокирования на долгое время. Это может привести к дефектам
//!          изображения в окне. Если в программе требуется задержка, то используйте
//!          функцию txSleep(), так как она автоматически обновляет изображение,
//!          независимо от состояния блокировки.
//!
//! @return  Значение счетчика блокировки (если 0, то рисование разблокировано).
//!
//! @see     txEnd(), txSleep(), txUpdateWindow(), txTextCursor()
//! @usage
//! @code
//!          txBegin();                        // Здесь изображение "замерзнет"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                        // Это вызвало бы мигание без txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                          // Здесь мы сразу увидим окончательный рисунок
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txBegin();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Разблокирует обновление окна, заблокированное функцией txBegin().
//!
//! @warning Если txBegin() вызывалась несколько раз, то для снятия блокировки
//!          требуется столько же раз вызвать txEnd().
//!
//! @return  Значение счетчика блокировки (если 0, то рисование разблокировано).
//!
//! @see     txBegin(), txSleep(), txUpdateWindow(), txTextCursor()
//! @usage
//! @code
//!          txBegin();                        // Здесь изображение "замерзнет"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                        // Это вызвало бы мигание без txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                          // Здесь мы сразу увидим окончательный рисунок
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
int txEnd();

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Задерживает выполнение программы на определенное время.
//!
//! @param   time  Задержка в миллисекундах.
//!
//! @return  Состояние блокировки обновления окна.
//!
//! @note    <b>Во время задержки изображение в окне всегда обновляется.</b>
//!
//! @see     txBegin(), txEnd(), txUpdateWindow()
//! @usage
//! @code
//!          txSleep (500); // Поспать полсекунды
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSleep (int time);

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Разрешает или запрещает автоматическое обновление изображения в окне.
//!
//! @param   update  Режим обновления (true - разрешить, false - запретить).
//!
//! @return  Предыдущее состояние режима обновления.
//!
//!          В отличие от txBegin() и txEnd(), которые поддерживают вложенные вызовы
//!          и работают как "скобки для замерзания картинки", txUpdateWindow()
//!          позволяет явно установить или снять блокировку автоматического обновления.
//!
//!          Более полную информацию о блокировке см. в функциях txBegin(), txEnd() и txSleep().
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
//! @brief   Устанавливает текущий объект GDI.
//!
//! @param   obj  Дескриптор объекта GDI
//!
//! @return  Если операция была успешна - true, иначе - false.
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
//! @brief   Уничтожает окно TXlib.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если уничтожается главное окно TXLib, функция main() прерывается и программа
//!          автоматически завершается. При этом @b не гарантируется правильное завершение
//!          программы, поэтому так делать @b не рекомендуется.
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
//! @brief   Делает нечто иногда удобное. См. название функции.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          У этой функции есть синоним с простым понятным названием, поищите его в файле
//!          библиотеки, около @a определения этой функции. Или можно [скопировать]набрать
//!          это километровое имя и посмотреть, что получится.
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
//! @name    Работа с мышью
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает позицию Мыши!
//!
//! @return  Позиция мыши как структура POINT.
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
//! @brief   Возвращает Х-Координату Мыши!
//!
//! @return  Х-координата мыши.
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
//! @brief   Возвращает Y-Координату Мыши!
//!
//! @return  Y-координата мыши.
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
//! @brief   Возвращает состояние Кнопок Мыши!
//!
//! @return  Состояние Кнопок Мыши!
//!
//!          В возвращаемом значении выставленный в единицу 1-й (младший)
//!          бит означает нажатую левую Кнопку Мыши, 2-й - правую, 3-й - среднюю. \n
//!          Например, возвращенное число 5 (двоичное 101) означает одновременное
//!          нажатие средней и левой Кнопок, но не правой Кнопки.
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
//! @name    Функции консоли
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает цветовые атрибуты консоли.
//!
//! @param   colors  Цветовые атрибуты консоли.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          @b Атрибуты - это цвет текста (colorText) и цвет фона (colorBackground),
//!          объединенные вместе: \n\n
//!          <tt>colors = colorText + colorBackground * 16</tt> \n\n
//!          либо \n\n
//!          <tt>colors = colorText | (colorBackground \<\< 4)</tt> \n\n
//!          Цвета атрибутов @b не имеют никакого отношения к цветам рисования,
//!          задаваемыми @ref txColors "TX_..." константами, RGB(), txSetColor(), txColor(),
//!          txSetFillColor(), txFillColor() и т.д. Значения цветов см. ниже.
//!
//! @title   Значения цветов атрибутов
//! @table   @tr  Dec @td @c Hex @td                 @td Dec  @td @c Hex @td
//!          @tbr
//!          @tr  0 = @td @c 0x0 @td = Черный,       @td  8 = @td @c 0x8 @td = Темно-серый,
//!          @tr  1 = @td @c 0x1 @td = Синий,        @td  9 = @td @c 0x9 @td = Светло-синий,
//!          @tr  2 = @td @c 0x2 @td = Зеленый,      @td 10 = @td @c 0xA @td = Светло-зеленый,
//!          @tr  3 = @td @c 0x3 @td = Сине-зеленый, @td 11 = @td @c 0xB @td = Светло-сине-зеленый,
//!          @tr  4 = @td @c 0x4 @td = Красный,      @td 12 = @td @c 0xC @td = Светло-красный,
//!          @tr  5 = @td @c 0x5 @td = Малиновый,    @td 13 = @td @c 0xD @td = Светло-малиновый,
//!          @tr  6 = @td @c 0x6 @td = Темно-желтый, @td 14 = @td @c 0xE @td = Желтый,
//!          @tr  7 = @td @c 0x7 @td = Серый,        @td 15 = @td @c 0xF @td = Белый.
//! @endtable
//!
//!          В шестнадцатиричной системе счисления атрибуты задавать можно проще: если нужен,
//!          скажем, желтый цвет на синем фоне, то его код будет @c 0x1e (старшая цифра - старшие 4
//!          бита - это цвет фона, младшая цифра - младшие 4 бита - это цвет текста).
//!
//! @see     txTextCursor(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          txSetConsoleAttr (0x1e);
//!          printf ("А в небе голубом есть город золотой");
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txSetConsoleAttr (WORD colors = 0x07);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущие цветовые атрибуты консоли.
//!
//! @return  Текущие цветовые атрибуты консоли. См. txSetConsoleAttr().
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
//! @brief   Стирает текст консоли.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          При стирании используются текущие атрибуты (цвета текста и фона) консоли.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          txClearConsole();  // Ну вот и все, дружок
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txClearConsole();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает позицию мигающего курсора консоли.
//!
//! @param   x  X-координата курсора в пикселях.
//! @param   y  Y-координата курсора в пикселях.
//!
//! @return  Предыдущее положение мигающего курсора в структуре POINT.
//!
//! @note    Нельзя установить совсем любую позицию. Текст в консоли расположен по прямоугольной
//!          сетке, размер которой зависит от размеров шрифта консоли. Устанавливаемая позиция
//!          округляется, чтобы курсор попал в ячейку сетки. См. пример к функции txGetConsoleFontSize().
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          txSetConsoleCursorPos (txGetExtentX(), txGetExtentY());  // Центр Вселенной
//! @endcode
//}-------------------------------------------------------------------------------------------

POINT txSetConsoleCursorPos (int x, int y);

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает позицию мигающего курсора консоли.
//!
//! @return  Положение мигающего курсора в структуре POINT.
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
//! @brief   Возвращает размеры шрифта консоли.
//!
//! @return  Размеры шрифта консоли в пикселях, в структуре POINT.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//! @usage
//! @code
//!          POINT size = txGetConsoleFontSize();
//!          txSetConsoleCursorPos (5 * size.x, 10 * size.y);  // Теперь мигай там
//! @endcode
//}-------------------------------------------------------------------------------------------

POINT txGetConsoleFontSize();

//{-------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Запрещает или разрешает рисование мигающего курсора в окне.
//!
//! @param   blink  false - запретить мигающий курсор
//!
//! @return  Предыдущее значение разрешения.
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
//! @name    Другие полезные функции, не связанные с рисованием
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Воспроизводит звуковой файл.
//!
//! @param   filename  Имя звукового файла. Если NULL - останавливает звук.
//! @param   mode      Режим воспроизведения
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @title   Режимы воспроизведения: @table
//!          @tr SND_ASYNC       @td Звук проигрывается одновременно с работой программы. \n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).
//!          @tr SND_SYNC        @td Выполнение программы приостанавливается до окончания
//!                                  воспроизведения звука.
//!          @tr SND_LOOP        @td Зацикливать звук при воспроизведении. \n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).
//!          @tbr
//!          @tr SND_NODEFAULT   @td Не использовать звук по умолчанию, если нельзя проиграть
//!                                  указанный звуковой файл.
//!          @tr SND_NOSTOP      @td Если какой-либо звук уже проигрывается, не останавливать
//!                                  его для воспроизведения указанного звука.
//!          @tr SND_APPLICATION @td Проигрывать звук, используя программу, зарегистрированную
//!                                  для данного типа звуковых файлов.
//!          @endtable
//!
//! @note    Поддерживаются только файлы в формате WAV. Остальные форматы (MP3 и др.) надо
//!          перекодировать. Переименование со сменой расширения не поможет, как и в случае
//!          с форматом картинок в txLoadImage().
//! @usage
//! @code
//!          txPlaySound ("tada.wav"); // so happy that this always exists
//! @endcode
//}-------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC);

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Оценивает скорость работы компьютера.
//!
//! @return  Скорость работы в условных единицах.
//!
//! @see     txSleep()
//! @usage
//! @code
//!          if (txQueryPerformance() < 1) printf ("Хочется новый компьютер");
//! @endcode
//}-------------------------------------------------------------------------------------------

double txQueryPerformance() _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Вычисление размера массива в элементах
//!
//! @param   arr  Имя массива
//!
//! @return  Размер массива в элементах (не в байтах).
//!
//!          Макрос SIZEARR() вычисляет размер массива в элементах, проверяя, можно ли его
//!          правильно вычислить при компиляции.
//!
//!          Макрос sizearr() просто делит размер всего массива в байтах на размер его элемента,
//!          получается размер массива в элементах. Он не проверяет, можно ли его правильно
//!          вычислить, и при неправильном использовании выдает неверный размер.
//!
//! @warning sizearr() выдает неверный размер, если определение массива вместе с его размером,
//!          известным при компиляции, недоступно в месте использования sizearr(). См. пример ниже.
//!
//! @note    В Microsoft Visual Studio 6 макрос SIZEARR() недоступен.
//!
//! @usage
//! @code
//!          void test()
//!              {
//!              // Размер этого массива, хоть и не указан, но может быть автоматически определен
//!              // компилятором при компиляции программы. Он равен 4 (четыре структуры POINT).
//!
//!              POINT coord[] = { {110, 110}, {120, 120}, {130, 110}, {140, 120} };
//!
//!              // Здесь размер массива известен при компиляции, т.к. он определен здесь же.
//!
//!              for (int i = 0; i < SIZEARR (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!
//!              DrawLines1 (coord);                  // Попытка передать массив без передачи размера.
//!              DrawLines2 (coord, SIZEARR (coord)); // Правильная передача размера массива.
//!
//!              DrawLines3 (coord);                  // В принципе, можно и так, но тут водятся шаблоны.
//!              }
//!
//!          // Функции DrawLines1 и DrawLines2 определены так:
//!
//!          void DrawLines1 (const POINT coord[])
//!              {
//!              // Массивы в Си передаются как указатели на начало массива. Поэтому:
//!              // 1) SIZEARR здесь выдаст ошибку компиляции, и ее легко будет найти.
//!              // 2) sizearr здесь неправильно посчитает размер, что намного хуже,
//!              //      т.к. он будет равен sizeof (POINT*) / sizeof (POINT) == 4/8 == 0.
//!
//!              for (int i = 0; i < SIZEARR (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//!
//!          void DrawLines2 (const POINT coord[], int n)
//!              {
//!              // Здесь размер приходит как целочисленный параметр n, так что все просто.
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

//! Замена макросу SIZEARR() для работы в Microsoft Visual Studio 6

#define sizearr( arr )        ( sizeof (arr) / sizeof (arr)[0] )

//! @}
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Проверка, находится ли параметр х внутри замкнутого интервала [a; b]
//!
//! @param   x  Проверяемый параметр
//! @param   a  Левая  граница (включительно)
//! @param   b  Правая граница (включительно)
//!
//! @return  Если a <= x && x <= b, то истина, если нет - ложь
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
//! @brief   Проверка, находится ли точка pt внутри прямоугольника rect
//!
//! @param   pt    Проверяемая точка в виде <tt> POINT {x, y} </tt>
//! @param   rect  Прямоугольник     в виде <tt> RECT  {left, top, right, bottom} </tt>
//!
//! @return  Результат проверки
//!
//!          Удобно для реализации кнопок.
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
//! @brief   Генератор случайных чисел
//!
//! @param   range  Правая граница диапазона (@b не включая саму границу).
//!
//! @return  Случайное целое число в диапазоне [0; range).
//!
//!          Вы еще помните, что означают разные скобочки в обозначении интервалов? :)
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
//! @brief   Генератор случайных чисел
//!
//! @param   left   Правая граница диапазона (@b включая саму границу).
//! @param   right  Правая граница диапазона (@b включая саму границу).
//!
//! @return  Случайное целое число в диапазоне [left; right].
//!
//!          Вы все еще помните, что означают разные скобочки в обозначении интервалов? :)
//! @usage
//! @code
//!          int money = random (-100, +100);
//!          if (money < 0)
//!              {
//!              char message[100] = "Maybe...";
//!              sprintf ("Играли в лотерею? Верните %d рублей", -money);
//!              MessageBox (txWindow(), message, "Быстро!", 0);
//!              }
//! @endcode
//}-------------------------------------------------------------------------------------------

inline
double random (double left, double right) _TX_CHECK_RESULT;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Возвращает максимальное из двух чисел
//!
//! @param   a  Одно из чисел :)
//! @param   b  Другое из чисел :)
//!
//! @return  Максимальное из двух чисел a и b
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
//! @brief   Возвращает минимальное из двух чисел
//!
//! @param   a  Одно из чисел :)
//! @param   b  Другое из чисел :)
//!
//! @return  Минимальное из двух чисел a и b
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
//! @brief   Число Пи
//!
//! @return  Число Пи
//!
//! @usage
//! @code
//!          if (txPI == 1) MessageBox (txWindow(), "Вы попали в другую Вселенную.", "Поздравляем", MB_ICONSTOP);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Обнулитель типов, не имеющих конструкторов
//!
//! @param   type  Имя типа
//!
//! @return  Значение типа @c type, покомпонентно инициализированное по умолчанию
//!          (для встроенных типов C++ - нулем).
//!
//! @usage
//! @code
//!          void f (POINT p);
//!          ...
//!
//!          POINT z = {}; f (z);  // Так без ZERO
//!
//!          f (ZERO (POINT));     // Так с ZERO
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
//! @name    Очень служебные функции
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Устанавливает дополнительный обработчик оконных сообщений Windows.
//!
//! @param   handler  Новый дополнительный обработчик событий окна. \n
//!                   Если NULL, то дополнительный обработчик удаляется.
//!
//! @return  Адрес предыдущего дополнительного обработчика сообщений окна.
//!
//!          Обработчик будет вызываться @b до обработки события средствами TXLib.
//!          Он должен быть функцией со следующим прототипом:
//! @code
//!          LRESULT CALLBACK NewWndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam);
//! @endcode
//!
//! @warning Обработчик вызывается из вспомогательного (второго) потока, создаваемого
//!          \ref txCreateWindow(). Это @b не тот же самый поток, в котором выполняется
//!          main(). В связи с этим будьте внимательны при работе с глобальными переменными
//!          или их аналогами, т.к. может возникнуть "гонка за данными" (race condition).
//!
//! @warning Если обработчик вернет значение, не равное 0, стандартная обработка
//!          сообщений средствами TXLib не произведется. Возможно, оно даже не
//!          сможет нормально закрыться. Придется завершать программу с помощью
//!          Alt-Ctrl-Del из диспетчера задач, или из более продвинутого диспетчера
//!          <a href=http://technet.microsoft.com/en-us/sysinternals/bb896653.aspx>
//!          Process Explorer</a>. Если Вы берете на себя обработку оконного сообщения,
//!          делайте ее по правилам Win32 (см. MSDN), включая вызов DefWindowProc().
//!
//! @note    Совсем поменять оконную функцию можно с помощью SetWindowLong() или SetWindowLongPtr():
//! @code
//!          WNDPROC OldWndProc = (WNDPROC) SetWindowLongPtr (txWindow(), GWL_WNDPROC, (LONG_PTR) NewWndProc);
//! @endcode
//!          При этом надо обязательно всегда вызывать старую оконную функцию с помощью CallWindowProc(),
//!          (см. MSDN), иначе последствия будут такими же плачевными, как описаны выше.
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
//! @brief   Блокировка холста (контекста рисования).
//!
//! @param   wait  Ожидать конца перерисовки окна вспомогательным потоком
//!
//! @return  Состояние блокировки
//!
//!          Перед вызовом любых функций Win32 GDI необходимо заблокировать
//!          холст функцией txLock() и затем разблокировать с помощью txUnlock().
//!          Это связано с тем, что обновление содержимого окна (для тех, кто знает -
//!          обработка сообщения WM_PAINT в библиотеке TXlib происходит в отдельном
//!          вспомогательном потоке. Надолго блокировать нельзя - при заблокированном
//!          потоке окно не обновляется.
//!
//!          txLock() использует EnterCriticalSection(), и физически приостанавливает
//!          поток, обновляющий окно, так что надолго блокировать нельзя. Иначе тормозится
//!          обработка оконных сообщений, окно перестает реагировать на действия пользователя
//!          и перерисовываться. Нельзя также вызывать txSleep() или Sleep() при заблокированном
//!          потоке.
//!
//!          txLock() / txUnlock() - низкоуровневый механизм. Он отличается от более простого
//!          высокоуровневого механизма txBegin() / txEnd() / txUpdateWindow(),
//!          который не приостанавливает поток, а просто отключает операции по обновлению окна.
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//!          См. исходный текст функций _txCanvas_OnPaint() и _txConsole_Draw() в TXLib.h.
//}-------------------------------------------------------------------------------------------

bool txLock (bool wait = true);

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Разблокировка холста
//!
//! @return  Состояние блокировки (всегда false).
//!
//!          Более подробно см. в описании txLock().
//!
//! @see     txDC(), txLock(), txGDI()
//! @usage
//!          См. исходный текст функций _txCanvas_OnPaint() и _txConsole_Draw() в TXLib.h.
//}-------------------------------------------------------------------------------------------
//! @{

bool txUnlock();

//! @cond INTERNAL
template <typename T> inline T txUnlock (T value);
//! @endcond

//! @}

//{-------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Вызов функции Win32 GDI с автоматической блокировкой и разблокировкой.
//!
//! @param   command  Команда GDI (возможно, возвращающая значение)
//!
//! @return  Значение, возвращаемое вызываемой функцией GDI.
//!          Если система рисования не готова, возвращается значение false.
//!
//! @note    Если система рисования не готова (txDC() возвращает NULL),
//!          то команда GDI не выполняется, а txGDI() возвращает значение false.
//!
//! @note    Если в вызове функции GDI используются запятые, то используйте двойные
//!          скобки, чтобы получился один параметр, так как txGDI() все-таки макрос.
//!
//! @see     txDC(), txLock(), txUnlock()
//! @usage
//! @code
//!          txGDI (( Rectangle (txDC(), x1, y1, x2, y2) )); // Не забудьте про ДВЕ скобки
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define txGDI( command )  txUnlock ( (txLock(), (command)) )

//! @}
//}
//============================================================================================

//============================================================================================
//{          Tune-up constants
//! @name    Настроечные константы
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Запрет статической инициализации TXLib
//!
//!          Если константа определена с помощью #define до включения TXLib.h в программу,
//!          статическая инициализация не проводится. По умолчанию она проводится.
//!
//! @note    Статическая инициализация включает:
//!        - Открытие окна консоли,
//!        - Установку кодовой страницы 1251 консоли для поддержки русского языка,
//!        - Установку русской локали стандартной библиотеки,
//!        - Переинициализация библиотек stdio и iostream на случай, если приложение
//!          не скомпоновано как консольное и библиотеки остались неинициализированы,
//!        - Перехват системных сигналов (деление на 0, обращение по неверному адресу и т.д.),
//!        - Перехват необработанных исключений,
//!        - Смена заголовка консольного окна,
//!        - Установка режима паузы по завершении программы, чтобы окно закрывалось не сразу,
//!        - Подавление паузы от сред программирования, заставляющей нажимать на клавишу два раза.
//!          <br><br>
//! @note    Если статическая инициализация запрещена, но создается окно TXLib с помощью
//!          txCreateWindow(), то библиотека все равно будет инициализирована.
//!
//!          Может задаваться перед включением TXLib.h в программу.
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
//! @brief   Список запускающих программ, которые ждут нажатия клавиши после завершения процесса
//!          TXLib.
//!
//!          Если программа перечислена в списке и TXLib запущена из нее, то при завершении TXLib
//!          указанная программа будет закрыта. (Это произойдет, если не открыто графическое окно
//!          TXLib, а есть только окно консоли.)
//!
//!          Программы разделяются пробелом или запятой. Допускается указание родителя запускающей
//!          программы, после двоеточия.
//!
//!          Может задаваться перед включением TXLib.h в программу.
//!
//! @see     _TX_ALLOW_KILL_PARENTS, _TX_NOINIT
//}-------------------------------------------------------------------------------------------

            // TX_VEGETABLE_PRINTERS
#if !defined  (_TX_WAITABLE_PARENTS)
    #define    _TX_WAITABLE_PARENTS       "cmd.exe:devenv.exe, cb_console_runner.exe:codeblocks.exe, starter.exe:eclipse.exe"
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Разрешать принудительное завершение вызывающих программ, ждущих нажатия клавиш после
//!          завершения TXLib.
//!
//!          Иначе отменяется собственная пауза до нажатия клавиши, встроенная в TXLib, и пусть
//!          тогда паузу делает вызывающий процесс.
//!
//!          Список вызывающих программ, которые могут делать такую паузу, задается в _TX_WAITABLE_PARENTS.
//!
//!          Может задаваться перед включением TXLib.h в программу.
//!
//! @see     _TX_WAITABLE_PARENTS, _TX_NOINIT
//! @usage
//! @code
//!          #define _TX_ALLOW_KILL_PARENT false
//!          #include "TXLib.h"
//! @endcode
//}-------------------------------------------------------------------------------------------

#if !defined (_TX_ALLOW_KILL_PARENT)
#define       _TX_ALLOW_KILL_PARENT       true  // Все, это последняя настроечная константа! Хватит уже.
#endif                                          // И да, я не призываю к убийству родителей. Это технический термин.

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Режим отображения консольного окна. Допустимы любые флаги функции SetWindowPos.
//!
//!          По умролчанию: @c SWP_HIDEWINDOW @d Скрывать консольное окно.
//!
//!          Может задаваться перед включением TXLib.h в программу.
//!
//! @see     _TX_NOINIT
//! @usage
//! @code
//!          #define _TX_CONSOLE_MODE SWP_SHOWWINDOW // Наоборот, показать окно
//!          #include "TXLib.h"
//! @endcode
//}-------------------------------------------------------------------------------------------

#if !defined  (_TX_CONSOLE_MODE)
    #define    _TX_CONSOLE_MODE           SWP_HIDEWINDOW
#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Шрифт консоли
//}-------------------------------------------------------------------------------------------

const char     _TX_CONSOLE_FONT[]         = "Lucida Console";

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Цвет шрифта консоли
//}-------------------------------------------------------------------------------------------

const COLORREF _TX_CONSOLE_COLOR          = TX_LIGHTGRAY;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал мигания курсора консоли (мс)
//}-------------------------------------------------------------------------------------------

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал обновления холста (мс)
//}-------------------------------------------------------------------------------------------

const int      _TX_WINDOW_UPDATE_INTERVAL = 10;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Таймаут операций ожидания (мс)
//}-------------------------------------------------------------------------------------------

const int      _TX_TIMEOUT                = 1000;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Размеры внутренних статических строковых буферов TXLib
//}-------------------------------------------------------------------------------------------

const int      _TX_BUFSIZE                = 1024;

//{-------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Размеры внутренних статических строковых буферов TXLib
//}-------------------------------------------------------------------------------------------

const int      _TX_BIGBUFSIZE             = 2048;

//! @}
//}
//============================================================================================

//============================================================================================
//{          Diagnostics and Tools
//! @name    Диагностика и утилиты
//============================================================================================
//! @{ @cond INTERNAL

#define  TX_QUOTE( symbol )   _TX_QUOT2 (symbol)
#define _TX_QUOT2( symbol )   #symbol

//! @endcond
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя и версия текущего компилятора
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
//! @brief   Макрос, раскрывающийся в имя файла и номер строки файла, где он встретился.
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define __TX_FILELINE__       __FILE__ " (" TX_QUOTE (__LINE__) ")"

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя текущей функции
//!
//! @warning Если определение имени функции не поддерживается компилятором, то __TX_FUNCTION__
//!          раскрывается в имя исходного файла и номер строки.
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
//! @brief   Имя режима сборки
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
//! @brief   Замена стандартного макроса assert(), с выдачей сообщения через MessageBox(),
//!          консоль и OutputDebugString().
//!
//! @param   cond  Условие для проверки
//!
//! @return  Всегда 0
//!
//!          Если условие, проверяемое assert(), истинно, то макрос ничего не делает. \n
//!          Если условие оказывается ложно, то выводится диагностическое сообщение и
//!          программа аварийно завершается.
//!
//! @note    <b>При компиляции в режиме Release (или если определен NDEBUG) assert
//!          превращается в пустой оператор.</b> \n
//!          Не надо помещать в assert() действия, которые важны для работы алгорима.
//!
//! @see     asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_DEBUG_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          assert (0 <= i && i < ARRAY_SIZE);
//!
//!          FILE* input = fopen ("a.txt", "r");
//!          assert (input);
//!
//!          // Этот вызов fgets() НЕ будет выполнен в режиме Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          // Здесь все будет правильно:
//!          bool ok = (fclose (input) == 0);
//!          assert (ok);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#undef  assert

#if !defined (NDEBUG)
    #define assert( cond )    ( !(cond)? (TX_ERROR ("\a" "ВНЕЗАПНО: Логическая ошибка: Неверно, что \"%s\"" _ #cond), 0) : _txNOP (0) )

#else
    #define assert( cond )    ( 0 )

#endif

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит диагностическое сообщение в случае нулевого или ложного результата.
//!
//! @return  Всегда 0
//!
//!          Суффиксная форма макроса assert(), не теряющая в режиме Release
//!          исполнения предиката.
//!
//! @note    <b>Предполагается, что операция в случае неуспеха возвращает 0 или false.</b> \n\n
//!          <b>При компиляции в режиме Release (или если определен NDEBUG) asserted
//!          превращается в пустое место.</b>
//!
//! @see     assert(), __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_DEBUG_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          FILE* input = fopen ("a.txt", "r"); assert (input);
//!
//!          // Этот вызов fgets() будет выполнен в любом случае:
//!          fgets (str, sizeof (str) - 1, input) asserted;
//!
//!          // Этот вызов fgets() НЕ будет выполнен в режиме Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          (fclose (input) != 0) asserted;
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define asserted          || TX_ERROR ("\a" "Обнаружен нулевой или ложный результат")

#else
    #define asserted          || 0

#endif

//! @cond INTERNAL
#define TX_NEEDED             asserted  //!< For compatibility with earlier releases
//! @endcond

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит развернутое диагностическое сообщение.
//!
//! @param   msg  Сообщение с произвольным количеством параметров в стиле функции @c printf().
//!               Если параметров несколько, они разделяются _ (@ref _ "символом подчеркивания",
//!               переопределенным в запятую) вместо настоящей запятой, т.к. TX_ERROR - макрос.
//!
//! @return  Всегда false
//!
//! @see     _, assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_DEBUG_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          TX_ERROR ("Не смог прочитать 'Войну и мир'. Отмазка %d: не нашел '%s'" _ reasonNum _ fileName);
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
//! @brief   Выводит развернутое диагностическое сообщение в отладочном режиме.
//!
//! @param   msg  Сообщение с произвольным количеством параметров в стиле функции @c printf().
//!               Если параметров несколько, они разделяются _ (@ref _ "символом подчеркивания",
//!               переопределенным в запятую вместо настоящей запятой, т.к. TX_DEBUG_ERROR - макрос.
//!
//! @return  Всегда false
//!
//! @note    В режиме Release этот макрос не выводит ничего.
//!
//! @see     _, assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          TX_DEBUG_ERROR ("Так и не смог прочитать 'Войну и мир'. Отмазка %d: потерял '%s'" _ reasonNum _ fileName);
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
//! @brief   Выводит развернутое диагностическое сообщение в отладочном режиме.
//!
//! @param   msg  Сообщение с произвольным количеством параметров в стиле функции @c printf().
//!               Если параметров несколько, они разделяются _ (@ref _ "символом подчеркивания",
//!               переопределенным в запятую вместо настоящей запятой, т.к. TX_DEBUG_ERROR - макрос.
//!
//! @return  Всегда false
//!
//! @note    В режиме Release этот макрос не выводит ничего.
//!
//! @see     _, assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          TX_DEBUG_ERROR ("Так и не смог прочитать 'Войну и мир'. Отмазка %d: потерял '%s'" _ reasonNum _ fileName);
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
//! @brief   Выводит сообщение в отладчике.
//!
//! @param   format  Строка для печати, как в printf().
//!
//! @return  Количество напечатанных символов.
//!
//!          Функция формирует сообщение по правилам printf() и передает его OutputDebugString().
//!          Ее вывод можно перехватить утилитами-логгерами, например,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>DebugView</a>.
//!          Если этого не сделать, и не задать первый символ @c '\a' (см. ниже), то о сообщении никто не узнает.
//!
//! @note    Если первый символ в строке @c '\a', то сообщение также дублирется MessageBox().
//!
//! @warning Сообщение не должно превышать _TX_BIGBUFSIZE символов, иначе оно обрезается.
//!
//! @see     TX_ERROR, TX_DEBUG_ERROR
//! @usage
//! @code
//!          int x = 5821;
//!          ...
//!          txOutputDebugPrintf ("Никто не узнает, что %d.", x);
//! @endcode
//}-------------------------------------------------------------------------------------------

int txOutputDebugPrintf (const char format[], ...) _TX_CHECK_FORMAT (1);

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Макрос, позволяющий передать переменное число параметров в какой-либо другой макрос.
//!
//! @note    <b>Символ подчеркивания просто переопределяется в запятую.</b>
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR()
//! @usage
//! @code
//!          TX_ERROR ("Слишком умный абзац: роман 'Война и мир', файл '%s', строка %d" _ fileName _ lineNum);
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define _                     ,

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит имя файла, номер строки и имя функции, где находится вызов TX_PRINT_HERE().
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
//! @brief   Включает/отключает внутреннюю трассировку исполнения кода библиотеки.
//!
//!          Трассировка идет через макрос _TX_TRACE, который подставляется перед
//!          каждым оператором (statement). По умолчанию трассировка выключена.
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(),
//!          ее вывод можно перехватить утилитами-логгерами, например,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a>. Это можно изменить, переопределив макрос _TX_TRACE.
//!
//! @warning Трассировка @b очень тормозит выполнение программы, особенно при отладке в
//!          Microsoft Visual Studio. В этом случае лучше пользоваться DebugView (см. выше)
//!          и запускать отлаживаемую программу отдельно, а не из-под отладчика Visual Studio.
//!
//!          _TX_ALLOW_TRACE и _TX_TRACE задаются перед включением TXLib.h в программу.
//! @usage
//! @code
//!          #define  _TX_ALLOW_TRACE  // Для просмотра трассы запустить DebugView
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
//! @brief   Трассирует исполнение кода библиотеки через OutputDebugString().
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(),
//!          ее вывод можно перехватить утилитами-логгерами, например,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> или WinTail.
//!
//!          _TX_TRACE можно переопределить в свой код, тогда он будет вызываться
//!          перед каждой строкой кода TXLib.
//!
//!          Трассировку нужно предварительно разрешить идет через макрос _TX_ALLOW_TRACE.
//!          По умолчанию она выключена.
//!
//!          _TX_TRACE и _TX_ALLOW_TRACE задаются перед включением TXLib.h в программу.
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
//! @name    Работа с диалоговыми окнами. Класс txDialog
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Базовый класс для диалоговых окон.
//!
//!          Для создания своего диалогового окна нужно:
//!           -# Унаследовать свой класс из этого базового класса;
//!           -# Задать состав и расположение элементов управления (контролов)
//!              функцией txDialog::setLayout(), или указать карту расположения
//!              при показе диалогового окна функцией txDialog::dialogBox();
//!           -# Переопределить в своем классе функцию txDialog::dialogProc() для
//!              обработки событий диалогового окна или построить карту реакций
//!              на команды с помощью макросов TX_BEGIN_MESSAGE_MAP(),
//!              TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @see     txDialog::setLayout(), txDialog::dialogProc(), txDialog::Layout,
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

struct txDialog
    {

//{-------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Константы для задания типа контрола.
//!
//!          Вместо констант можно использовать названия оконных классов,
//!          преобразованные к типу txDialog::CONTROL.
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

    public:
    enum CONTROL
        {
        DIALOG    = 0x00000000,                  //!< Начало описания диалога
        BUTTON    = 0xFFFF0080,                  //!< Кнопка
        EDIT      = 0xFFFF0081,                  //!< Редактируемый текст
        STATIC    = 0xFFFF0082,                  //!< Нередактируемый элемент (текст, картинка и т.д.)
        LISTBOX   = 0xFFFF0083,                  //!< Список с прокруткой
        SCROLLBAR = 0xFFFF0084,                  //!< Полоса прокрутки
        COMBOBOX  = 0xFFFF0085,                  //!< Комбинированный список
        END       = 0x00000000                   //!< Конец описания диалога
        };

//{-------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Класс для описания элемента диалогового окна (контрола)
//!
//!          Массив таких структур задает описание макета диалогового окна.
//!          Это описание похоже на задание диалога в ресурсном скрипте (.rc):
//!
//!           - Нулевой элемент описывает диалоговое окно в целом
//!           - Остальные элементы описывают контролы
//!           - Последний элемент - txDialog::END или {NULL}
//!
//! @see     txDialog::setLayout(), txDialog::dialogBox(), txDialog::dialogProc()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    public:
    struct Layout
        {
        CONTROL     wndclass;                    //!< Тип контрола
        const char* caption;                     //!< Название или текст
        WORD        id;                          //!< Идентификатор контрола
        short        x;                          //!< Координата верхнего левого угла
        short        y;                          //!< Координата нижнего правого угла
        short       sx;                          //!< Размер по X
        short       sy;                          //!< Размер по Y
        DWORD       style;                       //!< Стиль контрола

        const char* font;                        //!< Шрифт диалогового окна
        WORD        fontsize;                    //!< Размер шрифта диалогового окна
        };

//{-------------------------------------------------------------------------------------------
//! @brief   Конструктор.
//! @see     txDialog::txDialog (const txDialog::Layout*)
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    public:
    txDialog();

//{-------------------------------------------------------------------------------------------
//! @brief   Конструктор.
//!
//! @param   layout  Макет диалогового окна
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    txDialog (const Layout* layout);

//{-------------------------------------------------------------------------------------------
//! @brief   Деструктор.
//}-------------------------------------------------------------------------------------------

    virtual ~txDialog() {};

//{-------------------------------------------------------------------------------------------
//! @brief   Устанавливает текущий макет диалогового окна.
//!
//! @param   layout  Макет диалогового окна
//!
//! @return  Предыдущий макет.
//!
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*)
//! @see     txDialog::dialogBox()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    const Layout* setLayout (const Layout *layout);

//{-------------------------------------------------------------------------------------------
//! @brief   Функция обработки сообщений диалогового окна.
//!
//! @param   _wnd     Дескриптор
//! @param   _msg     Номер сообщения
//! @param   _wParam  1-й параметр сообщения (WORD)
//! @param   _lParam  2-й параметр сообщения (DWORD)
//!
//! @return  В большинстве случаев false, детальнее см. DialogProc
//!          в <a href=msdn.com>MSDN</a>.
//!
//!          Эту функцию надо переопределить для обработки событий окна,
//!          или построить ее с помощью макросов TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @see     txDialog::dialogBox()
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

//{-------------------------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//!
//! @param   layout   Макет диалогового окна. \n
//!                     Если не указан - используется значение, заданное txDialog::setLayout()
//!                     или конструктором txDialog::txDialog (const txDialog::Layout*).
//! @param   bufsize  Размер буфера для создания шаблона диалога (если не указан - размер по
//!                     умолчанию)
//!
//! @return  Значение, указанное в функции EndDialog(). \n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была
//!          запущена txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    INT_PTR dialogBox (const Layout* layout = NULL, size_t bufsize = 0);

//{-------------------------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//!
//! @param   resource  Идентификатор диалогового ресурса
//!
//! @return  Значение, указанное в функции EndDialog(). \n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была
//!          запущена txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}-------------------------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource);

//{-------------------------------------------------------------------------------------------
//! @brief   Закрытые конструктор копирования и оператор присваивания.
//}-------------------------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//{-------------------------------------------------------------------------------------------
//! Настоящая диалоговая функция (не txDialog::dialogProc(), т.к. функция окна
//! Win32 должна быть статической).
//}-------------------------------------------------------------------------------------------

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//{-------------------------------------------------------------------------------------------
//! Текущий макет диалога.
//}-------------------------------------------------------------------------------------------

    private:
    const Layout* layout_;
    };

//! @}
//}
//============================================================================================

//============================================================================================
//{          Dialogs: Message Map macros
//! @name    Макросы для построения статической карты сообщений (Message Map)
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Заголовок карты сообщений (Message Map).
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//! @brief   Заголовок обработчика сообщения (Message handler) карты сообщений.
//!
//! @param   id  Идентификатор сообщения
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//! @hideinitializer
//}-------------------------------------------------------------------------------------------

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

//{-------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Начало карты команд (Command map) в карте сообщений.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//! @brief   Завершитель карты сообщений.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//! @name    Пример использования класса диалога: функция txInputBox()
//============================================================================================
//! @{
//{-------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Ввод строки в отдельном окне.
//!
//! @param   text     Текст с вопросом
//! @param   caption  Заголовок окна
//! @param   input    Значение строки по умолчанию
//!
//! @return  Введенная строка (статическая переменная функции).
//!
//! @warning Возвращаемая строка - статическая, и обновляется при каждом вызове функции.
//!          Если txInputBox() будет вызываться несколько раз, то для сохранения строки
//!          ее необходимо копировать в другую строку при помощи <i>strcpy()</i>.
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
    // Если не указаны параметры, приходится использовать хоть какие-то надписи.
    // txGetModuleFileName() - имя EXE-файла, на случай, если кое-кто поленился задать название.
    //----------------------------------------------------------------------------------------

$   if (!text)    text    = "Введите строку:";
$   if (!caption) caption = txGetModuleFileName (false);
$   if (!input)   input   = "";

    //----------------------------------------------------------------------------------------
    // Идентификаторы элементов диалога. Они требуются в GetDlgItemText().
    // Если диалог строится не вручную, а редактором ресурсов, то они задаются в нем автоматически.
    // У нас же тут - хардкор стайл, к сожалению. Причина в том, что у разных сред программирования
    // разные редакторы ресурсов и системы сборки. Поэтому для независимости от них все будет
    // строиться на этапе выполнения, динамически. Вы еще посмотрите, как это будет реализовано
    // в txDialog::dialogBox() и _tx_DLGTEMPLATE_()... О_о
    //----------------------------------------------------------------------------------------

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    //----------------------------------------------------------------------------------------
    // Задание макета (вида) диалога в виде массива структур.
    // С помощью особого порядка полей в структуре txDialog::Layout и констант из класса
    // txDialog этот массив становится похож на описание ресурса диалога в .rc - файле.
    // См. описание синтаксиса rc-файла в документации по Win32 (MSDN, http://msdn.com).
    //----------------------------------------------------------------------------------------

$   txDialog::Layout layout[] =

    //----------------------+-----------+-------------+-----------------+---------------------
    //     Тип элемента     | Имя       | Идентифика- |   Координаты    | Флаги элементов
    //     диалога          | элемента  | тор, связан-|-----------------| (см. описание элементов диалога в MSDN).
    //                      |           | ный с ним   | X | Y |Шир.|Выс.|
    //----------------------+-----------+-------------+---+---+----+----+---------------------
    //                      |           |             |   |   |    |    |
        {{ txDialog::DIALOG,   caption,   0,             0,  0, 240,  85                                                     },
         { txDialog::STATIC,   text,      ID_TEXT_,     10, 10, 150,  40, SS_LEFT                                            },
         { txDialog::EDIT,     input,     ID_INPUT_,    10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP  },
         { txDialog::BUTTON,   "&OK",     IDOK,        180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP  },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL,    180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP  },
         { txDialog::END                                                                                                     }};

    //----------------------------------------------------------------------------------------
    // Класс диалога для InputBox. Внутренний, т.к. зачем ему быть внешним.
    // Нужен в основном для задания строки ввода (str) и оконной функции диалогового окна,
    // требуемой Win32 (она построена макросами TX_BEGIN_MESSAGE_MAP и другими). Можно не делать
    // внутреннего класса, но тогда оконную функцию придется писать в глобальной области видимости,
    // и str объявлять глобально тоже (или передавать ее адрес через DialogBoxParam и записывать
    // его в класс во время обработки WM_INITDIALOG).
    //----------------------------------------------------------------------------------------

    struct inputDlg : txDialog
        {
        char str [1024];

        //------------------------------------------------------------------------------------

        inputDlg() :
            str()                               // Обнуление всей строки. Не работает на старых
            {                                   //     компиляторах, поэтому еще раз:
$           memset (str, 0, sizeof (str) - 1);  // Обнуление всей строки
            }

        //------------------------------------------------------------------------------------

        TX_BEGIN_MESSAGE_MAP()    // Карта сообщений. На самом деле это начало оконной функции.

            TX_COMMAND_MAP        // Здесь обрабатываются WM_COMMAND. На самом деле это switch.

                //----------------------------------------------------------------------------
                // При нажатии кнопки OK копируем строку из поля ввода в нашу переменную str,
                // т.к. после закрытия диалога строка ввода умрет и текст уже из нее получить.
                // Этот макрос на самом деле превращается в case из оператора switch.
                // _wnd - это параметр оконной функции, см. определение макроса TX_BEGIN_MESSAGE_MAP().
                //----------------------------------------------------------------------------

                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP

        //------------------------------------------------------------------------------------
        // Конец внутреннего класса диалога
        //------------------------------------------------------------------------------------

        };

    //----------------------------------------------------------------------------------------
    // Убираем дефайны, чтобы потом не мешали.
    // От этого они получаются "локального действия", как будто у них была бы область видимости -
    // функция. На самом деле это сделано вручную через #undef. Чтобы подчеркнуть их локальную
    // природу, у них имена заканчиваются на _. Такие дейфайны потом не перекосячат весь код после
    // того как, фактически, стали уже не нужны.
    //----------------------------------------------------------------------------------------

    #undef ID_TEXT_
    #undef ID_INPUT_

    //----------------------------------------------------------------------------------------
    // Это статический объект, потому что строка в нем должна жить после завершения функции.
    //----------------------------------------------------------------------------------------

$   static inputDlg dlg;

    //----------------------------------------------------------------------------------------
    // Передаем layout и запускаем окно диалога
    //----------------------------------------------------------------------------------------

$   dlg.dialogBox (layout);

    //----------------------------------------------------------------------------------------
    // Возвращаем адрес строки из статического объекта. Так можно делать, потому что статический
    // объект не умрет при выходе из функции и строка в нем, соответственно, тоже. Адрес
    // нестатических переменных передавать синтаксически можно, но ведет к серьезным ошибкам.
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
//           Реализация функций библиотеки
//============================================================================================
//! @cond INTERNAL

//============================================================================================
//{          [Internal] Function prototypes, macros and constants
//           Прототипы внутренних функций, макросы и константы
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
    #define  _txAssertOK()          ( txOK() || TX_ERROR ("\a" "Окно рисования не создано") )
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

const int    _TX_IDM_ABOUT          = 40000;  // Идентификаторы системного меню окна
const int    _TX_IDM_CONSOLE        = 40001;

//}
//============================================================================================

//============================================================================================
//{          [Internal] DLL functions import
//! @name    Импорт внешних библиотек
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
//           Малая механизация
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
//! @name    Глобальные данные
//           Не упакованы в структуру или класс, для того, чтобы это сделали Вы сами :)
//============================================================================================
//! @{

unsigned         _txMainThreadId        = 0;      // ID потока, где выполняется main()
unsigned         _txCanvas_ThreadId     = 0;      // ID потока, владеющего окном холста TXLib

HWND             _txCanvas_Window       = NULL;   // Дескриптор окна холста TXLib

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

WNDPROC          _txAltWndProc          = NULL;   // Альтернативная оконная функция. См. txSetWindowHandler().

const char*      _txSrcLocFile          = NULL;
int              _txSrcLocLine          = 0;
const char*      _txSrcLocFunc          = NULL;

int              _txStaticInitialized   = _TX_NOINIT || _txInitialize();

//! @}
//}
//============================================================================================

//============================================================================================
//{          TXLib engine init/check/cleanup
//! @name    Инициализация/проверка/завершение TXLib
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
$   strncat_s (title, " [ЗАВЕРШЕНО]", sizeof (title) - 1);
$   if (wnd) SetWindowText (wnd, title);

$   DWORD parent = 0;
$   bool waitable = _txIsParentWaitable (&parent);
$   bool waitKey  = !waitable || _TX_ALLOW_KILL_PARENT;

$   if (isMaster && !_txExit && GetCurrentThreadId() == _txMainThreadId)
        {
$       if (!canvas && waitKey)
            printf ("\n" "[Нажмите любую клавишу для завершения]");

$       while (_kbhit()) (void)_getch();

$       for (int i = 1; ; i++)
            {
$           if (_kbhit()) break;

            if ( canvas && !_txCanvas_ThreadId) break;
            if (!canvas && !waitKey)            break;

            Sleep (_TX_WINDOW_UPDATE_INTERVAL);

            if (!(i % 100500))
                printf ("\r" "[Нажмите же какую-нибудь клавишу для моего завершения]");
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
//! @name    Функции окна TXLib                     (_txCanvas...)
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
//! @name    События основного окна                (_txCanvas_On...)
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

    // Инициируем остановку цикла сообщений

$   PostQuitMessage (_txRunning? WM_DESTROY : EXIT_SUCCESS);

$   if (!_txCanvas_Window) return false;

    // Indicate that we are about to manually terminate

$   _txExit = true;

    // Lock GDI resources

$   bool locked = false;
$   _txWaitFor ((locked = txLock (false), locked));
$   if (!locked) TX_DEBUG_ERROR ("Cannot lock GDI to free resources");

    // Освобождаем ресурсы, связанные с окном

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
        MessageBox (wnd, "Функция main() не завершена. Программа все еще работает. Прервать ее аварийно?    \n\n"
                         "Внимание: ресурсы не будут освобождены, это может нарушить работу Windows.\n"
                         "Лучше подождать, когда main() завершится - это отображается в заголовке окна.",
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
        #define __DESCRIPTION  "(Мне лень задать описание)." " \t\t" "#define __DESCRIPTION to override project role."
        #endif

        #ifndef __AUTHOR
        #define __AUTHOR       "(Непонятно кто)."            " \t\t" "#define __AUTHOR to override this name."
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
                     "Здесь могла бы быть Ваша реклама:)" EOL_
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
//! @name    Функции консольного окна              (_txConsole...)
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
//! @name    Функции "виртуального холста" (графического буфера, _txBuffer...)
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
//! @name    Диагностика
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

    const char* sSig = ": Неизвестный тип сигнала";
    const char* sFPE = ": Неизвестный тип исключения";

    #define GET_DESCR_( str, code, descr )  case (code): { (str) = #code ": " descr; break; }

    switch (sig)
        {
        GET_DESCR_ (sSig, SIGSEGV, "Доступ по неверному указателю. Ставьте ассерты!")
        GET_DESCR_ (sSig, SIGILL,  "Попытка выполнить недопустимую операцию. Проверьте указатели на функции.")
        GET_DESCR_ (sSig, SIGABRT, "Аварийное завершение программы, вызвана функция abort.")
        GET_DESCR_ (sSig, SIGTERM, "Получен сигнал принудительного завершения программы")
        GET_DESCR_ (sSig, SIGFPE,  "Грубая ошибка в вычислениях, деление на 0 или что-то еще")
        default:   break;
        }

    if (sig == SIGFPE) switch (fpe)
        {
        #ifdef _FPE_INVALID
        GET_DESCR_ (sFPE, _FPE_INVALID,        "Результат неверен")
        GET_DESCR_ (sFPE, _FPE_DENORMAL,       "Денормализация")
        GET_DESCR_ (sFPE, _FPE_ZERODIVIDE,     "Деление на ноль")
        GET_DESCR_ (sFPE, _FPE_OVERFLOW,       "Переполнение результата")
        GET_DESCR_ (sFPE, _FPE_UNDERFLOW,      "Антипереполнение результата")
        GET_DESCR_ (sFPE, _FPE_INEXACT,        "Неточный результат")
        GET_DESCR_ (sFPE, _FPE_UNEMULATED,     "Операция не эмулируется")
        GET_DESCR_ (sFPE, _FPE_SQRTNEG,        "Квадратный корень из -1")
        GET_DESCR_ (sFPE, _FPE_STACKOVERFLOW,  "Переполнение стека")
        GET_DESCR_ (sFPE, _FPE_STACKUNDERFLOW, "Антипереполнение стека")
        GET_DESCR_ (sFPE, _FPE_EXPLICITGEN,    "Явный вызов исключения")
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
              "std::unexpected(): Необработанное исключение. Проверьте свои catch-блоки. Перехватите catch (...).    \n"
              "Проверьте, не нарушена ли спецификация исключений какой-либо функции, если вы ее (зря) используете.");
    }

//--------------------------------------------------------------------------------------------

void _txOnTerminate()
    {
    _txError (NULL, 0, NULL, (DWORD)-1,-1,-1,
              "std::terminate(): Программа будет завершена из-за неперехваченного исключения в функции main()    \n"
              "или в деструкторе. Используйте try/catch блоки, перехватывайте catch (...), разбирайтесь, в чем дело.");
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

        MessageBox (wnd, str, "Оказывается, что", MB_ICONEXCLAMATION | MB_TOPMOST);
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

                s +=  _snprintf_s  (s, SZARG_ (1), "TX_ERROR() сообщает:" "\v\v");

    if (file)   s +=  _snprintf_s  (s, SZARG_ (1), "Файл: %s," _TX_NAME, file);
    if (line)   s +=  _snprintf_s  (s, SZARG_ (1), "Строка: %d, ",       line);
    if (func)   s +=  _snprintf_s  (s, SZARG_ (1), "Функция: %s   \v\v", func);

    if (msg)    s +=  _snprintf_s  (s, SZARG_ (1), "%s: ", (file || line || func)? "Сообщение" : "ВНЕЗАПНО"),
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

    MessageBox (NULL, str[0], fatal? "Фатальная ошибка" : "Ошибка в программе",
                MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

    va_end (arg);

    if (fatal)
        {
        if (!IsDebuggerPresent()) exit (EXIT_FAILURE);

/* > */ DebugBreak(); // >>> Вы в отладчике, есть шанс посмотреть переменные и разобраться.
        }             //     Выходите из функции пошаговой отладкой. Смотрите на стек вызовов.

    return false;
    }

//! @}
//}
//============================================================================================

//============================================================================================
//{          TXLib API implementation
//           Реализация TXLib API
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
                "Это запланированная ошибка. Такое бывает. Вы хотели вызвать:" "\n\n"
                "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()" "\n\n"
                "Хоть вы долго [копировали]набирали это имя, на самом деле эта функция не работает." "\n"
                "Но для нее есть работающий синоним. См. определение этой функции в исходных текстах библиотеки."    "\n\n",
                "Не получилось", MB_ICONSTOP);

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
//           Реализация методов класса txDialog
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

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_DEBUG_ERROR ("Не найден ресурс диалога %d" _
                                                                          resourceID);
$   return DialogBoxParam (NULL, resName, NULL, dialogProc__, (LPARAM) this);
    }

//--------------------------------------------------------------------------------------------

INT_PTR txDialog::dialogBox (const txDialog::Layout* layout /*= NULL*/, size_t bufsize /*= 0*/)
    {
$   if (!layout)  layout = layout_;
$   if (!layout)  return TX_DEBUG_ERROR ("Не установлен динамический шаблон диалога");

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_DEBUG_ERROR ("GlobalAlloc(): Нет памяти для шаблона диалога");

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
//           Очистка служебных макросов
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
//           Адаптация к компиляторам и платформам
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

