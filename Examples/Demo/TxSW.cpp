
/*               Episode X

              RETURN OF TXLIB

  War!  The Republic  of Windows  is  under
  attack  of  modern   graphics  libraries.
  Programmers  of the Galaxy  fight against
  SFML, SDL, OpenGL and DirectX.

  But  the more pixels painted,  the lesser
  their Force.  Some  programmers  think to
  switch to Pascal and Python.

  Being in  utter despair,  princess Organa
  calls for anybody could help the Graphics
  to get back its Force.

  A long time ago in a galaxy far, far away
  a  small  library  called   TXLib   heard
  this call ...
*/

#include "TXLib.h"

HDC CreateSW (const char* source);

int main()
    {
    txCreateWindow (GetSystemMetrics (SM_CXSCREEN) / 1.5, GetSystemMetrics (SM_CXSCREEN) / 3.0);
    txTextCursor (false);
    txBegin();

    HDC sw = CreateSW (__FILE__);
    if (!sw) return txMessageBox ("ERROR: File \"" __FILE__ "\" NOT found!"), 1;

    if (_access (__FILE__ ".wav", 0) != 0) return txMessageBox ("ERROR: File \"" __FILE__ ".wav\" NOT found!"), 1;
    txPlaySound (__FILE__ ".wav");
    txSleep (1000);

    POINT scr = txGetExtent();
    POINT sz  = txGetExtent (sw);
    
    int posY  = ROUND (scr.y * 0.8);

    unsigned time0 = GetTickCount();

    txSetFillColor (TX_BLACK);

    for (double i = 0; i <= sz.y - posY + scr.y && !GetAsyncKeyState (VK_ESCAPE); i += 0.1)
        {
        txLock();

        txClear();

        for (int y = 0; y <= posY; y++)
            {
            double t  = 1.0 * y / posY;

            int sizeX = ROUND (t * scr.x * 5/6 + scr.x/6);
            int destX = (scr.x - sizeX) / 2;

            int destY = ROUND (y + scr.y - posY);
            int srcY  = ROUND ((t+1 - 2 / pow (t+1, 3)) * scr.y + i - scr.y);

            int alpha = ROUND (t * 255);

            Win32::AlphaBlend (txDC(), destX, destY, sizeX, 3, sw, 0, srcY, sz.x, 7,
                               BLENDFUNCTION { AC_SRC_OVER, 0, (BYTE) alpha, 0 });
            }

        txUnlock();

        txSleep();

        double fps = txGetFPS <50> ();
        if (fps <= 0) continue;

        static double fixFps = 0;
        if (fixFps <= 0) fixFps = (fps >= 5)? fps : 5;

        char str [128] = "";
        _tx_snprintf_s (str, sizeof (str), __FILE__ " - Time %.0fs, FPS %.0f", (GetTickCount() - time0) / 1000.0, fps);
        SetWindowText (txWindow(), str);

        i += 1/fixFps * pow (scr.y, 2.53) / 4E5;
        }

    txDeleteDC (sw);
    }

#include <sys/stat.h>

HDC CreateSW (const char* source)
    {
    struct stat st = {};
    if (stat (source, &st) != 0) return NULL;
    size_t size = (size_t) st.st_size;

    char* text = new (std::nothrow) char [size + 1] {};
    if (!text) return NULL;

    FILE* f = NULL;
    fopen_s (&f, source, "r"); if (!f) { delete[] text; return NULL; }
    fread (text, size, 1, f);
    fclose (f);

    int lines = 1;
    for (char* s = strchr (text, '\n'); s; s = strchr (s+1, '\n')) lines++;

    POINT scr  = txGetExtent();
    POINT font = { scr.x/45, scr.y/10 };

    HDC   sw = txCreateCompatibleDC (scr.x, scr.y * 2 + font.y * lines);
    POINT sz = txGetExtent (sw);

    txSetColor (RGB (235, 180, 60), 1, sw);
    txSelectFont ("Lucida Console", font.y, font.x, FW_BOLD, false, false, false, 0, sw);
    txDrawText (0, scr.y/1.5, sz.x, sz.y + scr.y, text, 0, sw);

    delete[] text;
    text = NULL;

    return sw;
    }

#if !defined (_TX_VER) || (_TX_VER < 0x173a0105)
#error Must use TXLib.h version >= 1.73 and revision >= 105 to compile this.
#error Get up-to-date source from http://storage.ded32.net.ru/Lib/TX/TXUpdate/TXLib.h
#error Or use AutoUpdate from http://sourceforge.net/projects/txlib/files/TXLib/TXLib-Update.rar.exe/download
#endif

/*******************************************
 *
 * Source (c) Ded, 2017
 * May the Source be with you!
 *
 * Inspired by LucasFilm and Kirill Acharya.
 *
 * Music theme by (C) John Willams.
 *
 * :)
 *
 *******************************************/
