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
    explicit Vector (T xyz);
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

template <typename T>
inline Vector<T>::Vector (T xyz) :
    x (xyz),
    y (xyz),
    z (xyz)
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

//----------------------------------------------------------------------------

inline double Clamp (double value, double min, double max)
    {
    return (value < min)? min : (value > max)? max : value;
    }

//----------------------------------------------------------------------------

inline double Random (double min, double max)
    {
    return min + (max - min) * rand() / RAND_MAX;
    }

//============================================================================

void DrawScene (const vec& lightPos, double r);

vec PhongLightning (const vec& p, const vec& N, const vec& V,
                    const vec& lightPos, const vec& lightColor,
                    const vec& materialColor,
                    const vec& ambientColor = vec (0, 0, 0));

const vec Bump (const vec& p = vec(), double r = 0);

void DrawPixel (double x, double y, Vector<double> color);

//----------------------------------------------------------------------------

bool UseTxPixel = false;

//----------------------------------------------------------------------------

int main()
    {
    double r = 200;

    txCreateWindow (800, 600);
    txTextCursor (false);
    txBegin();

    static double perf = txQueryPerformance();
    
    txSetTextAlign (TA_CENTER);
    txSetColor (TX_DARKGRAY);
    txSelectFont ("Lucida Console", 15, 0);
    txTextOut (txGetExtentX()/2, txGetExtentY()*19/20, "Press Z, R, X, H to bump, T to use txSetPixel(), "
                                                       "ESC to exit");
    for (double t = txPI/2; ; t += 0.1)
        {
        DrawScene (vec (-2*r * (1 + cos (t)),
                        -2*r *      cos (t),
                        +2*r *      sin (t)), r);
        txSleep ();

        if (GetAsyncKeyState (VK_ESCAPE) && GetForegroundWindow() == txWindow()) break;

        /* For FPS testing only: */
        
        if (GetAsyncKeyState (VK_SPACE)) continue;
        UseTxPixel = GetAsyncKeyState ('T');

        static char s [128] = "";
        sprintf (s, "tx[Q]ueryPerformance(): %.2f. FPS %.2f. Using %s",
                    perf, txGetFPS(), (UseTxPixel? "txSetPixel" : "direct memory access"));
        SetWindowText (txWindow(), s);
        }

    txEnd();
    return 0;
    }

//----------------------------------------------------------------------------

void DrawScene (const vec& lightPos, double r)
    {
    const vec viewPos       (   0,    0, +5*r);
//  const vec lightPos      (-2*r, +2*r, +2*r);

    const vec materialColor (0.0, 1.0, 0.0);
    const vec lightColor    (1.0, 0.7, 0.0);
    const vec ambientColor  (0.2, 0.2, 0.2);

    for (double y = +r; y >= -r; y--)
    for (double x = -r; x <= +r; x++)
        {
        if (x*x + y*y > r*r) continue;

        vec p = vec (x, y, 0);
        p = p + Bump (p, r) * 100;
        if (p.x*p.x + p.y*p.y > r*r) { DrawPixel (x, y, vec (0)); continue; }

        p.z = sqrt (r*r - p.x*p.x - p.y*p.y);
        vec N = !p + Bump (p, r);

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
                                    vec (+2*r, -1*r,   0),
                                    vec ( 0.5,  0.5, 0.5),
                                    materialColor);
                                    
        DrawPixel (x, y, color);
        }
    }

//----------------------------------------------------------------------------

inline void DrawPixel (double x, double y, Vector<double> color)
    {
    static POINT scr = txGetExtent();

    POINT   p   = { (int) (x + scr.x/2 + 0.5),
                    (int) (y + scr.y/2 + 0.5) };

    RGBQUAD rgb = { (BYTE) (Clamp (color.x, 0, 1) * 255 + 0.5),
                    (BYTE) (Clamp (color.y, 0, 1) * 255 + 0.5),
                    (BYTE) (Clamp (color.z, 0, 1) * 255 + 0.5) };

    if (UseTxPixel)
         txSetPixel (p.x, p.y, RGB (rgb.rgbRed, rgb.rgbGreen, rgb.rgbBlue));
    else
         *(txVideoMemory() + p.x + (-p.y + scr.y) * scr.x) = rgb;
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

const vec Bump (const vec& p, double r)
    {
    bool bXY  = (GetAsyncKeyState ('X') != 0),
         bXY2 = (GetAsyncKeyState ('H') != 0),
         bZ   = (GetAsyncKeyState ('Z') != 0),
         bRnd = (GetAsyncKeyState ('R') != 0);

    if (!bXY && !bXY2 && !bZ && !bRnd) return vec (0);

    const int sz = 100;
    static vec env[sz][sz] = {};

    static bool init = false;
    if (!init)
        {
        for (int y = 0; y < sz; y++) for (int x = 0; x < sz; x++)
            env[y][x] = vec (Random (-1, +1), Random (-1, +1), Random (-1, +1));
            
        init = true;
        }

    vec bump (0);

    if (bXY)  bump += p * ((sin (p.x/4) + cos (p.y/4)) / 4 + 1.5) / 5000.0;
    if (bXY2) bump += p * ((cos (p.x/4) + sin (p.y/4)) / 2 + 1.0) / 3000.0;
    if (bZ)   bump += p * ( sin (p.z*p.z / 500)        / 2 + 1.5) / 5000.0;
    if (bRnd) bump += env [(unsigned) ROUND (p.y + r) % sz] [(unsigned) ROUND (p.x + r) % sz] / 100.0;

    return bump;
    }
