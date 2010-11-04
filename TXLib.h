
TODO

int main()
{
    http://users.livejournal.com/sizeof/
    return 0;
}

//=============================================================================
//!
//! @file       TXLib.h
//! @brief      Главный файл
//!
//! @mainpage
//!
//! @brief      Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @version    [Version 0.01 alpha, build 72]
//! @author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky <ded@concord.ru>, http://ded32.net.ru)
//! @date       2010
//!
//! @par        Протестировано
//!           - Компиляторы
//!             - Dev-CPP 4.9.9.2   + MinGW GCC 3.4.2
//!             - CodeBlocks 1.0rc2 + MinGW GCC 3.4.4
//!             - CodeBlocks 8.02   + MinGW GCC 3.4.5
//!             - CodeBlocks 10.05  + MinGW GCC 4.4.1
//!             - Microsoft Visual Studio  6.0
//!             - Microsoft Visual Studio  7.1 (2003)
//!             - Microsoft Visual Studio  8.0 (2005)
//!             - Microsoft Visual Studio  9.0 (2008)
//!             - Microsoft Visual Studio 10.0 (2010)
//!           - Операционные системы
//!             - Windows 2000 SP4 ru/en
//!             - Windows XP SP2/SP3 ru/en
//!             - Windows 2003 SP1 R2
//!             - Windows Vista
//!             - Windows 7
//!
//! @warning
//!           - <b>Это альфа-версия.
//!             Для использования требуется согласование с автором библиотеки.</b>\n\n
//!           - <b>При компиляции в Visual Studio может требоваться во время
//!             выполнения: файл msvcrt.dll</b>\n\n
//!           - Если кодовая страница для консоли установлена неверно, русский текст
//!             может отображаться некорректно. Это проблема исключительно настройки
//!             локального компьютера. Для исправления можно с помощью редактора
//!             реестра в ветке "LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage"
//!             изменить значение ключа "1252" на "c_1251.nls", либо запустить файл
//!             "Wizard\CodePage.reg". После этих изменений потребуется перезагрузка.
//!             (<b>Важно:</b> Если Вы не до конца поняли эти советы, не следуйте им,
//!             и выводите русский текст на экран только с помощью функции @ref txTextOut).
//!
//! @par        История изменений
//! - Build 72
//!          -# Соответствие стандарту C++0x и GCC 4.5 в режиме компиляции -Wall -Wextra.
//! - Build 71
//!          -# Соответствие стандартам MS SAL и режиму компиляции /analyze в MSVS 2005, 2008.
//!          -# Восстановлен механизм обновления по таймеру.
//!          -# Русский язык в консоли в _txThrow().
//! - Build 70
//!          -# Исправление ошибок _txCanvas_OnPaint (NULL DC).
//!          -# Упрощен механизм генерации сообщений для обновления экрана.
//!          -# Добавлена трассировка (@ref TX_TRACE).
//! - Build 69
//!          -# Добавлена работа с диалоговыми окнами (still experimental).
//! - Build 66
//!          -# Исправлена работа при использовании отладчиков на платформах Win2000, WinXP.
//!          -# Документированы отладочные функции и макросы.
//! - Build 65
//!          -# Добавлены Мастера проектов для VS6, VS2003-2008, CodeBlocks, DevCPP.
//!          -# Добавлена интеграция с системой помощи для для VS2003-2008.
//! - Build 64
//!          -# Добавлена cовместимость с Visual Studio 2005.\n
//!             ВНИМАНИЕ!\n
//!             -# Принудительно отключается режим UNICODE (кроме редактора ресурсов
//!                Visual Studio). Для явной работы с UNICODE-функциями используйте суффикс W.\n
//!             -# Принудительно включается  режим _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES.\n
//!          -# Изменен размер шрифта консоли и шрифта, выбранного по умолчанию.
//! - Build 50
//!          -# Добавлены txTransparentBlt(), txAlphaBlend() - Win98 и старше.
//!          -# ВНИМАНИЕ! Функции txSetBkColor(), txBkColor(), txGetBkColor()
//!             теперь называются txSetFillColor(), txFillColor(), txGetFillColor()
//!             (совместимость со старыми версиями - в Graphics.h).
//! - Build 45
//!          -# Добавлена txPlaySound().
//! - Build 44
//!          -# Исправлен баг в txMouseButtons().
//!
//-----------------------------------------------------------------------------
//! @defgroup Drawing   Рисование
//! @defgroup Mouse     Поддержка мыши
//! @defgroup Dialogs   Диалоговые окна
//! @defgroup Misc      Разное
//! @defgroup Service   Служебное
//! @defgroup Technical Технические детали
//=============================================================================

#ifndef __TXLIB_H
#define __TXLIB_H

//-----------------------------------------------------------------------------
//
// Адаптация к компиляторам и платформам
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
//! @name    Цвета
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Названия предопределенных цветов.
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
    TX_TRANSPARENT   = 0xFFFFFFFF,            //!< Прозрачный цвет. Если его выбрать, <i>ничего не рисуется.</i>
    TX_NULL          = TX_NULL,               //!< Прозрачный цвет. Если его выбрать, <i>ничего не рисуется.</i>

//  Цветовые каналы (компоненты) - см. @ref txExtractColor(), @ref txRGB2HSL(), @ref txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< Цветовой тон цвета в модели HSL
    TX_SATURATION   = 0x05000000,             //!< Насыщенность цвета в модели HSL
    TX_LIGHTNESS    = 0x06000000;             //!< Светлота цвета в модели HSL

//=============================================================================
//
//! @name    Настроечные константы
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Не скрывать автоматически консольное окно
//!
//!          Задается перед включением TXLib.h в программу.
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define  _TX_NO_HIDE_CONSOLE
#endif

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Шрифт консоли
//-----------------------------------------------------------------------------

const char   _TX_CONSOLE_FONT[]           = "Lucida Console";

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Цвет шрифта консоли
//-----------------------------------------------------------------------------

const COLORREF _TX_CONSOLE_COLOR          = TX_LIGHTGRAY;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал мигания курсора консоли (мс)
//-----------------------------------------------------------------------------

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал обновления холста (мс)
//-----------------------------------------------------------------------------

const int    _TX_WINDOW_UPDATE_INTERVAL   = 10;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Таймаут операций ожидания (мс)
//-----------------------------------------------------------------------------

const int    _TX_TIMEOUT                  = 1000;

//-----------------------------------------------------------------------------
//  @ingroup Internal
//  @brief   Идентификаторы дополнительных пунктов системного меню окна TXLib
//-----------------------------------------------------------------------------

const int    _TX_IDM_ABOUT                = 40000;
const int    _TX_IDM_CONSOLE              = 40001;

//=============================================================================
//
//! @name    Диагностика и утилиты
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Текущая версия библиотеки.
//!          Эта константа автоматически обновляется при обновлении версии.
//! @see     txVersion()
//-----------------------------------------------------------------------------

#define      _TX_VERSION                  "[Version 0.01 alpha, build 72]"

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Макрос, раскрывающийся в имя файла и номер строки файла, где он встретился.
//! @hideinitializer
//-----------------------------------------------------------------------------

#define __TX_FILELINE__                      __TX_FILELINE__1 (__FILE__, __LINE__)

//! @cond NOT_FOR_DOXYGEN
#define __TX_FILELINE__1(__file__, __line__) __TX_FILELINE__2 (__file__, __line__)
#define __TX_FILELINE__2(__file__, __line__) __file__ " (" #__line__ ")"
//! @endcond

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Строка, соответствующая имени текущей функции, или имя исходного файла и
//!          номер строки, если определение имени функции не поддерживается компилятором.
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
//! @brief   Замена стандартного макроса assert(), с выдачей сообщения через MessageBox(),
//!          консоль и OutputDebugString().
//!
//!          Если условие, проверяемое assert(), истинно, то макрос ничего не делает.\n
//!          Если условие оказывается ложно, то выводится диагностическое сообщение и
//!          программа аварийно завершается.
//!
//! @param   cond Условие для проверки
//! @return  1, если assert() не сработал, и 0, если он сработал (но в этом случае
//!          фактически ничего не вернется, т.к. программа будет прервана).
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
//! @brief   Макрос, позволяющий передать переменное число параметров в какой-либо другой макрос.
//! @note    <b>Символ подчеркивания просто переопределяется в запятую.</b>
//! @see     TX_THROW()
//! @usage
//! @code
//!          TX_THROW ("Ошибка чтения романа 'Война и мир', строка %d файла '%s'" _ lineNum _ fileName);
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#define _                ,

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит развернутое пользовательское диагностическое сообщение.
//! @return  всегда false
//! @see     TX_NEEDED(), _
//! @usage
//! @code
//!          TX_THROW ("Не могу читать 'Войну и мир', ошибка открытия '%s'" _ fileName);
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
//! @brief   Выводит имя файла и номер строки, где находится вызов TX_PRINT_HERE().
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
//! @brief   Выводит диагностическое сообщение в случае неуспеха операции.
//!          Используется, если лень писать if() :)
//! @note    <b>Предполагается, что операция в случае неуспеха возвращает 0 или false.</b>\n\n
//!          <b>При компиляции в режиме Release (или если определен NDEBUG) TX_NEEDED
//!          превращается в пустой оператор.</b>
//! @return  Всегда false
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
//! @brief   Возвращает максимальное из двух чисел
//! @param   a Одно из чисел :)
//! @param   b Другое из чисел :)
//! @return  Максимальное из двух чисел a и b
//! @hideinitializer
//! @usage
//! @code
//!          if (MAX (3, 7) != 7) printf ("Your CPU is broken, throw it away.");
//! @endcode
//-----------------------------------------------------------------------------

#define MAX( a, b )      ( (a) > (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Возвращает минимальное из двух чисел
//! @param   a Одно из чисел :)
//! @param   b Другое из чисел :)
//! @return  Минимальное из двух чисел a и b
//! @hideinitializer
//! @usage
//! @code
//!          if (MIN (3, 7) != 3) printf ("Your CPU is still broken, throw it away again.");
//! @endcode
//-----------------------------------------------------------------------------

#define MIN( a, b )      ( (a) < (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Число Пи
//! @return  Число Пи
//! @hideinitializer
//! @usage
//! @code
//!          if (txPI == 1) MessageBox (txWindow(), "Вы попали в другую Вселенную.", "Поздравляем", MB_ICONSTOP);
//! @endcode
//-----------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Включает/отключает внутреннюю трассировку исполнения кода библиотеки.
//!
//!          Трассировка идет через макрос TX_TRACE, который подставляется перед
//!          каждым оператором (statement). По умолчанию трассировка выключена.
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(),
//!          ее вывод можно перехватить утилитами-логгерами, например,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DebugView</a> или WinTail.
//!
//!          Задается перед включением TXLib.h в программу.
//! @usage
//! @code
//!          #define  _TX_TRACE   // Для просмотра трассы запустить DebugView
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
//!          Задается перед включением TXLib.h в программу.
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
//! @name    Прототипы функций библиотеки
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @name    TXLib API. Документацию см. ниже в определениях функций.
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
//! @name    Внутренние функции
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
//! @name    Импорт внешних библиотек
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
//! @name    Глобальные данные.
//           Не упакованы в структуру или класс, для того, чтобы это сделали Вы сами :)
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
//! @name    Инициализация библиотеки, установка параметров, получение информации
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создание окна рисования
//!
//!          При создании окна устанавливаются папаметры рисования по умолчанию,
//!          см. функцию @ref txSetDefaults().
//!
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txOk()
//! @usage
//! @code
//!          txCreateWindow ( 800,  600);
//!          txCreateWindow (1024,  768, false);
//! @endcode
//-----------------------------------------------------------------------------

bool txCreateWindow // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                    (double sizeX,        //!< Размер окна по горизонтали (в пикселях)
                     double sizeY,        //!< Размер окна по вертикали   (в пикселях)
                     bool centered        //!< Центрирование окна на дисплее
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
//! @brief   Установка параметров рисования по умолчанию.
//!
//!          Параметры по умолчанию:\n
//!          - Линии - цвет белый (TX_WHITE), толщина 1
//!          - Заливка - цвет белый (TX_WHITE)
//!          - Шрифт - Системный шрифт, цвет белый (TX_WHITE)
//!          - Логическая растровая операция - копирование цвета (R2_COPYPEN)
//!
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txSelectFont(), txSelectRegion(), txSetROP2()
//! @usage
//! @code
//!          txSetDefaults();
//! @endcode
//-----------------------------------------------------------------------------

bool txSetDefaults() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
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
//! @brief   Проверка правильности работы библиотеки
//! @return  Состояние библиотеки
//! @see     txCreateWindow()
//! @usage
//! @code
//!          txCreateWindow (800, 600);
//!          if (!txOK())
//!              {
//!              MessageBox (txWindow(), "Не смог создать окно", "Извините", MB_ICONSTOP);
//!              return;
//!              }
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txOK() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return _txConsole_OK() &&
           _txCanvas_OK();
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает размер окна рисования в виде структуры POINT.
//! @return  Размер окна рисования в виде структуры POINT.
//! @see     txGetExtentX(), txGetExtentY()
//! @usage
//! @code
//!          POINT size = txGetExtent();
//!          txLine (0, 0,      size.x, size.y);
//!          txLine (0, size.y, size.x, 0);
//! @endcode
//-----------------------------------------------------------------------------

POINT txGetExtent() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   RECT r = {0};
$   GetClientRect (txWindow(), &r);
$   POINT size = { r.right - r.left, r.bottom - r.top };
$   return size;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает ширину окна рисования.
//! @return  Ширина окна рисования.
//! @see     txGetExtent(), txGetExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_CENTER);
//!          txTextOut (txGetExtentX() / 2, 100, "O-o-o, you are in the middle now");
//! @endcode
//-----------------------------------------------------------------------------

inline
int txGetExtentX() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return txGetExtent().x;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает высоту окна рисования.
//! @return  Высота окна рисования.
//! @see     txGetExtent(), txGetExtentX()
//! @usage
//! @code
//!          void DrawHouse (int height);
//!          ...
//!          DrawHouse (txGetExtentY() / 2);
//! @endcode
//-----------------------------------------------------------------------------

inline
int txGetExtentY() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return txGetExtent().y;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Вызов функции Win32 GDI с автоматической блокировкой и разблокировкой
//! @return  Значение, возвращаемое вызываемой функцией GDI.
//! @param   cmd Команда GDI (возможно, возвращающая значение)
//! @note    Если в вызове функции GDI используются запятые, то используйте двойные
//!          скобки, чтобы получился один параметр, так как txGDI() все-таки макрос.
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @hideinitializer
//! @usage
//! @code
//!          txGDI (( Rectangle (txDC(), x1, y1, x2, y2) )); // Не забудьте про 2 скобки
//! @endcode
//-----------------------------------------------------------------------------

#define txGDI( cmd ) txUnlock ( (txLock(), (cmd)) )

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет и толщину линий, цвет текста.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! @endcode
//-----------------------------------------------------------------------------

bool txSetColor // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                (COLORREF color,   //!< Цвет линий и текста, см. @ref TX_COLOR_NAMES, RGB()
                 double thickness  //!< Толщина линий
                 )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), (int)thickness, color)) &&
            txGDI   ((Win32::SetTextColor (txDC(), color) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет линий и текста.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()
//! @usage
//! @code
//!          txColor (1.0, 0.5, 0.25);
//! @endcode
//-----------------------------------------------------------------------------

bool txColor // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
             (double red,     //!< Количество красного цвета в интервале [0; 1]
              double green,   //!< Количество зеленого цвета в интервале [0; 1]
              double blue     //!< Количество синего цвета в интервале [0; 1]
              )
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetColor (RGB (red * 255, green * 255, blue * 255));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет линий и текста.
//! @return  Текущий цвет линий и текста, см. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetColor();
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txGetColor() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
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
//! @brief   Устанавливает текущий цвет заполнения фигур.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! @endcode
//-----------------------------------------------------------------------------

bool txSetFillColor // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                    (COLORREF color  //!< Цвет заполнения, см. @ref TX_COLOR_NAMES, RGB()
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                                 Win32::CreateSolidBrush (color));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет заполнения фигур.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor()
//! @usage
//! @code
//!          txFillColor (1.0, 0.5, 0.25);
//! @endcode
//-----------------------------------------------------------------------------

bool txFillColor // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                 (double red,   //!< Количество красного цвета в интервале [0; 1]
                  double green, //!< Количество зеленого цвета в интервале [0; 1]
                  double blue   //!< Количество синего   цвета в интервале [0; 1]
                  )
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetFillColor (RGB (red * 255, green * 255, blue * 255));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет заполнения фигур.
//! @return  Текущий цвет заполнения фигур, см. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetFillColor();
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txGetFillColor() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); obj TX_NEEDED;

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) TX_NEEDED;

$   return buf.lbColor;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает режим взаимодействия цветов при рисовании.
//!
//!          При рисовании графическая библиотека может не просто красить пиксели
//!          на экране, а смешивать цвета экрана и текущие цвета линий и заполнения.
//!
//!          Режимы взаимодействия цветов:
//!
//!          @table
//!          @tr R2_COPYPEN     @td Пиксели = цвета кисти (самый нормальный режим :) @endtr
//!          @tr R2_NOTCOPYPEN  @td Пиксели = ~кисть\n @endtr
//!
//!          @tr R2_BLACK       @td Пиксели = черный цвет (цвет кисти игнорируется)    @endtr
//!          @tr R2_WHITE       @td Пиксели = белый  цвет (цвет кисти игнорируется)    @endtr
//!          @tr R2_NOT         @td Пиксели = ~пиксели    (цвет кисти игнорируется)\n  @endtr
//!
//!          @tr R2_XORPEN      @td Пиксели =    пиксели ^  кисть    @endtr
//!          @tr R2_NOTXORPEN   @td Пиксели = ~ (пиксели ^  кисть)\n @endtr
//!
//!          @tr R2_MASKPEN     @td Пиксели =    пиксели &  кисть    @endtr
//!          @tr R2_NOTMASKPEN  @td Пиксели = ~ (пиксели &  кисть)   @endtr
//!          @tr R2_MASKNOTPEN  @td Пиксели =    пиксели & ~кисть    @endtr
//!          @tr R2_MASKPENNOT  @td Пиксели =   ~пиксели &  кисть\n  @endtr
//!
//!          @tr R2_MERGEPEN    @td Пиксели =    пиксели |  кисть    @endtr
//!          @tr R2_NOTMERGEPEN @td Пиксели = ~ (пиксели |  кисть)   @endtr
//!          @tr R2_MERGENOTPEN @td Пиксели =    пиксели | ~кисть    @endtr
//!          @tr R2_MERGEPENNOT @td Пиксели =   ~пиксели |  кисть\n  @endtr
//!
//!          @tr R2_NOP         @td Пиксели вообще не изменяются.    @endtr
//!          @endtable
//!
//! @return  Предыдущий режим взаимодействия цветов, см. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txSetROP2 (R2_XORPEN);
//!          txSetROP2 (R2_COPYPEN);
//! @endcode
//-----------------------------------------------------------------------------

bool txSetROP2 // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
               (int mode         //!< Режим смешивания цветов
                )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::SetROP2 (txDC(), mode) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает (смешивает) цвет из трех базовых цветов (компонент).
//! @return  Созданный цвет в формате COLORREF.
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
COLORREF RGB (red,       //!< Количество красного цвета в интервале [0; 255]
              green,     //!< Количество зеленого цвета в интервале [0; 255]
              blue       //!< Количество синего   цвета в интервале [0; 255]
              );
#endif

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Извлекает цветовую компоненту (цветовой канал) из смешанного цвета.
//! @return  Цветовая компонента, см. @ref TX_COLOR_NAMES
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_COLOR_NAMES
//! @usage
//! @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          Другие примеры см. в функциях AppearText(), AppearEarth() Примера 5 ("Циклы").
//! @endcode
//-----------------------------------------------------------------------------

int txExtractColor // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                   (COLORREF color,     //!< Смешанный цвет
                    COLORREF component  //!< Извлекаемая компонента, см. @ref TX_COLOR_NAMES
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
//! @brief   Преобразует цвет из формата RGB в формат HSL.
//!
//!          Формат RGB определяется как
//!
//!          - Красная компонента цвета (Red), от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя компонента цвета (Blue), от 0 до 255.
//!
//!          Формат HSL определяется как
//!
//!          - Цветовой тон (Hue), от 0 до 360.
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота (Lightness), от 0 до 255.
//!
//! @return  Созданный цвет в виде COLORREF.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_COLOR_NAMES
//! @usage
//! @code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txRGB2HSL // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                   (COLORREF rgbColor   //!< Преобразуемый цвет в формате RGB
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
//! @brief   Преобразует цвет из формата HSL в формат RGB.
//!
//!          Формат RGB определяется как
//!
//!          - Красная компонента цвета (Red),   от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя   компонента цвета (Blue),  от 0 до 255.
//!
//!          Формат HSL определяется как
//!
//!          - Цветовой тон (Hue),        от 0 до 360.
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота     (Lightness),  от 0 до 255.
//!
//! @return  Созданный цвет в виде COLORREF.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES
//! @see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), @ref TX_COLOR_NAMES
//! @usage
//! @code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txHSL2RGB // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                   (COLORREF hslColor   //!< Преобразуемый цвет в формате HSL
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
//! @name    Рисование фигур
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Стирает холст текущим цветом заполнения.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetFillColor(), txFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txClear();
//! @endcode
//-----------------------------------------------------------------------------

bool txClear() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   POINT size = txGetExtent();

$   return txGDI ((Win32::PatBlt (txDC(), 0, 0, size.x, size.y, PATCOPY) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует пиксель (точку на экране).
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txPixel(), txGetPixel(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSetPixel (100, 100, TX_RED);
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! @endcode
//-----------------------------------------------------------------------------

bool txSetPixel // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                (double x,      //!< Х-координата точки
                 double y,      //!< Y-координата точки
                 COLORREF color //!< Цвет точки, см. @ref TX_COLOR_NAMES, RGB()
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
//! @brief   Рисует пиксель (точку на экране).
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetPixel(), txGetPixel()
//! @usage
//! @code
//!          txSetPixel (100, 100, 1.0, 0.5, 0.25);
//! @endcode
//-----------------------------------------------------------------------------

bool txPixel // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
             (double x,         //!< Х-координата точки
              double y,         //!< Y-координата точки
              double red,       //!< Количество красного цвета в интервале [0; 1]
              double green,     //!< Количество зеленого цвета в интервале [0; 1]
              double blue       //!< Количество синего цвета в интервале [0; 1]
              )
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetPixel (x, y, RGB (red * 255, green * 255, blue * 255));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет точки (пикселя) на экране.
//! @return  Текущий цвет пикселя, см. @ref TX_COLOR_NAMES, RGB()
//! @see     txSetPixel(), txPixel(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED) CarCrash (x, y);
//! @endcode
//-----------------------------------------------------------------------------

COLORREF txGetPixel // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                    (double x,  //!< Х-координата точки
                     double y   //!< Y-координата точки
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::GetPixel (txDC(), (int)x, (int)y)));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует линию.
//!          Цвет и толщина линии задается функцией txSetColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txLine (100, 200, 400, 500);
//! @endcode
//-----------------------------------------------------------------------------

bool txLine // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
            (double x0,        //!< X-координата начальной точки
             double y0,        //!< Y-координата начальной точки
             double x1,        //!< X-координата конечной  точки
             double y1         //!< Y-координата конечной  точки
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
//! @brief   Рисует прямоугольник.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txRectangle (100, 200, 400, 500);
//! @endcode
//-----------------------------------------------------------------------------

bool txRectangle // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                 (double x0,   //!< X-координата верхнего левого угла
                  double y0,   //!< Y-координата верхнего левого угла
                  double x1,   //!< X-координата нижнего правого угла
                  double y1    //!< Y-координата нижнего правого угла
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
//! @brief   Рисует ломаную линию или многоугольник.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          POINT star[6] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}, {150, 300}};
//!          txPolygon (star, 6);
//! @endcode
//-----------------------------------------------------------------------------

bool txPolygon // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
               (POINT* points, //!< Массив структур POINT с координатами точек
                int numPoints  //!< Количество точек в массиве
                )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::Polygon (txDC(), points, numPoints) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует эллипс.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txEllipse (100, 100, 300, 200);
//! @endcode
//-----------------------------------------------------------------------------

bool txEllipse // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
               (double x0,     //!< X-координата верхнего левого угла описанного прямоугольника
                double y0,     //!< Y-координата верхнего левого угла описанного прямоугольника
                double x1,     //!< X-координата нижнего правого угла описанного прямоугольника
                double y1      //!< Y-координата нижнего правого угла описанного прямоугольника
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
//! @brief   Рисует окружность или круг.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txCircle (100, 100, 10);
//! @endcode
//-----------------------------------------------------------------------------

bool txCircle // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
              (double x,       //!< Х-координата центра
               double y,       //!< Y-координата центра
               double r        //!< Радиус
               )
    {
$   return txEllipse (x-r, y-r, x+r, y+r);
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует дугу эллипса.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txArc (100, 100, 300, 200, 0, 180);
//! @endcode
//-----------------------------------------------------------------------------

bool txArc // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
           (double x0,         //!< X-координата верхнего левого угла прямоугольника,
                               //!<   описанного вокруг эллипса, содержащего дугу
            double y0,         //!< Y-координата верхнего левого угла прямоугольника
            double x1,         //!< X-координата нижнего правого угла прямоугольника
            double y1,         //!< Y-координата нижнего правого угла прямоугольника
            double startAngle, //!< Угол между направлением оси OX и началом дуги (в градусах)
            double totalAngle  //!< Величина дуги (в градусах)
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
//! @brief   Рисует сектор эллипса.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txPie (100, 100, 300, 200, 0, 180);
//! @endcode
//-----------------------------------------------------------------------------

bool txPie // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
           (double x0,         //!< X-координата верхнего левого угла прямоугольника,
                               //!<   описанного вокруг эллипса, содержащего сектор
            double y0,         //!< Y-координата верхнего левого угла прямоугольника
            double x1,         //!< X-координата нижнего правого угла прямоугольника
            double y1,         //!< Y-координата нижнего правого угла прямоугольника
            double startAngle, //!< Угол между направлением оси OX и началом сектора (в градусах)
            double totalAngle  //!< Величина сектора (в градусах)
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
//! @brief   Рисует хорду эллипса.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txChord (100, 100, 300, 200, 0, 180);
//! @endcode
//-----------------------------------------------------------------------------

bool txChord // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
             (double x0,         //!< X-координата верхнего левого угла прямоугольника,
                                 //!<   описанного вокруг эллипса, содержащего хорду
              double y0,         //!< Y-координата верхнего левого угла прямоугольника
              double x1,         //!< X-координата нижнего правого угла прямоугольника
              double y1,         //!< Y-координата нижнего правого угла прямоугольника
              double startAngle, //!< Угол между направлением оси OX и началом хорды (в градусах)
              double totalAngle  //!< Величина хорды (в градусах)
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
//! @brief   Заливает произвольный контур текущим цветом заполнения.
//!          Цвет заполнения задается функцией txSetFillColor().
//!          Не рекомендуется для применения - довольно медленно работает.
//!
//!          Режимы заливки:
//!
//!          FLOODFILLSURFACE - Заливать область, куазанную цветом color.\n
//!          FLOODFILLBORDER  - Заливать до границы, указанной цветом color.
//!
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! @usage
//! @code
//!          txFloodFill (100, 100);
//! @endcode
//-----------------------------------------------------------------------------

bool txFloodFill // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                 (double x,                        //!< Х-координата точки начала заливки
                  double y,                        //!< Y-координата точки начала заливки
                  COLORREF color = TX_TRANSPARENT, //!< Цвет заливаемой области (TX_TRANSPARENT - автоопределение)
                  DWORD mode = FLOODFILLSURFACE    //!< Режим заливки (FLOODFILLSURFACE - заливка однородного фона)
                  )
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y);

$   return txGDI ((Win32::ExtFloodFill (txDC(), (int)x, (int)y, color, mode) != 0));
    }

//=============================================================================
//
//! @name    Работа с текстом
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует текст.
//!          Цвет текста задается функцией txSetColor().
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//! @endcode
//-----------------------------------------------------------------------------

bool txTextOut // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
               (double x,         //!< Х-координата начальной точки текста
                double y,         //!< Y-координата начальной точки текста
                const char text[] //!< Текстовая строка
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
//! @brief   Выбирает текущий шрифт.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txTextOut()
//! @usage
//! @code
//!          txSelectFont ("Comic Sans MS", 20);
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//!          txSelectFont ("Comic Sans MS", 20, 10, false, true, false, true);
//!          txTextOut (100, 200, "Но ее почему-то нет.");
//! @endcode
//-----------------------------------------------------------------------------

bool txSelectFont // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                  (const char* name,       //!< Название шрифта
                   double sizeY,           //!< Высота букв (размер по Y)
                   double sizeX = 0,       //!< Ширина букв
                   int bold = FW_DONTCARE, //!< Жирность шрифта (от 0 до 1000)
                   bool italic = false,    //!< Курсив
                   bool underline = false, //!< Подчеркивание
                   bool strikeout = false  //!< Зачеркивание
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
//! @brief   Вычисляет размеры текстовой надписи.
//! @return  Размеры надписи в структуре SIZE.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          SIZE size = txGetTextExtent (text);
//!          txTextOut (100 + size.cx / 2, 200 + size.cy / 2, text);
//! @endcode
//-----------------------------------------------------------------------------

SIZE txGetTextExtent // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                     (const char* text     //!< Текстовая строка
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, (int) strlen (text), &size))) TX_NEEDED;

$   return size;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Вычисляет ширину текстовой надписи.
//! @return  Ширина надписи.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//-----------------------------------------------------------------------------

int txGetTextExtentX // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                     (const char text[]     //!< Текстовая строка
                      )
    {
$   return txGetTextExtent (text) .cx;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Вычисляет высоту текстовой надписи.
//! @return  Высота надписи.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//-----------------------------------------------------------------------------

int txGetTextExtentY // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                     (const char text[]     //!< Текстовая строка
                      )
    {
$   return txGetTextExtent (text) .cy;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущее выравнивание текста.
//!
//!          Флаги выравнивания:
//!
//!          @table
//!          @tr TA_BASELINE @td Точка (X,Y) определяет базовую линию текста. @endtr
//!          @tr TA_BOTTOM   @td Точка (X,Y) определяет нижнюю сторону описанного прямоугольника\n
//!                              (текст лежит выше этой точки).   @endtr
//!          @tr TA_TOP      @td Точка (X,Y) определяет верхнюю сторону описанного прямоугольника\n
//!                              (текст лежит ниже этой точки).\n @endtr
//!
//!          @tr TA_CENTER   @td Текст будет выровнен по горизонтали относительно точки (X,Y). @endtr
//!          @tr TA_LEFT     @td Точка (X,Y) определяет левую сторону описанного прямоугольника\n
//!                              (текст лежит правее этой точки). @endtr
//!          @tr TA_RIGHT    @td Точка (X,Y) определяет правую сторону описанного прямоугольника\n
//!                              (текст лежит левее этой точки).  @endtr
//!          @endtable
//!
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! @usage
//! @code
//!          txSetTextAlign (TA_RIGHT);
//!
//!          txSetTextAlign();
//! @endcode
//-----------------------------------------------------------------------------

bool txSetTextAlign // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                    (unsigned align = TA_CENTER | TA_BASELINE //!< Флаги выравнивания
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::SetTextAlign (txDC(), align)));
$   return true;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Ищет шрифт по его названию.
//! @return  Информация о шрифте в структуре LOGFONT.
//!          Если шрифт не найден, возвращает NULL.
//! @see     txTextOut(), txSelectFont()
//! @usage
//! @code
//!          if (txFontExist ("Comic Sans MS")) txSelectFont ("Comic Sans MS", 30);
//!          else                               txSelectFont ("Times", 30);
//! @endcode
//-----------------------------------------------------------------------------

LOGFONT* txFontExist // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                     (const char* name      //!< Название шрифта
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
//! @name    Разное
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий прямоугольный регион отсечения.
//!          Всё, что оказывается вне региона отсечения, не рисуется.
//!
//!          Непрямоугольные регионы устанавливайте самостоятельно
//!          через стандартные функции работы с регионами из Win32 API.
//!
//! @return  Декскриптор установленного региона. Если регион не создан или не установлен - NULL.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//! @code
//!          txSelectRegion (100, 100, 300, 400);
//! @endcode
//-----------------------------------------------------------------------------

HRGN txSelectRegion // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                    (double x0,   //!< X-координата верхнего левого угла
                     double y0,   //!< Y-координата верхнего левого угла
                     double x1,   //!< X-координата нижнего правого угла
                     double y1    //!< Y-координата нижнего правого угла
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HRGN rgn = CreateRectRgn ((int)x0, (int)y0, (int)x1, (int)y1);

$   txSelectObject (rgn) || (Win32::DeleteObject (rgn), rgn = NULL);

$   return rgn;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Устанавливает текущий объект GDI.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//!          txSelectFont(), txSelectRegion()
//! @usage
//! @code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! @endcode
//-----------------------------------------------------------------------------

bool txSelectObject // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                    (HGDIOBJ obj   //!< Дескриптор объекта GDI
                     )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect (obj);
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Блокирует обновление изображения окна, во избежание мигания.
//!
//! @warning Избегайте блокирования на долгое время. Это может привести к
//!          дефектам изображения в окне. Если требуется задержка, то используйте
//!          txSleep() вместо обычной функции Sleep().
//!
//! @return  Значение счетчика блокировки (если 0, то рисование разблокировано).
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
int txBegin() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock + 1);

$   return _txCanvas_RefreshLock;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Разблокирует обновление окна, заблокированное функцией txBegin().
//!
//! @warning Если txBegin() вызывалась несколько раз, то для снятия блокировки
//!          требуется столько же раз вызвать txEnd().
//!
//! @return  Значение счетчика блокировки (если 0, то рисование разблокировано).
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
int txEnd() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock - 1);

$   return _txCanvas_RefreshLock;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Блокирует или разблокирует обновление изображения в окне.
//!
//!          В отличие от txBegin() и txEnd(), позволяет явно установить или
//!          снять блокировку.
//!
//! @warning Избегайте блокирования на долгое время. Это может привести к
//!          дефектам изображения в окне. Если требуется задержка, то используйте
//!          txSleep() вместо обычной функции Sleep().
//!
//! @return  Предыдущее состояние режима обновления.
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txUpdateWindow // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                    (bool update   //!< Режим обновления (false - запретить обновление)
                     )
    {
$   return _txCanvas_SetRefreshLock (update? 0 : 1) != 0;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Блокирует или разблокирует рисование мигающего курсора в окне.
//! @return  Предыдущее значение блокировки.
//! @see     txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! @endcode
//-----------------------------------------------------------------------------

bool txTextCursor // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                  (bool blink   //!< false - блокировать мигающий курсор
                   )
    {
$   bool old = _txConsole_CursorMode;

$   _txConsole_CursorMode = blink;

$   return old;
    }

//=============================================================================
//
//! @name    Рисование в памяти (на "виртуальном холсте") и загрузка изображений
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает дополнительный холст (контекст рисования, Device Context, DC) в памяти.
//! @return  Дескриптор (системный номер, выданный Windows) созданного холста (контекста рисования).
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//!
//! @remarks Созданный контекст затем будет нужно удалить при помощи txDeleteDC().
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

HDC txCreateCompatibleDC // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                         (double sizeX,     //!< Ширина холста
                          double sizeY,     //!< Высота холста
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
//! @brief   Загружает из файла изображение в формате BMP. Делает это довольно медленно.
//!
//!          Изображение загружается в создаваемый контекст рисования в памяти ("виртуальный холст"),
//!          который затем будет нужно <b>обязательно</b> удалить при помощи txDeleteDC().
//!
//!          Изображения поддерживаются только в формате BMP. Если взять файл другого формата, например JPG, и переименовать
//!          его со сменой расширения на BMP, то от этого формат не изменится. Такое изображение загружено не будет.
//!
//! @return  Дескриптор созданного контекста рисования в памяти, с загруженным изображением.
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(), txTransparentBlt(),
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//-----------------------------------------------------------------------------

HDC txLoadImage // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                (LPCTSTR filename  //!< Имя файла с изображением в формате BMP
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
//! @brief   Уничтожает холст (контекст рисования, DC) в памяти.
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//-----------------------------------------------------------------------------

bool txDeleteDC // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                (HDC dc            //!< Контекст рисования для уничтожения
                 )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txBuffer_Delete (dc);
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой.
//!
//!          Режимы копирования:
//!
//!          @table
//!          @tr SRCCOPY     @td Просто копирует :) - самый распространенный режим\n @endtr
//!
//!          @tr BLACKNESS   @td Заполняет холст-приемник черным цветом (холст-источник игнорируется). @endtr
//!          @tr WHITENESS   @td Заполняет холст-приемник белым цветом  (холст-источник игнорируется). @endtr
//!          @tr DSTINVERT   @td Инвертирует цвета на холсте-приемнике  (холст-источник игнорируется). @endtr
//!          @tr PATCOPY     @td Копирует цвет текущей кисти холста-приемника.\n @endtr
//!
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
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), @ref TX_COLOR_NAMES, RGB()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC background = txLoadImage ("Resources\\Images\\Background.bmp");
//!          txBitBlt (txDC(), 0, 0, 800, 600, background, 0, 0);
//!          txDeleteDC (background);
//! @endcode
//-----------------------------------------------------------------------------

bool txBitBlt // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
              (HDC dest,        //!< Контекст назначения (куда копировать)
               double xDest,    //!< Х-координата верхнего левого угла изображения-приемника
               double yDest,    //!< Y-координата верхнего левого угла изображения-приемника
               double width,    //!< Ширина копируемого изображения
               double height,   //!< Высота копируемого изображения
               HDC src,         //!< Контекст источника (откуда копировать)
               double xSrc,     //!< Х-координата верхнего левого угла изображения-источника
               double ySrc,     //!< Y-координата верхнего левого угла изображения-источника
               DWORD rOp        //!< Растровая операция копирования
               )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::BitBlt (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                                  src,  (int)xSrc,  (int)ySrc, rOp) != 0));
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//! @brief   с учетом прозрачности.
//!
//!          Стандартная функция TransparentBlt из Win32 API может масштабировать изображение.
//!          В txTransparentBlt это убрано для упрощения использования. If you need image scaling,
//!          use original function TransparentBlt and don't mess with stupid TX-based tools.
//!          (See implementation of txTransparentBlt in TXLib.h).
//!
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC superman = txLoadImage ("Resources\\Images\\SuperMan.bmp");
//!          txTransparentBlt (txDC(), 0, 0, 800, 600, superman, 0, 0);
//!          txDeleteDC (superman);  // So pity :(
//! @endcode
//-----------------------------------------------------------------------------

bool txTransparentBlt // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                      (HDC dest,             //!< Контекст назначения (куда копировать)
                       double xDest,         //!< Х-координата верхнего левого угла изображения-приемника
                       double yDest,         //!< Y-координата верхнего левого угла изображения-приемника
                       double width,         //!< Ширина копируемого изображения
                       double height,        //!< Высота копируемого изображения
                       HDC src,              //!< Контекст источника (откуда копировать)
                       double xSrc,          //!< Х-координата верхнего левого угла изображения-источника
                       double ySrc,          //!< Y-координата верхнего левого угла изображения-источника
                       COLORREF transColor   //!< Цвет, который будет считаться прозрачным
                       )
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   if (!TransparentBlt) return false;

$   return Win32::TransparentBlt (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                                  src,  (int)xSrc,  (int)ySrc,  (int)width, (int)height, transColor) != 0;
    }

//-----------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//! @brief   с учетом прозрачности.
//!
//!          Изображение должно быть загружено с помощью txLoadImage() и иметь
//!          32-битовый RGBA-формат. Дополнительный канал (альфа-канал) этого
//!          формата отвечает за прозрачность участков изображения.
//!
//!          Альфа-канал можно сделать, например, в Adobe Photoshop, командой
//!          "Новый канал (New Channel)" в палитре каналов (Channels). Черный
//!          цвет в альфа-канале соответствует полной прозрачности, белый -
//!          полной непрозрачности. При этом в прозрачных областях само изображение
//!          (в канале RGB) должно быть черным.
//!
//!          Стандартная функция AlphaBlend из Win32 API может масштабировать изображение.
//!          В txAlphaBlend это убрано для упрощения использования. If you still need image
//!          scaling, use original function AlphaBlend and don't mess with stupid TX-based
//!          tools. (See implementation of txAlphaBlend in TXLib.h).
//!
//! @return  Если операция была успешна - true, иначе - false.
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! @usage
//!          Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC superman = txLoadImage ("Resources\\Images\\SuperMan.bmp");
//!          txAlphaBlend (txDC(), 0, 0, 800, 600, superman, 0, 0);
//!          txDeleteDC (superman);  // Don't worry, he'll come back in future series
//! @endcode
//-----------------------------------------------------------------------------

bool txAlphaBlend // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                  (HDC dest,        //!< Контекст назначения (куда копировать)
                   double xDest,    //!< Х-координата верхнего левого угла изображения-приемника
                   double yDest,    //!< Y-координата верхнего левого угла изображения-приемника
                   double width,    //!< Ширина копируемого изображения
                   double height,   //!< Высота копируемого изображения
                   HDC src,         //!< Контекст источника (откуда копировать)
                   double xSrc,     //!< Х-координата верхнего левого угла изображения-источника
                   double ySrc,     //!< Y-координата верхнего левого угла изображения-источника
                   double alpha     //!< Общая прозрачность изображения, в дополнение к альфа-каналу.\n
                                    //!<   (0 - все прозрачно, 1 - использовать только альфа-канал)
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
//! @name    Работа с мышью
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает Х-Координату Мыши!
//! @return  Х-координата мыши.
//! @see     txMouseX(), txMouseY(), txMouseButtons()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
int txMouseX() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return _txMousePos.x;
    }

//-----------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает Y-Координату Мыши!
//! @return  Y-координата мыши.
//! @see     txMouseX(), txMouseY(), txMouseButtons()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
int txMouseY() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return _txMousePos.y;
    }

//-----------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает состояние Кнопок Мыши!
//!
//!          В возвращаемом значении выставленный в единицу 1-й (младший)
//!          бит означает нажатую левую Кнопку Мыши, 2-й - правую, 3-й -
//!          среднюю.\n Например, возвращенное число 5 (двоичное 101) означает
//!          одновременное нажатие средней и левой Кнопок, но не правой Кнопки.
//!
//! @return  Состояние Кнопок Мыши!
//! @see     txMouseX(), txMouseY(), txMouseButtons()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

int txMouseButtons() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return _txMouseButtons;
    }

//=============================================================================
//
//! @name    Работа с диалоговыми окнами
//
//=============================================================================

//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------

struct txDialog
    {

//-----------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Константы для задания типа контрола.
//!
//!          Вместо констант можно использовать названия оконных классов,
//!          преобразованные к типу txDialog::CONTROL.
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//! @hideinitializer
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
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
//-----------------------------------------------------------------------------

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

//-----------------------------------------------------------------------------
//! @brief   Конструктор.
//! @see     txDialog::txDialog (const txDialog::Layout*)
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    public:
    txDialog ();

//-----------------------------------------------------------------------------
//! @brief   Конструктор.
//! @see     txDialog::Layout, txDialog::setLayout()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    txDialog (const Layout* layout               //!< Макет диалогового окна
             );

//-----------------------------------------------------------------------------
//! @brief   Деструктор.
//-----------------------------------------------------------------------------

    virtual ~txDialog () {};

//-----------------------------------------------------------------------------
//! @brief   Устанавливает текущий макет диалогового окна.
//! @return  Предыдущий макет.
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    const Layout* setLayout (const Layout* layout //!< Макет диалогового окна
                            );

//-----------------------------------------------------------------------------
//! @brief   Функция обработки сообщений диалогового окна.
//!
//!          Эту функцию надо переопределить для обработки событий окна,
//!          или построить ее с помощью макросов TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @return  В большинстве случаев false, детальнее см. DialogProc
//!          в <a href=msdn.com>MSDN</a>.
//! @see     txDialog::dialogBox()
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd,           //!< Дескриптор
                            UINT _msg,           //!< Номер сообщения
                            WPARAM _wParam,      //!< 1-й параметр сообщения (WORD)
                            LPARAM _lParam       //!< 2-й параметр сообщения (DWORD)
                            );

//-----------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//! @return  Значение, указанное в функции EndDialog().\n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была
//!          запущена txDialog::dialogBox().
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    INT_PTR dialogBox
        (const Layout* layout = NULL, //!< Макет диалогового окна.\n
                                      //!< Если не указан - используется значение,
                                      //!< заданное txDialog::setLayout() или конструктором
                                      //!< txDialog::txDialog (const txDialog::Layout*)
         size_t bufsize = 0           //!< Размер буфера для создания шаблона диалога
                                      //!< (если не указан - размер по умолчанию)
         );

//-----------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//! @return  Значение, указанное в функции EndDialog().\n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была
//!          запущена txDialog::dialogBox().
//! @see     txDialog::dialogProc()
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//-----------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource  //!< Идентификатор диалогового ресурса
                       );

//-----------------------------------------------------------------------------
//! @brief   Закрытые конструктор копирования и оператор присваивания.
//-----------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//-----------------------------------------------------------------------------
//! Настоящая диалоговая функция (не @ref txDialog::dialogProc(), т.к. функция окна
//! Win32 должна быть статической).

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//-----------------------------------------------------------------------------
//! Текущий макет диалога.

    private:
    const Layout* layout_;
    };

//=============================================================================
//
//! @name    Реализация методов класса txDialog
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
$   if (!layout)  return TX_THROW ("Не установлен динамический шаблон диалога    ");

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_THROW ("GlobalAlloc(): Нет памяти для шаблона диалога    ");

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

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_THROW ("Не найден ресурс диалога %d   " _ resourceID);

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
//! @name    Макросы для построения статической карты сообщений (Message Map)
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Заголовок карты сообщений (Message Map).
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//! @brief   Заголовок обработчика сообщения (Message handler) карты сообщений.
//! @param   id Идентификатор сообщения
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//! @hideinitializer
//-----------------------------------------------------------------------------

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Начало карты команд (Command map) в карте сообщений.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//! @brief   Завершитель карты сообщений.
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP,
//! @see     txDialog::dialogProc(), txDialog
//! @usage
//! @code
//!          Cм. реализацию функции txInputBox().
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
//! @name    Пример использования класса диалога: функция txInputBox()
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Ввод строки в отдельном окне.
//! @return  Введенная строка (статическая переменная функции).
//! @warning Возвращаемая строка - статическая, и обновляется при каждом вызове функции!
//!          Для сохранения ее необходимо копировать при помощи <i>strcpy()</i>.
//! @see     txDialog, TX_BEGIN_MESSAGE_MAP, TX_BEGIN_COMMAND_MAP, TX_HANDLE, TX_END_MESSAGE_MAP
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

const char* txInputBox // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                       (const char* text    = NULL, //!< Текст с вопросом
                        const char* caption = NULL, //!< Заголовок окна
                        const char* input   = NULL  //!< Значение строки по умолчанию
                        )
    {

    // Получение имени EXE-файла, на случай, если кое-кто поленился задать название диалога

$   char name[256] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1) TX_NEEDED;

    // Если не указаны параметры, использовать более-менее внятные надписи. А что делать?!..

$   if (!text)    text    = "Введите строку:";
$   if (!caption) caption = name;
$   if (!input)   input   = "";

    // Идентификаторы элементов диалога. Они требуются в GetDlgItemText().
    // Если диалог строится не вручную, а редактором ресурсов, то они задаются в нем автоматически.
    // У нас же тут олдскул хардкор стайл. А что делать? Редакторы ресурсов разные у разных сред
    // программирования. Поэтому для независимости от них все будет строиться на этапе выполнения,
    // динамически. Хе-хе, вы еще посмотрите, как в txDialog::dialogBox() и _tx_DLGTEMPLATE_...()
    // все это будет строиться... О_о

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    // Задание макета (вида) диалога в виде массива структур.
    // С помощью особого порядка полей в структуре txDialog::Layout и констант из класса
    // txDialog этот массив становится похож на описание ресурса диалога в .rc - файле.
    // См. описание синтаксиса rc-файла в документации по Win32 (MSDN, http://msdn.com).

$   txDialog::Layout layout[] =

    //----------------------+-----------+-------------+-----------------+-----------------------------------------------------
    //     Тип элемента     | Имя       | Идентифика- |   Координаты    | Флаги элементов
    //     диалога          | элемента  | тор, связан-|-----------------| (см. описание элементов диалога в MSDN).
    //                      |           | ный с ним   | X | Y |Шир.|Выс.|
    //----------------------+-----------+-------------+---+---+----+----+-----------------------------------------------------
    //                      |           |             |   |   |    |    |
        {{ txDialog::DIALOG,   caption,   0,             0,  0, 240,  85                                                     },
         { txDialog::STATIC,   text,      ID_TEXT_,     10, 10, 150,  40, SS_LEFT                                            },
         { txDialog::EDIT,     input,     ID_INPUT_,    10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP  },
         { txDialog::BUTTON,   "&OK",     IDOK,        180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP  },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL,    180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP  },
         { txDialog::END                                                                                                     }};

    // Класс диалога для InputBox. Внутренний, т.к. зачем ему быть внешним.
    // Нужен в основном для задания строки ввода (str) и оконной функции диалогового окна,
    // требуемой Win32 (она построена макросами TX_BEGIN_MESSAGE_MAP и другими). Можно не делать
    // внутреннего класса, но тогда оконную функцию придется писать в глобальной области видимости,
    // и str объявлять глобально тоже (или передавать ее адрес через DialogBoxParam и записывать
    // его в класс во время обработки WM_INITDIALOG).

    struct inputDlg : txDialog
        {
        char str [1024];

        inputDlg()
            {
$           memset (str, 0, sizeof (str) - 1);          // Обнуление всей строки
            }

        TX_BEGIN_MESSAGE_MAP()    // На самом деле это начало оконной функции!

            TX_COMMAND_MAP        // Здесь обрабатываются WM_COMMAND. На самом деле это switch

                // При нажатии кнопки OK копируем строку из поля ввода в нашу переменную str, т.к.
                // после закрытия диалога строка ввода умрет и текст уже из нее получить.
                // Этот макрос на самом деле превращается в case из оператора switch.
                // _wnd - это параметр оконной функции, см. определение макроса TX_BEGIN_MESSAGE_MAP().

                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP
        };

    // Убираем дефайны, чтобы потом не мешали.
    // От этого они получаются "локального действия", как будто у них была бы область видимости -
    // функция. На самом деле это сделано вручную через #undef. Чтобы подчеркнуть их локальную
    // природу, у них имена заканчиваются на _.

    #undef ID_TEXT_
    #undef ID_INPUT_

    // Это статический объект, потому что строка в нем должна жить после завершения функции txInputBox.

$   static inputDlg dlg;

    // Передаем layout и запускаем окно диалога

$   dlg.dialogBox (layout);

    // Возвращаем адрес строки из статического объекта. Так можно ltkfnm, потому что статический
    // объект не умрет при выходе из функции и строка в нем, соответственно, тоже.

$   return dlg.str;
    }

//=============================================================================
//
//! @name    Back-hole (I hope, not an ass-hole:) of the library)
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Возвращает дескриптор контекста рисования (DC) холста
//! @return  Дескриптор контекста рисования холста
//! @see     txWindow(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
HDC txDC() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return _txCanvas_BackBuf[0];
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Возвращает дескриптор окна холста
//! @return  Дескриптор окна холста
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
HWND txWindow() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return _txCanvas_Wnd;
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Блокировка холста (контекста рисования).
//!
//!          Перед вызовом любых функций Win32 GDI необходимо заблокировать
//!          холст функцией txLock() и затем разблокировать с помощью txUnlock().
//!          Это связано с тем, что обновление содержимого окна (для тех, кто
//!          знает - обработка сообщения WM_PAINT :) происходит в отдельном
//!          вспомогательном потоке. Надолго блокировать нельзя - при
//!          заблокированном холсте окно не обновляется.
//!
//!          txLock() использует EnterCriticalSection(), и физически
//!          приостанавливает поток, обновляющий окно, так что надолго
//!          блокировать нельзя. Иначе тормозится обработка оконных сообщений
//!          и окно перестает реагировать на действия пользователя.
//!
//!          txLock()/txUnlock() - низкоуровневый механизм, он отличается от
//!          высокоуровневого механизма txBegin()/txEnd()/txUpdateWindow(),
//!          который не приостанавливает поток, а просто отключает операции
//!          по обновлению окна.
//!
//! @return  Состояние блокировки
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txLock // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
            (bool wait   //!< Ожидать конца перерисовки окна вспомогательным потоком
            )
    {
$   if (wait) { return    EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { return TryEnterCriticalSection (&_txCanvas_LockBackBuf) != 0;  }
    }

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Разблокировка холста
//! @return  Состояние блокировки (всегда false)
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------
//! @{

template <typename T>
inline
T    txUnlock ( // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
            T value      //!< Значение, передаваемое сквозь txUnlock()
            )
    {
$   txUnlock();
$   return value;
    }

inline
bool txUnlock() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   LeaveCriticalSection (&_txCanvas_LockBackBuf);
$   return false;
    }

//! @}

//-----------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Возвращает строку с информацией о текущей версии библиотеки.
//! @return  Строка с информацией о текущей версии библиотеки.
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
const char* txVersion() // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
    {
$   return _TX_VERSION;
    }

//=============================================================================
//
//! @name    Другие функции
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Вычисление размера массива в элементах
//!
//!          Макрос sizearr() делит размер массива в байтах на размер элемента массива,
//!          получается размер массива в элементах.
//!
//! @param   arr Имя массива
//! @return  Размер массива в элементах
//! @warning Определение массива вместе с его размером должно быть доступно
//!          в месте использования sizearr(). Размер массива в байтах должен быть
//!          известен при компиляции.
//! @hideinitializer
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

#define sizearr( arr )   ( sizeof (arr) / sizeof (arr)[0] )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Проверка, находится ли параметр х внутри замкнутого интервала [a; b]
//! @return  Если a <= x && x <= b, то истина, если нет - ложь
//! @hideinitializer
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

template <typename T>
inline
bool In // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
        (T x, //!< Проверяемый параметр
         T a, //!< Левая  граница (включительно)
         T b  //!< Правая граница (включительно)
         )
    {
    return a <= x && x <= b;
    }

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Проверка, находится ли точка pt внутри прямоугольника rect
//! @return  Результат проверки
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

inline
bool In // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
        (const COORD& pt,       //!< Проверяемая точка
         const SMALL_RECT& rect //!< Прямоугольник
         )
    {
    return In (pt.X, rect.Left, rect.Right) &&
           In (pt.Y, rect.Top,  rect.Bottom);
    }

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Генератор случайных чисел
//! @param   range Правая граница диапазона (не включая саму границу).
//! @return  Случайное целое число в диапазоне [0; range).\n
//!          Вы еще помните, что означают разные скобочки в обозначении интервалов? :)
//! @hideinitializer
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

#define random( range )  ( rand() % (range) )

//-----------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Задерживает выполнение программы на определенное время.
//!
//!          Во время задержки обновление изображения в окне всегда
//!          автоматически разблокируется.
//!
//! @return  Состояние блокировки обновления окна.
//! @see     txUpdateWindow()
//! @usage
//! @code
//!          txSleep (500); // Поспать полсекунды
//! @endcode
//-----------------------------------------------------------------------------

inline
bool txSleep // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
             (int time   //!< Задержка в миллисекундах
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
//! @brief   Воспроизводит звуковой файл.
//!
//!          Режимы воспроизведения:
//!
//!          @table
//!          @tr SND_ASYNC       @td Звук проигрывается одновременно с работой программы.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL). @endtr
//!          @tr SND_SYNC        @td Выполнение программы приостанавливается до окончания
//!                                  воспроизведения звука. @endtr
//!          @tr SND_LOOP        @td Зацикливать звук при воспроизведении.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).\n @endtr
//!
//!          @tr SND_NODEFAULT   @td Не использовать звук по умолчанию, если нельзя проиграть
//!                                  указанный звуковой файл. @endtr
//!          @tr SND_NOSTOP      @td Если какой-либо звук уже проигрывается, не останавливать
//!                                  его для воспроизведения указанного звука. @endtr
//!          @tr SND_APPLICATION @td Проигрывать звук, используя программу, зарегистрированную
//!                                  для данного типа звуковых файлов. @endtr
//!          @endtable
//!
//! @return  Если операция была успешна - true, иначе - false.
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

bool txPlaySound // ЭТО НЕ ОШИБКА В TXLib.h! См. TXLib Help, Описания, Борьба с ошибками
                 (const char* filename = NULL, //!< Имя звукового файла.
                                               //!< Если NULL - останавливает звук.
                  DWORD mode = SND_ASYNC       //!< Режим воспроизведения
                  )
    {
$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;
$   if (!filename) mode = SND_PURGE;

$   return PlaySound (filename, NULL, mode) != 0;
    }

//=============================================================================
//
//! @name    Внутренние функции TXLib
//
//=============================================================================

bool _txCheck (const char msg[])
    {
$   if (txOK()) return true;

$   MessageBox (txWindow(), "Ошибка: Окно рисования не создано!    ", (msg && *msg)? msg : "TXLib", MB_ICONSTOP);

$   exit (1); //  Во избежание лишних вопросов о якобы ошибках в библиотеке приходится делать так. :(

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
//! @name    Функции основного окна (_txCanvas...)
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
//! @name    События основного окна (_txCanvas_On...)
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
        MessageBox (txWindow(), "Функция main() не завершена. "
                    "Программа все еще работает. Прервать?    ", name,
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
//! @name    Функции консольного окна (_txConsole...)
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
//! @name    Функции "виртуального холста" (графического буфера, _txBuffer...)
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
//! @name    Разное
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
//! @name    Функции низкоуровневой работы с диалоговыми окнами
//
//=============================================================================

//-----------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Создание шаблона диалога DLGTEMPLATE для функций
//!          DialogBoxIndirect() и DialogBoxIndirectParam().
//!
//!          Низкоуровневая работа с диалоговыми окнами. Для служебных целей.
//!
//! @return  Указатель на конец заполненной функцией части памяти.
//! @see     _tx_DLGTEMPLATE_Add(), txDialog::run(), CreateWindowEx()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Create (void* globalMem,     //!< Буфер памяти для заполнения
                              size_t bufsize,      //!< Размер буфера (0 - не проверяется)
                              DWORD style,         //!< Стиль диалогового окна
                              DWORD exStyle,       //!< Расширенный стиль
                              WORD controls,       //!< Количество контролов
                              short x,             //!< Координата верхнего левого угла
                              short y,             //!< Координата нижнего правого угла
                              short cx,            //!< Размер по X
                              short cy,            //!< Размер по Y
                              const char* caption, //!< Заголовок диалога
                              const char* font,    //!< Шрифт (должен быть выставлен DS_SETFONT в style)
                              WORD fontsize,       //!< Размер шрифта (должен быть выставлен DS_SETFONT в style)
                              HANDLE menu          //!< Меню диалогового окна, если есть
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
//! @brief   Добавление элемента окна (контрола) в шаблон диалога для функций
//!          DialogBoxIndirect() и DialogBoxIndirectParam().
//!
//!          Низкоуровневая работа с диалоговыми окнами. Для служебных целей.
//!
//! @return  Указатель на конец заполненной функцией части памяти.
//! @see     _tx_DLGTEMPLATE_Create(), txDialog::run()
//! @usage
//! @code
//!          [example]
//! @endcode
//-----------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr,   //!< Буфер памяти для заполнения
                           size_t bufsize,         //!< Размер буфера (0 - не проверяется)
                           DWORD style,            //!< Стиль контрола
                           DWORD exStyle,          //!< Расширенный стиль контрола
                           short x,                //!< Координата верхнего левого угла
                           short y,                //!< Координата нижнего правого угла
                           short cx,               //!< Размер по X
                           short cy,               //!< Размер по Y
                           WORD id,                //!< Идентификатор контрола
                           const char* wclass,     //!< Тип контрола (оконный класс)
                           const char* caption     //!< Текст контрола
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
//! @name    Диагностика
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
    MessageBox (NULL, str, fatal? "Фатальная ошибка" : "Ошибка в программе",
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
//! @name    Адаптация к компиляторам
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
//! @name    Документация по примерам
//
//=============================================================================

//! @include "Examples/Examples.dox"

//=============================================================================
//
// EOF
//
//=============================================================================
