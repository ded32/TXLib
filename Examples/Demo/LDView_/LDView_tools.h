//{=========================================================================== 
//! @file       Examples\Demo\LDView_\LDView_Tools.h
//!
//! @brief      Этюд "Визуализатор графов", Misc tools
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:50:10 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#ifndef __LDVIEW_TOOLS_H

//-----------------------------------------------------------------------------

#include "TXLib.h"

#if !defined (_TX_VER) || (_TX_VER < 0x172a0000)
#error Must use TXLib.h version >= 1.72 to compile this.
#endif

//-----------------------------------------------------------------------------

__attribute__ (( format (printf, 5, 5+1) ))
void LabelCircle (POINT pos, int VertexSize, COLORREF color, int thickness,
                  const char* format = NULL, ...);

__attribute__ (( format (printf, 5, 5+1) ))
void LabelLine   (POINT p1, POINT p2,        COLORREF color, int thickness,
                  const char* format = NULL, ...);

int UpdateMouse();

//-----------------------------------------------------------------------------

void LabelCircle (POINT pos, int VertexSize, COLORREF color, int thickness,
                  const char* format, ...)
    {
    char s[10] = "";
    va_list arg; va_start (arg, format);
    if (format) vsprintf (s, format, arg);
    va_end (arg);

    txSetColor (RGB (64, 0, 0), thickness); txCircle  (pos.x+1, pos.y+0, VertexSize);
                                            txCircle  (pos.x+0, pos.y+1, VertexSize);
                                            txCircle  (pos.x+1, pos.y+1, VertexSize);

    txSetColor (color, thickness);          txCircle  (pos.x,   pos.y,   VertexSize);

    txTextOut (pos.x, pos.y + VertexSize/3, s);
    }

//-----------------------------------------------------------------------------

void LabelLine (POINT p1, POINT p2, COLORREF color, int thickness,
                const char* format, ...)
    {
    char s[10] = "";
    va_list arg; va_start (arg, format);
    if (format) vsprintf (s, format, arg);
    va_end (arg);

    txSetColor (RGB (64, 0, 0), thickness);  txLine (p1.x+1, p1.y+0, p2.x+1, p2.y+0);
                                             txLine (p1.x+0, p1.y+1, p2.x+0, p2.y+1);
                                             txLine (p1.x+1, p1.y+1, p2.x+1, p2.y+1);

    txSetColor (color, thickness);           txLine (p1.x,   p1.y,   p2.x,   p2.y);
    }

//-----------------------------------------------------------------------------

POINT MousePos        = {};
int   MouseButtons    = 0;
int   OldMouseButtons = 0;

int UpdateMouse()
    {
    MousePos.x = txMouseX();
    MousePos.y = txMouseY();

    OldMouseButtons = MouseButtons;
    MouseButtons = txMouseButtons();

    return (MouseButtons)? MouseButtons ^ OldMouseButtons : 0;
    }

//-----------------------------------------------------------------------------

#define BEGIN_NAMESPACE( name ) namespace name {
#define END_NAMESPACE(   name ) }

//-----------------------------------------------------------------------------

BEGIN_NAMESPACE (a_bit_of_vector_algebra)

double Distance (POINT p1, POINT p2);
double Distance (POINT p, POINT a, POINT b);

//-----------------------------------------------------------------------------

struct vec2d
    {
    double x, y;

    vec2d (POINT p)              : x (p.x), y (p.y) {}
    vec2d (double px, double py) : x (px),  y (py)  {}
    vec2d (double r)             : x (r),   y (r)   {}

    operator POINT() { POINT p = { (int) round (x), (int) round (y) }; return p; }
    };

//-----------------------------------------------------------------------------

inline vec2d operator + (const vec2d& a, const vec2d& b) { return vec2d (a.x + b.x, a.y + b.y); }
inline vec2d operator - (const vec2d& a, const vec2d& b) { return vec2d (a.x - b.x, a.y - b.y); }

inline vec2d operator * (double d, const vec2d& v)       { return vec2d (v.x * d, v.y * d);     }
inline vec2d operator * (const vec2d& v, double d)       { return vec2d (v.x * d, v.y * d);     }

inline vec2d operator / (const vec2d& v, double d)       { return vec2d (v.x / d, v.y / d);     }

inline double dot (const vec2d& a, const vec2d& b)       { return (a.x * b.x) + (a.y * b.y);    }

inline double length (const vec2d& v)                    { return sqrt (dot (v, v));            }
inline vec2d  norm   (const vec2d& v)                    { return v / length (v);               }

inline vec2d proj    (const vec2d& a, const vec2d& b)    { return b * (dot (a, b) / dot (b, b)); }

//-----------------------------------------------------------------------------

double Distance (POINT p1, POINT p2)
    {
    return length (p1 - p2);
    }

//-----------------------------------------------------------------------------

double Distance (POINT p, POINT a, POINT b)
    {
    vec2d ba (b - a),
          pa (p - a),
          pb (p - b);

    if (dot (pa, ba) <= 0) return length (pa);  // PAB is obtuse, A is the closest point to P
    if (dot (pb, ba) >= 0) return length (pb);  // PAB is acute,  B is the closest point to P

    return length (pa - proj (pa, ba));         // PA minus projection PA to BA
    }

//-----------------------------------------------------------------------------

END_NAMESPACE (a_bit_of_vector_algebra)

//-----------------------------------------------------------------------------

inline double Random (double min, double max)
    {
    return min + (max - min) * rand() / RAND_MAX;
    }

#endif




