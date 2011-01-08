
#if !defined (__TXLIB_H) || defined (_TX_MULTIPLE_INSTANCE)
#define       __TXLIB_H

#define _TX_VERSION           "TXLib [Version 0.01 alpha, build 72]"
#define _TX_AUTHOR            "Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)"

#define _TX                   0x0001720a

#ifndef __cplusplus
    #error TXLib.h: Must use C++ to compile this
#endif

#ifdef __STRICT_ANSI__
    #warning TXLib.h: Trying to extend strict ANSI compatibility
    #undef __STRICT_ANSI__
#endif

#if defined (__GNUC__)

    #if (__GNUC__ >= 4)
        #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
        #pragma GCC diagnostic ignored "-Wunreachable-code"
    #endif

    #define _TX_CHECK_FORMAT( fmtIdx )  __attribute__ (( format (printf, (fmtIdx), (fmtIdx)+1) ))
    #define _TX_CHECK_USAGE             __attribute__ (( warn_unused_result ))

#else

    #define _TX_CHECK_FORMAT( fmtIdx )
    #define _TX_CHECK_USAGE

#endif

#if defined (_MSC_VER)

    #pragma warning (push, 4)
    #pragma warning (disable: 4127)
    #pragma warning (disable: 4351)

    #define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

#endif

#if defined (_MSC_VER) && (_MSC_VER == 1200)

    #pragma warning (push, 3)
    #pragma warning (disable: 4663)

    #if !defined (WINVER)
        #define WINVER   0x0400
    #endif

#endif

#if defined (_MSC_VER) && (_MSC_VER >= 1400)

    #define _TX_USE_SECURE_CRT

#else

    #define  strncpy_s              strncpy
    #define  strncat_s              strncat
    #define  ctime_s                ctime
    #define _snprintf_s            _snprintf
    #define _vsnprintf_s           _vsnprintf
    #define  strerror_s(buf,code)   strerror (code)

#endif

#if defined (__INTEL_COMPILER)

#endif

#ifndef     WINVER
    #define WINVER       0x0500
    #define WINDOWS_ENABLE_CPLUSPLUS
#endif

#ifndef     _WIN32_WINNT
    #define _WIN32_WINNT WINVER
#endif

#undef   UNICODE
#undef  _UNICODE

#undef  _TX_ANON_NSPACE

#ifdef  _TX_MULTIPLE_INSTANCE
    #define _TX_ANON_NSPACE  _TX_MULTIPLE_INSTANCE
#else
    #define _TX_ANON_NSPACE
#endif

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <direct.h>
#include <process.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <assert.h>

#include <iostream>
#include <algorithm>

#include <conio.h>

#include <windows.h>
#include <tlhelp32.h>

#if defined (_MSC_VER) && (_MSC_VER == 1200)
    #pragma warning (push, 4)
#endif

#ifndef TX_COUNTER
#define TX_COUNTER _tx_Counter

inline int _tx_Counter()
    {
    static int count = 1;
    return count++;
    }

#endif

namespace _TX_ANON_NSPACE {  namespace TX {

const COLORREF
    TX_BLACK         = RGB (  0,   0,   0),
    TX_BLUE          = RGB (  0,   0, 128),
    TX_GREEN         = RGB (  0, 128,   0),
    TX_CYAN          = RGB (  0, 128, 128),
    TX_RED           = RGB (128,   0,   0),
    TX_MAGENTA       = RGB (128,   0, 128),
    TX_BROWN         = RGB (128, 128,   0),
    TX_ORANGE        = RGB (255, 128,   0),
    TX_GRAY          = RGB (160, 160, 160),
    TX_DARKGRAY      = RGB (128, 128, 128),
    TX_LIGHTGRAY     = RGB (192, 192, 192),
    TX_LIGHTBLUE     = RGB (  0,   0, 255),
    TX_LIGHTGREEN    = RGB (  0, 255, 128),
    TX_LIGHTCYAN     = RGB (  0, 255, 255),
    TX_LIGHTRED      = RGB (255,   0, 128),
    TX_LIGHTMAGENTA  = RGB (255,   0, 255),
    TX_PINK          = RGB (255, 128, 255),
    TX_YELLOW        = RGB (255, 255, 128),
    TX_WHITE         = RGB (255, 255, 255),
    TX_TRANSPARENT   = 0xFFFFFFFF,
    TX_NULL          = TX_NULL,

    TX_HUE          = 0x04000000,
    TX_SATURATION   = 0x05000000,
    TX_LIGHTNESS    = 0x06000000;

int txCreateWindow (int sizeX, int sizeY, bool centered = true);
bool txSetDefaults();
inline bool txOK();
POINT txGetExtent();
int txGetExtentX();
int txGetExtentY();
inline HDC& txDC();
inline HWND txWindow();
inline const char* txVersion();
inline unsigned txVersionNumber();
const char* txGetModuleFileName (bool fileNameOnly = true);
bool txSetColor (COLORREF color, int thickness = 1);
bool txColor (double red, double green, double blue);
COLORREF txGetColor();
bool txSetFillColor (COLORREF color);
bool txFillColor (double red, double green, double blue);
COLORREF txGetFillColor();
bool txSetROP2 (int mode = R2_COPYPEN);
int txExtractColor (COLORREF color, COLORREF component);
COLORREF txRGB2HSL (COLORREF rgbColor);
COLORREF txHSL2RGB (COLORREF hslColor);
bool txClear();
inline bool txSetPixel (int x, int y, COLORREF color);
inline bool txPixel (int x, int y, int red, double green, double blue);
inline COLORREF txGetPixel (int x, int y);
bool txLine (int x0, int y0, int x1, int y1);
bool txRectangle (int x0, int y0, int x1, int y1);
bool txPolygon (const POINT points[], int numPoints);
bool txEllipse (int x0, int y0, int x1, int y1);
bool txCircle (int x, int y, int r);
bool txArc (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);
bool txPie (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);
bool txChord (int x0, int y0, int x1, int y1, int startAngle, int totalAngle);
bool txFloodFill (int x, int y, COLORREF color = TX_TRANSPARENT, DWORD mode = FLOODFILLSURFACE);
bool txTextOut (int x, int y, const char text[]);
bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format = DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_MODIFYSTRING | DT_PATH_ELLIPSIS);
bool txSelectFont (const char name[], int sizeY, int sizeX = -1, int bold = FW_DONTCARE,
                   bool italic = false, bool underline = false, bool strikeout = false);
SIZE txGetTextExtent (const char text[]);
int txGetTextExtentX (const char text[]);
int txGetTextExtentY (const char text[]);
unsigned txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE);
LOGFONT* txFontExist (const char name[]);
HDC txCreateCompatibleDC (int sizeX, int sizeY, HBITMAP bitmap = NULL);
HDC txLoadImage (const char filename[]);
bool txDeleteDC (HDC  dc);
bool txDeleteDC (HDC* dcPtr);
bool txBitBlt (HDC dest, int xDest, int yDest, int width, int height,
               HDC src,  int xSrc,  int ySrc,  DWORD rOp = SRCCOPY);
bool txTransparentBlt (HDC dest, int xDest, int yDest, int width, int height,
                       HDC src,  int xSrc,  int ySrc,  COLORREF transColor = TX_BLACK);
bool txAlphaBlend (HDC dest, int xDest, int yDest, int width, int height,
                   HDC src,  int xSrc,  int ySrc,  double alpha = 1.0);
inline int txBegin();
inline int txEnd();
bool txSleep (int time);
inline int txUpdateWindow (int update = true);
HRGN txSelectRegion (int x0, int y0, int x1, int y1);
bool txSelectObject (HGDIOBJ obj);
bool txTextCursor (bool blink = true);
bool txDestroyWindow();
bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture();
inline POINT txMousePos();
inline int txMouseX();
inline int txMouseY();
inline int txMouseButtons();
bool txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC);
double txQueryPerformance();

#define SIZEARR( arr )    ( sizeof (get_size_of_an_array_with_unknown_or_nonconst_size_ (arr)) )
#define sizearr( arr )    ( sizeof (arr) / sizeof (arr)[0] )

template <typename T, int N> char (&get_size_of_an_array_with_unknown_or_nonconst_size_ (T (&) [N])) [N];

template <typename T>
inline bool In (T x, T a, T b)
    {
    return a <= x && x <= b;
    }

inline bool In (const POINT& pt, const RECT& rect)
    {
    return In (pt.x, rect.left, rect.right) &&
           In (pt.y, rect.top,  rect.bottom);
    }

inline bool In (const COORD& pt, const SMALL_RECT& rect)
    {
    return In (pt.X, rect.Left, rect.Right) &&
           In (pt.Y, rect.Top,  rect.Bottom);
    }

inline int random (int range)
    {
    return rand() % range;
    }

template <typename T, typename T1, typename T2>
inline T random (T1 left, T2 right)
    {
    return left + (right - left) * ((double) rand() / RAND_MAX);
    }

#define MAX( a, b )  ( (a) > (b) ? (a) : (b) )

#define MIN( a, b )  ( (a) < (b) ? (a) : (b) )

const double txPI = asin (1.0) * 2;

WNDPROC txSetWindowHandler (WNDPROC handler = NULL);

inline bool txLock (bool wait = true);

inline bool txUnlock();

template <typename T> inline T txUnlock (T value);

#define txGDI( command )  txUnlock ( (txLock(), (command)) )

#ifndef        _TX_CONSOLE_MODE
    #define    _TX_CONSOLE_MODE           SWP_HIDEWINDOW
#endif

const char     _TX_CONSOLE_FONT[]         = "Lucida Console";

const COLORREF _TX_CONSOLE_COLOR          = TX_LIGHTGRAY;

const unsigned _TX_CURSOR_BLINK_INTERVAL  = 250;

const int      _TX_WINDOW_UPDATE_INTERVAL = 10;

const int      _TX_TIMEOUT                = 1000;

#define  TX_QUOTE( symbol )   _TX_QUOTE (symbol)
#define _TX_QUOTE( symbol )   #symbol

#if   defined (__GNUC__)
    #define __TX_COMPILER__   "GNU C++ "            TX_QUOTE (__GNUC__)       "."  \
                                                    TX_QUOTE (__GNUC_MINOR__) "."  \
                                                    TX_QUOTE (__GNUC_PATCHLEVEL__) \
                                         ", C++ = " TX_QUOTE (__cplusplus)
#elif defined (_MSC_VER)
    #define __TX_COMPILER__   "Microsoft C++ "      TX_QUOTE (_MSC_VER) \
                                         ", C++ = " TX_QUOTE (__cplusplus)

#elif defined (__INTEL_COMPILER)
    #define __TX_COMPILER__   "Intel C++ Compiler " TX_QUOTE (__INTEL_COMPILER) \
                                         ", C++ = " TX_QUOTE (__cplusplus)

#else
    #define __TX_COMPILER__   "Unknown compiler" \
                                         ", C++ = " TX_QUOTE (__cplusplus)
#endif

#if   !defined (NDEBUG) &&  defined (_DEBUG)
    #define _TX_BUILDMODE     "DEBUG"

#elif !defined (NDEBUG) && !defined (_DEBUG)
    #define _TX_BUILDMODE     "Debug"

#elif  defined (NDEBUG)
    #define _TX_BUILDMODE     "Release"
#endif

#define __TX_FILELINE__       __FILE__ " (" TX_QUOTE (__LINE__) ")"

#if defined (__GNUC__)
    #define __TX_FUNCTION__   __PRETTY_FUNCTION__

#elif defined (__FUNCSIG__)
    #define __TX_FUNCTION__   __FUNCSIG__

#elif defined (__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)
    #define __TX_FUNCTION__   __FUNCTION__

#elif defined (__BORLANDC__) && (__BORLANDC__ >= 0x550)
    #define __TX_FUNCTION__   __FUNC__

#elif defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
    #define __TX_FUNCTION__   __func__

#else
    #define __TX_FUNCTION__   "(" __TX_FILELINE__ ")"

#endif

#undef  assert

#ifndef NDEBUG
    #define assert( cond )    ( !!(cond) || TX_ERROR ("\a" "Логическая ошибка: Неверно, что \"%s\"" _ #cond), 0 )

#else
    #define assert( cond )    ( 0 )

#endif

#ifndef NDEBUG
    #define asserted          || TX_ERROR ("\a" "Обнаружен нулевой или ложный результат")

#else
    #define asserted

#endif

#define TX_NEEDED             asserted

#ifndef NDEBUG
    #define TX_ERROR( msg )   ( _tx_Error (__FILE__, __LINE__,                                 \
                                          ((*__TX_FUNCTION__ != '(')? __TX_FUNCTION__ : NULL), \
                                          (DWORD)(-1), -1, -1, msg), 0 )

#else
    #define TX_ERROR(msg)     ( 0 )

#endif

#define TX_THROW              TX_ERROR

#define _                     ,

#ifndef NDEBUG
    #define TX_PRINT_HERE()   printf ("[" __TX_FILELINE__ " " __TX_FUNCTION__ "]")

#else
    #define TX_PRINT_HERE()   ;

#endif

#ifdef FOR_DOXYGEN_ONLY
#define _TX_ALLOW_TRACE
#endif

#ifdef _TX_ALLOW_TRACE
    #undef  $
    #define $                 TX_TRACE

#else
    #undef  $
    #define $

#endif

#ifdef FOR_DOXYGEN_ONLY
#define TX_TRACE
#endif

#ifndef TX_TRACE

    #define TX_TRACE          OutputDebugString (__TX_FILELINE__ ": ")

#endif

struct txDialog
    {
    public:
    enum CONTROL
        {
        DIALOG    = 0x00000000,
        BUTTON    = 0xFFFF0080,
        EDIT      = 0xFFFF0081,
        STATIC    = 0xFFFF0082,
        LISTBOX   = 0xFFFF0083,
        SCROLLBAR = 0xFFFF0084,
        COMBOBOX  = 0xFFFF0085,
        END       = 0x00000000
        };

    struct Layout
        {
        CONTROL     wndclass;
        const char* caption;
        WORD        id;
        short       x, y;
        short       sx, sy;
        DWORD       style;
        const char* font;
        WORD        fontsize;
        };

    public:
    txDialog();
    txDialog (const Layout* layout);
    virtual ~txDialog() {};

    const Layout* setLayout (const Layout *layout);
    INT_PTR dialogBox (const Layout* layout = NULL, size_t bufsize = 0);
    INT_PTR dialogBox (WORD resource);
    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

    private:
    static int CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

    private:
    const Layout* layout_;
    };

#define TX_BEGIN_MESSAGE_MAP()                                                     \
    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam)  \
        {                                                                          \
        (void)_wnd; (void)_msg; (void)_wParam; (void)_lParam;                      \
                                                                                   \
        switch (_msg)                                                              \
            {                                                                      \
            case WM_NULL:

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

#define TX_COMMAND_MAP                                                             \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        if (_msg == WM_COMMAND) switch (LOWORD (_wParam))                          \
            {                                                                      \
            case 0:

#define TX_END_MESSAGE_MAP                                                         \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        return FALSE;                                                              \
        }

const char* txInputBox (const char* text = NULL, const char* caption = NULL, const char* input = NULL);

const char* txInputBox (const char* text, const char* caption, const char* input)
    {
$   if (!text)    text    = "Введите строку:";
$   if (!caption) caption = txGetModuleFileName (false);
$   if (!input)   input   = "";

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

$   txDialog::Layout layout[] =
        {{ txDialog::DIALOG,   caption,   0,             0,  0, 240,  85                                                     },
         { txDialog::STATIC,   text,      ID_TEXT_,     10, 10, 150,  40, SS_LEFT                                            },
         { txDialog::EDIT,     input,     ID_INPUT_,    10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP  },
         { txDialog::BUTTON,   "&OK",     IDOK,        180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP  },
         { txDialog::BUTTON,   "&Cancel", IDCANCEL,    180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP  },
         { txDialog::END                                                                                                     }};

    struct inputDlg : txDialog
        {
        char str [1024];

        TX_BEGIN_MESSAGE_MAP()
            TX_COMMAND_MAP
                TX_HANDLE (IDOK) $ GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);
        TX_END_MESSAGE_MAP
        };

    #undef ID_TEXT_
    #undef ID_INPUT_

$   static inputDlg dlg;
$   dlg.dialogBox (layout);

$   return dlg.str;
    }

void         _txOnExit();

HWND         _txCanvas_CreateWindow (SIZE size);
bool         _txCanvas_OK();

bool         _txConsole_InitSTDIO();
int          _txCanvas_SetRefreshLock (int count);

bool         _txCanvas_OnCREATE     (HWND wnd);
bool         _txCanvas_OnDESTROY    (HWND wnd);
bool         _txCanvas_OnCLOSE      (HWND);
bool         _txCanvas_OnPAINT      (HWND wnd);
bool         _txCanvas_OnCHAR       (HWND wnd, WPARAM ch);
bool         _txCanvas_OnTIMER      (HWND wnd, WPARAM id);
bool         _txCanvas_OnMOUSEMOVE  (HWND wnd, WPARAM buttons, LPARAM coords);
bool         _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd);
bool         _txCanvas_OnCmdABOUT   (HWND wnd, WPARAM cmd);

unsigned CALLBACK _txCanvas_ThreadProc (void* data);
LRESULT  CALLBACK _txCanvas_WndProc    (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

HDC          _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL);
bool         _txBuffer_Delete (HDC* dc);
bool         _txBuffer_Select (HGDIOBJ obj, HDC dc = txDC());

bool         _txConsole_Attach();
bool         _txConsole_OK();
bool         _txConsole_Detach();
bool         _txConsole_Draw (HDC dc);

void*        _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                                     WORD controls, short x, short y, short cx, short cy,
                                     const char caption[], const char font[], WORD fontsize,
                                     HANDLE menu = NULL);
void*        _tx_DLGTEMPLATE_Add    (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                                     short x, short y, short cx, short cy,
                                     WORD id, const char wclass[], const char caption[]);

bool         _tx_Error (const char file[], int line, const char func[],
                        DWORD getlasterror_value, int errno_value, int doserrno_value,
                        const char msg[], ...) _TX_CHECK_FORMAT (7);

#define      _txCheck()             ( txOK() || TX_ERROR ("\a" "Окно рисования не создано") )

#define      _txWaitFor(cond)       { for (DWORD __t##__LINE__ = GetTickCount() + _TX_TIMEOUT; GetTickCount() < __t##__LINE__; )\
                                        { $ if ((cond) != 0) break; Sleep (_TX_WINDOW_UPDATE_INTERVAL); } }

#ifdef _TX_MULTIPLE_INSTANCE
    #define _TX_NSPACE_NAME         TX_QUOTE (_TX_ANON_NSPACE) "::" "TX"
#else
    #define _TX_NSPACE_NAME                                         "TX"
#endif

const int    _TX_IDM_ABOUT          = 40000;
const int    _TX_IDM_CONSOLE        = 40001;

FARPROC _txImport (const char lib[], const char name[], int required = true);

FARPROC _txImport (const char lib[], const char name[], int required)
    {
$   HMODULE dll  = LoadLibrary (lib);
$   if (!dll  && required) TX_ERROR ("\a" "Cannot load library \"%s\"" _ lib);
$   if (!dll) return NULL;

$   FARPROC addr = GetProcAddress (dll, name);
$   if (!addr && required) TX_ERROR ("\a" "Cannot import \"%s\" from library \"%s\"" _ name _ lib);

$   return addr;
    }

#define _TX_IMPORT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, true)

#define _TX_IMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txImport (lib ".dll", #name, false)

namespace Win32 {

_TX_IMPORT ("GDI32", int,      GetDeviceCaps,          (HDC dc, int index));
_TX_IMPORT ("GDI32", HDC,      CreateCompatibleDC,     (HDC dc));
_TX_IMPORT ("GDI32", HBITMAP,  CreateCompatibleBitmap, (HDC dc, int width, int height));
_TX_IMPORT ("GDI32", HGDIOBJ,  GetStockObject,         (int object));
_TX_IMPORT ("GDI32", HGDIOBJ,  SelectObject,           (HDC dc, HGDIOBJ object));
_TX_IMPORT ("GDI32", HGDIOBJ,  GetCurrentObject,       (HDC dc, UINT objectType));
_TX_IMPORT ("GDI32", int,      GetObjectA,             (HGDIOBJ obj, int bufsize, LPVOID buffer));
_TX_IMPORT ("GDI32", DWORD,    GetObjectType,          (HGDIOBJ object));
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
_TX_IMPORT ("GDI32", BOOL,     Polygon,                (HDC dc, CONST POINT points[], int count));
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

_TX_IMPORT ("USER32",int,      DrawTextA,              (HDC dc, LPCTSTR text, int length, LPRECT rect, UINT format));
_TX_IMPORT ("USER32",HANDLE,   LoadImageA,             (HINSTANCE inst, LPCTSTR name, UINT type,
                                                        int sizex, int sizey, UINT mode));
_TX_IMPORT ("WinMM", BOOL,     PlaySound,              (LPCSTR sound, HMODULE mod, DWORD mode));

_TX_IMPORT ("Kernel32",   HWND,GetConsoleWindow,       ());

_TX_IMPORT_OPT ("MSImg32",BOOL,TransparentBlt,         (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                        HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                        UINT transparentColor));
_TX_IMPORT_OPT ("MSImg32",BOOL,AlphaBlend,             (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                        HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                        BLENDFUNCTION blending));
}

using namespace Win32;

HANDLE           _txCanvas_Thread       = NULL;
unsigned         _txCanvas_ThreadId     = 0;

HWND             _txCanvas_Window       = NULL;

HDC              _txCanvas_BackBuf[2]   = {NULL,
                                           NULL};

CRITICAL_SECTION _txCanvas_LockBackBuf  = {0};

UINT             _txCanvas_RefreshTimer = 0;
int              _txCanvas_RefreshLock  = 0;

bool             _txConsole_IsBlinking  = true;

int              _txWindowId            = 0;
bool             _txRunning             = false;
bool             _txExit                = false;

POINT            _txMousePos            = {0};
int              _txMouseButtons        =  0;

WNDPROC          _txAltWndProc          = NULL;

#ifndef NDEBUG

int _txInitTrace = (OutputDebugString ("\n"),
                    OutputDebugString ("The Dumb Artist Library - " _TX_VERSION " " _TX_AUTHOR ": "
                                       "\"" __FILE__ "\" [" _TX_NSPACE_NAME "], "
                                       "compiled " __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode\n"),
                    OutputDebugString ("\n"), 1);
#endif

int txCreateWindow (int sizeX, int sizeY, bool centered /*= true*/)
    {
$   if (txOK()) return 0;

$   _txRunning  = false;
$   _txExit     = false;
$   _txWindowId = TX_COUNTER();

$   atexit (_txOnExit);

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   if (_txWindowId == 1)
        { $ _txConsole_Attach() asserted; }

$   SIZE size = { sizeX, sizeY };
$   if (centered) { size.cx *= -1; size.cy *= -1; }

$   _txCanvas_Thread = (HANDLE) _beginthreadex (NULL, 0,  _txCanvas_ThreadProc, &size,
                                                      0, &_txCanvas_ThreadId);
$   if (!_txCanvas_Thread || !_txCanvas_ThreadId)
        { $ return TX_ERROR ("\a" "Cannot start canvas thread"),  0; }

$   _txWaitFor (_txCanvas_OK());

$   if (!_txCanvas_OK())
        { $ return TX_ERROR ("\a" "Cannot create canvas window"), 0; }

$   errno = _doserrno = 0;
$   SetLastError (0);

$   return _txWindowId;
    }

bool txSetDefaults()
    {
$   _txCheck();

$   txUpdateWindow (false);
$   txLock();

$   RECT r = {0};

$   GetClientRect (_txCanvas_Window,  &r) asserted;
$   SIZE szCanvas = { r.right - r.left, r.bottom - r.top };

$   GetClientRect (Win32::GetConsoleWindow(), &r) asserted;
$   SIZE szCon    = { r.right - r.left, r.bottom - r.top };

$   _txBuffer_Select (GetStockObject (WHITE_PEN),   txDC()) asserted;
$   _txBuffer_Select (GetStockObject (WHITE_BRUSH), txDC()) asserted;
$   _txBuffer_Select (CreateFont (szCon.cy/25, szCon.cx/80, 0, 0,
                                  FW_REGULAR, FALSE, FALSE, FALSE,
                                  DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                  DEFAULT_QUALITY, DEFAULT_PITCH, _TX_CONSOLE_FONT),
                                  txDC()) asserted;

$   (Win32::SetTextColor (txDC(), TX_WHITE) != CLR_INVALID) asserted;
$    Win32::SetBkMode    (txDC(), TRANSPARENT)              asserted;

$    Win32::SetROP2      (txDC(), R2_COPYPEN)               asserted;

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   SIZE szChr  = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
                    (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

$   SIZE szFont = { (short) ((1.0 * szCon.cx / szChr.cx) / (1.0 * szCon.cx / szCanvas.cx)),
                    (short) ((1.0 * szCon.cy / szChr.cy) / (1.0 * szCon.cy / szCanvas.cy)) };

$   _txBuffer_Select (txFontExist (_TX_CONSOLE_FONT)? CreateFont (szFont.cy, szFont.cx, 0, 0,
                                                                  FW_REGULAR, FALSE, FALSE, FALSE,
                                                                  DEFAULT_CHARSET,
                                                                  OUT_DEFAULT_PRECIS,
                                                                  CLIP_DEFAULT_PRECIS,
                                                                  DEFAULT_QUALITY, FIXED_PITCH,
                                                                  _TX_CONSOLE_FONT)

                                                    : GetStockObject (SYSTEM_FIXED_FONT),
                      _txCanvas_BackBuf[1]) asserted;

$   txUnlock();
$   txUpdateWindow (true);

    return true;
    }

inline
bool txOK()
    {
$   bool ok = _txCanvas_OK() &&
              _txWindowId;

    if (_txWindowId == 1) ok &= _txConsole_OK();

    return ok;
    }

void _txOnExit()
    {
$   _txRunning = false;
$   if (_txWindowId != 1) _txExit = true;

$   char title [1024] = "";
$   GetWindowText (txWindow(), title, sizeof (title) - 1);
$   strncat_s (title, " [ЗАВЕРШЕНО]", sizeof (title) - 1);
$   SetWindowTextA (txWindow(), title);

$   if (GetCurrentThreadId() != _txCanvas_ThreadId)
        { $ (WaitForSingleObject (_txCanvas_Thread, INFINITE) == WAIT_OBJECT_0) asserted; }

$   if (_txCanvas_Thread)
        { $ CloseHandle (_txCanvas_Thread) asserted; _txCanvas_Thread = NULL; }

$   if (_txWindowId == 1)
        { $ _txConsole_Detach(); }

$   DeleteCriticalSection (&_txCanvas_LockBackBuf);

#ifndef NDEBUG
    OutputDebugString ("\n");
    OutputDebugString (_TX_VERSION ": \"" __FILE__ "\" [" _TX_NSPACE_NAME "] -- FINISHED\n");
    OutputDebugString ("\n");
#endif
    }

bool txDestroyWindow()
    {
    return SendNotifyMessage (txWindow(), WM_DESTROY, 0, 0) != 0;
    }

unsigned CALLBACK _txCanvas_ThreadProc (void* data)
    {
$   assert (data);
$   if (!data) return WM_SIZE;

$   _txCanvas_Window = _txCanvas_CreateWindow (*(SIZE*) data);
$   _txCanvas_Window || TX_ERROR ("\a" "Cannot create canvas: _txCanvas_CreateWindow() failed");

$   _txRunning = true;

#ifndef NDEBUG
    OutputDebugString (_TX_VERSION ": \"" __FILE__ "\" [" _TX_NSPACE_NAME "] -- STARTED\n");
#endif

$   MSG msg = {0};
$   while (GetMessage (&msg, NULL, 0, 0))
        {
$       TranslateMessage (&msg);
$       DispatchMessage  (&msg);
$       Sleep (0);

$       if (!_txRunning && _txExit && _txCanvas_Window)
            { $ DestroyWindow (_txCanvas_Window) asserted; }
        }

$   if (_txRunning && _txWindowId == 1)
        { $ exit (msg.wParam); }

$   _txCanvas_ThreadId = 0;
$   return msg.wParam;
    }

HWND _txCanvas_CreateWindow (SIZE clientSize)
    {
$   const char className[] = ">>>>> " _TX_VERSION ": " __FILE__ " [" _TX_NSPACE_NAME "] WndClass <<<<<";
$   WNDCLASSEX wc    = {0};
$   wc.cbSize        = sizeof (wc);
$   wc.style         = CS_HREDRAW | CS_VREDRAW;
$   wc.lpfnWndProc   = _txCanvas_WndProc;
$   wc.hInstance     = NULL;
$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) GetStockObject (HOLLOW_BRUSH);
$   wc.lpszClassName = className;
$   RegisterClassEx (&wc) || TX_ERROR ("\a" "RegisterClass (\"%s\") failed"_ className);

$   int centered = false;
$   if (clientSize.cx < 0 && clientSize.cy < 0) { clientSize.cx *= -1; clientSize.cy *= -1; centered = true; }

$   SIZE scr     = { GetSystemMetrics (SM_CXSCREEN),     GetSystemMetrics (SM_CYSCREEN)     };
$   SIZE frame   = { GetSystemMetrics (SM_CXFIXEDFRAME), GetSystemMetrics (SM_CYFIXEDFRAME) };
$   SIZE caption = { 0, GetSystemMetrics (SM_CYCAPTION) };
$   SIZE size    = { clientSize.cx + 2*frame.cx, clientSize.cy + 2*frame.cy + caption.cy };
$   POINT center = { scr.cx / 2, scr.cy / 2 };

$   if (!centered)
        {
$       RECT r = { scr.cx, scr.cy };
$       GetWindowRect (Win32::GetConsoleWindow(), &r);

$       center.x = (r.right + r.left) / 2;
$       center.y = (r.bottom + r.top) / 2;
        }

$   _txCanvas_Window = CreateWindowEx (0, className, txGetModuleFileName (false),
                       WS_POPUP | WS_BORDER | WS_CAPTION | ((_txWindowId == 1)? WS_SYSMENU : 0),
                       center.x - size.cx/2, center.y - size.cy/2, size.cx, size.cy,
                       NULL, NULL, NULL, NULL);

$   if (!_txCanvas_Window) return TX_ERROR ("\a" "Cannot create canvas: CreateWindowEx (\"%s\") failed"_ className), (HWND)NULL;

$   ShowWindow          (_txCanvas_Window, SW_SHOW);
$   SetForegroundWindow (_txCanvas_Window) asserted;
$   UpdateWindow        (_txCanvas_Window) asserted;

$   if (_txConsole_OK())
        { $ SetWindowPos (Win32::GetConsoleWindow(), HWND_NOTOPMOST,
                          center.x - size.cx*2/5, center.y - size.cy*2/5, 0, 0,
                          SWP_NOSIZE | SWP_NOACTIVATE | _TX_CONSOLE_MODE) asserted; }

$   HMENU menu = GetSystemMenu (_txCanvas_Window, false);
$   if (!menu) return _txCanvas_Window;

$   AppendMenu (menu, MF_SEPARATOR, 0, NULL)                      asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_CONSOLE, "Show Console") asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_ABOUT,   "About...")     asserted;

$   CheckMenuItem (menu, _TX_IDM_CONSOLE,
                   _txConsole_OK()? (IsWindowVisible (Win32::GetConsoleWindow())? MF_CHECKED : 0) : MF_DISABLED);

$   return _txCanvas_Window;
    }

inline
bool _txCanvas_OK()
    {
$   return _txCanvas_Thread     &&
           _txCanvas_Window     &&
           _txCanvas_BackBuf[0] &&
           _txCanvas_BackBuf[1];
    }

int _txCanvas_SetRefreshLock (int count)
    {
$   int oldCount = _txCanvas_RefreshLock;

$   _txCanvas_RefreshLock = count;

$   if (_txCanvas_RefreshLock <= 0 || oldCount <= 0)
        if (_txCanvas_Window)
            {
$           InvalidateRect (_txCanvas_Window, NULL, false);
$           UpdateWindow   (_txCanvas_Window);
            }

$   return oldCount;
    }

bool _txCanvas_OnCREATE (HWND wnd)
    {
$   assert (wnd);

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); _txCanvas_BackBuf[0] asserted;
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); _txCanvas_BackBuf[1] asserted;

$   SetTimer (wnd, _txCanvas_RefreshTimer, _TX_WINDOW_UPDATE_INTERVAL, NULL) asserted;

$   _txCanvas_Window = wnd;

$   txSetDefaults();

$   return true;
    }

bool _txCanvas_OnDESTROY (HWND wnd)
    {
    assert (wnd);

$   PostQuitMessage (_txRunning? WM_DESTROY : EXIT_SUCCESS);

$   if (!_txCanvas_Window) return false;

$   _txExit = true;

$   bool locked = false;
$   _txWaitFor (locked = txLock (false));

$   if (!locked) TX_ERROR ("Cannot lock GDI to free resources");

$   if (_txCanvas_BackBuf[0])   _txBuffer_Delete (&_txCanvas_BackBuf[0]) asserted;
$   if (_txCanvas_BackBuf[1])   _txBuffer_Delete (&_txCanvas_BackBuf[1]) asserted;
$   if (_txCanvas_RefreshTimer) KillTimer (wnd, _txCanvas_RefreshTimer)  asserted;

$   _txCanvas_Window = NULL;

$   return true;
    }

bool _txCanvas_OnCLOSE (HWND wnd)
    {
$   if (!wnd || !_txCanvas_OK()) return false;

$   if (_txRunning &&
        MessageBox (wnd, "Функция main() не завершена. Программа все еще работает. Прервать?    ",
                    txGetModuleFileName (false), MB_OKCANCEL | MB_ICONSTOP) != IDOK) return false;
$   return true;
    }

bool _txCanvas_OnPAINT (HWND wnd)
    {
$   if (!wnd || !_txCanvas_OK()) return false;

$   if (!txLock (false)) return false;

$   PAINTSTRUCT ps = {0};
$   HDC dc = BeginPaint (wnd, &ps);
$   if (!dc) { txUnlock(); return false; }

$   RECT r = {0};
$   GetClientRect (wnd, &r) asserted;
$   POINT size = { r.right - r.left, r.bottom - r.top };

$   if (_txCanvas_RefreshLock <= 0)
      {
$     Win32::BitBlt (_txCanvas_BackBuf[1], 0, 0, size.x, size.y, txDC(), 0, 0, SRCCOPY);

$     if (_txConsole_OK())
          { $ _txConsole_Draw (_txCanvas_BackBuf[1]); }
      }

$   if (_txCanvas_RefreshLock != 100500)
        { $ Win32::BitBlt (dc, 0, 0, size.x, size.y, _txCanvas_BackBuf[1], 0, 0, SRCCOPY); }

$   EndPaint (wnd, &ps) asserted;

$   txUnlock();

$   return true;
    }

bool _txCanvas_OnCHAR (HWND, WPARAM ch)
    {
$   INPUT_RECORD evt = {0};

$   evt.EventType                        = KEY_EVENT;
$   evt.Event.KeyEvent.bKeyDown          = true;
$   evt.Event.KeyEvent.wRepeatCount      = 1;
$   evt.Event.KeyEvent.wVirtualKeyCode   = 0;
$   evt.Event.KeyEvent.wVirtualScanCode  = 0;
$   evt.Event.KeyEvent.uChar.AsciiChar   = (unsigned char) ch;
$   evt.Event.KeyEvent.dwControlKeyState = 0;

$   DWORD written = 0;
$   WriteConsoleInput (GetStdHandle (STD_INPUT_HANDLE), &evt, 1, &written) asserted;

$   return true;
    }

bool _txCanvas_OnMOUSEMOVE (HWND, WPARAM buttons, LPARAM coords)
    {
$   if (_txCanvas_OK()) return false;

$   _txMousePos.x   = LOWORD (coords);
$   _txMousePos.y   = HIWORD (coords);
$   _txMouseButtons = (int) buttons;

$   return true;
    }

bool _txCanvas_OnTIMER (HWND wnd, WPARAM)
    {
$   if (!wnd)                      return false;
$   if (_txCanvas_RefreshLock > 0) return false;

$   InvalidateRect (wnd, NULL, false) asserted;
$   UpdateWindow   (wnd)              asserted;

$   return true;
    }

bool _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd)
    {
$   if (!wnd)             return false;
$   if (!_txConsole_OK()) return false;

$   bool visible = IsWindowVisible (Win32::GetConsoleWindow()) != 0;

$   ShowWindow (Win32::GetConsoleWindow(), visible? SW_HIDE : SW_SHOW);

$   visible = IsWindowVisible (Win32::GetConsoleWindow()) != 0;
$   CheckMenuItem (GetSystemMenu (wnd, false), (int)cmd, visible? MF_CHECKED : MF_UNCHECKED);

$   return true;
    }

bool _txCanvas_OnCmdABOUT (HWND, WPARAM)
    {
    #if defined (__MODULE)
        #define ABOUT_NAME_    __MODULE
    #else
        #define ABOUT_NAME_    "TXLib"
    #endif

    #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__AUTHOR)

        #ifndef __MODULE
        #define __MODULE       "TXLib"                       " \t\t"  "#define __MODULE to set the name."
        #endif
        #ifndef __VERSION
        #define __VERSION      "(0.000000000)."              " \t\t" "#define __VERSION to set the string value."
        #endif
        #ifndef __DESCRIPTION
        #define __DESCRIPTION  "(Мне лень задать описание)." " \t\t" "#define __DESCRIPTION to override project role."
        #endif
        #ifndef __AUTHOR
        #define __AUTHOR       "(Непонятно кто)."            " \t\t" "#define __AUTHOR to override this name."
        #endif

    #endif

$   time_t timeT      = time (NULL) - clock()/CLOCKS_PER_SEC;
$   char   timeS[100] = "";

#ifdef  _TX_USE_SECURE_CRT
$   ctime_s  (timeS, sizeof (timeS), &timeT);
#else
$   strncpy (timeS, ctime (&timeT), sizeof (timeS) - 1);
#endif

$   char text[1024] = "";
$   char cwd [MAX_PATH] = "";

    #define EOL_ "    \n"

$   _snprintf_s (text, sizeof (text) - 1,
                 #ifdef _TX_USE_SECURE_CRT
                 _TRUNCATE,
                 #endif

                 "Application:" EOL_ "\n"

                 #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__PROGRAMMER)
                     __MODULE " version " __VERSION EOL_
                     __DESCRIPTION EOL_
                     "Copyright (c) " __AUTHOR EOL_
                 #else
                     "Здесь могла бы быть Ваша реклама:)" EOL_
                     "#define __MODULE to \"your program name\" before including TXLib.h to use this billboard..." EOL_
                 #endif

                 "\n" "Developed with:" EOL_ "\n"
                 "The Dumb Artist Library (TX Library) - " _TX_VERSION EOL_
                 _TX_AUTHOR EOL_
                 "See license and more on: http://ded32.net.ru" EOL_ "\n"

                 "TXLib file:" "\t" __FILE__ ", namespace " _TX_NSPACE_NAME EOL_
                 "Compiler:"   "\t" __TX_COMPILER__ EOL_
                 "Compiled:"   "\t" __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode" EOL_ "\n"

                 "Run file:"   "\t" "%s" EOL_
                 "From dir:"   "\t" "%s" EOL_
                 "Started:"    "\t" "%.6s %.4s %.8s",

                 txGetModuleFileName(), _getcwd (cwd, sizeof (cwd) - 1),
                 timeS + 4, timeS + 20, timeS + 11);
    #undef EOL_

$   MessageBox (txWindow(), text, "About " ABOUT_NAME_, MB_ICONINFORMATION);

$   return true;

    #undef ABOUT_NAME_
    }

LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
    {
    if (msg == WM_KEYDOWN && wpar == VK_F12 &&
        GetKeyState (VK_SHIFT) && GetKeyState (VK_CONTROL) && GetKeyState (VK_MENU))
        {
$       _txCanvas_OnCmdABOUT (wnd,      wpar);
$       return DefWindowProc (wnd, msg, wpar, lpar);
        }

    WNDPROC altWndProc = _txAltWndProc;
    if (altWndProc)
        {
$       LRESULT res = altWndProc (wnd, msg, wpar, lpar);
$       if (res) return res;
        }

    switch (msg)
        {
        case WM_CREATE:  $      _txCanvas_OnCREATE     (wnd);             break;

        case WM_CLOSE:   $ if (!_txCanvas_OnCLOSE      (wnd))             return 0;
        case WM_DESTROY: $      _txCanvas_OnDESTROY    (wnd);             break;

        case WM_PAINT:   $      _txCanvas_OnPAINT      (wnd);             break;
        case WM_CHAR:    $      _txCanvas_OnCHAR       (wnd, wpar);       break;
        case WM_TIMER:   $      _txCanvas_OnTIMER      (wnd, wpar);       break;

        case WM_LBUTTONUP:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MOUSEMOVE:    $ _txCanvas_OnMOUSEMOVE  (wnd, wpar, lpar); break;
        default:              $ break;
        }

    if (msg == WM_SYSCOMMAND) switch (wpar)
        {
        case _TX_IDM_ABOUT:   $ _txCanvas_OnCmdABOUT   (wnd, wpar);       break;
        case _TX_IDM_CONSOLE: $ _txCanvas_OnCmdCONSOLE (wnd, wpar);       break;
        default:              $ break;
        }

    return DefWindowProc (wnd, msg, wpar, lpar);

    #undef IS_TXLIB_HOTKEY_
    }

bool _txConsole_Attach()
    {
#if (_TX_CONSOLE_MODE != SWP_HIDEWINDOW)
$   if (!GetConsoleWindow())
#endif
        {
$       FreeConsole();
$       AllocConsole();

$       HANDLE con = GetStdHandle (STD_OUTPUT_HANDLE); assert (con);
$       COORD size = { 80, 25 };
$       if (con) SetConsoleScreenBufferSize (con, size);
        }

$   _txConsole_InitSTDIO() asserted;

$   return Win32::GetConsoleWindow() != NULL;
    }

bool _txConsole_InitSTDIO()
    {
$   static bool done = false;
$   if (done) return false;

$   int crtIn  = _open_osfhandle ((ptrdiff_t) GetStdHandle (STD_INPUT_HANDLE),  _O_TEXT);
$   int crtOut = _open_osfhandle ((ptrdiff_t) GetStdHandle (STD_OUTPUT_HANDLE), _O_TEXT);

$   *stdin  = * _fdopen (crtIn,  "r");
$   *stdout = * _fdopen (crtOut, "w");

$   setvbuf (stdin,  NULL, _IONBF, 0);
$   setvbuf (stdout, NULL, _IONBF, 0);

$   std::ios::sync_with_stdio();

$   SetConsoleCP       (1251);
$   SetConsoleOutputCP (1251);

$     setlocale (LC_CTYPE,  "Russian");
$   _wsetlocale (LC_CTYPE, L"Russian_Russia.ACP");

$   done = true;

$   return !ferror (stdin)  &&
           !ferror (stdout) &&
           std::cin.good()  &&
           std::cout.good();
    }

inline bool _txConsole_OK()
    {
$   return Win32::GetConsoleWindow() != NULL;
    }

bool _txConsole_Detach()
    {
    return FreeConsole() != 0;
    }

bool _txConsole_Draw (HDC dc)
    {
$   assert (_txConsole_OK()); assert (_txCanvas_OK());

$   if (!txLock (false)) return false;

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   BOOL ok = GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);
    if (!ok) { $ txUnlock(); return false; }

$   SIZE fontSz = {0};
$   txGDI (Win32::GetTextExtentPoint32 (dc, "W", 1, &fontSz)) asserted;

$   Win32::SetTextColor (dc, _TX_CONSOLE_COLOR);
$   Win32::SetBkMode    (dc, TRANSPARENT) asserted;

$   int sizeX = con.srWindow.Right - con.srWindow.Left + 1;
$   for (SHORT y = con.srWindow.Top; y <= con.srWindow.Bottom; y++)
        {
$       static TCHAR buf [1024 + 1] = "";
$       COORD coord = { 0, y };
$       DWORD read  =   0;

$       if (!ReadConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
                                         buf, sizeof (buf), coord, &read)) continue;

$       Win32::TextOut (dc, 0, y*fontSz.cy, buf + con.srWindow.Left, sizeX) asserted;
        }

$   if (_txConsole_IsBlinking &&
        GetTickCount() % _TX_CURSOR_BLINK_INTERVAL*2 > _TX_CURSOR_BLINK_INTERVAL &&
        In (con.dwCursorPosition, con.srWindow))
        {
$       Win32::TextOut (dc, (con.dwCursorPosition.X - con.srWindow.Left)*fontSz.cx,
                            (con.dwCursorPosition.Y - con.srWindow.Top) *fontSz.cy + 1, "_", 1)
                        asserted;
        }

$   txUnlock();

$   return true;
    }

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bitmap)
    {
$   txLock();

$   HDC wndDC = GetDC (wnd); assert (wndDC); if (!wndDC) return NULL;

$   (Win32::GetDeviceCaps (wndDC, RASTERCAPS) & RC_BITBLT) || TX_ERROR ("GetDeviceCaps(): RASTERCAPS: RC_BITBLT not supported");

$   RECT r = {0};
$   GetClientRect (wnd, &r) asserted;
$   POINT sz = { r.right - r.left, r.bottom - r.top };
$   if (!size) size = &sz;

$   HDC dc = Win32::CreateCompatibleDC (wndDC);
$   dc || TX_ERROR ("Cannot create buffer: CreateCompatibleDC() failed");

$   HBITMAP bmap = bitmap? bitmap : Win32::CreateCompatibleBitmap (wndDC, size->x, size->y);
$   bmap || TX_ERROR ("Cannot create buffer: CreateCompatibleBitmap() failed");

$   Win32::SelectObject (dc, bmap) asserted;

$   if (!bitmap) Win32::PatBlt (dc, 0, 0, size->x, size->y, BLACKNESS) asserted;

$   ReleaseDC (wnd, wndDC) asserted;

$   txUnlock();
$   return dc;
    }

bool _txBuffer_Delete (HDC* dc)
    {
$   assert (dc);
$   if (!dc || !*dc) return false;

$   txLock();

$   _txBuffer_Select (Win32::GetStockObject         (NULL_PEN),    *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject         (NULL_BRUSH),  *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject         (SYSTEM_FONT), *dc) asserted;
$   _txBuffer_Select (Win32::CreateCompatibleBitmap (*dc, 0, 0),   *dc) asserted;

$   Win32::DeleteObject (Win32::GetCurrentObject (*dc, OBJ_BITMAP)) asserted;
$   Win32::DeleteObject (Win32::GetCurrentObject (*dc, OBJ_REGION));

$   Win32::DeleteDC (*dc) asserted;

$   *dc = NULL;

$   txUnlock();
$   return true;
    }

bool _txBuffer_Select (HGDIOBJ obj, HDC dc /*= txDC()*/)
    {
$   assert (obj); assert (dc);
$   (obj && Win32::GetObjectType (obj)) || TX_ERROR ("Invalid GDI object type");

$   txLock();

$   obj = Win32::SelectObject (dc, obj);
$   if (obj) Win32::DeleteObject (obj) asserted;

$   txUnlock();

$   return obj != NULL;
    }

const char* txGetModuleFileName (bool fileNameOnly /*= true*/)
    {
$   static char name[256] = "";

$   GetModuleFileName (NULL, name, sizeof (name) - 1) asserted;
$   if (fileNameOnly) return name;

$   strncat_s (name, " - TXLib", sizeof (name));

    #ifdef _TX_MULTIPLE_INSTANCE
$   strncat_s (name, " [" _TX_NSPACE_NAME "]", sizeof (name));
    #endif

$   const char* title = strrchr (name, '\\'); title = title? title+1 : name;

$   return title;
    }

bool _tx_Error (const char file[], int line, const char func[],
               DWORD winerr, int crterr, int doserr,
               const char msg[], ...)
    {
    const size_t MAXSTR = 1024;
    static int nCalls = 0;

    if (winerr == (DWORD) -1) winerr = GetLastError();
    if (crterr ==         -1) crterr = errno;
    if (doserr ==         -1) doserr = _doserrno;
    nCalls++;

    unsigned threadId = GetCurrentThreadId();

    if (!_txRunning) _txConsole_InitSTDIO();

    bool fatal = (msg && *msg == '\a')? (msg++, true) : false;

    va_list arg; va_start (arg, msg);

    #ifdef  _TX_USE_SECURE_CRT
        #define SZARG_(n)  sizeof (str[0]) - (n) - (s-str[0]), _TRUNCATE

    #else
        #define SZARG_(n)  sizeof (str[0]) - (n) - (s-str[0])

    #endif

    char str[2][MAXSTR] = {}, *s = str[0];

                s +=  _snprintf_s  (s, SZARG_ (1), "TX_ERROR() сообщает:" "\v\v");

    if (file)   s +=  _snprintf_s  (s, SZARG_ (1), "Файл: %s [%s], " , file, _TX_NSPACE_NAME);
    if (line)   s +=  _snprintf_s  (s, SZARG_ (1), "Строка: %d    \v", line);
    if (func)   s +=  _snprintf_s  (s, SZARG_ (1), "Функция: %s   \v", func);

                s +=  _snprintf_s  (s, SZARG_ (1), "\v");

    if (msg)    s +=  _snprintf_s  (s, SZARG_ (1), "Сообщение: "),
                s += _vsnprintf_s  (s, SZARG_ (1), msg, arg),
                s +=  _snprintf_s  (s, SZARG_ (1), "    \v\v");

                s +=  _snprintf_s  (s, SZARG_ (1), "#%d: Thread: 0x%08X%s", nCalls, threadId,
                                                   (threadId == _txCanvas_ThreadId? " (Canvas thread)" : ""));

    if (winerr) s +=  _snprintf_s  (s, SZARG_ (0), ", GetLastError(): %lu (", winerr),
                s += FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                    NULL, winerr, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                                    s, (DWORD) (sizeof (str[0]) - (s-str[0])), NULL) - 3,
                s +=  _snprintf_s  (s, SZARG_ (1), ")");

    if (crterr) s +=  _snprintf_s  (s, SZARG_ (1), ", errno: %lu (%s)",
                                    crterr, (strerror_s (str[1], crterr), str[1]));

    if (doserr) s +=  _snprintf_s  (s, SZARG_ (1), ", _doserrno: %lu (%s)",
                                    doserr, (strerror_s (str[1], doserr), str[1]));

                s +=  _snprintf_s  (s, SZARG_ (1), ".%s    \n",
                                    std::uncaught_exception()? "std::uncaught_exception(): true." : "");
    #undef SZARG_

    OutputDebugString (str[0]);

    for (char* p = strchr (str[0], '\v'); p; p = strchr (p+1, '\v')) *p = '\n';

    printf ("\n" "--------------------------------------------------" "\n"
                 "%s"
                 "--------------------------------------------------" "\n", str[0]);

    MessageBox (NULL, str[0], fatal? "Фатальная ошибка" : "Ошибка в программе",
                MB_ICONSTOP | MB_TOPMOST | MB_SYSTEMMODAL);

    va_end (arg);

    if (fatal)
        {
        if (!IsDebuggerPresent()) exit (EXIT_FAILURE);

        DebugBreak();
        }

    return false;
    }

inline const char* txVersion()
    {
$   return _TX_VERSION;
    }

inline unsigned txVersionNumber()
    {
$   return _TX;
    }

POINT txGetExtent()
    {
$   _txCheck();

$   RECT r = {0};
$   GetClientRect (txWindow(), &r);
$   POINT size = { r.right - r.left, r.bottom - r.top };
$   return size;
    }

int txGetExtentX()
    {
$   return txGetExtent().x;
    }

int txGetExtentY()
    {
$   return txGetExtent().y;
    }

inline HDC& txDC()
    {
$   return _txCanvas_BackBuf[0];
    }

inline HWND txWindow()
    {
$   return _txCanvas_Window;
    }

bool txSetColor (COLORREF color, int thickness /*= 1*/)
    {
$   _txCheck();

$   return _txBuffer_Select (Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), thickness, color)) &&
            txGDI          ((Win32::SetTextColor (txDC(), color) != 0));
    }

bool txColor (double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetColor (RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

COLORREF txGetColor()
    {
$   _txCheck();

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_PEN))); assert (obj);

$   char buf [MAX (sizeof (LOGPEN), sizeof (EXTLOGPEN))] = {0};

$   int size = GetObject (obj, 0, NULL);
$   GetObject (obj, sizeof (buf), buf) asserted;

$   return (size == sizeof (LOGPEN))? ((LOGPEN*)buf)->lopnColor : ((EXTLOGPEN*)buf)->elpColor;
    }

bool txSetFillColor (COLORREF color)
    {
$   _txCheck();

$   return _txBuffer_Select ((color == TX_TRANSPARENT)? Win32::GetStockObject   (HOLLOW_BRUSH) :
                                                 Win32::CreateSolidBrush (color));
    }

bool txFillColor (double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetFillColor (RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

COLORREF txGetFillColor()
    {
$   _txCheck();

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (txDC(), OBJ_BRUSH))); assert (obj);

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf))) asserted;

$   return buf.lbColor;
    }

bool txSetROP2 (int mode /*= R2_COPYPEN*/)
    {
$   _txCheck();

$   return txGDI ((Win32::SetROP2 (txDC(), mode) != 0));
    }

bool txClear()
    {
$   _txCheck();

$   POINT size = txGetExtent();
$   return txGDI ((Win32::PatBlt (txDC(), 0, 0, size.x, size.y, PATCOPY) != 0));
    }

inline bool txSetPixel (int x, int y, COLORREF color)
    {
$   _txCheck();

$   txGDI ((Win32::SetPixel (txDC(), x, y, color)));

$   return true;
    }

inline bool txPixel (int x, int y, double red, double green, double blue)
    {
$   if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetPixel (x, y, RGB (red * 255 + 0.5, green * 255 + 0.5, blue * 255 + 0.5));
    }

inline COLORREF txGetPixel (int x, int y)
    {
$   _txCheck();

$   return txGDI ((Win32::GetPixel (txDC(), x, y)));
    }

bool txLine (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   txGDI ((Win32::MoveToEx (txDC(), x0, y0, NULL))) asserted;
$   txGDI ((Win32::LineTo   (txDC(), x1, y1      ))) asserted;

$   return true;
    }

bool txRectangle (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   txGDI ((Win32::Rectangle (txDC(), x0, y0, x1, y1))) asserted;

$   return true;
    }

bool txPolygon (const POINT points[], int numPoints)
    {
$   _txCheck();

$   return txGDI ((Win32::Polygon (txDC(), points, numPoints) != 0));
    }

bool txEllipse (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   txGDI ((Win32::Ellipse (txDC(), x0, y0, x1, y1))) asserted;

$   return true;
    }

bool txCircle (int x, int y, int r)
    {
$   return txEllipse (x-r, y-r, x+r, y+r);
    }

bool txArc (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txCheck();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI ((Win32::Arc (txDC(), x0, y0, x1, y1,
                                       (int) (center.x + 100 * cos (start) + 0.5),
                                       (int) (center.y - 100 * sin (start) + 0.5),
                                       (int) (center.x + 100 * cos (end)   + 0.5),
                                       (int) (center.y - 100 * sin (end)   + 0.5)) != 0));
    }

bool txPie (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txCheck();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI ((Win32::Pie (txDC(), x0, y0, x1, y1,
                                       (int) (center.x + 100 * cos (start) + 0.5),
                                       (int) (center.y - 100 * sin (start) + 0.5),
                                       (int) (center.x + 100 * cos (end)   + 0.5),
                                       (int) (center.y - 100 * sin (end)   + 0.5)) != 0));
    }

bool txChord (int x0, int y0, int x1, int y1, int startAngle, int totalAngle)
    {
$   _txCheck();

$   POINT center = { (x0 + x1) /2, (y0 + y1) /2 };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI ((Win32::Chord (txDC(), x0, y0, x1, y1,
                                         (int) (center.x + 100 * cos (start) + 0.5),
                                         (int) (center.y - 100 * sin (start) + 0.5),
                                         (int) (center.x + 100 * cos (end)   + 0.5),
                                         (int) (center.y - 100 * sin (end)   + 0.5)) != 0));
    }

bool txFloodFill (int x, int y,
                  COLORREF color /*= TX_TRANSPARENT*/, DWORD mode /*= FLOODFILLSURFACE*/)
    {
$   _txCheck();

$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y);

$   return txGDI ((Win32::ExtFloodFill (txDC(), x, y, color, mode) != 0));
    }

bool txTextOut (int x, int y, const char text[])
    {
$   _txCheck();

$   txGDI ((Win32::TextOut (txDC(), x, y, text, (int) strlen (text)))) asserted;

$   return true;
    }

bool txDrawText (int x0, int y0, int x1, int y1, const char text[],
                 unsigned format /*= DT_CENTER | DT_VCENTER | DT_WORDBREAK |
                                   DT_MODIFYSTRING | DT_PATH_ELLIPSIS*/)
{
$   _txCheck();

$   RECT r = { x0, y0, x1, y1 };

$   if (!strchr (text, '\n')) format |= DT_SINGLELINE;

$   unsigned prev = txSetTextAlign (TA_LEFT | TA_TOP | TA_NOUPDATECP);
$   txGDI ((Win32::DrawText (txDC(), text, -1, &r, format))) asserted;
$   txSetTextAlign (prev);

$   return true;
}

bool txSelectFont (const char name[], int sizeY, int sizeX /*= -1*/,
                   int  bold /*= FW_DONTCARE*/, bool italic /*= false*/,
                   bool underline /*= false*/, bool strikeout /*= false*/)
    {
$   _txCheck();

$   _txBuffer_Select (txFontExist (name)? CreateFont (sizeY, (int) ((sizeX != -1)? sizeX : sizeY/3), 0, 0,
                                               bold, italic, underline, strikeout,
                                               DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                               DEFAULT_QUALITY, FIXED_PITCH, name)
                                   :
                                   GetStockObject (SYSTEM_FIXED_FONT));
$   return true;
    }

SIZE txGetTextExtent (const char text[])
    {
$   _txCheck();

$   SIZE size = {0};
$   txGDI ((Win32::GetTextExtentPoint32 (txDC(), text, (int) strlen (text), &size))) asserted;

$   return size;
    }

int txGetTextExtentX (const char text[])
    {
$   return txGetTextExtent (text) .cx;
    }

int txGetTextExtentY (const char text[])
    {
$   return txGetTextExtent (text) .cy;
    }

unsigned txSetTextAlign (unsigned align /*= TA_CENTER | TA_BASELINE*/)
    {
$   _txCheck();

$   return txGDI ((Win32::SetTextAlign (txDC(), align)));
    }

LOGFONT* txFontExist (const char name[])
    {
$   _txCheck();

$   static LOGFONT font = {0};
$   font.lfCharSet = DEFAULT_CHARSET;
$   strncpy_s (font.lfFaceName, name, sizeof (font.lfFaceName) - 1);

    struct enumFonts
        {
        static int CALLBACK Proc (const LOGFONT* fnt, const TEXTMETRIC*, DWORD, LPARAM data)
            {
$           assert (fnt); assert (data); if (! (data && fnt)) return 0;
#ifndef __STRICT_ANSI__
$           return _strnicmp (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
#else
$           return  strncmp  (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE) != 0;
#endif
            }
        };

$   return txGDI ((Win32::EnumFontFamiliesEx (txDC(), &font, enumFonts::Proc, (LPARAM)&font, 0) == 0? &font : NULL));
    }

HRGN txSelectRegion (int x0, int y0, int x1, int y1)
    {
$   _txCheck();

$   HRGN rgn = Win32::CreateRectRgn (x0, y0, x1, y1);

$   txSelectObject (rgn) asserted;

$   return rgn;
    }

bool txSelectObject (HGDIOBJ obj)
    {
$   _txCheck();

$   return _txBuffer_Select (obj);
    }

HDC txCreateCompatibleDC (int sizeX, int sizeY, HBITMAP bitmap /*= NULL*/)
    {
$   _txCheck();

$   POINT size = { sizeX, sizeY };
$   HDC dc = _txBuffer_Create (txWindow(), &size, bitmap); assert (dc);

$   return dc;
    }

HDC txLoadImage (const char filename[])
    {
$   _txCheck();

$   HBITMAP image = (HBITMAP) LoadImage (NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
$   if (!image) return NULL;

$   HDC dc = txCreateCompatibleDC (0, 0, image);

$   return dc;
    }

bool txDeleteDC (HDC dc)
    {
$   _txCheck();

$   return _txBuffer_Delete (&dc);
    }

bool txDeleteDC (HDC* dc)
    {
$   _txCheck();

$   return _txBuffer_Delete (dc);
    }

bool txBitBlt (HDC dest, int xDest, int yDest, int width, int height,
               HDC src,  int xSrc,  int ySrc,  DWORD rOp /*= SRCCOPY*/)
    {
$   _txCheck();

$   return txGDI ((Win32::BitBlt (dest, xDest, yDest, width, height,
                                  src,  xSrc,  ySrc, rOp) != 0));
    }

bool txTransparentBlt (HDC dest, int xDest, int yDest, int width, int height,
                       HDC src,  int xSrc,  int ySrc,  COLORREF transColor /*= TX_BLACK*/)
    {
$   _txCheck();

$   if (!TransparentBlt) return false;

$   return Win32::TransparentBlt (dest, xDest, yDest, width, height,
                                  src,  xSrc,  ySrc,  width, height, transColor) != 0;
    }

bool txAlphaBlend (HDC dest, int xDest, int yDest, int width, int height,
                   HDC src,  int xSrc,  int ySrc,  double alpha /*= 1.0*/)
    {
$   _txCheck();

$   if (!AlphaBlend) return false;

$   if (alpha < 0) alpha = 0;
$   if (alpha > 1) alpha = 1;

    #ifndef AC_SRC_ALPHA
    #define AC_SRC_ALPHA 0x01
    #endif

$   BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) (alpha * 255 + 0.5), AC_SRC_ALPHA };

$   return Win32::AlphaBlend (dest, xDest, yDest, width, height,
                              src,  xSrc,  ySrc,  width, height, blend) != 0;
    }

inline int txUpdateWindow (int update /*= true*/)
    {
$   return _txCanvas_SetRefreshLock (update >= 0? !update : -update);
    }

inline int txBegin()
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock + 1);

$   return _txCanvas_RefreshLock;
    }

inline int txEnd()
    {
$   _txCanvas_SetRefreshLock (_txCanvas_RefreshLock - 1);

$   return _txCanvas_RefreshLock;
    }

inline bool txSleep (int time)
    {
    _txCheck();

$   int old = _txCanvas_SetRefreshLock (0);

$   Sleep (time);

$   _txCanvas_SetRefreshLock (old);

$   return old != 0;
    }

inline bool txLock (bool wait /*= true*/)
    {
$   if (_txExit) Sleep (0);

$   if (wait) { $ return    EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { $ return TryEnterCriticalSection (&_txCanvas_LockBackBuf) != 0;  }
    }

inline
bool txUnlock()
    {
$   LeaveCriticalSection (&_txCanvas_LockBackBuf);

$   if (_txExit) Sleep (0);
$   return false;
    }

template <typename T>
inline T txUnlock (T value)
    {
$   txUnlock();
$   return value;
    }

inline POINT txMousePos()
    {
$   return _txMousePos;
    }

inline int txMouseX()
    {
$   return _txMousePos.x;
    }

inline int txMouseY()
    {
$   return _txMousePos.y;
    }

inline int txMouseButtons()
    {
$   return _txMouseButtons;
    }

bool txPlaySound (const char filename[] /*= NULL*/, DWORD mode /*= SND_ASYNC*/)
    {
$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;

$   if (!filename) mode = SND_PURGE;

$   return PlaySound (filename, NULL, mode) != 0;
    }

WNDPROC txSetWindowHandler (WNDPROC handler /*= NULL*/)
    {
$   WNDPROC old = _txAltWndProc; _txAltWndProc = handler;
$   return  old;
    }

bool txTextCursor (bool blink /*= true*/)
    {
$   bool old = _txConsole_IsBlinking;

$   _txConsole_IsBlinking = blink;

$   return old;
    }

bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()
    {
$   MessageBox (txWindow(),
                "Это запланированная ошибка. Такое бывает. Вы хотели вызвать:" "\n\n"
                "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillCloseAndIWillNotBeAskingWhereIsMyPicture()" "\n\n"
                "Хоть вы долго [копировали]набирали это имя, на самом деле эта функция не работает." "\n"
                "Но для нее есть работающий синоним. См. определение этой функции в исходных текстах библиотеки." "\n\n",
                "Не получилось", MB_ICONSTOP);

$   return false;
    }

inline bool txDisableAutoPause()
    {
$   _txExit = true;
$   return true;
    }

double txQueryPerformance()
    {
    double time = 0;

    for (int i = 0; i < 10; i++)
        {
        LARGE_INTEGER ticks0 = {{0}}, ticks1 = {{0}};

        QueryPerformanceCounter (&ticks0) asserted;
        Sleep (_TX_WINDOW_UPDATE_INTERVAL);
        QueryPerformanceCounter (&ticks1) asserted;

        time += ticks1.QuadPart - ticks0.QuadPart;
        }

    return time / double (10 * _TX_WINDOW_UPDATE_INTERVAL) / 1024/1024;
    }

int txExtractColor (COLORREF color, COLORREF component)
    {
$   switch (component)
        {
        case TX_RED:
        case TX_HUE:        $ return (color >>  0) & 0xFF;

        case TX_GREEN:
        case TX_SATURATION: $ return (color >>  8) & 0xFF;

        case TX_BLUE:
        case TX_LIGHTNESS:  $ return (color >> 16) & 0xFF;

        default:            $ return CLR_INVALID;
        }
    }

COLORREF txRGB2HSL (COLORREF rgbColor)
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

$   return RGB (((ih >= 0)? ih*60 : ih*60 + 360) + 0.5, is*255 + 0.5, il*255 + 0.5);
    }

COLORREF txHSL2RGB (COLORREF hslColor)
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

$   return RGB (ir * 255 + 0.5, ig * 255 + 0.5, ib * 255 + 0.5);
    }

txDialog::txDialog () :
    layout_ (NULL)
    {$}

txDialog::txDialog (const Layout* layout) :
    layout_ (layout)
    {$}

const txDialog::Layout* txDialog::setLayout (const Layout* layout)
    {
$   return std::swap (layout_, layout), layout;
    }

INT_PTR txDialog::dialogBox (const txDialog::Layout* layout /*= NULL*/, size_t bufsize /*= 0*/)
    {
$   if (!layout)  layout = layout_;
$   if (!layout)  return TX_ERROR ("Не установлен динамический шаблон диалога    ");

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_ERROR ("GlobalAlloc(): Нет памяти для шаблона диалога    ");

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

INT_PTR txDialog::dialogBox (WORD resourceID)
    {
$   const char* resName = (char*)(ptrdiff_t)resourceID;

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_ERROR ("Не найден ресурс диалога %d   " _ resourceID);

$   return DialogBoxParam (NULL, resName, NULL, dialogProc__, (LPARAM) this);
    }

int txDialog::dialogProc (HWND, UINT, WPARAM, LPARAM)
    {
$   return FALSE;
    }

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

void* _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                              WORD controls, short x, short y, short cx, short cy,
                              const char caption[], const char font[], WORD fontsize,
                              HANDLE menu /*= NULL*/)
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

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                           short x, short y, short cx, short cy,
                           WORD id, const char wclass[], const char caption[])
    {
$   if (!dlgTemplatePtr) return NULL;

$   WORD* pw = (LPWORD) dlgTemplatePtr;
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

#undef       $
#undef       _txCheck
#undef       _txWaitFor

 }  }

#ifndef _TX_MULTIPLE_INSTANCE
using namespace TX;
using namespace TX::Win32;
#endif

using std::cin;
using std::cout;

#if defined (_MSC_VER)

    #pragma warning (default: 4127)
    #pragma warning (default: 4351)
    #pragma warning (default: 4663)

#endif

#define $$$$        TX_PRINT_HERE()

#define $_(var)    ( _txDump (var) )
#define $(var)     ( _txDump ((var),  "[" #var " = ", "]") )

#define $$(cmd)    (  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n",  \
                     _txDump ((cmd),"\n[" __TX_FILELINE__ ": " #cmd ": ", ", DONE]\n") )

#define $$_(cmd)   (  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n",  \
                     _txDump ((cmd),  "[" __TX_FILELINE__ ": " #cmd ": ", ", DONE]\n") )

#define $$$(cmd)   {  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n";  \
                     _txSuffixDump ("\n[" __TX_FILELINE__ ": " #cmd ": DONE]\n"); { cmd; } }

#define $$$_(cmd)  {  std::cout <<  "\n[" __TX_FILELINE__ ": " #cmd "]\n";  \
                     _txSuffixDump (  "[" __TX_FILELINE__ ": " #cmd ": DONE]\n"); { cmd; } }

#define $n         (  std::cout << "\n" )

#ifndef __TX_DEBUG_MACROS
#define __TX_DEBUG_MACROS

template <typename T> inline
const T& _txDump (const T& value, const char* prefix = "", const char* suffix = "")
    {
    if (prefix) std::cout << prefix << value << suffix;
    return value;
    }

struct _txSuffixDump
    {
    const char* suffix_;

    inline  _txSuffixDump (const char* suffix = "") : suffix_ (suffix)     {}
    inline ~_txSuffixDump()                         { std::cout << suffix_; }

    _txSuffixDump (const _txSuffixDump&);
    _txSuffixDump& operator = (const _txSuffixDump&);
    };

#endif

#endif
