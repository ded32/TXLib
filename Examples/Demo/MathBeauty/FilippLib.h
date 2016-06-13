//{===========================================================================
//! @file       Examples\Demo\MathBeauty\FilippLib.h
//!
//! @brief      Построитель графиков, вспомогательная библиотека
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @date       2018
//! @author     Филипп Куликов, 7 класс
//          (C) Филипп Куликов, 7 класс, 2006
//}===========================================================================

#include "TXLib.h"
#include "Config.h"

//----------------------------------------------------------------------------------------------------------------------
//{ Прототипы
//----------------------------------------------------------------------------------------------------------------------

void txdrawGrafics    (double start, double finish, double (*func) (double x, const double kF[]),
                       COLORREF colour(), double increase, double radius,     const double kF[]);

void alphaBlend       (double x, double y, double width, double height,
                       HDC image, double xImage, double yImage, double widthOriginal, double heightOriginal, double alpha,
                       int pictureN);

double parabola       (double x, const double kF[]);
double liner          (double x, const double kF[]);
double parabola_3     (double x, const double kF[]);
double parabola_4     (double x, const double kF[]);
double arc            (double x, const double kF[]);
double big_arc        (double x, const double kF[]);
double some_sin       (double x, const double kF[]);
double more_parabols  (double x, const double kF[]);
double big_sin        (double x, const double kF[]);
double scliff         (double x, const double kF[]);
double rope           (double x, const double kF[]);
double waves          (double x, const double kF[]);
double big_waves      (double x, const double kF[]);
double radio_waves    (double x, const double kF[]);
double forest         (double x, const double kF[]);
double small_forest   (double x, const double kF[]);
double rainforest     (double x, const double kF[]);
double big_rainforest (double x, const double kF[]);
double sinus          (double x, const double kF[]);
double cosinus        (double x, const double kF[]);

COLORREF GREEN();
COLORREF LIGHTGREEN();
COLORREF BLUE();
COLORREF LIGHTBLUE();
COLORREF RED();
COLORREF LIGHTRED();
COLORREF CYAN();
COLORREF LIGHTCYAN();
COLORREF MAGENTA();
COLORREF LIGHTMAGENTA();
COLORREF PINK();
COLORREF YELLOW();
COLORREF ORANGE();
COLORREF BROWN();
COLORREF WHITE();
COLORREF BLACK();
COLORREF DARKGREY();
COLORREF LIGHTGREY();
COLORREF GREY();
COLORREF MULTICOLOUR();

void Pen();

//}
//----------------------------------------------------------------------------------------------------------------------

namespace { namespace TX { namespace Win32 {
_TX_DLLIMPORT ("GDI32", HRGN, CreateRectRgn, (int x0, int y0, int x1, int y1));
}}}

//----------------------------------------------------------------------------------------------------------------------
//{  Функции
//----------------------------------------------------------------------------------------------------------------------

void txdrawGrafics (double start, double finish, double (*func) (double x, const double kF[]),
                     COLORREF colour(),    double increase, double /*radius*/, const double kF[])
    {
    double oldX = -11.35;
    double oldY = -11.35;

    txSetFillColour (TX_BLACK);

    HRGN region = Win32::CreateRectRgn (LeftOfTheGrafic, TopOfTheGrafic, RightOfTheGrafic, BottomOfTheGrafic);
    Win32::SelectObject (txDC(), region);

    double x = start;
    while (x <= finish)
        {
        txSetColour (colour(), 3);

        double y = func (x, kF);

        double grX =  x * Step + Xcentre;
        double grY = -y * Step + Ycentre;

        txLine (oldX, oldY, grX, grY);

        oldX = grX;
        oldY = grY;

        x += increase;
        }

    HRGN fullRegion = Win32::CreateRectRgn (0, 0, txGetExtentX(), txGetExtentY());
    Win32::SelectObject (txDC(), fullRegion);

    Win32::DeleteObject (region);
    }

//----------------------------------------------------------------------------------------------------------------------

void alphaBlend (double x, double y, double width, double height,
                 HDC image, double xImage, double yImage, double widthOriginal, double heightOriginal, double alpha, int pictureN)
    {
    BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) ROUND (alpha * 255), AC_SRC_ALPHA};

    if (pictureN == 2) width = width * 2;

    txGDI (Win32::AlphaBlend (txDC(), ROUND (x), ROUND (y), ROUND (width), ROUND (height),
           image, ROUND (xImage),  ROUND (yImage),  ROUND (widthOriginal), ROUND (heightOriginal), blend), txDC());
    }

//----------------------------------------------------------------------------------------------------------------------

void Pen()
    {
    HPEN pen = Win32::CreatePen (PS_DOT, 1, TX_RED);

    txSelectObject (pen);
    }

//----------------------------------------------------------------------------------------------------------------------
//{ Функции графиков
//----------------------------------------------------------------------------------------------------------------------

/*
double parabola (double x, double k, double b, double c)
    {
    return k * x*x + b*x + c;
    }
*/

double parabola (double x, const double kF[])
    {
    double k = kF [2];
    double b = kF [1];
    double c = kF [0];

    return k * x*x + b * x + c;
    }

//---------------------------------------------------------------------------------------------------------------------

double liner (double x, const double kF[])
    {
    return kF [1] * x + kF [0];
    }

//---------------------------------------------------------------------------------------------------------------------

double parabola_3 (double x, const double kF[])
    {
    return kF [2] * x*x*x + kF [1] / kF [0];
    }

//---------------------------------------------------------------------------------------------------------------------

double parabola_4 (double x, const double kF[])
    {
    return kF [2] * x*x*x*x + kF [1] / kF [0];
    }

//---------------------------------------------------------------------------------------------------------------------

double arc (double x, const double kF[])
    {
    double k = kF [2];
    double b = kF [1];
    double c = kF [0];

    return k * x*x/10 + b*x + c;
    }

//------------------------------------------------------------------------------------------------------------------------------------

double big_arc (double x, const double kF[])
    {
    return kF [2] * x*x/100 + kF [1] + kF [0];
    }

//---------------------------------------------------------------------------------------------------------------------------------

double some_sin (double x, const double kF[])
    {
    double k = kF [2];
    double b = kF [1];
    double c = kF [0];

    return k  * sin (x) * sin (x) * cos (x) + b * x + c;
    }

//------------------------------------------------------------------------------------------------------------------------------------

double more_parabols (double x, const double kF[])
    {
    return kF [2] * sin (x) / sin (x) / cos (x) + kF [1]*x + kF [0];
    }

//---------------------------------------------------------------------------------------------------------------------------

double big_sin (double x, const double kF[])
    {
    return kF [2] * sin (x) / tan (x) + kF [1]*x + kF [0];
    }

//-----------------------------------------------------------------------------------------------------------------------

double scliff (double x, const double kF[])
    {
    return kF [2] * sin (x) / tan (x) + x * x / 10 + kF [1]*x + kF [0];
    }

//----------------------------------------------------------------------------------------------------------------------------

double rope (double x, const double kF[])
    {
    return kF [2] * sin (x) / tan (x) + x * x / 100 + kF [1]*x + kF [0];
    }

//-----------------------------------------------------------------------------------------------------------------------------------

double waves (double x, const double kF[])
    {
    return kF [2] * sin (x) / tan (x) * x * x / 70 + kF [1]*x + kF [0];
    }

//----------------------------------------------------------------------------------------------------------------------------

double big_waves (double x, const double kF[])
    {
    return kF [2] * sin (x) / tan (x) * x * x / 10 + kF [1]*x + kF [0];
    }

//------------------------------------------------------------------------------------------------------------------------------

double radio_waves (double x, const double kF[])
    {
    return kF [2] * sin (x) / tan (x) * x * x / 10* (x / 2 + x - (x/2)) + kF [1]*x + kF [0];
    }

//-------------------------------------------------------------------------------------------------------------------------

double forest (double x, const double kF[])
    {
    return kF [2] * x*x * tan (x) * sin (x) * cos (x)/10 + kF [1]*x + kF [0];
    }

//---------------------------------------------------------------------------------------------------------------------------------
double small_forest (double x, const double kF[])
    {
    return kF [2] * x*x * tan (x) * sin (x) * cos (x)/100 + kF [1]*x + kF [0];
    }

//-------------------------------------------------------------------------------------------------------------------------------

double rainforest (double x, const double kF[])
    {
    return kF [2] * x*x * tan (x) * sin (x) * cos (x) * 100 + kF [1]*x + kF [0];
    }

//----------------------------------------------------------------------------------------------------------------------

double big_rainforest (double x, const double kF[])
    {
    return kF [2] * x*x * tan (x) * sin (x) * cos (x) + x/x + kF [1]*x + kF [0];
    }

//----------------------------------------------------------------------------------------------------------------------

double sinus (double x, const double kF[])
    {
    return kF [2] * sin (x * kF [1]) + kF [0];
    }

//----------------------------------------------------------------------------------------------------------------------

double cosinus (double x, const double kF[])
    {
    return kF [2] * cos (x) + kF [1] / kF [0];
    }

//----------------------------------------------------------------------------------------------------------------------
//}

//----------------------------------------------------------------------------------------------------------------------
//{ Функции цветов
//----------------------------------------------------------------------------------------------------------------------

COLORREF GREEN()
    {
    return TX_GREEN;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF LIGHTGREEN()
    {
    return TX_LIGHTGREEN;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF YELLOW()
    {
    return TX_YELLOW;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF ORANGE()
    {
    return TX_ORANGE;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF RED()
    {
    return TX_RED;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF LIGHTRED()
    {
    return TX_LIGHTRED;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF BLUE()
    {
    return TX_BLUE;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF LIGHTBLUE()
    {
    return TX_LIGHTBLUE;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF PINK()
    {
    return TX_PINK;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF WHITE()
    {
    return TX_WHITE;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF BLACK()
    {
    return TX_BLACK;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF BROWN()
    {
    return TX_BROWN;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF LIGHTGREY()
    {
    return TX_LIGHTGREEN;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF DARKGREY()
    {
    return TX_DARKGREY;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF MAGENTA()
    {
    return TX_MAGENTA;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF LIGHTCYAN ()
    {
    return TX_LIGHTCYAN;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF LIGHTMAGENTA()
    {
    return TX_LIGHTMAGENTA;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF CYAN()
    {
    return TX_CYAN;
    }

//----------------------------------------------------------------------------------------------------------------------

COLORREF MULTICOLOUR()
    {
    return rand() * rand()/64;
    }

//}
//}
//----------------------------------------------------------------------------------------------------------------------
