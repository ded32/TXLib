//{===========================================================================
//           Библиотека DirectTX - DirectTX.cpp
//           Copyright (C) Nikita Uvarov, 7 класс
//}===========================================================================

/**\file     DirectTX.cpp
 *
 * \brief    DirectTX - расширение TXLib'а, призванное помочь программистам
 *           в написании быстрых прогамм на уровне отдельных пикселей.
 *
 *           DirectTX использует прямую запись в память, что обеспечивает огромную
 *           скорость на маленьких окнах.
 *
 *           В основном скорость зависит от размеров окна, а не от сложности графики,
 *           что позволяет выводит достаточно красивые изображения на приемлимой скорости.
 *
 * \par      Предостережение
 *        -# Многие функции работают совсем не так, как в TXLib'е, или на их
 *           их использование наложены ограничения. Ознакомьтесь с данным файлом помощи
 *           перед их использованием.
 *
 * \version  [v 0.2]
 *
 * \author   Copyright (C) Nikita Uvarov, 7 класс
 * \date     2009
 *
 * \defgroup DirectTX DirectTX: Движок (Н. Уваров)
 */

#ifndef __TXLIB_H
#include "TXLib.h"
#endif

#if !defined (_TX_VER) || (_TX_VER < 0x172a0093)
#error Must use TXLib.h version >= 1.72 build >= 93 to compile this. -- Ded
#endif

enum DirectTXInfo
    {
    DTX_RENDEREDIN,
    DTX_FPS
    };

struct DirectTXColor
    {
    char    red, green, blue;

            DirectTXColor();
            DirectTXColor (int r, int g, int b);
            DirectTXColor (float r, float g, float b);
            DirectTXColor (COLORREF c);

            operator COLORREF();

    DirectTXColor Mix (const DirectTXColor& c, float howManyOfThatColor);
    };

/** \ingroup DirectTX
 *  \brief   Создаёт окно DirectTX. Не является оболочкой, поэтому вместо
 *           txCreateWindow нужно обязательно использовать эту функцию.
 *
 *  \param   width   Ширина окна
 *  \param   height  Высота окна
 *  \param   header  Заголовок окна. Может не указываться, в таком случае у окна будет
 *                   стандартное для TXLib имя (имя файла из которого запущена программа).
 *
 *  \par     Пример
 *  \code
 *           DirectTXCreateWindow(800, 600, "Window with title");
 *  \endcode
 *  \code
 *           DirectTXCreateWindow(800, 600); // Окно со стандартным заголовком
 *  \endcode
 */

void DirectTXCreateWindow (int width, int height, const char* header = 0);

/** \ingroup DirectTX
 *  \brief   Копирует пиксели из буфера DirectTX в буфер TXLib.
 *
 *  \warning
 *        -# Если не вызвать эту функцию, результат всех остальных DirectTX-функций на
 *           на экране не отобразится.
 *        -# Функция не вызывает обновления окна, поэтому желательно использовать ее
 *           между функциями \ref DirectTXBegin и \ref DirectTXEnd. В противном
 *           случае графика будет прерывистой или вообще может отсутствовать.
 */

void DirectTXFlush();

/** \ingroup DirectTX
 *  \brief   Копирует пиксели из буфера TXLib в буфер DirectTX.
 */

void DirectTXFlushBack();

/** \ingroup DirectTX
 *  \brief   Функция блокирует обновление окна - аналогична txBegin.
 */

void DirectTXBegin();

/** \ingroup DirectTX
 *  \brief   Функция возобнавляет обновление окна - аналогична txEnd.
 */

void DirectTXEnd();

/** \ingroup DirectTX
 *  \brief   Функция возвращает индекс пикселя в массиве пикселей.
 *
 *  \param   x       X-координата пикселя
 *  \param   y       Y-координата пикселя
 *  \param   offset  Смещение. 0 означает красный цвет, 1 - зелёный, 2 - синий.
 *                   Является необязательным параметром (по умолчанию 0).
 *
 *  \return  Индекс пикселя в массиве пикселей.
 *
 *  \note    Во избежании ручной работы с пикселями, эта функция не рекомендуется для
 *           применения. Вместо неё используйте \ref DirectTXPutPixel и
 *           \ref DirectTXGetPixel.
 */

int  DirectTXGetPixelIndex (int x, int y, int offset = 0);

/** \ingroup DirectTX
 *  \brief   Устанавливает значения цвета пикселя.
 *
 *  \param   x  X-координата пикселя
 *  \param   y  Y-координата пикселя
 *  \param   c  Цвет пикселя
 *
 *  \note    Цвет пикселя устанавливается в буфере и не копируется на экран до
 *           вызова \ref DirectTXFlush.
 */

void DirectTXPutPixel (int x, int y, const DirectTXColor& c);

/** \ingroup DirectTX
 *  \brief   Устанавливает значения цвета пикселя.
 *
 *  \param   x  X-координата пикселя
 *  \param   y  Y-координата пикселя
 *  \param   r  Красная компонента цвета пикселя.
 *  \param   g  Зелёная компонента цвета пикселя.
 *  \param   b  Синяя компонента цвета пикселя.
 *
 *  \note    Цвет пикселя устанавливается в буфере и не копируется на экран до
 *           вызова \ref DirectTXFlush.
 */

void DirectTXPutPixel (int x, int y, int r, int g, int b);

/** \ingroup DirectTX
 *  \brief   Возвращает цвет пикселя.
 *
 *  \param   x  X-координата пикселя
 *  \param   y  Y-координата пикселя
 *
 *  \note    Цвет пикселя возвращается из буфера DirectTX, а цвет пикселя в буфере и
 *           на экране могут не совпадать (если рисовать TXLib-овскими функциями). Эту
 *           функцию имеет смысл использовать только если большая часть графики рисуется
 *           с помощью DirectTX.
 */

DirectTXColor DirectTXGetPixel (int x, int y);

/** \ingroup DirectTX
 *  \brief   Устанавливает цвет линий.
 *
 *  \param   c  Цвет линий и текста
 *
 *  \note    Цвет линий DirectTX хранится отдельно от цвета линий TXLib и не
 *           обязан с ним совпадать. Все DirectTX-овские функции используют
 *           цвет DirectTX, за исключением \ref DirectTXTextOut.
 */

void DirectTXSetColor (const DirectTXColor& c);

/** \ingroup DirectTX
 *  \brief   Устанавливает цвет заливки.
 *
 *  \param   c  Цвет заливки
 *
 *  \note    Цвет заливки DirectTX хранится отдельно от цвета заливки TXLib и не
 *           обязан с ним совпадать. Все DirectTX-овские функции используют
 *           цвет DirectTX, за исключением \ref DirectTXTextOut.
 */

void DirectTXSetFillColor (const DirectTXColor& c);

/** \ingroup DirectTX
 *  \brief   Рисует прямоугольник. Работает быстрее, чем txRectangle.
 *
 *  \param   x0  X-координата первого угла прямоугольника
 *  \param   y0  Y-координата первого угла прямоугольника
 *  \param   x1  X-координата второго угла прямоугольника
 *  \param   y1  Y-координата второго угла прямоугольника
 */

void DirectTXDrawRectangle (int x0, int y0, int x1, int y1);

/** \ingroup DirectTX
 *  \brief   Рисует линию. Работает быстрее, чем txLine.
 *
 *  \param   x0  X-координата начала линии
 *  \param   y0  Y-координата начала линии
 *  \param   x1  X-координата конца  линии
 *  \param   y1  Y-координата конца  линии
 */

void DirectTXDrawLine (int x0, int y0, int x1, int y1);

/** \ingroup DirectTX
 *  \brief   Рисует круг или окружность. Работает МЕДЛЕННЕЕ, чем txCircle. Тем не
 *           менее, во избежания проблем с раздельными буферами, рекомендуется
 *           использовать DirectTX-овские функции вместо TXLib-овских.
 *
 *  \param   xc  X-координата центра круга
 *  \param   yc  X-координата центра круга
 *  \param   r   Радиус круга
 */

void DirectTXDrawCircle (int xc, int yc, int r);

/** \ingroup DirectTX
 *  \brief   Выводит данные о производительности программы. См. параметры.
 *
 *  \param   what  Какие данные выводить. Может принимать значения DTX_FPS (выводить
 *                 количество кадров в секунду) или DTX_RENDEREDIN (количество
 *                 миллисекунд, за которое был отрисован последний кадр).
 */

void DirectTXDrawInfo (DirectTXInfo what);

/** \ingroup DirectTX
 *  \brief   Выводит данные о производительности программы. Смотри параметры
 *
 *  \param   fps  Какие данные выводить. Может принимать значения true (выводить
 *                количество кадров в секунду) или false (количество миллисекунд,
 *                за которое был отрисован последний кадр).
 */

void DirectTXDrawFPS (bool fps = true);

/** \ingroup DirectTX
 *  \brief   Возвращает состояние клавиши (нажата или нет).
 *
 *  \param   keyCode  Код клавиши
 *
 *  \par     Преимущества перед GetAsyncKeyState и getch:
 *        -# Реагирует на нажатия клавиш вне окна, в отличие от getch.
 *        -# Не вызывает эффекта "залипания клавиш". (<b>Не путать со sticky keys:</b>
 *           здесь это означает, что если клавиша была нажата, а функция вызвана через
 *           несколько секунд после этого, то функция вернёт false.)
 */

bool DirectTXKeyPressed (char keyCode);

/** \ingroup DirectTX
 *  \brief   Возвращает состояние левой кнопки мыши. Является оболочкой для
 *           txMouseButtons.
 *
 *  \return  Состояние левой кнопки мыши.
 */

bool DirectTXLeftButtonPressed();

/** \ingroup DirectTX
 *  \brief   Возвращает состояние правой кнопки мыши. Является оболочкой для
 *           txMouseButtons.
 *
 *  \return  Состояние правой кнопки мыши.
 */

bool DirectTXRightButtonPressed();

/** \ingroup DirectTX
 *  \brief   Рисует текст, может выводить значения - работает аналогично printf.
 *
 *  \param   x     X-координата текста
 *  \param   y     Y-координата текста
 *  \param   text  Шаблон текстовой строки. См. пример.
 *
 *  \note    Текст выводиться с помощью функции txTextOut поэтому эту функцию можно
 *           вызывать только между DirectTXFlush (когда из DirectTX-овского буфера все
 *           скопировано в TXLib-овский) и DirectTXEnd (но ещё не выведено на экран). В
 *           противном случае вызовет рассинхронизацию буферов (графика затрёт текст или
 *           текст будет мерцать).
 *
 * \par Пример
 * \code
 *           int a = 0;
 *           ...
 *           DirectTXTextOut (0, 0, "a is %i\n"); // Нарисует строку со значением переменной a.
 * \endcode
 */

void DirectTXTextOut (int x, int y, const char* text, ...);

/** \name    Примеры использования */

/** \page    DirectTXTutorial  Дополнение: Библиотека DirectTX

             <b>Библиотека DirectTX - DirectTX.cpp \n
                Copyright (C) Nikita Uvarov, 7 класс</b>

    \section DirectTXTutorialFirstIntroduction  Введение

             DirectTX - библиотека, позволяющая быстро выводить графику на TXLib'e.
             В основу DirectTX заложены принципы "тупого художника", а большинство его
             функций - переписанные функции TXLib.

    \section DirectTXTutorialFirstBaseProgram  Как это использовать? Преобразование старого кода

             Рассмотрим пример преобразования кода из TXLib в DirectTX.

             Код на TXLib:
    \code
             #include "TXLib.h"

             int main()
                 {
                 txCreateWindow (800, 600);

                 while (true)
                     {
                     txBegin();

                     txSetFillColor(TX_WHITE);
                     txSetColor(TX_BLACK);
                     txClear();

                     txRectangle(100, 100, 200, 200);
                     txCircle(500, 400, 100);

                     txEnd();
                     }
                 }
    \endcode
             Эта программа создаёт окно и вечно рисует в нём квадрат и круг. Ключевые
             слова - "вечно рисует". DirectTX рассчитан на покадровую отрисовку, то есть
             когда в секунду рисуются десятки, а то и сотни кадров. Рассмотрим аналогичную
             по смыслу программу на DirectTX:
    \code
             #include "DirectTX.cpp"

             int main()
                 {
                 DirectTXCreateWindow (800, 600);

                 while (true)
                     {
                     DirectTXBegin();

                     DirectTXSetFillColor (TX_WHITE);
                     DirectTXSetColor (TX_BLACK);
                     DirectTXDrawRectangle (0, 0, 800, 600);

                     DirectTXDrawRectangle (100, 100, 200, 200);
                     DirectTXDrawCircle (500, 400, 100);

                     DirectTXFlush();

                     DirectTXEnd();
                     }
                 }
    \endcode
             Рассмотрим изменения по порядку:

          -# Во первых, включается не TXLib.h а DirectTX.cpp.
          -# Во вторых, вместо txCreateWindow (800, 600) используется
             DirectTXCreateWindow (800, 600). Помимо создания окна, эта функция
             создаёт DirectTX-буфер и выполняет его инициализацию.
          -# Вместо txBegin и txEnd используются DirectTXBegin и DirectTXEnd.
             Это делает код однородным и выровненным.
          -# Вместо txSetColor и txSetFillColor используются DirectTXSetColor
             и DirectTXSetFillColor, так как цвета в DirectTX и TXLib хранятся
             отдельно.
          -# Вместо txClear используется DirectTXDrawRectangle, т.к. в DirectTX
             нет функции очистки (можно реализовать ее самостоятельно).
          -# Вместо txCircle и txRectangle используются DirectTXDrawCircle и
             DirectTXDrawRectangle. Это аналоги TXLib-овских функций. Они
             написаны, чтобы работать на DirectTX-технологии и рисуют свои
             обьекты попиксельно.
          -# В конце рисования стоит DirectTXFlush. Он копирует изображение в
             буфер TXLib и тем самым подготавливает кадр для отрисовки.

             Таким образом, DirectTX внешне не сильно отличается от TXLib.

    \section DirectTXTutorialFirstGetMore  Дальше - больше

             Мы рассмотрели превращение TXLib-овского кода в DirectTX-овский. Однако
             при этом мы не использовали дополнительные возможности DirectTX.
             Рассмотрим их по порядку.

          -# DirectTXCreateWindow может не только создавать окно, но и присваивать
             ему имя. Например, можно вызвать его так:
    \code
             DirectTXCreateWindow (800, 600, "A window with title");
    \endcode
          -# Между DirectTXFlush и DirectTXEnd нет кода. На самом деле, туда
             можно поместить любой TXLib-овский код. Например, пусть рисуется
             линия, если нажата клавиша 'L':
    \code
             ...
             DirectTXFlush();

             if (DirectTXKeyPressed ('L'))
                 DirectTXDrawLine (0, 0, 800, 600);

             DirectTXEnd();
             ...
    \endcode
            -# DirectTX изначально создавался для скорости, однако в этом примере
               мы ничего о ней не знаем. Добавим код для диагностики скорости :
    \code
               ...
               DirectTXFlush();

               DirectTXDrawInfo(DTX_FPS);

               DirectTXEnd();
               ...
    \endcode
               Этот код нарисует в углу окна текущий FPS (frames per second,
               количество кадров в секунду). Это значение часто меняется - FPS
               считается не на основе реального количества отрисованных кадров,
               а на основе времени, потраченного на отрисовку одного кадра. Узнать
               это время можно, если вызвать DirectTXDrawInfo (DTX_RENDEREDIN).

    \section   DirectTXTutorialFirstSum  Шаблон приложения DirectTX

               На основе всего рассмотренного, мы можем создать шаблон приложения на
               DirectTX:
    \code
               #include "DirectTX.cpp"

               void DrawDirectTXGraphics() {...}
               void DrawTXLibGraphics()    {...}

               int main()
                   {
                   DirectTXCreateWindow (800, 600, "Header");

                   while (true)
                       {
                       DirectTXBegin();

                       DrawDirectTXGraphics();
                       DirectTXFlush();

                       DrawTXLibGraphics();
                       DirectTXDrawInfo (DTX_FPS);

                       DirectTXEnd();
                       }
                   }
    \endcode
               @b Удачи!
*/

/* Implementation */

POINT           DirectTXScreenSize       = {};
int             DirectTXScreenBufferSize = 0;

unsigned char*  DirectTXScreen           = NULL;

DirectTXColor   DirectTXCurrentFillColor (TX_WHITE),
                DirectTXCurrentColor     (TX_BLACK);

BITMAPINFO      DirectTXScreenBitmapInfo = {{0}};
long            DirectTXLastRenderMoment =   0;
double          DirectTXLastRenderTime   =   0;

void DirectTXCreateWindow (int width, int height, const char* header)
    {
    txCreateWindow (width, height);
    SetWindowText (txWindow(), header);

    DirectTXScreenSize.x     = width;
    DirectTXScreenSize.y     = height;
    DirectTXScreenBufferSize = (width * 3 + width % 4) * height;
    DirectTXScreen           = new unsigned char [DirectTXScreenBufferSize];

    BITMAPINFOHEADER hdr     = { sizeof (BITMAPINFOHEADER), DirectTXScreenSize.x, DirectTXScreenSize.y,
                                 1, 24, BI_RGB, 0, 0, 0 };

    RGBQUAD          palette = {};
    BITMAPINFO            bi = { hdr, { palette } };

    DirectTXScreenBitmapInfo = bi;
    }

void DirectTXFlush()
    {
    Win32::SetDIBitsToDevice (txDC(), 0, 0,
                              DirectTXScreenBitmapInfo.bmiHeader.biWidth,
                              DirectTXScreenBitmapInfo.bmiHeader.biHeight,
                              0, 0, 0, DirectTXScreenBitmapInfo.bmiHeader.biHeight,
                              DirectTXScreen, &DirectTXScreenBitmapInfo, DIB_RGB_COLORS);

    DirectTXLastRenderTime   = GetTickCount() - DirectTXLastRenderMoment;
    DirectTXLastRenderMoment = GetTickCount();
    }

void DirectTXFlushBack()
    {
    Win32::GetDIBits         (txDC(),
                             (HBITMAP) Win32::GetCurrentObject (txDC(), OBJ_BITMAP),
                              0, DirectTXScreenBitmapInfo.bmiHeader.biHeight,
                              DirectTXScreen,
                              &DirectTXScreenBitmapInfo, DIB_RGB_COLORS);

    DirectTXLastRenderTime   = GetTickCount() - DirectTXLastRenderMoment;
    DirectTXLastRenderMoment = GetTickCount();
    }

void DirectTXDrawFPS (bool fps)
    {
    static long lastGoodFPS = 0;

    char buf [128] = "";

    if (fps)
        {
        if (ROUND (DirectTXLastRenderTime) != 0) lastGoodFPS = ROUND (1000.0 / DirectTXLastRenderTime);

        sprintf (buf, "FPS: %ld", lastGoodFPS);
        }
    else
        sprintf (buf, "Rendered in: %.0f ms.", DirectTXLastRenderTime);

    txTextOut (0, 0, buf);
    }

void DirectTXDrawInfo (DirectTXInfo info)
    {
    DirectTXDrawFPS (info == DTX_FPS);
    }

inline void DirectTXBegin()
    {
    txBegin();
    }

inline void DirectTXEnd()
    {
    txEnd();
    Sleep (0);
    }

inline int DirectTXGetPixelIndex (int x, int y, int color)
    {
    POINT size = DirectTXScreenSize;

    if (!(0 <= x && x < size.x &&
          0 <= y && y < size.y)) return -1;

    int rowSize = size.x * 3 + size.x % 4;
    int offset  = (size.y - y) * rowSize + x*3 + color;

    return (0 <= offset && offset < DirectTXScreenBufferSize)? offset : -1;
    }

inline void DirectTXPutPixel (int x, int y, int r, int g, int b)
    {
    int index = DirectTXGetPixelIndex (x, y, 0);
    if (index < 0) return;

    DirectTXScreen [index + 0] = (char) b;
    DirectTXScreen [index + 1] = (char) g;
    DirectTXScreen [index + 2] = (char) r;
    }

inline void DirectTXPutPixel (int x, int y, const DirectTXColor& c)
    {
    DirectTXPutPixel (x, y, c.red, c.green, c.blue);
    }

inline DirectTXColor DirectTXGetPixel (int x, int y)
    {
    int index = DirectTXGetPixelIndex (x, y, 0);
    if (index < 0) return DirectTXColor (0);

    int b = DirectTXScreen [index + 0];
    int g = DirectTXScreen [index + 1];
    int r = DirectTXScreen [index + 2];

    return DirectTXColor (r, g, b);
    }

inline DirectTXColor::DirectTXColor() :
    red   (0),
    green (0),
    blue  (0)
    {}

inline DirectTXColor::DirectTXColor (int r, int g, int b) :
    red   ((char) r),
    green ((char) g),
    blue  ((char) b)
    {}

inline DirectTXColor::DirectTXColor (float r, float g, float b) :
    red   ((char) round (r)),
    green ((char) round (g)),
    blue  ((char) round (b))
    {}

inline DirectTXColor::DirectTXColor (COLORREF c) :
    red   ((char) ((c >> 16) & 0xFF)),
    green ((char) ((c >>  8) & 0xFF)),
    blue  ((char) ((c >>  0) & 0xFF))
    {}

inline DirectTXColor::operator COLORREF()
    {
    return RGB (red, green, blue);
    }

inline DirectTXColor DirectTXColor::Mix (const DirectTXColor& c, float howManyOfFirst)
    {
    return DirectTXColor (red   * howManyOfFirst + c.red   * (1 - howManyOfFirst),
                          green * howManyOfFirst + c.green * (1 - howManyOfFirst),
                          blue  * howManyOfFirst + c.blue  * (1 - howManyOfFirst));
    }

inline void DirectTXSetColor (const DirectTXColor& c)
    {
    DirectTXCurrentColor = c;
    }

inline void DirectTXSetFillColor (const DirectTXColor& c)
    {
    DirectTXCurrentFillColor = c;
    }

inline bool DirectTXKeyPressed (char c)
    {
    return (GetKeyState (c) >> 7) == -1;
    }

inline bool DirectTXLeftButtonPressed()
    {
    return (txMouseButtons() & 1) == 1;
    }

inline bool DirectTXRightButtonPressed()
    {
    return (txMouseButtons() & 2) == 1;
    }

void DirectTXDrawRectangle (int x0, int y0, int x1, int y1)
    {
    if (x0 > x1) std::swap (x0, x1);
    if (y0 > y1) std::swap (y0, y1);

    for (int y = y0 + 1; y < y1; y++)
    for (int x = x0 + 1; x < x1; x++)
        DirectTXPutPixel (x, y, DirectTXCurrentFillColor);

    for (int x = x0; x <= x1; x++)
        {
        DirectTXPutPixel (x, y0, DirectTXCurrentColor);
        DirectTXPutPixel (x, y1, DirectTXCurrentColor);
        }

    for (int y = y0; y <= y1; y++)
        {
        DirectTXPutPixel (x0, y, DirectTXCurrentColor);
        DirectTXPutPixel (x1, y, DirectTXCurrentColor);
        }
    }

void DirectTXDrawLine (int x0, int y0, int x1, int y1)
    {
    int dx      = (x1 - x0 >= 0)? -1 : 1;
    int dy      = (y1 - y0 >= 0)? -1 : 1;

    int lengthX = abs (x1 - x0);
    int lengthY = abs (y1 - y0);

    int length  = (lengthX > lengthY)? lengthX : lengthY;

    if (length == 0)
        {
        DirectTXPutPixel (x1, y1, DirectTXCurrentColor);
        return;
        }

    if (lengthY <= lengthX)
        {
        int x =  x1;
        int y =  y1;
        int d = -lengthX;

        length++;
        while (length--)
            {
            DirectTXPutPixel (x, y, DirectTXCurrentColor);

            x += dx;
            d += 2 * lengthY;

            if (d > 0)
                {
                d -= 2 * lengthX;
                y += dy;
                }
            }
        }
    else
        {
        int x =  x1;
        int y =  y1;
        int d = -lengthY;

        length++;
        while (length--)
            {
            DirectTXPutPixel (x, y, DirectTXCurrentColor);

            y += dy;
            d += 2 * lengthX;

            if (d > 0)
                {
                d -= 2 * lengthY;
                x += dx;
                }
            }
        }
    }

void DirectTXDrawCircle (int xc, int yc, int r)
    {
    if (r < 0) return;

    int x = 0;
    int y = r;
    int d = 3 - (r << 1);

    while (y >= x)
        {
        DirectTXPutPixel ( x + xc,  y + yc, DirectTXCurrentColor);
        DirectTXPutPixel ( x + xc, -y + yc, DirectTXCurrentColor);

        DirectTXPutPixel (-x + xc,  y + yc, DirectTXCurrentColor);
        DirectTXPutPixel (-x + xc, -y + yc, DirectTXCurrentColor);

        DirectTXPutPixel ( y + xc,  x + yc, DirectTXCurrentColor);
        DirectTXPutPixel ( y + xc, -x + yc, DirectTXCurrentColor);

        DirectTXPutPixel (-y + xc,  x + yc, DirectTXCurrentColor);
        DirectTXPutPixel (-y + xc, -x + yc, DirectTXCurrentColor);

        for (int vertX = -y + xc + 1; vertX < y + xc; vertX++)
            {
            DirectTXPutPixel (vertX, -x + yc, DirectTXCurrentFillColor);
            DirectTXPutPixel (vertX,  x + yc, DirectTXCurrentFillColor);
            }

        if (d >= 0)
            {
            d += ((x - y) << 2) + 10;
            y--;

            for (int vertX = -x + xc; vertX <= x + xc; vertX++)
                {
                DirectTXPutPixel (vertX,  y + yc, DirectTXCurrentFillColor);
                DirectTXPutPixel (vertX, -y + yc, DirectTXCurrentFillColor);
                }
            }
        else
            d += (x << 2) + 6;

        x++;
        }
    }

void DirectTXTextOut (int x, int y, const char* stringTemplate, ...)
    {
    char text [1024] = "";

    va_list firstArgPointer;
    va_start (firstArgPointer, stringTemplate);
    vsprintf (text, stringTemplate, firstArgPointer);
    va_end (firstArgPointer);

    txTextOut (x, y, text);
    }

