//{================================================================================================================
//! @file       TXWaveExample.cpp
//!
//! @brief      Пример для библиотеки TXWave.
//!
//!             $Version: 00173a, Revision: 164 $
//!             $Date: 2020-01-30 05:00:00 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}================================================================================================================

#include "..\TXWave.h"

void BeepDemo();
void SinusDemo();
void StereoDemo();
void Sort1Demo();
void Sort2Demo();
void Sort3Demo();
void BeepDemo2();
void WaveformDemo();
void CatPurrDemo();
void RecordingDemo();
bool MonitorProc (HWAVEIN, txWaveData_t& data, void*);
void Banner (const char* text);
void Pause();

//-----------------------------------------------------------------------------------------------------------------

int main()
    {
    txDisableAutoPause();

    printf ("\n");

    Banner ("1/10: Beep demo");
    BeepDemo();
    Pause();

    txCreateWindow (800, 600);

    Banner ("2/10: Sinus demo");
    SinusDemo();
    Pause();

    printf ("\n" "For idea of the sorting demos see: https://www.youtube.com/watch?v=kPRA0W1kECg\n\n");

    Banner ("3/10: Shaker Sort demo");
    Sort1Demo();
    Pause();

    Banner ("4/10: std::sort (QuickSort) demo");
    Sort2Demo();
    Pause();

    Banner ("5/10: std::stable_sort (MergeSort) demo");
    Sort3Demo();
    Pause();

    ShowWindow (Win32::GetConsoleWindow(), SW_SHOW);
    ShowWindow (txWindow(), SW_HIDE);

    Banner ("6/10: Stereo demo");
    StereoDemo();
    Pause();

    Banner ("7/10: Beep demo 2");
    BeepDemo2();
    Pause();

    Banner ("8/10: Waveform demo");
    WaveformDemo();
    Pause();

    Banner ("9/10: Cat purr demo");
    CatPurrDemo();
    Pause();

    Banner ("10/10: Recording demo");
    RecordingDemo();
    Pause();

    Banner ("All demos done");
    return 0;
    }

//-----------------------------------------------------------------------------------------------------------------

void BeepDemo()
    {
    txWaveOut (250, 880);
    }

//-----------------------------------------------------------------------------------------------------------------

void SinusDemo()
    {
    POINT size = txGetExtent();

    double x0 = -2*M_PI, x1 = +2*M_PI;
    double zoom = 50;

    for (int i = -10; i <= 10; i++)
        {
        txSetColor (i? TX_DARKGRAY : TX_WHITE);

        txLine (0, size.y/2 + i*zoom, size.x, size.y/2 + i*zoom);
        txLine (size.x/2 + i*zoom, 0, size.x/2 + i*zoom, size.y);
        }

    Banner ("\f" "SinusDemo. Press any key to stop...");

    for (double x = x0; x <= x1 && !_kbhit(); x += (x1 - x0) / 101)
        {
        double y = 5 * sin (x);

        txWaveOut (50, 880 + 88 * y);

        txCircle (x*zoom + size.x/2, -y*zoom + size.y/2, 5);
        }
    }

//-----------------------------------------------------------------------------------------------------------------

void StereoDemo()
    {
    for (double t = -0.1; !_kbhit(); t += 0.1)
        {
        txWaveOut (50, 880 + 88 * cos (t), 100,
                       880 + 88 * sin (t), 100);

        const char line[] = "----------------------------------------";
        const int  lineSz = sizeof (line) - 1;

        int sz = (int) ROUND ((1 + cos (t))/2 * lineSz);
        printf ("Press any key to stop...     [%.*s|%.*s]  \r", lineSz-sz, line, sz, line);
        }

    printf ("\n\n");
    }

//-----------------------------------------------------------------------------------------------------------------

void BeepDemo2()
    {
    int time = 2000;
    txWaveData_t wav (ROUND (time * txWaveSampleRate));

    printf ("Generating the waveform ~880 Hz...\n");

    for (unsigned i = 0; i < wav.size(); i++)
        wav[i][0] = wav[i][1] = (short) (sin (i*0.125) * txWaveVolMax);  // * 2*M_PI/44100 * 880

    printf ("Playing %d sec...\n\n", time/1000);

    txWaveOut (wav);
    txWaveOut();
    }

//-----------------------------------------------------------------------------------------------------------------

void WaveformDemo()
    {
    int time = 90000;
    txWaveData_t buf (ROUND (time * txWaveSampleRate));
    unsigned size = (unsigned) buf.size();

    printf ("Generating the wave: (t >> 7 | t | t >> 6) * 10 + 4 * (t & t >> 13 | t >> 6)...\n"
            "See: http://countercomplex.blogspot.ru/2011/10/algorithmic-symphonies-from-one-line-of.html\n\n");

    for (unsigned i = 0; i < size; i++)
        {
        int t   = i/5;
        int val = (((t >> 7) | t | (t >> 6)) * 10 + 4 * ((t & (t >> 13)) | (t >> 6))) & 0xFF;

        buf[i][0] = buf[i][1] = (short) ((val/127.0 - 1) / (1 + pow (15, 17.0*i/size - 15)) * txWaveVolMax);
        }

    printf ("Now playing, press a key to stop...\n\n");

    HWAVEOUT waveOut = txWaveOut (buf); assert (waveOut);

    while (!_kbhit())
        {
        unsigned long pos = txWaveGetPosition (waveOut);
        unsigned done = (unsigned) (100 * pos/size);

        const char line[] = "----------------------------------------";
        const int  lineSz = sizeof (line) - 1;

        printf ("Done %7lu/%7u samples [%.*s|%.*s] %3u%%  \r",
                 pos, size, (int) (lineSz*done/100), line, (int) (lineSz - lineSz*done/100), line, done);

        if (done >= 100) break;
        Sleep (100);
        }

    txWaveOut (0);
    printf ("\n\n");
    }

//-----------------------------------------------------------------------------------------------------------------

void CatPurrDemo()
    {
    txWaveData_t purr = txWaveLoadWav ("Purr.wav");

    txWaveOut (purr);

    printf ("Uninterruptable... do relax and wait %ld sec\n\n", ROUND ((int) purr.size() / txWaveSampleRate / 1000));

    txWaveOut();
    }

//-----------------------------------------------------------------------------------------------------------------

void RecordingDemo()
    {
    Banner ("\r" "Turn on the microphone and get prepared for a recording."); Pause();

    int time = 20000;

    printf ("Recording %2d sec...\n",   time/1000);

    txWaveData_t wav = txWaveIn (time, MonitorProc);
    time = ROUND ((int) wav.size() / txWaveSampleRate);

    printf ("\nRecorded: %2d sec\n",  time/1000);
    printf ("\nPlaying %2d sec...\n", time/1000);

    HWAVEOUT waveOut = txWaveOut (wav);
    while (!_kbhit() && txWaveGetPosition (waveOut) < wav.size()) Sleep (100);
    txWaveOut (0);

    printf ("\nSaving to WAV file...\n\n");
    txWaveSaveWav (wav, "Recording.wav");
    }

bool MonitorProc (HWAVEIN, txWaveData_t& data, void*)
    {
    static const char line1[] = "---------------";
    static const char line2[] = "|||||||||||||||";
    static const int  lineSz  = sizeof (line1) - 1;

    unsigned pos  = (unsigned) data.size();
    unsigned size = (unsigned) data.capacity();
    unsigned done = (unsigned) (100 * pos/size);

    double avr = 10;
    if (pos >= 100) for (unsigned i = pos - 100; i < pos; i++) avr += (abs (data[i][0]) + abs (data[i][1])) / txWaveVolMax;
    int vol = (avr <= 100)? (int) avr : 100;

    printf ("Done %6u/%6u samples   [%.*s|%.*s] %3u%%  [%.*s%.*s%s %3d%%  \r",
             pos, size,
             (int) (lineSz*done/100), line1, (int) (lineSz - lineSz*done/100), line1,                         done,
             (int) (lineSz*vol /100), line2, (int) (lineSz - lineSz*vol /100), line1, (vol < 100? "]" : "X"), vol);

    return (_kbhit()? ((void) _getch(), false) : true);
    }

//-----------------------------------------------------------------------------------------------------------------

// For idea of this demo see: https://www.youtube.com/watch?v=kPRA0W1kECg

struct Number_t
    {
    int val_;

    Number_t();

    Number_t& operator = (const Number_t& that);
    bool      operator < (const Number_t& that) const;

    bool draw (COLORREF color, COLORREF fillColor) const;

    static void setinfo (const Number_t* data, size_t size);

    static const Number_t* data__;
    static       size_t    size__;
    };

const Number_t* Number_t::data__   = NULL;
      size_t    Number_t::size__   = 0;

Number_t::Number_t() :
    val_ (88 + rand() % 2552)
    {}

void Number_t::setinfo (const Number_t* data, size_t size)
    {
    data__ = data;
    size__ = size;

    for (unsigned i = 0; i < size__; i++) data__[i].draw (RGB (64, 64, 64), RGB (32, 32, 32));
    }

bool Number_t::draw (COLORREF color, COLORREF fillColor) const
    {
    if (_kbhit()) throw EOF;

    const int width = 9;

    int n = (int) (this - data__);
    if (!data__ || !(0 <= n && n < (int) size__)) return false;

    int x0 = txGetExtentX()/2 - width * (int)size__/2;

    txSetColor (TX_BLACK); txSetFillColor (TX_BLACK);
    txRectangle (x0 + n*width, 500, x0 + (n+1)*width, 500 - 400);

    txSetColor (color); txSetFillColor (fillColor);
    txRectangle (x0 + n*width, 500, x0 + (n+1)*width, 500 - val_/10);

    return true;
    }

Number_t& Number_t::operator = (const Number_t& that)
    {
    if (_kbhit()) throw EOF;

    val_ = that.val_;
    draw (TX_WHITE, TX_LIGHTGRAY);

    return *this;
    }

bool Number_t::operator < (const Number_t& that) const
    {
    if (_kbhit()) throw EOF;

    this->draw (TX_LIGHTRED, TX_RED);
    that. draw (TX_LIGHTRED, TX_RED);

    txWaveOut (50, val_, 10, that.val_, 10);

    this->draw (TX_WHITE, TX_LIGHTGRAY);
    that. draw (TX_WHITE, TX_LIGHTGRAY);

    return val_ < that.val_;
    }

void Sort1Demo()
    {
    try
        {
        Number_t data[16];
        Number_t::setinfo (data, sizearr (data));

        for (int left = 0, right = (int) sizearr (data) - 1; left < right; )
            {
            bool change = false;

            for (int i = left; i < right; i++)
                if (data[i+1] < data[i]) { std::swap (data[i+1], data[i]); change = true; }

            right--;
            if (!change) break;

            change = false;

            for (int i = right-1; i >= left; i--)
                if (data[i+1] < data[i]) { std::swap (data[i+1], data[i]); change = true; }

            left++;
            if (!change) break;
            }
        }

    catch (...) {}
    }

void Sort2Demo()
    {
    try
        {
        Number_t data[32];
        Number_t::setinfo (data, sizearr (data));

        std::sort (data, data + sizearr (data));
        }

    catch (...) {}
    }

void Sort3Demo()
    {
    try
        {
        Number_t data[32];
        Number_t::setinfo (data, sizearr (data));

        std::stable_sort (data, data + sizearr (data));
        }

    catch (...) {}
    }

//-----------------------------------------------------------------------------------------------------------------

void Banner (const char* text)
    {
    if (txWindow() && IsWindowVisible (txWindow()))
        {
        static POINT size = txGetExtent();

        if (*text != '\f')
            {
            txSetFillColor (TX_BLACK);
            txClear();
            }
        else
            text++;

        if (*text == '\r') text++;
        if (*text == '\t') text++;

        txSetFillColor (TX_WHITE);
        txSetTextAlign (TA_CENTER);

        txSetColor (TX_WHITE); txRectangle (0, size.y * 0.95, size.x, size.y);
        txSetColor (TX_BLACK); txDrawText  (0, size.y * 0.95, size.x, size.y, text);
        txSleep (0);

        txSetColor (TX_WHITE);
        }
    else
        {
        $y;
        if (*text == '\f') {     text++; }
        if (*text == '\r') { $r; text++; }
        if (*text == '\t') { $d; text++; }

        printf ("%s\n\n", text);

        $d;
        }
    }

void Pause()
    {
    Banner ("\f\t" "Press a key to continue...");

    while (_kbhit()) (void) _getch();
    (void) _getch();
    }
