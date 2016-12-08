//=================================================================================================================
//           [These sections are for folding control  in Code::Blocks]
//{          [Best viewed with "Fold all on file open" option enabled]             [best screen width is 120 chars]
//=================================================================================================================
//!
//! @file    TXLib.h
//! @brief   Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!          $Version: 00173a, Revision: 120 $
//!          $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//!          $Date: 2016-12-08 04:19:47 +0400 $
//!
//!          TX Library - компактная библиотека двумерной графики для MS Windows на С++.
//!          Это небольшая "песочница" для начинающих реализована с целью помочь им в изучении
//!          простейших принципов программирования. Документация на русском языке.
//!          Философия TX Library - облегчить первые шаги в программировании и подтолкнуть
//!          к творчеству и самостоятельности.
//!
//!          TX Library is a tiny 2D graphics library for MS Windows written in C++. This is a small
//!          sandbox for the very beginners to help them to learn basic programming principles.
//!          The documentation is currently in Russian.
//!
//!          Официальный сайт библиотеки: <a href=http://txlib.ru>txlib.ru.</a>
//!
//!          См. также <a href=http://sourceforge.net/p/txlib>страницу проекта на SourceForge.</a>
//!          Короткая ссылка на онлайн-документацию: <a href=http://gg.gg/TXLib>gg.gg/TXLib.</a>
//!
//! @par     Установка библиотеки
//!
//! @note    Библиотека TXLib состоит из единственного файла и не требует никаких настроек в среде
//!          программирования, чтобы облегчить ее установку и работу для начинающих.
//!
//!       -# <a href=https://sourceforge.net/projects/txlib/files/latest/download>Скачайте</a>
//!          программу установки, загрузка по ссылке начнется автоматически. Ее имя имеет вид
//!          <tt>TXLib-v0173a.rar.exe.</tt> Цифры могут отличаться (это номер версии), расширение
//!          @c .exe может не отображаться, в зависимости от текущих настроек Windows.
//!       -# Запустите скачанную программу установки. Программа установки - это саморазархивирующийся
//!          архив, она не требует особых прав для запуска.
//!       -# На рабочем столе появится "Ярлык для TX". Откройте его и запустите систему помощи <tt>TXLib Help,</tt>
//!          изучите ее. Простейший пример см. <http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/a00001.htm>
//!          здесь.</a> Другие примеры см. <a href=http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/dirs.htm>
//!          в папке Examples,</a> в папке Examples/Demo.
//!
//!       -  Если при установке происходят ошибки или запуск программы установки невозможен, скачайте
//!          файл библиотеки @c \TXLib.h <a href=http://sf.net/projects/txlib/files/TXLib/TXLib.h/download>
//!          отсюда (загрузка начнется автоматически)</a>, скопируйте его в свою рабочую папку
//!          (где вы сохраняете свои программы). Скачайте систему помощи <tt>TXLib Help</tt>
//!          <a href=http://sf.net/projects/txlib/files/TXLib/TXLib%20Help.chm/download>отсюда</a>
//!          или пользуйтесь <a href=http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/index.htm>
//!          системой помощи онлайн.</a>
//!
//!       -# Для полной обработки ошибок библиотеке требуются модули, которые желательно установить
//!          (скопировать) в папку Windows. Устанавливать эти библиотеки не обязательно. Программы,
//!          использующие TXLib, будут запускаться и без них.
//!
//!          -# Модули библиотеки Microsoft DBGHELP для доступа к отладочным символам Microsoft:
//!
//!             - @c dbghelp32.dll для 32-разрядных программ (либо @c dbghelp.dll, 32-разрядная версия),
//!             - @c dbghelp64.dll для 64-разрядных программ (либо @c dbghelp.dll, 64-разрядная версия),
//!             - @c symsrv32.dll  для 32-разрядных программ (либо @c symsrv.dll,  32-разрядная версия),
//!             - @c symsrv64.dll  для 64-разрядных программ (либо @c symsrv.dll,  64-разрядная версия),
//!             - @c symsrv.yes.
//!
//!          -# Модули библиотеки <a href=https://github.com/jrfonseca/drmingw/releases>DrMinGW</a> для доступа
//!             к отладочным символам MinGW компилятора GCC @c g++:
//!
//!             - @c mgwhelp32.dll для 32-разрядных программ (либо @c mgwhelp.dll, 32-разрядная версия),
//!             - @c mgwhelp64.dll для 64-разрядных программ (либо @c mgwhelp.dll, 64-разрядная версия).
//!
//!          Суффиксы @c 32 и @c 64 помогают отличить 32-разрядную и 64-разрядную версии DLL-файлов библиотек.
//!          Например, @c dbghelp32.dll - это просто переименованная 32-разрядная версия файла @c dbghelp.dll.
//!
//!          <b>Cамораспаковывающийся архив с этими библиотеками можно скачать
//!          <a href=http://storage.ded32.net.ru/Lib/TX/TXLib-SupportDLLs.rar.exe>здесь.</a></b>
//!
//!          Для наиболее полной диагностики ошибок полностью отключайте оптимизацию при компиляции. Например,
//!          для компилятора GCC @c g++ - с помощью ключа командной строки @c -O0. Разные среды программирования
//!          позволяют задать эти ключи по-разному, например, в CodeBlocks через Главное меню - Settings -
//!          Compiler - (Global Compiler Settings) - (Compiler Settings) - Other Options.
//!
//! @note    Кодовая страница в редакторе среды разработки должна быть установлена как Windows CP1251, проверьте
//!          это. В разных средах разработки она устанавливается по-разному, например, в CodeBlocks через
//!          Главное меню - Settings - Editor - (General Settings) - Other Settings - Encoding. Иначе русские
//!          буквы в сообщениях TXLib будут отображаться неправильно.
//!
//! @warning <b>Это альфа-версия. Для использования библиотеки требуется согласование с ее автором.</b> @nn
//!          Правила использования материалов библиотеки и сайта см. на <a href=http://txlib.ru>официальном
//!          сайте TXLib.</a>
//!
//! @par     Баг-трекер на SourceForge:
//!        - <a href=http://sourceforge.net/p/txlib/bugs/new><b>Сообщить об ошибке</b></a>
//!
//           $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//-----------------------------------------------------------------------------------------------------------------
//!
//! @defgroup Drawing   Рисование
//! @defgroup Mouse     Поддержка мыши
//! @defgroup Dialogs   Диалоговые окна
//! @defgroup Misc      Разное
//! @defgroup Service   Служебное
//! @defgroup Technical Технические детали
//}
//=================================================================================================================

#if !defined (__TXLIB_H_INCLUDED)                // <<<<<<<<< The code is here, unfold it <<<<<<<<<<<<<<<<<<<<<<<<<
#define       __TXLIB_H_INCLUDED

//-----------------------------------------------------------------------------------------------------------------
//{          Version information
//-----------------------------------------------------------------------------------------------------------------

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup   Technical
//! @brief     Текущая версия библиотеки.
//!
//!            Версия библиотеки в целочисленном формате: старшее слово - номер версии, младшее - номер ревизии,
//!            в двоично-десятичном формате. Например, @c 0x172a0050 - версия @c 0.172a, ревизия @c 50.
//! @code
//!            #define _TX_VERSION "TXLib [Version: 1.72a, Revision 50]"                 //
//!            #define _TX_AUTHOR  "Copyright (C) Ded (Ilya Dedinsky, http://txlib.ru)"  //  ПРИМЕР
//!            #define _TX_VER     0x172a0000                                            //
//! @endcode
//!            Эти константы автоматически обновляются при изменении версии.
//!
//! @see       txVersion()
//!
//! @usage @code
//!            #if !(defined (_TX_VER) && (_TX_VER >= 0x172a0000))
//!            #error Must use TXLib.h version >= 1.72 to compile this.
//!            #endif
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------
//! @{

#define _TX_VER      _TX_v_FROM_CVS ($VersionInfo: , TXLib.h, 00173a, 120, 2016-12-08 04:19:47 +0300, "Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru>", $)
#define _TX_VERSION  _TX_V_FROM_CVS ($VersionInfo: , TXLib.h, 00173a, 120, 2016-12-08 04:19:47 +0300, "Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru>", $)
#define _TX_AUTHOR   _TX_A_FROM_CVS ($VersionInfo: , TXLib.h, 00173a, 120, 2016-12-08 04:19:47 +0300, "Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru>", $)

//! @cond INTERNAL
#define _TX_v_FROM_CVS(_1,file,ver,rev,date,auth,_2)  ((0x##ver##u << 16) | 0x##rev##u)
#define _TX_V_FROM_CVS(_1,file,ver,rev,date,auth,_2)  "TXLib [Ver: " #ver ", Rev: " #rev "]"
#define _TX_A_FROM_CVS(_1,file,ver,rev,date,auth,_2)  "Copyright (C) " auth
//! @endcond

//! @}
//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    Адаптация к компиляторам и платформам
//-----------------------------------------------------------------------------------------------------------------
//! @{ @cond INTERNAL

#if !defined (__cplusplus)

    #ifdef __GNUC__
    #error
    #error --------------------------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Must use C++ to compile TXLib.h. Now you are using C only.
    #error
    #error CHECK source file EXTENSION. Maybe it is ".C". It must be ".CPP".
    #error If your file is named, for example, "Untitled.C", go to menu [File], then
    #error then [Save As] and rename it to "Untitled.CPP". Please do NOT use spaces.
    #error --------------------------------------------------------------------------------------------------------
    #error

#endif

#if !defined (WIN32) && !defined (__WIN32__) && !defined(_WIN32) && !defined(_WIN32_WINNT)

    #ifdef __GNUC__
    #error
    #error --------------------------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Windows (MSVC/Win32 or GCC/MinGW) is the only supported system, sorry.
    #error
    #error In Linux or iOS, you should write your own TXLib and share it with your friends,
    #error or use wine.
    #error --------------------------------------------------------------------------------------------------------
    #error

#endif

#if  defined (UNICODE) || defined (_UNICODE)

    #ifdef __GNUC__
    #warning TXLib.h: Disabling the UNICODE
    #endif

    #undef   UNICODE                            // Burn Unicode, burn
    #undef  _UNICODE

    #if defined (_WINDOWS_H) || defined (_INC_WINDOWS) || defined (_WINDOWS_) || defined (__WINDOWS__)

    #ifdef __GNUC__
    #error
    #error --------------------------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Should include "TXLib.h" BEFORE or INSTEAD of <Windows.h> in UNICODE mode.
    #error
    #error REARRANGE your #include directives, or DISABLE the UNICODE mode by #undef UNICODE/_UNICODE.
    #error --------------------------------------------------------------------------------------------------------
    #error

    #endif

#endif

#if  defined (__STRICT_ANSI__)                  // Try to extend strict ANSI rules

    #undef  __STRICT_ANSI__
    #define __STRICT_ANSI__UNDEFINED

    #if defined (_STRING_H_) || defined (_INC_STRING) || defined (_STDIO_H_) || defined (_INC_STDIO)

    #ifdef __GNUC__
    #error
    #error --------------------------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Should include "TXLib.h" BEFORE <string.h> or <stdio.h> in Strict ANSI mode.
    #error
    #error REARRANGE your #include directives, or DISABLE ANSI-compliancy by #undef __STRICT_ANSI__.
    #error --------------------------------------------------------------------------------------------------------
    #error

    #endif

#endif

#if  defined (__GNUC__)

    #define _GCC_VER                   ( __GNUC__*100 + __GNUC_MINOR__*10 + __GNUC_PATCHLEVEL__ )

    #if (_GCC_VER >= 420)

        #pragma GCC diagnostic warning "-Wall"
        #pragma GCC diagnostic warning "-Weffc++"
        #pragma GCC diagnostic warning "-Wextra"

        #pragma GCC diagnostic warning "-Wcast-align"
        #pragma GCC diagnostic warning "-Wcast-qual"
        #pragma GCC diagnostic warning "-Wchar-subscripts"
        #pragma GCC diagnostic warning "-Wconversion"
        #pragma GCC diagnostic warning "-Wctor-dtor-privacy"
        #pragma GCC diagnostic warning "-Wempty-body"
        #pragma GCC diagnostic warning "-Wfloat-equal"
        #pragma GCC diagnostic warning "-Wformat-nonliteral"
        #pragma GCC diagnostic warning "-Wformat-security"
        #pragma GCC diagnostic warning "-Wformat"
        #pragma GCC diagnostic warning "-Wlogical-op"
        #pragma GCC diagnostic warning "-Wmissing-declarations"
        #pragma GCC diagnostic warning "-Wnon-virtual-dtor"
        #pragma GCC diagnostic warning "-Woverloaded-virtual"
        #pragma GCC diagnostic warning "-Wpacked"
        #pragma GCC diagnostic warning "-Wpointer-arith"
        #pragma GCC diagnostic warning "-Wredundant-decls"
        #pragma GCC diagnostic warning "-Wshadow"
        #pragma GCC diagnostic warning "-Wsign-promo"
        #pragma GCC diagnostic warning "-Wstrict-aliasing"
        #pragma GCC diagnostic warning "-Wstrict-null-sentinel"
        #pragma GCC diagnostic warning "-Wstrict-overflow"
        #pragma GCC diagnostic warning "-Wswitch-default"
        #pragma GCC diagnostic warning "-Wswitch-enum"
        #pragma GCC diagnostic warning "-Wsync-nand"
        #pragma GCC diagnostic warning "-Wundef"
        #pragma GCC diagnostic warning "-Wunused"
        #pragma GCC diagnostic warning "-Wvariadic-macros"

        #pragma GCC diagnostic ignored "-Winline"
        #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
        #pragma GCC diagnostic ignored "-Wold-style-cast"
        #pragma GCC diagnostic ignored "-Wunreachable-code"
        #pragma GCC diagnostic ignored "-Wunused-function"

        #if (_GCC_VER >= 461)
        #pragma GCC diagnostic warning "-Wsuggest-attribute=noreturn"
        #endif

        #if (_GCC_VER >= 471)
        #pragma GCC diagnostic ignored "-Wnarrowing"
        #endif

        #if (_GCC_VER >= 472)
        #pragma GCC diagnostic ignored "-Wliteral-suffix"
        #endif

        #if (_GCC_VER >= 481)
        #pragma GCC diagnostic warning "-Waggressive-loop-optimizations"
        #pragma GCC diagnostic ignored "-Wvarargs"
        #endif

        #if (_GCC_VER >= 510)
        #pragma GCC diagnostic warning "-Wconditionally-supported"
        #pragma GCC diagnostic warning "-Wformat-signedness"
        #pragma GCC diagnostic warning "-Wopenmp-simd"
        #pragma GCC diagnostic warning "-Wsuggest-final-methods"
        #pragma GCC diagnostic warning "-Wsuggest-final-types"
        #pragma GCC diagnostic warning "-Wsuggest-override"
        #endif

        // These warning settings for TXLib.h only and will be re-enabled at end of file:

        #if (_GCC_VER >= 460)
        #pragma GCC push_options
        #pragma GCC diagnostic push
        #endif

        #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
        #pragma GCC diagnostic ignored "-Wredundant-decls"
        #pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
        #pragma GCC diagnostic ignored "-Wshadow"
        #pragma GCC diagnostic ignored "-Wsign-conversion"
        #pragma GCC diagnostic ignored "-Wstrict-aliasing"
        #pragma GCC diagnostic ignored "-Wunused-value"
        #pragma GCC diagnostic ignored "-Wunused-label"    // Just for fun in _txCanvas_OnCmdAbout()

        #pragma GCC optimize           "no-strict-aliasing"

    #endif

    #if (_GCC_VER >= 420)
        #define _tx_thread             __thread
    #else
        #define _tx_thread
    #endif

    #if (_GCC_VER >= 472)
        #define _tx_explicit           explicit

        #if !defined (_TX_TESTING)              // This is not a fair play, but this pragma is the only way to clear the
        #pragma GCC system_header               // "override controls (override/final) only available with -std=c++11
        #endif                                  // or -std=gnu++11" warning when -std=... command line option is not set.

        #define _TX_DEPRECATED         __attribute__ (( deprecated ))

    #else
        #define _tx_explicit
        #define _TX_DEPRECATED

    #endif

    #ifndef MINGW_HAS_SECURE_API
    #define MINGW_HAS_SECURE_API       1
    #endif

    #ifndef __USE_MINGW_ANSI_STDIO
    #define __USE_MINGW_ANSI_STDIO     1
    #endif

    #define _TX_CHECK_FORMAT( arg )    __attribute__ (( format (printf, (arg), (arg)+1) ))

    template <typename T>
    inline T _txNOP (T value)          { return value; }      // To suppress performance warnings in assert etc.

    // From MinGW\include\float.h which is replaced by MinGW\lib\gcc\i686-pc-mingw32\x.x.x\include\float.h
    extern "C" __declspec (dllimport)  unsigned int __cdecl _controlfp (unsigned int unNew, unsigned int unMask);
    extern "C"                         void         __cdecl _fpreset   (void);

#else

    #define _TX_CHECK_FORMAT( arg )
    #define _TX_DEPRECATED

    #define _txNOP( value )            ( value )

#endif

#if  defined (_MSC_VER)

    #pragma warning (disable: 4616)             // #pragma warning: warning number 'n' out of range, must be between '4001' and '4999'
    #pragma warning (disable: 5032)             // detected #pragma warning (push) with no corresponding #pragma warning (pop)

    #pragma warning (push, 4)                   // Set maximum warning level. This 'push' is to set the level only. It will NOT be popped.

    #pragma warning (disable: 4514)             // unreferenced inline function has been removed
    #pragma warning (disable: 4710)             // function not inlined
    #pragma warning (disable: 4786)             // identifier was truncated to '255' characters in the debug information

    // These warning settings for TXLib.h only and will be re-enabled at end of file:

    #pragma warning (push)

    #pragma warning (disable: 4619)             // #pragma warning: there is no warning number 'n'

    #pragma warning (disable: 4127)             // conditional expression is constant
    #pragma warning (disable: 4200)             // nonstandard extension used: zero-sized array in struct/union
    #pragma warning (disable: 4351)             // new behavior: elements of array will be default initialized
    #pragma warning (disable: 4512)             // assignment operator could not be generated
    #pragma warning (disable: 4611)             // interaction between '_setjmp' and C++ object destruction is non-portable
    #pragma warning (disable: 4702)             // unreachable code
    #pragma warning (disable: 4481)             // nonstandard extension used: override specifier 'override'

    #define _tx_thread                 __declspec (thread)

    #if  (_MSC_VER == 1200)                     // MSVC 6 (1998)

        #define _MSC_VER_6                      // Flag the bad dog

        #pragma warning (disable: 4511)         // copy constructor could not be generated
        #pragma warning (disable: 4514)         // unreferenced inline function has been removed
        #pragma warning (disable: 4663)         // C++ language change: to explicitly specialize class template
        #pragma warning (disable: 4710)         // function not inlined
        #pragma warning (disable: 4786)         // identifier was truncated to '255' characters in the debug information

        #if !defined (WINVER)
            #define   WINVER           0x0400   // MSVC 6: Defaults to Windows 95
        #endif

        #if !defined (NDEBUG)
            #define _CRTDBG_MAP_ALLOC 1         // Set debug mode heap allocation
        #endif

        #define AC_SRC_ALPHA           0x01     // Copied from Windows SDK 7.0a.

    #endif

    #if (_MSC_VER >= 1400)                      // MSVC 8 (2005) or greater

        #pragma warning (disable: 26135)        // missing locking annotation
        #pragma warning (disable: 28125)        // the function must be called from within a try/except block
        #pragma warning (disable: 28159)        // consider using another function instead

        #pragma setlocale              ("russian")  // Set source file encoding, see also _TX_CP

        #if !defined (NDEBUG)
            #pragma check_stack        (      on)   // Turn on stack probes at runtime
            #pragma strict_gs_check    (push, on)   // Detects stack buffer overruns
        #endif

        #define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES  1

        #define _tx_explicit           explicit

    #else

        #define _tx_explicit

    #endif

#endif

#if  defined (__INTEL_COMPILER)

    #pragma warning (disable:  174)             // remark: expression has no effect
    #pragma warning (disable:  304)             // remark: access control not specified ("public" by default)
    #pragma warning (disable:  444)             // remark: destructor for base class "..." is not virtual
    #pragma warning (disable:  522)             // remark: function "..." redeclared "inline" after being called
    #pragma warning (disable:  981)             // remark: operands are evaluated in unspecified order
    #pragma warning (disable: 1684)             // conversion from pointer to same-sized integral type (potential portability problem)

#endif

#if !defined (WINVER)
    #define   WINVER                   0x0500   // Defaults to Windows 2000
    #define   WINDOWS_ENABLE_CPLUSPLUS          // Allow use of type-limit macros in <basetsd.h>,
#endif                                          //   they are allowed by default if WINVER >= 0x0600.

#if !defined (_WIN32_WINNT)
    #define   _WIN32_WINNT             WINVER   // Defaults to the same as WINVER
#endif

#if !defined (_WIN32_IE)
    #define   _WIN32_IE                WINVER   // Defaults to the same as WINVER
#endif

#define _USE_MATH_DEFINES              1        // math.h's M_PI etc.
#define __STDC_WANT_LIB_EXT1__         1        // string and output *_s functions
#define _SECURE_SCL                    1        // To enable checked STL iterators to throw an exception on incorrect use

#if !( defined (_MSC_VER) && (1600 <= _MSC_VER && _MSC_VER <= 1899) )
#define _SECURE_SCL_THROWS             1
#endif

#if  ( __cplusplus >= 201103L )
    #define _tx_override               override
    #define _tx_final                  final
    #define _tx_default                = default
    #define _tx_delete                 = delete

#else
    #define _tx_override
    #define _tx_final
    #define _tx_default
    #define _tx_delete

#endif

#define stristr( str1, str2 )          Win32::StrStrIA ((char*) (str1), (str2))

namespace std { enum nomeow_t { nomeow }; }     // Vital addition to the C++ standard. Should contact C++ std committee.

//! @} @endcond
//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          The Includes
//-----------------------------------------------------------------------------------------------------------------

#ifdef _MSC_VER_6
    #pragma warning (push, 3)                   // MSVC 6: At level 4, some std headers emit warnings O_o
#endif

//-----------------------------------------------------------------------------------------------------------------

#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <math.h>
#include <direct.h>
#include <process.h>
#include <signal.h>
#include <setjmp.h>
#include <locale.h>
#include <time.h>
#include <float.h>
#include <limits.h>

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <stdexcept>

#include <windows.h>
#include <tlhelp32.h>
#include <shellapi.h>

#if defined (_MSC_VER)
#pragma warning (disable: 4091)                 // 'typedef ': ignored on left of '' when no variable is declared
#pragma warning (disable: 6001)                 // Uninitialized variable usage "*ppidls"
#endif

#include <shlobj.h>

#if defined (_MSC_VER)
#pragma warning (default: 4091)                 // 'typedef ': ignored on left of '' when no variable is declared
#pragma warning (default: 6001)                 // Uninitialized variable usage "*ppidls"
#endif

#if defined (_GCC_VER)
#include <cxxabi.h>
#include <unwind.h>
#endif

#if defined (_MSC_VER)
#pragma warning (disable: 4005)                 // '...': macro redefinition

#include <new.h>
#include <ntstatus.h>
#include <crtdbg.h>
#include <rtcapi.h>
#include <dbghelp.h>

#pragma warning (default: 4005)                 // '...': macro redefinition
#endif

//-----------------------------------------------------------------------------------------------------------------

#ifdef _MSC_VER_6
    #pragma warning (pop)                       // MSVC 6: Restore max level
#endif

#ifdef __STRICT_ANSI__UNDEFINED
    #define  __STRICT_ANSI__                    // Redefine back
#endif

#if !defined (_TRUNCATE)

    #define  strncpy_s( dest, sizeof_dest, src, count )  ( (void)(sizeof_dest), strncpy ((dest), (src), (count)) )
    #define  wcsncpy_s( dest, sizeof_dest, src, count )  ( (void)(sizeof_dest), wcsncpy ((dest), (src), (count)) )
    #define  strncat_s( dest, sizeof_dest, src, count )  ( (void)(sizeof_dest), strncat ((dest), (src), (count)) )
    #define  strerror_s( buf, sizeof_buf, code        )  ( strncpy  ((buf), strerror ((int)(code)), (sizeof_buf)-1) )
    #define  strtok_s(   buf, delim, ctx              )  ( (void)(ctx), strtok ((buf), (delim)) )
    #define  fopen_s(    file, name, mode             )  ( *(file) = fopen ((name), (mode)) )
    #define _strlwr_s(   str, sizeof_str              )  ( _strlwr (str) )

    #define  ctime_s( buf, sizeof_buf, time    )         ( strncpy ((buf), ctime (time), (sizeof_buf)-1) )
    #define _controlfp_s( oldCtl, newCtl, mask )         ( *(oldCtl) = _controlfp (newCtl, mask), 0 )

    #define _snprintf_s                                  _snprintf

#endif

#if !( defined (_MSC_VER) && (_MSC_VER >= 1400) || defined (__STDC_LIB_EXT1__) )

    #define  getenv_s( sz, buf, sizeof_buf, name )       ( (void)(sz), strncpy ((buf), getenv (name), (sizeof_buf)-1) )

#endif

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          The namespaces
//-----------------------------------------------------------------------------------------------------------------

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Анонимное пространство имен для защиты от конфликтов при сборке многофайлового проекта.
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
namespace { namespace TX { }}
#endif

//}
//-----------------------------------------------------------------------------------------------------------------

/*! @cond INTERNAL */

namespace { namespace TX {                       // <<<<<<<<< The main code is here, unfold it <<<<<<<<<<<<<<<<<<<<

/*! @endcond */

//=================================================================================================================
//{          TXLIB INTERFACE
//           Интерфейс библиотеки
//=================================================================================================================

//=================================================================================================================
//{          Initialization
//! @name    Инициализация библиотеки
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создание окна рисования
//!
//! @param   sizeX     Размер окна по горизонтали (в пикселях)
//! @param   sizeY     Размер окна по вертикали   (в пикселях)
//! @param   centered  Центрирование окна на дисплее
//!
//! @return  Дескриптор (системный номер) окна TXLib. Если окно не создано, возвращается NULL.
//!
//! @note    Устанавливаются параметры рисования по умолчанию, см. функцию txSetDefaults().
//!
//! @warning Если используется многофайловый проект (с раздельной компиляцией), то графические функции TXLib,
//!          вызванные из файла проекта, будут работать только с тем окном, которое создано <b>в этом же файле</b>
//!          проекта. Если проект состоит, скажем, из файлов @c main.cpp и @c game.cpp, и в файле @c main.cpp
//!          создается графическое окно, то функции из @c game.cpp не смогут рисовать в нем. (Однако @c game.cpp
//!          сможет создать свое собственное окно.) @n
//!          Если такой программе нужно одно окно, то в проект следует включить файл, ответственный за рисование,
//!          скажем, @c graphics.cpp, и выводить графику только через функции этого файла. Такой файл (или
//!          библиотеку) в больших проектах часто называют графическим движком. @nn
//!          То же касается и использования TXLib в @b DLL.
//!
//! @note    Вспомогательные окна могут создаваться по одному на каждый файл многофайлового проекта или загруженную
//!          DLL. Для закрытия вспомогательных окон используется txDestroyWindow(). Для закрытия главного надо
//!          выйти из main().
//!
//! @warning Одновременное создание нескольких окон не потокобезопасно (not thread-safe). @nn
//!          Многооконная программа на TXLib тормозит, да и однооконная тоже не отличается высокой скоростью. Чтобы
//!          избавиться от этого, бросьте TXLib и используйте другие оконные библиотеки (<a href=http://qt-project.org>Qt</a>,
//!          <a href=http://wxwidgets.org>wxWidgets</a>, <a href=http://gtk.org>GTK+</a> и т.д., см. также
//!          <a href=http://libsdl.org>SDL</a>, <a href=http://opengl.org>OpenGL</a> и т.п.) или напишите свою.
//!          Помните, что цель TXLib - облегчить первые шаги, но потом стать ненужной.
//!
//! @see     txOK(), txWindow(), txDC(), _txWindowStyle, _txConsoleMode, _txConsoleFont, _txCursorBlinkInterval,
//!          _txWindowUpdateInterval, _TX_NOINIT, _TX_ALLOW_TRACE, TX_TRACE
//!
//! @usage @code
//!          txCreateWindow ( 800, 600);         // Окно  800х600,    центрировано
//!          txCreateWindow (1024, 768, false);  // Окно 1024х768, не центрировано
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HWND txCreateWindow (double sizeX, double sizeY, bool centered = true);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает дескриптор контекста рисования основного холста
//!
//! @param   forced  Если дескриптор равен NULL (например, если окно TXLib не создано), то сообщает об ошибке.
//!
//! @return  Дескриптор (системный номер, handler) контекста рисования (device context, DC) холста (HDC).
//!
//! @note    HDC возвращается в виде ссылки, что позволяет подменить его. Перед подменой надо сохранить старый
//!          дескриптор или освободить его с помощью txDeleteDC(). До подмены рисование должно быть заблокировано
//!          с помощью txLock() и после подмены разблокировано с помощью txUnlock().
//!
//! @see     txWindow(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          txBitBlt (txDC(),   0,   0, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 100,   0, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 0,   100, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 100, 100, 100, 100, txDC(), 0, 0);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline HDC& txDC (bool forced = false);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Установка параметров рисования по умолчанию.
//!
//! @param   dc  Дескриптор контекста рисования (холста) для установки параметров
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @par     Параметры по умолчанию:
//!        - Линии - цвет белый (TX_WHITE), толщина 1
//!        - Заливка - цвет белый (TX_WHITE)
//!        - Шрифт - Системный шрифт, цвет белый (TX_WHITE)
//!        - Растровая операция - копирование цвета (R2_COPYPEN)
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txSelectFont(), txSetROP2()
//!
//! @usage @code
//!          txSetDefaults();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txSetDefaults (HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Проверка правильности работы библиотеки
//!
//! @return  Состояние библиотеки: true - библиотека в порядке, false - не в порядке.
//!
//!          "Библиотека не в порядке" означает, что ее внутренние данные неверны. Самая простая причина -
//!          не открыто окно, однако могут быть и другие проблемы.
//!
//! @see     txCreateWindow()
//!
//! @usage @code
//!          txCreateWindow (800, 600);
//!          if (!txOK())
//!              {
//!              txMessageBox ("Не смогла создать окно", "Извините", MB_ICONSTOP);
//!              return;
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline bool txOK();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает размер холста в виде структуры POINT.
//!
//! @param   dc  Дескриптор контекста рисования (холста)
//!
//! @return  Размер окна рисования в виде структуры POINT, содержащей компоненты @c x и @c y.
//!
//! @note    Если окно не создано, возвращается размер экрана.
//!
//! @see     txGetExtentX(), txGetExtentY()
//!
//! @usage @code
//!          POINT size = txGetExtent();
//!
//!          txLine (0, 0,      size.x, size.y);
//!          txLine (0, size.y, size.x, 0);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txGetExtent (HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает ширину холста.
//!
//! @param   dc  Дескриптор контекста рисования (холста)
//!
//! @return  Ширина окна рисования.
//!
//! @note    Если окно не создано, возвращается ширина экрана.
//!
//! @see     txGetExtent(), txGetExtentY()
//!
//! @usage @code
//!          txSetTextAlign (TA_CENTER);
//!          txTextOut (txGetExtentX() / 2, 100, "Oh, oh, you're in the [army]middle now");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txGetExtentX (HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает высоту окна холста.
//!
//! @param   dc  Дескриптор контекста рисования (холста)
//!
//! @return  Высота окна рисования.
//!
//! @note    Если окно не создано, возвращается высота экрана.
//!
//! @see     txGetExtent(), txGetExtentX()
//!
//! @usage @code
//!          void DrawHouse (int height);
//!          ...
//!          DrawHouse (txGetExtentY() / 2);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txGetExtentY (HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает дескриптор окна рисования
//!
//! @return  Дескриптор (системный номер, handler) окна холста
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          SetWindowText (txWindow(), "Новые заголовки - теперь и в ваших окнах!");
//!          txMessageBox ("Распишитесь", "Получите", MB_ICONINFORMATION);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline HWND txWindow();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Возвращает строку с информацией о текущей версии библиотеки.
//!
//! @return  Строка с информацией о текущей версии библиотеки.
//!
//! @usage @code
//!          printf ("I personally love %s\n", txVersion());
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline const char* txVersion();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Возвращает номер версии библиотеки.
//!
//! @return  Номер версии библиотеки.
//!
//! @usage @code
//!          printf ("My magic number is %x\n", txVersionNumber());
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline unsigned txVersionNumber();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Возвращает имя исполняемого файла или изначальный заголовок окна TXLib.
//!
//! @param   fileNameOnly  Возвратить только полное имя исполняемого файла, полученного через Win32 функцию
//!                        GetFileModuleName (NULL, ...).
//!
//! @return  fileNameOnly = true:  Имя исполняемого файла @n
//!          fileNameOnly = false: Изначальный заголовок окна TXLib
//!
//! @note    Возвращается @b статическая строка.
//!
//! @see     txWindow(), txVersion(), txVersionNumber()
//!
//! @usage @code
//!          printf ("Смотрите на заголовок окна!");
//!
//!          for (int done = 0; done <= 100; done++)
//!              {
//!              char title [1024] = "";
//!              sprintf (title, "%s - [%-10.*s] %d%%", txGetModuleFileName (false), done/10, "||||||||||", done);
//!
//!              SetWindowText (txWindow(), title);
//!              txSleep (50);
//!              }
//!
//!          txMessageBox ("Вот такой вот progress bar", "TXLib forever)");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

const char* txGetModuleFileName (bool fileNameOnly = true);

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Setting the parameters
//! @name    Установка цветов и режимов рисования
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Названия предопределенных цветов.
//!
//!          См. TX_BLACK, TX_BLUE и другие цвета в списке выше.
//!
//!          Если кому-то эти цвета не нравятся (что неудивительно), всегда можно сделать свои с помощью RGB().
//!          См. пример ниже.
//!
//! @see     txSetColor(), txSetFillColor(), txGetColor(), txGetFillColor(), txGetPixel(), RGB()
//!
//! @usage @code
//!          #include "TXLib.h"
//!
//!          const COLORREF MY_DEEP_ROMANTIC_BLUE = RGB (  0,   0, 129),
//!                         MY_SHINING_MOONLIGHT  = RGB (128, 255,  64);
//!          ...
//!
//!          txSetColor     (TX_RED);
//!          txSetFillColor (TX_NULL);
//!
//!          txSetFillColor (MY_DEEP_ROMANTIC_BLUE);  // А.И. Куинджи, "Лунная ночь на Днепре"
//!          txSetColor     (MY_SHINING_MOONLIGHT);   // http://tanais.info/art/pic/kuindzhi1.html
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

const COLORREF
#ifdef FOR_DOXYGEN_ONLY
    enum txColors {
#endif

    TX_BLACK         = RGB (  0,   0,   0),   //!< Черный цвет.
    TX_BLUE          = RGB (  0,   0, 128),   //!< Темно-синий цвет. <i>Плохо виден.</i>
    TX_GREEN         = RGB (  0, 128,   0),   //!< Зеленый цвет.
    TX_CYAN          = RGB (  0, 128, 128),   //!< Бирюзовый цвет.
    TX_RED           = RGB (128,   0,   0),   //!< Темно-красный цвет. <i>Слишком темный.</i>
    TX_MAGENTA       = RGB (128,   0, 128),   //!< Темно-малиновый цвет.
    TX_BROWN         = RGB (128, 128,   0),   //!< Коричневый цвет. <i>Некрасивый. Do it yourself with RGB().</i>
    TX_ORANGE        = RGB (255, 128,   0),   //!< Оранжевый цвет.
    TX_GRAY          = RGB (160, 160, 160),   //!< Серый цвет.
    TX_DARKGRAY      = RGB (128, 128, 128),   //!< Темно-серый цвет.
    TX_LIGHTGRAY     = RGB (192, 192, 192),   //!< Светло-серый цвет.
    TX_LIGHTBLUE     = RGB (  0,   0, 255),   //!< Светло-синий цвет.
    TX_LIGHTGREEN    = RGB (  0, 255, 128),   //!< Светло-зеленый цвет.
    TX_LIGHTCYAN     = RGB (  0, 255, 255),   //!< Светло-бирюзовый цвет.
    TX_LIGHTRED      = RGB (255,   0, 128),   //!< Светло-красный цвет.   <i>Не самого лучшего оттенка.</i>
    TX_LIGHTMAGENTA  = RGB (255,   0, 255),   //!< Светло-малиновый цвет. <i>Еще менее лучшего оттенка.</i>
    TX_PINK          = RGB (255, 128, 255),   //!< Розовый гламурный :)
    TX_YELLOW        = RGB (255, 255, 128),   //!< Желтый цвет.
    TX_WHITE         = RGB (255, 255, 255),   //!< Белый цвет.
    TX_TRANSPARENT   = 0xFFFFFFFF,            //!< Прозрачный цвет. <i>Отключает рисование.</i>
    TX_NULL          = TX_TRANSPARENT,        //!< Прозрачный цвет. <i>Отключает рисование.</i>

//  Цветовые каналы (компоненты) - см. txExtractColor(), txRGB2HSL(), txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< Цветовой тон цвета в модели HSL
    TX_SATURATION   = 0x05000000,             //!< Насыщенность цвета в модели HSL
    TX_LIGHTNESS    = 0x06000000;             //!< Светлота цвета в модели HSL

#ifdef FOR_DOXYGEN_ONLY
    };
#endif

//! @cond INTERNAL
#define TX_DARKGREY   TX_DARKGRAY
#define TX_LIGHTGREY  TX_LIGHTGRAY
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает (смешивает) цвет из трех базовых цветов (компонент).
//!
//! @param   red    Количество красного цвета в интервале [0; 255]
//! @param   green  Количество зеленого цвета в интервале [0; 255]
//! @param   blue   Количество синего   цвета в интервале [0; 255]
//!
//! @return  Созданный цвет в формате COLORREF.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txExtractColor(),
//!          txRGB2HSL(), txHSL2RGB()
//!
//! @usage @code
//!          txSetColor (RGB (255, 128, 0));                // Красный + половина зеленого = оранжевый
//!
//!          int red = 20, green = 200, blue = 20;
//!          COLORREF color = RGB (red, green, blue);
//!          txSetFillColor (color);
//!
//!          const COLORREF SKY_COLOR = RGB (0, 128, 255);  // Создаем константу для нового цвета
//!
//!          ...
//!          txSetFillColor (SKY_COLOR);                    // Используем ее
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
COLORREF RGB (int red, int green, int blue);
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет и толщину линий, цвет текста.
//!
//! @param   color      Цвет линий и текста, см. txColors, RGB()
//! @param   thickness  Толщина линий
//! @param   dc         Дескриптор контекста рисования (холста) для установки цвета
//!
//! @return  Перо, созданное при установке цвета. При ошибке возвращается NULL.
//!
//! @see     txColor(), txGetColor(), txFillColor(), txGetFillColor(), txColors, RGB()
//!
//! @usage @code
//!          txSetColor (TX_RED);
//!          txSetColor (RGB (255, 128, 0), 5);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HPEN txSetColor (COLORREF color, double thickness = 1, HDC dc = txDC (true));

//! @cond INTERNAL
#define txSetColour txSetColor
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет линий и текста.
//!
//! @param   red        Количество красного цвета в интервале [0; 1]
//! @param   green      Количество зеленого цвета в интервале [0; 1]
//! @param   blue       Количество синего   цвета в интервале [0; 1]
//!
//! @return  Цвет RGB, соответствующий указанной комбинации основных цветов. При ошибке возвращается CLR_INVALID.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor()
//!
//! @usage @code
//!          txColor (1.0, 1.0, 0.0);   // Красный + зеленый = желтый
//!          txColor (1.0, 0.5, 0.25);  // Нечто оранжевое
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txColor (double red, double green, double blue);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет линий и текста.
//!
//! @param   dc  Дескриптор контекста рисования (холста) для возврата цвета
//!
//! @return  Текущий цвет линий и текста, см. txColors, RGB()
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!
//! @usage @code
//!          COLORREF color = txGetColor();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txGetColor (HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет заполнения фигур.
//!
//! @param   color  Цвет заполнения, см. txColors, RGB()
//! @param   dc     Дескриптор контекста рисования (холста) для установки цвета
//!
//! @return  Кисть, созданная при установке цвета. При ошибке возвращается NULL.
//!
//! @see     txFillColor(), txGetFillColor(), txColor(), txGetColor(), txColors, RGB()
//!
//! @usage @code
//!          txSetFillColor (TX_RED);
//!          txSetFillColor (RGB (255, 128, 0));
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HBRUSH txSetFillColor (COLORREF color, HDC dc = txDC (true));

//! @cond INTERNAL
#define txSetFillColour txSetFillColor
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущий цвет заполнения фигур.
//!
//! @param   red    Количество красного цвета в интервале [0; 1]
//! @param   green  Количество зеленого цвета в интервале [0; 1]
//! @param   blue   Количество синего   цвета в интервале [0; 1]
//!
//! @return  Цвет RGB, соответствующий указанной комбинации основных цветов. При ошибке возвращается CLR_INVALID.
//!
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor()
//!
//! @usage @code
//!          txFillColor (1.0, 0.5, 0.25);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txFillColor (double red, double green, double blue);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет заполнения фигур.
//!
//! @param   dc  Дескриптор контекста рисования (холста) для возврата цвета
//!
//! @return  Текущий цвет заполнения фигур, см. txColors, RGB()
//!
//! @see     txSetFillColor(), txGetFillColor(), txSetColor(), txGetColor(), txColors, RGB()
//!
//! @usage @code
//!          COLORREF color = txGetFillColor();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txGetFillColor (HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает режим взаимодействия цветов при рисовании.
//!
//!          При рисовании графическая библиотека может не просто красить пиксели на экране, а смешивать цвета
//!          экрана и текущие цвета линий и заполнения.
//!
//! @param   mode  Режим смешивания цветов
//! @param   dc    Дескриптор контекста рисования (холста) для установки режима
//!
//! @return  Предыдущий режим взаимодействия цветов, см. txColors, RGB()
//!
//! @title   Режимы взаимодействия цветов:
//! @table   @tr R2_COPYPEN     @td Пиксели = цвета кисти (самый нормальный режим :)
//!          @tr R2_NOTCOPYPEN  @td Пиксели = ~кисть
//!          @tbr
//!          @tr R2_BLACK       @td Пиксели = черный цвет (цвет кисти игнорируется)
//!          @tr R2_WHITE       @td Пиксели = белый  цвет (цвет кисти игнорируется)
//!          @tr R2_NOT         @td Пиксели = ~пиксели    (цвет кисти игнорируется)
//!          @tbr
//!          @tr R2_XORPEN      @td Пиксели =    пиксели ^  кисть (удобный режим, cм. пример ниже)
//!          @tr R2_NOTXORPEN   @td Пиксели = ~ (пиксели ^  кисть)
//!          @tbr
//!          @tr R2_MASKPEN     @td Пиксели =    пиксели &  кисть
//!          @tr R2_NOTMASKPEN  @td Пиксели = ~ (пиксели &  кисть)
//!          @tr R2_MASKNOTPEN  @td Пиксели =    пиксели & ~кисть
//!          @tr R2_MASKPENNOT  @td Пиксели =   ~пиксели &  кисть
//!          @tbr
//!          @tr R2_MERGEPEN    @td Пиксели =    пиксели |  кисть
//!          @tr R2_NOTMERGEPEN @td Пиксели = ~ (пиксели |  кисть)
//!          @tr R2_MERGENOTPEN @td Пиксели =    пиксели | ~кисть
//!          @tr R2_MERGEPENNOT @td Пиксели =   ~пиксели |  кисть
//!          @tbr
//!          @tr R2_NOP         @td Пиксели вообще не изменяются.
//! @endtable
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txSetColor (TX_WHITE, 5);       // При рисовании белым цветом в режиме
//!          txSetROP2 (R2_XORPEN);          //   R2_XORPEN цвета на экране инвертируются
//!
//!          txLine (100, 100, 200, 200);    // Рисуем первый раз - линия появляется
//!          txSleep (1000);
//!          txLine (100, 100, 200, 200);    // Рисуем второй раз - линия исчезает (немного уличной магии)
//!
//!          txSetROP2 (R2_COPYPEN);         // Восстанавливаем нормальный режим
//!          txLine (100, 100, 200, 200);    // Рисуем первый раз - линия появляется
//!
//!          txLine (100, 100, 200, 200);    // Рисуем первый раз - линия остается, кто бы мог подумать
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txSetROP2 (int mode = R2_COPYPEN, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Извлекает цветовую компоненту (цветовой канал) из смешанного цвета.
//!
//! @param   color      Смешанный цвет
//! @param   component  Извлекаемая компонента, см. txColors
//!
//! @return  Цветовая компонента, см. txColors
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txExtractColor(),
//!          txRGB2HSL(), txHSL2RGB()
//!
//! @usage @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          Другие примеры см. в функциях AppearText(), AppearEarth() Примера 5 ("Циклы").
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned txExtractColor (COLORREF color, COLORREF component);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Преобразует цвет из формата RGB в формат HSL.
//!
//! @param   rgbColor  Преобразуемый цвет в формате @strike ЕГЭ @endstrike RGB
//!
//! @return  Созданный цвет в виде COLORREF.
//!
//!          Формат @b RGB определяется как
//!
//!          - Красная компонента цвета (Red),   от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя   компонента цвета (Blue),  от 0 до 255.
//!
//!          Формат @b HSL определяется как
//!
//!          - Цветовой тон (Hue),        от 0 до 255 <b>(не до 360).</b>
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота     (Lightness),  от 0 до 255.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txExtractColor(),
//!          txRGB2HSL(), txHSL2RGB()
//!
//! @usage @code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Преобразует цвет из формата HSL в формат RGB.
//!
//! @param   hslColor  Преобразуемый цвет в формате HSL
//!
//! @return  Созданный цвет в виде COLORREF.
//!
//!          Формат @b RGB определяется как
//!
//!          - Красная компонента цвета (Red),   от 0 до 255.
//!          - Зеленая компонента цвета (Green), от 0 до 255.
//!          - Синяя   компонента цвета (Blue),  от 0 до 255.
//!
//!          Формат @b HSL определяется как
//!
//!          - Цветовой тон (Hue),        от 0 до 255 <b>(не до 360).</b>
//!          - Насыщенность (Saturation), от 0 до 255.
//!          - Светлота     (Lightness),  от 0 до 255.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txExtractColor(),
//!          txRGB2HSL(), txHSL2RGB()
//!
//! @usage @code
//!          int hue = 10, saturation = 128, lightness = 128;
//!          COLORREF hslColor = RGB (hue, saturation, lightness);
//!          txSetColor (txHSL2RGB (hslColor));
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor);

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Drawing
//! @name    Рисование фигур
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Стирает холст текущим цветом заполнения.
//!
//! @param   dc  Дескриптор контекста рисования (холста) для стирания
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txSetFillColor(), txFillColor(), txGetFillColor(), txColors, RGB()
//!
//! @usage @code
//!          txSetFillColor (TX_BLUE);  // Кто-то хотел синий фон?
//!          txClear();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txClear (HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует пиксель (точку на экране).
//!
//! @param   x      X-координата точки
//! @param   y      Y-координата точки
//! @param   color  Цвет точки, см. txColors, RGB()
//! @param   dc     Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txPixel(), txGetPixel(), txColors, RGB()
//!
//! @usage @code
//!          txSetPixel (100, 100, TX_LIGHTRED);  // Красная точка! http://www.google.ru/search?q=коты+и+красная+точка
//!
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline bool txSetPixel (double x, double y, COLORREF color, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует пиксель (точку на экране).
//!
//! @param   x      X-координата точки
//! @param   y      Y-координата точки
//! @param   red    Количество красного цвета в интервале [0; 1]
//! @param   green  Количество зеленого цвета в интервале [0; 1]
//! @param   blue   Количество синего   цвета в интервале [0; 1]
//! @param   dc     Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txSetPixel(), txGetPixel()
//!
//! @usage @code
//!          txSetPixel (100, 100, 1.0, 0.5, 0.25);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline bool txPixel (double x, double y, double red, double green, double blue, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущий цвет точки (пикселя) на экране.
//!
//! @param   x  X-координата точки
//! @param   y  Y-координата точки
//! @param   dc Дескриптор контекста рисования (холста) для возврата цвета
//!
//! @return  Текущий цвет пикселя, см. txColors, RGB()
//!
//! @see     txSetPixel(), txPixel(), txColors, RGB()
//!
//! @usage @code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED)
//!              CarCrash (x, y);     // Mess with the red - die like the rest
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline COLORREF txGetPixel (double x, double y, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует линию.
//!
//! @param   x0  X-координата начальной точки
//! @param   y0  Y-координата начальной точки
//! @param   x1  X-координата конечной  точки
//! @param   y1  Y-координата конечной  точки
//! @param   dc  Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линии задается функцией txSetColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txLine (100, 200, 400, 500);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txLine (double x0, double y0, double x1, double y1, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует прямоугольник.
//!
//! @param   x0  X-координата верхнего левого  угла
//! @param   y0  Y-координата верхнего левого  угла
//! @param   x1  X-координата нижнего  правого угла
//! @param   y1  Y-координата нижнего  правого угла
//! @param   dc  Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txRectangle (100, 200, 400, 500);
//!
//!          Win32::RoundRect (txDC(), 100, 200, 400, 500, 30, 30);  // И такое есть. Погуглите "RoundRect function".
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txRectangle (double x0, double y0, double x1, double y1, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует ломаную линию или многоугольник.
//!
//! @param   points     Массив структур POINT с координатами точек
//! @param   numPoints  Количество точек в массиве
//! @param   dc         Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          POINT star[5] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}};
//!          txPolygon (star, 5);  // Я кривая звездочка
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует эллипс.
//!
//! @param   x0  X-координата верхнего левого угла прямоугольника, описанного вокруг эллипса
//! @param   y0  Y-координата верхнего левого угла описанного прямоугольника
//! @param   x1  X-координата нижнего правого угла описанного прямоугольника
//! @param   y1  Y-координата нижнего правого угла описанного прямоугольника
//! @param   dc  Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txEllipse (100, 100, 300, 200);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txEllipse (double x0, double y0, double x1, double y1, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует окружность или круг.
//!
//! @param   x  X-координата центра
//! @param   y  Y-координата центра
//! @param   r  Радиус
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txCircle (100, 100, 10);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txCircle (double x, double y, double r);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует дугу эллипса.
//!
//! @param   x0          X-координата верхнего левого угла прямоугольника, описанного вокруг эллипса, содержащего дугу (см. txEllipse)
//! @param   y0          Y-координата верхнего левого угла прямоугольника
//! @param   x1          X-координата нижнего правого угла прямоугольника
//! @param   y1          Y-координата нижнего правого угла прямоугольника
//! @param   startAngle  Угол между направлением оси OX и началом дуги (в градусах)
//! @param   totalAngle  Величина дуги (в градусах)
//! @param   dc          Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txArc (100, 100, 300, 200, 45, 270);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует сектор эллипса.
//!
//! @param   x0          X-координата верхнего левого угла прямоугольника, описанного вокруг эллипса, содержащего дугу (см. txEllipse)
//! @param   y0          Y-координата верхнего левого угла прямоугольника
//! @param   x1          X-координата нижнего правого угла прямоугольника
//! @param   y1          Y-координата нижнего правого угла прямоугольника
//! @param   startAngle  Угол между направлением оси OX и началом сектора (в градусах)
//! @param   totalAngle  Величина сектора (в градусах)
//! @param   dc          Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txPie (100, 100, 300, 200, 0, 180);  // Enter Pacman
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует хорду эллипса.
//!
//! @param   x0          X-координата верхнего левого угла прямоугольника, описанного вокруг эллипса, содержащего дугу (см. txEllipse)
//! @param   y0          Y-координата верхнего левого угла прямоугольника
//! @param   x1          X-координата нижнего правого угла прямоугольника
//! @param   y1          Y-координата нижнего правого угла прямоугольника
//! @param   startAngle  Угол между направлением оси OX и началом хорды (в градусах)
//! @param   totalAngle  Величина хорды (в градусах)
//! @param   dc          Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет и толщина линий задается функцией txSetColor(), цвет заполнения - txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txChord (100, 100, 300, 200, 45, 270);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Заливает произвольный контур текущим цветом заполнения.
//!
//! @param   x      X-координата точки начала заливки
//! @param   y      Y-координата точки начала заливки
//! @param   color  Цвет заливаемой области (TX_TRANSPARENT - автоопределение)
//! @param   mode   Режим заливки (FLOODFILLSURFACE - заливка однородного фона)
//! @param   dc     Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет заполнения задается функцией txSetFillColor(). Не рекомендуется для применения, так как работает
//!          довольно медленно. Лучше Используйте txPolygon().
//!
//! @title   Режимы заливки: @table
//!          @tr FLOODFILLSURFACE @td - Заливать область,    указанную цветом color.
//!          @tr FLOODFILLBORDER  @td - Заливать до границы, указанной цветом color.
//!          @endtable
//!
//! @see     txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txSetFillColor (TX_PINK);
//!          txLine (100, 200, 150, 100);
//!          txLine (150, 100, 200, 200);
//!          txLine (200, 200, 100, 200);
//!          txFloodFill (150, 150);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txFloodFill (double x, double y, COLORREF color = TX_TRANSPARENT, DWORD mode = FLOODFILLSURFACE, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Функция, которая должна бы рисовать треугольник.
//!
//! @param   x1     X-координата 1 точки
//! @param   y1     Y-координата 1 точки
//! @param   x2     X-координата 2 точки
//! @param   y2     Y-координата 2 точки
//! @param   x3     X-координата 3 точки
//! @param   y3     Y-координата 3 точки
//!
//! @return  Если операция была бы успешна - true, иначе - false.
//!
//! @see     txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @par См. также:
//!          @ref Tutor_Params "Пример с функциями с параметрами"
//}----------------------------------------------------------------------------------------------------------------

bool txTriangle (double x1, double y1, double x2, double y2, double x3, double y3);
bool txTriangle (double x1, double y1, double x2, double y2, double x3, double y3)
    {
    (void)x1; (void)y1; (void)x2; (void)y2; (void)x3; (void)y3;

    MessageBox (txWindow(),
               "Эта функция не реализована в библиотеке, потому что вы легко можете реализовать ее сами\n"
               "как функцию с параметрами, используя txPolygon(). См. \"Пример с функциями с параметрами\".",
               "TXLib сообщает", MB_ICONINFORMATION);

    return false;
    }

//{----------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#define txRectandle  Sleep (1000), txRectangle  // Copy-protection for the function below
#define txCircle     ;txCircle                  //
#define txSetColor   ;txSetColor                //
#define C0L0RREF     COLORREF                   //
#define OxFFFFFF     0xFFFFFF                   //
#define lO           10                         //
#define lOOO         1000                       //
#define O                                       //

bool txNotifyIcon (unsigned flags, const char title[], const char format[], ...) _TX_CHECK_FORMAT (3);

//! @endcond
//}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует человечка.
//!
//! Это пример функции, которую Вы могли бы написать и сами.
//!
//! @param   x      X-координата человечка
//! @param   y      Y-координата человечка
//! @param   sizeX  Ширина человечка
//! @param   sizeY  Высота человечка (также определяет размер головы)
//! @param   color  Цвет человечка
//! @param   handL  Высота подъема левой  руки (относительно высоты человечка)
//! @param   handR  Высота подъема правой руки (относительно высоты человечка)
//! @param   twist  Смещение @a спины          (относительно ширины человечка)
//! @param   head   Высота @a подъема головы   (относительно высоты человечка)
//! @param   eyes   Величина глаз              (относительно размера головы)
//! @param   wink   Моргание глаз (0 - оба открыты, -1 - закрыт левый, +1 - закрыт правый)
//! @param   crazy  Смещение глаз по вертикали (относительно размера головы)
//! @param   smile  Улыбка                     (относительно размера головы)
//! @param   hair   Длина волос                (относительно размера головы)
//! @param   wind   Ветер, развевающий волосы  (относительно размера головы)
//!
//! @see     txSetFillColor(), txColors, RGB(), txLine(), txCircle()
//!
//! @usage @code
//!          txCreateWindow (800, 600);
//!
//!        //-----------+---+----+-----+-----+----------+-----+-----+-----+----+----+----+-----+-----+----+-----
//!        //           | x |  y |sizeX|sizeY| color    |handL|handR|twist|head|eyes|wink|crazy|smile|hair|wind
//!        //-----------+---+----+-----+-----+----------+-----+-----+-----+----+----+----+-----+-----+----+-----
//!        //           |   |    |     |     |          |     |     |     |    |    |    |     |     |    |
//!           txDrawMan (125, 250, 200,  200, TX_WHITE,    0,    0,    0,   0,   0.8,  0,   0,   1.0,   0,  0);
//!           txDrawMan (325, 250, 100,  200, TX_YELLOW,   0,    0,    0,   0,   0.8,  0,   0,  -1.0,   2,  0);
//!           txDrawMan (525, 250, 200,  100, TX_ORANGE,   0,    0,    0,   0,   1.0,  0,  -1,   0.3,   1,  0);
//!           txDrawMan (725, 250, 100,  100, TX_LIGHTRED, 0,    0,    0,   0,   1.0,  0,   1,  -0.3,   3,  0);
//!
//!           txDrawMan (125, 550, 200,  200, TX_WHITE,    0.3,  0.3,  0,   0,   0.8, -1,   1,   0.5,   2, -1);
//!           txDrawMan (325, 550, 100,  200, TX_YELLOW,  -0.5, -0.5,  0,   0.1, 0.8,  1,   0,  -0.5,   3,  5);
//!           txDrawMan (525, 550, 200,  100, TX_ORANGE,  -0.5,  0.3,  0.2, 0,   0.8, -1,   1,   0.0,  10, -5);
//!           txDrawMan (725, 550, 100,  100, TX_LIGHTRED, 0.3, -0.5, -0.4, 0,   0.8,  1,  -1,   0.0,   1,  1);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

void txDrawMan (int x, int y, int sizeX, int sizeY, COLORREF color, double handL, double handR, double twist,
                double head, double eyes, double wink, double crazy, double smile, double hair, double wind);

void txDrawMan (int x, int y, int sizeX, int sizeY, COLORREF color, double handL, double handR, double twist,
                double head, double eyes, double wink, double crazy, double smile, double hair, double wind)
    {
    const char msg[] = "\0/А я - человечек из библиотеки!\0/Меня объясняли на уроке!\0/Напиши меня сам!\0/";

    static unsigned count = GetTickCount(), L = 0;

    C0L0RREF lineColor = txGetColor();
    C0L0RREF fillColor = txGetFillColor();

    txSetColor     (color);
    txSetFillColor (color);

    txLine (x + twist * sizeX, y - O.35 * sizeY, x, y - O.7 * sizeY);

    txLine (x, y - O.7 * sizeY, x - sizeX/2, y - (O.7 + handL) * sizeY);
    txLine (x, y - O.7 * sizeY, x + sizeX/2, y - (O.7 + handR) * sizeY);

    txLine (x + twist * sizeX, y - O.35 * sizeY, x - sizeX/2, y);
    txLine (x + twist * sizeX, y - O.35 * sizeY, x + sizeX/2, y);

    txCircle (x, y - (O.85 + head) * sizeY, O.15 * sizeY);

    txLine (x, y - (1 + head) * sizeY, x +  wind/lO        * sizeX, y - (1 + head + hair/lO) * sizeY);
    txLine (x, y - (1 + head) * sizeY, x + (wind/lO - O.1) * sizeX, y - (1 + head + hair/lO) * sizeY);
    txLine (x, y - (1 + head) * sizeY, x + (wind/lO + O.1) * sizeX, y - (1 + head + hair/lO) * sizeY);

    txSetColor     (~color & OxFFFFFF);  // Inverse the color
    txSetFillColor (~color & OxFFFFFF);

    txLine (x, y - (O.8 + head - O.05 * smile/2) * sizeY, x - O.05 * sizeY, y - (O.8 + head + O.05 * smile/2) * sizeY),
    txLine (x, y - (O.8 + head - O.05 * smile/2) * sizeY, x + O.05 * sizeY, y - (O.8 + head + O.05 * smile/2) * sizeY),
    txNotifyIcon (4, (const char*)!! (L+'L')[msg], "\n%s\n", msg + (count++ % 3)["\"<"]);

    txCircle (x - O.05 * sizeY, y - (O.9 + head - O.02 * crazy) * sizeY, eyes * (1 + O.5*wink) * O.02 * sizeY);
    txCircle (x + O.05 * sizeY, y - (O.9 + head + O.02 * crazy) * sizeY, eyes * (1 - O.5*wink) * O.02 * sizeY),
    Sleep (lOOO + count%2);

    txSetColor     (TX_DARKGRAY);
    txSetFillColor (TX_TRANSPARENT);

    txCircle (x, y, 4);
    txRectandle (x - sizeX/2, y - sizeY, x + sizeX/2, y);

    txSetColor     (lineColor);
    txSetFillColor (fillColor);
    }

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Drawing text
//! @name    Работа с текстом
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует текст.
//!
//! @param   x     X-координата начальной точки текста
//! @param   y     Y-координата начальной точки текста
//! @param   text  Текстовая строка
//! @param   dc    Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет текста задается функцией txSetColor(), выравнивание - txSetTextAlign().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txSelectFont(), txSetTextAign(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txTextOut (100, 100, "Здесь могла бы быть Ваша реклама.");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txTextOut (double x, double y, const char text[], HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#undef txCircle
#undef txSetColor
#undef C0L0RREF
#undef OxFFFFFF
#undef lO
#undef lOOO
#undef O

//! @endcond
//}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Рисует текст, размещенный в прямоугольной области.
//!
//! @param   x0      X-координата верхнего левого  угла области
//! @param   y0      Y-координата верхнего левого  угла области
//! @param   x1      X-координата нижнего  правого угла области
//! @param   y1      Y-координата нижнего  правого угла области
//! @param   text    Текстовая строка
//! @param   format  Флаги форматирования текста
//! @param   dc      Дескриптор контекста рисования (холста) для рисования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          Цвет текста задается функцией txSetColor(), выравнивание - txSetTextAlign().
//!
//! @note    Не выводит ничего, если координаты идут в неверном порядке (если x0 > x1 или y0 > y1).
//!
//!          Флаги форматирования текста см. в MSDN (http://msdn.com), искать "DrawText Function (Windows)":
//!          http://msdn.microsoft.com/en-us/library/dd162498%28VS.85%29.aspx.
//!
//!          <b>Автоматический перенос</b> текста на несколько строк включается, если текст состоит из нескольких
//!          строк (есть хотя бы один символ новой строки @b @c \\n).
//!
//!          Если надо отформатировать текст не по центру, а по левому или правому краю, то не забудьте указать
//!          остальные флаги форматирования, если они нужны: @c DT_VCENTER (вертикальное центрирование) @c |
//!          @c DT_WORDBREAK (перенос по словам) @c | @c DT_WORD_ELLIPSIS (ставить многоточие в конце, если текст
//!          не умещается). См. значение флагов по умолчанию.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txSetColor     (TX_BLACK);
//!          txSetFillColor (TX_DARKGRAY); Win32::RoundRect (txDC(), 105, 105, 205, 255, 30, 30);
//!          txSetFillColor (TX_WHITE);    Win32::RoundRect (txDC(), 100, 100, 200, 250, 30, 30);
//!
//!          txSelectFont ("Arial", 20, 0, FW_BOLD);
//!          txDrawText  (100, 100, 200, 250, "I hate it when I'm studying "
//!                                           "and a Velociraptor throws bananas on me.\n");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txDrawText (double x0, double y0, double x1, double y1, const char text[],
                 unsigned format = DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_WORD_ELLIPSIS, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Выбирает текущий шрифт.
//!
//! @param   name       Название шрифта
//! @param   sizeY      Высота букв (размер по Y)
//! @param   sizeX      Ширина букв
//! @param   bold       Жирность шрифта (от 0 до 1000)
//! @param   italic     Курсив
//! @param   underline  Подчеркивание
//! @param   strikeout  Перечеркивание
//! @param   angle      Угол поворота текста (в градусах)
//! @param   dc         Дескриптор контекста рисования (холста) для выбора шрифта
//!
//! @return  Выбранный шрифт. Если он не был найден, то устанавливается системный шрифт Windows
//!          @c (SYSTEM_FIXED_FONT, см. MSDN). Существование шрифта можно проверить функцией txFontExist().
//!
//! @see     txTextOut(), txDrawText(), txFontExist()
//!
//! @usage @code
//!          txSelectFont ("Comic Sans MS", 40);
//!          txTextOut (100, 100, "И здесь могла бы быть Ваша реклама.");
//!          txSelectFont ("Comic Sans MS", 40, 10, false, true, false, true, 15);
//!          txTextOut (100, 200, "Но ее почему-то нет.");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HFONT txSelectFont (const char name[], double sizeY, double sizeX = -1,
                    int bold = FW_DONTCARE, bool italic = false, bool underline = false,
                    bool strikeout = false, double angle = 0,
                    HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Вычисляет размеры текстовой надписи.
//!
//! @param   text  Текстовая строка
//! @param   dc    Дескриптор контекста рисования (холста), где планируется разместить надпись
//!
//! @return  Размеры надписи в структуре SIZE.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          SIZE size = txGetTextExtent (text);
//!          txTextOut (100 + size.cx / 2, 200 + size.cy / 2, text);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[], HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Вычисляет ширину текстовой надписи.
//!
//! @param   text  Текстовая строка
//! @param   dc    Дескриптор контекста рисования (холста), где планируется разместить надпись
//!
//! @return  Ширина надписи.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[], HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Вычисляет высоту текстовой надписи.
//!
//! @param   text  Текстовая строка
//! @param   dc    Дескриптор контекста рисования (холста), где планируется разместить надпись
//!
//! @return  Высота надписи.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[], HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает текущее выравнивание текста.
//!
//! @param   align  Флаги выравнивания
//! @param   dc     Дескриптор контекста рисования (холста), где планируется разместить надпись
//!
//! @return  Предыдущее состояние выравнивания текста.
//!
//! @title   Флаги выравнивания: @table
//!          @tr TA_BASELINE @td Точка (X,Y) определяет базовую линию текста.
//!          @tr TA_BOTTOM   @td Точка (X,Y) определяет нижнюю сторону описанного прямоугольника  (текст лежит выше этой точки).
//!          @tr TA_TOP      @td Точка (X,Y) определяет верхнюю сторону описанного прямоугольника (текст лежит ниже этой точки).
//!          @tbr
//!          @tr TA_CENTER   @td Текст будет выровнен по горизонтали относительно точки (X,Y).
//!          @tr TA_LEFT     @td Точка (X,Y) определяет левую сторону описанного прямоугольника  (текст лежит правее этой точки).
//!          @tr TA_RIGHT    @td Точка (X,Y) определяет правую сторону описанного прямоугольника (текст лежит левее этой точки).
//!          @endtable
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txSetTextAlign (TA_RIGHT);
//!          txTextOut (700, 100, "Чтобы доступ был легок и быстр,");
//!          txTextOut (700, 150, "Переменную клади в регистр.");
//!          txSetTextAlign();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Ищет шрифт по его названию.
//!
//! @param   name  Название шрифта
//!
//! @return  Информация о шрифте в структуре LOGFONT. Если шрифт не найден, возвращает NULL.
//!
//! @see     txTextOut(), txSelectFont()
//!
//! @usage @code
//!          if (txFontExist ("Comic Sans MS")) txSelectFont ("Comic Sans MS",   30);
//!          else                               txSelectFont ("Times New Roman", 30);
//!
//!          txTextOut (100, 100, "Комик ли Санс?");  // google.ru/search?q=philosoraptor
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[]);

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Drawing to memory DC and image loading
//! @name    Рисование в памяти (на "виртуальном холсте") и загрузка изображений
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает дополнительный холст (контекст рисования, Device Context, DC) в памяти.
//!
//! @param   sizeX   Ширина холста
//! @param   sizeY   Высота холста
//! @param   bitmap  Bitmap to be associated with DC
//!
//! @return  Дескриптор (системный номер, выданный Windows) созданного холста (контекста рисования).
//!
//! @warning Созданный контекст затем будет нужно @b обязательно удалить при помощи txDeleteDC(). @n
//!          <small>When the program will be shutting down, TXLib will try to delete DCs which were not deleted,
//!          but this is not guaranteed.</small>
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection()
//!
//! @usage @code
//!          HDC save = txCreateCompatibleDC (100, 100);
//!
//!          txBitBlt (save, 0, 0, 100, 100, txDC(), 0, 0);  // Сохраняем фон
//!
//!          txTextOut (20, 20, "Boo!");
//!          txSleep (2000);
//!
//!          txBitBlt (txDC(), 0, 0, 100, 100, save, 0, 0);  // Текст исчезает
//!
//!          txDeleteDC (save);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap = NULL);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Создает аппаратно-независимый дополнительный холст (контекст рисования, Device Context, DC) в памяти
//!          с возможностью прямого доступа к нему как к массиву.
//!
//! @param   sizeX   Ширина холста
//! @param   sizeY   Высота холста
//! @param   pixels  Указатель на переменную, которая будет использоваться для доступа к пикселям изображения.
//!                  Эта переменная, в свою очередь @d указатель на массив структур RGBQUAD, каждая из которых
//!                  описывает цвет одного пикселя.
//!
//! @return  Дескриптор созданного аппаратно-независимого холста (контекста рисования).
//!
//!          Аппаратно-независимые холсты, создаваемые этой функцией, позволяют напрямую и быстро изменять цвета
//!          пикселей изображения, а также его прозрачность в каждой точке. См. пример использования ниже.
//!
//!          Для прямого доступа к пикселям холста, как к массиву, надо объявить указатель на массив структур
//!          RGBQUAD и передать адрес этого указателя в качестве третьего параметра функции txCreateDIBSection().
//!          Она изменит значение этого указателя так, что он станет указывать на массив цветов пикселей холста.
//!          Память под массив RGBQUAD выделять и освобождать @b не надо, этим занимается сама txCreateDIBSection().
//!
//!          Массив @p pixels @d одномерный, но по сути он описывает двумерное изображение. Поэтому с ним надо
//!          работать как с двумерным прямоугольным массивом, физически расположенным в одномерном массиве:
//!          вручную вычислять смещение от начала массива до нужного пикселя и после этого адресоваться к массиву.
//!          (Так обычно делают, размещая двумерные массивы в динамической памяти.) См. пример использования ниже.
//!
//! @note    Аппаратно-независимые холсты @d это контексты устройств, связанные с аппаратно-независимыми растрами
//!          (Device Independent Bitmaps, DIB) Windows.
//!
//! @warning Созданный контекст затем будет нужно @b обязательно удалить при помощи txDeleteDC(). @n
//!          <small>When the program will be shutting down, TXLib will try to delete DCs which were not deleted,
//!          but this is not guaranteed.</small>
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txSaveImage(), txGetExtent(),
//!          txCreateCompatibleDC()
//!
//! @usage @code
//!          int main()
//!              {
//!              txCreateWindow (800, 600);
//!
//!              POINT size = txGetExtent();
//!
//!              txSetFillColor (TX_BLACK);
//!              txTextCursor (false);
//!              txBegin();
//!
//!              HDC src = GetDC (HWND_DESKTOP);                       // Get HDC from Windows Desktop
//!
//!              RGBQUAD* buf = NULL;
//!              HDC dc = txCreateDIBSection (size.x, size.y, &buf);
//!              assert (dc); assert (buf);
//!
//!              while (!GetAsyncKeyState (VK_ESCAPE))
//!                  {
//!                  txBitBlt (dc, 0, 0, size.x, size.y, src);
//!
//!                  for (int y = 0; y < size.y; y++)
//!                  for (int x = 0; x < size.x; x++)
//!                      {
//!                      RGBQUAD* c = &buf [x + y*size.x];             // Get color at (x, y) within image buffer
//!
//!                      c->rgbRed      = (BYTE) (255 - c->rgbRed);    // Negative colors
//!                      c->rgbGreen    = (BYTE) (255 - c->rgbGreen);
//!                      c->rgbBlue     = (BYTE) (255 - c->rgbBlue);
//!
//!                      double r       = hypot (x - size.x/2, y - size.y/2);
//!                      double alpha   = sin (0.05 * r) * 0.1 + 0.5;
//!
//!                      c->rgbReserved = (BYTE) ROUND (255 * alpha);  // Set alpha-channel (transparency)
//!                      }
//!
//!                  txUseAlpha (dc) asserted;                         // Premultiply colors with alpha
//!
//!                  txClear();
//!                  txAlphaBlend (txDC(), 0, 0, 0, 0, dc);
//!
//!                  printf ("FPS %.0lf\t\t\r", txGetFPS());
//!                  txSleep (0);
//!                  }
//!
//!              txSaveImage ("TxFilter.bmp", dc);
//!
//!              txDeleteDC (dc);
//!              ReleaseDC (HWND_DESKTOP, src);                        // Free Windows Desktop HDC
//!
//!              return 0;
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HDC txCreateDIBSection (double sizeX, double sizeY, RGBQUAD** pixels = NULL);

//! @cond INTERNAL
HDC txCreateDIBSection (double sizeX, double sizeY, COLORREF** pixels = NULL);
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Загружает из файла изображение в формате BMP. Делает это довольно медленно.
//!
//! @param   filename    Имя файла с изображением в формате BMP
//! @param   imageFlags  Тип загружаемого изображения, см. ниже
//! @param   loadFlags   Флаги загрузки изображения, см. ниже
//!
//! @return  Дескриптор созданного контекста рисования в памяти, с загруженным изображением.
//!          Если изображение не загружено (не найден файл, неверный формат файла и т.д.), то NULL.
//!
//! @warning Изображение загружается в автоматически создаваемый контекст рисования в памяти ("виртуальный холст"),
//!          который затем будет нужно <b>обязательно удалить</b> при помощи txDeleteDC(). @n
//!          <small>When the program will be shutting down, TXLib will try to delete DCs which were not deleted,
//!          but this is not guaranteed.</small>
//!
//! @note    Изображения поддерживаются <b>только в формате BMP.</b> Если взять файл другого формата, например JPG,
//!          и переименовать его со сменой расширения на BMP, то от этого формат не изменится. Такое изображение
//!          загружено не будет.
//!
//!          Если функция вернула NULL, то надо прежде всего <b>проверить наличие файла изображения</b> по
//!          указанному в программе пути и формат файла. Если путь к файлу не указан (или указан как неполный),
//!          то путь отсчитывается от текущей папки программы, которая может не совпадать текущей папкой среды
//!          программирования. Текущую папку программы можно посмотреть по команде About в системном меню
//!          (она указана там как "Run from").
//!
//!          Если изображение в файле содержит альфа-канал (информацию о прозрачности), то его цвета должны
//!          находиться в формате <b>Premultiplied Alpha</b>. См. замечания к функции txAlphaBlend().
//!
//!          Если изображение в файле с альфа-каналом @b не находится в формате <b>Premultiplied Alpha</b>, то после
//!          вызова txLoadImage() нужно вызвать функцию txUseAlpha(). Однако не надо этого делать, если цвета в файле
//!          @b уже находятся в формате Premultiplied Alpha, иначе картинка станет темнее. Также не надо вызывать
//!          txUseAlpha() несколько раз для одного и того же изображения.
//!
//! @note    <b>Не надо часто загружать</b> одно и то же изображение, особенно в цикле. От этого программа начинает
//!          тормозить! @n
//! @note    Загрузите один раз @a перед циклом, потом используйте много раз. Посмотрите, как это сделано в примере
//!          TX\Examples\Tennis\Tennis.cpp.
//!
//! @title   Типы загружаемых изображений:
//! @table   @tr IMAGE_BITMAP @td Рисунок в формате BMP
//!          @tr IMAGE_CURSOR @td Курсор в формате CUR или ANI
//!          @tr IMAGE_ICON   @td Иконка в формате ICO
//!          @endtable
//!
//! @title   Флаги загрузки:
//! @table   @tr LR_CREATEDIBSECTION @td Создает DIB (device-indepandent bitmap), удобную для прямого доступа к данным
//!          @tr LR_LOADFROMFILE     @td Загружает из файла (если этот флаг не указан, то загружает из ресурса EXE-файла)
//!          @tr Остальные флаги загрузки @td см. на MSDN.com, поиск "LoadImage function".
//!          @endtable
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(),
//!          txTransparentBlt(), txSaveImage(), txGetExtent()
//!
//! @usage   Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  background_FromTXLibHelp = txLoadImage ("Resources\\Images\\Background.bmp");
//!
//!          if (!background_FromTXLibHelp)
//!              txMessageBox ("Не могу загрузить фон из Background.bmp", "Да, я скопировал это из примера");
//!
//!          // Не надо часто загружать одно и то же изображение, особенно в цикле - программа будет тормозить!
//!          // Загрузите один раз перед циклом, потом используйте много раз.
//!          // Посмотрите, как сделано в примере TX\Examples\Tennis\Tennis.cpp.
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background_FromTXLibHelp, 0, 0);
//!
//!          ...
//!          txDeleteDC (background_FromTXLibHelp);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[], unsigned imageFlags = IMAGE_BITMAP, unsigned loadFlags = LR_LOADFROMFILE);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Уничтожает холст (контекст рисования, DC) в памяти.
//!
//! @param   dc     Контекст рисования для уничтожения. @n
//!                 Если передан указатель, то после уничтожения по указателю записывается NULL.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection()
//!
//! @usage   Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  background_FromTXLibHelp = txLoadImage ("Resources\\Images\\Background.bmp");
//!
//!          if (!background_FromTXLibHelp)
//!              txMessageBox ("Не могу загрузить фон из Background.bmp, и я скопировал это из примера.", "Oh, not now");
//!
//!          // См. важный комментарий в примере к функции txLoadImage!
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background_FromTXLibHelp, 0, 0);
//!
//!          ...
//!          txDeleteDC (background_FromTXLibHelp);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
//@ {

bool txDeleteDC (HDC  dc);

//! @cond INTERNAL
bool txDeleteDC (HDC* dc);
//! @endcond

//@ }
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой.
//!
//! @param   dest    Контекст назначения (куда копировать). Если NULL, то копирует в окно TXLib
//! @param   xDest   X-координата верхнего левого угла изображения-приемника
//! @param   yDest   Y-координата верхнего левого угла изображения-приемника
//! @param   width   Ширина копируемого изображения. Если <= 0, то автоматически берется из размера источника
//! @param   height  Высота копируемого изображения. Если <= 0, то автоматически берется из размера источника
//! @param   src     Контекст источника (откуда копировать)
//! @param   xSrc    X-координата верхнего левого угла изображения-источника
//! @param   ySrc    Y-координата верхнего левого угла изображения-источника
//! @param   rOp     Растровая операция копирования
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если контексты источника равен NULL, то он не существует и копирование вызовет ошибку.
//!          Наиболее частая причина - ошибка при загрузке файла изображения и отсутствие проверки на эту ошибку.
//!          Пример с проверкой на правильность загрузки см. ниже.
//!
//! @title   Режимы копирования:
//! @table   @tr SRCCOPY     @td Просто копирует :) - самый распространенный режим
//!          @tbr
//!          @tr BLACKNESS   @td Заполняет холст-приемник черным цветом (холст-источник игнорируется).
//!          @tr WHITENESS   @td Заполняет холст-приемник белым цветом  (холст-источник игнорируется).
//!          @tr DSTINVERT   @td Инвертирует цвета на холсте-приемнике  (холст-источник игнорируется).
//!          @tr PATCOPY     @td Копирует цвет текущей кисти холста-приемника.
//!          @tbr
//!          @tr MERGECOPY   @td Приемник =   приемник & цвет текущей кисти источника.
//!          @tr MERGEPAINT  @td Приемник = ~ приемник | источник
//!          @tr NOTSRCCOPY  @td Приемник = ~ источник
//!          @tr NOTSRCERASE @td Приемник = ~ (приемник | источник)
//!          @tr PATINVERT   @td Приемник =  кисть приемника ^  приемник
//!          @tr PATPAINT    @td Приемник = (кисть приемника | ~источник) | приемник
//!          @tr SRCAND      @td Приемник =  приемник & источник
//!          @tr SRCERASE    @td Приемник = ~приемник & источник
//!          @tr SRCINVERT   @td Приемник =  приемник ^ источник
//!          @tr SRCPAINT    @td Приемник =  приемник | источник
//!          @endtable
//!
//! @see     txAlphaBlend(), txTransparentBlt(), txSaveImage(), txGetExtent(), txSetColor(), txGetColor(),
//!          txSetFillColor(), txGetFillColor(), txColors, RGB(), txCreateDIBSection()
//!
//! @usage   Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  background_FromTXLibHelp = txLoadImage ("Resources\\Images\\Background.bmp");
//!
//!          if (!background_FromTXLibHelp)
//!              ("Не могу фон из загрузить Background.bmp, и да, я взял этот код из примера.", "Once again :(");
//!
//!          // См. важный комментарий в примере к функции txLoadImage!
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background_FromTXLibHelp);
//!
//!          ...
//!          txDeleteDC (background_FromTXLibHelp);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txBitBlt (HDC dest, double xDest, double yDest, double width, double height,
               HDC src,  double xSrc = 0, double ySrc = 0, DWORD rOp = SRCCOPY);

//! @cond INTERNAL
inline bool txBitBlt (HDC dest, double xDest, double yDest, HDC src, double xSrc = 0, double ySrc = 0);
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой с учетом прозрачности.
//!
//! @param   dest        Контекст назначения (куда копировать). Если NULL, то копирует в окно TXLib
//! @param   xDest       X-координата верхнего левого угла изображения-приемника
//! @param   yDest       Y-координата верхнего левого угла изображения-приемника
//! @param   width       Ширина копируемого изображения. Если <= 0, то автоматически берется из размера источника
//! @param   height      Высота копируемого изображения. Если <= 0, то автоматически берется из размера источника
//! @param   src         Контекст источника (откуда копировать)
//! @param   xSrc        X-координата верхнего левого угла изображения-источника, должна быть в пределах размера источника
//! @param   ySrc        Y-координата верхнего левого угла изображения-источника, должна быть в пределах размера источника
//! @param   transColor  Цвет, который будет считаться прозрачным
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если контекст источника равен NULL, то он не существует и копирование вызовет ошибку.
//!          Наиболее частая причина - ошибка при загрузке файла изображения и отсутствие проверки на эту ошибку.
//!          Пример с проверкой на правильность загрузки см. ниже. @nn
//!          Изображение-источник и изображение-приемник не могут налагаться друг на друга. @nn
//!          Если прямоугольник копируемой области не полностью лежит в полном прямоугольнике источника, то функция
//!          работать не будет.
//!
//!          Стандартная функция TransparentBlt из Win32 API может масштабировать изображение. В txTransparentBlt
//!          это убрано для упрощения использования. If you need image scaling, use original function
//!          TransparentBlt and don't mess with stupid TX-based tools. (See implementation of txTransparentBlt in TXLib.h).
//!
//! @note    Если TransparentBlt не работает, используйте функцию AlphaBlend, она вообще лучше.
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection()
//!
//! @usage   Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  superman_FromTXLibHelp = txLoadImage ("Resources\\Images\\Superman.bmp");
//!
//!          if (!superman_FromTXLibHelp)
//!              txMessageBox ("Cannot load superman, all the monsters will succeed (I copied them from TXLib Help)", "Sorry");
//!
//!          // См. важный комментарий в примере к функции txLoadImage!
//!
//!          txTransparentBlt (txDC(), 0, 0, 800, 600, superman_FromTXLibHelp);
//!
//!          // А можно и так:
//!          Win32::TransparentBlt (txDC(), 0, 0, 800, 600, superman_FromTXLibHelp, 0, 0, 80, 60, -1); // 10x zoom
//!          // Познай мощь Win32 GDI, отказавшись от TXLib'а! :) см. TransparentBlt в MSDN.com.
//!
//!          ...
//!          txDeleteDC (superman_FromTXLibHelp);  // So pity :( But he was only a copy from TXLib Help.
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, double xDest, double yDest, double width, double height,
                       HDC src,  double xSrc = 0, double ySrc = 0, COLORREF transColor = TX_BLACK);

//! @cond INTERNAL
inline bool txTransparentBlt (HDC dest, double xDest, double yDest, HDC src, COLORREF transColor = TX_BLACK);
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Копирует изображение с одного холста (контекста рисования, DC) на другой с учетом полупрозрачности.
//!
//! @param   dest    Контекст назначения (куда копировать). Если NULL, то копирует в окно TXLib
//! @param   xDest   X-координата верхнего левого угла изображения-приемника
//! @param   yDest   Y-координата верхнего левого угла изображения-приемника
//! @param   width   Ширина копируемого изображения. Если <= 0, то автоматически берется из размера источника
//! @param   height  Высота копируемого изображения. Если <= 0, то автоматически берется из размера источника
//! @param   src     Контекст источника (откуда копировать). Должен иметь 32-битовый формат и альфа-канал (см. ниже)
//! @param   xSrc    X-координата верхнего левого угла изображения-источника
//! @param   ySrc    Y-координата верхнего левого угла изображения-источника
//! @param   alpha   Общая прозрачность изображения, в дополнение к альфа-каналу (0 - все прозрачно, 1 - использовать
//!                  только альфа-канал)
//! @param   format  Если нужно учитывать альфа-канал источника (например, в загруженных картинках), то AC_SRC_ALPHA,
//!                  иначе 0 (например, если холст источника создан с помощью txCreateCompatibleDC, см. ниже)
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если контекст источника равен NULL, то он не существует и копирование вызовет ошибку.
//!          Наиболее частая причина - ошибка при загрузке файла изображения и отсутствие проверки на эту ошибку.
//!          Пример с проверкой на правильность загрузки см. ниже.
//!
//! @warning Изображение-источник и изображение-приемник не могут налагаться друг на друга. @nn
//!          Если прямоугольник копируемой области не полностью лежит в прямоугольнике источника, то функция
//!          работать не будет.
//!
//! @note    Изображение-источник должно быть загружено с помощью txLoadImage() и иметь <b>32-битовый RGBA-формат,</b>
//!          либо создано с помощью функции txCreateDIBSection(). @nn
//!          Дополнительный канал <b>(A, альфа-канал)</b> этого формата отвечает за прозрачность участков
//!          изображения. 24-битовый формат файлов (TrueColor RGB) функция txAlphaBlend поддерживает только если
//!          установить параметр @p format равным 0.
//!
//!          Альфа-канал можно сделать, например, в Adobe Photoshop, командой "Новый канал (New Channel)" в палитре
//!          каналов (Channels). Черный цвет в альфа-канале соответствует полной прозрачности, белый - полной
//!          непрозрачности. <b>При этом в прозрачных областях само изображение (в каналах R, G, B) должно быть
//!          черным, и чем прозрачнее, тем чернее.</b> Такой формат цвета называется <b>Premultiplied Alpha.</b>
//!          См. изображение с альфа-каналом в примере TX\Examples\Tennis\Tennis.cpp (файл с теннисной ракеткой:
//!          TX\Examples\Tennis\Resources\Images\Racket.bmp).
//!
//!          Иначе говоря, при пересчете в формат <b>Premultiplied Alpha</b> надо домножить цвета в каналах R,G,B
//!          на значения альфа-канале @c A: <tt>R,G,B *= A / 255.0</tt>. Получится вот что:
//!
//!        - Если значение альфа-канала для некоторого пикселя равно   0 (полная   прозрачность), тогда значения
//!          каналов R,G,B для этого пикселя также станут 0 (это черный цвет).
//!        - Если значение альфа-канала для некоторого пикселя равно 255 (полная непрозрачность), тогда значения
//!          каналов R,G,B для этого пикселя не изменятся.
//!        - Для других значений альфа-канала, пиксели изображения станут темнее.
//!
//!          В редакторе Adobe Photoshop это можно сделать командой <b>Image @d Apply Image</b> с параметрами:
//! @table   @tr Source:     @td <i>Имя файла с картинкой</i>
//!          @tr Layer:      @td Background
//!          @tr @b Channel: @td <b> Alpha 1</b>
//!          @tr Blending:   @td Multiply
//!          @tr Opacity:    @td 100%
//! @endtable
//!
//!          Если изображение с альфа-каналом @b не находится в формате <b>Premultiplied Alpha</b>, то для перевода
//!          в этот формат можно использовать функцию txUseAlpha(). Однако не надо вызывать txUseAlpha() несколько
//!          раз для одного и того же изображения, иначе оно может становиться темнее.
//!
//!          Изображение-источник также может быть создано с помощью txCreateCompatibleDC(), если видеорежим дисплея
//!          32-битовый (TrueColor). @nn
//!          В этом случае альфа-канал созданного холста будет содержать нули, т.е. изображение на нем будет всегда
//!          трактоваться как полностью прозрачное и при копировании с помощью txAlphaBlend результата не будет.
//!          Чтобы игнорировать такой нулевой альфа-канал, параметр @p format надо установить в 0, и общую прозрачность
//!          регулировать только параметром @p alpha. Попиксельной прозрачности в этом случае не будет. См. пример
//!          к функции txSaveImage().
//!
//!          Если изображение-источник создано с помощью txCreateDIBSection() или txLoadImage(), то txAlppaBlend()
//!          может использовать как общую прозрачность, задачаемую параметром @p alpha, так и попиксельную прозрачность,
//!          задаваемую альфа-каналом.
//!
//! @note    Стандартная функция AlphaBlend из Win32 API @b может масштабировать изображение. В txAlphaBlend это
//!          @b убрано для упрощения использования. If you still need image scaling, use original function AlphaBlend
//!          and don't mess with stupid TX-based tools. (See implementation of txAlphaBlend in TXLib.h).
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection(), txUseAlpha()
//!
//! @usage   Пример использования см. в файле TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  batman_FromTXLibHelp = txLoadImage ("Resources\\Images\\Batman.bmp");
//!
//!          if (!batman_FromTXLibHelp)
//!              txMessageBox ("Call to Batman failed because I copied it from TXLib Help", "Do save yourself");
//!
//!          // См. важный комментарий в примере к функции txLoadImage!
//!
//!          txAlphaBlend (txDC(), 0, 0, 800, 600, batman_FromTXLibHelp);
//!
//!          ...
//!          txDeleteDC (batman_FromTXLibHelp);  // Don't worry, batman will return in "Batman returns" movie, later...
//!          ...
//!
//!          return batman_FromTXLibHelp;        // ...and there he comes -- in TXLib copy form
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, double xDest, double yDest, double width, double height,
                   HDC src,  double xSrc = 0, double ySrc = 0, double alpha = 1.0, unsigned format = AC_SRC_ALPHA);

//! @cond INTERNAL
inline bool txAlphaBlend (HDC dest, double xDest, double yDest, HDC src, double alpha = 1.0);
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Пересчитывает цвета пикселей с учетом прозрачности (переводит цвета в формат Premultiplied Alpha).
//!
//! @param   dc  Дескриптор холста, изображение которого пересчитывается.
//!
//! @return  Если операция была успешна, возвращается исходный HDC, иначе - NULL.
//!
//!          Пересчет цветов в каналах R,G,B в формат <b>Premultiplied Alpha</b> с учетом значения в альфа-канале
//!          @c A идет по формуле <tt>R,G,B *= A / 255.0</tt>. Получается вот что:
//!
//!        - Если значение альфа-канала для некоторого пикселя равно   0 (полная   прозрачность), тогда значения
//!          каналов R,G,B для этого пикселя также станут 0 (это черный цвет).
//!        - Если значение альфа-канала для некоторого пикселя равно 255 (полная непрозрачность), тогда значения
//!          каналов R,G,B для этого пикселя не изменятся.
//!        - Для других значений альфа-канала, пиксели изображения станут темнее.
//!
//!          Пересчет цветов пикселей с учетом их прозрачности в формат Premultiplied Alpha необходим:
//!
//!        - В случае ручного изменения цветов (пример см. в функции txCreateDIBSection).
//!        - После загрузки картинок из файла с помощью txLoadImage(), если цвета изображения в нем не были заранее
//!          домножены на альфа-канал в Adobe Photoshop или аналогичной программе (см. замечания к функции @ref
//!          txAlphaBlend).
//!
//!          См. также замечания к функции txAlphaBlend().
//!
//! @see     txCreateCompatibleDC(), txCreateDIBSection(), txLoadImage(), txDeleteDC(), txAlphaBlend()
//!
//! @usage   См. в функции txCreateDIBSection().
//}----------------------------------------------------------------------------------------------------------------

HDC txUseAlpha (HDC dc);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Сохраняет в файл изображение в формате BMP.
//!
//! @param   filename    Имя файла с расширением "BMP", куда будет записано изображение в формате BMP
//! @param   dc          Дескриптор холста, изображение которого сохраняется в файл. Если NULL, сохраняется изображение
//!                      окна TXLib.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @see     txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(), txTransparentBlt()
//!
//! @usage   @code
//!          txDrawMan (50, 110, 100, 100, TX_YELLOW, 0.3, -0.5, -0.4, 0, 0.8, 1, -1, 0.5, 1, 1);
//!
//!          HDC dc = txCreateCompatibleDC (100, 110);
//!          txBitBlt (dc, 0, 0, 100, 110, txDC());
//!          txSaveImage ("TXLibMan.bmp", dc);
//!
//!          txBitBlt     (dc,       0,   0, 100, 110, txDC());
//!          txBitBlt     (txDC(), 200, 200,   0,   0, dc);
//!          txAlphaBlend (txDC(), 100, 100,   0,   0, dc, 0, 0, 0.25, 0);
//!          txDeleteDC (dc);
//!
//!          txSaveImage ("ScreenShot.bmp");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txSaveImage (const char filename[], HDC dc = txDC());

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Utility functions
//! @name    Вспомогательные функции
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Задерживает выполнение программы на определенное время.
//!
//! @param   time  Задержка в миллисекундах.
//!
//! @return  Задержка в миллисекундах, произошедшая в действительности.
//!
//! @note    <b>Перед началом задержки изображение в окне обязательно обновится,</b> даже если рисование
//!          заблокировано через txBegin().
//!
//! @see     txBegin(), txEnd(), txUpdateWindow()
//!
//! @usage @code
//!          txSleep (500); // ПП: Поспать Полсекунды
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

double txSleep (double time);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Блокирует обновление изображения окна, во избежание мигания.
//!
//!          Для снятия блокировки используется функция txEnd().
//!
//!          Если в программе требуется задержка, то используйте функцию txSleep(), так как она автоматически
//!          обновляет изображение, независимо от состояния блокировки.
//!
//! @warning Избегайте блокирования на долгое время. Это может привести к дефектам изображения в окне.
//!
//! @note    Если нажата клавиша Alt+PrintScreen, то блокировка временно отменяется.
//!
//! @return  Значение счетчика блокировки (если 0, то рисование разблокировано).
//!
//! @see     txEnd(), txSleep(), txUpdateWindow(), txTextCursor()
//!
//! @usage @code
//!          txBegin();                        // Здесь изображение "замерзнет"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                        // Это вызвало бы мигание без txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                          // Здесь мы сразу увидим окончательный рисунок
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txBegin();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Разблокирует обновление окна, заблокированное функцией txBegin().
//!
//! @warning Если txBegin() вызывалась несколько раз, то для снятия блокировки требуется столько же раз вызвать
//!          txEnd().
//!
//! @note    Если нажата клавиша Alt+PrintScreen, то блокировка временно отменяется.
//!
//! @return  Значение счетчика блокировки (если 0, то рисование разблокировано).
//!
//! @see     txBegin(), txSleep(), txUpdateWindow(), txTextCursor()
//!
//! @usage @code
//!          txBegin();                        // Здесь изображение "замерзнет"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                        // Это вызвало бы мигание без txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                          // Здесь мы сразу увидим окончательный рисунок
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txEnd();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Разрешает или запрещает автоматическое обновление изображения в окне.
//!
//! @param   update  Режим обновления (true - разрешить, false - запретить).
//!
//! @return  Предыдущее состояние режима обновления.
//!
//!          В отличие от txBegin() и txEnd(), которые поддерживают вложенные вызовы и работают как "скобки для
//!          замерзания картинки", txUpdateWindow() позволяет явно установить или снять блокировку автоматического
//!          обновления экрана.
//!
//!          Более полную информацию о блокировке см. в функциях txBegin(), txEnd() и txSleep().
//!
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txTextCursor(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txUpdateWindow (int update = true);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Устанавливает текущий активный объект GDI.
//!
//! @param   obj  Дескриптор объекта GDI
//! @param   dc   Холст (контекст рисования), в котором устанавливается текущий активный объект GDI
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @note    Предыдущий выбранный объект того же типа (PEN/BRUSH/BITMAP и т.п.), как и @c obj, @b уничтожается.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txSelectFont()
//!
//! @usage @code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj, HDC dc = txDC (true));

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Делает нечто иногда удобное. См. название функции.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          У этой функции есть синоним с простым понятным названием, поищите его в файле библиотеки, около
//!          @a определения этой функции. Или можно @strike скопировать @endstrike набрать это километровое имя
//!          и посмотреть, что получится.
//!
//! @see     txCreateWindow(), txSleep()
//!
//! @usage @code
//!          int main()
//!              {
//!              txCreateWindow (800, 600);
//!
//!              txSetTextAlign (TA_CENTER);
//!              txTextOut (txGetExtentX()/2, txGetExtentY()/2, "Press any key to exit!");
//! @endcode
//
//                 +--<<< Это текст помощи, который вы уже читали. Ищите дальше! Жмите [F3] или "Найти далее"
//                 |
//                 v
//               txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();
//! @code        txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();
//!              return 0;
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

//     +--<<< Это _прототип_ функции, а надо найти ее _определение_. Ищите дальше! Жмите [F3] или "Найти далее"
//     |
//     v
bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Уничтожает окно TXLib.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @warning Если уничтожается главное окно TXLib, функция main() прерывается и программа автоматически завершается.
//!          При этом @b не гарантируется правильное завершение программы, поэтому так делать @b не рекомендуется.
//!
//! @see     txCreateWindow()
//!
//! @usage @code
//!          txDestroyWindow();  // Farewell to the world
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txDestroyWindow();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Оценивает скорость работы компьютера.
//!
//! @return  Скорость работы (графических операций) в условных единицах.
//!
//! @see     txSleep(), txGetFPS()
//!
//! @usage @code
//!          if (txQueryPerformance() < 1) printf ("Хочется новый компьютер");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

double txQueryPerformance();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Выдает количество кадров (вызовов этой функции) в секунду.
//!
//! @param   minFrames  Количество вызовов, после которых FPS начинает усредняться.
//!
//! @return  FPS (Frames per Second), т.е. количество кадров (вызовов этой функции) в секунду.
//!
//! @note    Когда количество вызовов этой функции превысит @p minFrames, FPS начинает усредняться по последним
//!          кадрам. Максимальное количество интервала усреднения @d 100 кадров.
//!
//! @see     txSleep(), txQueryPerformance()
//!
//! @usage   См. в функции txCreateDIBSection().
//}----------------------------------------------------------------------------------------------------------------

double txGetFPS (unsigned minFrames = 0);

//! @}
//}

//=================================================================================================================
//{          Mouse functions
//! @name    Работа с мышью
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает позицию Мыши!
//!
//! @return  Позиция мыши как структура POINT.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//!
//! @usage @code
//!          RECT area = { 100, 100, 110, 110 };
//!
//!          while (txMouseButtons() != 1)
//!              {
//!              if (In (txMousePos(), area)) txTextOut (100, 100, "What are you doing here?!");
//!              txSleep (0);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline POINT txMousePos();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает X-Координату Мыши!
//!
//! @return  X-координата мыши.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//!
//! @usage @code
//!          while (txMouseButtons() != 1)
//!              {
//!              txCircle (txMouseX(), txMouseY(), 20);
//!              txSleep (0);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txMouseX();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает Y-Координату Мыши!
//!
//! @return  Y-координата мыши.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//!
//! @usage @code
//!          while (txMouseButtons() != 1)
//!              {
//!              txCircle (txMouseX(), txMouseY(), 20);
//!              txSleep (0);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txMouseY();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   Возвращает состояние Кнопок Мыши!
//!
//! @return  Состояние Кнопок Мыши!
//!
//!          В возвращаемом значении выставленный в единицу 1-й (младший) бит означает нажатую левую Кнопку Мыши,
//!          2-й - правую. @n
//!          Например, возвращенное число 3 (двоичное 11) означает одновременное нажатие левой и правой Кнопок.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//!
//! @usage @code
//!          while (txMouseButtons() != 3)
//!              {
//!              if (txMouseButtons() & 1) txCircle (txMouseX(), txMouseY(), 20);
//!              if (txMouseButtons() & 2) txLine   (txMouseX(), txMouseY(), 0, 0);
//!              txSleep (0);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline unsigned txMouseButtons();

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Console functions
//! @name    Функции консоли
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает цветовые атрибуты консоли.
//!
//! @param   colors  Цветовые атрибуты консоли.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          @b Атрибуты - это цвет текста (colorText) и цвет фона (colorBackground), объединенные вместе: @nn
//!          <tt>colors = colorText + colorBackground * 16</tt> @nn
//!          либо @nn
//!          <tt>colors = colorText | (colorBackground \<\< 4)</tt> @nn
//!          Цвета атрибутов @b не имеют никакого отношения к цветам рисования, задаваемыми @ref txColors "TX_..."
//!          константами, RGB(), txSetColor(), txColor(), txSetFillColor() и т.д. Значения цветов см. ниже.
//!
//! @title   Значения цветов атрибутов
//! @table   @tr  Dec @td @c Hex @td                 @td Dec  @td @c Hex @td
//!          @tbr
//!          @tr  0 = @td @c 0x0 @td = Черный,       @td  8 = @td @c 0x8 @td = Темно-серый,
//!          @tr  1 = @td @c 0x1 @td = Синий,        @td  9 = @td @c 0x9 @td = Светло-синий,
//!          @tr  2 = @td @c 0x2 @td = Зеленый,      @td 10 = @td @c 0xA @td = Светло-зеленый,
//!          @tr  3 = @td @c 0x3 @td = Сине-зеленый, @td 11 = @td @c 0xB @td = Светло-сине-зеленый,
//!          @tr  4 = @td @c 0x4 @td = Красный,      @td 12 = @td @c 0xC @td = Светло-красный,
//!          @tr  5 = @td @c 0x5 @td = Малиновый,    @td 13 = @td @c 0xD @td = Светло-малиновый,
//!          @tr  6 = @td @c 0x6 @td = Темно-желтый, @td 14 = @td @c 0xE @td = Желтый,
//!          @tr  7 = @td @c 0x7 @td = Серый,        @td 15 = @td @c 0xF @td = Белый.
//! @endtable
//!
//!          В шестнадцатеричной системе счисления атрибуты задавать можно проще: если нужен, скажем, желтый цвет
//!          на синем фоне, то его код будет @c 0x1e (старшая цифра - старшие 4 бита - это цвет фона, младшая
//!          цифра - младшие 4 бита - это цвет текста).
//!
//! @see     txTextCursor(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          txSetConsoleAttr (0x1E);
//!          printf ("А в небе 0x1 есть город 0xE");  // (c) Б. Гребенщиков
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txSetConsoleAttr (unsigned colors = 0x07);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает текущие цветовые атрибуты консоли.
//!
//! @return  Текущие цветовые атрибуты консоли. См. txSetConsoleAttr().
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          unsigned attr = txGetConsoleAttr();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned txGetConsoleAttr();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Стирает текст консоли.
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//!          При стирании используются текущие атрибуты (цвета текста и фона) консоли.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          txClearConsole();  // Ну вот и все, дружок
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txClearConsole();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Устанавливает позицию мигающего курсора консоли.
//!
//! @param   x  X-координата курсора в пикселях.
//! @param   y  Y-координата курсора в пикселях.
//!
//! @return  Предыдущее положение мигающего курсора в структуре POINT.
//!
//! @note    Нельзя установить совсем любую позицию. Текст в консоли расположен по прямоугольной сетке, размер
//!          которой зависит от размеров шрифта консоли. Устанавливаемая позиция округляется, чтобы курсор попал
//!          в ячейку сетки. См. пример к функции txGetConsoleFontSize().
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(), txClearConsole()
//!
//! @usage @code
//!          txSetConsoleCursorPos (txGetExtentX(), txGetExtentY());  // Центр Вселенной
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txSetConsoleCursorPos (double x, double y);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает позицию мигающего курсора консоли.
//!
//! @return  Положение мигающего курсора в структуре POINT.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(), txClearConsole()
//!
//! @usage @code
//!          POINT pos = txGetConsoleCursorPos();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleCursorPos();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Возвращает размеры шрифта консоли.
//!
//! @return  Размеры шрифта консоли в пикселях, в структуре POINT.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          POINT size = txGetConsoleFontSize();
//!          txSetConsoleCursorPos (5 * size.x, 10 * size.y);  // А теперь мигай вот там
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleFontSize();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   Запрещает или разрешает рисование мигающего курсора в окне.
//!
//! @param   blink  false - запретить мигающий курсор
//!
//! @return  Предыдущее значение состояния курсора.
//!
//! @see     txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(),
//!          txGetConsoleFontSize(), txClearConsole(), txCreateWindow(), txUpdateWindow(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          txTextCursor (false);
//!          ...
//!          txTextCursor();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txTextCursor (bool blink = true);

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Other staff not related to drawing
//! @name    Другие полезные функции, не связанные с рисованием
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Воспроизводит звуковой файл.
//!
//! @param   filename  Имя звукового файла. Если NULL - останавливает звук.
//! @param   mode      Режим воспроизведения
//!
//! @return  Если операция была успешна - true, иначе - false.
//!
//! @title   Режимы воспроизведения: @table
//!          @tr SND_ASYNC       @td Звук проигрывается одновременно с работой программы. @n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).
//!          @tr SND_SYNC        @td Выполнение программы приостанавливается до окончания воспроизведения звука.
//!          @tr SND_LOOP        @td Зацикливать звук при воспроизведении. @n
//!                                  Чтобы отменить звучание, вызовите txPlaySound (NULL).
//!          @tbr
//!          @tr SND_NODEFAULT   @td Не использовать звук по умолчанию, если нельзя проиграть указанный звуковой файл.
//!          @tr SND_NOSTOP      @td Если какой-либо звук уже проигрывается, не останавливать его для запуска указанного звука.
//!          @tr SND_APPLICATION @td Проигрывать звук, используя программу, зарегистрированную для данного типа звуковых файлов.
//!          @endtable
//!
//! @note    Поддерживаются только файлы в формате WAV. Остальные форматы (MP3 и др.) надо перекодировать.
//!          Переименование со сменой расширения не поможет, как и в случае с форматом картинок в txLoadImage().
//!
//! @usage @code
//!          txPlaySound ("tada.wav");  // So happy that this always exists
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит сообщение в окне с помощью функции MessageBox.
//!
//! @param   text    Текст сообщения
//! @param   header  Заголовок сообщения
//! @param   flags   Флаги отображения сообщения
//!
//! @return  Значение, возвращаемое функцией MessageBox.
//!
//! @warning Текст не должен превышать _TX_BIGBUFSIZE символов, а заголовок @d _TX_BIGBUFSIZE символов, иначе они
//!          обрезаются.
//!
//! @note    Вместо <tt><b>txMessageBox (text, header, flags)</b></tt> можно использовать стандартную функцию Win32
//!          <tt><b>MessageBox (txWindow(), text, header, flags)</b></tt>. Отличия txMessageBox в том, что она
//!          автоматически подставляет окно-родитель, и в том, что при выводе в окно строчки переводятся в формат
//!          UNICODE. Это важно лишь в том случае, когда <i>в региональных настройках контрольной панели Windows
//!          неверно установлена кодовая страница для программ, не поддерживающих UNICODE.</i> В остальных случаях
//!          нужды в @c txMessageBox нет.
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txNotifyIcon(), txStackBackTrace()
//!
//! @usage @code
//!          if (txMessageBox ("Получилось?", "Прочти меня", MB_YESNO) == IDYES)
//!              {
//!              MessageBox (txWindow(), "Хватит и обычного MessageBox()", "Win32 сообщает", 0);
//!              }
//!          else
//!              txMessageBox ("Спасаем от кракозябл вместо русских букв. Гарантия. Недорого.");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txMessageBox (const char text[], const char header[] = "TXLib сообщает", unsigned flags = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит всплывающее сообщение в системном трее.
//!
//! @param   flags   Флаги сообщения
//! @param   title   Заголовок сообщения
//! @param   format  Строка для печати, как в printf().
//!
//! @title   Флаги сообщения:
//! @table   @tr @c NIIF_INFO    @td Информация
//!          @tr @c NIIF_WARNING @td Предупреждение
//!          @tr @c NIIF_ERROR   @td Сообщение об ошибке
//! @endtable
//!
//! @return  Удалось ли отобразить сообщение.
//!
//!          Функция формирует сообщение по правилам printf() и выводит во всплывающем окне.
//!
//! @warning
//!        - Эта функция требует, чтобы при компиляции константа версии Internet Explorer @c (_WIN32_IE) была
//!          задана не ниже 0x0500. Для этого надо либо <b>включить TXLib.h вместо @c windows.h или перед ним.</b>
//!          Либо надо самостоятельно определить @c (\#define) эту константу. @n
//!          <small>С версией Internet Explorer это связано потому, что при его установке в Windows обновляются
//!          многие компоненты (например, @c shell32.dll и @c comctl32.dll), которые влияют на функциональность
//!          системы независимо от использования браузера). Сам Internet Explorer в отображении сообщения
//!          не участвует.</small>
//!        - Сообщение не должно превышать _TX_BUFSIZE символов, иначе оно обрезается.
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox()
//!
//! @usage @code
//!          int hours = 3, minutes = 10;
//!          const char station[] = "Юму";
//!          ...
//!          txNotifyIcon (NIIF_INFO, "Уважаемые пассажиры",
//!                        "Поезд на %s отправляется в %d:%d.", station, hours, minutes);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
bool txNotifyIcon (unsigned flags, const char title[], const char format[], ...) _TX_CHECK_FORMAT (3);
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит сообщение в отладчике.
//!
//! @param   format  Строка для печати, как в printf().
//!
//! @return  Количество напечатанных символов.
//!
//!          Функция формирует сообщение по правилам printf() и передает его в OutputDebugString(). Ее вывод можно
//!          перехватить отладчиком или утилитами-логгерами, например,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>DbgView</a>.
//!          Если этого не сделать, и не задать первый символ @c '\\a' (см. ниже), то о сообщении никто не узнает. :(
//! @note
//!        - Если первый            символ в строке @c '\\a', то сообщение также дублируется txMessageBox().
//!        - Если первый или второй символ в строке @c '\\f', то сообщение также дублируется printf().
//!
//! @warning Сообщение не должно превышать _TX_BIGBUFSIZE символов, иначе оно обрезается.
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR(), txNotifyIcon(), txMessageBox(), txStackBackTrace()
//!
//! @usage @code
//!          int x = 42;
//!          ...
//!          txOutputDebugPrintf ("Никто не узнает, что %d.", x);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txOutputDebugPrintf (const char format[], ...) _TX_CHECK_FORMAT (1);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Вычисление размера массива в элементах
//!
//! @param   arr  Имя массива
//!
//! @return  Размер массива в элементах (не в байтах).
//!
//!          Макрос sizearr() вычисляет размер массива в элементах, проверяя, можно ли его правильно вычислить при
//!          компиляции.
//!
//!          Макрос SIZEARR() просто делит размер всего массива в байтах на размер его элемента, получается размер
//!          массива в элементах. @n
//!          Он <b>не проверяет,</b> можно ли его правильно вычислить, и при неправильном использовании может
//!          выдать <b>неверный размер.</b>
//!
//! @warning SIZEARR() выдает неверный размер, если определение массива вместе с его размером, известным при
//!          компиляции, недоступно в месте использования SIZEARR(). См. пример ниже.
//!
//! @note    В Microsoft Visual Studio 6 макрос sizearr() недоступен - у ее компилятора недостаточно сил, чтобы
//!          скомпилировать его. :(
//!
//! @usage @code
//!          void test()
//!              {
//!              // Размер этого массива, хоть и не указан, но может быть автоматически определен
//!              // компилятором при компиляции программы. Он равен 4 (четыре структуры POINT).
//!
//!              POINT coord[] = { {110, 110}, {120, 120}, {130, 110}, {140, 120} };
//!
//!              // Здесь размер массива известен при компиляции, т.к. он был определен тут же.
//!
//!              for (int i = 0; i < sizearr (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!
//!              DrawLines1 (coord);                  // Попытка передать массив без передачи размера.
//!              DrawLines2 (coord, sizearr (coord)); // Правильная передача размера массива.
//!
//!              DrawLines3 (coord);                  // В принципе, можно и так, но тут ВОДЯТСЯ ШАБЛОНЫ.
//!              }
//!
//!          // Функции DrawLines1 и DrawLines2 определены так:
//!
//!          void DrawLines1 (const POINT coord[])
//!              {
//!              // Массивы в Си передаются как указатели на начало массива. Поэтому:
//!              // 1) sizearr здесь выдаст ошибку компиляции, и ее легко будет найти.
//!              // 2) SIZEARR здесь неверно посчитает размер, что намного хуже, чем ошибка компиляции,
//!              //      т.к. он будет равен sizeof (POINT*) / sizeof (POINT) == 4/8 == 0, что станет
//!              //      трудноуловимой логической ошибкой времени исполнения.
//!
//!              for (int i = 0; i < sizearr (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//!
//!          void DrawLines2 (const POINT coord[], int n)
//!              {
//!              // Здесь размер приходит как параметр n, так что все просто. Вызывающая сторона (функция
//!              // test) правильно вычисляет его и передает функции DrawLines2, которая им пользуется.
//!
//!              for (int i = 0; i < n - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//!
//!          // HIC SVNT TEMPLATES
//!
//!          template <int size>
//!          void DrawLines3 (const POINT (&coord) [size])
//!              {
//!              for (int i = 0; i < size - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------
//! @{

#ifndef _MSC_VER_6

    #define sizearr( arr )    ( sizeof (get_size_of_an_array_with_unknown_or_nonconst_size_ (arr)) )

    //! @cond INTERNAL
    //  See explanation here: http://blogs.msdn.com/b/the1/archive/2004/05/07/128242.aspx

    template <typename T, int N> char (&get_size_of_an_array_with_unknown_or_nonconst_size_ (T (&) [N])) [N]; // ;)

    //! @endcond

#endif

//! Замена макросу sizearr() для работы в Microsoft Visual Studio 6

#define SIZEARR( arr )        ( sizeof (arr) / sizeof (0[arr]) )

//! @}
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Генератор случайных чисел
//!
//! @param   range  Правая граница диапазона (@b не включая саму границу).
//!
//! @return  Случайное целое число в диапазоне [0; range).
//!
//!          Вы еще помните, что означают разные скобочки в обозначении интервалов? :)
//!
//! @warning Эта функция может мяукать. @strike Just because it can. @endstrike Потому что она не часть стандарта С++
//!          или Windows, а зависит от TXLib'а. Если это вам не нравится, вы можете написать ее сами, с помощью
//!          стандартной функции rand() и операции остатка от деления %. Подсказка: rand() % rande.
//!
//! @usage @code
//!          char message[100] = "Maybe...";
//!          sprintf (message, "You SUDDENLY got %d bucks now. But note that tax rate is $%d.", random (100), 100);
//!          txMessageBox (message, "Lottery");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int random (int range) _TX_DEPRECATED;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Генератор случайных чисел
//!
//! @param   left   Левая  граница диапазона (@b включая саму границу).
//! @param   right  Правая граница диапазона (@b включая саму границу).
//!
//! @return  Случайное целое число в диапазоне [left; right].
//!
//!          Вы все еще помните, что означают разные скобочки в обозначении интервалов? :)
//!
//! @warning Эта функция может мяукать. @strike Just in case. @endstrike Потому что она не часть стандарта С++
//!          или Windows, а зависит от TXLib'а. Если это вам не нравится, вы можете написать ее сами, с помощью
//!          стандартной функции rand() и небольшой @strike уличной @endstrike магии с делением на RAND_MAX и
//!          @strike таинственной @endstrike операцией вычитания.
//!
//! @usage @code
//!          int money = random (-100, +100);
//!          if (money < 0)
//!              {
//!              char message[100] = "Maybe...";
//!              sprintf ("Проиграли в лотерею? Отдайте долг в %d рублей", -money);
//!              txMessageBox (message, "Быстро!");
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline double random (double left, double right) _TX_DEPRECATED;

inline double random (std::nomeow_t, double left, double right);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Проверка, находится ли параметр х внутри замкнутого интервала [a; b]
//!
//! @param   x  Проверяемый параметр
//! @param   a  Левая  граница (включительно)
//! @param   b  Правая граница (включительно)
//!
//! @return  Если a <= x && x <= b, то истина, если нет - ложь
//!
//! @warning Эта функция может мяукать. @strike Because cats are power! @endstrike Потому что она не часть стандарта
//!          С++ или Windows, а зависит от TXLib'а. Если это вам не нравится, вы можете написать ее сами, используя
//!          неравенства.
//!
//! @usage @code
//!          while (txMouseButtons() != 1)
//!              {
//!              if (In (txMouseX(), 110, 120)) txTextOut (100, 100, "Meet the wall!");
//!              txSleep (0);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

template <typename Tx, typename Ta, typename Tb>
inline bool In (Tx x, Ta a, Tb b) _TX_DEPRECATED;

template <typename Tx, typename Ta, typename Tb>
inline bool In (std::nomeow_t, Tx x, Ta a, Tb b) _TX_DEPRECATED;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Проверка, находится ли точка pt внутри прямоугольника rect
//!
//! @param   pt    Проверяемая точка в виде <tt> POINT {x, y} </tt>
//! @param   rect  Прямоугольник     в виде <tt> RECT  {left, top, right, bottom} </tt>
//!
//! @return  Результат проверки
//!
//!          Удобно для реализации экранных кнопок, нажимаемых курсором мыши.
//!
//! @warning Эта функция может мяукать. @strike Because cats are always right. @endstrike Потому что она не часть
//!          стандарта С++ или Windows, а зависит от TXLib'а. Если это вам не нравится, вы можете написать ее сами.
//!
//! @usage @code
//!          RECT button = { 100, 100, 150, 120 };
//!
//!          txSetFillColor (TX_LIGHTGRAY);
//!          txRectangle (button.left, button.top, button.right, button.bottom);
//!
//!          txSetTextAlign();
//!          txSetFillColor (TX_WHITE);
//!          txTextOut (125, 115, "Cookie");
//!
//!          for (;;)
//!              {
//!              if (In (txMousePos(), button))
//!                  {
//!                  txSetFillColor (TX_TRANSPARENT);
//!                  txRectangle (button.left, button.top, button.right, button.bottom);
//!
//!                  if (txMouseButtons())
//!                      {
//!                      txSetFillColor (TX_DARKGRAY);
//!                      txRectangle (button.left, button.top, button.right, button.bottom);
//!
//!                      txSetFillColor (TX_WHITE);
//!                      txTextOut (125, 115, "You got cookie");
//!
//!                      break;
//!                      }
//!                  }
//!
//!              txSleep (0);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
//! @{

inline bool In (const POINT& pt, const RECT& rect)       _TX_DEPRECATED;

inline bool In (const COORD& pt, const SMALL_RECT& rect) _TX_DEPRECATED;

//! @}
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Возвращает максимальное из двух чисел
//!
//! @param   a  Одно   из чисел :)
//! @param   b  Другое из чисел :)
//!
//! @return  Максимальное из двух чисел a и b
//!
//! @warning Это @b макрос, и аргументы @c a и @c b могут вычисляться в нем два раза. Поэтому не используйте в нем
//!          побочных действий @c ++, @c --, @c += и т.п. Например, @b не пишите так: <tt>int m = MAX (++x, y += 2);</tt>
//!
//! @see     MIN()
//!
//! @usage @code
//!          if (MAX (3, 7) != 7) printf ("Your CPU is broken, throw it away.");
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define MAX( a, b )     ( (a) > (b) ? (a) : (b) )

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Возвращает минимальное из двух чисел
//!
//! @param   a  Одно   из чисел :)
//! @param   b  Другое из чисел :)
//!
//! @return  Минимальное из двух чисел a и b
//!
//! @warning Это @b макрос, и аргументы @c a и @c b могут вычисляться в нем два раза. Поэтому не используйте в нем
//!          побочных действий @c ++, @c --, @c += и т.п. Например, @b не пишите так: <tt>int m = MIN (x--, y /= 2);</tt>
//!
//! @see     MAX()
//!
//! @usage @code
//!          if (MIN (3, 7) != 3) printf ("Your CPU is still broken, throw it away twice.");
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define MIN( a, b )     ( (a) < (b) ? (a) : (b) )

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Округляет число до целого
//!
//! @param   x  Число
//!
//! @return  Округленное число, преобразованное в тип @c long
//!
//! @usage @code
//!          double weight = 5.5;        // 5.5 kilos is the weight of Maru in 2012.
//!          long Maru = ROUND (weight); // Should use ROUND() because Maru is so round. And long.
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L  // C99 case

    #define ROUND( x )  ( (long) round (x) )

#else

    #define ROUND( x )  ( (long) floor ((x) + 0.5) )

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Переинициализирует математический сопроцессор
//!
//! Сбрасывает состояние математического сопроцессора, вызывая _fpreset() и разрешая генерацию исключений сопроцессора
//! для неверного результата (_EM_INVALID), денормализации (_EM_DENORMAL), деления на ноль (_EM_ZERODIVIDE), переполнения
//! (_EM_OVERFLOW) и антипереполнения (_EM_UNDERFLOW). Обычный вызов _fpreset() эти исключения маскирует, в результате
//! чего вычислительные ошибки могут оказаться незамеченными.
//!
//! Если вы хотите замаскировать эти исключения, вызывайте обычный _fpreset(), и затем проверяйте результат вычислений
//! на достоверность хотя бы с помощью std::isfinite (x).
//!
//! @note    Поведение TXLib по умолчанию - @b генерация этих исключений и их @b перехват TXLib'ом в виде @b ошибки. @nn
//!          См. [1] <a href=http://books.google.ru/books?id=uwgNv8VlNPgC&pg=PA343>пример работы с этими исключениями,</a>
//!              [2] <a href=http://www.gamasutra.com/view/news/169203/Exceptional_floating_point.php>статью о них.</a>
//!
//! @usage @code
//!          tx_fpreset();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

void tx_fpreset();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Число Пи
//!
//! @usage @code
//!          if (txPI == 1) txMessageBox ("Вы попали в другую Вселенную.", "Поздравляем", MB_ICONSTOP);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   <i>Очень удобное</i> возведение числа в квадрат.
//!
//! @param   x  Число для возведения в него
//!
//! @return  Квадрат, полученный путем возведения в него числа, заданного для возведения в квадрат
//!
//! @note    Это пример, как <b> не надо </b> писать код: txSqr() @d функция с "медвежьей услугой". Иногда встречаются
//!          те, кто любит печатать в функции результат ее вычислений <small> (не данные для отладки, а именно результат),
//!          </small> вместо того, чтобы просто возвращать его туда, где эту функцию вызывали. Пусть эти люди воспользуются
//!          приведенной txSqr() для какого-нибудь нужного дела, особенно в цикле. Пример, конечно, несколько преувеличен.
//!          См. в исходном тексте код этой навязчивой радости.
//!
//! @usage @code
//!          printf ("\n" "Радиус\t\t" "Площадь круга\n\n");
//!
//!          for (double r = 100; r > 0; r--)
//!              {
//!              printf ("%6.2lf...", r);
//!
//!              double square = M_PI * txSqr (r);  // Надолго запомним эту площадь!
//!              printf ("\b\b\b   \t");
//!
//!              printf ("%-.2lf\n", square);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline
double txSqr (double x)
    {
    double sqr = pow (sqrt (x) * sqrt (x), sqrt (4.0));  // Бурная вычислительная деятельность

    char str[1024] = "";
    _snprintf_s (str, sizeof (str), "Возведение дало %g!" "!!" "!!" " Вы рады????", sqr);
    txMessageBox (str, "Получен ОТВЕТ!" "!!", MB_ICONEXCLAMATION | MB_YESNO) != IDNO ||
        (
        txMessageBox ("Жаль...", "А я так старалась", MB_ICONINFORMATION),
        txMessageBox ("Уйду я от вас", "Злые вы...",  MB_ICONSTOP),
        exit (EXIT_FAILURE), 0
        );

    txNotifyIcon (1, NULL, "\n%s\n", "Высшая математика!  \0"  // А как это работает, а?
                                     "С ума сойти...      \0"  //
                                     "а КЭП подтверждает  \0"  //       и кто это будет
                                     "Главное - отчитаться\0"  //       поддерживать?..
                                     "Невероятно, но факт \0"
                                     "Кто бы мог подумать?\0" + GetTickCount() % 6 * 21);

    return sqr;  // Все же вернем значение. Мы же не звери
    }

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   <i>Ну просто <b>очень</b> удобный</i> макрос.
//!
//! @warning Это еще один пример, как <b> не надо </b> писать код. @nn
//!          Макрос определен так: @nn
//!          <tt> \#define z 0 </tt> @nn
//!          Замечательный макрос! Теперь на одну переменную в программе стало меньше. :((
//!
//! @note    (Используйте @c \#undef. С @c <http://www.google.ru/search?q=%23undef>\#undef</a> ваша программа станет
//!          мягкой и шелковистой.)
//!
//! @usage @code
//!          #define _TX_DESTROY_3D
//!          #include "TXLib.h"
//!
//!          // А теперь попробуйте объявить переменную z для расчета 3-D координат x, y, z:
//!
//!          int z = 0;  // Да! TXLib уничтожает трехмерность! Очень круто. :=/
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define _TX_DESTROY_3D
#endif

#ifdef _TX_DESTROY_3D

    #define z  0                   // Читайте "Флатландию" Эбботта!
    #endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   <i>Еще парочка макросов.</i>
//!
//! @usage @code
//!          #include "TXLib.h"
//!
//!          int x = rand() meow   // Как же без котиков?
//!          int y = rand() meow
//!          if (x+y > RAMD_MAX/2) please x = y = 0;
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
//! @{

#define please

#define meow  ;

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Обнулитель типов, не имеющих конструкторов
//!
//! @param   type  Имя типа
//!
//! @return  Значение типа @p type, покомпонентно инициализированное по умолчанию (для встроенных типов - нулем).
//!
//! @usage @code
//!          void f (POINT p);
//!          ...
//!
//!          POINT z = {}; f (z);  // Так без ZERO
//!
//!          f (ZERO (POINT));     // Так с ZERO
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define ZERO( type )    zero <type> ()

//! @cond INTERNAL
template <typename T> inline T zero();
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Автоматический вызов функции при завершении другой функции (аналог @c __finally)
//!
//! @param   param_t  Тип параметра автоматически вызываемой функции
//! @param   param    Имя параметра автоматически вызываемой функции
//! @param   func     Тело автоматически вызываемой функции (фигурные скобки не обязательны)
//!
//! @par     Макрос <tt>TX_AUTO_FUNC (param_t, param, func)</tt>
//! @note
//!        - Для автоматически вызываемой функции допускается только @a один параметр.
//!        - Его тип @c param_t и имя @c param должны соответствовать определению переменной, доступной в текущей
//!          области видимости. @n
//!          Параметр вызываемой функции будет связан с этой переменной через ссылку.
//!        - Синоним: TX_FINALLY
//!
//! @warning В Microsoft Visual Studio 6 и 2003 в отладочной конфигурации (Debug) этот макрос работать не будет,
//!          см. <a href="http://support.microsoft.com/kb/199057">MS KB Article 199057</a>. Можно обходиться
//!          макросом @c _TX_AUTO_FUNC, см. его определение в исходном тексте рядом с определением @c TX_AUTO_FUNC.
//!
//! @par     Макрос <tt>tx_auto_func (func)</tt>
//! @note
//!        - @a Все переменные вызываемой функции связываются с переменными внешней функции по ссылке.
//!        - Их названия и типы @a не указываются. Указывается только тело вызываемой функции.
//!        - Эта форма использует лямбда-функции @c C++0x, поэтому при компиляции требуется <i>MSVS 2010</i>
//!          или <i>GCC не ниже версии 4.5 с ключом компиляции @c -std=c++0x или @c -std=c++11.</i>
//!        - Синоним: tx_finally
//!
//! @see     txAutoLock
//!
//! @usage @code
//!          void f1()
//!              {
//!              int x = 1;
//!              TX_AUTO_FUNC (int, x, $(x));              // Will be printed at return
//!
//!              FILE* f = fopen (__FILE__".o.txt", "w");  // Will be closed at return
//!              TX_AUTO_FUNC (FILE*, f, fclose (f));
//!
//!              fprintf (f, "start: x = %d\n", x);        // Do some job
//!              x = 2;                                    // Do some job
//!              }
//!
//!          void f2()                                     // Do the same. For C++0x only
//!              {
//!              int x = 1;
//!              tx_auto_func ($(x));                      // More simple usage
//!
//!              FILE* f = fopen (__FILE__".o.txt", "w");
//!              tx_auto_func (fclose (f));                // More simple usage
//!
//!              fprintf (f, "start: x = %d\n", x);
//!              x = 2;
//!              }
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------
//! @{

//{ C++03 version

#define  TX_AUTO_FUNC(           param_t, param, func )                  \
        _TX_AUTO_FUNC( __LINE__, param_t, param, func )

#define _TX_AUTO_FUNC( n,        param_t, param, func )                  \
        _TX_AUTO_FUN2( n,        param_t, param, func )

#define _TX_AUTO_FUN2( n,        param_t, param, func )                  \
    struct _TX_AUTO_FUNC_##n                                             \
        {                                                                \
        typedef _TX_AUTO_FUNC_##n this_t;                                \
        param_t& param;                                                  \
                                                                         \
        _TX_AUTO_FUNC_##n (param_t& __p) : param (__p) {       }         \
       ~_TX_AUTO_FUNC_##n ()                           { func; }         \
                                                                         \
        private: this_t& operator= (const this_t&)     { return *this; } \
        }                                                                \
        _TX_AUTO_FUNC_##n (param)
//}

//{ C++0x version, use MSVS 2010 or GCC v.4.5+ and -std=c++0x in command line

#define  tx_auto_func(    func )  _tx_auto_fun1 ( __LINE__, func )
#define _tx_auto_fun1( n, func )  _tx_auto_fun2 ( n,        func )
#define _tx_auto_fun2( n, func )  auto _tx_auto_func_##n = _tx_auto_func ([&]() { func; })

template <typename T>
struct _tx_auto_func_
    {
    typedef _tx_auto_func_ this_t;
    T func_;

    _tx_explicit _tx_auto_func_ (T func) : func_ (func) {}
                ~_tx_auto_func_ () { func_(); }

    private: this_t& operator= (const this_t&) { return *this; }
    };

template <typename T>
_tx_auto_func_<T> _tx_auto_func  (T   func)
    {
    return        _tx_auto_func_ <T> (func);
    }
//}

//{ Compatibility

#define TX_FINALLY( param_t, param, func )  TX_AUTO_FUNC (param_t, param, func)
#define tx_finally( func )                  tx_auto_func (func)

//}

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Замена стандартного макроса assert(), с выдачей сообщения через txMessageBox(), консоль и OutputDebugString().
//!
//! @param   cond  Условие для проверки
//!
//! @return  Не определено
//!
//!          Если условие, проверяемое assert(), истинно, то макрос ничего не делает. @n
//!          Если условие оказывается ложно, то выводится диагностическое сообщение и программа аварийно завершается.
//!
//! @warning <b>При компиляции в режиме Release (или если определен NDEBUG) assert превращается в пустой оператор.</b> @n
//!          Не надо помещать в assert() действия, которые важны для работы алгоритма!
//!
//! @note    Если условие @c cond может быть вычислено уже во время компиляции как ложное, компилятор может
//!          предупредить об этом (как о делении на 0).
//! @note    <small>See: <a href=http://lars-lab.jpl.nasa.gov/JPL_Coding_Standard_C.pdf> "JPL Institutional Coding
//!          Standard for the C Programming Language", Jet Propulsion Laboratory, California Institute of
//!          Technology, JPL DOCID D-60411, Ver. 1.0, March 3, 2009</a>, page 15.</small>
//!
//! @see     asserted, verified, verify(), TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox(),
//!          txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          assert (0 <= i && i < ARRAY_SIZE);
//!
//!          FILE* input = fopen ("a.txt", "r");
//!          assert (input);
//!
//!          // Этот вызов fgets() НЕ будет выполнен в режиме Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          // Здесь все будет правильно:
//!          bool ok = (fclose (input) == 0);
//!          assert (ok);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #undef  assert
    #define assert( cond )    _txNOP ( !(cond)? (TX_ERROR ("\a" "ВНЕЗАПНО: Логическая ошибка: "    \
                                                           "Неверно, что \"%s\"." TX_COMMA #cond), \
                                                 0/(int)!!(cond)) : 1 )
#else
    #undef  assert
    #define assert( cond )    ((void) 1)

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит диагностическое сообщение в случае нулевого или ложного результата.
//!
//! @return  Всегда 0
//!
//!          Суффиксная форма макроса assert(), не теряющая в режиме Release исполнения предиката.
//!
//! @note    <b>Предполагается, что операция в случае неуспеха возвращает 0 или false.</b> @n@n
//!          <b>При компиляции в режиме Release (или если определен NDEBUG) asserted превращается в пустое место.</b>
//!
//! @see     assert(), verify(), verified, TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox(),
//!          txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          FILE* input = fopen ("a.txt", "r"); assert (input);
//!
//!          // Этот вызов fgets() будет выполнен в любом случае:
//!          fgets (str, sizeof (str) - 1, input) asserted;
//!
//!          // Этот вызов fgets() НЕ будет выполнен в режиме Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          (fclose (input) != 0) asserted;
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define asserted          || TX_ERROR ("\a" "Обнаружен нулевой или ложный результат.")

#else
    #define asserted          || _txNOP (0)

#endif

#define verified              asserted  //!< For compatibility with assert macro

//! @cond INTERNAL
#define TX_NEEDED             asserted  //!< For compatibility with earlier releases
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выполняет команду (вычисляет выражение) и проверяет результат.
//!
//! @param   expr  Команда (выражение)
//!
//! @return  1, если выражение @p expr истинно, иначе 0.
//!
//!          Если условие, проверяемое verify(), истинно, то макрос ничего не делает. @n
//!          Если условие оказывается ложно, то выводится диагностическое сообщение и программа аварийно завершается.
//!
//! @note    Действие макроса аналогично assert(), но при компиляции в режиме Release (или если определен NDEBUG)
//!          verify @b не превращается в пустой оператор.
//!
//! @see     verified, assert(), asserted, TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox(),
//!          txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          FILE* input = verify (fopen ("a.txt", "r"));
//!
//!          // Этот вызов fgets() БУДЕТ выполнен в режиме Release:
//!          verify (fgets (str, sizeof (str) - 1, input));
//!
//!          // Здесь все тоже будет правильно:
//!          verify (fclose (input) == 0);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #undef  verify
    #define verify            assert

#else
    #undef  verify
    #define verify( expr )    ( expr )

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит развернутое диагностическое сообщение.
//!
//! @param   msg  Сообщение с произвольным количеством параметров в стиле функции @c printf().
//!
//! @note    @c GCC в режиме строгого соответствия стандарту ANSI (с ключом командной строки <tt>-ansi</tt>) и
//!          Microsoft Visual Studio версий 6 и 2003 не поддерживают макросы с переменным числом параметров.
//!          Поэтому, если параметров несколько, они разделяются @b _ (@ref _ "символом подчеркивания",
//!          переопределенным в запятую) или символом TX_COMMA, вместо настоящей запятой, так как TX_ERROR @d макрос. @n
//!          Если в проекте используются библиотеки <a href=http://boost.org><tt>boost</tt></a>, то их надо включать
//!          @b до @c TXLib.h и вместо символа подчеркивания пользоваться TX_COMMA, так как @c boost использует
//!          символ подчеркивания как свой собственный служебный макрос в модуле @c boost::preprocessor, @strike
//!          где творится дефайновый адЪ. @endstrike
//!
//! @note    Этот макрос может распечатывать стек вызовов функций в консоли. По этому поводу см. замечания к функции
//!          txStackBackTrace() и раздел @ref TXLibSetup "Установка библиотеки", п.4.
//!
//! @return  Всегда false
//!
//! @see     _, TX_COMMA, assert(), asserted, verify(), verified, TX_DEBUG_ERROR(), txOutputDebugPrintf(),
//!          txMessageBox(), txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          TX_ERROR ("Не смог прочитать 'Войну и мир'. Отмазка %d: не нашел '%s'", reasonNum, fileName);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

// Variadic macros not supported in Strict ANSI mode and in MSVC prior to MSVC 8 (2005)

#if defined (__STRICT_ANSI__) || defined (_MSC_VER) && (_MSC_VER < 1400)
    #define TX_ERROR( msg )   _txError (__FILE__, __LINE__, __TX_FUNCTION__, 0, msg)

#else
    #define TX_ERROR( ... )   _txError (__FILE__, __LINE__, __TX_FUNCTION__, 0, ##__VA_ARGS__)

#endif

//! @cond INTERNAL
#define TX_THROW              TX_ERROR  //!< For compatibility with earlier TXLib releases
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Выводит развернутое диагностическое сообщение в отладочном режиме.
//!
//!          Описание см. в TX_ERROR.
//!
//! @note    В режиме Release этот макрос не выводит ничего.
//!
//! @see     _, TX_COMMA, assert(), asserted, verify(), verified, TX_ERROR(), txOutputDebugPrintf(),
//!          txMessageBox(), txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          TX_DEBUG_ERROR ("Так и не смог прочитать 'Войну и мир'. Отмазка %d: потерял '%s'", reasonNum, fileName);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define TX_DEBUG_ERROR    TX_ERROR

#else
    #define TX_DEBUG_ERROR(m) ((void) 0)

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Распечатывает дамп области памяти в консоли.
//!
//! @param   address  Адрес начала распечатки.
//! @param   name     Название распечатки (усекается до 8 символов).
//!
//! @note    Распечатывается область памяти размером 256 байт.
//!
//! @see     txStackBackTrace(), TX_ERROR(), TX_DEBUG_ERROR()
//!
//! @usage @code
//!          const char text[] = "Каждому лектору - в портфель по вектору";
//!          txDump (text);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

void txDump (const void* address, const char name[] = "txDump()");

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Распечатывает текущий стек вызовов функций в консоли.
//!
//! @warning Для корректной работы этой функкции требуются модули, которые нужно установить (скопировать)
//!          в папку Windows. См. раздел @ref TXLibSetup "Установка библиотеки", п.4.
//!
//! @note    Для наиболее корректной работы этой функции полностью отключайте оптимизацию при компиляции. Например,
//!          для компилятора GCC @c g++ - с помощью ключа командной строки @c -O0. Разные среды программирования
//!          позволяют задать эти ключи по-разному, например, в CodeBlocks через Главное меню - Settings -
//!          Compiler - (Global Compiler Settings) - (Compiler Settings) - Other Options.
//!
//! @see     txDump(), TX_ERROR(), TX_DEBUG_ERROR()
//!
//! @usage @code
//!          void Recursion()  // http://google.ru/search?q=%D1%80%D0%B5%D0%BA%D1%83%D1%80%D1%81%D0%B8%D1%8F
//!              {
//!              txStackBackTrace();
//!
//!              printf ("Press any key...\n");
//!              _getch();
//!
//!              Recursion();
//!              }
//! @endcode
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define txStackBackTrace()    _txStackBackTrace (__FILE__, __LINE__, __TX_FUNCTION__, true);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Макрос, позволяющий передать переменное число параметров в какой-либо другой макрос.
//!
//! @note    <b>Символ подчеркивания и символ TX_COMMA просто переопределяются в запятую.</b>
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR()
//!
//! @usage @code
//!          TX_ERROR ("Слишком умный абзац: роман 'Война и мир', файл '%s', строка %d" _ fileName _ lineNum);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------
//! @{

#define _                     ,
#define TX_COMMA              ,  //!< Синоним макроса _ (@ref _ "символ подчеркивания")

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя и версия текущего компилятора
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if   defined (__GNUC__)
    #define __TX_COMPILER__   "GNU g++ "            TX_QUOTE (__GNUC__)       "."  \
                                                    TX_QUOTE (__GNUC_MINOR__) "."  \
                                                    TX_QUOTE (__GNUC_PATCHLEVEL__) \
                              ", std="              TX_QUOTE (__cplusplus)
#elif defined (_MSC_VER)
    #define __TX_COMPILER__   "MSVS "               TX_QUOTE (_MSC_VER)            \
                              ", std="              TX_QUOTE (__cplusplus)

#elif defined (__INTEL_COMPILER)
    #define __TX_COMPILER__   "Intel C++ "          TX_QUOTE (__INTEL_COMPILER)    \
                              ", std="              TX_QUOTE (__cplusplus)

#else
    #define __TX_COMPILER__   "Unknown C++, std="   TX_QUOTE (__cplusplus)

#endif

//! @cond INTERNAL

#define  TX_QUOTE( sym )  _TX_QUOTE (sym)
#define _TX_QUOTE( sym )  #sym

//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Макрос, раскрывающийся в имя файла и номер строки файла, где он встретился.
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define __TX_FILELINE__       __FILE__ " (" TX_QUOTE (__LINE__) ")"

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя текущей функции
//!
//! @warning Если определение имени функции не поддерживается компилятором, то __TX_FUNCTION__ раскрывается в имя
//!          исходного файла и номер строки.
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if defined (__GNUC__)
    #define __TX_FUNCTION__   __PRETTY_FUNCTION__

#elif defined (__FUNCSIG__)
    #define __TX_FUNCTION__   __FUNCSIG__

#elif defined (__FUNCTION__)
    #define __TX_FUNCTION__   __FUNCTION__

#elif defined (__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)
    #define __TX_FUNCTION__   __FUNCTION__

#elif defined (__BORLANDC__) && (__BORLANDC__ >= 0x550)
    #define __TX_FUNCTION__   __FUNC__

#elif defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
    #define __TX_FUNCTION__   __func__
    
#elif defined (__PYTHON__)
    #error No Python. No. Using parseltongue languages can lead you to Slytherin.

#else
    #define __TX_FUNCTION__   "(" __TX_FILELINE__ ")"

#endif

#if !defined (__func__) && defined (__FUNCTION__)
    #define __func__          __FUNCTION__

#endif
    
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя режима сборки
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if   !defined (NDEBUG) &&  defined (_DEBUG)
    #define _TX_BUILDMODE     "DEBUG"

#elif !defined (NDEBUG) && !defined (_DEBUG)
    #define _TX_BUILDMODE     "Debug"

#elif  defined (NDEBUG)
    #define _TX_BUILDMODE     "Release"
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Имя модуля TXLib, входит в диагностические сообщения.
//!
//! @note    Можно переопределять до включения файла TXLib.h.
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (_TX_MODULE)
    #define   _TX_MODULE      "TXLib"
#endif

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Back-hole (I hope, not an ass-hole:) of the library)
//! @name    Очень служебные функции
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Устанавливает альтернативную функцию обработки оконных сообщений Windows (оконную функцию) для окна
//!          TXLib.
//!
//! @param   wndProc  Новая оконная функция окна TXLib. @n
//!                   Если NULL, то текущая оконная функция удаляется и устанавливается стандартная.
//!
//! @return  Адрес предыдущей оконной функции для окна TXLib.
//!
//!          Заданная оконная функция будет вызываться @b до обработки события средствами TXLib.
//!          Она должна быть функцией со следующим прототипом:
//! @code
//!          LRESULT CALLBACK NewWndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam);
//! @endcode
//!
//! @warning Оконная функция будет вызываться из вспомогательного (второго) потока, создаваемого @ref
//!          txCreateWindow(). Это @b не тот же самый поток, в котором выполняется main(). В связи с этим будьте
//!          внимательны при работе с глобальными переменными или их аналогами, т.к. может возникнуть "гонка
//!          потоков" (race condition).
//!
//! @warning Если оконная функция вернет значение, не равное 0, то стандартная обработка сообщений средствами TXLib
//!          @b не будет произведена. Из-за этого, возможно, окно даже не сможет нормально закрыться. Придется
//!          завершать программу с помощью Alt-Ctrl-Del из диспетчера задач, или из более продвинутого диспетчера
//!          <a href=http://technet.microsoft.com/en-us/sysinternals/bb896653.aspx> Process Explorer</a>. Если Вы
//!          берете на себя обработку оконных сообщений, делайте ее по правилам Win32 (см. MSDN), включая вызов
//!          DefWindowProc().
//!
//! @note    Полностью поменять оконную функцию можно с помощью функций SetWindowLong или SetWindowLongPtr:
//! @code
//!          WNDPROC OldWndProc = (WNDPROC) SetWindowLongPtr (txWindow(), GWL_WNDPROC, (LONG_PTR) NewWndProc);
//! @endcode
//!          При этом надо обязательно всегда вызывать старую оконную функцию с помощью CallWindowProc, (см. MSDN),
//!          иначе последствия будут такими же плачевными, как описаны выше.
//!
//! @see     txCreateWindow(), txDialog, txInputBox()
//!
//! @usage @code
//!          LRESULT CALLBACK MyWndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam);
//!
//!          int main()
//!              {
//!              txCreateWindow (GetSystemMetrics (SM_CXSCREEN) / 4, GetSystemMetrics (SM_CYSCREEN) / 4);
//!
//!              txSetWindowsHook (MyWndProc);
//!
//!              txDrawText (0, 0, txGetExtentX(), txGetExtentY(), "MOV txWindow, eax [please]");
//!
//!              return 0;
//!              }
//!
//!          LRESULT CALLBACK MyWndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam)
//!              {
//!              if (message == WM_MOVE) txMessageBox ("  I like to MOVe it, MOVe it", "TXLib 2 Real", MB_ICONINFORMATION);
//!
//!              static int i = 0;
//!              if (i++ % 10 == 0) printf ("\b" "%c", "-\\|/" [i/10 % 4]);  // Прропппеллллерррр
//!
//!              return 0;  // Продолжить обработку сообщения средствами TXLib
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

WNDPROC txSetWindowsHook (WNDPROC wndProc = NULL);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Блокировка холста (контекста рисования).
//!
//! @param   wait  Ожидать конца перерисовки окна вспомогательным потоком
//!
//! @return  Состояние блокировки
//!
//!          Перед вызовом любых функций Win32 GDI необходимо заблокировать холст функцией txLock() и затем
//!          разблокировать с помощью txUnlock(). Это связано с тем, что обновление содержимого окна (для тех, кто
//!          знает Win32: обработка сообщения WM_PAINT) в библиотеке TXLib происходит в отдельном вспомогательном
//!          потоке. Надолго блокировать его нельзя - при заблокированном потоке окно не обновляется.
//!
//!          txLock() использует EnterCriticalSection(), и физически приостанавливает поток, обновляющий окно, так
//!          что надолго блокировать нельзя. Иначе тормозится обработка оконных сообщений, окно перестает
//!          реагировать на действия пользователя и перерисовываться. Нельзя также вызывать txSleep() или Sleep()
//!          при заблокированном потоке.
//!
//!          txLock() / txUnlock() - это низкоуровневый механизм. Он отличается от более простого высокоуровневого
//!          механизма txBegin() / txEnd() / txUpdateWindow(), который не приостанавливает поток, а просто
//!          отключает принудительное постоянное обновление окна.
//!
//! @see     txDC(), txLock(), txUnlock(), txGDI()
//!
//! @usage   См. исходный текст функций _txCanvas_OnPAINT() и _txConsole_Draw() в TXLib.h.
//}----------------------------------------------------------------------------------------------------------------

bool txLock (bool wait = true);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Разблокировка холста
//!
//! @return  Состояние блокировки (всегда false).
//!
//!          Более подробно см. в описании txLock().
//!
//! @see     txDC(), txLock(), txGDI()
//!
//! @usage   См. исходный текст функций _txCanvas_OnPAINT() и _txConsole_Draw() в TXLib.h.
//}----------------------------------------------------------------------------------------------------------------
//! @{

bool txUnlock();

//! @cond INTERNAL
template <typename T> inline T txUnlock (T value);
//! @endcond

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Вызов функции Win32 GDI с автоматической блокировкой и разблокировкой.
//!
//! @param   command  Функция GDI (возможно, возвращающая значение)
//! @param   dc       Дескриптор контекста рисования (холста) для вызова функции
//!
//! @return  Значение, возвращаемое вызываемой функцией GDI.
//!
//! @note    Если параметр dc соответствует основному холсту TXLib (совпадает с возвращаемым значением txDC()),
//!          то на время выполнения функции GDI поток, обновляющий окно TXLib, блокируется. @n
//!
//! @note    Если в вызове функции GDI используются запятые, то используйте двойные скобки, чтобы получился один
//!          параметр, так как txGDI() это все же макрос.
//!
//! @see     txDC(), txLock(), txUnlock()
//!
//! @usage @code
//!          txGDI (( Rectangle (txDC(), x1, y1, x2, y2) ));  // Не забудьте про две ((ДВЕ)) скобки
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define txGDI( command, dc )  ( ((dc) == txDC())? txUnlock ( (txLock(), (command)) ) : (command) )

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Tune-up constants and variables
//! @name    Настроечные константы и переменные
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Имя лог-файла TXLib
//!
//!          В эту строку надо скопировать нужное имя лог-файла.
//!
//!          По умолчанию файл создается во время ошибки в одной папке с запущенной программой, имеет то же имя, что
//!          и файл программы, с добавлением расширения @c ".log".
//!
//! @note    Устанавливать имя лог-файла надо в начале работы программы, до появления первой ошибки.
//}----------------------------------------------------------------------------------------------------------------

char _txLogName[MAX_PATH] = "";

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Запрет ранней инициализации TXLib
//!
//!          Если константа определена с помощью \#define @a до включения TXLib.h в программу, ранняя инициализация
//!          (до запуска функции @c main) @b не проводится.
//!
//! @note    Ранняя инициализация включает:
//!        - Открытие окна консоли,
//!        - Установку кодовой страницы _TX_CP (1251) консоли для поддержки русского языка,
//!        - Установку русской локали стандартной библиотеки,
//!        - Переинициализация библиотек stdio и iostream на случай, если приложение не скомпоновано как консольное
//!          и библиотеки остались неинициализированы,
//!        - Перехват системных сигналов (деление на 0, обращение по неверному адресу и т.д.),
//!        - Перехват необработанных исключений,
//!        - Смена заголовка консольного окна,
//!        - Установка режима паузы по завершении программы, чтобы окно закрывалось не сразу,
//!        - Подавление паузы при запуске из сред программирования, заставляющей нажимать на клавишу два раза. @nn
//!
//! @note    Если ранняя инициализация запрещена, но в EXE-файле создается окно TXLib с помощью txCreateWindow(),
//!          то библиотека все равно будет инициализирована. В @b DLL ранняя инициализация никогда @b не проводится. @nn
//!
//! @note    Ранняя инициализация не потокобезопасна (not thread-safe).
//!
//! @see     txCreateWindow(), _TX_ALLOW_KILL_PARENT, _TX_WAITABLE_PARENTS, _txConsoleMode
//!
//! @usage @code
//!          #define _TX_NOINIT
//!          #include "TXLib.h"
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if  defined  (_TX_NOINIT)

    #undef     _TX_NOINIT
    #define    _TX_NOINIT                 1

#else

    #define    _TX_NOINIT                 0

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Режим отображения консольного окна. Допустимы любые флаги функции ShowWindow.
//!
//!          По умолчанию: @c SW_HIDE @d Скрывать консольное окно.
//!
//! @note    Переменная устанавливается @b до открытия окна библиотеки.
//!
//! @see     _TX_NOINIT
//!
//! @usage @code
//!          _txConsoleMode = SW_HIDE;  // Всегда скрывать консольное окно
//!          txCreateWindow (800, 600);
//!
//!          _txConsoleMode = SW_SHOW;  // Всегда показывать консольное окно
//!          txCreateWindow (800, 600);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int            _txConsoleMode             = SW_HIDE;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Стиль графического окна библиотеки.
//!
//! @note
//!        - Переменная устанавливается @b до открытия окна библиотеки.
//!
//! @usage @code
//!          _txWindowStyle &= ~WS_CAPTION; // FullScreen: окно без заголовка, размером с экран
//!          txCreateWindow (GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN));
//!
//!          printf ("Закройте меня через Alt+F4\n");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int            _txWindowStyle             = WS_POPUP | WS_BORDER | WS_CAPTION | WS_SYSMENU;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Шрифт консоли
//! @note    Переменная устанавливается @b до открытия окна библиотеки.
//}----------------------------------------------------------------------------------------------------------------

const char*    _txConsoleFont             = "Lucida Console";

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал мигания курсора консоли (мс)
//}----------------------------------------------------------------------------------------------------------------

unsigned       _txCursorBlinkInterval     = 500;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Интервал обновления холста (мс)
//! @note    Переменная устанавливается @b до открытия окна библиотеки.
//}----------------------------------------------------------------------------------------------------------------

unsigned       _txWindowUpdateInterval    = 25;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Таймаут операций ожидания (мс)
//}----------------------------------------------------------------------------------------------------------------

#if !defined (TX_TRACE)
    const int  _TX_TIMEOUT                = 1000

#else
    const int  _TX_TIMEOUT                = 5000

#endif

#if  defined  (_TX_USE_DEVPARTNER)
    * 10
#endif
    ;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Размеры внутренних статических строковых буферов TXLib и стеков потоков
//}----------------------------------------------------------------------------------------------------------------

const unsigned _TX_BUFSIZE                =  1024,
               _TX_BIGBUFSIZE             = _TX_BUFSIZE *  2,
               _TX_HUGEBUFSIZE            = _TX_BUFSIZE * 20,

               _TX_STACKSIZE              = 64 * 1024;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Список запускающих программ, которые ждут нажатия клавиши после завершения процесса TXLib.
//!
//!          Если программа перечислена в списке и TXLib запущена из нее, то при завершении TXLib указанная
//!          программа будет закрыта. (Это произойдет, если не открыто графическое окно TXLib, а есть только окно
//!          консоли.)
//!
//!          Программы разделяются пробелом или запятой. Допускается указание родителя запускающей программы, после
//!          двоеточия.
//!
//!          Может задаваться перед включением TXLib.h в программу.
//!
//! @see     _TX_ALLOW_KILL_PARENT, _TX_NOINIT
//}----------------------------------------------------------------------------------------------------------------

#if !defined  (_TX_WAITABLE_PARENTS)
    #define    _TX_WAITABLE_PARENTS       "cmd.exe:devenv.exe, "                    /* MSVS 2003+    */ \
                                          "vcspawn.exe:msdev.exe, "                 /* MSVS 6        */ \
                                          "cb_console_runner.exe:codeblocks.exe, "  /* CodeBlocks 8+ */ \
                                          "cmd.exe:console_runner.exe, "            /* CodeBlocks 1  */ \
                                          "starter.exe:eclipse.exe, "               /* Eclipse 4     */ \
                                          "starter.exe:javaw.exe, "                 /* Eclipse 3     */ \
                                          "consolepauser.exe:devcpp.exe"            /* Dev-Cpp       */

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Разрешать принудительное завершение вызывающих программ, ждущих нажатия клавиш после завершения TXLib.
//!
//!          Иначе отменяется собственная пауза до нажатия клавиши, встроенная в TXLib, и пусть тогда паузу делает
//!          вызывающий процесс.
//!
//!          Список вызывающих программ, которые могут делать такую паузу, задается в _TX_WAITABLE_PARENTS.
//!
//!          Может задаваться перед включением TXLib.h в программу.
//!
//!          См. также определение этой константы в файле TXLib.h.
//!
//! @see     _TX_WAITABLE_PARENTS, _TX_NOINIT
//!
//! @usage @code
//!          #define _TX_ALLOW_KILL_PARENT false
//!          #include "TXLib.h"
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#if !defined (_TX_ALLOW_KILL_PARENT)            // DISCLAIMER: Я не призываю к убийству родителей!
#define       _TX_ALLOW_KILL_PARENT       true  //             Это технический термин.
#endif                                          //             г-дам юристам привет.

#endif

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Internal diagnostics
//! @name    Внутренняя диагностика
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Включает/отключает внутреннюю трассировку исполнения кода библиотеки.
//!
//!          Трассировка идет через макрос TX_TRACE, который подставляется перед каждым оператором (statement).
//!          По умолчанию трассировка выключена.
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(), ее вывод можно перехватить
//!          утилитами-логгерами, например, <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DbgView</a>. Это можно изменить, переопределив макрос TX_TRACE до включения TXLib.h в программу.
//!
//! @warning Трассировка @b очень тормозит выполнение программы, особенно при отладке в Microsoft Visual Studio.
//!          В этом случае лучше пользоваться DbgView (см. выше) и запускать отлаживаемую программу отдельно,
//!          а не из-под отладчика Visual Studio.
//!
//!          _TX_ALLOW_TRACE и TX_TRACE задаются перед включением TXLib.h в программу.
//!
//! @usage @code
//!          // Для просмотра трассы запустить DbgView до запуска программы!
//!
//!          #define  _TX_ALLOW_TRACE    // Трассировать только входы в функции.
//!          #include "TXLib.h"
//!
//!          #define  _TX_ALLOW_TRACE 1  // Трассировать все строки TXLib.
//!          #include "TXLib.h"
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define _TX_ALLOW_TRACE
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   Трассирует исполнение кода через OutputDebugString().
//!
//!          По умолчанию трассировка ведется через функцию OutputDebugString(), ее вывод можно перехватить
//!          утилитами-логгерами, например, <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DbgView</a>. Для "раскраски" лога есть файл <tt>TX\Dev\DbgView.ini,</tt> его надо загрузить в DbgView
//!          через меню Edit/Filter/Load (Ctrl+L).
//!
//!          С помощью TX_TRACE можно трассировать код самой библиотеки TXLib. Для этого надо разрешить трассировку
//!          TXLib, определив макрос _TX_ALLOW_TRACE перед включением файла TXLib.h в программу. По умолчанию
//!          трассировка TXLib выключена.
//!
//!          TX_TRACE можно переопределить в свой код. Тогда, если трассировка библиотеки разрешена, он будет
//!          вызываться почти перед каждой исполняемой строкой TXLib. Может быть, это кому-нибудь будет интересно.
//!
//! @usage @code
//!          int main()
//!              {
//!              ...
//!              TX_TRACE;  // Через DbgView увидим имя файла и номер выполняемой строки
//!              ...
//!              }
//! @endcode
//! @code
//!          #define  TX_TRACE  printf (__TX_FILELINE__ "\n");
//!          #include "TXLib.h"
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------
//! @{

#ifdef FOR_DOXYGEN_ONLY
#define       TX_TRACE
#endif

#if !defined (TX_TRACE)
    #define   TX_TRACE  { if (_txLocCur.trace) _txTrace (__FILE__, __LINE__, __TX_FUNCTION__); }
#endif

void _txTrace (const char file[], int line, const char func[], const char msg[] = NULL, ...);

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @{
//! @cond INTERNAL

namespace Win32
    {
    struct SYMBOL_INFO;
    struct IMAGEHLP_LINE64;
    }

struct _txLoc
    {
    const char*   file;
    int           line;
    const char*   func;

    int           inTX;   // We are inside one of TXLib functions
    int           trace;  // Internal TX trace level, when enabled by _TX_ALLOW_TRACE

    const _txLoc* prev;   // Caller's location
    };

extern _txLoc _tx_thread  _txLocCur;

struct _txFuncEntry
    {
    const _txLoc loc;

    _txFuncEntry() : loc (_txLocCur) { _txLocCur.inTX++; _txLocCur.prev = &loc; }
   ~_txFuncEntry()      { _txLocCur = loc;                                      }
    };

#define _txLocCurSet()  { _txLocCur.file = __FILE__; _txLocCur.line = __LINE__; _txLocCur.func = __TX_FUNCTION__; }

//-----------------------------------------------------------------------------------------------------------------

#if defined (_TX_ALLOW_TRACE)

    #if !defined ($1) && (_TX_ALLOW_TRACE +0 >= 0)
    #define       $1    _txFuncEntry __txFuncEntry; { _txLocCurSet(); TX_TRACE;      }
    #endif

    #if !defined ($)  && (_TX_ALLOW_TRACE +0 >= 1)
    #define       $                                 { _txLocCurSet(); TX_TRACE;      }
    #endif

    #define       $$                                { __txFuncEntry.~_txFuncEntry(); }

#elif defined (_DEBUG)

    #if !defined ($1)
    #define       $1    _txFuncEntry __txFuncEntry; { _txLocCurSet();                }
    #endif

    #if !defined ($)
    #define       $                                 { _txLocCurSet();                }
    #endif

    #define       $$                                { __txFuncEntry.~_txFuncEntry(); }

#endif

#if !defined ($1)
    #define   $1        ;
    #endif

#if !defined ($)
    #define   $         ;
    #endif

#if !defined ($$)
    #define   $$        ;
    #endif

//! @endcond
//! @}
//}----------------------------------------------------------------------------------------------------------------

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Sweet critical section blocking: txAutoLock class
//=================================================================================================================

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Service
//! @brief   Класс для автоматической блокировки и разблокировки критической секции.
//!
//!          Начиная с <a href=http://progbook.ru/2008/08/03/sovremennoe-proektirovanie-na-c-andrejj.html>
//!          Александреску,</a> его пишут все и он прост, как пробка: в конструкторе @d EnterCriticalSection(),
//!          в деструкторе @d LeaveCriticalSection(). Это @c RAII в чистом виде: вы никогда не забудете разблочить
//!          секцию and your thread show will always go on.
//!
//!          Некоторые добавления: есть возможность вызвать TryEnterCriticalSection(), и, если она не заблочила
//!          секцию, деструктор ее не разблочивает. Есть оператор для проверки, заблочилась ли секция или нет
//!          (см. конструкторы класса и оператор @c bool).
//!
//! @note    Класс не инициализирует и не удаляет критическую секцию. Только синхронизирует. Остальное сами-сами :)
//!
//! @see     txLock(), txUnlock(), txGDI()
//}----------------------------------------------------------------------------------------------------------------

//! @cond _OFF
extern CRITICAL_SECTION _txCanvas_LockBackBuf;
//! @endcond

class txAutoLock
    {
    public:

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Конструктор, блокирует критическую секцию
//!
//! @param   cs         Критическая секция для блокировки
//! @param   mandatory  Если @c true,  то блокировать обязательно (EnterCriticalSection). @n
//!                     Если @c false, то только пытаться блокировать (TryEnterCriticalSection).
//! @usage @code
//!          CRITICAL_SECTION cs = {};         // This is not a Counter Strike
//!
//!          void foo()
//!              {
//!              txAutoLock lock (&cs);        // Здесь вызовется EnterCriticalSection()
//!              ...
//!              }                             // а здесь LeaveCriticalsection()
//!
//!          void bar()
//!              {
//!              txAutoLock lock (&cs, false); // TryEnterCriticalSection()
//!              if (!lock) return;            // ну не смогла
//!              ...
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    _tx_explicit txAutoLock (CRITICAL_SECTION* cs, bool mandatory = true) :
        cs_ (cs)
        {
$1      if (!cs_) return;

        if (mandatory) { $    EnterCriticalSection (cs_);                   }
        else           { $ TryEnterCriticalSection (cs_)? 0 : (cs_ = NULL); }
        }

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Конструктор для блокировки холста TXLib
//!
//! @param   mandatory  Если @c true,  то блокировать @b обязательно,     как в @ref txLock (true). @n
//!                     Если @c false, то только @b пытаться блокировать, как в @ref txLock (false).
//! @usage @code
//!          void foobar()
//!              {
//!              txAutoLock lock;      // Здесь вызовется txLock()
//!              ...
//!              }                     // а здесь txUnlock()
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    _tx_explicit txAutoLock (bool mandatory = true) :
        cs_ (NULL)
        {
$1      new (this) txAutoLock (&_txCanvas_LockBackBuf, mandatory);
        }

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Деструктор, разблокирует секцию
//}----------------------------------------------------------------------------------------------------------------

   ~txAutoLock()
        {
$1      if (!cs_) return;
$       LeaveCriticalSection (cs_); cs_ = NULL;
        }

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Позволяет проверить, заблокировалась секция или нет
//! @usage   См. в txAutoLock::AutoLock (CRITICAL_SECTION&, bool)
//}----------------------------------------------------------------------------------------------------------------

    operator bool () const
        {
$1      return (cs_ != NULL);
        }

//{----------------------------------------------------------------------------------------------------------------
//! Блокируемая критическая секция
//}----------------------------------------------------------------------------------------------------------------

//  private:
    CRITICAL_SECTION* cs_;

//{----------------------------------------------------------------------------------------------------------------
//! Такой вот копирайт.
//}----------------------------------------------------------------------------------------------------------------
//! @{

    private:
    txAutoLock             (const txAutoLock&);
    txAutoLock& operator = (const txAutoLock&);

//! @}

    };

//}
//=================================================================================================================

//=================================================================================================================
//{          Dialogs: txDialog class
//! @name    Работа с диалоговыми окнами. Класс txDialog
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Базовый класс для диалоговых окон.
//!
//!          Для создания своего диалогового окна нужно:
//!           -# Унаследовать свой класс из этого базового класса;
//!           -# Задать состав и расположение элементов управления (контролов) функцией txDialog::setLayout(), или
//!              указать карту расположения при показе диалогового окна функцией txDialog::dialogBox();
//!           -# Переопределить в своем классе функцию txDialog::dialogProc() для обработки событий диалогового
//!              окна или построить карту реакций на команды с помощью макросов TX_BEGIN_MESSAGE_MAP(),
//!              TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @note    Этот класс предоставляет только базовую функциональность диалоговых окон и только базовые сведения
//!          по ним. Для его полноценного использования нужно знать, как работать с диалоговыми окнами в Windows.
//!
//! @see     txDialog::setLayout(), txDialog::dialogProc(), txDialog::Layout, TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

struct txDialog
    {

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Константы для задания типа контрола.
//!
//!          Вместо констант можно использовать названия оконных классов, преобразованные к типу txDialog::CONTROL.
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

    public:
    enum CONTROL
        {
        DIALOG    = 0x00000000,                  //!< Начало описания диалога
        BUTTON    = 0xFFFF0080,                  //!< Кнопка
        EDIT      = 0xFFFF0081,                  //!< Редактируемый текст
        STATIC    = 0xFFFF0082,                  //!< Нередактируемый элемент (текст, картинка и т.д.)
        LISTBOX   = 0xFFFF0083,                  //!< Список с прокруткой
        SCROLLBAR = 0xFFFF0084,                  //!< Полоса прокрутки
        COMBOBOX  = 0xFFFF0085,                  //!< Комбинированный список
        END       = 0x00000000                   //!< Конец описания диалога
        };

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Класс для описания элемента диалогового окна (контрола)
//!
//!          Массив таких структур задает описание макета диалогового окна. Это описание похоже на задание диалога
//!          в ресурсном скрипте (.rc):
//!
//!           - Нулевой элемент описывает диалоговое окно в целом
//!           - Остальные элементы описывают контролы (порядок задания параметров контрола похож на порядок
//!             параметров в ресурсном скрипте)
//!           - Последний элемент - txDialog::END или {NULL}
//!
//! @see     txDialog::setLayout(), txDialog::dialogBox(), txDialog::dialogProc()
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    public:
    struct Layout
        {
        CONTROL     wndclass;                    //!< Тип контрола
        const char* caption;                     //!< Название или текст
        WORD        id;                          //!< Идентификатор контрола
        short        x;                          //!< Координата верхнего левого угла
        short        y;                          //!< Координата нижнего правого угла
        short       sx;                          //!< Размер по X
        short       sy;                          //!< Размер по Y
        DWORD       style;                       //!< Стиль контрола

        const char* font;                        //!< Шрифт диалогового окна
        WORD        fontsize;                    //!< Размер шрифта диалогового окна
        };

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Конструктор.
//!
//! @see     txDialog::txDialog (const txDialog::Layout*)
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    public:
    txDialog();

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Конструктор.
//!
//! @param   layout  Макет диалогового окна
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    _tx_explicit txDialog (const Layout* layout);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Деструктор.
//}----------------------------------------------------------------------------------------------------------------

    virtual ~txDialog() {};

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Устанавливает текущий макет диалогового окна.
//!
//! @param   layout  Макет диалогового окна
//!
//! @return  Предыдущий макет.
//!
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    const Layout* setLayout (const Layout *layout);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Функция обработки сообщений диалогового окна.
//!
//! @param   _wnd     Дескриптор
//! @param   _msg     Номер сообщения
//! @param   _wParam  1-й параметр сообщения (WORD)
//! @param   _lParam  2-й параметр сообщения (DWORD)
//!
//! @return  В большинстве случаев false, детальнее см. DialogProc в <a href=msdn.com>MSDN</a>.
//!
//!          Эту функцию надо переопределить для обработки событий окна, или построить ее с помощью макросов
//!          TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @see     txDialog::dialogBox(), TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//!
//! @param   layout   Макет диалогового окна. @n
//!                   Если не указан - используется значение, заданное txDialog::setLayout() или конструктором
//!                   txDialog::txDialog (const txDialog::Layout*).
//! @param   bufsize  Размер буфера для создания шаблона диалога (если не указан - размер по умолчанию)
//!
//! @return  Значение, указанное в функции EndDialog(). @n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была запущена txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    ptrdiff_t dialogBox (const Layout* layout = NULL, size_t bufsize = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Запускает диалоговое окно.
//!
//! @param   resource  Идентификатор диалогового ресурса
//!
//! @return  Значение, указанное в функции EndDialog(). @n
//!          По умолчанию - адрес объекта <i>(this),</i> для которого была запущена txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc()
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    ptrdiff_t dialogBox (WORD resource);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   Закрытые конструктор копирования и оператор присваивания.
//}----------------------------------------------------------------------------------------------------------------

    private:
    txDialog (const txDialog&);
    txDialog& operator = (const txDialog&);

//{----------------------------------------------------------------------------------------------------------------
//! Настоящая диалоговая функция (не txDialog::dialogProc(), т.к. функция окна in32 должна быть статической).
//}----------------------------------------------------------------------------------------------------------------

    private:
    static ptrdiff_t CALLBACK dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//{----------------------------------------------------------------------------------------------------------------
//! Текущий макет диалога.
//}----------------------------------------------------------------------------------------------------------------

    private:
    const Layout* layout_;
    };

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Dialogs: Message Map macros
//! @name    Макросы для построения статической карты сообщений (Message Map)
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Заголовок карты сообщений (Message Map).
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_BEGIN_MESSAGE_MAP()                                                                 \
    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) _tx_override \
        {                                                                                      \
        (void)_wnd; (void)_msg; (void)_wParam; (void)_lParam;                                  \
                                                                                               \
        switch (_msg)                                                                          \
            {                                                                                  \
            case WM_NULL:

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Заголовок обработчика сообщения (Message handler) карты сообщений.
//!
//! @param   id  Идентификатор сообщения
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_HANDLE( id )                                                            \
            break;                                                                 \
            case (id):

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Начало карты команд (Command map) в карте сообщений.
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_COMMAND_MAP                                                             \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        if (_msg == WM_COMMAND) switch (LOWORD (_wParam))                          \
            {                                                                      \
            case 0:

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Завершитель карты сообщений.
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          Cм. реализацию функции txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_END_MESSAGE_MAP                                                         \
            default: break;                                                        \
            }                                                                      \
                                                                                   \
        return FALSE;                                                              \
        }

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Dialogs: txDialog example: txInputBox()
//! @name    Пример использования класса диалога: функция txInputBox()
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   Ввод строки в отдельном окне.
//!
//! @param   text     Текст с вопросом
//! @param   caption  Заголовок окна
//! @param   input    Значение строки по умолчанию
//!
//! @return  Введенная строка (статическая переменная функции).
//!
//! @warning Возвращаемая строка - статическая, и обновляется при каждом вызове функции. Если txInputBox() будет
//!          вызываться несколько раз, то для сохранения строки ее необходимо копировать в другую строку при помощи
//!          <i>strcpy()</i>.
//!
//! @see     txDialog, TX_BEGIN_MESSAGE_MAP, TX_BEGIN_COMMAND_MAP, TX_HANDLE, TX_END_MESSAGE_MAP
//!
//! @usage @code
//!          const char* name = txInputBox ("So what's ur name?!?!", "System", "Sorry I'm Vasya Pupkin");
//!          txMessageBox (name, "Aaand nooowww.. the winner iiis...");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

const char* txInputBox (const char* text = NULL, const char* caption = NULL, const char* input = NULL);

const char* txInputBox (const char* text, const char* caption, const char* input)
    {
    //-------------------------------------------------------------------------------------------------------------
    // Если не указаны параметры, приходится использовать хоть какие-то надписи.
    // txGetModuleFileName() - имя EXE-файла, на случай, если кое-кто поленился задать название.
    //-------------------------------------------------------------------------------------------------------------

    if (!text)    text    = "Введите строку:";
    if (!caption) caption = txGetModuleFileName (false);
    if (!input)   input   = "";

    //-------------------------------------------------------------------------------------------------------------
    // Идентификаторы элементов диалога. Они требуются в GetDlgItemText().
    // Если диалог строится не вручную, а редактором ресурсов, то они задаются в нем автоматически.
    // У нас же тут - хардкор стайл, к сожалению. Причина в том, что у разных сред программирования разные редакторы
    // ресурсов и системы сборки. Поэтому для независимости от них все будет строиться на этапе выполнения,
    // динамически. Вы еще гляньте, как это реализовано в txDialog::dialogBox() и функциях _tx_DLGTEMPLATE_()... О_о
    //-------------------------------------------------------------------------------------------------------------

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    //-------------------------------------------------------------------------------------------------------------
    // Задание макета (вида) диалога в виде массива структур.
    // С помощью особого порядка полей в структуре txDialog::Layout и констант из класса txDialog этот массив
    // становится похож на описание ресурса диалога в .rc - файле.
    // См. описание синтаксиса rc-файла в документации по Win32 (MSDN, http://msdn.com).
    //-------------------------------------------------------------------------------------------------------------

    txDialog::Layout layout[] =

    //----------------------+----------+-----------+-----------------+---------------------------------------------
    //     Тип элемента     | Имя      | Иденти-   |   Координаты    | Флаги элементов
    //     диалога          | элемента | фикатор   |-----------------| (см. описание элементов
    //                      |          | элемента  | X | Y |Шир.|Выс.| окон диалога в MSDN)
    //----------------------+----------+-----------+---+---+----+----+---------------------------------------------
    //                      |          |           |   |   |    |    |
        {{ txDialog::DIALOG,  caption,   0,           0,  0, 240,  85                                                    },
         { txDialog::STATIC,  text,      ID_TEXT_,   10, 10, 150,  40, SS_LEFT                                           },
         { txDialog::EDIT,    input,     ID_INPUT_,  10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP },
         { txDialog::BUTTON,  "&OK",     IDOK,      180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP },
         { txDialog::BUTTON,  "&Cancel", IDCANCEL,  180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP },
         { txDialog::END                                                                                                 }};

    //-------------------------------------------------------------------------------------------------------------
    // Класс диалога для InputBox. Внутренний, т.к. зачем ему быть внешним.
    // Нужен в основном для задания строки ввода (str) и оконной функции диалогового окна, требуемой Win32 (она
    // построена макросами TX_BEGIN_MESSAGE_MAP и другими). Можно не делать внутреннего класса, но тогда оконную
    // функцию придется писать в глобальной области видимости, и str объявлять глобально тоже (или передавать ее
    // адрес через DialogBoxParam и записывать его в класс во время обработки WM_INITDIALOG).
    //-------------------------------------------------------------------------------------------------------------
    struct inputDlg : txDialog
        {
        char str [1024];

        //---------------------------------------------------------------------------------------------------------

        inputDlg() :
            str()                               // Обнуление всей строки. Не работает на старых
            {                                   //     компиляторах, поэтому еще раз:
            memset (str, 0, sizeof (str));      // Обнуление всей строки
            }

        //---------------------------------------------------------------------------------------------------------

        TX_BEGIN_MESSAGE_MAP()    // Карта сообщений. На самом деле это начало оконной функции.

            TX_COMMAND_MAP        // Здесь обрабатываются WM_COMMAND. На самом деле это switch.

                //-------------------------------------------------------------------------------------------------
                // При нажатии кнопки OK копируем строку из поля ввода в нашу переменную str, т.к. после закрытия
                // диалога строка ввода умрет и текст уже из нее получить.
                // Этот макрос на самом деле превращается в case из оператора switch.
                // _wnd - это параметр оконной функции, см. определение макроса TX_BEGIN_MESSAGE_MAP().
                //-------------------------------------------------------------------------------------------------

                TX_HANDLE (IDOK) GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP

        //---------------------------------------------------------------------------------------------------------
        // Конец внутреннего класса диалога
        //---------------------------------------------------------------------------------------------------------

        #if defined (_GCC_VER) && (_GCC_VER >= 530) || defined (_MSC_VER) && (_MSC_VER >= 1900)

        private:
        inputDlg (const inputDlg&)              = delete;
        inputDlg& operator = (const inputDlg&)  = delete;

        #if __STDC_VERSION__ >= 201112L
        inputDlg (const inputDlg&&)             = delete;
        inputDlg& operator = (const inputDlg&&) = delete;
        #endif

        #endif
        };

    //-------------------------------------------------------------------------------------------------------------
    // Убираем дефайны, чтобы потом не мешали.
    // От этого они получаются "локального действия", как будто у них была бы область видимости - функция. На самом
    // деле это сделано вручную через #undef. Чтобы подчеркнуть их локальную природу, у них имена заканчиваются на _.
    // Такие дефайны потом не перекосячат весь код после того как, фактически, стали уже не нужны.
    //-------------------------------------------------------------------------------------------------------------

    #undef ID_TEXT_
    #undef ID_INPUT_

    //-------------------------------------------------------------------------------------------------------------
    // Это статический объект, потому что строка в нем должна жить после завершения функции.
    //-------------------------------------------------------------------------------------------------------------

    static inputDlg dlg;

    //-------------------------------------------------------------------------------------------------------------
    // Передаем layout и запускаем окно диалога
    //-------------------------------------------------------------------------------------------------------------

    dlg.dialogBox (layout);

    //-------------------------------------------------------------------------------------------------------------
    // Возвращаем адрес строки из статического объекта. Так можно делать, потому что статический объект не умрет
    // при выходе из функции и строка в нем, соответственно, тоже. Адрес нестатических переменных передавать
    // синтаксически можно, но ведет к серьезным ошибкам.
    //-------------------------------------------------------------------------------------------------------------

    return dlg.str;
    }

//! @}
//}
//=================================================================================================================

//}
//=================================================================================================================

//=================================================================================================================
//{          TXLIB IMPLEMENTATION
//           Реализация функций библиотеки
//=================================================================================================================
//! @cond INTERNAL

//=================================================================================================================
//{          Internal function prototypes, macros and constants
//           Прототипы внутренних функций, макросы и константы
//=================================================================================================================

const int        _TX_CP                                   =   1251;        // Информация о локали
const char       _TX_LC_CTYPE[]                           =  "Russian";
const wchar_t    _TX_LC_CTYPE_W[]                         = L"Russian_Russia.ACP";

const int        _TX_IDM_ABOUT                            =   40000,       // Идентификаторы системного меню окна
                 _TX_IDM_CONSOLE                          =   40001;

//-----------------------------------------------------------------------------------------------------------------

int              _txInitialize();
void             _txCleanup();

HWND             _txCanvas_CreateWindow (SIZE* size);
inline bool      _txCanvas_OK();

bool             _txCanvas_OnCREATE     (HWND wnd);
bool             _txCanvas_OnDESTROY    (HWND wnd);
bool             _txCanvas_OnCLOSE      (HWND);
bool             _txCanvas_OnPAINT      (HWND wnd);
bool             _txCanvas_OnKEYDOWN    (HWND wnd, WPARAM vk, LPARAM info);
bool             _txCanvas_OnCHAR       (HWND wnd, WPARAM ch, LPARAM info);
bool             _txCanvas_OnTIMER      (HWND wnd, WPARAM id);
bool             _txCanvas_OnMOUSEMOVE  (HWND wnd, WPARAM buttons, LPARAM coords);
bool             _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd);
bool             _txCanvas_OnCmdABOUT   (HWND wnd, WPARAM cmd);

unsigned WINAPI  _txCanvas_ThreadProc (void* data);
LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

int              _txCanvas_SetRefreshLock (int count);

HDC              _txBuffer_Create (HWND wnd, const POINT* size = NULL, HBITMAP bmap = NULL);
bool             _txBuffer_Delete (HDC* dc);
bool             _txBuffer_Select (HGDIOBJ obj, HDC dc = txDC (true));

HWND             _txConsole_Attach();
bool             _txConsole_OK();
bool             _txConsole_Detach (bool activate);
bool             _txConsole_Draw (HDC dc);
bool             _txConsole_SetUnicodeFont();

HICON            _txCreateTXIcon (int size);
int              _txSetFinishedText (HWND wnd);
void             _txPauseBeforeTermination (HWND canvas);
bool             _txIsParentWaitable (DWORD* parentPID = NULL);
PROCESSENTRY32*  _txFindProcess (unsigned pid = GetCurrentProcessId());
bool             _txKillProcess (DWORD pid);
bool             _txInDll();
int              _txGetInput();

bool             _txCreateShortcut (const char shortcutName[],
                                    const char fileToLink[], const char args[] = NULL, const char workDir[] = NULL,
                                    const char description[] = NULL, int cmdShow = SW_SHOWNORMAL,
                                    const char iconFile[] = NULL, int iconIndex = 0, int fontSize = 0,
                                    COORD bufSize = ZERO (COORD), COORD wndSize = ZERO (COORD), COORD wndOrg = ZERO (COORD));

void*            _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                                         WORD controls, short x, short y, short cx, short cy,
                                         const char caption[], const char font[], WORD fontsize,
                                         HANDLE menu);

void*            _tx_DLGTEMPLATE_Add    (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                                         short x, short y, short cx, short cy,
                                         WORD id, const char wclass[], const char caption[]);

const char*      _txError        (const char file[] = NULL, int line = 0, const char func[] = NULL, unsigned color = 0,
                                  const char msg[] = NULL, ...) _TX_CHECK_FORMAT (5);
const char*      _txProcessError (const char file[], int line, const char func[], unsigned color,
                                  const char msg[], va_list args);
const char*      _txAppInfo();

void             _txOnTerminate();
void             _txOnUnexpected();
void             _txOnPureCall();
void             _txOnSignal            (int signal = 0, int fpe = 0);
BOOL WINAPI      _txOnConsoleCtrlEvent  (DWORD type);
void             _txOnSecurityError     (int code, void*);
void             _txOnSecurityErrorAnsi (const char* msg, void* ptr, int error);

int              _txOnNewHandler        (size_t size);
void             _txOnNewHandlerAnsi    ();
int              _txOnMatherr           (_exception* except);
void             _txOnInvalidParam      (const wchar_t* expr, const wchar_t* func, const wchar_t* file,
                                         unsigned line, uintptr_t);
int              _txOnAllocHook         (int type, void* data, size_t size, int use, long request,
                                         const unsigned char* file, int line);
int              _txOnRTCFailure        (int type, const char* file, int line, const char* module, const char* format, ...);
int              _txOnErrorReport       (int type, char* message, int* ret);

void             _txOnCExit();
void             _txOnExit              (int      retcode);
void             _txOnExitProcess       (unsigned retcode);
bool             _txOnTerminateProcess  (HANDLE process, unsigned retcode);
LPTOP_LEVEL_EXCEPTION_FILTER WINAPI _txOnSetUnhandledExceptionFilter (LPTOP_LEVEL_EXCEPTION_FILTER filter);

long WINAPI      _txVectoredExceptionHandler (EXCEPTION_POINTERS* exc);
long WINAPI      _txUnhandledExceptionFilter (EXCEPTION_POINTERS* exc);
long             _txOnExceptionSEH           (EXCEPTION_POINTERS* info, const char func[]);
ptrdiff_t        _txDumpExceptionSEH         (char what[], ptrdiff_t size, const EXCEPTION_RECORD* exc, const char func[]);
ptrdiff_t        _txDumpExceptionObj         (char what[], ptrdiff_t size, void* obj, size_t szObj, const std::type_info* type);
ptrdiff_t        _txDumpExceptionCPP         (char what[], ptrdiff_t size, unsigned code = 0,
                                              unsigned params = 0, const ULONG_PTR info[] = NULL);

void             _txStackBackTrace           (const char file[] = "?", int line = 0, const char func[] = "?",
                                              bool readSource = true);
const char*      _txCaptureStackBackTrace    (int framesToSkip = 0, bool readSource = true,
                                              CONTEXT* context = NULL, HANDLE thread = GetCurrentThread());
int              _txStackWalk                (int framesToSkip, size_t szCapture, void* capture[], unsigned long* backTraceHash,
                                              CONTEXT* context = NULL, HANDLE thread = GetCurrentThread());
const char*      _txCaptureStackBackTraceTX  (int framesToSkip = 0, bool readSource = false);

const char*      _txSymPrintFromAddr         (void* addr = NULL, const char format[] = NULL, ...) _TX_CHECK_FORMAT (2);
bool             _txSymGetFromAddr           (void* addr, Win32::SYMBOL_INFO** symbol = NULL,
                                              Win32::IMAGEHLP_LINE64** line = NULL, const char** module = NULL,
                                              const char** source = NULL, int context = 2);
ptrdiff_t        _txReadSource               (char buf[], ptrdiff_t size, const char file[],
                                              int linStart = 0, int linEnd = INT_MIN, int linMark = INT_MIN);

FARPROC          _txDllImport      (const char dllFileName[], const char funcName[], bool required = true);
PROC             _txSetProcAddress (const char funcName[], PROC newFunc, const char dllName[] = NULL, int useIAT = true,
                                    HMODULE module = NULL, bool debug = false);

ptrdiff_t        _tx_snprintf_s    (char stream[], ptrdiff_t size, const char format[], ...);
ptrdiff_t        _tx_vsnprintf_s   (char stream[], ptrdiff_t size, const char format[], va_list arg);

//-----------------------------------------------------------------------------------------------------------------

// These are macros for __FILE__ and __LINE__ to work properly.

#if !defined (NDEBUG)
    #define  _TX_IF_ARGUMENT_FAILED( cond )    if (!assert (cond) && (SetLastErrorEx (ERROR_BAD_ARGUMENTS, 0),   1))

    #define  _TX_IF_TXWINDOW_FAILED            if (       !txOK() && (SetLastErrorEx (ERROR_INVALID_DATA,  0),   1) && \
                                                  (TX_ERROR ("\a" "Окно рисования не создано или не в порядке"), 1))
#else
    #define  _TX_IF_ARGUMENT_FAILED( cond )    if (!       (cond) && (SetLastErrorEx (ERROR_BAD_ARGUMENTS, 0),   1))

    #define  _TX_IF_TXWINDOW_FAILED            if (       !txOK() && (SetLastErrorEx (ERROR_INVALID_DATA,  0),   1))

#endif

// Take action in debug configuration only.
// Definition ({ expr; }) would be better, but some old dinosaurs (yes it is MSVC 6) reject it. So sad. :'(

#if !defined (NDEBUG)
    #define  _TX_ON_DEBUG( code )              { code; }
#else
    #define  _TX_ON_DEBUG( code )              ;
#endif

#if defined (__STRICT_ANSI__) || defined (_MSC_VER) && (_MSC_VER < 1400)
    #define _TX_UNEXPECTED( msg )              $$ _txError (NULL, 0, NULL, 0, msg)

#else
    #define _TX_UNEXPECTED( ... )              $$ _txError (NULL, 0, NULL, 0, ##__VA_ARGS__)

#endif

// This is a macro because cond is an expression and is not always a function. Lack of lambdas in pre-C++0x.

#define      _txWaitFor( cond, time )          { for (DWORD _t = GetTickCount() + (time); \
                                                      !(cond) && GetTickCount() < _t;     \
                                                      Sleep (_txWindowUpdateInterval)) ;  \
                                                 if  (!(cond))                            \
                                                      _txTrace (__FILE__, __LINE__, NULL, "WARNING: Timeout: " #cond "."); }
// Hand-made DLLIMPORT helpers

#define _TX_DLLIMPORT(     lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txDllImport (lib ".dll", #name, true)

#define _TX_DLLIMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txDllImport (lib ".dll", #name, false)

//}
//=================================================================================================================

//=================================================================================================================
//{          DLL functions import, missing types definitions
//! @name    Импорт внешних библиотек, определение недостающих типов
//=================================================================================================================
//! @{

//-----------------------------------------------------------------------------------------------------------------
//{ Hand-made IAT.
//  Some IDEs don't link with these libs by default in console projects, so do sunrise by hand. :(
//-----------------------------------------------------------------------------------------------------------------

namespace Win32 {

struct NT_CONSOLE_PROPS;
struct CONSOLE_FONT_INFOEX;
struct ADDRESS64;
struct STACKFRAME64;
struct WOW64_CONTEXT;

#ifdef _MSC_VER_6
struct CONSOLE_FONT_INFO;
#endif

typedef bool    (__stdcall *PREAD_PROCESS_MEMORY_ROUTINE64)   (HANDLE process, DWORD64 baseAddress, void* buffer, DWORD size, DWORD* bytesRead);
typedef void*   (__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE64) (HANDLE process, DWORD64 baseAddress);
typedef DWORD64 (__stdcall *PGET_MODULE_BASE_ROUTINE64)       (HANDLE process, DWORD64 address);
typedef DWORD64 (__stdcall *PTRANSLATE_ADDRESS_ROUTINE64)     (HANDLE process, HANDLE thread, ADDRESS64* address);

//-----------------------------------------------------------------------------------------------------------------

_TX_DLLIMPORT     ("GDI32",    HDC,      CreateCompatibleDC,         (HDC dc));
_TX_DLLIMPORT     ("GDI32",    HBITMAP,  CreateCompatibleBitmap,     (HDC dc, int width, int height));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  GetStockObject,             (int object));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  SelectObject,               (HDC dc, HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  GetCurrentObject,           (HDC dc, unsigned objectType));
_TX_DLLIMPORT     ("GDI32",    int,      GetObjectA,                 (HGDIOBJ obj, int bufsize, void* buffer));
_TX_DLLIMPORT     ("GDI32",    DWORD,    GetObjectType,              (HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    bool,     DeleteDC,                   (HDC dc));
_TX_DLLIMPORT     ("GDI32",    bool,     DeleteObject,               (HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetTextColor,               (HDC dc, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetBkColor,                 (HDC dc, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    int,      SetBkMode,                  (HDC dc, int bkMode));
_TX_DLLIMPORT     ("GDI32",    HFONT,    CreateFontA,                (int height, int width, int escapement, int orientation,
                                                                      int weight, DWORD italic, DWORD underline, DWORD strikeout,
                                                                      DWORD charSet, DWORD outputPrec, DWORD clipPrec,
                                                                      DWORD quality, DWORD pitchAndFamily, const char face[]));
_TX_DLLIMPORT     ("GDI32",    int,      EnumFontFamiliesExA,        (HDC dc, LPLOGFONT logFont, FONTENUMPROC enumProc,
                                                                      LPARAM lParam, DWORD reserved));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetPixel,                   (HDC dc, int x, int y, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    COLORREF, GetPixel,                   (HDC dc, int x, int y));
_TX_DLLIMPORT     ("GDI32",    HPEN,     CreatePen,                  (int penStyle, int width, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    HBRUSH,   CreateSolidBrush,           (COLORREF color));
_TX_DLLIMPORT     ("GDI32",    bool,     MoveToEx,                   (HDC dc, int x, int y, POINT* point));
_TX_DLLIMPORT     ("GDI32",    bool,     LineTo,                     (HDC dc, int x, int y));
_TX_DLLIMPORT     ("GDI32",    bool,     Polygon,                    (HDC dc, const POINT points[], int count));
_TX_DLLIMPORT     ("GDI32",    bool,     Rectangle,                  (HDC dc, int x0, int y0, int x1, int y1));
_TX_DLLIMPORT     ("GDI32",    bool,     RoundRect,                  (HDC dc, int x0, int y0, int x1, int y1, int sizeX, int sizeY));
_TX_DLLIMPORT     ("GDI32",    bool,     Ellipse,                    (HDC dc, int x0, int y0, int x1, int y1));
_TX_DLLIMPORT     ("GDI32",    bool,     Arc,                        (HDC dc, int x0, int y0, int x1, int y1,
                                                                      int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    bool,     Pie,                        (HDC dc, int x0, int y0, int x1, int y1,
                                                                      int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    bool,     Chord,                      (HDC dc, int x0, int y0, int x1, int y1,
                                                                      int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    bool,     TextOutA,                   (HDC dc, int x, int y, const char string[], int length));
_TX_DLLIMPORT     ("GDI32",    UINT,     SetTextAlign,               (HDC dc, unsigned mode));
_TX_DLLIMPORT     ("GDI32",    bool,     GetTextExtentPoint32A,      (HDC dc, const char string[], int length, SIZE* size));
_TX_DLLIMPORT     ("GDI32",    bool,     ExtFloodFill,               (HDC dc, int x, int y, COLORREF color, unsigned type));
_TX_DLLIMPORT     ("GDI32",    bool,     BitBlt,                     (HDC dest, int xDest, int yDest, int width, int height,
                                                                      HDC src,  int xSrc,  int ySrc,  DWORD rOp));
_TX_DLLIMPORT     ("GDI32",    int,      SetDIBitsToDevice,          (HDC dc, int xDest, int yDest, DWORD width, DWORD height,
                                                                      int xSrc, int ySrc, unsigned startLine, unsigned numLines,
                                                                      const void* data, const BITMAPINFO* info, unsigned colorUse));
_TX_DLLIMPORT     ("GDI32",    int,      GetDIBits,                  (HDC hdc, HBITMAP hbmp, unsigned uStartScan, unsigned cScanLines,
                                                                      void* lpvBits, BITMAPINFO* lpbi, unsigned usage));
_TX_DLLIMPORT     ("GDI32",    bool,     PatBlt,                     (HDC dc, int x0, int y0, int width, int height, DWORD rOp));
_TX_DLLIMPORT     ("GDI32",    int,      SetROP2,                    (HDC dc, int mode));
_TX_DLLIMPORT     ("GDI32",    int,      SetStretchBltMode,          (HDC dc, int mode));
_TX_DLLIMPORT     ("GDI32",    HBITMAP,  CreateDIBSection,           (HDC dc, const BITMAPINFO* bmInfo, unsigned colorUsage, void **vBits,
                                                                      HANDLE section, DWORD offset));

_TX_DLLIMPORT     ("User32",   int,      DrawTextA,                  (HDC dc, const char text[], int length, RECT* rect, unsigned format));
_TX_DLLIMPORT     ("User32",   HANDLE,   LoadImageA,                 (HINSTANCE inst, const char name[], unsigned type,
                                                                     int sizex, int sizey, unsigned mode));
_TX_DLLIMPORT_OPT ("User32",   bool,     IsHungAppWindow,            (HWND wnd));
_TX_DLLIMPORT_OPT ("User32",   HWND,     GhostWindowFromHungWindow,  (HWND wnd));

_TX_DLLIMPORT     ("WinMM",    bool,     PlaySound,                  (const char sound[], HMODULE mod, DWORD mode));

_TX_DLLIMPORT_OPT ("MSImg32",  bool,     TransparentBlt,             (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                                      HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                                      unsigned transparentColor));
_TX_DLLIMPORT_OPT ("MSImg32",  bool,     AlphaBlend,                 (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                                      HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                                      BLENDFUNCTION blending));

_TX_DLLIMPORT     ("Kernel32", void,     ExitProcess,                (unsigned retcode));
_TX_DLLIMPORT     ("Kernel32", bool,     TerminateProcess,           (HANDLE process, unsigned retcode));
_TX_DLLIMPORT     ("Kernel32", HWND,     GetConsoleWindow,           (void));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     SetConsoleFont,             (HANDLE con, DWORD fontIndex));
_TX_DLLIMPORT_OPT ("Kernel32", DWORD,    GetNumberOfConsoleFonts,    (void));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     GetCurrentConsoleFont,      (HANDLE con, bool maxWnd, CONSOLE_FONT_INFO*   curFont));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     GetCurrentConsoleFontEx,    (HANDLE con, bool maxWnd, CONSOLE_FONT_INFOEX* curFont));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     SetCurrentConsoleFontEx,    (HANDLE con, bool maxWnd, CONSOLE_FONT_INFOEX* curFont));
_TX_DLLIMPORT_OPT ("Kernel32", void,     RtlCaptureContext,          (CONTEXT* contextRecord));
_TX_DLLIMPORT_OPT ("Kernel32", USHORT,   RtlCaptureStackBackTrace,   (DWORD framesToSkip, DWORD framesToCapture, void** backTrace, DWORD* hash));
_TX_DLLIMPORT_OPT ("Kernel32", void*,    AddVectoredExceptionHandler,(unsigned long firstHandler, PVECTORED_EXCEPTION_HANDLER handler));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     GetModuleHandleEx,          (DWORD flags, const char moduleName[], HMODULE* module));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     IsWow64Process,             (HANDLE process, int* isWow64Process));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     Wow64GetThreadContext,      (HANDLE thread, WOW64_CONTEXT* context));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     SetThreadStackGuarantee,    (unsigned long* stackSize));


_TX_DLLIMPORT     ("OLE32",    HRESULT,  CoInitialize,               (void*));
_TX_DLLIMPORT     ("OLE32",    HRESULT,  CoCreateInstance,           (REFCLSID clsId, IUnknown*, DWORD, REFIID iId, PVOID* value));
_TX_DLLIMPORT     ("OLE32",    void,     CoUninitialize,             (void));

_TX_DLLIMPORT     ("Shell32",  HINSTANCE,ShellExecuteA,              (HWND wnd, const char operation[], const char file[],
                                                                      const char parameters[], const char directory[], int showCmd));

_TX_DLLIMPORT     ("ShlWAPI",  char*,    StrStrIA,                   (char string[], const char search[]));

_TX_DLLIMPORT_OPT ("NTDLL",    char*,    wine_get_version,           (void));

_TX_DLLIMPORT     ("MSVCRT",   void,     exit,                       (int retcode));
_TX_DLLIMPORT_OPT ("MSVCRT",   void,     _cexit,                     (void));

_TX_DLLIMPORT_OPT ("DbgHelp*", DWORD,    SymSetOptions,              (DWORD options));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymInitialize,              (HANDLE process, const char userSearchPath[], bool invadeProcess));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymFromAddr,                (HANDLE process, DWORD64 addr, DWORD64* offset, Win32::SYMBOL_INFO*     symbol));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymGetLineFromAddr64,       (HANDLE process, DWORD64 addr, DWORD*   offset, Win32::IMAGEHLP_LINE64* line));
_TX_DLLIMPORT_OPT ("DbgHelp*", DWORD64,  SymGetModuleBase64,         (HANDLE process, DWORD64 addr));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymCleanup,                 (HANDLE process));
_TX_DLLIMPORT_OPT ("DbgHelp*", void*,    SymFunctionTableAccess64,   (HANDLE process, DWORD64 addrBase));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     StackWalk64,                (DWORD arch, HANDLE process, HANDLE thread, STACKFRAME64* frame, void* ctxRecord,
                                                                      PREAD_PROCESS_MEMORY_ROUTINE64   readMemoryFunc,
                                                                      PFUNCTION_TABLE_ACCESS_ROUTINE64 tableAccessFunc,
                                                                      PGET_MODULE_BASE_ROUTINE64       getModuleBaseFunc,
                                                                      PTRANSLATE_ADDRESS_ROUTINE64     translateAddressFunc));
namespace MinGW {
_TX_DLLIMPORT_OPT ("MgwHelp*", DWORD,    SymSetOptions,              (DWORD options));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymInitialize,              (HANDLE process, const char userSearchPath[], bool invadeProcess));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymFromAddr,                (HANDLE process, DWORD64 addr, DWORD64* offset, Win32::SYMBOL_INFO*     symbol));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymGetLineFromAddr64,       (HANDLE process, DWORD64 addr, DWORD*   offset, Win32::IMAGEHLP_LINE64* line));
_TX_DLLIMPORT_OPT ("MgwHelp*", DWORD64,  SymGetModuleBase64,         (HANDLE process, DWORD64 addr));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymCleanup,                 (HANDLE process));
_TX_DLLIMPORT_OPT ("MgwHelp*", void*,    SymFunctionTableAccess64,   (HANDLE process, DWORD64 addrBase));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     StackWalk64,                (DWORD arch, HANDLE process, HANDLE thread, STACKFRAME64* frame, void* ctxRecord,
                                                                      PREAD_PROCESS_MEMORY_ROUTINE64   readMemoryFunc,
                                                                      PFUNCTION_TABLE_ACCESS_ROUTINE64 tableAccessFunc,
                                                                      PGET_MODULE_BASE_ROUTINE64       getModuleBaseFunc,
                                                                      PTRANSLATE_ADDRESS_ROUTINE64     translateAddressFunc));
} // namespace MinGW

} // namespace Win32

//}
//-----------------------------------------------------------------------------------------------------------------

FARPROC _txDllImport (const char dllFileName[], const char funcName[], bool required /*= true*/)
    {
    _TX_IF_ARGUMENT_FAILED (!dllFileName  || *dllFileName) return NULL;
    _TX_IF_ARGUMENT_FAILED ( funcName     && *funcName)    return NULL;

    char dllName[MAX_PATH] = "", dllArch[MAX_PATH] = "";
    const char* arch = (dllFileName? strchr (dllFileName, '*') : NULL);

    if (arch)
        {
        strncpy_s (dllName, sizeof (dllName), dllFileName, arch - dllFileName);
        strncat_s (dllName, sizeof (dllName), arch+1, sizeof (dllName) - 1 - strlen (dllName));

        strncpy_s (dllArch, sizeof (dllArch), dllFileName, arch - dllFileName);
        strncat_s (dllArch, sizeof (dllArch), sizeof (void*) == 8? "64" : "32", 3);
        strncat_s (dllArch, sizeof (dllArch), arch+1, sizeof (dllArch) - 1 - strlen (dllArch));
        }
    else if (dllFileName)
        strncat_s (dllName, sizeof (dllName), dllFileName, sizeof (dllName) - 1);

    HMODULE   dll = GetModuleHandle (dllFileName);

    if (!dll) dll = GetModuleHandle (dllName);
    if (!dll) dll = GetModuleHandle (dllArch);

    if (!dll) dll = LoadLibrary     (dllName);
    if (!dll) dll = LoadLibrary     (dllArch);

    if (!dll && required)  TX_ERROR ("\a" "Cannot load library \"%s%s%s\"." _
                                     dllName _ (arch? "\" / \"" : "") _ dllArch);
    if (!dll) return NULL;

    FARPROC addr = GetProcAddress (dll, funcName);
    if (!addr && required) TX_ERROR ("\a" "Cannot import \"%s\" from library \"%s%s%s\"." _
                                     funcName _ dllName _ (arch? "\" / \"" : "") _ dllArch);
    return addr;
    }

//-----------------------------------------------------------------------------------------------------------------
//{ Another issue, some of structs, consts and interfaces aren't defined in MinGW some early headers.
//  Copied from Windows SDK 7.0a.
//-----------------------------------------------------------------------------------------------------------------

namespace Win32 {

#ifndef AC_SRC_ALPHA
#define AC_SRC_ALPHA          0x01
#endif

#ifndef SMTO_ERRORONEXIT
#define SMTO_ERRORONEXIT      0x0020
#endif

#ifndef NT_CONSOLE_PROPS_SIG
#define NT_CONSOLE_PROPS_SIG  0xA0000002
#endif

#ifndef NIIF_INFO
#define NIIF_INFO             0x00000001
#define NIIF_WARNING          0x00000002
#define NIIF_ERROR            0x00000003
#endif

#ifndef NIF_INFO
#define NIF_STATE             0x00000008
#define NIF_INFO              0x00000010
#endif

#ifndef GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS
#define GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS   0x00000004
#endif

#ifndef SYMOPT_CASE_INSENSITIVE
#define SYMOPT_CASE_INSENSITIVE                  0x00000001
#define SYMOPT_UNDNAME                           0x00000002
#define SYMOPT_DEFERRED_LOADS                    0x00000004
#define SYMOPT_NO_CPP                            0x00000008
#define SYMOPT_LOAD_LINES                        0x00000010
#define SYMOPT_OMAP_FIND_NEAREST                 0x00000020
#define SYMOPT_LOAD_ANYTHING                     0x00000040
#define SYMOPT_IGNORE_CVREC                      0x00000080
#define SYMOPT_NO_UNQUALIFIED_LOADS              0x00000100
#define SYMOPT_FAIL_CRITICAL_ERRORS              0x00000200
#define SYMOPT_EXACT_SYMBOLS                     0x00000400
#define SYMOPT_ALLOW_ABSOLUTE_SYMBOLS            0x00000800
#define SYMOPT_IGNORE_NT_SYMPATH                 0x00001000
#define SYMOPT_INCLUDE_32BIT_MODULES             0x00002000
#define SYMOPT_PUBLICS_ONLY                      0x00004000
#define SYMOPT_NO_PUBLICS                        0x00008000
#define SYMOPT_AUTO_PUBLICS                      0x00010000
#define SYMOPT_NO_IMAGE_SEARCH                   0x00020000
#define SYMOPT_SECURE                            0x00040000
#define SYMOPT_NO_PROMPTS                        0x00080000
#define SYMOPT_ALLOW_ZERO_ADDRESS                0x01000000
#define SYMOPT_DISABLE_SYMSRV_AUTODETECT         0x02000000
#define SYMOPT_FAVOR_COMPRESSED                  0x00800000
#define SYMOPT_FLAT_DIRECTORY                    0x00400000
#define SYMOPT_IGNORE_IMAGEDIR                   0x00200000
#define SYMOPT_OVERWRITE                         0x00100000
#define SYMOPT_DEBUG                             0x80000000
#endif

// SEH exception codes. For GCC, see http://github.com/gcc-mirror/gcc/blob/master/libgcc/unwind-seh.c, lines 64-66.

#define EXCEPTION_BUFFER_OVERFLOW                0xC0000409

#ifndef STATUS_POSSIBLE_DEADLOCK
#define STATUS_POSSIBLE_DEADLOCK                 0xC0000194
#endif

#ifndef EXCEPTION_POSSIBLE_DEADLOCK
#define EXCEPTION_POSSIBLE_DEADLOCK              0xC0000194
#endif

#ifndef STATUS_FLOAT_MULTIPLE_FAULTS
#define STATUS_FLOAT_MULTIPLE_FAULTS             0xC00002B4
#endif

#ifndef STATUS_ASSERTION_FAILURE
#define STATUS_ASSERTION_FAILURE                 0xC0000420
#endif

#ifndef STATUS_WX86_BREAKPOINT
#define STATUS_WX86_BREAKPOINT                   0x4000001F
#endif

#define EXCEPTION_CPP_MSC                        0xE06D7363  // '?msc'
#define EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER1       0x19930520  // '?msc' version magic, see ehdata.h
#define EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER2       0x19930521  // '?msc' version magic
#define EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER3       0x19930522  // '?msc' version magic
#define EXCEPTION_CPP_MSC_EH_PURE_MAGIC_NUMBER1  0x01994000  // '?msc' version magic

#define EXCEPTION_CPP_GCC                        0x20474343  // ' GCC'
#define EXCEPTION_CPP_GCC_UNWIND                 0x21474343  // '!GCC'
#define EXCEPTION_CPP_GCC_FORCED                 0x22474343  // '"GCC'

#define EXCEPTION_CLR_FAILURE                    0xE0434f4D  // 'аCOM'

#define EXCEPTION_CPP_BORLAND_BUILDER            0x0EEDFAE6  // Should never occur here
#define EXCEPTION_CPP_BORLAND_DELPHI             0x0EEDFADE  // Should never occur here

#define EXCEPTION_OUTPUT_DEBUG_STRING            0x40010006  // OutputDebugStringA() call
#define EXCEPTION_OUTPUT_DEBUG_STRING_W          0x4001000A  // OutputDebugStringW() call

#define EXCEPTION_THREAD_NAME                    0x406D1388

#pragma pack (push, 1)

#ifdef _MSC_VER_6

struct CONSOLE_FONT_INFO
    {
    DWORD  nFont;
    COORD  dwFontSize;
    };

struct NOTIFYICONDATA
    {
    DWORD cbSize;
    HWND  hWnd;
    UINT  uID;
    UINT  uFlags;
    UINT  uCallbackMessage;
    HICON hIcon;

    CHAR  szTip[128];
    DWORD dwState;
    DWORD dwStateMask;
    CHAR  szInfo[256];

    union {
        UINT uTimeout;
        UINT uVersion;
        } u;

    CHAR  szInfoTitle[64];
    DWORD dwInfoFlags;
    };

#endif

struct CONSOLE_FONT_INFOEX
    {
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
    };

struct DATABLOCK_HEADER
    {
    DWORD cbSize;
    DWORD dwSignature;
    };

struct NT_CONSOLE_PROPS
    {
    DATABLOCK_HEADER dbh;

    WORD  wFillAttribute;
    WORD  wPopupFillAttribute;
    COORD dwScreenBufferSize;
    COORD dwWindowSize;
    COORD dwWindowOrigin;
    DWORD nFont;
    DWORD nInputBufferSize;
    COORD dwFontSize;
    UINT  uFontFamily;
    UINT  uFontWeight;
    WCHAR FaceName[LF_FACESIZE];
    UINT  uCursorSize;
    BOOL  bFullScreen;
    BOOL  bQuickEdit;
    BOOL  bInsertMode;
    BOOL  bAutoPosition;
    UINT  uHistoryBufferSize;
    UINT  uNumberOfHistoryBuffers;
    BOOL  bHistoryNoDup;

    COLORREF ColorTable[16];
    };

#pragma pack (pop)

#undef  INTERFACE
#define INTERFACE IShellLinkDataList

DECLARE_INTERFACE_ (IShellLinkDataList, IUnknown)
    {
    // *** IUnknown methods ***
    STDMETHOD (QueryInterface)  (THIS_ REFIID iid, void** value)    _tx_override PURE;
    STDMETHOD_(ULONG, AddRef)   (THIS)                              _tx_override PURE;
    STDMETHOD_(ULONG, Release)  (THIS)                              _tx_override PURE;

    // *** IShellLinkDataList methods ***
    STDMETHOD (AddDataBlock)    (THIS_ void* dataBlock)             PURE;
    STDMETHOD (CopyDataBlock)   (THIS_ DWORD sig, void** dataBlock) PURE;
    STDMETHOD (RemoveDataBlock) (THIS_ DWORD sig)                   PURE;
    STDMETHOD (GetFlags)        (THIS_ DWORD* flags)                PURE;
    STDMETHOD (SetFlags)        (THIS_ DWORD  flags)                PURE;

    protected:
    virtual ~IShellLinkDataList();
    };

const GUID IID_IShellLink         = {0x000214ee, 0x0000, 0x0000, {0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
const GUID IID_IShellLinkDataList = {0x45e2b4ae, 0xb1c3, 0x11d0, {0xb9,0x2f,0x00,0xa0,0xc9,0x03,0x12,0xe1}};
const GUID IID_IPersistFile       = {0x0000010b, 0x0000, 0x0000, {0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};

#undef  INTERFACE

enum ADDRESS_MODE
    {
    AddrMode1616,
    AddrMode1632,
    AddrModeReal,
    AddrModeFlat
    };

struct ADDRESS64
    {
    DWORD64      Offset;
    WORD         Segment;
    ADDRESS_MODE Mode;
    };

struct KDHELP64
    {
    DWORD64 Thread;
    DWORD   ThCallbackStack;
    DWORD   ThCallbackBStore;
    DWORD   NextCallback;
    DWORD   FramePointer;
    DWORD64 KiCallUserMode;
    DWORD64 KeUserCallbackDispatcher;
    DWORD64 SystemRangeStart;
    DWORD64 KiUserExceptionDispatcher;
    DWORD64 StackBase;
    DWORD64 StackLimit;
    DWORD64 Reserved[5];
    };

struct STACKFRAME64
    {
    ADDRESS64 AddrPC;
    ADDRESS64 AddrReturn;
    ADDRESS64 AddrFrame;
    ADDRESS64 AddrStack;
    ADDRESS64 AddrBStore;
    PVOID     FuncTableEntry;
    DWORD64   Params[4];
    BOOL      Far;
    BOOL      Virtual;
    DWORD64   Reserved[3];
    KDHELP64  KdHelp;
    };

struct WOW64_FLOATING_SAVE_AREA
    {
    DWORD ControlWord;
    DWORD StatusWord;
    DWORD TagWord;
    DWORD ErrorOffset;
    DWORD ErrorSelector;
    DWORD DataOffset;
    DWORD DataSelector;
    BYTE  RegisterArea[80];
    DWORD Cr0NpxState;
    };

#pragma pack (push, 4)

struct WOW64_CONTEXT
    {
    DWORD ContextFlags;

    DWORD Dr0;
    DWORD Dr1;
    DWORD Dr2;
    DWORD Dr3;
    DWORD Dr6;
    DWORD Dr7;

    WOW64_FLOATING_SAVE_AREA FloatSave;

    DWORD SegGs;
    DWORD SegFs;
    DWORD SegEs;
    DWORD SegDs;

    DWORD Edi;
    DWORD Esi;
    DWORD Ebx;
    DWORD Edx;
    DWORD Ecx;
    DWORD Eax;

    DWORD Ebp;
    DWORD Eip;
    DWORD SegCs;
    DWORD EFlags;
    DWORD Esp;
    DWORD SegSs;

    BYTE  ExtendedRegisters[512];
    };

#pragma pack (pop)

struct SYMBOL_INFO
    {
    ULONG   SizeOfStruct;
    ULONG   TypeIndex;
    ULONG64 Reserved[2];
    ULONG   info;
    ULONG   Size;
    ULONG64 ModBase;
    ULONG   Flags;
    ULONG64 Value;
    ULONG64 Address;
    ULONG   Register;
    ULONG   Scope;
    ULONG   Tag;
    ULONG   NameLen;
    ULONG   MaxNameLen;
    CHAR    Name[1];
    };

struct IMAGEHLP_LINE64
    {
    DWORD   SizeOfStruct;
    PVOID   Key;
    DWORD   LineNumber;
    PCHAR   FileName;
    DWORD64 Address;
    };

} // namespace Win32

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{ There are copies of MSVC compiler built-in predefined definitions, which are wrong in 64-bit mode.
//  So we have to override them. See: http://stackoverflow.com/questions/39113168
//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)
                                                    //  MS ABI C++ Exception Layout
namespace Win32 {                                   //  ---------------------------
                                                    //
#pragma pack (push, 4)                              //   EXCEPTION_RECORD:
                                                    //  +==================================================+
struct ThrowInfo                                    //  |...                                               |
    {                                               //  |NumberParameters:        3, 4 or more             |
    __int32 attributes;                             //  |ExceptionInformation[0]: MS signature 0x19930520  |
    __int32 pmfnUnwind;                             //  |ExceptionInformation[1]: object* thrown           |
    __int32 pForwardCompat;                         //  |ExceptionInformation[2]: ThrowInfo* --------------+---+
    __int32 pCatchableTypeArray;                    //  |ExceptionInformation[3]: ImageBase (if params > 3)|   |
    };                                              //  +==================================================+   |
                                                    //                                                         |
struct CatchableTypeArray                           //        ThrowInfo:                                       |
    {                                               //        +======================================+ <-------+
    __int32 nCatchableTypes;                        //        |   ...                                |
    __int32 arrayOfCatchableTypes[];                //  +-----+-- pCatchableTypeArray (ptr/RVA)      |
    };                                              //  |     +======================================+
                                                    //  |
struct CatchableType                                //  |     CatchableTypeArray:
    {                                               //  +---> +======================================+
    __int32 properties;                             //        |   ...                                |
    __int32 pType;                                  //  +-----+-- arrayOfCatchableTypes[0] (ptr/RVA) |
    __int32 thisDisplacement[3]; // struct _PMD     //  |     +======================================+
    __int32 sizeOrOffset;                           //  |
    __int32 copyFunction;                           //  |     CatchableType:
    };                                              //  +---> +====================+
                                                    //        | ...                |        std::type_info:
#pragma pack (pop)                                  //        | pType (ptr/RVA) ---+------> +==================+
                                                    //        | ...                |        |type_info data    |
} // namespace Win32                                //        +====================+        |...               |
                                                    //                                      +==================+
#endif

// Similar to __CxxDetectRethrow(), see C:\Bin\Microsoft Visual Studio 14.0\VC\crt\src\crtsrc\vcruntime\frame.cpp:

#define _TX_MSC__CXX_DETECT_RETHROW( exc )                                     \
    (                                                                          \
    (exc)                                          &&                          \
    (exc) -> ExceptionCode    == EXCEPTION_CPP_MSC &&                          \
    (exc) -> NumberParameters >= 3                 &&                          \
                                                                               \
    ((exc)-> ExceptionInformation[0] == EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER1 ||  \
     (exc)-> ExceptionInformation[0] == EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER2 ||  \
     (exc)-> ExceptionInformation[0] == EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER3) && \
                                                                               \
    (exc) -> ExceptionInformation[2] == 0                                      \
    )

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{ The corresponding structures for GCC
//
//  From: http://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/libsupc%2B%2B/unwind-cxx.h
//  See:  http://mentorembedded.github.io/cxx-abi/abi-eh.html#cxx-abi
//-----------------------------------------------------------------------------------------------------------------

#if defined (_GCC_VER)
                                                    // GCC ABI C++ Exception layout. A/B are ExceptionInformation[0].
namespace ABI {                                     // --------------------------------------------------------------
                                                    //
struct __cxa_exception                              // Case A: "_Unwind_Exception* A" is undependent exception:
    {                                               // --------------------------------------------------------
    union {                                         //
        struct                                      //           __cxa_exception:           std::type_info:
            {                                       //       -*--+====================+     +==================+
            ::std::type_info* exceptionType;        //        ^  |exceptionType* -----+---->|type_info data    |
            void (*exceptionDestructor)(void*);     //        |  |...                 |     |...               |
            };                                      //       -1  |                    |     +==================+
        struct                                      //        |  |                    |
            {                                       // A >----|--+--------------------+
            __cxa_exception*  primaryException;     //     |  |  |unwindHeader        |
            void (*padding)();                      //    +1  |  |                    |
            };                                      //     |  |  |                    |
        };                                          //     V  |  |                    |
                                                    //    -*---  +====================+
    std::unexpected_handler   unexpectedHandler;    //           |object              |
    std::terminate_handler    terminateHandler;     //           +--------------------+
                                                    //
    __cxa_exception*          nextException;        // Case B: "_Unwind_Exception* B" is dependent exception
    int                       handlerCount;         // (unwindHeader.exception_class & 1 != 0):
    int                       handlerSwitchValue;   // -----------------------------------------------------
    const unsigned char*      actionRecord;         //
    const unsigned char*      languageSpecificData; //           __cxa_exception:               __cxa_exception:
    void*                     catchTemp;            //       -*--+====================+     -*--+=================+
    void*                     adjustedPtr;          //        ^  |primaryException* --+--    ^  |exceptionType*   |
                                                    //        |  |...                 |  \   |  |...              |
    _Unwind_Exception         unwindHeader;         //       -1  |                    |  |   |  |                 |
    };                                              //        |  |                    |  |   |  |                 |
                                                    // B >----|--+--------------------+  |  -1  +-----------------+
struct __cxa_eh_globals                             //     |  |  |unwindHeader        |  |   |  |unwindHeader     |
    {                                               //    +1  |  |                    |  |   |  |                 |
    __cxa_exception* caughtExceptions;              //     |  |  |                    |  |   |  |                 |
    unsigned int     uncaughtExceptions;            //     V  |  |                    |  \   |  |                 |
    };                                              //    -*---  +====================+   -->*--+=================+
                                                    //           |...                 |         |object           |
}  // namespace ABI                                 //           .                    .         |                 |
                                                    //                                          +-----------------+

extern "C" ABI::__cxa_eh_globals* __cxa_get_globals();

#endif

//}
//-----------------------------------------------------------------------------------------------------------------

#ifdef _MSC_VER_6
using namespace Win32;
#endif

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Internal global data
//! @name    Внутренние глобальные данные
//
//           Данные не упакованы в структуру или класс, для того, чтобы это сделали Вы сами :)
//
//           Если вы пишете свою библиотеку и используете TXLib.h как примеру, не следуйте ему и не делайте так же.
//           Здесь это сделано только в образовательных целях.
//
//           Будьте практичнее, сделайте структуру и глобальную функцию для доступа к ней.
//=================================================================================================================
//! @{

int                          _txInitialized              = _TX_NOINIT || _txInitialize();

unsigned          volatile   _txMainThreadId             = 0;       // ID потока, где выполняется main()

unsigned          volatile   _txCanvas_ThreadId          = 0;       // ID потока, владеющего окном холста TXLib
HANDLE            volatile   _txCanvas_Thread            = NULL;    // Дексриптор этого потока
HWND              volatile   _txCanvas_Window            = NULL;    // Дескриптор окна холста TXLib

UINT                         _txCanvas_RefreshTimer      = 0;       // Timer to redraw TXLib window
int               volatile   _txCanvas_RefreshLock       = 0;       // Blocks auto on-timer canvas update, see txBegin/txEnd

HDC                          _txCanvas_BackBuf[2]        = {NULL,   // [0] Main TXLib in-memory DC, where user's pictures lies
                                                            NULL};  // [1] Image ready for auto-refresh, see txCanvas_OnPAINT()
CRITICAL_SECTION             _txCanvas_LockBackBuf       = {0,-1};  // Prevent simultaneous access to back buffer, see txLock()

::std::vector<HDC>*          _txCanvas_UserDCs           = NULL;    // List of DCs allocated, for auto-free

bool              volatile   _txConsole_IsBlinking       = true;    // To blink or not to blink, that is the question.

bool                         _txConsole                  = false;   // Only first TXLib module in app can own the console
bool                         _txMain                     = false;   // First TXLib wnd opened (closing it terminates program)
bool                         _txIsDll                    = false;   // TXLib module is in DLL
bool              volatile   _txRunning                  = false;   // main() is still running
bool              volatile   _txExit                     = false;   // exit() is active

POINT                        _txMousePos                 = {-1,-1}; // Ask Captn Obviouos about it. See txCanvas_OnMOUSE()
unsigned                     _txMouseButtons             = 0;

WNDPROC           volatile   _txAltWndProc               = NULL;    // Альтернативная оконная функция. См. txSetWindowsHook().

_txLoc            _tx_thread _txLocCur                   = {};      // Execution point tracking and trace state, see "$" macro

char                         _txDumpSE [_TX_BUFSIZE]     = "";      // SEH dump data area
char                         _txTraceSE[_TX_HUGEBUFSIZE] = "";      // Stack trace data area

jmp_buf                      _txDumpExceptionObjJmp      = {0};     // Hook for _txDumpExceptionObj
LPTOP_LEVEL_EXCEPTION_FILTER _txPrevUEFilter             = NULL;    // Previous UnhandledExceptionFilter

PROC              volatile   _txForceImportThese[]       = { (PROC) ::TerminateProcess, (PROC) ::ExitProcess, (PROC) ::exit };

const unsigned               _txSystemMessage[]          = { 0x776F656D, 0x5E2E2E5E };  // A very system messages

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          TXLib engine init/check/cleanup
//! @name    Инициализация/проверка/завершение TXLib
//=================================================================================================================
//! @{

//-----------------------------------------------------------------------------------------------------------------
//{          Early initialization
//-----------------------------------------------------------------------------------------------------------------

int _txInitialize()
    {
    if (_txInitialized) return 1;
    _txInitialized = 1;

    #if defined (_TX_ALLOC_BREAK) && defined (_MSC_VER)  // See http://msdn.microsoft.com/en-us/library/w2fhc9a3%28v=vs.90%29.aspx
    _CrtSetBreakAlloc (_TX_ALLOC_BREAK);                 // and http://support.microsoft.com/ru-ru/kb/151585
    #endif

    #if defined (_TX_ALLOW_TRACE)
    _txLocCur.trace = 1;
    #endif

    _TX_ON_DEBUG (OutputDebugString ("\n");
                  OutputDebugString (_TX_VERSION " - The Dumb Artist Library, " _TX_AUTHOR ": \"" __FILE__ "\" "
                                     "compiled " __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode, module: " _TX_MODULE "\n");
                  OutputDebugString ("\n"));

    _txMainThreadId = GetCurrentThreadId();

$1  _txIsDll = _txInDll();

$   if (!_txIsDll)
        {
$       _txConsole = ! FindAtom ("_txConsole");
$       (void)          AddAtom ("_txConsole");
        }

$   if (_txConsole)
        {
$       unsigned long stackSize = _TX_STACKSIZE;
        if (Win32::SetThreadStackGuarantee) { $ Win32::SetThreadStackGuarantee (&stackSize); }

$       _txOnSignal();

$       if (!*_txLogName)
            { $ _tx_snprintf_s (_txLogName, sizeof (_txLogName) - 1, "%s.log", txGetModuleFileName()); }

        #if !defined (_MSC_VER_6)
$       ::std::set_unexpected (_txOnUnexpected);
$       ::std::set_terminate  (_txOnTerminate);
        #endif

$       Win32::AddVectoredExceptionHandler (1, _txVectoredExceptionHandler);
$       _txPrevUEFilter = SetUnhandledExceptionFilter (_txUnhandledExceptionFilter);

$       std::set_new_handler (_txOnNewHandlerAnsi);

$       SetConsoleCtrlHandler (_txOnConsoleCtrlEvent, true);

$       SetErrorMode (SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);

        #if defined (_MSC_VER)

$       _set_printf_count_output (1);

$       _CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);
$       _CrtSetAllocHook (_txOnAllocHook);
$       _set_new_handler (_txOnNewHandler);
$       _set_new_mode (1);

$       unsigned mode = _CRTDBG_MODE_FILE;
$       if (_CrtSetReportHook2 (_CRT_RPTHOOK_INSTALL, _txOnErrorReport) > 0) mode = 0;

$       _CrtSetReportMode (_CRT_WARN,   _CRTDBG_MODE_DEBUG | mode);
$       _CrtSetReportMode (_CRT_ERROR,  _CRTDBG_MODE_DEBUG | mode | _CRTDBG_MODE_WNDW);
$       _CrtSetReportMode (_CRT_ASSERT, _CRTDBG_MODE_DEBUG | mode | _CRTDBG_MODE_WNDW);
$       _CrtSetReportFile (_CRT_WARN,   _CRTDBG_FILE_STDERR);
$       _CrtSetReportFile (_CRT_ERROR,  _CRTDBG_FILE_STDERR);
$       _CrtSetReportFile (_CRT_ASSERT, _CRTDBG_FILE_STDERR);

$       _set_abort_behavior (_WRITE_ABORT_MSG, _WRITE_ABORT_MSG);
$       _set_abort_behavior (0,                _CALL_REPORTFAULT);

$       _RTC_SetErrorFunc              (_txOnRTCFailure);
$       _set_purecall_handler          (_txOnPureCall);
$       _set_invalid_parameter_handler (_txOnInvalidParam);

        #endif

        #if defined (_MSC_VER) && (_MSC_VER == 1310)  // MSVC 7.1 (2003)
$       _set_security_error_handler (_txOnSecurityError);
        #endif

        #if defined (__STDC_LIB_EXT1__)
$       ::std::set_constraint_handler_s (_txOnSecurityErrorAnsi);
        #endif

        #if defined (_MSC_VER) && (_MSC_VER >= 1900) || defined (_GCC_VER) && (_GCC_VER >= 530)
$       __setusermatherr (_txOnMatherr);
        #endif

        #if defined (_MSC_VER) && (_MSC_VER >= 1 /*!!!*/) || defined (_GCC_VER) && (_GCC_VER >= 461)
$       _set_error_mode (_OUT_TO_MSGBOX | _OUT_TO_STDERR);
        #endif

$       HWND console = _txConsole_Attach();
$       SetWindowTextA (console, txGetModuleFileName (false));
        }

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   _txCanvas_UserDCs = new ::std::vector <HDC>;

$   _txSetProcAddress ("ExitProcess",                 (PROC) _txOnExitProcess,                 "KERNEL32.DLL");
$   _txSetProcAddress ("TerminateProcess",            (PROC) _txOnTerminateProcess,            "KERNEL32.DLL");
$   _txSetProcAddress ("UnhandledExceptionFilter",    (PROC) _txUnhandledExceptionFilter,      "KERNEL32.DLL", true);
$   _txSetProcAddress ("SetUnhandledExceptionFilter", (PROC) _txOnSetUnhandledExceptionFilter, "KERNEL32.DLL");
$   _txSetProcAddress ("exit",                        (PROC) _txOnExit);
$   _txSetProcAddress ("_cexit",                      (PROC) _txOnCExit);

$   atexit (_txCleanup);

$   if (_txConsole)
        {
$       txSetConsoleAttr (0x07);

$       tx_fpreset();
$       srand ((unsigned) time (NULL));
$       SetLastError (0);
        }

$   (void) Win32::RoundRect;  // Just to suppress "defined but not used" warning

$   return 1;
    }

//}
//-----------------------------------------------------------------------------------------------------------------

HWND txCreateWindow (double sizeX, double sizeY, bool centered /*= true*/)
    {
$1  if (!_txInitialized) _txInitialized = _txInitialize();

$   if (txWindow())
        {
$       SetLastErrorEx (ERROR_INVALID_DATA, 0);
$       _TX_ON_DEBUG (TX_ERROR ("\a" "Окно рисования уже создано"));
$       return txWindow();
        }

$   if (!_txIsDll)
        {
$       _txMain = ! FindAtom ("_txMain");  // Not a thread-safe
$       (void)       AddAtom ("_txMain");
        }

$   if (_txWindowUpdateInterval < 10) { $ _txWindowUpdateInterval = 10; }

$   _txRunning = false;

    // Store the size

$   static SIZE size = { ROUND (sizeX), ROUND (sizeY) };
$   if (centered) { size.cx *= -1; size.cy *= -1; }

    // In Thread, where REAL creation lies...

    #if !( defined (_MSC_VER) && (_MSC_VER < 1400) && !defined (_MT) )
$   unsigned id = 0;
$   _txCanvas_Thread = (HANDLE) _beginthreadex (NULL, 0,                         _txCanvas_ThreadProc, &size, 0, &id);
    #else
$   DWORD    id = 0;
$   _txCanvas_Thread =           CreateThread  (NULL, 0, (LPTHREAD_START_ROUTINE)_txCanvas_ThreadProc, &size, 0, &id);
    #endif

$   if (!_txCanvas_Thread) return TX_DEBUG_ERROR ("\a" "Cannot start canvas thread."), (HWND)NULL;

$   _txWaitFor (_txRunning, 30*_TX_TIMEOUT);

$   if (!_txRunning)       return TX_DEBUG_ERROR ("\a" "Cannot create canvas window."),(HWND)NULL;
$   if (!txOK())           return TX_DEBUG_ERROR ("\a" "Canvas window is not OK."),    (HWND)NULL;

$   Sleep (100);

$   errno = 0; _doserrno = 0;
$   SetLastError (0);

$   return txWindow();
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSetDefaults (HDC dc /*= txDC (true)*/)
    {
$1  txUpdateWindow (false);
$   txAutoLock _lock;

$   RECT r = {0};
$   GetClientRect (Win32::GetConsoleWindow(), &r) asserted;
$   SIZE szCon = { r.right - r.left, r.bottom - r.top };

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {{80, 25}, {0}, 0, {0, 0, 80-1, 25-1}, {80, 25}};
$   GetConsoleScreenBufferInfo (out, &con);

$   SIZE szTxt = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
                   (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

//{ Set defaults for graphics layer

$   _txBuffer_Select (Win32::GetStockObject (WHITE_PEN),   dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject (WHITE_BRUSH), dc) asserted;

$   _txBuffer_Select (Win32::CreateFont (szCon.cy/szTxt.cy, szCon.cx/szTxt.cx,
                                         0, 0, FW_REGULAR, FALSE, FALSE, FALSE,
                                         RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                         DEFAULT_QUALITY, DEFAULT_PITCH, _txConsoleFont),
                      dc) asserted;

$  (Win32::SetTextColor      (dc, TX_WHITE) != CLR_INVALID) asserted;
$   Win32::SetBkMode         (dc, TRANSPARENT)              asserted;

$   Win32::SetROP2           (dc, R2_COPYPEN)               asserted;
$   Win32::SetStretchBltMode (dc, HALFTONE)                 asserted;

//}

$   if (dc != txDC (false)) return true;

//{ Set defaults for console  layer

$   POINT szCanvas = txGetExtent (dc);

$   HGDIOBJ font = txFontExist (_txConsoleFont)?
                       Win32::CreateFont ((int) (1.0 * szCanvas.y/szTxt.cy), (int) (1.0 * szCanvas.x/szTxt.cx),
                                          0, 0, FW_REGULAR, FALSE, FALSE, FALSE,
                                          RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                          DEFAULT_QUALITY, FIXED_PITCH, _txConsoleFont)
                       :
                       Win32::GetStockObject (SYSTEM_FIXED_FONT);

$   _txBuffer_Select (font, _txCanvas_BackBuf[1]) asserted;
//}

//{ Scroll the console for text to go above top of window and don't mix with graphics

$   if (con.dwCursorPosition.X) _putch ('\n');

$   short delta = (short) (con.dwCursorPosition.Y - con.srWindow.Top);

$   con.srWindow.Top    = (short) (con.srWindow.Top    + delta);
$   con.srWindow.Bottom = (short) (con.srWindow.Bottom + delta);

$   SMALL_RECT src  = {0, 0, (short) (con.dwSize.X - 1), (short) (con.dwSize.Y - 1) };
$   CHAR_INFO  fill = {{' '}, 0x07};        // Fill with spaces, light-gray on black
$   COORD      dest = {0, (short) -delta};  // New UL-corner of src, scroll up

$   con.dwCursorPosition.X = 0;
$   con.dwCursorPosition.Y = (short) (con.dwCursorPosition.Y - delta);

$   (con.srWindow.Bottom < con.dwSize.Y &&                        // Move the "window"
     SetConsoleWindowInfo      (out, true, &con.srWindow))
    ||
    (ScrollConsoleScreenBuffer (out, &src, NULL, dest, &fill),    // Or scroll the buffer
     SetConsoleCursorPosition  (out, con.dwCursorPosition));
//}

$   txUpdateWindow (true);

    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool txOK()
    {
    return _txCanvas_OK();
    }

//-----------------------------------------------------------------------------------------------------------------
//{          Cleanup
//-----------------------------------------------------------------------------------------------------------------

// Implicit std(MSVCRT.dll)::_cexit() call before _txCleanup can lead to hangs in _cexit handlers chain.
// So redefining ::std::_cexit(). Do it dynamically via PE Import Table hook to avoid duplicate symbols
// if several modules linked together include TXLib.h. See _txSetProcAddress() call in _txInitialize().

void _txOnCExit()
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s() called", _TX_VERSION, __func__);

$1  _txCleanup();

    if (Win32::_cexit) { $ Win32::_cexit(); }
    return;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnExit (int retcode)
    {
    if (retcode != 0) txOutputDebugPrintf ("\r" "%s - WARNING: %s (%d) called", _TX_VERSION, __func__, retcode);

$1  _txCleanup();

    Win32::exit (retcode);
    return;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnExitProcess (unsigned retcode)
    {
    if (retcode != 0) txOutputDebugPrintf ("\r" "%s - WARNING: %s (%u) called", _TX_VERSION, __func__, retcode);

$1  _txCleanup();

    Win32::ExitProcess (retcode);
    return;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txOnTerminateProcess (HANDLE process, unsigned retcode)
    {
    if (retcode != 0) txOutputDebugPrintf ("\r" "%s - WARNING: %s (0x%p, %u) called", _TX_VERSION, __func__, process, retcode);

$1  _txCleanup();

    return Win32::TerminateProcess (process, retcode);
    }

//-----------------------------------------------------------------------------------------------------------------

BOOL WINAPI _txOnConsoleCtrlEvent (DWORD type)
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s (0x%04X) called", _TX_VERSION, __func__, type);

$1  switch (type)
        {
        case CTRL_LOGOFF_EVENT:
        case CTRL_SHUTDOWN_EVENT: $ _txExit = true;
                                  $ _txCleanup();
        case CTRL_C_EVENT:
        case CTRL_CLOSE_EVENT:
        case CTRL_BREAK_EVENT:

        default:                  break;
        }

$   return false;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txCleanup()
    {
    if (!_txInitialized) return;
    else _txInitialized = false;

$1  //!!! txSleep (_txWindowUpdateInterval);

$   _txRunning = false;
$   _txConsole_IsBlinking = false;

$   HWND canvas     = txWindow();
$   HWND console    = Win32::GetConsoleWindow();
$   unsigned thread = GetCurrentThreadId();

$   HWND wnd        = (canvas)? canvas : console;

$   bool externTerm = (thread != _txMainThreadId &&
                       thread != _txCanvas_ThreadId);
$   DWORD parent = 0;
$   bool waitableParent = !externTerm && _txIsParentWaitable (&parent);

$   if (_txConsole)
        {
$       if (_txMain) txSetConsoleAttr (0x07);
$       if (console) EnableWindow (console, true);
        }

$   if (_txMain && !externTerm && wnd != NULL)
        { $ _txSetFinishedText (wnd); }

$   if ((canvas? _txMain : (_txConsole && !waitableParent)) && !_txExit &&
        thread == _txMainThreadId)
        {
$       if (wnd)
            {
$           ShowWindow          (wnd, SW_SHOW);
$           EnableWindow        (wnd, true);
$           SetForegroundWindow (wnd);
$           BringWindowToTop    (wnd);
$           RedrawWindow        (wnd, NULL, NULL, RDW_INVALIDATE | RDW_INTERNALPAINT | RDW_UPDATENOW);
            }

$       if (console)
            { $ _txPauseBeforeTermination (canvas); }
        }

$   if (txWindow())
        { $ SendNotifyMessage (txWindow(), WM_DESTROY, 0, 0); }

$   _txWaitFor (!txWindow(), 5*_TX_TIMEOUT);

$   if (!txWindow())
        { $ DeleteCriticalSection (&_txCanvas_LockBackBuf); _txCanvas_LockBackBuf = ZERO (CRITICAL_SECTION); }

$   if (_txCanvas_Thread)
        { $ CloseHandle (_txCanvas_Thread) asserted; _txCanvas_Thread = NULL; }

$   delete _txCanvas_UserDCs; _txCanvas_UserDCs = NULL;

$   if (_txMain && canvas && waitableParent && _txNOP (_TX_ALLOW_KILL_PARENT))
        { $ waitableParent |= !_txKillProcess (parent); }

$   if (_txMain && _txConsole)
        { $ _txConsole_Detach (waitableParent && !externTerm); }

$   _txSymGetFromAddr (NULL);

    _TX_ON_DEBUG (OutputDebugString ("\n");
                  OutputDebugString (_TX_VERSION " - FINISHED: " _TX_MODULE "\n");
                  OutputDebugString ("\n"));
    }

//-----------------------------------------------------------------------------------------------------------------

int _txSetFinishedText (HWND wnd)
    {
    struct tools
        {
        static LRESULT getWindowText (HWND window, wchar_t text[], size_t size)
            {
$1          memset (text, 0, size * sizeof (*text));

$           return SendMessageTimeoutW (window, WM_GETTEXT, (WPARAM) size, (LPARAM) text, SMTO_BLOCK | SMTO_ABORTIFHUNG, _TX_TIMEOUT, NULL);
            }

        static LRESULT setWindowText (HWND window, wchar_t text[])
            {
$1          return SendMessageTimeoutW (window, WM_SETTEXT, 0,             (LPARAM) text, SMTO_BLOCK | SMTO_ABORTIFHUNG, _TX_TIMEOUT, NULL);
            }
        };

$1  static wchar_t title [_TX_BUFSIZE+15] = L"TXLib";

$   tools::getWindowText (wnd, title, _TX_BUFSIZE-1);
$   unsigned len = (unsigned) wcslen (title); if (len >= _TX_BUFSIZE) len = _TX_BUFSIZE-1;

$   MultiByteToWideChar (_TX_CP, 0, " [ЗАВЕРШЕНО]", -1, title + len, _TX_BUFSIZE - len);

$   tools::setWindowText (wnd, title);
$   tools::getWindowText (wnd, title, _TX_BUFSIZE-1);
$   if (len <= _TX_BUFSIZE-1-2 && title [len+2] == (wchar_t) 0x0417 /* 'З' */) return 0;

$   MultiByteToWideChar (_TX_CP, 0, " [FINISHED]",  -1, title + len, _TX_BUFSIZE - len);

$   tools::setWindowText (wnd, title);
$   tools::getWindowText (wnd, title, _TX_BUFSIZE-1);
$   if (len <= _TX_BUFSIZE-1-2 && title [len+2] == /* 'F' */ (wchar_t) 0x0046) return 1;

$   return 2;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txPauseBeforeTermination (HWND canvas)
    {
$1  while (_kbhit()) (void)_getch();

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   bool kbRedir = !GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);
$   bool kbWait  = (_txGetInput() == EOF);
$   bool wine    = !!Win32::wine_get_version;

$   if (kbWait && !canvas && !kbRedir && !wine)
        {
$       printf ("\n" "[Нажмите любую клавишу для завершения]");
        }

$   for (int i = 1; ; i++)
        {
$       Sleep (_txWindowUpdateInterval);

        if (!kbWait || (kbRedir && !canvas)) { $ break; }  // No need to run and hide

        if (!wine && _txGetInput() != EOF)   { $ break; }  // Somebody hit something.

        if (canvas && !_txCanvas_ThreadId)   { $ break; }  // There was a window, and now there is not.

        if (!Win32::GetConsoleWindow())      { $ break; }  // Console was destroyed

        if (Win32::GhostWindowFromHungWindow && Win32::GhostWindowFromHungWindow (canvas))
            { $ TX_ERROR ("Программа зависла и будет завершена."); break; }

        if (canvas && Win32::IsHungAppWindow && Win32::IsHungAppWindow (canvas))
            { $ _txTrace (__FILE__, __LINE__, NULL, "WARNING: Программа зависла и будет завершена.");     break; }

        if (canvas && !SendMessageTimeout (canvas, WM_NULL, 0,0, SMTO_BLOCK | SMTO_ABORTIFHUNG, _TX_TIMEOUT, NULL))
            { $ _txTrace (__FILE__, __LINE__, NULL, "WARNING: Программа не отвечает и будет завершена."); break; }

        if (!wine && !(i % 100500))
            { $ printf ("\r" "[Так нажмите же какую-нибудь клавишу для моего завершения]"); }
        }

$   while (!wine && _kbhit()) (void)_getch();

$   printf ("\n");
    }

//-----------------------------------------------------------------------------------------------------------------

int _txGetInput()
    {
$1  HANDLE con = GetStdHandle (STD_INPUT_HANDLE);

$   DWORD nchars = 0;
$   if (GetConsoleMode (con, &nchars) == 0 &&
        PeekNamedPipe  (con, NULL, 0, NULL, &nchars, NULL))
        {
$       return (nchars)? fgetc (stdin) : EOF;
        }

$   if (_kbhit())
        {
$       return _getch();
        }

#if defined (_MSC_VER) && (_MSC_VER < 1700)

$   if (fseek (stdin, 1, SEEK_CUR) != EOF)
        {
$       (void) fseek (stdin, -1, SEEK_CUR);
$       return fgetc (stdin);                              // This causes blocking in MSVC 2011 beta
        }

#endif

$   return EOF;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txIsParentWaitable (DWORD* parentPID /*= NULL*/)
    {
$1  PROCESSENTRY32* info = _txFindProcess();
$   if (!info) return false;

$   info = _txFindProcess (info->th32ParentProcessID);
$   if (!info) return false;

$   char parent [MAX_PATH] = "";
$   strncpy_s (parent, sizeof (parent), info->szExeFile, sizeof (parent) - 1);
$   if (parentPID) *parentPID = info->th32ProcessID;

$   info = _txFindProcess (info->th32ParentProcessID);          // info: grandparent

$   char list[_TX_BUFSIZE] = _TX_WAITABLE_PARENTS;
$   char* ctx = NULL;

$   for (char* p = strtok_s (list, ", ", &ctx); p; p = strtok_s (NULL, ", ", &ctx))
        {
$       char* gp = strchr (p, ':');

$       if (gp)
            {
$           *gp++ = 0;
$           if (_stricmp (p, parent) != 0) { continue; }

$           if (info) if (_stricmp (gp, info->szExeFile) == 0)  // Was &&, but OMG MSVC /analyze...
                { $ return true; }
            }
        else
            {
$           if (_stricmp (p, parent) == 0)
                { $ return true; }
            }
        }

$   return false;
    }

//-----------------------------------------------------------------------------------------------------------------

PROCESSENTRY32* _txFindProcess (unsigned pid /*= GetCurrentProcessId()*/)
    {
$1  static PROCESSENTRY32 info = { sizeof (info) };
$   if (!pid) return &info;

$   HANDLE sshot = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, 0);
$   assert (sshot); if (!sshot) return NULL;

$   for (bool ok = !!Process32First (sshot, &info); ok; ok = !!Process32Next (sshot, &info))
        if (info.th32ProcessID == pid) break;

$   CloseHandle (sshot);

$   return &info;
    }

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Tools
//-----------------------------------------------------------------------------------------------------------------

bool _txInDll()
    {
$1  MODULEENTRY32 mod = { sizeof (mod) };

$   HANDLE sshot = CreateToolhelp32Snapshot (TH32CS_SNAPMODULE, 0);
$   assert (sshot); if (!sshot) return false;

$   bool inDll = false;

$   for (bool ok = !!Module32First (sshot, &mod); ok; ok = !!Module32Next (sshot, &mod))
        {
$       if (!mod.modBaseAddr) continue;

$       IMAGE_DOS_HEADER* dosHdr = (IMAGE_DOS_HEADER*)  mod.modBaseAddr;
$       IMAGE_NT_HEADERS* ntHdr  = (IMAGE_NT_HEADERS*) (mod.modBaseAddr + dosHdr->e_lfanew);

$       inDll = (dosHdr->e_magic  == IMAGE_DOS_SIGNATURE &&
                 ntHdr->Signature == IMAGE_NT_SIGNATURE  &&
                (ntHdr->FileHeader.Characteristics & IMAGE_FILE_DLL) != 0);

$       if (In (std::nomeow, (BYTE*)(uintptr_t)_txInDll, mod.modBaseAddr, mod.modBaseAddr + mod.modBaseSize))
            { $ break; }
        }

$   CloseHandle (sshot);
$   return inDll;
    }

//-----------------------------------------------------------------------------------------------------------------

// You are here, little hacker?

bool _txKillProcess (DWORD pid)
    {
$1  _TX_IF_ARGUMENT_FAILED (pid) return false;

$   HANDLE token = INVALID_HANDLE_VALUE;
$   OpenProcessToken (GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token) asserted;

$   LUID luid = {0};
$   LookupPrivilegeValue (NULL, SE_DEBUG_NAME, &luid) asserted;

$   TOKEN_PRIVILEGES priv = { 1, {{{ luid.LowPart, luid.HighPart}, SE_PRIVILEGE_ENABLED }}};
$   TOKEN_PRIVILEGES old  = {0};

$   DWORD oldSz = 0;
$   AdjustTokenPrivileges (token, false, &priv, sizeof (priv), &old, &oldSz) asserted;

$   HANDLE proc = OpenProcess (PROCESS_ALL_ACCESS, 0, pid);
$   if (!proc) return false;

$   bool ok = !!Win32::TerminateProcess (proc, 0);
$   CloseHandle (proc);

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

// TXLib continues to hack the reality to make your life better, sweeter and easier

PROC _txSetProcAddress (const char funcName[], PROC newFunc, const char dllName[] /*= NULL*/, int useIAT /*= true*/,
                        HMODULE module /*= NULL*/, bool debug /*= false*/)
    {
$1  _txLocCur.trace = 0;

$   if (debug) printf ("_txSetProcAddress (%s, 0x%p, %s, 0x%p):\n", funcName, newFunc, dllName, module);

$   _TX_IF_ARGUMENT_FAILED (funcName) return NULL;
$   _TX_IF_ARGUMENT_FAILED (newFunc)  return NULL;

$   if (!module) module = GetModuleHandle (NULL);
$   if (!module) return NULL;

$   HMODULE dll     = (dllName)? GetModuleHandle (dllName)       : NULL;
$   PROC    oldFunc = (dll)?     GetProcAddress  (dll, funcName) : NULL;

$   if (!useIAT && oldFunc)  // Use hotpatching
        {
$       const size_t jmpSz = 1 + sizeof (DWORD);  // sizeof (JMP rel instruction)

$       DWORD rights = PAGE_READWRITE;
$       if (!VirtualProtect ((void*)(uintptr_t) oldFunc, jmpSz, rights, &rights)) return NULL;

        // Overwrite oldFunc prolog with JMP trampoline to newFunc.
        // Calling oldFunc from any location will lead to newFunc call anyway.

$       *(BYTE*)  ((char*)(uintptr_t) oldFunc + 0) = 0xE9;  // JMP rel
$       *(DWORD*) ((char*)(uintptr_t) oldFunc + 1) = (DWORD) ((char*)(uintptr_t) newFunc - (char*)(uintptr_t) oldFunc - jmpSz);

$       VirtualProtect ((void*)(uintptr_t) oldFunc, jmpSz, rights, &rights);

$       return oldFunc;
        }

//  For PE structure and Import Table format, e.g. see https://books.google.ru/books?id=ifQPC86G66sC&pg=PA255
//  and below through Figure 5-5, and/or http://www.brokenthorn.com/Resources/OSDevPE.html.

    #define RVA_(type, addr)  ( (type) ((uintptr_t) module + (uintptr_t) (addr)) )

$   IMAGE_DOS_HEADER* dosHdr = RVA_ (IMAGE_DOS_HEADER*, 0);
$   IMAGE_NT_HEADERS* ntHdr  = RVA_ (IMAGE_NT_HEADERS*, dosHdr->e_lfanew);

$   if (dosHdr->e_magic   != IMAGE_DOS_SIGNATURE ||
        ntHdr ->Signature != IMAGE_NT_SIGNATURE) return NULL;

$   DWORD impOffset = ntHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
$   IMAGE_IMPORT_DESCRIPTOR* desc = RVA_ (IMAGE_IMPORT_DESCRIPTOR*, impOffset);

$   if (desc == (IMAGE_IMPORT_DESCRIPTOR*) ntHdr) return NULL;

$   IMAGE_THUNK_DATA* thunk0 = NULL, * thunk1 = NULL;
$   char* impDll = NULL;
$   char* impName = NULL;
$   void** impPtr = NULL;
$   bool found = false;

    for (; desc->Name; desc++)
        {
$       impDll = RVA_ (char*, desc->Name);
$       if (dllName && _stricmp (impDll, dllName) != 0) continue;

$       for (thunk0 = RVA_ (IMAGE_THUNK_DATA*, desc->OriginalFirstThunk),
             thunk1 = RVA_ (IMAGE_THUNK_DATA*, desc->FirstThunk);

             thunk0 && thunk1 && thunk1->u1.Function;

             thunk0++,
             thunk1++)
            {
            impName = (char*) RVA_ (IMAGE_IMPORT_BY_NAME*, thunk0->u1.AddressOfData) -> Name;
            impPtr  = (void**)                            &thunk1->u1.Function;  // Should change it, so this is ptr

            if (debug) printf ("[0x%p] %s!%s\n", *impPtr, impDll, impName);

            if ((oldFunc && (uintptr_t) oldFunc == (uintptr_t) *impPtr) ||
                (impName && _stricmp (funcName, impName) == 0))
                {
                found = true;
                break;
                }
            }

$       if (found) break;
        }

    if (debug) printf ("_txSetProcAddress (%s, 0x%p, %s, 0x%p): %s\n\n",
                       funcName, newFunc, dllName, module, (found? "FOUND" : "NOT found"));

$   if (!found) return NULL;

$   DWORD rights = PAGE_READWRITE;
$   if (!VirtualProtect (impPtr, sizeof (*impPtr), rights, &rights)) return NULL;

$   *(PROC*) impPtr = newFunc;  // In different MS-SDKs this field has different types (DWORD/DWORD*/etc)

$   VirtualProtect (impPtr, sizeof (*impPtr), rights, &rights);

$   return oldFunc;

    #undef RVA_
    }

//}
//-----------------------------------------------------------------------------------------------------------------

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Internal TXLib window functions     (_txCanvas...)
//! @name    Внутренние функции окна TXLib       (_txCanvas...)
//=================================================================================================================

//{
#if defined (_MSC_VER_6) || defined (_GCC_VER) && (_GCC_VER <= 345)

    #define SetClassLong_  SetClassLong
    #define GCL_HICON_     GCL_HICON
    #define GCL_HICONSM_   GCL_HICONSM
    #define GCL_HCURSOR_   GCL_HCURSOR

#else
    #define SetClassLong_  SetClassLongPtr
    #define GCL_HICON_     GCLP_HICON
    #define GCL_HICONSM_   GCLP_HICONSM
    #define GCL_HCURSOR_   GCLP_HCURSOR
    #endif
//}

unsigned WINAPI _txCanvas_ThreadProc (void* data)
    {
$1  _txCanvas_ThreadId = GetCurrentThreadId();

$   _TX_IF_ARGUMENT_FAILED (data) return false;

$   unsigned long stackSize = _TX_STACKSIZE;
    if (Win32::SetThreadStackGuarantee) { $ Win32::SetThreadStackGuarantee (&stackSize); }

$   HWND wnd = _txCanvas_CreateWindow ((SIZE*) data);
$   if (!txWindow()) return TX_DEBUG_ERROR ("\a" "Cannot create canvas"), 0;

$   HICON   icon32 = LoadIcon         (NULL, "_TX_ICON");
$   HICON   icon16 = LoadIcon         (NULL, "_TX_ICONSM");
$   HCURSOR cursor = LoadCursor       (NULL, "_TX_CURSOR");
$   HMENU   menu   = LoadMenu         (NULL, "_TX_MENU");
$   HACCEL  accel  = LoadAccelerators (NULL, "_TX_ACCELERATORS");

$   SetClassLong_ (wnd, GCL_HICON_,   (DWORD)(uintptr_t) (icon32? icon32 : _txCreateTXIcon (32)));
$   SetClassLong_ (wnd, GCL_HICONSM_, (DWORD)(uintptr_t) (icon16? icon16 : _txCreateTXIcon (16)));
$   SetClassLong_ (wnd, GCL_HCURSOR_, (DWORD)(uintptr_t) (cursor? cursor : LoadCursor (NULL, IDC_ARROW)));

    if (menu) { $ SetMenu (wnd, menu); DrawMenuBar (wnd); }

    _TX_ON_DEBUG (OutputDebugString (_TX_VERSION " - STARTED: " _TX_MODULE "\n"));

$   _txRunning = true;

$   SetForegroundWindow (wnd);

$   ShowWindow          (wnd, SW_SHOW);
$   UpdateWindow        (wnd);

$   MSG msg = {0};
$   while (GetMessage (&msg, NULL, 0, 0))
        {
$       if (!msg.hwnd) continue;

$       if (accel && TranslateAccelerator (wnd, accel, &msg)) continue;

$       TranslateMessage (&msg);
$       DispatchMessage  (&msg);

$       Sleep (0);
        }

$   if (icon16) DestroyIcon (icon16);  // If Explorer is displaying Tray Notification, these
$   if (icon32) DestroyIcon (icon32);  // calls will possibly fail, and we'll get resource leak.

$   LeaveCriticalSection (&_txCanvas_LockBackBuf);

$   if (_txRunning && _txMain)         // Main window is destroyed but main() is still running.
        {                              // No chances for good termination, so use exit().
$       ::exit ((int) msg.wParam);
        }

    _TX_ON_DEBUG (OutputDebugString (_TX_VERSION " - STOPPED: " _TX_MODULE "\n"));

$   _txCanvas_ThreadId = 0;
$   return true;
    }

//{
#undef SetClassLong
#undef GCL_HICON_
#undef GCL_HICONSM_
#undef GCL_HCURSOR_
//}

//-----------------------------------------------------------------------------------------------------------------

HWND _txCanvas_CreateWindow (SIZE* size)
    {
$1  _TX_IF_ARGUMENT_FAILED (size) return NULL;

$   static char className[_TX_BUFSIZE] = "";
$   _tx_snprintf_s (className, sizeof (className) - 1, "/*---[TXLib]-------------------------- "
                                                       _TX_VERSION "  " __FILE__ "  WndClass %08X "
                                                       "---------------------------[TXLib]---*/", (int) GetTickCount());
$   WNDCLASSEX wc    = { sizeof (wc) };
$   wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
$   wc.lpfnWndProc   = _txCanvas_WndProc;
$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) Win32::GetStockObject (HOLLOW_BRUSH);
$   wc.lpszClassName = className;

$   ATOM wndclass = RegisterClassEx (&wc);
$   if (!wndclass) return TX_DEBUG_ERROR ("RegisterClass (\"%s\") failed" _ className), (HWND) NULL;

$   int centered = false;
$   if (size->cx < 0 && size->cy < 0) { size->cx *= -1; size->cy *= -1; centered = true; }

$   SIZE scr = { GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN) };
$   RECT r   = { 0, 0, size->cx, size->cy }; AdjustWindowRect (&r, _txWindowStyle, false);
$   SIZE sz  = { r.right - r.left, r.bottom - r.top };

$   HWND wnd = CreateWindowEx (WS_EX_APPWINDOW, className, txGetModuleFileName (false), _txWindowStyle,
                               centered? scr.cx/2 - sz.cx/2 : CW_USEDEFAULT,
                               centered? scr.cy/2 - sz.cy/2 : CW_USEDEFAULT,
                               sz.cx, sz.cy, NULL, NULL, NULL, NULL);

$   if (!wnd || !txWindow()) return TX_DEBUG_ERROR ("Cannot create canvas: CreateWindowEx (\"%s\") failed" _ className), (HWND) NULL;
$   HMENU menu = GetSystemMenu (txWindow(), false);
$   if (!menu) return txWindow();

$   AppendMenu (menu, MF_SEPARATOR, 0, NULL)                       asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_CONSOLE, "Show &Console") asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_ABOUT,   "&About...")     asserted;

$   HWND console = Win32::GetConsoleWindow();

$   DWORD proc = 0;
$   GetWindowThreadProcessId (console, &proc);

$   if (console && (proc == GetCurrentProcessId() || _txIsParentWaitable()))
        { $ ShowWindow (console, _txConsoleMode); }

$   CheckMenuItem (menu, _TX_IDM_CONSOLE, (console? (IsWindowVisible (console)? MF_CHECKED : 0) : MF_DISABLED));

$   return txWindow();
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool _txCanvas_OK()
    {
    return _txCanvas_ThreadId   &&
           _txCanvas_Window     &&
           _txCanvas_BackBuf[0] &&
           _txCanvas_BackBuf[1];
    }

//-----------------------------------------------------------------------------------------------------------------

int _txCanvas_SetRefreshLock (int count)
    {
$1  int oldCount = _txCanvas_RefreshLock;

$   _txCanvas_RefreshLock = count;

$   HWND wnd = txWindow();

$   if ((_txCanvas_RefreshLock <= 0 || oldCount <= 0) && wnd)
        { $ RedrawWindow (wnd, NULL, NULL, RDW_INVALIDATE | RDW_INTERNALPAINT | RDW_UPDATENOW); }

$   return oldCount;
    }

//-----------------------------------------------------------------------------------------------------------------

HICON _txCreateTXIcon (int size)
    {
$1  _TX_IF_ARGUMENT_FAILED (size == 32 || size == 16) return NULL;

$   const unsigned char image32 [32*32+1] =
        "00000000000000000000000000000000""0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0""0F0000000000000000000000000000F0""0F0000000000000000000000000000F0"
        "0F0000000000000099999999999900F0""0F0000000000000090300333330900F0""0F0000000990000090000000000900F0""0F00000099990000900BB000000900F0"
        "0F0000039999000090B00090900900F0""0F0000009999000090B00999990900F0""0F00000009903799900BB090900900F0""0F000000009BB70090000010000900F0"
        "0F0000000B90000090000000000900F0""0F000000B0B0000099999999999900F0""0F00007B30B0000090000000000000F0""0F00007300B0000090000000000000F0"
        "0F00000000B3000090000000000000F0""0F0000000B0B000090000000000000F0""0F000000B303B00090000000000000F0""0F000003B000B00090000000000000F0"
        "0F00003B00003B0090000000000000F0""0F0000300000030090000000000000F0""0F0000000448888888888844000000F0""0F00004886E6E6E60E66E6EEEE4400F0"
        "0F4488866E0E60E00660E06E66EEE4F0""0F868806E06E06E666E66E00E06EE6F0""0F08606E66E0066000E006E66E00E6F0""0F8666E006600E00006600E006E00EF0"
        "0F000E066888888888888888606660F0""0F66EEE6EE000E00000E00086EEEE6F0""0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0""00000000000000000000000000000000";

$   const unsigned char image16 [16*16+1] =
        "0000000000000000""0000000999999990""0009000900000090""0099900909973090""0059700909009390""0009799909973090""0099000900000090""0959330999999990"
        "0709500900000000""0095930900000000""0090393900000000""0790073900000000""0900000900000000""000EE6E6E6E6E000""0EE6E6E6E6E6EEE0""0000000000000000";

$   const COLORREF pal['F'-'0'+1] = { 0x000000, 0x002b2b, 0x555500, 0x005555, 0x808000, 0x008080, 0xaaaa00, 0x00aaaa, 0xd5d500, 0x00d5d5, 0,0,0,0,0,0,0,
                                      0xffff00, 0x00ffff, 0xffffaa, 0xaaffff, 0xd5d500, 0xffffff };

$   const unsigned char* image = (size == 32)? image32 : image16;

$   POINT sz = { size, size };
$   HDC dcMask  = _txBuffer_Create (txWindow(), &sz); assert (dcMask);
$   HDC dcColor = _txBuffer_Create (txWindow(), &sz); assert (dcColor);

$   for (int i = 0; i < size*size; i++)
        {
        assert (In (std::nomeow, image[i], '0', '9') ||
                In (std::nomeow, image[i], 'A', 'F'));

        Win32::SetPixel (dcColor, i % size, i / size, pal [image[i] - '0']);
        }

$   ICONINFO info = { true, 0, 0, (HBITMAP) Win32::GetCurrentObject (dcMask,  OBJ_BITMAP),
                                  (HBITMAP) Win32::GetCurrentObject (dcColor, OBJ_BITMAP) };

$   HICON icon = CreateIconIndirect (&info);
$   assert (icon);

$   _txBuffer_Delete (&dcMask)  asserted;
$   _txBuffer_Delete (&dcColor) asserted;

$   return icon;
    }

//}
//=================================================================================================================

//=================================================================================================================
//{          Main window event handlers          (_txCanvas_On...)
//! @name    События основного окна              (_txCanvas_On...)
//=================================================================================================================
//! @{

LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
    {
#ifdef _TX_ALLOW_TRACE

    int inTX = _txLocCur.inTX++;

    if (_txLocCur.trace) _txTrace (__FILE__, __LINE__, __TX_FUNCTION__, "%*s" "0x%X <- 0x%03X (0x%08X, 0x%08lX)",
                                   12 - _txLocCur.inTX*2, "", wnd, msg, wpar, lpar);
    _txLocCur.inTX = inTX;

#endif

$1  if (msg == WM_KEYDOWN && wpar == VK_F12 &&
        GetKeyState (VK_SHIFT) && GetKeyState (VK_CONTROL) && GetKeyState (VK_MENU))
        {
$       _txCanvas_OnCmdABOUT (wnd,      wpar);
$       return DefWindowProc (wnd, msg, wpar, lpar);
        }

    WNDPROC altWndProc = _txAltWndProc;  // Cache to prevent change from main thread
    if (altWndProc)
        {
$       LRESULT res = altWndProc (wnd, msg, wpar, lpar);
$       if (res) return res;
        }

    switch (msg)
        {
        case WM_CREATE:       $     _txCanvas_OnCREATE     (wnd);             return 0;

        case WM_CLOSE:        $ if (_txCanvas_OnCLOSE      (wnd)) break; else return 0;
        case WM_DESTROY:      $     _txCanvas_OnDESTROY    (wnd);             return 0;

        case WM_PAINT:        $     _txCanvas_OnPAINT      (wnd);             return 0;
        case WM_TIMER:        $     _txCanvas_OnTIMER      (wnd, wpar);       return 0;

        case WM_KEYDOWN:      $     _txCanvas_OnKEYDOWN    (wnd, wpar, lpar); return 0;
        case WM_CHAR:         $     _txCanvas_OnCHAR       (wnd, wpar, lpar); return 0;

        case WM_LBUTTONUP:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MOUSEMOVE:    $     _txCanvas_OnMOUSEMOVE  (wnd, wpar, lpar); return 0;

        default: break;
        }

    if (msg == WM_SYSCOMMAND) switch (wpar)
        {
        case _TX_IDM_ABOUT:   $     _txCanvas_OnCmdABOUT   (wnd, wpar);       return 0;
        case _TX_IDM_CONSOLE: $     _txCanvas_OnCmdCONSOLE (wnd, wpar);       return 0;

        default: break;
        }

$   return DefWindowProc (wnd, msg, wpar, lpar);
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCREATE (HWND wnd)
    {
$1  _TX_IF_ARGUMENT_FAILED (wnd) return false;

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd); assert (_txCanvas_BackBuf[0]);
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd); assert (_txCanvas_BackBuf[1]);

$   SetTimer (wnd, _txCanvas_RefreshTimer, _txWindowUpdateInterval, NULL) asserted;

$   _txCanvas_Window = wnd;

$   txSetDefaults();

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnDESTROY (HWND wnd)
    {
$1  _TX_IF_ARGUMENT_FAILED (wnd) return false;

    // Инициируем остановку цикла сообщений

$   PostQuitMessage (_txRunning? WM_DESTROY : EXIT_SUCCESS);

$   if (!_txCanvas_Window) return false;

    // Indicate that we are about to manually terminate

$   _txExit = true;

    // Lock GDI resources

$   bool locked = false;
$   _txWaitFor ((locked = txLock (false), locked), _TX_TIMEOUT);
$   if (!locked) TX_DEBUG_ERROR ("Cannot lock GDI to free resources");

    // Освобождаем пользовательские ресурсы

$   if (_txCanvas_UserDCs && _txCanvas_UserDCs->size())
        {
$       txNotifyIcon (NIIF_ERROR, NULL, "Вы забыли освободить %d HDC.", (int) _txCanvas_UserDCs->size());
$       Sleep (_TX_TIMEOUT);

$       for (size_t i = 0; i < _txCanvas_UserDCs->size(); i++) _txBuffer_Delete (&_txCanvas_UserDCs->at (i));
$       _txCanvas_UserDCs->clear();
        }

    // Освобождаем ресурсы, связанные с окном

$   if (_txCanvas_RefreshTimer) KillTimer (wnd, _txCanvas_RefreshTimer) asserted;

$   if (_txCanvas_BackBuf[1]) _txBuffer_Delete (&_txCanvas_BackBuf[1])  asserted;
$   if (_txCanvas_BackBuf[0]) _txBuffer_Delete (&_txCanvas_BackBuf[0])  asserted;

$   txUnlock();

    // Indicate that we are destroyed

$   _txCanvas_Window = NULL;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCLOSE (HWND wnd)
    {
$1  _TX_IF_ARGUMENT_FAILED (wnd && _txCanvas_OK()) return false;

$   if (_txMain && _txRunning &&
        txMessageBox ("Функция main() не завершена. Программа все еще работает. Прервать аварийно?\n\n"
                      "Лучше подождать, когда main() завершится - это отображается в заголовке окна.",
                      txGetModuleFileName (false), MB_OKCANCEL | MB_ICONSTOP) != IDOK) return false;
$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnTIMER (HWND wnd, WPARAM)
    {
$1  _TX_IF_ARGUMENT_FAILED (wnd) return false;

$   if (_txCanvas_RefreshLock > 0 || !_txRunning) return false;

$   InvalidateRect (wnd, NULL, false) asserted;
$   UpdateWindow   (wnd)              asserted;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnPAINT (HWND wnd)
    {
$1  _TX_IF_ARGUMENT_FAILED (wnd && _txCanvas_OK()) return false;

$   bool forceRedraw   = GetAsyncKeyState (VK_MENU)  && GetAsyncKeyState (VK_CONTROL) &&
                         GetAsyncKeyState (VK_SHIFT) && GetAsyncKeyState (VK_SNAPSHOT);

$   PAINTSTRUCT ps = {0};
$   HDC dc = BeginPaint (wnd, &ps);
$   if (!dc) return false;

$   RECT r = {0};
$   GetClientRect (wnd, &r) asserted;
$   POINT size = { r.right - r.left, r.bottom - r.top };

$   if ((_txCanvas_RefreshLock <= 0 || forceRedraw) &&
        txLock (false))
        {
$       Win32::BitBlt (_txCanvas_BackBuf[1], 0, 0, size.x, size.y, txDC (false), 0, 0, SRCCOPY);

$       _txConsole_Draw (_txCanvas_BackBuf[1]);

$       txUnlock();
        }

    // Magic 100500 value is used to completely block screen refresh.
    // Since no value can be 100500 or above, this condition is always true and the refresh cannot be blocked IRL.
    // Do not use 100501 because it may lead to errors on some compilers and possible may crash the compilers
    // themselves.
    // Yes guys, with all your software installed. :(

$   if (_txCanvas_RefreshLock != 100500)
        { $ Win32::BitBlt (dc, 0, 0, size.x, size.y, _txCanvas_BackBuf[1], 0, 0, SRCCOPY); }

$   EndPaint (wnd, &ps) asserted;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnKEYDOWN (HWND, WPARAM vk, LPARAM info)
    {
$1  INPUT_RECORD evt = {0};

$   evt.EventType                        = KEY_EVENT;
$   evt.Event.KeyEvent.bKeyDown          = true;
$   evt.Event.KeyEvent.wRepeatCount      = 1;
$   evt.Event.KeyEvent.uChar.AsciiChar   = (char)  MapVirtualKey ((WORD) vk, 2);   // 2 == MAPVK_VK_TO_CHAR
$   evt.Event.KeyEvent.wVirtualScanCode  = (WORD)  (info >> 16);
$   evt.Event.KeyEvent.wVirtualKeyCode   = (WORD)  vk;
$   evt.Event.KeyEvent.dwControlKeyState = (DWORD) (info & (1 << 24))? ENHANCED_KEY : 0;

$   if (evt.Event.KeyEvent.uChar.AsciiChar) return false;  // Let TranslateMessage() and WM_CHAR do the job

$   DWORD written = 0;
$   WriteConsoleInput (GetStdHandle (STD_INPUT_HANDLE), &evt, 1, &written);

$   return false;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCHAR (HWND, WPARAM ch, LPARAM info)
    {
$1  INPUT_RECORD evt = {0};

$   evt.EventType                        = KEY_EVENT;
$   evt.Event.KeyEvent.bKeyDown          = true;
$   evt.Event.KeyEvent.wRepeatCount      = 1;
$   evt.Event.KeyEvent.uChar.AsciiChar   = (char) (ch);
$   evt.Event.KeyEvent.wVirtualScanCode  = (WORD) (info >> 16);
$   evt.Event.KeyEvent.wVirtualKeyCode   = (WORD) MapVirtualKey ((WORD) (info >> 16), 3);  // 3 == MAPVK_VSC_TO_VK_EX
$   evt.Event.KeyEvent.dwControlKeyState = 0;

$   DWORD written = 0;
$   WriteConsoleInput (GetStdHandle (STD_INPUT_HANDLE), &evt, 1, &written);

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnMOUSEMOVE (HWND, WPARAM buttons, LPARAM coords)
    {
$1  _TX_IF_ARGUMENT_FAILED (_txCanvas_OK()) return false;

$   _txMousePos.x   = LOWORD (coords);
$   _txMousePos.y   = HIWORD (coords);
$   _txMouseButtons = (unsigned) buttons;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd)
    {
$1  _TX_IF_ARGUMENT_FAILED (wnd) return false;

$   HWND console = Win32::GetConsoleWindow();
$   if (!console) return false;

$   bool visible = !!IsWindowVisible (console);

$   ShowWindow (console, visible? SW_HIDE : SW_SHOW);

$   visible = !!IsWindowVisible (console);
$   CheckMenuItem (GetSystemMenu (wnd, false), (int) cmd, visible? MF_CHECKED : MF_UNCHECKED);

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCmdABOUT (HWND, WPARAM)
    {
$1  //{ Overriding the missing names, if the set is uncomplete

    #if defined (__MODULE)
        #define ABOUT_NAME_    __MODULE
    #else
        #define ABOUT_NAME_    "TXLib"
    #endif

    #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__AUTHOR)

        #ifndef __MODULE
        #define __MODULE       "TXLib"                           "\n"  "#define __MODULE to set the name.\n"
        #endif

        #ifndef __VERSION
        #define __VERSION      "(0.000000000)."                  "\n" "#define __VERSION to set the string value.\n"
        #endif

        #ifndef __DESCRIPTION
        #define __DESCRIPTION  "(Да, мне лень задать описание)." "\n" "#define __DESCRIPTION to override project role.\n"
        #endif

        #ifndef __AUTHOR
        #define __AUTHOR       "(Непонятно кто)."                "\n" "#define __AUTHOR to override this name."
        #endif

    #endif
    //}

$   static char text[_TX_BUFSIZE] = "";

$   _tx_snprintf_s (text, sizeof (text) - 1,

                    "Application:\n\n"

                    #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__AUTHOR)
                        __MODULE " version " __VERSION "\n" __DESCRIPTION "\n" "Copyright (c) " __AUTHOR "\n"
                    #else
                        "Здесь могла бы быть Ваша реклама :)\n"
                        "#define __MODULE to \"your program name\" before including TXLib.h to use this billboard...\n"
                    #endif

                    "\n" "%s", _txAppInfo());

$   txMessageBox (text, "About " ABOUT_NAME_, MB_ICONINFORMATION);

    // And a bit of HTTP-code in C++ function:

    goto http;
    http://txlib.ru            // See valuable refs here :)

$   return true;

    #undef ABOUT_NAME_
    }

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Console-support functions           (_txConsole...)
//! @name    Функции консольного окна            (_txConsole...)
//=================================================================================================================
//! @{

HWND _txConsole_Attach()
    {
$1  HWND console = Win32::GetConsoleWindow();

$   if (!console)
        {
$       FreeConsole();
$       AllocConsole();
        }

$   console = Win32::GetConsoleWindow();
$   if (!console) return NULL;

    // Linux::Wine v1.2.2+ compatibility.
    // Beer compatibility will be added in future versions.
    // Минздрав РФ предупреждает: чрезмерное употребление wine вредит Вашему здоровью.

$   if (Win32::wine_get_version)
        {
$       Win32::GetNumberOfConsoleFonts = NULL;
$       Win32::GetCurrentConsoleFont   = NULL;
$       Win32::SetConsoleFont          = NULL;
        }

    // Устанавливаем русскую кодовую страницу для консоли Windows

$   SetConsoleCP       (_TX_CP);  // 1251
$   SetConsoleOutputCP (_TX_CP);  // 1251

    // Устанавливаем русскую кодовую страницу для стандартной библиотеки, иначе не будут работать Unicode-версии
    // функций (wprintf, ...). Если компилите с помощью gcc и собираетесь использовать L"unicode-строки" с русским
    // языком, укажите опции в командной строке компилятора g++: -finput-charset=CP1251 -fexec-charset=CP1251.

$   setlocale (LC_CTYPE, _TX_LC_CTYPE);                                    //  "Russian"
$   if (!Win32::wine_get_version) _wsetlocale (LC_CTYPE, _TX_LC_CTYPE_W);  // L"Russian_Russia.ACP"

$   static bool done = false;
$   if (done) return console;

    // Впечатлительным лучше сюда не смотреть.

$   if (!Win32::wine_get_version)
        { $ _txConsole_SetUnicodeFont(); }

#ifndef _CONSOLE

    // Переоткрываем заново <s>Америку</s> потоки ввода-вывода, если subsystem != console

$                    *stdin  = *_fdopen (_open_osfhandle ((DWORD)(uintptr_t) GetStdHandle (STD_INPUT_HANDLE),  _O_TEXT), "r");
$   fflush (stdout); *stdout = *_fdopen (_open_osfhandle ((DWORD)(uintptr_t) GetStdHandle (STD_OUTPUT_HANDLE), _O_TEXT), "w");
$   fflush (stderr); *stderr = *_fdopen (_open_osfhandle ((DWORD)(uintptr_t) GetStdHandle (STD_ERROR_HANDLE),  _O_TEXT), "w");

$   setvbuf (stdin,  NULL, _IONBF, 0);
$   setvbuf (stdout, NULL, _IONBF, 0);
$   setvbuf (stderr, NULL, _IONBF, 0);

$   ::std::ios::sync_with_stdio();

#endif

    // That's all, folks

$   done = true;
$   return console;
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool _txConsole_OK()
    {
    return Win32::GetConsoleWindow() != NULL;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txConsole_Detach (bool activate)
    {
$1  HWND console = Win32::GetConsoleWindow();
$   if (!console) return false;

$   EnableWindow (console, true);
$   ShowWindow   (console, SW_SHOW);

$   if (activate)
        {
$       SetForegroundWindow (console);
$       BringWindowToTop    (console);
        }

$   return !!FreeConsole();
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txConsole_Draw (HDC dc)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   BOOL ok = GetConsoleScreenBufferInfo (out, &con);
$   if (!ok) return false;

$   POINT size = { con.srWindow.Right  - con.srWindow.Left + 1,
                   con.srWindow.Bottom - con.srWindow.Top  + 1 };

$   SIZE fontSz = { 12, 16 };
$   Win32::GetTextExtentPoint32 (dc, "W", 1, &fontSz) asserted;

$   COLORREF pal [16] = { 0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080, 0xC0C0C0,
                          0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF };

$   for (short y = 0; y < size.y; y++)
        {
        static char chr [_TX_BUFSIZE + 1] = "";  // [con.dwSize.X + 1]; maybe will be truncated
        static WORD atr [_TX_BUFSIZE + 1] = {0}; // [con.dwSize.X + 1]; maybe will be truncated
        COORD coord = { (short) (con.srWindow.Left), (short) (y + con.srWindow.Top) };
        DWORD read  = 0;

        if (!ReadConsoleOutputCharacter (out, chr, SIZEARR (chr) - 1, coord, &read)) continue;
        if (!ReadConsoleOutputAttribute (out, atr, SIZEARR (atr) - 1, coord, &read)) continue;

        for (int x = 0, xEnd = size.x; x < size.x; x = xEnd)
            {
            Win32::SetTextColor (dc, pal [ atr[x]       & 0x0F]);
            Win32::SetBkColor   (dc, pal [(atr[x] >> 4) & 0x0F]);
            Win32::SetBkMode    (dc,      (atr[x]       & 0xF0)? OPAQUE : TRANSPARENT);

            for (xEnd = x+1; atr[xEnd] == atr[x] && xEnd < size.x; xEnd++) {;}

            Win32::TextOut (dc, ROUND (fontSz.cx * (x + con.srWindow.Left)),
                                ROUND (fontSz.cy *  y), chr + x, xEnd - x) asserted;
            }
        }

$   Win32::SetTextColor (dc, pal [ con.wAttributes       & 0x0F]);
$   Win32::SetBkColor   (dc, pal [(con.wAttributes >> 4) & 0x0F]);
$   Win32::SetBkMode    (dc, TRANSPARENT);

$   if (_txConsole_IsBlinking &&
        In (con.dwCursorPosition, con.srWindow) &&
        GetTickCount() % _txCursorBlinkInterval*2 > _txCursorBlinkInterval &&
        GetForegroundWindow() == txWindow())
        {
$       Win32::TextOut (dc, ROUND (fontSz.cx * (con.dwCursorPosition.X - con.srWindow.Left)),
                            ROUND (fontSz.cy * (con.dwCursorPosition.Y - con.srWindow.Top)) + 1,
                            "_", 1) asserted;
        }

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------
//{          Welcome to the Duck Side! Together we will rule the Bathroom!
//-----------------------------------------------------------------------------------------------------------------

bool _txConsole_SetUnicodeFont()
    {
    // Начиная с Висты все хорошо...

$1  if (Win32::GetCurrentConsoleFontEx && Win32::SetCurrentConsoleFontEx)
        {
$       HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$       Win32::CONSOLE_FONT_INFOEX info = { sizeof (info) };
$       if (!Win32::GetCurrentConsoleFontEx (out, false, &info)) return false;

$       info.FontFamily = 0x36;                                                    // Unicode fixed-pitch
$       if (!*info.FaceName) info.dwFontSize.Y = (SHORT) (info.dwFontSize.Y + 2);  // Terminal font is too small
$       wcsncpy_s (info.FaceName, SIZEARR (info.FaceName), L"Lucida Console", SIZEARR (info.FaceName));

$       return !!Win32::SetCurrentConsoleFontEx (out, false, &info);
        }

    // ...а до этого все не так сладко

$   const unsigned uniFont = 10;  // The Internet and W2K sources know this magic number
$   const unsigned uniSize = 20;  // Size of the font desired, should be > max of Raster Fonts
$   bool ok = true;

    // Force Windows to use Unicode font by creating and run the console shortcut tuned to use that font.

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   if (Win32::GetNumberOfConsoleFonts && Win32::GetNumberOfConsoleFonts() <= uniFont)
        {
$       HRESULT init = Win32::CoInitialize (NULL);
$       size_t sz = 0;

$       char link [MAX_PATH] = "";
$       getenv_s (&sz, link, sizeof (link) - 1, "TEMP");
$       strncat_s (link, sizeof (link), "\\~txLink.lnk", sizeof (link) - 1);

$       char comspec [MAX_PATH] = "";
$       getenv_s (&sz, comspec, sizeof (comspec), "COMSPEC");

$       (void) _unlink (link);

$       _txCreateShortcut (link, comspec, "/c exit", NULL, NULL, SW_SHOWMINNOACTIVE, NULL, 0, uniSize) asserted;

$       ok = (Win32::ShellExecuteA (NULL, NULL, link, NULL, NULL, SW_SHOWMINNOACTIVE) > (void*)32);  // Sic!
        if (ok) { $ _txWaitFor (FindWindow (NULL, "~txLink"), _TX_TIMEOUT); }

$       (void) _unlink (link);

$       if (init == S_OK) Win32::CoUninitialize();
        }

    // If Unicode font is not already set, do set it.

$   CONSOLE_FONT_INFO cur = {0};
    if (Win32::GetCurrentConsoleFont) { $ Win32::GetCurrentConsoleFont (out, false, &cur); }

$   ok &= (cur.nFont >= uniFont);
    if (!ok) { $ ok &= Win32::SetConsoleFont && Win32::SetConsoleFont (out, uniFont); }

$   HWND console = Win32::GetConsoleWindow();
$   InvalidateRect (console, NULL, false);
$   UpdateWindow   (console);

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------
//{          The assistants to the nightmare. You can use it freely to make your own nightmare sweet.

#define      _TX_TRY                { goto __tx_try; } __tx_try: { int __tx_error = S_OK; (void)__tx_error;
#define      _TX_CHECKED( cmd )     { if (FAILED (__tx_error = (cmd))) goto __tx_catch; }
#define      _TX_FAIL               { __tx_error = E_FAIL; goto __tx_catch; }
#define      _TX_RETRY              { __tx_error = S_OK;   goto __tx_try;   }
#define      _TX_OK                 ( SUCCEEDED (__tx_error) )
#define      _TX_CATCH              goto __tx_finally; __tx_catch:
#define      _TX_RETURN             goto __tx_finally;
#define      _TX_FINALLY            __tx_finally:
#define      _TX_ENDTRY             }

//}
//-----------------------------------------------------------------------------------------------------------------

// Мало не покажется

bool _txCreateShortcut (const char shortcutName[],
                        const char fileToLink[], const char args[] /*= NULL*/, const char workDir[] /*= NULL*/,
                        const char description[] /*= NULL*/, int cmdShow /*= SW_SHOWNORMAL*/, const char iconFile[] /*= NULL*/, int iconIndex /*= 0*/,
                        int fontSize /*= 0*/, COORD bufSize /*= ZERO (COORD)*/, COORD wndSize /*= ZERO (COORD)*/, COORD wndOrg /*=ZERO (COORD)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (shortcutName && *shortcutName) return false;
$   _TX_IF_ARGUMENT_FAILED (fileToLink   && *fileToLink)   return false;

$   IShellLink* shellLink = NULL;
$   Win32::IShellLinkDataList* dataList = NULL;
$   IPersistFile* file = NULL;

$   HRESULT init = Win32::CoInitialize (NULL);

    _TX_TRY
        {
$       _TX_CHECKED (Win32::CoCreateInstance (CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER, Win32::IID_IShellLink, (void**) &shellLink));
$       if (!shellLink) _TX_FAIL;

$       shellLink->SetPath (fileToLink);
$       shellLink->SetArguments (args);
$       shellLink->SetWorkingDirectory (workDir);
$       shellLink->SetDescription (description);
$       shellLink->SetShowCmd (cmdShow);
$       shellLink->SetIconLocation (iconFile, iconIndex);

$       _TX_CHECKED (shellLink->QueryInterface (Win32::IID_IShellLinkDataList, (void**) &dataList));
$       if (!dataList) _TX_FAIL;

$       Win32::NT_CONSOLE_PROPS props =
          {{sizeof (props), NT_CONSOLE_PROPS_SIG},

            0x07, 0xF5,                                 // wFillAttribute, wPopupFillAttribute
           {bufSize.X, bufSize.Y},                      // dwScreenBufferSize
           {wndSize.X, wndSize.Y},                      // dwWindowSize
           {wndOrg.X,  wndOrg.Y},                       // dwWindowOrigin
            0,                                          // nFont
            0,                                          // nInputBufferSize
           {0, (short) fontSize},                       // dwFontSize
            0x36, 400, L"Lucida Console",               // uFontFamily, uFontWeight, FaceName. We're dancing for this!
            15,                                         // uCursorSize
            0,  1, 1, 0,                                // bFullScreen, bQuickEdit, bInsertMode, bAutoPosition
            50, 4, 0,                                   // uHistoryBufferSize, uNumberOfHistoryBuffers, bHistoryNoDup

           {0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080, 0xC0C0C0,
            0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF}
            };

$       _TX_CHECKED (dataList->AddDataBlock (&props));

$       _TX_CHECKED (shellLink->QueryInterface (Win32::IID_IPersistFile, (void**) &file));
$       if (!file) _TX_FAIL;

$       wchar_t wName[MAX_PATH] = L"";
$       MultiByteToWideChar (_TX_CP, 0, shortcutName, -1, wName, MAX_PATH) || ZeroMemory (wName, sizeof (wName));

$       _TX_CHECKED (file->Save (wName, true));
        }

$   _TX_CATCH
$   _TX_FINALLY

$   if (file)      file     ->Release();
$   if (dataList)  dataList ->Release();
$   if (shellLink) shellLink->Release();

$   if (init == S_OK) Win32::CoUninitialize();

$   return _TX_OK;
    _TX_ENDTRY
    }

//}
//-----------------------------------------------------------------------------------------------------------------

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Memory DC functions                 (_txBuffer...)
//! @name    Функции "вирт.холста" (граф.буфера) (_txBuffer...)
//=================================================================================================================
//! @{

HDC _txBuffer_Create (HWND wnd, const POINT* size, HBITMAP bitmap)
    {
$1  txAutoLock _lock;

$   HDC wndDC = GetDC (wnd);
$   if (!wndDC) return NULL;

$   POINT sz = { 1, 1 };
$   if (size) sz = *size;

$   if (!size && wnd)
        {
$       RECT r = {0};
$       GetClientRect (wnd, &r) asserted;

$       sz.x = r.right  - r.left;
$       sz.y = r.bottom - r.top;
        }

$   if (bitmap)
        {
$       BITMAP bmap = {0};
$       Win32::GetObject (bitmap, sizeof (bmap), &bmap) asserted;

$       sz.x = bmap.bmWidth;
$       sz.y = bmap.bmHeight;
        }

$   HDC dc = Win32::CreateCompatibleDC (wndDC);
$   if (!dc) TX_DEBUG_ERROR ("Cannot create buffer: CreateCompatibleDC() failed");

$   HBITMAP bmap = bitmap? bitmap : Win32::CreateCompatibleBitmap (wndDC, sz.x, sz.y);
$   if (!bmap) TX_DEBUG_ERROR ("Cannot create buffer: CreateCompatibleBitmap() failed");

$   Win32::SelectObject (dc, bmap) asserted;

$   if (!bitmap) Win32::PatBlt (dc, 0, 0, sz.x, sz.y, BLACKNESS) asserted;

$   ReleaseDC (wnd, wndDC) asserted;

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txBuffer_Delete (HDC* dc)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;
$   if (!*dc) return false;

$   if (!Win32::GetObjectType (Win32::GetCurrentObject (*dc, OBJ_BITMAP))) return false;

$   txAutoLock _lock;

$   _txBuffer_Select (Win32::GetStockObject         (NULL_PEN),    *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject         (NULL_BRUSH),  *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject         (SYSTEM_FONT), *dc) asserted;
$   _txBuffer_Select (Win32::CreateCompatibleBitmap (*dc, 0, 0),   *dc) asserted;

$   Win32::DeleteObject (Win32::GetCurrentObject (*dc, OBJ_BITMAP)) asserted;

$   Win32::DeleteDC (*dc) asserted;

$   *dc = NULL;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txBuffer_Select (HGDIOBJ obj, HDC dc /*= txDC()*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (obj) return false;
$   _TX_IF_ARGUMENT_FAILED (dc)  return false;

$   if (!Win32::GetObjectType (obj)) TX_DEBUG_ERROR ("Invalid GDI object type");

$   txAutoLock _lock;

$   obj = Win32::SelectObject (dc, obj);
$   if (obj) Win32::DeleteObject (obj);

$   return obj != NULL;
    }

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Diagnostics
//! @name    Диагностика
//=================================================================================================================
//! @{

const char* _txError (const char file[] /*= NULL*/, int line /*= 0*/, const char func[] /*= NULL*/, unsigned color /*= 0*/,
                      const char msg [] /*= NULL*/, ...)
    {                                                                        //------------------Это ASCII KOT!
$1  va_list arg; va_start (arg, msg);                                        //   /\_|_/\                     |
$$  const char* what = _txProcessError (file, line, func, color, msg, arg);  //  \| o o |/      Добавь его себе
    va_end (arg);                                                            // --\ =!= /--  в исходник, и тебе
                                                                             //  / \ v / \      будет, наверно,
    if (!(msg && msg[0] == '\a')) return what;                               //     ---    приятно отлаживаться
                                                                             //----------------долгими ночами:)
//  vvvvvvvvvvvvvvvvvv
    DebugBreak();   //>>> Котики, вы в отладчике. Не пугайтесь. Есть шанс посмотреть переменные и разобраться.
//  ^^^^^^^^^^^^^^^^^^

    return what;    //>>> Уходите из функции пошаговой отладкой (F10/F11). Следите за стеком вызовов (Alt+7).
    }

//-----------------------------------------------------------------------------------------------------------------
//{          General runtime check hooks
//-----------------------------------------------------------------------------------------------------------------

void _txOnSignal (int sig /*= 0*/, int fpe /*= 0*/)
    {
$1  if (!sig && !fpe)
        {
$       signal (SIGSEGV, (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGFPE,  (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGABRT, (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGILL,  (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       signal (SIGTERM, (void(*)(int))_txOnSignal) != SIG_ERR asserted;
$       return;
        }

    txOutputDebugPrintf ("\r" "%s - WARNING: %s (%d, %d) called", _TX_VERSION, __func__, sig, fpe);

    #define GET_DESCR_(str, code, descr)  case (code): { $ (str) = " " #code ": " descr; break; }

$   const char* sSig = "Неизвестный тип сигнала";

$   switch (sig)
        {
        GET_DESCR_ (sSig, SIGSEGV, "Доступ по неверному указателю. Ставьте ассерты!")
        GET_DESCR_ (sSig, SIGILL,  "Попытка выполнить недопустимую операцию. Проверьте указатели на функции.")
        GET_DESCR_ (sSig, SIGABRT, "Аварийное завершение программы, вызвана функция abort().")
        GET_DESCR_ (sSig, SIGTERM, "Получен сигнал принудительного завершения программы.")
        GET_DESCR_ (sSig, SIGFPE,  "Грубая ошибка в вычислениях.")
        default:   break;
        }

$   const char* sFPE = "";

    #if defined (_MSC_VER)

    // MSVC provides the FPE code as a MS extension.
    // See: https://msdn.microsoft.com/ru-ru/library/xdkz3x12.aspx

$   if (sig == SIGFPE) switch (fpe)
        {
        GET_DESCR_ (sFPE, _FPE_INVALID,        "Результат неверен.")
        GET_DESCR_ (sFPE, _FPE_DENORMAL,       "Денормализация.")
        GET_DESCR_ (sFPE, _FPE_ZERODIVIDE,     "Деление на ноль.")
        GET_DESCR_ (sFPE, _FPE_OVERFLOW,       "Результат слишком большой.")
        GET_DESCR_ (sFPE, _FPE_UNDERFLOW,      "Результат слишком маленький.")
        GET_DESCR_ (sFPE, _FPE_INEXACT,        "Результат неточен.")
        GET_DESCR_ (sFPE, _FPE_UNEMULATED,     "Операция не поддерживается.")
        GET_DESCR_ (sFPE, _FPE_SQRTNEG,        "Квадратный корень из отрицательного числа.")
        GET_DESCR_ (sFPE, _FPE_STACKOVERFLOW,  "Переполнение стека сопроцессора.")
        GET_DESCR_ (sFPE, _FPE_STACKUNDERFLOW, "В стеке сопроцессора не хватает данных.")
        GET_DESCR_ (sFPE, _FPE_EXPLICITGEN,    "Явный вызов исключения.")
        default:   break;
        }

    #else
$   fpe = 0;
    #endif

    #undef GET_DESCR_

$   signal (sig, (void(*)(int))_txOnSignal);
$   _fpreset();

$   _TX_UNEXPECTED ("\a\t"
                    "signal (%d, 0x%02X):%s%s "
                    "%s%s"
                    "С помощью функции signal() вы можете сами обработать эту ошибку." _
                    sig _ (unsigned) fpe _ sSig _ sFPE _
                    ((_txDumpSE[1] == '\n')? "" : "\n\n")_ _txDumpSE + 1);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnTerminate()
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s() called", _TX_VERSION, __func__);

    // From: http://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/libsupc%2B%2B/vterminate.cc

$1  static int terminating = 0;
    if (terminating++) { $ _TX_UNEXPECTED ("\a" "std::terminate() вызвана рекурсивно."); return; }

$   if (!*_txDumpSE)
        { $ _txDumpExceptionCPP (_txDumpSE + 1, sizeof (_txDumpSE) - 2); }

$   _TX_UNEXPECTED ("\t\a"
                    "std::terminate(): Неперехваченное исключение в функции main() или в деструкторе, "
                    "или другая фатальная ошибка C++."
                    "%s"
                    "Используйте try/catch блоки, перехватывайте catch (...), проверяйте вызовы виртуальных функций, "
                    "разбирайтесь, в чем дело.\n\n"
                    "С помощью std::set_terminate() вы можете сами обработать эту ошибку." + !_txDumpSE _
                    _txDumpSE + 1);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnUnexpected()
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s() called", _TX_VERSION, __func__);

$1  if (!*_txDumpSE)
        { $ _txDumpExceptionCPP (_txDumpSE + 1, sizeof (_txDumpSE) - 2); }

$   _TX_UNEXPECTED ("std::unexpected(): Необработанное исключение.\n\n"
                    "Проверьте свои catch-блоки. Перехватите catch (...). Если вы (зря) используете "
                    "спецификацию исключений для функций, проверьте, не нарушена ли она."
                    "%s"
                    "С помощью std::set_unexpected() вы можете сами обработать эту ошибку." _
                    _txDumpSE + 1);
    }

//-----------------------------------------------------------------------------------------------------------------

int _txOnMatherr (_exception* exc)
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s (0x%p) called", _TX_VERSION, __func__, exc);

    #define GET_DESCR_(code, descr)  case (code): { $ sType = "(" #code "): " descr; break; }

$1  const char* sType = "Неизвестный тип исключения";

$   switch (exc->type)
        {
        GET_DESCR_ (_DOMAIN,    "Нарушение области определения");
        GET_DESCR_ (_SING,      "Сингулярность аргумента");
        GET_DESCR_ (_PLOSS,     "Частичная потеря значимости");
        GET_DESCR_ (_TLOSS,     "Полная потеря значимости");
        GET_DESCR_ (_OVERFLOW,  "Результат слишком большой");
        GET_DESCR_ (_UNDERFLOW, "Результат слишком маленький");
        default:   break;
        }

    #undef GET_DESCR_

$   _TX_UNEXPECTED ("_matherr(): Математическая ошибка %d %s в функции %s (%lg, [%lg]). Она вернет значение %lg.\n\n"
                    "С помощью __setusermatherr() вы можете сами обработать эту ошибку." _
                    exc->type _ sType _ exc->name _ exc->arg1 _ exc->arg2 _ exc->retval);

    return 0;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnNewHandlerAnsi()
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s() called", _TX_VERSION, __func__);
$1
$   _TX_UNEXPECTED ("operator new: Ошибка выделения памяти.\n\n"
                    "С помощью std::set_new_handler() вы можете сами обработать эту ошибку "
                    "и где-нибудь найти недостающую память.");

$   throw std::bad_alloc();
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnSecurityErrorAnsi (const char* msg, void* ptr, int code)
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s (%s, 0x%p, %d) called", _TX_VERSION, __func__, msg, ptr, code);

$1  if (code)
        { $ errno = code; }

$   _TX_UNEXPECTED ("\a"
                    "Ошибка переполнения буфера %d: %s в %.20s (0x%p). Ставьте ассерты!\n\n"
                    "С помощью std::set_constraint_handler_s() вы можете сами обработать эту ошибку "
                    "и постараться не выходить за границы массивов." _
                    code _ msg _ (char*) ptr _ ptr);
    }

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          MSC Runtime check hooks
//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

//-----------------------------------------------------------------------------------------------------------------

int _txOnNewHandler (size_t size)
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s (0x%p) called", _TX_VERSION, __func__, (void*)(uintptr_t) size);
$1
$   _TX_UNEXPECTED ("operator new: Ошибка выделения %llu байт памяти.\n\n"
                    "С помощью _set_new_handler() вы можете сами обработать эту ошибку "
                    "и где-нибудь найти недостающую память." _ (unsigned long long) size);

$   throw std::bad_alloc();
$   return 0;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnSecurityError (int code, void* addr)
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s (%d, 0x%p) called", _TX_VERSION, __func__, code, addr);
$1
$   _TX_UNEXPECTED ("\a"
                    "Ошибка переполнения буфера %d (_SECERR_BUFFER_OVERRUN). Ставьте ассерты!\n\n"
                    "С помощью _set_security_error_handler() вы можете сами обработать эту ошибку "
                    "и более торжественно завершить программу. Ставьте же ассерты." _ code);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnPureCall()
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s() called", _TX_VERSION, __func__);
$1
$   _TX_UNEXPECTED ("\a"
                    "Вызвана чисто виртуальная функция. Такое бывает, например, в конструкторах "
                    "или деструкторах базовых классов - не вызывайте там таких функций.\n\n"
                    "С помощью _set_purecall_handler() вы можете сами обработать эту ошибку "
                    "и проверить свое знание С++ :)");
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnInvalidParam (const wchar_t* wExpr, const wchar_t* wFunc, const wchar_t* wFile, unsigned int line, uintptr_t addr)
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s (%S, %S, %S, %d, 0x%p) called", _TX_VERSION, __func__, wExpr, wFunc, wFile, line, addr);

$1  char expr [_TX_BUFSIZE/2] = "[Unknowm expr]",
         func [_TX_BUFSIZE/2] = "[Unknowm func]",
         file [MAX_PATH]      = "[Unknowm file]";

$   WideCharToMultiByte (_TX_CP, 0, wExpr, -1, expr, sizeof (expr) - 1, NULL, NULL);
$   WideCharToMultiByte (_TX_CP, 0, wFunc, -1, func, sizeof (func) - 1, NULL, NULL);
$   WideCharToMultiByte (_TX_CP, 0, wFile, -1, file, sizeof (file) - 1, NULL, NULL);

$$  _txError (file, line, func, 0, "\a"
              "В функцию %s передан неверный параметр: неверно, что %s. Не надо так.\n\n"
              "С помощью _set_invalid_parameter_handler() вы можете сами обработать эту ошибку.", func, expr);
    }

//-----------------------------------------------------------------------------------------------------------------

#pragma runtime_checks ("", off)

int _txOnRTCFailure (int type, const char* file, int line, const char* module, const char* format, ...)
    {
    txOutputDebugPrintf ("\r" "%s - WARNING: %s (%d, %s, %d, %s, %s) called", _TX_VERSION, __func__, type, file, line, module, format);

$1  static long running = 0;
$   while (InterlockedExchange (&running, 1)) Sleep (0);

    // Disable all RTC failures

$   int nErrors = _RTC_NumErrors();
$   int* errors = NULL;
$   try { errors = (int*) _alloca (nErrors * sizeof (*errors)); } catch (...) { $ }

$   int err = 0;
$   for (int i = 0; i < nErrors; i++) *(errors? &errors[i] : &err) = _RTC_SetErrorType ((_RTC_ErrorNumber) i, _RTC_ERRTYPE_IGNORE);

$   char text [_TX_BUFSIZE] = "";

$   va_list arg; va_start (arg, format);
$   _tx_vsnprintf_s (text, sizeof (text) - 1, format, arg);   // Get message from the vararg list
$   _RTC_ErrorNumber error = va_arg (arg, _RTC_ErrorNumber);  // Get the RTC error number (note that arg changes)
$   va_end (arg);

$   const char* sType = "type";

$   switch (type)
       {
       case _CRT_ERROR:  $ sType = "ошибка";            break;
       case _CRT_ASSERT: $ sType = "логическая ошибка"; break;
       case _CRT_WARN:   $ sType = "возможная ошибка";  break;
       default:          $                              break;
       }

$   const char* sError = _RTC_GetErrDesc (error);

$$  _txError (file, line, NULL, 0, "\a"
              "Сбой проверки выполнения машинного кода: %s %d (%s): %s в модуле %s.", sType, error, sError, text, module);

    // The code below will be never executed until the error above will stay fatal:

    // Restore the RTC error types

    #ifdef _MSC_VER
    #pragma warning (disable: 6385)  // Reading invalid data from 'errors': the readable size is 'n' bytes, but 'm' bytes may be read.
    #endif

$   for (int i = 0; i < nErrors; i++) _RTC_SetErrorType ((_RTC_ErrorNumber) i, (errors? errors[i] : _CRT_ERROR));

    #ifdef _MSC_VER
    #pragma warning (default: 6385)  // Reading invalid data from 'errors': the readable size is 'n' bytes, but 'm' bytes may be read.
    #endif

$   InterlockedExchange (&running, 0);
$   return 1;
    }

#pragma runtime_checks ("", restore)

//-----------------------------------------------------------------------------------------------------------------

int _txOnAllocHook (int type, void* data, size_t size, int use, long request, const unsigned char* file, int line)
    {
    #if (_TX_ALLOW_TRACE +0 >= 4)

    static _tx_thread int recursive = 0;
    if (recursive) return true;
    recursive++;

    #define GET_DESCR_(str, type)  case (type): { $ str = " (" #type ")"; break; }

$1  const char* sType = "";
$   const char* sUse  = "";

$   switch (_BLOCK_TYPE (type))
        {
        GET_DESCR_ (sType, _HOOK_ALLOC);
        GET_DESCR_ (sType, _HOOK_REALLOC);
        GET_DESCR_ (sType, _HOOK_FREE);
        default: $ break;
        }

$   switch (use)
        {
        GET_DESCR_ (sUse,  _NORMAL_BLOCK);
        GET_DESCR_ (sUse,  _CRT_BLOCK);
        GET_DESCR_ (sUse,  _CLIENT_BLOCK);
        GET_DESCR_ (sUse,  _FREE_BLOCK);
        GET_DESCR_ (sUse,  _IGNORE_BLOCK);
        default: $ break;
        }

    #undef  GET_DESCR_

$   _txTrace ((const char*) file, line, NULL, "%*s"
              "_txOnAllocHook (type = 0x%02X%s, subtype =0x%X, data = 0x%p, size = 0x%p, use = 0x%02X%s, request = %ld)",
              12 - _txLocCur.inTX*2, "",
              type, sType, _BLOCK_SUBTYPE (type), data, (void*) size, use, sUse, request);

$   recursive--;

    #else

    UNREFERENCED_PARAMETER (type);
    UNREFERENCED_PARAMETER (data);
    UNREFERENCED_PARAMETER (size);
    UNREFERENCED_PARAMETER (use);
    UNREFERENCED_PARAMETER (request);
    UNREFERENCED_PARAMETER (file);
    UNREFERENCED_PARAMETER (line);

    #endif

    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

#endif

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          SEH staff
//-----------------------------------------------------------------------------------------------------------------

long WINAPI _txVectoredExceptionHandler (EXCEPTION_POINTERS* exc)
    {
    return _txOnExceptionSEH (exc, "_txVectoredExceptionHandler");
    }

//-----------------------------------------------------------------------------------------------------------------

long WINAPI _txUnhandledExceptionFilter (EXCEPTION_POINTERS* exc)
    {
    long res = _txOnExceptionSEH (exc, "_txUnhandledExceptionFilter");

    if (_txPrevUEFilter)
        {
        if (setjmp (_txDumpExceptionObjJmp) == 0)
            {
            res = _txPrevUEFilter (exc);
            }
        else
            {
$1          *(unsigned long long*) _txDumpExceptionObjJmp = 0;

            _TX_UNEXPECTED ("\t\a"
                            "%s"
                            "С помощью функции _set_se_translator() вы можете сами обработать эту ошибку.\n\n"
                            "Дополнительно: Сбой вызова стандартного обработчика неперехваченнных исключений SEH." + !_txDumpSE _
                            _txDumpSE + 1);
            }
        }

    return res;
    }

//-----------------------------------------------------------------------------------------------------------------

LPTOP_LEVEL_EXCEPTION_FILTER WINAPI _txOnSetUnhandledExceptionFilter (LPTOP_LEVEL_EXCEPTION_FILTER filter)
    {
$1  _txPrevUEFilter = filter;
    return _txUnhandledExceptionFilter;
    }

//-----------------------------------------------------------------------------------------------------------------

long _txOnExceptionSEH (EXCEPTION_POINTERS* exc, const char func[])
    {
    assert (exc);
    assert (exc->ExceptionRecord);

    assert (func);
    assert (func[3] == 'V' || func[3] == 'U');

    DWORD code = (exc && exc->ExceptionRecord)? exc->ExceptionRecord->ExceptionCode : 0;

    if (code == EXCEPTION_OUTPUT_DEBUG_STRING   ||
        code == EXCEPTION_OUTPUT_DEBUG_STRING_W ||
        code == EXCEPTION_THREAD_NAME           ||
        code == EXCEPTION_BREAKPOINT && IsDebuggerPresent())
        return EXCEPTION_CONTINUE_SEARCH;

    txOutputDebugPrintf ("\r" "%s - WARNING: %s (0x%p (code 0x%08lX), %s) called", _TX_VERSION, __func__, exc, code, func);

$1  if (*(unsigned long long*) _txDumpExceptionObjJmp)
        {
$       longjmp (_txDumpExceptionObjJmp, 1);
        }

    tx_fpreset();

    #ifdef _MSC_VER
    if (code == EXCEPTION_STACK_OVERFLOW) { $ _resetstkoflw(); }
    #endif

$   bool primaryException = (func && exc)? ((func[3] == 'V' || (func[3] == 'U' && !*_txDumpSE)) &&
                                            !_TX_MSC__CXX_DETECT_RETHROW (exc->ExceptionRecord)) : true;
$   if (primaryException)
        {
$       unsigned err = GetLastError();

$       _txDumpExceptionSEH (_txDumpSE,  (ptrdiff_t) sizeof (_txDumpSE)  - 1, exc->ExceptionRecord, func);

$       if (code != EXCEPTION_STACK_OVERFLOW)
            {
$           _tx_snprintf_s  (_txTraceSE, (ptrdiff_t) sizeof (_txTraceSE) - 1, "%s", _txCaptureStackBackTrace (0, true, exc->ContextRecord));
            }

$       SetLastError (err);
        }

$   if (_txDumpSE[0] == '\a')
        {
$       _TX_UNEXPECTED ("\a\t"
                        "%s"
                        "С помощью функции _set_se_translator() вы можете сами обработать эту ошибку." _
                        _txDumpSE + 1);
        }

$   return EXCEPTION_CONTINUE_SEARCH;
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t _txDumpExceptionSEH (char what[], ptrdiff_t size, const EXCEPTION_RECORD* exc, const char func[])
    {
$1  assert (what);
$   assert (size >= 0);
$   assert (exc);

$   unsigned         code   = exc->ExceptionCode;
$   void*            addr   = exc->ExceptionAddress;
$   unsigned         params = exc->NumberParameters;
$   const ULONG_PTR* info   = exc->ExceptionInformation;
$   void*            object = (params >= 2)? (void*) info[1] : NULL;

$   char* s = what;

    #define PRINT_(msg)  s += _tx_snprintf_s (s, size-2 - (s-what), msg)

$   const char* sCode  = NULL;
$   const char* sDescr = NULL;

    #define GET_DESCR_(code, descr)  case (code): { $ sCode = #code; sDescr = descr; break; }

$   switch (code)
        {
        GET_DESCR_ (EXCEPTION_ACCESS_VIOLATION,         " "  "Нарушение доступа к памяти.")
        GET_DESCR_ (EXCEPTION_ILLEGAL_INSTRUCTION,      " "  "Недопустимая операция.")
        GET_DESCR_ (EXCEPTION_PRIV_INSTRUCTION,         " "  "Привилегированная операция.")
        GET_DESCR_ (EXCEPTION_ARRAY_BOUNDS_EXCEEDED,    "\a" "Выход за границы массива. Ставьте ассерты!")
        GET_DESCR_ (EXCEPTION_BREAKPOINT,               "\a" "Достигнута точка останова. Удачи в отладке!")
        GET_DESCR_ (EXCEPTION_DATATYPE_MISALIGNMENT,    "\a" "Нарушение выравнивания данных.")
        GET_DESCR_ (EXCEPTION_INVALID_DISPOSITION,      "\a" "Обработчик исключения возвратил неверное значение.")
        GET_DESCR_ (EXCEPTION_IN_PAGE_ERROR,            "\a" "Невозможно загрузить нужную страницу памяти.")
        GET_DESCR_ (EXCEPTION_NONCONTINUABLE_EXCEPTION, "\a" "Продолжение выполнения невозможно.")
        GET_DESCR_ (EXCEPTION_SINGLE_STEP,              "\a" "Выполнена инструкция машинного кода. Одна штука.")
        GET_DESCR_ (EXCEPTION_STACK_OVERFLOW,           "\a" "Ю-ху! Переполнение стека!")
        GET_DESCR_ (EXCEPTION_GUARD_PAGE,               "\a" "Попытка доступа к защищенной странице памяти.")
        GET_DESCR_ (EXCEPTION_INVALID_HANDLE,           "\a" "Неверный или уже закрытый дескриптор.")
        GET_DESCR_ (EXCEPTION_POSSIBLE_DEADLOCK,        "\a" "Возможно, взаимная блокировка ресурсов.")

        GET_DESCR_ (EXCEPTION_FLT_DENORMAL_OPERAND,     " "  "Денормализация числа с плавающей точкой.")
        GET_DESCR_ (EXCEPTION_FLT_DIVIDE_BY_ZERO,       " "  "Деление на ноль при операции с плавающей точкой.")
        GET_DESCR_ (EXCEPTION_FLT_INEXACT_RESULT,       " "  "Неточный результат при операции с плавающей точкой.")
        GET_DESCR_ (EXCEPTION_FLT_INVALID_OPERATION,    " "  "Недопустимая операция с плавающей точкой.")
        GET_DESCR_ (EXCEPTION_FLT_OVERFLOW,             " "  "Переполнение при операции с плавающей точкой.")
        GET_DESCR_ (EXCEPTION_FLT_UNDERFLOW,            " "  "Потеря значимости при операции с плавающей точкой.")
        GET_DESCR_ (STATUS_FLOAT_MULTIPLE_FAULTS,       " "  "Множественные ошибки с плавающей точкой.")
        GET_DESCR_ (EXCEPTION_FLT_STACK_CHECK,          "\a" "Ошибка стека при операции с плавающей точкой.")

        GET_DESCR_ (EXCEPTION_INT_DIVIDE_BY_ZERO,       "\a" "Целочисленное деление на ноль.")
        GET_DESCR_ (EXCEPTION_INT_OVERFLOW,             "\a" "Переполнение при целочисленной операции.")

        GET_DESCR_ (EXCEPTION_THREAD_NAME,              "\a" "Служебное исключение для именования потока.")
        GET_DESCR_ (EXCEPTION_CLR_FAILURE,              "\a" "Сбой среды исполнения языка Си (CLR).")
        GET_DESCR_ (EXCEPTION_BUFFER_OVERFLOW,          "\a" "Переполнение стекового буфера!")
        GET_DESCR_ (STATUS_ASSERTION_FAILURE,           "\a" "Сработал assert. На этот раз из ядра.")
        GET_DESCR_ (STATUS_WX86_BREAKPOINT,             "\a" "Точка останова подсистемы эмуляции x86.")
        GET_DESCR_ (DBG_TERMINATE_THREAD,               "\a" "Отладчик завершил поток сознания.")
        GET_DESCR_ (DBG_TERMINATE_PROCESS,              "\a" "Отладчик завершил процесс.")
        GET_DESCR_ (DBG_CONTROL_C,                      "\a" "Отладчик получил сигнал прерывания Control+C.")
        GET_DESCR_ (DBG_CONTROL_BREAK,                  "\a" "Отладчик получил сигнал прерывания Control+Break.")
        GET_DESCR_ (RPC_S_UNKNOWN_IF,                   "\a" "Неизвестный интерфейс удаленного вызова процедур (RPC).")
        GET_DESCR_ (RPC_S_SERVER_UNAVAILABLE,           "\a" "Сервер удаленного вызова процедур (RPC) недоступен.")

        GET_DESCR_ (EXCEPTION_CPP_MSC,                  " "  "Исключение С++, вызванное оператором throw.")
        GET_DESCR_ (EXCEPTION_CPP_GCC,                  " "  "Исключение С++, вызванное оператором throw.")
        GET_DESCR_ (EXCEPTION_CPP_GCC_UNWIND,           "\a" "Исключение С++, вызванное во время раскрутки стека.")
        GET_DESCR_ (EXCEPTION_CPP_GCC_FORCED,           "\a" "Исключение С++, вызванное нарушением магии.")
        GET_DESCR_ (EXCEPTION_CPP_BORLAND_BUILDER,      "\a" "Это скомпилилось под Билдер? O_O")
        GET_DESCR_ (EXCEPTION_CPP_BORLAND_DELPHI,       "\a" "Это же С++. Как это вышло?")

        GET_DESCR_ (EXCEPTION_OUTPUT_DEBUG_STRING,      " "  "Отладчик вывел исключение по CTRL+C (OutputDebugString)")

        default: $ break;
        }

    #undef GET_DESCR_

$   if (sDescr)
        {
$       PRINT_ ("%s\n\n"
                "Исключение %s" _ sDescr _ sCode);
        }
    else
        {
$       PRINT_ ("\a");
$       s += FormatMessage (FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS,
                            GetModuleHandle ("NTDLL.DLL"), code, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                            s, (DWORD) (size - (s-what)), NULL) - 2;
$       PRINT_ ("\r\r");
        }

$   PRINT_ (" (0x%lX) при выполнении кода по адресу" _ code);
$   PRINT_ ((addr? " 0x%p" : " NULL")_ addr);

$   Win32::SYMBOL_INFO*     sym  = NULL;
$   Win32::IMAGEHLP_LINE64* line = NULL;

    if (addr) { $ _txSymGetFromAddr (addr, &sym, &line); }

$   if (sym  && sym->Name      && *sym->Name)      PRINT_ (" в функции %s" _ sym->Name);
$   if (line && line->FileName && *line->FileName) PRINT_ (" в файле %s на строке %u" _ line->FileName _ line->LineNumber);

$   if (code == EXCEPTION_ACCESS_VIOLATION ||
        code == EXCEPTION_IN_PAGE_ERROR)
        {
$       PRINT_ (". Попытка ");

$       unsigned long op = 0xBADC0DE;
$       const char*  sOp = "(действие не указано)";

$       if (params >= 1)
            {
$           switch (op = (unsigned long) info[0])
                {
                case 0:  $ sOp = "прочесть данные";          break;
                case 1:  $ sOp = "записать данные";          break;
                case 8:  $ sOp = "исполнить код";            break;
                default: $ sOp = "совершить операцию 0x%lX"; break;
                }
            }

$       PRINT_ (sOp _ op);

$       if (params >= 2) { $ PRINT_ ((object? " по адресу 0x%p" : " по адресу NULL")_ object); }
        else             { $ PRINT_ (" (адрес не указан)"); }

$       if (code == EXCEPTION_IN_PAGE_ERROR)
            {
$           PRINT_ (", ошибка ввода-вывода:");

$           if (params >= 3)
                {
$               unsigned long ntstatus = (unsigned long) info[2];

$               PRINT_ (" 0x%lX (" _ ntstatus);

$               s += FormatMessage (FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS,
                                    GetModuleHandle ("NTDLL.DLL"), ntstatus, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                                    s, (DWORD) (size - (s-what)), NULL) - 2;
$               PRINT_ (")");
                }
            else
                { $ PRINT_ (" (не указана)"); }
            }
        }

$   HMODULE module = NULL;
$   if (Win32::GetModuleHandleEx)
        { $ Win32::GetModuleHandleEx (GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (const char*) addr, &module); }

$   if (module)
        {
$       static char sModule [MAX_PATH] = "";
$       int ok = GetModuleFileName (module, sModule, sizeof (sModule));

$       char* ext = (ok? strrchr (sModule, '.') : NULL);
$       if (ext) _strlwr_s (ext, sizeof (sModule) - 1 - (ext - sModule));

        if (ok) { $ PRINT_ (" в модуле %s" _  sModule); }
        else    { $ PRINT_ (" в модуле 0x%p" _ module); }
        }

$   PRINT_ (". Спасибо %s(), что сообщил. Люблю его <3" _ func);

$   if (code == EXCEPTION_CPP_GCC        ||
        code == EXCEPTION_CPP_GCC_UNWIND ||
        code == EXCEPTION_CPP_GCC_FORCED ||
        code == EXCEPTION_CPP_MSC)
        {
$       s += _txDumpExceptionCPP (what, size, code, params, info);  // In this case, SEH info is not interesting
        }

$   if (exc->ExceptionFlags & EXCEPTION_NONCONTINUABLE)
        {
$       PRINT_ ("\n\n" "Ой, всё (EXCEPTION_NONCONTINUABLE).");
        }

$   if (exc->ExceptionRecord)
        {
$       PRINT_ ("\n\n" "Причина:" "\n\n");
$       s += _txDumpExceptionSEH (s, size - (s-what), exc->ExceptionRecord, func);
        }

    #undef PRINT_

$   s += _tx_snprintf_s (s, size - (s-what), "\n\n");

$   return s - what;
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t _txDumpExceptionCPP (char what[], ptrdiff_t size,
                               unsigned code /*= 0*/, unsigned params /*= 0*/, const ULONG_PTR info[] /*= NULL*/)
    {
$1  assert (what);
$   assert (size >= 0);

$   char* s = what;

$   switch (code)
        {
        #if defined (_GCC_VER)

        case EXCEPTION_CPP_GCC:
        case EXCEPTION_CPP_GCC_UNWIND:
        case EXCEPTION_CPP_GCC_FORCED:
            {
            // See: [1] http://llvm.org/svn/llvm-project/libcxxabi/trunk/src/cxa_exception.cpp
            //      [2] http://github.com/gcc-mirror/gcc/blob/master/libgcc/unwind-seh.c, lines 51-55 and below
            //      [3] http://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/libsupc++/eh_throw.cc, __cxa_throw, line 59 and below
            //      [4] http://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/libsupc++/unwind-cxx.h, __cxa_exception, line 58 and below
            //      and figure above near ABI::__cxa_exception definition in this file

$           const std::type_info* type   = NULL;
$           void*                 object = NULL;

$           if (params >= 1)
                {
$               _Unwind_Exception*    unwind_exception = (_Unwind_Exception*) info[0];
$               ABI::__cxa_exception* cxa_exception    = (ABI::__cxa_exception*) (unwind_exception + 1) - 1;

$               type   = cxa_exception->exceptionType;
$               object = cxa_exception + 1;
                }

$           s += _txDumpExceptionObj (s, size - (s-what), object, 0, type);
            }
$           break;

        case 0:  // Not called within SEH chain
            {
            // From: [1] http://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/libsupc++/eh_type.cc
            //       [2] http://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/libsupc++/vterminate.cc

            #if (_GCC_VER >= 400)
            using namespace abi;
            #endif

$           ABI::__cxa_exception* cxa_exception = __cxa_get_globals() -> caughtExceptions;

$           if (cxa_exception && (cxa_exception->unwindHeader.exception_class & 1))  // Dependent exception, case B, see pic above
                {
$               cxa_exception = (((ABI::__cxa_exception*) (&cxa_exception->unwindHeader + 1) - 1) -> primaryException) - 1;
                }

$           if (cxa_exception)
                {
$               verify (cxa_exception->exceptionType == abi::__cxa_current_exception_type());

$               s += _txDumpExceptionObj (s, size, cxa_exception + 1, 0, cxa_exception->exceptionType);
                }
            }
$           break;

        #elif defined (_MSC_VER)

$       case EXCEPTION_CPP_MSC:
            {
            // See [1] http://blogs.msdn.microsoft.com/oldnewthing/20100730-00/?p=13273
            //     [2] http://www.openrce.org/articles/full_view/21
            //     [3] http://www.openrce.org/articles/full_view/23
            //     [4] http://yurichev.com/mirrors/RE/Recon-2012-Skochinsky-Compiler-Internals.pdf

$           const std::type_info* type   = NULL;
$           void*                 object = (params >= 2)? (void*) info[1] : NULL;
$           size_t                szObj  = 0;

$           if (params >= 3 &&
               (info[0] == EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER1 ||
                info[0] == EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER2 ||
                info[0] == EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER3 ||
                info[0] == EXCEPTION_CPP_MSC_EH_PURE_MAGIC_NUMBER1))
                {
$               const Win32::ThrowInfo* throwInfo = (const Win32::ThrowInfo*) info[2];

$               if (throwInfo && throwInfo->pCatchableTypeArray)
                    {
$                   HMODULE module = (params >= 4)? (HMODULE) info[3] : NULL;

                    #define RVA_(type, addr)  ( (type) ((uintptr_t) module + (uintptr_t) (addr)) )

$                   const Win32::CatchableTypeArray* cArray = RVA_(const Win32::CatchableTypeArray*, throwInfo->pCatchableTypeArray);
$                   const Win32::CatchableType*      cType  = RVA_(const Win32::CatchableType*,      cArray->arrayOfCatchableTypes[0]);

$                   type  = RVA_(const std::type_info*, cType->pType);
$                   szObj = cType->sizeOrOffset;

                    #undef  RVA_
                    }
                }

$           s += _txDumpExceptionObj (s, size - (s-what), object, szObj, type);
            }
            break;

        case 0:  // Not called within SEH chain

            // signal() handlers or unexpected()/terminate() are called after Vectored Exception in MSC:
            //
            // terminate() is called by __scrt_unhandled_exception_filter() in case of MSC exception.
            // See C:\Bin\Microsoft Visual Studio 14.0\VC\crt\src\vcruntime\utility_desktop.cpp
            //
            // signal() handlers are called by _seh_filter_exe(), which is called by _mainCRTStartup() in case of exception.
            // See C:\Bin\Microsoft Visual Studio 14.0\VC\crt\src\vcruntime\mcrtexe.cpp
            // and C:\Bin\Windows Kits\10\Source\10.0.10240.0\ucrt\misc\exception_filter.cpp
            // and http://msdn.microsoft.com/en-us/library/ff730818.aspx.
            //
            // So _txDumpSE information should have been recorded during previous call. Now do nothing.

$           break;

        #endif

        default:
$           txOutputDebugPrintf ("ERROR: Wrong call to %s: Unknown exception code 0x%08X" _ __TX_FUNCTION__ _ code);
$           break;
        }

$   if (s > what) s += _tx_snprintf_s (s, size - (s - what), "\n\n");

$   return (s - what);
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t _txDumpExceptionObj (char what[], ptrdiff_t size, void* object, size_t sizeObj, const std::type_info* type)
    {
$1  assert (what);
$   assert (size > 0);

$   static char*  s     = NULL; s     = what;
$   static size_t szObj = 0;    szObj = sizeObj;

    #define PRINT_(msg)  s += _tx_snprintf_s (s, size - (s - what), msg)

$   PRINT_ (" \n\n" "Объект исключения C++:");

$   const char* mangledName = (type)? type->name() : NULL;

$   char* typeName = NULL;
$   int err = 1;

    #ifdef _GCC_VER
$   typeName = ::abi::__cxa_demangle (mangledName, 0, 0, &err);
    #endif

$   const char* name = (!err && typeName)? typeName : mangledName;

$   if (name &&
       (strcmp (name, "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >")           == 0 ||
        strcmp (name, "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >")                   == 0))
        { $ name = "std::string"; }

$   if (name &&
       (strcmp (name, "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > *")         == 0 ||
        strcmp (name, "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > * __ptr64") == 0 ||
        strcmp (name, "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*")                  == 0))
        { $ name = "std::string*"; }

    if (name) { $ PRINT_ (" %s" _ name); }

    #ifdef _GCC_VER
$   free (typeName);
    #endif

$   err = 0;
$   if (mangledName)
        if (setjmp (_txDumpExceptionObjJmp) == 0)
            {
            #define PRINT_VAL_(fmt, typ, ...)                                                                            \
                else if (*type == typeid (      typ       )) { $ PRINT_ (" = " #fmt _ (* (typ* ) object) __VA_ARGS__); } \
                else if (*type == typeid (const typ       )) { $ PRINT_ (" = " #fmt _ (* (typ* ) object) __VA_ARGS__); } \
                else if (*type == typeid (      typ*      )) { $ PRINT_ (" = " #fmt _ (**(typ**) object) __VA_ARGS__); } \
                else if (*type == typeid (const typ*      )) { $ PRINT_ (" = " #fmt _ (**(typ**) object) __VA_ARGS__); } \
                else if (*type == typeid (      typ* const)) { $ PRINT_ (" = " #fmt _ (**(typ**) object) __VA_ARGS__); } \
                else if (*type == typeid (const typ* const)) { $ PRINT_ (" = " #fmt _ (**(typ**) object) __VA_ARGS__); }

            if (0) ;
            PRINT_VAL_ ("%s", char*)  PRINT_VAL_ ('%c', unsigned char)   PRINT_VAL_ (%s,   bool, ? "true" : "false")
            PRINT_VAL_ ( %d,  int)    PRINT_VAL_ ( %u,  unsigned int)    PRINT_VAL_ (%g,   float)
            PRINT_VAL_ ( %hd, short)  PRINT_VAL_ ( %hu, unsigned short)  PRINT_VAL_ (%lg,  double)
            PRINT_VAL_ ( %ld, long)   PRINT_VAL_ ( %lu, unsigned long)   PRINT_VAL_ ('%c', char)
            PRINT_VAL_ ("%s", std::string, .c_str())

            else if (std::exception* e = dynamic_cast <std::exception*> ( (std::exception* ) object))
                {
$               PRINT_ (", what(): \"%s\"" _ e->what());
                }
            else
                { $ err = 1; }
            }
        else
            { $ err = 2; }

$   *(unsigned long long*) _txDumpExceptionObjJmp = 0;

$   if (err && object && szObj)
        {
$       const unsigned char* buf = (const unsigned char*) object;

$       if (szObj >= 64) szObj = 64;

$       PRINT_ (", дамп: [");
$       for (size_t i = 0; i < szObj; i++) PRINT_ ("%c" _ (isprint (buf[i]) && !iscntrl (buf[i]))? buf[i] : '.' );

$       PRINT_ ("]");
$       for (size_t i = 0; i < szObj; i++) PRINT_ (" %02X" _ buf[i]);

$       err = 0;
        }

$   if (err)
        { $ PRINT_ (" = ???"); }

$   PRINT_ ((object? "%sего адрес 0x%p." : "%sего адрес NULL.")_ ((typeName || mangledName)? ", " : "")_ object);

    #undef PRINT_VAL_
    #undef PRINT_

$   return s - what;
    }

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Stack trace and debug info access
//-----------------------------------------------------------------------------------------------------------------

const char* _txCaptureStackBackTrace (int framesToSkip /*= 0*/, bool readSource /*= true*/,
                                      CONTEXT* context /*= NULL*/, HANDLE thread /*= GetCurrentThread()*/)
    {
$1  _txLocCur.trace = 0;

$   const int maxFrames = 62;  // MS says: < 63
$   static char trace [(MAX_PATH + 1024+1) * maxFrames] = "";

    if (framesToSkip == -1) { $ return trace; }

$   static void* capture [maxFrames] = {};
$   int frames = _txStackWalk (framesToSkip + !context, SIZEARR (capture), capture, NULL, context, thread);

$   memset (trace, 0, sizeof (trace));
$   char* s = trace;

    #define PRINT_(msg)  s += _tx_snprintf_s (s, sizeof (trace) - 1 - 3 - (s-trace), msg)

$   for (int i = 0, n = 0; i < frames; i++)
        {
$       void* addr = capture[i];

$       Win32::SYMBOL_INFO*     sym    = NULL;
$       Win32::IMAGEHLP_LINE64* line   = NULL;
$       const char*             module = NULL;
$       const char*             source = NULL;
$       bool                    inTX   = false;

        if (addr) { $ inTX = _txSymGetFromAddr ((char*) addr - 1, &sym, &line, &module); }

        if (readSource && !inTX) { $ _txSymGetFromAddr ((void*) 1, NULL, NULL, NULL, &source, 2); }

$       int nl = 0;
$       while (s > trace && s[-1] == '\n') { s--; nl++; }

$       PRINT_ ("%s#%2d 0x%p" _ ((n)? ((source || nl)? "\n\n" : "\n") : "")_ n _ addr);
$       n++;

        if ((uintptr_t) addr ==  0)         { $ PRINT_ (" [Неверный фрейм]");        break; }
        if ((uintptr_t) addr == -1)         { $ PRINT_ (" [Странный фрейм]");        break; }
        if ((uintptr_t) addr == 0xBAADF00D) { $ PRINT_ (" [Мусор от LocalAlloc()]"); break; }

        if (module)                         { $ PRINT_ (" in %s%s"     _ module _ ((sym && *sym->Name)? "!" : "")); }
        if (sym  && *sym->Name)             { $ PRINT_ ("%s"           _ sym->Name);                                }
        if (line && line->FileName)         { $ PRINT_ (" at %s"       _ line->FileName);                           }
        if (line && line->LineNumber)       { $ PRINT_ (" (%u)"        _ line->LineNumber);                         }
        if (source)                         { $ PRINT_ (":\n\n" "%s\n" _ source);                                   }

        if (sym && sym->Name && strcmp (sym->Name , "main") == 0) { $ break; }
        }

    #if defined (_MSC_VER)
    #pragma warning (disable: 28199)  // Using possibly uninitialized memory '*s'
    #endif

$   while (s > trace && s[-1] == '\n') s--;
$   *s = 0;

    #if defined (_MSC_VER)
    #pragma warning (default: 28199)  // Using possibly uninitialized memory '*s'
    #endif

    #undef PRINT_

$   s += _tx_snprintf_s (s, sizeof (trace) - 1 - (s-trace), "");

$   return trace;
    }

//-----------------------------------------------------------------------------------------------------------------

// Stack WALKING if the program is DEAD. Dead, Carl!

int _txStackWalk (int framesToSkip, size_t szCapture, void* capture[], unsigned long* /*!!! backTraceHash*/,
                  CONTEXT* context /*= NULL*/, HANDLE thread /* = GetCurrentThread()*/)
    {
$1  _txLocCur.trace = 0;

$   namespace MinGW = Win32::MinGW;

$   assert (capture);

$   int cpu = 0;

$   Win32::STACKFRAME64 frame = {};
$   frame.AddrPC.Mode = frame.AddrStack.Mode = frame.AddrFrame.Mode = Win32::AddrModeFlat;

$   CONTEXT ctx = {};
$   ctx.ContextFlags |= CONTEXT_FULL;

$   int isWow64 = 0;
$   Win32::IsWow64Process (GetCurrentProcess(), &isWow64);
    
$   if (context)
        {
$       ctx = *context;
        }
    else
        {
$       //!!! return Win32::RtlCaptureStackBackTrace (framesToSkip + 1, (DWORD) szCapture, capture, backTraceHash);

$       assert (Win32::RtlCaptureContext);
$       Win32::RtlCaptureContext (&ctx);
        }

    #if   (defined (_M_X64) || defined (_WIN64)) && !defined (_M_X32) && !defined (_M_IX86)

$   if (isWow64)
        {
$       Win32::WOW64_CONTEXT wow64ctx = {};
$       wow64ctx.ContextFlags |= WOW64_CONTEXT_FULL;

$       if (!Win32::Wow64GetThreadContext (thread, &wow64ctx))  // In WINE, after EXIT_PROCESS_DEBUG_EVENT
            { $ return 0; }

$       cpu = IMAGE_FILE_MACHINE_I386;

$       frame.AddrPC.Offset    = wow64ctx.Eip;
$       frame.AddrStack.Offset = wow64ctx.Esp;
$       frame.AddrFrame.Offset = wow64ctx.Ebp;
        }
    else
        {
$       cpu = IMAGE_FILE_MACHINE_AMD64;

$       frame.AddrPC.Offset    = ctx.Rip;
$       frame.AddrStack.Offset = ctx.Rbp;
$       frame.AddrFrame.Offset = ctx.Rsp;
        }

    #elif (defined (_M_X32) || defined (_M_IX86)) && !defined (_M_X64) && !defined (_WIN64)

        {
$       cpu = IMAGE_FILE_MACHINE_I386;

$       frame.AddrPC.Offset    = ctx.Eip;
$       frame.AddrStack.Offset = ctx.Ebp;
$       frame.AddrFrame.Offset = ctx.Esp;
        }

    #else
        #error TXLib.h: CPU architecture is not properly defined (either _M_X32/_M_IX86 or _M_X64/_WIN64).

    #endif
    
$   assert (cpu);

$   _txSymGetFromAddr ((void*) 1);

$   int  n = 0;
$   for (n = -framesToSkip; n < (int) szCapture; n++)
        {
$       DWORD64 prev = frame.AddrStack.Offset;

        // Я злой и страшный серый walk. Я в поросятах знаю talk.

        if ((MinGW::StackWalk64)? !MinGW::StackWalk64 (cpu, GetCurrentProcess(), thread, &frame, &ctx,
                                                       NULL, MinGW::SymFunctionTableAccess64, MinGW::SymGetModuleBase64, NULL) :
                      
            (Win32::StackWalk64)? !Win32::StackWalk64 (cpu, GetCurrentProcess(), thread, &frame, &ctx,
                                                       NULL, Win32::SymFunctionTableAccess64, Win32::SymGetModuleBase64, NULL) :
            true)
            {
$           break;
            }

        if (n < 0) { $ continue; }

$       void* addr = (void*) frame.AddrPC.Offset;

        if (frame.AddrFrame.Offset == 0)   { $ addr = 0;          }  // Bad frame
        if (frame.AddrStack.Offset < prev) { $ addr = (void*) -1; }  // Strange frame

$       assert (0 <= n && n < (int) szCapture);

$       capture[n] = (void*) frame.AddrPC.Offset;
        }

$   return n;
    }

// Note that Rick and Carl are speaking near the C language block. "C block", Carl. See: http://knowyourmeme.com/memes/carl

//-----------------------------------------------------------------------------------------------------------------

bool _txSymGetFromAddr (void* addr, Win32::SYMBOL_INFO** symbol /*= NULL*/,
                        Win32::IMAGEHLP_LINE64** line /*= NULL*/, const char** module /*= NULL*/,
                        const char** source /*= NULL*/, int context /*= 2*/)
    {
$1  _txLocCur.trace = 0;

$   namespace MinGW = Win32::MinGW;

$   static HANDLE process = NULL;
$   bool done = false;

    #if (_DEBUG+0 > 0)
$   char res[10] = "";
    #endif

    #define CALL_(func, param)  ( (func)? ((func) param) : 0 )

$   if (!process && addr)
        {
$       process = GetCurrentProcess();

$       DWORD options = SYMOPT_UNDNAME | SYMOPT_LOAD_LINES | SYMOPT_LOAD_ANYTHING | SYMOPT_INCLUDE_32BIT_MODULES |
                        SYMOPT_DEFERRED_LOADS | SYMOPT_FAVOR_COMPRESSED | SYMOPT_FAIL_CRITICAL_ERRORS | SYMOPT_NO_PROMPTS;

        #if (_DEBUG+0 > 0)
$           options |= SYMOPT_DEBUG;
            #define RES_(sym)       (strncat_s (res, sizeof (res) - 1, #sym, sizeof (res) - 1), 1)
            #define DBG_(msg, ...)  txOutputDebugPrintf ("DBGTXLP: " __TX_FILELINE__ " _txSymGetFromAddr(): err = 0x%03lX, " msg "\n", \
                                                        (DWORD) GetLastError(), ##__VA_ARGS__)
        #else
            #define RES_(sym)       1
            #define DBG_(msg, ...)  0
        #endif

$        SetLastError (0);
$        CALL_(MinGW::SymSetOptions, (options)) && RES_(o);
$        CALL_(Win32::SymSetOptions, (options)) && RES_(O);

$        SetLastError (0);
$       (CALL_(MinGW::SymInitialize, (process, NULL, true)) && RES_(i)) || DBG_ ("MinGW::SymInitialize() failed");
$       (CALL_(Win32::SymInitialize, (process, NULL, true)) && RES_(I)) || DBG_ ("Win32::SymInitialize() failed");

$       done = true;
        }

$   static DWORD64 mod = 0;

$   if (module)
        {
$       static char sMod [MAX_PATH] = "";
$       memset (sMod, 0, sizeof (sMod));

$       SetLastError (0);

        mod = 0;  { $ mod = CALL_(MinGW::SymGetModuleBase64, (process, (uintptr_t) addr)); if (mod) (void) RES_(m); }
        if (!mod) { $ mod = CALL_(Win32::SymGetModuleBase64, (process, (uintptr_t) addr)); if (mod) (void) RES_(M); }
        if (!mod) { $ DBG_ ("SymGetModuleBase64() failed"); }

$       GetModuleFileName ((HMODULE)(ptrdiff_t) mod, sMod, MAX_PATH);

$       char* ext = strrchr (sMod, '.');
        if (ext) { $ _strlwr_s (ext, sizeof (sMod) - (ext-sMod)); }

$       *module = sMod;
$       done = true;
        }

$   static char buffer [_TX_BUFSIZE] = "";
$   static Win32::SYMBOL_INFO* sym = (Win32::SYMBOL_INFO*) buffer;

$   if (symbol)
        {
$       memset (buffer, 0, sizeof (buffer));

$       sym->MaxNameLen   = sizeof (buffer) - sizeof (Win32::SYMBOL_INFO) - 1;
$       sym->SizeOfStruct = sizeof (Win32::SYMBOL_INFO);
$       unsigned long long ofs = 0;

$       SetLastError (0);
$       (CALL_(MinGW::SymFromAddr, (process, (uintptr_t) addr, &ofs, sym)) && RES_(y)) ||
        (CALL_(Win32::SymFromAddr, (process, (uintptr_t) addr, &ofs, sym)) && RES_(Y)) ||
            DBG_ ("SymFromAddr (0x%p) failed", addr);

        if (strcmp (sym->Name, "??") == 0) { $ *sym->Name = 0; }

$       *symbol = sym;
$       done = true;
        }

$   static Win32::IMAGEHLP_LINE64 line64 = { sizeof (line) };

$   if (line)
        {
$       memset (&line64, 0, sizeof (line64));

$       unsigned long ofs = 0;

$       SetLastError (0);
$       (CALL_(MinGW::SymGetLineFromAddr64, (process, (uintptr_t) addr, &ofs, &line64)) && RES_(l)) ||
        (CALL_(Win32::SymGetLineFromAddr64, (process, (uintptr_t) addr, &ofs, &line64)) && RES_(L)) ||
            DBG_ ("SymGetLineFromAddr64 (\"%s\") failed", (symbol? (*symbol)->Name : "(null)"));

$       *line = &line64;
$       done = true;
        }

$   if (source)
        {
$       static char buf [_TX_BUFSIZE] = "";
$       memset (buf, 0, sizeof (buf));

$       if (line64.FileName && line64.LineNumber)
            {
$           _txReadSource (buf, sizeof (buf) - 1, line64.FileName,
                           line64.LineNumber - context, line64.LineNumber + context, line64.LineNumber);

$           *source = buf;
            }

        if (!*source || !**source) { $ *source = NULL; }

        if (*source) { $ (void) RES_(S); }
        else         { $ DBG_ ("_txReadSource (\"%s\") failed", line64.FileName); }

$       done = true;
        }

$   if (!addr && process)
        {
$       SetLastError (0);
$       (CALL_(MinGW::SymCleanup, (process)) && RES_(u)) || DBG_ ("MinGW::SymCleanup() failed");
$       (CALL_(Win32::SymCleanup, (process)) && RES_(U)) || DBG_ ("Win32::SymCleanup() failed");

$       process = NULL;
$       done = true;
        }

$   if (done) DBG_ ("res = \"%s\"", res);

    #undef CALL_
    #undef DBG_

$   if (symbol)
        {
$       if (strstr  (sym->Name, "::TX::")                                                 ||
            strncmp (sym->Name, "_tx",  3) == 0 && isupper ((unsigned char) sym->Name[3]) ||
            strncmp (sym->Name,  "tx",  2) == 0 && isupper ((unsigned char) sym->Name[2]) ||
            strncmp (sym->Name, "_tx_", 4) == 0                                           ||
            strncmp (sym->Name,  "tx_", 3) == 0)
            {
$           return true;
            }

$       if (!line || !line64.FileName) return false;

$       ptrdiff_t len = strlen (line64.FileName) - (sizeof (__FILE__) - 1);

$       return (len >= 0 && _stricmp (line64.FileName + len, __FILE__) == 0) &&
               (len == 0 || line64.FileName[len-1] == '/' || line64.FileName[len-1] == '\\');
        }

$   return false;
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t _txReadSource (char buf[], ptrdiff_t size, const char file[],
                         int linStart /*= 0*/, int linEnd /*= INT_MIN*/, int linMark /*= INT_MIN*/)
    {
$1  _txLocCur.trace = 0;

$   assert (buf);

    if (!file || !*file) { $ return 0; }

    if (linStart < 1) { $ linStart = 1;       }
    if (linEnd == -1) { $ linEnd   = INT_MAX; }

$   FILE* f = NULL;
$   fopen_s (&f, file, "r");
    if (!f) { $ return 0; }

$   int n = 1;
    while (!feof (f))
        {
        if (n >= linStart) { $ break; }
        while (!feof (f) && fgetc (f) != '\n') ;
$       n++;
        }

$   char* s = buf;

    #define SZ_  ( size - 3 - (s - buf) )

$   while (!feof (f) && SZ_ > 0)
        {
        if (n > linEnd || _txNOP (SZ_) < 0) { $ break; }

        if (linMark != INT_MIN)
            { $ s += _tx_snprintf_s (s, SZ_, "%s%5d: ", ((n == linMark)? "=>" : "  "), n); }

$       int c = 0;
$       while (!feof (f) && SZ_ > 0 && (c = fgetc (f)) != '\n') *s++ = (char) c;
        if (c == EOF) { $ s--; }

        if (SZ_ > 0) { $ *s++ = '\n'; }
$       n++;
        }

    if (n <= linEnd && SZ_ <= 0)
        { $ s += _tx_snprintf_s (s, size - (s - buf), "..."); }

    #undef SZ_

$   fclose (f);

    if (s > buf && s[-1] == '\n') { $ s--; }
$   *s = 0;

$   return (s - buf);
    }

//-----------------------------------------------------------------------------------------------------------------

const char* _txCaptureStackBackTraceTX (int framesToSkip /*= 0*/, bool readSource /*= false*/)
    {
$1  _txLocCur.trace = 0;

$   const int maxFrames = 62;  // TX says too: < 63
$   static char trace [(MAX_PATH + 1024+1) * maxFrames] = "";

    if (framesToSkip == -1) { $ return trace; }

$   memset (trace, 0, sizeof (trace));
$   char* s = trace;

    #define SZ_  ( sizeof (trace) - 1 - 3 - (s-trace) )

$   const _txLoc* loc = &_txLocCur;

$   for (int i = 0; loc && i < framesToSkip + 1; i++, loc = loc->prev) ;

$   for (int i = -framesToSkip; loc && i < maxFrames; i++, loc = loc->prev)
        {
        if (i < 0) { $ continue; }

        if (loc->func || loc->file || loc->line)
            {
$           s += _tx_snprintf_s     (s, SZ_, "%s#%2d in %s at %s (%d)" _ (i? readSource? "\n\n" : "\n" : "")_
                                     i, loc->func, loc->file, loc->line);

$           if (readSource)
                {
$               s += _tx_snprintf_s (s, SZ_, ":\n\n");
$               s += _txReadSource  (s, SZ_, loc->file, loc->line - 2, loc->line + 2, loc->line);
                }
            }
        }

    #undef SZ_

$   s += _tx_snprintf_s (s, sizeof (trace) - 1 - (s-trace), "");

$   return trace;
    }

//-----------------------------------------------------------------------------------------------------------------
//}

//-----------------------------------------------------------------------------------------------------------------
//{          Reporting
//-----------------------------------------------------------------------------------------------------------------

const char* _txProcessError (const char file[], int line, const char func[], unsigned color, const char msg[], va_list args)
    {
    static int nCalls = 0; nCalls++;

    DWORD          winerr   = GetLastError();
    int            crterr   = errno;
    unsigned long  doserr   = _doserrno;
    unsigned       threadId = GetCurrentThreadId();

    enum { isFatal = 1, traceSE = 2, noMsgBox = 4, fmtOnly = 8 };
    int options = 0;

    for (; msg && *msg; msg++)
        {
        if      (*msg == '\a') options |= isFatal;
        else if (*msg == '\t') options |= traceSE;
        else if (*msg == '\b') options |= noMsgBox;
        else if (*msg == '\f') options |= fmtOnly;
        else break;
        }

    const char* stkTrace = ((options & traceSE) && *_txTraceSE)? _txTraceSE : _txCaptureStackBackTrace (2, true);
    const char*  txTrace = _txCaptureStackBackTraceTX (0, true);

    static char what[_TX_BIGBUFSIZE*10] = "";
    static char str [_TX_BIGBUFSIZE]    = "";
    char *s = what;

    #define  PRINT_(msg)  s += _tx_snprintf_s  (s, sizeof (what) - 1 - (s - what), msg)
    #define VPRINT_(msg)  s += _tx_vsnprintf_s (s, sizeof (what) - 1 - (s - what), msg)

                PRINT_ ("TXLib сообщает:\n\n");

                PRINT_ ("Программа: %s" _ txGetModuleFileName());
    if (file)   PRINT_ (", файл: %s"    _ file);
    if (line)   PRINT_ (", строка: %d"  _ line);
    if (func)   PRINT_ (", функция: %s" _ func);
                PRINT_ (",\n\n");

    if (msg)    PRINT_ ("%s: " _ (file || line || func)? "Сообщение" : "ВНЕЗАПНО"),
               VPRINT_ (msg _ args),
                PRINT_ ("\n\n");

                PRINT_ ("#%d: %s, Instance: 0x%p (%d-bit), Flags: %c%c%c%c%c%d, Thread: 0x%X%s" _
                        nCalls _ _TX_VERSION _ &_txInitialized _ (sizeof (void*) == 4)? 32 : 64 _
                        "cC"[_txConsole]_ "mM"[_txMain]_ "dD"[_txIsDll]_ "rR"[_txRunning]_ "eE"[_txExit]_ _txLocCur.trace _
                        threadId _ (threadId == _txMainThreadId)?    " (Main)"   :
                                   (threadId == _txCanvas_ThreadId)? " (Canvas)" : "");

    if (winerr) PRINT_ (", GetLastError(): %lu (" _ winerr),
                s += FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                    NULL, winerr, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                                    s, (DWORD) (sizeof (what) - (s-what)), NULL) - 2,
                s -=  (s[-1] == '.')? 1 : 0,
                PRINT_ (")");

    if (crterr) PRINT_ (", errno: %d (%s)" _      crterr _ (strerror_s (str, sizeof (str), crterr), str));
    if (doserr) PRINT_ (", _doserrno: %lu (%s)" _ doserr _ (strerror_s (str, sizeof (str), doserr), str));
                PRINT_ (". %s\n" _ ::std::uncaught_exception()? "std::uncaught_exception(): true." : "");

    if (_txLocCur.inTX > 0 && !(_txLocCur.line == line && file && _stricmp (_txLocCur.file, file) == 0))
                PRINT_ ("From: %s (%d) %s.\n" _ _txLocCur.file _ _txLocCur.line _ _txLocCur.func);

    #undef PRINT_

    txOutputDebugPrintf ("\r" "%s - ERROR: %s", _TX_VERSION, what);

    if (options & fmtOnly) return what;

    unsigned restore = txGetConsoleAttr();
    txSetConsoleAttr ((options & isFatal)? 0x0D /* LightMagenta */ : 0x0C /* LightRed */);
    if (color) txSetConsoleAttr (color);

    printf ("\n" "--------------------------------------------------\n"
                 "%s\n"
                 "--------------------------------------------------\n",
                 what);

    if (stristr (stkTrace, ".exe!"))
        printf  ("Трассировка стека:\n\n"
                 "%s\n\n"
                 "--------------------------------------------------\n",
                 stkTrace);

    txSetConsoleAttr (restore);

    if (*_txLogName) do
        {
        FILE* log = NULL; fopen_s (&log, _txLogName, "a");
        if (!log) { $ break; }

        fprintf (log, "\n"     "--------------------------------------------------\n"
                               "%s\n"
                               "--------------------------------------------------\n"
                               "Стек вызовов:\n\n"
                               "%s\n",
                               what, (*_txTraceSE? _txTraceSE : stkTrace));

        #if defined (_TX_ALLOW_TRACE) || defined (_DEBUG)

        if (txTrace && *txTrace)
            {
            fprintf (log, "\n" "--------------------------------------------------\n"
                               "Стек вызовов TX:\n\n"
                               "%s\n",
                               txTrace);
            }
        #endif

        fprintf (log, "\n"     "--------------------------------------------------\n"
                               "%s\n\n"
                               "--------------------------------------------------\n",
                               _txAppInfo());
        fclose (log);
        break;
        }
        while (0);

    if (!(options & noMsgBox))
        {
        txSleep (0);
        txMessageBox (what, (isFatal? "Фатальная ошибка" : "Ошибка в программе"), MB_ICONSTOP | MB_SYSTEMMODAL);
        }

    if ((options & isFatal) && !IsDebuggerPresent())
        {
        ::exit (EXIT_FAILURE);
        }

    return what;
    }

//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

int _txOnErrorReport (int type, char* text, int* ret)
    {
    static int nCalls = 0; nCalls++;

    unsigned restore = txGetConsoleAttr();

    switch (type)
       {
       case _CRT_WARN:   txSetConsoleAttr (0x0B); /* LightCyan    */ break;
       case _CRT_ERROR:  txSetConsoleAttr (0x0D); /* LightMagenta */ break;
       case _CRT_ASSERT: txSetConsoleAttr (0x0E); /* Yellow       */ break;
       default:                                                      break;
       }

    if (strcmp (text, "Detected memory leaks!\n") == 0)  // Dirty, dirty hack. А что делать?
        {
        _txOnErrorReport (type, "\n" "Внимание: Обнаружены утечки памяти!\n\n", NULL);
        }

    txOutputDebugPrintf ("\r" "%s - ERROR: %s", _TX_VERSION, text);

    DWORD n = 0;
    HANDLE err = GetStdHandle (STD_ERROR_HANDLE);
    WriteFile (err, text, (DWORD) strlen (text), &n, NULL);

    txSetConsoleAttr (restore);

    if (*_txLogName) do
        {
        HANDLE log = CreateFile (_txLogName, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (log == INVALID_HANDLE_VALUE) break;

        SetFilePointer (log, 0, NULL, FILE_END);
        WriteFile (log, text, (DWORD) strlen (text), &n, NULL);

        CloseHandle (log);
        break;
        }
        while (0);

    if (ret) *ret = 0;

    return (type == _CRT_WARN);
    }

#endif

//-----------------------------------------------------------------------------------------------------------------

void _txTrace (const char file[], int line, const char func[], const char msg[] /*= NULL*/, ...)
    {
    unsigned id = GetCurrentThreadId();

    const char marks[2][2][3] = {{"uU", "cC"}, {"mM", "??"}};

    char mark = marks [id == _txMainThreadId] [id == _txCanvas_ThreadId] [(_txLocCur.inTX > 0)];

    char msgStr[_TX_BUFSIZE] = "";
    if (msg)
        {
        va_list arg; va_start (arg, msg);
        _tx_vsnprintf_s (msgStr, sizeof (msgStr) - 1, msg, arg);
        va_end (arg);
        }

    txOutputDebugPrintf ("%s - 0x%p %c%c%c%c%c%d [%c] - %s (%5d)  " "|%*s%s" "%s%s\n",
                         _TX_VERSION, &_txInitialized,
                         "cC"[_txConsole], "mM"[_txMain], "dD"[_txIsDll], "rR"[_txRunning], "eE"[_txExit], _txLocCur.trace,
                         mark, (file? file : "(NULL file)"), line, !!func * (_txLocCur.inTX - 1) * 2, "", (func? func : ""),
                         ((*msgStr && func)? ": " : ""), msgStr);
    }

//-----------------------------------------------------------------------------------------------------------------

int txOutputDebugPrintf (const char format[], ...)
    {
    if (!format) return 0;

    enum { msgbox = 1, print = 2, compr = 4 };
    int options = 0;

    for (; format && *format; format++)
        {
        if      (*format == '\a') options |= msgbox;
        else if (*format == '\f') options |= print;
        else if (*format == '\r') options |= compr;
        else break;
        }

    char str[_TX_BIGBUFSIZE] = "";

    va_list arg; va_start (arg, format);
    int n = (int) _tx_vsnprintf_s (str, sizeof (str) - 1-1, format, arg);
    va_end (arg);

    struct __ { static int trimSpaces (char str[])
        {
        char *dst = str, *src = str;

        for (char d = ' '; d; src++)
            if (isspace ((unsigned char)(*src))) { if (d != ' ') *dst++ = d = ' '; }
            else                                                 *dst++ = d = *src;
        
        return (int) (dst - str - 1);
        }};

    if (options & compr)  n = __::trimSpaces (str);

    OutputDebugString (str);

    if (options & print)  fprintf (stderr, "%s\n", str);

    if (options & msgbox) txMessageBox (str, "Оказывается, что", MB_ICONEXCLAMATION);

    return n;
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t _tx_snprintf_s (char stream[], ptrdiff_t size, const char format[], ...)
    {
    va_list arg; va_start (arg, format);
    ptrdiff_t ret = _tx_vsnprintf_s (stream, size, format, arg);
    va_end (arg);

    return ret;
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t _tx_vsnprintf_s (char stream[], ptrdiff_t size, const char format[], va_list arg)
    {
    #if defined (_TRUNCATE)
    ptrdiff_t ret = _vsnprintf_s (stream, size, _TRUNCATE, format, arg);
    #else
    ptrdiff_t ret = _vsnprintf   (stream, size,            format, arg);
    #endif

    if (ret < 0 && size >= 4)
        {
        const char ellipsis[] = "...";
        size_t     szEllipsis = sizeof (ellipsis) - 1;

        strncpy_s (stream + size - szEllipsis, szEllipsis+1, ellipsis, szEllipsis);
        }

    return (ret >= 0)? ret : size;
    }

//-----------------------------------------------------------------------------------------------------------------

int txMessageBox (const char text[], const char header[], unsigned flags /*= 0*/)
    {
$1  static wchar_t textW   [_TX_BIGBUFSIZE * sizeof (wchar_t)] = L"[NULL text]";
    static wchar_t headerW [_TX_BUFSIZE    * sizeof (wchar_t)] = L"[NULL header]";

    if (text)   MultiByteToWideChar (_TX_CP, 0, text,   -1, textW,   SIZEARR (textW))   || memset (textW,   0, sizeof (textW));
    if (header) MultiByteToWideChar (_TX_CP, 0, header, -1, headerW, SIZEARR (headerW)) || memset (headerW, 0, sizeof (headerW));

    HWND wnd = _txCanvas_Window;
    return MessageBoxW ((wnd? wnd : Win32::GetConsoleWindow()), textW, headerW, flags | MB_SETFOREGROUND | MB_TOPMOST);

    return 0;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txNotifyIcon (unsigned flags, const char title[], const char format[], ...)
    {
$1  _txLocCur.trace = 0;

$   _TX_IF_ARGUMENT_FAILED (format) return false;

$   va_list arg; va_start (arg, format);
$   bool ok = true;

    #if defined (_WIN32_IE) && (_WIN32_IE >= 0x0500)

$   NOTIFYICONDATA nid = { sizeof (nid) };

$   nid.uFlags = NIF_ICON | NIF_TIP | NIF_INFO;
$   nid.hWnd   = NULL;
$   nid.uID    = 1;
$   nid.hIcon  = _txCreateTXIcon (16); assert (nid.hIcon);
$   strncpy_s       (nid.szTip,       sizeof (nid.szTip),       "TXLib Information", sizeof (nid.szTip));
$   strncpy_s       (nid.szInfoTitle, sizeof (nid.szInfoTitle), (title? title : "TXLib сообщает"), sizeof (nid.szInfoTitle) - 1);
$   _tx_vsnprintf_s (nid.szInfo, sizeof (nid.szInfo), format, arg);
$   nid.dwInfoFlags = flags;

$   txOutputDebugPrintf ("\r" _TX_VERSION " - %s: %s (Icon notification)\n", nid.szInfoTitle, nid.szInfo);

$   ok &= !!Shell_NotifyIcon (NIM_ADD,    (::NOTIFYICONDATA*) &nid);
$   ok &= !!Shell_NotifyIcon (NIM_MODIFY, (::NOTIFYICONDATA*) &nid);

$   if (nid.hIcon) DestroyIcon (nid.hIcon) asserted;

    #else

$   char nid_szInfo[_TX_BUFSIZE] = "";
$   _tx_vsnprintf_s (nid_szInfo, sizeof (nid_szInfo), format, arg);
$   txOutputDebugPrintf ("\r" _TX_VERSION " - %s: %s (Icon notification - NOT displayed)\n", title, nid_szInfo);
$   ok = false;

$   (void)flags; (void)title;

    #endif

$   va_end (arg);
    return ok;
    }

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Information
//-----------------------------------------------------------------------------------------------------------------

const char* txGetModuleFileName (bool fileNameOnly /*= true*/)
    {
    static char name[MAX_PATH] = "";

    if (!*name)
        {
        if (!GetModuleFileName (NULL, name, sizeof (name) - 1)) *name = 0;

        char* ext = strrchr (name, '.');
        if (ext) _strlwr_s (ext, sizeof (name) - 1 - (ext - name));
        }

    assert (*name);

    if (fileNameOnly) return name;

    static char fullName[MAX_PATH] = "";
    strncpy_s (fullName, sizeof (fullName), name, sizeof (fullName) - 1);

    char* title = strrchr (fullName, '\\'); if (!title) title = fullName;
    char* ext   = strrchr (fullName,  '.'); if (!ext)   ext   = fullName + strlen (fullName);

    size_t sz = sizeof (fullName) - (ext - fullName) - 1;
    strncpy_s (ext, sz, " - TXLib", sz);

    return title + 1;
    }

//-----------------------------------------------------------------------------------------------------------------

const char* _txAppInfo()
    {
$1  time_t timeT     = time (NULL) - clock()/CLOCKS_PER_SEC;
    char   timeS[32] = "";
    ctime_s (timeS, sizeof (timeS), &timeT);

    static char text[_TX_BUFSIZE] = "";
    char cwd [MAX_PATH] = "";

    _tx_snprintf_s (text, sizeof (text) - 1,

                    "Developed with:\n\n"
                    "The Dumb Artist Library (TX Library) - " _TX_VERSION "\n" _TX_AUTHOR "\n"
                    "See license on: http://txlib.ru\n\n"

                    "TXLib file:" "\t" __FILE__ "\n"
                    "Compiled:"   "\t" __DATE__ " " __TIME__ ", " _TX_BUILDMODE ", " __TX_COMPILER__ "\n"
                    "Started:"    "\t" "%.6s %.4s %.8s\n\n"

                    "Run file:"   "\t" "%s\n"
                    "Directory:"  "\t" "%s",

                    timeS + 4, timeS + 20, timeS + 11,  // These offsets are ANSI standardized
                    txGetModuleFileName(),
                    _getcwd (cwd, sizeof (cwd) - 1));

    return text;
    }

//}
//-----------------------------------------------------------------------------------------------------------------

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          TXLib API implementation
//           Реализация TXLib API
//=================================================================================================================

inline const char* txVersion()
    {
    return _TX_VERSION;
    }

//-----------------------------------------------------------------------------------------------------------------

inline unsigned txVersionNumber()
    {
    return _TX_VER;
    }

//-----------------------------------------------------------------------------------------------------------------

POINT txGetExtent (HDC dc /*= txDC (true)*/)
    {
$1  BITMAP bmap = {0};
$   txGDI (Win32::GetObject (Win32::GetCurrentObject (dc, OBJ_BITMAP), sizeof (bmap), &bmap), dc) asserted;

$   POINT size = { bmap.bmWidth, bmap.bmHeight };
$   return size;
    }

//-----------------------------------------------------------------------------------------------------------------

int txGetExtentX (HDC dc /*= txDC (true)*/)
    {
    return txGetExtent (dc).x;
    }

//-----------------------------------------------------------------------------------------------------------------

int txGetExtentY (HDC dc /*= txDC (true)*/)
    {
    return txGetExtent (dc) .y;
    }

//-----------------------------------------------------------------------------------------------------------------

inline HDC& txDC (bool forced /*= false*/)
    {
$1  if (forced) _TX_IF_TXWINDOW_FAILED { static HDC null = NULL; return null; }

$   return _txCanvas_BackBuf[0];
    }

//-----------------------------------------------------------------------------------------------------------------

inline HWND txWindow()
    {
$1  return _txCanvas_Window;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDestroyWindow()
    {
$1  if (!txWindow()) return false;

$   if (SendNotifyMessage (txWindow(), (_txMain? WM_CLOSE : WM_DESTROY), 0, 0) == 0) return false;

$   if (_txMain)
        {
$       txNotifyIcon (NIIF_WARNING, NULL, "\n" "Очень, очень плохо завершать программу через txDestroyWindow().\n\n"
                                               "Возвращайтесь через main(), там вам будут рады.\n");
$       Sleep (_TX_TIMEOUT);
        }

$   _txWaitFor (!_txCanvas_Window, _TX_TIMEOUT);

$   return _txCanvas_Window == NULL;
    }

//-----------------------------------------------------------------------------------------------------------------

HPEN txSetColor (COLORREF color, double thickness /*= 1*/, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return NULL;

$   HPEN pen = Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), ROUND (thickness), color);

$   if (!pen) return (HPEN) NULL;

$   if (!_txBuffer_Select (pen, dc))
        {
$       Win32::DeleteObject (pen);
$       return (HPEN) NULL;
        }

$   if (txGDI (Win32::SetTextColor (dc, color), dc) == CLR_INVALID)
        { $ return (HPEN) NULL; }

$   return pen;
    }

//-----------------------------------------------------------------------------------------------------------------

COLORREF txColor (double red, double green, double blue)
    {
$1  if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   COLORREF color = RGB (ROUND (red * 255), ROUND (green * 255), ROUND (blue * 255));

$   return txSetColor (color)? color : CLR_INVALID;
    }

//-----------------------------------------------------------------------------------------------------------------

COLORREF txGetColor (HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return CLR_INVALID;

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (dc, OBJ_PEN)), dc);
$   assert (obj); if (!obj) return CLR_INVALID;

$   union { EXTLOGPEN extLogPen; LOGPEN LogPen; } buf = {{0}};

$   int size = Win32::GetObject (obj, 0, NULL);
$   Win32::GetObject (obj, sizeof (buf), &buf) asserted;

$   return (size == sizeof (LOGPEN))? buf.LogPen.lopnColor : buf.extLogPen.elpColor;
    }

//-----------------------------------------------------------------------------------------------------------------

HBRUSH txSetFillColor (COLORREF color, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return NULL;

$   HBRUSH brush = (color == TX_TRANSPARENT)? (HBRUSH) Win32::GetStockObject (HOLLOW_BRUSH) : Win32::CreateSolidBrush (color);

$   return (_txBuffer_Select (brush, dc))? brush : (Win32::DeleteObject (brush), (HBRUSH) NULL);
    }

//-----------------------------------------------------------------------------------------------------------------

COLORREF txFillColor (double red, double green, double blue)
    {
$1  if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   COLORREF color = RGB (ROUND (red * 255), ROUND (green * 255), ROUND (blue * 255));

$   return txSetFillColor (color)? color : CLR_INVALID;
    }

//-----------------------------------------------------------------------------------------------------------------

COLORREF txGetFillColor (HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return CLR_INVALID;

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (dc, OBJ_BRUSH)), dc);
$   assert (obj); if (!obj) return CLR_INVALID;

$   LOGBRUSH buf = {0};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf)), dc) asserted;

$   return buf.lbColor;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSetROP2 (int mode /*= R2_COPYPEN*/, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   return txGDI (!!(Win32::SetROP2 (dc, mode)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txClear (HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   POINT size = txGetExtent (dc);
$   return txGDI (!!(Win32::PatBlt (dc, 0, 0, size.x, size.y, PATCOPY)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool txSetPixel (double x, double y, COLORREF color, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   txGDI ((Win32::SetPixel (dc, ROUND (x), ROUND (y), color)), dc);

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool txPixel (double x, double y, double red, double green, double blue, HDC dc /*= txDC (true)*/)
    {
$1  if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetPixel (x, y, RGB (ROUND (red * 255), ROUND (green * 255), ROUND (blue * 255)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

inline COLORREF txGetPixel (double x, double y, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return CLR_INVALID;

$   return txGDI ((Win32::GetPixel (dc, ROUND (x), ROUND (y))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txLine (double x0, double y0, double x1, double y1, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   txGDI ((Win32::MoveToEx (dc, ROUND (x0), ROUND (y0), NULL)), dc) asserted;
$   txGDI ((Win32::LineTo   (dc, ROUND (x1), ROUND (y1)      )), dc) asserted;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txRectangle (double x0, double y0, double x1, double y1, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   txGDI ((Win32::Rectangle (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1))), dc) asserted;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc)     return false;
$   _TX_IF_ARGUMENT_FAILED (points) return false;

$   return txGDI (!!(Win32::Polygon (dc, points, numPoints)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txEllipse (double x0, double y0, double x1, double y1, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   txGDI ((Win32::Ellipse (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1))), dc) asserted;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txCircle (double x, double y, double r)
    {
$1  return txEllipse (x-r, y-r, x+r, y+r);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   POINT center = { ROUND ((x0 + x1) /2), ROUND ((y0 + y1) /2) };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Arc (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1),
                                     ROUND (center.x + 1E3*cos (start)), ROUND (center.y - 1E3*sin (start)),
                                     ROUND (center.x + 1E3*cos (end)),   ROUND (center.y - 1E3*sin (end)))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   POINT center = { ROUND ((x0 + x1) /2), ROUND ((y0 + y1) /2) };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Pie (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1),
                                     ROUND (center.x + 1E3*cos (start)), ROUND (center.y - 1E3*sin (start)),
                                     ROUND (center.x + 1E3*cos (end)),   ROUND (center.y - 1E3*sin (end)))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   POINT center = { ROUND ((x0 + x1) /2), ROUND ((y0 + y1) /2) };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Chord (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1),
                                       ROUND (center.x + 1E3*cos (start)), ROUND (center.y - 1E3*sin (start)),
                                       ROUND (center.x + 1E3*cos (end)),   ROUND (center.y - 1E3*sin (end)))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txFloodFill (double x, double y,
                  COLORREF color /*= TX_TRANSPARENT*/, DWORD mode /*= FLOODFILLSURFACE*/, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return false;

$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y, dc);

$   return txGDI (!!(Win32::ExtFloodFill (dc, ROUND (x), ROUND (y), color, mode)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txTextOut (double x, double y, const char text[], HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc)   return false;
$   _TX_IF_ARGUMENT_FAILED (text) return false;

$   int len = (int) strlen (text);
$   txGDI (!!(Win32::TextOut (dc, ROUND (x), ROUND (y), text, len)), dc) asserted;
$   Win32::GetPixel (dc, 0, 0);

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDrawText (double x0, double y0, double x1, double y1, const char text[],
                 unsigned format /*= DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_WORD_ELLIPSIS*/,
                 HDC dc /*= txDC (true)*/)
{
$1  _TX_IF_ARGUMENT_FAILED (dc)   return false;
$   _TX_IF_ARGUMENT_FAILED (text) return false;

$   RECT r = { ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1) };

$   if (!strchr (text, '\n')) format |= DT_SINGLELINE;

$   unsigned prev = txSetTextAlign (TA_LEFT | TA_TOP | TA_NOUPDATECP, dc);

    if (Win32::DrawText) { $ txGDI ((Win32::DrawText (dc, text, -1, &r, format)), dc) asserted; Win32::GetPixel (dc, 0, 0); }

$   txSetTextAlign (prev, dc);

$   return true;
}

//-----------------------------------------------------------------------------------------------------------------

HFONT txSelectFont (const char name[], double sizeY, double sizeX /*= -1*/,
                    int bold /*= FW_DONTCARE*/, bool italic /*= false*/, bool underline /*= false*/,
                    bool strikeout /*= false*/, double angle /*= 0*/,
                    HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc)   return NULL;
$   _TX_IF_ARGUMENT_FAILED (name) return NULL;

$   HFONT font = txFontExist (name)?
                     Win32::CreateFont (ROUND (sizeY), ROUND ((sizeX >= 0)? sizeX : sizeY/3),
                                        ROUND (angle*10), 0, bold, italic, underline, strikeout,
                                        RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                        DEFAULT_QUALITY, FIXED_PITCH, name)
                     :
                     (HFONT) Win32::GetStockObject (SYSTEM_FIXED_FONT);

$   _txBuffer_Select (font, dc);

$   return font;
    }

//-----------------------------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[], HDC dc /*= txDC (true)*/)
    {
$1  SIZE size = {0};

$   _TX_IF_ARGUMENT_FAILED (dc)   return size;
$   _TX_IF_ARGUMENT_FAILED (text) return size;

$   txGDI ((Win32::GetTextExtentPoint32 (dc, text, (int) strlen (text), &size)), dc) asserted;

$   return size;
    }

//-----------------------------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[], HDC dc /*= txDC (true)*/)
    {
$1  return txGetTextExtent (text, dc) .cx;
    }

//-----------------------------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[], HDC dc /*= txDC (true)*/)
    {
$1  return txGetTextExtent (text, dc) .cy;
    }

//-----------------------------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align /*= TA_CENTER | TA_BASELINE*/, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return 0;

$   return txGDI ((Win32::SetTextAlign (dc, align)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[])
    {
$1  _TX_IF_ARGUMENT_FAILED (name) return NULL;

$   static LOGFONT font = {0};
$   font.lfCharSet = DEFAULT_CHARSET;
$   strncpy_s (font.lfFaceName, sizeof (font.lfFaceName), name, sizeof (font.lfFaceName) - 1);

$   struct tools
        {
        static int CALLBACK enumFonts (const LOGFONT* fnt, const TEXTMETRIC*, DWORD, LPARAM data)
            {
$           _TX_IF_ARGUMENT_FAILED (fnt)  return 0;
$           _TX_IF_ARGUMENT_FAILED (data) return 0;

            #ifndef __STRICT_ANSI__
$           return _strnicmp (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE);

            #else
$           return  strncmp  (fnt->lfFaceName, ((LOGFONT*)data)->lfFaceName, LF_FACESIZE);

            #endif
            }
        };

$   return txGDI ((Win32::EnumFontFamiliesEx (NULL, &font, tools::enumFonts, (LPARAM) &font, 0)), NULL) == 0? &font : NULL;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj, HDC dc /*= txDC (true)*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (obj) return false;
$   _TX_IF_ARGUMENT_FAILED (dc)  return false;

$   return _txBuffer_Select (obj, dc);
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap /*= NULL*/)
    {
$1  POINT size = { ROUND (sizeX), ROUND (sizeY) };

$   HDC dc = _txBuffer_Create (NULL, &size, bitmap);
$   assert (dc); if (!dc) return NULL;

$   if (!_txCanvas_UserDCs) return dc;

$   txAutoLock _lock;
$   _txCanvas_UserDCs->push_back (dc);

$   if (_txCanvas_UserDCs->size() >= _TX_BUFSIZE)
        { $ txNotifyIcon (NIIF_WARNING, NULL, "Вы загрузили уже %d HDC, системе может стать плохо.", (int) _txCanvas_UserDCs->size()); }

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txCreateDIBSection (double sizeX, double sizeY, RGBQUAD** pixels /*= NULL*/)
    {
$1  RGBQUAD* buf = NULL;
$   if (!pixels) pixels = &buf;

$   BITMAPINFO info = {{ sizeof (info), ROUND (sizeX), ROUND (sizeY), 1, WORD (sizeof (RGBQUAD) * 8), BI_RGB }};

$   return txCreateCompatibleDC (0, 0, Win32::CreateDIBSection (NULL, &info, DIB_RGB_COLORS, (void**) pixels, NULL, 0));
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txCreateDIBSection (double sizeX, double sizeY, COLORREF** pixels /*= NULL*/)
    {
$1  return txCreateDIBSection (sizeX, sizeY, (RGBQUAD**) pixels);
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[], unsigned imageFlags /*= IMAGE_BITMAP*/, unsigned loadFlags /*= LR_LOADFROMFILE*/)
    {
$1  _TX_IF_TXWINDOW_FAILED                         return NULL;
$   _TX_IF_ARGUMENT_FAILED (filename && *filename) return NULL;

$   HBITMAP image = (HBITMAP) Win32::LoadImage ((loadFlags & LR_LOADFROMFILE)? NULL : GetModuleHandle (NULL),
                                                 filename, imageFlags, 0, 0, loadFlags);
$   if (!image) return NULL;

$   HDC dc = txCreateCompatibleDC (0, 0, image);

$   if (!(loadFlags & LR_LOADFROMFILE)) return dc;

$   static std::map <std::string, unsigned> loadTimes;
$   std::string file = filename;
$   unsigned time    = GetTickCount();

$   if ((long) (time - loadTimes [file]) < _TX_TIMEOUT)
        { $ txNotifyIcon (NIIF_WARNING, NULL, "Вы загружаете \"%s\" слишком часто, программа будет тормозить.", filename); }

$   loadTimes [file] = time;

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDeleteDC (HDC* pdc)
    {
$1  _TX_IF_TXWINDOW_FAILED       return false;
$   _TX_IF_ARGUMENT_FAILED (pdc) return false;

$   HDC  dc = *pdc;
$   bool ok = _txBuffer_Delete (pdc);
$   if (!ok) return false;

$   if (!_txCanvas_UserDCs) return ok;

$   txAutoLock _lock;
$   std::vector <HDC> ::iterator i = std::find (_txCanvas_UserDCs->begin(), _txCanvas_UserDCs->end(), dc);
$   if (i != _txCanvas_UserDCs->end()) { std::swap (*i, _txCanvas_UserDCs->back()); _txCanvas_UserDCs->pop_back(); }

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDeleteDC (HDC dc)
    {
$1  _TX_IF_TXWINDOW_FAILED return false;

$   return txDeleteDC (&dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txBitBlt (HDC dest, double xDest, double yDest, double width, double height,
               HDC src,  double xSrc /*= 0*/, double ySrc /*= 0*/, DWORD rOp /*= SRCCOPY*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (src) return false;

$   if (!dest) dest = txDC();

$   if (width <= 0 || height <= 0)
        {
$       POINT size = txGetExtent (src);
$       if (width  <= 0) width  = size.x;
$       if (height <= 0) height = size.y;
        }

$   return txGDI (!!(Win32::BitBlt (dest, ROUND (xDest), ROUND (yDest), ROUND (width), ROUND (height),
                                    src,  ROUND (xSrc),  ROUND (ySrc),  rOp)), dest);
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool txBitBlt (HDC dest, double xDest, double yDest, HDC src, double xSrc /*= 0*/, double ySrc /*= 0*/)
    {
$1  return txBitBlt (dest, xDest, yDest, 0, 0, src, xSrc, ySrc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC dest, double xDest, double yDest, double width, double height,
                       HDC src,  double xSrc /*= 0*/, double ySrc /*= 0*/, COLORREF transColor /*= TX_BLACK*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (src) return false;

$   if (!dest) dest = txDC();

$   if (width <= 0 || height <= 0)
        {
$       POINT size = txGetExtent (src);
$       if (width  <= 0) width  = size.x;
$       if (height <= 0) height = size.y;
        }

$   return (Win32::TransparentBlt)?
        txGDI (!!(Win32::TransparentBlt (dest, ROUND (xDest), ROUND (yDest), ROUND (width), ROUND (height),
                                         src,  ROUND (xSrc),  ROUND (ySrc),  ROUND (width), ROUND (height), transColor)), dest)
    :
        txGDI (!!(Win32::BitBlt         (dest, ROUND (xDest), ROUND (yDest), ROUND (width), ROUND (height),
                                         src,  ROUND (xSrc),  ROUND (ySrc),  SRCCOPY)), dest), false;
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool txTransparentBlt (HDC dest, double xDest, double yDest, HDC src, COLORREF transColor /*= TX_BLACK*/)
    {
$1  return txTransparentBlt (dest, xDest, yDest, 0, 0, src, 0, 0, transColor);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC dest, double xDest, double yDest, double width, double height,
                   HDC src,  double xSrc /*= 0*/, double ySrc /*= 0*/, double alpha /*= 1.0*/,
                   unsigned format /*= AC_SRC_ALPHA*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (src) return false;

$   if (!dest) dest = txDC();

$   if (width <= 0 || height <= 0)
        {
$       POINT size = txGetExtent (src);
$       if (width  <= 0) width  = size.x;
$       if (height <= 0) height = size.y;
        }

$   if (alpha < 0) alpha = 0;
$   if (alpha > 1) alpha = 1;

$   BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) ROUND (alpha * 255), (BYTE) format };

$   return (Win32::AlphaBlend)?
        txGDI (!!(Win32::AlphaBlend (dest, ROUND (xDest), ROUND (yDest), ROUND (width), ROUND (height),
                                     src,  ROUND (xSrc),  ROUND (ySrc),  ROUND (width), ROUND (height), blend)), dest)
    :
        txGDI (!!(Win32::BitBlt     (dest, ROUND (xDest), ROUND (yDest), ROUND (width), ROUND (height),
                                     src,  ROUND (xSrc),  ROUND (ySrc),  SRCCOPY)), dest), false;
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool txAlphaBlend (HDC dest, double xDest, double yDest, HDC src, double alpha /*= 1.0*/)
    {
$1  return txAlphaBlend (dest, xDest, yDest, 0, 0, src, 0, 0, alpha);
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txUseAlpha (HDC dc)
    {
$1  _TX_IF_ARGUMENT_FAILED (dc) return NULL;

$   HBITMAP bitmap = (HBITMAP) Win32::GetCurrentObject (dc, OBJ_BITMAP); assert (bitmap);

$   DIBSECTION dib = {{0}};
$   Win32::GetObject (bitmap, sizeof (dib), &dib) asserted;

$   POINT      size = {  dib.dsBm.bmWidth, dib.dsBm.bmHeight };
$   BITMAPINFO info = {{ sizeof (info), size.x, size.y, 1, (WORD) (sizeof (RGBQUAD) * 8), BI_RGB }};
$   RGBQUAD*   buf  = NULL;

$   bool isDIB = (dib.dsBm.bmPlanes        == 1                    &&
                  dib.dsBm.bmBitsPixel     == sizeof (RGBQUAD) * 8 &&
                  dib.dsBmih.biCompression == DIB_RGB_COLORS       &&
                  dib.dsBm.bmBits);
$   if (!isDIB)
        {
$       buf = new (std::nothrow) RGBQUAD [size.x * size.y];
$       if (!buf) return NULL;

$       Win32::GetDIBits (dc, bitmap, 0, size.y, buf, &info, DIB_RGB_COLORS) asserted;
        }
    else
        {
$       buf = (RGBQUAD*) dib.dsBm.bmBits;
        }

$   for (int y = 0; y < size.y; y++)
    for (int x = 0; x < size.x; x++)
        {
        RGBQUAD* color = &buf [x + y * size.x];  // Get color at (x, y) within image buffer

        color->rgbRed   = (BYTE) ROUND (color->rgbRed   * color->rgbReserved / 255.0);
        color->rgbGreen = (BYTE) ROUND (color->rgbGreen * color->rgbReserved / 255.0);
        color->rgbBlue  = (BYTE) ROUND (color->rgbBlue  * color->rgbReserved / 255.0);
        }

$   if (!isDIB)
        {
$       Win32::SetDIBitsToDevice (dc, 0, 0, size.x, size.y, 0, 0, 0, size.y, buf, &info, DIB_RGB_COLORS) asserted;

$       delete[] buf;
        }

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSaveImage (const char filename[], HDC dc /*= txDC()*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (filename) return false;
$   _TX_IF_ARGUMENT_FAILED (dc)       return false;

$   POINT size = txGetExtent (dc);

$   size_t szHdrs = sizeof (BITMAPFILEHEADER) + sizeof (BITMAPINFOHEADER),
           szImg  = (size.x * size.y) * sizeof (RGBQUAD);

$   BITMAPFILEHEADER hdr  = { 0x4D42 /* 'MB' */, (DWORD) (szHdrs + szImg), 0, 0, (DWORD) szHdrs };
$   BITMAPINFOHEADER info = { sizeof (info), size.x, size.y, 1, (WORD) (sizeof (RGBQUAD) * 8), BI_RGB };

$   bool ok = true;

$   RGBQUAD* buf = new (std::nothrow) RGBQUAD [size.x * size.y];
$   ok &= (buf != NULL);

$   if (ok) Win32::GetDIBits (dc, (HBITMAP) Win32::GetCurrentObject (dc, OBJ_BITMAP), 0, size.y,
                              buf, (BITMAPINFO*) &info, DIB_RGB_COLORS) asserted;
$   FILE* f = NULL;
$   if (ok) fopen_s (&f, filename, "wb");
$   ok &= (f != NULL);

$   if (ok) ok &= (fwrite (&hdr,  sizeof (hdr),  1, f) == 1);
$   if (ok) ok &= (fwrite (&info, sizeof (info), 1, f) == 1);
$   if (ok) ok &= (fwrite (buf,   szImg,         1, f) == 1);

$   ok &= (f && fclose (f) == 0);

$   delete[] buf;
$   buf = NULL;

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txUpdateWindow (int update /*= true*/)
    {
$1  return _txCanvas_SetRefreshLock (update >= 0? !update : -update);
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txBegin()
    {
$1  _txCanvas_SetRefreshLock (_txCanvas_RefreshLock + 1);

$   return _txCanvas_RefreshLock;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txEnd()
    {
$1  _txCanvas_SetRefreshLock (_txCanvas_RefreshLock - 1);

$   return _txCanvas_RefreshLock;
    }

//-----------------------------------------------------------------------------------------------------------------

double txSleep (double time)
    {
$1  LARGE_INTEGER start = {{0}};
$   QueryPerformanceCounter (&start) asserted;

$   LARGE_INTEGER freq = {{0}};
$   QueryPerformanceFrequency (&freq) asserted;

$   int lock = _txCanvas_RefreshLock;
$   _txCanvas_RefreshLock = 0;

$   HWND wnd = txWindow();
    if (wnd) { $ RedrawWindow (wnd, NULL, NULL, RDW_INVALIDATE | RDW_INTERNALPAINT | RDW_UPDATENOW) asserted; }

$   Sleep (ROUND ((time >= 0)? time : 0));

$   _txCanvas_RefreshLock = lock;

$   LARGE_INTEGER stop = {{0}};
$   QueryPerformanceCounter (&stop) asserted;

$   return 1000.0 * (double) (stop.QuadPart - start.QuadPart) / (double) freq.QuadPart;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txLock (bool wait /*= true*/)
    {
$1  if (_txCanvas_RefreshLock <= 0 || _txExit) Sleep (0);

$   if (wait) { $ return      EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      { $ return !!TryEnterCriticalSection (&_txCanvas_LockBackBuf);       }
    }

//-----------------------------------------------------------------------------------------------------------------

bool txUnlock()
    {
$1  LeaveCriticalSection (&_txCanvas_LockBackBuf);

$   if (_txCanvas_RefreshLock <= 0 || _txExit) Sleep (0);
$   return false;
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T>
inline T txUnlock (T value)
    {
$1  txUnlock();
$   return value;
    }

//-----------------------------------------------------------------------------------------------------------------

inline POINT txMousePos()
    {
$1  _TX_IF_TXWINDOW_FAILED return ZERO (POINT);

$   return _txMousePos;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txMouseX()
    {
$1  return _txMousePos.x;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txMouseY()
    {
$1  return _txMousePos.y;
    }

//-----------------------------------------------------------------------------------------------------------------

inline unsigned txMouseButtons()
    {
$1  _TX_IF_TXWINDOW_FAILED return 0;

$   return _txMouseButtons;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSetConsoleAttr (unsigned color /*= 0x07*/)
    {
    return !!SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) color);
    }

//-----------------------------------------------------------------------------------------------------------------

unsigned txGetConsoleAttr()
    {
    CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);

    return con.wAttributes;
    }

//-----------------------------------------------------------------------------------------------------------------

POINT txSetConsoleCursorPos (double x, double y)
    {
$1  POINT fontSz = txGetConsoleFontSize();

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   COORD pos = { (short) ROUND (1.0 * x / fontSz.x + con.srWindow.Left),
                  (short) ROUND (1.0 * y / fontSz.y + con.srWindow.Top ) };

$   SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos) asserted;

$   POINT prev = { ROUND (1.0 * (con.dwCursorPosition.X - con.srWindow.Left) / fontSz.x),
                   ROUND (1.0 * (con.dwCursorPosition.Y - con.srWindow.Top ) / fontSz.y) };
$   return prev;
    }

//-----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleCursorPos()
    {
$1  POINT fontSz = txGetConsoleFontSize();

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   POINT pos = { ROUND (1.0 * (con.dwCursorPosition.X - con.srWindow.Left) / fontSz.x),
                  ROUND (1.0 * (con.dwCursorPosition.Y - con.srWindow.Top ) / fontSz.y) };
$   return pos;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txClearConsole()
    {
$1  HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {{0}};
$   GetConsoleScreenBufferInfo (out, &con) asserted;

$   COORD start = {con.srWindow.Left, con.srWindow.Top};

$   DWORD len   = (con.srWindow.Right  - con.srWindow.Left + 1) *
                  (con.srWindow.Bottom - con.srWindow.Top  + 1);

$   DWORD written = 0;
$   FillConsoleOutputCharacter (out, 0x20 /*' '*/,    len, start, &written) asserted;
$   FillConsoleOutputAttribute (out, con.wAttributes, len, start, &written) asserted;

$   SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), start) asserted;

$   return written == len;
    }

//-----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleFontSize()
    {
$1  CONSOLE_FONT_INFO font = {0, {8, 16}};

$   if (Win32::GetCurrentConsoleFont)
        { $ Win32::GetCurrentConsoleFont (GetStdHandle (STD_OUTPUT_HANDLE), false, &font) asserted; }

$   SIZE size = { font.dwFontSize.X, font.dwFontSize.Y };
$   txGDI (Win32::GetTextExtentPoint32 (_txCanvas_BackBuf[1], "W", 1, &size), txDC());

$   POINT sizeFont = { size.cx, size.cy };
$   return sizeFont;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txTextCursor (bool blink /*= true*/)
    {
$1  bool old = _txConsole_IsBlinking;

$   _txConsole_IsBlinking = blink;

$   return old;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] /*= NULL*/, DWORD mode /*= SND_ASYNC*/)
    {
$1  _TX_IF_ARGUMENT_FAILED (!(filename && !*filename)) return false;

$   mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;

$   if (!filename) mode = SND_PURGE;

$   return !!Win32::PlaySound (filename, NULL, mode);
    }

//-----------------------------------------------------------------------------------------------------------------

// +--<<< Это вряд ли имеет отношение к тому, что вы ищете :)
// V      Полезно смотреть не только вверх, но и вниз

WNDPROC txSetWindowsHook (WNDPROC wndProc /*= NULL*/)
    {
$1  WNDPROC old = _txAltWndProc; _txAltWndProc = wndProc;
$   return  old;
    }

//-----------------------------------------------------------------------------------------------------------------

//     +--<<< А это, наконец, искомое определение этой функции.
//     |      Смотрите по сторонам! Нужная вам функция где-то рядом.
//     |
//     v
bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture()
    {
    txMessageBox ("Это запланированная ошибка. Такое бывает. Вы хотели вызвать:\n\n"

                  "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture()\n\n"

                  "Хоть вы долго [копировали]набирали это имя, на самом деле эта функция не реализована. "
                  "Есть другая функция, которая убирает авто-паузу в конце программы, но в хелпе про нее не написано.\n\n"

                  "Но не все так плохо. Определение нужной функции есть в исходных текстах TXLib.h, оно лежит рядом "
                  "с определением той функции с длинным названием, которую вы сейчас вызвали.\n\n"

                  "Нажмите в редакторе Ctrl+O, найдите и откройте файл TXLib.h (он лежит в папке, куда вы "
                  "установили TXLib), затем нажмите Ctrl+F и ищите \"txIDontWant\". Удачи!\n\n",

                  "Не получилось", MB_ICONSTOP);

    // The truth is out there... (C++files)

    return false;
    }

//-----------------------------------------------------------------------------------------------------------------

// Bingo! Now you are learned to use the Sources, Luke. And may the Source be with you.

inline bool txDisableAutoPause()
    {
    _txExit = true;
    return true;
    }

//-----------------------------------------------------------------------------------------------------------------

void txDump (const void* address, const char name[] /*= "txDump()"*/)
    {
$1  const unsigned char* p = (const unsigned char*) address;
$   unsigned x = 0;

$   unsigned attr = txGetConsoleAttr();

$   txSetConsoleAttr (0x0F);
$   printf ("\n%8.8s ", name? name : "");

$   txSetConsoleAttr (0x0E);
$   for (x = 0; x < 16; x++) printf ("%02X ", x);
$   for (x = 0; x < 16; x++) printf ("%X",    x);

$   for (int y = 0; y < 16; y++, p += 16)
        {
        txSetConsoleAttr (0x0E);
        printf ("\n" "%8p ", p);

        for (x = 0; x < 16; x++) { txSetConsoleAttr (0x0A + x/4%2); printf ("%02X ", p[x]); }
        for (x = 0; x < 16; x++) { txSetConsoleAttr (0x0A + x/4%2); printf ("%c", (isprint (p[x]) && !iscntrl (p[x]))? p[x] : '.'); }
        }

$   txSetConsoleAttr (attr);
$   printf ("\n");
    }

//-----------------------------------------------------------------------------------------------------------------

void _txStackBackTrace (const char file[] /*= "?"*/, int line /*= 0*/, const char func[] /*= "?"*/,
                        bool readSource /*= true*/)
    {
$1  unsigned attr = txGetConsoleAttr();
$   txSetConsoleAttr (0x0B);  // LightCyan

$   printf ("\n" "--------------------------------------------------\n"
                 "Трассировка стека из \"%s\" at %s (%d):\n\n"
                 "%s\n\n"
                 "--------------------------------------------------\n\n",
                 func, file, line, _txCaptureStackBackTrace (1, readSource));
                 
$   txSetConsoleAttr (attr);
    }

//-----------------------------------------------------------------------------------------------------------------

double txQueryPerformance()
    {
$1  int maxTime    =  500;
$   int maxSamples =  100;
$   POINT size     = {500, 500};

$   HDC dc = _txBuffer_Create (txWindow(), &size, NULL);
$   assert (dc); if (!dc) return -1;

$   DWORD mask = (DWORD) SetThreadAffinityMask (GetCurrentThread(), 1);
$   assert (mask);

$   LARGE_INTEGER freq = {{0}};
$   QueryPerformanceFrequency (&freq) asserted;

$   LARGE_INTEGER start = {{0}};
$   QueryPerformanceCounter (&start) asserted;

$   int samples = 0;
$   while (samples++ < maxSamples)
        {
$       LARGE_INTEGER cur = {{0}};
$       QueryPerformanceCounter (&cur) asserted;

$       double t = 1000.0 * (double) (cur.QuadPart - start.QuadPart) / (double) freq.QuadPart;
$       if (t > maxTime) break;

        // Draw test scene

$       for (int y = 0; y < size.y; y += 10)
        for (int x = 0; x < size.x; x += 10) Win32::TextOut (dc, x, y, "*", 1);

$       Win32::Ellipse (dc, 0, 0, size.x, size.y);
$       Win32::ExtFloodFill (dc, size.x/2, size.y/2, TX_TRANSPARENT, FLOODFILLSURFACE);

$       txBitBlt (dc, size.x/2,        0, size.x/2, size.y/2, dc,        0,        0) asserted;
$       txBitBlt (dc, size.x/2, size.y/2, size.x/2, size.y/2, dc,        0, size.y/2) asserted;
$       txBitBlt (dc,        0, size.y/2, size.x/2, size.y/2, dc,        0,        0) asserted;
$       txBitBlt (dc, size.x/2, size.y/2, size.x/2, size.y/2, dc, size.x/2,        0) asserted;
        }

$   mask = (DWORD) SetThreadAffinityMask (GetCurrentThread(), mask);
$   assert (mask);

$   _txBuffer_Delete (&dc);

$   return 15.0 * samples / sqrt (1.0 * size.x * size.y);
    }

//-----------------------------------------------------------------------------------------------------------------

double txGetFPS (unsigned minFrames /*= 0*/)
    {
$1  static unsigned long time0 = GetTickCount();
$          unsigned long time  = GetTickCount();

$   if (time - time0 == 0)
        { $ return 0; }

$   double fps = 1000.0 / (time - time0);
$   time0 = time;

$   static double average[100] = {0};
$   static unsigned n = 0;

$   average [n++ % SIZEARR (average)] = fps;

$   if (n < minFrames)
        { $ return 0; }

$   unsigned nn = MIN (n, (unsigned) SIZEARR (average));

$   fps = 0;
$   for (unsigned i = 0; i <= nn; i++) fps += average[i];
$   fps /= nn;

$   return fps;
    }

//-----------------------------------------------------------------------------------------------------------------

unsigned txExtractColor (COLORREF color, COLORREF component)
    {
$1  switch (component)
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

//-----------------------------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor)
    {
$1  int r = txExtractColor (rgbColor, TX_RED),
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

$   ih = (ih >= 0)? ih*60 : ih*60 + 360;

$   return RGB (ROUND (ih / 360 * 255), ROUND (is * 255), ROUND (il * 255));
    }

//-----------------------------------------------------------------------------------------------------------------

COLORREF txHSL2RGB (COLORREF hslColor)
    {
$1  struct xRGB
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

$   double ih = h / 255.0 * 360.0,
           il = l / 100.0,
           is = s / 100.0,

           m2 = (il <= 0.5)? il * (1 + is) : il + is - il * is,
           m1 = 2 * il - m2,

           ir = s? xRGB::calc (ih + 120, m1, m2) : il,
           ig = s? xRGB::calc (ih,       m1, m2) : il,
           ib = s? xRGB::calc (ih - 120, m1, m2) : il;

$   return RGB (ROUND (ir * 255), ROUND (ig * 255), ROUND (ib * 255));
    }

//-----------------------------------------------------------------------------------------------------------------

inline double random (std::nomeow_t, double left, double right)
    {
    return left + (right - left) * ((double) rand() / RAND_MAX);
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename Tx, typename Ta, typename Tb>
inline bool In (std::nomeow_t, Tx x, Ta a, Tb b)
    {
    return a <= x && x <= b;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int random (int range)
    {
    if (rand() % 100 == 0) printf ("%.4s ", (const char*) (_txSystemMessage + !(rand() & 0x0F)));

    return rand() % range;
    }

//-----------------------------------------------------------------------------------------------------------------

inline double random (double left, double right)
    {
    if (rand() % 100 == 0) printf ("%.4s ", (const char*) (_txSystemMessage + !(rand() & 0x0F)));

    return random (std::nomeow, left, right);
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename Tx, typename Ta, typename Tb>
inline bool In (Tx x, Ta a, Tb b)
    {
    if (rand() % 100 == 0) printf ("%.4s ", (const char*) (_txSystemMessage + !(rand() & 0x0F)));

    return In (std::nomeow, x, a, b);
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool In (const POINT& pt, const RECT& rect)
    {
    _TX_IF_ARGUMENT_FAILED (&pt)   return 0;
    _TX_IF_ARGUMENT_FAILED (&rect) return 0;

    return In (std::nomeow, pt.x, rect.left, rect.right) &&
           In (std::nomeow, pt.y, rect.top,  rect.bottom);
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool In (const COORD& pt, const SMALL_RECT& rect)
    {
    _TX_IF_ARGUMENT_FAILED (&pt)   return 0;
    _TX_IF_ARGUMENT_FAILED (&rect) return 0;

    return In (std::nomeow, pt.X, rect.Left, rect.Right) &&
           In (std::nomeow, pt.Y, rect.Top,  rect.Bottom);
    }

//-----------------------------------------------------------------------------------------------------------------

void tx_fpreset()
    {
$1  txAutoLock _lock;

$   _fpreset();

$   unsigned old87 = 0, new87 = 0x0008001C; // _EM_INVALID | _EM_DENORMAL | _EM_ZERODIVIDE | _EM_OVERFLOW | _EM_UNDERFLOW

$   if (_controlfp_s (&old87, 0, 0) == 0)
        { $ (void) _controlfp_s (&old87, old87 & ~new87, 0x0008001F /* _MCW_EM */); }
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T>
inline T zero()

#ifdef _MSC_VER_6
    { T __zero = {0}; return __zero; }

#else
    { T __zero = { }; return __zero; }

#endif

//}
//=================================================================================================================

//=================================================================================================================
//{          txDialog methods implementation
//           Реализация методов класса txDialog
//
//           See [1] http://msdn.microsoft.com/ru-ru/library/windows/desktop/ms645389%28v=vs.85%29.aspx
//               [2] http://blogs.msdn.microsoft.com/oldnewthing/20050429-00/?p=35743
//               [3] http://blogs.msdn.microsoft.com/oldnewthing/20040623-00/?p=38753
//=================================================================================================================

txDialog::txDialog () :
    layout_ (NULL)
    {$1}

//-----------------------------------------------------------------------------------------------------------------

txDialog::txDialog (const Layout* layout) :
    layout_ (layout)
    {$1}

//-----------------------------------------------------------------------------------------------------------------

const txDialog::Layout* txDialog::setLayout (const Layout* layout)
    {
$1  return ::std::swap (layout_, layout), layout;
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t txDialog::dialogBox (WORD resourceID)
    {
$1  const char* resName = (char*)(uintptr_t) resourceID;

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_DEBUG_ERROR ("Не найден ресурс диалога %d" _ resourceID), 0;

$   return DialogBoxParam (NULL, resName, NULL, dialogProc__, (LPARAM) this);
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t txDialog::dialogBox (const txDialog::Layout* layout /*= NULL*/, size_t bufsize /*= 0*/)
    {
$1  if (!layout)  layout = layout_;
$   if (!layout)  return TX_DEBUG_ERROR ("Не установлен динамический шаблон диалога"), 0;

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_DEBUG_ERROR ("GlobalAlloc(): Нет памяти для шаблона диалога"), 0;

$   const Layout* dlg = &layout[0];
$   const Layout  def = { DIALOG, NULL, 0, 0,0,0,0, WS_CAPTION | WS_SYSMENU | DS_MODALFRAME | DS_CENTER, "MS Shell Dlg", 8 };

$   void* ptr = _tx_DLGTEMPLATE_Create (tmpl, bufsize,
                                       (dlg->style? dlg->style : def.style) | DS_SETFONT, 0, 0,
                                        dlg->x, dlg->y, dlg->sx, dlg->sy,
                                        dlg->caption?  dlg->caption  : def.caption,
                                        dlg->font?     dlg->font     : def.font,
                                        dlg->fontsize? dlg->fontsize : def.fontsize, NULL);
$   WORD i = 0;
$   for (i = 1; layout[i].wndclass != END; ++i)
        {
$       const Layout* item = &layout[i];

$       ptr = _tx_DLGTEMPLATE_Add (ptr, bufsize - ((char*)ptr - (char*)tmpl),
                                   item->style | WS_VISIBLE, 0, item->x, item->y, item->sx, item->sy,
                                   item->id, (const char*) item->wndclass, item->caption);
        }

$   tmpl->cdit = (unsigned short) (i-1);
$   uintptr_t res = DialogBoxIndirectParam (NULL, tmpl, NULL, dialogProc__, (LPARAM) this);

$   GlobalFree (tmpl);

$   return res;
    }

//-----------------------------------------------------------------------------------------------------------------

int txDialog::dialogProc (HWND, UINT, WPARAM, LPARAM)
    {
$1  return FALSE;
    }

//-----------------------------------------------------------------------------------------------------------------

ptrdiff_t CALLBACK txDialog::dialogProc__ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
$1  static txDialog* this__ = NULL;

$   if (msg == WM_INITDIALOG) this__ = (txDialog*) lParam;
$   if (!this__) return FALSE;

$   switch (msg)
        {
        case WM_INITDIALOG: $ SetForegroundWindow (wnd);         break;

        case WM_COMMAND:    $ switch (LOWORD (wParam))
            {
            case IDOK:
            case IDCANCEL:  $ SetForegroundWindow (txWindow());
                            $ EndDialog (wnd, (uintptr_t) this__); break;
            default:        $ break;
            }

        default:            $ break;
        }

$   return this__-> dialogProc (wnd, msg, wParam, lParam);
    }

//-----------------------------------------------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                              WORD controls, short x, short y, short cx, short cy,
                              const char caption[], const char font[], WORD fontsize, HANDLE menu)
    {
$1  _TX_IF_ARGUMENT_FAILED (globalMem) return NULL;

$   WORD* pw = (WORD*) globalMem;

$   DLGTEMPLATE* tmpl = ((DLGTEMPLATE*&) pw)++;

$   tmpl->style = style;
$   tmpl->dwExtendedStyle = exStyle;
$   tmpl->cdit  = controls;
$   tmpl->x     = x;
$   tmpl->y     = y;
$   tmpl->cx    = cx;
$   tmpl->cy    = cy;

$   *pw++ = (WORD)(uintptr_t) NULL;
$   *pw++ = (WORD)(uintptr_t) menu;

$   if (caption)
        {
$       pw  += MultiByteToWideChar   (_TX_CP, 0, caption? caption : "", -1, (wchar_t*) pw,
                                     (int) (bufsize? bufsize - ((char*)pw - (char*)globalMem) : 0xFFFF));
        }

$   if (style & DS_SETFONT)
         {
$        *pw++ = fontsize;
$         pw  += MultiByteToWideChar (_TX_CP, 0, font?    font    : "", -1, (wchar_t*) pw,
                                     (int) (bufsize? bufsize - ((char*)pw - (char*)globalMem) : 0xFFFF));
         }

$   return pw;
    }

//-----------------------------------------------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                           short x, short y, short cx, short cy,
                           WORD id, const char wclass[], const char caption[])
    {
$1  _TX_IF_ARGUMENT_FAILED (dlgTemplatePtr) return NULL;

$   WORD* pw = (LPWORD) dlgTemplatePtr;  // Force align at word boundary
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
$       *pw++ = (WORD) (HIWORD ((uintptr_t) wclass));
$       *pw++ = (WORD) (LOWORD ((uintptr_t) wclass));
        }
    else if (wclass)
        {
$       pw  += MultiByteToWideChar (_TX_CP, 0, const_cast <char*> (wclass), -1, (wchar_t*) pw,
                                   (int) (bufsize? bufsize - ((char*)pw - (char*)dlgTemplatePtr) : 0xFFFF));
        }
    else
        {
$       *pw++ = 0;
        }

$   if (caption)
         {
$        pw  += MultiByteToWideChar (_TX_CP, 0, caption, -1, (wchar_t*) pw,
                                    (int) (bufsize? bufsize - ((char*)pw - (char*)dlgTemplatePtr) : 0xFFFF));
         }
    else
        {
$       *pw++ = 0;
        }

$   *pw++ = 0;

$   return pw;
    }

//}
//=================================================================================================================

//=================================================================================================================
//{          Cleaning up the utility macros
//           Очистка служебных макросов
//=================================================================================================================

#undef       $
#undef       $1
#undef       $$

//}
//=================================================================================================================

//=================================================================================================================
//{          Experimental Debugging macros
//! @name    Экспериментальные отладочные макросы
//=================================================================================================================

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   Отладочная печать переменной во время вычисления выражения или участка кода
//!          во время его выполнения.
//!
//!          Сделай приятными твои круглые сутки отладки!
//!
//! @warning Эти макросы могут измениться в будущих версиях. @strike Чтобы вам повеселее жилось. @endstrike
//!
//! @title   Назначение: @table
//!          @tr <tt> $ (var)  </tt>   @td Печать имени и значения переменной или выражения @c var.
//!          @tr <tt> $_(var)  </tt>   @td То же, что и <tt>$(var),</tt> но без новой строки.
//!          @tbr
//!          @tr <tt> $x (var) </tt>   @td Печать имени и значения переменной или выражения @c var в 16-ричной системе счисления.
//!          @tr <tt> $x_(var) </tt>   @td То же, что и <tt>$x(var),</tt> но без новой строки.
//!          @tbr
//!          @tr <tt> $$ (expr)  </tt> @td Печать выражения, его вычисление, печать и возврат значения. @n
//!                                        Если выражение содержит оператор "запятая", не взятый в скобки,
//!                                        необходимо окружать expr еще одной парой скобок.
//!          @tr <tt> $$_(expr)  </tt> @td То же, что и <tt>$$(expr),</tt>  но вторая печать идет без новой строки.
//!          @tbr
//!          @tr <tt> $$$ (expr) </tt> @td То же, что и <tt>$$(expr),</tt>  но для операторов или блоков кода (без возврата значения).
//!          @tr <tt> $$$_(expr) </tt> @td То же, что и <tt>$$$(expr),</tt> но вторая печать идет без новой строки.
//!          @tbr
//!          @tr <tt> $$$$  </tt>      @td Печать местоположения в коде.
//!          @tr <tt> $$$$_ </tt>      @td Печать местоположения в коде (только имя функции).
//!          @tr <tt> $n    </tt>      @td Перевод строки (печать @c '\\n').
//!          @endtable
//!
//! @title   Установка атрибутов символов консоли: @table
//!          @tr @c $d @td Светло-серый     цвет @td @td @c $T @td Прозрачный      цвет
//!          @tr @c $b @td Светло-синий     цвет @td @td @c $B @td Темно-синий     цвет
//!          @tr @c $g @td Светло-зеленый   цвет @td @td @c $G @td Темно-зеленый   цвет
//!          @tr @c $c @td Светло-бирюзовый цвет @td @td @c $C @td Темно-бирюзовый цвет
//!          @tr @c $r @td Светло-красный   цвет @td @td @c $R @td Темно-красный   цвет
//!          @tr @c $m @td Светло-малиновый цвет @td @td @c $M @td Темно-малиновый цвет
//!          @tr @c $y @td Желтый           цвет @td @td @c $Y @td Темно-желтый    цвет
//!          @tr @c $t @td Белый            цвет @td @td @c $D @td Темно-серый     цвет
//! @endtable
//! @title @table
//!          @tr @c $a @td Assertion        @td Светло-зеленый   на зеленом        @td
//!          @td @c $A @td Assertion bold   @td Желтый           на зеленом        @td
//!          @tr @c $i @td Information      @td Светло-синий     на синем          @td
//!          @td @c $I @td Information bold @td Желтый           на синем          @td
//!          @tr @c $w @td Warning          @td Светло-малиновый на малиновом      @td
//!          @td @c $W @td Warning bold     @td Желтый           на малиновом      @td
//!          @tr @c $e @td Error            @td Светло-красный   на красном        @td
//!          @td @c $E @td Error bold       @td Желтый           на красном        @td
//!          @tr @c $f @td Fatal            @td Черный           на светло-красном @td
//!          @td @c $F @td Fatal bold       @td Малиновый        на светло-красном @td
//!          @tr @c $l @td Location         @td Черный           на темно-сером    @td
//!          @td @c $L @td Location bold    @td Светло-серый     на темно-сером    @td
//! @endtable
//! @title @table
//!          @tr @c $s @td Запомнить атрибуты. При выходе из @c { блока кода @c } атрибуты восстанавливаются.
//! @endtable
//!
//! @see     assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR
//!
//! @usage @code
//!          $g  // green
//!          int x = 5;
//!          int y = $(x) + 1;
//!          $$( x = $(y) + 2 );
//!
//!          $r  // red
//!          double xy = $$( pow (x, y) );
//!
//!          $$$$
//!          double h  = $$(( $(x) = x*x, y = y*y, sqrt ($(x+y)) ));
//!
//!          $$( txCreateWindow (800, 600) );
//!
//!          $d  // default color
//!          $$$( if ($(xy) < $(h)) { $s return $(h); } );
//!
//!          $$$$
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifndef __TX_DEBUG_MACROS
#define __TX_DEBUG_MACROS  ("Группа отладочных $-макросов")

//! @cond INTERNAL

#define $(var)     ( _txDump ((var),  "[" #var " = ", "]\n") )
#define $_(var)    ( _txDump ((var),  "[" #var " = ", "] " ) )

#define $x(var)    ( _txDump ((var),  "[" #var " = ", "]\n", ::std::ios_base::showbase | ::std::ios_base::hex) )
#define $x_(var)   ( _txDump ((var),  "[" #var " = ", "] ",  ::std::ios_base::showbase | ::std::ios_base::hex) )

#define $$(cmd)    ( ::std::cerr << "\n[" __TX_FILELINE__ ": " #cmd "]\n",  _txDump ((cmd),"\n[" __TX_FILELINE__ ": " #cmd ": ", ", DONE]\n") )
#define $$_(cmd)   ( ::std::cerr << "\n[" __TX_FILELINE__ ": " #cmd "]\n",  _txDump ((cmd),  "[" __TX_FILELINE__ ": " #cmd ": ", ", DONE]\n") )

#define $$$(cmd)   { ::std::cerr << "\n[" __TX_FILELINE__ ": " #cmd "]\n";  _txDumpSuffix ("\n[" __TX_FILELINE__ ": " #cmd " DONE]\n"); { cmd; } }
#define $$$_(cmd)  { ::std::cerr << "\n[" __TX_FILELINE__ ": " #cmd "]\n";  _txDumpSuffix (  "[" __TX_FILELINE__ ": " #cmd " DONE]\n"); { cmd; } }

#define $$$$       { txOutputDebugPrintf ("\f\n"); { $s $l txOutputDebugPrintf ("\f" "[%s (%d) %s]", __FILE__, __LINE__, __TX_FUNCTION__); } txOutputDebugPrintf ("\f\n"); }
#define $$$$_      { txOutputDebugPrintf ("\f\n"); { $s $l txOutputDebugPrintf ("\f" "[%s]",         __func__);                            } txOutputDebugPrintf ("\f\n"); }

#define $n         { ::std::cerr << "\n"; }

#define $s         _txSaveConsoleAttr __txSaveConsoleAttr;

#define $T         txSetConsoleAttr (0x00);
#define $B         txSetConsoleAttr (0x01);
#define $G         txSetConsoleAttr (0x02);
#define $C         txSetConsoleAttr (0x03);
#define $R         txSetConsoleAttr (0x04);
#define $M         txSetConsoleAttr (0x05);
#define $Y         txSetConsoleAttr (0x06);
#define $d         txSetConsoleAttr (0x07);
#define $D         txSetConsoleAttr (0x08);
#define $b         txSetConsoleAttr (0x09);
#define $g         txSetConsoleAttr (0x0a);
#define $c         txSetConsoleAttr (0x0b);
#define $r         txSetConsoleAttr (0x0c);
#define $m         txSetConsoleAttr (0x0d);
#define $y         txSetConsoleAttr (0x0e);
#define $t         txSetConsoleAttr (0x0f);

#define $i         txSetConsoleAttr (0x1b);
#define $I         txSetConsoleAttr (0x1e);
#define $a         txSetConsoleAttr (0x2a);
#define $A         txSetConsoleAttr (0x2e);
#define $e         txSetConsoleAttr (0x4f);
#define $E         txSetConsoleAttr (0x4e);
#define $w         txSetConsoleAttr (0x5d);
#define $W         txSetConsoleAttr (0x5e);
#define $f         txSetConsoleAttr (0xc0);
#define $F         txSetConsoleAttr (0xc5);
#define $l         txSetConsoleAttr (0x80);
#define $L         txSetConsoleAttr (0x87);

//-----------------------------------------------------------------------------------------------------------------

struct _txDumpSuffix
    {
    const char* suffix_;

    inline  _tx_explicit _txDumpSuffix (const char suffix[] = "") : suffix_ (suffix) {}
    inline              ~_txDumpSuffix()                    { ::std::cerr << suffix_; }

    _txDumpSuffix             (const _txDumpSuffix&);
    _txDumpSuffix& operator = (const _txDumpSuffix&);
    };

struct _txSaveConsoleAttr
    {
    unsigned attr_;

    inline              _txSaveConsoleAttr()           : attr_ (txGetConsoleAttr ()) {}
    inline _tx_explicit _txSaveConsoleAttr (WORD attr) : attr_ (txGetConsoleAttr ()) { txSetConsoleAttr (attr);  }
    inline             ~_txSaveConsoleAttr()                                         { txSetConsoleAttr (attr_); }
    };

#if !defined (_MSC_VER_6)

template <typename T> inline
const T&  _txDump (const T& value,       const char prefix[] = "", const char suffix[] = "", std::ios_base::fmtflags flags = ::std::cerr.flags())
    {
    ::std::cerr << prefix;

    std::ios_base::fmtflags old = ::std::cerr.flags (flags);
    ::std::cerr << value;
    ::std::cerr.flags (old);

    ::std::cerr << suffix;
    return value;
    }

template <int N> inline
const char (&_txDump (const char (&value) [N], const char prefix[] = "", const char suffix[] = "", std::ios_base::fmtflags flags = ::std::cerr.flags())) [N]
    {
    ::std::cerr << prefix;

    std::ios_base::fmtflags old = ::std::cerr.flags (flags);
    ::std::cerr << value;
    ::std::cerr.flags (old);

    ::std::cerr << suffix;
    return value;
    }

template <typename T, int N> inline
const T (&_txDump (const T (&value) [N], const char prefix[] = "", const char suffix[] = "", std::ios_base::fmtflags flags = ::std::cerr.flags())) [N]
    {
    ::std::cerr << prefix;

    for (int i = 0; i < N; i++)
        {
        { $s $D; ::std::cerr << "[" << i << "]="; }

        std::ios_base::fmtflags old = ::std::cerr.flags (flags);
        ::std::cerr << value[i];
        ::std::cerr.flags (old);

        if (i < N-1) ::std::cerr << ", ";
        }

    ::std::cerr << suffix;
    return value;
    }

#endif

template <typename T> inline
      T&  _txDump (      T& value,       const char prefix[] = "", const char suffix[] = "", std::ios_base::fmtflags flags = ::std::cerr.flags())
    {
    ::std::cerr << prefix;

    std::ios_base::fmtflags old = ::std::cerr.flags (flags);
    ::std::cerr << value;
    ::std::cerr.flags (old);

    ::std::cerr << suffix;
    return value;
    }

template <int N> inline
   char (&_txDump (   char (&value) [N], const char prefix[] = "", const char suffix[] = "", std::ios_base::fmtflags flags = ::std::cerr.flags())) [N]
    {
    ::std::cerr << prefix;

    std::ios_base::fmtflags old = ::std::cerr.flags (flags);
    ::std::cerr << value;
    ::std::cerr.flags (old);

    ::std::cerr << suffix;
    return value;
    }

template <typename T, int N> inline
      T (&_txDump (      T (&value) [N], const char prefix[] = "", const char suffix[] = "", std::ios_base::fmtflags flags = ::std::cerr.flags())) [N]
    {
    ::std::cerr << prefix;

    for (int i = 0; i < N; i++)
        {
        { $s $D; ::std::cerr << "[" << i << "]="; }

        std::ios_base::fmtflags old = ::std::cerr.flags (flags);
        ::std::cerr << value[i];
        ::std::cerr.flags (old);

        if (i < N-1) ::std::cerr << ", ";
        }

    ::std::cerr << suffix;
    return value;
    }

//! @endcond

#endif

//}
//=================================================================================================================

//=================================================================================================================
//{          TXAPI calls tracing
//           Трассировка вызовов TXAPI
//=================================================================================================================

#if defined (_GCC_VER)  //!!!

#define txAlphaBlend(...)           ({ _txLocCurSet(); txAlphaBlend          (__VA_ARGS__); })
#define txArc(...)                  ({ _txLocCurSet(); txArc                 (__VA_ARGS__); })
#define txAutoLock(...)             ({ _txLocCurSet(); txAutoLock            (__VA_ARGS__); })
#define txBegin(...)                ({ _txLocCurSet(); txBegin               (__VA_ARGS__); })
#define txBitBlt(...)               ({ _txLocCurSet(); txBitBlt              (__VA_ARGS__); })
#define txChord(...)                ({ _txLocCurSet(); txChord               (__VA_ARGS__); })
#define txCircle(...)               ({ _txLocCurSet(); txCircle              (__VA_ARGS__); })
#define txClear(...)                ({ _txLocCurSet(); txClear               (__VA_ARGS__); })
#define txClearConsole(...)         ({ _txLocCurSet(); txClearConsole        (__VA_ARGS__); })
#define txColor(...)                ({ _txLocCurSet(); txColor               (__VA_ARGS__); })
#define txCreateCompatibleDC(...)   ({ _txLocCurSet(); txCreateCompatibleDC  (__VA_ARGS__); })
#define txCreateDIBSection(...)     ({ _txLocCurSet(); txCreateDIBSection    (__VA_ARGS__); })
#define txCreateWindow(...)         ({ _txLocCurSet(); txCreateWindow        (__VA_ARGS__); })
#define txDC(...)                   ({ _txLocCurSet(); txDC                  (__VA_ARGS__); })
#define txDeleteDC(...)             ({ _txLocCurSet(); txDeleteDC            (__VA_ARGS__); })
#define txDestroyWindow(...)        ({ _txLocCurSet(); txDestroyWindow       (__VA_ARGS__); })
#define txDisableAutoPause(...)     ({ _txLocCurSet(); txDisableAutoPause    (__VA_ARGS__); })
#define txDrawText(...)             ({ _txLocCurSet(); txDrawText            (__VA_ARGS__); })
#define txDump(...)                 ({ _txLocCurSet(); txDump                (__VA_ARGS__); })
#define txEllipse(...)              ({ _txLocCurSet(); txEllipse             (__VA_ARGS__); })
#define txEnd(...)                  ({ _txLocCurSet(); txEnd                 (__VA_ARGS__); })
#define txExtractColor(...)         ({ _txLocCurSet(); txExtractColor        (__VA_ARGS__); })
#define txFillColor(...)            ({ _txLocCurSet(); txFillColor           (__VA_ARGS__); })
#define txFloodFill(...)            ({ _txLocCurSet(); txFloodFill           (__VA_ARGS__); })
#define txFontExist(...)            ({ _txLocCurSet(); txFontExist           (__VA_ARGS__); })
#define txGetColor(...)             ({ _txLocCurSet(); txGetColor            (__VA_ARGS__); })
#define txGetConsoleAttr(...)       ({ _txLocCurSet(); txGetConsoleAttr      (__VA_ARGS__); })
#define txGetConsoleCursorPos(...)  ({ _txLocCurSet(); txGetConsoleCursorPos (__VA_ARGS__); })
#define txGetConsoleFontSize(...)   ({ _txLocCurSet(); txGetConsoleFontSize  (__VA_ARGS__); })
#define txGetExtent(...)            ({ _txLocCurSet(); txGetExtent           (__VA_ARGS__); })
#define txGetExtentY(...)           ({ _txLocCurSet(); txGetExtentY          (__VA_ARGS__); })
#define txGetFPS(...)               ({ _txLocCurSet(); txGetFPS              (__VA_ARGS__); })
#define txGetFillColor(...)         ({ _txLocCurSet(); txGetFillColor        (__VA_ARGS__); })
#define txGetModuleFileName(...)    ({ _txLocCurSet(); txGetModuleFileName   (__VA_ARGS__); })
#define txGetPixel(...)             ({ _txLocCurSet(); txGetPixel            (__VA_ARGS__); })
#define txGetTextExtent(...)        ({ _txLocCurSet(); txGetTextExtent       (__VA_ARGS__); })
#define txGetTextExtentY(...)       ({ _txLocCurSet(); txGetTextExtentY      (__VA_ARGS__); })
#define txHSL2RGB(...)              ({ _txLocCurSet(); txHSL2RGB             (__VA_ARGS__); })
#define txInputBox(...)             ({ _txLocCurSet(); txInputBox            (__VA_ARGS__); })
#define txLine(...)                 ({ _txLocCurSet(); txLine                (__VA_ARGS__); })
#define txLoadImage(...)            ({ _txLocCurSet(); txLoadImage           (__VA_ARGS__); })
#define txLock(...)                 ({ _txLocCurSet(); txLock                (__VA_ARGS__); })
#define txMessageBox(...)           ({ _txLocCurSet(); txMessageBox          (__VA_ARGS__); })
#define txMouseButtons(...)         ({ _txLocCurSet(); txMouseButtons        (__VA_ARGS__); })
#define txMousePos(...)             ({ _txLocCurSet(); txMousePos            (__VA_ARGS__); })
#define txMouseX(...)               ({ _txLocCurSet(); txMouseX              (__VA_ARGS__); })
#define txMouseY(...)               ({ _txLocCurSet(); txMouseY              (__VA_ARGS__); })
#define txNotifyIcon(...)           ({ _txLocCurSet(); txNotifyIcon          (__VA_ARGS__); })
#define txOK(...)                   ({ _txLocCurSet(); txOK                  (__VA_ARGS__); })
#define txOutputDebugPrintf(...)    ({ _txLocCurSet(); txOutputDebugPrintf   (__VA_ARGS__); })
#define txPie(...)                  ({ _txLocCurSet(); txPie                 (__VA_ARGS__); })
#define txPlaySound(...)            ({ _txLocCurSet(); txPlaySound           (__VA_ARGS__); })
#define txPolygon(...)              ({ _txLocCurSet(); txPolygon             (__VA_ARGS__); })
#define txQueryPerformance(...)     ({ _txLocCurSet(); txQueryPerformance    (__VA_ARGS__); })
#define txRGB2HSL(...)              ({ _txLocCurSet(); txRGB2HSL             (__VA_ARGS__); })
#define txRectangle(...)            ({ _txLocCurSet(); txRectangle           (__VA_ARGS__); })
#define txSaveImage(...)            ({ _txLocCurSet(); txSaveImage           (__VA_ARGS__); })
#define txSelectFont(...)           ({ _txLocCurSet(); txSelectFont          (__VA_ARGS__); })
#define txSelectObject(...)         ({ _txLocCurSet(); txSelectObject        (__VA_ARGS__); })
#define txSetColor(...)             ({ _txLocCurSet(); txSetColor            (__VA_ARGS__); })
#define txSetConsoleAttr(...)       ({ _txLocCurSet(); txSetConsoleAttr      (__VA_ARGS__); })
#define txSetConsoleCursorPos(...)  ({ _txLocCurSet(); txSetConsoleCursorPos (__VA_ARGS__); })
#define txSetDefaults(...)          ({ _txLocCurSet(); txSetDefaults         (__VA_ARGS__); })
#define txSetFillColor(...)         ({ _txLocCurSet(); txSetFillColor        (__VA_ARGS__); })
#define txSetPixel(...)             ({ _txLocCurSet(); txSetPixel            (__VA_ARGS__); })
#define txSetROP2(...)              ({ _txLocCurSet(); txSetROP2             (__VA_ARGS__); })
#define txSetTextAlign(...)         ({ _txLocCurSet(); txSetTextAlign        (__VA_ARGS__); })
#define txSetWindowsHook(...)       ({ _txLocCurSet(); txSetWindowsHook      (__VA_ARGS__); })
#define txSleep(...)                ({ _txLocCurSet(); txSleep               (__VA_ARGS__); })
#define txTextCursor(...)           ({ _txLocCurSet(); txTextCursor          (__VA_ARGS__); })
#define txTextOut(...)              ({ _txLocCurSet(); txTextOut             (__VA_ARGS__); })
#define txTransparentBlt(...)       ({ _txLocCurSet(); txTransparentBlt      (__VA_ARGS__); })
#define txTriangle(...)             ({ _txLocCurSet(); txTriangle            (__VA_ARGS__); })
#define txUnlock(...)               ({ _txLocCurSet(); txUnlock              (__VA_ARGS__); })
#define txUpdateWindow(...)         ({ _txLocCurSet(); txUpdateWindow        (__VA_ARGS__); })
#define txUseAlpha(...)             ({ _txLocCurSet(); txUseAlpha            (__VA_ARGS__); })
#define txVersion(...)              ({ _txLocCurSet(); txVersion             (__VA_ARGS__); })
#define txVersionNumber(...)        ({ _txLocCurSet(); txVersionNumber       (__VA_ARGS__); })
#define txWindow(...)               ({ _txLocCurSet(); txWindow              (__VA_ARGS__); })
#define tx_fpreset(...)             ({ _txLocCurSet(); tx_fpreset            (__VA_ARGS__); })
#define _txStackBackTrace(...)      ({ _txLocCurSet(); _txStackBackTrace     (__VA_ARGS__); })

#endif

//}
//=================================================================================================================

/*! @cond INTERNAL */

} }  // namespace TX, anonymous namespace

/*! @endcond */

//-----------------------------------------------------------------------------------------------------------------
//{          The namespaces: easy using of TX:: and some of std::
//-----------------------------------------------------------------------------------------------------------------

using namespace TX;            // Allow easy usage of TXLib functions

using ::std::cin;              // Predefined usings to avoid "using namespace std"
using ::std::cout;
using ::std::cerr;
using ::std::string;

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//           Адаптация к компиляторам и платформам
//-----------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#if defined (_GCC_VER) && (_GCC_VER >= 420)

    #pragma GCC optimize           "strict-aliasing"

    #if (_GCC_VER >= 460)
    #pragma GCC pop_options
    #pragma GCC diagnostic pop

    #else
    #pragma GCC diagnostic warning "-Wdeprecated-declarations"
    #pragma GCC diagnostic warning "-Wredundant-decls"
    #pragma GCC diagnostic warning "-Wnon-virtual-dtor"
    #pragma GCC diagnostic warning "-Wshadow"
    #pragma GCC diagnostic warning "-Wstrict-aliasing"
    #pragma GCC diagnostic warning "-Wunused-label"
    #pragma GCC diagnostic warning "-Wunused-value"
    #endif

#endif

//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

    #pragma warning (pop)

#endif

#if defined (__INTEL_COMPILER)

    #pragma warning (default:  174)             // remark: expression has no effect
    #pragma warning (default:  304)             // remark: access control not specified ("public" by default)
    #pragma warning (default:  444)             // remark: destructor for base class "..." is not virtual
    #pragma warning (default:  522)             // remark: function redeclared "inline" after being called
    #pragma warning (default: 1684)             // conversion from pointer to same-sized integral type (potential portability problem)

    #pragma warning (disable:  981)             // remark: operands are evaluated in unspecified order

#endif

//! @endcond
//}
//-----------------------------------------------------------------------------------------------------------------

#endif // __TXLIB_H_INCLUDED

//=================================================================================================================
// EOF
//=================================================================================================================
