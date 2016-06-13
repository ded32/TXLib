//{===========================================================================
//! @file       Examples\Demo\MathBeauty\MathBeauty.cpp
//!
//! @brief      Построитель графиков
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @date       2018
//! @author     Филипп Куликов, 7 класс
//          (C) Филипп Куликов, 7 класс, 2006
//}===========================================================================

#include "FilippLib.h"

//----------------------------------------------------------------------------------------------------------------------

struct Button
    {
    int x, y;
    int lengh, hight;

    COLORREF setColor, fillColor;

    const char* text;
    COLORREF setTextColor;

    int number;
    int hotKey;
    double (*grafic) (double x, const double kF[]);
    char yFormula [125];

    void drawButton();
    };

//----------------------------------------------------------------------------------------------------------------------

void buildGrafics      (HDC desk, HDC book, HDC voprosImage);
int  controlGrafics    (double kF[]);
void deskKF            (const double kF[], int n);
void DrawButtons       (Button object[], int size);
int  CheckButtons      (Button object[], int size);
int  CheckMouseButtons (Button object[], int size);

int fIn (double xMin, double x, double xMax, double yMin, double y, double yMax);
void formula (double kF[], char yFormula[]);
void Lines (bool grid);
void signingOfTheAxes();
void InformationDesk();
void ShadowRect (int x1, int y1, int x2, int y2, COLORREF fillColor, COLORREF countourColor);
void ShadowText (int x1, int y1, int x2, int y2, COLORREF color, const char text[]);

//----------------------------------------------------------------------------------------------------------------------

int main()
    {
    HDC desk        = txLoadImage ("Desk.bmp");
    HDC book        = txLoadImage ("Book.bmp");
    HDC voprosImage = txLoadImage ("Vopros.bmp");

    txCreateWindow (1300, 700);
    txTextCursor (false);
    txDisableAutoPause();

    buildGrafics (desk, book, voprosImage);

    txDeleteDC (desk);
    txDeleteDC (book);
    txDeleteDC (voprosImage);

    while (_kbhit()) _getch();

    return 0;
    }

//----------------------------------------------------------------------------------------------------------------------

void buildGrafics (HDC desk, HDC book, HDC voprosImage)
    {
    //                   x    y    lengh hight setColor       fillColor    name text           setTextColor  number  function     formula text
    Button object[] = { {975, 110, 300,  60,   CountourColor, ButtonColor, "Линейная функция", TextColor,    0, '1', liner,       "y = %.1f + x * %.1f"              },
                        {975, 210, 300,  60,   CountourColor, ButtonColor, "Парабола",         TextColor,    1, '2', parabola,    "y = %.1f + %.1f * x + %.1f * x^2" },
                        {975, 310, 300,  60,   CountourColor, ButtonColor, "Радиоволны",       TextColor,    2, '3', radio_waves, "y = %.1f + %.1f*x + %.1f * sin (x) / tan (x) * x^3 / 10" },
                        {975, 410, 300,  60,   CountourColor, ButtonColor, "Большая Арка!!",   TextColor,    3, '4', big_arc,     "y = %.1f + x*x/100 / %.1f * %.1f" },
                        {975, 510, 300,  60,   CountourColor, ButtonColor, "Синус",            TextColor,    4, '5', sinus,       "y = %.1f + sin (x * %.1f) * %.1f" } };

    int size = sizeof (object) / sizeof (object [0]);

    int oldMousePressed  = 0;
    int mousePressed = 0;

    int drawButtons = 0;
    int vopros = 0;

    const int n = 3; // c  b  k
    double kF [n] =  {  0, 1, 0.5 };

    txBegin();

    int numberOfGrafic = 0;

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        int button = CheckButtons (object, size);
        if (button != -1) numberOfGrafic = button;

        controlGrafics (kF);

        txSetFillColor (TX_BLACK);
        txClear();

        alphaBlend (0, 0, LenghDesk, HightDesk, desk, 0, 0, (txGetExtentX (desk)), (txGetExtentY (desk)), 1, 2);

        Lines (true);

        const COLORREF veryGray = RGB (15, 15, 15);
        txSetColor     (veryGray);
        txSetFillColor (veryGray);

        txdrawGrafics (-50, 50, object [numberOfGrafic].grafic, WHITE, 0.1, 5, kF);

        signingOfTheAxes();

        formula (kF, object[numberOfGrafic].yFormula);

        txTransparentBlt (txDC(), 1240,  45, 55, 47, book);
        txTransparentBlt (txDC(), 1170,  45, 50, 50, voprosImage);

        double x = txMousePos().x, y = txMousePos().y;

        oldMousePressed = mousePressed;
        mousePressed = txMouseButtons() & 1;

        if (!oldMousePressed && mousePressed)
            {
            if (fIn (1240, x, 1295, 45, y, 92)) drawButtons = !drawButtons;
            if (fIn (1170, x, 1220, 45, y, 90)) vopros      = !vopros;
            }

        if (vopros || GetAsyncKeyState (VK_F1))
            InformationDesk();

        if (drawButtons || GetAsyncKeyState (VK_F2))
            DrawButtons (object, size);

        txSleep();
        }

    txEnd();
    }

//----------------------------------------------------------------------------------------------------------------------

int controlGrafics (double kF[])
    {
    int difference = 0;

    if (GetAsyncKeyState ('C'))
        {
        if (GetAsyncKeyState (VK_UP))    kF [0] += 0.08;
        if (GetAsyncKeyState (VK_DOWN))  kF [0] -= 0.08;
        if (GetAsyncKeyState (VK_SPACE)) kF [0]  = 1;

        difference++;
        }

    if (GetAsyncKeyState ('B'))
        {
        if (GetAsyncKeyState (VK_UP))    kF [1] += 0.1;
        if (GetAsyncKeyState (VK_DOWN))  kF [1] -= 0.1;
        if (GetAsyncKeyState (VK_SPACE)) kF [1]  = 1;

        difference++;
        }

    if (GetAsyncKeyState ('K'))
        {
        if (GetAsyncKeyState (VK_UP))    kF [2] += 0.2;
        if (GetAsyncKeyState (VK_DOWN))  kF [2] -= 0.2;
        if (GetAsyncKeyState (VK_SPACE)) kF [2]  = 1;

        difference++;
        }

    if (difference == 0 && GetAsyncKeyState (VK_SPACE))
        {
        kF [0] = 0;
        kF [1] = 0;
        kF [2] = 1;

        difference++;
        }

    return difference;
    }

//----------------------------------------------------------------------------------------------------------------------

void formula (double kF[], char yFormula[])
    {
    char str [100] = "";
    sprintf (str, yFormula, kF [0], kF [1], kF [2]);

    txSelectFont ("Comic Sans MS", 40);
    txSetTextAlign (TA_LEFT);

    ShadowRect (LeftOfTheGrafic + 3, TopOfTheGrafic + 10,
                LeftOfTheGrafic + 30 + txGetTextExtentX (str),
                TopOfTheGrafic  + 25 + txGetTextExtentY (str),
                ButtonColor, CountourColor);

    ShadowText (LeftOfTheGrafic + 15, TopOfTheGrafic + 15, 0, 0, TX_YELLOW, str);
    }

//----------------------------------------------------------------------------------------------------------------------

void Button::drawButton()
    {
    txSelectFont ("Comic Sans MS", 40);

    ShadowRect (x, y, x + lengh, y + hight, fillColor, setColor);
    ShadowText (x, y, x + lengh, y + hight, setTextColor, text);
    }

//----------------------------------------------------------------------------------------------------------------------

void DrawButtons (Button object[], int size)
    {
    int i = 0;
    while (i < size)
        {
        object [i].drawButton();
        i++;
        }
    }

//----------------------------------------------------------------------------------------------------------------------

int CheckMouseButtons (Button object[], int size)
    {
    if (!txMouseButtons() & 1) return -1;

    int i = 0;
    while (i < size)
        {
        double xMin = object [i].x, xMax = object [i].x + object [i].lengh;
        double yMin = object [i].y, yMax = object [i].y + object [i].hight;
        double x = txMousePos().x, y = txMousePos().y;

        if (fIn (xMin, x, xMax, yMin, y, yMax))
            {
            return i;
            }

        i++;
        }

    return -1;
    }

//----------------------------------------------------------------------------------------------------------------------

int CheckButtons (Button object[], int size)
    {
    int i = 0;
    while (i < size)
        {
        if (GetAsyncKeyState (object [i].hotKey) ||
           (fIn (object [i].x, txMouseX(), object [i].x + object [i].lengh,
                 object [i].y, txMouseY(), object [i].y + object [i].hight) && (txMouseButtons() & 1)))
            {
            return i;
            }

        i++;
        }

    return -1;
    }

//----------------------------------------------------------------------------------------------------------------------

int fIn (double xMin, double x, double xMax,
         double yMin, double y, double yMax)
    {
    return (xMin <= x && x <= xMax) &&
           (yMin <= y && y <= yMax);
    }

//----------------------------------------------------------------------------------------------------------------------

void Lines (bool grid)
    {
    txSetColor (TX_RED, 2);
    txLine (Xcentre+1, TopOfTheGrafic + 7, Xcentre+1, BottomOfTheGrafic - 7);
    txLine (LeftOfTheGrafic + 10, Ycentre+1, RightOfTheGrafic - 10, Ycentre+1);
    txLine (Xcentre-10, TopOfTheGrafic+20, Xcentre+1, TopOfTheGrafic+7);
    txLine (Xcentre+11, TopOfTheGrafic+20, Xcentre+1, TopOfTheGrafic+7);
    txLine (RightOfTheGrafic-23, Ycentre+11, RightOfTheGrafic-10, Ycentre+1);
    txLine (RightOfTheGrafic-23, Ycentre-11, RightOfTheGrafic-10, Ycentre+1);

    txSelectFont ("Comic Sans MS", 25);
    txSetTextAlign (TA_LEFT);

    txTextOut (txGetExtentX()/2 - 25, TopOfTheGrafic + 13,   "Y");
    txTextOut (RightOfTheGrafic - 25, txGetExtentY()/2 + 15, "X");

    if (grid)
        {
        Pen();

        int Xnum = LeftOfTheGrafic;
        while (Xnum < RightOfTheGrafic-20)
            {
            Xnum += 20;
            txLine (Xnum, TopOfTheGrafic, Xnum, BottomOfTheGrafic);
            }

        int Ynum = TopOfTheGrafic-10;
        while (Ynum < BottomOfTheGrafic-20)
            {
            Ynum += 20;
            txLine (LeftOfTheGrafic, Ynum, RightOfTheGrafic, Ynum);
            }
        }
    }

//----------------------------------------------------------------------------------------------------------------------

void signingOfTheAxes()
    {
    txSetColor (TX_RED);
    txSelectFont ("Comic Sans MS", 25);
    txSetTextAlign (TA_RIGHT);

    int i = 1;
    int y = Ycentre-90;
    while (y >= TopOfTheGrafic - 40)
        {
        char str [20]= "";
        sprintf (str, "%d", i);

        txTextOut (Xcentre-10, TopOfTheGrafic  + y, str);

        i++;
        y -= 2*Step;
        }

    int i2 = 1;
    int y2 = Ycentre-10;
    while (y2 <= BottomOfTheGrafic - 80)
        {
        char str [20]= "";
        sprintf (str, "-%d", i2);

        txTextOut (Xcentre-10, TopOfTheGrafic  + y2, str);

        i2++;
        y2 += 2*Step;
        }

    txSetTextAlign (TA_CENTER);

    int i3 = -1;
    int x = Xcentre-90;
    while (x >= LeftOfTheGrafic - 60)
        {
        char str [20]= "";
        sprintf (str, "%d", i3);

        txTextOut (LeftOfTheGrafic + x+5, Ycentre+5, str);

        i3--;
        x -= 2*Step;
        }

    int i4 = 1;
    int x2 = Xcentre-5;
    while (x2 <= RightOfTheGrafic - 60)
        {
        char str [20]= "";
        sprintf (str, "%d", i4);

        txTextOut (LeftOfTheGrafic + x2+5, Ycentre+5, str);

        i4++;
        x2 += 2*Step;
        }

    txSelectFont ("Comic Sans MS", 25);
    txSetTextAlign (TA_TOP + TA_RIGHT);

    txTextOut (Xcentre-7, Ycentre+4, "0");
    }

//----------------------------------------------------------------------------------------------------------------------

void InformationDesk()
    {
    ShadowRect (30, 530, 885, 680, ButtonColor, CountourColor);

    txSelectFont ("Comic Sans MS", 25);
    txSetTextAlign (TA_LEFT);

    ShadowText (50, 540, 0, 0, TX_WHITE, "Выбор графика, включение и выключение меню - значок книги в правом верхнем углу или F2");
    ShadowText (50, 570, 0, 0, TX_WHITE, "Увеличение k -- K + UP,  уменьшение -- K + DOWN,      k = 0 -- K + SPACE");
    ShadowText (50, 590, 0, 0, TX_WHITE, "Увеличение b -- B + UP,  уменьшение -- B + DOWN,      b = 0 -- B + SPACE           Выход -- ESC");
    ShadowText (50, 610, 0, 0, TX_WHITE, "Увеличение c -- C + UP,  уменьшение -- C + DOWN,      c  = 0 -- C + SPACE");
    ShadowText (50, 640, 0, 0, TX_WHITE, "Copyright (C) Филипп Куликов, 2018, 7 класс                 k = b = c = 0 -- SPACE");
    }

//----------------------------------------------------------------------------------------------------------------------

void ShadowRect (int x1, int y1, int x2, int y2, COLORREF fillColor, COLORREF countourColor)
    {
    txSetColor       (ShadowColor);
    txSetFillColor   (ShadowColor);
    Win32::RoundRect (txDC(), x1+3, y1+3, x2+3, y2+3, 15, 15);

    txSetColor       (countourColor);
    txSetFillColor   (fillColor);
    Win32::RoundRect (txDC(), x1, y1, x2, y2, 15, 15);
    }

//----------------------------------------------------------------------------------------------------------------------

void ShadowText (int x1, int y1, int x2, int y2, COLORREF color, const char text[])
    {
    txSetColor (ShadowColor);
    if (x2 && y2) txDrawText (x1+2, y1+2, x2+2, y2+2, text);
    else          txTextOut  (x1+2, y1+2,             text);

    txSetColor (color);
    if (x2 && y2) txDrawText (x1, y1, x2, y2, text);
    else          txTextOut  (x1, y1,         text);
    }
