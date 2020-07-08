//{================================================================================================================
//! @file       Examples\Demo\TXGL.cpp
//!
//! @brief      TXLib OpenGL Demo
//!
//!             А вы как думали?
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:51:05 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}================================================================================================================

#include "TXLib.h"

#include "GL\gl.h"
#include "GL\glu.h"

#if !defined (_TX_VER) || (_TX_VER < 0x173a0165)
#error Must use TXLib.h version >= 1.73 and revision >= 165 to compile this. -- Ded
#endif

//=================================================================================================================
//{          OpenGL support
//! @name    Поддержка OpenGL
//=================================================================================================================

typedef float vec4f[4];

const vec4f TX_GL_BLACK = {0, 0,    0, 1},
            TX_GL_RED   = {1, 0,    0, 1},
            TX_GL_GREEN = {0, 1,    0, 1},
            TX_GL_BLUE  = {0, 0.25, 1, 1},
            TX_GL_WHITE = {1, 1,    1, 1};

HGLRC txglCreateContext (HDC dc);
bool  txglDeleteContext (HGLRC rc);
bool  txglSetDefaults();
void  txglSwapBuffers();

void  txglClear     (double red, double green, double blue, double alpha = 0);
void  txgluSphere   (double radius, int slices = 100, int stacks = 100);
void  txgluDisk     (double innerRadius, double outerRadius, int slices = 100, int loops = 100);
void  txgluCylinder (double baseRadius, double topRadius, double height, int slices = 100, int stacks = 100);
void  txglTextOut   (double x, double y, const char* text);

bool  txglLight     (int light, double x, double y, double z, 
                     double ambient, double diffuse, double specular);
bool  txglMaterial  (double specular, double emittance, double shining);
bool  txglSetCamera (POINT size, bool perspective = true);

//-----------------------------------------------------------------------------------------------------------------

namespace { namespace TX { namespace Win32 {

_TX_DLLIMPORT ("OpenGL32", void,        glBlendFunc,         (int sFactor, int dFactor));
_TX_DLLIMPORT ("OpenGL32", void,        glClear,             (GLbitfield mask));
_TX_DLLIMPORT ("OpenGL32", void,        glClearAccum,        (float red, float green, float blue, float alpha));
_TX_DLLIMPORT ("OpenGL32", void,        glClearColor,        (float red, float green, float blue, float alpha));
_TX_DLLIMPORT ("OpenGL32", void,        glClearDepth,        (double depth));
_TX_DLLIMPORT ("OpenGL32", void,        glClearIndex,        (float color));
_TX_DLLIMPORT ("OpenGL32", void,        glClearStencil,      (int stencil));
_TX_DLLIMPORT ("OpenGL32", void,        glColor3d,           (double red, double green, double blue));
_TX_DLLIMPORT ("OpenGL32", void,        glColor3dv,          (const double* color));
_TX_DLLIMPORT ("OpenGL32", void,        glColor4d,           (double red, double green, double blue, double alpha));
_TX_DLLIMPORT ("OpenGL32", void,        glColor4dv,          (const double* color));
_TX_DLLIMPORT ("OpenGL32", void,        glDepthFunc,         (int func));
_TX_DLLIMPORT ("OpenGL32", void,        glDisable,           (int cap));
_TX_DLLIMPORT ("OpenGL32", void,        glDisableClientState,(int array));
_TX_DLLIMPORT ("OpenGL32", void,        glEnable,            (int cap));
_TX_DLLIMPORT ("OpenGL32", void,        glEnableClientState, (int array));
_TX_DLLIMPORT ("OpenGL32", void,        glHint,              (int target, int mode));
_TX_DLLIMPORT ("OpenGL32", void,        glLightfv,           (int light, int name, const float* params));
_TX_DLLIMPORT ("OpenGL32", void,        glLoadIdentity,      (void));
_TX_DLLIMPORT ("OpenGL32", void,        glMaterialf,         (int face, int name, float param));
_TX_DLLIMPORT ("OpenGL32", void,        glMaterialfv,        (int face, int name, const float* params));
_TX_DLLIMPORT ("OpenGL32", void,        glMatrixMode,        (int mode));
_TX_DLLIMPORT ("OpenGL32", void,        glOrtho,             (double left, double right, double bottom, double top, double zNear, double zFar));
_TX_DLLIMPORT ("OpenGL32", void,        glPixelStorei,       (int pName, int param));
_TX_DLLIMPORT ("OpenGL32", void,        glPixelZoom,         (float xFactor, float yFactor));
_TX_DLLIMPORT ("OpenGL32", void,        glPointSize,         (float size));
_TX_DLLIMPORT ("OpenGL32", void,        glShadeModel,        (int mode));
_TX_DLLIMPORT ("OpenGL32", void,        glCallLists,         (unsigned size, int type, const void* lists));
_TX_DLLIMPORT ("OpenGL32", void,        glDeleteLists,       (unsigned list, int range));
_TX_DLLIMPORT ("OpenGL32", void,        glFlush,             (void));
_TX_DLLIMPORT ("OpenGL32", void,        glListBase,          (unsigned base));
_TX_DLLIMPORT ("OpenGL32", void,        glMateriali,         (int face, int name, int param));
_TX_DLLIMPORT ("OpenGL32", void,        glRasterPos2d,       (double x, double y));
_TX_DLLIMPORT ("OpenGL32", void,        glRotated,           (double angle, double x, double y, double z));
_TX_DLLIMPORT ("OpenGL32", void,        glTranslated,        (double x, double y, double z));
_TX_DLLIMPORT ("OpenGL32", void,        glViewport,          (int x, int y, int width, int height));
_TX_DLLIMPORT ("OpenGL32", HGLRC,       wglCreateContext,    (HDC dc));
_TX_DLLIMPORT ("OpenGL32", bool,        wglDeleteContext,    (HGLRC context));
_TX_DLLIMPORT ("OpenGL32", bool,        wglMakeCurrent,      (HDC dc, HGLRC context));
_TX_DLLIMPORT ("OpenGL32", bool,        wglUseFontBitmapsA,  (HDC dc, DWORD first, DWORD count, DWORD listBase));
                                       
_TX_DLLIMPORT ("GLU32",    GLUquadric*, gluNewQuadric,       (void));
_TX_DLLIMPORT ("GLU32",    void,        gluDeleteQuadric,    (GLUquadric* state));
_TX_DLLIMPORT ("GLU32",    void,        gluCylinder,         (GLUquadric *obj, double baseRadius, double topRadius, double height, int slices, int stacks));
_TX_DLLIMPORT ("GLU32",    void,        gluDisk,             (GLUquadric* obj, double innerRadius, double outerRadius, int slices, int loops));
_TX_DLLIMPORT ("GLU32",    void,        gluSphere,           (GLUquadric* obj, double radius, int slices, int stacks));
_TX_DLLIMPORT ("GLU32",    void,        gluLookAt,           (double eyeX, double eyeY, double eyeZ, double centerX, double centerY, double centerZ, double upX, double upY, double upZ));
_TX_DLLIMPORT ("GLU32",    void,        gluPerspective,      (double fovy, double aspect, double zNear, double zFar));

_TX_DLLIMPORT ("GDI32",    int,         ChoosePixelFormat,   (HDC dc, const PIXELFORMATDESCRIPTOR* pPfd));
_TX_DLLIMPORT ("GDI32",    int,         DescribePixelFormat, (HDC dc, int numPfd, unsigned szPfd, const PIXELFORMATDESCRIPTOR* pfd));
_TX_DLLIMPORT ("GDI32",    bool,        SetPixelFormat,      (HDC dc, int numPfd, const PIXELFORMATDESCRIPTOR* pfd));
_TX_DLLIMPORT ("GDI32",    bool,        SwapBuffers,         (HDC dc));

}}}

//=================================================================================================================

HGLRC txglCreateContext (HDC dc)
    {
    PIXELFORMATDESCRIPTOR pfd = {0};

    pfd.nSize       = (WORD) sizeof (pfd);
    pfd.nVersion    = 1;
                   
    pfd.dwFlags     = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
                   
    pfd.iLayerType  = PFD_MAIN_PLANE;
    pfd.iPixelType  = PFD_TYPE_RGBA;
    pfd.cColorBits  = 24;
    pfd.cDepthBits  = 32;

    pfd.cAuxBuffers = 0; 

    int index = Win32::ChoosePixelFormat (dc, &pfd);

    if (!index) index = 1;

    if (!Win32::DescribePixelFormat (dc, index, sizeof (pfd), &pfd)) return 0;
    if (!Win32::SetPixelFormat (dc, index, &pfd)) return 0;

    HGLRC rc = Win32::wglCreateContext (dc); rc asserted;
    Win32::wglMakeCurrent (dc, rc)              asserted;

    txglSetDefaults();
    txglSetCamera (txGetExtent (dc), false);

    return rc;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txglDeleteContext (HGLRC rc)
    {
    if (!rc) return false;

    Win32::glDeleteLists (0, INT_MAX);

    Win32::wglMakeCurrent (NULL, NULL) asserted;
    Win32::wglDeleteContext (rc)       asserted;

    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txglSetDefaults()
    {
    Win32::glEnable (GL_DEPTH_TEST);                           !tx_glGetError() asserted;
    Win32::glEnable (GL_ALPHA_TEST);                           !tx_glGetError() asserted;
    Win32::glEnable (GL_BLEND);                                !tx_glGetError() asserted;
    Win32::glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); !tx_glGetError() asserted;

    Win32::glEnable (GL_POINT_SMOOTH);                         !tx_glGetError() asserted;
    Win32::glEnable (GL_LINE_SMOOTH);                          !tx_glGetError() asserted;
    Win32::glShadeModel (GL_SMOOTH);                           !tx_glGetError() asserted;
    
    Win32::glPixelStorei (GL_UNPACK_ALIGNMENT, 1);             !tx_glGetError() asserted;

    Win32::glPointSize (2);                                    !tx_glGetError() asserted;
    
    Win32::wglUseFontBitmaps (txDC(), 0, 256, 1000); 
    Win32::glListBase (1000); 

    txglMaterial (0.6, 0.1, 0.5) asserted;

    txglLight (0,  1000, 1000,  1000, 0.2, 0.4, 0.6) asserted;
    txglLight (1, -1000,  100,  -500, 0.1, 0.4, 0.2) asserted;
    txglLight (2,   500,  500, -1000, 0.0, 0.8, 0.0) asserted;

    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txglLight (int light, double x, double y, double z, 
                double ambient, double diffuse, double specular)
    {
    Win32::glEnable (GL_LIGHTING);       !tx_glGetError() asserted;
    Win32::glEnable (GL_LIGHT0 + light); !tx_glGetError() asserted;
    
    float  pos[4] = {(float)x, (float)y, (float)z};                      
    float  amb[4] = {(float)ambient,  (float)ambient,  (float)ambient};  
    float diff[4] = {(float)diffuse,  (float)diffuse,  (float)diffuse};  
    float spec[4] = {(float)specular, (float)specular, (float)specular}; 

    Win32::glLightfv (GL_LIGHT0 + light, GL_POSITION,  pos); !tx_glGetError() asserted;
    Win32::glLightfv (GL_LIGHT0 + light, GL_AMBIENT,   amb); !tx_glGetError() asserted;
    Win32::glLightfv (GL_LIGHT0 + light, GL_DIFFUSE,  diff); !tx_glGetError() asserted;
    Win32::glLightfv (GL_LIGHT0 + light, GL_SPECULAR, spec); !tx_glGetError() asserted;

    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txglMaterial (double specular, double emittance, double shining)
    {
    Win32::glEnable (GL_COLOR_MATERIAL); !tx_glGetError() asserted;

    float spec[4] = {(float)specular,  (float)specular,  (float)specular,  1.0f}; 
    float emit[4] = {(float)emittance, (float)emittance, (float)emittance, 1.0f}; 

    Win32::glMateriali  (GL_FRONT_AND_BACK, GL_SHININESS, (int) (shining*128)); !tx_glGetError() asserted;
    Win32::glMaterialfv (GL_FRONT_AND_BACK, GL_SPECULAR,  spec);                !tx_glGetError() asserted;
    Win32::glMaterialfv (GL_FRONT_AND_BACK, GL_EMISSION,  emit);                !tx_glGetError() asserted;

    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txglSetCamera (POINT size, bool perspective /*= true*/)
    {
    Win32::glViewport (0, 0, size.x, size.y); !tx_glGetError() asserted;

    Win32::glMatrixMode (GL_PROJECTION);      !tx_glGetError() asserted;
    Win32::glLoadIdentity();                  !tx_glGetError() asserted;

    if (perspective) { Win32::gluPerspective (40, 1.0*size.x/size.y, 1, 1001);                 !tx_glGetError() asserted; }
    else             { Win32::glOrtho (-size.x/2, size.x/2, -size.y/2, size.y/2, -1000, 1000); !tx_glGetError() asserted; }

    Win32::gluLookAt (0,0,500, 0,0,0, 0,1,0); !tx_glGetError() asserted;

    Win32::glMatrixMode (GL_MODELVIEW);       !tx_glGetError() asserted;

    return true;
    }    

//-----------------------------------------------------------------------------------------------------------------

void txglClear (double red, double green, double blue, double alpha /*= 0*/)
    {
    Win32::glClearColor ((float) red, (float) green, (float) blue, (float) alpha);

    Win32::glClear (GL_COLOR_BUFFER_BIT);
    Win32::glClear (GL_DEPTH_BUFFER_BIT);
    }

//-----------------------------------------------------------------------------------------------------------------

void txgluSphere (double radius, int slices /*= 100*/, int stacks /*= 100*/)
    {
    GLUquadricObj* obj = Win32::gluNewQuadric();
    Win32::gluSphere (obj, radius, slices, stacks);
    Win32::gluDeleteQuadric (obj);
    }

//-----------------------------------------------------------------------------------------------------------------

void txgluCylinder (double baseRadius, double topRadius, double height, int slices /*= 100*/, int stacks /*= 100*/)
    {
    GLUquadricObj* obj = Win32::gluNewQuadric();
    Win32::gluCylinder (obj, baseRadius, topRadius, height, slices, stacks);
    Win32::gluDeleteQuadric (obj);
    }

//-----------------------------------------------------------------------------------------------------------------

void txgluDisk (double innerRadius, double outerRadius, int slices /*= 100*/, int loops /*= 100*/)
    {
    GLUquadricObj* obj = Win32::gluNewQuadric();
    Win32::gluDisk (obj, innerRadius, outerRadius, slices, loops);
    Win32::gluDeleteQuadric (obj);
    }

//-----------------------------------------------------------------------------------------------------------------

void txglTextOut (double x, double y, const char* text)
    {
    Win32::glRasterPos2d (x, y);
    Win32::glCallLists ((unsigned) strlen (text), GL_UNSIGNED_BYTE, text); 
    }

//-----------------------------------------------------------------------------------------------------------------

void txglSwapBuffers()
    {
    Win32::glFlush();
    Win32::SwapBuffers (Win32::wglGetCurrentDC());
    }

//}
//=================================================================================================================

void DrawBackgr (int mode);
void DrawBackgr (int mode)
    {
    COLORREF white = RGB (24, 24, 32), red = RGB (32, 0, 0), blue = RGB ( 0, 0, 32);
    POINT sz = txGetExtent();

    // For tests only. Do not use for brexit() purposes

    if (mode == 1)
        {
        txSetColor (TX_NULL); txSetFillColor (blue); txRectangle (0, 0, sz.x, sz.y);
        txSetColor (white, 75); txLine (0, 0, sz.x, sz.y); txLine (0, sz.y, sz.x, 0);
        txSetColor (red,   25); txLine (0, 0, sz.x, sz.y); txLine (0, sz.y, sz.x, 0);
        }
    else
        {
        txSetColor (white, 100); txLine (0, sz.y/2, sz.x, sz.y/2); txLine (sz.x/2, 0, sz.x/2, sz.y);
        txSetColor (red,    50); txLine (0, sz.y/2, sz.x, sz.y/2); txLine (sz.x/2, 0, sz.x/2, sz.y);
        }
    }

//-----------------------------------------------------------------------------------------------------------------

void DrawModel (double rotation);
void DrawModel (double rotation)
    {
    txglClear (0, 0, 0);
    
    Win32::glLoadIdentity();
    Win32::glRotated (rotation, 1, 0, 1);
    
    Win32::glTranslated (0, 0, -50);

    Win32::glColor3d (1, 0, 0);
    txgluSphere   (75);
    
    Win32::glColor3d (0, 0, 1);
    txgluCylinder (50, 50, 150);
    txgluCylinder (40, 40, 150);
    txgluDisk     (40, 50);
    
    Win32::glTranslated (0, 0, 150);
    
    txgluDisk     (40, 50);
    
    Win32::glLoadIdentity();

    Win32::glColor3d (1, 1, 0);
    txglTextOut (-100, +250, "Это кто? (Who?)"); 
    txglTextOut (-120, +220, "Это тестовый объект.");
    txglTextOut (- 70, +190, "Cats rules.");

    Win32::glColor3d (0, 1, 0);
    txglTextOut (-250, -220, "A quick brown fox jums over the lazy dog."); 
    txglTextOut (-330, -250, "В чащах юга жил-был цитрус, да, но фальшивый экземпляр.");
    txglTextOut (- 30, -280, "Meow.");
    }

//-----------------------------------------------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);

    txBegin();
    txLock();

    DrawBackgr (1);
    
    HDC   dc = GetDC (txWindow());
    HGLRC rc = txglCreateContext (dc); rc asserted;
    
    for (double rotation = 0; !txGetAsyncKeyState (VK_ESCAPE); )
        {
        DrawBackgr (2);

        double fps = txGetFPS();
        if (fps > 0) rotation += 50/fps;

        DrawModel (rotation);
        
        if (fps > 0) txglSwapBuffers();
        Sleep (50);
        }

    txUnlock();
    txEnd();

    txglDeleteContext (rc) asserted;
    ReleaseDC (txWindow(), dc);
    }

