//===============================================================================================================================
//              [These sections are for folding control  in Code::Blocks]
//{             [Best viewed with "Fold all on file open" option enabled]
//===============================================================================================================================
//!
//! @file       TXLib.h
//! @brief      Главный файл
//!
//! @mainpage
//!
//! @brief      Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
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
//! @defgroup Drawing   Рисование
//! @defgroup Mouse     Поддержка мыши
//! @defgroup Dialogs   Диалоговые окна
//! @defgroup Misc      Разное
//! @defgroup Service   Служебное
//! @defgroup Technical Технические детали
//}
//===============================================================================================================================

#if !defined (__TXLIB_H) || defined (_TX_MULTIPLE_INSTANCE)
#define       __TXLIB_H

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Текущая версия библиотеки.
//!
//!          Эта константа автоматически обновляется при обновлении версии.
//!
//! @see     txVersion()
//-------------------------------------------------------------------------------------------------------------------------------
//! @{

#define _TX_VERSION           "TXLib [Version 0.01 alpha, build 72]"
#define _TX_AUTHOR            "Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)"

#define _TX                   0x0001720a        //!< Версия библиотеки в целочисленном формате

//! @}
//}------------------------------------------------------------------------------------------------------------------------------

//{ <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< All the code is here, unfold it

//-------------------------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    Адаптация к компиляторам и платформам
//-------------------------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#ifndef __cplusplus
#error TXLib.h: Must use C++ to compile this
#endif

#ifdef __STRICT_ANSI__                          // Try to extend strict ANSI C
#warning TXLib.h: Trying to extend strict ANSI compatibility
#undef __STRICT_ANSI__
#endif

//-------------------------------------------------------------------------------------------------------------------------------

#if defined (__GNUC__)

    #if (__GNUC__ >= 4)
        #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
//!!!        #pragma GCC diagnostic ignored "-Wstrict-aliasing"
//!!!        #pragma GCC diagnostic ignored "-Wunreachable-code"
//!!!        #pragma GCC diagnostic ignored "-Wunused-value"
//!!!        #pragma GCC diagnostic ignored "-Wunused-function"
        #pragma GCC diagnostic ignored "-Wunused-label"  // Just for fun in _txCanvas_OnCmdAbout()
    #endif

    #define _TX_CHECK_FORMAT( fmtIdx )  __attribute__ (( format (printf, (fmtIdx), (fmtIdx)+1) ))
    #define _TX_CHECK_USAGE             __attribute__ (( warn_unused_result ))

#else

    #define _TX_CHECK_FORMAT( fmtIdx )
    #define _TX_CHECK_USAGE

#endif

//-------------------------------------------------------------------------------------------------------------------------------

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
//!!!    #pragma warning (disable: 4100)             // unreferenced formal parameter
//!!!    #pragma warning (disable: 4511)             // copy constructor could not be generated
//!!!    #pragma warning (disable: 4512)             // assignment operator could not be generated
    #pragma warning (disable: 4663)             // C++ language change: to explicitly specialize class template '...'

    #if !defined (WINVER)
        #define WINVER   0x0400                 // MSVC 6: Defaults to Windows 95
    #endif

#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1400)    // MSVC 8 (2005) or greater

    #define _TX_USE_SECURE_CRT

#else

    #define  strncpy_s              strncpy     // MSVC prior to 8(2005) versions and GCC
    #define  strncat_s              strncat     //   do NOT have secure variants of these
    #define  ctime_s                ctime       //   functions, so use insecure ones.
    #define _snprintf_s            _snprintf    //
    #define _vsnprintf_s           _vsnprintf   //
    #define  strerror_s(buf,code)   strerror (code)

#endif

//-------------------------------------------------------------------------------------------------------------------------------

#if defined (__INTEL_COMPILER)

//  remark #174                                 // expression has no effect
//  remark #304                                 // access control not specified ("public" by default)
//  remark #522                                 // function "..." redeclared "inline" after being called
//  remark #981                                 // operands are evaluated in unspecified order
//  warning #1684                               // conversion from pointer to same-sized integral type (portability problem)

#endif

//-------------------------------------------------------------------------------------------------------------------------------

#ifndef     WINVER
    #define WINVER       0x0500                 // Defaults to Windows 2000
    #define WINDOWS_ENABLE_CPLUSPLUS            // Allow use of type-limit macros in <basetsd.h>,
#endif                                          //   they allowed by default if WINVER >= 0x0600.

#ifndef     _WIN32_WINNT
    #define _WIN32_WINNT WINVER                 // Defaults to the same as WINVER
#endif

#undef   UNICODE                                // Drop the Unicode
#undef  _UNICODE

//-------------------------------------------------------------------------------------------------------------------------------

#undef  _TX_ANON_NSPACE

#ifdef  _TX_MULTIPLE_INSTANCE
    #define _TX_ANON_NSPACE  _TX_MULTIPLE_INSTANCE  // Guard TXLib from linker errors when included
                                                    //   in several files of multifile project. See
#else                                               //   "namespace TX..." below.
    #define _TX_ANON_NSPACE

#endif

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
//! @name    Адаптация к компиляторам и платформам
//-------------------------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#if defined (_MSC_VER) && (_MSC_VER == 1200)    // MSVC 6 (1998)

    #pragma warning (push, 4)                   // Restore maximum level

#endif

//! @endcond
//}

//-------------------------------------------------------------------------------------------------------------------------------
//{          This function should lie outside TX namespace(s)
//-------------------------------------------------------------------------------------------------------------------------------

#ifndef TX_COUNTER
#define TX_COUNTER _tx_Counter

inline
int _tx_Counter()
    {
    static int count = 1;
    return count++;
    }

#endif

//}

//===============================================================================================================================

// All the code goes below.

/*! @cond INTERNAL @cond OFF */ namespace _TX_ANON_NSPACE { /*! @endcond */ namespace TX { /*! @endcond */

//===============================================================================================================================
//{          TXLib interface
//! @name    Интерфейс библиотеки
//===============================================================================================================================

//===============================================================================================================================
//{          Colors
//! @name    Цвета
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Названия предопределенных цветов.
//!
//!          См. @ref TX_BLACK, @ref TX_BLUE и другие цвета в списке выше.
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
    TX_BLACK         = RGB (  0,   0,   0),   //!< Черный цвет.
    TX_BLUE          = RGB (  0,   0, 128),   //!< Темно-синий цвет.
    TX_GREEN         = RGB (  0, 128,   0),   //!< Зеленый цвет.
    TX_CYAN          = RGB (  0, 128, 128),   //!< Бирюзовый цвет.
    TX_RED           = RGB (128,   0,   0),   //!< Темно-красный цвет.
    TX_MAGENTA       = RGB (128,   0, 128),   //!< Темно-малиновый цвет.
    TX_BROWN         = RGB (128, 128,   0),   //!< Коричневый цвет. Некрасивый. Do it yourself using @ref RGB().
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
    TX_NULL          = TX_NULL,               //!< Прозрачный цвет. <i>Отключает рисование.</i>

//  Цветовые каналы (компоненты) - см. @ref txExtractColor(), @ref txRGB2HSL(), @ref txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< Цветовой тон цвета в модели HSL
    TX_SATURATION   = 0x05000000,             //!< Насыщенность цвета в модели HSL
    TX_LIGHTNESS    = 0x06000000;             //!< Светлота цвета в модели HSL

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает (смешивает) цвет из трех базовых цветов (компонент).
//!
//! @param   red    Количество красного цвета в интервале [0; 255]
//! @param   green  Количество зеленого цвета в интервале [0; 255]
//! @param   blue   Количество синего   цвета в интервале [0; 255]
//!
//! @return  Созданный цвет в формате COLORREF.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета"
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
//! @brief   Извлекает цветовую компоненту (цветовой канал) из смешанного цвета.
//!
//! @param   color      Смешанный цвет
//! @param   component  Извлекаемая компонента, см. @ref TX_BLACK "Цвета"
//!
//! @return  Цветовая компонента, см. @ref TX_BLACK "Цвета"
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), TX_BLACK "Цвета"
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_BLACK "Цвета"
//! @usage
//! @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          Другие примеры см. в функциях AppearText(), AppearEarth() Примера 5 ("Циклы").
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

int txExtractColor (COLORREF color, COLORREF component);

//{--------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Преобразует цвет из формата RGB в формат HSL.
//!
//! @param   rgbColor  Преобразуемый цвет в формате @ref RGB
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета"
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_BLACK "Цвета"
//! @usage
//! @code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Преобразует цвет из формата HSL в формат @ref RGB.
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета"
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_BLACK "Цвета"
//! @usage
//! @code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor);

//}

//===============================================================================================================================
//{          Initialization
//! @name    Инициализация библиотеки
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создание окна рисования
//!
//! @param   sizeX     Размер окна по горизонтали (в пикселях)
//! @param   sizeY     Размер окна по вертикали   (в пикселях)
//! @param   centered  Центрирование окна на дисплее
//!
//! @return  Номер открытого окна TXLib (начиная с 1). Если окно не открыто, возвращается 0.
//!
//!          При создании окна устанавливаются параметры рисования по умолчанию,
//!          см. функцию @ref txSetDefaults().
//!
//! @see     txOK()
//! @usage
//! @code
//!          txCreateWindow ( 800,  600);
//!          txCreateWindow (1024,  768, false);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

int txCreateWindow (int sizeX, int sizeY, bool centered = true);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txSelectFont(), txSelectRegion(), txSetROP2()
//! @usage
//! @code
//!          txSetDefaults();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetDefaults();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
bool txOK();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

POINT txGetExtent();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetExtentX();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetExtentY();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
HDC& txDC();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
HWND txWindow();

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Возвращает строку с информацией о текущей версии библиотеки.
//!
//! @return  Строка с информацией о текущей версии библиотеки.
//!
//! @usage
//! @code
//!          printf ("I personally love %s\n", txVersion());
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline
const char* txVersion();

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Возвращает номер версии библиотеки.
//!
//! @return  Номер версии библиотеки.
//!
//! @usage
//! @code
//!          printf ("My magic number %x\n", txVersionNumber());
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline
unsigned txVersionNumber();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

const char* txGetModuleFileName (bool fileNameOnly = true);

//}

//===============================================================================================================================
//{          Setting the parameters
//! @name    Установка цветов и режимов рисования
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет и толщину линий, цвет текста.
//!
//! @param   color      Цвет линий и текста, см. @ref TX_BLACK "Цвета", RGB()
//! @param   thickness  Толщина линий
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetColor (COLORREF color, int thickness = 1);

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          txColor (1.0, 0.5, 0.25);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txColor (double red, double green, double blue);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет линий и текста.
//!
//! @return  Текущий цвет линий и текста, см. @ref TX_BLACK "Цвета", RGB()
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          COLORREF color = txGetColor();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txGetColor();

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет заполнения фигур.
//!
//! @param   color  Цвет заполнения, см. @ref TX_BLACK "Цвета", RGB()
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetFillColor (COLORREF color);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txFillColor (double red, double green, double blue);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет заполнения фигур.
//!
//! @return  Текущий цвет заполнения фигур, см. @ref TX_BLACK "Цвета", RGB()
//!
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          COLORREF color = txGetFillColor();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

COLORREF txGetFillColor();

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает режим взаимодействия цветов при рисовании.
//!
//!          При рисовании графическая библиотека может не просто красить пиксели
//!          на экране, а смешивать цвета экрана и текущие цвета линий и заполнения.
//!
//! @param   mode  Режим смешивания цветов
//!
//! @return  Предыдущий режим взаимодействия цветов, см. @ref TX_BLACK "Цвета", RGB()
//!
//! @title   Режимы взаимодействия цветов:
//! @table   @tr R2_COPYPEN     @td Пиксели = цвета кисти (самый нормальный режим :) @endtr
//!          @tr R2_NOTCOPYPEN  @td Пиксели = ~кисть\n @endtr
//!          @tr @endtr
//!          @tr R2_BLACK       @td Пиксели = черный цвет (цвет кисти игнорируется)    @endtr
//!          @tr R2_WHITE       @td Пиксели = белый  цвет (цвет кисти игнорируется)    @endtr
//!          @tr R2_NOT         @td Пиксели = ~пиксели    (цвет кисти игнорируется)\n  @endtr
//!          @tbr
//!          @tr R2_XORPEN      @td Пиксели =    пиксели ^  кисть    @endtr
//!          @tr R2_NOTXORPEN   @td Пиксели = ~ (пиксели ^  кисть)\n @endtr
//!          @tbr
//!          @tr R2_MASKPEN     @td Пиксели =    пиксели &  кисть    @endtr
//!          @tr R2_NOTMASKPEN  @td Пиксели = ~ (пиксели &  кисть)   @endtr
//!          @tr R2_MASKNOTPEN  @td Пиксели =    пиксели & ~кисть    @endtr
//!          @tr R2_MASKPENNOT  @td Пиксели =   ~пиксели &  кисть\n  @endtr
//!          @tbr
//!          @tr R2_MERGEPEN    @td Пиксели =    пиксели |  кисть    @endtr
//!          @tr R2_NOTMERGEPEN @td Пиксели = ~ (пиксели |  кисть)   @endtr
//!          @tr R2_MERGENOTPEN @td Пиксели =    пиксели | ~кисть    @endtr
//!          @tr R2_MERGEPENNOT @td Пиксели =   ~пиксели |  кисть\n  @endtr
//!          @tbr
//!          @tr R2_NOP         @td Пиксели вообще не изменяются.    @endtr
//! @endtable
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txSetROP2 (int mode = R2_COPYPEN);

//}

//===============================================================================================================================
//{          Drawing
//! @name    Рисование фигур
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Стирает холст текущим цветом заполнения.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txSetFillColor(), txFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          txClear();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txClear();

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует пиксель (точку на экране).
//!
//! @param   x      Х-координата точки
//! @param   y      Y-координата точки
//! @param   color  Цвет точки, см. @ref TX_BLACK "Цвета", RGB()
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txPixel(), txGetPixel(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          txSetPixel (100, 100, TX_RED);
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline
bool txSetPixel (int x, int y, COLORREF color);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
bool txPixel (int x, int y, int red, double green, double blue);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет точки (пикселя) на экране.
//!
//! @param   x  Х-координата точки
//! @param   y  Y-координата точки
//!
//! @return  Текущий цвет пикселя, см. @ref TX_BLACK "Цвета", RGB()
//!
//! @see     txSetPixel(), txPixel(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED)
//!              CarCrash (x, y);     // Mess with the red - die like the rest
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline
COLORREF txGetPixel (int x, int y);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txLine (100, 200, 400, 500);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txLine (int x0, int y0, int x1, int y1);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txRectangle (100, 200, 400, 500);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txRectangle (int x0, int y0, int x1, int y1);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          POINT star[6] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}, {150, 300}};
//!          txPolygon (star, 6);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txEllipse (100, 100, 300, 200);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txEllipse (int x0, int y0, int x1, int y1);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txCircle (100, 100, 10);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txCircle (int x, int y, int r);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txArc (100, 100, 300, 200, 0, 180);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txArc (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txPie (100, 100, 300, 200, 0, 180);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txPie (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txChord (100, 100, 300, 200, 0, 180);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txChord (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          @tr FLOODFILLSURFACE @td - Заливать область,    указанную цветом color. @endtr
//!          @tr FLOODFILLBORDER  @td - Заливать до границы, указанной цветом color. @endtr
//!          @endtable
//!
//! @see     txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txFloodFill (100, 100);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txFloodFill (int x, int y, COLORREF color = TX_TRANSPARENT, DWORD mode = FLOODFILLSURFACE);
//}

//===============================================================================================================================
//{          Drawing text
//! @name    Работа с текстом
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txTextOut (int x, int y, const char text[]);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "Здесь вновь могла бы быть Ваша реклама.");
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format = DT_CENTER | DT_VCENTER | DT_WORDBREAK |
                                   DT_MODIFYSTRING | DT_PATH_ELLIPSIS);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txSelectFont (const char name[], int sizeY,
                   int  sizeX     = -1,
                   int  bold      = FW_DONTCARE,
                   bool italic    = false,
                   bool underline = false,
                   bool strikeout = false);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[]);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[]);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[]);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущее выравнивание текста.
//!
//! @param   align  Флаги выравнивания
//!
//! @return  Предыдущее состояние выравнивания текста.
//!
//! @title   Флаги выравнивания: @table
//!          @tr TA_BASELINE @td Точка (X,Y) определяет базовую линию текста. @endtr
//!          @tr TA_BOTTOM   @td Точка (X,Y) определяет нижнюю сторону описанного прямоугольника\n
//!                              (текст лежит выше этой точки).   @endtr
//!          @tr TA_TOP      @td Точка (X,Y) определяет верхнюю сторону описанного прямоугольника\n
//!                              (текст лежит ниже этой точки).\n @endtr
//!          @tbr
//!          @tr TA_CENTER   @td Текст будет выровнен по горизонтали относительно точки (X,Y). @endtr
//!          @tr TA_LEFT     @td Точка (X,Y) определяет левую сторону описанного прямоугольника\n
//!                              (текст лежит правее этой точки). @endtr
//!          @tr TA_RIGHT    @td Точка (X,Y) определяет правую сторону описанного прямоугольника\n
//!                              (текст лежит левее этой точки).  @endtr
//!          @endtable
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_RIGHT);
//!
//!          txSetTextAlign();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[]);

//}

//===============================================================================================================================
//{          Drawing to memory DC and image loading
//! @name    Рисование в памяти (на "виртуальном холсте") и загрузка изображений
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (int sizeX, int sizeY, HBITMAP bitmap = NULL);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[]);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Уничтожает холст (контекст рисования, DC) в памяти.
//!
//! @param   dc     Контекст рисования для уничтожения
//! @param   dcPtr  Указатель на контекст рисования для уничтожения.
//!                 После уничтожения по указателю записывается NULL.
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
//}------------------------------------------------------------------------------------------------------------------------------
//@ {

bool txDeleteDC (HDC  dc);
bool txDeleteDC (HDC* dcPtr);

//@ }
//{------------------------------------------------------------------------------------------------------------------------------
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
//! @table   @tr SRCCOPY     @td Просто копирует :) - самый распространенный режим\n @endtr
//!          @tbr
//!          @tr BLACKNESS   @td Заполняет холст-приемник черным цветом (холст-источник игнорируется). @endtr
//!          @tr WHITENESS   @td Заполняет холст-приемник белым цветом  (холст-источник игнорируется). @endtr
//!          @tr DSTINVERT   @td Инвертирует цвета на холсте-приемнике  (холст-источник игнорируется). @endtr
//!          @tr PATCOPY     @td Копирует цвет текущей кисти холста-приемника.\n @endtr
//!          @tbr
//!          @tr MERGECOPY   @td Приемник =   приемник & цвет текущей кисти источника. @endtr
//!          @tr MERGEPAINT  @td Приемник = ~ приемник | источник @endtr
//!          @tr NOTSRCCOPY  @td Приемник = ~ источник @endtr
//!          @tr NOTSRCERASE @td Приемник = ~ (приемник | источник) @endtr
//!          @tr PATINVERT   @td Приемник =  кисть приемника ^  приемник @endtr
//!          @tr PATPAINT    @td Приемник = (кисть приемника | ~источник) | приемник @endtr
//!          @tr SRCAND      @td Приемник =  приемник & источник @endtr
//!          @tr SRCERASE    @td Приемник = ~приемник & источник @endtr
//!          @tr SRCINVERT   @td Приемник =  приемник ^ источник @endtr
//!          @tr SRCPAINT    @td Приемник =  приемник | источник @endtr
//!          @endtable
//!
//! @see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(),
//!          @ref TX_BLACK "Цвета", RGB()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          if (!background) MessageBox (txWindow(), "Cannot load background", "Once again :(", 0);
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txBitBlt (HDC dest, int xDest, int yDest, int width, int height,
               HDC src,  int xSrc,  int ySrc,  DWORD rOp = SRCCOPY);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, int xDest, int yDest, int width, int height,
                       HDC src,  int xSrc,  int ySrc,  COLORREF transColor = TX_BLACK);

//{------------------------------------------------------------------------------------------------------------------------------
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
//! @param   alpha   Общая прозрачность изображения, в дополнение к альфа-каналу.\n
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
//!          (в каналах R, G, B) должно быть черным.
//!
//!          Стандартная функция AlphaBlend из Win32 API может масштабировать изображение.
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
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, int xDest, int yDest, int width, int height,
                   HDC src,  int xSrc,  int ySrc,  double alpha = 1.0);
//}

//===============================================================================================================================
//{          Utility functions
//! @name    Вспомогательные функции
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Блокирует обновление изображения окна, во избежание мигания.
//!
//!          Для снятия блокировки используется функция @ref txEnd().
//!
//! @warning Избегайте блокирования на долгое время. Это может привести к дефектам
//!          изображения в окне. Если в программе требуется задержка, то используйте
//!          функцию @ref txSleep(), так как она автоматически обновляет изображение,
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
//}------------------------------------------------------------------------------------------------------------------------------

int txBegin();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

int txEnd();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

bool txSleep (int time);

//{------------------------------------------------------------------------------------------------------------------------------
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
//!          Более полную информацию о блокировке см. в функциях @ref txBegin(), @ref txEnd() и @ref txSleep().
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

inline
int txUpdateWindow (int update = true);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий прямоугольный регион отсечения.
//!
//! @param   x0  X-координата верхнего левого  угла
//! @param   y0  Y-координата верхнего левого  угла
//! @param   x1  X-координата нижнего  правого угла
//! @param   y1  Y-координата нижнего  правого угла
//!
//! @return  Декскриптор установленного региона. Если регион не создан или не установлен - NULL.
//!
//!          Все, что оказывается вне региона отсечения, не рисуется.
//!
//!          Непрямоугольные регионы TXLib не поддерживает, устанавливайте их
//!          сами через стандартные функции работы с регионами из Win32 API.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//! @usage
//! @code
//!          txSelectRegion (100, 100, 300, 400);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

HRGN txSelectRegion (int x0, int y0, int x1, int y1);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Устанавливает текущий объект GDI.
//!
//! @param   obj  Дескриптор объекта GDI
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_BLACK "Цвета", RGB()
//!          txSelectFont(), txSelectRegion()
//! @usage
//! @code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Запрещает или разрешает рисование мигающего курсора в окне.
//!
//! @param   blink  false - запретить мигающий курсор
//!
//! @return  Предыдущее значение блокировки.
//!
//! @see     txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txTextCursor (bool blink = true);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Запускает процесс уничтожения окна TXlib.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning После успешного вызова этой функции, функция main() будет
//!          впоследствии завершена через exit().
//!
//! @see     txCreateWindow()
//! @usage
//! @code
//!          txDestroyWindow();  // Farewell to the world
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txDestroyWindow();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------


// See definition of this function below in this file.

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture();

//}

//===============================================================================================================================
//{          Mouse
//! @name    Работа с мышью
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
POINT txMousePos();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
int txMouseX();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

inline
int txMouseY();

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает состояние Кнопок Мыши!
//!
//! @return  Состояние Кнопок Мыши!
//!
//!          В возвращаемом значении выставленный в единицу 1-й (младший)
//!          бит означает нажатую левую Кнопку Мыши, 2-й - правую, 3-й -
//!          среднюю.\n Например, возвращенное число 5 (двоичное 101) означает
//!          одновременное нажатие средней и левой Кнопок, но не правой Кнопки.
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

inline
int txMouseButtons();

//}

//===============================================================================================================================
//{          Other staff not related to drawing
//! @name    Другие полезные функции, не связанные с рисованием
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Воспроизводит звуковой файл.
//!
//! @param   filename  Имя звукового файла. Если NULL - останавливает звук.
//! @param   mode      Режим воспроизведения
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @title   Режимы воспроизведения: @table
//!          @tr SND_ASYNC       @td Звук проигрывается одновременно с работой программы.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL). @endtr
//!          @tr SND_SYNC        @td Выполнение программы приостанавливается до окончания
//!                                  воспроизведения звука. @endtr
//!          @tr SND_LOOP        @td Зацикливать звук при воспроизведении.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).\n @endtr
//!          @tbr
//!          @tr SND_NODEFAULT   @td Не использовать звук по умолчанию, если нельзя проиграть
//!                                  указанный звуковой файл. @endtr
//!          @tr SND_NOSTOP      @td Если какой-либо звук уже проигрывается, не останавливать
//!                                  его для воспроизведения указанного звука. @endtr
//!          @tr SND_APPLICATION @td Проигрывать звук, используя программу, зарегистрированную
//!                                  для данного типа звуковых файлов. @endtr
//!          @endtable
//!
//! @note    Поддерживаются только файлы в формате WAV. Остальные форматы (MP3 и др.) надо
//!          перекодировать. Переименование со сменой расширения не поможет, как и в случае
//!          с форматом картинок в txLoadImage().
//! @usage
//! @code
//!          txPlaySound ("tada.wav"); // so happy that this always exists
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Оценивает скорость работы компьютера.
//!
//! @return  Скорость работы в условных единицах.
//!
//! @see     txSleep()
//! @usage
//! @code
//!          if (txQueryPerformance() < 1) printf ("Хочется новый компьютер");
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

double txQueryPerformance();

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

#define SIZEARR( arr )    ( sizeof (get_size_of_an_array_with_unknown_or_nonconst_size_ (arr)) )
#define sizearr( arr )    ( sizeof (arr) / sizeof (arr)[0] )

//! @cond INTERNAL
template <typename T, int N> char (&get_size_of_an_array_with_unknown_or_nonconst_size_ (T (&) [N])) [N]; // ;)
//! @endcond

//! @}
//{------------------------------------------------------------------------------------------------------------------------------
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
//! @brief   Генератор случайных чисел
//!
//! @param   range  Правая граница диапазона (@b не включая саму границу).
//!
//! @return  Случайное целое число в диапазоне [0; range).\n
//!
//!          Вы еще помните, что означают разные скобочки в обозначении интервалов? :)
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
//! @brief   Генератор случайных чисел
//!
//! @param   left   Правая граница диапазона (@b включая саму границу).
//! @param   right  Правая граница диапазона (@b включая саму границу).
//!
//! @return  Случайное целое число в диапазоне [left; right].\n
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
//}------------------------------------------------------------------------------------------------------------------------------

#define MAX( a, b )           ( (a) > (b) ? (a) : (b) )

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

#define MIN( a, b )           ( (a) < (b) ? (a) : (b) )

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//}

//===============================================================================================================================
//{          Back-hole (I hope, not an ass-hole:) of the library)
//! @name    Очень служебные функции
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Устанавливает дополнительный обработчик оконных сообщений Windows.
//!
//! @param   handler  Новый дополнительный обработчик событий окна.\n
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
//}------------------------------------------------------------------------------------------------------------------------------

WNDPROC txSetWindowHandler (WNDPROC handler = NULL);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Блокировка холста (контекста рисования).
//!
//! @param   wait  Ожидать конца перерисовки окна вспомогательным потоком
//!
//! @return  Состояние блокировки
//!
//!          Перед вызовом любых функций Win32 GDI необходимо заблокировать
//!          холст функцией txLock() и затем разблокировать с помощью @ref txUnlock().
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
//!          txLock() /@ref txUnlock() - низкоуровневый механизм. Он отличается от более простого
//!          высокоуровневого механизма @ref txBegin() / @ref txEnd() /@ref txUpdateWindow(),
//!          который не приостанавливает поток, а просто отключает операции по обновлению окна.
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage   См. исходный текст функций _txCanvas_OnPaint() и _txConsole_Draw() в TXLib.h.
//! @code
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

inline bool txLock (bool wait = true);

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Разблокировка холста
//!
//! @return  Состояние блокировки (всегда false).
//!
//!          Более подробно см. в @ref txLock().
//!
//! @see     txDC(), txLock(), txGDI()
//! @usage
//! @code
//! @usage   См. исходный текст функций _txCanvas_OnPaint() и _txConsole_Draw() в TXLib.h.
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

inline bool txUnlock();

template <typename T> inline
T txUnlock (T value);

//! @}

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Вызов функции Win32 GDI с автоматической блокировкой и разблокировкой.
//!
//! @param   command  Команда GDI (возможно, возвращающая значение)
//!
//! @return  Значение, возвращаемое вызываемой функцией GDI.
//!          Если система рисования не готова, возвращается значение false.
//!
//! @note    Если система рисования не готова (@ref txDC() возвращает NULL),
//!          то команда GDI не выполняется, а @ref txGDI() возвращает значение false.
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
//}------------------------------------------------------------------------------------------------------------------------------

#define txGDI( command )  txUnlock ( (txLock(), (command)) )

//}

//===============================================================================================================================
//{          Tune-up constants
//! @name    Настроечные константы
//===============================================================================================================================

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Режим отображения консольного окна
//!
//!          Может задаваться перед включением TXLib.h в программу.
//-------------------------------------------------------------------------------------------------------------------------------

#ifndef      _TX_CONSOLE_MODE
    #define  _TX_CONSOLE_MODE             SWP_HIDEWINDOW
    #endif

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Шрифт консоли
//-------------------------------------------------------------------------------------------------------------------------------

const char   _TX_CONSOLE_FONT[]           = "Lucida Console";

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Цвет шрифта консоли
//-------------------------------------------------------------------------------------------------------------------------------

const COLORREF _TX_CONSOLE_COLOR          = TX_LIGHTGRAY;

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал мигания курсора консоли (мс)
//-------------------------------------------------------------------------------------------------------------------------------

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал обновления холста (мс)
//-------------------------------------------------------------------------------------------------------------------------------

const int    _TX_WINDOW_UPDATE_INTERVAL   = 10;

//-------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Таймаут операций ожидания (мс)
//-------------------------------------------------------------------------------------------------------------------------------

const int    _TX_TIMEOUT                  = 1000;

//}

//===============================================================================================================================
//{          Diagnostics and Tools
//! @name    Диагностика и утилиты
//===============================================================================================================================

//! @cond INTERNAL
#define  TX_QUOTE( symbol )   _TX_QUOTE (symbol)
#define _TX_QUOTE( symbol )   #symbol
//! @endcond

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя и версия текущего компилятора
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
//! @brief   Имя режима сборки
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
//! @brief   Макрос, раскрывающийся в имя файла и номер строки файла, где он встретился.
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

#define __TX_FILELINE__       __FILE__ " (" TX_QUOTE (__LINE__) ")"

//! @}
//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя текущей функции
//!
//! @warning Если определение имени функции не поддерживается компилятором, то __TX_FUNCTION__
//!          раскрывается в имя исходного файла и номер строки.
//!
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
//! @brief   Замена стандартного макроса assert(), с выдачей сообщения через MessageBox(),
//!          консоль и OutputDebugString().
//!
//! @param   cond  Условие для проверки
//!
//! @return  Всегда 0
//!
//!          Если условие, проверяемое assert(), истинно, то макрос ничего не делает.\n
//!          Если условие оказывается ложно, то выводится диагностическое сообщение и
//!          программа аварийно завершается.
//!
//! @note    <b>При компиляции в режиме Release (или если определен NDEBUG) assert
//!          превращается в пустой оператор.</b>\n Не надо помещать в assert() действия,
//!          которые важны для работы алгорима.
//!
//! @see     asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE,
//!          @ref "отладочные $-макросы" $
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
//!          bool fcloseOk = (fclose (input) == 0);
//!          assert (fcloseOk);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#undef  assert

#ifndef NDEBUG
    #define assert( cond )    ( !!(cond) || TX_ERROR ("\a" "Логическая ошибка: Неверно, что \"%s\"" _ #cond), 0 )

#else
    #define assert( cond )    ( 0 )

#endif

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит диагностическое сообщение в случае нулевого или ложного результата.
//!
//! @return  Всегда 0
//!
//!          Суффиксная форма макроса assert(), не теряющая в режиме Release
//!          исполнения предиката.
//!
//! @note    <b>Предполагается, что операция в случае неуспеха возвращает 0 или false.</b>\n\n
//!          <b>При компиляции в режиме Release (или если определен NDEBUG) asserted
//!          превращается в пустое место.</b>
//!
//! @see     assert(), __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE,
//!          @ref "отладочные $-макросы" $
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
//}------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG
    #define asserted          || TX_ERROR ("\a" "Обнаружен нулевой или ложный результат")

#else
    #define asserted

#endif

#define TX_NEEDED             asserted  // For compatibility with earlier releases

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит развернутое диагностическое сообщение.
//!
//! @return  всегда false
//!
//! @see     _, assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE,
//!          @ref "отладочные $-макросы" $
//! @usage
//! @code
//!          TX_ERROR ("Не смог прочитать 'Войну и мир'! Ошибка чтения '%s'" _ fileName);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG
    #define TX_ERROR( msg )   ( _tx_Error (__FILE__, __LINE__, 						           \
                                          ((*__TX_FUNCTION__ != '(')? __TX_FUNCTION__ : NULL), \
                                          (DWORD)(-1), -1, -1, msg), 0 )

#else
    #define TX_ERROR(msg)     ( 0 )

#endif

#define TX_THROW              TX_ERROR  // For compatibility with earlier releases

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Макрос, позволяющий передать переменное число параметров в какой-либо другой макрос.
//!
//! @note    <b>Символ подчеркивания просто переопределяется в запятую.</b>
//!
//! @see     TX_ERROR()
//! @usage
//! @code
//!          TX_ERROR ("Слишком умный абзац: роман 'Война и мир', файл '%s', строка %d" _ fileName _ lineNum);
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#define _                     ,

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит имя файла, номер строки и имя функции, где находится вызов TX_PRINT_HERE().
//!
//! @see     assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE,
//!          @ref "отладочные $-макросы" $
//! @usage
//! @code
//!          TX_PRINT_HERE();
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG
    #define TX_PRINT_HERE()   printf ("[" __TX_FILELINE__ " " __TX_FUNCTION__ "]")

#else
    #define TX_PRINT_HERE()   ;

#endif

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Включает/отключает внутреннюю трассировку исполнения кода библиотеки.
//!
//!          Трассировка идет через макрос @ref TX_TRACE, который подставляется перед
//!          каждым оператором (statement). По умолчанию трассировка выключена.
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(),
//!          ее вывод можно перехватить утилитами-логгерами, например,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> или WinTail. Это можно изменить, переопределив макрос @ref TX_TRACE.
//!
//!          _TX_ALLOW_TRACE и @ref TX_TRACE задаются перед включением TXLib.h в программу.
//! @usage
//! @code
//!          #define  _TX_ALLOW_TRACE   // Для просмотра трассы запустить DebugView
//!          #include "TXLib.h"
//! @endcode
//! @hideinitializer
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

#ifdef FOR_DOXYGEN_ONLY
#define _TX_ALLOW_TRACE
#endif

#ifdef _TX_ALLOW_TRACE
    #undef  $
    #define $                 TX_TRACE

#else
    #undef  $
    #define $

#endif

//! @}
//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Трассирует исполнение кода библиотеки через OutputDebugString().
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(),
//!          ее вывод можно перехватить утилитами-логгерами, например,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> или WinTail.
//!
//!          TX_TRACE можно переопределить в свой код, тогда он будет вызываться
//!          перед каждой строкой кода TXLib.
//!
//!          Трассировку нужно предварительно разрешить идет через макрос @ref _TX_ALLOW_TRACE.
//!          По умолчанию она выключена.
//!
//!          TX_TRACE и @ref _TX_ALLOW_TRACE задаются перед включением TXLib.h в программу.
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
//{          Dialogs: class txDialog
//! @name    Работа с диалоговыми окнами. Класс txDialog
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

struct txDialog
    {

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

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

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

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

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   Конструктор.
//! @see     txDialog::txDialog (const txDialog::Layout*)
//!
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    public:
    txDialog();

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   Конструктор.
//!
//! @param   layout  Макет диалогового окна
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    txDialog (const Layout* layout);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   Деструктор.
//}------------------------------------------------------------------------------------------------------------------------------

    virtual ~txDialog() {};

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   Устанавливает текущий макет диалогового окна.
//!
//! @param   layout  Макет диалогового окна
//!
//! @return  Предыдущий макет.
//!
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    const Layout* setLayout (const Layout *layout);

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//!
//! @param   layout   Макет диалогового окна.\n
//!                     Если не указан - используется значение, заданное txDialog::setLayout()
//!                     или конструктором txDialog::txDialog (const txDialog::Layout*).
//! @param   bufsize  Размер буфера для создания шаблона диалога (если не указан - размер по умолчанию)
//!
//! @return  Значение, указанное в функции EndDialog().\n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была
//!          запущена txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    INT_PTR dialogBox (const Layout* layout = NULL, size_t bufsize = 0);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//!
//! @param   resource  Идентификатор диалогового ресурса
//!
//! @return  Значение, указанное в функции EndDialog().\n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была
//!          запущена txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource);

//{------------------------------------------------------------------------------------------------------------------------------
//! @brief   Закрытые конструктор копирования и оператор присваивания.
//}------------------------------------------------------------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//{------------------------------------------------------------------------------------------------------------------------------
//! Настоящая диалоговая функция (не @ref txDialog::dialogProc(), т.к. функция окна
//! Win32 должна быть статической).
//}------------------------------------------------------------------------------------------------------------------------------

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//{------------------------------------------------------------------------------------------------------------------------------
//! Текущий макет диалога.
//}------------------------------------------------------------------------------------------------------------------------------

    private:
    const Layout* layout_;
    };

//}

//===============================================================================================================================
//{          Dialogs: Message Map macros
//! @name    Макросы для построения статической карты сообщений (Message Map)
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Заголовок карты сообщений (Message Map).

//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//}------------------------------------------------------------------------------------------------------------------------------

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Начало карты команд (Command map) в карте сообщений.

//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//! @brief   Завершитель карты сообщений.

//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//{          Dialogs: txDialog example: txInputBox()
//! @name    Пример использования класса диалога: функция txInputBox()
//===============================================================================================================================

//{------------------------------------------------------------------------------------------------------------------------------
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
//}------------------------------------------------------------------------------------------------------------------------------

const char* txInputBox (const char* text = NULL, const char* caption = NULL, const char* input = NULL);

const char* txInputBox (const char* text, const char* caption, const char* input)
    {
    //---------------------------------------------------------------------------------------------------------------------------
    // Если не указаны параметры, использовать более-менее внятные надписи. А что делать?..
    // _tx_GetModuleName() - имя EXE-файла, на случай, если кое-кто поленился задать название диалога.
    //---------------------------------------------------------------------------------------------------------------------------

$   if (!text)    text    = "Введите строку:";
$   if (!caption) caption = txGetModuleFileName (false);
$   if (!input)   input   = "";

    //---------------------------------------------------------------------------------------------------------------------------
    // Идентификаторы элементов диалога. Они требуются в GetDlgItemText().
    // Если диалог строится не вручную, а редактором ресурсов, то они задаются в нем автоматически.
    // У нас же тут - хардкор стайл, к сожалению. Причина в том, что у разных сред программирования
    // разные редакторы ресурсов и системы сборки. Поэтому для независимости от них все будет
    // строиться на этапе выполнения, динамически. Вы еще посмотрите, как это будет реализовано
    // в txDialog::dialogBox() и _tx_DLGTEMPLATE_()... О_о
    //---------------------------------------------------------------------------------------------------------------------------

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    //---------------------------------------------------------------------------------------------------------------------------
    // Задание макета (вида) диалога в виде массива структур.
    // С помощью особого порядка полей в структуре txDialog::Layout и констант из класса
    // txDialog этот массив становится похож на описание ресурса диалога в .rc - файле.
    // См. описание синтаксиса rc-файла в документации по Win32 (MSDN, http://msdn.com).
    //---------------------------------------------------------------------------------------------------------------------------

$   txDialog::Layout layout[] =

    //----------------------+-----------+-------------+-----------------+--------------------------------------------------------
    //     Тип элемента     | Имя       | Идентифика- |   Координаты    | Флаги элементов
    //     диалога          | элемента  | тор, связан-|-----------------| (см. описание элементов диалога в MSDN).
    //                      |           | ный с ним   | X | Y |Шир.|Выс.|
    //----------------------+-----------+-------------+---+---+----+----+--------------------------------------------------------
    //                      |           |             |   |   |    |    |
        {{ txDialog::DIALOG,   caption,   0,             0,  0, 240,  85                                                     },
         { txDialog::STATIC,   text,      ID_TEXT_,     10, 10, 150,  40, SS_LEFT                                            },
         { txDialog::EDIT,     input,     ID_INPUT_,    10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP  },
         { txDialog::BUTTON,   "&OK",     IDOK,        180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP  },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL,    180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP  },
         { txDialog::END                                                                                                     }};

    //---------------------------------------------------------------------------------------------------------------------------
    // Класс диалога для InputBox. Внутренний, т.к. зачем ему быть внешним.
    // Нужен в основном для задания строки ввода (str) и оконной функции диалогового окна,
    // требуемой Win32 (она построена макросами TX_BEGIN_MESSAGE_MAP и другими). Можно не делать
    // внутреннего класса, но тогда оконную функцию придется писать в глобальной области видимости,
    // и str объявлять глобально тоже (или передавать ее адрес через DialogBoxParam и записывать
    // его в класс во время обработки WM_INITDIALOG).
    //---------------------------------------------------------------------------------------------------------------------------

    struct inputDlg : txDialog
        {
        char str [1024];

        //-----------------------------------------------------------------------------------------------------------------------

        inputDlg() :
            str()                               // Обнуление всей строки. Не работает на старых
            {                                   //     компиляторах, поэтому еще раз:
$           memset (str, 0, sizeof (str) - 1);  // Обнуление всей строки
            }

        //-----------------------------------------------------------------------------------------------------------------------

        TX_BEGIN_MESSAGE_MAP()    // Карта сообщений. На самом деле это начало оконной функции.

            TX_COMMAND_MAP        // Здесь обрабатываются WM_COMMAND. На самом деле это switch.

                //---------------------------------------------------------------------------------------------------------------
                // При нажатии кнопки OK копируем строку из поля ввода в нашу переменную str,
                // т.к. после закрытия диалога строка ввода умрет и текст уже из нее получить.
                // Этот макрос на самом деле превращается в case из оператора switch.
                // _wnd - это параметр оконной функции, см. определение макроса TX_BEGIN_MESSAGE_MAP().
                //---------------------------------------------------------------------------------------------------------------

                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP

        //-----------------------------------------------------------------------------------------------------------------------
        // Конец внутреннего класса диалога
        //-----------------------------------------------------------------------------------------------------------------------

        };

    //---------------------------------------------------------------------------------------------------------------------------
    // Убираем дефайны, чтобы потом не мешали.
    // От этого они получаются "локального действия", как будто у них была бы область видимости -
    // функция. На самом деле это сделано вручную через #undef. Чтобы подчеркнуть их локальную
    // природу, у них имена заканчиваются на _. Такие дейфайны потом не перекосячат весь код после
    // того как, фактически, стали уже не нужны.
    //---------------------------------------------------------------------------------------------------------------------------

    #undef ID_TEXT_
    #undef ID_INPUT_

    //---------------------------------------------------------------------------------------------------------------------------
    // Это статический объект, потому что строка в нем должна жить после завершения функции.
    //---------------------------------------------------------------------------------------------------------------------------

$   static inputDlg dlg;

    //---------------------------------------------------------------------------------------------------------------------------
    // Передаем layout и запускаем окно диалога
    //---------------------------------------------------------------------------------------------------------------------------

$   dlg.dialogBox (layout);

    //---------------------------------------------------------------------------------------------------------------------------
    // Возвращаем адрес строки из статического объекта. Так можно делать, потому что статический
    // объект не умрет при выходе из функции и строка в нем, соответственно, тоже. Адрес
    // нестатических переменных передавать синтаксически можно, но ведет к серьезным ошибкам.
    //---------------------------------------------------------------------------------------------------------------------------

$   return dlg.str;
    }

//}

//}

//===============================================================================================================================
//{          TXLib implementation
//! @name    Реализация функций библиотеки
//===============================================================================================================================
//! @cond    INTERNAL

//===============================================================================================================================
//{          [Internal] Function prototypes, macros and constants
//! @name    Прототипы внутренних функций, макросы и константы
//===============================================================================================================================

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
bool         _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd);
bool         _txCanvas_OnCmdABOUT   (HWND wnd, WPARAM cmd);

unsigned CALLBACK _txCanvas_ThreadProc (void* data);
LRESULT  CALLBACK _txCanvas_WndProc    (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

HDC          _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL);
bool         _txBuffer_Delete (HDC* dc);
bool         _txBuffer_Select (HGDIOBJ obj, HDC dc = txDC());

bool         _txConsole_Attach();
bool         _txConsole_OK();
bool         _txConsole_Detach();
bool         _txConsole_Draw (HDC dc);

void*        _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                                     WORD controls, short x, short y, short cx, short cy,
                                     const char caption[], const char font[], WORD fontsize,
                                     HANDLE menu = NULL);
void*        _tx_DLGTEMPLATE_Add    (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                                     short x, short y, short cx, short cy,
                                     WORD id, const char wclass[], const char caption[]);

bool         _tx_Error (const char file[], int line, const char func[],
                        DWORD getlasterror_value, int errno_value, int doserrno_value,
                        const char msg[], ...) _TX_CHECK_FORMAT (7);

//-------------------------------------------------------------------------------------------------------------------------------

// This is a macro for __FILE__ and __LINE__ to work properly.

#define      _txCheck()             ( txOK() || TX_ERROR ("\a" "Окно рисования не создано") )

// This is a macro because cond is not a function but an expression. Lack of lambdas in pre-C++0x

#define      _txWaitFor(cond)       { for (DWORD __t##__LINE__ = GetTickCount() + _TX_TIMEOUT; GetTickCount() < __t##__LINE__; )\
                                        { $ if ((cond) != 0) break; Sleep (_TX_WINDOW_UPDATE_INTERVAL); } }

//-------------------------------------------------------------------------------------------------------------------------------

#ifdef _TX_MULTIPLE_INSTANCE
    #define _TX_NSPACE_NAME         TX_QUOTE (_TX_ANON_NSPACE) "::" "TX"
#else
    #define _TX_NSPACE_NAME                                         "TX"
#endif

//-------------------------------------------------------------------------------------------------------------------------------

const int    _TX_IDM_ABOUT          = 40000;  // Идентификаторы системного меню окна
const int    _TX_IDM_CONSOLE        = 40001;

//}

//===============================================================================================================================
//{          [Internal] DLL functions import
//! @name    Импорт внешних библиотек
//===============================================================================================================================

FARPROC _txImport (const char lib[], const char name[], int required = true);

FARPROC _txImport (const char lib[], const char name[], int required)
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
//! @name    Малая механизация
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

_TX_IMPORT ("Kernel32",   HWND,GetConsoleWindow,       ());

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
//! @name    Глобальные данные
//           Не упакованы в структуру или класс, для того, чтобы это сделали Вы сами :)
//===============================================================================================================================

unsigned         _txMainThreadId        = 0;      // ID потока с main()

HANDLE           _txCanvas_Thread       = NULL;   // Дескриптор потока, владеющего окном холста TXLib
unsigned         _txCanvas_ThreadId     = 0;      // ID этого потока

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

int              _txWindowId            = 0;      // Номер окна TXLib по порядку создания
bool             _txRunning             = false;  // Indicate that main() is still running
bool             _txExit                = false;  // Indicate that exit() is active

POINT            _txMousePos            = {0};
int              _txMouseButtons        =  0;

WNDPROC          _txAltWndProc          = NULL;   // Альтернативная оконная функция. См. @ref txSetWindowHandler().

//}

//===============================================================================================================================
//{          TXLib engine init/check/cleanup
//! @name    Инициализация/проверка/завершение TXLib
//===============================================================================================================================

//-------------------------------------------------------------------------------------------------------------------------------
//{          Start tracing output
//-------------------------------------------------------------------------------------------------------------------------------

#ifndef NDEBUG

int _txInitTrace = (OutputDebugString ("\n"),
                    OutputDebugString ("The Dumb Artist Library - " _TX_VERSION " " _TX_AUTHOR ": "
                                       "\"" __FILE__ "\" [" _TX_NSPACE_NAME "], "
                                       "compiled " __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode\n"),
                    OutputDebugString ("\n"), 1);
#endif

//}

//-------------------------------------------------------------------------------------------------------------------------------

int txCreateWindow (int sizeX, int sizeY, bool centered /*= true*/)
    {
$   if (txOK()) return 0;

$   assert (!_txRunning);
$   _txRunning  = false;
$   _txExit     = false;
$   _txWindowId = TX_COUNTER();

$   atexit (_txOnExit);

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   assert (!_txMainThreadId);
$   _txMainThreadId = GetCurrentThreadId();
$   assert ( _txMainThreadId);

$   if (_txWindowId == 1)
        { $ _txConsole_Attach() asserted; }

$   SIZE size = { sizeX, sizeY };
$   if (centered) { size.cx *= -1; size.cy *= -1; }

    // In Thread, where REAL creation lies...

$   assert (!_txCanvas_Thread); assert (!_txCanvas_ThreadId);
$   _txCanvas_Thread = (HANDLE) _beginthreadex (NULL, 0, _txCanvas_ThreadProc, &size,
                                                CREATE_SUSPENDED, &_txCanvas_ThreadId);

$   _txCanvas_Thread || _txCanvas_ThreadId || TX_ERROR ("\a" "Cannot start canvas thread");
$   if (!_txCanvas_Thread) return 0;

$   SetThreadPriority (GetCurrentThread(), THREAD_PRIORITY_ABOVE_NORMAL) asserted;
$   SetThreadPriority (_txCanvas_Thread,   THREAD_PRIORITY_BELOW_NORMAL) asserted;
$   ResumeThread      (_txCanvas_Thread)   asserted;

$   _txWaitFor (_txCanvas_OK());
$   _txCanvas_OK() || TX_ERROR ("\a" "Cannot create canvas window");

$   errno = _doserrno = 0;
$   SetLastError (0);

$   return _txWindowId;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txSetDefaults()
    {
$   _txCheck();

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
                                  FW_REGULAR, FALSE, FALSE, FALSE,
                                  DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, DEFAULT_PITCH, _TX_CONSOLE_FONT),
                                  txDC()) asserted;

$   (Win32::SetTextColor (txDC(), TX_WHITE) != CLR_INVALID) asserted;
$    Win32::SetBkMode    (txDC(), TRANSPARENT)              asserted;

$    Win32::SetROP2      (txDC(), R2_COPYPEN)               asserted;

//}

//{  Set defaults for console  layer

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

                                                    : GetStockObject (SYSTEM_FIXED_FONT),
                      _txCanvas_BackBuf[1]) asserted;
//}

$   txUnlock();
$   txUpdateWindow (true);

    return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool txOK()
    {
$   bool ok = _txCanvas_OK() &&
              _txWindowId;

    if (_txWindowId == 1) ok &= _txConsole_OK();

    return ok;
    }

//-------------------------------------------------------------------------------------------------------------------------------

void _txOnExit()
    {
$   _txRunning = false;
$   if (_txWindowId != 1) _txExit = true;

$   char title [1024] = "";
$   GetWindowText (txWindow(), title, sizeof (title) - 1);
$   strncat_s (title, " [ЗАВЕРШЕНО]", sizeof (title) - 1);
$   SetWindowTextA (txWindow(), title);

$   if (GetCurrentThreadId() != _txCanvas_ThreadId)
        { $ (WaitForSingleObject (_txCanvas_Thread, INFINITE) == WAIT_OBJECT_0) asserted; }

$   if (_txCanvas_Thread)
        { $ CloseHandle (_txCanvas_Thread) asserted; _txCanvas_Thread = NULL; }

$   if (_txWindowId == 1)
        { $ _txConsole_Detach(); }

$   DeleteCriticalSection (&_txCanvas_LockBackBuf);

#ifndef NDEBUG
    OutputDebugString ("\n");
    OutputDebugString (_TX_VERSION ": \"" __FILE__ "\" [" _TX_NSPACE_NAME "] -- FINISHED\n");
    OutputDebugString ("\n");
#endif
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool txDestroyWindow()
    {
    return SendNotifyMessage (txWindow(), WM_DESTROY, 0, 0) != 0;
    }

//}

//===============================================================================================================================
//{          [Internal] Main window functions      (_txCanvas...)
//! @name    Функции основного окна                (_txCanvas...)
//===============================================================================================================================

unsigned CALLBACK _txCanvas_ThreadProc (void* data)
    {
$   assert (data);
$   if (!data) return WM_SIZE;

$   _txCanvas_Window = _txCanvas_CreateWindow (*(SIZE*) data);
$   _txCanvas_Window || TX_ERROR ("\a" "Cannot create canvas: _txCanvas_CreateWindow() failed");

$   _txRunning = true;

#ifndef NDEBUG
    OutputDebugString (_TX_VERSION ": \"" __FILE__ "\" [" _TX_NSPACE_NAME "] -- STARTED\n");
#endif

$   MSG msg = {0};
$   while (GetMessage (&msg, NULL, 0, 0))
        {
$       TranslateMessage (&msg);
$       DispatchMessage  (&msg);
$       Sleep (0);

        // main() finished, but we don't need to pause, so destroying ourselves.
        // See txDisableAutoPause().

$       if (!_txRunning && _txExit && _txCanvas_Window)
            { $ DestroyWindow (_txCanvas_Window) asserted; }
        }

    // The window #1 is destroyed but main() is still running.
    // No chances for good termination, so use exit().

$   if (_txRunning && _txWindowId == 1)
        { $ exit (msg.wParam); }

$   _txCanvas_ThreadId = 0;
$   return msg.wParam;
    }

//-------------------------------------------------------------------------------------------------------------------------------

HWND _txCanvas_CreateWindow (SIZE clientSize)
    {
$   const char className[] = ">>>>> " _TX_VERSION ": " __FILE__ " [" _TX_NSPACE_NAME "] WndClass <<<<<";
$   WNDCLASSEX wc    = {0};
$   wc.cbSize        = sizeof (wc);
$   wc.style         = CS_HREDRAW | CS_VREDRAW;
$   wc.lpfnWndProc   = _txCanvas_WndProc;
$   wc.hInstance     = NULL;
$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) GetStockObject (HOLLOW_BRUSH);
$   wc.lpszClassName = className;
$   RegisterClassEx (&wc) || TX_ERROR ("\a" "RegisterClass (\"%s\") failed"_ className);

$   int centered = false;
$   if (clientSize.cx < 0 && clientSize.cy < 0) { clientSize.cx *= -1; clientSize.cy *= -1; centered = true; }

$   SIZE scr     = { GetSystemMetrics (SM_CXSCREEN),     GetSystemMetrics (SM_CYSCREEN)     };
$   SIZE frame   = { GetSystemMetrics (SM_CXFIXEDFRAME), GetSystemMetrics (SM_CYFIXEDFRAME) };
$   SIZE caption = { 0, GetSystemMetrics (SM_CYCAPTION) };
$   SIZE size    = { clientSize.cx + 2*frame.cx, clientSize.cy + 2*frame.cy + caption.cy };
$   POINT center = { scr.cx / 2, scr.cy / 2 };

$   if (!centered)
        {
$       RECT r = { scr.cx, scr.cy };
$       GetWindowRect (Win32::GetConsoleWindow(), &r);

$       center.x = (r.right + r.left) / 2;
$       center.y = (r.bottom + r.top) / 2;
        }

$   assert (!_txCanvas_Window);

$   _txCanvas_Window = CreateWindowEx (0, className, txGetModuleFileName (false),
                       WS_POPUP | WS_BORDER | WS_CAPTION | ((_txWindowId == 1)? WS_SYSMENU : 0),
                       center.x - size.cx/2, center.y - size.cy/2, size.cx, size.cy,
                       NULL, NULL, NULL, NULL);

$   if (!_txCanvas_Window) return TX_ERROR ("\a" "Cannot create canvas: CreateWindowEx (\"%s\") failed"_ className), (HWND)NULL;

$   ShowWindow          (_txCanvas_Window, SW_SHOW);
$   SetForegroundWindow (_txCanvas_Window) asserted;
$   UpdateWindow        (_txCanvas_Window) asserted;

$   if (_txConsole_OK())
        { $ SetWindowPos (Win32::GetConsoleWindow(), HWND_NOTOPMOST,
                          center.x - size.cx*2/5, center.y - size.cy*2/5, 0, 0,
                          SWP_NOSIZE | SWP_NOACTIVATE | _TX_CONSOLE_MODE) asserted; }

$   HMENU menu = GetSystemMenu (_txCanvas_Window, false);
$   if (!menu) return _txCanvas_Window;

$   AppendMenu (menu, MF_SEPARATOR, 0, NULL)                      asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_CONSOLE, "Show Console") asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_ABOUT,   "About...")     asserted;

$   CheckMenuItem (menu, _TX_IDM_CONSOLE,
                   _txConsole_OK()? (IsWindowVisible (Win32::GetConsoleWindow())? MF_CHECKED : 0) : MF_DISABLED);

$   return _txCanvas_Window;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
bool _txCanvas_OK()
    {
$   return _txCanvas_Thread     &&
           _txCanvas_Window     &&
           _txCanvas_BackBuf[0] &&
           _txCanvas_BackBuf[1];
    }

//-------------------------------------------------------------------------------------------------------------------------------

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

//}

//===============================================================================================================================
//{          [Internal] Main window event handlers (_txCanvas_On...)
//! @name    События основного окна                (_txCanvas_On...)
//===============================================================================================================================

bool _txCanvas_OnCREATE (HWND wnd)
    {
$   assert (wnd); assert (!_txCanvas_Window);

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); _txCanvas_BackBuf[0] asserted;
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); _txCanvas_BackBuf[1] asserted;

$   SetTimer (wnd, _txCanvas_RefreshTimer, _TX_WINDOW_UPDATE_INTERVAL, NULL) asserted;

$   _txCanvas_Window = wnd;

$   txSetDefaults();

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnDESTROY (HWND wnd)
    {
    assert (wnd);

    // Инициируем остановку цикла сообщений

$   PostQuitMessage (_txRunning? WM_DESTROY : EXIT_SUCCESS);

$   if (!_txCanvas_Window) return false;

    // Indicate that we are about to terminate

$   _txExit = true;
$   SetThreadPriority (GetCurrentThread(), THREAD_PRIORITY_NORMAL) asserted; /* !!! ignore? */ 
$   SetThreadPriority (_txMainThread,      THREAD_PRIORITY_NORMAL) asserted; /* !!! ignore? */ 

    // Lock GDI resources forever, will not txUnlock() at return.

$   bool locked = false;
$   _txWaitFor (locked = txLock (false));

$   if (!locked) TX_ERROR ("Cannot lock GDI to free resources");

    // Освобождаем ресурсы, связанные с окном

$   if (_txCanvas_BackBuf[0]) _txBuffer_Delete (&_txCanvas_BackBuf[0])  asserted;
$   if (_txCanvas_BackBuf[1]) _txBuffer_Delete (&_txCanvas_BackBuf[1])  asserted;

$   if (_txCanvas_RefreshTimer) KillTimer (wnd, _txCanvas_RefreshTimer) asserted;

    // Indicate that we are destroyed

$   _txCanvas_Window = NULL;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCLOSE (HWND wnd)
    {
$   if (!wnd || !_txCanvas_OK()) return false;

$   if (_txRunning &&
        MessageBox (wnd, "Функция main() не завершена. Программа все еще работает. Прервать?    ",
                    txGetModuleFileName (false), MB_OKCANCEL | MB_ICONSTOP) != IDOK) return false;
$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

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
$   if (_txCanvas_OK()) return false;

$   _txMousePos.x   = LOWORD (coords);
$   _txMousePos.y   = HIWORD (coords);
$   _txMouseButtons = (int) buttons;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnTIMER (HWND wnd, WPARAM)
    {
$   if (!wnd)                      return false;
$   if (_txCanvas_RefreshLock > 0) return false;

$   InvalidateRect (wnd, NULL, false) asserted;
$   UpdateWindow   (wnd)              asserted;

$   return true;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd)
    {
$   if (!wnd)             return false;
$   if (!_txConsole_OK()) return false;

$   bool visible = IsWindowVisible (Win32::GetConsoleWindow()) != 0;

$   ShowWindow (Win32::GetConsoleWindow(), visible? SW_HIDE : SW_SHOW);

$   visible = IsWindowVisible (Win32::GetConsoleWindow()) != 0;
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
        #define __DESCRIPTION  "(Мне лень задать описание)." " \t\t" "#define __DESCRIPTION to override project role."
        #endif

        #ifndef __AUTHOR
        #define __AUTHOR       "(Непонятно кто)."            " \t\t" "#define __AUTHOR to override this name."
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

$   char text[1024] = "";
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
                 _TX_AUTHOR EOL_
                 "See license and more on: http://ded32.net.ru" EOL_ "\n"

                 "TXLib file:" "\t" __FILE__ ", namespace " _TX_NSPACE_NAME EOL_
                 "Compiler:"   "\t" __TX_COMPILER__ EOL_
                 "Compiled:"   "\t" __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode" EOL_ "\n"

                 "Run file:"   "\t" "%s" EOL_
                 "From dir:"   "\t" "%s" EOL_
                 "Started:"    "\t" "%.6s %.4s %.8s",

                 txGetModuleFileName(), _getcwd (cwd, sizeof (cwd) - 1),
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
//! @name    Функции консольного окна              (_txConsole...)
//===============================================================================================================================

bool _txConsole_Attach()
    {
#if (_TX_CONSOLE_MODE != SWP_HIDEWINDOW)
$   if (!GetConsoleWindow())
#endif
        {
$       FreeConsole();
$       AllocConsole();

$       HANDLE con = GetStdHandle (STD_OUTPUT_HANDLE); assert (con);
$       COORD size = { 80, 25 };
$       if (con) SetConsoleScreenBufferSize (con, size);
        }

$   _txConsole_InitSTDIO() asserted;

$   return Win32::GetConsoleWindow() != NULL;
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
$   return Win32::GetConsoleWindow() != NULL;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txConsole_Detach()
    {
    return FreeConsole() != 0;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _txConsole_Draw (HDC dc)
    {
$   assert (_txConsole_OK()); assert (_txCanvas_OK());

$   if (!txLock (false)) return false;

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   BOOL ok = GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);
    if (!ok) { $ txUnlock(); return false; }

$   SIZE fontSz = {0};
$   txGDI (Win32::GetTextExtentPoint32 (dc, "W", 1, &fontSz)) asserted;

$   Win32::SetTextColor (dc, _TX_CONSOLE_COLOR);
$   Win32::SetBkMode    (dc, TRANSPARENT) asserted;

$   int sizeX = con.srWindow.Right - con.srWindow.Left + 1;
$   for (SHORT y = con.srWindow.Top; y <= con.srWindow.Bottom; y++)
        {
$       static TCHAR buf [1024 + 1] = ""; // [con.dwSize.X + 1]
$       COORD coord = { 0, y };
$       DWORD read  =   0;

$       if (!ReadConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
                                         buf, sizeof (buf), coord, &read)) continue;

$       Win32::TextOut (dc, 0, y*fontSz.cy, buf + con.srWindow.Left, sizeX) asserted;
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

//}

//===============================================================================================================================
//{          [Internal] Memory DC functions        (_txBuffer...)
//! @name    Функции "виртуального холста" (графического буфера, _txBuffer...)
//===============================================================================================================================

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bitmap)
    {
$   txLock();

$   HDC wndDC = GetDC (wnd); assert (wndDC); if (!wndDC) return NULL;

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
//! @name    Диагностика
//===============================================================================================================================

const char* txGetModuleFileName (bool fileNameOnly /*= true*/)
    {
$   static char name[256] = "";

$   GetModuleFileName (NULL, name, sizeof (name) - 1) asserted;
$   if (fileNameOnly) return name;

$   strncat_s (name, " - TXLib", sizeof (name));

    #ifdef _TX_MULTIPLE_INSTANCE
$   strncat_s (name, " [" _TX_NSPACE_NAME "]", sizeof (name));
    #endif

$   const char* title = strrchr (name, '\\'); title = title? title+1 : name;

$   return title;
    }

//-------------------------------------------------------------------------------------------------------------------------------

bool _tx_Error (const char file[], int line, const char func[],
               DWORD winerr, int crterr, int doserr,
               const char msg[], ...)
    {
    const size_t MAXSTR = 1024;
    static int nCalls = 0;

    if (winerr == (DWORD) -1) winerr = GetLastError();
    if (crterr ==         -1) crterr = errno;
    if (doserr ==         -1) doserr = _doserrno;
    nCalls++;

    unsigned threadId = GetCurrentThreadId();

    if (!_txRunning) _txConsole_InitSTDIO();

    bool fatal = (msg && *msg == '\a')? (msg++, true) : false;

    va_list arg; va_start (arg, msg);

    #ifdef  _TX_USE_SECURE_CRT
        #define SZARG_(n)  sizeof (str[0]) - (n) - (s-str[0]), _TRUNCATE

    #else
        #define SZARG_(n)  sizeof (str[0]) - (n) - (s-str[0])

    #endif

    char str[2][MAXSTR] = {}, *s = str[0];

                s +=  _snprintf_s  (s, SZARG_ (1), "TX_ERROR() сообщает:" "\v\v");

    if (file)   s +=  _snprintf_s  (s, SZARG_ (1), "Файл: %s [%s], " , file, _TX_NSPACE_NAME);
    if (line)   s +=  _snprintf_s  (s, SZARG_ (1), "Строка: %d    \v", line);
    if (func)   s +=  _snprintf_s  (s, SZARG_ (1), "Функция: %s   \v", func);

                s +=  _snprintf_s  (s, SZARG_ (1), "\v");

    if (msg)    s +=  _snprintf_s  (s, SZARG_ (1), "Сообщение: "),
                s += _vsnprintf_s  (s, SZARG_ (1), msg, arg),
                s +=  _snprintf_s  (s, SZARG_ (1), "    \v\v");

                s +=  _snprintf_s  (s, SZARG_ (1), "#%d: Thread: 0x%08X%s", nCalls, threadId,
                                                    threadId == _txMainThreadId?    " (Main thread)"   :
                                                    threadId == _txCanvas_ThreadId? " (Canvas thread)" : "");

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

//}

//===============================================================================================================================
//{          TXLib API implementation
//! @name    Реализация TXLib API
//===============================================================================================================================

inline
const char* txVersion()
    {
$   return _TX_VERSION;
    }

//-------------------------------------------------------------------------------------------------------------------------------

inline
unsigned txVersionNumber()
    {
$   return _TX;
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
$   return _txCanvas_Window;
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

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_PEN))); assert (obj);

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

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); assert (obj);

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
$   HDC dc = _txBuffer_Create (txWindow(), &size, bitmap); assert (dc);

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
                "Это запланированная ошибка. Такое бывает. Вы хотели вызвать:" "\n\n"
                "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()" "\n\n"
                "Хоть вы долго [копировали]набирали это имя, на самом деле эта функция не работает." "\n"
                "Но для нее есть работающий синоним. См. определение этой функции в исходных текстах библиотеки." "\n\n",
                "Не получилось", MB_ICONSTOP);

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
//! @name    Реализация методов класса txDialog
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
$   if (!layout)  return TX_ERROR ("Не установлен динамический шаблон диалога    ");

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_ERROR ("GlobalAlloc(): Нет памяти для шаблона диалога    ");

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

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_ERROR ("Не найден ресурс диалога %d   " _ resourceID);

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
//! @name    Функции низкоуровневой работы с диалоговыми окнами
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

// namespace TX, namespace _TX_ANON_NSPACE

/*! @cond INTERNAL @cond OFF */ } /*! @endcond */ } /*! @endcond */

//-------------------------------------------------------------------------------------------------------------------------------
//{          Easy using of TX:: and some of std::
//-------------------------------------------------------------------------------------------------------------------------------

#ifndef _TX_MULTIPLE_INSTANCE
using namespace TX;                    // Allow easy usage of TXLib functions
using namespace TX::Win32;             // Simulate linkage with Win32 libs
#endif

using std::cin;                        // Predefined usings to avoid "using namespace std"
using std::cout;

//}

//-------------------------------------------------------------------------------------------------------------------------------
//{          Cleaning up the utility macros
//-------------------------------------------------------------------------------------------------------------------------------

#undef       $
#undef       _txCheck
#undef       _txWaitFor

//}

//-------------------------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    Адаптация к компиляторам и платформам
//-------------------------------------------------------------------------------------------------------------------------------
//! @cond    INTERNAL

#if defined (__GNUC__) && (__GNUC__ >= 4)

//!!!    #pragma GCC diagnostic warning "-Wstrict-aliasing"

    // Still block this warning to avoid reporting about "= {}" initialization.

    #if 0
    #pragma GCC diagnostic warning "-Wmissing-field-initializers"
    #endif

    // These warnings really occur at end of compilation, so do not restore them.

    #if 0
//!!!    #pragma GCC diagnostic warning "-Wunreachable-code"
//!!!    #pragma GCC diagnostic warning "-Wunused-value"
//!!!    #pragma GCC diagnostic warning "-Wunused-function"
    #pragma GCC diagnostic warning "-Wunused-label"
    #endif

#endif

//-------------------------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

    #pragma warning (default: 4127)             // conditional expression is constant
//!!!    #pragma warning (default: 4245)             // conversion from... to..., signed/unsigned mismatch
    #pragma warning (default: 4351)             // new behavior: elements of array ... will be default initialized

//!!!    #pragma warning (default: 4018)             // '<': signed/unsigned mismatch
//!!!    #pragma warning (default: 4100)             // unreferenced formal parameter
//!!!    #pragma warning (default: 4511)             // copy constructor could not be generated
//!!!    #pragma warning (default: 4512)             // assignment operator could not be generated
    #pragma warning (default: 4663)             // C++ language change: to explicitly specialize class template '...'
//!!!    #pragma warning (default: 6031)             // return value ignored: '...'

    // This warning really occur at end of compilation, so do not restore it.

    #if 0
//!!!    #pragma warning (default: 4710)             // function '...' not inlined
    #endif

#endif

//}

//-------------------------------------------------------------------------------------------------------------------------------
//{          [Experimental] Debugging macros
//! @name    Экспериментальные отладочные макросы
//-------------------------------------------------------------------------------------------------------------------------------

//{------------------------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Отладочная печать переменной во время вычисления выражения или участка кода
//!          во время его выполнения
//!
//! @warning Эти макросы могут измениться в будущих версиях.
//!
//! @title   Назначение: @table
//!          @tr <tt> $ (x) </tt>      @td Печать имени и значения переменной @c x внутри выражения.
//!          @tr <tt> $_(x) </tt>      @td Печать только  значения переменной @c x внутри выражения.
//!          @tbr
//!          @tr <tt> $$ (expr)  </tt> @td Печать выражения, его вычисление, печать и возврат значения.\n
//!                                        Если выражение содержит оператор "запятая", не взятый
//!                                        в скобки, необходимо окружать expr еще одной парой скобок.
//!          @tr <tt> $$_(expr)  </tt> @td То же, что и <tt>$$(expr),</tt> но вторая печать идет без новой строки.
//!          @tbr
//!          @tr <tt> $$$ (expr) </tt> @td То же, что и <tt>$$(expr),</tt> но для операторов или блоков кода
//!                                        (без возврата значения).
//!          @tr <tt> $$$_(expr)</tt>  @td То же, что и <tt>$$$(expr),</tt> но вторая печать идет без новой строки.
//!          @tbr
//!          @tr <tt> $$$$ </tt>       @td Печать местоположения в коде (то же, что и TX_PRINT_HERE).
//!          @tr <tt> $n   </tt>       @td Перевод строки (печать @c '\\n').
//!          @endtable
//!
//! @see     assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR, TX_PRINT_HERE
//! @usage
//! @code
//!          int x = 5;
//!          int y = $(x) + 1;
//!          $$( x = $(y) + 2 );
//!
//!          double a = $$( pow (x, y) );
//!
//!          double b = $$(( $(x) = x*x, y = y*y, sqrt ($(x+y)) ));
//!
//!          $((  txCreateWindow (800, 600) ));
//!
//!          $$c( if ($(a) > $(b)) return 5; )
//! @endcode
//}------------------------------------------------------------------------------------------------------------------------------
//! @{

//! @hideinitializer
#define $$$$        TX_PRINT_HERE()

//! @hideinitializer
#define $_(var)    ( _txDump (var) )

//! @hideinitializer
#define $(var)     ( _txDump ((var),  "[" #var " = ", "]") )

//! @hideinitializer
#define $$(cmd)    (  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n",  \
                     _txDump ((cmd),"\n[" __TX_FILELINE__ ": " #cmd ": ", ", DONE]\n") )
//! @hideinitializer
#define $$_(cmd)   (  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n",  \
                     _txDump ((cmd),  "[" __TX_FILELINE__ ": " #cmd ": ", ", DONE]\n") )
//! @hideinitializer
#define $$$(cmd)   {  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n";  \
                     _txSuffixDump ("\n[" __TX_FILELINE__ ": " #cmd ": DONE]\n"); { cmd; } }
//! @hideinitializer
#define $$$_(cmd)  {  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n";  \
                     _txSuffixDump (  "[" __TX_FILELINE__ ": " #cmd ": DONE]\n"); { cmd; } }
//! @hideinitializer
#define $n         (  std::cout << "\n" )

//-------------------------------------------------------------------------------------------------------------------------------

#ifndef __TX_DEBUG_MACROS
#define __TX_DEBUG_MACROS

template <typename T> inline
const T& _txDump (const T& value, const char* prefix = "", const char* suffix = "")
    {
    if (prefix) std::cout << prefix << value << suffix;
    return value;
    }

struct _txSuffixDump
    {
    const char* suffix_;

    inline  _txSuffixDump (const char* suffix = "") : suffix_ (suffix)     {}
    inline ~_txSuffixDump()                         { std::cout << suffix_; }

    _txSuffixDump (const _txSuffixDump&);
    _txSuffixDump& operator = (const _txSuffixDump&);
    };

#endif

//! @}
//}

//-------------------------------------------------------------------------------------------------------------------------------

//! @endcond
//}

#endif // __TXLIB_H

//===============================================================================================================================
// EOF
//===============================================================================================================================

