//{===========================================================================
//           ���������� DirectTX - DirectTX.cpp
//           Copyright (C) Nikita Uvarov, 7 �����
//}===========================================================================

/**\file     DirectTX.cpp
 *
 * \brief    DirectTX - ���������� TXLib'�, ���������� ������ �������������
 *           � ��������� ������� ������� �� ������ ��������� ��������.
 *
 *           DirectTX ���������� ������ ������ � ������, ��� ������������ ��������
 *           �������� �� ��������� �����.
 *
 *           � �������� �������� ������� �� �������� ����, � �� �� ��������� �������,
 *           ��� ��������� ������� ���������� �������� ����������� �� ���������� ��������.
 *
 * \par      ���������������
 *        -# ������ ������� �������� ������ �� ���, ��� � TXLib'�, ��� �� ��
 *           �� ������������� �������� �����������. ������������ � ������ ������ ������
 *           ����� �� ��������������.
 *
 * \version  [v 0.2]
 *
 * \author   Copyright (C) Nikita Uvarov, 7 �����
 * \date     2009
 *
 * \defgroup DirectTX DirectTX: ������ (�. ������)
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
 *  \brief   ������ ���� DirectTX. �� �������� ���������, ������� ������
 *           txCreateWindow ����� ����������� ������������ ��� �������.
 *
 *  \param   width   ������ ����
 *  \param   height  ������ ����
 *  \param   header  ��������� ����. ����� �� �����������, � ����� ������ � ���� �����
 *                   ����������� ��� TXLib ��� (��� ����� �� �������� �������� ���������).
 *
 *  \par     ������
 *  \code
 *           DirectTXCreateWindow(800, 600, "Window with title");
 *  \endcode
 *  \code
 *           DirectTXCreateWindow(800, 600); // ���� �� ����������� ����������
 *  \endcode
 */

void DirectTXCreateWindow (int width, int height, const char* header = 0);

/** \ingroup DirectTX
 *  \brief   �������� ������� �� ������ DirectTX � ����� TXLib.
 *
 *  \warning
 *        -# ���� �� ������� ��� �������, ��������� ���� ��������� DirectTX-������� ��
 *           �� ������ �� �����������.
 *        -# ������� �� �������� ���������� ����, ������� ���������� ������������ ��
 *           ����� ��������� \ref DirectTXBegin � \ref DirectTXEnd. � ���������
 *           ������ ������� ����� ����������� ��� ������ ����� �������������.
 */

void DirectTXFlush();

/** \ingroup DirectTX
 *  \brief   �������� ������� �� ������ TXLib � ����� DirectTX.
 */

void DirectTXFlushBack();

/** \ingroup DirectTX
 *  \brief   ������� ��������� ���������� ���� - ���������� txBegin.
 */

void DirectTXBegin();

/** \ingroup DirectTX
 *  \brief   ������� ������������ ���������� ���� - ���������� txEnd.
 */

void DirectTXEnd();

/** \ingroup DirectTX
 *  \brief   ������� ���������� ������ ������� � ������� ��������.
 *
 *  \param   x       X-���������� �������
 *  \param   y       Y-���������� �������
 *  \param   offset  ��������. 0 �������� ������� ����, 1 - ������, 2 - �����.
 *                   �������� �������������� ���������� (�� ��������� 0).
 *
 *  \return  ������ ������� � ������� ��������.
 *
 *  \note    �� ��������� ������ ������ � ���������, ��� ������� �� ������������� ���
 *           ����������. ������ �� ����������� \ref DirectTXPutPixel �
 *           \ref DirectTXGetPixel.
 */

int  DirectTXGetPixelIndex (int x, int y, int offset = 0);

/** \ingroup DirectTX
 *  \brief   ������������� �������� ����� �������.
 *
 *  \param   x  X-���������� �������
 *  \param   y  Y-���������� �������
 *  \param   c  ���� �������
 *
 *  \note    ���� ������� ��������������� � ������ � �� ���������� �� ����� ��
 *           ������ \ref DirectTXFlush.
 */

void DirectTXPutPixel (int x, int y, const DirectTXColor& c);

/** \ingroup DirectTX
 *  \brief   ������������� �������� ����� �������.
 *
 *  \param   x  X-���������� �������
 *  \param   y  Y-���������� �������
 *  \param   r  ������� ���������� ����� �������.
 *  \param   g  ������ ���������� ����� �������.
 *  \param   b  ����� ���������� ����� �������.
 *
 *  \note    ���� ������� ��������������� � ������ � �� ���������� �� ����� ��
 *           ������ \ref DirectTXFlush.
 */

void DirectTXPutPixel (int x, int y, int r, int g, int b);

/** \ingroup DirectTX
 *  \brief   ���������� ���� �������.
 *
 *  \param   x  X-���������� �������
 *  \param   y  Y-���������� �������
 *
 *  \note    ���� ������� ������������ �� ������ DirectTX, � ���� ������� � ������ �
 *           �� ������ ����� �� ��������� (���� �������� TXLib-������� ���������). ���
 *           ������� ����� ����� ������������ ������ ���� ������� ����� ������� ��������
 *           � ������� DirectTX.
 */

DirectTXColor DirectTXGetPixel (int x, int y);

/** \ingroup DirectTX
 *  \brief   ������������� ���� �����.
 *
 *  \param   c  ���� ����� � ������
 *
 *  \note    ���� ����� DirectTX �������� �������� �� ����� ����� TXLib � ��
 *           ������ � ��� ���������. ��� DirectTX-������ ������� ����������
 *           ���� DirectTX, �� ����������� \ref DirectTXTextOut.
 */

void DirectTXSetColor (const DirectTXColor& c);

/** \ingroup DirectTX
 *  \brief   ������������� ���� �������.
 *
 *  \param   c  ���� �������
 *
 *  \note    ���� ������� DirectTX �������� �������� �� ����� ������� TXLib � ��
 *           ������ � ��� ���������. ��� DirectTX-������ ������� ����������
 *           ���� DirectTX, �� ����������� \ref DirectTXTextOut.
 */

void DirectTXSetFillColor (const DirectTXColor& c);

/** \ingroup DirectTX
 *  \brief   ������ �������������. �������� �������, ��� txRectangle.
 *
 *  \param   x0  X-���������� ������� ���� ��������������
 *  \param   y0  Y-���������� ������� ���� ��������������
 *  \param   x1  X-���������� ������� ���� ��������������
 *  \param   y1  Y-���������� ������� ���� ��������������
 */

void DirectTXDrawRectangle (int x0, int y0, int x1, int y1);

/** \ingroup DirectTX
 *  \brief   ������ �����. �������� �������, ��� txLine.
 *
 *  \param   x0  X-���������� ������ �����
 *  \param   y0  Y-���������� ������ �����
 *  \param   x1  X-���������� �����  �����
 *  \param   y1  Y-���������� �����  �����
 */

void DirectTXDrawLine (int x0, int y0, int x1, int y1);

/** \ingroup DirectTX
 *  \brief   ������ ���� ��� ����������. �������� ���������, ��� txCircle. ��� ��
 *           �����, �� ��������� ������� � ����������� ��������, �������������
 *           ������������ DirectTX-������ ������� ������ TXLib-������.
 *
 *  \param   xc  X-���������� ������ �����
 *  \param   yc  X-���������� ������ �����
 *  \param   r   ������ �����
 */

void DirectTXDrawCircle (int xc, int yc, int r);

/** \ingroup DirectTX
 *  \brief   ������� ������ � ������������������ ���������. ��. ���������.
 *
 *  \param   what  ����� ������ ��������. ����� ��������� �������� DTX_FPS (��������
 *                 ���������� ������ � �������) ��� DTX_RENDEREDIN (����������
 *                 �����������, �� ������� ��� ��������� ��������� ����).
 */

void DirectTXDrawInfo (DirectTXInfo what);

/** \ingroup DirectTX
 *  \brief   ������� ������ � ������������������ ���������. ������ ���������
 *
 *  \param   fps  ����� ������ ��������. ����� ��������� �������� true (��������
 *                ���������� ������ � �������) ��� false (���������� �����������,
 *                �� ������� ��� ��������� ��������� ����).
 */

void DirectTXDrawFPS (bool fps = true);

/** \ingroup DirectTX
 *  \brief   ���������� ��������� ������� (������ ��� ���).
 *
 *  \param   keyCode  ��� �������
 *
 *  \par     ������������ ����� GetAsyncKeyState � getch:
 *        -# ��������� �� ������� ������ ��� ����, � ������� �� getch.
 *        -# �� �������� ������� "��������� ������". (<b>�� ������ �� sticky keys:</b>
 *           ����� ��� ��������, ��� ���� ������� ���� ������, � ������� ������� �����
 *           ��������� ������ ����� �����, �� ������� ����� false.)
 */

bool DirectTXKeyPressed (char keyCode);

/** \ingroup DirectTX
 *  \brief   ���������� ��������� ����� ������ ����. �������� ��������� ���
 *           txMouseButtons.
 *
 *  \return  ��������� ����� ������ ����.
 */

bool DirectTXLeftButtonPressed();

/** \ingroup DirectTX
 *  \brief   ���������� ��������� ������ ������ ����. �������� ��������� ���
 *           txMouseButtons.
 *
 *  \return  ��������� ������ ������ ����.
 */

bool DirectTXRightButtonPressed();

/** \ingroup DirectTX
 *  \brief   ������ �����, ����� �������� �������� - �������� ���������� printf.
 *
 *  \param   x     X-���������� ������
 *  \param   y     Y-���������� ������
 *  \param   text  ������ ��������� ������. ��. ������.
 *
 *  \note    ����� ���������� � ������� ������� txTextOut ������� ��� ������� �����
 *           �������� ������ ����� DirectTXFlush (����� �� DirectTX-������� ������ ���
 *           ����������� � TXLib-������) � DirectTXEnd (�� ��� �� �������� �� �����). �
 *           ��������� ������ ������� ���������������� ������� (������� ����� ����� ���
 *           ����� ����� �������).
 *
 * \par ������
 * \code
 *           int a = 0;
 *           ...
 *           DirectTXTextOut (0, 0, "a is %i\n"); // �������� ������ �� ��������� ���������� a.
 * \endcode
 */

void DirectTXTextOut (int x, int y, const char* text, ...);

/** \name    ������� ������������� */

/** \page    DirectTXTutorial  ����������: ���������� DirectTX

             <b>���������� DirectTX - DirectTX.cpp \n
                Copyright (C) Nikita Uvarov, 7 �����</b>

    \section DirectTXTutorialFirstIntroduction  ��������

             DirectTX - ����������, ����������� ������ �������� ������� �� TXLib'e.
             � ������ DirectTX �������� �������� "������ ���������", � ����������� ���
             ������� - ������������ ������� TXLib.

    \section DirectTXTutorialFirstBaseProgram  ��� ��� ������������? �������������� ������� ����

             ���������� ������ �������������� ���� �� TXLib � DirectTX.

             ��� �� TXLib:
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
             ��� ��������� ������ ���� � ����� ������ � �� ������� � ����. ��������
             ����� - "����� ������". DirectTX ��������� �� ���������� ���������, �� ����
             ����� � ������� �������� �������, � �� � ����� ������. ���������� �����������
             �� ������ ��������� �� DirectTX:
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
             ���������� ��������� �� �������:

          -# �� ������, ���������� �� TXLib.h � DirectTX.cpp.
          -# �� ������, ������ txCreateWindow (800, 600) ������������
             DirectTXCreateWindow (800, 600). ������ �������� ����, ��� �������
             ������ DirectTX-����� � ��������� ��� �������������.
          -# ������ txBegin � txEnd ������������ DirectTXBegin � DirectTXEnd.
             ��� ������ ��� ���������� � �����������.
          -# ������ txSetColor � txSetFillColor ������������ DirectTXSetColor
             � DirectTXSetFillColor, ��� ��� ����� � DirectTX � TXLib ��������
             ��������.
          -# ������ txClear ������������ DirectTXDrawRectangle, �.�. � DirectTX
             ��� ������� ������� (����� ����������� �� ��������������).
          -# ������ txCircle � txRectangle ������������ DirectTXDrawCircle �
             DirectTXDrawRectangle. ��� ������� TXLib-������ �������. ���
             ��������, ����� �������� �� DirectTX-���������� � ������ ����
             ������� �����������.
          -# � ����� ��������� ����� DirectTXFlush. �� �������� ����������� �
             ����� TXLib � ��� ����� �������������� ���� ��� ���������.

             ����� �������, DirectTX ������ �� ������ ���������� �� TXLib.

    \section DirectTXTutorialFirstGetMore  ������ - ������

             �� ����������� ����������� TXLib-������� ���� � DirectTX-������. ������
             ��� ���� �� �� ������������ �������������� ����������� DirectTX.
             ���������� �� �� �������.

          -# DirectTXCreateWindow ����� �� ������ ��������� ����, �� � �����������
             ��� ���. ��������, ����� ������� ��� ���:
    \code
             DirectTXCreateWindow (800, 600, "A window with title");
    \endcode
          -# ����� DirectTXFlush � DirectTXEnd ��� ����. �� ����� ����, ����
             ����� ��������� ����� TXLib-������ ���. ��������, ����� ��������
             �����, ���� ������ ������� 'L':
    \code
             ...
             DirectTXFlush();

             if (DirectTXKeyPressed ('L'))
                 DirectTXDrawLine (0, 0, 800, 600);

             DirectTXEnd();
             ...
    \endcode
            -# DirectTX ���������� ���������� ��� ��������, ������ � ���� �������
               �� ������ � ��� �� �����. ������� ��� ��� ����������� �������� :
    \code
               ...
               DirectTXFlush();

               DirectTXDrawInfo(DTX_FPS);

               DirectTXEnd();
               ...
    \endcode
               ���� ��� �������� � ���� ���� ������� FPS (frames per second,
               ���������� ������ � �������). ��� �������� ����� �������� - FPS
               ��������� �� �� ������ ��������� ���������� ������������ ������,
               � �� ������ �������, ������������ �� ��������� ������ �����. ������
               ��� ����� �����, ���� ������� DirectTXDrawInfo (DTX_RENDEREDIN).

    \section   DirectTXTutorialFirstSum  ������ ���������� DirectTX

               �� ������ ����� ��������������, �� ����� ������� ������ ���������� ��
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
               @b �����!
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

