//{===========================================================================
//! @file       Examples\Demo\PhongDemo.cpp
//!
//! @brief      Этюд "Освещение по Фонгу"
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @date       2006
//! @author     Стас Артюхин, 9 класс
//          (C) Стас Артюхин, 9 класс, 2006
//}===========================================================================

#define _CRT_SECURE_NO_WARNINGS 1

#include "TXLib.h"

#if !defined (_TX_VER) || (_TX_VER < 0x172a0000)
#error Must use TXLib.h version >= 1.72 to compile this.
#endif

//============================================================================

template <typename T = double>
struct Vector
    {
    T x, y, z;

    Vector();
    Vector (T x0, T y0, T z0);
    };

typedef Vector<> vec;

//----------------------------------------------------------------------------

template <typename T>
inline Vector<T>::Vector() :
    x (0),
    y (0),
    z (0)
    {}

//----------------------------------------------------------------------------

template <typename T>
inline Vector<T>::Vector (T x0, T y0, T z0) :
    x (x0),
    y (y0),
    z (z0)
    {}

//----------------------------------------------------------------------------
// Normalization

template <typename T>
inline double len (const Vector<T>& v)
    {
    return sqrt (v.x*v.x + v.y*v.y + v.z*v.z);
    }

template <typename T>
inline Vector<T> operator ! (const Vector<T>& v)
    {
    return v / len (v);
    }

//----------------------------------------------------------------------------

template <typename T>
inline Vector<T>& operator += (Vector<T>& a, const Vector<T>& b)
    {
    a.x += b.x; a.y += b.y; a.z += b.z;
    return a;
    }

//----------------------------------------------------------------------------

template <typename T>
inline Vector<T> operator + (const Vector<T>& a, const Vector<T>& b)
    {
    return Vector<T> (a.x+b.x, a.y+b.y, a.z+b.z);
    }

//----------------------------------------------------------------------------

template <typename T>
inline Vector<T> operator - (const Vector<T>& a, const Vector<T>& b)
    {
    return Vector<T> (a.x-b.x, a.y-b.y, a.z-b.z);
    }

//----------------------------------------------------------------------------
// Non-vector product

template <typename T>
inline Vector<T> operator * (const Vector<T>& a, const Vector<T>& b)
    {
    return Vector<T> (a.x*b.x, a.y*b.y, a.z*b.z);
    }

//----------------------------------------------------------------------------
// Scalar (dot) product

template <typename T>
inline T operator ^ (const Vector<T>& a, const Vector<T>& b)
    {
    return a.x*b.x + a.y*b.y + a.z*b.z;
    }

//----------------------------------------------------------------------------

template <typename T, typename T2>
inline Vector<T> operator * (const Vector<T>& v, T2 val)
    {
    return Vector<T> (v.x*val, v.y*val, v.z*val);
    }

template <typename T, typename T2>
inline Vector<T> operator * (T2 val, const Vector<T>& v)
    {
    return v * val;
    }

//----------------------------------------------------------------------------

template <typename T>
inline Vector<T> operator / (const Vector<T>& v, T val)
    {
    return Vector<T> (v.x/val, v.y/val, v.z/val);
    }

//----------------------------------------------------------------------------

template <typename T>
inline std::ostream& operator << (std::ostream& o, const Vector<T>& v)
    {
    o << "Vector (" << v.x << ", " << v.y << ", " << v.z << ")";
    return o;
    }

//============================================================================

template <typename T>
inline void DrawPixel (T x, T y, Vector<T> color, bool useTxPixel = true, HDC dc = txDC())
    {
    static POINT scr = txGetExtent();

    POINT p = { ROUND (x + scr.x/2),
                ROUND (y + scr.y/2) };

    if (color.x > +1) color.x = +1; if (color.x < 0) color.x = 0;
    if (color.y > +1) color.y = +1; if (color.y < 0) color.y = 0;
    if (color.z > +1) color.z = +1; if (color.z < 0) color.z = 0;

    COLORREF rgb = RGB (ROUND (color.x * 255),
                        ROUND (color.y * 255),
                        ROUND (color.z * 255));
    if (useTxPixel)
             txSetPixel (    p.x, p.y, rgb);
    else
        Win32::SetPixel (dc, p.x, p.y, rgb);  // For FPS testing only
    }

//============================================================================

unsigned DrawScene (const vec& lightPos, double R,
                    bool tx = true, HDC dc = txDC()); // For FPS testing only

vec PhongLightning (const vec& p, const vec& N, const vec& V,
                    const vec& lightPos, const vec& lightColor,
                    const vec& materialColor,
                    const vec& ambientColor = vec (0, 0, 0));

const vec Bump (const vec& p = vec (0, 0, 0));

//----------------------------------------------------------------------------

int main()
    {
    double R = 200;

    txCreateWindow (800, 600);
    txTextCursor (false);
    txBegin();

    HDC wndDC = GetDC (txWindow());
    bool useTxPixel = true, useTxDC = true;

    txUpdateWindow (false);

    txSetTextAlign (TA_CENTER);
    txSetColor (TX_DARKGRAY);
    txSelectFont ("Lucida Console", 15, 0);
    txTextOut (txGetExtentX()/2, txGetExtentY()*19/20, "Alt, Ctrl, Shift, Space to bump");

    for (double t = txPI/2; ; t += 0.1)
        {
        if (useTxDC && !useTxPixel) txLock();    // For FPS testing only

        double time = DrawScene (vec (-2*R * (1 + cos (t)),
                                      -2*R *      cos (t),
                                      +2*R *      sin (t)),
                                 R,

                                 useTxPixel,
                                 useTxDC? txDC() : wndDC);

        if (useTxDC && !useTxPixel) txUnlock();  // For FPS testing only

        if (useTxDC) txSleep (0); else Sleep (0);

        /* For FPS testing only */

        useTxPixel = !GetAsyncKeyState ('P'),
        useTxDC    = !GetAsyncKeyState ('D');
        if (GetAsyncKeyState (VK_SPACE)) continue;
        if (GetAsyncKeyState (VK_ESCAPE) && GetForegroundWindow() == txWindow()) break;

        static double avr[5] = {0};
        static unsigned n = 0;

        avr [n++ % SIZEARR (avr)] = time;
        if  (n   < SIZEARR (avr)) continue;

        time = 0;
        for (unsigned i = 0; i < SIZEARR (avr); i++) time += avr[i];
        time /= SIZEARR (avr);

        static double perf = txQueryPerformance();
        if (GetAsyncKeyState ('Q')) perf = txQueryPerformance();

        static char s [128] = "";
        sprintf (s, "tx[Q]ueryPerformance(): %.2f. %.2f ms per frame. Using %sSet[P]ixel and %s[D]C",
                    perf, time, (useTxPixel? "tx" : ""), (useTxDC? "tx" : "Get"));
        SetWindowText (txWindow(), s);
        }

    ReleaseDC (txWindow(), wndDC);

    txEnd();
    return 0;
    }

//----------------------------------------------------------------------------

unsigned DrawScene (const vec& lightPos, double R, bool tx /*= true*/, HDC dc /*= txDC()*/)
    {
    const vec viewPos       (   0,    0, +5*R);
//  const vec lightPos      (-2*R, +2*R, +2*R);

    const vec materialColor (0.0, 1.0, 0.0);
    const vec lightColor    (1.0, 0.7, 0.0);
    const vec ambientColor  (0.2, 0.2, 0.2);

    unsigned time = GetTickCount();  // For FPS testing only
    srand (0);                       // Reset random sequence in Bump()

    for (double y = -R; y <= R; y++)
        for (double x = -R; x <= R; x++)
            {
            if (x*x + y*y > R*R) continue;

            vec p = vec (x, y, sqrt (R*R - x*x - y*y));
            vec N = !p + Bump (p);

            vec V = !(viewPos  - p);
            vec L = !(lightPos - p);

            double diffuse = N ^ L;
            if (diffuse < 0) diffuse = 0;

            vec Lr = 2*(N^L)*N - L;
            double spec = Lr ^ V;
            if (spec < 0) spec = 0;
            double specular = pow (spec, 25);

            vec color = ambientColor * materialColor              +

                        diffuse      * materialColor * lightColor +
                        specular     *                 lightColor +

                        PhongLightning (p, N, V,
                                        vec (+2*R, -1*R,   0),
                                        vec ( 0.5,  0.5, 0.5),
                                        materialColor);

            DrawPixel (x, y, color, tx, dc);
            }

    return GetTickCount() - time;    // For FPS testing only
    }

//----------------------------------------------------------------------------

vec PhongLightning (const vec& p, const vec& N, const vec& V,
                    const vec& lightPos, const vec& lightColor,
                    const vec& materialColor,
                    const vec& ambientColor)
    {
    vec L = !(lightPos - p);

    double diffuse = N ^ L;
    if (diffuse < 0) return ambientColor;

    vec Lr = 2*diffuse*N - L;
    double specular = pow (Lr ^ V, 25);

    return diffuse  * lightColor * materialColor +
           specular * lightColor +
           ambientColor;
    }

//----------------------------------------------------------------------------

const vec Bump (const vec& p)
    {
    vec bump = vec (0, 0, 0);

    if (GetAsyncKeyState (VK_MENU))    bump += p * ( sin (p.z*p.z / 500)        / 2 + 1.5)          / 5000.0;
    if (GetAsyncKeyState (VK_CONTROL)) bump += p * ((sin (p.x/4) + cos (p.y/4)) / 4 + 1.5)          / 5000.0;
    if (GetAsyncKeyState (VK_SHIFT))   bump += p * ((cos (p.x/4) + sin (p.y/4)) / 2 + 1.0)          / 1000.0;
    if (GetAsyncKeyState (VK_SPACE))   bump += vec (random (-1,+1), random (-1,+1), random (-1,+1)) /  100.0;

    return bump;
    }


