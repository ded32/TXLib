//=============================================================================
//! \file       TXLib.h
//! \brief      Главный файл
//!
//! \mainpage
//!
//! \brief      Библиотека Тупого Художника (The Dumb Artist Library).
//!
//! \version    [Version 0.01 alpha, build 71]
//! \author     Copyright (C) Ded, 2005-08 (Ilya Dedinsky <ded@concord.ru>)
//! \date       2008
//!
//! \warning
//!           - <b>Это альфа-версия.
//!             Для использования требуется согласование с автором библиотеки.</b><br><br>
//!           - <b>При компиляции в Visual Studio может требоваться во время 
//!             выполнения: файл msvcrt.dll</b><br><br>
//!           - Если кодовая страница для консоли установлена неверно, русский текст
//!             может отображаться некорректно. Это проблема исключительно настройки 
//!             локального компьютера. Для исправления можно с помощью редактора 
//!             реестра в ветке "LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Nls\CodePage"
//!             изменить значение ключа "1252" на "c_1251.nls", либо запустить файл 
//!             "Wizard\CodePage.reg". После этих изменений потребуется перезагрузка.
//!             (<b>Важно:</b> Если Вы не до конца поняли эти советы, не следуйте им,
//!             и выводите русский текст на экран только с помощью функции \ref txTextOut).
//!
//! \par        Протестировано
//!           - Dev-CPP 4.9.9.2   + MinGW GCC 3.4.2
//!           - CodeBlocks 1.0rc2 + MinGW GCC 3.4.4
//!           - Microsoft Visual studio 6.0, 7.1 (2003), 8.0 (2005), 9.0 (2008)
//!           - Win 2003 SP1 R2, Win XP SP2/SP3 ru, Win 2000 SP4 ru
//!
//! \par        История изменений
//! - Build 71
//!          -# Соответствие стандартам MS SAL и режиму компиляции /analyze в MSVS 2005, 2008.
//!          -# Восстановлен механизм обновления по таймеру.
//!          -# Русский язык в консоли в _txThrow().
//! - Build 70
//!          -# Исправление ошибок _txCanvas_OnPaint (NULL DC).
//!          -# Упрощен механизм генерации сообщений для обновления экрана.
//!          -# Добавлена трассировка (\ref TX_TRACE).
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
//! \defgroup Drawing   Рисование
//! \defgroup Mouse     Поддержка мыши
//! \defgroup Dialogs   Диалоговые окна
//! \defgroup Service   Служебное
//! \defgroup Misc      Разное
//! \defgroup Technical Технические детали
//! \cond     Internal
//! \defgroup Internal  Реализация
//! \endcond
//=============================================================================

#ifndef __TXLIB_H
#define __TXLIB_H

//-----------------------------------------------------------------------------
// Адаптация к компиляторам и платформам
//-----------------------------------------------------------------------------
//! \cond Internal

#undef  UNICODE
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400 
#endif

#if defined (_MSC_VER)
#pragma warning (push, 4)
#pragma warning (disable: 4127)				 // conditional expression is constant
#pragma warning (disable: 4245)				 // 'argument': conversion from A to B, signed/unsigned mismatch
#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200) // MSVC 6
#pragma warning (disable: 4100)              // 'parameter': unreferenced formal parameter
#pragma warning (disable: 4511)              // 'class': copy constructor could not be generated
#pragma warning (disable: 4512)				 // 'class': assignment operator could not be generated
#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1400) // MSVC 8 (2005)
#define _TX_USE_SECURE_CRT
#else
#define  strncpy_s    strncpy				 // Not a MSVC 8 (2005)
#define _snprintf_s  _snprintf
#define _vsnprintf_s _vsnprintf
#endif

//! \endcond Internal
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdarg.h>
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

//=============================================================================
//! \name    Цвета
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Названия предопределенных цветов
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
    txBLACK        = RGB (  0,   0,   0), TX_BLACK         = txBLACK,        //!< Черный цвет
    txBLUE         = RGB (  0,   0, 128), TX_BLUE          = txBLUE,         //!< Синий цвет
    txGREEN        = RGB (  0, 128,   0), TX_GREEN         = txGREEN,        //!< Зеленый цвет
    txCYAN         = RGB (  0, 128, 128), TX_CYAN          = txCYAN,         //!< Бирюзовый цвет
    txRED          = RGB (128,   0,   0), TX_RED           = txRED,          //!< Красный цвет
    txMAGENTA      = RGB (128,   0, 128), TX_MAGENTA       = txMAGENTA,      //!< Малиновый цвет
    txBROWN        = RGB (128, 128,   0), TX_BROWN         = txBROWN,        //!< Коричневый цвет
    txORANGE       = RGB (255, 128,   0), TX_ORANGE        = txORANGE,       //!< Оранжевый цвет
    txGRAY         = RGB (160, 160, 160), TX_GRAY          = txGRAY,         //!< Серый цвет
    txDARKGRAY     = RGB (128, 128, 128), TX_DARKGRAY      = txDARKGRAY,     //!< Темно-серый цвет
    txLIGHTGRAY    = RGB (192, 192, 192), TX_LIGHTGRAY     = txLIGHTGRAY,    //!< Светло-серый цвет
    txLIGHTBLUE    = RGB (  0,   0, 255), TX_LIGHTBLUE     = txLIGHTBLUE,    //!< Светло-синий цвет
    txLIGHTGREEN   = RGB (  0, 255, 128), TX_LIGHTGREEN    = txLIGHTGREEN,   //!< Светло-зеленый цвет
    txLIGHTCYAN    = RGB (  0, 255, 255), TX_LIGHTCYAN     = txLIGHTCYAN,    //!< Светло-бирюзовый цвет
    txLIGHTRED     = RGB (255,   0, 128), TX_LIGHTRED      = txLIGHTRED,     //!< Светло-красный цвет
    txLIGHTMAGENTA = RGB (255,   0, 255), TX_LIGHTMAGENTA  = txLIGHTMAGENTA, //!< Светло-малиновый цвет
    txPINK         = RGB (255, 128, 255), TX_PINK          = txPINK,         //!< Розовый гламурный:)
    txYELLOW       = RGB (255, 255, 128), TX_YELLOW        = txYELLOW,       //!< Желтый цвет
    txWHITE        = RGB (255, 255, 255), TX_WHITE         = txWHITE,        //!< Белый цвет
    txTRANSPARENT  = 0xFFFFFFFF,          TX_TRANSPARENT   = txTRANSPARENT,  //!< Прозрачный цвет
    txNULL         = txTRANSPARENT,       TX_NULL          = txNULL,         //!< Прозрачный цвет

// Цветовые каналы (компоненты) - см. \ref txExtractColor(), \ref txRGB2HSL(), \ref txHSL2RGB()

    txHUE          = 0x04000000,          TX_HUE           = txHUE,          //!< Цветовой тон
    txSATURATION   = 0x05000000,          TX_SATURATION    = txSATURATION,   //!< Насыщенность
    txLIGHTNESS    = 0x06000000,          TX_LIGHTNESS     = txLIGHTNESS;    //!< Светлота

#ifdef FOR_DOXYGEN_ONLY
    }
#endif

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Создает (смешивает) цвет из трех базовых цветов (компонент).
//! \return  Созданный цвет в формате COLORREF.
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
COLORREF RGB (red,       //!< Количество красного цвета в интервале [0; 255]
              green,     //!< Количество зеленого цвета в интервале [0; 255]
              blue       //!< Количество синего цвета в интервале [0; 255]
              );
#endif

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Извлекает цветовую компоненту (цветовой канал) из смешанного цвета.
//! \return  Цветовая компонента, см. \ref txColors
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors
//! \examples 
//! \code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          Другие примеры см. в функциях AppearText(), AppearEarth() Примера 5 ("Циклы").
//! \endcode
//-----------------------------------------------------------------------------

int txExtractColor (COLORREF color,     //!< Смешанный цвет
                    COLORREF component  //!< Извлекаемая компонента, см. \ref txColors
                    );

//---------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Преобразует цвет из формата RGB в формат HSL.
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
//! \return  Созданный цвет в виде COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors
//! \examples 
//! \code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor   //!< Преобразуемый цвет в формате RGB
                    );

//---------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Преобразует цвет из формата HSL в формат RGB.
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
//! \return  Созданный цвет в виде COLORREF.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors
//! \see     RGB(), txExtractColor(), txRGB2HSL(), txHSL2RGB(), \ref txColors
//! \examples 
//! \code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor   //!< Преобразуемый цвет в формате HSL
                    );

//=============================================================================
//  \name    Инициализация и параметры рисования
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Создание окна рисования
//! \return  Успех операции
//! \see     txOk()
//! \examples 
//! \code
//!          txCreateWindow ( 800,  600);
//!          txCreateWindow (1024,  768, false);
//! \endcode
//-----------------------------------------------------------------------------

bool  txCreateWindow (double sizeX,        //!< Размер окна по горизонтали (в пикселях)
                      double sizeY,        //!< Размер окна по горизонтали (в пикселях)
                      bool centered = true //!< Центрирование окна на дисплее
                      );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Проверка правильности работы библиотеки
//! \return  Состояние библиотеки
//! \see     txCreateWindow()
//! \examples 
//! \code
//!          txCreateWindow (800, 600);
//!          if (!txOK()) 
//!              {
//!              MessageBox (NULL, "Не могу создать окно", "Ошибка!", MB_ICONSTOP);
//!              return;
//!              }
//! \endcode
//-----------------------------------------------------------------------------

bool  txOK();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает размер окна рисования в виде структуры POINT.
//! \return  Размер окна рисования в виде структуры POINT.
//! \see     txGetExtentX(), txGetExtentY()
//! \examples 
//! \code
//!          POINT size = txGetExtent();
//!          txLine (0, 0,      size.x, size.y);
//!          txLine (0, size.y, size.x, 0);
//! \endcode
//-----------------------------------------------------------------------------

POINT txGetExtent();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает ширину окна рисования.
//! \return  Ширина окна рисования.
//! \see     txGetExtent(), txGetExtentY()
//! \examples 
//! \code
//!          txSetTextAlign (TA_CENTER);
//!          txTextOut (txGetExtentX() / 2, 100, "O-o-o, you are in the middle now");
//! \endcode
//-----------------------------------------------------------------------------

int txGetExtentX();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает высоту окна рисования.
//! \return  Высота окна рисования.
//! \see     txGetExtent(), txGetExtentX()
//! \examples 
//! \code
//!          void DrawHouse (int height);
//!          ...
//!          DrawHouse (txGetExtentY() / 2);
//! \endcode
//-----------------------------------------------------------------------------

int txGetExtentY();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Установка параметров рисования по умолчанию.
//! 
//!          Параметры по умолчанию:\n
//!          - Линии - цвет белый (TX_WHITE), толщина 1
//!          - Заливка - цвет белый (TX_WHITE)
//!          - Шрифт - Системный шрифт, цвет белый (TX_WHITE)
//!          - Логическая растровая операция - копирование цвета (R2_COPYPEN)
//! 
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txSelectFont(), txSelectRegion(), txSetROP2()
//! \examples 
//! \code
//!          txSetDefaults();
//! \endcode
//-----------------------------------------------------------------------------

bool txSetDefaults();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет и толщину линий, цвет текста.
//! \return  Успех операции.
//! \see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples 
//! \code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! \endcode
//-----------------------------------------------------------------------------

bool txSetColor (COLORREF color,   //!< Цвет линий и текста, см. \ref txColors, RGB()
                 int thickness = 1 //!< Толщина линий
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет линий и текста.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()
//! \examples 
//! \code
//!          txColor (1.0, 0.5, 0.25);
//! \endcode
//-----------------------------------------------------------------------------

bool txColor (double red,     //!< Количество красного цвета в интервале [0; 1]
              double green,   //!< Количество зеленого цвета в интервале [0; 1]
              double blue     //!< Количество синего цвета в интервале [0; 1]
              );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает текущий цвет линий и текста.
//! \return  Текущий цвет линий и текста, см. \ref txColors, RGB()
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples 
//! \code
//!          COLORREF color = txGetColor();
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txGetColor();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет заполнения фигур.
//! \return  Успех операции.
//! \see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), \ref txColors, RGB()
//! \examples 
//! \code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! \endcode
//-----------------------------------------------------------------------------

bool txSetFillColor (COLORREF color  //!< Цвет заполнения, см. \ref txColors, RGB()
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий цвет заполнения фигур.
//! \return  Успех операции.
//! \see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor()
//! \examples 
//! \code
//!          txFillColor (1.0, 0.5, 0.25);
//! \endcode
//-----------------------------------------------------------------------------

bool txFillColor (double red,   //!< Количество красного цвета в интервале [0; 1]
                  double green, //!< Количество зеленого цвета в интервале [0; 1]
                  double blue   //!< Количество синего цвета в интервале [0; 1]
                  );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает текущий цвет заполнения фигур.
//! \return  Текущий цвет заполнения фигур, см. \ref txColors, RGB()
//! \see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), \ref txColors, RGB()
//! \examples 
//! \code
//!          COLORREF color = txGetFillColor();
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txGetFillColor();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает режим взаимодействия цветов при рисовании.
//!          
//!          При рисовании графическая библиотека может не просто красить пиксели
//!          на экране, а смешивать цвета экрана и текущие цвета линий и заполнения.
//!          
//!          Режимы взаимодействия цветов:
//!          
//!          \table
//!          \tr R2_COPYPEN     \td Пиксели = цвета кисти (самый нормальный режим :) \endtr
//!          \tr R2_NOTCOPYPEN  \td Пиксели = ~кисть\n \endtr
//!
//!          \tr R2_BLACK       \td Пиксели = черный цвет (цвет кисти игнорируется)    \endtr
//!          \tr R2_WHITE       \td Пиксели = белый  цвет (цвет кисти игнорируется)    \endtr
//!          \tr R2_NOT         \td Пиксели = ~пиксели    (цвет кисти игнорируется)\n  \endtr
//!
//!          \tr R2_XORPEN      \td Пиксели =    пиксели ^  кисть    \endtr
//!          \tr R2_NOTXORPEN   \td Пиксели = ~ (пиксели ^  кисть)\n \endtr
//!
//!          \tr R2_MASKPEN     \td Пиксели =    пиксели &  кисть    \endtr
//!          \tr R2_NOTMASKPEN  \td Пиксели = ~ (пиксели &  кисть)   \endtr
//!          \tr R2_MASKNOTPEN  \td Пиксели =    пиксели & ~кисть    \endtr
//!          \tr R2_MASKPENNOT  \td Пиксели =   ~пиксели &  кисть\n  \endtr
//!
//!          \tr R2_MERGEPEN    \td Пиксели =    пиксели |  кисть    \endtr
//!          \tr R2_NOTMERGEPEN \td Пиксели = ~ (пиксели |  кисть)   \endtr
//!          \tr R2_MERGENOTPEN \td Пиксели =    пиксели | ~кисть    \endtr
//!          \tr R2_MERGEPENNOT \td Пиксели =   ~пиксели |  кисть\n  \endtr
//!
//!          \tr R2_NOP         \td Пиксели вообще не изменяются.    \endtr
//!          \endtable
//!
//! \return  Предыдущий режим взаимодействия цветов, см. \ref txColors, RGB()
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txSetROP2 (R2_XORPEN);
//!          txSetROP2 (R2_COPYPEN);
//! \endcode
//-----------------------------------------------------------------------------

bool txSetROP2 (int mode         //!< Режим смешивания цветов
                );

//=============================================================================
//  \name    Фигуры
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Стирает холст текущим цветом заполнения.
//! \return  Успех операции.
//! \see     txSetFillColor(), txFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples 
//! \code
//!          txClear();
//! \endcode
//-----------------------------------------------------------------------------

bool  txClear();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует пиксель (точку на экране).
//! \return  Успех операции.
//! \see     txPixel(), txGetPixel(), \ref txColors, RGB()
//! \examples 
//! \code
//!          txSetPixel (100, 100, TX_RED);
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! \endcode
//-----------------------------------------------------------------------------

bool  txSetPixel (double x,      //!< Х-координата точки
                  double y,      //!< Y-координата точки
                  COLORREF color //!< Цвет точки, см. \ref txColors, RGB()
                  );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует пиксель (точку на экране).
//! \return  Успех операции.
//! \see     txSetPixel(), txGetPixel()
//! \examples 
//! \code
//!          txSetPixel (100, 100, 1.0, 0.5, 0.25);
//! \endcode
//-----------------------------------------------------------------------------

bool  txPixel (double x,         //!< Х-координата точки
               double y,         //!< Y-координата точки
               double red,       //!< Количество красного цвета в интервале [0; 1] 
               double green,     //!< Количество зеленого цвета в интервале [0; 1] 
               double blue       //!< Количество синего цвета в интервале [0; 1]   
               );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Возвращает текущий цвет точки (пикселя) на экране.
//! \return  Текущий цвет пикселя, см. \ref txColors, RGB()
//! \see     txSetPixel(), txPixel(), \ref txColors, RGB()
//! \examples 
//! \code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED) CarCrash (x, y);
//! \endcode
//-----------------------------------------------------------------------------

COLORREF txGetPixel (double x,  //!< Х-координата точки
                     double y   //!< Y-координата точки
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует линию.
//!          Цвет и толщина линии задается функцией txSetColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txLine (100, 200, 400, 500);
//! \endcode
//-----------------------------------------------------------------------------

bool  txLine (double x0,        //!< X-координата начальной точки
              double y0,        //!< Y-координата начальной точки
              double x1,        //!< X-координата конечной точки
              double y1         //!< Y-координата конечной точки
              );
              
//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует прямоугольник.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txRectangle (100, 200, 400, 500);
//! \endcode
//-----------------------------------------------------------------------------

bool  txRectangle (double x0,   //!< X-координата верхнего левого угла
                   double y0,   //!< Y-координата верхнего левого угла
                   double x1,   //!< X-координата нижнего правого угла
                   double y1    //!< Y-координата нижнего правого угла
                   );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует ломаную линию или многоугольник.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          POINT star[6] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}, {150, 300}};
//!          txPolygon (star, 6);
//! \endcode
//-----------------------------------------------------------------------------

bool  txPolygon (POINT* points, //!< Массив структур POINT с координатами точек
                 int npoints    //!< Количество точек в массиве
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует эллипс.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txEllipse (100, 100, 300, 200);
//! \endcode
//-----------------------------------------------------------------------------

bool  txEllipse (double x0,     //!< X-координата верхнего левого угла описанного прямоугольника
                 double y0,     //!< Y-координата верхнего левого угла описанного прямоугольника
                 double x1,     //!< X-координата нижнего правого угла описанного прямоугольника
                 double y1      //!< Y-координата нижнего правого угла описанного прямоугольника
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует окружность или круг.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txCircle (100, 100, 10);
//! \endcode
//-----------------------------------------------------------------------------

bool  txCircle (double x,       //!< Х-координата центра
                double y,       //!< Y-координата центра
                double r        //!< Радиус
                );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует дугу эллипса.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txArc (100, 100, 300, 200, 0, 180);
//! \endcode
//-----------------------------------------------------------------------------

bool  txArc (double x0,         //!< X-координата верхнего левого угла прямоугольника,          
                                //!<   описанного вокруг эллипса, содержащего дугу                
             double y0,         //!< Y-координата верхнего левого угла прямоугольника           
             double x1,         //!< X-координата нижнего правого угла прямоугольника           
             double y1,         //!< Y-координата нижнего правого угла прямоугольника           
             double startAngle, //!< Угол между направлением оси OX и началом дуги (в градусах) 
             double totalAngle  //!< Величина дуги (в градусах)                                 
             );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует сектор эллипса.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txPie (100, 100, 300, 200, 0, 180);
//! \endcode
//-----------------------------------------------------------------------------

bool  txPie (double x0,         //!< X-координата верхнего левого угла прямоугольника, 
                                //!<   описанного вокруг эллипса, содержащего сектор
             double y0,         //!< Y-координата верхнего левого угла прямоугольника
             double x1,         //!< X-координата нижнего правого угла прямоугольника
             double y1,         //!< Y-координата нижнего правого угла прямоугольника
             double startAngle, //!< Угол между направлением оси OX и началом сектора (в градусах) 
             double totalAngle  //!< Величина сектора (в градусах)                                 
             );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует хорду эллипса.
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txChord (100, 100, 300, 200, 0, 180);
//! \endcode
//-----------------------------------------------------------------------------

bool  txChord (double x0,         //!< X-координата верхнего левого угла прямоугольника,           
                                  //!<   описанного вокруг эллипса, содержащего хорду
               double y0,         //!< Y-координата верхнего левого угла прямоугольника            
               double x1,         //!< X-координата нижнего правого угла прямоугольника            
               double y1,         //!< Y-координата нижнего правого угла прямоугольника            
               double startAngle, //!< Угол между направлением оси OX и началом хорды (в градусах)  
               double totalAngle  //!< Величина хорды (в градусах)                                  
               );

//=============================================================================
//  \name    Работа с текстом
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Рисует текст.
//!          Цвет текста задается функцией txSetColor().
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples 
//! \code
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//! \endcode
//-----------------------------------------------------------------------------

bool  txTextOut (double x,         //!< Х-координата начальной точки текста
                 double y,         //!< Y-координата начальной точки текста
                 const char text[] //!< Текстовая строка
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Выбирает текущий шрифт.
//! \return  Успех операции.
//! \see     txTextOut()
//! \examples 
//! \code
//!          txSelectFont ("Comic Sans MS", 20);
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//!          txSelectFont ("Comic Sans MS", 20, 10, false, true, false, true);
//!          txTextOut (100, 200, "Но ее почему-то нет.");
//! \endcode
//-----------------------------------------------------------------------------

bool  txSelectFont (const char* name,       //!< Название шрифта
                    double sizeY,           //!< Высота букв (размер по Y) 
                    double sizeX = 0,       //!< Ширина букв 
                    int bold = FW_DONTCARE, //!< Жирность шрифта (от 0 до 1000)
                    bool italic = false,    //!< Курсив
                    bool underline = false, //!< Подчеркивание
                    bool strikeout = false  //!< Зачеркивание
                    );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Вычисляет размеры текстовой надписи.
//! \return  Размеры надписи в структуре SIZE.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples 
//! \code
//!          SIZE size = txGetTextExtent (text);
//!          txTextOut (100 + size.cx / 2, 200 + size.cy / 2, text);
//! \endcode
//-----------------------------------------------------------------------------

SIZE  txGetTextExtent (const char* text     //!< Текстовая строка
                      );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Вычисляет ширину текстовой надписи.
//! \return  Ширина надписи.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples 
//! \code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! \endcode
//-----------------------------------------------------------------------------

int txGetTextExtentX (const char* text      //!< Текстовая строка
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Вычисляет высоту текстовой надписи.
//! \return  Высота надписи.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples 
//! \code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! \endcode
//-----------------------------------------------------------------------------

int txGetTextExtentY (const char* text      //!< Текстовая строка
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущее выравнивание текста.
//!
//!          Флаги выравнивания:
//!
//!          \table
//!          \tr TA_BASELINE \td Точка (X,Y) определяет базовую линию текста. \endtr
//!          \tr TA_BOTTOM   \td Точка (X,Y) определяет нижнюю сторону описанного прямоугольника\n
//!                              (текст лежит выше этой точки).   \endtr
//!          \tr TA_TOP      \td Точка (X,Y) определяет верхнюю сторону описанного прямоугольника\n
//!                              (текст лежит ниже этой точки).\n \endtr
//!
//!          \tr TA_CENTER   \td Текст будет выровнен по горизонтали относительно точки (X,Y). \endtr
//!          \tr TA_LEFT     \td Точка (X,Y) определяет левую сторону описанного прямоугольника\n
//!                              (текст лежит правее этой точки). \endtr
//!          \tr TA_RIGHT    \td Точка (X,Y) определяет правую сторону описанного прямоугольника\n
//!                              (текст лежит левее этой точки).  \endtr
//!          \endtable
//!
//! \return  Успех операции.
//! \see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//! \examples 
//! \code
//!          txSetTextAlign (TA_RIGHT);
//!
//!          txSetTextAlign();
//! \endcode
//-----------------------------------------------------------------------------

bool txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE //!< Флаги выравнивания
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Ищет шрифт по его названию.
//! \return  Информация о шрифте в структуре LOGFONT. 
//!          Если шрифт не найден, возвращает NULL.
//! \see     txTextOut(), txSelectFont()
//! \examples 
//! \code
//!          if (txFontExist ("Comic Sans MS")) txSelectFont ("Comic Sans MS", 30);
//!          else                               txSelectFont ("Times", 30);
//! \endcode
//-----------------------------------------------------------------------------

LOGFONT* txFontExist (const char* name      //!< Название шрифта
                     );

//=============================================================================
//  \name    Разное
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Заливает произвольный контур текущим цветом заполнения.
//!          Цвет заполнения задается функцией txSetFillColor().
//!          Не рекомендуется для применения - довольно медленно работает.
//!
//!          Режимы заливки:
//!
//!          FLOODFILLSURFACE - Заливать область, куазанную цветом color.\n
//!          FLOODFILLBORDER  - Заливать до границы, указанной цветом color.
//!
//! \return  Успех операции.
//! \see     txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//! \examples 
//! \code
//!          txFloodFill (100, 100);
//! \endcode
//-----------------------------------------------------------------------------

bool txFloodFill (double x,                        //!< Х-координата точки начала заливки
                  double y,                        //!< Y-координата точки начала заливки
                  COLORREF color = TX_TRANSPARENT, //!< Цвет заливаемой области (TX_TRANSPARENT - автоопределение)
                  DWORD mode = FLOODFILLSURFACE    //!< Режим заливки (FLOODFILLSURFACE - заливка однородного фона)
                  );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Устанавливает текущий прямоугольный регион отсечения.
//!          Всё, что оказывается вне региона отсечения, не рисуется.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples 
//! \code
//!          txSelectRegion (100, 100, 300, 400);
//! \endcode
//-----------------------------------------------------------------------------

bool txSelectRegion (double x0,   //!< X-координата верхнего левого угла
                     double y0,   //!< Y-координата верхнего левого угла
                     double x1,   //!< X-координата нижнего правого угла
                     double y1    //!< Y-координата нижнего правого угла
                     );

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Устанавливает текущий объект GDI.
//! \return  Успех операции.
//! \see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//!          txSelectFont(), txSelectRegion()
//! \examples 
//! \code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! \endcode
//-----------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj     //!< Дескриптор объекта GDI
                     );              

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Блокирует обновление изображения окна, во избежание мигания.
//!
//! \warning Избегайте блокирования на долгое время. Это может привести к
//!          дефектам изображения в окне. Если требуется задержка, то используйте
//!          txSleep() вместо обычной функции Sleep().
//!
//! \return  Значение счетчика блокировки (если 0, то рисование разблокировано).
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

int txBegin();

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Разблокирует обновление окна, заблокированное функцией txBegin().
//!
//! \warning Если txBegin() вызывалась несколько раз, то для снятия блокировки
//!          требуется столько же раз вызвать txEnd().
//!
//! \return  Значение счетчика блокировки (если 0, то рисование разблокировано).
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

int txEnd();

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Блокирует или разблокирует обновление изображения в окне.
//!
//!          В отличие от txBegin() и txEnd(), позволяет явно установить или
//!          снять блокировку.
//!
//! \warning Избегайте блокирования на долгое время. Это может привести к
//!          дефектам изображения в окне. Если требуется задержка, то используйте
//!          txSleep() вместо обычной функции Sleep().
//!
//! \return  Предыдущее состояние режима обновления.
//! \see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(), txLock(), txUnlock(), txGDI()
//! \examples 
//! \code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! \endcode
//-----------------------------------------------------------------------------

bool txUpdateWindow (bool update = true //!< Режим обновления (false - запретить обновление)
                     );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Блокирует или разблокирует рисование мигающего курсора в окне.
//! \return  Предыдущее значение блокировки.
//! \see     txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//! \examples 
//! \code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! \endcode
//-----------------------------------------------------------------------------

bool txTextCursor (bool blink = true    //!< false - блокировать мигающий курсор
                   );

//=============================================================================
//  \name    Рисование в памяти (на "виртуальном экране") и загрузка изображений
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Создает дополнительный холст (контекст рисования, Device Context, DC) в памяти.
//! \return  Дескриптор (обозначение) созданного холста (контекста рисования).
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//!
//! \remarks Созданный контекст затем будет нужно удалить при помощи txDeleteDC().
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HDC txCreateCompatibleDC (double sizeX,            //!< Ширина холста
                          double sizeY,            //!< Высота холста
                          HBITMAP bitmap = NULL    //!< Bitmap associated with DC
                          );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Загружает из файла изображение в формате BMP.
//! \return  Дескриптор созданного контекста рисования в памяти, с загруженным изображением.
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(), txTransparentBlt(), 
//!
//! \remarks Изображение загружается в создаваемый контекст рисования (холст),
//!          который затем будет нужно удалить при помощи txDeleteDC().
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HDC txLoadImage (LPCTSTR name      //!< Имя файла с изображением
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Уничтожает холст (контекст рисования, DC) в памяти.
//! \return  Успех операции.
//! \see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txDeleteDC (HDC dc            //!< Контекст рисования для уничтожения
                 );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Копирует изображение с одного холста (контекста рисования, DC) на другой.
//!
//!          Режимы копирования:
//!
//!          \table
//!          \tr SRCCOPY     \td Просто копирует :) - самый распространенный режим\n \endtr
//!
//!          \tr BLACKNESS   \td Заполняет холст-приемник черным цветом (холст-источник игнорируется). \endtr
//!          \tr WHITENESS   \td Заполняет холст-приемник белым цветом (холст-источник игнорируется). \endtr
//!          \tr DSTINVERT   \td Инвертирует цвета на холсте-приемнике (холст-источник игнорируется). \endtr
//!          \tr PATCOPY     \td Копирует цвет текущей кисти холста-приемника.\n \endtr
//!
//!          \tr MERGECOPY   \td Приемник =   приемник & цвет текущей кисти источника. \endtr
//!          \tr MERGEPAINT  \td Приемник = ~ приемник | источник \endtr
//!          \tr NOTSRCCOPY  \td Приемник = ~ источник \endtr
//!          \tr NOTSRCERASE \td Приемник = ~ (приемник | источник) \endtr
//!          \tr PATINVERT   \td Приемник =  кисть приемника ^  приемник \endtr
//!          \tr PATPAINT    \td Приемник = (кисть приемника | ~источник) | приемник \endtr
//!          \tr SRCAND      \td Приемник =  приемник & источник \endtr
//!          \tr SRCERASE    \td Приемник = ~приемник & источник \endtr
//!          \tr SRCINVERT   \td Приемник =  приемник ^ источник \endtr
//!          \tr SRCPAINT    \td Приемник =  приемник | источник \endtr
//!          \endtable
//!
//! \return  Успех операции.
//! \see     txAlphaBlend(), txTransparentBlt(), txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), \ref txColors, RGB()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txBitBlt (HDC dest,           //!< Контекст назначения (куда копировать)
               double xDest,       //!< Х-координата верхнего левого угла изображения-приемника
               double yDest,       //!< Y-координата верхнего левого угла изображения-приемника
               double width,       //!< Ширина копируемого изображения
               double height,      //!< Высота копируемого изображения
               HDC src,            //!< Контекст источника (откуда копировать)
               double xSrc,        //!< Х-координата верхнего левого угла изображения-источника
               double ySrc,        //!< Y-координата верхнего левого угла изображения-источника
               DWORD rOp = SRCCOPY //!< Растровая операция копирования
               );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//! \brief   с учетом прозрачности.
//! \return  Успех операции.
//! \see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txTransparentBlt (HDC dest,                 //!< Контекст назначения (куда копировать)                   
                       double xDest,             //!< Х-координата верхнего левого угла изображения-приемника 
                       double yDest,             //!< Y-координата верхнего левого угла изображения-приемника 
                       double width,             //!< Ширина копируемого изображения
                       double height,            //!< Высота копируемого изображения
                       HDC src,                  //!< Контекст источника (откуда копировать)                  
                       double xSrc,              //!< Х-координата верхнего левого угла изображения-источника 
                       double ySrc,              //!< Y-координата верхнего левого угла изображения-источника 
                       COLORREF transColor = TX_BLACK //!< Цвет, который будет считаться прозрачным
                       );

//-----------------------------------------------------------------------------
//! \ingroup Drawing
//! \brief   Копирует изображение с одного холста (контекста рисования, DC) на другой
//! \brief   с учетом прозрачности.
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
//! \return  Успех операции.
//! \see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txAlphaBlend (HDC dest,                     //!< Контекст назначения (куда копировать)                   
                   double xDest,                 //!< Х-координата верхнего левого угла изображения-приемника 
                   double yDest,                 //!< Y-координата верхнего левого угла изображения-приемника 
                   double width,                 //!< Ширина копируемого изображения
                   double height,                //!< Высота копируемого изображения
                   HDC src,                      //!< Контекст источника (откуда копировать)                  
                   double xSrc,                  //!< Х-координата верхнего левого угла изображения-источника 
                   double ySrc,                  //!< Y-координата верхнего левого угла изображения-источника 
                   double alpha = 1.0            //!< Общая прозрачность изображения, в дополнение к альфа-каналу.\n
                                                 //!<   (0 - все прозрачно, 1 - использовать только альфа-канал)
                   );

//=============================================================================
//
//  \name    Работа с мышью
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   Возвращает Х-Координату Мыши!
//! \return  Х-координата мыши.
//! \see     txMouseX(), txMouseY(), txMouseButtons()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

double txMouseX();                        

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   Возвращает Y-Координату Мыши!
//! \return  Y-координата мыши.
//! \see     txMouseX(), txMouseY(), txMouseButtons()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

double txMouseY();

//-----------------------------------------------------------------------------
//! \ingroup Mouse
//! \brief   Возвращает состояние Кнопок Мыши!
//!
//!          В возвращаемом значении выставленный в единицу 1-й (младший)
//!          бит означает нажатую левую Кнопку Мыши, 2-й - правую, 3-й - 
//!          среднюю. Например, возвращенное число 5 (двоичное 101) означает
//!          одновременное нажатие средней и левой Кнопок, но не правой Кнопки.
//!
//! \return  Состояние Кнопок Мыши!
//! \see     txMouseX(), txMouseY(), txMouseButtons()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

int txMouseButtons();

//=============================================================================
//
//  \name    Работа с диалоговыми окнами
//! \ingroup Dialogs
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \brief   Ввод строки в отдельном окне.
//! \return  Введенная строка (статическая переменная функции).
//! \warning Возвращаемая строка обновляется при каждом вызове функции!
//!          Для сохранения ее необходимо копировать при помощи <i>strcpy()</i>.
//! \see     txDialog
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

const char* txInputBox (const char* text,        //!< Текст с вопросом
                        const char* caption,     //!< Заголовок окна
                        const char* input = NULL //!< Значение строки по умолчанию
                        );

//-----------------------------------------------------------------------------
//! \brief   Базовый класс для диалоговых окон.
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
//! \see     txDialog::setLayout(), txDialog::dialogProc(), txDialog::Layout,
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

struct txDialog
    {

//-----------------------------------------------------------------------------
//! \brief   Константы для задания типа контрола.
//!
//!          Вместо констант можно использовать названия оконных классов,
//!          преобразованные к типу txDialog::CONTROL.
//!
//! \see     txDialog::Layout, txDialog::setLayout()
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
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
//! \brief   Структура для описания элемента диалогового окна (контрола)
//!
//!          Массив таких структур задает описание макета диалогового окна.
//!          Это описание похоже на задание диалога в ресурсном скрипте (.rc):
//!
//!           - Нулевой элемент описывает диалоговое окно в целом
//!           - Остальные элементы описывают контролы
//!           - Последний элемент - txDialog::END или {NULL}
//!
//! \see     txDialog::setLayout(), txDialog::dialogBox(), txDialog::dialogProc()
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
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
//! \brief   Конструктор.
//! \see     txDialog::txDialog (const txDialog::Layout*)
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    public:    
    txDialog ();

//-----------------------------------------------------------------------------
//! \brief   Конструктор.
//! \see     txDialog::Layout, txDialog::setLayout()
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    txDialog (const Layout* layout               //!< Макет диалогового окна
             );

//-----------------------------------------------------------------------------
//! \brief   Устанавливает текущий макет диалогового окна.
//! \return  Предыдущий макет.
//! \see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    const Layout* setLayout (const Layout* layout //!< Макет диалогового окна
                            );

//-----------------------------------------------------------------------------
//! \brief   Функция обработки сообщений диалогового окна.
//!
//!          Эту функцию надо переопределить для обработки событий окна,
//!          или построить ее с помощью макросов TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! \return  В большинстве случаев false, детальнее см. DialogProc
//!          в <a href=msdn.com>MSDN</a>.
//! \see     txDialog::dialogBox()
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd,           //!< Дескриптор 
                            UINT _msg,           //!< Номер сообщения
                            WPARAM _wParam,      //!< 1-й параметр сообщения (WORD)
                            LPARAM _lParam       //!< 2-й параметр сообщения (DWORD)
                            );

//-----------------------------------------------------------------------------
//! \brief   Запускает диалоговое окно.
//! \return  Значение, указанное в функции EndDialog().\n 
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была 
//!          запущена txDialog::dialogBox().
//! \see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
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
//! \brief   Запускает диалоговое окно.
//! \return  Значение, указанное в функции EndDialog().\n 
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была 
//!          запущена txDialog::dialogBox().
//! \see     txDialog::dialogProc()
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
//-----------------------------------------------------------------------------

    INT_PTR dialogBox (WORD resource  //!< Идентификатор диалогового ресурса
                       );

//-----------------------------------------------------------------------------
//! \brief   Закрытые конструктор копирования и оператор присваивания.
//-----------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);
        
//-----------------------------------------------------------------------------
//! Настоящая диалоговая функция (т.к. должна быть статической).

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//-----------------------------------------------------------------------------
//! Текущий макет диалога.

    private:
    const Layout* layout_;
    };

//-----------------------------------------------------------------------------
//! \brief   Заголовок карты сообщений (Message map).
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, 
//! \see     txDialog::dialogProc(), txDialog
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
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
//! \brief   Заголовок обработчика сообщения (Message handler) карты сообщений.
//! \param   id Идентификатор сообщения
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, 
//! \see     txDialog::dialogProc(), txDialog
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
//! \endcode
//! \hideinitializer
//-----------------------------------------------------------------------------

#define TX_HANDLE( id )																\
            break;																	\
            case (id):

//-----------------------------------------------------------------------------
//! \brief   Начало карты команд (Command map) в карте сообщений.
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, 
//! \see     txDialog::dialogProc(), txDialog
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
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
//! \brief   Завершитель карты сообщений.
//! \see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, 
//! \see     txDialog::dialogProc(), txDialog
//! \examples 
//! \code
//!          Cм. реализацию функции txInputBox().
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
//! \brief   Создание шаблона диалога DLGTEMPLATE для функций
//!          DialogBoxIndirect() и DialogBoxIndirectParam().
//!
//!          Низкоуровневая работа с диалоговыми окнами. Для служебных целей.
//!
//! \return  Указатель на конец заполненной функцией части памяти.
//! \see     _tx_DLGTEMPLATE_Add(), txDialog::run(), CreateWindowEx()
//! \examples 
//! \code
//!          [example]
//! \endcode
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
                              HANDLE menu = NULL   //!< Меню диалогового окна, если есть
                              );

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Добавление элемента окна (контрола) в шаблон диалога для функций
//!          DialogBoxIndirect() и DialogBoxIndirectParam().
//!
//!          Низкоуровневая работа с диалоговыми окнами. Для служебных целей.
//!
//! \return  Указатель на конец заполненной функцией части памяти.
//! \see     _tx_DLGTEMPLATE_Create(), txDialog::run()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr,   //!< Буфер памяти для заполнения
                           size_t bufsize,         //!< Размер буфера (0 - не проверяется)
                           DWORD style,            //!< Стиль контрола
                           DWORD exStyle,          //!< Расширенный стиль
                           short x,                //!< Координата верхнего левого угла
                           short y,                //!< Координата нижнего правого угла
                           short cx,               //!< Размер по X
                           short cy,               //!< Размер по Y
                           WORD id,                //!< Идентификатор контрола
                           const char* wclass,     //!< Тип контрола (оконный класс)
                           const char* caption     //!< Текст контрола
                           );

//=============================================================================
//
// \name     Back-hole (I hope, not an ass-hole:) of the library)
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Возвращает дескриптор контекста рисования холста
//! \return  Дескриптор контекста рисования холста
//! \see     txWindow(), txLock(), txUnlock(), txGDI()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HDC  txDC();

//-----------------------------------------------------------------------------
//! \ingroup Service
//! \brief   Возвращает дескриптор окна холста
//! \return  Дескриптор окна холста
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

HWND txWindow();

//-----------------------------------------------------------------------------
//! \ingroup Service 
//! \brief   Блокировка холста (поверхности рисования).
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
//!          блокировать нельзя.
//!
//!          txLock()/txUnlock() - низкоуровневый механизм, он отличается от
//!          высокоуровневого механизма txBegin()/txEnd()/txUpdateWindow(),
//!          который не приостанавливает поток, а просто отключает операции
//!          по обновлению окна.
//!
//! \return  Состояние блокировки
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txLock (bool wait = true          //!< Ожидать конца перерисовки окна 
                                       //!< вспомогательным потоком
            );

//-----------------------------------------------------------------------------
//! \ingroup Service 
//! \brief   Разблокировка холста
//! \return  Состояние блокировки
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txUnlock();

//! \cond    Internal
template <typename T> inline T txUnlock (T value);
//! \endcond Internal

//-----------------------------------------------------------------------------
//! \ingroup Service 
//! \brief   Вызов функции Win32 GDI с автоматической блокировкой и разблокировкой
//! \return  Значение, возвращаемое вызываемой функцией GDI.
//! \param   cmd Команда GDI (возможно, возвращающая значение)
//! \note    Если в вызове функции GDI используются запятые, то используйте 
//!          двойные скобки, чтобы получился один параметр, так как txGDI() все-таки макрос: 
//!          txGDI <b>((</b> Rectangle (txDC(), x1, y1, x2, y2) <b>))</b>;
//! \see     txDC(), txLock(), txUnlock(), txGDI()
//! \hideinitializer
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define txGDI( cmd ) txUnlock ((txLock(), (cmd)))

//-----------------------------------------------------------------------------
//! \ingroup Technical
//! \brief   Возвращает строку с информацией о текущей версии библиотеки.
//! \return  Строка с информацией о текущей версии библиотеки.
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

const char* txVersion();

//=============================================================================
//
// \name     Misc functions
//
//=============================================================================

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Вычисление размера массива
//! \param   arr Имя массива
//! \return  Размер массива
//! \warning Определение массива вместе с его размером должно быть доступно
//!          в месте использования sizearr().
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define sizearr( arr )   ( sizeof (arr) / sizeof (arr)[0] )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Проверка, находится ли параметр х внутри замкнутого интервала [a; b]
//! \return  Если a <= x && x <= b, то истина, если нет - ложь
//! \hideinitializer
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

template <typename T>
inline bool In (T x, //!< Проверяемый параметр
                T a, //!< Левая граница (включительно)
                T b  //!< Правая граница (включительно)
                ) 
    { 
    return a <= x && x <= b; 
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Проверка, находится ли точка pt внутри прямоугольника rect
//! \return  Результат проверки
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

inline bool In (const COORD& pt,       //!< Проверяемая точка
                const SMALL_RECT& rect //!< Прямоугольник
                )
    {
    return In (pt.X, rect.Left, rect.Right) && In (pt.Y, rect.Top, rect.Bottom);
    }

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Возвращает максимальное из двух чисел
//! \param   a Одно из чисел :) 
//! \param   b Другое из чисел :)
//! \return  Максимальное из двух чисел a и b
//! \hideinitializer
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define MAX( a, b )      ( (a) > (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Возвращает минимальное из двух чисел
//! \param   a Одно из чисел :) 
//! \param   b Другое из чисел :)
//! \return  Минимальное из двух чисел a и b
//! \hideinitializer
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define MIN( a, b )      ( (a) < (b) ? (a) : (b) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Генератор случайных чисел
//! \param   range Правая граница диапазона (не включая саму границу).
//! \return  Случайное целое число в диапазоне [0; range).\n
//!          Вы еще помните, что означают разные скобочки в обозначении интервалов? :)
//! \hideinitializer
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

#define random( range )  ( rand() % (range) )

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Задерживает выполнение программы на определенное время.
//!
//!          Во время задержки обновление изображения в окне всегда 
//!          автоматически разблокируется.
//!
//! \return  Состояние блокировки обновления окна.
//! \see     txUpdateWindow()
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txSleep (int time   //!< Задержка в миллисекундах
              );

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Воспроизводит звуковой файл.
//!
//!          Режимы воспроизведения:
//!
//!          \table
//!          \tr SND_ASYNC       \td Звук проигрывается одновременно с работой программы.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL). \endtr
//!          \tr SND_SYNC        \td Выполнение программы приостанавливается до окончания 
//!                                  воспроизведения звука. \endtr
//!          \tr SND_LOOP        \td Зацикливать звук при воспроизведении.\n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).\n \endtr
//!
//!          \tr SND_NODEFAULT   \td Не использовать звук по умолчанию, если нельзя проиграть 
//!                                  указанный звуковой файл. \endtr
//!          \tr SND_NOSTOP      \td Если какой-либо звук уже проигрывается, не останавливать
//!                                  его для воспроизведения указанного звука. \endtr
//!          \tr SND_APPLICATION \td Проигрывать звук, используя программу, зарегистрированную
//!                                  для данного типа звуковых файлов. \endtr
//!          \endtable
//!
//! \return  Успех операции.
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

bool txPlaySound (const char* filename = NULL, //!< Имя звукового файла.
                                               //!< Если NULL - останавливает звук.
                  DWORD mode = SND_ASYNC       //!< Режим воспроизведения
                  );

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Выводит развернутое пользовательское диагностическое сообщение.
//! \return  всегда false
//! \see     TX_NEEDED(), _
//! \examples 
//! \code
//!          TX_THROW ("Ошибка открытия файла '%s'" _ fileName);
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
bool TX_THROW (msg                             //!< Сообщение в формате printf().\n
                                               //!< Можно использовать %d, %s и т.д., при этом
                                               //!< части сообщения <b>разделяются символом 
                                               //!< подчеркивания "_" а не запятой.</b>
                                               //!<
                                               //!< msg может быть NULL.
         );
#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Выводит имя файла и номер строки, где находится вызов TX_PRINT_HERE().
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
//! \brief   Макрос, позволяющий передать переменное число параметров в какой-либо другой макрос.
//! \note    <b>Символ подчеркивания просто переопределяется в запятую.</b>
//! \see     TX_THROW()
//! \examples 
//! \code
//!          TX_THROW ("Ошибка чтения строки %d файла '%s'" _ lineNum _ fileName);
//! \endcode
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define _ ,
#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Выводит диагностическое сообщение в случае неуспеха операции.
//! \brief   Используется, если лень писать if() :)
//! \note    <b>Предполагается, что операция в случае неуспеха возвращает 0 или false.</b>
//! \note    <b>При компиляции в режиме Release (или если определен NDEBUG) превращается
//!          в пустой оператор.</b>
//! \return  Всегда false
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
//! \brief   Строка, соответствующая имени текущей функции, или имя исходного файла и
//! \brief   номер строки, если определение имени функции не поддерживается компилятором.
//-----------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
const char __TX_FUNCTION__[];
#endif

//-----------------------------------------------------------------------------
//! \ingroup Misc
//! \brief   Число Пи
//! \return  Число Пи
//! \examples 
//! \code
//!          [example]
//! \endcode
//-----------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//=============================================================================
// Настроечные константы
//=============================================================================

//! \ingroup Technical
//! \brief   Интервал мигания курсора консоли (мс)

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

//! \ingroup Technical
//! \brief   Шрифт консоли

const char   _TX_CONSOLE_FONT[]           = "Lucida Console";

//! \ingroup Technical
//! \brief   Цвет шрифта консоли

const COLORREF _TX_CONSOLE_COLOR          = txLIGHTGRAY;

//! \ingroup Technical
//! \brief   Таймаут операций ожидания (мс)

const int    _TX_TIMEOUT                  = 1000;

//! \ingroup Technical
//! \brief   Интервал обновления холста (мс)

const int    _TX_WINDOW_UPDATE_INTERVAL   = 10;

//! \ingroup Technical
//! \brief   Не скрывать автоматически консольное окно
//!
//!          Задается перед включением TXLib.h в программу.

#ifdef FOR_DOXYGEN_ONLY
#define      _TX_NO_HIDE_CONSOLE
#endif

//! \ingroup Technical
//! \brief   Имя файла и номер строки, константа времени компиляции.

#ifdef FOR_DOXYGEN_ONLY
#define      __TX_FILELINE__                __FILE__ ( __LINE__ )
#endif

//! \ingroup Technical
//! \brief   Включить внутреннюю трассировку выполнения библиотеки.
//!
//!          Трассировка идет через макрос TX_TRACE, который подставляется перед
//!          каждым оператором (statement). По умолчанию трассировка выключена.
//!
//!          Задается перед включением TXLib.h в программу.

#ifdef FOR_DOXYGEN_ONLY
#define      _TX_TRACE
#endif

//! \ingroup Technical
//! \brief   Макрос для трассировки.
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(),
//!          ее вывод можно перехватить утилитами-логгерами, например, WinTail.
//!
//!          Задается перед включением TXLib.h в программу.

#ifdef FOR_DOXYGEN_ONLY
#define      TX_TRACE                       OutputDebugString (__TX_FILELINE__ ": ");
#endif

//! \ingroup Technical
//! \brief   Текущая версия библиотеки.
//!          Эта константа автоматически обновляется при обновлении версии.
//! \see     txVersion()

#define      _TX_VERSION                    "[Version 0.01 alpha, build 71]"

//=============================================================================
//
// Реализация
//
//=============================================================================
//! \cond    Internal
//@{

namespace Internal
{

//-----------------------------------------------------------------------------

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
bool _txSelect (HGDIOBJ obj, HDC dc = txDC());

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
// Диагностика
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

#define TX_THROW( msg )   _txThrow (__FILE__, __LINE__, __FUNCTION__, (DWORD)(-1), msg)
#define TX_PRINT_HERE()   printf ("%s (%d) %s(): Here... :)\n", __FILE__, __LINE__, __FUNCTION__)

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
// Импорт внешних библиотек
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
//! \cond Namespaces
}; // namespace Win32
using namespace Win32;
//! \endcond Namespaces

// </tears>
//=============================================================================
// Глобальные данные
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

int              _txMouseX             = 0;
int              _txMouseY             = 0;
int              _txMouseButtons       = 0;

//=============================================================================
// Идентификаторы меню
//=============================================================================

#define _txIDM_ABOUT        40000
#define _txIDM_CONSOLE      40001

//-----------------------------------------------------------------------------

//! \cond Namespaces
}; // namespace Internal
using namespace Internal;
//! \endcond Namespaces

//=============================================================================
// Реализация функций интерфейса
//=============================================================================

bool txCreateWindow (double sizeX, double sizeY, bool centered)
    {
$   if (txOK()) return false;
$   return _txInitialize ((int)sizeX, (int)sizeY, centered);
    }

//-----------------------------------------------------------------------------

inline
bool txOK()
    {
$   return _txConsole_OK() &&
           _txCanvas_OK();
    }

//-----------------------------------------------------------------------------

const char* txVersion()
    {
$   return _TX_VERSION;
    }

//-----------------------------------------------------------------------------

inline 
HDC txDC()
    { 
$   return _txCanvas_BackBuf[0]; 
    }

//-----------------------------------------------------------------------------

inline 
HWND txWindow()       
    { 
$   return _txCanvas_Wnd;        
    }

//-----------------------------------------------------------------------------

POINT txGetExtent()
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   RECT r = {0};
$   GetClientRect (txWindow(), &r);
$   POINT size = { r.right - r.left, r.bottom - r.top };
$   return size;
    }

inline int txGetExtentX() { $ return txGetExtent().x; }
inline int txGetExtentY() { $ return txGetExtent().y; }

//-----------------------------------------------------------------------------

bool txClear()
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   POINT size = txGetExtent();

$   return txGDI ((Win32::PatBlt (txDC(), 0, 0, size.x, size.y, PATCOPY) != 0));
    }

//-----------------------------------------------------------------------------

bool txSetColor (COLORREF color, int thickness)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), thickness, color)) &&
            txGDI   ((Win32::SetTextColor (txDC(), color) != 0));
    }

//-----------------------------------------------------------------------------

bool txColor (double r, double g, double b)
    {
$   if (r > 1) r = 1; if (r < 0) r = 0;
$   if (g > 1) g = 1; if (g < 0) g = 0;
$   if (b > 1) b = 1; if (b < 0) b = 0;
$   return txSetColor (RGB (r*255, g*255, b*255));
    }

//-----------------------------------------------------------------------------

COLORREF txGetColor()
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_PEN))); obj TX_NEEDED;

$   char buf [MAX (sizeof (LOGPEN), sizeof (EXTLOGPEN))] = {0};

$   int size = GetObject (obj, 0, NULL);
$   GetObject (obj, sizeof (buf), buf) TX_NEEDED;

$   return (size == sizeof (LOGPEN))? ((LOGPEN*)buf)->lopnColor : ((EXTLOGPEN*)buf)->elpColor;
    }

//-----------------------------------------------------------------------------

bool txSetFillColor (COLORREF color)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txSelect ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                                 Win32::CreateSolidBrush (color));
    }

//-----------------------------------------------------------------------------

bool txFillColor (double r, double g, double b)
    {
$   if (r > 1) r = 1; if (r < 0) r = 0;
$   if (g > 1) g = 1; if (g < 0) g = 0;
$   if (b > 1) b = 1; if (b < 0) b = 0;
$   return txSetFillColor (RGB (r*255, g*255, b*255));
    }

//-----------------------------------------------------------------------------

COLORREF txGetFillColor()
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); obj TX_NEEDED;

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) TX_NEEDED;

$   return buf.lbColor;
    }

//-----------------------------------------------------------------------------

int txExtractColor (COLORREF color, COLORREF component)
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

COLORREF txRGB2HSL (COLORREF color)
    {
$   int r = txExtractColor (color, TX_RED),
        g = txExtractColor (color, TX_GREEN),
        b = txExtractColor (color, TX_BLUE);

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

$   if (dm != 0)
        {
$       is = dm / ((sm <= 1)? sm : (2-sm));

$       double cr = (m1 - ir) / dm,
               cg = (m1 - ig) / dm,
               cb = (m1 - ib) / dm;

$       if (ir == m1) ih =     cb - cg;
$       if (ig == m1) ih = 2 + cr - cb;
$       if (ib == m1) ih = 4 + cg - cr;
        }

$   return RGB ((int)(ih >= 0? ih*60 : ih*60 + 360), (int)(is*255), (int)(il*255));
    }

//---------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF color)
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

$   int h = txExtractColor (color, TX_HUE),
        s = txExtractColor (color, TX_SATURATION),
        l = txExtractColor (color, TX_LIGHTNESS);

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

bool txSetPixel (double x, double y, COLORREF color)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::SetPixel (txDC(), (int)x, (int)y, color)));

$   RECT r = { (int)x, (int)y, (int)x, (int)y };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool txSetPixel (double x, double y, double r, double g, double b)
    {
$   if (r > 1) r = 1; if (r < 0) r = 0;
$   if (g > 1) g = 1; if (g < 0) g = 0;
$   if (b > 1) b = 1; if (b < 0) b = 0;
$   return txSetPixel (x, y, RGB (r*255, g*255, b*255));
    }

//-----------------------------------------------------------------------------

COLORREF txGetPixel (double x, double y)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::GetPixel (txDC(), (int)x, (int)y)));
    }

//-----------------------------------------------------------------------------

bool txLine (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::MoveToEx (txDC(), (int)x0, (int)y0, NULL))) TX_NEEDED;
$   txGDI ((Win32::LineTo   (txDC(), (int)x1, (int)y1)))       TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool txRectangle (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::Rectangle (txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool txPolygon (POINT* points, int npoints)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::Polygon (txDC(), points, npoints) != 0));
    }

//-----------------------------------------------------------------------------

bool txEllipse (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::Ellipse (txDC(), (int)x0, (int)y0, (int)x1, (int)y1))) TX_NEEDED;

$   RECT r = { (int)x0, (int)y0, (int)x1, (int)y1 };
$   InvalidateRect (txWindow(), &r, false) TX_NEEDED;
$   return true;
    }

//-----------------------------------------------------------------------------

bool txCircle (double x, double y, double r)
    {
$   return txEllipse (x-r, y-r, x+r, y+r);
    }

//-----------------------------------------------------------------------------

bool txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Arc (txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                        center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                        center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------

bool txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Pie (txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                        center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                        center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------

bool txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   double start = startAngle * txPI / 180, end = (startAngle + totalAngle) * txPI / 180;
$   POINT center = { (int)((x0+x1)/2), (int)((y0+y1)/2) };

$   return txGDI ((Win32::Chord (txDC(), (int)x0, (int)y0, (int)x1, (int)y1,
                                          center.x + (int)(100*cos (start)), center.y - (int)(100*sin (start)),
                                          center.x + (int)(100*cos (end)),   center.y - (int)(100*sin (end))) != 0));
    }

//-----------------------------------------------------------------------------

bool txTextOut (double x, double y, const char text[])
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

SIZE txGetTextExtent (const char* text)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, (int) strlen (text), &size))) TX_NEEDED;

$   return size;
    }

inline int txGetTextExtentX (const char* text) { $ return txGetTextExtent (text) . cx; }
inline int txGetTextExtentY (const char* text) { $ return txGetTextExtent (text) . cy; }

//-----------------------------------------------------------------------------

bool txSelectFont (const char* name, double sizeY, double sizeX,
                   int bold, bool italic, bool underline, bool strikeout)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   _txSelect (txFontExist (name)? CreateFont ((int)sizeY, (int)(sizeX? sizeX : sizeY/3), 0, 0,
                                               bold, italic, underline, strikeout,
                                               DEFAULT_CHARSET,
                                               OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                               DEFAULT_QUALITY, FIXED_PITCH, name)
                                   :
                                   GetStockObject (SYSTEM_FIXED_FONT));
$   return true;
    }

//-----------------------------------------------------------------------------

bool txSetTextAlign (unsigned align)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   txGDI ((Win32::SetTextAlign (txDC(), align)));
$   return true;
    }

//-----------------------------------------------------------------------------

LOGFONT* txFontExist (const char* name)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   static LOGFONT font = {0};
$   font.lfCharSet = DEFAULT_CHARSET;
$   strncpy_s (font.lfFaceName, name, sizeof (font.lfFaceName) - 1);

    struct enumFonts
        {
        static int CALLBACK Proc (const LOGFONT* font, const TEXTMETRIC*, DWORD, LPARAM data)
            {
$           assert (font); assert (data);
$           return _strnicmp (font->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
            }
        };

$   return txGDI ((Win32::EnumFontFamiliesEx (txDC(), &font, enumFonts::Proc, (LPARAM)&font, 0) == 0? &font : NULL));
    }

//-----------------------------------------------------------------------------

bool txFloodFill (double x, double y, COLORREF color, DWORD mode)
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y);

$   return txGDI ((Win32::ExtFloodFill (txDC(), (int)x, (int)y, color, mode) != 0));
    }

//-----------------------------------------------------------------------------

bool txSetROP2 (int mode)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::SetROP2 (txDC(), mode) != 0));
    }

//-----------------------------------------------------------------------------

HDC txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap)
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   POINT size = { (int)sizeX, (int)sizeY };
$   HDC dc = _txBuffer_Create (txWindow(), &size, bitmap); dc TX_NEEDED;
$   return dc;
    }

//-----------------------------------------------------------------------------

HDC txLoadImage (LPCTSTR name)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HBITMAP image = (HBITMAP) LoadImage (NULL, name, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
$   if (!image) return NULL;

$   HDC dc = txCreateCompatibleDC (0, 0, image);
    
$   return dc;
    }

//-----------------------------------------------------------------------------

bool txDeleteDC (HDC dc)
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   return _txBuffer_Delete (dc);
    }

//-----------------------------------------------------------------------------

bool txBitBlt (HDC dest, double xDest, double yDest, double width, double height,
               HDC src,  double xSrc,  double ySrc,  DWORD rOp)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return txGDI ((Win32::BitBlt (dest, (int)xDest, (int)yDest, (int)width, (int)height,
                                  src,  (int)xSrc,  (int)ySrc, rOp) != 0));
    }

//-----------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, double destX, double destY, double sizeX, double sizeY,
                       HDC src,  double srcX,  double srcY,  COLORREF transColor)
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   if (!TransparentBlt) return false;

$   return Win32::TransparentBlt (dest, (int)destX, (int)destY, (int)sizeX, (int)sizeY,
                                  src,  (int)srcX,  (int)srcY,  (int)sizeX, (int)sizeY, transColor) != 0;
    }

//-----------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, double destX, double destY, double sizeX, double sizeY,
                   HDC src,  double srcX,  double srcY,  double alpha)
    {
$   _txCheck (__FUNCTION__); assert (txOK());
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

bool txSelectRegion (double x0, double y0, double x1, double y1)
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   HRGN rgn = CreateRectRgn ((int)x0, (int)y0, (int)x1, (int)y1);
$   return txSelectObject (rgn);
    }

//-----------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj)
    {
$   _txCheck (__FUNCTION__); assert (txOK());
$   return _txSelect (obj);
    }

//-----------------------------------------------------------------------------

inline 
int txBegin()
    {             
$   _txCanvas_SetLockRefresh (_txCanvas_LockRefresh + 1);
$   return _txCanvas_LockRefresh;
    }

//-----------------------------------------------------------------------------

inline
int txEnd()
    {
$   _txCanvas_SetLockRefresh (_txCanvas_LockRefresh - 1);
$   return _txCanvas_LockRefresh;
    }

//-----------------------------------------------------------------------------

inline
bool txUpdateWindow (bool update)
    {
$   return _txCanvas_SetLockRefresh (update? 0 : 1) != 0;
    }

//-----------------------------------------------------------------------------

inline
bool txSleep (int time)
    {
$   int old = _txCanvas_SetLockRefresh (0);

$   Sleep (time);

$   _txCanvas_SetLockRefresh (old);
$   return old != 0;
    }

//-----------------------------------------------------------------------------

bool txTextCursor (bool mode)
    {
$   bool old = _txConsole_CursorMode;

$   _txConsole_CursorMode = mode;

$   return old;
    }

//-----------------------------------------------------------------------------

inline 
bool txLock (bool wait)
    {
$   if (wait) { return    EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { return TryEnterCriticalSection (&_txCanvas_LockBackBuf) != 0;  }
    }

//-----------------------------------------------------------------------------

inline 
bool txUnlock()
    {
$   LeaveCriticalSection (&_txCanvas_LockBackBuf);
$   return true;
    }

//-----------------------------------------------------------------------------

template <typename T> inline 
T txUnlock (T value)
    { 
$   txUnlock(); 
$   return value; 
    }

//-----------------------------------------------------------------------------

inline double  txMouseX()       { $ return _txMouseX;       }
inline double  txMouseY()       { $ return _txMouseY;       }
inline int     txMouseButtons() { $ return _txMouseButtons; }

//-----------------------------------------------------------------------------

bool txPlaySound (const char* filename, DWORD mode)
    {
$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = mode & ~SND_SYNC | SND_ASYNC;
$   if (!filename) mode = SND_PURGE;

$   return PlaySound (filename, NULL, mode) != 0;
    }

//-----------------------------------------------------------------------------

bool txSetDefaults()
    {
$   _txCheck (__FUNCTION__); assert (txOK());

$   return _txCanvas_SetDefaults() &&
           _txConsole_SetDefaults();
    }

//=============================================================================
// Работа с диалоговыми окнами
//=============================================================================

const char* txInputBox (const char* text, const char* caption, const char* input) 
    {
$   char name[256] = ""; GetModuleFileName (NULL, name, sizeof (name) - 1) TX_NEEDED;

$   if (!text)    text    = "Введите строку:";
$   if (!caption) caption = name;
$   if (!input)   input   = "";

    #define ID_TEXT   101
    #define ID_INPUT  102
    
$   txDialog::Layout layout[] = 
        {{ txDialog::DIALOG,   caption,   0,          0,  0, 240, 85                                                    },
         { txDialog::STATIC,   text,      ID_TEXT,   10, 10, 150, 40, SS_LEFT                                           },
         { txDialog::EDIT,     input,     ID_INPUT,  10, 60, 220, 15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP },
         { txDialog::BUTTON,   "&OK",     IDOK,     180, 10,  50, 15, BS_DEFPUSHBUTTON                     | WS_TABSTOP },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL, 180, 30,  50, 15, BS_PUSHBUTTON                        | WS_TABSTOP },
         { txDialog::END }};

    struct inputDlg : txDialog
        {
        char str [1024];

        inputDlg() 
            {
$           memset (str, 0, sizeof (str) - 1);
            }    

        TX_BEGIN_MESSAGE_MAP()
            TX_COMMAND_MAP
                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT, str, sizeof (str) - 1);
        TX_END_MESSAGE_MAP
        };

    #undef ID_TEXT
    #undef ID_INPUT

$   static inputDlg dlg;

$   dlg.dialogBox (layout);
    
$   return dlg.str;
    }

//=============================================================================
// Методы класса txDialog
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
            }
        }

$   return this__-> dialogProc (wnd, msg, wParam, lParam);
    }

//=============================================================================
// Функции низкоуровневой работы с диалоговыми окнами
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

//! \cond Namespaces
namespace Internal {
//! \endcond Namespaces

//=============================================================================
//
// Детали реализации
//
//=============================================================================

//=============================================================================
// Инициализация/проверка/завершение
//=============================================================================

bool _txInitialize (int sizeX, int sizeY, bool centered)
    {
$   atexit (_txOnExit);
    
$   _txExit    = false;
$   _txRunning = false;
    
$   txUpdateWindow (false);
    
$   InitializeCriticalSection (&_txCanvas_LockBackBuf);
    
$   _txConsole_Attach();

$// _wsetlocale (LC_ALL, L"Russian_Russia.ACP");
$   SetConsoleCP (1251);
$   SetConsoleOutputCP (1251);
    
$   POINT size = { sizeX, sizeY };
$   if (centered) { size.x *= -1; size.y *= -1; }
    
$   DWORD id = 0;
$   _txCanvas_Thread = CreateThread (NULL, 0, _txCanvas_ThreadProc, &size, 0, &id);
$   _txCanvas_Thread || TX_THROW ("Cannot create _txCanvas_Thread: CreateThread() failed");
$   _txWaitFor (_txCanvas_OK());
$   _txCanvas_OK() || TX_THROW ("Cannot create canvas");
    
$   txSetDefaults();
    
$   txUpdateWindow (true);
    
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txCheck (const char msg[])
    {
$   if (txOK()) return true;

$   MessageBox (NULL, "Ошибка: Окно рисования не создано!    ", (msg && *msg)? msg : "Ошибка программы", MB_ICONSTOP);

//  Во избежание лишних вопросов о якобы ошибках в библиотеке приходится делать так. :(

$   exit (1);  
//  return false;
    }

//-----------------------------------------------------------------------------

void _txOnExit()
    {
$   _txRunning = false;

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
// Установка значений по умолчанию
//=============================================================================

bool _txCanvas_SetDefaults()
    {
$   assert (txOK());
    
$   txLock();
    
$   RECT r = {0};
$   GetClientRect (_txConsole_Wnd, &r) TX_NEEDED;
$   SIZE size = { r.right - r.left, r.bottom - r.top };
    
$   _txSelect (GetStockObject (WHITE_PEN))   TX_NEEDED;
$   _txSelect (GetStockObject (WHITE_BRUSH)) TX_NEEDED;
$   _txSelect (CreateFont (size.cy/25, size.cx/80, 0, 0,
                         FW_REGULAR, FALSE, FALSE, FALSE,
                         DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                         DEFAULT_QUALITY, DEFAULT_PITCH, _TX_CONSOLE_FONT)) TX_NEEDED;
    
$   Win32::SetTextColor (txDC(), RGB (255, 255, 255));
$   Win32::SetBkMode    (txDC(), TRANSPARENT) TX_NEEDED;
    
$   Win32::SetROP2      (txDC(), R2_COPYPEN) TX_NEEDED;
    
$   txUnlock();
$   return true;
    }

//-----------------------------------------------------------------------------

bool _txConsole_SetDefaults()
    {
$   assert (txOK());
    
$   txLock();
    
$   HDC dc = _txCanvas_BackBuf[1];
    
$   CONSOLE_SCREEN_BUFFER_INFO con = {0};
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
    
$   _txSelect (txFontExist (_TX_CONSOLE_FONT)? CreateFont (fontSize.y * 8/10, fontSize.x, 0, 0,
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
$   return true;
    }

//=============================================================================
// Функции основного окна (_txCanvas...)
//=============================================================================

DWORD WINAPI _txCanvas_ThreadProc (LPVOID data)
    {
$   assert (data);
    
$   _txCanvas_CreateWindow (*(POINT*) data);
$   _txCanvas_Wnd || TX_THROW ("Cannot create canvas: _txCanvas_CreateWindow() failed");
    
$   MSG msg = {0};
    
$   while (_txReturn1())
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
                
$       if (_txCanvas_Wnd)
            {
$           InvalidateRect (_txCanvas_Wnd, NULL, false);
$           UpdateWindow   (_txCanvas_Wnd);
            }

$       Sleep (_TX_WINDOW_UPDATE_INTERVAL);
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
// События основного окна (_txCanvas_On...)
//=============================================================================

bool _txCanvas_OnCreate (HWND wnd)
    {
$   _txRunning = true;

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); _txCanvas_BackBuf[0] TX_NEEDED;
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); _txCanvas_BackBuf[1] TX_NEEDED;

    #if !_TX_USE_CONSOLE_THREAD
$   SetTimer (wnd, _txCanvas_Timer, _TX_WINDOW_UPDATE_INTERVAL, NULL) TX_NEEDED;
    #endif

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
        MessageBox (_txCanvas_Wnd, "Функция main() не завершена. "
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
    
$   if (!_txCanvas_LockRefresh)
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

$   _txMouseX       = LOWORD (coords);
$   _txMouseY       = HIWORD (coords);
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
        }

    if (msg == WM_SYSCOMMAND) switch (wpar)
        {
        case _txIDM_ABOUT:    $ _txCanvas_OnCmdAbout   (wnd, wpar);   break;
        case _txIDM_CONSOLE:  $ _txCanvas_OnCmdConsole (wnd, wpar);   break;
        }

    if (msg == WM_KEYDOWN && 
        wpar == VK_F12 && GetKeyState (VK_CONTROL) && GetKeyState (VK_SHIFT) && GetKeyState (VK_MENU))
        { 
$       _txCanvas_OnCmdAbout (wnd, wpar);
        }

    return DefWindowProc (wnd, msg, wpar, lpar);
    }

//=============================================================================
// Функции консольного окна (_txConsole...)
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
    
$   CONSOLE_SCREEN_BUFFER_INFO con = {0};
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
$   LARGE_INTEGER time = {0};
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
// Функции графического буфера (_txBuffer...)
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
   
$   txLock();
   
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

bool _txSelect (HGDIOBJ obj, HDC dc)
    {
$   txLock();
   
$   obj = Win32::SelectObject (dc, obj); obj TX_NEEDED;
$   if (obj) Win32::DeleteObject (obj);
   
$   txUnlock();
   
$   return obj != NULL;
    }

//=============================================================================
// Импорт библиотечных функций
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
// Диагностика
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
    MessageBox (NULL, str, fatal? "Фатальная ошибка" : "Ошибка программы",
                MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

    if (fatal) abort();

    va_end (arg);
    return false;
    }

//@}
//! \endcond Internal
//=============================================================================
//! \cond Namespaces

} // namespace Internal
} // namespace TX
} // anonymous namespace

using namespace TX;
using namespace TX::Internal::Win32;

//! \endcond Namespaces
//=============================================================================

//------------------------------------------------------------------------
// Адаптация к компиляторам
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
//  \name    Примеры использования
//
//=============================================================================

//-----------------------------------------------------------------------------
/*! \page    Tutorial_1st Пример: Простейший

    \section Tutorial_1st_01 Структура простейшей программы

    Простейшая программа на С (или С++) состоит из двух частей: раздела 
    подключения библиотек и главной функции программы. Рассмотрим пример, 
    в котором рисуется на экране простой рисунок.

    \section Tutorial_1st_02 Раздел подключения библиотек 

    Директивы (команды) подключения библиотек находятся обычно в начале
    файла программы и выглядят обычно так:

    \code
    #include <stdlib.h>
    #include "TXLib.h"
    \endcode

    \c Stdlib.h и \c TXLib.h - файлы библиотек, которые подключаются к вашей 
    программе. После этого вы можете использовать команды, функции и переменные,
    объявленные в этих файлах. Больше, чем нужно, библиотек подключать не стоит,
    хотя это и не вредно. Когда используется много библиотек, раздел может быть
    очень большим.

    \section Tutorial_1st_03 Главная функция программы

    Программа на С (С++) состоит из функций. Функция - это описание каких-либо 
    действий с заданным именем (названием).

    Например,

    \code
    int main()                     
        {                               
        txCreateWindow (800, 600);      
        txLine (320, 290, 320, 220);  
        return 0;
        }
    \endcode

    Главная функция - это функция, с которой начинается исполнение программы.
    Ее имя - \c main(). Скобки показывают, что речь идет именно о функции, т.е.,
    об описании каких-то действий. Для того, чтобы функция начала работу, ее
    нужно \a вызвать. Функцию \c main() вызывает сама операционная система 
    компьютера. Слово \c int означает, что \c main() в конце работы передаст
    тому, кто ее вызывал (операционной системе), некое целое число. Это число 
    для функции main() означает код завершения нашей программы. Если он равен 0,
    то работа программы считается успешной.

    Действия, записанные в функции, заключаются в фигурные скобки \c { и \c }.
    Они обозначают начало и конец функции.

    Внутри функции записаны вызовы команд, которые что-то рисуют на экране.
    Между командами, там, где это логически необходимо, стоят пустые строки,
    отделяющие одни части программы от других. Это способствует большей 
    понятности программы. Пустая строка в программировании соответствует 
    началу абзаца текста в русском языке.

    Для понимания программы и того, чтобы в ней не появлялись ошибки, очень
    важно, чтобы в нужных местах в ней стояли пробелы. Обычно их ставят до
    открывающих круглых скобок, после запятых, до и после знаков операций.
    Наличие пробелов делает программу приятной на вид, и предотвращает
    напряжение глаз при работе с компьютером. Работа с плохо оформленным
    текстом программы может нанести вред глазам, снизить зрение.

    Пример плохо написанной программы:

    \code
    #include "TXLib.h"
    int   main(){                           
    txCreateWindow(800,600);  // По-моему, про зрение все ясно. :)          
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

    Для задания положения рисуемых фигур используется координатная система,
    у которой верхний левый угол расположен слева-вверху, а ось OY смотрит
    вниз. Это несколько непривычно, но деваться некуда. :) Например, команда

    \code
    txLine (320, 290, 320, 220);
    \endcode

    проводит линию из точки x=320 и у=290 в точку с x=320 и y=220.

    Каждая команда заканчивается точкой с запятой. Это - аналог точки в русском 
    языке. Точка с запятой ставится в конце каждого \a законченного действия
    или объявления. Например, в строке с \c txCreateWindow (800, 600) точка с
    запятой ставится, т.к. в этой строке "закончена мысль" о том, что надо
    создать окно для рисования. В строке с <tt>int main()</tt> - не ставится,
    т.к. описание функции \c main() не закончено (на самом деле, оно там только
    начато).

    Если в программе используются строки, они заключаются в двойные кавычки,
    например:

    \code
    txTextOut (240, 400, "Hello, world!");
    \endcode

    Если в программе присутствут числа с дробной частью, то эта часть 
    отделяется от целой части точкой, а не запятой, как в русском языке.

    \section Tutorial_1st_04 Распространенные ошибки

    В простых программах ошибки бывают двух видов:

    - Ошибки записи (орфография, пунктуация) - их называют синтаксическими 
      ошибками <i>(syntax error).</i> Они происходят до запуска программы, 
      на стадии перевода программы в машинный код (стадии компиляции). Поэтому
      их называют ошибками времени компиляции. Исполняемый файл при этом не 
      создается и программа не запускается.

    - Логические ошибки - они происходят после запуска программы, при этом
      при компиляции ошибок нет (иногда имеются предупреждения, \a warnings).
      Их называют ошибками времени исполнения.

    Практически все синтаксические ошибки на этой стадии происходят из-за 
    невнимательности. Распространенные синтаксические ошибки:

    - Путают ключевые слова, названия библиотек и команд: 
      \code
      #iclude "TX lib.h"
      in maim()
      tx Line (10, 10, 20, 20)
      \endcode

    - Путают большие и маленькие буквы: 
      \code
      txcircle (100, 100, 10)
      \endcode

    - Не ставят скобки: 
      \code
      int main
      \endcode

    - Забывают запятые: 
      \code
      txСircle (100 100 10)
      \endcode

    - Забывают точки с запятой:
      \code
      txSelectFont ("Times", 60)
      \endcode

    - Забывают или путают кавычки:
      \code
      txSelectFont (Times, 60)
      txSelectFont ('Times', 60)
      \endcode

    - Ставят лишние точки с запятой:
      \code
      int main();
      \endcode

    - Указвают дробную часть числа через запятую:
      \code
      3,1415
      \endcode

    - Забывают фигурные скобки:
      \code
      int main()                     
      txCreateWindow (800, 600);      
      txLine (320, 290, 320, 220);  
      return 0;
      \endcode

    - Забывают писать открывающие или закрывающие скобки, или пишут лишние,
      отчего появляются непарные скобки, или путают виды скобок:
      \code
      int main()                     
          {                               
          txCreateWindow (800, 600);      

          txLine (320, 290, 320, 220;  // Не закрыта круглая скобка
          return 0;
          }
      \endcode
      \code
      int main()                     
      {                               
      txCreateWindow {800, 600};   // Фигурные скобки вместо круглых
      return 0;
      }

      txLine (320, 290, 320, 220;  // Команда за пределами функции main()
      }                            // Лишняя скобка
      \endcode

    - Помещают команды за пределы фигурных скобок
      \code
      int main()                     
      {                               
      txCreateWindow (800, 600);      
      return 0;
      }

      txLine (320, 290, 320, 220); // Команда за пределами функции main() 
      \endcode

    Бывают и логические ошибки. Например, мы не выбрали нужный цвет рисования
    (по умолчанию он белый), или нарисовали одну фигуру поверх другой, и она 
    закрыла предыдущую, или задали неверные координаты. Эти ошибки появляются
    после запуска программы. Их легко понять, если выполнить на листе бумаги 
    все команды одну за другой, в том порядке, в котором они заданы в программе.

    \section Tutorial_1st_Code Законченный пример
    \include "Examples\TXEx01.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_1stEx Пример: Улучшенный :)

    \section Tutorial_1stEx_Code Законченный пример
    \include "Examples\TXEx02.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_Functions Пример: Функции

    \section Tutorial_Functions_Code Законченный пример
    \include "Examples\TXEx03.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_Parameters Пример: Функции с параметрами

    \section Tutorial_Parameters_Code Законченный пример
    \include "Examples\TXEx04.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_While Пример: Циклы

    \section Tutorial_While_Code Законченный пример
    \include "Examples\TXEx05.cpp"
*/
//-----------------------------------------------------------------------------
/*! \page Tutorial_For Пример: Циклы (2)

    \section Tutorial_For_Code Законченный пример
    \include "Examples\TXEx06.cpp"
*/

//=============================================================================
// EOF
//=============================================================================
