//{================================================================================================================
//! @file       TXWave.h
//!
//  @mainpage
//! @brief      ���������� TXWave - ��������������� � ������ ������
//!
//!             $Version: 00173a, Revision: 165 $
//!             $Date: 2020-03-26 21:07:17 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//!
//! @section    Contents ������� ������� ������
//! @par
//!           - @ref Wave    "���������� TXWave"
//!           - @ref Misc    "������"
//!           - @ref Example "������ ������"
//!
//! @page       Example ������ ��� ���������� TXWave
//! @include    "TXWaveExample.cpp"
//!
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//-----------------------------------------------------------------------------------------------------------------
//! @defgroup   Wave ������ �� ������
//! @defgroup   Misc ������
//}================================================================================================================

#ifndef __TXWAVE_INCLUDED
#define __TXWAVE_INCLUDED

//=================================================================================================================

#include "TXLib.h"
#include <limits.h>

#if !(defined (_TX_VER) && (_TX_VER >= 0x173a0105))
    #error Must use TXLib.h version >= 1.73a, revision >= 105 to compile TXWave.
    #endif

#if defined (_MSC_VER)
    #pragma warning (push)
    #pragma warning (disable: 4068)             // unknown pragma
    #pragma warning (disable: 4200)             // nonstandard extension used : zero-sized array in struct/union
    #pragma warning (disable: 28159)            // Consider using 'GetTickCount64' instead of 'GetTickCount'
    #endif

//=================================================================================================================

/*! @cond INTERNAL */

namespace { namespace TX {

/*! @endcond */

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   �������� ����������� ��� TXWave � ������� <b>�� 1 ������������.</b>
//!
//! @see     txWaveFormat, txWaveOut(), txWaveIn(), txWaveGetPosition(), txWaveLoadWav(), txWaveFormat, txWaveSample_t
//}----------------------------------------------------------------------------------------------------------------

const double txWaveSampleRate = 44.100;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ������ ����������� ��� TXWave.
//!
//!          ����������� ��������� ��� ������, 2 ������, 16 ��� �� �����, 44.100 ��� (@ref txWaveSampleRate).
//!
//! @see     txWaveOut(), txWaveIn(), txWaveGetPosition(), txWaveLoadWav(), txWaveSampleRate, txWaveSample_t,
//!          txWaveData_t
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

const WAVEFORMATEX txWaveFormat = { WAVE_FORMAT_PCM, 2, (DWORD) (txWaveSampleRate*1000),
                                                        (DWORD) (txWaveSampleRate*1000) * 2*16/8, 2*16/8, 16 };

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ������������ ��������� � @ref txWaveSample_t, �������� ������� @ref txWaveFormat.
//!
//! @see     txWaveSampleRate, txWaveFormat, txWaveData_t, txWaveLoadWav(), txWaveOut(), txWaveIn()
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

const double txWaveVolMax = ((1 << txWaveFormat.wBitsPerSample) - 1) / 2.0;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ��� ������, �������������� ��� ����������� ������������� ������ �������� ������� @ref txWaveFormat.
//!
//!          ������������� ������������ �������: [0] - ����� �����, [1] - ������ �����.
//!
//! @see     txWaveSampleRate, txWaveVolMax, txWaveData_t, txWaveFormat, txWaveLoadWav(), txWaveOut(), txWaveIn()
//!
//! @usage @code
//!          // ������ 880 ��, ����������� � ������
//!
//!          int time = 2000;
//!          txWaveData_t buf (ROUND (time * txWaveSampleRate));
//!
//!          for (unsigned i = 0; i < buf.size(); i++)
//!              buf[i][0] = buf[i][1] = (short) (sin (i*0.125) * txWaveVolMax);  // * 2*M_PI/44100 * 880
//!
//!          txWaveOut (buf);  // ����������� ����
//!          txWaveOut();      // ������� ����� ������������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

union txWaveSample_t
    {
    //! ������ �������: [0] - �����, [1] - ������

    short ch[2];

    //! �������������� � ������� �������� �������

    inline operator short*() { return ch; }
    };

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ���, �������������� ��� ������� ������.
//!
//!          ��� <tt>std::vector \<txWaveSample_t\></tt>.
//!
//!          @ref txWaveSample_t ������������ ������� �� ���� ��������� ���� short, ��������������� ������ � ������� ������.
//!
//!          ������������ ��������� � ������ �������� ���������� @ref txWaveVolMax.
//!
//! @see     txWaveData_t, txWaveSampleRate, txWaveVolMax, txWaveFormat, txWaveLoadWav(), txWaveOut(), txWaveIn()
//!
//! @usage @code
//!          int time = 2000;
//!          txWaveData_t wav (ROUND (time * txWaveSampleRate));
//!
//!          printf ("Generating the waveform ~880 Hz...\n");
//!
//!          for (unsigned i = 0; i < wav.size(); i++)
//!              wav[i][0] = wav[i][1] = (short) (sin (i*0.125) * txWaveVolMax);  // * 2*M_PI/44100 * 880
//!
//!          printf ("Playing %d sec...\n\n", time/1000);
//!
//!          txWaveOut (buf);  // ����������� ����
//!          txWaveOut();      // ������� ����� ������������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

typedef std::vector <txWaveSample_t> txWaveData_t;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ����������� ���� ����� �������� �����.
//!
//! @param   timeMs    ����� �������� � �������������
//! @param   freqL     ������� ����� � ����� ������ � ������
//! @param   volL      ��������� ����� � ����� ������ � ��������� �� ���������
//! @param   freqR     ������� ����� � ������ ������ � ������
//! @param   volR      ��������� ����� � ������ ������ � ��������� �� ���������
//! @param   loops     ������� ��� ��������� ����
//! @param   data      �������������� ������ ��� ��������������� (��������, ����������� �� WAV-�����)
//!
//! @return  ���������� ��������������� ���������������
//!
//! @par     ���������:
//!          ���� �� ����� ������ ��� ��������������� ���������� ����, �� ������� �������� ��� ����������,
//!          � ����� �������� ��������������� ������.
//!
//! @par     �������� @p time:
//!        - ���� ����� �������� @p time ������������, �� ������� �������� ��������������� � ������������,
//!          � ���� ���������� ������� � ������� ������.
//!        - ���� ������������, �� ������� ����� ������� ���������� ��������������� ������ � ������� @c |time|
//!          �����������.
//!        - ����� ������� ��� ���������� ����� ������� ��������� ��������������� ���� ������.
//!        - ���� @p time ����� ����, �� ��������������� ����� ������������.
//!
//! @par     ������������� ��������� - ������� (@p freqL, @p freqR) � ��������� (@p volL, @p volR) �������:
//!        - ���� ������� ������ ������ @p freqL �� ������� ��� ����� 0, �� ����� ����������� ������ ������
//!          �� ������ ������ ������.
//!        - ���� ��������� ������ ������ @p volL �� �������, �� ��� ���������� ������ 50%.
//!        - ���� ������� ������� ������ @p freqR �� �������, �� ��� ���������� ������ ������� ������ ������.
//!        - ���� ��������� ������� ������ @p volR �� �������, �� ��� ���������� ������ ��������� ������ ������.
//!        - ������� ����� �������� � ��������������� ������� ������ @p data.
//!        - ���� ������������� ������ ��� ��� � ����� ������ (@p freqL == 0 ��� @p volL == 0), ��� � � ������
//!          (@p freqR == 0 ��� @p volR == 0), �� ����������� ������������ �������� ������������ �� ����������
//!          @p time, � �������� ������ @p data.
//!
//! @par     �������������� ������ @p data:
//!        - ������ � ������� @p data �������� ������ �� �������� ������� ��� ���������.
//!        - �� ������ � ���� ������� �� ������ ��������� ��������� @p volL � @p volR.
//!        - ���� ������ @p data �� ������, �� �� �� �����������.
//!        - �������������� ������ @p data ����� �������� � ��������� @p freqL � @p freqR.
//!        - ������ @p data ������ ���� �������� �� �����, ��� <tt>time * @ref txWaveSampleRate.</tt>
//!        - ���� ������� ������� �� ������� ��� ������� ��������������� � ������� ������� @p time,
//!          �� ��� ���������� ������ ������� ��� ����� ��������������.
//!
//! @see     txWaveIn(), txWaveGetPosition(), txWaveLoadWav(), txWaveSampleRate, txWaveVolMax, txWaveFormat,
//!          txWaveData_t, txWaveSample_t
//!
//! @usage @code
//!          // ���� 1 ���, 880 ��, ����, 50% ���������
//!
//!          txWaveOut (1000, 880);  // ��������� ������������, ����� ��� ���� � ������� ������
//!
//!          // ������ 880 +/- 88 ��, ����, 50% ���������
//!
//!          for (double t = -0.1; !_kbhit(); t += 0.1)
//!              txWaveOut (100, 880 + 88 * cos (t));
//!
//!          // ������ 880 +/- 88 ��, ������
//!
//!          for (double t = -0.1; !_kbhit(); t += 0.1)
//!              txWaveOut (100, 880 + 88 * cos (t), 100, 880 + 88 * sin (t), 100);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HWAVEOUT txWaveOut (int timeMs = -INT_MAX,
                    double freqL =  0, double volL = 50,
                    double freqR = -1, double volR = -1,
                    int loops = 1,
                    const txWaveData_t& data = txWaveData_t());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ����������� �������������� ��� ����������� ����� ����� �������� �����.
//!
//! @param   data   �������������� ������ ��� ��������������� (��������, ����������� �� WAV-�����)
//! @param   loops  ������� ��� ��������� ����
//!
//! @return  ���������� ��������������� ���������������
//!
//! @see     txWaveIn(), txWaveGetPosition(), txWaveLoadWav(), txWaveSampleRate, txWaveVolMax, txWaveFormat,
//!          txWaveData_t, txWaveSample_t
//!
//! @usage @code
//!          // ������, ����������� �� �����
//!
//!          txWaveOut (txWaveLoadWav ("Purr.wav"));  // �������� ����������� ����, �� ��������������� ����������
//!          ...
//!          txSleep();                               // ������� ����� ������������
//!
//!          // ������, ����������� � ������
//!          // See http://countercomplex.blogspot.ru/2011/10/algorithmic-symphonies-from-one-line-of.html
//!
//!          int time = 90000;
//!          txWaveData_t buf (ROUND (time * txWaveSampleRate));
//!          unsigned size = (unsigned) buf.size();
//!
//!          for (unsigned i = 0; i < size; i++)
//!              {
//!              int t   = i/5;
//!              int val = (((t >> 7) | t | (t >> 6)) * 10 + 4 * ((t & (t >> 13)) | (t >> 6))) & 0xFF;
//!
//!              buf[i][0] = buf[i][1] = (short) ((val/127.0 - 1) / (1 + pow (15, 17.0*i/size - 15)) * txWaveVolMax);
//!              }
//!
//!          HWAVEOUT waveOut = txWaveOut (buf); assert (waveOut);  // ��������� ����
//!
//!          while (txWaveGetPosition (waveOut) < size)  // �������� �� ���� �� �����?
//!              {
//!              if (_kbhit())) txWaveOut (0);           // ��������� ����, ���� ������ �������
//!              Sleep (100);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HWAVEOUT txWaveOut (const txWaveData_t& data, int loops = 1);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ��� �������-�������� ��� ������� @ref txWaveIn().
//!
//! @param   waveIn    ���������� ���������� ������
//! @param   data      ������ �� �����, ��� ��������� ���������� ������
//! @param   userData  ��������� �� ���������������� ������ @p monitorData, ���������� �� ������� txWaveIn()
//!
//! @return  ���� ���� ���������� ������, �� @c true. ���� ���� ��������� ������ - @c false.
//!
//! @see     txWaveIn(), MonitorProc()
//!
//! @usage   ��. @ref MonitorProc()
//}----------------------------------------------------------------------------------------------------------------

typedef bool MonitorProc_t (HWAVEIN waveIn, txWaveData_t& data, void* userData);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   �������-�������, ��������� ������������ ��� ������ �����.
//!
//! @param   waveIn    ���������� ���������� ������
//! @param   data      ������ �� �����, ��� ��������� ���������� ������
//! @param   userData  ��������� �� ���������������� ������ @p monitorData, ���������� �� ������� txWaveIn()
//!
//! @return  ���� ���� ���������� ������, �� @c true. ���� ���� ��������� ������ - @c false.
//!
//! @see     txWaveIn(), txWaveGetPosition(), txWaveVolMax, txWaveFormat, txWaveData_t, txWaveSample_t
//!
//! @usage @code
//!          bool MonitorProc (HWAVEIN, txWaveData_t& data, void*)
//!              {
//!              static const char line1[] = "-------------------------";
//!              static const char line2[] = "|||||||||||||||||||||||||";
//!              static const int  lineSz  = sizeof (line1) - 1;
//!
//!              unsigned pos  = (unsigned) data.size();
//!              unsigned size = (unsigned) data.capacity();
//!              unsigned done = (unsigned) (100 * pos/size);
//!
//!              double avr = 0;
//!              if (pos >= 100) for (unsigned i = pos - 100; i < pos; i++) avr += (abs (data[i][0]) + abs (data[i][1])) / txWaveVolMax;
//!              int vol = (avr <= 100)? (int) avr : 100;
//!
//!              printf ("Done %6u/%6u samples   [%.*s|%.*s] %3u%%  [%.*s%.*s%s %3d%%  \r",
//!                       pos, size,
//!                       (int) (lineSz*done/100), line1, (int) (lineSz - lineSz*done/100), line1,                         done,
//!                       (int) (lineSz*vol /100), line2, (int) (lineSz - lineSz*vol /100), line1, (vol < 100? "]" : "X"), vol);
//!
//!              return (_kbhit()? (_getch(), false) : true);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
bool MonitorProc (HWAVEIN waveIn, txWaveData_t& data, void* userData);
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ���������� ���� �� �������� �����.
//!
//! @param   timeMs       ����� ������ � �������������
//! @param   monitorProc  �������, ������� ���������� ����� ������� ����������� ����� ������ @p frameTime ����
//! @param   monitorData  ��������� �� ���������������� ������, ������� ����� �������� ������� @p monitorProc
//! @param   frameTime    �������� ������� ������, ����� ������� ����� ���������� ������� @p monitorProc, ����
//!
//! @return  ���������� ���������� ������
//!
//! @par     ���������:
//!        - ���� ������� @ref MonitorProc �� �������, �� � �������� ������ ��� �� ����� ����������.
//!        - ���� �������� ������� @p frameTime �� ������ ��� ����� 0, �� ��������������� ������ 100 �����������.
//!
//! @see     monitorProc(), txWaveOut(), txWaveGetPosition(), txWaveSaveWav(), txWaveSampleRate, txWaveVolMax,
//!          txWaveFormat, txWaveData_t, txWaveSample_t
//!
//! @usage @code
//!          txWaveData_t wav = txWaveIn (20000);  // ���������� ���� 20 ������
//!
//!          txWaveOut (wav);  // ����������� ����
//!          txWaveOut();      // ������� ����� ������������
//!
//!          // ������ � ��������-��������� ��. � ����� TXWaveExample.cpp.
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

txWaveData_t txWaveIn (int timeMs,
                       MonitorProc_t* monitorProc = NULL, void* monitorData = NULL,
                       unsigned frameTime = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ���������� ������� ������� ��������������� ��� ������.
//!
//! @param   wave  ���������� ��������������� ��� ������
//!
//! @return  ���������� ��� ���������������� ��� ��� ���������� ��������� �������
//!
//! @see     txWaveOut(), txWaveIn(), txWaveSampleRate, txWaveFormat
//!
//! @usage @code
//!          HWAVEOUT waveOut = txWaveOut (time, 440); assert (waveOut);  // ��������� ����
//!
//!          while (txWaveGetPosition (waveOut) < size)  // �������� �� ���� �� �����?
//!              {
//!              if (_kbhit())) txWaveOut (0);           // ��������� ����, ���� ������ �������
//!
//!              printf (".");
//!              Sleep (100);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned long txWaveGetPosition (void* wave);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ��������� �������� ������ �� WAV-�����.
//!
//! @param   filename    ��� ����� � ������� WAV
//!
//! @return  @ref txWaveData_t, �.�. <tt>std::vector \<@ref txWaveData_t\>,</tt> � ������������ �������
//!
//! @note    ���� ������ ���� � ������� WAV, Microsoft PCM, ������ (2 ������), �������� ������������� 44.100 ���
//!          (@ref txWaveSampleRate), 16 ��� �� �����. ���� ���� ������� �������, ��� ���� ������������� � ������
//!          ������.
//!
//! @see     txWaveOut(), txWaveIn(), txWaveSaveWav(), txWaveSampleRate, txWaveVolMax, txWaveFormat
//!
//! @usage @code
//!          txWaveData_t purr = txWaveLoadWav ("Purr.wav");
//!
//!          txWaveOut (purr);  // ����������� ����
//!          txWaveOut();       // ������� ����� ������������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

txWaveData_t txWaveLoadWav (const char filename[]);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Wave
//! @brief   ��������� �������� ������ � WAV-�����.
//!
//! @param   data        ������ ��� ������ (��������, ���������� � ������� @ref txWaveIn(), ��� ����������� �� �������)
//! @param   filename    ��� ����� � ����������� WAV
//!
//! @return  true, ���� ���� �������� �� ������, ����� false
//!
//! @see     txWaveIn(), txWaveSampleRate, txWaveVolMax, txWaveFormat
//!
//! @usage @code
//!          txWaveData_t wav = txWaveIn (20000);   // ���������� ����
//!          txWaveSaveWav (wav, "Recording.wav");  // ��������� ���� � ����
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txWaveSaveWav (const txWaveData_t& data, const char filename[]);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   �������� ���� ������������ ������ ����� calloc � �������������� ��������������� ���� ���������.
//!
//! @param   type  ��� ������, ����������� � ������
//! @param   size  ���������� ��������� ���� @p type
//!
//! @return  ���������� ������
//!
//! @usage @code
//!          char* str = CALLOC (char, 100);
//!          ...
//!          FREE (str);
//! @endcode
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define CALLOC( type, size )  ( (type*) calloc ((size), sizeof (type)) )

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ������������ ������ � �������� ��������� �� ���.
//!
//! @param   ptr  ��������� �� ������������� ������. ����� ������������ ������ �� ����������.
//!
//! @usage @code
//!          char* str = CALLOC (char, 100);
//!          ...
//!          FREE (str);
//! @endcode
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define FREE( ptr )  ( free (ptr), (ptr) = NULL )

//-----------------------------------------------------------------------------------------------------------------

/*! @cond INTERNAL */

}};  // namespace TX; namespace

/*! @endcond */

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   �������� ���� ������������ ������ ����� new � ���������� ��� ����������� ����� ������� ������������.
//!
//! @param   size  ������ ��������/���������
//!
//! @return  ���������� ������
//!
//! @usage @code
//!          int* i = new(0) int;
//!          ...
//!          delete i;
//! @endcode
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

inline void* operator new (size_t size, int /* = 0 */) { return ::memset (::new char [size], 0, size); }

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   �������� ���� ������������ ������ ����� new[] � ���������� ����������� ����� ������� �������������.
//!
//! @param   size   ������ ���������
//! @param   items  ���������� ��������� �������
//!
//! @return  ���������� ������
//!
//! @usage @code
//!          char* str = new(0) char [100];
//!          ...
//!          delete[] str;
//! @endcode
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

inline void* operator new (size_t size, size_t items, int /* = 0 */) { return ::new (0) char [size * items];         }

/*! @cond INTERNAL */

namespace { namespace TX {

/*! @endcond */

//{================================================================================================================

namespace Win32
{
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutOpen,            (HWAVEOUT* wave, UINT device, const WAVEFORMATEX* format,
                                                           DWORD callback, DWORD callbackData, DWORD flags));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutPrepareHeader,   (HWAVEOUT wave, WAVEHDR* header, UINT size));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutUnprepareHeader, (HWAVEOUT wave, WAVEHDR* header, UINT size));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutWrite,           (HWAVEOUT wave, WAVEHDR* header, UINT size));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutReset,           (HWAVEOUT wave));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutClose,           (HWAVEOUT wave));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutBreakLoop,       (HWAVEOUT wave));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveOutGetPosition,     (HWAVEOUT wave, MMTIME* time, UINT size));

_TX_DLLIMPORT ("WinMM", MMRESULT, waveInOpen,             (HWAVEIN* wave, UINT device, const WAVEFORMATEX* format,
                                                           DWORD callback, DWORD callbackData, DWORD flags));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInPrepareHeader,    (HWAVEIN wave, WAVEHDR* header, UINT size));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInUnprepareHeader,  (HWAVEIN wave, WAVEHDR* header, UINT size));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInAddBuffer,        (HWAVEIN wave, WAVEHDR* header, UINT size));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInStart,            (HWAVEIN wave));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInStop,             (HWAVEIN wave));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInReset,            (HWAVEIN wave));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInClose,            (HWAVEIN wave));
_TX_DLLIMPORT ("WinMM", MMRESULT, waveInGetPosition,      (HWAVEIN wave, MMTIME* time, UINT size));
}

//}================================================================================================================

#if defined (_GCC_VER) && (_GCC_VER < 530)
#pragma GCC system_header
#endif

int _txWaveInit();

int _txWaveInitialized = _txWaveInit();

int _txWaveInit()
    {
    assert (sizeof (txWaveSample_t)      == txWaveFormat.nBlockAlign);
    assert (txWaveFormat.nBlockAlign     == txWaveFormat.wBitsPerSample/8 * txWaveFormat.nChannels);
    assert (txWaveFormat.nAvgBytesPerSec == txWaveFormat.nSamplesPerSec   * txWaveFormat.nBlockAlign);

    (void) _txWaveInitialized;
    return 1;
    }

//-----------------------------------------------------------------------------------------------------------------

HWAVEOUT txWaveOut (int timeMs /* = -INT_MAX */,
                    double freqL /* =  0 */, double volL /* = 50 */,
                    double freqR /* = -1 */, double volR /* = -1 */,
                    int loops /* = 1 */,
                    const txWaveData_t& data /* = txWaveData_t() */)
    {
    static HWAVEOUT waveOut = NULL;
    static WAVEHDR  waveHdr[8] = {};

    static long long phase[2] = {};

    int time0 = GetTickCount();

    // Check the params

    if (freqR < 0) freqR = freqL;
    if (volR  < 0) volR  = volL;

    if (loops == 1) loops = 0;

    // Initialize the wave device

    if (!waveOut)
        {
        Win32::waveOutOpen (&waveOut, WAVE_MAPPER, &txWaveFormat, 0, 0, 0) == MMSYSERR_NOERROR asserted;
        if (!waveOut) return NULL;
        }

    // Prepare and start the sound

    if (timeMs && (freqL > 0 || freqR > 0 || data.size()))
        {
        // Prepare the WAVEHDR

        WAVEHDR wav = {};

        unsigned size = (unsigned) data.size();
        if ((freqL > 0 && volL > 0) || (freqR > 0 && volR > 0)) size = ROUND (abs (timeMs) * txWaveSampleRate);

        wav.dwBufferLength = (unsigned) (size * sizeof (txWaveSample_t));
        wav.lpData = (char*) malloc (wav.dwBufferLength); assert (wav.lpData);

        wav.dwFlags = loops? (WHDR_BEGINLOOP | WHDR_ENDLOOP) : 0;
        wav.dwLoops = loops;

        // Copy raw data

        size_t szPrefill = MIN (size, data.size()) * sizeof (txWaveSample_t);

        if (szPrefill) memcpy (wav.lpData, &data[0], szPrefill);

        // Add harmonic data. All values premultiplied by 360 and converted to integers.

        if (freqL > 0 || freqR > 0)
            {
            long long time    =   ROUND (360 * abs (timeMs) / 1000.0),
                      freq[2] = { ROUND (360 * freqL),
                                  ROUND (360 * freqR) },
                      vol [2] = { ROUND (360 * volL / 101.0  * (int) txWaveVolMax),
                                  ROUND (360 * volR / 101.0  * (int) txWaveVolMax) };

            static const int sinTab[91] = {  0,   6,  13,  19,  25,  31,  38,  44,  50,  56,
                                            63,  69,  75,  81,  87,  93,  99, 105, 111, 117,
                                           123, 129, 135, 141, 146, 152, 158, 163, 169, 175,
                                           180, 185, 191, 196, 201, 206, 212, 217, 222, 227,
                                           231, 236, 241, 246, 250, 255, 259, 263, 268, 272,
                                           276, 280, 284, 288, 291, 295, 298, 302, 305, 309,
                                           312, 315, 318, 321, 324, 326, 329, 331, 334, 336,
                                           338, 340, 342, 344, 346, 348, 349, 351, 352, 353,
                                           355, 356, 356, 357, 358, 359, 359, 360, 360, 360, 360 };

            txWaveSample_t* buf = (txWaveSample_t*) wav.lpData;

            #pragma GCC diagnostic ignored "-Wconversion"

            #define MAKEDATA_(chan)                                                            \
                {                                                                              \
                for (unsigned i = 0; i < size; i++)                                            \
                    {                                                                          \
                    int ch = (i < szPrefill)? buf[i].ch[chan] * 129600 : 0;                    \
                                                                                               \
                    int t  = (phase[chan] + freq[chan] * time * i/size) / 360 % 360;           \
                                                                                               \
                    int sign = +1;                                                             \
                    if (t >= 180) { t = t - 180; sign = -1; }                                  \
                    if (t >=  90) { t = 180 - t; }                                             \
                                                                                               \
                    assert (0 <= t && t < (int) sizearr (sinTab));                             \
                                                                                               \
                    buf[i].ch[chan] = (short) ((ch + vol[chan] * sign * sinTab [t]) / 129600); \
                    }                                                                          \
                                                                                               \
                phase[chan] += freq[chan] * time;                                              \
                }

            if (volL > 0 && freqL > 0) MAKEDATA_ (0);
            if (volR > 0 && freqR > 0) MAKEDATA_ (1);

            #undef MAKEDATA_
            #pragma GCC diagnostic warning "-Wconversion"
            }

        // Find free WAVEHDR

        WAVEHDR* next = NULL;

        for (size_t i = 0; ; i = (i+1) % sizearr (waveHdr), Sleep (_txWindowUpdateInterval))
            {
            if (Win32::waveOutUnprepareHeader (waveOut, &waveHdr[i], sizeof (WAVEHDR)) == MMSYSERR_NOERROR)
                {
                next = &waveHdr[i];  // Free WAVEHDR found
                FREE (next->lpData);
                break;
                }

            if (timeMs < 0 && GetTickCount() - time0 < (unsigned) abs (timeMs))
                break;
            }

        // Start the sound

        if (next)
            {
            std::swap (wav, *next);  // Put the data prepared to queue

            Win32::waveOutPrepareHeader (waveOut, next, sizeof (WAVEHDR)) == MMSYSERR_NOERROR asserted;
            Win32::waveOutWrite         (waveOut, next, sizeof (WAVEHDR)) == MMSYSERR_NOERROR asserted;

            Win32::waveOutBreakLoop     (waveOut)                         == MMSYSERR_NOERROR asserted;
            }
        }

    // Wait and stop the sound

    if (timeMs <= 0)
        {
        if (!timeMs) Win32::waveOutReset (waveOut) == MMSYSERR_NOERROR asserted;  // Immediate stop

        // Wait for sound to stop

        for (size_t i = 0; i < sizearr (waveHdr); i++, Sleep (_txWindowUpdateInterval))
            {
            if (GetTickCount() - time0 >= (unsigned) abs (timeMs)) break;

            if ((waveHdr[i].dwFlags & WHDR_PREPARED) && !(waveHdr[i].dwFlags & WHDR_DONE)) { i--; continue; }
            }

        Win32::waveOutReset (waveOut) == MMSYSERR_NOERROR asserted;

        // Free the buffers

        for (size_t i = 0; i < sizearr (waveHdr); i++)
            {
            Win32::waveOutUnprepareHeader (waveOut, &waveHdr[i], sizeof (WAVEHDR));
            FREE (waveHdr[i].lpData);
            }

        // Close the wave device

        Win32::waveOutClose (waveOut) == MMSYSERR_NOERROR asserted;
        waveOut = NULL;
        }

    return waveOut;
    }

//-----------------------------------------------------------------------------------------------------------------

inline HWAVEOUT txWaveOut (const txWaveData_t& data, int loops /* = 1 */)
    {
    return txWaveOut (-INT_MAX, 0,0,0,0, loops, data);
    }

//-----------------------------------------------------------------------------------------------------------------

txWaveData_t txWaveIn (int timeMs,
                       MonitorProc_t monitorProc /* = NULL */, void* userData /* = NULL */,
                       unsigned frameTime /* = 0 */)
    {
    static HWAVEIN waveIn = NULL;
    static WAVEHDR waveHdr[2] = {};

    txWaveData_t data;

    int time0 = GetTickCount();

    // Initialize the wave device

    if (!waveIn)
        {
        Win32::waveInOpen (&waveIn, WAVE_MAPPER, &txWaveFormat, 0, 0, 0) == MMSYSERR_NOERROR asserted;
        if (!waveIn) return data;
        }

    // Calculate the sizes

    if (!frameTime) frameTime = 100;  // Default frame time

    unsigned size  = ROUND (abs (timeMs) * txWaveSampleRate);
    unsigned frame = ROUND (frameTime    * txWaveSampleRate);

    // Feed the recording queue with buffers

    for (unsigned i = 0; i < sizearr (waveHdr); i++)
        {
        waveHdr[i].dwBufferLength = frame * (unsigned) sizeof (txWaveSample_t);
        waveHdr[i].lpData = (char*) malloc (waveHdr[i].dwBufferLength); assert (waveHdr[i].lpData);

        Win32::waveInPrepareHeader (waveIn, &waveHdr[i], sizeof (waveHdr[i])) == MMSYSERR_NOERROR asserted;
        Win32::waveInAddBuffer     (waveIn, &waveHdr[i], sizeof (waveHdr[i])) == MMSYSERR_NOERROR asserted;
        }

    // Start the recording

    data.resize (size);
    txWaveData_t (data) .swap (data);  // C++11: data.shrink_to_fit();
    data.resize (0);

    Win32::waveInStart (waveIn) == MMSYSERR_NOERROR asserted;

    // Recording loop

    for (size_t i = 0; ; i = (i+1) % sizearr (waveHdr), Sleep (_txWindowUpdateInterval))
        {
        WAVEHDR* wav = &waveHdr[i];

        if (!(wav->dwFlags & WHDR_DONE)) continue;  // Buffer is not done yet

        // Process the buffer recorded

        size_t pos = data.size();
        data.resize (pos + MIN (wav->dwBytesRecorded / sizeof (txWaveSample_t), size - pos));

        memcpy (&data[0] + pos, wav->lpData, (data.size() - pos) * sizeof (txWaveSample_t));

        if (monitorProc && !monitorProc (waveIn, data, userData)) break;             // Monitor breaks the recording

        if (timeMs < 0 && GetTickCount() - time0 >= (unsigned) abs (timeMs)) break;  // Time is over

        if (data.size() == size) break;                                              // All data recorded

        // Re-feed the queue with the buffer

        wav->dwFlags         = 0;
        wav->dwBytesRecorded = 0;

        Win32::waveInPrepareHeader (waveIn, wav, sizeof (*wav)) == MMSYSERR_NOERROR asserted;
        Win32::waveInAddBuffer     (waveIn, wav, sizeof (*wav)) == MMSYSERR_NOERROR asserted;
        }

    // Stop the recording

    Win32::waveInStop  (waveIn) == MMSYSERR_NOERROR asserted;
    Win32::waveInReset (waveIn) == MMSYSERR_NOERROR asserted;

    // Free the buffers

    for (unsigned i = 0; i < sizearr (waveHdr); i++)
        {
        Win32::waveInUnprepareHeader (waveIn, &waveHdr[i], sizeof (waveHdr[i])) == MMSYSERR_NOERROR asserted;
        FREE (waveHdr[i].lpData);
        }

    // Close the wave device

    Win32::waveInClose (waveIn) == MMSYSERR_NOERROR asserted;
    waveIn = NULL;

    return data;
    }

//-----------------------------------------------------------------------------------------------------------------

unsigned long txWaveGetPosition (void* wave)
    {
    static MMTIME time = { TIME_SAMPLES };

    if (Win32::waveOutGetPosition ((HWAVEOUT) wave, &time, sizeof (time)) == MMSYSERR_NOERROR) return (long) time.u.sample;
    if (Win32::waveInGetPosition  ((HWAVEIN)  wave, &time, sizeof (time)) == MMSYSERR_NOERROR) return (long) time.u.sample;

    return ULONG_MAX;
    }

//-----------------------------------------------------------------------------------------------------------------

struct WAVFILEHEADER
    {
    unsigned       chunkId;        // 0x46464952 'RIFF'
    unsigned long  chunkSize;      // FileSize - sizeof (chunkId) - sizeof (chunkSize)
    unsigned       format;         // 0x45564157 'WAVE'

    unsigned       subchunk1Id;    // 0x20746d66 'fmt '
    unsigned long  subchunk1Size;  // sizeof (PCMWAVEFORMAT), maybe +2, see below

    PCMWAVEFORMAT  pcm;

    /*                             // Here lies metadata, we ignore them

    struct                         // If (subchunk1Size == sizeof (PCMWAVEFORMAT) + 2)
        {
        unsigned short size;
        unsigned char  data[];     // data [size]
        }
        metadata[];

    */

    unsigned       subchunk2Id;    // 0x61746164 'data'
    unsigned long  subchunk2Size;  // length (numSamples * pcm.wf.nChannels * pcm.wBitsPerSample/8

    txWaveSample_t data[];         // data [numSamples], size in bytes = subchunk2Size
    };

//-----------------------------------------------------------------------------------------------------------------

#define TRY        int __error = 0;
#define FAIL(err)  { __error = (err); goto __catch; }
#define FAILURE    FAIL (__LINE__)
#define CATCH      __catch: if (__error)

//-----------------------------------------------------------------------------------------------------------------

txWaveData_t txWaveLoadWav (const char filename[])
    {
    assert (filename);

    FILE* f = NULL;
    txWaveData_t data;

    TRY
        {
        // Open the file

        fopen_s (&f, filename, "rb");
        if (!f) FAILURE;

        long size = _filelength (_fileno (f));

        // Allocate memory for waveform data

        try { data.resize (size / sizeof (txWaveSample_t)); }
        catch (...) { FAILURE; }

        // Read the file header

        WAVFILEHEADER* wav = (WAVFILEHEADER*) &data[0];
        fread (wav, sizeof (WAVFILEHEADER), 1, f) == 1 asserted;

        // Check file format and properties

        if (wav->chunkId                != 0x46464952 /* 'RIFF' */)      FAILURE;
        if (wav->format                 != 0x45564157 /* 'WAVE' */)      FAILURE;
        if (wav->subchunk1Id            != 0x20746d66 /* 'fmt ' */)      FAILURE;

        if (wav->pcm.wf.wFormatTag      != txWaveFormat.wFormatTag)      FAILURE;
        if (wav->pcm.wf.nChannels       != txWaveFormat.nChannels)       FAILURE;
        if (wav->pcm.wf.nSamplesPerSec  != txWaveFormat.nSamplesPerSec)  FAILURE;
        if (wav->pcm.wf.nAvgBytesPerSec != txWaveFormat.nAvgBytesPerSec) FAILURE;
        if (wav->pcm.wf.nBlockAlign     != txWaveFormat.nBlockAlign)     FAILURE;

        if (wav->pcm.wBitsPerSample     != txWaveFormat.wBitsPerSample)  FAILURE;

        // Skip metadata

        unsigned metaSize = (wav->subchunk1Size == sizeof (PCMWAVEFORMAT) + 2)? *(short*)&wav->subchunk2Id : 0;
        fread (&wav->subchunk2Id, 1, metaSize, f) == metaSize asserted;

        // Now we at waveform data section
        
        if (wav->subchunk2Id != 0x61746164 /* 'data' */) FAILURE;

        // Read the waveform data

        size -= (long) sizeof (WAVFILEHEADER) + metaSize;
        fread (wav, size, 1, f) == 1 asserted;

        // Adjust vector size according to the data read

        data.resize (size / sizeof (txWaveSample_t));
        }

    CATCH
        {
        txNotifyIcon (NIIF_ERROR, "txWaveLoadWav() ��������", "\n������ ������ WAV-����� \"%s\"\n\n"
                                                              "��. %s, ������ %d", filename, __FILE__, __error);
        }

    if (f) fclose (f) == 0 asserted;

    return data;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txWaveSaveWav (const txWaveData_t& data, const char filename[])
    {
    assert (filename);

    unsigned size = (unsigned) (data.size() * sizeof (txWaveSample_t));

    WAVFILEHEADER header = { 0x46464952 /* 'RIFF' */,
                             (unsigned) (sizeof (header) + size - sizeof (header.chunkId) - sizeof (header.chunkSize)),
                             0x45564157 /* 'WAVE' */,

                             0x20746d66 /* 'fmt ' */,
                             sizeof (PCMWAVEFORMAT),

                             {{txWaveFormat.wFormatTag,     txWaveFormat.nChannels,
                               txWaveFormat.nSamplesPerSec, txWaveFormat.nAvgBytesPerSec,
                               txWaveFormat.nBlockAlign},   txWaveFormat.wBitsPerSample},

                             // Here should be metadata, we live happy without them
                             
                             0x61746164 /* 'data' */,
                             size
                             };

    FILE* f = NULL;
    fopen_s (&f, filename, "wb");
    if (!f) return false;

    fwrite (&header,  sizeof (header), 1, f) == 1 asserted;
    fwrite (&data[0], size,            1, f) == 1 asserted;

    fclose (f) == 0 asserted;

    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

/*! @cond INTERNAL */

}};  // namespace TX; namespace

/*! @endcond */

//=================================================================================================================

#if defined (_MSC_VER)
    #pragma warning (pop)
    #endif

//=================================================================================================================

#endif  // __TXWAVE_INCLUDED
