//=================================================================================================================
//           [These sections are for folding control  in Code::Blocks]         [$Date: 2020-07-08 18:51:07 +0400 $]
//           [Best viewed with "Fold all on file open" option enabled]         [Best screen/page width = 120 chars]
//                                                                                                                 
//           [If RUSSIAN CHARS below are UNREADABLE, check this file codepage. It should be CP1251, NOT UTF-8 etc.]
//{          [Use RELOAD options in your IDE or editor (CLion / Visual Studio Code / ...), and do NOT use Convert.]
//=================================================================================================================
//!
//! @file    TXLib.h
//! @brief   ���������� ������ ��������� (The Dumb Artist Library, TX Library, TXLib).
//!
//!          $Version: 00173a, Revision: 166 $
//!          $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//!          $Date: 2020-07-08 18:51:07 +0400 $
//!
//!          TX Library -- ���������� ���������� ��������� ������� ��� MS Windows �� �++.
//!          ��� ��������� "���������" ��� ���������� ����������� � ����� ������ �� � ��������
//!          ���������� ��������� ����������������. ������������ �� ������� �����.
//!          ��������� TX Library -- ��������� ������ ���� � ���������������� � �����������
//!          � ���������� � �����������������.
//!
//!          TX Library is a tiny 2D graphics library for MS Windows written in C++. This is a small
//!          sandbox for the very beginners to help them to learn basic programming principles.
//!          The documentation is currently in Russian.
//!
//!          ����������� ���� ����������: <a href=http://txlib.ru>txlib.ru.</a>
//!
//!          ��. ����� <a href=http://sourceforge.net/p/txlib>�������� ������� �� SourceForge.</a>
//!          �������� ������ �� ������-������������: <a href=http://gg.gg/TXLib>gg.gg/TXLib.</a>
//!
//! @par     ��������� ����������
//!
//! @note    ���������� TXLib ������� �� ������������� ����� � �� ������� ������� �������� � �����
//!          ����������������, ����� ��������� �� ��������� � ������ ��� ����������.
//!
//! @note    ���� ���������� ������� � ����� ��������������� �����, ������� �������� �������� �� �����������
//!          ������������� ������������������ ������ � �������� � ���������� �����������. ��. ������ @ref TX_COMPILED.
//!          ����� ����� ���������� ������ @c WIN32_LEAN_AND_MEAN �� ��������� @c TXLib.h � ���������.
//!
//!       -# <a href=https://sourceforge.net/projects/txlib/files/latest/download>��������</a> ��������� ���������,
//!          �������� �� ������ �������� �������������. �� ��� ����� ��� <tt>TXLib-v0173a.rar.exe.</tt> ����� �����
//!          ���������� (��� ����� ������), ���������� @c .exe ����� �� ������������, � ����������� �� �������� Windows.
//!       -# ��������� ��������� ��������� ���������. ��������� ��������� -- ��� ���������������������
//!          �����, ��� �� ������� ������ ���� ��� �������.
//!       -# �� ������� ����� �������� "����� ��� TX". �������� ��� � ��������� ������� ������ <tt>TXLib Help,</tt>
//!          ������� ��. ���������� ������ ��. <http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/a00001.htm>
//!          �����.</a> ������ ������� ��. <a href=http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/dirs.htm>
//!          � ����� Examples,</a> � ����� Examples/Demo.
//!
//!       -  ���� ��� ��������� ���������� ������ ��� ������ ��������� ��������� ����������, �������� ���� ����������
//!          @c TXLib.h <a href=http://storage.ded32.net.ru/Lib/TX/TXUpdate/TXLib.h> ������</a>, ��������� (Ctrl+S)
//!          ��� � ���� ������� �����, ��� �� ���������� ���� ���������.
//!          ����������� <a href=http://storage.ded32.net.ru/Lib/TX/TXUpdate/Doc/HTML.ru/index.htm> �������� ������ ������.</a>
//!
//!       -# ��� ������ ��������� ������ ���������� ��������� ������, ������� ���������� ���������� (�����������) � �����
//!          Windows. ������������� ��� ���������� �� �����������. ���������, ������������ TXLib, ����������� � ��� ���.
//!
//!          -# ������ ���������� Microsoft DBGHELP ��� ������� � ���������� �������� Microsoft:
//!
//!             - @c dbghelp32.dll ��� dbghe32.dll - ��� 32-��������� �������� (���� @c dbghelp.dll, 32-��������� ������),
//!             - @c dbghelp64.dll ��� dbghe64.dll - ��� 64-��������� �������� (���� @c dbghelp.dll, 64-��������� ������),
//!
//!          -# ������ ���������� <a href=https://github.com/jrfonseca/drmingw/releases>DrMinGW</a> ��� �������
//!             � ���������� �������� MinGW ����������� GCC @c g++:
//!
//!             - @c mgwhelp32.dll ��� mgwhe32.dll - ��� 32-��������� �������� (���� @c mgwhelp.dll, 32-��������� ������),
//!             - @c mgwhelp64.dll ��� mgwhe64.dll - ��� 64-��������� �������� (���� @c mgwhelp.dll, 64-��������� ������).
//!
//!          �������� @c 32 � @c 64 �������� �������� 32-��������� � 64-��������� ������ DLL-������ ���������.
//!          ��������, @c dbghelp32.dll -- ��� ������ ��������������� 32-��������� ������ ����� @c dbghelp.dll.
//!
//!          <b>C�������������������� ����� � ����� ������������ ����� �������
//!          <a href=http://storage.ded32.net.ru/Lib/TX/TXLib-SupportDLLs.rar.exe>�����.</a></b>
//!
//!          ��� �������� ������ ����������� ������ ��������� ���������� ����������� ��� ����������. ��������,
//!          ��� ����������� GCC @c g++ -- � ������� ����� ��������� ������ @c -O0. ������ ����� ����������������
//!          ��������� ������ ��� ����� ��-�������, ��������, � CodeBlocks ����� ������� ���� -- Settings --
//!          Compiler -- (Global Compiler Settings) -- (Compiler Settings) -- Other Options.
//!
//! @note    ������� �������� � ��������� ����� ���������� ������ ���� ����������� ��� Windows CP1251, ���������
//!          ���. � ������ ������ ���������� ��� ��������������� ��-�������, ��������, � CodeBlocks �����
//!          ������� ���� -- Settings -- Editor -- (General Settings) -- Other Settings -- Encoding. �����
//!          ������� ����� � ���������� TXLib ����� ������������ �����������.
//!
//! @warning <b>��� �����-������. ��� ������������� ���������� ��������� ������������ � �� �������.</b> @nn
//!          <a href=http://www.ded32.ru/index/0-6>������� ������������� ���������� ���������� � �����</a> ��. ��
//!          <a href=http://txlib.ru>����������� ����� TXLib.</a>
//!
//! @par     ���-������ �� GitHub:
//!        - <a href=https://github.com/ded32/TXLib/issues/new><b>�������� �� ������</b></a>
//!
//           $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//-----------------------------------------------------------------------------------------------------------------
//!
//! @defgroup Drawing   ���������
//! @defgroup Mouse     ��������� ����!
//! @defgroup Dialogs   ���������� ����
//! @defgroup Misc      ������
//! @defgroup Technical ����������� ������
//}
//=================================================================================================================

#if !defined (__TXLIB_H_INCLUDED)                // <<<<<<<<< THE CODE IS HERE, UNFOLD IT <<<<<<<<<<<<<<<<<<<<<<<<<
#define       __TXLIB_H_INCLUDED

//-----------------------------------------------------------------------------------------------------------------
//{          Version information and configuration
//-----------------------------------------------------------------------------------------------------------------

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup   Technical
//! @brief     ������� ������ ����������.
//!
//!            ������ ���������� � ������������� �������: ������� ����� -- ����� ������, ������� -- ����� �������,
//!            � �������-���������� �������. ��������, @c 0x172a0050 -- ������ @c 0.172a, ������� @c 50.
//! @code
//!            #define _TX_VERSION "TXLib [Ver: 1.73a, Rev: 164, Date: 2020-01-30 05:00:00 +0300]"  //
//!            #define _TX_AUTHOR  "Copyright (C) Ded (Ilya Dedinsky, http://txlib.ru)"             //  ������
//!            #define _TX_VER      0x173a0000                                                      //
//! @endcode
//!            ��� ��������� ������������� ����������� ��� ��������� ������.
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

#define _TX_VER      _TX_v_FROM_CVS ($VersionInfo: , TXLib.h, 00173a, 166, 2020-07-08 18:51:07 +0400, "Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru>", $)
#define _TX_VERSION  _TX_V_FROM_CVS ($VersionInfo: , TXLib.h, 00173a, 166, 2020-07-08 18:51:07 +0400, "Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru>", $)
#define _TX_AUTHOR   _TX_A_FROM_CVS ($VersionInfo: , TXLib.h, 00173a, 166, 2020-07-08 18:51:07 +0400, "Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru>", $)

//! @cond INTERNAL
#define _TX_v_FROM_CVS(_1,file,ver,rev,date,auth,_2)  ((0x##ver##u << 16) | 0x##rev##u)
#define _TX_V_FROM_CVS(_1,file,ver,rev,date,auth,_2)  "TXLib [Ver: " #ver ", Rev: " #rev ", Date: " #date "]"
#define _TX_A_FROM_CVS(_1,file,ver,rev,date,auth,_2)  "Copyright (C) " auth
//! @endcond

//! @}
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��� ������ TXLib. ������ � ��������������� ���������.
//!
//! @note    ����� �������������� �� ��������� ����� TXLib.h.
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (_TX_MODULE)
    #define   _TX_MODULE      "TXLib"
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��� � ������ �������� �����������
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if    defined (__GNUC__)

    #define _GCC_VER          ( __GNUC__*100 + __GNUC_MINOR__*10 + __GNUC_PATCHLEVEL__ )

    #define __TX_COMPILER__   "GNU g++ "            TX_QUOTE (__GNUC__)       "."  \
                                                    TX_QUOTE (__GNUC_MINOR__) "."  \
                                                    TX_QUOTE (__GNUC_PATCHLEVEL__) \
                              ", std="              TX_QUOTE (__cplusplus)

#elif  defined (__clang__) || defined (__clang_major__)

    #define _CLANG_VER        ( __clang_major__*100 + __clang_minor__*10 + __clang_patchlevel__ )

    #define __TX_COMPILER__   "Clang "              TX_QUOTE (__clang_major__) "."  \
                                                    TX_QUOTE (__clang_minor__) "."  \
                                                    TX_QUOTE (__clang_patchlevel__) \
                              ", std="              TX_QUOTE (__cplusplus)
#elif  defined (_MSC_VER)

    #define __TX_COMPILER__   "MSVS "               TX_QUOTE (_MSC_VER)            \
                              ", std="              TX_QUOTE (__cplusplus)

#elif  defined (__INTEL_COMPILER)

    #define __TX_COMPILER__   "Intel C++ "          TX_QUOTE (__INTEL_COMPILER)    \
                              ", std="              TX_QUOTE (__cplusplus)
#else

    #define __TX_COMPILER__   "Unknown C++, std="   TX_QUOTE (__cplusplus)
    #endif

//! @cond INTERNAL

#define  TX_QUOTE(sym)        _TX_QUOTE (sym)
#define _TX_QUOTE(sym)        #sym

#define  TX_JOIN(sym1, sym2)  _TX_JOIN (sym1, sym2)
#define _TX_JOIN(sym1, sym2)  sym1 ## sym2

//! @endcond

#if (__cplusplus >= 201103L) || defined (_MSC_VER) && (_MSC_VER >= 1800)  // MSVC 2013

    #define _TX_CPP11         1
    #endif

#if (__cplusplus >= 201103L) || defined (_MSC_VER) && (_MSC_VER >= 1900)  // MSVC 2015

    #define _TX_CPP11_MSVC15  1
    #endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��� ������ ������
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
//! @brief   ������, �������������� � ��� ����� � ����� ������ �����, ��� �� ����������.
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define __TX_FILELINE__       __FILE__ " (" TX_QUOTE (__LINE__) ")"

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��� ������� �������
//!
//! @warning ���� ����������� ����� ������� �� �������������� ������������, �� __TX_FUNCTION__ ������������ � ���
//!          ��������� ����� � ����� ������.
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if defined (__GNUC__) || defined (__clang__) || defined (__clang_major__)
    #define __TX_FUNCTION__   __PRETTY_FUNCTION__

#elif defined (__FUNCSIG__)
    #define __TX_FUNCTION__   __FUNCSIG__

#elif defined (__FUNCTION__)
    #define __TX_FUNCTION__   __FUNCTION__

#elif defined (__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)
    #define __TX_FUNCTION__   __FUNCTION__

#elif defined (__BORLANDC__) && (__BORLANDC__ >= 0x550)
    #define __TX_FUNCTION__   __FUNC__

#elif defined (__cplusplus) && (__cplusplus >= 199711L)
    #define __TX_FUNCTION__   __func__

#elif defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)
    #define __TX_FUNCTION__   __func__

#elif defined (__PYTHON__)
    #error No Python. No. Using parseltongue languages can lead you to Slytherin.

#else
    #define __TX_FUNCTION__   "(" __TX_FILELINE__ ")"

#endif

#if !defined (__func__) && defined (__FUNCTION__)
    #define   __func__        __FUNCTION__

#endif

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    ��������� � ������������ � ����������
//-----------------------------------------------------------------------------------------------------------------
//! @{ @cond INTERNAL

#if !defined (__cplusplus)

    #ifdef __GNUC__
    #error
    #error ---------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Must use C++ to compile TXLib.h. Now you are using C only.
    #error
    #error CHECK source file EXTENSION. Maybe it is ".C". It must be ".CPP".
    #error If your file is named, for example, "Untitled.C", go to menu [File],
    #error then [Save As] and rename it to "Untitled.CPP". Please do NOT use spaces.
    #error ---------------------------------------------------------------------------------------
    #error

#endif

//-----------------------------------------------------------------------------------------------------------------

#if !defined (WIN32) && !defined (__WIN32__) && !defined(_WIN32) && !defined(_WIN32_WINNT) && !defined (__CYGWIN__)

    #ifdef __GNUC__
    #error
    #error ---------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Windows (MSVC/Win32 or GCC/MinGW or Cygwin) is the only supported OS, sorry.
    #error
    #error In Linux or MacOS, you should write your own TXLib and share it with your friends, or use wine.
    #error ---------------------------------------------------------------------------------------
    #error

#endif

//-----------------------------------------------------------------------------------------------------------------

#if  defined (UNICODE) || defined (_UNICODE)

    #ifdef __GNUC__
    #warning TXLib.h: Disabling the UNICODE
    #endif

    #undef   UNICODE                             // Burn Unicode, burn
    #undef  _UNICODE

    #if defined (_WINDOWS_H) || defined (_INC_WINDOWS) || defined (_WINDOWS_) || defined (__WINDOWS__)

    #ifdef __GNUC__
    #error
    #error ---------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Should include "TXLib.h" BEFORE or INSTEAD of <Windows.h> in UNICODE mode.
    #error
    #error REARRANGE your #include directives, or DISABLE the UNICODE mode by #undef UNICODE/_UNICODE.
    #error ---------------------------------------------------------------------------------------
    #error

    #endif

#endif

//-----------------------------------------------------------------------------------------------------------------

#if  defined (__STRICT_ANSI__)                   // Try to extend strict ANSI rules

    #undef  __STRICT_ANSI__
    #define __STRICT_ANSI__UNDEFINED

    #if defined (_STRING_H_) || defined (_INC_STRING) || defined (_STDIO_H_) || defined (_INC_STDIO)

    #ifdef __GNUC__
    #error
    #error ---------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: Should include "TXLib.h" BEFORE <string.h> or <stdio.h> in Strict ANSI mode.
    #error
    #error REARRANGE your #include directives, or DISABLE ANSI-compliancy by #undef __STRICT_ANSI__.
    #error ---------------------------------------------------------------------------------------
    #error

    #endif

#endif

//-----------------------------------------------------------------------------------------------------------------

#if  defined (__GNUC__)

    #pragma GCC diagnostic ignored     "-Wpragmas"

    #pragma GCC diagnostic warning     "-Wall"
    #pragma GCC diagnostic warning     "-Weffc++"
    #pragma GCC diagnostic warning     "-Wextra"

    #pragma GCC diagnostic warning     "-Waggressive-loop-optimizations"
    #pragma GCC diagnostic warning     "-Walloc-zero"
    #pragma GCC diagnostic warning     "-Walloca"
    #pragma GCC diagnostic warning     "-Walloca-larger-than=8192"
    #pragma GCC diagnostic warning     "-Warray-bounds"
    #pragma GCC diagnostic warning     "-Wcast-align"
    #pragma GCC diagnostic warning     "-Wcast-qual"
    #pragma GCC diagnostic warning     "-Wchar-subscripts"
    #pragma GCC diagnostic warning     "-Wconditionally-supported"
    #pragma GCC diagnostic warning     "-Wconversion"
    #pragma GCC diagnostic warning     "-Wctor-dtor-privacy"
    #pragma GCC diagnostic warning     "-Wdangling-else"
    #pragma GCC diagnostic warning     "-Wduplicated-branches"
    #pragma GCC diagnostic warning     "-Wempty-body"
    #pragma GCC diagnostic warning     "-Wfloat-equal"
    #pragma GCC diagnostic warning     "-Wformat-nonliteral"
    #pragma GCC diagnostic warning     "-Wformat-overflow=2"
    #pragma GCC diagnostic warning     "-Wformat-security"
    #pragma GCC diagnostic warning     "-Wformat-signedness"
    #pragma GCC diagnostic warning     "-Wformat-truncation=2"
    #pragma GCC diagnostic warning     "-Wformat=2"
    #pragma GCC diagnostic warning     "-Wlarger-than=8192"
    #pragma GCC diagnostic warning     "-Wlogical-op"
    #pragma GCC diagnostic warning     "-Wmissing-declarations"
    #pragma GCC diagnostic warning     "-Wnarrowing"
    #pragma GCC diagnostic warning     "-Wnon-virtual-dtor"
    #pragma GCC diagnostic warning     "-Wnonnull"
    #pragma GCC diagnostic warning     "-Wopenmp-simd"
    #pragma GCC diagnostic warning     "-Woverloaded-virtual"
    #pragma GCC diagnostic warning     "-Wpacked"
    #pragma GCC diagnostic warning     "-Wpointer-arith"
    #pragma GCC diagnostic warning     "-Wredundant-decls"
    #pragma GCC diagnostic warning     "-Wrestrict"
    #pragma GCC diagnostic warning     "-Wshadow"
    #pragma GCC diagnostic warning     "-Wsign-promo"
    #pragma GCC diagnostic warning     "-Wstack-usage=8192"
    #pragma GCC diagnostic warning     "-Wstrict-aliasing"
    #pragma GCC diagnostic warning     "-Wstrict-null-sentinel"
    #pragma GCC diagnostic warning     "-Wstrict-overflow=2"
    #pragma GCC diagnostic warning     "-Wstringop-overflow=4"
    #pragma GCC diagnostic warning     "-Wsuggest-attribute=noreturn"
    #pragma GCC diagnostic warning     "-Wsuggest-final-methods"
    #pragma GCC diagnostic warning     "-Wsuggest-final-types"
    #pragma GCC diagnostic warning     "-Wsuggest-override"
    #pragma GCC diagnostic warning     "-Wswitch-default"
    #pragma GCC diagnostic warning     "-Wswitch-enum"
    #pragma GCC diagnostic warning     "-Wsync-nand"
    #pragma GCC diagnostic warning     "-Wundef"
    #pragma GCC diagnostic warning     "-Wunused"
    #pragma GCC diagnostic warning     "-Wvarargs"
    #pragma GCC diagnostic warning     "-Wvariadic-macros"
    #pragma GCC diagnostic warning     "-Wvla-larger-than=8192"

    #pragma GCC diagnostic error       "-Wsizeof-array-argument"

    #pragma GCC diagnostic ignored     "-Winline"
    #pragma GCC diagnostic ignored     "-Wliteral-suffix"
    #pragma GCC diagnostic ignored     "-Wmissing-field-initializers"
    #pragma GCC diagnostic ignored     "-Wnonnull-compare"
    #pragma GCC diagnostic ignored     "-Wold-style-cast"
    #pragma GCC diagnostic ignored     "-Wunreachable-code"
    #pragma GCC diagnostic ignored     "-Wunused-const-variable"
    #pragma GCC diagnostic ignored     "-Wunused-function"

    #pragma GCC diagnostic warning     "-Wpragmas"

    //{ These warning settings for TXLib.h only and will be re-enabled at end of file:

    #pragma GCC push_options
    #pragma GCC diagnostic push

    #pragma GCC diagnostic ignored     "-Wpragmas"

    #pragma GCC diagnostic ignored     "-Waddress"
    #pragma GCC diagnostic ignored     "-Warray-bounds"
    #pragma GCC diagnostic ignored     "-Wclobbered"
    #pragma GCC diagnostic ignored     "-Wdeprecated-declarations"
    #pragma GCC diagnostic ignored     "-Wfloat-equal"
    #pragma GCC diagnostic ignored     "-Wformat-nonliteral"
    #pragma GCC diagnostic ignored     "-Wlarger-than="
    #pragma GCC diagnostic ignored     "-Wnon-virtual-dtor"
    #pragma GCC diagnostic ignored     "-Wredundant-decls"
    #pragma GCC diagnostic ignored     "-Wshadow"
    #pragma GCC diagnostic ignored     "-Wsign-conversion"
    #pragma GCC diagnostic ignored     "-Wstrict-aliasing"
    #pragma GCC diagnostic ignored     "-Wunused-label"    // Just for fun in _txCanvas_OnCmdAbout()
    #pragma GCC diagnostic ignored     "-Wunused-value"
    #pragma GCC diagnostic ignored     "-Wformat-zero-length"
    #pragma GCC diagnostic ignored     "-Wpacked-not-aligned"
    #pragma GCC optimize               "no-strict-aliasing"

    #if (__cplusplus < 201402L)
    #pragma GCC diagnostic ignored     "-Wsuggest-override"
    #endif

    #pragma GCC diagnostic warning     "-Wpragmas"

    #if defined (__CYGWIN__) && !defined (_TX_TESTING)
    #pragma GCC system_header                    // This is not a fair play, but this is the only way to deal with Cygwin :(
    #endif

    //}

    #define _tx_thread                 __thread
    #define _tx_decltype(value)        __decltype (value)

    #ifndef     MINGW_HAS_SECURE_API
        #define MINGW_HAS_SECURE_API   1
    #endif

    #if defined (TX_USE_SFML)
        #define _GLIBCXX_NDEBUG
    #endif

    #ifndef     _GLIBCXX_NDEBUG                  // TXLib enables _GLIBCXX_DEBUG by default. When using third-party libraries
        #define _GLIBCXX_DEBUG                   // compiled without _GLIBCXX_DEBUG (SFML, for example), #define _GLIBCXX_NDEBUG
        #define _GLIBCXX_DEBUG_PEDANTIC          // *before* including TXLib.h.
    #endif

    #if defined (_WIN64)                         // removed in x86 because printf ("%lg", double) failure, this prints 0 always
    #ifndef     __USE_MINGW_ANSI_STDIO
        #define __USE_MINGW_ANSI_STDIO 1
    #endif
    #endif

    template <typename T>
    inline T _txNOP (T value)          { return value; }   // To suppress performance warnings in assert etc.

    // From MinGW\include\float.h which is replaced by MinGW\lib\gcc\i686-pc-mingw32\x.x.x\include\float.h
    extern "C" __declspec (dllimport)  unsigned __cdecl _controlfp (unsigned control, unsigned mask);
    extern "C"                         void     __cdecl _fpreset   ();

#else

    #define     __attribute__( attr )
    #define     _txNOP( value )        ( value )

#endif

//-----------------------------------------------------------------------------------------------------------------

#if  defined (__clang__) || defined (__clang_major__)

    #pragma clang diagnostic ignored   "-Wunknown-pragmas"

    #pragma clang diagnostic warning   "-Wall"
    #pragma clang diagnostic warning   "-Weffc++"
    #pragma clang diagnostic warning   "-Wextra"

    #pragma clang diagnostic warning   "-Wcast-qual"
    #pragma clang diagnostic warning   "-Wchar-subscripts"
    #pragma clang diagnostic warning   "-Wconversion"
    #pragma clang diagnostic warning   "-Wctor-dtor-privacy"
    #pragma clang diagnostic warning   "-Wempty-body"
    #pragma clang diagnostic warning   "-Wfloat-equal"
    #pragma clang diagnostic warning   "-Wformat"
    #pragma clang diagnostic warning   "-Wformat-nonliteral"
    #pragma clang diagnostic warning   "-Wformat-security"
    #pragma clang diagnostic warning   "-Wmissing-declarations"
    #pragma clang diagnostic warning   "-Wnon-virtual-dtor"
    #pragma clang diagnostic warning   "-Woverloaded-virtual"
    #pragma clang diagnostic warning   "-Wpacked"
    #pragma clang diagnostic warning   "-Wpointer-arith"
    #pragma clang diagnostic warning   "-Wredundant-decls"
    #pragma clang diagnostic warning   "-Wshadow"
    #pragma clang diagnostic warning   "-Wsign-promo"
    #pragma clang diagnostic warning   "-Wstrict-aliasing"
    #pragma clang diagnostic warning   "-Wstrict-overflow"
    #pragma clang diagnostic warning   "-Wswitch-default"
    #pragma clang diagnostic warning   "-Wswitch-enum"
    #pragma clang diagnostic warning   "-Wunused"
    #pragma clang diagnostic warning   "-Wvariadic-macros"

    #pragma clang diagnostic ignored   "-Winvalid-source-encoding"
    #pragma clang diagnostic ignored   "-Wunused-const-variable"
    #pragma clang diagnostic ignored   "-Wunused-variable"

    #pragma clang diagnostic warning   "-Wunknown-pragmas"

    //{ These warning settings for TXLib.h only and will be re-enabled at end of file:

    #pragma clang diagnostic push

    #pragma clang diagnostic ignored   "-Wunknown-pragmas"

    #pragma clang diagnostic ignored   "-Wcast-align"
    #pragma clang diagnostic ignored   "-Wfloat-conversion"
    #pragma clang diagnostic ignored   "-Wmissing-braces"
    #pragma clang diagnostic ignored   "-Wmissing-field-initializers"
    #pragma clang diagnostic ignored   "-Wsign-compare"
    #pragma clang diagnostic ignored   "-Wsign-conversion"
    #pragma clang diagnostic ignored   "-Wstring-plus-int"
    #pragma clang diagnostic ignored   "-Wundef"
    #pragma clang diagnostic ignored   "-Wunused-function"
    #pragma clang diagnostic ignored   "-Wunused-value"

    #pragma clang diagnostic warning   "-Wunknown-pragmas"

    //{ CLang-Tidy options
    //
    // *,-cert-dcl50-cpp,-cert-dcl58-cpp,-cert-err52-cpp,-cert-err58-cpp,-cert-flp30-c,-cert-msc30-c,-cert-msc32-c,
    // -cert-msc50-cpp,-cert-msc51-cpp,-clang-analyzer-core.DivideZero,-cppcoreguidelines-avoid-c-arrays,
    // -cppcoreguidelines-avoid-goto,-cppcoreguidelines-avoid-magic-numbers,-cppcoreguidelines-macro-usage,
    // -cppcoreguidelines-owning-memory,-cppcoreguidelines-pro-bounds-array-to-pointer-decay,-cppcoreguidelines-no-malloc,
    // -cppcoreguidelines-pro-bounds-constant-array-index,-cppcoreguidelines-pro-bounds-pointer-arithmetic,
    // -cppcoreguidelines-pro-type-const-cast,-cppcoreguidelines-pro-type-cstyle-cast,-cppcoreguidelines-pro-type-union-access,
    // -cppcoreguidelines-pro-type-vararg,-fuchsia-default-arguments-calls,-fuchsia-default-arguments-declarations,
    // -fuchsia-overloaded-operator,-google-build-using-namespace,-google-global-names-in-headers,-google-runtime-int,
    // -google-readability-braces-around-statements,-google-readability-casting,-google-readability-namespace-comments,
    // -hicpp-avoid-c-arrays,-hicpp-avoid-goto,-hicpp-braces-around-statements,-hicpp-deprecated-headers,-hicpp-no-array-decay,
    // -hicpp-signed-bitwise,-hicpp-use-equals-delete,-hicpp-use-nullptr,-hicpp-vararg,-llvm-include-order,-hicpp-no-malloc,
    // -llvm-namespace-comment,-misc-non-private-member-variables-in-classes,-modernize-avoid-c-arrays,-modernize-use-auto,
    // -modernize-deprecated-headers,-modernize-raw-string-literal,-modernize-use-default-member-init,-hicpp-use-auto,
    // -modernize-use-equals-delete,-modernize-use-nullptr,-modernize-use-trailing-return-type,-modernize-use-using,
    // -readability-braces-around-statements,-readability-else-after-return,-readability-implicit-bool-conversion,
    // -readability-isolate-declaration,-readability-magic-numbers,-readability-named-parameter,-modernize-loop-convert
    //}

    //}

#endif

//-----------------------------------------------------------------------------------------------------------------

#if  defined (_MSC_VER)

    #pragma warning (push, 4)                    // Set maximum warning level. This 'push' is to set the level only. It will NOT be popped.

    #pragma warning (disable:    4616)           // #pragma warning: warning number 'n' not a valid compiler warning

    #pragma warning (disable:    4514)           // Unreferenced inline function has been removed
    #pragma warning (disable:    4710)           // Function not inlined
    #pragma warning (disable:    4786)           // Identifier was truncated to '255' characters in the debug information

    #pragma warning (error:      4715)           // Not all control paths return a value

    #pragma warning (default:    4616)           // #pragma warning: warning number 'n' not a valid compiler warning

    // These warning settings for TXLib.h only and will be re-enabled at end of file:

    #pragma warning (push)

    #pragma warning (disable:    4616)           // #pragma warning: warning number 'n' not a valid compiler warning

    #pragma warning (disable:    4091)           // 'typedef': ignored on left of '...' when no variable is declared
    #pragma warning (disable:    4124)           // Using __fastcall with stack checking is ineffective
    #pragma warning (disable:    4127)           // Conditional expression is constant
    #pragma warning (disable:    4200)           // Nonstandard extension used: zero-sized array in struct/union
    #pragma warning (disable:    4201)           // Nonstandard extension used: nameless struct/union
    #pragma warning (disable:    4351)           // New behavior: elements of array will be default initialized
    #pragma warning (disable:    4480)           // Nonstandard extension used: specifying underlying type for enum 'type'
    #pragma warning (disable:    4481)           // Nonstandard extension used: override specifier 'override'
    #pragma warning (disable:    4555)           // Result of expression not used
    #pragma warning (disable:    4611)           // Interaction between '_setjmp' and C++ object destruction is non-portable
    #pragma warning (disable:    5045)           // Compiler will insert Spectre mitigation for memory load if /Qspectre switch specified
    #pragma warning (disable:    6269)           // Possibly incorrect order of operations: dereference ignored
    #pragma warning (disable:    6285)           // (<non-zero constant>) || (<non-zero constant>) is always a non-zero constant. Did you intend to use bitwize-and operator?
    #pragma warning (disable:    6319)           // Use of the comma-operator in a tested expression causes the left argument to be ignored when it has no side-effects
    #pragma warning (disable:    6326)           // Potential comparison of a constant with another constant
    #pragma warning (disable:   26135)           // Missing locking annotation
    #pragma warning (disable:   26400)           // Do not assign the result of an allocation or a function call with an owner<T> return value to a raw pointer, use owner<T> instead (i.11).
    #pragma warning (disable:   26401)           // Do not delete a raw pointer that is not an owner<T> (i.11).
    #pragma warning (disable:   26403)           // Reset or explicitly delete an owner<T> pointer 'name' (r.3).
    #pragma warning (disable:   26408)           // Avoid malloc() and free(), prefer the nothrow version of new with delete (r.10).
    #pragma warning (disable:   26409)           // Avoid calling new and delete explicitly, use std::make_unique<T> instead (r.11).
    #pragma warning (disable:   26426)           // Global initializer calls a non-constexpr function 'name' (i.22).
    #pragma warning (disable:   26429)           // Symbol 'name' is never tested for nullness, it can be marked as not_null (f.23).
    #pragma warning (disable:   26430)           // Symbol 'name' is not tested for nullness on all paths (f.23).
    #pragma warning (disable:   26432)           // If you define or delete any default operation in the type 'struct 'name'', define or delete them all (c.21).
    #pragma warning (disable:   26435)           // Function 'name' should specify exactly one of 'virtual', 'override', or 'final' (c.128).
    #pragma warning (disable:   26438)           // Avoid 'goto' (es.76).
    #pragma warning (disable:   26440)           // Function 'name' can be declared 'noexcept' (f.6).
    #pragma warning (disable:   26446)           // Prefer to use gsl::at() instead of unchecked subscript operator (bounds.4).
    #pragma warning (disable:   26447)           // The function is declared 'noexcept' but calls function 'func' which may throw exceptions (f.6).
    #pragma warning (disable:   26448)           // Consider using gsl::finally if final action is intended (gsl.util).
    #pragma warning (disable:   26451)           // Arithmetic overflow: Using operator 'op' on a n-byte value and then casting the result to a m-byte value. Cast the value to the wider type before calling operator 'op' to avoid overflow (io.2).
    #pragma warning (disable:   26455)           // Default constructor may not throw. Declare it 'noexcept' (f.6).
    #pragma warning (disable:   26460)           // The reference argument 'stream' for function 'name' can be marked as const (con.3).
    #pragma warning (disable:   26461)           // The pointer argument 'name' for function 'name' can be marked as a pointer to const (con.3).
    #pragma warning (disable:   26462)           // The value pointed to by 'name' is assigned only once, mark it as a pointer to const (con.4).
    #pragma warning (disable:   26475)           // Do not use function style C-casts (es.49).
    #pragma warning (disable:   26477)           // Use 'nullptr' rather than 0 or NULL (es.47).
    #pragma warning (disable:   26481)           // Don't use pointer arithmetic. Use span instead (bounds.1).
    #pragma warning (disable:   26482)           // Only index into arrays using constant expressions (bounds.2).
    #pragma warning (disable:   26483)           // Value 'value' is outside the bounds (min, max) of variable 'name'. Only index into arrays using constant expressions that are within bounds of the array (bounds.2).
    #pragma warning (disable:   26485)           // Expression 'expr': No array to pointer decay (bounds.3).
    #pragma warning (disable:   26486)           // Don't pass a pointer that may be invalid to a function. Parameter 'n' 'name' in call to 'name' may be invalid (lifetime.3).
    #pragma warning (disable:   26487)           // Don't return a pointer 'name' that may be invalid (lifetime.4).
    #pragma warning (disable:   26488)           // Do not dereference a potentially null pointer: 'name'. 'name' was null at line 'n' (lifetime.1).
    #pragma warning (disable:   26489)           // Don't dereference a pointer that may be invalid: 'name'. 'name' may have been invalidated at line 'n' (lifetime.1).
    #pragma warning (disable:   26490)           // Don't use reinterpret_cast (type.1).
    #pragma warning (disable:   26492)           // Don't use const_cast to cast away const or volatile (type.3).
    #pragma warning (disable:   26493)           // Don't use C-style casts (type.4).
    #pragma warning (disable:   26496)           // The variable 'name' is assigned only once, mark it as const (con.4).
    #pragma warning (disable:   26497)           // The function 'name' could be marked constexpr if compile-time evaluation is desired (f.4).
    #pragma warning (disable:   26812)           // The enum type 'type' is unscoped. Prefer 'enum class' over 'enum' (Enum.3).
    #pragma warning (disable:   26814)           // The const variable 'name' can be computed at compile-time. Consider using constexpr (con.5).
    #pragma warning (disable:   28125)           // The function must be called from within a try/except block
    #pragma warning (disable:   28159)           // Consider using another function instead

    #pragma warning (default:    4616)           // #pragma warning: warning number 'n' not a valid compiler warning

    #define _tx_thread          __declspec (thread)
    #define _tx_decltype(value)   decltype (value)

    #if !defined (_CLANG_VER)

    #pragma setlocale           ("russian")      // Set source file encoding, see also _TX_CODEPAGE

    #if !defined (NDEBUG)
        #pragma check_stack     (      on)       // Turn on stack probes at runtime
        #pragma strict_gs_check (push, on)       // Detects stack buffer overruns
    #endif

    #endif

    #define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES  1

#endif

//-----------------------------------------------------------------------------------------------------------------

#if  defined (__INTEL_COMPILER)

    #pragma warning (disable:    174)            // Remark: expression has no effect
    #pragma warning (disable:    304)            // Remark: access control not specified ("public" by default)
    #pragma warning (disable:    444)            // Remark: destructor for base class "..." is not virtual
    #pragma warning (disable:    522)            // Remark: function "..." redeclared "inline" after being called
    #pragma warning (disable:    981)            // Remark: operands are evaluated in unspecified order
    #pragma warning (disable:   1684)            // Conversion from pointer to same-sized integral type (potential portability problem)

#endif

//-----------------------------------------------------------------------------------------------------------------

#if (defined (_GCC_VER) && (_GCC_VER <  472)  || \
     defined (_MSC_VER) && (_MSC_VER < 1600)) // Minimum requirements are now GCC 4.7.2 or MSVC 10.0 (2010)

    #ifdef __GNUC__
    #error
    #error ---------------------------------------------------------------------------------------
    #endif
    #error TXLib.h: This version will NOT work with GCC < 4.7.2 or MS Visual Studio < 2010, sorry.
    #error
    #error Please use TXLib.h previous stable version/revision OR upgrade your compiler.
    #error ---------------------------------------------------------------------------------------
    #error

#endif

//-----------------------------------------------------------------------------------------------------------------

#if defined (_GCC_VER) && (_GCC_VER >= 492)
#if defined (TX_USE_SPEAK) && !__has_include (<SAPI.h>)

    #ifdef __GNUC__
    #error
    #error ---------------------------------------------------------------------------------------
    #endif
    #error You have defined TX_USE_SPEAK, but your compiler do NOT have the library <SAPI.h>.
    #error
    #error Please use compiler library set with SAPI.h included. SAPI is Microsoft Speech API
    #error nesessary for txSpeak() to work.
    #error ---------------------------------------------------------------------------------------
    #error

#endif
#endif

//-----------------------------------------------------------------------------------------------------------------

#if !defined (WINVER)
    #define   WINVER                   0x0500    // Defaults to Windows 2000
    #define   WINDOWS_ENABLE_CPLUSPLUS           // Allow use of type-limit macros in <basetsd.h>,
#endif                                           //   they are allowed by default if WINVER >= 0x0600.

#if !defined (_WIN32_WINNT)
    #define   _WIN32_WINNT             WINVER    // Defaults to the same as WINVER
#endif

#if !defined (_WIN32_IE)
    #define   _WIN32_IE                WINVER    // Defaults to the same as WINVER
#endif

#define stristr(  str1, str2 )         Win32::StrStrIA ((str1), (str2))
#define stristrw( str1, str2 )         Win32::StrStrIW ((str1), (str2))

//-----------------------------------------------------------------------------------------------------------------

#define _USE_MATH_DEFINES              1         // Math.h's M_PI etc.
#define __STDC_FORMAT_MACROS           1         // PRIu64 and other PR... macros
#define __STDC_WANT_LIB_EXT1__         1         // String and output *_s functions

#define _LIBCPP_ENABLE_CXX17_REMOVED_UNEXPECTED_FUNCTIONS  // Wow, how long. Kudos, Clang

#define _ALLOW_RTCc_IN_STL             1         // MSVC C2338: /RTCc rejects conformant code, so it isn't supported by libc.

#define NOMINMAX                       1         // Preventing 'min' and 'max' defines in Windows.h

#if defined (_DEBUG)
#define _SECURE_SCL                    1         // Enable checked STL iterators to throw an exception on incorrect use
#define _HAS_ITERATOR_DEBUGGING        1
#define _LIBCPP_DEBUG                  1
#endif

#if defined (_MSC_VER) && defined (_DEBUG)

    #define _CRTDBG_MAP_ALLOC                    // Enable MSVCRT debug heap
    #define _new_dbg                   new (_NORMAL_BLOCK, __FILE__, __LINE__)
    #define NEW                        new (_NORMAL_BLOCK, __FILE__, __LINE__)

#else
    #define _new_dbg                   new
    #define NEW                        new

#endif

#if !( defined (_MSC_VER) && (_MSC_VER < 1900) ) // MSVC 2015
#define _SECURE_SCL_THROWS             1
#endif

#define     tx_noreturn                __attribute__ (( noreturn           ))
#define     tx_nodiscard               __attribute__ (( warn_unused_result ))
#define     tx_deprecated              __attribute__ (( deprecated         ))
#define     tx_printfy( formatArgN )   __attribute__ (( format (printf, (formatArgN), (formatArgN)+1) ))
#define     tx_scanfy(  formatArgN )   __attribute__ (( format (scanf,  (formatArgN), (formatArgN)+1) ))


#if defined (_TX_CPP11)

    #define _tx_delete                 = delete
    #define _tx_default                = default
    #define _tx_override               override
    #define _tx_final                  final

#else

    #define _tx_delete
    #define _tx_default
    #define _tx_override
    #define _tx_final

#endif

namespace std { enum nomeow_t { nomeow }; }      // Vital addition to the C++ standard. TODO: Should contact C++ std committee.

//-----------------------------------------------------------------------------------------------------------------

//! @} @endcond
//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          The Includes
//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)
    #pragma warning (push, 3)                    // MSVC: At level /Wall, some std headers emit warnings... O_o

    #pragma warning (disable: 4365)              // 'argument': conversion from 'long' to 'unsigned int', signed/unsigned mismatch
    #pragma warning (disable: 4005)              // 'name': macro redefinition
#endif

//-----------------------------------------------------------------------------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <float.h>

#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

#if !defined (__CYGWIN__)
#include <conio.h>
#include <direct.h>
#endif

#if defined (TX_COMPILED)
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <mmsystem.h>

//-----------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//! @name    ��������� � ������������ � ����������
//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)
    #pragma warning (pop)                        // MSVC: Restore max level
#endif

#if defined (__STRICT_ANSI__UNDEFINED)
    #define  __STRICT_ANSI__                     // Redefine back
#endif

#if !defined (_TRUNCATE) || defined (__CYGWIN__) || defined (_MEMORY_S_DEFINED)

    #define  strncpy_s( dest, sizeof_dest, src, count )  ( strncpy ((dest), (src), MIN ((count), (sizeof_dest))) )
    #define  wcsncpy_s( dest, sizeof_dest, src, count )  ( wcsncpy ((dest), (src), MIN ((count), (sizeof_dest))) )
    #define  strncat_s( dest, sizeof_dest, src, count )  ( strncat ((dest), (src), MIN ((count), (sizeof_dest))) )
    #define  strerror_s( buf, sizeof_buf, code        )  ( strncpy ((buf), strerror ((int)(code)), (sizeof_buf)-1) )
    #define  strtok_s(   buf, delim, ctx              )  ( (void)(ctx), strtok ((buf), (delim)) )
    #define  fopen_s(    file, name, mode             )  ( *(file) = fopen ((name), (mode)) )
    #define _strlwr_s(   str, sizeof_str              )  ( _strlwr (str) )

    #define  ctime_s( buf, sizeof_buf, time    )         ( strncpy ((buf), ctime (time), (sizeof_buf)-1) )
    #define _controlfp_s( oldCtl, newCtl, mask )         ( assert (oldCtl), *(oldCtl) = _controlfp (newCtl, mask), 0 )

    #define _snprintf_s                                  snprintf
    #define _vsnprintf_s( str, sz, trunc, format, arg )  _vsnprintf (str, sz, format, arg)

#endif

#if !( defined (_MSC_VER) || defined (__STDC_LIB_EXT1__) )

    #define  getenv_s( sz, buf, sizeof_buf, name )       ( (void)(sz), strncpy ((buf), getenv (name), (sizeof_buf)-1) )

#endif

#if defined (__CYGWIN__)

    #undef   __STRICT_ANSI__

    typedef  void                                _exception;

    #define _O_TEXT                              O_TEXT
    #define _fdopen                              fdopen
    #define _flushall()                          fflush (NULL)
    #define _getcwd                              getcwd
    #define _getpid                              getpid
    #define _stricmp                             strcasecmp
    #define _strlwr                              strlwr
    #define _strnicmp                            strncasecmp
    #define _unlink                              unlink
    #define _vsnprintf                           vsnprintf
    #define _access                              access
    #define _strdup                              strdup

    #define getch                                _getch
    #define putch                                _putch
    #define kbhit                                _kbhit

#endif

#if !defined (PRId64) || \
     defined (_GCC_VER) && (_GCC_VER == 492) && !defined (_WIN64) // Dev-CPP 5.11: TDM-GCC 4.9.2 MinGW64 with -m32

    #undef  PRId64
    #undef  PRIi64
    #undef  PRIo64
    #undef  PRIu64
    #undef  PRIx64
    #undef  PRIX64

    #define PRId64                               "I64d"
    #define PRIi64                               "I64i"
    #define PRIo64                               "I64o"
    #define PRIu64                               "I64u"
    #define PRIx64                               "I64x"
    #define PRIX64                               "I64X"

#endif

//}
//-----------------------------------------------------------------------------------------------------------------

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          The namespaces
//-----------------------------------------------------------------------------------------------------------------

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������� ������������ ���� ��� ������ �� ���������� ��� ������ �������������� �������.
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
namespace { namespace TX { }}
#endif

/*! @cond INTERNAL */

//-----------------------------------------------------------------------------------------------------------------

#if defined (TX_COMPILED) && defined (TX_COMPILING)
    #undef   TX_COMPILED
    #endif

#if !defined (TX_COMPILED) && !defined (TX_COMPILING)

    #define _TX_BEGIN_NAMESPACE                      namespace { namespace TX {
    #define _TX_END_NAMESPACE                        } }

#else

    #define _TX_BEGIN_NAMESPACE                                  namespace TX {
    #define _TX_END_NAMESPACE                        }

#endif

//-----------------------------------------------------------------------------------------------------------------

_TX_BEGIN_NAMESPACE

/*! @endcond */

//}
//-----------------------------------------------------------------------------------------------------------------

//=================================================================================================================
//{          TXLIB INTERFACE
//           ��������� ����������
//=================================================================================================================

//=================================================================================================================
//{          Initialization
//! @name    ������������� ����������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���� ���������
//!
//! @param   sizeX       ������ ���� �� ����������� (� ��������).
//! @param   sizeY       ������ ���� �� ���������   (� ��������).
//! @param   centered <i>������������� ���� �� �������. �������������. ���� �� �������, �� ���� ������������.</i>
//!
//! @return  ���������� (��������� �����) ���� TXLib. ���� ���� �� �������, ������������ NULL.
//!
//! @note    ��������������� ��������� ��������� �� ���������, ��. ������� txSetDefaults().
//!
//! @warning ���� ������������ ������������� ������ (� ���������� �����������), �� ����������� ������� TXLib,
//!          ��������� �� ����� �������, ����� �������� ������ � ��� �����, ������� ������� <b>� ���� �� �����</b>
//!          �������. ���� ������ �������, ������, �� ������ @c main.cpp � @c game.cpp, � � ����� @c main.cpp
//!          ��������� ����������� ����, �� ������� �� @c game.cpp �� ������ �������� � ���. (������ @c game.cpp
//!          ������ ������� ���� ����������� ����.) @n
//!          ���� ����� ��������� ����� ���� ����, �� � ������ ������� �������� ����, ������������� �� ���������,
//!          ������, @c graphics.cpp, � �������� ������� ������ ����� ������� ����� �����. ����� ���� (���
//!          ����������) � ������� �������� ����� �������� ����������� �������. @nn
//!          �� �� �������� � ������������� TXLib � @b DLL.
//!
//! @note    ��������������� ���� ����� ����������� �� ������ �� ������ ���� �������������� ������� ��� �����������
//!          DLL. ��� �������� ��������������� ���� ������������ txDestroyWindow(). ��� �������� �������� ����
//!          ����� �� main().
//!
//! @warning ������������� �������� ���������� ���� �� ��������������� (not thread-safe). @nn
//!          ������������ ��������� �� TXLib ��������, �� � ����������� ���� �� ���������� ������� ���������. �����
//!          ���������� �� �����, ������� TXLib � ����������� ������ ������� ����������: <a href=http://qt-project.org>
//!          Qt</a>, <a href=http://wxwidgets.org>wxWidgets</a>, <a href=http://gtk.org>GTK+</a> � �.�., ���
//!          ����������, ���������� ������������� ��� �������� ���: <a href=http://sfml-dev.org>SFML</a> (���
//!          �������), <a href=http://libsdl.org>SDL</a> � ������. �� ������ �������� � ���� ����������� �������
//!          ����������, ���������� �� <a href=http://opengl.org>OpenGL</a> @strike � ��������� SFML ��� SDL:),
//!          @endstrike ��� DirectX. �������, ��� ���� TXLib -- ��������� ������ ����, �� ����� ����� ��������.
//!
//! @see     txOK(), txWindow(), txDC(), txVideoMemory(), _txWindowStyle, _txConsoleMode, _txConsoleFont,
//!          _txCursorBlinkInterval, _txWindowUpdateInterval, _TX_NOINIT, _TX_ALLOW_TRACE, TX_TRACE
//!
//! @usage @code
//!          txCreateWindow ( 800, 600);         // ����  800�600,    ������������
//!          txCreateWindow (1024, 768, false);  // ���� 1024�768, �� ������������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HWND txCreateWindow (double sizeX, double sizeY, bool centered = true);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ����� (���������� ��������� ���������, HDC) ���� ��������� TXLib.
//!
//! @return  ���������� (��������� �����, handler) ��������� ��������� (device context, DC) ������ TXLib (TXLib HDC).
//!
//! @note    ������������ ���������� -- @b �� ������� �������� ��������� ���� TXLib. TXLib ��������� �������
//!          �����������. ��� ������������� �������� ���������� �� ������� HDC, ����������� � ������, � ���
//!          ���������� ������������ ������������� ���������� �� �����. ��� ������ �������� � ��������.
//!          �������������� ����������� ����� ��������� �������� txBegin() � ������� �������� �������� txEnd(),
//!          � ���� ������ ���������� ���� ����� ������������ ��������� txRedrawWindow() ��� txSleep(). @nn
//!          �������������� ���������� �� �������������� ���������� ��. � �������� txBegin(), txEnd(), txUpdateWindow(),
//!          txRedrawWindow() � txSleep().
//!
//! @note    ���� HDC ������������ � ���� ������, ��� ��������� ��������� ���. ����� TXLib ����� ������������ ����������
//!          �� ����� ����������� ��� �� ������ ������. ����� �������� ���� ��������� ������ ���������� ��� ����������
//!          ��� � ������� txDeleteDC(). �� ����� ������� ��������� ������ ���� ������������� � ������� txLock()
//!          � ����� �������������� � ������� txUnlock().
//!
//! @see     txWindow(), txBegin(), txEnd(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          txBitBlt (txDC(),   0,   0, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 100,   0, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 0,   100, 100, 100, txDC(), 0, 0);
//!          txBitBlt (txDC(), 100, 100, 100, 100, txDC(), 0, 0);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline HDC& txDC() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ����� ������, ��������� � ������� (HDC) TXLib.
//!
//! @return  ��������� �� ������ �������� RGBQUAD, -- ������ ������, ���������� � HDC ������ TXLib.
//!
//!          ������ ������ � ������ ������ HDC ��������� �������� � ��� � ����� ������� ���������. ������, ��������
//!          ����� ������ ��������� �������. ��� �������, � ��������, ���� �� ������ ����������� ����������� ������
//!          <i>(��� �������� �� ���!).</i>
//!
//!          ����� ������ HDC -- ��������� ������, ������� �������� ������������� ������ � ������ ������ (HDC). �� ��
//!          ������������ ��� ��������� �� ���������� ������, ������� ��������� ��������� � ���� ���� ����� �������.
//!          ����� ����, "Y-���" ����� ������� ���������� @b �����, � �� ����, ��� � ���� TXLib. ������� ��� �������
//!          ������� ��� �������� �� ������ ������� ����� ������������ � ������� ������� <tt>x + (-y + sizeY) * sizeX</tt>.
//!
//! @warning ������ ���������, �� �������� �� ������� �������, ����������� ����� ����������������.
//!
//! @note    �� ����� ������ � ������� �������������� ���������� ���� TXLib ������ ���� ������������� � ������� txLock()
//!          � ����� �������������� � ������� txUnlock(). @nn
//!
//! @note    HDC TXLib -- @b �� ������� �������� ��������� ���� TXLib. TXLib ��������� ������� �����������. ���
//!          ������������� �������� ���������� �� ������� HDC, ����������� � ������ (��� ���������� txGetDC()),
//!          � ��� ���������� ������������ ������������� ���������� �� �����. ��� ������ �������� � ��������.
//!          �������������� ����������� ����� ��������� �������� txBegin() � ������� �������� �������� txEnd(),
//!          � ���� ������ ���������� ���� ����� ������������ ��������� txRedrawWindow() ��� txSleep(). @nn
//!          �������������� ���������� �� �������������� ���������� ��. � �������� txBegin(), txEnd(), txUpdateWindow(),
//!          txRedrawWindow() � txSleep().
//!
//! @see     txCreateDIBSection(), txDC(), txWindow(), txBegin(), txEnd(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          ������ ��. � ����� PhongDemo.cpp �� ����� TX\Examples\Demo.
//!          ����� ��. ������ � ������ �� ������� txCreateDIBSection().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline RGBQUAD* txVideoMemory() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ���������� ��������� �� ���������.
//!
//! @param   dc <i>���������� ��������� ��������� (������) ��� ��������� ����������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @par     ��������� �� ���������:
//!        - �����   -- ���� ����� (TX_WHITE), ������� 1
//!        - ������� -- ���� ����� (TX_WHITE)
//!        - �����   -- ���������, ���� ����� (TX_WHITE)
//!        - ��������� �������� -- ����������� ����� (R2_COPYPEN)
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txSelectFont()
//!
//! @usage @code
//!          txSetDefaults();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txSetDefaults (HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������������ ������ ����������
//!
//! @return  ��������� ����������: true -- ���������� � �������, false -- �� � �������.
//!
//!          "���������� �� � �������" ��������, ��� �� ���������� ������ �������. ����� ������� ������� -
//!          �� ������� ����, ������ ����� ���� � ������ ��������.
//!
//! @see     txCreateWindow()
//!
//! @usage @code
//!          txCreateWindow (800, 600);
//!          if (!txOK())
//!              {
//!              txMessageBox ("�� ������ ������� ����", "��������", MB_ICONSTOP);
//!              return;
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline bool txOK() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ����, �������� ��� ������ � ���� ��������� POINT.
//!
//! @param   dc <i>���������� ��������� ��������� (������) � ����������� ��� ��������� ���������, ������� ��������
//!                ����� ����������. ������������. ���� �� ������ ��� ����� txDC(), ������������ ������� ���� TXLib.</i>
//!
//! @return  ������ ����, �������� ��� ������ � ���� ��������� POINT, ���������� ���������� @c x � @c y.
//!
//! @note    ���� ���� �� �������, ������������ ������ ������.
//!
//! @see     txGetExtentX(), txGetExtentY()
//!
//! @usage @code
//!          txCreateWindow (800, 600);
//!
//!          HDC image = txLoadImage ("TX/Wizard/TX Application/VS/HTML/1033/TX Application_resize.bmp");
//!
//!          POINT center = { txGetExtentX() / 2, txGetExtentY() / 2 };
//!          POINT size   = txGetExtent (image);
//!
//!          txBitBlt (center.x,            center.y,            image);  // This is krivo
//!
//!          txBitBlt (center.x - size.x/2, center.y - size.y/2, image);  // This is centered
//!
//!          txSetColor (TX_WHITE, 3);
//!          txSetFillColor (TX_TRANSPARENT);
//!          txCircle (center.x, center.y, hypot (size.x, size.y) / 2);
//!          txCircle (center.x, center.y, 10);
//!
//!          txDeleteDC (image);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txGetExtent (HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ��� ������.
//!
//! @param   dc <i>���������� ��������� ��������� (������), ������ �������� ������������. ������������. ���� �� ������
//!                ��� ����� txDC(), ������������ ������ ���� TXLib.</i>
//!
//! @return  ������ ���� ���������.
//!
//! @note    ���� ���� �� �������, ������������ ������ ������.
//!
//! @see     txGetExtent(), txGetExtentY()
//!
//! @usage @code
//!          txSetTextAlign (TA_CENTER);
//!          txTextOut (txGetExtentX() / 2, 100, "Oh, oh, you're in the [army]middle now");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txGetExtentX (HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ ���� ��� ������.
//!
//! @param   dc <i>���������� ��������� ��������� (������), ������ �������� ������������. ������������. ���� �� ������
//!                ��� ����� txDC(), ������������ ������ ���� TXLib.</i>
//!
//! @return  ������ ���� ���������.
//!
//! @note    ���� ���� �� �������, ������������ ������ ������.
//!
//! @see     txGetExtent(), txGetExtentX()
//!
//! @usage @code
//!          void DrawHouse (int height);
//!          ...
//!          DrawHouse (txGetExtentY() / 2);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txGetExtentY (HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ���������� ���� ���������
//!
//! @return  ���������� (��������� �����, handler) ���� ������.
//!
//! @see     txDC(), txVideoMemory(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          SetWindowText (txWindow(), "����� ��������� -- ������ � � ����� �����!");
//!          txMessageBox ("�����������", "��������", MB_ICONINFORMATION);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline HWND txWindow() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ������ � ����������� � ������� ������ ����������.
//!
//! @return  ������ � ����������� � ������� ������ ����������.
//!
//! @usage @code
//!          printf ("I personally love %s\n", txVersion());
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline const char* txVersion() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ����� ������ ����������.
//!
//! @return  ����� ������ ����������.
//!
//! @usage @code
//!          printf ("My magic number is %x\n", txVersionNumber());
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline unsigned txVersionNumber() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ��� ������������ ����� ��� ����������� ��������� ���� TXLib.
//!
//! @param   fileNameOnly <i>���������� ������ ������ ��� ������������ �����, ����������� ����� Win32 �������
//!                          GetFileModuleName (NULL, ...). �������������. ���� �� �������, �� ������������ ������
//!                          ��� ������������ �����.</i>
//!
//! @return  fileNameOnly = true:  ��� ������������ �����. @n
//!          fileNameOnly = false: ����������� ��������� ���� TXLib.
//!
//! @note    ������������ @b ����������� ������.
//!
//! @see     txWindow(), txVersion(), txVersionNumber()
//!
//! @usage @code
//!          printf ("�������� �� ��������� ����!");
//!
//!          for (int done = 0; done <= 100; done++)
//!              {
//!              char title [1024] = "";
//!              sprintf (title, "%s - [%-10.*s] %d%%", txGetModuleFileName (false), done/10, "||||||||||", done);
//!
//!              SetWindowText (txWindow(), title);
//!              SetWindowText (Win32::GetConsoleWindow(), title);
//!              txSleep (50);
//!              }
//!
//!          txMessageBox ("��� ����� ��� progress bar", "TXLib forever)");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

const char* txGetModuleFileName (bool fileNameOnly = true) tx_nodiscard;

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Setting the parameters
//! @name    ��������� ������ � ������� ���������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ���������������� ������.
//!
//!          ��. TX_BLACK, TX_BLUE � ������ ����� � ������ ����.
//!
//!          ���� ����-�� ��� ����� �� �������� (��� �������������), ������ ����� ������� ���� � ������� RGB().
//!          ��. ������ ����.
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
//!          txSetColor     (TX_YELLOW);              // ������������� ������ ���� �����
//!          txSetFillColor (TX_NULL);                // ������� ����� ����� ����������
//!
//!          txSetFillColor (MY_DEEP_ROMANTIC_BLUE);  // �.�. �������, "������ ���� �� ������"
//!          txSetColor     (MY_SHINING_MOONLIGHT);   // http://tanais.info/art/pic/kuindzhi1.html
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

const COLORREF
#ifdef FOR_DOXYGEN_ONLY
    enum txColors {
#endif

    TX_BLACK         = RGB (  0,   0,   0),   //!< ������ ����.
    TX_BLUE          = RGB (  0,   0, 128),   //!< �����-����� ����. <i>����� �����.</i>
    TX_GREEN         = RGB (  0, 128,   0),   //!< ������� ����.
    TX_CYAN          = RGB (  0, 128, 128),   //!< ��������� ����.
    TX_RED           = RGB (128,   0,   0),   //!< �����-������� ����. <i>������� ������.</i>
    TX_MAGENTA       = RGB (128,   0, 128),   //!< �����-��������� ����.
    TX_BROWN         = RGB (128, 128,   0),   //!< ���������� ����. <i>����������. Do it yourself with RGB().</i>
    TX_ORANGE        = RGB (255, 128,   0),   //!< ��������� ����.
    TX_GRAY          = RGB (160, 160, 160),   //!< ����� ����.
    TX_DARKGRAY      = RGB (128, 128, 128),   //!< �����-����� ����.
    TX_LIGHTGRAY     = RGB (192, 192, 192),   //!< ������-����� ����.
    TX_LIGHTBLUE     = RGB (  0,   0, 255),   //!< ������-����� ����.
    TX_LIGHTGREEN    = RGB (  0, 255, 128),   //!< ������-������� ����.
    TX_LIGHTCYAN     = RGB (  0, 255, 255),   //!< ������-��������� ����.
    TX_LIGHTRED      = RGB (255,   0, 128),   //!< ������-������� ����.   <i>�� ������ ������� �������.</i>
    TX_LIGHTMAGENTA  = RGB (255,   0, 255),   //!< ������-��������� ����. <i>��� ����� ������� �������.</i>
    TX_PINK          = RGB (255, 128, 255),   //!< ������� ��������� :)
    TX_YELLOW        = RGB (255, 255, 128),   //!< ������ ����.
    TX_WHITE         = RGB (255, 255, 255),   //!< ����� ����.
    TX_TRANSPARENT   = 0xFFFFFFFF,            //!< ���������� ����. <i>��������� ���������.</i>
    TX_NULL          = TX_TRANSPARENT,        //!< ���������� ����. <i>��������� ���������.</i>

//  �������� ������ (����������) -- ��. txExtractColor(), txRGB2HSL(), txHSL2RGB()

    TX_HUE          = 0x04000000,             //!< �������� ��� ����� � ������ HSL
    TX_SATURATION   = 0x05000000,             //!< ������������ ����� � ������ HSL
    TX_LIGHTNESS    = 0x06000000;             //!< �������� ����� � ������ HSL

#ifdef FOR_DOXYGEN_ONLY
    };
#endif

//! @cond INTERNAL
#define TX_GREY       TX_GRAY
#define TX_DARKGREY   TX_DARKGRAY
#define TX_LIGHTGREY  TX_LIGHTGRAY
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� (���������) ���� �� ���� ������� ������ (���������).
//!
//! @param   red    ���������� �������� ����� � ��������� [0; 255].
//! @param   green  ���������� �������� ����� � ��������� [0; 255].
//! @param   blue   ���������� ������   ����� � ��������� [0; 255].
//!
//! @return  ��������� ���� � ������� COLORREF.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txExtractColor(),
//!          txRGB2HSL(), txHSL2RGB()
//!
//! @usage @code
//!          txSetColor (RGB (255, 128, 0));                // ������� + �������� �������� = ���������
//!
//!          int red = 20, green = 200, blue = 20;
//!          COLORREF color = RGB (red, green, blue);
//!          txSetFillColor (color);
//!
//!          const COLORREF SKY_COLOR = RGB (0, 128, 255);  // ������� ��������� ��� ������ �����
//!
//!          ...
//!          txSetFillColor (SKY_COLOR);                    // ���������� ��
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
COLORREF RGB (int red, int green, int blue);
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� � ������� �����, ���� ������.
//!
//! @param   color        ���� ����� � ������, ��. txColors, RGB().
//! @param   thickness <i>������� �����. �������������. ���� �� �������, �� 1 �������.</i>
//! @param   dc        <i>���������� ��������� ��������� (������) ��� ��������� �����. ������������.</i>
//!
//! @return  ����, ��������� ��� ��������� �����. ��� ������ ������������ NULL.
//!
//! @see     txSetFillColor(), txGetColor(), txGetFillColor(), txColors, RGB()
//!
//! @usage @code
//!          txSetColor (TX_YELLOW);             // ���� ����� ����� ������
//!          txSetColor (RGB (255, 128, 0), 5);  // ��������� ����� �������� 5 ��������
//!
//!          txSetColor (RGB (255, 255, 0));     // ������ = ������� + ������� (������ ������ �������� �����)
//!          txSetColor (RGB (255, 128, 64));    // ����� ���������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HPEN txSetColor (COLORREF color, double thickness = 1, HDC dc = txDC());

//! @cond INTERNAL
#define txSetColour txSetColor
//! @endcond

//! @cond INTERNAL

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ����� � ������.
//!
//! @param   red    ���������� �������� ����� � ��������� [0; 1].
//! @param   green  ���������� �������� ����� � ��������� [0; 1].
//! @param   blue   ���������� ������   ����� � ��������� [0; 1].
//!
//! @return  ���� RGB, ��������������� ��������� ���������� �������� ������. ��� ������ ������������ CLR_INVALID.
//!
//! @see     txSetColor(), txSetFillColor(), txGetColor(), txGetFillColor()
//}----------------------------------------------------------------------------------------------------------------

COLORREF txColor (double red, double green, double blue);

//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� � ������.
//!
//! @param   dc <i>���������� ��������� ��������� (������) ��� �������� �����. ������������.</i>
//!
//! @return  ������� ���� ����� � ������, ��. txColors, RGB().
//!
//! @see     txSetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB()
//!
//! @usage @code
//!          COLORREF color = txGetColor();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txGetColor (HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ���������� �����.
//!
//! @param   color  ���� ����������, ��. txColors, RGB().
//! @param   dc  <i>���������� ��������� ��������� (������) ��� ��������� �����. ������������.</i>
//!
//! @return  �����, ��������� ��� ��������� �����. ��� ������ ������������ NULL.
//!
//! @see     txSetColor(), txGetFillColor(), txGetColor(), txColors, RGB()
//!
//! @usage @code
//!          txSetFillColor (TX_LIGHTGREEN);
//!          txSetFillColor (RGB (255, 128, 0));
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HBRUSH txSetFillColor (COLORREF color, HDC dc = txDC());

//! @cond INTERNAL
#define txSetFillColour txSetFillColor
//! @endcond

//! @cond INTERNAL

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ���� ���������� �����.
//!
//! @param   red    ���������� �������� ����� � ��������� [0; 1].
//! @param   green  ���������� �������� ����� � ��������� [0; 1].
//! @param   blue   ���������� ������   ����� � ��������� [0; 1].
//!
//! @return  ���� RGB, ��������������� ��������� ���������� �������� ������. ��� ������ ������������ CLR_INVALID.
//!
//! @see     txSetFillColor(), txSetColor(), txGetFillColor(), txGetColor()
//}----------------------------------------------------------------------------------------------------------------

COLORREF txFillColor (double red, double green, double blue);

//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ���������� �����.
//!
//! @param   dc <i>���������� ��������� ��������� (������) ��� �������� �����. ������������.</i>
//!
//! @return  ������� ���� ���������� �����, ��. txColors, RGB().
//!
//! @see     txSetFillColor(), txSetColor(), txGetColor(), txColors, RGB()
//!
//! @usage @code
//!          COLORREF color = txGetFillColor();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txGetFillColor (HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �������� ���������� (�������� �����) �� ���������� �����.
//!
//! @param   color      ��������� ����.
//! @param   component  ����������� ����������, ��. txColors.
//!
//! @return  �������� ����������, ��. txColors.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txExtractColor(),
//!          txRGB2HSL(), txHSL2RGB()
//!
//! @usage @code
//!          int red       = txExtractColor (color, TX_RED);
//!          int lightness = txExtractColor (TX_BLUE, TX_LIGHTNESS);
//!
//!          ������ ������� ��. � �������� AppearText(), AppearEarth() ������� 5 ("�����").
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned txExtractColor (COLORREF color, COLORREF component) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� RGB � ������ HSL.
//!
//! @param   rgbColor  ������������� ���� � ������� @strike ��� @endstrike RGB.
//!
//! @return  ��������� ���� � ���� COLORREF.
//!
//!          ������ @b RGB ������������ ���
//!
//!          - ������� ���������� ����� (Red),   �� 0 �� 255.
//!          - ������� ���������� ����� (Green), �� 0 �� 255.
//!          - �����   ���������� ����� (Blue),  �� 0 �� 255.
//!
//!          ������ @b HSL ������������ ���
//!
//!          - �������� ��� (Hue),        �� 0 �� 255 <b>(�� �� 360).</b>
//!          - ������������ (Saturation), �� 0 �� 255.
//!          - ��������     (Lightness),  �� 0 �� 255.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txExtractColor(),
//!          txRGB2HSL(), txHSL2RGB()
//!
//! @usage @code
//!          COLORREF hslColor = txRGB2HSL (TX_RED);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

COLORREF txRGB2HSL (COLORREF rgbColor) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ����������� ���� �� ������� HSL � ������ RGB.
//!
//! @param   hslColor  ������������� ���� � ������� HSL.
//!
//! @return  ��������� ���� � ���� COLORREF.
//!
//!          ������ @b RGB ������������ ���
//!
//!          - ������� ���������� ����� (Red),   �� 0 �� 255.
//!          - ������� ���������� ����� (Green), �� 0 �� 255.
//!          - �����   ���������� ����� (Blue),  �� 0 �� 255.
//!
//!          ������ @b HSL ������������ ���
//!
//!          - �������� ��� (Hue),        �� 0 �� 255 <b>(�� �� 360).</b>
//!          - ������������ (Saturation), �� 0 �� 255.
//!          - ��������     (Lightness),  �� 0 �� 255.
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

COLORREF txHSL2RGB (COLORREF hslColor) tx_nodiscard;

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Drawing
//! @name    ��������� �����
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� ����� ������� ������ ����������.
//!
//! @param   dc <i>���������� ��������� ��������� (������) ��� ��������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @see     txSetFillColor(), txGetFillColor(), txColors, RGB()
//!
//! @usage @code
//!          txSetFillColor (TX_BLUE);  // ���-�� ����� ����� ���?
//!          txClear();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txClear (HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� (����� �� ������).
//!
//! @param   x      X-���������� �����.
//! @param   y      Y-���������� �����.
//! @param   color  ���� �����, ��. txColors, RGB().
//! @param   dc  <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @see     txGetPixel(), txColors, RGB(), txVideoMemory()
//!
//! @usage @code
//!          txSetPixel (100, 100, TX_LIGHTRED);  // ������� �����! http://www.google.ru/search?q=����+�+�������+�����
//!
//!          txSetPixel (100, 100, RGB (255, 128, 0));
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline bool txSetPixel (double x, double y, COLORREF color, HDC dc = txDC());

//! @cond INTERNAL

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� (����� �� ������).
//!
//! @param   x      X-���������� �����.
//! @param   y      Y-���������� �����.
//! @param   red    ���������� �������� ����� � ��������� [0; 1].
//! @param   green  ���������� �������� ����� � ��������� [0; 1].
//! @param   blue   ���������� ������   ����� � ��������� [0; 1].
//! @param   dc  <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @see     txSetPixel(), txGetPixel(), txVideoMemory()
//!
//! @usage @code
//!          txSetPixel (100, 100, 1.0, 0.5, 0.25);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline bool txPixel (double x, double y, double red, double green, double blue, HDC dc = txDC());

//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ���� ����� (�������) �� ������.
//!
//! @param   x     X-���������� �����.
//! @param   y     Y-���������� �����.
//! @param   dc <i>���������� ��������� ��������� (������) ��� �������� �����. ������������.</i>
//!
//! @return  ������� ���� �������, ��. txColors, RGB().
//!
//! @see     txSetPixel(), txColors, RGB(), txVideoMemory()
//!
//! @usage @code
//!          COLORREF color = txGetPixel (100, 200);
//!
//!          if (txGetPixel (x, y) == TX_RED)
//!              CarCrash (x, y);     // Mess with the red -- die like the rest
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline COLORREF txGetPixel (double x, double y, HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!
//! @param   x0    X-���������� ��������� �����.
//! @param   y0    Y-���������� ��������� �����.
//! @param   x1    X-���������� ��������  �����.
//! @param   y1    Y-���������� ��������  �����.
//! @param   dc <i>���������� ��������� ��������� (������) ��� ��������� �����. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txLine (10, 50, 100, 500);  // ������ ������ ���������, ��?
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txLine (double x0, double y0, double x1, double y1, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �������������.
//!
//! @param   x0    X-���������� �������� ������  ����.
//! @param   y0    Y-���������� �������� ������  ����.
//! @param   x1    X-���������� �������  ������� ����.
//! @param   y1    Y-���������� �������  ������� ����.
//! @param   dc <i>���������� ��������� ��������� (������) ��� ��������� ��������������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� -- txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txRectangle (100, 200, 400, 500);
//!
//!          Win32::RoundRect (txDC(), 100, 200, 400, 500, 30, 30);  // � ����� ����. ��������� "RoundRect function".
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txRectangle (double x0, double y0, double x1, double y1, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������� ����� ��� �������������.
//!
//! @param   points     ������ �������� POINT � ������������ �����.
//! @param   numPoints  ���������� ����� � �������.
//! @param   dc      <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� -- txSetFillColor().
//!          ���� ����� ���������� ������� �����, � �� �������������, ����������� ���������� ���� ���������� (TX_TRANSPARENT).
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          POINT star[5] = {{150, 300}, {200, 100}, {250, 300}, {100, 200}, {300, 200}};
//!          txPolygon (star, 5);  // � ������ ���������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������.
//!
//! @param   x0    X-���������� �������� ������ ���� ��������������, ���������� ������ �������.
//! @param   y0    Y-���������� �������� ������ ���� ���������� ��������������.
//! @param   x1    X-���������� ������� ������� ���� ���������� ��������������.
//! @param   y1    Y-���������� ������� ������� ���� ���������� ��������������.
//! @param   dc <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� -- txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txEllipse (100, 100, 300, 200);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txEllipse (double x0, double y0, double x1, double y1, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���������� ��� ����.
//!
//! @param   x  X-���������� ������.
//! @param   y  Y-���������� ������.
//! @param   r  ������.
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� -- txSetFillColor().
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
//! @brief   ������ ���� �������.
//!
//! @param   x0          X-���������� �������� ������ ���� ��������������, ���������� ������ �������, �����������
//!                      ���� (��. txEllipse).
//! @param   y0          Y-���������� �������� ������ ���� ��������������.
//! @param   x1          X-���������� ������� ������� ���� ��������������.
//! @param   y1          Y-���������� ������� ������� ���� ��������������.
//! @param   startAngle  ���� ����� ������������ ��� OX � ������� ���� (� ��������).
//! @param   totalAngle  �������� ���� (� ��������).
//! @param   dc       <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� -- txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txArc (100, 100, 300, 200, 45, 270);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ������ �������.
//!
//! @param   x0          X-���������� �������� ������ ���� ��������������, ���������� ������ �������, �����������
//!                      ���� (��. txEllipse).
//! @param   y0          Y-���������� �������� ������ ���� ��������������.
//! @param   x1          X-���������� ������� ������� ���� ��������������.
//! @param   y1          Y-���������� ������� ������� ���� ��������������.
//! @param   startAngle  ���� ����� ������������ ��� OX � ������� ������� (� ��������).
//! @param   totalAngle  �������� ������� (� ��������).
//! @param   dc       <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� -- txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txPie (100, 100, 300, 200, 0, 180);  // Enter Pacman
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ����� �������.
//!
//! @param   x0          X-���������� �������� ������ ���� ��������������, ���������� ������ �������, �����������
//!                      ���� (��. txEllipse).
//! @param   y0          Y-���������� �������� ������ ���� ��������������.
//! @param   x1          X-���������� ������� ������� ���� ��������������.
//! @param   y1          Y-���������� ������� ������� ���� ��������������.
//! @param   startAngle  ���� ����� ������������ ��� OX � ������� ����� (� ��������).
//! @param   totalAngle  �������� ����� (� ��������).
//! @param   dc       <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� � ������� ����� �������� �������� txSetColor(), ���� ���������� -- txSetFillColor().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @usage @code
//!          txChord (100, 100, 300, 200, 45, 270);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������������ ������ ������� ������ ����������.
//!
//! @param   x        X-���������� ����� ������ �������.
//! @param   y        Y-���������� ����� ������ �������.
//! @param   color <i>���� ���������� �������. ������������. ���� �� ������, �� ������������ TX_TRANSPARENT --
//!                   ��������������� �����.</i>
//! @param   mode  <i>����� �������. ������������. ���� �� ������, �� ������������ FLOODFILLSURFACE -- �������
//!                   ����������� ����.</i>
//! @param   dc    <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� ���������� �������� �������� txSetFillColor(). �� ������������� ��� ����������, ��� ��� ��������
//!          �������� ��������. ����� ����������� txPolygon().
//!
//! @title   ������ �������: @table
//!          @tr FLOODFILLSURFACE @td -- �������� �������,    ��������� ������ color.
//!          @tr FLOODFILLBORDER  @td -- �������� �� �������, ��������� ������ color.
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

bool txFloodFill (double x, double y, COLORREF color = TX_TRANSPARENT, DWORD mode = FLOODFILLSURFACE, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������, ������� <i>������ ��</i> �������� �����������.
//!
//! @param   x1  X-���������� 1-� �����.
//! @param   y1  Y-���������� 1-� �����.
//! @param   x2  X-���������� 2-� �����.
//! @param   y2  Y-���������� 2-� �����.
//! @param   x3  X-���������� 3-� �����.
//! @param   y3  Y-���������� 3-� �����.
//!
//! @return  ���� �������� ���� �� ������� -- true, ����� -- false.
//!
//! @see     txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txLine(), txRectangle(), txPolygon(), txEllipse(), txCircle(), txArc(), txPie(), txChord()
//!
//! @par ��. �����:
//!          @ref Tutor_Params "������ � ��������� � �����������"
//}----------------------------------------------------------------------------------------------------------------

inline bool txTriangle (double x1, double y1, double x2, double y2, double x3, double y3)
    {
    (void)x1; (void)y1; (void)x2; (void)y2; (void)x3; (void)y3;

    MessageBox (txWindow(),
               "txTriangle (double x1, double y1, double x2, double y2, double x3, double y3)\n\n"
               "��� ������� �� ����������� � ����������, ������ ��� �� ����� ������ ����������� �� ���� "
               "��� ������� � �����������, ��������� txPolygon(). ��. \"������ � ��������� � �����������\". "
               "�� ��� ���������� ����� �������. :)",
               "TXLib ��������", MB_ICONINFORMATION);

    return false;
    }

//{----------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

bool txNotifyIcon (unsigned flags, const char title[], const char format[], ...) tx_printfy (3);

#define txRectandle  Sleep (1000), txRectangle  // Copy-protection for the function below
#define txLine(...)  txLine (__VA_ARGS__); {    //
#define txNotifyIcon }}}}}}}}}} txNotifyIcon    // �� �����������, �����. ��� ����.
#define txCircle     ;txCircle                  //
#define txSetColor   ;txSetColor                //
#define C0L0RREF     COLORREF                   //
#define OxFFFFFF     0xFFFFFF                   //
#define lO           10                         //
#define lOOO         1000                       //
#define O                                       //

//! @endcond
//}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���������.
//!
//! ��� ������ �������, ������� �� ����� �� �������� � ����.
//!
//! @param   x      X-���������� ���������.
//! @param   y      Y-���������� ���������.
//! @param   sizeX  ������ ���������.
//! @param   sizeY  ������ ��������� (����� ���������� ������ ������).
//! @param   color  ���� ���������.
//! @param   handL  ������ ������� �����  ���� (������������ ������  ���������).
//! @param   handR  ������ ������� ������ ���� (������������ ������  ���������).
//! @param   twist  �������� @a �����          (������������ ������  ���������).
//! @param   head   ������ @a ������� ������   (������������ ������  ���������).
//! @param   eyes   �������� ����              (������������ ������� ������).
//! @param   wink   �������� ����              (0 -- ��� �������, -1 -- ������ �����, +1 -- ������ ������).
//! @param   crazy  �������� ���� �� ��������� (������������ ������� ������).
//! @param   smile  ������                     (������������ ������� ������).
//! @param   hair   ����� �����                (������������ ������� ������).
//! @param   wind   �����, ����������� ������  (������������ ������� ������).
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
//}----------------------------------------------------------------------------------------------------------------//////
                                                                                                                       //
inline void txDrawMan (int x, int y, int sizeX, int sizeY, COLORREF color, double handL, double handR, double twist,   //
                       double head, double eyes, double wink, double crazy, double smile, double hair, double wind)    //
    {                                                                                                                  //
    const char msg[] = "\0/� � - ��������� �� ����������!\0/���� ��������� �� �����!\0/������ ���� ���!\0/";           //
    //                   |                                |                          |                  |              //
    // �� �����������! _/ \_ ��� ����� �� ���������! :) _/ \_  ��������� ��������  _/ \_ ���� ���! :) _/ \_  ��������! //
    //                                                                                                                 //
    static int count = GetTickCount(), L = 0;  //////////////////////////////////////////////////////////////////////////

    C0L0RREF lineColor = txGetColor();
    C0L0RREF fillColor = txGetFillColor();

    txSetColor     (color, 3);
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

    txLine (x, y - (O.8 + head - O.05 * smile/2) * sizeY, x - O.05 * sizeY, y - (O.8 + head + O.05 * smile/2) * sizeY);
    txLine (x, y - (O.8 + head - O.05 * smile/2) * sizeY, x + O.05 * sizeY, y - (O.8 + head + O.05 * smile/2) * sizeY);

    txNotifyIcon (4, (const char*)!! (L+'L')[msg], "\n%s\n", msg + ((unsigned) (((count -=- 1) ^=! 1) ^=~ ((0)^(0)) +1) % 3)["\"<"]);

    // See above: Mouth operator -=-, Cat operator ^=!, Mouse operator ^=~ and Owl constant ((0)^(0)). Use it freely, meow

    txCircle (x - O.05 * sizeY, y - (O.9 + head - O.02 * crazy) * sizeY, eyes * (1 + O.5*wink) * O.02 * sizeY);
    txCircle (x + O.05 * sizeY, y - (O.9 + head + O.02 * crazy) * sizeY, eyes * (1 - O.5*wink) * O.02 * sizeY);
    Sleep (lOOO + count%2);

    txSetColor     ((color == 0xDEADFACE)? TX_DARKGRAY : TX_TRANSPARENT);
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
//! @name    ������ � �������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ �����.
//!
//! @param   x     X-���������� ��������� ����� ������.
//! @param   y     Y-���������� ��������� ����� ������.
//! @param   text  ��������� ������.
//! @param   dc <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� ������ �������� �������� txSetColor(), ������������ (�����/������/�� ������) -- txSetTextAlign().
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(),
//!          txSelectFont(), txSetTextAlign(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txTextOut (100, 100, "����� ����� �� ���� ���� �������.");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txTextOut (double x, double y, const char text[], HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#undef txRectandle
#undef txLine
#undef txNotifyIcon
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
//! @brief   ������ �����, ����������� � ������������� �������.
//!
//! @param   x0        X-���������� �������� ������  ���� �������.
//! @param   y0        Y-���������� �������� ������  ���� �������.
//! @param   x1        X-���������� �������  ������� ���� �������.
//! @param   y1        Y-���������� �������  ������� ���� �������.
//! @param   text      ��������� ������.
//! @param   format <i>����� �������������� ������. �������������. ���� �� �������, �� ������������: �������������,
//!                    ������� �� ������ � ���������� ����������, ���� ������� �� ��������� � �������.</i>
//! @param   dc     <i>���������� ��������� ��������� (������) ��� ���������. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ���� ������ �������� �������� txSetColor(), ������������ (�����/������/�� ������) -- txSetTextAlign().
//!
//! @note    �� ������� ������, ���� ���������� ���� � �������� ������� (���� x0 \> x1 ��� y0 \> y1).
//!
//!          ����� �������������� ������ ��. � MSDN (http://msdn.com), ������ "DrawText Function (Windows)":
//!          http://msdn.microsoft.com/en-us/library/dd162498%28VS.85%29.aspx.
//!
//!          <b>�������������� �������</b> ������ �� ��������� ����� ����������, ���� ����� ������� �� ����������
//!          ����� (���� ���� �� ���� ������ ����� ������ @b @c \\n).
//!
//!          ���� ���� ��������������� ����� �� �� ������, � �� ������ ��� ������� ����, �� �� �������� �������
//!          ��������� ����� ��������������, ���� ��� �����: @c DT_VCENTER (������������ �������������) @c |
//!          @c DT_WORDBREAK (������� �� ������) @c | @c DT_WORD_ELLIPSIS (������� ���������� � �����, ���� �����
//!          �� ���������). ��. �������� ������ �� ���������.
//!
//! @note    ������������ ������������� �������� ������ ��� ��������, � ������� ��� ������� ����� ������ @c \\n.
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
                 unsigned format = DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_WORD_ELLIPSIS, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ������� �����, ��� ������ � ������ ��������.
//!
//! @param   name         �������� ������.
//! @param   sizeY        ������ ���� (������ �� @c Y).
//! @param   sizeX     <i>������ ����. �������������. ���� �� �������, �� ������� 1/3 �� ������.</i>
//! @param   bold      <i>�������� ������ (�� 0 �� 1000). �������������. ���� �� �������, �� ������� ������� �����.</i>
//! @param   italic    <i>������. ������������.</i>
//! @param   underline <i>�������������. �������������.</i>
//! @param   strikeout <i>��������������. �������������.</i>
//! @param   angle     <i>���� �������� ������ (� ��������). ������������.</i>
//! @param   dc        <i>���������� ��������� ��������� (������) ��� ������ ������. ������������.</i>
//!
//! @return  ��������� �����. ���� �� �� ��� ������, �� ��������������� ��������� ����� Windows
//!          @c (SYSTEM_FIXED_FONT, ��. MSDN). ������������� ������ ����� ��������� �������� txFontExist().
//!
//! @see     txTextOut(), txDrawText(), txFontExist()
//!
//! @usage @code
//!          txSelectFont ("Comic Sans MS", 40);
//!          txTextOut (100, 100, "� ����� ����� �� ���� ���� �������.");
//!          txSelectFont ("Comic Sans MS", 40, 10, false, true, false, true, 15);
//!          txTextOut (100, 200, "�� �� ������-�� ���.");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HFONT txSelectFont (const char name[], double sizeY, double sizeX = -1,
                    int bold = FW_DONTCARE, bool italic = false, bool underline = false,
                    bool strikeout = false, double angle = 0,
                    HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������� ��������� �������.
//!
//! @param   text  ��������� ������.
//! @param   dc <i>���������� ��������� ��������� (������), ��� ����������� ���������� �������. ������������.</i>
//!
//! @return  ������� ������� � ��������� SIZE.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          SIZE size = txGetTextExtent (text);
//!          txTextOut (100 + size.cx / 2, 200 + size.cy / 2, text);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[], HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������ ��������� �������.
//!
//! @param   text  ��������� ������.
//! @param   dc <i>���������� ��������� ��������� (������), ��� ����������� ���������� �������. ������������.</i>
//!
//! @return  ������ �������.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[], HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ������ ��������� �������.
//!
//! @param   text  ��������� ������.
//! @param   dc <i>���������� ��������� ��������� (������), ��� ����������� ���������� �������. ������������.</i>
//!
//! @return  ������ �������.
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txTextOut (100 + txGetTextExtentX (text) / 2, 200 + txGetTextExtentY (text) / 2, text);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[], HDC dc = txDC()) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ������������ ������ (�����/������/�� ������).
//!
//! @param   align <i>����� ������������. �������������. ���� �� �������, �� ������������ ������������� �� �����������.</i>
//! @param   dc    <i>���������� ��������� ��������� (������), ��� ����������� ���������� �������. ������������.</i>
//!
//! @return  ���������� ��������� ������������ ������.
//!
//! @title   ����� ������������: @table
//!          @tr TA_LEFT     @td ����� ������������� �����.  ����� @c (X,Y) ���������� �����  ������� ������.
//!          @tr TA_RIGHT    @td ����� ������������� ������. ����� @c (X,Y) ���������� ������ ������� ������.
//!          @tr TA_CENTER   @td ����� ������������ �� ����������� ������������ ����� @ (X,Y).
//!          @tbr
//!          @tr TA_BASELINE @td ����� @c (X,Y) ���������� ������� �����   ������.
//!          @tr TA_BOTTOM   @td ����� @c (X,Y) ���������� ������  ������� ������.
//!          @tr TA_TOP      @td ����� @c (X,Y) ���������� ������� ������� ������.
//!          @endtable
//!
//! @see     txTextOut(), txSelectFont(), txGetTextExtent(), txGetTextExtentX(), txGetTextExtentY()
//!
//! @usage @code
//!          txSetTextAlign (TA_RIGHT);
//!          txTextOut (700, 100, "����� ������ ��� ����� � �����,");
//!          txTextOut (700, 150, "���������� ����� � �������.");
//!          txSetTextAlign();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align = TA_CENTER | TA_BASELINE, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���� ����� �� ��� ��������.
//!
//! @param   name  �������� ������.
//!
//! @return  ���������� � ������ � ��������� LOGFONT. ���� ����� �� ������, ���������� NULL.
//!
//! @see     txTextOut(), txSelectFont()
//!
//! @usage @code
//!          if (txFontExist ("Comic Sans MS")) txSelectFont ("Comic Sans MS",   30);
//!          else                               txSelectFont ("Times New Roman", 30);
//!
//!          txTextOut (100, 100, "����� �� ����?");  // google.ru/search?q=philosoraptor
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[]) tx_nodiscard;

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Drawing to memory DC and image loading
//! @name    ��������� � ������ (�� "����������� ������") � �������� �����������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� �������������� ����� (�������� ���������, Device Context, DC) � ������.
//!
//! @param   sizeX     ������ ������.
//! @param   sizeY     ������ ������.
//! @param   bitmap <i>Bitmap to be associated with DC (optional). If omitted, color bitmap will be created
//!                    automatically via Win32::CreateDIBSection.</i>
//!
//! @return  ���������� (��������� �����, �������� Windows) ���������� ������ (��������� ���������).
//!
//!          ����� �������� �� ���� ������ ����� ��������, ��� � �� �������� ���� TXLib, ��������� �������� @c dc
//!          ������� ���������. ��������� ����� ����� ���� ����������� ��������� ������, ������� � �.�., ��������
//!          �� �������� ��������� ���� TXLib. ����� ������� ��������� ���������, ���������� ����������� ������
//!          �� ����� � ������� ������� txBitBlt(), txTransparentBlt() ��� txAlphaBlend().
//!
//! @warning ��������� �������� ����� ����� ����� @b ����������� ������� ��� ������ txDeleteDC(). @n
//!          <small>When the program will be shutting down, TXLib will try to delete DCs which were not deleted,
//!          but this is not guaranteed.</small> ��� ���� ��������� � @c bitmap, ������ �����������.
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection(), txVideoMemory()
//!
//! @usage @code
//!          HDC save = txCreateCompatibleDC (100, 100);
//!
//!          txBitBlt (save, 0, 0, 100, 100, txDC(), 0, 0);  // ��������� ���
//!
//!          txTextOut (20, 20, "Boo!");
//!          txSleep (2000);
//!
//!          txBitBlt (txDC(), 0, 0, 100, 100, save, 0, 0);  // ����� ��������
//!
//!          txDeleteDC (save);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap = NULL) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� ���������-����������� �������������� ����� (�������� ���������, Device Context, DC) � ������
//!          � ������������ ������� ������� � ���� ��� � �������.
//!
//! @param   sizeX     ������ ������.
//! @param   sizeY     ������ ������.
//! @param   pixels <i>��������� �� ����������, ������� ����� �������������� ��� ������� � �������� �����������.
//!                    ������������. ��� ���������� ������ ���� ���������� �� ������ �������� RGBQUAD, ������
//!                    �� ������� ��������� ���� ������ �������. @b �� ���� ��������� ������ ���� ������!
//!                    ��� ������� txCreateDIBSection() � ������ ����� ���� ������������ ��������. ��������
//!                    ������ ��������� � �������� ���, ����� ��� ����� ��������� � �������.</i>
//!
//! @return  ���������� ���������� ���������-������������ ������ (��������� ���������).
//!
//!          ����� �������� �� ���� ������ ����� ��������, ��� � �� �������� ���� TXLib, ��������� �������� @c dc
//!          ������� ���������. ��������� ����� ����� ���� ����������� ��������� ������, ������� � �.�., ��������
//!          �� �������� ��������� ���� TXLib. ����� ������� ��������� ���������, ���������� ����������� ������
//!          �� ����� � ������� ������� txBitBlt(), txTransparentBlt() ��� txAlphaBlend().
//!
//!          ����� ������, ��� ���������-����������� ������, ����������� ���� ��������, ��������� �������� � ������
//!          �������� ����� �������� �����������, � ����� ��� ������������ � ������ �����. ��. ������ �������������.
//!
//!          ��� ������� ������� � �������� ������, ��� � �������, ���� �������� ��������� �� ������ ��������
//!          RGBQUAD � �������� ����� ����� ��������� � �������� �������� ��������� ������� txCreateDIBSection().
//!          ��� ������� �������� ����� ��������� ���, ��� �� ������ ��������� �� ������ ������ �������� ������.
//!
//!          ������ @p pixels ����������, �� �� ���� �� ��������� ��������� �����������. ������� � ��� ����
//!          �������� ��� � ��������� ������������� ��������, ��������� ������������� � ���������� �������:
//!          ������� ��������� �������� �� ������ ������� �� ������� ������� � ����� ����� ������������ � �������.
//!          (��� ������ ������, �������� ��������� ������� � ������������ ������.) ����� ����, "Y-���" �����
//!          ������� ���������� @b �����, � �� ����, ��� � ���� TXLib. ������� ��� ������� ������� ��� ��������
//!          �� ������ ������� ����� ������������ � ������� ������� <tt>x + (-y + sizeY) * sizeX</tt>.
//!          ��. ������ �������������.
//!
//! @warning ������ ���������, �� �������� �� ������� �������, ����������� ����� ����������������. @nn
//!
//! @warning ��������� �������� ����� ����� ����� @b ����������� ������� ��� ������ txDeleteDC(). @n
//!          <small>When the program will be shutting down, TXLib will try to delete DCs which were not deleted,
//!          but this is not guaranteed.</small>
//!
//! @note    ������ ��� ������ RGBQUAD �������� @b �� ���� � ����������� ��� @b �� ����, ���� ���������� ����
//!          txCreateDIBSection() ������ � txDeleteDC(). @nn
//!
//! @note    ���������-����������� ������ -- ��� ��������� ���������, ��������� � ���������-������������ ��������
//!          (Device Independent Bitmaps, DIB) Windows.
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
//!              RGBQUAD* buf = NULL;                                  // Do NOT actually create the array!
//!              HDC dc = txCreateDIBSection (size.x, size.y, &buf);
//!              assert (dc); assert (buf);                            // Here, 'buf' points to an array created
//!                                                                    // by txCreateDIBSection()
//!              while (!GetAsyncKeyState (VK_ESCAPE))
//!                  {
//!                  txBitBlt (dc, 0, 0, size.x, size.y, src);
//!
//!                  for (int y = 0; y < size.y; y++)
//!                  for (int x = 0; x < size.x; x++)
//!                      {
//!                      RGBQUAD* c = & buf [x + y * size.x];          // Get color at (x, y) within image buffer
//!
//!                      c->rgbRed      = (BYTE) c->rgbRed;
//!                      c->rgbGreen    = (BYTE) c->rgbGreen;
//!                      c->rgbBlue     = (BYTE) c->rgbBlue;
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

HDC txCreateDIBSection (double sizeX, double sizeY, RGBQUAD**  pixels = NULL) tx_nodiscard;

//! @cond INTERNAL
HDC txCreateDIBSection (double sizeX, double sizeY, COLORREF** pixels)        tx_nodiscard;
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �� ����� ����������� � ������� BMP. ������ ��� �������� ��������.
//!
//! @param   filename      ��� ����� � ������������ � ������� BMP.
//! @param   imageFlags <i>��� ������������ �����������, ��. ����. ������������.  ���� �� �������, �����������
//!                        ������� � ������� BMP.</i>
//! @param   loadFlags  <i>����� �������� �����������,   ��. ����. �������������. ���� �� �������, �������� ����
//!                        �� �����.</i>
//!
//! @return  ���������� ���������� ��������� ��������� � ������, � ����������� ������������.
//!          ���� ����������� �� ��������� (�� ������ ����, �������� ������ ����� � �.�.), �� NULL.
//!
//! @warning ����������� ����������� � ������������� ����������� �������� ��������� � ������ ("����������� �����"),
//!          ������� ����� ����� ����� <b>����������� �������</b> ��� ������ txDeleteDC(). @nn
//!          <small>When the program will be shutting down, TXLib will try to delete DCs which were not deleted,
//!          but this is not guaranteed.</small>
//!
//! @note    ����������� �������������� <b>������ � ������� BMP.</b> ���� ����� ���� ������� �������, �������� JPG,
//!          � ������������� ��� �� ������ ���������� �� BMP, �� �� ����� ������ �� ���������. ����� �����������
//!          ��������� �� �����.
//!
//!          ���� ������� ������� NULL, �� ���� ������ ����� <b>��������� ������� ����� �����������</b> ��
//!          ���������� � ��������� ���� � ������ �����. ���� ���� � ����� �� ������ (��� ������ ��� ��������),
//!          �� ���� ������������� �� ������� ����� ���������, ������� ����� �� ��������� ������� ������ �����
//!          ����������������. ������� ����� ��������� ����� ���������� �� ������� About � ��������� ����
//!          (��� ������� ��� ��� "Run from").
//!
//!          ���� ����������� � ����� �������� �����-����� (���������� � ������������), �� ��� ����� ������
//!          ���������� � ������� <b>Premultiplied Alpha</b>. ��. ��������� � ������� txAlphaBlend().
//!
//!          ���� ����������� � ����� � �����-������� @b �� ��������� � ������� <b>Premultiplied Alpha</b>, �� �����
//!          ������ txLoadImage() ����� ������� ������� txUseAlpha(). ������ �� ���� ����� ������, ���� ����� � �����
//!          @b ��� ��������� � ������� Premultiplied Alpha, ����� �������� ������ ������. ����� �� ���� ��������
//!          txUseAlpha() ��������� ��� ��� ������ � ���� �� �����������.
//!
//! @note    <b>�� ���� ����� ���������</b> ���� � �� �� �����������, �������� � �����. �� ����� ��������� ��������
//!          ���������! @n
//! @note    ��������� ���� ��� @a ����� ������, ����� ����������� ����� ���. ����������, ��� ��� ������� � �������
//!          TX\Examples\Tennis\Tennis.cpp.
//!
//! @title   ���� ����������� �����������:
//! @table   @tr IMAGE_BITMAP @td ������� � ������� BMP
//!          @tr IMAGE_CURSOR @td ������ � ������� CUR ��� ANI
//!          @tr IMAGE_ICON   @td ������ � ������� ICO
//!          @endtable
//!
//! @title   ����� ��������:
//! @table   @tr LR_CREATEDIBSECTION @td ������� DIB (device-indepandent bitmap), ������� ��� ������� ������� � ������
//!          @tr LR_LOADFROMFILE     @td ��������� �� ����� (���� ���� ���� �� ������, �� ��������� �� ������� EXE-�����)
//!          @tr ��������� ����� �������� @td ��. �� MSDN.com, ����� "LoadImage function".
//!          @endtable
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txBitBlt(), txAlphaBlend(),
//!          txTransparentBlt(), txSaveImage(), txGetExtent()
//!
//! @usage   ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  background_CopiedFromHelp = txLoadImage ("Resources\\Images\\Background.bmp");
//!
//!          if (!background_CopiedFromHelp)
//!              txMessageBox ("�� ���� ��������� ��� �� Background.bmp", "��, � ���������� ��� �� �������");
//!
//!          // �� ���� ����� ��������� ���� � �� �� �����������, �������� � ����� -- ��������� ����� ���������!
//!          // ��������� ���� ��� ����� ������, ����� ����������� ����� ���.
//!          // ����������, ��� ������� � ������� TX\Examples\Tennis\Tennis.cpp.
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background_CopiedFromHelp, 0, 0);
//!
//!          ...
//!          txDeleteDC (background_CopiedFromHelp);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[], unsigned imageFlags = IMAGE_BITMAP, unsigned loadFlags = LR_LOADFROMFILE) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ����� (�������� ���������, DC) � ������.
//!
//! @param   dc  �������� ��������� ��� �����������. @n
//!           <i>���� ������� ��������� �� ��������, �� ����� ����������� �� ��������� ������������ NULL.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @see     txCreateWindow(), txCreateCompatibleDC(), txLoadImage(), txDeleteDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection()
//!
//! @usage   ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  background_CopiedFromHelp = txLoadImage ("Resources\\Images\\Background.bmp");
//!
//!          if (!background_CopiedFromHelp)
//!              txMessageBox ("�� ���� ��������� ��� �� Background.bmp, � � ���������� ��� �� �������.", "Oh, not now");
//!
//!          // ��. ������ ����������� � ������� � ������� txLoadImage!
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background_CopiedFromHelp, 0, 0);
//!
//!          ...
//!          txDeleteDC (background_CopiedFromHelp);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txDeleteDC (HDC  dc);

//! @cond INTERNAL
bool txDeleteDC (HDC* dc);
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������.
//!
//! @param   destImage    �������� ���������� (���� ����������). ��� ����������� � ���� TXLib ������� txDC().
//! @param   xDest        X-���������� �������� ������ ���� ����������� �����������.
//! @param   yDest        Y-���������� �������� ������ ���� ����������� �����������.
//! @param   width        ������ ���������� �������. <i>���� ����� 0, �� ����� ������ �����������-���������.</i>
//! @param   height       ������ ���������� �������. <i>���� ����� 0, �� ����� ������ �����������-���������.</i>
//! @param   sourceImage  �������� ��������� (������ ����������).
//! @param   xSource   <i>X-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                       �������������. ���� �� �������, �� 0.</i>
//! @param   ySource   <i>Y-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                       �������������. ���� �� �������, �� 0.</i>
//! @param   operation <i>��� �������� �����������. ������ ����� ������� �� ������� "BitBlt function MSDN".
//!                       �������������. ���� �� ������, �� @c SRCCOPY (������� ����������� �����������).</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @warning ���� ��������� ��������� ����� NULL, �� �� �� ���������� � ����������� ������� ������.
//!          �������� ������ ������� -- ������ ��� �������� ����� ����������� � ���������� �������� �� ��� ������.
//!          ������ � ��������� �� ������������ �������� ��. ����.
//!
//! @see     txAlphaBlend(), txTransparentBlt(), txSaveImage(), txGetExtent(), txSetColor(), txGetColor(),
//!          txSetFillColor(), txGetFillColor(), txColors, RGB(), txCreateDIBSection()
//!
//! @usage   ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  background_CopiedFromHelp = txLoadImage ("Resources\\Images\\Background.bmp");
//!
//!          if (!background_CopiedFromHelp)
//!              ("�� ���� ��� �� ��������� Background.bmp, � ��, � ���� ���� ��� �� �������.", "Once again :(");
//!
//!          // ��. ������ ����������� � ������� � ������� txLoadImage!
//!
//!          txBitBlt (txDC(), 0, 0, 800, 600, background_CopiedFromHelp);
//!
//!          ...
//!          txDeleteDC (background_CopiedFromHelp);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txBitBlt (HDC destImage,   double xDest,       double yDest, double width, double height,
               HDC sourceImage, double xSource = 0, double ySource = 0, unsigned operation = SRCCOPY);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� �� �����.
//!
//! @param   xDest        X-���������� �������� ������ ���� ����������� �����������.
//! @param   yDest        Y-���������� �������� ������ ���� ����������� �����������.
//! @param   sourceImage  ���������� �����������.
//! @param   xSource   <i>X-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                       �������������. ���� �� �������, �� 0.</i>
//! @param   ySource   <i>Y-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                       �������������. ���� �� �������, �� 0.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! ��. �������� � ������� txBitBlt() ����.
//}----------------------------------------------------------------------------------------------------------------

inline bool txBitBlt (double xDest, double yDest, HDC sourceImage, double xSource = 0, double ySource = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������ � ������ ������������.
//!
//! @param   destImage     �������� ���������� (���� ����������). ��� ����������� � ���� TXLib ������� txDC().
//! @param   xDest         X-���������� �������� ������ ���� ����������� �����������.
//! @param   yDest         Y-���������� �������� ������ ���� ����������� �����������.
//! @param   width         ������ ���������� �������. <i>���� ����� 0, �� ������������� ������� �� ������� ���������.</i>
//! @param   height        ������ ���������� �������. <i>���� ����� 0, �� ������������� ������� �� ������� ���������.</i>
//! @param   sourceImage   �������� ��������� (������ ����������).
//! @param   xSource    <i>X-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                        �������������. ���� �� �������, �� 0.</i>
//! @param   ySource    <i>Y-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                        �������������. ���� �� �������, �� 0.</i>
//! @param   transColor <i>����, ������� ����� ��������� ����������. ������������. ���� �� ������, �� TX_BLACK.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @warning ���� �������� ��������� ����� NULL, �� �� �� ���������� � ����������� ������� ������.
//!          �������� ������ ������� -- ������ ��� �������� ����� ����������� � ���������� �������� �� ��� ������.
//!          ������ � ��������� �� ������������ �������� ��. ����. @nn
//!
//! @warning �����������-�������� � �����������-�������� �� ����� ���������� ���� �� �����. @nn
//!
//! @warning ���� ������������� ���������� ������� �� ��������� ����� ������ �����������-���������, �� �������
//!          �������� �� �����. ����� ������, ���� xSource ��� ySource ������������, ��� �������� (xSource + width)
//!          ������ ������ �����������-���������, ��� �������� (ySource + height) ������ ������ �����������-���������.
//!
//!          ����������� ������� TransparentBlt �� Win32 API ����� �������������� �����������. � txTransparentBlt
//!          ��� ������ ��� ��������� �������������. If you need image scaling, use original function
//!          TransparentBlt and don't mess with stupid TX-based tools. (See implementation of txTransparentBlt in TXLib.h).
//!
//! @note    ���� TransparentBlt �� ��������, ����������� ������� AlphaBlend, ��� ������ �����.
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection()
//!
//! @usage   ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  superman_CopiedFromHelp = txLoadImage ("Resources\\Images\\Superman.bmp");
//!
//!          if (!superman_CopiedFromHelp)
//!              txMessageBox ("Cannot load superman, all the monsters will succeed (I copied them from TXLib Help)", "Sorry");
//!
//!          // ��. ������ ����������� � ������� � ������� txLoadImage!
//!
//!          txTransparentBlt (txDC(), 0, 0, 800, 600, superman_CopiedFromHelp);
//!
//!          // � ����� � ���:
//!          Win32::TransparentBlt (txDC(), 0, 0, 800, 600, superman_CopiedFromHelp, 0, 0, 80, 60, -1); // 10x zoom
//!          // ������ ���� Win32 GDI, ����������� �� TXLib'�! :) ��. TransparentBlt � MSDN.com.
//!
//!          ...
//!          txDeleteDC (superman_CopiedFromHelp);  // So pity :( But he was only a copy from TXLib Help.
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC destImage,   double xDest,       double yDest,       double width, double height,
                       HDC sourceImage, double xSource = 0, double ySource = 0, COLORREF transColor = TX_BLACK);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� �� ����� � ������ ������������.
//!
//! @param   xDest         X-���������� �������� ������ ���� ����������� �����������.
//! @param   yDest         Y-���������� �������� ������ ���� ����������� �����������.
//! @param   sourceImage   ���������� �����������.
//! @param   transColor <i>����, ������� ����� ��������� ����������. ������������. ���� �� ������, �� TX_BLACK.</i>
//! @param   xSource    <i>X-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                        �������������. ���� �� �������, �� 0.</i>
//! @param   ySource    <i>Y-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                        �������������. ���� �� �������, �� 0.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! ��. �������� � ������� txTransparentBlt() ����.
//}----------------------------------------------------------------------------------------------------------------

inline bool txTransparentBlt (double xDest, double yDest, HDC sourceImage,
                              COLORREF transColor = TX_BLACK, double xSource = 0, double ySource = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� � ������ ������ (��������� ���������, DC) �� ������ � ������ ����������������.
//!
//! @param   destImage    �������� ���������� (���� ����������). ��� ����������� � ���� TXLib ������� txDC().
//! @param   xDest        X-���������� �������� ������ ���� ����������� �����������.
//! @param   yDest        Y-���������� �������� ������ ���� ����������� �����������.
//! @param   width        ������ ���������� �������. <i>���� ����� 0, �� ����� ������ �����������-���������.</i>
//! @param   height       ������ ���������� �������. <i>���� ����� 0, �� ����� ������ �����������-���������.</i>
//! @param   sourceImage  �������� ��������� (������ ����������). ������ ����� 32-������� ������ � �����-����� (��. ����).
//! @param   xSource   <i>X-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                       �������������. ���� �� �������, �� 0.</i>
//! @param   ySource   <i>Y-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                       �������������. ���� �� �������, �� 0.</i>
//! @param   alpha     <i>����� ������������ �����������, � ���������� � �����-������ (0 -- ��� ���������, 1 -- ������������
//!                       ������ �����-�����). �������������. ���� �� �������, �� 1.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @warning ���� �������� ��������� ����� NULL, �� �� �� ���������� � ����������� ������� ������.
//!          �������� ������ ������� -- ������ ��� �������� ����� ����������� � ���������� �������� �� ��� ������.
//!          ������ � ��������� �� ������������ �������� ��. ����. @nn
//!
//! @warning �����������-�������� � �����������-�������� �� ����� ���������� ���� �� �����. @nn
//!
//! @warning ���� ������������� ���������� ������� �� ��������� ����� ������ �����������-���������, �� �������
//!          �������� �� �����. ����� ������, ���� xSource ��� ySource ������������, ��� �������� (xSource + width)
//!          ������ ������ �����������-���������, ��� �������� (ySource + height) ������ ������ �����������-���������.
//!
//! @note    �����������-�������� ������ ���� ��������� � ������� txLoadImage() � ����� <b>32-������� RGBA-������.</b>
//!          �������������� ����� <b>(A: �����-�����)</b> 32-�������� ������� �������� �� ������������ ������������
//!          �������� �����������: ��� ������� ������� � ���� ������ �������� 0 �������� ��� ������ ������������,
//!          �������� 255 -- ������ ��������������, ������������� �������� -- ����������������. @nn
//!
//!          ������ 32-������� �����������-�������� ����� ����� ���� ������� � ������� ������� txCreateDIBSection(), �
//!          24-������� -- �������� txCreateCompatibleDC(). ����� �������� �� ���� ����������� ����� ��������, ��� ��
//!          �������� ���� TXLib, ��������� �������� @c dc ������� ���������.
//!
//! @warning ���� ����������� ����� 32-������� RGBA-������ �����, �� ��� �����-����� �� ������ ���� ��������� ������,
//!          ����� txAlphaBlend() ��������� ����������� ��������� ���������� � �� ������� �� ����� ������. @nn
//!
//!          ���� �����������-�������� ������� � ������� txCreateDIBSection() ��� txLoadImage(), �� txAlphaBlend()
//!          ����� ������������ ��� ����� ������������, ���������� ���������� @p alpha, ��� � ������������ ������������,
//!          ���������� �����-�������.
//!
//!          ���� ����������� ����� 24-������� RGB-������ ������ (TrueColor), �� ��� �������������, ��� ������������
//!          ������������ ��� � ��� ������� ����������� ����� ������ ������������, ���������� ���������� @c alpha. @nn
//!
//!          ������ � ����, ��� ������ ����������� ��������� ��������� ����������� � 32-������� �������, ���� ���� ��
//!          ���� ���������� 24-������� ������ ��� ������ TrueColor. ���� ��� ���� � ����������� ��� �����-������,
//!          �� txAlphaBlend �� ������� ������. ��� ����������, ��������, ���� ��������� �������� � Microsoft Paint,
//!          ������� �� ����� ��������� �����-������ � ��� ���� ��������� ������ � 32-������� �������. ��� ����� �������
//!          ���� ������������ txTransparentBlt. @nn
//!
//!          ��� BMP-����� �����-����� ����� �������, ��������, � Adobe Photoshop, �������� "����� ����� (New Channel)"
//!          � ������� ������� (Channels). ������ ���� � �����-������ ������������� ������ ������������, ����� --
//!          ������ ��������������. <b>��� ���� � ���������� �������� ���� ����������� (� ������� R, G, B) ������
//!          ���� ������, � ��� ����������, ��� ������.</b> ����� ������ ����� ���������� <b>Premultiplied Alpha.</b>
//!          ��. ����������� � �����-������� � ������� TX\Examples\Tennis\Tennis.cpp (���� � ��������� ��������:
//!          TX\Examples\Tennis\Resources\Images\Racket.bmp).
//!
//!          ����� ������, ��� ��������� � ������ <b>Premultiplied Alpha</b> ���� ��������� ����� � ������� R,G,B
//!          �� �������� �����-������ @c A: <tt>R,G,B *= A / 255.0</tt>. ��������� ��� ���:
//!
//!        - ���� �������� �����-������ ��� ���������� ������� �����   0 (������   ������������), ����� ��������
//!          ������� R,G,B ��� ����� ������� ����� ������ 0 (��� ������ ����).
//!        - ���� �������� �����-������ ��� ���������� ������� ����� 255 (������ ��������������), ����� ��������
//!          ������� R,G,B ��� ����� ������� �� ���������.
//!        - ��� ������ �������� �����-������, ������� ����������� ������ ������.
//!
//!          � ��������� Adobe Photoshop ��� ����� ������� �������� <b>Image -- Apply Image</b> � �����������:
//! @table   @tr Source:     @td <i>��� ����� � ���������</i>
//!          @tr Layer:      @td Background
//!          @tr @b Channel: @td <b> Alpha 1</b>
//!          @tr Blending:   @td Multiply
//!          @tr Opacity:    @td 100%
//! @endtable
//!
//!          ���� ����������� � �����-������� @b �� ��������� � ������� <b>Premultiplied Alpha</b> @strike � ��� ����
//!          ������ ���, ��� �������� ����, @endstrike �� ��� �������� � ���� ������ ����� ������������ �������
//!          txUseAlpha(). ������ �� ���� �������� txUseAlpha() ��������� ��� ��� ������ � ���� �� ��� ������������
//!          �����������, ����� ��� ����� ����������� ������ � ������.
//!
//! @note    ����������� ������� AlphaBlend �� Win32 API @b ����� �������������� �����������. � txAlphaBlend ���
//!          @b ������ ��� ��������� �������������. If you still need image scaling, use original function AlphaBlend
//!          and don't mess with stupid TX-based tools. (See implementation of txAlphaBlend in TXLib.h: open this file
//!          in your editor and search for txAlphaBlend function definition.)
//!
//! @see     txBitBlt(), txTransparentBlt(), txLoadImage(), txCreateCompatibleDC(), txSaveImage(), txGetExtent(),
//!          txCreateDIBSection(), txUseAlpha()
//!
//! @usage   ������ ������������� ��. � ����� TX\Examples\Tennis\Tennis.cpp.
//! @code
//!          HDC  batman_CopiedFromHelp = txLoadImage ("Resources\\Images\\Batman.bmp");
//!
//!          if (!batman_CopiedFromHelp)
//!              txMessageBox ("Call to Batman failed because I copied it from TXLib Help", "Do save yourself");
//!
//!          txUseAlpha (batman_CopiedFromHelp);  // If image colors are not premultiplied, see above
//!
//!          // ��. ������ ����������� � ������� � ������� txLoadImage!
//!
//!          txAlphaBlend (txDC(), 0, 0, 800, 600, batman_CopiedFromHelp);
//!
//!          ...
//!          txDeleteDC (batman_CopiedFromHelp);  // Don't worry, batman will return in "Batman returns" movie, later...
//!          ...
//!
//!          return batman_CopiedFromHelp;        // ...and there he comes -- in TXLib copy form
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC destImage,   double xDest,       double yDest,       double width, double height,
                   HDC sourceImage, double xSource = 0, double ySource = 0, double alpha = 1.0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   �������� ����������� �� ����� � ������ ����������������.
//!
//! @param   xDest        X-���������� �������� ������ ���� ����������� �����������.
//! @param   yDest        Y-���������� �������� ������ ���� ����������� �����������.
//! @param   sourceImage  ���������� �����������.
//! @param   xSource    <i>X-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                        �������������. ���� �� �������, �� 0.</i>
//! @param   ySource    <i>Y-���������� �������� ������ ���� ���������� ������� ������ �����������-���������.
//!                        �������������. ���� �� �������, �� 0.</i>
//! @param   alpha     <i>����� ������������ �����������, � ���������� � �����-������ (0 -- ��� ���������,
//!                       1 -- ������������ ������ �����-�����). �������������. ���� �� �������, �� 1.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! ��. �������� � ������� txAlphaBlend() ����.
//}----------------------------------------------------------------------------------------------------------------

inline bool txAlphaBlend (double xDest, double yDest, HDC sourceImage,
                          double xSource = 0, double ySource = 0, double alpha = 1.0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ����� �������� � ������ ������������ (��������� ����� � ������ Premultiplied Alpha).
//!
//! @param   image  ���������� ������, ����������� �������� ���������������.
//!
//! @return  ���� �������� ���� �������, ������������ �������� HDC, ����� -- NULL.
//!
//!          �������� ������ � ������� R,G,B � ������ <b>Premultiplied Alpha</b> � ������ �������� � �����-������
//!          @c A ���� �� ������� <tt>R,G,B *= A / 255.0</tt>. ���������� ��� ���:
//!
//!        - ���� �������� �����-������ ��� ���������� ������� �����   0 (������   ������������), ����� ��������
//!          ������� R,G,B ��� ����� ������� ����� ������ 0 (��� ������ ����).
//!        - ���� �������� �����-������ ��� ���������� ������� ����� 255 (������ ��������������), ����� ��������
//!          ������� R,G,B ��� ����� ������� �� ���������.
//!        - ��� ������ �������� �����-������, ������� ����������� ������ ������.
//!
//!          �������� ������ �������� � ������ �� ������������ � ������ Premultiplied Alpha ���������:
//!
//!        - � ������ ������� ��������� ������, ������ ��. � ������� txCreateDIBSection().
//!        - ����� �������� �������� �� ����� � ������� txLoadImage(), ���� ����� ����������� � ��� �� ���� �������
//!          ��������� �� �����-����� � Adobe Photoshop ��� ����������� ��������� (��. ��������� � ������� @ref
//!          txAlphaBlend).
//!
//!          ��. ����� ��������� � ������� txAlphaBlend().
//!
//! @see     txCreateCompatibleDC(), txCreateDIBSection(), txLoadImage(), txDeleteDC(), txAlphaBlend()
//!
//! @usage   ��. � ������� txCreateDIBSection().
//}----------------------------------------------------------------------------------------------------------------

HDC txUseAlpha (HDC image);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� � ���� ����������� � ������� BMP.
//!
//! @param   filename  ��� ����� � ����������� "BMP", ���� ����� �������� ����������� � ������� BMP.
//! @param   dc     <i>���������� ������, ����������� �������� ����������� � ����. ������������. ���� txDC(),
//!                    ����������� ����������� ���� TXLib.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
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
//! @name    ��������������� �������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ����������� ���������� ��������� �� ������������ �����.
//!
//! @param   time <i>�������� � �������������. �������������. ���� �� �������, �� ������������ ����������� ���������
//!                  ��������.</i>
//!
//! @return  �������� ����� �������� � �������������.
//!
//! @note    <b>����� ������� �������� ����������� � ���� ����������� ���������,</b> ���� ���� ���������
//!          ������������� ����� txBegin(). @nn
//!          ����� ������ ���������� �� ���������� ����������� ���� ��. � ������� txBegin(). ��. ����� txEnd(),
//!          txRedrawWindow(), txUpdateWindow().
//!
//! @see     txBegin(), txEnd(), txUpdateWindow(), txDC()
//!
//! @usage @code
//!          txSleep (500); // ��: ������� ����������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

double txSleep (double time = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ���������� ����������� ����, �� ��������� �������.
//!
//!          ��� ������ ���������� ������������ ������� txEnd().
//!
//!          TXLib ��������� ������� �����������. ��� ������������� �������� ���������� �� ������� HDC, �����������
//!          � ������, � ��� ���������� ������������ ������������� ���������� �� �����. ��� ������ �������� � ��������.
//!          �������������� ����������� ����� ��������� �������� txBegin() � ������� �������� �������� txEnd(),
//!          � ���� ������ ���������� ���� ����� ������������ ��������� txRedrawWindow() ��� txSleep().
//!
//!          ���� � ��������� ��������� ��������, �� ����������� ������� txRedrawWindow() ��� txSleep(), ��� ��� ���
//!          ������������� ��������� �����������, ���������� �� ��������� ����������.
//!
//! @warning ��������� ������������ �� ������ �����. ��� ����� �������� � �������� ����������� � ����.
//!
//! @note    ���� ������ ������� Alt+PrintScreen, �� ���������� �������� ����������.
//!
//! @return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//!
//! @see     txEnd(), txSleep(), txUpdateWindow(), txDC(), txVideoMemory(), txTextCursor()
//!
//! @usage @code
//!          txBegin();                             // ����� ����������� "���������"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                             // ��� ������� �� ������� ��� txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                               // ����� �� ����� ������ ������������� �������
//!
//!          //
//!          // ��� ��������� ������������ ���������� ���������� ���� � ������:
//!          //
//!
//!          int x = 0, y = 0;
//!
//!          txBegin();                             // ��������� �������������� ���������� ����
//!
//!          while (!GetAsyncKeyState (VK_ESCAPE))  // ����, ���� �� ������ ������� ESCAPE
//!              {
//!              txSetFillColor (TX_BLACK);
//!              txClear();                         // ������� ����
//!
//!              txSetFillColor (TX_DARKGRAY);      // ������ ������. ��-����������� ��� ���� ������� � ���������
//!              txCircle (x, y, 50);               // �������. �� ������ ��� ��������� ���� �� ����� �����,
//!              txSetFillColor (TX_LIGHTGRAY);     // ��-�� ������������ ���������� � ������� �����������.
//!              txCircle (x, y, 30);
//!              txSetFillColor (TX_WHITE);
//!              txCircle (x, y, 10);
//!
//!              x += 5;                            // �������� ���������� �������
//!              y += 5;
//!
//!              txSleep (50);                      // ������ ��������. ��� ���� ����������� ���� �����������.
//!              }
//!
//!          txEnd();                               // ����� ����� �������� �������������� ���������� ����
//!
//!          //
//!          // ��� *��* ��������� ������������ ����������:
//!          //
//!
//!          txBegin();
//!
//!          while (!GetAsyncKeyState (VK_ESCAPE))
//!              {
//!              txSetFillColor (TX_BLACK);         // ������� ����
//!              txClear();
//!              txSleep (50);                      // ������ ������: ���� ����������� � ���������� ������,
//!                                                 // ����� ��� ������ ��� �������. �� ������ ������ ������ ���.
//!
//!              txSetFillColor (TX_DARKGRAY);      // ������ ������, �� �� �� ����� �����.
//!              txCircle (x, y, 50);
//!              txSetFillColor (TX_LIGHTGRAY);
//!              txCircle (x, y, 30);
//!              txSetFillColor (TX_WHITE);
//!              txCircle (x, y, 10);
//!
//!              x += 5;
//!              y += 5;
//!
//!              txEnd();                           // ������ ������: ��� ������ �� ������� ����� �����������
//!              }                                  // ���������� ����������, �� ���� ����������� �������� ������.
//!
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txBegin();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������ ���������� ����, ��������������� �������� txBegin().
//!
//! @warning ���� txBegin() ���������� ��������� ���, �� ��� ������ ���������� ����� ������� �� ��� ������� txEnd().
//!
//! @return  �������� �������� ���������� (���� 0, �� ��������� ��������������).
//!
//!          ����� ������ ���������� �� �������������� ���������� ��. � ������� txBegin(). ��. ����� txRedrawWindow(),
//!          txUpdateWindow(), txSleep().
//!
//! @note    ���� ������ ������� Alt+PrintScreen, �� ���������� �������� ����������.
//!
//! @see     txBegin(), txSleep(), txUpdateWindow(), txDC(), txVideoMemory(), txTextCursor()
//!
//! @usage @code
//!          txBegin();                        // ����� ����������� "���������"
//!          txSetFillColor (TX_WHITE);
//!          txClear();                        // ��� ������� �� ������� ��� txBegin()
//!          txSetFillColor (TX_RED);
//!          txRectangle (100, 100, 200, 200);
//!          txEnd();                          // ����� �� ����� ������ ������������� �������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txEnd();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ����������� � ���� TXLib �������.
//!
//!          ����� ������ ���������� �� �������������� ���������� ��. � ������� txBegin(). ��. ����� txEnd(),
//!          txUpdateWindow(), txSleep().
//!
//! @warning ���������� ���� ������� ������������: ��� �������� txSleep (0), ��� �������� ��������. ����� ������� �����
//!          ����������� ����������, ���������� �������� ����� ������� txRedrawWindow() � txSleep() � �������� �����.
//!          ���� �������� ����, ����� ������� ���������� �� ������ Win32 GDI, GDI Plus, OpenGL, DirectX, SDL ��� SFML.
//!
//! @see     txWindow(), txBegin(), txEnd(), txLock(), txUnlock(), txGDI()
//!
//! @usage @code
//!          txBegin();                // ��������� �������������� ���������� ������
//!
//!          txCircle (100, 100, 50);  // ������ -- ����������� �� ����������
//!
//!          Sleep (3000);             // �� txSleep()! txSleep() ���� ������� ����������� �� ������
//!
//!          txRedrawWindow();         // ��������� ����� ������� -- ����������� ����������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline void txRedrawWindow();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��� ��������� �������������� ���������� ����������� � ����.
//!
//! @param   update <i>����� ���������� (true -- ���������, false -- ���������). ������������. ���� �� ������, ��
//!                    "���������".</i>
//!
//! @return  ���������� ��������� ������ ����������.
//!
//!          � ������� �� txBegin() � txEnd(), ������� ������������ ��������� ������ � �������� ��� "������ ���
//!          ���������� ��������", txUpdateWindow() ��������� ���� ���������� ��� ����� ���������� ���������������
//!          ���������� ������.
//!
//!          ����� ������ ���������� �� �������������� ���������� ��. � ������� txBegin(). ��. ����� txEnd(),
//!          txRedrawWindow(), txSleep().
//!
//! @see     txBegin(), txEnd(), txSleep(), txUpdateWindow(), txDC(), txVideoMemory(), txTextCursor(), txLock(),
//!          txUnlock(), txGDI()
//!
//! @usage @code
//!          txUpdateWindow (false);
//!          ...
//!          txUpdateWindow();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int txUpdateWindow (int update = true);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� ������� �������� ������ GDI.
//!
//! @param   obj   ���������� ������� GDI.
//! @param   dc <i>����� (�������� ���������), � ������� ��������������� ������� �������� ������ GDI. ������������.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @note    ���������� ��������� ������ ���� �� ���� (PEN/BRUSH/BITMAP � �.�.), ��� � @c obj, @b ������������.
//!
//! @see     txSetColor(), txGetColor(), txSetFillColor(), txGetFillColor(), txColors, RGB(), txSelectFont()
//!
//! @usage @code
//!          HPEN pen = CreatePen (PS_DASH, 1, RGB (255, 128, 0));
//!          txSelectObject (pen);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txSelectObject (HGDIOBJ obj, HDC dc = txDC());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ����� ������ �������. ��. �������� �������.
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          � ���� ������� ���� ������� � ������� �������� ���������, ������� ��� � ����� ����������, �����
//!          @a ����������� ���� �������. ��� ����� @strike ����������� @endstrike ������� ��� ������������ ���
//!          � ����������, ��� ���������.
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
//                 +--<<< ��� ����� ������, ������� �� ��� ������. ����� ������! ����� [F3] ��� "����� �����"
//                 |
//                 v
//               txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();
//! @code        txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();
//!              return 0;
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

//     +--<<< ��� _��������_ �������, � ���� ����� �� _�����������_. ����� ������! ����� [F3] ��� "����� �����"
//     |
//     v
bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ����.
//!
//! @param   wnd  <i>���������� ���� ��� �����������. �������������. ���� �� ������, ������������ ���� TXLib.</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @warning ���� ������������ ���� TXLib, ������� main() ������������� ����������� � ��������� �����������.
//!          ��� ���� @b �� ������������� ���������� ���������� ���������, ������� ��� ������ @b �� �������������.
//!
//! @see     txCreateWindow()
//!
//! @usage @code
//!          txDestroyWindow();  // Farewell to the world
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txDestroyWindow (HWND wnd = txWindow());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� �������� ������ ����������.
//!
//! @return  �������� ������ (����������� ��������) � �������� ��������.
//!
//! @see     txSleep(), txGetFPS()
//!
//! @usage @code
//!          if (txQueryPerformance() < 1) printf ("������� ����� ���������");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

double txQueryPerformance() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������ ���������� ������ (������� ���� �������) � �������.
//!
//! @param   minFrames <i>���������� �������, ����� ������� FPS �������� ����������� �� ��������� @c txFramesToAverage
//!                       ������. �������������. ���� �� �������, ������������ txFramesToAverage.</i>
//!
//! @return  FPS (Frames per Second), �.�. ���������� ������ (������� ���� �������) � �������.
//!
//! @note    ����� ���������� ������� ���� ������� �������� @p minFrames, FPS �������� ����������� �� ���������
//!          @c txFramesToAverage ������. ������������ �������� ���������� -- @c txFramesToAverage ������.
//!
//! @see     txSleep(), txQueryPerformance()
//!
//! @usage   ��. � ������� txCreateDIBSection().
//}----------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#if defined (_TX_CPP11)
    template <int txFramesToAverage = 5>
#else
    const     int txFramesToAverage = 5;
#endif

//! @endcond

double txGetFPS (int minFrames = txFramesToAverage) tx_nodiscard;

//! @}
//}

//=================================================================================================================
//{          Mouse functions
//! @name    ������ � �����!
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� ������� ����!
//!
//! @return  ������� ����! ��� ��������� POINT, ��������������� �� ������ �������� ���� ����.
//!
//! @note    ���� ���� TXLib ��� @strike (����� ����!), @endstrike �� ���������� ������������� �� �������� ������
//!          ���� ������.
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//!
//! @usage @code
//!          RECT area = { 100, 100, 110, 110 };
//!
//!          while (txMouseButtons() != 1)
//!              {
//!              if (In (txMousePos(), area)) txTextOut (100, 100, "http://vk.com/TiShtoTamDelaesh?!");
//!              txSleep (0);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline POINT txMousePos() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� X-���������� ����!
//!
//! @return  X-���������� ����!, ��������������� �� ������ �������� ���� ����.
//!
//! @note    ���� ���� TXLib ��� @strike (����� ����!), @endstrike �� ���������� ������������� �� �������� ������
//!          ���� ������.
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

inline int txMouseX() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� Y-���������� ����!
//!
//! @return  Y-���������� ����!, ��������������� �� ������ �������� ���� ����.
//!
//! @note    ���� ���� TXLib ��� @strike (����� ����!), @endstrike �� ���������� ������������� �� �������� ������
//!          ���� ������.
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

inline int txMouseY() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ���������� ��������� ������ ����!
//!
//! @return  ��������� ������ ����!
//!
//!          � ������������ �������� ������������ � ������� 1-� (�������) ��� �������� ������� ����� ������ ����!,
//!          2-� -- ������ ������. @n
//!          ��������, ������������ ����� 3 (�������� 11) �������� ������������� ������� ����� � ������ ������.
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

inline unsigned txMouseButtons() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Mouse
//! @brief   ����� ����!
//!
//! @param   shouldEat  To eat, or not to eat: that is the question.
//!
//! @return  ��������� ����!
//!
//! @note    ��� ������� ����� ���������, ������ ���� �� -- ���. <a href=http://sisinmaru.com><tt> =^..^= </tt></a> @n
//!          ������� � ������� ������ ��� �� ����������� :)
//!
//! @see     txMouseX(), txMouseY(), txMousePos(), txMouseButtons()
//!
//! @usage @code
//!          void CatsLife()
//!              {
//!              try
//!                  {
//!                  while (true)
//!                      {
//!                      Mouse mouse = txCatchMouse();
//!                      Eat (mouse);
//!                      txSleep();
//!                      }
//!                  }
//!
//!              catch (Mouse& mouse)
//!                  {
//!                  Eat (mouse);  // Just do eat (R). Anyway
//!                  }
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
inline Mouse& txCatchMouse (bool shouldEat = true);
#endif

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Console functions
//! @name    ������� �������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� �������� �������� �������.
//!
//! @param   colors <i>�������� �������� �������. �������������. ���� �� �������, �� ���� -- ������-�����.</i>
//!
//! @return  ���������� �������� �������� �������.
//!
//!          @b �������� -- ��� ���� ������ (colorText) � ���� ���� (colorBackground), ������������ ������: @nn
//!          <tt>colors = colorText + colorBackground * 16</tt> @nn
//!          ���� @nn
//!          <tt>colors = colorText | (colorBackground \<\< 4)</tt> @nn
//!          ����� ��������� @b �� ����� �������� ��������� � ������ ���������, ����������� @ref txColors "TX_..."
//!          �����������, RGB(), txSetColor(), txSetFillColor() � �.�. �������� ������ ��. ����.
//!
//! @title   �������� ������ ���������
//! @table   @tr  Dec @td @c Hex @td                              @td Dec  @td @c Hex @td
//!          @tbr
//!          @tr  0 = @td @c 0x0 @td = BLACK      (������),       @td  8 = @td @c 0x8 @td = DARKGRAY     (�����-�����),
//!          @tr  1 = @td @c 0x1 @td = BLUE       (�����),        @td  9 = @td @c 0x9 @td = LIGHTBLUE    (������-�����),
//!          @tr  2 = @td @c 0x2 @td = GREEN      (�������),      @td 10 = @td @c 0xA @td = LIGHTGREEN   (������-�������),
//!          @tr  3 = @td @c 0x3 @td = CYAN       (����-�������), @td 11 = @td @c 0xB @td = LIGHTCYAN    (������-����-�������),
//!          @tr  4 = @td @c 0x4 @td = RED        (�������),      @td 12 = @td @c 0xC @td = LIGHTRED     (������-�������),
//!          @tr  5 = @td @c 0x5 @td = MAGENTA    (���������),    @td 13 = @td @c 0xD @td = LIGHTMAGENTA (������-���������),
//!          @tr  6 = @td @c 0x6 @td = DARKYELLOW (�����-������), @td 14 = @td @c 0xE @td = YELLOW       (������),
//!          @tr  7 = @td @c 0x7 @td = LIGHTGRAY  (������-�����), @td 15 = @td @c 0xF @td = WHITE        (�����).
//! @endtable
//!
//!          ����� ���� ���������� ����������� ���� @c FOREGROUND_\<�������� �����\>, ��������, @c FOREGROUND_WHITE. @nn
//!          ����� ���� ���������� ����������� ���� @c BACKGROUND_\<�������� �����\>, ��������, @c BACKGROUND_CYAN.
//!
//!          � ����������������� ������� ��������� �������� �������� ���: ���� �����, ������, ������ ����
//!          �� ����� ����, �� ��� ��� ����� @c 0x1e (������� ����� -- ������� 4 ���� -- ��� ���� ����, �������
//!          ����� -- ������� 4 ���� -- ��� ���� ������).
//!
//! @see     txTextCursor(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(), txGetConsoleExtent(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          txSetConsoleAttr (FOREGROUND_YELLOW | BACKGROUND_BLUE);
//!          printf ("� � ���� 0x1 ���� ����� 0xE");  // (c) �. �����������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned txSetConsoleAttr (unsigned colors = 0x07 /*FOREGROUND_LIGHTGRAY*/);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� �������� �������� �������.
//!
//! @return  ������� �������� �������� �������. ��. txSetConsoleAttr().
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleCursorPos(), txGetConsoleExtent(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          unsigned attr = txGetConsoleAttr();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

unsigned txGetConsoleAttr() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������� ����� �������.
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//!          ��� �������� ������������ ������� �������� (����� ������ � ����) �������.
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(), txGetConsoleExtent(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          txClearConsole();  // �� ��� � ���, ������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txClearConsole();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ������������� ������� ��������� ������� �������.
//!
//! @param   x  X-���������� ������� � ��������.
//! @param   y  Y-���������� ������� � ��������.
//!
//! @return  ���������� ��������� ��������� ������� � ��������, � <a href=http://www.google.com/search?q=POINT+structure+MSDN>
//!          ��������� POINT.</a>
//!
//! @note    ������ ���������� ������ ����� �������. ����� � ������� ���������� �� ������������� �����, ������
//!          ������� ������� �� �������� ������ �������. ��������������� ������� �����������, ����� ������ �����
//!          � ������ �����. ��. ������ � ������� txGetConsoleFontSize().
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txGetConsoleCursorPos(), txGetConsoleExtent(),
//!          txClearConsole()
//!
//! @usage @code
//!          txSetConsoleCursorPos (txGetExtentX(), txGetExtentY());  // ����� ���������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txSetConsoleCursorPos (double x, double y);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ��������� ������� �������.
//!
//! @return  ��������� ��������� ������� � ��������, � <a href=http://www.google.com/search?q=POINT+structure+MSDN>
//!          ��������� POINT.</a>
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleExtent(),
//!          txClearConsole()
//!
//! @usage @code
//!          POINT pos = txGetConsoleCursorPos();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleCursorPos();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������ �������.
//!
//! @return  ��������� ��������� ������� � @b ��������, � <a href=http://www.google.com/search?q=POINT+structure+MSDN>
//!          ��������� POINT.</a>
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleExtent(),
//!          txClearConsole()
//!
//! @usage @code
//!          POINT size = txGetConsoleExtent();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleExtent();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ���������� ������� ������ �������.
//!
//! @return  ������� ������ ������� � ��������, � <a href=http://www.google.com/search?q=POINT+structure+MSDN>
//!          ��������� POINT.</a>
//!
//! @see     txTextCursor(), txSetConsoleAttr(), txGetConsoleAttr(), txSetConsoleCursorPos(), txGetConsoleExtent(),
//!          txGetConsoleFontSize(), txClearConsole()
//!
//! @usage @code
//!          POINT size = txGetConsoleFontSize();
//!          txSetConsoleCursorPos (5 * size.x, 10 * size.y);  // � ������ ����� ��� ���
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleFontSize() tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Drawing
//! @brief   ��������� ��� ��������� ��������� ��������� ������� � ����.
//!
//! @param   blink <i>false -- ��������� �������� ������. ���� �� �������, �� ������� �����������.</i>
//!
//! @return  ���������� �������� ��������� �������.
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
//! @name    ������ �������� �������, �� ��������� � ����������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� �������� ����.
//!
//! @param   filename    ��� ��������� �����, ������� ����������. <i>���� �� ������� ��� NULL, �� ������������� ����.</i>
//! @param   mode     <i>����� ���������������. �������������. ���� �� ������, �� SND_ASYNC (��. ����).</i>
//!
//! @return  ���� �������� ���� ������� -- true, ����� -- false.
//!
//! @title   ������ ���������������: @table
//!          @tr @c SND_ASYNC       @td ���� ������������� ������������ � ������� ���������. @n
//!                                     ����� �������� ��������, �������� txPlaySound (NULL).
//!          @tr @c SND_SYNC        @td ���������� ��������� ������������������ �� ��������� ��������������� �����.
//!          @tr @c SND_LOOP        @td ����������� ���� ��� ���������������. @n
//!                                     ����� �������� ��������, �������� txPlaySound (NULL).
//!          @tbr
//!          @tr @c SND_NODEFAULT   @td �� ������������ ���� �� ���������, ���� ������ ��������� ��������� �������� ����.
//!          @tr @c SND_NOSTOP      @td ���� �����-���� ���� ��� �������������, @b �� ������������� ��� ��� ������� ���������� �����.
//!          @tr @c SND_APPLICATION @td ����������� ����, ��������� ���������, ������������������ ��� ������� ���� �������� ������.
//! @endtable
//!
//! @note    �������������� ������ ����� � ������� WAV. ��������� ������� (MP3 � ��.) ���� �������������� � WAV.
//!          �������������� �� ������ ���������� �� �������, ��� � � ������ � �������� �������� � txLoadImage().
//!
//! @see     txSpeak(), txPlayVideo()
//!
//! @usage @code
//!          txPlaySound ("tada.wav");  // So happy that this always exists
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txPlaySound (const char filename[] = NULL, DWORD mode = SND_ASYNC);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� �����.
//!
//! @param   x         X-���������� �������� ������ ���� �����. <i>��. �������������� ����.</i>
//! @param   y         Y-���������� �������� ������ ���� �����. <i>��. �������������� ����.</i>
//! @param   width     ������ �����. ���� 0, �� ����� ������ ����. <i>����� ��. �������������� ����.</i>
//! @param   height    ������ �����. ���� 0, �� ����� ������ ����. <i>����� ��. �������������� ����.</i>
//! @param   fileName  ��� ���������� (������� ����������) ��� ������ ������� ���������, � ������� �������� VideoLAN
//!                    (rtsp://, http:// � �.�.). ���� ��� -- ������ ������ @c (""), �� ���������� ������ ��������
//!                    �� ������� ������������������.
//! @param   zoom   <i>������� �����������. ������������. ���� �� ������, �� ����� 0 (�������������������).</i>
//! @param   gain   <i>��������� �����, �� 0 �� 8 (800%). �������������. ���� �� �������, �� ����� 1 (100%).</i>
//! @param   wnd    <i>����, � ������� ��������������� �����. �������������. ���� �� �������, �� ������������
//!                    ���� TXLib.</i>
//!
//! @return  ����� ��������������� � ������������� (���� �� ������� ����� @c \\a). ���� ������ ��� ����� 0,
//!          �� ����� �� �����������. :( ��. ���� ������ ����.
//!          @nn
//!          ���� ������� ����� @c \\a, �� ������������ �������� -- ���������� (HWND) ���� �����������
//!          (��. "����������� ���������������").
//!
//! @title   ������������ �������� � ������ ������: @table
//!          @tr @c INT_MIN                    @td �� ������ ������������������.
//!          @tr @c INT_MIN+1                  @td �� ������ ���������.
//!          @tr @c INT_MIN+2                  @td ���������� ������ ����������� ������ ���� �����������.
//!          @tr @c INT_MIN+3                  @td ���������� ������ �������� ���� �����������.
//!          @tr @c INT_MIN+4                  @td ���������� ������ ������� VideoLAN.
//!          @tr ������ ������������� �������� @td ��� ���������� �������� VideoLAN � �������� ������.
//! @endtable
//!
//! @par     ����������� ��������������� �����
//!          @n
//!          ���� � ��������� @c fileName ����� ������ �������� ��������� ������ @c \\a, �� ���� �����
//!          ���������������� ����������: txPlayVideo() ����������� ����� ����� ������, � ���������������
//!          ����� ������ ����������� � ������� ���������. ���� ��� ����� �� ����� ������ <b>�� ����.</b>
//!          ��������������� ����������, ����� ���������� ���������, ��� ����� ����� ������� ���� TXLib.
//!          ��. ������ �������������.
//!          @nn
//!          ��� ���� ����� txPlayVideo() ������ ����� � ���������, ������ ����� ���������������, � ������
//!          ����� ������������.
//!          @nn
//!          � ������ ������������ ���������������� ������������ ��������� ������� txPlayVideo() ����� ��
//!          ����� �� ������, � ���������� ���� ����������� (HWND). � ��� ������� ����� �������������� ���
//!          ����, ��� ��������� �� ������, �������, ��������� � ������ ��������. ��. �������
//!          <a href="https://www.google.com/search?q=MoveWindow+function+Win32+apps">MoveWindow</a>(),
//!          <a href="https://www.google.com/search?q=ShowWindow+function+Win32+apps">ShowWindow</a>()
//!          � ������ ������ � MSDN. �������. ����� ��. ������ �������������.
//!          @nn
//!          �������� �������� ����������� ��������������� �����, ��������� ���� ����������� � �������
//!          ������� txDestroyWindow().
//!          @nn
//!          ������������� ��������� ����������� ��������������� @b ���� ����� �����, ������ �����
//!          <tt>txPlayVideo (NULL).</tt>
//!
//! @warning ���� � ��������� ��������� @c (wnd) ������� @b �� ���� TXLib, � �����-���� ������, �� ����������
//!          ����� @c x, @c y � ��� ������� @c width, @c height ������������. � ���� ����� ���������� �����
//!          �������� ��� ���������� ������� ����, ���������� ���������� @c wnd. ��. ������ �������������.
//!
//! @note    <b>��������������� ����� ������� ��������� ������� ��������� @c VideoLAN @c (vlc.exe) ������ 3.0 ���
//!          �����.</b> �� ����� ������� � ������������ ����� <a href=http://videolan.org><b>VideoLAN.org</b></a>.
//!          ��� ��������� @c VideoLAN ����� ���������������� �� ����� � ��������� ��������� �� ������.
//!          @nn
//!          <b>���� ����� ��������� VideoLAN ��������� @c (vlc.exe) ��� ����� �� �������</b> � ���������
//!          ��������� �� ���� ������, �� ���������� <b>�� 64-������</b> ������ VideoLAN, <b>� 32-������ @c (x86).</b>
//!
//! @see     <a href=https://www.youtube.com/watch?v=z_AbfPXTKms><b>��� ����!</b></a>, txPlaySound(), txSpeak(),
//!          txMessageBox(), txOutputDebugPrintf()
//!
//! @usage @code
//!          // ��� ����, 24 000 000+ ����������. � �� ���� ������� � �����? :)
//!
//!          #define MARU_ON_YOUTUBE "http://ded32.net.ru/www.youtube.com-watch-z_AbfPXTKms"
//!                                        // Cached from www.youtube.com/watch/z_AbfPXTKms
//!          int main()                    // Because Google prevents direct playing from Youtube
//!              {
//!              txCreateWindow (800, 500);
//!              txSetFillColor (TX_BLUE);
//!              txClear();
//!
//!              txDrawText (0, 0, txGetExtentX(), txGetExtentY(), "Press ESC to stop!");
//!              txSleep();
//!
//!              if (txPlayVideo ("") <= 0) return TX_ERROR ("� ���� �� ������? VideoLAN �� ������..."), 1;
//!
//!              txPlayVideo ("\a" MARU_ON_YOUTUBE);
//!
//!              txPlayVideo (580, 330, 200, 150, MARU_ON_YOUTUBE, 0, 0);
//!
//!              // ��� ���, ��� [�������] ��������...
//!
//!              system ("cmd.exe /c start /min notepad.exe");
//!              double dt = 0.04 / (txQueryPerformance() + 1);
//!
//!              HWND notepad = FindWindow ("Notepad", NULL);
//!              if (!notepad) return 1;
//!
//!              txPlayVideo ("\a" MARU_ON_YOUTUBE, 0, 1, notepad);
//!
//!              HWND wnd = (HWND) txPlayVideo (0, 330, 200, 150, "\a" MARU_ON_YOUTUBE, 0, 0);
//!
//!              for (double t = 0; !GetAsyncKeyState (VK_ESCAPE); t += dt)
//!                  {
//!                  static const POINT cent = { GetSystemMetrics (SM_CXSCREEN) / 2, GetSystemMetrics (SM_CYSCREEN) / 2 };
//!                  static const POINT size = { 500, 400 };
//!
//!                  MoveWindow (notepad, cent.x + ROUND (cent.y/2 * cos (t)) - size.x/2,
//!                                       cent.y - ROUND (cent.y/2 * sin (t)) - size.y/2, size.x, size.y, false);
//!
//!                  ShowWindow (notepad, SW_RESTORE);
//!
//!                  MoveWindow (wnd, ROUND (t*100) % 1000 - 200, 330, 200, 150, false);
//!
//!                  Sleep (20);
//!                  }
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

intptr_t txPlayVideo (int x, int y, int width, int height, const char fileName[],
                       double zoom = 0, double gain = 1, HWND wnd = txWindow());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� �����.
//!
//! @param   fileName  ��� ���������� (������� ����������) ��� ������ ������� ���������, � ������� �������� VideoLAN
//!                    (rtsp://, http:// � �.�.). ���� ��� -- ������ ������ @c (""), �� ���������� �������� �� �������
//!                    ������������������.
//! @param   zoom   <i>������� �����������. ������������. ���� �� ������, �� ����� 0 (�������������������).</i>
//! @param   gain   <i>��������� �����, �� 0 �� 8 (800%). �������������. ���� �� �������, �� ����� 1 (100%).</i>
//! @param   wnd    <i>����, � ������� ��������������� �����. �������������. ���� �� �������, �� ������������ ���� TXLib.</i>
//!
//! @return  ��. � ������� txPlayVideo() ����.
//!
//! ��. �������� � ������� txPlayVideo() ����.
//}----------------------------------------------------------------------------------------------------------------

intptr_t txPlayVideo (const char fileName[], double zoom = 0, double gain = 1, HWND wnd = txWindow());

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ @strike ����� @endstrike ����� �����.
//!
//! @param   text  ����� ��� @strike ������������ @endstrike ������.
//!
//! @return  ����� ������ ������ � ������������� (���� �� ������� ����� @c \\a). ���� -1, �� ����� �� ����������. :(
//!
//!          ��� ������������� ���� ������� ������� ����� ���������� ����� @c TXLib.h ���������� ��� @c TX_USE_SPEAK
//!          �������� <tt>\#define TX_USE_SPEAK</tt> @b �� ������ � \#include "TXLib.h" ��� ����, ����� TXLib ������������
//!          ���������� Microsoft Speech API (SAPI.h). ��. ������ ������������� ����.
//!
//!          ����� �������� �������, ������������� �� ��������� � ������ ���������� Windows. ���� ����� ������������ �������
//!          ���� (������� � Windows 8.1), �� ����� ������������ ������� �����. �� Windows 8.1 ��� �� ���������������. ����
//!          ����� ������ �����, �� ������� ��� � ������ ���������� Windows.
//!
//! @note    ���� ����� ���������� � ������� @c \\v, �� �� ��� � ���������� �� ������ (��� ������ @c \\v �� ����������). @nn
//!
//! @note    ���� ����� ���������� � ������� @c \\a, �� �� ��������������� ����������: txSpeak() ������������ ����� �����
//!          ������, � ������ ���� ����������� � ������� ���������. ��� ���� ����� txSpeak() ������ ����� � ���������,
//!          ������ ����� ������, � ������ ����� ������������. @nn
//!
//! @note    ���� ������ � ������� ������ (�� ������ @c \\v � @c \\a), �� txSpeak() ����� ������ ���-�� ����� ������, ���
//!          ������ ��������. :)
//!
//! @warning ��� ������ ���� ������� TXLib ������� ������� ����� @c SAPI.h �� ����������� ���������� Windows. �� �� ����
//!          ���������� �� ����. ���� ���� ���� �� ������, �� ����� ������ ����������. @nn
//!          ���� ���� ����� ���� � Visual Studio ��� � ���� ������ ��������� MinGW: https://nuwen.net/mingw.html.
//!
//! @see     txPlaySound(), txPlayVideo(), txMessageBox(), txOutputDebugPrintf()
//!
//! @usage @code
//!          #define  TX_USE_SPEAK
//!          #include "TXLib.h"
//!
//!          int main()
//!              {
//!              txSpeak ("TX Library is cool!");
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txSpeak (const char* text, ...) tx_printfy (1);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��������� � ���� � ������� ������� MessageBox.
//!
//! @param   text      ����� ���������. <i>� ��������, �������������, �� ����� �� ����� ���� ��������?</i>
//! @param   header <i>��������� ���������. �������������.</i>
//! @param   flags  <i>����� ����������� ���������. �������������.</i>
//!
//! @return  ��������, ������������ �������� MessageBox.
//!
//! @warning ����� �� ������ ��������� _TX_BIGBUFSIZE ��������, � ��������� -- _TX_BIGBUFSIZE ��������, ����� ���
//!          ����������.
//!
//! @note    ������ <tt><b>txMessageBox (text, header, flags)</b></tt> ����� ������������ ����������� ������� Win32
//!          <tt><b>MessageBox (txWindow(), text, header, flags)</b></tt>. ������� txMessageBox � ���, ��� ���
//!          ������������� ����������� ����-��������, � � ���, ��� ��� ������ � ���� ������� ����������� � ������
//!          UNICODE. ��� ����� ���� � ��� ������, ����� <i>� ������������ ���������� ����������� ������ Windows
//!          ������� ����������� ������� �������� ��� ��������, �� �������������� UNICODE.</i> � ��������� �������
//!          ����� � @c txMessageBox ���.
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txNotifyIcon(), txSpeak(), txStackBackTrace()
//!
//! @usage @code
//!          if (txMessageBox ("����������?", "������ ����", MB_YESNO) == IDYES)
//!              {
//!              MessageBox (txWindow(), "������ � �������� MessageBox()", "Win32 ��������", 0);
//!              }
//!          else
//!              txMessageBox ("������� �� ��������� ������ ������� ����, ��� ����������� � ���.");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txMessageBox (const char text[] = "��������! :)", const char header[] = "TXLib ��������",
                  unsigned flags = MB_ICONINFORMATION | MB_OKCANCEL);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������, ������ �� ��������� �������.
//!
//! @param   key  ��� (�����) �������, ��� �������, �������� ���������� (VK_SPACE, VK_LEFT, 'W' � �.�.)
//!
//! @return  true, ���� ��������� ������� ������, false -- ���� �� ������.
//!
//! @note    � ������� �� ������������ ������� GetAsyncKeyState(), ���������� false, ���� ���� TXLib �� �������.
//!
//! @usage @code
//!          void PlayBall();
//!
//!          int main()
//!              {
//!              txCreateWindow (800, 600);
//!
//!              PlayBall();
//!              }
//!
//!          void PlayBall()
//!              {
//!              int x  = 100, y  = 100;
//!              int vx = 5,   vy = 7;
//!              int ax = 0,   ay = 1;
//!              int dt = 1;
//!
//!              txSetColor     (TX_LIGHTGREEN);
//!              txSetFillColor (TX_GREEN);
//!
//!              while (!txGetAsyncKeyState (VK_ESCAPE))  // ��������� ����� ��� VK_...,
//!                  {                                    // � ������� �� ���
//!                  txCircle (x, y, 20);
//!
//!                  vx += ax * dt;                       // First velocity, then position: this gives more precision
//!                  vy += ay * dt;                       // See: http://en.wikipedia.org/wiki/Backward_Euler_method
//!
//!                   x += vx * dt;
//!                   y += vy * dt;
//!
//!                  if (x > 800) { vx = -vx; x = 800; }  // = 800 is not the precise solution. Can you make it better?
//!                  if (x <   0) { vx = -vx; x =   0; }
//!                  if (y > 600) { vy = -vy; y = 600; }
//!                  if (y <   0) { vy = -vy; y =   0; }
//!
//!                  if (txGetAsyncKeyState (VK_LEFT))  vx--;
//!                  if (txGetAsyncKeyState (VK_RIGHT)) vx++;
//!                  if (txGetAsyncKeyState (VK_UP))    vy--;
//!                  if (txGetAsyncKeyState (VK_DOWN))  vy++;
//!                  if (txGetAsyncKeyState (VK_SPACE)) vx = vy = 0;
//!                  if (txGetAsyncKeyState ('M'))      printf ("Meow ");
//!
//!                  txSleep (20);
//!                  }
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

bool txGetAsyncKeyState (int key);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ����������� ��������� � ��������� ����.
//!
//! @param   flags   ����� ���������.
//! @param   title   ��������� ���������.
//! @param   format  ������ ��� ������, ��� � printf().
//!
//! @title   ����� ���������:
//! @table   @tr @c NIIF_INFO    @td ����������
//!          @tr @c NIIF_WARNING @td ��������������
//!          @tr @c NIIF_ERROR   @td ��������� �� ������
//! @endtable
//!
//! @return  ������� �� ���������� ���������.
//!
//!          ������� ��������� ��������� �� �������� printf() � ������� �� ����������� ����.
//!
//! @warning
//!        - ��� ������� �������, ����� ��� ���������� ��������� ������ Internet Explorer @c (_WIN32_IE) ����
//!          ������ �� ���� 0x0500. ��� ����� ���� ���� <b>�������� TXLib.h ������ @c windows.h ��� ����� ���.</b>
//!          ���� ���� �������������� ���������� @c (\#define) ��� ���������. @n
//!          <small>� ������� Internet Explorer ��� ������� ������, ��� ��� ��� ��������� � Windows �����������
//!          ������ ���������� (��������, @c shell32.dll � @c comctl32.dll), ������� ������ �� ����������������
//!          ������� ���������� �� ������������� ��������). ��� Internet Explorer � ����������� ���������
//!          �� ���������.</small>
//!        - ��������� �� ������ ��������� _TX_BUFSIZE ��������, ����� ��� ����������.
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox(), txSpeak()
//!
//! @usage @code
//!          int hours = 3, minutes = 10;
//!          const char station[] = "���";
//!          ...
//!          txNotifyIcon (NIIF_INFO, "��������� ���������",
//!                        "����� �� %s ������������ � %d:%d.", station, hours, minutes);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
bool txNotifyIcon (unsigned flags, const char title[], const char format[], ...) tx_printfy (3);
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��������� � ���������.
//!
//! @param   format  ������ ��� ������, ��� � printf().
//!
//! @return  ���������� ������������ ��������.
//!
//!          ������� ��������� ��������� �� �������� printf() � �������� ��� � OutputDebugString(). �� ����� �����
//!          ����������� ���������� ��� ���������-���������, ��������,
//!          <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>DbgView</a>.
//!          ���� ����� �� �������, � �� ������ ������ ������ @c '\\a' (��. ����), �� � ��������� ����� �� ������. :(
//! @note
//!        - ���� ������            ������ � ������ @c '\\a', �� ��������� ����� ����������� txMessageBox().
//!        - ���� ������ ��� ������ ������ � ������ @c '\\f', �� ��������� ����� ����������� printf().
//!
//! @warning ��������� �� ������ ��������� _TX_BIGBUFSIZE ��������, ����� ��� ����������.
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR(), txPrintf(), txNotifyIcon(), txMessageBox(), txStackBackTrace()
//!
//! @usage @code
//!          int x = 42;
//!          ...
//!          txOutputDebugPrintf ("����� �� ������, ��� %d.\n", x);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txOutputDebugPrintf (const char format[], ...) tx_printfy (1);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ������� ������. ������ ����������.
//!
//! @param   format  ������ ��� ������, ��� ��� � ����� ������� printf().
//! @param   args    �������� ��� ������.
//!
//! @return  ���������� ������������ ��������.
//!
//!          ������� �������� ���������� @c printf(). ������, � ���� ���������� @strike ��������������� @endstrike
//!          ������������� ��������, ��� ������������� @d ���� ���������� ��� ���������� ���������� � �����������
//!          ������ ������� �������������� �����. ����������� ���������� �������������� ������� ���� @c %$ (��� @c %?)
//!          ������ ������ �������� �����, ����� ��� <tt>%d, %i, %c, %s, %p, %g</tt> � ������.
//!
//!          txPrintf() ��������� ������������� ����, �� ���������� � ���� �++: ������ �++ @c (std::string),
//!          ��������� ���� Win32 (��������, @c POINT) � ���� ����������� ����. ��� ����, ����� ���� ���� �����
//!          ����������, ���� ���������� ���������������� �������� ������ � ����� STL. ���, ��������, ��� ���������
//!          �������� ������ ��� ��������� POINT:
//! @code
//!          std::ostream& operator << (std::ostream& stream, const POINT& point)
//!              {
//!              stream << "{ x: " << point.x << ", y: " << point.y << " }";
//!              return stream;
//!              }
//! @endcode
//!          �� ������ ���������� ���� �������� ������ ����������.
//!
//!          �� ����� ���� ������� txPrintf() @d ��� ������� ��� ����������� ���������� ������ STL: @c operator @c <<.
//!          ����� �� ������, � � ����� ������ ����� ���������������� ����� � �������������� ������ �������������� ���
//!          ��� ����� ��� �� ������� �� ��������� ������������� �������. ������ ����, ����� ��������� ����� ���������
//!          � ����, TXLib ���������� ��� ������������ �������� @c <<, ��� ������������� ��� ���� ����������� �����,
//!          � ��� ������� ��� ������ �����.
//!
//! @note    ���� ����� �������� ������������� ������ ��� �������� � ���� ���������� (��� �������� @c %*, @c %.* ���
//!          @c %*.*), �� ����� ����������� � ����������� @c width() � @c precision() � ������� ��������������� �������.
//!          ��. ������ ����. @nn
//!        - <tt>width_t     width     (int)</tt> @d �������, ������������� ������������ ������   � ��� enum @c width_t.
//!        - <tt>precision_t precision (int)</tt> @d �������, ������������� ������������ �������� � ��� enum @c precision_t.
//!
//! @warning ������� �������� ��������� � ������ �� �������: ��-������, � ���� ���������� ������ ������������� �������
//!          ������ STL @c (std::ostream), ��-������, ����� ������� ���� � ������ (����� ����� @c std::ostringstream),
//!          � ������ ����� ����������. @nn
//!          ���� ������� ������� � ��������� @d ������ ������� ������, �� ������������ �������. ���, ��� ��� �������
//!          � @c TXLib @d ������� ����.
//!
//!          ���� ���������� ����� � @strike ����������� ������ ������������ �++ @endstrike (Alexandrescu A., "Variadic
//!          Templates are Funadic", Going Native 2012, Redmond, WA, USA, https://www.youtube.com/watch?v=dD57tJjkumE,
//!          ������� ����� �������� ��. https://habr.com/ru/post/139064).
//!
//!          ���� ����� ������ <tt>TX_PRINTF (format, ...)</tt>, ������� ��������� ��������� �������� ������������
//!          ����������� ������� @c printf() � ����� �������� txPrintf(). �� �� ��������� %c %$ (%?), ������� �������
//!          ������������ �������� �������������� ����� � �� ��������� ���������� ����, �� ���������� ���������� � ����
//!          �++ (����������� � ��������� ����). ����������� ���, ���� � ���������� �� ���������� ������� �� �������
//!          @c printf().
//!
//! @warning ��� ������� �������� ������ ���� ��� ���������� ������������ �������� C++11 (g++ � ������ @c -std=c++11
//!          ��� ����, Microsoft Visual Studio 2013 ��� ����). ����������� ������ _TX_CPP11, ������� ���������, ����
//!          ���������� ������������ �������� C++11.
//!
//! @see     txFormat(), TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txNotifyIcon(), txMessageBox()
//!
//! @usage @code
//!          //         +--+--+---+---+----+-----+---+--+
//!          //         |2 |3 | 4 | 5 | 6  |  7  | 8 |  |
//!          //         +--+--+---+---+----+-----+---+--+
//!          txPrintf ("|%$|%s|%5s|%*d|%.*f|%*.*$|%*$|%%|\n",            // Arg#1
//!          //         |  |  |   |   |    |     |   |  |
//!          //         +--+--+---+---+----+-----+---+--+
//!                                               12,                    // Arg#2
//!                                              "Cats power!",          // Arg#3
//!                                               std::string ("meow"),  // Arg#4
//!                    width (10),                56,                    // Arg#5
//!                    precision (3),             3.141592653,           // Arg#6
//!                    width (15), precision (6), 2.718281828,           // Arg#7
//!                    width (20),                POINT { 10, 20 });     // Arg#8
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#if defined (_TX_CPP11) ||  defined (FOR_DOXYGEN_ONLY)

template <typename T, typename... ArgsT>
int txPrintf (const char* format, ArgsT... args);

#define TX_PRINTF(...)  ( _txPrintfCheck (__VA_ARGS__), txPrintf (__VA_ARGS__) )

#endif

//-----------------------------------------------------------------------------------------------------------------

#if defined (_TX_CPP11) && !defined (FOR_DOXYGEN_ONLY)

enum width_t     : int {};
enum precision_t : int {};

inline width_t     width     (int width) { return (width_t)     width; }
inline precision_t precision (int prec)  { return (precision_t) prec;  }

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   �������� � ��������� ����� ������, ��� sprintf().
//!
//! @param   format  ������, ��� � sprintf().
//! @param   stream  ��������� ����� ������.
//! @param   args    �������� ��� ������.
//!
//! @return  ���������� ������������ ��������.
//!
//! @warning ��� ������� �������� ������ ���� ��� ���������� ������������ �������� C++11 (g++ � ������ @c -std=c++11
//!          ��� ����, MSVC 2013 ��� ����). ����������� ������ _TX_CPP11, ������� ���������, ���� ���������� ������������
//!          �������� C++11.
//!
//! @see     txPrintf(), TX_ERROR(), TX_DEBUG_ERROR(), txPrintf(), txNotifyIcon(), txMessageBox(), txStackBackTrace()
//!
//! @usage   ��. ������ � ������� txPrintf() ����.
//!
//}----------------------------------------------------------------------------------------------------------------

#if defined (_TX_CPP11) ||  defined (FOR_DOXYGEN_ONLY)

template <typename T, typename... ArgsT>
int txPrintf (std::ostringstream& stream, const char* format, ArgsT... args);

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   �������� � ��������� �����, ��� sprintf().
//!
//! @param   format  ������, ��� � sprintf().
//! @param   buffer  ����� ��� ������.
//! @param   size    ����� ������ ������.
//! @param   args    �������� ��� ������.
//!
//! @return  ���������� ������������ ��������.
//!
//! @warning ��� ������� �������� ������ ���� ��� ���������� ������������ �������� C++11 (g++ � ������ @c -std=c++11
//!          ��� ����, MSVC 2013 ��� ����). ����������� ������ _TX_CPP11, ������� ���������, ���� ���������� ������������
//!          �������� C++11.
//!
//! @see     txPrintf(), TX_ERROR(), TX_DEBUG_ERROR(), txPrintf(), txNotifyIcon(), txMessageBox(), txStackBackTrace()
//!
//! @usage   ��. ������ � ������� txPrintf() ����.
//!
//}----------------------------------------------------------------------------------------------------------------

#if defined (_TX_CPP11) ||  defined (FOR_DOXYGEN_ONLY)

template <typename T, typename... ArgsT>
int txPrintf (char buffer[], size_t size, const char* format, ArgsT... args);

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ������, ��� sprintf().
//!
//! @param   format  ������, ��� � sprintf().
//! @param   args    �������� ��� ������.
//!
//! @return  ����������������� ������ � ���� @c std::string.
//!
//! @warning ��� ������� �������� ������ ���� ��� ���������� ������������ �������� C++11 (g++ � ������ @c -std=c++11
//!          ��� ����, MSVC 2013 ��� ����). ����������� ������ _TX_CPP11, ������� ���������, ���� ���������� ������������
//!          �������� C++11.
//!
//! @see     txPrintf(), TX_ERROR(), TX_DEBUG_ERROR(), txPrintf(), txNotifyIcon(), txMessageBox(), txStackBackTrace()
//!
//! @usage   ��. ������ � ������� txPrintf() ����.
//!
//}----------------------------------------------------------------------------------------------------------------

#if defined (_TX_CPP11) || defined (FOR_DOXYGEN_ONLY)

template <typename... ArgsT>
std::string txFormat (const char* format, ArgsT... args);

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������� ������� � ���������
//!
//! @param   arr  ��� �������.
//!
//! @return  ������ ������� � ��������� (�� � ������).
//!
//!          ������ sizearr() ��������� ������ ������� � ���������, ��������, ����� �� ��� ��������� ��������� ���
//!          ����������.
//!
//!          ������ SIZEARR() ������ ����� ������ ����� ������� � ������ �� ������ ��� ��������, ���������� ������
//!          ������� � ���������. @n
//!          �� <b>�� ���������,</b> ����� �� ��� ��������� ���������, � ��� ������������ ������������� �����
//!          ������ <b>�������� ������.</b>
//!
//! @warning SIZEARR() ������ �������� ������, ���� ����������� ������� ������ � ��� ��������, ��������� ���
//!          ����������, ���������� � ����� ������������� SIZEARR(). ��. ������ ����.
//!
//! @usage @code
//!          void test()
//!              {
//!              // ������ ����� �������, ���� � �� ������, �� ����� ���� ������������� ���������
//!              // ������������ ��� ���������� ���������. �� ����� 4 (������ ��������� POINT).
//!
//!              POINT coord[] = { {110, 110}, {120, 120}, {130, 110}, {140, 120} };
//!
//!              // ����� ������ ������� �������� ��� ����������, �.�. �� ��� ��������� ��� ��.
//!
//!              for (int i = 0; i < sizearr (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!
//!              DrawLines1 (coord);                  // ������� �������� ������ ��� �������� �������.
//!              DrawLines2 (coord, sizearr (coord)); // ���������� �������� ������� �������.
//!
//!              DrawLines3 (coord);                  // � ��������, ����� � ���, �� ��� ������� �������.
//!              }
//!
//!          // ������� DrawLines1 � DrawLines2 ���������� ���:
//!
//!          void DrawLines1 (const POINT coord[])
//!              {
//!              // ������� � �� ���������� ��� ��������� �� ������ �������. �������:
//!              // 1) sizearr ����� ������ ������ ����������, � �� ����� ����� �����.
//!              // 2) SIZEARR ����� ������� ��������� ������, ��� ������� ����, ��� ������ ����������,
//!              //      �.�. �� ����� ����� sizeof (POINT*) / sizeof (POINT) == 4/8 == 0, ��� ������
//!              //      �������������� ���������� ������� ������� ����������.
//!
//!              for (int i = 0; i < sizearr (coord) - 1; i++)
//!                  txLine (coord[i].x, coord[i].y, coord[i+1].x, coord[i+1].y);
//!              }
//!
//!          void DrawLines2 (const POINT coord[], int n)
//!              {
//!              // ����� ������ �������� ��� �������� n, ��� ��� ��� ������. ���������� ������� (�������
//!              // test) ��������� ��������� ��� � �������� ������� DrawLines2, ������� �� ����������.
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

#define sizearr( arr )  ( sizeof (get_size_of_an_array_with_unknown_or_nonconst_size_ (arr)) )

//! @cond INTERNAL
//  See explanation here: http://blogs.msdn.com/b/the1/archive/2004/05/07/128242.aspx

template <typename T, size_t N> char (&get_size_of_an_array_with_unknown_or_nonconst_size_ (T (&) [N])) [N];  // ;=P

//  Another approach

#if defined (_TX_CPP11_MSVC15)
template <typename T, size_t N> constexpr size_t countof (const T (&) [N] ) { return N; }
#endif

//! @endcond

#define SIZEARR( arr )  ( sizeof (arr) / sizeof ((arr)[0]) )

//! @}
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��������� �����
//!
//! @param   range  ������ ������� ��������� (@b �� ������� ���� �������).
//!
//! @return  ��������� ����� ����� � ��������� [0; range).
//!
//!          �� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//!
//! @warning ��� ������� ����� �������. @strike Just because it can. @endstrike ������ ��� ��� �� ����� ��������� �++
//!          ��� Windows, � ������� �� TXLib'�. ���� ��� ��� �� ��������, �� ������ �������� �� ����, � �������
//!          ����������� ������� rand() � �������� ������� �� ������� %. ���������: rand() % range.
//!
//! @usage @code
//!          char message[100] = "Maybe...";
//!          sprintf (message, "You SUDDENLY got %d bucks now. But note that tax rate is $%d.", random (100), 100);
//!          txMessageBox (message, "Lottery");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline int random (int range) tx_deprecated;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ��������� �����
//!
//! @param   left   �����  ������� ��������� (@b ������� ���� �������).
//! @param   right  ������ ������� ��������� (@b ������� ���� �������).
//!
//! @return  ��������� ����� ����� � ��������� [left; right].
//!
//!          �� ��� ��� �������, ��� �������� ������ �������� � ����������� ����������? :)
//!
//! @warning ��� ������� ����� �������. @strike Just in case. @endstrike ������ ��� ��� �� ����� ��������� �++
//!          ��� Windows, � ������� �� TXLib'�. ���� ��� ��� �� ��������, �� ������ �������� �� ����, � �������
//!          ����������� ������� rand() � ��������� @strike ������� @endstrike ����� � �������� �� RAND_MAX �
//!          @strike ������������ @endstrike ��������� ���������.
//!
//! @usage @code
//!          int money = random (-100, +100);
//!          if (money < 0)
//!              {
//!              char message[100] = "Maybe...";
//!              sprintf ("��������� � �������? ������� ���� � %d ������", -money);
//!              txMessageBox (message, "������!");
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline double random (double left, double right)                tx_nodiscard tx_deprecated;

inline double random (std::nomeow_t, double left, double right) tx_nodiscard;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������, ��������� �� �������� � ������ ���������� ��������� [a; b]
//!
//! @param   x  ����������� ��������.
//! @param   a  �����  ������� (������������).
//! @param   b  ������ ������� (������������).
//!
//! @return  ���� a \<= x && x \<= b, �� ������, ���� ��� -- ����.
//!
//! @warning ��� ������� ����� �������. @strike Because cats are power! @endstrike ������ ��� ��� �� ����� ���������
//!          �++ ��� Windows, � ������� �� TXLib'�. ���� ��� ��� �� ��������, �� ������ �������� �� ����, ���������
//!          �����������.
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
inline bool In (Tx x, Ta a, Tb b)                tx_nodiscard tx_deprecated;

template <typename Tx, typename Ta, typename Tb>
inline bool In (std::nomeow_t, Tx x, Ta a, Tb b) tx_nodiscard tx_deprecated;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������, ��������� �� ����� pt ������ �������������� rect
//!
//! @param   pt    ����������� ����� � ���� <tt> POINT {x, y} </tt>.
//! @param   rect  �������������     � ���� <tt> RECT  {left, top, right, bottom} </tt>.
//!
//! @return  ��������� ��������.
//!
//!          ������ ��� ���������� �������� ������, ���������� �������� ����.
//!
//! @warning ��� ������� ����� �������. @strike Because cats are always right. @endstrike ������ ��� ��� �� �����
//!          ��������� �++ ��� Windows, � ������� �� TXLib'�. ���� ��� ��� �� ��������, �� ������ �������� �� ����.
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

inline bool In (const POINT& pt, const RECT& rect)       tx_nodiscard tx_deprecated;

inline bool In (const COORD& pt, const SMALL_RECT& rect) tx_nodiscard tx_deprecated;

//! @}
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������������ �� ���� �����
//!
//! @param   a  ����   �� ����� :)
//! @param   b  ������ �� ����� :)
//!
//! @return  ������������ �� ���� ����� a � b.
//!
//! @warning ��� @b ������, � ��������� @c a � @c b ����� ����������� � ��� ��� ����. ������� �� ����������� � ���
//!          �������� �������� @c ++, @c --, @c += � �.�. ��������, @b �� ������ ���: <tt>int m = MAX (++x, y += 2);</tt>
//!
//! @see     MIN()
//!
//! @usage @code
//!          if (MAX (3, 7) != 7) printf ("Your CPU is broken, throw it away.");
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define MAX( a, b )     ( ((a) > (b))? (a) : (b) )

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ����������� �� ���� �����
//!
//! @param   a  ����   �� ����� :)
//! @param   b  ������ �� ����� :)
//!
//! @return  ����������� �� ���� ����� a � b.
//!
//! @warning ��� @b ������, � ��������� @c a � @c b ����� ����������� � ��� ��� ����. ������� �� ����������� � ���
//!          �������� �������� @c ++, @c --, @c += � �.�. ��������, @b �� ������ ���: <tt>int m = MIN (x--, y /= 2);</tt>
//!
//! @see     MAX()
//!
//! @usage @code
//!          if (MIN (3, 7) != 3) printf ("Your CPU is still broken, throw it away twice.");
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define MIN( a, b )     ( ((a) < (b))? (a) : (b) )

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����� �� ������
//!
//! @param   x  �����. @strike � �� ��� ������? @endstrike
//!
//! @return  ����������� �����, ��������������� � ��� @c long.
//!
//! @usage @code
//!          double weight = 5.5;        // 5.5 kilos is the weight of Maru the Cat in 2012.
//!          long Maru = ROUND (weight); // Should use ROUND() because Maru is so round. And long.
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L  // MSVC: C99 case

    #define ROUND( x )  ( (long) round (x) )

#else

    #define ROUND( x )  ( (long) floor ((x) + 0.5) )

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������������ �������������� �����������
//!
//! ���������� ��������� ��������������� ������������, ������� _fpreset() � �������� ��������� ���������� ������������
//! ��� ��������� ���������� (_EM_INVALID), �������������� (_EM_DENORMAL), ������� �� ���� (_EM_ZERODIVIDE), ������������
//! (_EM_OVERFLOW) � ���������������� (_EM_UNDERFLOW). ������� ����� _fpreset() ��� ���������� ���������, � ����������
//! ���� �������������� ������ ����� ��������� �������������.
//!
//! ���� �� ������ ������������� ��� ����������, ��������� ������� _fpreset(), � ����� ���������� ��������� ����������
//! �� ������������� ���� �� � ������� std::isfinite (x).
//!
//! @note    ��������� TXLib �� ��������� -- @b ��������� ���� ���������� � �� @b �������� TXLib'�� � ���� @b ������. @nn
//!          ��. [1] <a href=http://books.google.ru/books?id=uwgNv8VlNPgC&pg=PA343>������ ������ � ����� ������������,</a>
//!              [2] <a href=http://www.gamasutra.com/view/news/169203/Exceptional_floating_point.php>������ � ���.</a>
//!
//! @usage @code
//!          tx_fpreset();
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

void tx_fpreset();

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����� ��
//!
//! @usage @code
//!          if (txPI == 1) txMessageBox ("�� ������ � ������ ���������.", "�����������", MB_ICONSTOP);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

const double txPI = asin (1.0) * 2;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   <i>����� �������</i> ���������� ����� � �������.
//!
//! @param   x  ����� ��� ���������� � ����. (����? (Who?))
//!
//! @return  �������, ���������� ����� ���������� � ���� �����, ��������� ��� ���������� � �������.
//!
//! @note    ��� ������, ��� <b> �� ���� </b> ������ ���: txSqr() -- ������� � "��������� �������". ������ �����������
//!          ��, ��� ����� �������� � ������� ��������� �� ���������� <small> (�� ������ ��� �������, � ������ ���������),
//!          </small> ������ ����, ����� ������ ���������� ��� ����, ��� ��� ������� ��������. ����� ��� ���� �������������
//!          ����������� txSqr() ��� ������-������ ������� ����, �������� � �����. ������, �������, ��������� �����������.
//!          ��. � �������� ������ ��� ���� ���������� �������.
//!
//! @usage @code
//!          printf ("\n" "������\t\t" "������� �����\n\n");
//!
//!          for (double r = 100; r > 0; r--)
//!              {
//!              printf ("%6.2lf...", r);
//!
//!              double square = M_PI * txSqr (r);  // ������� �������� ��� �������!
//!              printf ("\b\b\b   \t");
//!
//!              printf ("%-.2lf\n", square);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

inline double txSqr (double x)
    {
    double sqr = pow (sqrt (x) * sqrt (x), sqrt (4.0));  // ������ �������������� ������������

    char str[1024] = "";
    _snprintf_s (str, sizeof (str), "���������� ���� %g!" "!!" "!!" " �� ����????", sqr);
    txMessageBox (str, "������� �����!" "!!", MB_ICONEXCLAMATION | MB_YESNO) != IDNO ||
        (
        txMessageBox ("����...", "� � ��� ���������", MB_ICONINFORMATION),
        txMessageBox ("���� � �� ���", "���� ��...",  MB_ICONSTOP),
        exit (EXIT_FAILURE), 0
        );

    txNotifyIcon (1, NULL, "\n%s\n", "������ ����������!  \0"  // � ��� ��� ��������, �?
                                     "� ��� �����...      \0"  //
                                     "� ��� ������������  \0"  //       � ��� ��� �����
                                     "������� - ����������\0"  //       ������������?..
                                     "����������, �� ���� \0"
                                     "��� �� ��� ��������?\0" + GetTickCount() % 6 * 21);

    return sqr;  // ��� �� ������ ��������. �� �� �� �����
    }

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   <i>�� ������ <b>�����</b> �������</i> ������.
//!
//! @warning ��� ��� ���� ������, ��� <b> �� ���� </b> ������ ���. @nn
//!          ������ ��������� ���: @nn
//!          <tt> \#define z 0 </tt> @nn
//!          ������������� ������! ������ �� ���� ���������� � ��������� ����� ������. :((
//!
//! @note    (����������� @c \#undef. � @c <http://www.google.ru/search?q=%23undef>\#undef</a> ���� ��������� ������
//!          ������ � �����������.)
//!
//! @usage @code
//!          #define _TX_DESTROY_3D
//!          #include "TXLib.h"
//!
//!          // � ������ ���������� �������� ���������� z ��� ������� 3-D ��������� x, y, z:
//!
//!          int z = 0;  // ��! TXLib ���������� ������������! ����� �����. :=/
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define _TX_DESTROY_3D
#endif

#if defined (_TX_DESTROY_3D)

    #define z  0                   // ������� "����������" �������!

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   <i>��� ������� ��������.</i>
//!
//!          @c please  ����������� ����������� ��������� ���������� ����*.
//!
//!          @c meow -- ...������ ��� :)
//!
//! @note    <small>* ��� ����� :)</small>
//!
//! @usage @code
//!          #include "TXLib.h"
//!
//!          int x = rand() meow   // ��� �� ��� �������?
//!          int y = rand() meow
//!          if (x+y > RAMD_MAX/2) please x = y = 0;
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
//! @{

#define please

#define meow   ;

#if defined (_MSC_VER) && !defined (_CLANG_VER)
#define ���    meow
#endif

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� �����, �� ������� �������������
//!
//! @param   type  ��� ����.
//!
//! @return  �������� ���� @p type, ������������� ������������������ �� ��������� (��� ���������� ����� -- �����).
//!
//! @usage @code
//!          void f (POINT p);
//!          ...
//!
//!          POINT z = {}; f (z);  // ��� ��� ZERO
//!
//!          f (ZERO (POINT));     // ��� � ZERO
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define ZERO( type )    zero <type> ()

//! @cond INTERNAL
template <typename T> inline T zero() tx_nodiscard;
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   �������������� ����� ������� ��� ���������� ������ ������� (������ @c __finally)
//!
//! @param   func  ���� ������������� ���������� ������� (�������� ������ �� �����������).
//!
//! @note  - @a ��� ���������� ���������� ������� ����������� � ����������� ������� ������� �� ������.
//!        - �� �������� � ���� @a �� �����������. ����������� ������ ���� ���������� �������.
//!        - �������: tx_finally
//!
//! @see     txAutoLock
//!
//! @usage @code
//!          void some_func()
//!              {
//!              int x = 1;
//!              tx_auto_func ($(x));                      // Will be printed at return
//!
//!              FILE* f = fopen (__FILE__".o.txt", "w");
//!              tx_auto_func (fclose (f));                // Will be closed at return
//!
//!              fprintf (f, "start: x = %d\n", x);        // Do some job
//!              x = 2;                                    // Do some job
//!              }
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------
//! @{

#define  tx_auto_func(    func )  _tx_auto_fun1 ( __LINE__, func )
#define _tx_auto_fun1( n, func )  _tx_auto_fun2 ( n,        func )
#define _tx_auto_fun2( n, func )  auto _tx_auto_func_##n = _tx_auto_func ([&]() { func; })

#define tx_finally(...)           tx_auto_func (__VA_ARGS__)

template <typename T>
struct _tx_auto_func_
    {
    typedef _tx_auto_func_<T> this_t;
    T func_;

    explicit _tx_auto_func_ (T func) : func_ (func) {}
            ~_tx_auto_func_ ()       { func_ ();     }

    private:         _tx_auto_func_ ()              _tx_delete;
                     _tx_auto_func_ (const this_t&) _tx_delete;
             this_t& operator =     (const this_t&) _tx_delete;
    };

template <typename T>
_tx_auto_func_<T> _tx_auto_func  (T   func)
    {
    return        _tx_auto_func_ <T> (func);
    }

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ������������ ������� assert(), � ������� ��������� ����� txMessageBox(), ������� � OutputDebugString().
//!
//! @param   cond  ������� ��� ��������.
//!
//! @return  �� ����������.
//!
//!          ���� �������, ����������� TX_ASSERT(), �������, �� ������ ������ �� ������. @n
//!          ���� ������� ����������� �����, �� ��������� ��������������� ��������� � ��������� �������� �����������.
//!
//! @warning <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) TX_ASSERT ������������ � ������ ��������.</b> @n
//!          �� ���� �������� � TX_ASSERT() ��� � assert() ��������, ������� ����� ��� ������ ���������!
//!
//! @note    ���� ������� @c cond ����� ���� ��������� ��� �� ����� ���������� ��� ������, ���������� �����
//!          ������������ �� ���� (��� � ������� �� 0).
//! @note    <small>See: <a href=http://lars-lab.jpl.nasa.gov/JPL_Coding_Standard_C.pdf> "JPL Institutional Coding
//!          Standard for the C Programming Language", Jet Propulsion Laboratory, California Institute of Technology,
//!          JPL DOCID D-60411, Ver. 1.0, March 3, 2009</a>, page 15.</small> @nn
//!
//! @note    ����������� ������ assert() ���������������� ���, ��� ���������� ������������ TX_ASSERT().
//!
//! @warning ��� �� ����� assert(), ��� ��� ���� �� ������!
//!
//! @see     asserted, verified, verify(), TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox(),
//!          txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          TX_ASSERT (0 <= i && i < ARRAY_SIZE);
//!          assert    (0 <= i && i < ARRAY_SIZE);  // �� �� �����, ��� � TX_ASSERT
//!
//!          FILE* input = fopen ("a.txt", "r");
//!          TX_ASSERT (input);
//!          assert    (input);                     // �� �� �����, ��� � TX_ASSERT
//!
//!          // ���� ����� fgets() �� ����� �������� � ������ Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          // ����� ��� ����� ���������:
//!          bool ok = (fclose (input) == 0);
//!          TX_ASSERT (ok);
//!          assert    (ok);                        // �� �� �����, ��� � TX_ASSERT
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #undef  TX_ASSERT
    #define TX_ASSERT( cond ) _txNOP ( !(cond)? (TX_ERROR ("\a" "��������: ���������� ������: " \
                                                           "�������, ��� \"%s\"." TX_COMMA #cond), 1/(int)!!(cond)) : 1 )
#else
    #undef  TX_ASSERT
    #define TX_ASSERT( cond ) ((void) 1)

#endif

#ifdef assert
    #undef assert
#endif

#define assert( cond )        TX_ASSERT (cond)

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ��������������� ��������� � ������ �������� ��� ������� ����������.
//!
//! @return  ������ 0.
//!
//!          ���������� ����� ������� assert(), �� �������� � ������ Release ���������� ���������.
//!
//! @note    <b>��������������, ��� �������� � ������ �������� ���������� 0 ��� false.</b> @n@n
//!          <b>��� ���������� � ������ Release (��� ���� ��������� NDEBUG) asserted ������������ � ������ �����.</b>
//!
//! @see     assert(), verify(), verified, TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox(),
//!          txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          FILE* input = fopen ("a.txt", "r"); assert (input);
//!
//!          // ���� ����� fgets() ����� �������� � ����� ������:
//!          fgets (str, sizeof (str) - 1, input) asserted;
//!
//!          // ���� ����� fgets() �� ����� �������� � ������ Release:
//!          assert (fgets (str, sizeof (str) - 1, input));
//!
//!          (fclose (input) != 0) asserted;
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define asserted          || TX_ERROR ("\a" "��������� ������� ��� ������ ���������.")

#else
    #define asserted          || _txNOP (0)

#endif

#define verified              asserted  //!< For compatibility with assert macro

//! @cond INTERNAL
#define TX_NEEDED             asserted  //!< For compatibility with earlier releases
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ������� (��������� ���������) � ��������� ���������.
//!
//! @param   expr  ������� (���������).
//!
//! @return  1, ���� ��������� @p expr �������, ����� 0.
//!
//!          ���� �������, ����������� verify(), �������, �� ������ ������ �� ������. @n
//!          ���� ������� ����������� �����, �� ��������� ��������������� ��������� � ��������� �������� �����������.
//!
//! @note    �������� ������� ���������� assert(), �� ��� ���������� � ������ Release (��� ���� ��������� NDEBUG)
//!          verify @b �� ������������ � ������ ��������.
//!
//! @see     verified, assert(), asserted, TX_ERROR(), TX_DEBUG_ERROR(), txOutputDebugPrintf(), txMessageBox(),
//!          txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          FILE* input = verify (fopen ("a.txt", "r"));
//!
//!          // ���� ����� fgets() ����� �������� � ������ Release:
//!          verify (fgets (str, sizeof (str) - 1, input));
//!
//!          // ����� ��� ���� ����� ���������:
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
//! @brief   ������� ����������� ��������������� ���������.
//!
//! @param   msg  ��������� � ������������ ����������� ���������� � ����� ������� @c printf().
//!
//! @note    ���� ������ ����� ������������� ���� ������� ������� � �������. �� ����� ������ ��. ��������� � �������
//!          txStackBackTrace() � ������ @ref TXLibSetup "��������� ����������", �.4.
//!
//! @return  ������ false.
//!
//! @see     _, TX_COMMA, assert(), asserted, verify(), verified, TX_DEBUG_ERROR(), txOutputDebugPrintf(),
//!          txMessageBox(), txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          TX_ERROR ("�� ���� ��������� '����� � ���'. ������� %d: �� ����� '%s'", reasonNum, fileName);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (FOR_DOXYGEN_ONLY)
    #define TX_ERROR( ... )   _txError (__FILE__, __LINE__, __TX_FUNCTION__, 0, ##__VA_ARGS__)
#else
    #define TX_ERROR( msg )   _txError (__FILE__, __LINE__, __TX_FUNCTION__, 0, msg)
#endif

//! @cond INTERNAL
    #define TX_THROW          TX_ERROR  //!< For compatibility with earlier TXLib releases
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������� ����������� ��������������� ��������� � ���������� ������.
//!
//!          �������� ��. � TX_ERROR.
//!
//! @note    � ������ Release ���� ������ �� ������� ������.
//!
//! @see     _, TX_COMMA, assert(), asserted, verify(), verified, TX_ERROR(), txOutputDebugPrintf(),
//!          txMessageBox(), txNotifyIcon(), txStackBackTrace(), __TX_FILELINE__, __TX_FUNCTION__
//!
//! @usage @code
//!          TX_DEBUG_ERROR ("��� � �� ���� ��������� '����� � ���'. ������� %d: ������� '%s'", reasonNum, fileName);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#if !defined (NDEBUG)
    #define TX_DEBUG_ERROR(...)  TX_ERROR (__VA_ARGS__)

#else
    #define TX_DEBUG_ERROR(...)  ((void) 0)

#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� ���� ������� ������ � �������.
//!
//! @param   address  ����� ������ ����������.
//! @param   pause <i>������ �� ����� � ����� ����������. �������������.</i>
//! @param   name  <i>�������� ���������� (��������� �� 8 ��������). �������������.</i>
//!
//! @note    ��������������� ������� ������ �������� 256 ����.
//!
//! @see     txStackBackTrace(), TX_ERROR(), TX_DEBUG_ERROR()
//!
//! @usage @code
//!          const char text[] = "������� ������� -- � �������� �� �������";
//!          txDump (text);
//!
//!          SetConsoleOutputCP (437);    // ����� ������������ �������������, �� �� ������� �����
//!          txDump (text);
//!          SetConsoleOutputCP (1251);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
void txDump (const void* address, const char name[] = "_txDump()", bool pause = true);
#endif

//! @cond INTERNAL

#ifdef _MSC_VER
#define txDump( ... )           _txDump ((const void*)(uintptr_t) __VA_ARGS__)
#else
#define txDump( address, ... )  _txDump ((const void*)(uintptr_t) (address), #address, ##__VA_ARGS__)
#endif

void _txDump (const void* address, const char name[] = "_txDump()", bool pause = true);

//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� ������� ���� ������� ������� � �������.
//!
//! @warning ��� ���������� ������ ���� �������� ��������� ������, ������� ����� ���������� (�����������)
//!          � ����� Windows. ��. ������ @ref TXLibSetup "��������� ����������", �.4.
//!
//! @note    ��� �������� ���������� ������ ���� ������� ��������� ���������� ����������� ��� ����������. ��������,
//!          ��� ����������� GCC @c g++ -- � ������� ����� ��������� ������ @c -O0. ������ ����� ����������������
//!          ��������� ������ ��� ����� ��-�������, ��������, � CodeBlocks ����� ������� ���� -- Settings --
//!          Compiler -- (Global Compiler Settings) -- (Compiler Settings) -- Other Options.
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
//! @brief   ����������� �������������� ��� �++ � �������� ����.
//!
//! @param   mangledName  �������������� (mangled) ���.
//!
//! @return  ������ � ������ ��������� ����.
//!
//!          <a href=http://en.wikipedia.org/wiki/Name_mangling#Simple_example>��� ����� ������������� ����
//!          (name mangling) ��. �����.</a>
//!
//! @warning ���� ������������ ����� �������, ������������ @c char*, �� ������ <b>����</b> ���������� ������,
//!          ���������� �������, � ������� ������ @c free(), ����� ����� ������ ������.
//!
//! @see     txDump(), txStackBackTrace(), TX_ERROR(), TX_DEBUG_ERROR()
//!
//! @usage @code
//!          auto type = txDemangle (typeid (std::string) .name());
//!          std::cout << "The real type of std::string is: " << type << ", muahhaha! :)\n";
//!
//!          std::cout << "Call is shorter, but result is the same: " << txTypename (std::string) << ", muahhaha, too.\n";
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
//! @{

std::string txDemangle (const char* mangledName);
char*       txDemangle (const char* mangledName, std::nomeow_t);

#define txTypename(value)     txDemangle (typeid (value) .name()) .c_str()

//! @}
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ���������� �� ������� Windows.
//!
//! @param   keyName    ��� ����� ������� (��. ����)
//! @param   valueName  ��� ��������� �����
//! @param   value      �����, � ������� ������������ ��������
//! @param   szValue    ������ ������
//!
//! @return  ���������� ����, ���������� � ����� @strike ��� ������ @endstrike �� ��������� value
//!
//! @note    ��� ����� ������� @c keyName @b ����������� ������ ���������� c ����� ��� ����������� ������ �� ��������:
//!
//! @table   @tr <b>�����������</b> @td <b>���� �������</b>
//!          @tr @c HKLM            @td @c HKEY_LOCAL_MACHINE
//!          @tr @c HKCU            @td @c HKEY_CURRENT_USER
//!          @tr @c HKCR            @td @c HKEY_CLASSES_ROOT
//!          @tr @c HKU             @td @c HKEY_USERS
//!          @tr @c HKCC            @td @c HKEY_CURRENT_CONFIG
//!          @endtable
//!
//! @usage @code
//!          char path[MAX_PATH] = "(not installed)";
//!          txRegQuery ("HKCU\\Software\\TX Library", "ProductDir", path, sizeof (path));
//!
//!          printf ("TX Library is installed in: \"%s\"\n", path);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

int txRegQuery (const char* keyName, const char* valueName, void* value, size_t szValue);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������, ����������� �������� ���������� ����� ���������� � �����-���� ������ ������.
//!
//! @note    <b>������ ������������� � ������ TX_COMMA ������ ���������������� � �������.</b>
//!
//! @see     TX_ERROR(), TX_DEBUG_ERROR()
//!
//! @usage @code
//!          TX_ERROR ("������� ����� �����: ����� '����� � ���', ���� '%s', ������ %d" _ fileName _ lineNum);
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------
//! @{

#define _                     ,
#define TX_COMMA              ,  //!< ������� ������� _ (@ref _ "������ �������������")

//! @}

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Back-hole (I hope, not an ass-hole:) of the library)
//! @name    ����� ��������� �������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� �������������� ������� ��������� ������� ��������� Windows (������� �������) ��� ����
//!          TXLib.
//!
//! @param   wndProc <i>����� ������� ������� ���� TXLib. @n
//!                     ���� �� ������� ��� NULL, �� ������� �������������� ������� ������� ��������� � ���������������
//!                     �����������.</i>
//!
//! @return  ����� ���������� ������� ������� ��� ���� TXLib.
//!
//!          �������� ������� ������� ����� ���������� @b �� ��������� ������� ���������� TXLib.
//!          ��� ������ ���� �������� �� ��������� ����������:
//! @code
//!          LRESULT CALLBACK NewWndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam);
//! @endcode
//!
//! @warning ������� ������� ����� ���������� �� ���������������� (�������) ������, ������������ @ref
//!          txCreateWindow(). ��� @b �� ��� �� ����� �����, � ������� ����������� main(). � ����� � ���� ������
//!          ����������� ��� ������ � ����������� ����������� ��� �� ���������, �.�. ����� ���������� "�����
//!          �������" (race condition).
//!
//! @warning ���� ������� ������� ������ ��������, �� ������ 0, �� ����������� ��������� ��������� ���������� TXLib
//!          @b �� ����� �����������. ��-�� �����, ��������, ���� ���� �� ������ ��������� ���������. ��������
//!          ��������� ��������� � ������� Alt-Ctrl-Del �� ���������� �����, ��� �� ����� ������������ ����������
//!          <a href=http://technet.microsoft.com/en-us/sysinternals/bb896653.aspx> Process Explorer</a>. ���� ��
//!          ������ �� ���� ��������� ������� ���������, ������� �� �� �������� Win32 (��. MSDN), ������� �����
//!          DefWindowProc().
//!
//! @note    ��������� �������� ������� ������� ����� � ������� ������� SetWindowLong ��� SetWindowLongPtr:
//! @code
//!          WNDPROC OldWndProc = (WNDPROC) SetWindowLongPtr (txWindow(), GWL_WNDPROC, (LONG_PTR) NewWndProc);
//! @endcode
//!          ��� ���� ���� ����������� ������ �������� ������ ������� ������� � ������� CallWindowProc, (��. MSDN),
//!          ����� ����������� ����� ������ �� ����������, ��� ������� ����.
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
//!              POINT sz = txGetExtent();
//!
//!              txSelectFont ("Lucida Console", 30, 15);
//!              txDrawText (0, 0,      sz.x, sz.y, "MOV txWindow, eax [please]");
//!
//!              txSelectFont ("Lucida Console", 15, 7.5);
//!              txDrawText (0, sz.y/2, sz.x, sz.y, "(Info for the cats: NO MOUSE HERE)");
//!
//!              return 0;
//!              }
//!
//!          LRESULT CALLBACK MyWndProc (HWND window, UINT message, WPARAM wParam, LPARAM lParam)
//!              {
//!              if (message == WM_MOVE)
//!                  txMessageBox ("  I like to MOVe it, MOVe it", "TXLib 2 Real", MB_ICONINFORMATION);
//!
//!              if (message == WM_SETCURSOR && LOWORD (lParam) == HTCLIENT)
//!                  {
//!                  SetCursor (NULL);
//!                  return true;
//!                  }
//!
//!              static int i = 0;
//!              if (i++ % 15 == 0)
//!                  {
//!                  char str[2] = {"-\\|/" [i/15 % 4]};  // �����������������
//!                  SetWindowText (txWindow(), str);
//!                  }
//!
//!              return 0;  // ���������� ��������� ��������� ���������� TXLib
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

WNDPROC txSetWindowsHook (WNDPROC wndProc = NULL);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������ (��������� ���������).
//!
//! @param   wait <i>������� ����� ����������� ���� ��������������� �������. ���� �� �������, �� "�������".</i>
//!
//! @return  ��������� ����������.
//!
//!          ����� ������� ����� ������� Win32 GDI ���������� ������������� ����� �������� txLock() � �����
//!          �������������� � ������� txUnlock(). ��� ������� � ���, ��� ���������� ����������� ���� (��� ���, ���
//!          ����� Win32: ��������� ��������� WM_PAINT) � ���������� TXLib ���������� � ��������� ���������������
//!          ������. ������� ����������� ��� ������ -- ��� ��������������� ������ ���� �� �����������.
//!
//!          txLock() ���������� EnterCriticalSection(), � ��������� ���������������� �����, ����������� ����, ���
//!          ��� ������� ����������� ������. ����� ���������� ��������� ������� ���������, ���� ���������
//!          ����������� �� �������� ������������ � ����������������. ������ ����� �������� txSleep() ��� Sleep()
//!          ��� ��������������� ������.
//!
//!          txLock() / txUnlock() -- ��� �������������� ��������. �� ���������� �� ����� �������� ����������������
//!          ��������� txBegin() / txEnd() / txUpdateWindow(), ������� �� ���������������� �����, � ������
//!          ��������� �������������� ���������� ���������� ����.
//!
//! @see     txDC(), txVideoMemory(), txLock(), txUnlock(), txGDI()
//!
//! @usage   ��. �������� ����� ������� _txCanvas_OnPAINT() � _txConsole_Draw() � TXLib.h.
//}----------------------------------------------------------------------------------------------------------------

bool txLock (bool wait = true);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������������� ������
//!
//! @return  ��������� ���������� (������ false).
//!
//!          ����� �������� ��. � �������� txLock().
//!
//! @see     txDC(), txVideoMemory(), txLock(), txGDI()
//!
//! @usage   ��. �������� ����� ������� _txCanvas_OnPAINT() � _txConsole_Draw() � TXLib.h.
//}----------------------------------------------------------------------------------------------------------------
//! @{

bool txUnlock();

//! @cond INTERNAL
template <typename T> inline T txUnlock (T value);
//! @endcond

//! @}

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����� ������� Win32 GDI � �������������� ����������� � ��������������.
//!
//! @param   command  ������� GDI (��������, ������������ ��������).
//! @param   dc       ���������� ��������� ��������� (������), �������������� � ������ ������� GDI (��. ��������
//!                   @c command).
//!
//! @return  ��������, ������������ ���������� �������� GDI.
//!
//! @note    ���� �������� dc ������������� ��������� ������ TXLib (��������� � ������������ ��������� txDC()),
//!          �� �� ����� ���������� ������� GDI �����, ����������� ���� TXLib, �����������. @n
//!
//! @note    ���� � ������ ������� GDI ������������ �������, �� ����������� ������� ������, ����� ��������� ����
//!          ��������, ��� ��� txGDI() ��� ��� �� ������.
//!
//! @see     txDC(), txVideoMemory(), txLock(), txUnlock()
//!
//! @usage @code
//!          txGDI (( Rectangle (txDC(), x1, y1, x2, y2) ));  // �� �������� ��� ��� ((���)) ������
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define txGDI( command, dc )  ( ((dc) == txDC())? txUnlock ( (txLock(), (command)) ) : (command) )

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����� ������� �������� ������� � ������ ����������� ���������� �++.
//!
//! @param   codepage  <i>����� ����� ������� �������� �������. ���� �� �������, �� 1251.</i>
//! @param   locale    <i>����� ������ (���������� � �����) ����������� ���������� �++.
//!                       ���� �� �������, �� "Russian" ��� "ru_RU.CP1251".</i>
//! @param   wLocale   <i>����� ������ ����������� ���������� �++ ��� wide character funstions.
//!                       ���� �� �������, �� L"Russian_Russia.ACP".</i>
//!
//! @return  ����� ������ ������� �������� �������.
//!
//!        - <a href=http://www.google.com/search?q=windows+console+code+page+identifiers>������ ������� ������� �������</a>
//!        - <a href=http://www.google.com/search?q=C%2B%2B+locale+name+list>             ������ ���� ������� C++</a>
//!
//! @warning ���� ��������������� ������� �������� �� 1251, �������� ��������� � ������ ��������� ������� C++
//!          � ������ ������ � �������.
//!
//! @see     txClearConsole(), txSetConsoleAttr() � ������ ���������� �������, txReopenStdio()
//!
//! @usage @code
//!          txSetLocale (866, "Russian_Russia.866", L"Russian_Russia.866");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifndef   FOR_DOXYGEN_ONLY

const int     _TX_CODEPAGE  =   1251;

#ifndef __CYGWIN__
const char    _TX_LOCALE[]  =  "Russian";
#else
const char    _TX_LOCALE[]  =  "ru_RU.CP1251";
#endif

const wchar_t _TX_WLOCALE[] = L"Russian_Russia.ACP";

#endif

int txSetLocale (int codepage = _TX_CODEPAGE, const char locale[] = _TX_LOCALE, const wchar_t wLocale[] = _TX_WLOCALE);

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Tune-up constants and variables
//! @name    ����������� ��������� � ����������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��� ���-����� TXLib
//!
//!          � ��� ������ ���� @b ����������� ������ ��� ��� ���-�����.
//!
//!          �� ��������� ���� ��������� �� ����� ������ � ����� ����� � ���������� ����������, ����� �� �� ���, ���
//!          � ���� ���������, � ����������� ���������� @c ".log".
//!
//! @note    ������������� ��� ���-����� ���� � ������ ������ ���������, �� ��������� ������ ������.
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

       char _txLogName[MAX_PATH]          = "";

#endif // TX_COMPILED

extern char _txLogName[];

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������ ������ ������������� TXLib
//!
//!          ���� ��������� ���������� � ������� \#define @a �� ��������� TXLib.h � ���������, ������ �������������
//!          (�� ������� ������� @c main) @b �� ����������.
//!
//! @note    ������ ������������� ��������:
//!        - �������� ���� �������,
//!        - ��������� ������� �������� _TX_CODEPAGE (1251) ������� ��� ��������� �������� �����,
//!        - ��������� ������� ������ ����������� ���������� C++ ("Russian" / "ru_RU.CP1251" � L"Russian_Russia.ACP"),
//!        - ����������������� ��������� stdio � iostream �� ������, ���� ���������� �� ������������ ��� ����������
//!          � ���������� �������� ������������������,
//!        - �������� ��������� �������� (������� �� 0, �������������� ������, ��������� �� ��������� ������ � �.�.),
//!        - �������� �������������� ����������,
//!        - ����� ��������� ����������� ����,
//!        - ��������� ������ ����� �� ���������� ���������, ����� ���� ����������� �� �����,
//!        - ���������� ����� ��� ������� �� ���� ����������������, ������������ �������� �� ������� ��� ����. @n
//!
//! @note    ���� ������ ������������� ���������, �� � EXE-����� ��������� ���� TXLib � ������� txCreateWindow(),
//!          �� ���������� ��� ����� ����� ����������������. � @b DLL ������ ������������� ������� @b �� ����������. @nn
//!
//! @note    ������ ������������� �� ��������������� (not thread-safe).
//!
//! @see     txCreateWindow(), _TX_ALLOW_KILL_PARENT, _TX_WAITABLE_PARENTS, _txWatchdogTimeout, _txConsoleMode
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
//! @brief   ����� ����������� ����������� ����. ��������� ����� ����� ������� ShowWindow.
//!
//!          �� ���������: @c SW_HIDE -- �������� ���������� ����.
//!
//! @note    ���������� ��������������� @b �� �������� ���� ����������.
//!
//! @see     _TX_NOINIT
//!
//! @usage @code
//!          _txConsoleMode = SW_HIDE;  // ������ �������� ���������� ����
//!          txCreateWindow (800, 600);
//!
//!          _txConsoleMode = SW_SHOW;  // ������ ���������� ���������� ����
//!          txCreateWindow (800, 600);
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

       int _txConsoleMode                 = SW_HIDE;

#endif // TX_COMPILED

extern int _txConsoleMode;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� ������������ ���� ����������.
//!
//! @note
//!        - ���������� ��������������� @b �� �������� ���� ����������.
//!
//! @usage @code
//!          _txWindowStyle &= ~WS_CAPTION; // FullScreen: ���� ��� ���������, �������� � �����
//!          txCreateWindow (GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN));
//!
//!          printf ("�������� ���� ����� Alt+F4\n");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

       int _txWindowStyle                 = WS_POPUP | WS_BORDER | WS_CAPTION | WS_SYSMENU;

#endif // TX_COMPILED

extern int _txWindowStyle;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� �������
//! @note    ���������� ��������������� @b �� �������� ���� ����������.
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

       const char* _txConsoleFont         = "Lucida Console";

#endif // TX_COMPILED

extern const char* _txConsoleFont;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ������� ������� ������� (��)
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

       unsigned _txCursorBlinkInterval    = 500;

#endif // TX_COMPILED

extern unsigned _txCursorBlinkInterval;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   �������� ���������� ������ (��)
//! @note    ���������� ��������������� @b �� �������� ���� ����������.
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

       unsigned _txWindowUpdateInterval   = 25;

#endif // TX_COMPILED

extern unsigned _txWindowUpdateInterval;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������, ����������� ������������ TXLib ������ � ����������� ����������� <a href=http://sfml-dev.org>SFML</a>
//! @note    ���� ������ �������� @b ����� ���������� TXLib.h � ���������.
//! @usage @code
//!          #define  TX_USE_SFML
//!          #include "TXLib.h"
//!          #include <SFML/Graphics.hpp>
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define       TX_USE_SFML
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� �������� �������� ������� (��)
//}----------------------------------------------------------------------------------------------------------------

#if !defined (TX_TRACE)
    const int _TX_TIMEOUT                 = 1000

#else
    const int _TX_TIMEOUT                 = 5000

#endif

#if  defined  (_TX_USE_DEVPARTNER)
    * 10
#endif
    ;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������� �� �������, ��������� ����������� ��������������� � ���� TXLib �� ����� ��������� WM_PAINT.
//!
//!          ���� ����� NULL, �� ������������ Win32::BitBlt.
//!
//!          �� ������ �������������� �������� ����� ���������, ����� �� �������� �� ���� �������, � �����
//!          TXLib ����� �������� ����������� � ���� ����� ���. ������ � ����, ��� ��� ������� ����� ����������
//!          � ��������� ������.
//!
//!          ��������� ���� ������� �������: "StretchBlt function".
//!
//! @see     txSetWindowsHook(), txBitBlt(), txAlphaBlend()
//!
//! @usage @code
//!          #include "TXLib.h"
//!
//!          bool MySwapBuffers (HDC dest, int xDest, int yDest, int wDest, int hDest,
//!                              HDC src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, DWORD rOp)
//!              {
//!              return txAlphaBlend (dest, xDest, yDest, wSrc-xSrc, hSrc-ySrc, src, xSrc, ySrc, 0.01);
//!              }
//!
//!          int main()
//!              {
//!              _txSwapBuffers = MySwapBuffers;  // That's it
//!
//!              txCreateWindow (800, 600);
//!
//!              txSetFillColor (TX_NULL);
//!              txRectangle (10, 10, txGetExtentX() - 10, txGetExtentY() - 10);
//!
//!              for (int x = 50; x <= txGetExtentX() - 50; x += 20)
//!                  {
//!                  txCircle (x, txGetExtentY()/2, 10);
//!                  txSleep (100);
//!                  }
//!
//!              txSleep (3000);
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

bool (*_txSwapBuffers) (HDC dest, int xDest, int yDest, int wDest, int hDest,
                        HDC src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, DWORD rOp) = NULL;

#endif // TX_COMPILED

extern bool (*_txSwapBuffers) (HDC dest, int xDest, int yDest, int wDest, int hDest,
                               HDC src,  int xSrc,  int ySrc,  int wSrc,  int hSrc, DWORD rOp);

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� ���������� ����������� ��������� ������� TXLib
//}----------------------------------------------------------------------------------------------------------------

const unsigned _TX_BUFSIZE                =  1024,
               _TX_BIGBUFSIZE             = _TX_BUFSIZE *  2,  //!< ������� ������� ����������� �������.
               _TX_HUGEBUFSIZE            = _TX_BUFSIZE * 20,  //!< ������� ����� ������� ����������� �������.

               _TX_STACKSIZE              = 64 * 1024;         //!< ����������� ������ ����� ��� ������� ���������.

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������������ ���������� ���������� � ���������.
//}----------------------------------------------------------------------------------------------------------------

#if !defined (_TX_EXCEPTIONS_LIMIT)
    #define   _TX_EXCEPTIONS_LIMIT        16
#endif

#if !defined (_TX_FATAL_EXCEPTIONS_LIMIT)
    #define   _TX_FATAL_EXCEPTIONS_LIMIT  16                   //!< ������������ ���������� ��������� ����������.
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���� ����������, �� ��������� ������ ��� ���������� ���������� �� ����������� �����.
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define       _TX_FULL_STACKTRACE
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������ ����������� ��������, ������� ���� ������� ������� ����� ���������� �������� TXLib.
//!
//!          ���� ��������� ����������� � ������ � TXLib �������� �� ���, �� ��� ���������� TXLib ��������� ���������
//!          ����� �������. (��� ����������, ���� �� ������� ����������� ���� TXLib, � ���� ������ ���� �������.)
//!
//!          ��������� ����������� �������� ��� �������. ����������� �������� �������� ����������� ���������, �����
//!          ���������. ��� ���������, ������������ � ������� ����� - ����. ������ ��� ������� CLion, ��. �������
//!          _txCleanup() � _txIsParentWaitable() � �������� ������ @ref TXLib.h.
//!
//!          ����� ���������� ����� ���������� TXLib.h � ���������.
//!
//! @see     _TX_ALLOW_KILL_PARENT, _TX_NOINIT, _txCleanup(), _txIsParentWaitable(), _txWatchdogTimeout
//}----------------------------------------------------------------------------------------------------------------

#if !defined  (_TX_WAITABLE_PARENTS)
    #define    _TX_WAITABLE_PARENTS       "Winpty-agent.exe:Clion.exe, "            /* 0: CLion32       */ \
                                          "Winpty-agent.exe:Clion64.exe, "          /* 1: CLion64       */ \
                                          "starter.exe:eclipse.exe, "               /* 2: Eclipse 4     */ \
                                          "starter.exe:javaw.exe, "                 /* 3: Eclipse 3     */ \
                                          "cmd.exe:devenv.exe, "                    /* 4: MSVS 2003+    */ \
                                          "VSDebugConsole.exe:devenv.exe, "         /* 5: MSVS 2019     */ \
                                          "consolepauser.exe:devcpp.exe, "          /* 6: Dev-Cpp       */ \
                                          "cb_console_runner.exe:codeblocks.exe"    /* 7: CodeBlocks 8+ */
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������� �������������� ���������� ���������� ��������, ������ ������� ������ ����� ���������� TXLib.
//!
//!          ����� ���������� ����������� ����� �� ������� �������, ���������� � TXLib, � ����� ����� ����� ������
//!          ���������� �������.
//!
//!          ������ ���������� ��������, ������� ����� ������ ����� �����, �������� � _TX_WAITABLE_PARENTS.
//!
//! @note    ������ ������ ���������� @b ����� ���������� TXLib.h � ���������.
//!
//!          ��. ����� ����������� ���� ��������� � ����� TXLib.h.
//!
//! @see     _TX_WAITABLE_PARENTS, _TX_NOINIT, _txWatchdogTimeout
//!
//! @usage @code
//!          #define _TX_ALLOW_KILL_PARENT false
//!          #include "TXLib.h"
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#if !defined (_TX_ALLOW_KILL_PARENT)            // DISCLAIMER: � �� �������� � �������� ���������.
    #define   _TX_ALLOW_KILL_PARENT       true  //             ��� ����������� ������.
#endif                                          //             �_��� ������� ������.

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ����� ������� �� ���������� ���������, ������� �� ���������� ������� main() ��� �� ������ exit(), � ��.
//!
//!          ���� �������� ������ 0, �� ����� �� ������������.
//!
//! @note    ��� �������������� ��������� ��������� ��� ������ TXLib ��������� ��������� ���������� ����� (watchdog
//!          thread), ������� ������� _txWatchdogTimeout �����������, � ����� ������������� ��������� ���������.
//!
//! @see     _TX_WAITABLE_PARENTS, _TX_NOINIT
//}----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

int            _txWatchdogTimeout         = 10*_TX_TIMEOUT;

#endif // TX_COMPILED

extern int _txWatchdogTimeout;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ������� ��� ��������� ������������� TX Library.
//!
//!          �� ������, ��� ���� @c TXLib.h ����� ������� �, ��� ���������, ����� �������������. ��� ��������� ������
//!          �������� ������ ������������ ������� ���������� ����������, ����� � ������ ������ �� ����, � ���������
//!          <tt>.cpp</tt>-������. � ���� ������, ���� ������� ������ ���� ����� ����, ������������������� �����
//!          ������ ��, � ���������� ���������� ��������� ������ �������������� �� ����� ��������, ��� ������� �������.
//!
//!          ������ ���������� TX Library ������������ ����� ������������ ������������ <tt>.h-</tt>����, � ������������
//!          ����� ���������������� ������ ���, ��� ������ ������. ��� ����������� ��������� ������ � �����������.
//!
//!          ������ ���� @c TXLib.h ������ �������� �� �����, ������� ����� ��-������� ����� ���� ��� ����������.
//!
//!          ���� ��� ���������� @b ����� ���������� ����� @c TXLib.h ��������� ������ @c TX_COMPILED, �� ���������������
//!          ����� ������� ����� �����, ������� ����� �����. ��� ����� �������� ��, ��� ����������� ���� �������� �
//!          ������ ����������: ����������� ��������, �������� � �������, ��������� �������, �������, ������� � ��.
//!          ��� ���� ����� ���� ������ �����, ������� �������� ����������� ����������� �������, �� ����� ���������������.
//!          (������ ������, ��� ���� ���� ������ ������ �� �������� � ������������ �����, ��, ��� ��� ���������� ���������
//!          �� �������� ������������� ����� ��� ��������� ������ � ���, ����� ��� ��� ��������� ���������.)
//!
//!          ����� � ������� ���� �������� ����������������� ����������� ���� ����������� ������� ����������, � ���� �����
//!          �������� ��� ���� ����, ������� � ���� @� TXLib.h � ��������� � ��� ������ @c TX_COMPILING. ��� �������� �
//!          ���������� ����� ����������� ����������, � �� �������� ��� ������ �������� ���� ���������. � ������� ����
//!          ���� ���� ������ @c TXLib.cpp, �� ��� ����� ���� �����. ��� ���������� ����� ����� ����������� �����,
//!          �� ����� �� ���������� ����������� � ����������, ��� ��� ��� ���������� �� ����� ����������, � ����� �����
//!          ������ ������� ����������, �� 1.5 �� 3 ���.
//!
//! @warning �� ������� �������� � ���� ���� ������, ����� �������� @c #define @c TX_COMPILING � @c #include "TXLib.h",
//!          ��� ��� ��� ��������� ����������� ����� ����� ����� ���������������� ����� ��������������� ���, �� ���
//!          ����� ����������� ������� �����.
//!
//!          ����� ��� ��������� ���������� ����� ���������� ������ @c WIN32_LEAN_AND_MEAN @b �� ��������� @c TXLib.h
//!          � ���������.
//!
//! @warning ������ @c WIN32_LEAN_AND_MEAN �������� ������������� ��� ������� ������� @c TX_COMPILED. ���� ��� ���� ��
//!          ����� ����������� �����-���� ���������, ������������ � @c Windows.h (�������, ��������, �������, ��������
//!          � �.�.), �������� � ��������� �����, ������������ ��� ��������, �������.
//!
//! @note    ���� ���������� ������� @c TX_COMPILED ��� @c TX_COMPILING, ��������� ������������ ����, ���������� ������������
//!          ���� @c TX, �� ������������.
//!
//! @usage @code
//!          // ��� ����� ���� ������ ������� � ���� � ��� �� ������ Visual Studio ��� ������ �����
//!          // ���������������� (IDE). ��� ���������� ����� � ������ ����������� ����������� ����� �����
//!          // ����������������.
//!
//!          //-----------------------------------------------
//!          // Main.cpp: ���� � ������� ���������
//!          //-----------------------------------------------
//!
//!          #define   TX_COMPILED   // ����������� ����� �������� #include
//!          #include "TXLib.h"
//!
//!          int main()
//!              {
//!              txCreateWindow (800, 600);
//!              ...
//!              }
//!
//!          //-----------------------------------------------
//!          // TXLib.cpp: ���� ��� ������������� TXLib
//!          //-----------------------------------------------
//!
//!          #define   TX_COMPILING  // ����������� ����� �������� #include
//!          #include "TXLib.h"
//!
//!          // [������ � ���� ����� ������ ���]
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
//! @{

#ifdef FOR_DOXYGEN_ONLY

#define TX_COMPILED

#endif

//! @}

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Internal diagnostics
//! @name    ���������� �����������
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ��������/��������� ���������� ����������� ���������� ���� ����������.
//!
//!          ����������� ���� ����� ������ TX_TRACE, ������� ������������� ����� ������ ���������� (statement).
//!          �� ��������� ����������� ���������.
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(), �� ����� ����� �����������
//!          ���������-���������, ��������, <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DbgView</a>. ��� ����� ��������, ������������� ������ TX_TRACE �� ��������� TXLib.h � ���������.
//!
//! @warning ����������� @b ����� �������� ���������� ���������, �������� ��� ������� � Microsoft Visual Studio.
//!          � ���� ������ ����� ������������ DbgView (��. ����) � ��������� ������������ ��������� ��������,
//!          � �� ��-��� ��������� Visual Studio.
//!
//! @note    _TX_ALLOW_TRACE � TX_TRACE �������� @b ����� ���������� TXLib.h � ���������.
//!
//! @title   ������ �����������: @table
//!          @tr  1  @td  Regular functions
//!          @tr  2  @td  Reserved
//!          @tr  3  @td  Init/Cleanup
//!          @tr  4  @td  Init/Cleanup, misc functions
//!          @tr  5  @td  Error handling, entry points
//!          @tr  6  @td  Error handling, main part
//!          @tr  7  @td  Error handling, misc functions
//!          @tr  8  @td  Canvas worker thread
//!          @tr  9  @td  Reserved
//! @endtable
//!
//! @usage @code
//!          // ��� ��������� ������ ��������� DbgView �� ������� ���������!
//!
//!          #define  _TX_ALLOW_TRACE 1  // ������������ ������ ������� ������� TXLib (������� 1).
//!          #include "TXLib.h"
//!
//!          #define  _DEBUG             // �� ������������, �� �������� ���������� � �������
//!          #include "TXLib.h"          // ������� TXLib ��� ��������� ����������� �����.
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define _TX_ALLOW_TRACE
#endif

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Technical
//! @brief   ���������� ���������� ���� ����� OutputDebugString().
//!
//!          �� ��������� ����������� ������� ����� ������� OutputDebugString(), �� ����� ����� �����������
//!          ���������-���������, ��������, <a href=http://technet.microsoft.com/ru-ru/sysinternals/bb896647%28en-us%29.aspx>
//!          DbgView</a>. ��� "���������" ���� ���� ���� <tt>TX\Dev\DbgView.ini,</tt> ��� ���� ��������� � DbgView
//!          ����� ���� Edit/Filter/Load (Ctrl+L).
//!
//!          � ������� TX_TRACE ����� ������������ ��� ����� ���������� TXLib. ��� ����� ���� ��������� �����������
//!          TXLib, ��������� ������ _TX_ALLOW_TRACE ����� ���������� ����� TXLib.h � ���������. �� ���������
//!          ����������� TXLib ���������.
//!
//!          TX_TRACE ����� �������������� � ���� ���. �����, ���� ����������� ���������� ���������, �� �����
//!          ���������� ����� ����� ������ ����������� ������� TXLib. ����� ����, ��� ����-������ ����� ���������.
//!
//! @usage @code
//!          int main()
//!              {
//!              ...
//!              TX_TRACE;  // ����� DbgView ������ ��� ����� � ����� ����������� ������
//!              ...
//!              }
//! @endcode
//! @code
//!          #define  TX_TRACE  printf (__TX_FILELINE__ "\t" __TX_FUNCTION__ "\n");
//!          #include "TXLib.h"
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#ifdef FOR_DOXYGEN_ONLY
#define       TX_TRACE
#endif

#if !defined (TX_TRACE)
    #define   TX_TRACE  { if (_txLoc::Cur.trace) _txTrace (__FILE__, __LINE__, __TX_FUNCTION__); }
#endif

//! @cond INTERNAL
void _txTrace (const char file[], int line, const char func[], const char msg[] = NULL, ...);
//! @endcond

//{----------------------------------------------------------------------------------------------------------------
//! @{
//! @cond INTERNAL

#ifndef   FOR_DOXYGEN_ONLY

struct _txLoc
    {
    const char*   func;
    const char*   file;
    int           line;

    int           inTX;   // We are inside one of TXLib functions
    int           trace;  // Internal TX trace level, when enabled by _TX_ALLOW_TRACE

    const _txLoc* prev;   // Caller's location

    static _txLoc _tx_thread Cur;
    };

struct _txFuncEntry
    {
    typedef _txFuncEntry this_t;

    _txLoc loc;

    _txFuncEntry() : loc (_txLoc::Cur) { _txLoc::Cur.inTX++; _txLoc::Cur.prev = &loc; }
    void restore()                     { _txLoc::Cur = loc;                           }
   ~_txFuncEntry()                     { restore();                                   }

    private:
            _txFuncEntry (const this_t&) _tx_delete;
    this_t& operator =   (const this_t&) _tx_delete;
    };

#if defined (_GCC_VER)

    inline void __txLocCurSet (const char* _file, int _line, const char* _func)
        { _txLoc::Cur.file = _file; _txLoc::Cur.line = _line; _txLoc::Cur.func = _func; }

#else

    #define __txLocCurSet( _file, _line, _func ) \
        ( _txLoc::Cur.file = (_file), _txLoc::Cur.line = (_line), _txLoc::Cur.func = (_func) )

#endif

#define _txLocCurSet()     __txLocCurSet (__FILE__, __LINE__, __TX_FUNCTION__)

#define _txLocLvlSet(lvl)  { _txLoc::Cur.trace = (lvl); }

//{----------------------------------------------------------------------------------------------------------------

#if defined ($0)
    #undef   $0
    #endif

#if defined ($1)
    #undef   $1
    #endif

#if defined ($2)
    #undef   $2
    #endif

#if defined ($3)
    #undef   $3
    #endif

#if defined ($4)
    #undef   $4
    #endif

#if defined ($5)
    #undef   $5
    #endif

#if defined ($6)
    #undef   $6
    #endif

#if defined ($7)
    #undef   $7
    #endif

#if defined ($8)
    #undef   $8
    #endif

#if defined ($9)
    #undef   $9
    #endif

#if defined ($)
    #undef   $
    #endif

#if defined ($$)
    #undef   $$
    #endif

//}
//-----------------------------------------------------------------------------------------------------------------

#if defined (_TX_ALLOW_TRACE)

    #define _txEntry(lvl)  _txFuncEntry __txFuncEntry; { if (lvl) _txLocLvlSet (lvl);    $;          }

    #define  $           { _txLocCurSet(); if (_txLoc::Cur.trace <= _TX_ALLOW_TRACE+0) { TX_TRACE; } }

    #define  $$          { __txFuncEntry.restore();                                                  }

#elif defined (_DEBUG)

    #define _txEntry(lvl)  _txFuncEntry __txFuncEntry; {                                 $;          }

    #define  $           { _txLocCurSet();                                                           }

    #define  $$          { __txFuncEntry.restore();                                                  }

#else

    #define _txEntry(lvl)  ;
    #define  $             ;
    #define  $$            ;

#endif

//{----------------------------------------------------------------------------------------------------------------

#define      $0            _txEntry (0)  // (Log level unchanged)
#define      $1            _txEntry (1)  // Regular functions
#define      $2            _txEntry (2)  // Resvd
#define      $3            _txEntry (3)  // Init/Cleanup
#define      $4            _txEntry (4)  // Init/Cleanup, misc functions
#define      $5            _txEntry (5)  // Error handling, entry points
#define      $6            _txEntry (6)  // Error handling, main part
#define      $7            _txEntry (7)  // Error handling, misc functions
#define      $8            _txEntry (8)  // Canvas worker thread
#define      $9            _txEntry (9)  // Resvd

//}
//-----------------------------------------------------------------------------------------------------------------

#endif // FOR_DOXYGEN_ONLY

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
//! @ingroup Misc
//! @brief   ����� ��� �������������� ���������� � ������������� ����������� ������.
//!
//!          ������� � <a href=http://progbook.ru/2008/08/03/sovremennoe-proektirovanie-na-c-andrejj.html>
//!          �������������,</a> ��� ����� ��� � �� �����, ��� ������: � ������������ -- EnterCriticalSection(),
//!          � ����������� -- LeaveCriticalSection(). ��� @c RAII � ������ ����: �� ������� �� �������� ����������
//!          ������ and your thread show will always go on.
//!
//!          ��������� ����������: ���� ����������� ������� TryEnterCriticalSection(), �, ���� ��� �� ���������
//!          ������, ���������� �� �� ������������. ���� �������� ��� ��������, ����������� �� ������ ��� ���
//!          (��. ������������ ������ � �������� @c bool).
//!
//! @note    ����� �� �������������� � �� ������� ����������� ������. ������ ��������������. ��������� ����-���� :)
//!
//! @see     txLock(), txUnlock(), txGDI()
//}----------------------------------------------------------------------------------------------------------------

//! @cond _OFF
extern CRITICAL_SECTION _txCanvas_LockBackBuf;
//! @endcond

class txAutoLock
    {
    typedef txAutoLock this_t;

    public:

//{----------------------------------------------------------------------------------------------------------------
//! @brief   �����������, ��������� ����������� ������
//!
//! @param   cs           ����������� ������ ��� ����������.
//! @param   mandatory <i>���� @c true,    �� ����������� �����������     (EnterCriticalSection).    @n
//!                       ���� @c false,   �� ������ �������� ����������� (TryEnterCriticalSection). @n
//!                       ���� �� �������, �� ���������� �����������.</i>
//! @usage @code
//!          CRITICAL_SECTION cs = {};         // This is not a Counter Strike
//!
//!          void foo()
//!              {
//!              txAutoLock lock (&cs);        // ����� ��������� EnterCriticalSection()
//!              ...
//!              }                             // � ����� LeaveCriticalsection()
//!
//!          void bar()
//!              {
//!              txAutoLock lock (&cs, false); // TryEnterCriticalSection()
//!              if (!lock) return;            // �� �� ������
//!              ...
//!              }
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    explicit txAutoLock (CRITICAL_SECTION* cs, bool mandatory = true) :
        cs_ (cs)
        {
$1      if (!cs_) return;

        if (mandatory) {$    EnterCriticalSection (cs_);                   }
        else           {$ TryEnterCriticalSection (cs_)? 0 : (cs_ = NULL); }
        }

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ����������� ��� ���������� ������ TXLib
//!
//! @param   mandatory <i>���� @c true,    �� ����������� @b �����������,     ��� � @ref txLock (true).  @n
//!                       ���� @c false,   �� ������ @b �������� �����������, ��� � @ref txLock (false). @n
//!                       ���� �� �������, �� ���������� �����������.</i>
//! @usage @code
//!          void foobar()
//!              {
//!              txAutoLock lock;      // ����� ��������� txLock()
//!              ...
//!              }                     // � ����� txUnlock()
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    explicit txAutoLock (bool mandatory = true) :
        cs_ (NULL)
        {
$1      new (this) txAutoLock (&_txCanvas_LockBackBuf, mandatory);
        }

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ����������, ������������ ������
//}----------------------------------------------------------------------------------------------------------------

   ~txAutoLock()
        {
$1      if (!cs_) return;
$       LeaveCriticalSection (cs_); cs_ = NULL;
        }

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ��������� ���������, ��������������� ������ ��� ���
//! @usage   ��. � txAutoLock::AutoLock (CRITICAL_SECTION&, bool)
//}----------------------------------------------------------------------------------------------------------------

    operator bool () const
        {
$1      return (cs_ != NULL);
        }

//{----------------------------------------------------------------------------------------------------------------
//! ����������� ����������� ������
//}----------------------------------------------------------------------------------------------------------------

//  private:
    CRITICAL_SECTION* cs_;

//{----------------------------------------------------------------------------------------------------------------
//! ����� ��� ��������.
//}----------------------------------------------------------------------------------------------------------------
//! @{

    private:
            txAutoLock (const this_t&) _tx_delete;
    this_t& operator = (const this_t&) _tx_delete;

//! @}

    };

//}
//=================================================================================================================

//=================================================================================================================
//{          Dialogs: txDialog class
//! @name    ������ � ����������� ������. ����� txDialog
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ������� ����� ��� ���������� ����.
//!
//!          ��� �������� ������ ����������� ���� �����:
//!           -# ������������ ���� ����� �� ����� �������� ������;
//!           -# ������ ������ � ������������ ��������� ���������� (���������) �������� txDialog::setLayout(), ���
//!              ������� ����� ������������ ��� ������ ����������� ���� �������� txDialog::dialogBox();
//!           -# �������������� � ����� ������ ������� txDialog::dialogProc() ��� ��������� ������� �����������
//!              ���� ��� ��������� ����� ������� �� ������� � ������� �������� TX_BEGIN_MESSAGE_MAP(),
//!              TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @note    ���� ����� ������������� ������ ������� ���������������� ���������� ���� � ������ ������� ��������
//!          �� ���. ��� ��� ������������ ������������� ����� �����, ��� �������� � ����������� ������ � Windows.
//!
//! @see     txDialog::setLayout(), txDialog::dialogProc(), txDialog::Layout, TX_BEGIN_MESSAGE_MAP(),
//!          TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

struct txDialog
    {
    typedef txDialog this_t;

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ��������� ��� ������� ���� ��������.
//!
//!          ������ �������� ����� ������������ �������� ������� �������, ��������������� � ���� txDialog::CONTROL.
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

    public:
    enum CONTROL
        {
        DIALOG    = (int) 0x00000000,            //!< ������ �������� �������
        BUTTON    = (int) 0xFFFF0080,            //!< ������
        EDIT      = (int) 0xFFFF0081,            //!< ������������� �����
        STATIC    = (int) 0xFFFF0082,            //!< ��������������� ������� (�����, �������� � �.�.)
        LISTBOX   = (int) 0xFFFF0083,            //!< ������ � ����������
        SCROLLBAR = (int) 0xFFFF0084,            //!< ������ ���������
        COMBOBOX  = (int) 0xFFFF0085,            //!< ��������������� ������
        END       = (int) 0x00000000             //!< ����� �������� �������
        };

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ����� ��� �������� �������� ����������� ���� (��������)
//!
//!          ������ ����� �������� ������ �������� ������ ����������� ����. ��� �������� ������ �� ������� �������
//!          � ��������� ������� (.rc):
//!
//!           - ������� ������� ��������� ���������� ���� � �����
//!           - ��������� �������� ��������� �������� (������� ������� ���������� �������� ����� �� �������
//!             ���������� � ��������� �������)
//!           - ��������� ������� -- txDialog::END ��� {NULL}
//!
//! @see     txDialog::setLayout(), txDialog::dialogBox(), txDialog::dialogProc()
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    public:
    struct Layout
        {
        CONTROL     wndclass;                    //!< ��� ��������
        const char* caption;                     //!< �������� ��� �����
        WORD        id;                          //!< ������������� ��������
        short        x;                          //!< ���������� �������� ������ ����
        short        y;                          //!< ���������� ������� ������� ����
        short       sx;                          //!< ������ �� X
        short       sy;                          //!< ������ �� Y
        DWORD       style;                       //!< ����� ��������

        const char* font;                        //!< ����� ����������� ����
        WORD        fontsize;                    //!< ������ ������ ����������� ����
        };

//{----------------------------------------------------------------------------------------------------------------
//! @brief   �����������.
//!
//! @see     txDialog::txDialog (const txDialog::Layout*)
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    public:
    txDialog();

//{----------------------------------------------------------------------------------------------------------------
//! @brief   �����������.
//!
//! @param   layout  ����� ����������� ����.
//!
//! @see     txDialog::Layout, txDialog::setLayout()
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    explicit txDialog (const Layout* layout);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ����������.
//}----------------------------------------------------------------------------------------------------------------

    virtual ~txDialog() {};

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������������� ������� ����� ����������� ����.
//!
//! @param   layout  ����� ����������� ����.
//!
//! @return  ���������� �����.
//!
//! @see     txDialog::Layout, txDialog::txDialog (const txDialog::Layout*), txDialog::dialogBox()
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    const Layout* setLayout (const Layout *layout);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������� ��������� ��������� ����������� ����.
//!
//! @param   _wnd     ���������� ����.
//! @param   _msg     ����� ���������.
//! @param   _wParam  1-� �������� ��������� (WORD).
//! @param   _lParam  2-� �������� ��������� (DWORD).
//!
//! @return  � ����������� ������� false, ��������� ��. DialogProc � <a href=msdn.com>MSDN</a>.
//!
//!          ��� ������� ���� �������������� ��� ��������� ������� ����, ��� ��������� �� � ������� ��������
//!          TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP.
//!
//! @see     txDialog::dialogBox(), TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_COMMAND_MAP
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ��������� ���������� ����.
//!
//! @param   layout <i>����� ����������� ����. @n
//!                    ���� �� ������ -- ������������ ��������, �������� txDialog::setLayout() ��� �������������
//!                    txDialog::txDialog (const txDialog::Layout*).</i>
//! @param   bufsize   ������ ������ ��� �������� ������� �������. ���� �� ������ -- ������ �� ���������.
//!
//! @return  ��������, ��������� � ������� EndDialog(). @n
//!          �� ��������� -- ����� ������� <i>(this),</i> ��� �������� ���� �������� txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc(), txDialog::setLayout(), txDialog::Layout, txDialog
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    intptr_t dialogBox (const Layout* layout = NULL, size_t bufsize = 0);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   ��������� ���������� ����.
//!
//! @param   resource  ������������� ����������� �������.
//!
//! @return  ��������, ��������� � ������� EndDialog(). @n
//!          �� ��������� -- ����� ������� <i>(this),</i> ��� �������� ���� �������� txDialog::dialogBox().
//!
//! @see     txDialog::dialogProc()
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

    intptr_t dialogBox (WORD resource);

//{----------------------------------------------------------------------------------------------------------------
//! @brief   �������� ����������� ����������� � �������� ������������.
//}----------------------------------------------------------------------------------------------------------------

    private:
            txDialog   (const this_t&) _tx_delete;
    this_t& operator = (const this_t&) _tx_delete;

//{----------------------------------------------------------------------------------------------------------------
//! ��������� ���������� ������� (�� txDialog::dialogProc(), �.�. ������� ���� in32 ������ ���� �����������).
//}----------------------------------------------------------------------------------------------------------------

    protected:
    static intptr_t CALLBACK DialogProc_ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam);

//{----------------------------------------------------------------------------------------------------------------
//! ������� ����� �������.
//}----------------------------------------------------------------------------------------------------------------

    private:
    const Layout* layout_;
    };

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Dialogs: Message Map macros
//! @name    ������� ��� ���������� ����������� ����� ��������� (Message Map)
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����� ��������� (Message Map).
//!
//! @par     ������������ �
//! @code
//!          virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) override
//!              {
//!              int _result = txDialog::dialogProc (_wnd, _msg, _wParam, _lParam);
//!
//!              switch (_msg)
//!                  {
//! @endcode
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_BEGIN_MESSAGE_MAP()                                                                 \
    virtual int dialogProc (HWND _wnd, UINT _msg, WPARAM _wParam, LPARAM _lParam) _tx_override \
        {                                                                                      \
        int _result = txDialog::dialogProc (_wnd, _msg, _wParam, _lParam); (void) _result;     \
                                                                                               \
        switch (_msg)                                                                          \
            {                                                                                  \
            case WM_NULL:

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ��������� ����������� ��������� (Message handler) ����� ���������.
//!
//! @param   id  ������������� ���������.
//!
//! @par     ������������ �
//! @code
//!                  break;
//!                  case (id):
//! @endcode
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_HANDLE( id )                                                                        \
            break;                                                                             \
            case (id):

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ������ ����� ������ (Command map) � ����� ���������.
//!
//! @par     ������������ �
//! @code
//!                  }  // ����� switch (_msg)
//!
//!              if (_msg == WM_COMMAND)
//!                  switch (LOWORD (_wParam))
//!                      {
//! @endcode
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_COMMAND_MAP                                                                         \
            default: break;                                                                    \
            }                                                                                  \
                                                                                               \
        if (_msg == WM_COMMAND) switch (LOWORD (_wParam))                                      \
            {                                                                                  \
            case 0:

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ����������� ����� ���������.
//!
//! @par     ������������ �
//! @code
//!                  }  // ����� switch (_msg) ��� switch (LOWORD (_wParam))
//!
//!              return FALSE;
//!              }
//! @endcode
//!
//! @see     TX_BEGIN_MESSAGE_MAP(), TX_END_MESSAGE_MAP, TX_HANDLE(), TX_COMMAND_MAP, txDialog::dialogProc(), txDialog
//!
//! @usage @code
//!          C�. ���������� ������� txInputBox().
//! @endcode
//!
//! @hideinitializer
//}----------------------------------------------------------------------------------------------------------------

#define TX_END_MESSAGE_MAP                                                                     \
            default: break;                                                                    \
            }                                                                                  \
                                                                                               \
        return FALSE;                                                                          \
        }

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Dialogs: txDialog example: txInputBox()
//! @name    ������ ������������� ������ �������: ������� txInputBox()
//=================================================================================================================
//! @{
//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Dialogs
//! @brief   ���� ������ � ��������� ����.
//!
//! @param   text    <i>����� � ��������. �������������.</i>
//! @param   caption <i>��������� ����. �������������.</i>
//! @param   input   <i>�������� ������ �� ���������. �������������.</i>
//!
//! @return  ��������� ������ (����������� ���������� �������).
//!
//! @warning ������������ ������ -- �����������, � ����������� ��� ������ ������ �������. ���� txInputBox() �����
//!          ���������� ��������� ���, �� ��� ���������� ������ �� ���������� ���������� � ������ ������ ��� ������
//!          <i>strcpy()</i>.
//!
//! @see     txDialog, TX_BEGIN_MESSAGE_MAP, TX_BEGIN_COMMAND_MAP, TX_HANDLE, TX_END_MESSAGE_MAP
//!
//! @usage @code
//!          const char* name = txInputBox ("So what's ur name?!?!", "System", "Sorry I'm Vasya Pupkin");
//!          txMessageBox (name, "Aaand nooowww.. the winner iiis...");
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

const char* txInputBox (const char* text = NULL, const char* caption = NULL, const char* input = NULL) tx_nodiscard;

#ifndef TX_COMPILED

const char* txInputBox (const char* text, const char* caption, const char* input)
    {
    //-------------------------------------------------------------------------------------------------------------
    // ���� �� ������� ���������, ���������� ������������ ���� �����-�� �������.
    // txGetModuleFileName() -- ��� EXE-�����, �� ������, ���� ���-��� ��������� ������ ��������.
    //-------------------------------------------------------------------------------------------------------------

    if (!text)    text    = "������� ������:";
    if (!caption) caption = txGetModuleFileName (false);
    if (!input)   input   = "";

    //-------------------------------------------------------------------------------------------------------------
    // �������������� ��������� �������. ��� ��������� � GetDlgItemText().
    // ���� ������ �������� �� �������, � ���������� ��������, �� ��� �������� � ��� �������������.
    // � ��� �� ��� -- ������� �����, � ���������. ������� � ���, ��� � ������ ���� ���������������� ������ ���������
    // �������� � ������� ������. ������� ��� ������������� �� ��� ��� ����� ��������� �� ����� ����������,
    // �����������. �� ��� �������, ��� ��� ����������� � txDialog::dialogBox() � �������� _tx_DLGTEMPLATE_()... �_�
    //-------------------------------------------------------------------------------------------------------------

    #define ID_TEXT_  101
    #define ID_INPUT_ 102

    //-------------------------------------------------------------------------------------------------------------
    // ������� ������ (����) ������� � ���� ������� ��������.
    // � ������� ������� ������� ����� � ��������� txDialog::Layout � �������� �� ������ txDialog ���� ������
    // ���������� ����� �� �������� ������� ������� � .rc-�����.
    // ��. �������� ���������� rc-����� � ������������ �� Win32 (MSDN, http://msdn.com).
    //-------------------------------------------------------------------------------------------------------------

    txDialog::Layout layout[] =

    //----------------------+----------+-----------+-----------------+---------------------------------------------
    //     ��� ��������     | ���      | ������-   |   ����������    | ����� ���������
    //     �������          | �������� | �������   |-----------------| (��. �������� ���������
    //                      |          | ��������  | X | Y |���.|���.| ���� ������� � MSDN)
    //----------------------+----------+-----------+---+---+----+----+---------------------------------------------
    //                      |          |           |   |   |    |    |
        {{ txDialog::DIALOG,  caption,   0,           0,  0, 240,  85                                                    },
         { txDialog::STATIC,  text,      ID_TEXT_,   10, 10, 150,  40, SS_LEFT                                           },
         { txDialog::EDIT,    input,     ID_INPUT_,  10, 60, 220,  15, ES_LEFT | WS_BORDER | ES_AUTOHSCROLL | WS_TABSTOP },
         { txDialog::BUTTON,  "&OK",     IDOK,      180, 10,  50,  15, BS_DEFPUSHBUTTON                     | WS_TABSTOP },
         { txDialog::BUTTON,  "&Cancel", IDCANCEL,  180, 30,  50,  15, BS_PUSHBUTTON                        | WS_TABSTOP },
         { txDialog::END                                                                                                 }};

    //-------------------------------------------------------------------------------------------------------------
    // ����� ������� ��� InputBox. ����������, �.�. ����� ��� ���� �������.
    // ����� � �������� ��� ������� ������ ����� (str) � ������� ������� ����������� ����, ��������� Win32 (���
    // ��������� ��������� TX_BEGIN_MESSAGE_MAP � �������). ����� �� ������ ����������� ������, �� ����� �������
    // ������� �������� ������ � ���������� ������� ���������, � str ��������� ��������� ���� (��� ���������� ��
    // ����� ����� DialogBoxParam � ���������� ��� � ����� �� ����� ��������� WM_INITDIALOG).
    //-------------------------------------------------------------------------------------------------------------
    struct inputDlg : txDialog
        {
        char str [1024];

        //---------------------------------------------------------------------------------------------------------

        inputDlg() :
            str()
            {}

        //---------------------------------------------------------------------------------------------------------

        TX_BEGIN_MESSAGE_MAP()    // ����� ��������� (�� ����� ���� ��� ������ ������� �������).

            TX_COMMAND_MAP        // ����� �������������� WM_COMMAND (�� ����� ���� ��� �������� switch).

                //-------------------------------------------------------------------------------------------------
                // ��� ������� ������ OK �������� ������ �� ���� ����� � ���� ���������� str, �.�. ����� ��������
                // ������� ������ ����� ����� � ����� ��� �� ��� ��������.
                // ���� ������ �� ����� ���� ������������ � case �� ��������� switch.
                // _wnd -- ��� �������� ������� �������, ��. ����������� ������� TX_BEGIN_MESSAGE_MAP().
                //-------------------------------------------------------------------------------------------------

                TX_HANDLE (IDOK) GetDlgItemText (_wnd, ID_INPUT_, str, sizeof (str) - 1);

        TX_END_MESSAGE_MAP

        //---------------------------------------------------------------------------------------------------------
        // ����� ����������� ������ �������
        //---------------------------------------------------------------------------------------------------------
        };

    //-------------------------------------------------------------------------------------------------------------
    // ������� �������, ����� ����� �� ������.
    // �� ����� ��� ���������� "���������� ��������", ��� ����� � ��� ���� �� ������� ��������� -- �������. �� �����
    // ���� ��� ������� ������� ����� #undef. ����� ����������� �� ��������� �������, � ��� ����� ������������� �� _.
    // ����� ������� ����� �� ����������� ���� ��� ����� ���� ���, ����������, ����� ��� �� �����.
    //-------------------------------------------------------------------------------------------------------------

    #undef ID_TEXT_
    #undef ID_INPUT_

    //-------------------------------------------------------------------------------------------------------------
    // ��� ����������� ������, ������ ��� ������ � ��� ������ ���� ����� ���������� �������.
    //-------------------------------------------------------------------------------------------------------------

    static inputDlg dlg;

    //-------------------------------------------------------------------------------------------------------------
    // �������� layout � ��������� ���� �������
    //-------------------------------------------------------------------------------------------------------------

    dlg.dialogBox (layout);

    //-------------------------------------------------------------------------------------------------------------
    // ���������� ����� ������ �� ������������ �������. ��� ����� ������, ������ ��� ����������� ������ �� �����
    // ��� ������ �� ������� � ������ � ���, ��������������, ����. ����� ������������� ���������� ����������
    // ������������� �����, �� ����� � ��������� �������.
    //-------------------------------------------------------------------------------------------------------------

    return dlg.str;
    }

#endif // TX_COMPILED

//! @}
//}
//=================================================================================================================

//}
//=================================================================================================================

//=================================================================================================================
//{          TXLIB IMPLEMENTATION
//           ���������� ������� ����������
//=================================================================================================================
//! @cond INTERNAL {

//-----------------------------------------------------------------------------------------------------------------
//{          The Includes
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

_TX_END_NAMESPACE

//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)
    #pragma warning (push, 3)                    // MSVC: At level /Wall, some std headers emit warnings... O_o

    #pragma warning (disable: 4365)              // 'argument': conversion from 'long' to 'unsigned int', signed/unsigned mismatch
    #pragma warning (disable: 4005)              // 'name': macro redefinition
#endif

#if defined (__STRICT_ANSI__) && defined (__STRICT_ANSI__UNDEFINED)
    #undef   __STRICT_ANSI__
#endif

//-----------------------------------------------------------------------------------------------------------------

#include <stdarg.h>
#include <io.h>
#include <fcntl.h>
#include <process.h>
#include <signal.h>
#include <setjmp.h>
#include <locale.h>
#include <limits.h>
#include <stdint.h>

#include <map>
#include <numeric>
#include <algorithm>
#include <exception>
#include <stdexcept>

#include <tlhelp32.h>
#include <shellapi.h>

#if defined (_GCC_VER)

#include <shlobj.h>

#include <cxxabi.h>
#include <unwind.h>

#endif

#if defined (__CYGWIN__)

#include <stdarg.h>
#include <unistd.h>
#include <termios.h>

#endif

#if defined (_MSC_VER)

#include <new.h>

#include <shlobj.h>
#include <ntstatus.h>
#include <crtdbg.h>
#include <rtcapi.h>
#include <dbghelp.h>

#endif

#if defined (_GCC_VER) || defined (_MSC_VER) && (_MSC_VER >= 1800)  // MSVC 2013
#include <inttypes.h>
#endif

//-----------------------------------------------------------------------------------------------------------------

#if defined (TX_USE_SPEAK) //--------------------------------------------------------------------------------------
#include <SAPI.h>          // <== ���� ����� ������, �� � ��� ��� ����� SAPI.h. No SAPI.h file, TXLib isn't guilty :(
#endif                     //--------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)
    #pragma warning (pop)                        // MSVC: Restore max level
#endif

#if defined (__STRICT_ANSI__UNDEFINED)
    #define  __STRICT_ANSI__                     // Redefine back
#endif

//-----------------------------------------------------------------------------------------------------------------

_TX_BEGIN_NAMESPACE

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//=================================================================================================================
//{          DLL functions import, missing types definitions
//! @name    ������ ������� ���������, ����������� ����������� �����
//=================================================================================================================
//! @{

//-----------------------------------------------------------------------------------------------------------------
//{ Some of structs, consts and interfaces aren't defined in MinGW some early headers.
//  Copied from Windows SDK 7.0a.
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

namespace Win32 {

#ifndef AC_SRC_ALPHA
#define AC_SRC_ALPHA                             0x01
#endif

#ifndef SMTO_ERRORONEXIT
#define SMTO_ERRORONEXIT                         0x0020
#endif

#ifndef NT_CONSOLE_PROPS_SIG
#define NT_CONSOLE_PROPS_SIG                     0xA0000002
#endif

#ifndef NIIF_INFO
#define NIIF_INFO                                0x00000001
#define NIIF_WARNING                             0x00000002
#define NIIF_ERROR                               0x00000003
#endif

#ifndef NIF_INFO
#define NIF_STATE                                0x00000008
#define NIF_INFO                                 0x00000010
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

#ifndef STATUS_POSSIBLE_DEADLOCK
#define STATUS_POSSIBLE_DEADLOCK                 0xC0000194
#endif

#ifndef STATUS_FLOAT_MULTIPLE_FAULTS
#define STATUS_FLOAT_MULTIPLE_FAULTS             0xC00002B4
#endif

#ifndef STATUS_STACK_BUFFER_OVERRUN
#define STATUS_STACK_BUFFER_OVERRUN              0xC0000409
#endif

#ifndef STATUS_ASSERTION_FAILURE
#define STATUS_ASSERTION_FAILURE                 0xC0000420
#endif

#ifndef STATUS_WX86_BREAKPOINT
#define STATUS_WX86_BREAKPOINT                   0x4000001F
#endif

#ifndef DBG_PRINTEXCEPTION_C
#define DBG_PRINTEXCEPTION_C                     0x40010006  // OutputDebugStringA() call
#endif

#ifndef DBG_PRINTEXCEPTION_WIDE_C
#define DBG_PRINTEXCEPTION_WIDE_C                0x4001000A  // OutputDebugStringW() call
#endif

#ifndef DBG_THREAD_NAME
#define DBG_THREAD_NAME                          0x406D1388
#endif

#define EXCEPTION_CPP_MSC                        0xE06D7363  // '?msc'
#define EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER1       0x19930520  // '?msc' version magic, see ehdata.h
#define EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER2       0x19930521  // '?msc' version magic
#define EXCEPTION_CPP_MSC_EH_MAGIC_NUMBER3       0x19930522  // '?msc' version magic
#define EXCEPTION_CPP_MSC_EH_PURE_MAGIC_NUMBER1  0x01994000  // '?msc' version magic

#define EXCEPTION_CPP_GCC                        0x20474343  // ' GCC'
#define EXCEPTION_CPP_GCC_UNWIND                 0x21474343  // '!GCC'
#define EXCEPTION_CPP_GCC_FORCED                 0x22474343  // '"GCC'

#define EXCEPTION_CLR_FAILURE                    0xE0434f4D  // '�COM'

#define EXCEPTION_CPP_BORLAND_BUILDER            0x0EEDFAE6  // Should never occur here
#define EXCEPTION_CPP_BORLAND_DELPHI             0x0EEDFADE  // Should never occur here

#pragma pack (push, 1)

struct CONSOLE_CURSOR_INFO
    {
    DWORD dwSize;
    BOOL bVisible;
    };

struct CONSOLE_FONT_INFO
    {
    DWORD nFont;
    COORD dwFontSize;
    };

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

const GUID CLSID_SpVoice          = {0x96749377, 0x3391, 0x11d2, {0x9e,0xe3,0x00,0xc0,0x4f,0x79,0x73,0x96}};
const GUID IID_ISpVoice           = {0x6c44df74, 0x72b9, 0x4992, {0xa1,0xec,0xef,0x99,0x6e,0x04,0x22,0xd4}};

#undef  INTERFACE

typedef DWORD     NTSTATUS;
typedef ULONG_PTR KAFFINITY;
typedef LONG      KPRIORITY;

struct UNICODE_STRING
    {
    USHORT Length;
    USHORT MaximumLength;
    WCHAR* Buffer;
    };

struct RTL_USER_PROCESS_PARAMETERS
    {
    BYTE  Reserved1[16];
    void* Reserved2[10];
    UNICODE_STRING ImagePathName;
    UNICODE_STRING CommandLine;
    };

struct PEB
    {
    BYTE  Reserved1[2];
    BYTE  BeingDebugged;
    BYTE  Reserved2[1];
    void* Reserved3[2];
    void* Ldr;
    RTL_USER_PROCESS_PARAMETERS* ProcessParameters;
    void* Reserved4[3];
    void* AtlThunkSListPtr;
    void* Reserved5;
    ULONG Reserved6;
    void* Reserved7;
    ULONG Reserved8;
    ULONG AtlThunkSListPtr32;
    void* Reserved9[45];
    BYTE  Reserved10[96];
    void* PostProcessInitRoutine;
    BYTE  Reserved11[128];
    void* Reserved12[1];
    ULONG SessionId;
    };

struct PROCESS_BASIC_INFORMATION
    {
    NTSTATUS  ExitStatus;
    PEB*      PebBaseAddress;
    KAFFINITY AffinityMask;
    KPRIORITY BasePriority;
    ULONG_PTR UniqueProcessId;
    ULONG_PTR InheritedFromUniqueProcessId;
    };

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

typedef bool    (__stdcall *PREAD_PROCESS_MEMORY_ROUTINE64)   (HANDLE process, DWORD64 baseAddress, void* buffer, DWORD size, DWORD* bytesRead);
typedef void*   (__stdcall *PFUNCTION_TABLE_ACCESS_ROUTINE64) (HANDLE process, DWORD64 baseAddress);
typedef DWORD64 (__stdcall *PGET_MODULE_BASE_ROUTINE64)       (HANDLE process, DWORD64 address);
typedef DWORD64 (__stdcall *PTRANSLATE_ADDRESS_ROUTINE64)     (HANDLE process, HANDLE thread, ADDRESS64* address);

typedef void (*unexpected_handler)();

#pragma pack (push, 4)

struct MINIDUMP_THREAD_CALLBACK
    {
    ULONG    ThreadId;
    HANDLE   ThreadHandle;
    CONTEXT  Context;
    ULONG    SizeOfContext;
    ULONG64  StackBase;
    ULONG64  StackEnd;
    };

struct MINIDUMP_THREAD_EX_CALLBACK
    {
    ULONG    ThreadId;
    HANDLE   ThreadHandle;
    CONTEXT  Context;
    ULONG    SizeOfContext;
    ULONG64  StackBase;
    ULONG64  StackEnd;
    ULONG64  BackingStoreBase;
    ULONG64  BackingStoreEnd;
    };

struct MINIDUMP_MODULE_CALLBACK
    {
    wchar_t* FullPath;
    ULONG64  BaseOfImage;
    ULONG    SizeOfImage;
    ULONG    CheckSum;
    ULONG    TimeDateStamp;
    VS_FIXEDFILEINFO VersionInfo;
    void*    CvRecord;
    ULONG    SizeOfCvRecord;
    PVOID    MiscRecord;
    ULONG    SizeOfMiscRecord;
    };

struct MINIDUMP_INCLUDE_THREAD_CALLBACK
    {
    ULONG    ThreadId;
    };

struct MINIDUMP_INCLUDE_MODULE_CALLBACK
    {
    ULONG64  BaseOfImage;
    };

struct MINIDUMP_MEMORY_INFO
    {
    ULONG64  BaseAddress;
    ULONG64  AllocationBase;
    ULONG32  AllocationProtect;
    ULONG32  __alignment1;
    ULONG64  RegionSize;
    ULONG32  State;
    ULONG32  Protect;
    ULONG32  Type;
    ULONG32  __alignment2;
    };

struct MINIDUMP_USER_STREAM
    {
    ULONG32  Type;
    ULONG    BufferSize;
    PVOID    Buffer;
    };

struct MINIDUMP_USER_STREAM_INFORMATION
    {
    ULONG                 UserStreamCount;
    MINIDUMP_USER_STREAM* UserStreamArray;
    };

struct MINIDUMP_CALLBACK_INPUT
    {
    ULONG    ProcessId;
    HANDLE   ProcessHandle;
    ULONG    CallbackType;

    union
        {
        MINIDUMP_THREAD_CALLBACK         Thread;
        MINIDUMP_THREAD_EX_CALLBACK      ThreadEx;
        MINIDUMP_MODULE_CALLBACK         Module;
        MINIDUMP_INCLUDE_THREAD_CALLBACK IncludeThread;
        MINIDUMP_INCLUDE_MODULE_CALLBACK IncludeModule;
        };
    };

struct MINIDUMP_CALLBACK_OUTPUT
    {
    union
        {
        ULONG ModuleWriteFlags;
        ULONG ThreadWriteFlags;
        ULONG SecondaryFlags;

        struct
            {
            ULONG64  MemoryBase;
            ULONG    MemorySize;
            };

        struct
            {
            unsigned CheckCancel;
            unsigned Cancel;
            };

        HANDLE Handle;
        };

    struct
        {
        MINIDUMP_MEMORY_INFO VmRegion;
        unsigned             Continue;
        };

    HRESULT Status;
    };

struct MINIDUMP_EXCEPTION_INFORMATION
    {
    DWORD               ThreadId;
    EXCEPTION_POINTERS* ExceptionPointers;
    unsigned            ClientPointers;
    };

typedef int (WINAPI* MINIDUMP_CALLBACK_ROUTINE) (void* param, MINIDUMP_CALLBACK_INPUT* input, MINIDUMP_CALLBACK_OUTPUT* output);

struct MINIDUMP_CALLBACK_INFORMATION
    {
    MINIDUMP_CALLBACK_ROUTINE CallbackRoutine;
    void*                     CallbackParam;
    };

enum MINIDUMP_TYPE
    {
    MiniDumpNormal                         = 0x00000000,
    MiniDumpWithDataSegs                   = 0x00000001,
    MiniDumpWithFullMemory                 = 0x00000002,
    MiniDumpWithHandleData                 = 0x00000004,
    MiniDumpFilterMemory                   = 0x00000008,
    MiniDumpScanMemory                     = 0x00000010,
    MiniDumpWithUnloadedModules            = 0x00000020,
    MiniDumpWithIndirectlyReferencedMemory = 0x00000040,
    MiniDumpFilterModulePaths              = 0x00000080,
    MiniDumpWithProcessThreadData          = 0x00000100,
    MiniDumpWithPrivateReadWriteMemory     = 0x00000200,
    MiniDumpWithoutOptionalData            = 0x00000400,
    MiniDumpWithFullMemoryInfo             = 0x00000800,
    MiniDumpWithThreadInfo                 = 0x00001000,
    MiniDumpWithCodeSegs                   = 0x00002000,
    MiniDumpWithoutAuxiliaryState          = 0x00004000,
    MiniDumpWithFullAuxiliaryState         = 0x00008000,
    MiniDumpWithPrivateWriteCopyMemory     = 0x00010000,
    MiniDumpIgnoreInaccessibleMemory       = 0x00020000,
    MiniDumpWithTokenInformation           = 0x00040000
    };

#ifndef CONTEXT_ALL
#define CONTEXT_ALL              ( CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS )
#endif

#pragma pack (pop)

} // namespace Win32

#endif // TX_COMPILED

#define FOREGROUND_BLACK         ( 0                                                         )
#define FOREGROUND_CYAN          ( FOREGROUND_BLUE       | FOREGROUND_GREEN                  )
#define FOREGROUND_MAGENTA       ( FOREGROUND_BLUE       | FOREGROUND_RED                    )
#define FOREGROUND_DARKYELLOW    ( FOREGROUND_GREEN      | FOREGROUND_RED                    )
#define FOREGROUND_LIGHTGRAY     ( FOREGROUND_BLUE       | FOREGROUND_GREEN | FOREGROUND_RED )
#define FOREGROUND_DARKGRAY      (                         FOREGROUND_INTENSITY              )
#define FOREGROUND_LIGHTBLUE     ( FOREGROUND_BLUE       | FOREGROUND_INTENSITY              )
#define FOREGROUND_LIGHTGREEN    ( FOREGROUND_GREEN      | FOREGROUND_INTENSITY              )
#define FOREGROUND_LIGHTCYAN     ( FOREGROUND_CYAN       | FOREGROUND_INTENSITY              )
#define FOREGROUND_LIGHTRED      ( FOREGROUND_RED        | FOREGROUND_INTENSITY              )
#define FOREGROUND_LIGHTMAGENTA  ( FOREGROUND_MAGENTA    | FOREGROUND_INTENSITY              )
#define FOREGROUND_YELLOW        ( FOREGROUND_DARKYELLOW | FOREGROUND_INTENSITY              )
#define FOREGROUND_WHITE         ( FOREGROUND_LIGHTGRAY  | FOREGROUND_INTENSITY              )

#define BACKGROUND_BLACK         ( 0                                                         )
#define BACKGROUND_CYAN          ( BACKGROUND_BLUE       | BACKGROUND_GREEN                  )
#define BACKGROUND_MAGENTA       ( BACKGROUND_BLUE       | BACKGROUND_RED                    )
#define BACKGROUND_DARKYELLOW    ( BACKGROUND_GREEN      | BACKGROUND_RED                    )
#define BACKGROUND_GRAY          ( BACKGROUND_BLUE       | BACKGROUND_GREEN | BACKGROUND_RED )
#define BACKGROUND_DARKGRAY      (                         BACKGROUND_INTENSITY              )
#define BACKGROUND_LIGHTBLUE     ( BACKGROUND_BLUE       | BACKGROUND_INTENSITY              )
#define BACKGROUND_LIGHTGREEN    ( BACKGROUND_GREEN      | BACKGROUND_INTENSITY              )
#define BACKGROUND_LIGHTCYAN     ( BACKGROUND_CYAN       | BACKGROUND_INTENSITY              )
#define BACKGROUND_LIGHTRED      ( BACKGROUND_RED        | BACKGROUND_INTENSITY              )
#define BACKGROUND_LIGHTMAGENTA  ( BACKGROUND_MAGENTA    | BACKGROUND_INTENSITY              )
#define BACKGROUND_LIGHTYELLOW   ( BACKGROUND_DARKYELLOW | BACKGROUND_INTENSITY              )
#define BACKGROUND_WHITE         ( BACKGROUND_DARKGRAY   | BACKGROUND_INTENSITY              )

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{ There are copies of MSVC compiler built-in predefined definitions, which are wrong in 64-bit mode.
//  So we have to override them. See: http://stackoverflow.com/questions/39113168
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

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

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{ The corresponding structures for GCC
//
//  From: http://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/libsupc%2B%2B/unwind-cxx.h
//  See:  http://mentorembedded.github.io/cxx-abi/abi-eh.html#cxx-abi
//-----------------------------------------------------------------------------------------------------------------

#if defined (_GCC_VER)

#ifndef TX_COMPILED

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
} // namespace ABI                                  //           .                    .         |                 |
                                                    //                                          +-----------------+

extern "C" ABI::__cxa_eh_globals* __cxa_get_globals();

#endif // TX_COMPILED

#endif

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{ Hand-made IAT.
//  Some IDEs don't link with these libs by default in console projects, so do sunrise by hand. :(
//-----------------------------------------------------------------------------------------------------------------

// Hand-made DLLIMPORT helpers

#define _TX_DLLIMPORT(     lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txDllImport (lib ".dll", #name, true)

#define _TX_DLLIMPORT_OPT( lib, retval, name, params ) \
     retval (WINAPI* name) params = (retval (WINAPI*) params) _txDllImport (lib ".dll", #name, false)

#define _TX_DLLIMPORT_CRT( lib, retval, name, params ) \
     retval (      * name) params = (retval (      *) params) _txDllImport (lib ".dll", #name, false)

typedef void (*_tx_FARPROC)();

_tx_FARPROC _txDllImport (const char dllFileName[], const char funcName[], bool required = true);

//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

namespace Win32 {

_TX_DLLIMPORT     ("GDI32",    HDC,      CreateCompatibleDC,            (HDC dc));
_TX_DLLIMPORT     ("GDI32",    HBITMAP,  CreateCompatibleBitmap,        (HDC dc, int width, int height));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  GetStockObject,                (int object));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  SelectObject,                  (HDC dc, HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    HGDIOBJ,  GetCurrentObject,              (HDC dc, unsigned objectType));
_TX_DLLIMPORT     ("GDI32",    int,      GetObjectA,                    (HGDIOBJ obj, int bufsize, void* buffer));
_TX_DLLIMPORT     ("GDI32",    DWORD,    GetObjectType,                 (HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    bool,     DeleteDC,                      (HDC dc));
_TX_DLLIMPORT     ("GDI32",    bool,     DeleteObject,                  (HGDIOBJ object));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetTextColor,                  (HDC dc, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetBkColor,                    (HDC dc, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    int,      SetBkMode,                     (HDC dc, int bkMode));
_TX_DLLIMPORT     ("GDI32",    HFONT,    CreateFontA,                   (int height, int width, int escapement, int orientation,
                                                                         int weight, DWORD italic, DWORD underline, DWORD strikeout,
                                                                         DWORD charSet, DWORD outputPrec, DWORD clipPrec,
                                                                         DWORD quality, DWORD pitchAndFamily, const char face[]));
_TX_DLLIMPORT     ("GDI32",    int,      EnumFontFamiliesExA,           (HDC dc, LPLOGFONT logFont, FONTENUMPROC enumProc,
                                                                         LPARAM lParam, DWORD reserved));
_TX_DLLIMPORT     ("GDI32",    COLORREF, SetPixel,                      (HDC dc, int x, int y, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    COLORREF, GetPixel,                      (HDC dc, int x, int y));
_TX_DLLIMPORT     ("GDI32",    HPEN,     CreatePen,                     (int penStyle, int width, COLORREF color));
_TX_DLLIMPORT     ("GDI32",    HBRUSH,   CreateSolidBrush,              (COLORREF color));
_TX_DLLIMPORT     ("GDI32",    bool,     MoveToEx,                      (HDC dc, int x, int y, POINT* point));
_TX_DLLIMPORT     ("GDI32",    bool,     LineTo,                        (HDC dc, int x, int y));
_TX_DLLIMPORT     ("GDI32",    bool,     Polygon,                       (HDC dc, const POINT points[], int count));
_TX_DLLIMPORT     ("GDI32",    bool,     Polyline,                      (HDC dc, const POINT points[], int count));
_TX_DLLIMPORT     ("GDI32",    bool,     PolyBezier,                    (HDC dc, const POINT points[], int count));
_TX_DLLIMPORT     ("GDI32",    bool,     Rectangle,                     (HDC dc, int x0, int y0, int x1, int y1));
_TX_DLLIMPORT     ("GDI32",    bool,     RoundRect,                     (HDC dc, int x0, int y0, int x1, int y1, int sizeX, int sizeY));
_TX_DLLIMPORT     ("GDI32",    bool,     Ellipse,                       (HDC dc, int x0, int y0, int x1, int y1));
_TX_DLLIMPORT     ("GDI32",    bool,     Arc,                           (HDC dc, int x0, int y0, int x1, int y1,
                                                                         int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    bool,     Pie,                           (HDC dc, int x0, int y0, int x1, int y1,
                                                                         int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    bool,     Chord,                         (HDC dc, int x0, int y0, int x1, int y1,
                                                                         int xStart, int yStart, int xEnd, int yEnd));
_TX_DLLIMPORT     ("GDI32",    bool,     TextOutA,                      (HDC dc, int x, int y, const char string[], int length));
_TX_DLLIMPORT     ("GDI32",    UINT,     SetTextAlign,                  (HDC dc, unsigned mode));
_TX_DLLIMPORT     ("GDI32",    bool,     GetTextExtentPoint32A,         (HDC dc, const char string[], int length, SIZE* size));
_TX_DLLIMPORT     ("GDI32",    bool,     ExtFloodFill,                  (HDC dc, int x, int y, COLORREF color, unsigned type));
_TX_DLLIMPORT     ("GDI32",    bool,     BitBlt,                        (HDC dest, int xDest, int yDest, int width, int height,
                                                                         HDC src,  int xSrc,  int ySrc,  DWORD rOp));
_TX_DLLIMPORT     ("GDI32",    bool,     StretchBlt,                    (HDC dest, int xDest, int yDest, int width, int height,
                                                                         HDC src, int xSrc, int ySrc, int wSrc, int hSrc, DWORD rOp));
_TX_DLLIMPORT     ("GDI32",    bool,     PlgBlt,                        (HDC dest, const POINT* parallelogram,
                                                                         HDC src, int xSrc, int ySrc, int width, int height,
                                                                         HBITMAP mask, int xMask, int yMask));
_TX_DLLIMPORT     ("GDI32",    int,      SetDIBitsToDevice,             (HDC dc, int xDest, int yDest, DWORD width, DWORD height,
                                                                         int xSrc, int ySrc, unsigned startLine, unsigned numLines,
                                                                         const void* data, const BITMAPINFO* info, unsigned colorUse));
_TX_DLLIMPORT     ("GDI32",    int,      GetDIBits,                     (HDC hdc, HBITMAP hbmp, unsigned uStartScan, unsigned cScanLines,
                                                                         void* lpvBits, BITMAPINFO* lpbi, unsigned usage));
_TX_DLLIMPORT     ("GDI32",    bool,     PatBlt,                        (HDC dc, int x0, int y0, int width, int height, DWORD rOp));
_TX_DLLIMPORT     ("GDI32",    int,      SetROP2,                       (HDC dc, int mode));
_TX_DLLIMPORT     ("GDI32",    int,      SetStretchBltMode,             (HDC dc, int mode));
_TX_DLLIMPORT     ("GDI32",    DWORD,    GdiSetBatchLimit,              (DWORD limit));
_TX_DLLIMPORT     ("GDI32",    HBITMAP,  CreateDIBSection,              (HDC dc, const BITMAPINFO* bmInfo, unsigned colorUsage, void **vBits,
                                                                         HANDLE section, DWORD offset));

_TX_DLLIMPORT     ("User32",   int,      DrawTextA,                     (HDC dc, const char text[], int length, RECT* rect, unsigned format));
_TX_DLLIMPORT     ("User32",   HANDLE,   LoadImageA,                    (HINSTANCE inst, const char name[], unsigned type,
                                                                        int sizex, int sizey, unsigned mode));
_TX_DLLIMPORT_OPT ("User32",   bool,     IsHungAppWindow,               (HWND wnd));
_TX_DLLIMPORT_OPT ("User32",   HWND,     GhostWindowFromHungWindow,     (HWND wnd));

_TX_DLLIMPORT     ("WinMM",    bool,     PlaySound,                     (const char sound[], HMODULE mod, DWORD mode));

_TX_DLLIMPORT_OPT ("MSImg32",  bool,     TransparentBlt,                (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                                         HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                                         unsigned transparentColor));
_TX_DLLIMPORT_OPT ("MSImg32",  bool,     AlphaBlend,                    (HDC dest, int destX, int destY, int destWidth, int destHeight,
                                                                         HDC src,  int srcX,  int srcY,  int srcWidth,  int srcHeight,
                                                                         BLENDFUNCTION blending));

_TX_DLLIMPORT     ("Kernel32", void,     ExitProcess,                   (unsigned retcode));
_TX_DLLIMPORT     ("Kernel32", bool,     TerminateProcess,              (HANDLE process, unsigned retcode));
_TX_DLLIMPORT_OPT ("Kernel32", void,     FatalExit,                     (int retcode));
_TX_DLLIMPORT_OPT ("Kernel32", void,     FatalAppExitA,                 (unsigned action, const char message[]));
_TX_DLLIMPORT     ("Kernel32", DWORD,    GetThreadId,                   (HANDLE thread));
_TX_DLLIMPORT     ("Kernel32", HWND,     GetConsoleWindow,              (void));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     SetConsoleFont,                (HANDLE con, DWORD fontIndex));
_TX_DLLIMPORT_OPT ("Kernel32", DWORD,    GetNumberOfConsoleFonts,       (void));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     GetCurrentConsoleFont,         (HANDLE con, bool maxWnd, CONSOLE_FONT_INFO*   curFont));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     GetCurrentConsoleFontEx,       (HANDLE con, bool maxWnd, CONSOLE_FONT_INFOEX* curFont));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     SetCurrentConsoleFontEx,       (HANDLE con, bool maxWnd, CONSOLE_FONT_INFOEX* curFont));
_TX_DLLIMPORT_OPT ("Kernel32", void,     RtlCaptureContext,             (CONTEXT* contextRecord));
_TX_DLLIMPORT_OPT ("Kernel32", USHORT,   RtlCaptureStackBackTrace,      (DWORD framesToSkip, DWORD framesToCapture, void** backTrace, DWORD* hash));
_TX_DLLIMPORT_OPT ("Kernel32", void*,    AddVectoredExceptionHandler,   (unsigned long firstHandler, PVECTORED_EXCEPTION_HANDLER handler));
_TX_DLLIMPORT_OPT ("Kernel32", unsigned, RemoveVectoredExceptionHandler,(void* handler));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     GetModuleHandleEx,             (DWORD flags, const char moduleName[], HMODULE* module));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     IsWow64Process,                (HANDLE process, int* isWow64Process));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     Wow64GetThreadContext,         (HANDLE thread, WOW64_CONTEXT* context));
_TX_DLLIMPORT_OPT ("Kernel32", bool,     SetThreadStackGuarantee,       (unsigned long* stackSize));

_TX_DLLIMPORT     ("OLE32",    HRESULT,  CoInitialize,                  (void*));
_TX_DLLIMPORT     ("OLE32",    HRESULT,  CoCreateInstance,              (REFCLSID clsId, IUnknown*, DWORD, REFIID iId, PVOID* value));
_TX_DLLIMPORT     ("OLE32",    void,     CoUninitialize,                (void));

_TX_DLLIMPORT     ("Shell32",  HINSTANCE,ShellExecuteA,                 (HWND wnd, const char operation[], const char file[],
                                                                         const char parameters[], const char directory[], int showCmd));

_TX_DLLIMPORT     ("ShlWAPI",  char*,    StrStrIA,                      (const char    string[], const char    search[]));
_TX_DLLIMPORT     ("ShlWAPI",  char*,    StrStrIW,                      (const wchar_t string[], const wchar_t search[]));

_TX_DLLIMPORT_OPT ("NTDLL",    char*,    wine_get_version,              (void));
_TX_DLLIMPORT     ("NTDLL",    NTSTATUS, NtQueryInformationProcess,     (HANDLE process, int infoClass,
                                                                         void* processInfo, unsigned long szProcessInfo, unsigned long* szReturnInfo));

_TX_DLLIMPORT_CRT ("MSVCRT",   void,     exit,                          (int retcode));
_TX_DLLIMPORT_CRT ("MSVCRT",   void,     _cexit,                        (void));
_TX_DLLIMPORT_CRT ("MSVCRT",   unsigned, _fpreset,                      (void));
_TX_DLLIMPORT_CRT ("MSVCRT",   unsigned, _controlfp,                    (unsigned control, unsigned mask));
_TX_DLLIMPORT_CRT ("MSVCRT",   uintptr_t,_beginthread,                  (void (__cdecl* start_address) (void*), unsigned stack_size, void* arglist));
_TX_DLLIMPORT_CRT ("MSVCRT",   uintptr_t,_beginthreadex,                (void* security, unsigned stack_size, unsigned (__stdcall* start_address) (void*),
                                                                         void *arglist, unsigned init_flag, unsigned* thread_addr));
_TX_DLLIMPORT_CRT ("MSVCRT",   char*,    __unDName,                     (char* outStr, const char* mangledName, int outStrLen,
                                                                         void* (*mallocFunc) (size_t size), void (*freeFunc) (void *pointer),
                                                                         unsigned short flags));
_TX_DLLIMPORT_CRT ("MSVCRT",   unexpected_handler, set_unexpected,      (unexpected_handler handler));

_TX_DLLIMPORT_OPT ("OpenGL32", HDC,         wglGetCurrentDC,            (void));
_TX_DLLIMPORT_OPT ("OpenGL32", unsigned,    glGetError,                 (void));
_TX_DLLIMPORT_OPT ("Glu32",    const char*, gluErrorString,             (unsigned error));

_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     MiniDumpWriteDump,             (HANDLE process, DWORD processId, HANDLE file, MINIDUMP_TYPE dumpType,
                                                                         MINIDUMP_EXCEPTION_INFORMATION*   exceptionParam,
                                                                         MINIDUMP_USER_STREAM_INFORMATION* userStreamParam,
                                                                         MINIDUMP_CALLBACK_INFORMATION*    callbackParam));

_TX_DLLIMPORT_OPT ("DbgHelp*", DWORD,    SymSetOptions,                 (DWORD options));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymInitialize,                 (HANDLE process, const char userSearchPath[], bool invadeProcess));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymFromAddr,                   (HANDLE process, DWORD64 addr, DWORD64* offset, SYMBOL_INFO*     symbol));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymGetLineFromAddr64,          (HANDLE process, DWORD64 addr, DWORD*   offset, IMAGEHLP_LINE64* line));
_TX_DLLIMPORT_OPT ("DbgHelp*", DWORD64,  SymGetModuleBase64,            (HANDLE process, DWORD64 addr));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     SymCleanup,                    (HANDLE process));
_TX_DLLIMPORT_OPT ("DbgHelp*", void*,    SymFunctionTableAccess64,      (HANDLE process, DWORD64 addrBase));
_TX_DLLIMPORT_OPT ("DbgHelp*", bool,     StackWalk64,                   (DWORD arch, HANDLE process, HANDLE thread, STACKFRAME64* frame, void* ctxRecord,
                                                                         PREAD_PROCESS_MEMORY_ROUTINE64   readMemoryFunc,
                                                                         PFUNCTION_TABLE_ACCESS_ROUTINE64 tableAccessFunc,
                                                                         PGET_MODULE_BASE_ROUTINE64       getModuleBaseFunc,
                                                                         PTRANSLATE_ADDRESS_ROUTINE64     translateAddressFunc));
namespace MinGW {
_TX_DLLIMPORT_OPT ("MgwHelp*", DWORD,    SymSetOptions,                 (DWORD options));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymInitialize,                 (HANDLE process, const char userSearchPath[], bool invadeProcess));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymFromAddr,                   (HANDLE process, DWORD64 addr, DWORD64* offset, SYMBOL_INFO*     symbol));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymGetLineFromAddr64,          (HANDLE process, DWORD64 addr, DWORD*   offset, IMAGEHLP_LINE64* line));
_TX_DLLIMPORT_OPT ("MgwHelp*", DWORD64,  SymGetModuleBase64,            (HANDLE process, DWORD64 addr));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     SymCleanup,                    (HANDLE process));
_TX_DLLIMPORT_OPT ("MgwHelp*", void*,    SymFunctionTableAccess64,      (HANDLE process, DWORD64 addrBase));
_TX_DLLIMPORT_OPT ("MgwHelp*", bool,     StackWalk64,                   (DWORD arch, HANDLE process, HANDLE thread, STACKFRAME64* frame, void* ctxRecord,
                                                                         PREAD_PROCESS_MEMORY_ROUTINE64   readMemoryFunc,
                                                                         PFUNCTION_TABLE_ACCESS_ROUTINE64 tableAccessFunc,
                                                                         PGET_MODULE_BASE_ROUTINE64       getModuleBaseFunc,
                                                                         PTRANSLATE_ADDRESS_ROUTINE64     translateAddressFunc));
} // namespace MinGW
} // namespace Win32

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Internal function prototypes, macros and constants
//  @name    ��������� ���������� �������, ������� � ���������
//=================================================================================================================
//! @{

#ifndef TX_COMPILED

int              _txInitialize();
void             _txCleanup();

HWND             _txCanvas_CreateWindow      (const SIZE* size);

bool             _txCanvas_OnCREATE          (HWND wnd);
bool             _txCanvas_OnDESTROY         (HWND wnd);
bool             _txCanvas_OnCLOSE           (HWND);
bool             _txCanvas_OnPAINT           (HWND wnd);
bool             _txCanvas_OnKEYDOWN         (HWND wnd, WPARAM vk, LPARAM info);
bool             _txCanvas_OnCHAR            (HWND wnd, WPARAM ch, LPARAM info);
bool             _txCanvas_OnTIMER           (HWND wnd, WPARAM id);
bool             _txCanvas_OnMOUSEMOVE       (HWND wnd, WPARAM buttons, LPARAM coords);
bool             _txCanvas_OnMOUSELEAVE      (HWND wnd);
bool             _txCanvas_OnCREATEWND       (HWND wnd, WPARAM, LPARAM lpar);
bool             _txCanvas_OnDESTROYWND      (HWND wnd, WPARAM, LPARAM lpar);
bool             _txCanvas_OnCmdCONSOLE      (HWND wnd, WPARAM cmd);
bool             _txCanvas_OnCmdABOUT        (HWND wnd, WPARAM cmd);

unsigned WINAPI  _txCanvas_ThreadProc        (void* data);
LRESULT CALLBACK _txCanvas_WndProc           (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);

HDC              _txBuffer_Create            (HWND wnd = NULL, const POINT* size = NULL, HBITMAP bitmap = NULL,
                                              RGBQUAD** pixels = NULL) tx_nodiscard;
bool             _txBuffer_Delete            (HDC* dc);
bool             _txBuffer_Select            (HGDIOBJ obj, HDC dc = txDC());

HWND             _txConsole_Attach();
bool             _txConsole_OK() tx_nodiscard;
bool             _txConsole_Detach           (bool activate);
bool             _txConsole_Draw             (HDC dc);
bool             _txConsole_SetUnicodeFont();

const char*       txRegisterClass            (const char classId[], WNDPROC wndProc, unsigned style, int backBrush, int wndExtra);
HWND              txCreateExtraWindow        (CREATESTRUCT createData);
HICON            _txCreateTXIcon             (int size) tx_nodiscard;
int              _txSetFinishedText          (HWND wnd);
void             _txPauseBeforeTermination   (HWND canvas);
int              _txIsParentWaitable         (DWORD* parentPID = NULL) tx_nodiscard;
int              _txGetInput();

LRESULT CALLBACK _txPlayVideo_WndProc        (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar);
const char*      _txPlayVideo_FindVLC() tx_nodiscard;

bool             _txCreateShortcut           (const char shortcutName[],
                                              const char fileToLink[], const char args[] = NULL, const char workDir[] = NULL,
                                              const char description[] = NULL, int cmdShow = SW_SHOWNORMAL,
                                              const char iconFile[] = NULL, int iconIndex = 0, int fontSize = 0,
                                              COORD bufSize = ZERO (COORD), COORD wndSize = ZERO (COORD), COORD wndOrg = ZERO (COORD));

void*            _tx_DLGTEMPLATE_Create      (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                                              WORD controls, short x, short y, short cx, short cy,
                                              const char caption[], const char font[], WORD fontsize,
                                              const char menu[]) tx_nodiscard;

void*            _tx_DLGTEMPLATE_Add         (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                                              short x, short y, short cx, short cy,
                                              WORD id, const char wclass[], const char caption[]);

const char*      _txProcessError             (const char file[], int line, const char func[], unsigned color,
                                              const char msg[], va_list args);
void             _txOnTerminate();
void             _txOnUnexpected();
void             _txOnPureCall();
void             _txOnNewHandlerAnsi();
int              _txOnNewHandler             (size_t size);
void             _txOnSignal                 (int signal = 0, int fpe = 0);
BOOL WINAPI      _txOnConsoleCtrlEvent       (DWORD type);
void             _txOnSecurityError          (int code, void*);
void             _txOnSecurityErrorAnsi      (const char* msg, void* ptr, int code);
int              _txOnMatherr                (_exception* except);
void             _txOnInvalidParam           (const wchar_t* expr, const wchar_t* func, const wchar_t* file,
                                              unsigned line, uintptr_t);
int              _txOnAllocHook              (int type, void* data, size_t size, int use, long request,
                                              const unsigned char* file, int line);
int              _txOnRTCFailure             (int type, const char* file, int line, const char* module, const char* format, ...) tx_printfy (5);
int              _txOnErrorReport            (int type, const char* text, int* ret);
int               tx_glGetError              (int setError = INT_MIN);

void             _txOnCExit();
void             _txOnExit                   (int      retcode);
void             _txOnFatalExit              (int      retcode);
void             _txOnExitProcess            (unsigned retcode);
void             _txOnFatalAppExitA          (unsigned action, const char message[]);
bool             _txOnTerminateProcess       (HANDLE process, unsigned retcode);
LPTOP_LEVEL_EXCEPTION_FILTER WINAPI
                 _txOnSetUnhandledExceptionFilter (LPTOP_LEVEL_EXCEPTION_FILTER filter);
void             _txWatchdogTerminator       (void* timeout);  // Only Arnold-type series are supported, not T1000

long WINAPI      _txVectoredExceptionHandler (EXCEPTION_POINTERS* exc);
long WINAPI      _txUnhandledExceptionFilter (EXCEPTION_POINTERS* exc);
long             _txOnExceptionSEH           (EXCEPTION_POINTERS* exc, const char func[]);
intptr_t         _txDumpExceptionSEH         (char what[], intptr_t size, const EXCEPTION_RECORD* exc, const char func[]);
intptr_t         _txDumpExceptionObj         (char what[], intptr_t size, void* object, size_t sizeObj, const std::type_info* type);
intptr_t         _txDumpExceptionCPP         (char what[], intptr_t size, unsigned code = 0,
                                              unsigned params = 0, const ULONG_PTR info[] = NULL);

void             _txStackBackTrace           (const char file[] = "?", int line = 0, const char func[] = "?",
                                              bool readSource = true);
const char*      _txCaptureStackBackTrace    (int framesToSkip = 0, bool readSource = true,
                                              CONTEXT* context = NULL, EXCEPTION_POINTERS* exc = NULL, HANDLE thread = GetCurrentThread());
int              _txStackWalk                (int framesToSkip, size_t szCapture, void* capture[], CONTEXT* context = NULL,
                                              HANDLE thread = GetCurrentThread());
const char*      _txCaptureStackBackTraceTX  (int framesToSkip = 0, bool readSource = false);

const char*      _txSymPrintFromAddr         (void* addr = NULL, const char format[] = NULL, ...) tx_printfy (2);
bool             _txSymGetFromAddr           (void* addr, Win32::SYMBOL_INFO** symbol = NULL,
                                              Win32::IMAGEHLP_LINE64** line = NULL, const char** module = NULL,
                                              const char** source = NULL, int context = 2);
intptr_t         _txReadSource               (char buf[], intptr_t size, const char file[],
                                              int linStart = 0, int linEnd = INT_MIN, int linMark = INT_MIN);
bool             _txCreateMiniDump           (EXCEPTION_POINTERS* exc = NULL);

uintptr_t        _txSetProcAddress           (const char funcName[], uintptr_t newFunc, const char dllName[] = NULL,
                                              int useHotPatching = false, HMODULE module = NULL, bool debug = false);
bool             _txInDll() tx_nodiscard;
PROCESSENTRY32*  _txFindProcess              (unsigned pid = GetCurrentProcessId()) tx_nodiscard;
bool             _txKillProcess              (DWORD pid);
int              _txTaskKill                 (const char name[] /*= NULL*/, const char cmdLineSubstr[] /*= NULL*/, unsigned pid /*= 0*/);
bool             _txCheckSourceCP            (int needCP = _TX_CODEPAGE, bool verbose = true);
bool             _txGetCommandLine           (wchar_t cmdLine[], size_t szCmdLine, unsigned pid = _getpid());
IMAGE_NT_HEADERS*_txGetNtHeaders             (HMODULE module = GetModuleHandle (NULL)) tx_nodiscard;
bool             _txIsConsoleSubsystem();
const char*      _txAppInfo() tx_nodiscard;

#if defined (_CLANG_VER) && !defined (_MSC_VER)
void             _txLibCppDebugFunction      (std::__libcpp_debug_info const& info);
#endif

#endif // TX_COMPILED

inline bool      _txCanvas_OK                () tx_nodiscard;
int              _txCanvas_SetRefreshLock    (int count);

const char*      _txError                    (const char file[] = NULL, int line = 0, const char func[] = NULL, unsigned color = 0,
                                              const char msg[] = NULL, ...) tx_printfy (5);

bool             _txIsBadReadPtr             (const void* address);

intptr_t         _tx_snprintf_s              (char stream[], intptr_t size, const char format[], ...) tx_printfy (3);
intptr_t         _tx_vsnprintf_s             (char stream[], intptr_t size, const char format[], va_list arg);
void              txReopenStdio();

#if defined (__CYGWIN__)

int              _getch();
int              _putch (int ch);
int              _kbhit() tx_nodiscard;

#endif

//-----------------------------------------------------------------------------------------------------------------
// There are macros for __FILE__ and __LINE__ to work properly.

#if !defined (NDEBUG)

    #define  _TX_ARGUMENT_FAILED( cond )       ( !(cond) &&                                          \
                                                     (SetLastErrorEx (ERROR_BAD_ARGUMENTS, 0), 1) && \
                                                     (assert (cond), true) )

    #define  _TX_TXWINDOW_FAILED()             ( !txOK() &&                                          \
                                                     (SetLastErrorEx (ERROR_INVALID_DATA,  0), 1) && \
                                                     (TX_ERROR ("\a" "���� ��������� �� ������� ��� �� � �������."), 1) )

    #define  _TX_HDC_FAILED( dc )              ( !Win32::GetObjectType (dc) &&                       \
                                                     (SetLastErrorEx (ERROR_INVALID_DATA,  0), 1) && \
                                                     (TX_ERROR ("�������� \"%s\" �������. ��������, ���� ����� �� ������, " \
                                                                "��� ��� ���������, ��� �� ����������� ��������.", #dc), 1) )
    #define _TX_DEFAULT_HDC_FAILED(dc)         ( (!(dc) &&                                           \
                                                     _TX_TXWINDOW_FAILED()) || _TX_HDC_FAILED (dc) )

#else
    #define  _TX_ARGUMENT_FAILED( cond )       ( !(cond) &&                                          \
                                                     (SetLastErrorEx (ERROR_BAD_ARGUMENTS, 0), 1) )

    #define  _TX_TXWINDOW_FAILED()             ( !txOK() &&                                          \
                                                     (SetLastErrorEx (ERROR_INVALID_DATA,  0), 1) )

    #define  _TX_HDC_FAILED( dc )              ( !Win32::GetObjectType (dc) &&                       \
                                                     (SetLastErrorEx (ERROR_INVALID_DATA,  0), 1) )

    #define _TX_DEFAULT_HDC_FAILED(dc)         ( !(dc) &&                                            \
                                                     (SetLastErrorEx (ERROR_INVALID_DATA,  0), 1) )
#endif

//-----------------------------------------------------------------------------------------------------------------
// Take action in debug configuration only.
// Definition ({ expr; }) would be better, but MSVC rejects it. So sad. :'(

#if !defined (NDEBUG)
    #define  _TX_ON_DEBUG( code )              { code; }
#else
    #define  _TX_ON_DEBUG( code )              ;
#endif

//-----------------------------------------------------------------------------------------------------------------
// Invokes an error without location information. "$$" restores TX-related call location context

#define _TX_UNEXPECTED( ... )                  $$ _txError (NULL, 0, NULL, 0, ##__VA_ARGS__)

//-----------------------------------------------------------------------------------------------------------------
// Safe call of a function via its pointer

#define _TX_CALL(  func, param )               ( (func)? ((func) param) :       0 )
#define _TX_CALLv( func, param )               ( (func)? ((func) param) : (void)0 )

//-----------------------------------------------------------------------------------------------------------------
// This is a macro because cond is an expression and is not always a function. Lack of lambdas in pre-C++0x.

#define _txWaitFor( cond, time )               { for (DWORD _t = GetTickCount() + (time); \
                                                      !(cond) && GetTickCount() < _t;     \
                                                      Sleep (_txWindowUpdateInterval)) ;  \
                                                 if  (!(cond))                            \
                                                      _txTrace (__FILE__, __LINE__, NULL, "WARNING: Timeout: " #cond "."); }
//-----------------------------------------------------------------------------------------------------------------
// Detouring in case of SEH mechanism

#define _txSetJmp()                            ( setjmp (_txDumpExceptionObjJmp) == 0 )

#define _txClearJmp()                          { *(unsigned long long*) _txDumpExceptionObjJmp = 0; }

//-----------------------------------------------------------------------------------------------------------------
// IN and OUT are defined in WinDef.h to support Microsoft SAL. Remove them because they are often confused with user's code.

#if defined (IN)
    #undef  IN
#endif

#if defined (IN)
    #undef  OUT
#endif

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Internal global data
//! @name    ���������� ���������� ������
//
//           ������ �� ��������� � ��������� ��� �����, ��� ����, ����� ��� ������� �� ���� :)
//
//           ���� �� ������ ���� ���������� � ����������� TXLib.h ��� ������, �� �������� ��� � �� ������� ��� ��.
//           ����� ��� ������� ������ � ��������������� �����.
//
//           ������ ����������, �������� ��������� � ���������� ������� ��� ������� � ���, ��� �����.
//=================================================================================================================
//! @{

#ifndef TX_COMPILED

const int                      _TX_IDM_ABOUT               = 40000,      // �������������� ���������� ���� ����
                               _TX_IDM_CONSOLE             = 40001,
                               _TX_WM_CREATEWND            = 0x7FF0,     // ��������� ��� ��������/�����������
                               _TX_WM_DESTROYWND           = 0x7FF1;     // ���� � ������ Canvas

//-----------------------------------------------------------------------------------------------------------------

int                            _txInitialized              = _TX_NOINIT || _txInitialize();

volatile unsigned              _txCanaryFirst              = 0x776F656D; // A very system value

volatile unsigned              _txMainThreadId             = 0;          // ID ������, ��� ����������� main()
volatile HANDLE                _txMainThread               = NULL;       // ���������� ����� ������

volatile unsigned              _txCanvas_ThreadId          = 0;          // ID ������, ���������� ����� ������ TXLib
volatile HANDLE                _txCanvas_Thread            = NULL;       // ���������� ����� ������
volatile HWND                  _txCanvas_Window            = NULL;       // ���������� ���� ������ TXLib

HDC                            _txCanvas_BackBuf[2]        = {NULL,      // [0] Main TXLib in-memory DC, where user's pictures lies
                                                              NULL};     // [1] Image ready for auto-refresh, see txCanvas_OnPAINT()

RGBQUAD*                       _txCanvas_Pixels            = NULL;       // Memory buffer of _txCanvas_BackBuf[0]

HBITMAP                        _txStockBitmap              = NULL;       // Equivalent of GetStockObject (BITMAP),
                                                                         // see https://devblogs.microsoft.com/oldnewthing/20100416-00/?p=14313

CRITICAL_SECTION               _txCanvas_LockBackBuf       = {0,-1};     // Prevent simultaneous access to back buffer, see txLock()

UINT_PTR                       _txCanvas_RefreshTimer      = 1;          // Timer ID to redraw TXLib window
volatile int                   _txCanvas_RefreshLock       = 0;          // Blocks auto on-timer canvas update, see txBegin/txEnd

::std::vector<HDC>*            _txCanvas_UserDCs           = NULL;       // List of DCs allocated, for auto-free

volatile bool                  _txConsole_IsBlinking       = true;       // To blink or not to blink, that is the question.

bool                           _txConsole                  = false;      // Only first TXLib module in app can own the console
bool                           _txMain                     = false;      // First TXLib wnd opened (closing it terminates program)
bool                           _txIsDll                    = false;      // TXLib module is in DLL
volatile bool                  _txRunning                  = false;      // main() is still running
volatile bool                  _txExit                     = false;      // exit() is active

volatile POINT                 _txMousePos                 = {-1,-1};    // Ask Captn Obviouos about it. See txCanvas_OnMOUSE()
volatile unsigned              _txMouseButtons             = 0;

volatile WNDPROC               _txAltWndProc               = NULL;       // �������������� ������� �������. ��. txSetWindowsHook().

_tx_thread _txLoc              _txLoc::Cur                 = {};         // Execution point tracking and trace state, see "$" macro

volatile int                   _txErrors                   = 0;          // TX_ERROR calls sequental number
volatile int                   _txOGLError                 = 0;          // Last OpenGL error when using tx_glGetError()
volatile long                  _txSENumber                 = 0;          // SEH exceptions sequental number
volatile long                  _txSEFatalNumber            = 0;          // SEH fatal exceptions sequental number
char                           _txDumpSE [_TX_BUFSIZE]     = "";         // SEH dump data area
char                           _txTraceSE[_TX_HUGEBUFSIZE] = "";         // Stack trace data area

LPTOP_LEVEL_EXCEPTION_FILTER   _txPrevUEFilter             = NULL;       // Previous UnhandledExceptionFilter

jmp_buf                        _txDumpExceptionObjJmp      = {};         // Hook for _txDumpExceptionObj

const volatile uintptr_t       _txForceImport[]            = { (uintptr_t) ::TerminateProcess,              (uintptr_t) ::ExitProcess,
                                                               (uintptr_t) ::FatalExit,                     (uintptr_t) ::FatalAppExitA,
                                                               (uintptr_t) ::exit,                          (uintptr_t) Win32::_controlfp,
                                                               (uintptr_t) Win32::Polyline,                 (uintptr_t) Win32::PolyBezier,
                                                               (uintptr_t) Win32::RoundRect,                (uintptr_t) Win32::RemoveVectoredExceptionHandler,
                                                               (uintptr_t) Win32::PlgBlt,                   (uintptr_t) Win32::RtlCaptureStackBackTrace,
                                                               (uintptr_t) Win32::SymInitialize,            (uintptr_t) Win32::MinGW::SymInitialize,
                                                               (uintptr_t) Win32::SymSetOptions,            (uintptr_t) Win32::MinGW::SymSetOptions,
                                                               (uintptr_t) Win32::SymGetLineFromAddr64,     (uintptr_t) Win32::MinGW::SymGetLineFromAddr64,
                                                               (uintptr_t) Win32::SymFromAddr,              (uintptr_t) Win32::MinGW::SymFromAddr,
                                                               (uintptr_t) Win32::SymCleanup,               (uintptr_t) Win32::MinGW::SymCleanup,
                                                               (uintptr_t) Win32::SymGetModuleBase64,       (uintptr_t) Win32::MinGW::SymGetModuleBase64,
                                                               (uintptr_t) Win32::SymFunctionTableAccess64, (uintptr_t) Win32::MinGW::SymFunctionTableAccess64,
                                                               (uintptr_t) Win32::StackWalk64,              (uintptr_t) Win32::MinGW::StackWalk64,
                                                               (uintptr_t) Win32::StrStrIA,                 (uintptr_t) Win32::Wow64GetThreadContext };

volatile unsigned              _txCanaryLast               = 0x5E2E2E5E; // Another very system value

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

extern volatile unsigned _txCanaryFirst;
extern volatile unsigned _txCanaryLast;
extern volatile HWND     _txCanvas_Window;
extern volatile unsigned _txCanvas_ThreadId;
extern          HDC      _txCanvas_BackBuf[2];
extern          RGBQUAD* _txCanvas_Pixels;
extern volatile int      _txCanvas_RefreshLock;
extern volatile WNDPROC  _txAltWndProc;
extern volatile bool     _txExit;
extern volatile int      _txOGLError;

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          TXLib engine init/check/cleanup
//! @name    �������������/��������/���������� TXLib
//=================================================================================================================
//! @{

//-----------------------------------------------------------------------------------------------------------------
//{          Early initialization
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

int _txInitialize()
    {
    if (_txInitialized) return 1;
    _txInitialized = 1;

    #if defined (_TX_ALLOC_BREAK) && defined (_MSC_VER)  // See http://msdn.microsoft.com/en-us/library/w2fhc9a3%28v=vs.90%29.aspx
    _CrtSetBreakAlloc (_TX_ALLOC_BREAK);                 // and http://support.microsoft.com/ru-ru/kb/151585
    #endif

    #if defined (_TX_ALLOW_TRACE)
    _txLocLvlSet (1);
    #endif

    _TX_ON_DEBUG (OutputDebugString ("\n");
                  OutputDebugString (_TX_VERSION " - The Dumb Artist Library, " _TX_AUTHOR ": \"" __FILE__ "\" "
                                     "compiled " __DATE__ " " __TIME__ ", " _TX_BUILDMODE " mode, module: " _TX_MODULE "\n");
                  OutputDebugString ("\n"));

    _txMainThreadId = GetCurrentThreadId();
    _txMainThread   = OpenThread (THREAD_ALL_ACCESS, false, _txMainThreadId);

$3  _txIsDll = _txInDll();

$   if (!_txIsDll)
        {
$       _txConsole = ! FindAtom ("_txConsole");
$       (void)          AddAtom ("_txConsole");
        }

$   if (_txConsole)
        {
$       _txCheckSourceCP (_TX_CODEPAGE, true);

$       unsigned long stackSize = _TX_STACKSIZE;
$       _TX_CALL (Win32::SetThreadStackGuarantee, (&stackSize));

$       _txOnSignal();

$       if (!*_txLogName)
            {$ _tx_snprintf_s (_txLogName, sizeof (_txLogName) - 1, "%s.log", txGetModuleFileName()); }

$       if (!_txIsDll)
            {
$           _TX_CALL  (Win32::AddVectoredExceptionHandler, (1, (PVECTORED_EXCEPTION_HANDLER)  _txVectoredExceptionHandler));
$           _txPrevUEFilter = SetUnhandledExceptionFilter  (   (LPTOP_LEVEL_EXCEPTION_FILTER) _txUnhandledExceptionFilter);
            }

$       ::std::set_terminate             (_txOnTerminate);
$       ::std::set_new_handler           (_txOnNewHandlerAnsi);
$       _TX_CALL (Win32::set_unexpected, (_txOnUnexpected));

        #if defined (_CLANG_VER) && !defined (_MSC_VER)
$       ::std::__libcpp_debug_function = _txLibCppDebugFunction;
        #endif

$       SetConsoleCtrlHandler (_txOnConsoleCtrlEvent, true);

$       SetErrorMode (SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);

        #if defined (_MSC_VER)

$       _set_printf_count_output (1);

$       _set_new_handler (_txOnNewHandler);
$       _set_new_mode (1);

        #if !defined (_CLANG_VER)

$       _CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_CHECK_ALWAYS_DF | _CRTDBG_LEAK_CHECK_DF);
$       _CrtSetAllocHook (_txOnAllocHook);

$       unsigned mode = _CRTDBG_MODE_FILE;
$       if (_CrtSetReportHook2 (_CRT_RPTHOOK_INSTALL, (_CRT_REPORT_HOOK) _txOnErrorReport) > 0) mode = 0;

$       _CrtSetReportMode (_CRT_WARN,   _CRTDBG_MODE_DEBUG | mode);
$       _CrtSetReportMode (_CRT_ERROR,  _CRTDBG_MODE_DEBUG | mode | _CRTDBG_MODE_WNDW);
$       _CrtSetReportMode (_CRT_ASSERT, _CRTDBG_MODE_DEBUG | mode | _CRTDBG_MODE_WNDW);
$       _CrtSetReportFile (_CRT_WARN,   _CRTDBG_FILE_STDERR);
$       _CrtSetReportFile (_CRT_ERROR,  _CRTDBG_FILE_STDERR);
$       _CrtSetReportFile (_CRT_ASSERT, _CRTDBG_FILE_STDERR);

        #endif

$       _set_abort_behavior (_WRITE_ABORT_MSG, _WRITE_ABORT_MSG);
$       _set_abort_behavior (0,                _CALL_REPORTFAULT);

$       _RTC_SetErrorFunc              (_txOnRTCFailure);
$       _set_purecall_handler          (_txOnPureCall);
$       _set_invalid_parameter_handler (_txOnInvalidParam);

        #endif

        #if defined (__STDC_LIB_EXT1__)
$       ::std::set_constraint_handler_s (_txOnSecurityErrorAnsi);
        #endif

        #if !defined (__CYGWIN__) && defined (_GCC_VER) && (_GCC_VER >= 530) && !defined (i386)
$       __setusermatherr (_txOnMatherr);
        #endif

        #if !defined (__CYGWIN__)
$       _set_error_mode (_OUT_TO_MSGBOX | _OUT_TO_STDERR);
        #endif

$       HWND console = _txConsole_Attach();
$       SetWindowTextA (console, txGetModuleFileName (false));
        }

$   InitializeCriticalSection (&_txCanvas_LockBackBuf);

$   _txSetProcAddress ("ExitProcess",                 (uintptr_t) _txOnExitProcess,                 "KERNEL32.DLL");
$   _txSetProcAddress ("TerminateProcess",            (uintptr_t) _txOnTerminateProcess,            "KERNEL32.DLL");
$   _txSetProcAddress ("FatalExit",                   (uintptr_t) _txOnFatalExit,                   "KERNEL32.DLL");
$   _txSetProcAddress ("FatalAppExitA",               (uintptr_t) _txOnFatalAppExitA,               "KERNEL32.DLL");
$   _txSetProcAddress ("UnhandledExceptionFilter",    (uintptr_t) _txUnhandledExceptionFilter,      "KERNEL32.DLL", true);
$   _txSetProcAddress ("SetUnhandledExceptionFilter", (uintptr_t) _txOnSetUnhandledExceptionFilter, "KERNEL32.DLL");
$   _txSetProcAddress ("exit",                        (uintptr_t) _txOnExit);
$   _txSetProcAddress ("_cexit",                      (uintptr_t) _txOnCExit);

$   atexit (_txCleanup);

$   if (_txConsole)
        {
$       txSetConsoleAttr (FOREGROUND_LIGHTGRAY);

$       tx_fpreset();

$       srand ((unsigned) time (NULL));

$       SetLastError (0);
$       errno = 0;

        #if !defined (__CYGWIN__)
$       _doserrno = 0;
        #endif
        }

$   HDC dc = Win32::CreateCompatibleDC (NULL); dc asserted;
$   _txStockBitmap = (HBITMAP) Win32::SelectObject (dc, Win32::CreateCompatibleBitmap (dc, 1, 1)); _txStockBitmap asserted;
$   Win32::DeleteObject (Win32::SelectObject (dc, _txStockBitmap)) asserted;
$   Win32::DeleteDC (dc) asserted;

$   return 1;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCheckSourceCP (int needCP /*= _TX_CODEPAGE*/, bool verbose /*= true*/)
    {
$3  const char* sCodePage = NULL;
$   int codePage = 0;

$   switch (((unsigned const char*) "�") [0])
        {
        case 192: {$ codePage =  1251; sCodePage = "1251.";          break; }
        case 208: {$ codePage = 65001; sCodePage = "UTF-8.";         break; }
        case 128: {$ codePage =   866; sCodePage = "866.";           break; }
        case 225: {$ codePage = 20866; sCodePage = "KOI-8, waaat?!"; break; }
        default:  {$ codePage =    -1; sCodePage = "(Unknown)";      break; }
        }

$   if (codePage != needCP && verbose)
        {
$       *_txTraceSE = ' ';  // No stack trace please

$       _TX_UNEXPECTED ("\v\t" "\n\n" "WARNING: CHECK TXLib.h file CODEPAGE. Maybe it is %s It should be %d.\n\n"
                        "This is NOT an error of TXLib itself. Please note:\n\n"
                        "Do NOT copy-and-paste TXLib.h file contents into a new file and them save it inside your "
                        "IDE or editor. This can change original TXLib codepage (%d) to another one. Instead, DO "
                        "use copy / move / cut-and-paste operations in Windows Explorer (Far Manager etc) only. "
                        "Or, when you see TXLib.h being opened in browser, use 'Save as...' (Ctrl+S) command.\n\n"
                        "Now you should re-download TXLib.h file from the http://txlib.ru site.\n\n"
                        "You can continue, but Russian messages and symbols may appear unreadable.",
                        sCodePage, needCP, needCP);
        }

$   return (codePage == needCP);
    }

//-----------------------------------------------------------------------------------------------------------------

_tx_FARPROC _txDllImport (const char dllFileName[], const char funcName[], bool required /*= true*/)
    {
    if (_TX_ARGUMENT_FAILED (dllFileName && *dllFileName)) return NULL;
    if (_TX_ARGUMENT_FAILED (funcName    && *funcName))    return NULL;

    static char dllPaths [2][MAX_PATH] = {"", ""};

    if (!*dllPaths[0])
        {
        const char dllDir[]  = "\\Windows\\";

        // dllPaths[0] is relative to the TX Setup directory stored in the Registry

        char* path = dllPaths[0];

        txRegQuery ("HKCU\\Software\\TX Library", "ProductDir", path, MAX_PATH);
        strncat_s (path, MAX_PATH, dllDir, sizeof (dllDir) - 1);

        // dllPaths[1] is relative to TXib.h file used in compilation

        path = dllPaths[1];

        if (strchr (__FILE__, ':'))
            {
            strncpy_s (path, MAX_PATH, __FILE__, sizeof (__FILE__) - 1);
            }
        else
            {
            GetCurrentDirectory (MAX_PATH, path);
            strncat_s (path, MAX_PATH, "\\" __FILE__, sizeof ("\\" __FILE__) - 1);
            }

        if (char* dir = strrchr (path, '\\')) *dir = 0;

        strncat_s (path, MAX_PATH, dllDir, sizeof (dllDir) - 1);
        }

    char dllName[MAX_PATH] = "", dllArch[MAX_PATH] = "";
    const char* arch = (dllFileName? strchr (dllFileName, '*') : NULL);

    if (arch)
        {
        assert (arch >= dllFileName);

        strncpy_s (dllName, sizeof (dllName), dllFileName, (size_t) (arch - dllFileName));
        strncat_s (dllName, sizeof (dllName), arch+1, sizeof (dllName) - 1 - strlen (dllName));

        strncpy_s (dllArch, sizeof (dllArch), dllFileName, (size_t) (arch - dllFileName));
        strncat_s (dllArch, sizeof (dllArch), sizeof (void*) == 8? "64" : "32", 3);
        strncat_s (dllArch, sizeof (dllArch), arch+1, sizeof (dllArch) - 1 - strlen (dllArch));
        }
    else if (dllFileName)
        {
        strncat_s (dllName, sizeof (dllName), dllFileName, sizeof (dllName) - 1);
        }

    HMODULE   dll = GetModuleHandle (dllFileName);

    if (!dll) dll = GetModuleHandle (dllArch);
    if (!dll) dll = GetModuleHandle (dllName);

    for (int i = 0; !dll && i < (int) sizearr (dllPaths); i++)
        {
        char path [MAX_PATH] = "";
        strncpy_s (path, sizeof (path), dllPaths[i], sizeof (dllPaths[i]));
        size_t len = strlen (path);

        strncpy_s (path + len, sizeof (path) - len, dllArch, sizeof (dllArch));
        if (!dll) dll = LoadLibrary (path);

        strncpy_s (path + len, sizeof (path) - len, dllName, sizeof (dllName));
        if (!dll) dll = LoadLibrary (path);
        }

    if (!dll) dll = LoadLibrary (dllArch);
    if (!dll) dll = LoadLibrary (dllName);

    if (!dll  && required) TX_ERROR ("\a" "Cannot load library \"%s%s%s\".",
                                           dllName, (arch? "\" / \"" : ""), dllArch);
    if (!dll) return NULL;

    _tx_FARPROC addr = (_tx_FARPROC) GetProcAddress (dll, funcName);

    if (!addr && required) TX_ERROR ("\a" "Cannot import \"%s\" from library \"%s%s%s\".",
                                           funcName, dllName, (arch? "\" / \"" : ""), dllArch);
    return addr;
    }

//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER) && (_MSC_VER == 1800) // MSVC 2013
    #pragma warning (push)
    #pragma warning (disable: 6102)          // ������������� 'name' �� �������������� ������� ������ �������
#endif

int txRegQuery (const char* keyName, const char* valueName, void* value, size_t szValue)
    {
    if (_TX_ARGUMENT_FAILED (keyName)) return 0;

    HKEY hive = NULL;

    #define EQU_(name1, name2)  ( _strnicmp (keyName, name1 "\\", sizeof (name1)) == 0 || \
                                  _strnicmp (keyName, name2 "\\", sizeof (name2)) == 0 )

    if      (EQU_("HKLM", "HKEY_LOCAL_MACHINE"))  hive = HKEY_LOCAL_MACHINE;
    else if (EQU_("HKCU", "HKEY_CURRENT_USER"))   hive = HKEY_CURRENT_USER;
    else if (EQU_("HKCR", "HKEY_CLASSES_ROOT"))   hive = HKEY_CLASSES_ROOT;
    else if (EQU_("HKU",  "HKEY_USERS"))          hive = HKEY_USERS;
    else if (EQU_("HKCC", "HKEY_CURRENT_CONFIG")) hive = HKEY_CURRENT_CONFIG;

    else { _TX_ARGUMENT_FAILED (("keyName ������ ���������� � HKLM\\, HKCU\\, HKCR\\, HKU\\ ��� HKCC\\ ", hive)); return 0; }

    #undef EQU_

    keyName = strchr (keyName, '\\') + 1;

    HKEY  key  = NULL;
    DWORD size = 0;

    bool                               ok  = !!RegOpenKeyEx    (hive, keyName,   0, KEY_QUERY_VALUE, &key)         == ERROR_SUCCESS;
    if (ok)                            ok &= !!RegQueryValueEx (key,  valueName, NULL, NULL, NULL,          &size) == ERROR_SUCCESS;
    if (ok && value && size < szValue) ok &= !!RegQueryValueEx (key,  valueName, NULL, NULL, (BYTE*) value, &size) == ERROR_SUCCESS;
    if (key)                           ok &= !!RegCloseKey     (key);

    return size;
    }

#if defined (_MSC_VER) && (_MSC_VER == 1800)
    #pragma warning (pop)
#endif

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

HWND txCreateWindow (double sizeX, double sizeY, bool centered /*= true*/)
    {
$1  if (!_txInitialized) _txInitialized = _txInitialize();

$   if (HWND wnd = txWindow())
        {
$       SetLastErrorEx (ERROR_INVALID_DATA, 0);
$       _TX_ON_DEBUG (TX_ERROR ("\a" "���� ��������� ��� �������!"));
$       return wnd;
        }

$   if (!_txIsDll)
        {
$       _txMain = ! FindAtom ("_txMain");  // Not a thread-safe
$       (void)       AddAtom ("_txMain");
        }

$   if (_txWindowUpdateInterval < 10) {$ _txWindowUpdateInterval = 10; }

$   _txRunning = false;

    // Store the size

$   static SIZE size = { ROUND (sizeX), ROUND (sizeY) };
$   if (centered) { size.cx *= -1; size.cy *= -1; }

    // In Thread, where REAL creation lies...

$   unsigned id = 0;
$   _txCanvas_Thread = (HANDLE) Win32::_beginthreadex (NULL, 0, _txCanvas_ThreadProc, &size, 0, &id);

$   if (!_txCanvas_Thread) return TX_DEBUG_ERROR ("\a" "Cannot start canvas thread."),  (HWND) NULL;

$   _txWaitFor (_txRunning, 10*_TX_TIMEOUT);

$   if (!_txRunning)       return TX_DEBUG_ERROR ("\a" "Cannot create canvas window."), (HWND) NULL;
$   if (!txOK())           return TX_DEBUG_ERROR ("\a" "Canvas window is not OK."),     (HWND) NULL;

$   HWND console = Win32::GetConsoleWindow();

$   DWORD proc = 0;
$   GetWindowThreadProcessId (console, &proc);

$   if (console && (proc == GetCurrentProcessId() || _txIsParentWaitable()))
        {$ ShowWindow (console, _txConsoleMode); }

$   HMENU menu = GetSystemMenu (txWindow(), false);
    if (menu) {$ CheckMenuItem (menu, _TX_IDM_CONSOLE, (console? (IsWindowVisible (console)? MF_CHECKED : 0) : MF_DISABLED)); }

$   Win32::GdiSetBatchLimit (1);

$   SetLastError (0);

$   errno = 0;

    #if !defined (__CYGWIN__)
$   _doserrno = 0;
    #endif

$   return txWindow();
    }

//-----------------------------------------------------------------------------------------------------------------

HWND txCreateExtraWindow (CREATESTRUCT createData)
    {
$1  if (_TX_TXWINDOW_FAILED()) return NULL;

$   volatile HWND wnd = NULL;
$   createData.hInstance = (HINSTANCE)(uintptr_t) &wnd;

$   PostMessage (txWindow(), _TX_WM_CREATEWND, 0, (LPARAM) &createData) asserted;

$   _txWaitFor (wnd, 5*_TX_TIMEOUT);

$   return wnd;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSetDefaults (HDC dc /*= txDC()*/)
    {
$1  if (dc == txDC()) txUpdateWindow (false);
$   txAutoLock _lock;

$   RECT r = {};
$   GetClientRect (Win32::GetConsoleWindow(), &r) asserted;
$   SIZE szCon = { r.right - r.left, r.bottom - r.top };

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {{80, 25}, {}, 0, {0, 0, 80-1, 25-1}, {80, 25}};
$   GetConsoleScreenBufferInfo (out, &con);

$   SIZE szTxt = { (short) (con.srWindow.Right  - con.srWindow.Left + 1),
                   (short) (con.srWindow.Bottom - con.srWindow.Top  + 1) };

//{ Set defaults for graphics layer

$   _txBuffer_Select (Win32::GetStockObject (WHITE_PEN),   dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject (WHITE_BRUSH), dc) asserted;

$   _txBuffer_Select (Win32::CreateFont (szCon.cy/szTxt.cy, szCon.cx/szTxt.cx,
                                         0, 0, FW_REGULAR, FALSE, FALSE, FALSE,
                                         RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                         DEFAULT_QUALITY, FIXED_PITCH, _txConsoleFont),
                      dc) asserted;

$  (Win32::SetTextColor      (dc, TX_WHITE) != CLR_INVALID) asserted;
$   Win32::SetBkMode         (dc, TRANSPARENT)              asserted;

$   Win32::SetROP2           (dc, R2_COPYPEN)               asserted;
$   Win32::SetStretchBltMode (dc, HALFTONE)                 asserted;

//}

$   if (dc != txDC())
        {$ return true; }

//{ Set defaults for console  layer

$   POINT szCanvas = txGetExtent (dc);

$   HGDIOBJ font = txFontExist (_txConsoleFont)?
                       Win32::CreateFont (szCanvas.y/szTxt.cy, szCanvas.x/szTxt.cx,
                                          0, 0, FW_REGULAR, FALSE, FALSE, FALSE,
                                          RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                          DEFAULT_QUALITY, FIXED_PITCH, _txConsoleFont)
                       :
                       Win32::GetStockObject (SYSTEM_FIXED_FONT);

$   _txBuffer_Select (font, _txCanvas_BackBuf[1]);
//}

//{ Scroll the console for text to go above top of window and don't mix with graphics

$   if (con.dwCursorPosition.X) _putch ('\n');

$   short delta = (short) (con.dwCursorPosition.Y - con.srWindow.Top);

$   con.srWindow.Top    = (short) (con.srWindow.Top    + delta);
$   con.srWindow.Bottom = (short) (con.srWindow.Bottom + delta);

$   SMALL_RECT src  = { 0, 0, (short) (con.dwSize.X - 1), (short) (con.dwSize.Y - 1) };
$   CHAR_INFO  fill = { {' '}, FOREGROUND_LIGHTGRAY };
$   COORD      dest = { 0, (short) -delta };  // New UL-corner of src, scroll up

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

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

inline bool txOK()
    {
    return (_txCanaryFirst == 0x776F656D &&  // Too well-known values to use constants. You know these values, don't you?
            _txCanaryLast  == 0x5E2E2E5E &&
            _txCanvas_OK()

    #if defined (_MSC_VER)
         && _CrtCheckMemory()
    #endif
            );
    }

//-----------------------------------------------------------------------------------------------------------------
//{          Cleanup
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

// Implicit std(MSVCRT.dll)::_cexit() call before _txCleanup can lead to hangs in _cexit handlers chain.
// So redefining ::std::_cexit(). Do it dynamically via PE Import Table hook to avoid duplicate symbols
// if several modules linked together include TXLib.h. See _txSetProcAddress() call in _txInitialize().

void _txOnCExit()
    {
    OutputDebugString ("\n");
    txOutputDebugPrintf ("%s - WARNING: %s() called\n", _TX_VERSION, __func__);

$5  _txCleanup();

    txOutputDebugPrintf ("%s - WARNING: calling Win32::_cexit()\n", _TX_VERSION);
    _TX_CALLv (Win32::_cexit, ());
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnExit (int retcode)
    {
    if (retcode != 0)
        {
        OutputDebugString ("\n");
        txOutputDebugPrintf ("%s - WARNING: %s (%d) called\n", _TX_VERSION, __func__, retcode);
        }

$5  _txCleanup();

    if (retcode != 0)
        txOutputDebugPrintf ("%s - WARNING: calling Win32::exit (%d)\n", _TX_VERSION, retcode);

    Win32::exit (retcode);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnExitProcess (unsigned retcode)
    {
    if (retcode != 0)
        {
        OutputDebugString ("\n");
        txOutputDebugPrintf ("%s - WARNING: %s (%u) called\n", _TX_VERSION, __func__, retcode);
        }

$5  _txCleanup();

    if (retcode != 0)
        txOutputDebugPrintf ("%s - WARNING: calling Win32::ExitProcess (%u)\n", _TX_VERSION, retcode);

    Win32::ExitProcess (retcode);
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txOnTerminateProcess (HANDLE process, unsigned retcode)
    {
    if (retcode != 0)
        {
        OutputDebugString ("\n");
        txOutputDebugPrintf ("%s - WARNING: %s (0x%p, %u) called\n", _TX_VERSION, __func__, process, retcode);
        }

$5  _txCleanup();

    if (retcode != 0)
        txOutputDebugPrintf ("%s - WARNING: calling Win32::TerminateProcess (0x%p, %u)\n", _TX_VERSION, process, retcode);

    return Win32::TerminateProcess (process, retcode);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnFatalExit (int retcode)
    {
    OutputDebugString ("\n");
    txOutputDebugPrintf ("%s - WARNING: %s (%d) called\n", _TX_VERSION, __func__, retcode);

$5  _txCleanup();

    txOutputDebugPrintf ("%s - WARNING: calling Win32::FatalExit (%d)\n", _TX_VERSION, retcode);
    _TX_CALLv (Win32::FatalExit, (retcode));

    txOutputDebugPrintf ("%s - WARNING: Win32::FatalExit() failure, calling Win32::TerminateProcess (%d)\n", _TX_VERSION, retcode);
    Win32::TerminateProcess (GetCurrentProcess(), retcode);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnFatalAppExitA (unsigned action, const char message[])
    {
    OutputDebugString ("\n");
    txOutputDebugPrintf ("%s - WARNING: %s (%u, \"%s\") called\n", _TX_VERSION, __func__, action, message);

$5  _txCleanup();

    txOutputDebugPrintf ("%s - WARNING: calling Win32::FatalAppExitA (%u, %s)\n", _TX_VERSION, action, message);
    _TX_CALLv (Win32::FatalAppExitA, (action, message));

    txOutputDebugPrintf ("%s - WARNING: Win32::FatalExit() failure, calling Win32::TerminateProcess (EXIT_FAILURE)\n", _TX_VERSION);
    Win32::TerminateProcess (GetCurrentProcess(), EXIT_FAILURE);
    }

//-----------------------------------------------------------------------------------------------------------------

BOOL WINAPI _txOnConsoleCtrlEvent (DWORD type)
    {
    OutputDebugString ("\n");
    txOutputDebugPrintf ("%s - WARNING: %s (0x%04lX) called\n", _TX_VERSION, __func__, (unsigned long) type);

$5  switch (type)
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

$3  _txRunning = false;
$   _txConsole_IsBlinking = false;

$   HWND canvas     = txWindow();
$   HWND console    = Win32::GetConsoleWindow();
$   unsigned thread = GetCurrentThreadId();

$   HWND wnd        = (canvas)? canvas : console;

$   bool externTerm = (thread != _txMainThreadId &&
                       thread != _txCanvas_ThreadId);
$   DWORD parent = 0;
$   int  isParentWaitable = _txIsParentWaitable (&parent);
$   bool waitableParent   = !externTerm && isParentWaitable;

$   if (canvas)
        {$ txSleep (5*_txWindowUpdateInterval); }

$   if (_txConsole)
        {
$       if (_txMain) txSetConsoleAttr (FOREGROUND_LIGHTGRAY);
$       if (console) EnableWindow (console, true);
        }

$   if (_txMain && !externTerm && wnd != NULL)
        {$ _txSetFinishedText (wnd); }

$   _flushall();

$   bool paused = false;
$   if (((canvas? _txMain : _txConsole) && !_txExit) || (_txErrors && thread == _txMainThreadId))
        {
$       if (wnd)
            {
            if (isParentWaitable >= 0) {$ SetWindowPos (wnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW); }
$           EnableWindow (wnd, true);
            }

$       if (console && isParentWaitable >= 0)
            {
$           _txPauseBeforeTermination (canvas);
$           paused = true;
            }
        }

$   if (txWindow())
        {$ SendNotifyMessage (txWindow(), WM_DESTROY, 0, 0); }

$   _txWaitFor (!txWindow(), 5*_TX_TIMEOUT);

$   txSpeak     (NULL);
$   txPlayVideo (NULL);

$   if (GetCurrentThreadId() != _txMainThreadId)
        {$ SuspendThread (_txMainThread);    }
$   if (GetCurrentThreadId() != _txCanvas_ThreadId)
        {$ SuspendThread (_txCanvas_Thread); }

$   if (_txMainThread)
        {$ CloseHandle (_txMainThread)    asserted; _txMainThread    = NULL; }
$   if (_txCanvas_Thread)
        {$ CloseHandle (_txCanvas_Thread) asserted; _txCanvas_Thread = NULL; }

$   if (!txWindow())
        {$ DeleteCriticalSection (&_txCanvas_LockBackBuf); CRITICAL_SECTION zero = {0, -1}; _txCanvas_LockBackBuf = zero; }

$   console = Win32::GetConsoleWindow();

$   if (_txMain && _txConsole)
        {$ _txConsole_Detach (waitableParent && !externTerm); }

$   bool parentKilled = false;
$   if (waitableParent && paused && _txNOP (_TX_ALLOW_KILL_PARENT))
        {
$       parentKilled = _txKillProcess (parent);

$       parent = 0;
$       if (!parentKilled || _txIsParentWaitable (&parent))
            {$ PostMessage (console, WM_CHAR, '\n', 0); }
        }

$   std::cout.flush();
$   std::cerr.flush();
$   std::clog.flush();
$   _flushall();

$   _txSymGetFromAddr (NULL);

    _TX_ON_DEBUG (OutputDebugString ("\n");
                  OutputDebugString (_TX_VERSION " - FINISHED: " _TX_MODULE "\n");
                  OutputDebugString ("\n"));

$   if (parentKilled && _txWatchdogTimeout >= 0)
        {$ Win32::_beginthread (_txWatchdogTerminator, 0, &_txWatchdogTimeout); }
    }

//-----------------------------------------------------------------------------------------------------------------

int _txSetFinishedText (HWND wnd)
    {
    struct tools
        {
        static LRESULT getWindowText (HWND window, wchar_t text[], size_t size)
            {
$3          memset (text, 0, size * sizeof (*text));

$           return SendMessageTimeoutW (window, WM_GETTEXT, (WPARAM) size, (LPARAM) text, SMTO_BLOCK | SMTO_ABORTIFHUNG, _TX_TIMEOUT, NULL);
            }

        static LRESULT setWindowText (HWND window, wchar_t text[])
            {
$1          return SendMessageTimeoutW (window, WM_SETTEXT, 0,             (LPARAM) text, SMTO_BLOCK | SMTO_ABORTIFHUNG, _TX_TIMEOUT, NULL);
            }
        };

$1  static wchar_t title [_TX_BUFSIZE+15] = L"TXLib";

$   tools::getWindowText (wnd, title, _TX_BUFSIZE-1);
$   int len = (int) wcslen (title); if (len >= (int)_TX_BUFSIZE) len = _TX_BUFSIZE-1;

$   MultiByteToWideChar (_TX_CODEPAGE, 0, " [���������]", -1, title + len, (int)_TX_BUFSIZE - len);

$   tools::setWindowText (wnd, title);
$   tools::getWindowText (wnd, title, _TX_BUFSIZE-1);
$   if (len <= (int)_TX_BUFSIZE-1-2 && title [len+2] == (wchar_t) 0x0417 /* '�' */) return 0;

$   MultiByteToWideChar (_TX_CODEPAGE, 0, " [FINISHED]",  -1, title + len, (int)_TX_BUFSIZE - len);

$   tools::setWindowText (wnd, title);
$   tools::getWindowText (wnd, title, _TX_BUFSIZE-1);
$   if (len <= (int)_TX_BUFSIZE-1-2 && title [len+2] == /* 'F' */ (wchar_t) 0x0046) return 1;

$   return 2;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txPauseBeforeTermination (HWND canvas)
    {
$3  while (_kbhit()) (void)_getch();

$   CONSOLE_SCREEN_BUFFER_INFO con = {};
$   bool kbRedir = !GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);
$   bool kbWait  = (_txGetInput() == EOF);
$   bool wine    = !!Win32::wine_get_version;

$   if (kbWait && !canvas && !kbRedir && !wine)
        {
$       txSetLocale();

$       fprintf (stderr, (!_txErrors? "\n" "[������� ����� ������� ��� ����������]" :
                                      "\n" "[Press F to Pay Respects...]"));  // https://knowyourmeme.com/memes/press-f-to-pay-respects
$       fflush  (stderr);
        }

$   for (int i = 1; ; i++)
        {
$       Sleep (_txWindowUpdateInterval);

        if (!kbWait || (kbRedir && !canvas)) {$ break; }  // No need to run and hide

        if (!wine && _txGetInput() != EOF)   {$ break; }  // Somebody hit something.

        if (canvas && !_txCanvas_ThreadId)   {$ break; }  // There was a window, and now there is not.

        if (!Win32::GetConsoleWindow())      {$ break; }  // Console was destroyed

        if (_TX_CALL (Win32::GhostWindowFromHungWindow, (canvas)))
            {$ TX_ERROR ("��������� ������� � ����� ���������."); break; }

        if (canvas && _TX_CALL (Win32::IsHungAppWindow, (canvas)))
            {$ _txTrace (__FILE__, __LINE__, NULL, "WARNING: ���������-���� ������� � ����� ���������."); break; }

        if (canvas && !SendMessageTimeout (canvas, WM_NULL, 0,0, SMTO_BLOCK | SMTO_ABORTIFHUNG, _TX_TIMEOUT, NULL))
            {$ _txTrace (__FILE__, __LINE__, NULL, "WARNING: ��������� �� �������� � ����� ���������.");  break; }

        if (!wine && !(i % 100500))
            {$ fprintf (stderr, "\r" "[��� ������� �� �����-������ ������� ��� ����� ����������]"); }
        }

$   while (!wine && _kbhit()) (void)_getch();

$   fprintf (stderr, "\n");
    }

//-----------------------------------------------------------------------------------------------------------------

int _txGetInput()
    {
$4  HANDLE con = GetStdHandle (STD_INPUT_HANDLE);

$   DWORD nChars = 0;
$   if (GetConsoleMode (con, &nChars) == 0 &&
        PeekNamedPipe  (con, NULL, 0, NULL, &nChars, NULL))
        {
$       return (nChars)? fgetc (stdin) : EOF;
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

int _txIsParentWaitable (DWORD* parentPID /*= NULL*/)
    {
$4  PROCESSENTRY32* info = _txFindProcess();
$   if (!info) return 0;

$   info = _txFindProcess (info->th32ParentProcessID);
$   if (!info) return 0;

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

$           if (info) if (_stricmp (gp, info->szExeFile) == 0)  // Was &&, but MSVC /analyze is so paranoid
                {$ return islower ((unsigned char) *gp)? +1 : -1; }
            }
        else
            {
$           if (_stricmp (p, parent) == 0)
                {$ return islower ((unsigned char)  *p)? +1 : -1; }
            }
        }

$   return 0;
    }

//-----------------------------------------------------------------------------------------------------------------

void _txWatchdogTerminator (void* timeout)  // Or Watchcat? Possibly will change in future versions
    {
$3  if (_TX_ARGUMENT_FAILED (timeout)) return;

$   Sleep (*(int*) timeout);

$   OutputDebugString ("\n");
    txOutputDebugPrintf ("%s - WARNING: %s(): Timeout (%d) expired, activating. %s\n",  // Kinda static reflection...
                         _TX_VERSION, __func__, *(int*) timeout, ((__func__[8] == 'd')? "Bark, bark" : "Meow, meow"));
$   DWORD parent = 0;
$   if (_txIsParentWaitable (&parent))
        {
        txOutputDebugPrintf ("%s - WARNING: %s(): Calling _txKillProcess (0x%04lu)\n",
                             _TX_VERSION, __func__, (unsigned long) parent);

$       _txKillProcess (parent);

$       PostMessage (GetConsoleWindow(), WM_CHAR, '\n', 0);
        }

    txOutputDebugPrintf ("%s - WARNING: %s(): Calling Win32::TerminateProcess (EXIT_FAILURE)\n", _TX_VERSION, __func__);
$   Win32::TerminateProcess (GetCurrentProcess(), EXIT_FAILURE);
    }

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Tools
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

// You are here, little hacker?

int _txTaskKill (const char i[] /*= NULL*/,
                 const char doYouWantToFindSomethingInTheCommandLineIDidSomethingForYouToFindSomethingInTheCommandLineMaybeYouWillFindSomeInterestingInTheCommandLineSoIDidSomethingForYouInTheCommandLine[] /*= NULL*/,
                 unsigned   x   /*= 0*/)
    {
    // ...so tired of it already...

    #define name          i  // Great name!
    #define cmdLineSubstr doYouWantToFindSomethingInTheCommandLineIDidSomethingForYouToFindSomethingInTheCommandLineMaybeYouWillFindSomeInterestingInTheCommandLineSoIDidSomethingForYouInTheCommandLine
    #define pid           x  // Another great name, isn't it?

$3  if (_TX_ARGUMENT_FAILED ((name || cmdLineSubstr || pid) && "��� ����� ��� ���������� ����� �����������...")) return false;

$   wchar_t cmdLineSubstrW[_TX_BUFSIZE] = L"";
    if (cmdLineSubstr) {$ MultiByteToWideChar (_TX_CODEPAGE, 0, cmdLineSubstr, -1, cmdLineSubstrW, sizearr (cmdLineSubstrW)); }

$   HANDLE sshot = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, 0);
$   assert (sshot); if (!sshot) return 0;

$   int killed = 0;

$   PROCESSENTRY32 info = { sizeof (info) };
$   for (bool ok = !!Process32First (sshot, &info); ok; ok = !!Process32Next (sshot, &info))
        {
        bool kill = false;

        if (!kill && pid  && info.th32ParentProcessID        == pid) {$ kill = true; }

        if (!kill && name && _stricmp (info.szExeFile, name) == 0)   {$ kill = true; }

        if (!kill)
            {
            wchar_t cmdLineW[_TX_BUFSIZE] = L"";
            if (!_txGetCommandLine (cmdLineW, sizearr (cmdLineW), info.th32ProcessID)) { continue; }

            if (*cmdLineW && stristrw (cmdLineW, cmdLineSubstrW))    {$ kill = true; }
            }

        if (kill)
            {
$           if (_txKillProcess (info.th32ProcessID))
                {$ killed++; }
            }
        }

$   CloseHandle (sshot);

$   return killed;

    #undef name
    #undef cmdLine
    #undef pid
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txKillProcess (DWORD pid)
    {
$3  if (_TX_ARGUMENT_FAILED (pid)) return false;

$   HANDLE token = INVALID_HANDLE_VALUE;
$   OpenProcessToken (GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token) asserted;

$   LUID luid = {};
$   LookupPrivilegeValue (NULL, SE_DEBUG_NAME, &luid) asserted;

$   TOKEN_PRIVILEGES priv = { 1, {{{ luid.LowPart, luid.HighPart}, SE_PRIVILEGE_ENABLED }}};
$   TOKEN_PRIVILEGES old  = {};

$   DWORD oldSz = 0;
$   AdjustTokenPrivileges (token, false, &priv, sizeof (priv), &old, &oldSz) asserted;

$   HANDLE proc = OpenProcess (PROCESS_ALL_ACCESS, 0, pid);
$   if (!proc) return false;

$   bool ok = !!Win32::TerminateProcess (proc, 0);
$   CloseHandle (proc);

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

PROCESSENTRY32* _txFindProcess (unsigned pid /*= GetCurrentProcessId()*/)
    {
$4  static PROCESSENTRY32 info = { sizeof (info) };
$   if (!pid) return &info;

$   HANDLE sshot = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, 0);
$   assert (sshot); if (!sshot) return NULL;

$   for (bool ok = !!Process32First (sshot, &info); ok; ok = !!Process32Next (sshot, &info))
        if (info.th32ProcessID == pid) break;

$   CloseHandle (sshot);

$   return &info;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txGetCommandLine (wchar_t cmdLine[], size_t szCmdLine, unsigned pid /*= _getpid()*/)
    {
$4  if (_TX_ARGUMENT_FAILED (cmdLine))        return false;
$   if (_TX_ARGUMENT_FAILED (szCmdLine >= 2)) return false;

$   if (pid == (unsigned) _getpid())
        {
$       wcsncpy_s (cmdLine, szCmdLine, GetCommandLineW(), szCmdLine-1);
$       return true;
        }

$   HANDLE proc = OpenProcess (PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, pid);
    if (!proc) {$ return false; }

$   Win32::PROCESS_BASIC_INFORMATION pbi = {};
$   Win32::NtQueryInformationProcess (proc, 0 /*ProcessBasicInformation*/, &pbi, sizeof (pbi), NULL) == 0 asserted;

    // Should use ReadProcessMemory() because the info is actually in another address space

$   bool ok = true;

$   Win32::PEB peb = {};
    if (ok && pbi.PebBaseAddress)        {$ ok &= !!ReadProcessMemory (proc, pbi.PebBaseAddress,        &peb,    sizeof (peb),    NULL); }

$   Win32::RTL_USER_PROCESS_PARAMETERS params = {};
    if (ok && peb.ProcessParameters)     {$ ok &= !!ReadProcessMemory (proc, peb.ProcessParameters,     &params, sizeof (params), NULL); }

$   *cmdLine = 0;
    if (ok && params.CommandLine.Buffer) {$ ok &= !!ReadProcessMemory (proc, params.CommandLine.Buffer, cmdLine,
                                                                       MIN  (params.CommandLine.Length + 2, (int) (szCmdLine * sizeof (*cmdLine)) - 2),
                                                                       NULL); }
$   CloseHandle (proc) asserted;

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

#define RVA_(type, module, addr)  ( (type) ((uintptr_t) (module) + (uintptr_t) (addr)) )

IMAGE_NT_HEADERS* _txGetNtHeaders (HMODULE module /*= GetModuleHandle (NULL)*/)
    {
$4  assert (module);

$   IMAGE_DOS_HEADER* dosHdr = RVA_ (IMAGE_DOS_HEADER*, module, 0);
$   IMAGE_NT_HEADERS* ntHdr  = RVA_ (IMAGE_NT_HEADERS*, module, dosHdr->e_lfanew);

$   return (dosHdr->e_magic  == IMAGE_DOS_SIGNATURE &&
            ntHdr->Signature == IMAGE_NT_SIGNATURE)? ntHdr : NULL;
    }

//-----------------------------------------------------------------------------------------------------------------

// TXLib continues to hack the reality to make your life better, sweeter and easier

uintptr_t _txSetProcAddress (const char funcName[], uintptr_t newFunc, const char dllName[] /*= NULL*/, int useHotPatching /*= false*/,
                             HMODULE module /*= NULL*/, bool debug /*= false*/)
    {
$4  if (debug) txOutputDebugPrintf ("_txSetProcAddress (%s, 0x%p, %s, 0x%p):\n", funcName, (void*) newFunc, dllName, module);

$   if (_TX_ARGUMENT_FAILED (funcName)) return 0;
$   if (_TX_ARGUMENT_FAILED (newFunc))  return 0;

$   if (!module) module = GetModuleHandle (NULL);
$   if (!module) return 0;

$   HMODULE dll     = (dllName)? GetModuleHandle (dllName)       : NULL;
$   PROC    oldFunc = (dll)?     GetProcAddress  (dll, funcName) : NULL;

$   if (useHotPatching && oldFunc)
        {
$       const size_t jmpSz = 1 + sizeof (DWORD);  // sizeof (JMP rel instruction)

$       DWORD oldRights = 0;
$       if (!VirtualProtect ((void*)(uintptr_t) oldFunc, jmpSz, PAGE_EXECUTE_READWRITE, &oldRights)) return 0;

        // Overwrite oldFunc prolog with JMP trampoline to newFunc.
        // Calling oldFunc from any location will lead to newFunc call anyway.

$       *(BYTE*)  ((char*)(uintptr_t) oldFunc + 0) = 0xE9;  // JMP rel
$       *(DWORD*) ((char*)(uintptr_t) oldFunc + 1) = ((char*)(uintptr_t) newFunc - (char*)(uintptr_t) oldFunc - jmpSz) & 0xFFFFFFFF;

$       FlushInstructionCache (GetCurrentProcess(), (void*)(uintptr_t) oldFunc, jmpSz);

$       VirtualProtect ((void*)(uintptr_t) oldFunc, jmpSz, oldRights, &oldRights);

$       return (uintptr_t) oldFunc;
        }

//  For PE structure and Import Table format, e.g. see https://books.google.ru/books?id=ifQPC86G66sC&pg=PA255
//  and below through Figure 5-5, and/or http://www.brokenthorn.com/Resources/OSDevPE.html.

$   IMAGE_NT_HEADERS* ntHdr = _txGetNtHeaders (module);
    if (!ntHdr || (ntHdr ->OptionalHeader.Magic != IMAGE_NT_OPTIONAL_HDR_MAGIC)) {$ return 0; }

$   DWORD impOffset = ntHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
$   IMAGE_IMPORT_DESCRIPTOR* desc = RVA_ (IMAGE_IMPORT_DESCRIPTOR*, module, impOffset);

$   if (desc == (IMAGE_IMPORT_DESCRIPTOR*) ntHdr) return 0;

$   IMAGE_THUNK_DATA* thunk0 = NULL, * thunk1 = NULL;
$   char*  impDll  = NULL;
$   char*  impName = NULL;
$   void** impPtr  = NULL;
$   bool   found   = false;

    for (; desc->Name; desc++)
        {
$       impDll = RVA_ (char*, module, desc->Name);
$       if (dllName && _stricmp (impDll, dllName) != 0) continue;

$       for (thunk0 = RVA_ (IMAGE_THUNK_DATA*, module, desc->OriginalFirstThunk),
             thunk1 = RVA_ (IMAGE_THUNK_DATA*, module, desc->FirstThunk);

             thunk0 && thunk1 && thunk1->u1.Function;

             thunk0++,
             thunk1++)
            {
            impName = (char*) RVA_ (IMAGE_IMPORT_BY_NAME*, module, thunk0->u1.AddressOfData) -> Name;
            impPtr  = (void**)(uintptr_t)                         &thunk1->u1.Function;  // Should change it, so this is ptr

            if (debug) txOutputDebugPrintf ("[0x%p] %s!%s\n", *impPtr, impDll, impName);

            if ((oldFunc && (uintptr_t) oldFunc == (uintptr_t) *impPtr) ||
                (impName && _stricmp (funcName, impName) == 0))
                {
                found = true;
                break;
                }
            }

$       if (found) break;
        }

    if (debug) txOutputDebugPrintf ("_txSetProcAddress (%s, 0x%p, %s, 0x%p): %s\n\n",
                                    funcName, (void*) newFunc, dllName, module, (found? "FOUND" : "NOT found"));
$   if (!found) return 0;

$   DWORD rights = PAGE_READWRITE;
$   if (!VirtualProtect (impPtr, sizeof (*impPtr), rights, &rights)) return 0;

$   *(uintptr_t*) impPtr = newFunc;

$   VirtualProtect (impPtr, sizeof (*impPtr), rights, &rights);

$   return (uintptr_t) oldFunc;
    }

#undef RVA_

//-----------------------------------------------------------------------------------------------------------------

bool _txInDll()
    {
$4  MODULEENTRY32 mod = { sizeof (mod) };

$   HANDLE sshot = CreateToolhelp32Snapshot (TH32CS_SNAPMODULE, 0);
$   assert (sshot); if (!sshot) return false;

$   bool inDll = false;

$   for (bool ok = !!Module32First (sshot, &mod); ok; ok = !!Module32Next (sshot, &mod))
        {
$       if (!mod.modBaseAddr) continue;

$       IMAGE_NT_HEADERS* ntHdr = _txGetNtHeaders ((HMODULE) mod.modBaseAddr);

$       inDll = ntHdr && ((ntHdr->FileHeader.Characteristics & IMAGE_FILE_DLL) != 0);

$       if (In (std::nomeow, (BYTE*)(uintptr_t)_txInDll, mod.modBaseAddr, mod.modBaseAddr + mod.modBaseSize))
            {$ break; }
        }

$   CloseHandle (sshot);
$   return inDll;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txIsConsoleSubsystem()
    {
$4  IMAGE_NT_HEADERS* ntHdr = _txGetNtHeaders();

$   return  ntHdr &&
            ntHdr ->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR_MAGIC &&

           (ntHdr ->OptionalHeader.Subsystem == IMAGE_SUBSYSTEM_WINDOWS_CUI ||
            ntHdr ->OptionalHeader.Subsystem == IMAGE_SUBSYSTEM_POSIX_CUI);
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txIsBadReadPtr (const void* address)
    {
    MEMORY_BASIC_INFORMATION mbi = {};
    if (!VirtualQuery (address, &mbi, sizeof (mbi))) return true;

    if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS))  return true;  // Guard page -> bad ptr

    DWORD readRights = PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY;

    return !(mbi.Protect & readRights);
    }

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Internal TXLib window functions     (_txCanvas...)
//! @name    ���������� ������� ���� TXLib       (_txCanvas...)
//=================================================================================================================

#ifndef TX_COMPILED

unsigned WINAPI _txCanvas_ThreadProc (void* data)
    {
    #define SetClassLong_  SetClassLongPtr
    #define GCL_HICON_     GCLP_HICON
    #define GCL_HICONSM_   GCLP_HICONSM
    #define GCL_HCURSOR_   GCLP_HCURSOR

$8  _txCanvas_ThreadId = GetCurrentThreadId();

$   if (_TX_ARGUMENT_FAILED (data)) return false;

$   unsigned long stackSize = _TX_STACKSIZE;
$   _TX_CALL (Win32::SetThreadStackGuarantee, (&stackSize));

$   HWND wnd = _txCanvas_CreateWindow ((SIZE*) data);
$   if (!txWindow()) return TX_DEBUG_ERROR ("\a" "Cannot create canvas!"), 0;

$   HICON   icon32 = LoadIcon         (NULL, "_TX_ICON");
$   HICON   icon16 = LoadIcon         (NULL, "_TX_ICONSM");
$   HCURSOR cursor = LoadCursor       (NULL, "_TX_CURSOR");
$   HMENU   menu   = LoadMenu         (NULL, "_TX_MENU");
$   HACCEL  accel  = LoadAccelerators (NULL, "_TX_ACCELERATORS");

$   SetClassLong_ (wnd, GCL_HICON_,   (LONG_PTR) (icon32? icon32 : _txCreateTXIcon (32)));
$   SetClassLong_ (wnd, GCL_HICONSM_, (LONG_PTR) (icon16? icon16 : _txCreateTXIcon (16)));
$   SetClassLong_ (wnd, GCL_HCURSOR_, (LONG_PTR) (cursor? cursor : LoadCursor (NULL, IDC_ARROW)));

    if (menu) {$ SetMenu (wnd, menu); DrawMenuBar (wnd); }

$   Win32::GdiSetBatchLimit (1);

    _TX_ON_DEBUG (OutputDebugString (_TX_VERSION " - STARTED: " _TX_MODULE "\n"));

$   SetForegroundWindow (wnd);

$   ShowWindow          (wnd, SW_SHOW);
$   UpdateWindow        (wnd);

$   _txRunning = true;

$   MSG msg = {};
$   while (GetMessage (&msg, NULL, 0, 0))
        {
        if (!msg.hwnd) {$ continue; }

        if (accel && TranslateAccelerator (wnd, accel, &msg)) {$ continue; }

$       TranslateMessage (&msg);
$       DispatchMessage  (&msg);

$       Sleep (0);
        }

$   if (icon16) DestroyIcon (icon16);  // If Explorer is displaying Tray Notification, these
$   if (icon32) DestroyIcon (icon32);  // calls will possibly fail, and we'll get resource leak.

$   LeaveCriticalSection (&_txCanvas_LockBackBuf);

    _TX_ON_DEBUG (OutputDebugString (_TX_VERSION " - STOPPED: " _TX_MODULE "\n"));

$   if (_txWatchdogTimeout >= 0)
        {$ Win32::_beginthread (_txWatchdogTerminator, 0, &_txWatchdogTimeout); }

$   if (_txRunning && _txMain)         // Main window is destroyed but main() is still running.
        {                              // No chances for good termination, so use exit().
$       _txCleanup();
$       ::exit ((int) msg.wParam);
        }

$   _txCanvas_ThreadId = 0;
$   return true;

    #undef SetClassLong
    #undef GCL_HICON_
    #undef GCL_HICONSM_
    #undef GCL_HCURSOR_
    }

//-----------------------------------------------------------------------------------------------------------------

HWND _txCanvas_CreateWindow (const SIZE* sizePtr)
    {
$8  if (_TX_ARGUMENT_FAILED (sizePtr)) return NULL;

$   bool centered = false;
    if (sizePtr->cx < 0 && sizePtr->cy < 0) {$ centered = true; }

$   SIZE screen = { GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN) };
$   RECT rect   = { 0, 0, abs (sizePtr->cx), abs (sizePtr->cy) }; AdjustWindowRect (&rect, _txWindowStyle, false);
$   SIZE size   = { rect.right - rect.left, rect.bottom - rect.top };

$   const char* wndClass = txRegisterClass ("MAIN", _txCanvas_WndProc, CS_HREDRAW | CS_VREDRAW | CS_OWNDC, BLACK_BRUSH, 0);
$   if (!wndClass) return (HWND) NULL;

$   HWND wnd = CreateWindowEx (WS_EX_APPWINDOW, wndClass, txGetModuleFileName (false), _txWindowStyle | WS_CLIPCHILDREN,
                               centered? screen.cx/2 - size.cx/2 : CW_USEDEFAULT,
                               centered? screen.cy/2 - size.cy/2 : CW_USEDEFAULT,
                               size.cx, size.cy, NULL, NULL, NULL, NULL);
$   if (!wnd || !txWindow())
        {$ return TX_DEBUG_ERROR ("Cannot create canvas: CreateWindowEx() failed"), (HWND) NULL; }

$   HMENU menu = GetSystemMenu (txWindow(), false);
    if (!menu) {$ return txWindow(); }

$   AppendMenu (menu, MF_SEPARATOR, 0, NULL)                       asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_CONSOLE, "Show &Console") asserted;
$   AppendMenu (menu, MF_STRING, _TX_IDM_ABOUT,   "&About...")     asserted;

$   return txWindow();
    }

//-----------------------------------------------------------------------------------------------------------------

const char* txRegisterClass (const char classId[], WNDPROC wndProc, unsigned style, int backBrush, int wndExtra)
    {
$8  assert (classId);
$   assert (wndProc);

$   static char name[_TX_BUFSIZE] = "";
$   _tx_snprintf_s (name, sizeof (name) - 1, "/*---[TXLib]-[%s]------------ "
                                             _TX_VERSION "  " __FILE__ "  WndClass %08lX "
                                             "-------------[%s]-[TXLib]---*/",
                                             classId, (unsigned long) GetTickCount(), classId);
$   WNDCLASS wc      = { sizeof (wc) };

$   wc.lpszClassName = name;
$   wc.lpfnWndProc   = wndProc;
$   wc.style         = style;
$   wc.cbWndExtra    = (wndExtra + 1) * (int) sizeof (long);

$   wc.hCursor       = LoadCursor (NULL, IDC_ARROW);
$   wc.hbrBackground = (HBRUSH) Win32::GetStockObject (backBrush);

$   ATOM atom = RegisterClass (&wc);
    if (!atom) {$ TX_DEBUG_ERROR ("RegisterClass (\"%s\") failed", name); return 0; }

$   return (const char*)(uintptr_t) atom;
    }

//-----------------------------------------------------------------------------------------------------------------

int _txCanvas_SetRefreshLock (int count)
    {
$8  int oldCount = _txCanvas_RefreshLock;

$   _txCanvas_RefreshLock = count;

$   HWND wnd = txWindow();

$   if ((_txCanvas_RefreshLock <= 0 || oldCount <= 0) && wnd)
        {$ RedrawWindow (wnd, NULL, NULL, RDW_INVALIDATE | RDW_INTERNALPAINT | RDW_UPDATENOW); }

$   return oldCount;
    }

//-----------------------------------------------------------------------------------------------------------------

HICON _txCreateTXIcon (int size)
    {
$8  if (_TX_ARGUMENT_FAILED (size == 32 || size == 16)) return NULL;

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

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

inline bool _txCanvas_OK()
    {
    return _txCanvas_ThreadId   &&
           _txCanvas_Window     &&
           _txCanvas_BackBuf[0] &&
           _txCanvas_BackBuf[1] &&
           _txCanvas_Pixels;
    }

//}
//=================================================================================================================

//=================================================================================================================
//{          Main window event handlers          (_txCanvas_On...)
//! @name    ������� ��������� ����              (_txCanvas_On...)
//=================================================================================================================
//! @{

#ifndef TX_COMPILED

LRESULT CALLBACK _txCanvas_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
    {
#if defined (_TX_ALLOW_TRACE)

    int inTX = _txLoc::Cur.inTX++;

    if (_txLoc::Cur.trace) _txTrace (__FILE__, __LINE__, __TX_FUNCTION__, "%*s" "0x%X <- 0x%03X (0x%08X, 0x%08lX)",
                                     2 * (_txLoc::Cur.inTX - 1), "", wnd, msg, wpar, lpar);
    _txLoc::Cur.inTX = inTX;

#endif

$8  if (msg == WM_KEYDOWN && wpar == VK_F12 &&
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

    static bool bkErased = false;

    switch (msg)
        {
        case WM_CREATE:         {$     _txCanvas_OnCREATE     (wnd);                return 0; }

        case WM_CLOSE:          {$ if (_txCanvas_OnCLOSE      (wnd))  break;   else return 0; }
        case WM_DESTROY:        {$     _txCanvas_OnDESTROY    (wnd);                return 0; }

        case WM_ERASEBKGND:     {$ if (!bkErased) { bkErased = true;  break; } else return 1; }
        case WM_SIZE:           {$                  bkErased = false; break;                  }

        case WM_PAINT:          {$     _txCanvas_OnPAINT      (wnd);                return 0; }

        case WM_TIMER:          {$     _txCanvas_OnTIMER      (wnd, wpar);          return 0; }

        case WM_KEYDOWN:        {$     _txCanvas_OnKEYDOWN    (wnd, wpar, lpar);    return 0; }
        case WM_CHAR:           {$     _txCanvas_OnCHAR       (wnd, wpar, lpar);    return 0; }

        case WM_LBUTTONUP:
        case WM_LBUTTONDOWN:
        case WM_RBUTTONUP:
        case WM_RBUTTONDOWN:
        case WM_MBUTTONUP:
        case WM_MBUTTONDOWN:
        case WM_MOUSEMOVE:      {$     _txCanvas_OnMOUSEMOVE  (wnd, wpar, lpar);    return 0; }

        case WM_MOUSELEAVE:     {$     _txCanvas_OnMOUSELEAVE (wnd);                return 0; }

        case _TX_WM_CREATEWND:  {$     _txCanvas_OnCREATEWND  (wnd, wpar, lpar);    return 0; }
        case _TX_WM_DESTROYWND: {$     _txCanvas_OnDESTROYWND (wnd, wpar, lpar);    return 0; }

        default: break;
        }

    if (msg == WM_SYSCOMMAND) switch (wpar)
        {
        case _TX_IDM_ABOUT:     {$       _txCanvas_OnCmdABOUT   (wnd, wpar);        return 0; }
        case _TX_IDM_CONSOLE:   {$       _txCanvas_OnCmdCONSOLE (wnd, wpar);        return 0; }

        default: break;
        }

$   return DefWindowProc (wnd, msg, wpar, lpar);
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCREATE (HWND wnd)
    {
$8  if (_TX_ARGUMENT_FAILED (wnd)) return false;

$   _txCanvas_BackBuf[0] = _txBuffer_Create (wnd, NULL, NULL, &_txCanvas_Pixels); assert (_txCanvas_BackBuf[0]);
$   _txCanvas_BackBuf[1] = _txBuffer_Create (wnd, NULL, NULL, NULL);              assert (_txCanvas_BackBuf[1]);

$   if (!SetTimer (wnd, _txCanvas_RefreshTimer, _txWindowUpdateInterval, NULL)) _txCanvas_RefreshTimer = 0;
$   assert (_txCanvas_RefreshTimer);

$   _txCanvas_UserDCs = new ::std::vector <HDC>;

$   _txCanvas_Window = wnd;

$   txSetDefaults();

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnDESTROY (HWND wnd)
    {
$8  if (_TX_ARGUMENT_FAILED (wnd)) return false;

    // ���������� ��������� ����� ���������

$   PostQuitMessage (_txRunning? WM_DESTROY : EXIT_SUCCESS);

$   if (!_txCanvas_Window) return false;

    // Indicate that we are about to manually terminate

$   _txExit = true;

    // Lock GDI resources

$   bool locked = false;
$   _txWaitFor ((locked = txLock (false), locked), _TX_TIMEOUT);
$   if (!locked) TX_DEBUG_ERROR ("Cannot lock GDI to free resources");

    // ����������� ���������������� �������

$   if (_txCanvas_UserDCs && !_txCanvas_UserDCs->empty())
        {
$       txNotifyIcon (NIIF_ERROR, NULL, "�� ������ ���������� %d HDC.", (int) _txCanvas_UserDCs->size());
$       Sleep (_TX_TIMEOUT);

$       for (size_t i = 0; i < _txCanvas_UserDCs->size(); i++) _txBuffer_Delete (&_txCanvas_UserDCs->at (i));
$       _txCanvas_UserDCs->clear();
        }

$   delete _txCanvas_UserDCs; _txCanvas_UserDCs = NULL;

    // ����������� �������, ��������� � �����

$   if (_txCanvas_RefreshTimer) KillTimer (wnd, _txCanvas_RefreshTimer) asserted;

$   if (_txCanvas_BackBuf[1]) _txBuffer_Delete (&_txCanvas_BackBuf[1])  asserted;
$   if (_txCanvas_BackBuf[0]) _txBuffer_Delete (&_txCanvas_BackBuf[0])  asserted;
$   _txCanvas_Pixels = NULL;

$   txUnlock();

    // Indicate that we are destroyed

$   _txCanvas_Window = NULL;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCLOSE (HWND wnd)
    {
$8  if (_TX_ARGUMENT_FAILED (wnd)) return false;
$   if (!_txCanvas_OK())           return false;

$   if (_txMain && _txRunning &&
        txMessageBox ("������� main() �� ���������. ��������� ��� ��� ��������. �������� ��������?\n\n"
                      "����� ���������, ����� main() ���������� - ��� ������������ � ��������� ����.",
                      txGetModuleFileName (false), MB_YESNOCANCEL | MB_ICONSTOP) != IDYES) return false;
$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnTIMER (HWND wnd, WPARAM)
    {
$8  if (_TX_ARGUMENT_FAILED (wnd)) return false;

$   if (_txCanvas_RefreshLock > 0 || !_txRunning) return false;

$   InvalidateRect (wnd, NULL, false) asserted;
$   UpdateWindow   (wnd)              asserted;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnPAINT (HWND wnd)
    {
$8  if (_TX_ARGUMENT_FAILED (wnd)) return false;
$   if (!_txCanvas_OK())           return false;

$   bool forceRedraw = GetAsyncKeyState (VK_MENU)  && GetAsyncKeyState (VK_CONTROL) &&
                       GetAsyncKeyState (VK_SHIFT) && GetAsyncKeyState (VK_SNAPSHOT);

$   PAINTSTRUCT ps = {};
$   HDC wndDc = BeginPaint (wnd, &ps);
$   if (!wndDc) return false;

$   HDC dc0 = _txCanvas_BackBuf[0],
        dc1 = _txCanvas_BackBuf[1];

$   RECT r = {};
$   GetClientRect (wnd, &r) asserted;
$   POINT wndSize = { r.right - r.left, r.bottom - r.top };

$   POINT dcSize = txGetExtent (dc1);

$   if ((_txCanvas_RefreshLock <= 0 || forceRedraw) &&
        txLock (false))
        {
$       Win32::BitBlt   (dc1, 0, 0, dcSize.x, dcSize.y, dc0, 0, 0, SRCCOPY);

$       _txConsole_Draw (dc1);

$       txUnlock();
        }

    // Magic 100500 value is used to completely block screen refresh.
    // Since no value can be 100500 or above, this condition is always true and the refresh cannot be blocked IRL.
    // Do not use 100501 because it may lead to errors on some compilers and possible may crash the compilers
    // themselves.
    // Yes guys, with all your software installed. :(

$   if (_txCanvas_RefreshLock != 100500)
        {
        if (_txSwapBuffers)
            {
$           _txSwapBuffers    (wndDc, 0, 0, wndSize.x, wndSize.y, dc1, 0, 0, dcSize.x, dcSize.y, SRCCOPY);
            }
        else if (dcSize.x == wndSize.x && dcSize.y == wndSize.y)
            {
$           Win32::BitBlt     (wndDc, 0, 0, wndSize.x, wndSize.y, dc1, 0, 0,                     SRCCOPY);
            }
        else
            {
$           Win32::SetStretchBltMode (wndDc, HALFTONE);
$           Win32::StretchBlt (wndDc, 0, 0, wndSize.x, wndSize.y, dc1, 0, 0, dcSize.x, dcSize.y, SRCCOPY);
            }
        }

$   EndPaint (wnd, &ps) asserted;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnKEYDOWN (HWND, WPARAM vk, LPARAM info)
    {
$8  INPUT_RECORD evt = {};

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
$8  INPUT_RECORD evt = {};

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

bool _txCanvas_OnMOUSEMOVE (HWND wnd, WPARAM buttons, LPARAM coords)
    {
$8  if (_TX_ARGUMENT_FAILED (wnd)) return false;
$   if (!_txCanvas_OK())           return false;

$   if (_txMousePos.x == -1 && _txMousePos.y == -1)
        {
$       TRACKMOUSEEVENT track = { sizeof (track), TME_HOVER | TME_LEAVE, wnd, HOVER_DEFAULT };
$       TrackMouseEvent (&track);
        }

$   _txMousePos.x   = LOWORD (coords);
$   _txMousePos.y   = HIWORD (coords);
$   _txMouseButtons = (unsigned) buttons;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnMOUSELEAVE (HWND)
    {
$8  _txMousePos.x   = -1;
$   _txMousePos.y   = -1;
$   _txMouseButtons = 0;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCREATEWND (HWND, WPARAM, LPARAM lpar)
    {
$8  if (_TX_ARGUMENT_FAILED (lpar)) return false;

$   const CREATESTRUCT* create = (CREATESTRUCT*) lpar;

$   HWND wnd = CreateWindowEx (create->dwExStyle, create->lpszClass, create->lpszName, create->style,
                               create->x, create->y, create->cx, create->cy,
                               create->hwndParent, create->hMenu, NULL, create->lpCreateParams);

$   *(HWND*) create->hInstance = wnd;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnDESTROYWND (HWND, WPARAM, LPARAM lpar)
    {
$8  if (_TX_ARGUMENT_FAILED (lpar)) return false;

$   DestroyWindow ((HWND) lpar);

$   return false;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txCanvas_OnCmdCONSOLE (HWND wnd, WPARAM cmd)
    {
$8  if (_TX_ARGUMENT_FAILED (wnd)) return false;

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
$8  //{ Overriding the missing names, if the set is uncomplete

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
        #define __DESCRIPTION  "(��, ��� ���� ������ ��������)." "\n" "#define __DESCRIPTION to override project role.\n"
        #endif

        #ifndef __AUTHOR
        #define __AUTHOR       "(��������� ���)."                "\n" "#define __AUTHOR to override this name."
        #endif

    #endif
    //}

$   static char text[_TX_BUFSIZE] = "";

$   _tx_snprintf_s (text, sizeof (text) - 1,

                    "Application:\n\n"

                    #if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__AUTHOR)
                        __MODULE " version " __VERSION "\n" __DESCRIPTION "\n" "Copyright (c) " __AUTHOR "\n"
                    #else
                        "����� ����� �� ���� ���� ������� :)\n"
                        "#define __MODULE to \"your program name\" before including TXLib.h to use this billboard...\n"
                    #endif

                    "\n" "%s", _txAppInfo());

$   txMessageBox (text, "About " ABOUT_NAME_, MB_ICONINFORMATION);

    // And a bit of HTTP-code in C++ function:

    goto http;
    http://sizeof.livejournal.com

$   return true;

    #undef ABOUT_NAME_
    }

#endif // TX_COMPILED

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Console-support functions           (_txConsole...)
//! @name    ������� ����������� ����            (_txConsole...)
//=================================================================================================================
//! @{

#ifndef TX_COMPILED

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

$   txSetLocale();                                // ������������� ������� ������� �������� ��� ������� Windows

$   static bool done = false;
$   if (done) return console;

$   _txConsole_SetUnicodeFont();                  // ��������������� ����� ���� �� ��������.

$   if (!_txIsConsoleSubsystem())
        {$ txReopenStdio(); }                     // ������������� ������ �����-������, ���� subsystem != console

    // That's all, folks

$   done = true;
$   return console;
    }

//-----------------------------------------------------------------------------------------------------------------

int txSetLocale (int codepage /*= _TX_CODEPAGE*/,
                 const char locale[] /*= _TX_LOCALE*/, const wchar_t wLocale[] /*= _TX_WLOCALE*/)
    {
$1  int oldPage = GetConsoleOutputCP();

    // ������������� ������ ������� �������� ��� ������� Windows

$   if (codepage)
        {
$       SetConsoleCP       (codepage);
$       SetConsoleOutputCP (codepage);
        }

    // ������������� ������ ������� �������� ��� ����������� ����������, ����� �� ����� �������� Unicode-������
    // ������� (wprintf, ...). ���� ��������� � ������� gcc � ����������� ������������ L"unicode-������" � ������������
    // ������, ������� ����� � ��������� ������ ����������� g++: -finput-charset=NNNN -fexec-charset=NNNN, ��� NNNN -
    // ����������� ������� �������� (��������, ��� �������� ����� - CP1251).

$   if (locale)
        {
$       setlocale (LC_ALL,     locale);
$       setlocale (LC_NUMERIC, "C");              // Return to decimal point (3.14) instead of comma (3,14) in floating numbers
        }

    #ifndef __CYGWIN__

$   const bool wine = !!Win32::wine_get_version;  // Linux::Wine v1.2.2+ compatibility.

$   if (wLocale && !wine)
        {
$       _wsetlocale (LC_ALL,     wLocale);
$       _wsetlocale (LC_NUMERIC, L"C");           // L"C" (see above)
        }

    #endif

    (void) wLocale;

$   return oldPage;
    }

//-----------------------------------------------------------------------------------------------------------------

void txReopenStdio()
    {
$1  // ������������� ������ <s>�������</s> ������ �����-������

    #ifndef __CYGWIN__

$   *stdin  =                  *_fdopen (_open_osfhandle ((intptr_t) GetStdHandle (STD_INPUT_HANDLE),  _O_TEXT), "r");
$   fflush (stdout); *stdout = *_fdopen (_open_osfhandle ((intptr_t) GetStdHandle (STD_OUTPUT_HANDLE), _O_TEXT), "w");
$   fflush (stderr); *stderr = *_fdopen (_open_osfhandle ((intptr_t) GetStdHandle (STD_ERROR_HANDLE),  _O_TEXT), "w");

    #else
$                    *stdin  = *_fdopen (STDIN_FILENO,  "r");
$   fflush (stdout); *stdout = *_fdopen (STDOUT_FILENO, "w");
$   fflush (stderr); *stderr = *_fdopen (STDERR_FILENO, "w");

    #endif

$   setvbuf (stdin,  NULL, _IONBF, 0);
$   setvbuf (stdout, NULL, _IONBF, 0);
$   setvbuf (stderr, NULL, _IONBF, 0);

$   ::std::ios::sync_with_stdio();
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
$8  if (_TX_HDC_FAILED (dc)) return false;

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {};
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
        static WORD atr [_TX_BUFSIZE + 1] = {}; // [con.dwSize.X + 1]; maybe will be truncated
        COORD coord = { (short) (con.srWindow.Left), (short) (y + con.srWindow.Top) };
        DWORD read  = 0;

        if (!ReadConsoleOutputCharacter (out, chr, sizearr (chr) - 1, coord, &read)) continue;
        if (!ReadConsoleOutputAttribute (out, atr, sizearr (atr) - 1, coord, &read)) continue;

        for (int x = 0, xEnd = size.x; x < size.x; x = xEnd)
            {
            Win32::SetTextColor (dc, pal [ atr[x]       & 0x0F]);
            Win32::SetBkColor   (dc, pal [(atr[x] >> 4) & 0x0F]);
            Win32::SetBkMode    (dc,      (atr[x]       & 0xF0)? OPAQUE : TRANSPARENT);

            for (xEnd = x+1; xEnd < size.x && atr[xEnd] == atr[x]; xEnd++) {;}

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

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------
//{          Welcome to the Duck Side! Together we will rule the Bathroom!
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

bool _txConsole_SetUnicodeFont()
    {
$   const bool wine = !!Win32::wine_get_version;  // Linux::Wine v1.2.2+ compatibility.
                                                  // Beer compatibility may be added in future versions...
$   if (wine)                                     // �������� �� �������������: ���������� ������������ wine
        {                                         // ������ ������ ��������.
$       Win32::GetNumberOfConsoleFonts = NULL;
$       Win32::GetCurrentConsoleFont   = NULL;
$       Win32::SetConsoleFont          = NULL;

$       return false;
        }

    // ������� � ����� ��� ������...

$1  if (Win32::GetCurrentConsoleFontEx && Win32::SetCurrentConsoleFontEx)
        {
$       HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$       Win32::CONSOLE_FONT_INFOEX info = { sizeof (info) };
$       if (!Win32::GetCurrentConsoleFontEx (out, false, &info)) return false;

$       info.FontFamily = 0x36;                                                    // Unicode fixed-pitch
$       if (!*info.FaceName) info.dwFontSize.Y = (SHORT) (info.dwFontSize.Y + 2);  // Terminal font is too small

$       if (wcsncmp (info.FaceName, L"Consolas", sizearr (info.FaceName)) != 0)    // Consolas is allowed too
            {$ wcsncpy_s (info.FaceName, sizearr (info.FaceName), L"Lucida Console", sizearr (info.FaceName)); }

$       return !!Win32::SetCurrentConsoleFontEx (out, false, &info);
        }

    // ...� �� ����� ��� �� ��� ������

$   const unsigned uniFont = 10;                  // The Internet and W2K sources know this magic number
$   const unsigned uniSize = 20;                  // Size of the font desired, should be > max # of Raster Fonts
$   bool ok = true;

    // Force Windows to use Unicode font by creating and run the console shortcut tuned to use that font.

$   HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   unsigned fonts = _TX_CALL (Win32::GetNumberOfConsoleFonts, ());
$   if (fonts && fonts <= uniFont)
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
        if (ok) {$ _txWaitFor (FindWindow (NULL, "~txLink"), _TX_TIMEOUT); }

$       (void) _unlink (link);

$       if (init == S_OK) Win32::CoUninitialize();
        }

    // If Unicode font is not already set, do set it.

$   Win32::CONSOLE_FONT_INFO cur = {};
$   _TX_CALL (Win32::GetCurrentConsoleFont, (out, false, &cur));

$   ok &= (cur.nFont >= uniFont);
    if (!ok) {$ ok &= _TX_CALL (Win32::SetConsoleFont, (out, uniFont)); }

$   HWND console = Win32::GetConsoleWindow();
$   InvalidateRect (console, NULL, false);
$   UpdateWindow   (console);

$   return ok;
    }

#endif // TX_COMPILED

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

// ���� �� ���������

#ifndef TX_COMPILED

bool _txCreateShortcut (const char shortcutName[],
                        const char fileToLink[], const char args[] /*= NULL*/, const char workDir[] /*= NULL*/,
                        const char description[] /*= NULL*/, int cmdShow /*= SW_SHOWNORMAL*/, const char iconFile[] /*= NULL*/, int iconIndex /*= 0*/,
                        int fontSize /*= 0*/, COORD bufSize /*= ZERO (COORD)*/, COORD wndSize /*= ZERO (COORD)*/, COORD wndOrg /*=ZERO (COORD)*/)
    {
$1  if (_TX_ARGUMENT_FAILED (shortcutName && *shortcutName)) return false;
$   if (_TX_ARGUMENT_FAILED (fileToLink   && *fileToLink))   return false;

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

            FOREGROUND_LIGHTGRAY,                       // wFillAttribute
            FOREGROUND_MAGENTA | BACKGROUND_WHITE,      // wPopupFillAttribute
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

           {0x000000, 0x800000, 0x008000, 0x808000, 0x000080, 0x800080, 0x008080, 0xC0C0C0,  // Palette
            0x808080, 0xFF0000, 0x00FF00, 0xFFFF00, 0x0000FF, 0xFF00FF, 0x00FFFF, 0xFFFFFF}
            };

$       _TX_CHECKED (dataList->AddDataBlock (&props));

$       _TX_CHECKED (shellLink->QueryInterface (Win32::IID_IPersistFile, (void**) &file));
$       if (!file) _TX_FAIL;

$       wchar_t wName[MAX_PATH] = L"";
$       MultiByteToWideChar (_TX_CODEPAGE, 0, shortcutName, -1, wName, MAX_PATH) || ZeroMemory (wName, sizeof (wName));

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

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Memory DC functions                 (_txBuffer...)
//! @name    ������� "����.������" (����.������) (_txBuffer...)
//=================================================================================================================
//! @{

#ifndef TX_COMPILED

HDC _txBuffer_Create (HWND wnd, const POINT* size /*= NULL*/, HBITMAP bitmap /*= NULL*/, RGBQUAD** pixels /*= NULL*/)
    {
$1  txAutoLock _lock;

$   HDC wndDC = GetDC (wnd);
$   if (!wndDC) return NULL;

$   POINT sz = { 1, 1 };
$   if (size) sz = *size;

$   if (!size && wnd)
        {
$       RECT r = {};
$       GetClientRect (wnd, &r) asserted;

$       sz.x = r.right  - r.left;
$       sz.y = r.bottom - r.top;
        }

$   if (bitmap)
        {
$       BITMAP bmap = {};
$       Win32::GetObject (bitmap, sizeof (bmap), &bmap) asserted;

$       sz.x = bmap.bmWidth;
$       sz.y = bmap.bmHeight;
        }

$   HDC dc = Win32::CreateCompatibleDC (wndDC);
$   if (!dc) TX_DEBUG_ERROR ("Cannot create buffer: CreateCompatibleDC() failed");

$   BITMAPINFO info = {{ sizeof (info), sz.x, sz.y, 1, WORD (sizeof (RGBQUAD) * 8), BI_RGB }};

$   HBITMAP bmap = bitmap? bitmap : Win32::CreateDIBSection (NULL, &info, DIB_RGB_COLORS, (void**) pixels, NULL, 0);
$   if (!bmap) TX_DEBUG_ERROR ("Cannot create buffer: CreateCompatibleBitmap() failed");

$   Win32::SelectObject (dc, bmap) asserted;

$   if (!bitmap) Win32::PatBlt (dc, 0, 0, sz.x, sz.y, BLACKNESS) asserted;

$   ReleaseDC (wnd, wndDC) asserted;

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txBuffer_Delete (HDC* dc)
    {
$1  if (_TX_ARGUMENT_FAILED (dc)) return false;
$   if (!*dc) return false;

$   if (_TX_HDC_FAILED (*dc)) return false;

$   if (!Win32::GetObjectType (Win32::GetCurrentObject (*dc, OBJ_BITMAP))) return false;

$   txAutoLock _lock;

$   _txBuffer_Select (Win32::GetStockObject (NULL_PEN),    *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject (NULL_BRUSH),  *dc) asserted;
$   _txBuffer_Select (Win32::GetStockObject (SYSTEM_FONT), *dc) asserted;
$   _txBuffer_Select (_txStockBitmap,                      *dc);

$   Win32::DeleteObject (Win32::GetCurrentObject (*dc, OBJ_BITMAP)) asserted;

$   Win32::DeleteDC (*dc) asserted;

$   *dc = NULL;

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool _txBuffer_Select (HGDIOBJ obj, HDC dc /*= txDC()*/)
    {
$1  if (_TX_ARGUMENT_FAILED (obj)) return false;
$   if (_TX_HDC_FAILED      (dc))  return false;

$   if (!Win32::GetObjectType (obj)) TX_DEBUG_ERROR ("Invalid GDI object type");

$   txAutoLock _lock;

$   obj = Win32::SelectObject (dc, obj);
$   if (obj) Win32::DeleteObject (obj);

$   return obj != NULL;
    }

#endif // TX_COMPILED

//! @}
//}
//=================================================================================================================

//=================================================================================================================
//{          Diagnostics
//! @name    �����������
//=================================================================================================================
//! @{

#ifndef TX_COMPILED

const char* _txError (const char file[] /*= NULL*/, int line /*= 0*/, const char func[] /*= NULL*/, unsigned color /*= 0*/,
                      const char msg [] /*= NULL*/, ...)
    {                                                                        //---/\---/\-------��� ASCII KOT!--//
$1  va_list arg; va_start (arg, msg);                                        //  {  '-'  }                      //
$$  const char* what = _txProcessError (file, line, func, color, msg, arg);  //  {  0 0  }     ������ ��� ����  //
    va_end (arg);                                                            //  --> V <--  � ��������, � ����  //
                                                                             //   \ \|/ /      �����, �������,  //
    if (!(msg && msg[0] == '\a')) return what;                               //    \___/  ������� ������������  //
                                                                             //---------------������� ������:)--//
//  vvvvvvvvvvvvvvvvvv
    DebugBreak();   // >>> ������, �� � ���������. �� ���������. ���� ���� ���������� ���������� � �����������.
//  ^^^^^^^^^^^^^^^^^^

    return what;    // >>> ������� �� ������� ��������� �������� (F10/F11). ������� �� ������ ������� (Alt+7).
    }

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------
//{          General runtime check hooks
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

void _txOnSignal (int sig /*= 0*/, int fpe /*= 0*/)
    {
$1  if (!sig && !fpe)
        {
$       signal (SIGSEGV, (void(*)(int))(uintptr_t)_txOnSignal) != SIG_ERR asserted;
$       signal (SIGFPE,  (void(*)(int))(uintptr_t)_txOnSignal) != SIG_ERR asserted;
$       signal (SIGABRT, (void(*)(int))(uintptr_t)_txOnSignal) != SIG_ERR asserted;
$       signal (SIGILL,  (void(*)(int))(uintptr_t)_txOnSignal) != SIG_ERR asserted;
$       signal (SIGTERM, (void(*)(int))(uintptr_t)_txOnSignal) != SIG_ERR asserted;
$       return;
        }

    txOutputDebugPrintf ("%s - WARNING: %s (%d, %d) called\n", _TX_VERSION, __func__, sig, fpe);

    #define GET_DESCR_(str, code, descr)  case (code): {$ (str) = " " #code ": " descr; break; }

$   const char* sSig = "����������� ��� �������";

$   switch (sig)
        {
        GET_DESCR_ (sSig, SIGSEGV, "������ �� ��������� ���������. ������� �������!")
        GET_DESCR_ (sSig, SIGILL,  "������� ��������� ������������ ��������. ��������� ��������� �� �������.")
        GET_DESCR_ (sSig, SIGABRT, "��������� ���������� ���������, ������� ������� abort().")
        GET_DESCR_ (sSig, SIGTERM, "������� ������ ��������������� ���������� ���������.")
        GET_DESCR_ (sSig, SIGFPE,  "������ ������ � �����������.")
        default:   break;
        }

$   const char* sFPE = "";

    #if defined (_MSC_VER)

    // MSVC provides the FPE code as a MS extension.
    // See: https://msdn.microsoft.com/ru-ru/library/xdkz3x12.aspx

$   if (sig == SIGFPE) switch (fpe)
        {
        GET_DESCR_ (sFPE, _FPE_INVALID,        "��������� �������.")
        GET_DESCR_ (sFPE, _FPE_DENORMAL,       "��������������.")
        GET_DESCR_ (sFPE, _FPE_ZERODIVIDE,     "������� �� ����.")
        GET_DESCR_ (sFPE, _FPE_OVERFLOW,       "��������� ������� �������.")
        GET_DESCR_ (sFPE, _FPE_UNDERFLOW,      "��������� ������� ���������.")
        GET_DESCR_ (sFPE, _FPE_INEXACT,        "��������� �������.")
        GET_DESCR_ (sFPE, _FPE_UNEMULATED,     "�������� �� ��������������.")
        GET_DESCR_ (sFPE, _FPE_SQRTNEG,        "���������� ������ �� �������������� �����.")
        GET_DESCR_ (sFPE, _FPE_STACKOVERFLOW,  "������������ ����� ������������.")
        GET_DESCR_ (sFPE, _FPE_STACKUNDERFLOW, "� ����� ������������ �� ������� ������.")
        GET_DESCR_ (sFPE, _FPE_EXPLICITGEN,    "����� ����� ����������.")
        default:   break;
        }

    #else
$   fpe = 0;
    #endif

    #undef GET_DESCR_

$   signal (sig, (void(*)(int))(uintptr_t)_txOnSignal);

$   Win32::_fpreset();

$   _TX_UNEXPECTED ("\a\t"
                    "signal (%d, 0x%02X):%s%s "
                    "%s%s"
                    "� ������� ������� signal() �� ������ ���� ���������� ��� ������.",
                    sig, (unsigned) fpe, sSig, sFPE,
                    ((_txDumpSE[1] == '\n')? "" : "\n\n"), _txDumpSE + 1);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnTerminate()
    {
    txOutputDebugPrintf ("%s - WARNING: %s() called\n", _TX_VERSION, __func__);

    // From: http://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/libsupc%2B%2B/vterminate.cc

$1  static int terminating = 0;
    if (terminating++) {$ _TX_UNEXPECTED ("\a" "std::terminate() ������� ����������."); return; }

$   if (!*_txDumpSE)
        {$ _txDumpExceptionCPP (_txDumpSE + 1, sizeof (_txDumpSE) - 2); }

$   _TX_UNEXPECTED ("\t\a"
                    "std::terminate(): ��������������� ���������� � ������� main() ��� � �����������, "
                    "��� ������ ��������� ������ C++. "
                    "%s"
                    "����������� try/catch �����, �������������� catch (...), ���������� ������ ����������� �������, "
                    "������������, � ��� ����.\n\n"
                    "� ������� std::set_terminate() �� ������ ���� ���������� ��� ������." + !*_txDumpSE,
                    _txDumpSE + 1);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnUnexpected()
    {
    txOutputDebugPrintf ("%s - WARNING: %s() called\n", _TX_VERSION, __func__);

$1  if (!*_txDumpSE)
        {$ _txDumpExceptionCPP (_txDumpSE + 1, sizeof (_txDumpSE) - 2); }

$   _TX_UNEXPECTED ("std::unexpected(): �������������� ����������.\n\n"
                    "��������� ���� catch-�����. ����������� catch (...). ���� �� (���) ����������� "
                    "������������ ���������� ��� �������, ���������, �� �������� �� ���."
                    "%s"
                    "� ������� catch (...) � main() �� ������ ���� ���������� ��� ������.",
                    _txDumpSE + 1);
    }

//-----------------------------------------------------------------------------------------------------------------

int _txOnMatherr (_exception* exc)
    {
    txOutputDebugPrintf ("%s - WARNING: %s (0x%p) called\n", _TX_VERSION, __func__, exc);

$1  assert (exc);

    const char* sType = "����������� ��� ����������";

    #if !defined (__CYGWIN__)

    #define GET_DESCR_(code, descr)  case (code): {$ sType = "(" #code "): " descr; break; }

$   switch (exc->type)
        {
        GET_DESCR_ (_DOMAIN,    "��������� ������� �����������");
        GET_DESCR_ (_SING,      "������������� ���������");
        GET_DESCR_ (_PLOSS,     "��������� ������ ����������");
        GET_DESCR_ (_TLOSS,     "������ ������ ����������");
        GET_DESCR_ (_OVERFLOW,  "��������� ������� �������");
        GET_DESCR_ (_UNDERFLOW, "��������� ������� ���������");
        default:   break;
        }

    #undef GET_DESCR_

$   _TX_UNEXPECTED ("_matherr(): �������������� ������ %d %s � ������� %s (%lg, [%lg]). ��� ������ �������� %lg.\n\n"
                    "� ������� __setusermatherr() �� ������ ���� ���������� ��� ������.",
                    exc->type, sType, exc->name, exc->arg1, exc->arg2, exc->retval);
    #else

$   _TX_UNEXPECTED ("_matherr(): �������������� ������: %s.", sType);

    #endif

    return 0;
    }

//-----------------------------------------------------------------------------------------------------------------

tx_noreturn void _txOnNewHandlerAnsi()
    {
    txOutputDebugPrintf ("%s - WARNING: %s() called\n", _TX_VERSION, __func__);
$1
$   _TX_UNEXPECTED ("operator new: ������ ��������� ������.\n\n"
                    "� ������� std::set_new_handler() �� ������ ���� ���������� ��� ������ "
                    "� ���-������ ����� ����������� ������.");

$   throw std::bad_alloc();
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnSecurityErrorAnsi (const char* msg, void* ptr, int code)
    {
    txOutputDebugPrintf ("%s - WARNING: %s (%s, 0x%p, %d) called\n", _TX_VERSION, __func__, msg, ptr, code);

$1  if (code)
        {$ errno = code; }

$   _TX_UNEXPECTED ("\a"
                    "������ ������������ ������ %d: %s � %.20s (0x%p). ������� �������!\n\n"
                    "� ������� std::set_constraint_handler_s() �� ������ ���� ���������� ��� ������ "
                    "� ����������� �� �������� �� ������� ��������.",
                    code, msg, (char*) ptr, ptr);
    }

//-----------------------------------------------------------------------------------------------------------------

int tx_glGetError (int setError /*= INT_MIN*/)
    {
$1  return _txOGLError = (setError == INT_MIN)? _TX_CALL (Win32::glGetError, ()) : setError;
    }

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          MSC Runtime check hooks
//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

#ifndef TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

int _txOnNewHandler (size_t size)
    {
    txOutputDebugPrintf ("%s - WARNING: %s (0x%p) called\n", _TX_VERSION, __func__, (void*)(uintptr_t) size);
$5
$   _TX_UNEXPECTED ("operator new: ������ ��������� %llu ���� ������.\n\n"
                    "� ������� _set_new_handler() �� ������ ���� ���������� ��� ������ "
                    "� ���-������ ����� ����������� ������.", (unsigned long long) size);

$   throw std::bad_alloc();
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnSecurityError (int code, void* addr)
    {
    txOutputDebugPrintf ("%s - WARNING: %s (%d, 0x%p) called\n", _TX_VERSION, __func__, code, addr);
$5
$   _TX_UNEXPECTED ("\a"
                    "������ ������������ ������ %d (_SECERR_BUFFER_OVERRUN). ������� �������!\n\n"
                    "� ������� _set_security_error_handler() �� ������ ���� ���������� ��� ������ "
                    "� ����� ������������ ��������� ���������. ������� �� �������.", code);
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnPureCall()
    {
    txOutputDebugPrintf ("%s - WARNING: %s() called\n", _TX_VERSION, __func__);
$5
$   _TX_UNEXPECTED ("\a"
                    "������� ����� ����������� �������. ����� ������, ��������, � ������������� "
                    "��� ������������ ������� ������� - �� ��������� ��� ����� �������.\n\n"
                    "� ������� _set_purecall_handler() �� ������ ���� ���������� ��� ������ "
                    "� ��������� ���� ������ �++ :)");
    }

//-----------------------------------------------------------------------------------------------------------------

void _txOnInvalidParam (const wchar_t* wExpr, const wchar_t* wFunc, const wchar_t* wFile, unsigned int line, uintptr_t addr)
    {
    txOutputDebugPrintf ("%s - WARNING: %s (%S, %S, %S, %d, 0x%p) called\n", _TX_VERSION, __func__, wExpr, wFunc, wFile, line, addr);

$5  assert (wExpr);
    assert (wFunc);
    assert (wFile);

    char expr [_TX_BUFSIZE/2] = "[Unknowm expr]",
         func [_TX_BUFSIZE/2] = "[Unknowm func]",
         file [MAX_PATH]      = "[Unknowm file]";

$   WideCharToMultiByte (_TX_CODEPAGE, 0, wExpr, -1, expr, sizeof (expr) - 1, NULL, NULL);
$   WideCharToMultiByte (_TX_CODEPAGE, 0, wFunc, -1, func, sizeof (func) - 1, NULL, NULL);
$   WideCharToMultiByte (_TX_CODEPAGE, 0, wFile, -1, file, sizeof (file) - 1, NULL, NULL);

$$  _txError (file, (int) line, func, 0, "\a"
              "� ������� %s ������� �������� ��������: �������, ��� %s. �� ���� ���.\n\n"
              "� ������� _set_invalid_parameter_handler() �� ������ ���� ���������� ��� ������.", func, expr);
    }

//-----------------------------------------------------------------------------------------------------------------

#if defined (_CLANG_VER) && !defined (_MSC_VER)

void _txLibCppDebugFunction (std::__libcpp_debug_info const& info)
    {
$5  assert (&info);

$$  _txError (info.__file_, info.__line_, NULL, 0, "\a"
              "��������� �������, ��� %s (%s). �� ���� ���.\n\n"
              "� ������� std::__libcpp_debug_function �� ������ ���� ���������� ��� ������.", info.__pred_, info.__msg_);
    }

#endif

//-----------------------------------------------------------------------------------------------------------------

#pragma runtime_checks ("", off)

int _txOnRTCFailure (int type, const char* file, int line, const char* module, const char* format, ...)
    {
    txOutputDebugPrintf ("%s - WARNING: %s (%d, %s, %d, %s, %s) called\n", _TX_VERSION, __func__, type, file, line, module, format);

$5  static long running = 0;
$   while (InterlockedExchange (&running, 1)) Sleep (0);

$   assert (format);

    // Disable all RTC failures

$   int nErrors = _RTC_NumErrors();
$   int* errors = NULL;
$   try { errors = (int*) _alloca (nErrors * sizeof (*errors)); } catch (...) {;}

$   int err = 0;
$   for (int i = 0; i < nErrors; i++) *(errors? &errors[i] : &err) = _RTC_SetErrorType ((_RTC_ErrorNumber) i, _RTC_ERRTYPE_IGNORE);

$   char text [_TX_BUFSIZE] = "";

$   va_list arg; va_start (arg, format);
$   _tx_vsnprintf_s (text, sizeof (text) - 1, format, arg);                  // Get message from the vararg list
$   auto error = (_RTC_ErrorNumber) va_arg (arg, int /*_RTC_ErrorNumber*/);  // Get the RTC error number
$   va_end (arg);

$   const char* sType = "type";

$   switch (type)
       {
       case _CRT_ERROR:  $ sType = "������";            break;
       case _CRT_ASSERT: $ sType = "���������� ������"; break;
       case _CRT_WARN:   $ sType = "��������� ������";  break;
       default:          $                              break;
       }

$   const char* sError = _RTC_GetErrDesc (error);

$$  _txError (file, line, NULL, 0, "\a"
              "���� �������� ���������� ��������� ����: %s %d (%s): %s � ������ %s.", sType, error, sError, text, module);

    // The code below will be never executed until the error above will stay fatal:

    // Restore the RTC error types

    #if defined (_MSC_VER)
    #pragma warning (disable: 6385)  // Reading invalid data from 'errors': the readable size is 'n' bytes, but 'm' bytes may be read.
    #endif

$   for (int i = 0; i < nErrors; i++) _RTC_SetErrorType ((_RTC_ErrorNumber) i, (errors? errors[i] : _CRT_ERROR));

    #if defined (_MSC_VER)
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

    #if (_TX_ALLOW_TRACE +0 <= 10)
    if (!size) return true;
    #endif

    #define GET_DESCR_(str, type)  case (type): { str = #type; break; }

    const char* sType = "Unknown type";
    const char* sUse  = "Unknown use";

    switch (_BLOCK_TYPE (type))
        {
        GET_DESCR_ (sType, _HOOK_ALLOC);
        GET_DESCR_ (sType, _HOOK_REALLOC);
        GET_DESCR_ (sType, _HOOK_FREE);
        default:   break;
        }

    switch (use)
        {
        GET_DESCR_ (sUse,  _NORMAL_BLOCK);
        GET_DESCR_ (sUse,  _CRT_BLOCK);
        GET_DESCR_ (sUse,  _CLIENT_BLOCK);
        GET_DESCR_ (sUse,  _FREE_BLOCK);
        GET_DESCR_ (sUse,  _IGNORE_BLOCK);
        default:   break;
        }

    #undef  GET_DESCR_

    _txTrace ((const char*) file, line, NULL, "%*s"
              "_txOnAllocHook (type = 0x%02X (%-*s), subtype =0x%X, data = 0x%p, size = 0x%p, use = 0x%02X (%-*s), request = %ld)",
              2 * _txLoc::Cur.inTX, "",
              type, 13, sType, _BLOCK_SUBTYPE (type), data, (void*) size, use, 13, sUse, request);

    recursive--;

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

#endif // TX_COMPILED

#endif

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          SEH staff
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

long WINAPI _txVectoredExceptionHandler (EXCEPTION_POINTERS* exc)
    {
    int inTX = _txLoc::Cur.inTX++;

    long ret = _txOnExceptionSEH (exc, "_txVectoredExceptionHandler");

    _txLoc::Cur.inTX = inTX;
    return ret;
    }

//-----------------------------------------------------------------------------------------------------------------

long WINAPI _txUnhandledExceptionFilter (EXCEPTION_POINTERS* exc)
    {
    int inTX = _txLoc::Cur.inTX++;

    long ret = _txOnExceptionSEH (exc, "_txUnhandledExceptionFilter");

    if (_txPrevUEFilter)
        {
        if (_txSetJmp())
            {
            int inTX2 = _txLoc::Cur.inTX++;

            ret = _txPrevUEFilter (exc);

            _txLoc::Cur.inTX = inTX2;
            }
        else
            {
$6          _txClearJmp();

            _TX_UNEXPECTED ("\t\a" "%s"
                            "� ������� ������� _set_se_translator() �� ������ ���� ���������� ��� ������.\n\n"
                            "�������������: ���� ������ ������������ ����������� ���������������� ���������� SEH." + !*_txDumpSE,
                            _txDumpSE + 1);
            }
        }

    _txLoc::Cur.inTX = inTX;
    return ret;
    }

//-----------------------------------------------------------------------------------------------------------------

LPTOP_LEVEL_EXCEPTION_FILTER WINAPI _txOnSetUnhandledExceptionFilter (LPTOP_LEVEL_EXCEPTION_FILTER filter)
    {
$6  _txPrevUEFilter = filter;

    return (LPTOP_LEVEL_EXCEPTION_FILTER) _txUnhandledExceptionFilter;
    }

//-----------------------------------------------------------------------------------------------------------------

long _txOnExceptionSEH (EXCEPTION_POINTERS* exc, const char func[])
    {
    assert (exc); if (!exc) {$ return EXCEPTION_CONTINUE_SEARCH; }

    assert (exc->ExceptionRecord);

    assert (func);
    assert (func[3] == 'V' || func[3] == 'U');

    bool  unhExc = (func[3] == 'U');
    DWORD code   = (exc && exc->ExceptionRecord)? exc->ExceptionRecord->ExceptionCode    : 0;
    void* addr   = (exc && exc->ExceptionRecord)? exc->ExceptionRecord->ExceptionAddress : NULL;

    if (code == DBG_PRINTEXCEPTION_C                  ||
        code == DBG_PRINTEXCEPTION_WIDE_C             ||
        code == DBG_THREAD_NAME                       ||
       (code == RPC_S_SERVER_UNAVAILABLE  && !unhExc) ||
       (code == RPC_S_CALL_CANCELLED      && !unhExc) ||
       (code == EXCEPTION_BREAKPOINT && IsDebuggerPresent()))
        return EXCEPTION_CONTINUE_SEARCH;

    _txSENumber++;
    if (HIBYTE (HIWORD (code)) == 0xC0) _txSEFatalNumber++;

    OutputDebugString ("\n");
    txOutputDebugPrintf ("%s - WARNING: #%ld: %s (code 0x%08lX, addr 0x%p) called\n",
                         _TX_VERSION, _txSENumber, func, (unsigned long) code, addr);

$6  if (*(unsigned long long*) _txDumpExceptionObjJmp)
        {
$       longjmp (_txDumpExceptionObjJmp, 1);
        }

    tx_fpreset();

    #if defined (_MSC_VER)
    if (code == EXCEPTION_STACK_OVERFLOW) {$ _resetstkoflw(); }
    #endif

$   bool primaryException = !(func && exc) || !((unhExc && *_txDumpSE) || _TX_MSC__CXX_DETECT_RETHROW (exc->ExceptionRecord));

$   if (primaryException && exc)
        {
$       unsigned err = GetLastError();

$       const char* stackTrace = _txCaptureStackBackTrace (0, true, exc->ContextRecord, exc);

$       _txDumpExceptionSEH (_txDumpSE,  (intptr_t) sizeof (_txDumpSE)  - 1, exc->ExceptionRecord, func);
$       _tx_snprintf_s      (_txTraceSE, (intptr_t) sizeof (_txTraceSE) - 1, "%s", stackTrace);

$       static _tx_thread DWORD prevCode = 0;
$       static _tx_thread void* prevAddr = NULL;

$       if (code != prevCode && addr != prevAddr &&
            !strstr (_txDumpSE, "������ ���������� C++:"))
            {
$           SetLastError (err);
$           _TX_UNEXPECTED ("\v\b\t" "%s", _txDumpSE + 1);

$           prevCode = code;
$           prevAddr = addr;
            }

$       SetLastError (err);
        }

$   if (_txDumpSE[0]     == '\a'                   ||
        _txSENumber      >= _TX_EXCEPTIONS_LIMIT+0 ||
        _txSEFatalNumber >= _TX_FATAL_EXCEPTIONS_LIMIT+0)
        {
$       _TX_UNEXPECTED ("\a\t" "%s"
                        "� ������� ������� _set_se_translator() �� ������ ���� ���������� ��� ������.",
                        _txDumpSE + 1);
        }

$   return EXCEPTION_CONTINUE_SEARCH;
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t _txDumpExceptionSEH (char what[], intptr_t size, const EXCEPTION_RECORD* exc, const char func[])
    {
$6  assert (what);
$   assert (size >= 0);
    assert (exc); if (!exc) {$ return 0; }
$   assert (func);

$   unsigned         code   = exc->ExceptionCode;
$   void*            addr   = exc->ExceptionAddress;
$   unsigned         params = exc->NumberParameters;
$   const ULONG_PTR* info   = exc->ExceptionInformation;
$   void*            object = (params >= 2)? (void*) info[1] : NULL;

$   char* s = what;

    #define PRINT_(...)  s += _tx_snprintf_s (s, size-2 - (s-what), ##__VA_ARGS__)

$   const char* sCode  = NULL;
$   const char* sDescr = NULL;

    #define GET_DESCR_(code, descr)  case ((unsigned long) (code)): {$ sCode = #code; sDescr = descr; break; }

$   switch (code)
        {
        GET_DESCR_ (EXCEPTION_ACCESS_VIOLATION,         " "  "��������� ������� � ������.")
        GET_DESCR_ (EXCEPTION_ILLEGAL_INSTRUCTION,      " "  "������������ ��������.")
        GET_DESCR_ (EXCEPTION_PRIV_INSTRUCTION,         " "  "����������������� ��������.")
        GET_DESCR_ (EXCEPTION_ARRAY_BOUNDS_EXCEEDED,    "\a" "����� �� ������� �������. ������� �������!")
        GET_DESCR_ (EXCEPTION_BREAKPOINT,               "\a" "���������� ����� ��������. ����� � �������!")
        GET_DESCR_ (EXCEPTION_DATATYPE_MISALIGNMENT,    "\a" "��������� ������������ ������.")
        GET_DESCR_ (EXCEPTION_INVALID_DISPOSITION,      "\a" "���������� ���������� ��������� �������� ��������.")
        GET_DESCR_ (EXCEPTION_IN_PAGE_ERROR,            "\a" "���������� ��������� ������ �������� ������.")
        GET_DESCR_ (EXCEPTION_NONCONTINUABLE_EXCEPTION, "\a" "����������� ���������� ����������.")
        GET_DESCR_ (EXCEPTION_SINGLE_STEP,              "\a" "��������� ���������� ��������� ����. ���� �����.")
        GET_DESCR_ (EXCEPTION_STACK_OVERFLOW,           "\a" "�-��! ������������ �����!")
        GET_DESCR_ (EXCEPTION_GUARD_PAGE,               "\a" "������� ������� � ���������� �������� ������.")
        GET_DESCR_ (EXCEPTION_INVALID_HANDLE,           "\a" "�������� ��� ��� �������� ����������.")
        GET_DESCR_ (STATUS_POSSIBLE_DEADLOCK,           "\a" "��������, �������� ���������� ��������.")

        GET_DESCR_ (EXCEPTION_FLT_STACK_CHECK,          "\a" "������ ����� ��� �������� � ��������� ������.")
        GET_DESCR_ (EXCEPTION_FLT_DENORMAL_OPERAND,     " "  "�������������� ����� � ��������� ������.")
        GET_DESCR_ (EXCEPTION_FLT_DIVIDE_BY_ZERO,       " "  "������� �� ���� ��� �������� � ��������� ������.")
        GET_DESCR_ (EXCEPTION_FLT_INEXACT_RESULT,       " "  "�������� ��������� ��� �������� � ��������� ������.")
        GET_DESCR_ (EXCEPTION_FLT_INVALID_OPERATION,    " "  "������������ �������� � ��������� ������.")
        GET_DESCR_ (EXCEPTION_FLT_OVERFLOW,             " "  "������������ ��� �������� � ��������� ������.")
        GET_DESCR_ (EXCEPTION_FLT_UNDERFLOW,            " "  "������ ���������� ��� �������� � ��������� ������.")
        GET_DESCR_ (STATUS_FLOAT_MULTIPLE_FAULTS,       " "  "������������� ������ � ��������� ������.")

        GET_DESCR_ (EXCEPTION_INT_DIVIDE_BY_ZERO,       "\a" "������������� ������� �� ����.")
        GET_DESCR_ (EXCEPTION_INT_OVERFLOW,             "\a" "������������ ��� ������������� ��������.")

        GET_DESCR_ (EXCEPTION_CLR_FAILURE,              "\a" "���� ����� ���������� (CLR).")
        GET_DESCR_ (STATUS_STACK_BUFFER_OVERRUN,        "\a" "������������ ��������� ������!")
        GET_DESCR_ (STATUS_ASSERTION_FAILURE,           "\a" "�������� assert. �� ���� ��� �� ����.")
        GET_DESCR_ (STATUS_WX86_BREAKPOINT,             "\a" "����� �������� ���������� �������� x86.")
        GET_DESCR_ (RPC_S_UNKNOWN_IF,                   "\a" "����������� ��������� ���������� ������ �������� (RPC).")
        GET_DESCR_ (RPC_S_SERVER_UNAVAILABLE,           "\a" "������ ���������� ������ �������� (RPC) ����������.")
        GET_DESCR_ (DBG_TERMINATE_THREAD,               "\a" "�������� �������� ����� ��������.")
        GET_DESCR_ (DBG_TERMINATE_PROCESS,              "\a" "�������� �������� �������.")
        GET_DESCR_ (DBG_CONTROL_C,                      "\a" "�������� ������� ������ ���������� Control+C.")
        GET_DESCR_ (DBG_CONTROL_BREAK,                  "\a" "�������� ������� ������ ���������� Control+Break.")
        GET_DESCR_ (DBG_THREAD_NAME,                    " "  "�������� ������� �������� ���� ������ ���.")
        GET_DESCR_ (DBG_PRINTEXCEPTION_C,               " "  "�������� ����� ���������� �� CTRL+C (OutputDebugStringA).")
        GET_DESCR_ (DBG_PRINTEXCEPTION_WIDE_C,          " "  "�������� ����� ���������� �� CTRL+C (OutputDebugStringW).")

        GET_DESCR_ (EXCEPTION_CPP_MSC,                  " "  "���������� �++, ��������� ���������� throw.")
        GET_DESCR_ (EXCEPTION_CPP_GCC,                  " "  "���������� �++, ��������� ���������� throw.")
        GET_DESCR_ (EXCEPTION_CPP_GCC_UNWIND,           " "  "���������� �++, ��������� �� ����� ��������� ����� (rethrow?).")
        GET_DESCR_ (EXCEPTION_CPP_GCC_FORCED,           " "  "���������� �++, ��������� ���������� �����.")
        GET_DESCR_ (EXCEPTION_CPP_BORLAND_BUILDER,      "\a" "��� ������������ ��� ������? O_O")
        GET_DESCR_ (EXCEPTION_CPP_BORLAND_DELPHI,       "\a" "��� �� �++. ��� ��� �����?")

        default: $ break;
        }

    #undef GET_DESCR_

$   if (sDescr)
        {
$       PRINT_ ("%s\n\n" "#%ld: ���������� %s", sDescr, _txSENumber, sCode);
        }
    else
        {
$       PRINT_ ("\a#%ld: ", _txSENumber);
$       s += FormatMessage (FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS,
                            GetModuleHandle ("NTDLL.DLL"), code, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                            s, (DWORD) (size - (s-what)), NULL) - 2;
$       PRINT_ ("\r\r");
        }

$   PRINT_ (" (0x%X) ��� ���������� ���� �� ������", code);
$   PRINT_ ((addr? " 0x%p" : " NULL"), addr);

$   Win32::SYMBOL_INFO*     sym  = NULL;
$   Win32::IMAGEHLP_LINE64* line = NULL;

    if (addr) {$ _txSymGetFromAddr (addr, &sym, &line); }

$   if (sym  &&                   *sym->Name)      PRINT_ (" � ������� %s()", sym->Name);
$   if (line && line->FileName && *line->FileName) PRINT_ (" � ����� %s �� ������ %u", line->FileName, (unsigned) line->LineNumber);

$   if (code == EXCEPTION_ACCESS_VIOLATION ||
        code == EXCEPTION_IN_PAGE_ERROR)
        {
$       PRINT_ (". ������� ");

$       unsigned long op = 0xBADC0DE;
$       const char*  sOp = "(�������� �� �������)";

$       if (params >= 1)
            {
$           switch (op = (unsigned long) info[0])
                {
                case 0:  $ sOp = "�������� ������";          break;
                case 1:  $ sOp = "�������� ������";          break;
                case 8:  $ sOp = "��������� ���";            break;
                default: $ sOp = "��������� �������� 0x%lX"; break;
                }
            }

$       PRINT_ (sOp, op);

$       if (params >= 2) {$ PRINT_ ((object? " �� ������ 0x%p" : " �� ������ NULL"), object); }
        else             {$ PRINT_ (" (����� �� ������)"); }

$       if (code == EXCEPTION_IN_PAGE_ERROR)
            {
$           PRINT_ (", ������ �����-������:");

$           if (params >= 3)
                {
$               unsigned long ntstatus = (unsigned long) info[2];

$               PRINT_ (" 0x%lX (", ntstatus);

$               s += FormatMessage (FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_IGNORE_INSERTS,
                                    GetModuleHandle ("NTDLL.DLL"), ntstatus, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                                    s, (DWORD) (size - (s-what)), NULL) - 2;
$               PRINT_ (")");
                }
            else
                {$ PRINT_ (" (�� �������)"); }
            }
        }

$   HMODULE module = NULL;
$   _TX_CALL (Win32::GetModuleHandleEx, (GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS, (const char*) addr, &module));

$   if (module)
        {
$       static char sModule [MAX_PATH] = "";
$       int ok = GetModuleFileName (module, sModule, sizeof (sModule));

$       char* ext = (ok? strrchr (sModule, '.') : NULL);
$       if (ext) _strlwr_s (ext, sizeof (sModule) - 1 - (ext - sModule));

        if (ok) {$ PRINT_ (" � ������ %s",  sModule); }
        else    {$ PRINT_ (" � ������ 0x%p", module); }
        }

$   PRINT_ (".");

$   if (_txSENumber >= _TX_EXCEPTIONS_LIMIT+0)
        {$ PRINT_ (" �������������, �������� ����� ���������� _TX_EXCEPTIONS_LIMIT (%d).",        _TX_EXCEPTIONS_LIMIT+0); }

$   if (_txSEFatalNumber >= _TX_FATAL_EXCEPTIONS_LIMIT+0)
        {$ PRINT_ (" ����� �������� ����� ��������� ���������� _TX_FATAL_EXCEPTIONS_LIMIT (%d).", _TX_FATAL_EXCEPTIONS_LIMIT+0); }

$   PRINT_ (" ������� %s(), ��� �������. ����� ��� <3", func);

$   if (exc->ExceptionFlags & EXCEPTION_NONCONTINUABLE)
        {$ PRINT_ ("\n\n" "��, �� (EXCEPTION_NONCONTINUABLE)."); }

$   if (exc->ExceptionRecord)
        {
$       PRINT_ ("\n\n" "�������:" "\n\n");
$       s += _txDumpExceptionSEH (s, size - (s-what), exc->ExceptionRecord, func);
        }

$   if (code == EXCEPTION_CPP_GCC        ||
        code == EXCEPTION_CPP_GCC_UNWIND ||
        code == EXCEPTION_CPP_GCC_FORCED ||
        code == EXCEPTION_CPP_MSC)
        {
$       s += _txDumpExceptionCPP (s,    size - (s-what), code, params, info);
        }

    #undef PRINT_

$   while (s > what && s[-1] == '\n') s--;
$   if (s > what) s += _tx_snprintf_s (s, size - (s-what), "\n\n");

$   return s - what;
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t _txDumpExceptionCPP (char what[], intptr_t size,
                              unsigned code /*= 0*/, unsigned params /*= 0*/, const ULONG_PTR info[] /*= NULL*/)
    {
$6  assert (what);
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

            using namespace abi;

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

        case EXCEPTION_CPP_MSC:
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
$               auto throwInfo = (const Win32::ThrowInfo*) info[2];

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
$           txOutputDebugPrintf ("ERROR: Wrong call to %s: Unknown exception code 0x%08X\n", __TX_FUNCTION__, code);
$           break;
        }

$   while (s > what && s[-1] == '\n') s--;
$   if (s > what) s += _tx_snprintf_s (s, size - (s - what), "\n\n");

$   return (s - what);
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t _txDumpExceptionObj (char what[], intptr_t size, void* object, size_t sizeObj, const std::type_info* type)
    {
$6  assert (what);
$   assert (size > 0);

$   static char*  s     = NULL; s     = what;
$   static size_t szObj = 0;    szObj = sizeObj;

    #define PRINT_(...)  s += _tx_snprintf_s (s, size - (s - what), ##__VA_ARGS__)

$   PRINT_ ("\n\n" "������ ���������� C++:");

$   const char* mangledName = (type)? type->name() : NULL;

$   char* typeName = NULL;
$   int err = 1;

    #if defined (_GCC_VER)
$   typeName = ::abi::__cxa_demangle (mangledName, 0, 0, &err);
    #endif

$   const char* name = (!err && typeName)? typeName : mangledName;

$   if (name &&
       (strcmp (name, "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >")           == 0 ||
        strcmp (name, "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >")                   == 0))
        {$ name = "std::string"; }

$   if (name &&
       (strcmp (name, "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > *")         == 0 ||
        strcmp (name, "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> > * __ptr64") == 0 ||
        strcmp (name, "std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*")                  == 0))
        {$ name = "std::string*"; }

    if (name) {$ PRINT_ (" %s", name); }

    #if defined (_GCC_VER)
$   free (typeName);
    #endif

$   err = 0;
$   if (mangledName)
        {
        if (_txSetJmp())
            {
            #define PRINT_VAL_(fmt, typ, ...)                                                                          \
                else if (*type == typeid (      typ       )) {$ PRINT_ (" = " #fmt, (* (typ* ) object) __VA_ARGS__); } \
                else if (*type == typeid (const typ       )) {$ PRINT_ (" = " #fmt, (* (typ* ) object) __VA_ARGS__); } \
                else if (*type == typeid (      typ*      )) {$ PRINT_ (" = " #fmt, (**(typ**) object) __VA_ARGS__); } \
                else if (*type == typeid (const typ*      )) {$ PRINT_ (" = " #fmt, (**(typ**) object) __VA_ARGS__); } \
                else if (*type == typeid (      typ* const)) {$ PRINT_ (" = " #fmt, (**(typ**) object) __VA_ARGS__); } \
                else if (*type == typeid (const typ* const)) {$ PRINT_ (" = " #fmt, (**(typ**) object) __VA_ARGS__); }

            if (false) ;
            PRINT_VAL_ ("%s", char*)  PRINT_VAL_ ('%c', unsigned char)   PRINT_VAL_ (%s,   bool, ? "true" : "false")
            PRINT_VAL_ ( %d,  int)    PRINT_VAL_ ( %u,  unsigned int)    PRINT_VAL_ (%g,   float)
            PRINT_VAL_ ( %hd, short)  PRINT_VAL_ ( %hu, unsigned short)  PRINT_VAL_ (%lg,  double)
            PRINT_VAL_ ( %ld, long)   PRINT_VAL_ ( %lu, unsigned long)   PRINT_VAL_ ('%c', char)
            PRINT_VAL_ ("%s", std::string, .c_str())

            else if (std::exception* e = dynamic_cast <std::exception*> ( (std::exception* ) object))
                {
$               PRINT_ (", what(): \"%s\"", e->what());
                }
            else
                {$ err = 1; }
            }
        else
            {$ err = 2; }
        }

$   _txClearJmp();

$   if (err && object && szObj)
        {
$       const unsigned char* buf = (const unsigned char*) object;

$       if (szObj >= 64) szObj = 64;

$       PRINT_ (", ����: [");
$       for (size_t i = 0; i < szObj; i++) PRINT_ ("%c", (isprint (buf[i]) && !iscntrl (buf[i]))? buf[i] : '.' );

$       PRINT_ ("]");
$       for (size_t i = 0; i < szObj; i++) PRINT_ (" %02X", buf[i]);

$       err = 0;
        }

$   if (err)
        {$ PRINT_ (" = ???"); }

$   PRINT_ ((object? "%s��� ����� 0x%p." : "%s��� ����� NULL."), ((typeName || mangledName)? ", " : ""), object);

    #undef PRINT_VAL_
    #undef PRINT_

$   return s - what;
    }

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Stack trace and debug info access
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

const char* _txCaptureStackBackTrace (int framesToSkip /*= 0*/, bool readSource /*= true*/,
                                      CONTEXT* context /*= NULL*/, EXCEPTION_POINTERS* exc /*= NULL*/,
                                      HANDLE thread /*= GetCurrentThread()*/)
    {
$6  const int maxFrames = 62;  // MS says: < 63
$   static char trace [(MAX_PATH + 1024+1) * maxFrames] = "";

    if (framesToSkip == -1) {$ return trace; }

$   static void* capture [maxFrames] = {};
$   int frames = _txStackWalk (framesToSkip + !context, sizearr (capture), capture, context, thread);

$   memset (trace, 0, sizeof (trace));
$   char* s = trace;

    #define PRINT_(...)  s += _tx_snprintf_s (s, sizeof (trace) - 1 - 3 - (s-trace), ##__VA_ARGS__)

$   for (int i = 0, n = 0; i < frames; i++)
        {
$       void* addr = capture[i];

$       Win32::SYMBOL_INFO*     sym    = NULL;
$       Win32::IMAGEHLP_LINE64* line   = NULL;
$       const char*             module = NULL;
$       const char*             source = NULL;
$       bool                    inTX   = false;

        if (addr)                {$ inTX = _txSymGetFromAddr ((char*) addr - 1, &sym, &line, &module);          }
        if (readSource && !inTX) {$        _txSymGetFromAddr ((void*) 1,        NULL, NULL,  NULL, &source, 2); }

$       int nl = 0;
$       while (s > trace && s[-1] == '\n') { s--; nl++; }

        #if !defined (_TX_FULL_STACKTRACE)

$       if (! ((sym && *sym->Name) || (line && ((line->FileName && *line->FileName) || line->LineNumber))))
            {$ continue; }

        #endif

$       PRINT_ ("%s#%2d 0x%p", ((n)? ((source || nl)? "\n\n" : "\n") : ""), i, addr);
$       n++;

        if (addr ==                    0)          {$ PRINT_ (" [�������� �����]");        break; }
        if (addr == (void*)           -1)          {$ PRINT_ (" [�������� �����]");        break; }
        if (addr == (void*)(uintptr_t) 0xBAADF00D) {$ PRINT_ (" [����� �� LocalAlloc()]"); break; }

        if (module)                                {$ PRINT_ (" in %s%s",     module, ((sym && *sym->Name)? ": " : "")); }
        if (sym  && *sym->Name)                    {$ PRINT_ ("%s()",         sym->Name);                                }
        if (line && line->FileName)                {$ PRINT_ (" at %s",       line->FileName);                           }
        if (line && line->LineNumber)              {$ PRINT_ (" (%d)",  (int) line->LineNumber);                         }
        if (source)                                {$ PRINT_ (":\n\n" "%s\n", source);                                   }

        if (sym && strcmp (sym->Name , "main") == 0) {$ break; }
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

    #if !defined (_TX_NO_MINIDUMP)
$   _txCreateMiniDump (exc);
    #endif

$   return trace;
    }

//-----------------------------------------------------------------------------------------------------------------

// Stack WALKING if the program is DEAD. Dead, Carl!

int _txStackWalk (int framesToSkip, size_t szCapture, void* capture[], CONTEXT* context /*= NULL*/,
                  HANDLE thread /* = GetCurrentThread()*/)
    {
$6  namespace MinGW = Win32::MinGW;

$   assert (capture);

$   HANDLE process  = GetCurrentProcess();
$   bool thisThread = (Win32::GetThreadId (thread) == GetCurrentThreadId());

$   CONTEXT ctx = {};
$   ctx.ContextFlags |= CONTEXT_FULL;

$   int isWow64 = 0;
$   if (Win32::IsWow64Process) Win32::IsWow64Process (process, &isWow64);
    else {$ return -1; }

$   if (context)
        {
$       ctx = *context;
        }
    else
        {
$       if (thisThread)
            {
$           _TX_CALLv (Win32::RtlCaptureContext, (&ctx));
            }
        else
            {
$           SuspendThread (thread);

$           ctx.ContextFlags = CONTEXT_ALL;
$           bool ok = !!GetThreadContext (thread, &ctx);

$           if (!ok)
                {
$               ResumeThread (thread);
$               return -1;
                }
            }
        }

$   Win32::STACKFRAME64 frame = {};
$   frame.AddrPC.Mode = frame.AddrStack.Mode = frame.AddrFrame.Mode = Win32::AddrModeFlat;

$   int cpu = 0;

    #if defined (_WIN64)

$   if (isWow64)
        {
$       Win32::WOW64_CONTEXT wow64ctx = {};
$       wow64ctx.ContextFlags |= WOW64_CONTEXT_FULL;

$       if (!_TX_CALL (Win32::Wow64GetThreadContext, (thread, &wow64ctx)))  // This call fails in WINE,
            {                                                               // while EXIT_PROCESS_DEBUG_EVENT
            if (!thisThread) {$ ResumeThread (thread); }
$           return 0;
            }

$       cpu = IMAGE_FILE_MACHINE_I386;

$       frame.AddrPC   .Offset = wow64ctx.Eip;
$       frame.AddrStack.Offset = wow64ctx.Esp;
$       frame.AddrFrame.Offset = wow64ctx.Ebp;
        }
    else
        {
$       cpu = IMAGE_FILE_MACHINE_AMD64;

$       frame.AddrPC   .Offset = ctx.Rip;
$       frame.AddrStack.Offset = ctx.Rbp;
$       frame.AddrFrame.Offset = ctx.Rsp;
        }

    #else

        {
$       cpu = IMAGE_FILE_MACHINE_I386;

$       frame.AddrPC   .Offset = ctx.Eip;
$       frame.AddrStack.Offset = ctx.Ebp;
$       frame.AddrFrame.Offset = ctx.Esp;
        }

    #endif

$   assert (cpu);

    if (_txSetJmp())
        {
$       _txSymGetFromAddr ((void*) 1);
        }
$   _txClearJmp();

$   int  frames = -1;

$   for (frames = -framesToSkip; frames < (int) szCapture; frames++)
        {
$       DWORD64 prev = frame.AddrStack.Offset;

        // � ���� � �������� ����� walk. � � ��������� ���� talk.

        if (!_txSetJmp()) {$ break; }

#if   defined (_GCC_VER)

        if (!_TX_CALL (MinGW::StackWalk64, (cpu, process, thread, &frame, &ctx, NULL,
                                            MinGW::SymFunctionTableAccess64, MinGW::SymGetModuleBase64, NULL))) {$ break; }
#elif defined (_MSC_VER)

$       if (!_TX_CALL (Win32::StackWalk64, (cpu, process, thread, &frame, &ctx, NULL,
                                            Win32::SymFunctionTableAccess64, Win32::SymGetModuleBase64, NULL))) {$ break; }
#else
        #error _GCC_VER / _MSC_VER not defined
#endif
        if (frames < 0) {$ continue; }

$       void* addr = (void*) frame.AddrPC.Offset;

        if (frame.AddrFrame.Offset == 0)   {$ addr =          0; }  // Bad frame
        if (frame.AddrStack.Offset < prev) {$ addr = (void*) -1; }  // Strange frame

$       assert (0 <= frames && frames < (int) szCapture);

$       capture[frames] = addr;
        }

$   _txClearJmp();

    if (!thisThread) {$ ResumeThread (thread); }

$   return frames;
    }

// Note that Rick and Carl are speaking near the C language block. "C block", Carl. See: http://knowyourmeme.com/memes/carl

//-----------------------------------------------------------------------------------------------------------------

bool _txSymGetFromAddr (void* addr, Win32::SYMBOL_INFO** symbol /*= NULL*/,
                        Win32::IMAGEHLP_LINE64** line /*= NULL*/, const char** module /*= NULL*/,
                        const char** source /*= NULL*/, int context /*= 2*/)
    {
$7  static HANDLE process = NULL;

#if   defined (_GCC_VER)
    #define LIB_  Win32::MinGW

#elif defined (_MSC_VER)
    #define LIB_  Win32

#else
    #error _GCC_VER / _MSC_VER not defined
#endif

$   if (!process && addr)
        {
$       process = GetCurrentProcess();

$       DWORD options = SYMOPT_UNDNAME | SYMOPT_LOAD_LINES | SYMOPT_LOAD_ANYTHING | SYMOPT_INCLUDE_32BIT_MODULES |
                        SYMOPT_DEFERRED_LOADS | SYMOPT_FAVOR_COMPRESSED | SYMOPT_FAIL_CRITICAL_ERRORS | SYMOPT_NO_PROMPTS;

$        _TX_CALL (LIB_::SymSetOptions, (options));
$        _TX_CALL (LIB_::SymInitialize, (process, NULL, true));
        }

$   static DWORD64 mod = 0;

$   if (module)
        {
$       static char sMod [MAX_PATH] = "";
$       memset (sMod, 0, sizeof (sMod));

$       mod = _TX_CALL (LIB_::SymGetModuleBase64, (process, (uintptr_t) addr));

$       GetModuleFileName ((HMODULE)(intptr_t) mod, sMod, MAX_PATH);

$       char* ext = strrchr (sMod, '.');
        if (ext) {$ _strlwr_s (ext, sizeof (sMod) - (ext-sMod)); }

$       *module = sMod;
        }

$   static char buffer [_TX_BUFSIZE] = "";
$   static Win32::SYMBOL_INFO* sym = (Win32::SYMBOL_INFO*) buffer;

$   if (symbol)
        {
$       memset (buffer, 0, sizeof (buffer));

$       sym->MaxNameLen   = sizeof (buffer) - sizeof (Win32::SYMBOL_INFO) - 1;
$       sym->SizeOfStruct = sizeof (Win32::SYMBOL_INFO);
$       unsigned long long ofs = 0;

$       _TX_CALL (LIB_::SymFromAddr, (process, (uintptr_t) addr, &ofs, sym));

        if (strcmp (sym->Name, "??") == 0) {$ *sym->Name = 0; }

$       *symbol = sym;
        }

$   static Win32::IMAGEHLP_LINE64 line64 = { sizeof (line) };

$   if (line)
        {
$       memset (&line64, 0, sizeof (line64));

$       DWORD ofs = 0;
$       _TX_CALL (LIB_::SymGetLineFromAddr64, (process, (uintptr_t) addr, &ofs, &line64));

$       *line = &line64;
        }

$   if (source)
        {
$       static char buf [_TX_BUFSIZE] = "";
$       memset (buf, 0, sizeof (buf));

$       if (line64.FileName && line64.LineNumber)
            {
$           _txReadSource (buf, sizeof (buf) - 1, line64.FileName,
                          (int) line64.LineNumber - context, (int) line64.LineNumber + context, (int) line64.LineNumber);

$           *source = buf;
            }

        if (!*source || !**source) {$ *source = NULL; }
        }

$   if (!addr && process)
        {
$       _TX_CALL (LIB_::SymCleanup, (process));

$       process = NULL;
        }

$   if (symbol)
        {
$       if (strstr  (sym->Name, "::TX::")                                                  ||
           (strncmp (sym->Name, "_tx",  3) == 0 && isupper ((unsigned char) sym->Name[3])) ||
           (strncmp (sym->Name,  "tx",  2) == 0 && isupper ((unsigned char) sym->Name[2])) ||
            strncmp (sym->Name, "_tx_", 4) == 0                                            ||
            strncmp (sym->Name,  "tx_", 3) == 0)
            {
$           return true;
            }

$       if (!line || !line64.FileName) return false;

$       intptr_t len = strlen (line64.FileName) - (sizeof (__FILE__) - 1);

$       return (len >= 0 && _stricmp (line64.FileName + len, __FILE__) == 0) &&
               (len == 0 || line64.FileName[len-1] == '/' || line64.FileName[len-1] == '\\');
        }

    #undef LIB_

$   return false;
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t _txReadSource (char buf[], intptr_t size, const char file[],
                        int linStart /*= 0*/, int linEnd /*= INT_MIN*/, int linMark /*= INT_MIN*/)
    {
$7  assert (buf);

    if (!file || !*file) {$ return 0; }

    if (linStart < 1) {$ linStart = 1;       }
    if (linEnd == -1) {$ linEnd   = INT_MAX; }

$   FILE* f = NULL;
$   fopen_s (&f, file, "r");
    if (!f) {$ return 0; }

$   int n = 1;
    while (!feof (f))
        {
        if (n >= linStart) {$ break; }
        while (!feof (f) && fgetc (f) != '\n')
            ;
        n++;
        }

$   char* s = buf;

    #define SZ_  ( size - 3 - (s - buf) )

$   while (!feof (f) && SZ_ > 0)
        {
        if (n > linEnd || _txNOP (SZ_) < 0) {$ break; }

        if (linMark != INT_MIN)
            {$ s += _tx_snprintf_s (s, SZ_, "%s%5d: ", ((n == linMark)? "=>" : "  "), n); }

$       int c = 0;
$       while (!feof (f) && SZ_ > 0 && (c = fgetc (f)) != '\n') *s++ = (char) c;
        if (c == EOF) {$ s--; }

        if (SZ_ > 0) {$ *s++ = '\n'; }
$       n++;
        }

    if (n <= linEnd && SZ_ <= 0)
        {$ s += _tx_snprintf_s (s, size - (s - buf), "..."); }

    #undef SZ_

$   fclose (f);

    if (s > buf && s[-1] == '\n') {$ s--; }
$   *s = 0;

$   return (s - buf);
    }

//-----------------------------------------------------------------------------------------------------------------

const char* _txCaptureStackBackTraceTX (int framesToSkip /*= 0*/, bool readSource /*= false*/)
    {
$6  const int maxFrames = 62;  // TX says too: < 63
$   static char trace [(MAX_PATH + 1024+1) * maxFrames] = "";

    if (framesToSkip == -1) {$ return trace; }

$   memset (trace, 0, sizeof (trace));
$   char* s = trace;

    #define SZ_  ( sizeof (trace) - 1 - 3 - (s-trace) )

$   const _txLoc* loc = &_txLoc::Cur;

    for (int i = 0; loc && i < framesToSkip + 1; i++, loc = loc->prev) { $; }

$   for (int i = -framesToSkip; loc && i < maxFrames; i++, loc = loc->prev)
        {
        if (i < 0) {$ continue; }

        if (loc->func || loc->file || loc->line)
            {
$           s += _tx_snprintf_s     (s, SZ_, "%s#%2d in %s at %s (%d)", (i? readSource? "\n\n" : "\n" : ""),
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

bool _txCreateMiniDump (EXCEPTION_POINTERS* exc /*= NULL*/)
    {
$6  static char dumpName[MAX_PATH] = "";
    if (!*dumpName) {$ _tx_snprintf_s (dumpName, sizeof (dumpName) - 1, "%s.dmp", _txLogName); }

$   HANDLE file = CreateFile (dumpName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (!file || file == INVALID_HANDLE_VALUE) {$ return false; }

$   Win32::MINIDUMP_EXCEPTION_INFORMATION excInfo = { GetCurrentThreadId(), exc, false };
$   Win32::MINIDUMP_TYPE type = (Win32::MINIDUMP_TYPE) (Win32::MiniDumpWithIndirectlyReferencedMemory | Win32::MiniDumpScanMemory);

$   bool ok = _TX_CALL (Win32::MiniDumpWriteDump, (GetCurrentProcess(), GetCurrentProcessId(), file, type,
                                                   ((exc)? &excInfo : NULL), NULL, NULL));
$   CloseHandle (file);

    if (ok) {$ return true;  }
    else    {$ return false; }
    }

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Errors reporting
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

const char* _txProcessError (const char file[], int line, const char func[], unsigned color, const char msg[], va_list args)
    {
    _txErrors++;

    DWORD           winErr   = GetLastError();

    int             crtErr   = errno;

    #if !defined (__CYGWIN__)
    unsigned long   dosErr   = _doserrno;
    #else
    unsigned long   dosErr   = 0;
    #endif

    unsigned        oglErr   = _TX_CALL (Win32::wglGetCurrentDC, ())? _TX_CALL (Win32::glGetError, ()) : _txOGLError;

    unsigned        threadId = GetCurrentThreadId();

    enum { isFatal = 0x01, isWarning = 0x02, noMsgBox = 0x04, fmtOnly = 0x08, traceSE = 0x10 };
    unsigned options = 0;

    for (; msg && *msg; msg++)
        {
        if      (*msg == '\a') options |= isFatal;
        else if (*msg == '\v') options |= isWarning;
        else if (*msg == '\b') options |= noMsgBox;
        else if (*msg == '\f') options |= fmtOnly;
        else if (*msg == '\t') options |= traceSE;
        else break;
        }

    const char* stkTrace = NULL;
    const char*  txTrace = NULL; (void) txTrace;

    if (!(options & fmtOnly))
        {
        stkTrace = ((options & traceSE) && *_txTraceSE)? _txTraceSE : _txCaptureStackBackTrace   (2, true);
        txTrace  =                                                    _txCaptureStackBackTraceTX (0, true);
        }

    static char what[_TX_BIGBUFSIZE*10] = "";
    static char str [_TX_BIGBUFSIZE]    = "";
    char *s = what;

    #define     PRINT_(...)  s += _tx_snprintf_s  (s, sizeof (what) - 1 - (s - what), ##__VA_ARGS__)
    #define    VPRINT_(...)  s += _tx_vsnprintf_s (s, sizeof (what) - 1 - (s - what), ##__VA_ARGS__)

                PRINT_ ("TXLib %s\n\n", ((options & isWarning)? "�������������:" :
                                         (options & isFatal)?   "�����������..." :
                                                                "��������:"));
                PRINT_ ("���������: %s", txGetModuleFileName());
    if (file)   PRINT_ (", ����: %s",    file);
    if (line)   PRINT_ (", ������: %d",  line);
    if (func)   PRINT_ (", �������: %s", func);
                PRINT_ (",\n\n");

    if (msg)    PRINT_ ("%s: ", (file || line || func)? "���������" : "��������"),
               VPRINT_ (msg, args);

    while (s > what && s[-1] == '\n') s--;

                PRINT_ ("\n\n" "#%d: %s, Instance: 0x%p (%d-bit), Flags: %c%c%c%c%c%d, Thread: 0x%X%s",

                        _txErrors, _TX_VERSION, &_txInitialized, (sizeof (void*) == 4)? 32 : 64,

                        "cC"[_txConsole], "mM"[_txMain], "dD"[_txIsDll], "rR"[_txRunning], "eE"[_txExit], _txLoc::Cur.trace,

                        threadId, (threadId == _txMainThreadId)?    " (Main)"   :
                                  (threadId == _txCanvas_ThreadId)? " (Canvas)" : "");

    if (winErr) PRINT_ (", GetLastError(): %lu (", (unsigned long) winErr),
                s += FormatMessage (FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                                    NULL, winErr, MAKELANGID (LANG_NEUTRAL, SUBLANG_DEFAULT),
                                    s, (DWORD) (sizeof (what) - (s-what)), NULL) - 2,
                s -=  (s[-1] == '.')? 1 : 0,
                PRINT_ (")");

    if (crtErr) PRINT_ (", errno: %d (%s)",        crtErr, (strerror_s (str, sizeof (str), crtErr), str));
    if (dosErr) PRINT_ (", _doserrno: %lu (%s)",   dosErr, (strerror_s (str, sizeof (str), dosErr), str));
    if (oglErr) PRINT_ (", glGetError(): %u (0x%04X, %s)", oglErr, oglErr, _TX_CALL (Win32::gluErrorString, (oglErr)));

    #if (__cplusplus >= 201703L) || (defined (_MSVC_LANG) && _MSVC_LANG >= 201703L)
                PRINT_ (". %s\n", ::std::uncaught_exceptions()? "std::uncaught_exceptions(): true." : "");
    #else
                PRINT_ (". %s\n", ::std::uncaught_exception ()? "std::uncaught_exception(): true."  : "");
    #endif

    if (_txLoc::Cur.inTX > 0 && file && !(_txLoc::Cur.line == line && _stricmp (_txLoc::Cur.file, file) == 0) &&
       (_txLoc::Cur.file || _txLoc::Cur.line || _txLoc::Cur.func))
                PRINT_ ("From: %s (%d) %s.\n", _txLoc::Cur.file, _txLoc::Cur.line, _txLoc::Cur.func);

    txOutputDebugPrintf ("\r" "%s - ERROR: %s\n", _TX_VERSION, what);

    if (options & fmtOnly)
        {
        SetLastError (winErr);

        errno = crtErr;

        #if !defined (__CYGWIN__)
        _doserrno = dosErr;
        #endif

        return what;
        }

    unsigned restore = txGetConsoleAttr();
    txSetConsoleAttr ((options & isFatal)? FOREGROUND_LIGHTMAGENTA : FOREGROUND_LIGHTRED);
    if (color) {$ txSetConsoleAttr (color); }

    int oldCodePage = txSetLocale();

    fprintf (stderr,      "\n" "--------------------------------------------------\n"
                               "%s\n"
                               "--------------------------------------------------\n",
                               what);

    if (stkTrace && strstr (stkTrace, ".exe: "))
        {$ fprintf (stderr,    "���� �������:\n\n"
                               "%s\n\n"
                               "--------------------------------------------------\n",
                               stkTrace); }

    SetConsoleOutputCP (oldCodePage);
    txSetConsoleAttr (restore);

    if (*_txLogName) do
        {
        FILE* log = NULL; fopen_s (&log, _txLogName, "a");
        if (!log) {$ break; }

        fprintf (log,     "\n" "--------------------------------------------------\n"
                               "%s\n"
                               "--------------------------------------------------\n",
                               what);

        fprintf (log,          "���� �������:\n\n"
                               "%s\n",
                               (*_txTraceSE? _txTraceSE : stkTrace));

        #if defined (_TX_ALLOW_TRACE) || defined (_DEBUG)

        if (_txLoc::Cur.inTX > 0 && txTrace && *txTrace)
            {
            fprintf (log, "\n" "--------------------------------------------------\n"
                               "���� ������� TX:\n\n"
                               "%s\n",
                               txTrace);
            }

        #endif

        fprintf (log,     "\n" "--------------------------------------------------\n"
                               "%s\n\n"
                               "--------------------------------------------------\n",
                               _txAppInfo());
        fclose (log);
        break;
        }
        while (false);

    int ret = 0;

    if (!(options & noMsgBox))
        {
        txSleep (_txWindowUpdateInterval);

        PRINT_ ("\n" "�������� ���������?");

        ret = txMessageBox (what, ((options & isWarning)? "��������������"   :
                                   (options & isFatal)?   "��������� ������" :
                                                          "������ � ���������"), MB_ICONSTOP | MB_SYSTEMMODAL | MB_YESNOCANCEL);
        }

    SetLastError (winErr);

    errno = crtErr;

    #if !defined (__CYGWIN__)
    _doserrno = dosErr;
    #endif

    if (((options & isFatal) && !IsDebuggerPresent()) || ret == IDYES)
        {
        txUnlock();
        _txCleanup();
        Win32::TerminateProcess (GetCurrentProcess(), EXIT_FAILURE);
        }

    #undef PRINT_

    return what;
    }

//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

int _txOnErrorReport (int type, const char* text, int* ret)
    {
    assert (text);
    assert (ret);

    _txErrors++;

    unsigned restore = txGetConsoleAttr();

    switch (type)
       {
       case _CRT_WARN:   txSetConsoleAttr (FOREGROUND_LIGHTRED);     break;
       case _CRT_ERROR:  txSetConsoleAttr (FOREGROUND_LIGHTMAGENTA); break;
       case _CRT_ASSERT: txSetConsoleAttr (FOREGROUND_YELLOW);       break;
       default:                                                      break;
       }

    const char startReport[] = "Detected memory leaks!\n",
                 endReport[] = "Object dump complete.\n";

    if (strcmp (text, startReport) == 0)  // Dirty, dirty hack. � ��� ������?
        {
        _txOnErrorReport (type, "\n",                                                                              NULL);
        _txOnErrorReport (type, _TX_VERSION " - ERROR: ",                                                          NULL);
        _txOnErrorReport (type, "��������: ���������� ������ ������! (��� ������ ����������� _TX_ALLOC_BREAK.)\n", NULL);
        _txOnErrorReport (type, "\n",                                                                              NULL);
        }

    size_t len = strlen (text);
    if (text [len-1] != '\n')               txOutputDebugPrintf ("%s",                text);
    else if (strcmp (text, endReport) != 0) txOutputDebugPrintf ("%s" "%s - ERROR: ", text, _TX_VERSION);
    else                                    txOutputDebugPrintf ("%s\n",              text);

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
        while (false);

    if (ret) *ret = 0;

    return (type == _CRT_WARN);
    }

#endif

//-----------------------------------------------------------------------------------------------------------------

int txMessageBox (const char text[], const char header[], unsigned flags /*= MB_ICONINFORMATION | MB_OKCANCEL*/)
    {
$5  static wchar_t textW   [_TX_BIGBUFSIZE * sizeof (wchar_t)] = L"[NULL text]";
$   static wchar_t headerW [_TX_BUFSIZE    * sizeof (wchar_t)] = L"[NULL header]";

    if (text)   {$ MultiByteToWideChar (_TX_CODEPAGE, 0, text,   -1, textW,   sizearr (textW))   || memset (textW,   0, sizeof (textW));   }
    if (header) {$ MultiByteToWideChar (_TX_CODEPAGE, 0, header, -1, headerW, sizearr (headerW)) || memset (headerW, 0, sizeof (headerW)); }

$   HWND wnd = _txCanvas_Window;
$   int  ret = MessageBoxW ((wnd && IsWindowVisible (wnd))? wnd : _TX_CALL (Win32::GetConsoleWindow,()),
                            textW, headerW, flags | MB_SETFOREGROUND | MB_TOPMOST | MB_OKCANCEL );
$   if (ret == IDCANCEL)
        {
$       SendNotifyMessage (txWindow(), (_txMain? WM_CLOSE : WM_DESTROY), 0, 0);
$       _txWaitFor (!_txCanvas_Window, _TX_TIMEOUT);
        }

$   return ret;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txGetAsyncKeyState (int key)
    {
$1  HWND wnd = GetForegroundWindow();

    return (GetAsyncKeyState (key) & 0x8000) &&
           (wnd == txWindow() || wnd == Win32::GetConsoleWindow());
    }

//-----------------------------------------------------------------------------------------------------------------

bool txNotifyIcon (unsigned flags, const char title[], const char format[], ...)
    {
$5  if (_TX_ARGUMENT_FAILED (format)) return false;

$   va_list arg; va_start (arg, format);
$   bool ok = true;

    #if defined (_WIN32_IE) && (_WIN32_IE >= 0x0500)

$   NOTIFYICONDATA nid = { sizeof (nid) };

$   nid.uFlags      = NIF_ICON | NIF_TIP | NIF_INFO;
$   nid.hWnd        = NULL;
$   nid.uID         = 1;
$   nid.hIcon       = _txCreateTXIcon (16); assert (nid.hIcon);
$   strncpy_s       (nid.szTip,       sizeof (nid.szTip),       "TXLib Information", sizeof (nid.szTip));
$   strncpy_s       (nid.szInfoTitle, sizeof (nid.szInfoTitle), (title? title : "TXLib ��������"), sizeof (nid.szInfoTitle) - 1);
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

//-----------------------------------------------------------------------------------------------------------------

void _txTrace (const char file[], int line, const char func[], const char msg[] /*= NULL*/, ...)
    {
    unsigned id = GetCurrentThreadId();

    const char marks[2][2][3] = {{"uU", "cC"}, {"mM", "??"}};

    char mark = marks [id == _txMainThreadId] [id == _txCanvas_ThreadId] [(_txLoc::Cur.inTX > 0)];

    char msgStr[_TX_BUFSIZE] = "";
    if (msg)
        {
        va_list arg; va_start (arg, msg);
        _tx_vsnprintf_s (msgStr, sizeof (msgStr) - 1, msg, arg);
        va_end (arg);
        }

    txOutputDebugPrintf ("%s - 0x%p %c%c%c%c%c%d [%c] - %-*s (%5d)  " "|%*s%s" "%s%s\n",

                         _TX_VERSION, &_txInitialized,

                         "cC"[_txConsole], "mM"[_txMain], "dD"[_txIsDll], "rR"[_txRunning], "eE"[_txExit],
                         _txLoc::Cur.trace, mark,

                         (int) sizeof (__FILE__) - 1, (file? file : "(NULL file)"), line,
                         2 * (_txLoc::Cur.inTX - 1) * !!func, "", (func? func : ""),

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

    char text[_TX_BIGBUFSIZE] = "";

    va_list arg; va_start (arg, format);
    int n = (int) _tx_vsnprintf_s (text, sizeof (text) - 1-1, format, arg);
    va_end (arg);

    struct __ { static int trimSpaces (char str[])
        {
        char *dst = str, *src = str;

        for (char d = ' '; d; src++)
            if (isspace ((unsigned char)(*src))) { if (d != ' ') *dst++ = d = ' '; }
            else                                                 *dst++ = d = *src;

        return (int) (dst - str - 1);
        }};

    if (options & compr)  n = __::trimSpaces (text);

    OutputDebugString (text);

    if (options & print)  fprintf (stderr, "%s", text);

    if (options & msgbox) txMessageBox (text, "�����������, ���", MB_ICONEXCLAMATION);

    return n;
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t _tx_snprintf_s (char stream[], intptr_t size, const char format[], ...)
    {
    if (!format) return 0;

    va_list arg; va_start (arg, format);
    intptr_t ret = _tx_vsnprintf_s (stream, size, format, arg);
    va_end (arg);

    return ret;
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t _tx_vsnprintf_s (char stream[], intptr_t size, const char format[], va_list arg)
    {
    if (!stream || !format) return 0;

    #if defined (_TRUNCATE)
    intptr_t ret = _vsnprintf_s (stream, size, _TRUNCATE, format, arg);
    #else
    intptr_t ret = _vsnprintf   (stream, size,            format, arg);
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

#if defined (__CYGWIN__)

int _getch()
    {
    termios oldattr = {}; tcgetattr (STDIN_FILENO, &oldattr);

    termios newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr (STDIN_FILENO, TCSANOW, &newattr);

    int ch = getchar();

    tcsetattr (STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
    }

//-----------------------------------------------------------------------------------------------------------------

int _putch (int ch)
    {
    termios old = {}; tcgetattr (STDOUT_FILENO, &old);

    termios cur = old;
    cur.c_lflag &= ~ICANON;
    cur.c_lflag |=  ECHO;
    tcsetattr (STDOUT_FILENO, TCSANOW, &cur);

    putchar (ch);

    tcsetattr (STDOUT_FILENO, TCSANOW, &old);

    return ch;
    }

//-----------------------------------------------------------------------------------------------------------------

int _kbhit()
    {
    termios old = {}; tcgetattr (STDIN_FILENO, &old);

    termios cur = old;
    cur.c_lflag &= ~(ICANON | ECHO);
    cur.c_cc[VMIN]  = 1;
    cur.c_cc[VTIME] = 0;

    tcsetattr (STDIN_FILENO, TCSAFLUSH, &cur);

    fd_set  fd = {}; FD_SET (STDIN_FILENO, &fd);
    timeval tv = {};

    int res = select (STDIN_FILENO + 1, &fd, NULL, NULL, &tv) && FD_ISSET (STDIN_FILENO, &fd);

    tcsetattr (STDIN_FILENO, TCSAFLUSH, &old);

    return res;
    }

#endif

#endif // TX_COMPILED

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Information
//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

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

    size_t sz = sizeof (fullName) - (ext - fullName);
    strncpy_s (ext, sz-1, " - TXLib", sz);

    return title + 1;
    }

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

inline const char* _txAppInfo()
    {
$1  time_t timeT     = time (NULL) - clock()/CLOCKS_PER_SEC;
    char   timeS[32] = "";
    ctime_s (timeS, sizeof (timeS), &timeT);

    static char text[_TX_BUFSIZE] = "";
    char cwd [MAX_PATH] = "";

    _tx_snprintf_s (text, sizeof (text) - 1,

                    "Developed with:\n\n"
                    "The Dumb Artist Library (TX Library)\n"
                    _TX_VERSION "\n" _TX_AUTHOR "\n"
                    "See license on: http://txlib.ru\n\n"

                    "TXLib file:" "\t" __FILE__ "\n"
                    "Compiled:"   "\t" __DATE__ " " __TIME__ ", " __TX_COMPILER__ ", %s, %d-bit, " _TX_BUILDMODE "\n"
                    "Started:"    "\t" "%.6s %.4s %.8s\n\n"

                    "Run file:"   "\t" "%s\n"
                    "Directory:"  "\t" "%s",

    #if   defined (_MSC_VER)
                    "MSVC Runtime",
    #elif defined (__CYGWIN__)
                    "Cygwin Runtime",
    #elif defined (_GCC_VER) && defined (_WIN64)
                    __mingw_get_crt_info(),
    #else
                    "MinGW Runtime " TX_QUOTE (__MINGW32_MAJOR_VERSION) "." TX_QUOTE (__MINGW32_MINOR_VERSION),
    #endif
                    (sizeof (void*) == sizeof (DWORD))? 32 : 64,

                    timeS + 4, timeS + 20, timeS + 11,              // These offsets are ANSI standardized
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
//           ���������� TXLib API
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

inline HWND txWindow()
    {
$0  return _txCanvas_Window;
    }

//-----------------------------------------------------------------------------------------------------------------

inline HDC& txDC()
    {
$0  return _txCanvas_BackBuf[0];
    }

//-----------------------------------------------------------------------------------------------------------------

inline RGBQUAD* txVideoMemory()
    {
    return _txCanvas_Pixels;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txGetExtentX (HDC dc /*= txDC()*/)
    {
    return txGetExtent (dc) .x;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txGetExtentY (HDC dc /*= txDC()*/)
    {
    return txGetExtent (dc) .y;
    }

//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

POINT txGetExtent (HDC dc /*= txDC()*/)
    {
$0  static POINT err = {-1, -1};

    if (!dc) {$ POINT screen = { GetSystemMetrics (SM_CXSCREEN), GetSystemMetrics (SM_CYSCREEN) }; return screen; };

    if (_TX_DEFAULT_HDC_FAILED (dc)) {$ return err; }

$   BITMAP bmap = {};
$   txGDI (Win32::GetObject (Win32::GetCurrentObject (dc, OBJ_BITMAP), sizeof (bmap), &bmap), dc) asserted;

$   POINT  size = { bmap.bmWidth, bmap.bmHeight };
$   return size;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDestroyWindow (HWND wnd /*= txWindow()*/)
    {
$1  if (!wnd || !txWindow()) return false;

$   if (wnd != txWindow())
        {
$       return !!SendNotifyMessage (txWindow(), _TX_WM_DESTROYWND, 0, (LPARAM) wnd);
        }

$   if (SendNotifyMessage (txWindow(), (_txMain? WM_CLOSE : WM_DESTROY), 0, 0) == 0) return false;

$   if (_txMain)
        {
$       txNotifyIcon (NIIF_WARNING, NULL, "\n" "�����, ����� ����� ��������� ��������� ����� txDestroyWindow().\n\n"
                                               "������������� ����� main(), ��� ��� ����� ����.\n");
$       Sleep (_TX_TIMEOUT);
        }

$   _txWaitFor (!_txCanvas_Window, _TX_TIMEOUT);

$   return _txCanvas_Window == NULL;
    }

//-----------------------------------------------------------------------------------------------------------------

HPEN txSetColor (COLORREF color, double thickness /*= 1*/, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return NULL;

$   HPEN pen = Win32::CreatePen ((color == TX_TRANSPARENT? PS_NULL : PS_SOLID), ROUND (thickness), color);

$   if (!pen) return (HPEN) NULL;

$   if (!_txBuffer_Select (pen, dc))
        {
$       Win32::DeleteObject (pen);
$       return (HPEN) NULL;
        }

$   if (txGDI (Win32::SetTextColor (dc, color), dc) == CLR_INVALID)
        {$ return (HPEN) NULL; }

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

COLORREF txGetColor (HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return CLR_INVALID;

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (dc, OBJ_PEN)), dc);
$   assert (obj); if (!obj) return CLR_INVALID;

$   union { EXTLOGPEN extLogPen; LOGPEN LogPen; } buf = {};

$   int size = Win32::GetObject (obj, 0, NULL);
$   Win32::GetObject (obj, sizeof (buf), &buf) asserted;

$   return (size == sizeof (LOGPEN))? buf.LogPen.lopnColor : buf.extLogPen.elpColor;
    }

//-----------------------------------------------------------------------------------------------------------------

HBRUSH txSetFillColor (COLORREF color, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return NULL;

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

COLORREF txGetFillColor (HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return CLR_INVALID;

$   HGDIOBJ obj = txGDI ((Win32::GetCurrentObject (dc, OBJ_BRUSH)), dc);
$   assert (obj); if (!obj) return CLR_INVALID;

$   LOGBRUSH buf = {};
$   txGDI ((Win32::GetObject (obj, sizeof (buf), &buf)), dc) asserted;

$   return buf.lbColor;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txClear (HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   POINT size = txGetExtent (dc);
$   return txGDI (!!(Win32::PatBlt (dc, 0, 0, size.x, size.y, PATCOPY)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSetPixel (double x, double y, COLORREF color, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   txGDI ((Win32::SetPixel (dc, ROUND (x), ROUND (y), color)), dc);

$   return true;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txPixel (double x, double y, double red, double green, double blue, HDC dc /*= txDC()*/)
    {
$1  if (red   > 1) red   = 1; if (red   < 0) red   = 0;
$   if (green > 1) green = 1; if (green < 0) green = 0;
$   if (blue  > 1) blue  = 1; if (blue  < 0) blue  = 0;

$   return txSetPixel (x, y, RGB (ROUND (red * 255), ROUND (green * 255), ROUND (blue * 255)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

COLORREF txGetPixel (double x, double y, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return CLR_INVALID;

$   return txGDI ((Win32::GetPixel (dc, ROUND (x), ROUND (y))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txLine (double x0, double y0, double x1, double y1, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   bool ok  = txGDI ((Win32::MoveToEx (dc, ROUND (x0), ROUND (y0), NULL)), dc);
$        ok &= txGDI ((Win32::LineTo   (dc, ROUND (x1), ROUND (y1)      )), dc);

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txRectangle (double x0, double y0, double x1, double y1, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   return txGDI ((Win32::Rectangle (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txPolygon (const POINT points[], int numPoints, HDC dc /*= txDC()*/)
    {
$1  if (_TX_ARGUMENT_FAILED    (points)) return false;
$   if (_TX_DEFAULT_HDC_FAILED (dc))     return false;

$   return txGDI (!!(Win32::Polygon (dc, points, numPoints)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txEllipse (double x0, double y0, double x1, double y1, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   return txGDI ((Win32::Ellipse (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txCircle (double x, double y, double r)
    {
$1  return txEllipse (x-r, y-r, x+r, y+r);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txArc (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   POINT center = { ROUND ((x0 + x1) /2), ROUND ((y0 + y1) /2) };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Arc (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1),
                                     ROUND (center.x + 1E3*cos (start)), ROUND (center.y - 1E3*sin (start)),
                                     ROUND (center.x + 1E3*cos (end)),   ROUND (center.y - 1E3*sin (end)))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txPie (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   POINT center = { ROUND ((x0 + x1) /2), ROUND ((y0 + y1) /2) };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Pie (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1),
                                     ROUND (center.x + 1E3*cos (start)), ROUND (center.y - 1E3*sin (start)),
                                     ROUND (center.x + 1E3*cos (end)),   ROUND (center.y - 1E3*sin (end)))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txChord (double x0, double y0, double x1, double y1, double startAngle, double totalAngle, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   POINT center = { ROUND ((x0 + x1) /2), ROUND ((y0 + y1) /2) };

$   double start =  startAngle               * txPI/180,
           end   = (startAngle + totalAngle) * txPI/180;

$   return txGDI (!!(Win32::Chord (dc, ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1),
                                       ROUND (center.x + 1E3*cos (start)), ROUND (center.y - 1E3*sin (start)),
                                       ROUND (center.x + 1E3*cos (end)),   ROUND (center.y - 1E3*sin (end)))), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txFloodFill (double x, double y,
                  COLORREF color /*= TX_TRANSPARENT*/, DWORD mode /*= FLOODFILLSURFACE*/, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   if (color == TX_TRANSPARENT) color = txGetPixel (x, y, dc);

$   return txGDI (!!(Win32::ExtFloodFill (dc, ROUND (x), ROUND (y), color, mode)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txTextOut (double x, double y, const char text[], HDC dc /*= txDC()*/)
    {
$1  if (_TX_ARGUMENT_FAILED    (text)) return false;
$   if (_TX_DEFAULT_HDC_FAILED (dc))   return false;

$   int len = (int) strlen (text);
$   bool ok = txGDI (!!(Win32::TextOut (dc, ROUND (x), ROUND (y), text, len)), dc);

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDrawText (double x0, double y0, double x1, double y1, const char text[],
                 unsigned format /*= DT_CENTER | DT_VCENTER | DT_WORDBREAK | DT_WORD_ELLIPSIS*/,
                 HDC dc /*= txDC()*/)
    {
$1  if (_TX_ARGUMENT_FAILED    (text)) return false;
$   if (_TX_DEFAULT_HDC_FAILED (dc))   return false;

#if !defined (NDEBUG)

$   if (x0 > x1)
        {
$       SetLastError (ERROR_INVALID_DATA);
$       TX_ERROR ("�������� x0 = %lg ������, ��� x1 = %lg. ����� ���������� �� �����.", x0, x1);
        }

$   if (y0 > y1)
        {
$       SetLastError (ERROR_INVALID_DATA);
$       TX_ERROR ("�������� y0 = %lg ������, ��� y1 = %lg. ����� ���������� �� �����.", y0, y1);
        }

#endif

$   RECT r = { ROUND (x0), ROUND (y0), ROUND (x1), ROUND (y1) };

$   if (!strchr (text, '\n')) format |= DT_SINGLELINE;

$   unsigned prev = txSetTextAlign (TA_LEFT | TA_TOP | TA_NOUPDATECP, dc);

$   bool ok = false;

$   if (Win32::DrawText)
        {
$       ok = !!txGDI ((Win32::DrawText (dc, text, -1, &r, format)), dc);
$       Win32::GetPixel (dc, 0, 0);
$       ok = true;
        }
    else
        {
$       txTextOut ((x0 + x1) / 2, (y0 + y1) / 2, text);
$       ok = false;
        }

$   txSetTextAlign (prev, dc);

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

HFONT txSelectFont (const char name[], double sizeY, double sizeX /*= -1*/,
                    int bold /*= FW_DONTCARE*/, bool italic /*= false*/, bool underline /*= false*/,
                    bool strikeout /*= false*/, double angle /*= 0*/,
                    HDC dc /*= txDC()*/)
    {
$1  if (_TX_ARGUMENT_FAILED    (name)) return NULL;
$   if (_TX_DEFAULT_HDC_FAILED (dc))   return NULL;

$   HFONT font = txFontExist (name)?
                     Win32::CreateFont (ROUND (sizeY), ROUND ((sizeX >= 0)? sizeX : sizeY/3),
                                        ROUND (angle*10), 0, bold, italic, underline, strikeout,
                                        RUSSIAN_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                        DEFAULT_QUALITY, DEFAULT_PITCH, name)
                     :
                     (HFONT) Win32::GetStockObject (SYSTEM_FIXED_FONT);

$   _txBuffer_Select (font, dc);

$   return font;
    }

//-----------------------------------------------------------------------------------------------------------------

SIZE txGetTextExtent (const char text[], HDC dc /*= txDC()*/)
    {
$1  SIZE size = {-1, -1};

$   if (_TX_ARGUMENT_FAILED    (text)) return size;
$   if (_TX_DEFAULT_HDC_FAILED (dc))   return size;

$   size_t len = strlen (text);
$   txGDI ((Win32::GetTextExtentPoint32 (dc, text, (int) len, &size)), dc) asserted;

$   return size;
    }

//-----------------------------------------------------------------------------------------------------------------

int txGetTextExtentX (const char text[], HDC dc /*= txDC()*/)
    {
$1  return txGetTextExtent (text, dc) .cx;
    }

//-----------------------------------------------------------------------------------------------------------------

int txGetTextExtentY (const char text[], HDC dc /*= txDC()*/)
    {
$1  return txGetTextExtent (text, dc) .cy;
    }

//-----------------------------------------------------------------------------------------------------------------

unsigned txSetTextAlign (unsigned align /*= TA_CENTER | TA_BASELINE*/, HDC dc /*= txDC()*/)
    {
$1  if (_TX_DEFAULT_HDC_FAILED (dc)) return false;

$   return txGDI ((Win32::SetTextAlign (dc, align)), dc);
    }

//-----------------------------------------------------------------------------------------------------------------

LOGFONT* txFontExist (const char name[])
    {
$1  if (_TX_ARGUMENT_FAILED (name)) return NULL;

$   static LOGFONT font = {};
$   font.lfCharSet = DEFAULT_CHARSET;
$   strncpy_s (font.lfFaceName, sizeof (font.lfFaceName), name, sizeof (font.lfFaceName) - 1);

$   struct tools
        {
        static int CALLBACK enumFonts (const LOGFONT* fnt, const TEXTMETRIC*, DWORD, LPARAM data)
            {
$           if (_TX_ARGUMENT_FAILED (fnt))  return 0;
$           if (_TX_ARGUMENT_FAILED (data)) return 0;

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

bool txSelectObject (HGDIOBJ obj, HDC dc /*= txDC()*/)
    {
$1  if (_TX_ARGUMENT_FAILED    (obj)) return false;
$   if (_TX_DEFAULT_HDC_FAILED (dc))  return false;

$   return _txBuffer_Select (obj, dc);
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txCreateCompatibleDC (double sizeX, double sizeY, HBITMAP bitmap /*= NULL*/)
    {
$1  POINT size = { ROUND (sizeX), ROUND (sizeY) };

$   HDC dc = _txBuffer_Create (NULL, &size, bitmap);
$   assert (dc); if (!dc) return NULL;

$   txSetDefaults (dc);

$   if (!_txCanvas_UserDCs) return dc;

$   txAutoLock _lock;
$   _txCanvas_UserDCs->push_back (dc);

$   if (_txCanvas_UserDCs->size() >= _TX_BUFSIZE)
        {$ txNotifyIcon (NIIF_WARNING, NULL, "�� ��������� ��� %d HDC, ������� ����� ����� �����.", (int) _txCanvas_UserDCs->size()); }

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txCreateDIBSection (double sizeX, double sizeY, RGBQUAD** pixels /*= NULL*/)
    {
$1  RGBQUAD* buf = NULL;
$   if (!pixels) pixels = &buf;

$   BITMAPINFO info = {{ sizeof (info), ROUND (sizeX), ROUND (sizeY), 1, WORD (sizeof (RGBQUAD) * 8), BI_RGB }};

$   HDC dc = txCreateCompatibleDC (0, 0, Win32::CreateDIBSection (NULL, &info, DIB_RGB_COLORS, (void**) pixels, NULL, 0));

$   RGBQUAD black = { 0, 0, 0, 255 };
$   for (int i = 0; i < sizeX * sizeY; i++) (*pixels)[i] = black;

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txCreateDIBSection (double sizeX, double sizeY, COLORREF** pixels)
    {
$1  return txCreateDIBSection (sizeX, sizeY, (RGBQUAD**) pixels);
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txLoadImage (const char filename[], unsigned imageFlags /*= IMAGE_BITMAP*/, unsigned loadFlags /*= LR_LOADFROMFILE*/)
    {
$1  if (_TX_ARGUMENT_FAILED (filename && *filename)) return NULL;

$   HBITMAP image = (HBITMAP) Win32::LoadImage ((loadFlags & LR_LOADFROMFILE)? NULL : GetModuleHandle (NULL),
                                                 filename, imageFlags, 0, 0, loadFlags);
$   if (!image) return NULL;

$   HDC dc = txCreateCompatibleDC (0, 0, image);

$   if (!(loadFlags & LR_LOADFROMFILE)) return dc;

$   static std::map <std::string, unsigned> loadTimes;
$   std::string file = filename;
$   unsigned time    = GetTickCount();

$   if ((long) (time - loadTimes [file]) < _TX_TIMEOUT)
        {$ txNotifyIcon (NIIF_WARNING, NULL, "�� ���������� \"%s\" ������� �����, ��������� ����� ���������.", filename); }

$   loadTimes [file] = time;

$   return dc;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDeleteDC (HDC* pdc)
    {
$1  if (_TX_ARGUMENT_FAILED (pdc)) return false;

$   HDC  dc = *pdc;
$   bool ok = _txBuffer_Delete (pdc);
$   if (!ok) return false;

$   if (!_txCanvas_UserDCs) return ok;

$   txAutoLock _lock;
$   std::vector <HDC> ::iterator it = std::find (_txCanvas_UserDCs->begin(), _txCanvas_UserDCs->end(), dc);
$   if  (it != _txCanvas_UserDCs->end()) { std::swap (*it, _txCanvas_UserDCs->back()); _txCanvas_UserDCs->pop_back(); }

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txDeleteDC (HDC dc)
    {
$1  return txDeleteDC (&dc);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txBitBlt (HDC destImage,   double xDest, double yDest, double width, double height,
               HDC sourceImage, double xSource /*= 0*/, double ySource /*= 0*/, unsigned operation /*= SRCCOPY*/)
    {
$1  if (_TX_HDC_FAILED (destImage))   return false;
$   if (_TX_HDC_FAILED (sourceImage)) return false;

$   POINT size = txGetExtent (sourceImage);
$   if (!width)  width  = size.x;
$   if (!height) height = size.y;

$   return txGDI (!!(Win32::BitBlt (destImage,   ROUND (xDest),   ROUND (yDest),   ROUND (width), ROUND (height),
                                    sourceImage, ROUND (xSource), ROUND (ySource), operation)), destImage);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txBitBlt (double xDest, double yDest, HDC sourceImage, double xSource /*= 0*/, double ySource /*= 0*/)
    {
$1  if (_TX_TXWINDOW_FAILED()) return false;

$   return txBitBlt (txDC(), xDest, yDest, 0, 0, sourceImage, xSource, ySource);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (HDC destImage,   double xDest, double yDest, double width, double height,
                       HDC sourceImage, double xSource /*= 0*/, double ySource /*= 0*/, COLORREF transColor /*= TX_BLACK*/)
    {
$1  if (_TX_HDC_FAILED (destImage))   return false;
$   if (_TX_HDC_FAILED (sourceImage)) return false;

$   POINT size = txGetExtent (sourceImage);
$   if (!width)  width  = size.x;
$   if (!height) height = size.y;

#if !defined (NDEBUG)

$   if (!(0 <= xSource && xSource + width  <= size.x &&
          0 <= ySource && ySource + height <= size.y))
        {
$       SetLastError (ERROR_INVALID_DATA);
$       TX_ERROR ("������������� ���������� ������� {%lg, %lg, %lg, %lg} �� ��������� ����� ������ �����������-��������� {%d, %d, %d, %d}, "
                  "������� txTransparentBlt() �������� �� �����.", xSource, ySource, xSource + width, ySource + height, 0, 0, (int) size.x, (int) size.y);
        }

#endif

$   bool ok = (Win32::TransparentBlt != NULL);

$   if (ok)
        {
$       ok &= txGDI (!!(Win32::TransparentBlt (destImage,   ROUND (xDest),   ROUND (yDest),   ROUND (width), ROUND (height),
                                               sourceImage, ROUND (xSource), ROUND (ySource), ROUND (width), ROUND (height), transColor)),
                                               destImage);
        }
    else
        {
$       ok &= txGDI (!!(Win32::BitBlt         (destImage,   ROUND (xDest),   ROUND (yDest),   ROUND (width), ROUND (height),
                                               sourceImage, ROUND (xSource), ROUND (ySource), SRCCOPY)),
                                               destImage);
        }

    return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txTransparentBlt (double xDest, double yDest, HDC sourceImage,
                       COLORREF transColor /*= TX_BLACK*/, double xSource /*= 0*/, double ySource /*= 0*/)
    {
$1  if (_TX_TXWINDOW_FAILED()) return false;

$   return txTransparentBlt (txDC(), xDest, yDest, 0, 0, sourceImage, xSource, ySource, transColor);
    }

//-----------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (HDC destImage,   double xDest, double yDest, double width, double height,
                   HDC sourceImage, double xSource /*= 0*/, double ySource /*= 0*/, double alpha /*= 1.0*/)
    {
    // ��� �������� ����, ���������� �� HDC �� �������� � �������.
    // �� ������� �������� - <s>��� �� ����������� ������</s> ��� ������� ��� ������� TXLib'�.

$1  if (_TX_HDC_FAILED (destImage))   return false;
$   if (_TX_HDC_FAILED (sourceImage)) return false;

    // ��� �������������� ����������� �������� �������� (������, HDC ��������� - source) � ������� txGetExtent().

$   POINT size = txGetExtent (sourceImage);
$   if (!width)  width  = size.x;
$   if (!height) height = size.y;

    // ��� �������� ����, ��� �������� (��� �� �����) ��������� �������� � ���� (������, HDC ��������� - destination, dest).
    // ���� ��� "��������" �� ���� � ����� �������, �� Win32::AlphaBlend �� ����� ��������. ��� �������� ���������� ������
    // � ������ ������� (����� �� ����� ������ NDEBUG - No Debugging, ��� �������).

#if !defined (NDEBUG)

$   if (!(0 <= xSource && xSource + width  <= size.x &&
          0 <= ySource && ySource + height <= size.y))
        {
$       SetLastError (ERROR_INVALID_DATA);
$       TX_ERROR ("������������� ���������� ������� {%lg, %lg, %lg, %lg} �� ��������� ����� ������ �����������-��������� {%d, %d, %d, %d}, "
                  "������� txAlphaBlend() �������� �� �����.", xSource, ySource, xSource + width, ySource + height, 0, 0, (int) size.x, (int) size.y);
        }

#endif

    // ��� �� ������, ���� �������� alpha �������� �� �������� [0..1].

$   if (alpha < 0) alpha = 0;
$   if (alpha > 1) alpha = 1;

    // �� ���� ��. ����.

$   BITMAP bmap = { 0, 0, 0, 0, 0, 24 };
$   bool ok = !!Win32::GetObject (txGDI ((Win32::GetCurrentObject (sourceImage, OBJ_BITMAP)), sourceImage), sizeof (bmap), &bmap);

    //
    // * ��������� BLENDFUNCTION *
    //
    // ��� ��������� ����������, ��� ����� �������� ���� (������, source DC) � �������� ����������� ��� ��������� � ������
    // ������������.
    //
    // ��������� ���������� ���������� � ������ �� ���������� - ��� ���������� ���������. ����������, �������� � ���������,
    // ���������� ������������ ���������.
    //
    // � ���� ��������� ����� ���� ����� �� ������ ��������� (��. ����), �������� ������������ ��������.
    // ���� �� ����� ���� - �� �������� ����� ��������� ��������� ���������� � ����� Win32::AlphaBlend ������ �� ��������.
    // ���� �� ����� 255  - �� �������� ����������� � ���� ���������, ��� ������� ������������.
    //
    // � ������� ���������� ���������� ��������� ������� ��������� Windows (Win32 GDI) ������, ���� �� ��������� �����-�����
    // � ���������� �������� ��� ��� ���� ������������. ���� � �������� ���������� ���� ��������� ����������� �����-�����
    // (��. �������� ������� txAlphaBlend � ������� ������ TXLib), �� ��������� ��������� ��������� ���� ������ ��� ���������
    // AC_SRC_ALPHA.
    //
    // ���� � �������� �����-������ ���������� ���, �� ��������� �������� ���� ���������� � 0.
    //
    // � ���� ���� ��������� �������� ������������ ������������� �� ������ Win32::GetObject(), ��� ��������������� ����������
    // ������� txAlphaBlend().
    //
    // ����������, �� ���� �������� ���������� ���� � ��������� ���� ���. ��������� ���, � ������, ������ �� �� ������������
    // �����-����� ��� ���, � ���������� ��������� �������� ��������� ���� AC_SRC_ALPHA, ���� 0. ����� ���� ���������� ��
    // �������� ��������� ������� ��� � ���������� ��������� ���� �����. :((
    //
    // �� ������� ($) �� ��������� ��������, ��� ����� ��� ������� ���������� TXLib. � ����� ��������� �� ������������ �� ����.
    //
    //                       ____1____   2   ___________3___________     _______________________4________________________
    //                      /         \  |  /                       \   /                                                \.

$   BLENDFUNCTION blend = { AC_SRC_OVER, 0, (BYTE) ROUND (alpha * 255), (BYTE) ((bmap.bmBitsPixel == 32)? AC_SRC_ALPHA : 0) };

    //
    // * ����� ����������� ������� Win32::AlphaBlend() *
    //
    // ���� - ��� ����� Win32::AlphaBlend(). �� ��� �������, ���, ���� ����� ���-�� �� ���������� (�.�. Win32::AlphaBlend()
    // ������ 0), �� ����� ����� ������� Win32::BitBlt(), ������� ������ ��������� �������� ��� ����� ������������. ���������
    // "Windows AlphaBlend function" � ��������� ��� �� ���������.
    //
    // ��� ������, ������������ ������� �� Win32 ��������� ������� �� ������ ��������, �� � �������� ��������, � ���� ��� ��
    // ���������, �� �������� ����� ��������� ��� ���������. TXlib'������ <s>�������</s> ������� txAlphaBlend ������������, ���
    // ��� ������� ������ ���������, � ������� ��� ������ � txAlphaBlend() ������� ����� ������ 1:1. <s>��� ���� �������, ��</s>
    // ��� ������� ��� ��������� ������ ������� txAlphaBlend().

$   if (Win32::AlphaBlend) // ������ ��, ��� ��� ��������� ���������� �����������, �� ���� ����������� ������ ������� ��������!   // <<--
        {                  //                           //                                       vvvvv          vvvvvv            // <<--
$       ok &= txGDI (!!(Win32::AlphaBlend (destImage,   ROUND (xDest),   ROUND (yDest),   ROUND (width), ROUND (height),          // <<==
                                           sourceImage, ROUND (xSource), ROUND (ySource), ROUND (width), ROUND (height), blend)), // <<==
                                           destImage);  //                                       ^^^^^          ^^^^^^            // <<--
        }                  //                                                                    |||||          ||||||            // <<--
                           // ��. "AlphaBlend function" � Google, ����� ����� ���������� wSrc � wDest (hSrc � hDest). �������!    // <<--

    else
        {
$       ok &= txGDI (!!(Win32::BitBlt     (destImage,   ROUND (xDest),   ROUND (yDest),   ROUND (width), ROUND (height),
                                           sourceImage, ROUND (xSource), ROUND (ySource), SRCCOPY)),
                                           destImage);
$       ok = false;
        }

    // � ���� ������� �������� � ������������ ������, ��� �������� ����, � ��� ��� �� ��������, ��� �������� ������� ����
    // ����������� ������� ��� ����������� �������� �����������. <s>���� �� ������� �� ����� �����,</s> �������� � ���� TXLib'�
    // �� ����������� GDI Win32, <s>���� GDI ���� ��� ����, ��� ��� ����� ������ GDI+, SFML, OpenGL ��� DirectX, ����� �����.
    // ���� ��� � �������.</s>

    // �� ����� ��� ������� �������� � �����, ��. ����. � �����������.

$   return ok;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txAlphaBlend (double xDest, double yDest, HDC sourceImage,
                   double xSource /*= 0*/, double ySource /*= 0*/, double alpha /*= 1.0*/)
    {
$1  if (_TX_TXWINDOW_FAILED()) return false;

$   return txAlphaBlend (txDC(), xDest, yDest, 0, 0, sourceImage, xSource, ySource, alpha);
    }

//-----------------------------------------------------------------------------------------------------------------

HDC txUseAlpha (HDC image)
    {
$1  if (_TX_HDC_FAILED (image)) return NULL;

$   HBITMAP bitmap = (HBITMAP) Win32::GetCurrentObject (image, OBJ_BITMAP);
$   if (!bitmap) return NULL;

$   DIBSECTION dib = {};
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

$       Win32::GetDIBits (image, bitmap, 0, size.y, buf, &info, DIB_RGB_COLORS) asserted;
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
$       Win32::SetDIBitsToDevice (image, 0, 0, size.x, size.y, 0, 0, 0, size.y, buf, &info, DIB_RGB_COLORS) asserted;

$       delete[] buf;
        }

$   return image;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txSaveImage (const char filename[], HDC dc /*= txDC()*/)
    {
$1  if (_TX_ARGUMENT_FAILED    (filename)) return false;
$   if (_TX_DEFAULT_HDC_FAILED (dc))       return false;

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

double txSleep (double time)
    {
$1  LARGE_INTEGER start = {};
$   QueryPerformanceCounter (&start) asserted;

$   LARGE_INTEGER freq = {};
$   QueryPerformanceFrequency (&freq) asserted;

$   int lock = _txCanvas_RefreshLock;
$   _txCanvas_RefreshLock = 0;

$   HWND wnd = txWindow();
    if (wnd) {$ RedrawWindow (wnd, NULL, NULL, RDW_INVALIDATE | RDW_INTERNALPAINT | RDW_UPDATENOW); }

$   Sleep (ROUND ((time >= 0)? time : 0));

$   _txCanvas_RefreshLock = lock;

$   LARGE_INTEGER stop = {};
$   QueryPerformanceCounter (&stop) asserted;

$   return 1000.0 * (double) (stop.QuadPart - start.QuadPart) / (double) freq.QuadPart;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txLock (bool wait /*= true*/)
    {
$0  if (_txCanvas_RefreshLock <= 0 || _txExit) Sleep (0);

$   if (wait) {$ return      EnterCriticalSection (&_txCanvas_LockBackBuf), true; }
    else      {$ return !!TryEnterCriticalSection (&_txCanvas_LockBackBuf);       }
    }

//-----------------------------------------------------------------------------------------------------------------

bool txUnlock()
    {
$0  LeaveCriticalSection (&_txCanvas_LockBackBuf);

$   if (_txCanvas_RefreshLock <= 0 || _txExit) Sleep (0);
$   return false;
    }

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

template <typename T>
inline T txUnlock (T value)
    {
$1  txUnlock();
$   return value;
    }

//-----------------------------------------------------------------------------------------------------------------

inline void txRedrawWindow()
    {
$1  txSleep (0);
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

inline POINT txMousePos()
    {
$1  POINT pos = {};
$   GetCursorPos (&pos);

$   if (txWindow())
        {$ ScreenToClient (txWindow(), &pos); }

$   return pos;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txMouseX()
    {
    return txMousePos() .x;
    }

//-----------------------------------------------------------------------------------------------------------------

inline int txMouseY()
    {
    return txMousePos() .y;
    }

//-----------------------------------------------------------------------------------------------------------------

inline unsigned txMouseButtons()
    {
$1  return ((GetAsyncKeyState (VK_LBUTTON) & 0x8000) >> 15) |  // MSB to bit 0
           ((GetAsyncKeyState (VK_RBUTTON) & 0x8000) >> 14) |  // MSB to bit 1
           ((GetAsyncKeyState (VK_MBUTTON) & 0x8000) >> 13);   // MSB to bit 2
    }

//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

unsigned txSetConsoleAttr (unsigned color /*= FOREGROUND_LIGHTGRAY*/)
    {
    unsigned oldAttr = txGetConsoleAttr();

    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), (WORD) color);

    return oldAttr;
    }

//-----------------------------------------------------------------------------------------------------------------

unsigned txGetConsoleAttr()
    {
    CONSOLE_SCREEN_BUFFER_INFO con = {};
    GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con);

    return con.wAttributes;
    }

//-----------------------------------------------------------------------------------------------------------------

POINT txSetConsoleCursorPos (double x, double y)
    {
$1  POINT fontSz = txGetConsoleFontSize();

$   CONSOLE_SCREEN_BUFFER_INFO con = {};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   COORD pos = { (short) ROUND (1.0 * x / fontSz.x + con.srWindow.Left),
                  (short) ROUND (1.0 * y / fontSz.y + con.srWindow.Top ) };

$   SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), pos) asserted;

$   POINT prev = { ROUND ((con.dwCursorPosition.X - con.srWindow.Left) * fontSz.x),
                   ROUND ((con.dwCursorPosition.Y - con.srWindow.Top ) * fontSz.y) };
$   return prev;
    }

//-----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleCursorPos()
    {
$1  POINT fontSz = txGetConsoleFontSize();

$   CONSOLE_SCREEN_BUFFER_INFO con = {};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   POINT  pos = { ROUND ((con.dwCursorPosition.X - con.srWindow.Left) * fontSz.x),
                   ROUND ((con.dwCursorPosition.Y - con.srWindow.Top ) * fontSz.y) };
$   return pos;
    }

//-----------------------------------------------------------------------------------------------------------------

POINT txGetConsoleExtent()
    {
$1  CONSOLE_SCREEN_BUFFER_INFO con = {};
$   GetConsoleScreenBufferInfo (GetStdHandle (STD_OUTPUT_HANDLE), &con) asserted;

$   POINT  size = { con.srWindow.Right  - con.srWindow.Left + 1,
                    con.srWindow.Bottom - con.srWindow.Top  + 1 };
$   return size;
    }

//-----------------------------------------------------------------------------------------------------------------

bool txClearConsole()
    {
$1  HANDLE out = GetStdHandle (STD_OUTPUT_HANDLE);

$   CONSOLE_SCREEN_BUFFER_INFO con = {};
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
$1  Win32::CONSOLE_FONT_INFO font = {0, {8, 16}};

$   _TX_CALL (Win32::GetCurrentConsoleFont, (GetStdHandle (STD_OUTPUT_HANDLE), false, &font));

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
$1  mode |= SND_FILENAME | SND_NODEFAULT | SND_NOWAIT;
$   if (mode & SND_LOOP) mode = (mode & ~SND_SYNC) | SND_ASYNC;

$   if (!filename) mode = SND_PURGE;

$   return !!Win32::PlaySound (filename, NULL, mode);
    }

//-----------------------------------------------------------------------------------------------------------------

int txSpeak (const char* text, ...)
    {
$1  bool verbose = false; (void) verbose;
$   bool async   = false; (void) async;

$   for (; text && *text; text++)
        {
        if      (*text == '\a') {$ async   = true; }
        else if (*text == '\v') {$ verbose = true; }
        else break;
        }

$   char textA [_TX_BUFSIZE] = "You asked to speak empty text. I would rather say that TX Library is cool! Cats rules!";

$   va_list arg; va_start (arg, text);
    if (text && *text) {$ _tx_vsnprintf_s (textA, sizeof (textA) - 1, text, arg); }
$   va_end (arg);

#ifdef TX_USE_SPEAK

    if (text && verbose) {$ printf ("%s", textA); }

$   int time = GetTickCount();

$   static wchar_t textW [_TX_BUFSIZE * sizeof (wchar_t)] = L"";
$   MultiByteToWideChar (_TX_CODEPAGE, 0, textA, -1, textW, sizearr (textW));

$   static ISpVoice* voice = NULL;

$   if (text && !voice)
        {
$       HRESULT res = Win32::CoInitialize (NULL);
        if (res == S_OK) {$ Win32::CoCreateInstance (Win32::CLSID_SpVoice, NULL, CLSCTX_ALL, Win32::IID_ISpVoice, (void**) &voice); }
        }

$   if (text && voice)
        {
$       Win32::_fpreset();
$       voice->Speak (textW, SPF_PERSIST_XML | SPF_PURGEBEFORESPEAK | (async? SPF_ASYNC : 0), NULL);
$       tx_fpreset();
        }

$   if (!text && voice)
        {
$       voice->Release();
$       voice = NULL;

$       Win32::CoUninitialize();
        }

$   return (voice)? GetTickCount() - time : -1;

#else

$   if (text)
        {
$       unsigned oldAttr = txSetConsoleAttr (FOREGROUND_LIGHTRED | BACKGROUND_BLACK);

$       txNotifyIcon (NIIF_ERROR, "txSpeak(): �� ���� ���������� (����� TX_USE_SPEAK, ��. TXLib Help)", "\n" "%s", textA);

$       txSetConsoleAttr (oldAttr);
        }

$   return -1;

#endif
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t txPlayVideo (int x, int y, int width, int height, const char fileName[],
                      double zoom /*= 0*/, double gain /*= 1*/, HWND wnd /*= txWindow()*/)
    {
$1  if (wnd && wnd == txWindow() && _TX_TXWINDOW_FAILED()) return -1;

$   int time = GetTickCount();

$   static char processUID [64] = "";
    if (!*processUID)
        {
$       FILETIME startTime = {}, null = {};
$       GetProcessTimes (GetCurrentProcess(), &startTime, &null, &null, &null) asserted;
$       _snprintf_s (processUID, sizeof (processUID) - 1, "TXLib[%08X%08X]::txPlayVideo",
                    (unsigned) startTime.dwHighDateTime, (unsigned) startTime.dwLowDateTime) < (int) sizeof (processUID) asserted;
        }

$   if (!fileName)
        {
$       _txTaskKill ("vlc.exe", processUID, 0);  // Kill'em all, by command line pattern
$       return 0;
        }

$   static const char* vlcPath = _txPlayVideo_FindVLC();

$   if (!vlcPath || _access (vlcPath, 0) != 0)
        {
$       static int once = false;

$       if (*fileName && !once++)
            {$ txOutputDebugPrintf ("\a" "�� ������ ������������������ VideoLAN (vlc.exe). C������� ��� � ����� VideoLAN.org "
                                    "� ����������. ��� ��������� VideoLAN ����� ���������������� �� ����� :(\n\n"
                                    "--\n" "������ ����, ������� " /* ��� �� */ "txPlayVideo()...\n"
                                    "P.S. ��. ��� �������� � TXLib Help."); }
$       return INT_MIN;
        }

$   bool async = false;
    if (*fileName == '\a') {$ async = true; fileName++; }

$   RECT rect = {};
    if (wnd) {$ GetClientRect (wnd, &rect); }

    if (!width)  {$ width  = rect.right;  }
    if (!height) {$ height = rect.bottom; }

    // Create a child window to hold the video stream

$   const char* errPos = "��������";

$   volatile HWND child = NULL;
$   if (wnd && (wnd == txWindow()))
        {
$       const char* wndClass = txRegisterClass ("txPlayVideo", _txPlayVideo_WndProc, 0, NULL_BRUSH, 1);

$       static int number = 1;
$       CREATESTRUCT createData = { NULL, NULL, (HMENU) (size_t) number++, txWindow(), height, width, y, x,
                                    WS_CHILD | WS_CLIPSIBLINGS | WS_VISIBLE, __func__, wndClass };
$       child = txCreateExtraWindow (createData);
$       if (!child)
            {
$           txNotifyIcon (NIIF_ERROR, "txPlayVideo() ��������", "\n" "%s",
                                       strstr (_txError (NULL, 0, NULL, 0, "\f" "�� ���� ������� ���� ��� ����� :("), errPos));
$           return INT_MIN+3;
            }

$       BringWindowToTop (child);

$       wnd = child;
        }

    // Build the command line

    if (!zoom && !wnd) {$ zoom = 1; }

$   char sZoom [64] = "--autoscale";
    if (zoom) {$ _snprintf_s (sZoom, sizeof (sZoom) - 1, "--no-autoscale --zoom=%.10g", zoom) < (int) sizeof (sZoom) asserted; }

$   static char cmd [MAX_PATH*2 + 1024] = "";

$   _snprintf_s (cmd, sizeof (cmd) - 1, "\"%s\" \"%s\" vlc://quit"

                 " %s --gain=%.10g --drawable-hwnd=%p --video-title=\"%s\" --logfile=%s"

                 " --live-caching=500 --network-caching=500 --quiet-synchro --no-embedded-video --file-logging"

                 " --ignore-config --reset-config --no-one-instance --play-and-exit"
                 " --intf=dummy --dummy-quiet --quiet --no-video-deco --no-video-title-show --no-stats --no-sub-autodetect-file"
                 " --no-disable-screensaver --no-snapshot-preview --no-auto-preparse --no-mouse-events --no-keyboard-events",

                 vlcPath, (*fileName? fileName : "fileName"), sZoom, gain, (void*) wnd, processUID, _txLogName) < (int) sizeof (cmd) asserted;

$   txOutputDebugPrintf ("txPlayVideo (%d, %d, %d, %d, \"%s\", %lg, %lg, %p): [%s]\n\n",
                         x, y, width, height, fileName, zoom, gain, wnd, cmd);
$   if (!*fileName)
        {
        if (child) {$ txDestroyWindow (child); }
$       return (intptr_t) cmd;
        }

$   if (!strstr (fileName, "://") && _access (fileName, 0) != 0)
        {
$       txNotifyIcon (NIIF_ERROR, "txPlayVideo() ��������", "\n" "%s",
                                   strstr (_txError (NULL, 0, NULL, 0, "\f" "�� ������ ���� \"%s\"", fileName), errPos));

        if (child) {$ txDestroyWindow (child); }
$       return INT_MIN+1;
        }

    // Run VLC, run

$   PROCESS_INFORMATION vlc   = {};
$   STARTUPINFO         start = { sizeof (start) };
$   DWORD               ret   = 0;

$   if (CreateProcess (NULL, cmd, NULL, NULL, true, 0, NULL, NULL, &start, &vlc) &&
        vlc.hProcess && vlc.hThread)
        {
$       if (child)
            {
$           assert (wnd == child);
$           SetWindowLongPtr (wnd, GWLP_USERDATA, (LONG_PTR) vlc.hProcess);
            }

$       if (!async)
            {
$           WaitForSingleObject (vlc.hProcess, INFINITE);
$           GetExitCodeProcess  (vlc.hProcess, &ret) asserted;
            }

$       if (!child)
            {
$           CloseHandle (vlc.hProcess) asserted;
            }

$       CloseHandle (vlc.hThread) asserted;

$       return (async? (intptr_t) wnd : (ret == 0)? time - GetTickCount() : - (int) ret);
        }
    else
        {
$       txNotifyIcon (NIIF_ERROR, "txPlayVideo() ��������", "%s",
                                   strstr (_txError (NULL, 0, NULL, 0, "\f" "������ ������� VideoLAN (%s)", cmd), errPos));
$       if (child)
            {$ txDestroyWindow (child); }

$       return INT_MIN+4;
        }

    #undef PROCESS_UID_
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t txPlayVideo (const char fileName[], double zoom /*= 0*/, double gain /*= 0*/, HWND wnd /*= txWindow()*/)
    {
$1  return txPlayVideo (0, 0, 0, 0, fileName, zoom, gain, wnd);
    }

//-----------------------------------------------------------------------------------------------------------------

LRESULT CALLBACK _txPlayVideo_WndProc (HWND wnd, UINT msg, WPARAM wpar, LPARAM lpar)
    {
    const UINT_PTR checkTimer = 1;

    switch (msg)
        {
        case WM_CREATE:
            {
$1          SetTimer  (wnd, checkTimer, 5*_txWindowUpdateInterval, NULL) asserted;
            }
            break;

        case WM_DESTROY:
            {
$1          KillTimer (wnd, checkTimer) asserted;

$           HANDLE vlc = (HANDLE)(uintptr_t) GetWindowLongPtr (wnd, GWLP_USERDATA);

$           if (vlc)
                {
$               Win32::TerminateProcess (vlc, 0);

$               CloseHandle (vlc) asserted;

$               SetWindowLongPtr (wnd, GWLP_USERDATA, 0);
                }
            }
            break;

        case WM_TIMER:
            {
            HANDLE vlc = (HANDLE)(uintptr_t) GetWindowLongPtr (wnd, GWLP_USERDATA);

            if (vlc && WaitForSingleObject (vlc, 0) != WAIT_TIMEOUT)
                {
$1              DestroyWindow (wnd) asserted;
                }
            }
            break;

        default:
            break;
        }

    return DefWindowProc (wnd, msg, wpar, lpar);
    }

//-----------------------------------------------------------------------------------------------------------------

const char* _txPlayVideo_FindVLC()
    {
$1  static char vlcPath [MAX_PATH] = "";

$   if (SearchPath (NULL, "vlc.bat", NULL, sizeof (vlcPath), vlcPath, NULL))
        {
        if (_access (vlcPath, 0) == 0) {$ return vlcPath; }
        }

$   if (SearchPath (NULL, "vlc.exe", NULL, sizeof (vlcPath), vlcPath, NULL))
        {
        if (_access (vlcPath, 0) == 0) {$ return vlcPath; }
        }

$   if (txRegQuery ("HKLM\\Software\\VideoLAN\\VLC", NULL, vlcPath, sizeof (vlcPath)))
        {
        if (_access (vlcPath, 0) == 0) {$ return vlcPath; }
        }

$   if (txRegQuery ("HKLM\\Software\\VideoLAN\\VLC", "InstallDir", vlcPath, sizeof (vlcPath)))
        {
$       strncat_s (vlcPath, sizeof (vlcPath) - 1, "\\vlc.exe", INT_MAX);

        if (_access (vlcPath, 0) == 0) {$ return vlcPath; }
        }

$   strncpy_s (vlcPath, sizeof (vlcPath), "C:\\Program Files"    "\\VideoLAN\\VLC\\vlc.exe", UINT_MAX);
        {
        if (_access (vlcPath, 0) == 0) {$ return vlcPath; }
        }

$   strncpy_s (vlcPath, sizeof (vlcPath), "C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe", UINT_MAX);
        {
        if (_access (vlcPath, 0) == 0) {$ return vlcPath; }
        }

$   return NULL;
    }

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

// +--<<< ��� ���� �� ����� ��������� � ����, ��� �� ����� :)
// V      ������� �������� �� ������ �����, �� � ����

inline WNDPROC txSetWindowsHook (WNDPROC wndProc /*= NULL*/)
    {
$1  WNDPROC old = _txAltWndProc; _txAltWndProc = wndProc;
$   return  old;
    }

//-----------------------------------------------------------------------------------------------------------------

//     +--<<< � ���, �������, ������� ����������� ���� �������.
//     |      �������� �� ��������! ������ ��� ������� ���-�� �����.
//     |
//     v
inline bool txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture()
    {
    txMessageBox ("��� ��������������� ������. ����� ������. �� ������ �������:\n\n"

                  "txIDontWantToHaveAPauseAfterMyProgramBeforeTheWindowWillClose_AndIWillNotBeAskingWhereIsMyPicture()\n\n"

                  "���� �� ����� [����������]�������� ��� ���, �� ����� ���� ��� ������� �� �����������. "
                  "���� ������ �������, ������� ������� ����-����� � ����� ���������, �� � ����� ��� ��� �� ��������.\n\n"

                  "�� �� ��� ��� �����. ����������� ������ ������� ���� � �������� ������� TXLib.h, ��� ����� ����� "
                  "� ������������ ��� ������� � ������� ���������, ������� �� ������ �������.\n\n"

                  "������� � ��������� Ctrl+O, ������� � �������� ���� TXLib.h (�� ����� � �����, ���� �� "
                  "���������� TXLib), ����� ������� Ctrl+F � ����� \"txIDontWant\". �����!\n\n",

                  "�� ����������", MB_ICONSTOP);

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

// P.S. This library contains more undocumented functions. Search them via "Luke" keyword.

//-----------------------------------------------------------------------------------------------------------------

#ifndef TX_COMPILED

void _txDump (const void* address, const char name[] /*= "_txDump()"*/, bool pause /*= true*/)
    {
$1  assert (!_txIsBadReadPtr (address));

    const unsigned char* p = (const unsigned char*) address;
$   unsigned x = 0;

$   unsigned attr = txGetConsoleAttr();

$   txSetConsoleAttr (FOREGROUND_WHITE);
$   printf ("\n%*.*s ", (int) sizeof (address) * 2, (int) sizeof (address) * 2, ((name)? name : ""));

$   txSetConsoleAttr (FOREGROUND_YELLOW);
$   for (x = 0; x < 16; x++) printf ("%02X ", x);
$   for (x = 0; x < 16; x++) printf ("%X",    x);

$   const char   isCtrl[] = "\a" "\b" "\n" "\r" "\t" "\0";
$   const char   xlatCh[] =  "�"  "�"  "�"  "�"  "�"  "�";
$   const size_t szCtrl   = sizeof (isCtrl) - 1;

$   int oldCP = GetConsoleOutputCP();

$   for (int y = 0; y < 16; y++, p += 16)
        {
        txSetConsoleAttr (FOREGROUND_YELLOW);

        printf ("\n" "%*p ", (int) sizeof (address) * 2, p);

        int color = FOREGROUND_LIGHTGREEN;

        for (x = 0; x < 16; x++)
            {
            txSetConsoleAttr (color + x/4%2);
            printf ("%02X ", p[x]);
            }

        for (x = 0; x < 16; x++)
            {
            txSetConsoleAttr (color + x/4%2);

            char c = p[x];
            const char* ctrl = (const char*) memchr (isCtrl, c, szCtrl);
            if (ctrl) c = xlatCh [ctrl - isCtrl];

            if (ctrl) SetConsoleOutputCP (1251);

            printf ("%c", c);

            if (ctrl) SetConsoleOutputCP (oldCP);
            }
        }

$   txSetConsoleAttr (attr);
$   printf ("\n");

$   if (pause)
        {
$       SetConsoleOutputCP (_TX_CODEPAGE);

$       fprintf (stderr, "[������� ����� ������� ��� �����������]                          CodePage = %5d\n", oldCP);
$       (void)_getch();

$       SetConsoleOutputCP (oldCP);
        }
    }

//-----------------------------------------------------------------------------------------------------------------

void _txStackBackTrace (const char file[] /*= "?"*/, int line /*= 0*/, const char func[] /*= "?"*/,
                        bool readSource /*= true*/)
    {
$1  unsigned attr = txGetConsoleAttr();
$   txSetConsoleAttr (FOREGROUND_LIGHTCYAN);

$   fprintf (stderr, "\n" "--------------------------------------------------\n"
                          "����������� ����� �� \"%s\" at %s (%d):\n\n"
                          "%s\n\n"
                          "--------------------------------------------------\n\n",
                          func, file, line, _txCaptureStackBackTrace (1, readSource));

$   txSetConsoleAttr (attr);
    }

//-----------------------------------------------------------------------------------------------------------------

char* txDemangle (const char* mangledName, std::nomeow_t)
    {
$1  if (!mangledName) return NULL;

$   char* typeName = NULL;

    #if defined (_GCC_VER)

$   int err = 1;
$   typeName = ::abi::__cxa_demangle (mangledName, 0, 0, &err); (void) err;
    if (typeName) {$ return typeName; }

    #endif

$   unsigned short flags = 0;

$   if (mangledName[0] == '.')
        {
$       mangledName++;
$       flags = 0x2800;  // UNDNAME_32_BIT_DECODE | UNDNAME_TYPE_ONLY
        }

$   typeName = _TX_CALL (Win32::__unDName, (NULL, mangledName, 0, malloc, free, flags));
    if (typeName) {$ return typeName; }

$   return _strdup (mangledName);
    }

//-----------------------------------------------------------------------------------------------------------------

std::string txDemangle (const char* mangledName)
    {
$1  char* typeName = txDemangle (mangledName, std::nomeow);
$   std::string name (typeName? typeName : "");
$   free (typeName);

$   return name;
    }

//-----------------------------------------------------------------------------------------------------------------

double txQueryPerformance()
    {
$1  int maxTime    =  500;
$   int maxSamples =  100;
$   POINT size     = {100, 100};

$   HDC dc = _txBuffer_Create (txWindow(), &size, NULL);
$   assert (dc); if (!dc) return -1;

$   DWORD mask = (DWORD) SetThreadAffinityMask (GetCurrentThread(), 1);
$   assert (mask);

$   LARGE_INTEGER freq = {};
$   QueryPerformanceFrequency (&freq) asserted;

$   LARGE_INTEGER start = {};
$   QueryPerformanceCounter (&start) asserted;

$   int samples = 0;
$   while (samples++ < maxSamples)
        {
$       LARGE_INTEGER cur = {};
$       QueryPerformanceCounter (&cur) asserted;

$       double t = 1000.0 * (double) (cur.QuadPart - start.QuadPart) / (double) freq.QuadPart;
$       if (t > maxTime) break;

        // Draw test scene

$       for (int y = 0; y < size.y; y++)
        for (int x = 0; x < size.x; x++)     txSetPixel (x, y, TX_BLACK, dc);

$       for (int y = 0; y < size.y; y += 10)
        for (int x = 0; x < size.x; x += 50) txTextOut  (x, y, "*", dc);

$       txEllipse (0, 0, size.x, size.y, dc);
$       txFloodFill (size.x/2, size.y/2, TX_TRANSPARENT, FLOODFILLSURFACE, dc);

$       txBitBlt (dc, size.x/2,        0, size.x/2, size.y/2, dc,        0,        0) asserted;
$       txBitBlt (dc, size.x/2, size.y/2, size.x/2, size.y/2, dc,        0, size.y/2) asserted;
$       txBitBlt (dc,        0, size.y/2, size.x/2, size.y/2, dc,        0,        0) asserted;
$       txBitBlt (dc, size.x/2, size.y/2, size.x/2, size.y/2, dc, size.x/2,        0) asserted;
        }

$   mask = (DWORD) SetThreadAffinityMask (GetCurrentThread(), mask);
$   assert (mask);

$   _txBuffer_Delete (&dc);

$   return 3.0 * samples / sqrt (1.0 * size.x * size.y);
    }

//-----------------------------------------------------------------------------------------------------------------

#if defined (_TX_CPP11) && !defined (TX_COMPILED)
template <int txFramesToAverage>
#endif

double txGetFPS (int minFrames)
    {
$1  static _tx_thread LARGE_INTEGER time0 = {}; if (!time0.QuadPart) QueryPerformanceCounter (&time0);
$                     LARGE_INTEGER time  = {};                      QueryPerformanceCounter (&time);

$   if (time.QuadPart - time0.QuadPart == 0)
        {$ return 0; }

$   LARGE_INTEGER freq = {}; QueryPerformanceFrequency (&freq);

$   double fps = (double) freq.QuadPart / (double) (time.QuadPart - time0.QuadPart);
$   time0 = time;

$   if (txFramesToAverage == 0) return fps;

$   static _tx_thread double average [txFramesToAverage] = {};
$   static _tx_thread unsigned n = 0;

$   average [n++ % txFramesToAverage] = fps;

$   unsigned nn = MIN (n, (unsigned) sizearr (average));

$   static _tx_thread double median  [txFramesToAverage] = {};
$   std::copy (average, average + nn, median);
$   std::nth_element (median, median + nn/2, median + nn);

$   fps = (median [(nn-1) / 2] + median [nn / 2]) / 2.0;

$   return ((int)n >= MIN (minFrames, txFramesToAverage))? fps : 0;
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
$1  int r = (int) txExtractColor (rgbColor, TX_RED),
        g = (int) txExtractColor (rgbColor, TX_GREEN),
        b = (int) txExtractColor (rgbColor, TX_BLUE);

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

$   int h = (int) txExtractColor (hslColor, TX_HUE),
        s = (int) txExtractColor (hslColor, TX_SATURATION),
        l = (int) txExtractColor (hslColor, TX_LIGHTNESS);

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

void tx_fpreset()
    {
$1  txAutoLock _lock;

$   Win32::_fpreset();

$   unsigned new87 = 0x0008001C;  // _EM_INVALID | _EM_DENORMAL | _EM_ZERODIVIDE | _EM_OVERFLOW | _EM_UNDERFLOW

    #if !defined (__CYGWIN__)

$   unsigned old87 = 0;
$   if (_controlfp_s (&old87, 0, 0) == 0)
        {$ (void) _controlfp_s (&old87, old87  & ~new87, 0x0008001F); }  // _MCW_EM

    #else

$   Win32::_controlfp (Win32::_controlfp (0, 0) & ~new87, 0x0008001F);    // _MCW_EM

    #endif
    }

#endif // TX_COMPILED

//-----------------------------------------------------------------------------------------------------------------

inline double random (std::nomeow_t, double left, double right)
    {
    return left + (right - left) * ((double) rand() / RAND_MAX);
    }

//-----------------------------------------------------------------------------------------------------------------

inline int random (int range)
    {
    if (rand() % 100 == 0) fprintf (stderr, "%.4s ", (const volatile char*) ((rand() & 0x0F)? &_txCanaryFirst : &_txCanaryLast));

    return rand() % range;
    }

//-----------------------------------------------------------------------------------------------------------------

inline double random (double left, double right)
    {
    if (rand() % 100 == 0) fprintf (stderr, "%.4s ", (const volatile char*) ((rand() & 0x0F)? &_txCanaryFirst : &_txCanaryLast));

    return random (std::nomeow, left, right);
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T>
inline T zero() { T __zero = {}; return __zero; }

//-----------------------------------------------------------------------------------------------------------------

template <typename Tx, typename Ta, typename Tb>
inline bool In (std::nomeow_t, Tx x, Ta a, Tb b)
    {
    return a <= x && x <= b;
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename Tx, typename Ta, typename Tb>
inline bool In (Tx x, Ta a, Tb b)
    {
    if (rand() % 100 == 0) fprintf (stderr, "%.4s ", (const volatile char*) ((rand() & 0x0F)? &_txCanaryFirst : &_txCanaryLast));

    return In (std::nomeow, x, a, b);
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool In (const POINT& pt, const RECT& rect)
    {
    if (_TX_ARGUMENT_FAILED (&pt))   return false;
    if (_TX_ARGUMENT_FAILED (&rect)) return false;

    return In (std::nomeow, pt.x, rect.left, rect.right) &&
           In (std::nomeow, pt.y, rect.top,  rect.bottom);
    }

//-----------------------------------------------------------------------------------------------------------------

inline bool In (const COORD& pt, const SMALL_RECT& rect)
    {
    if (_TX_ARGUMENT_FAILED (&pt))   return false;
    if (_TX_ARGUMENT_FAILED (&rect)) return false;

    return In (std::nomeow, pt.X, rect.Left, rect.Right) &&
           In (std::nomeow, pt.Y, rect.Top,  rect.Bottom);
    }

//}
//=================================================================================================================

//=================================================================================================================
//{          txPrintf() implementation
//           ���������� txPrintf()
//=================================================================================================================

#if defined (_TX_CPP11)

template <typename T, typename... ArgsT> void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt,                                  const T& arg, ArgsT... args);
template <typename T, typename... ArgsT> void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt, width_t width,                   const T& arg, ArgsT... args);
template <typename T, typename... ArgsT> void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt,                precision_t prec, const T& arg, ArgsT... args);
template <typename T, typename... ArgsT> void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt, width_t width, precision_t prec, const T& arg, ArgsT... args);
                                         void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt);

template <typename T>                    void _txPrintV (std::ostringstream& stream, const char* format, int n, const char*& fmt, const T& arg);
                                         void _txPrintV (std::ostringstream& stream, const char* format, int n, const char*& fmt, int*     arg);
                                         void _txPrintV (std::ostringstream& stream, const char* format, int n, const char*& fmt);

//-----------------------------------------------------------------------------------------------------------------

template <typename T, typename... ArgsT>
void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt, const T& arg, ArgsT... args)
    {
$1  assert (fmt);

$   _txPrintV (stream, format, n,   fmt);

    if (fmt[0] == '%') {$}
    else {$ TX_ERROR ("\"%%$\" required to print an argument in ...\"%s\" while printing %s argument %d in \"%s\"", fmt, txTypename (arg), n, format); }

$   _txPrintV (stream, format, n,   fmt, arg);

$   _txPrintF (stream, format, n+1, fmt, args...);
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T, typename... ArgsT>
void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt, width_t width, const T& arg, ArgsT... args)
    {
$1  assert (&stream);
$   assert (fmt);

$   _txPrintV (stream, format, n,   fmt);

    if (fmt[0] == '%' && fmt[1] == '*') {$ stream << std::setw (width); }
    else {$ TX_ERROR ("\"%%*\" required to setwidth (%d) in ...\"%s\" while printing %s argument %d in \"%s\"", width, fmt, txTypename (arg), n, format); }

$   _txPrintV (stream, format, n,   fmt, arg);

$   _txPrintF (stream, format, n+1, fmt, args...);
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T, typename... ArgsT>
void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt, precision_t prec, const T& arg, ArgsT... args)
    {
$1  assert (&stream);
$   assert (fmt);

$   _txPrintV (stream, format, n,   fmt);

    if (fmt[0] == '%' && fmt[1] == '.' && fmt[2] == '*') {$ stream << std::setprecision (prec+1); }
    else {$ TX_ERROR ("\"%%.*\" required to setprecision (%d) in ...\"%s\" while printing %s argument %d in \"%s\"", prec, fmt, txTypename (arg), n, format); }

$   _txPrintV (stream, format, n,   fmt, arg);

$   _txPrintF (stream, format, n+1, fmt, args...);
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T, typename... ArgsT>
void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt, width_t width, precision_t prec, const T& arg, ArgsT... args)
    {
$1  assert (&stream);
$   assert (fmt);

$   _txPrintV (stream, format, n,   fmt);

    if (fmt[0] == '%' && fmt[1] == '*' && fmt[2] == '.' && fmt[3] == '*') {$ stream << std::setw (width) << std::setprecision (prec+1); }
    else {$ TX_ERROR ("\"%%*.*\" required to setwidth (%d) and setprecision (%d) in ...\"%s\" while printing %s argument %d in \"%s\"", width, prec, fmt, txTypename (arg), n, format); }

$   _txPrintV (stream, format, n,   fmt, arg);

$   _txPrintF (stream, format, n+1, fmt, args...);
    }

//-----------------------------------------------------------------------------------------------------------------

inline void _txPrintF (std::ostringstream& stream, const char* format, int n, const char*& fmt)
    {
$1  assert (fmt);

$   _txPrintV (stream, format, n,   fmt);

    if (!fmt[0]) {$}
    else {$ TX_ERROR ("No argument provided for %% in \"%s\" while printing \"%s\"", fmt, format); }
    }

//-----------------------------------------------------------------------------------------------------------------

inline void _txPrintV (std::ostringstream& stream, const char*, int, const char*& fmt)
    {
$1  assert (&stream);
$   assert (fmt);

$   while (*fmt)
        {
        if (fmt[0] == '%')
            {
            if (fmt[1] == '%') fmt++;
            else break;
            }

        stream << *fmt++;
        }
$   }

//-----------------------------------------------------------------------------------------------------------------

template <typename T>
void _txPrintV (std::ostringstream& stream, const char* format, int n, const char*& fmt, const T& arg)
    {
$1  assert (&stream);
$   assert (fmt);

$   if (_TX_ARGUMENT_FAILED (&arg)) return;

    if (fmt[0] == '%') {$}
    else {$ TX_ERROR ("\"%%$\" required to print an argument in ...\"%s\" while printing %s argument %d in \"%s\"", fmt, txTypename (arg), n, format); }

$   fmt++;

$   char                    oldFill  = stream.fill (' ');
$   std::ios_base::fmtflags oldFlags = stream.flags();

$   for (;;) switch (*fmt)
        {
        case '-': $ stream << std::left;     fmt++; break;
        case '+': $ stream << std::showpos;  fmt++; break;
        case ' ': $ stream.fill (' ');       fmt++; break;
        case '#': $ stream << std::showbase; fmt++; break;
        case '0': $ stream.fill ('0');       fmt++; break;

        default:  $ goto end;
        }
    end:

$   int width = (*fmt != '*')?                  (int) strtoul (fmt, const_cast <char**> (&fmt), 10) : (fmt++, 0);
$   int prec  = (*fmt == '.')? (*++fmt != '*')? (int) strtoul (fmt, const_cast <char**> (&fmt), 10) : (fmt++, 0) : 0;

    if (width) {$ stream << std::setw (width);        }
    if (prec)  {$ stream << std::setprecision (prec); }

$   fmt += strspn (fmt, "hljztL");

$   switch (*fmt)
        {
        case '$':
        case '?': $                                              break;

        case 'd':
        case 'i':
        case 'u': $ stream << std::dec;                          break;

        case 'o': $ stream << std::oct;                          break;

        case 'x': $ stream << std::hex;                          break;
        case 'X': $ stream << std::hex        << std::uppercase; break;

        case 'f': $ stream << std::fixed;                        break;
        case 'F': $ stream << std::fixed      << std::uppercase; break;

        case 'e': $ stream << std::scientific;                   break;
        case 'E': $ stream << std::scientific << std::uppercase; break;

        case 'g': $                                              break;
        case 'G': $ stream                    << std::uppercase; break;

        case 'a': $                                              break;
        case 'A': $ stream                    << std::uppercase; break;

        case 'c':
        case 's':
        case 'p': $                                              break;

        default:  $ TX_ERROR ("Invalid format '%.1s' at \"%s\" while printing %s argument %d in \"%s\"", fmt, fmt, txTypename (arg), n, format); break;
        }

$   fmt++;

    if (&arg) {$ stream << arg;      }
    else      {$ stream << "(null)"; }

$   stream.fill  (oldFill);
$   stream.flags (oldFlags);
    }

//-----------------------------------------------------------------------------------------------------------------

inline void _txPrintV (std::ostringstream& stream, const char* format, int n, const char*& fmt, int* arg)
    {
$1  assert (fmt);

    if (_TX_ARGUMENT_FAILED (arg)) return;

    if (fmt[0] == '%' && fmt[1] == 'n') {$}
    else {$ TX_ERROR ("\"%%n\" required to store print length in int* argument %d in \"%s\"", n, format); }

$   *arg = (int) stream.str().length();

$   fmt += 2;
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T> inline const T&    _txPrintfNormalizeArg (const T&           arg) { if (_TX_ARGUMENT_FAILED (&arg)) {;}          return arg;         }
                      inline const char* _txPrintfNormalizeArg (const std::string& arg) { if (_TX_ARGUMENT_FAILED (&arg)) return NULL; return arg.c_str(); }

//-----------------------------------------------------------------------------------------------------------------

template <typename... ArgsT>
inline int txPrintf (std::ostringstream& stream, const char* format, ArgsT... args)
    {
$1  if (_TX_ARGUMENT_FAILED (&stream)) return 0;
$   if (_TX_ARGUMENT_FAILED (&format)) return 0;

$   const char* fmt = format;
$   _txPrintF (stream, format, 2, fmt, _txPrintfNormalizeArg (args)...);

$   return (int) stream.str().length();
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename... ArgsT>
inline int txPrintf (char buffer[], size_t size, const char* format, ArgsT... args)
    {
$1  if (_TX_ARGUMENT_FAILED (&buffer)) return 0;
$   if (_TX_ARGUMENT_FAILED (&format)) return 0;

$   if (size > 0) size--;
$   buffer[size] = 0;

$   if (!size) return 0;

$   std::ostringstream stream;
$   stream.rdbuf() -> pubsetbuf (buffer, size);

$   txPrintf (stream, format, args...);

$   return (int) stream.str().length();
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename... ArgsT>
inline std::string txFormat (const char* format, ArgsT... args)
    {
$1  if (_TX_ARGUMENT_FAILED (&format)) return "";

$   std::ostringstream stream;

$   txPrintf (stream, format, args...);

$   return stream.str();
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename... ArgsT>
inline int txPrintf (const char* format, ArgsT... args)
    {
$1  if (_TX_ARGUMENT_FAILED (&format)) return 0;

$   return printf ("%s", txFormat (format, args...) .c_str());
    }

#endif

//-----------------------------------------------------------------------------------------------------------------

       int _txPrintfCheck (const char* format, ...) tx_printfy (1);
inline int _txPrintfCheck (const char*,        ...) { return 0; }

//}
//=================================================================================================================

//=================================================================================================================
//{          txDialog methods implementation
//           ���������� ������� ������ txDialog
//
//           See [1] http://msdn.microsoft.com/ru-ru/library/windows/desktop/ms645389%28v=vs.85%29.aspx
//               [2] http://blogs.msdn.microsoft.com/oldnewthing/20050429-00/?p=35743
//               [3] http://blogs.msdn.microsoft.com/oldnewthing/20040623-00/?p=38753
//=================================================================================================================

#ifndef TX_COMPILED

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
$1  assert (layout);

$   return ::std::swap (layout_, layout), layout;
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t txDialog::dialogBox (WORD resourceID)
    {
$1  const char* resName = (char*)(uintptr_t) resourceID;

$   if (!FindResource (NULL, resName, RT_DIALOG)) return TX_DEBUG_ERROR ("�� ������ ������ ������� %d", resourceID), 0;

$   return DialogBoxParam (NULL, resName, NULL, (DLGPROC) DialogProc_, (LPARAM) this);
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t txDialog::dialogBox (const txDialog::Layout* layout /*= NULL*/, size_t bufsize /*= 0*/)
    {
$1  if (!layout)  layout = layout_;
$   if (!layout)  return TX_DEBUG_ERROR ("�� ���������� ������������ ������ �������"), 0;

$   if (!bufsize) bufsize = 1024;

$   DLGTEMPLATE* tmpl = (DLGTEMPLATE*) GlobalAlloc (GPTR, bufsize);
$   if (!tmpl) return TX_DEBUG_ERROR ("GlobalAlloc(): ��� ������ ��� ������� �������"), 0;

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
                                   item->id, (const char*)(uintptr_t) item->wndclass, item->caption);
        }

$   tmpl->cdit = (unsigned short) (i-1);

$   intptr_t res = DialogBoxIndirectParam (NULL, tmpl, NULL, (DLGPROC) DialogProc_, (LPARAM) this);

$   GlobalFree (tmpl);

$   return res;
    }

//-----------------------------------------------------------------------------------------------------------------

int txDialog::dialogProc (HWND wnd, UINT msg, WPARAM wParam, LPARAM)
    {
$1  switch (msg)
        {
        case WM_INITDIALOG: $ SetForegroundWindow (wnd);
                            $ break;

        case WM_COMMAND:    $ switch (LOWORD (wParam))
            {
            case IDOK:
            case IDCANCEL:  $ SetForegroundWindow (txWindow()? txWindow() : Win32::GetConsoleWindow());
                            $ EndDialog (wnd, (uintptr_t) this);
                            $ break;

            default:        $ break;
            }
                            $ break;
        default:            $ break;
        }

$   return FALSE;
    }

//-----------------------------------------------------------------------------------------------------------------

intptr_t CALLBACK txDialog::DialogProc_ (HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
$1  static txDialog* this__ = NULL;
$   if (msg == WM_INITDIALOG) this__ = (txDialog*) lParam;
$   if (!this__) return FALSE;

$   return this__-> dialogProc (wnd, msg, wParam, lParam);
    }

//-----------------------------------------------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Create (void* globalMem, size_t bufsize, DWORD style, DWORD exStyle,
                              WORD controls, short x, short y, short cx, short cy,
                              const char caption[], const char font[], WORD fontsize, const char menu[])
    {
$1  if (_TX_ARGUMENT_FAILED (globalMem)) return NULL;

$   WORD* pw = (WORD*) globalMem;

$   DLGTEMPLATE* tmpl = ((DLGTEMPLATE*&) pw)++;

$   tmpl->style = style;
$   tmpl->dwExtendedStyle = exStyle;
$   tmpl->cdit  = controls;
$   tmpl->x     = x;
$   tmpl->y     = y;
$   tmpl->cx    = cx;
$   tmpl->cy    = cy;

$   if (menu > (const char*) 0xFFFF)
        {
$       pw  += MultiByteToWideChar  (_TX_CODEPAGE, 0, (menu?    menu    : ""), -1, (wchar_t*) pw,
                                    (int) (bufsize? bufsize - ((char*) pw - (char*) globalMem) : 0xFFFF));
        }
    else
        {
$       *pw++ = (WORD)(uintptr_t) (menu? 0xFFFF : 0);
$       *pw++ = (WORD)(uintptr_t)  menu;
        }

$   if (caption)
        {
$       pw  += MultiByteToWideChar  (_TX_CODEPAGE, 0, (caption? caption : ""), -1, (wchar_t*) pw,
                                    (int) (bufsize? bufsize - ((char*) pw - (char*) globalMem) : 0xFFFF));
        }

$   if (style & DS_SETFONT)
        {
$       *pw++ = fontsize;
$        pw  += MultiByteToWideChar (_TX_CODEPAGE, 0, (font?    font    : ""), -1, (wchar_t*) pw,
                                    (int) (bufsize? bufsize - ((char*) pw - (char*) globalMem) : 0xFFFF));
        }

$   return pw;
    }

//-----------------------------------------------------------------------------------------------------------------

void* _tx_DLGTEMPLATE_Add (void* dlgTemplatePtr, size_t bufsize, DWORD style, DWORD exStyle,
                           short x, short y, short cx, short cy,
                           WORD id, const char wclass[], const char caption[])
    {
$1  if (_TX_ARGUMENT_FAILED (dlgTemplatePtr)) return NULL;

$   WORD* pw = (LPWORD) dlgTemplatePtr;  // Force align at word boundary
$   ((ULONG&) pw)  += 3;
$   ((ULONG&) pw) >>= 2;
$   ((ULONG&) pw) <<= 2;

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
$       pw  += MultiByteToWideChar (_TX_CODEPAGE, 0, const_cast <char*> (wclass), -1, (wchar_t*) pw,
                                   (int) (bufsize? bufsize - ((char*) pw - (char*) dlgTemplatePtr) : 0xFFFF));
        }
    else
        {
$       *pw++ = 0;
        }

$   if (caption)
         {
$        pw  += MultiByteToWideChar (_TX_CODEPAGE, 0, caption, -1, (wchar_t*) pw,
                                    (int) (bufsize? bufsize - ((char*) pw - (char*) dlgTemplatePtr) : 0xFFFF));
         }
    else
        {
$       *pw++ = 0;
        }

$   *pw++ = 0;

$   return pw;
    }

#endif // TX_COMPILED

//}
//=================================================================================================================

//=================================================================================================================
//{          Cleaning up the utility macros
//           ������� ��������� ��������
//=================================================================================================================

#undef       $
#undef       $0
#undef       $1
#undef       $2
#undef       $3
#undef       $4
#undef       $5
#undef       $6
#undef       $7
#undef       $8
#undef       $9
#undef       $$

//}
//=================================================================================================================

//! @endcond }

//=================================================================================================================
//{          Experimental Debugging macros
//! @name    ����������������� ���������� �������
//=================================================================================================================

//{----------------------------------------------------------------------------------------------------------------
//! @ingroup Misc
//! @brief   ���������� ������ ���������� �� ����� ���������� ��������� ��� ������� ����
//!          �� ����� ��� ����������.
//!
//!          ������ ��������� ���� <i>������� �����</i> �������!
//!
//! @warning ��� ������� ����� ���������� � ������� �������. @strike ����� ��� ��������� ������. @endstrike
//!
//! @title   ����������: @table
//!          @tr <tt> $ (var,  [name])        </tt> @td ������ ����� � �������� ���������� ��� ��������� @c var.                               <i>[name] @d �������������� ����������.</i>
//!          @tr <tt> $_(var,  [name])        </tt> @td �� ��, ��� � <tt>$(var),</tt> �� ��� ����� ������.                                     <i>[name] @d �������������� ����������.</i>
//!          @tbr
//!          @tr <tt> $x (var, [name])        </tt> @td ������ ����� � �������� ���������� ��� ��������� @c var � 16-������ ������� ���������. <i>[name] @d �������������� ����������.</i>
//!          @tr <tt> $x_(var, [name])        </tt> @td �� ��, ��� � <tt>$x(var),</tt> �� ��� ����� ������.                                    <i>[name] @d �������������� ����������.</i>
//!          @tbr
//!          @tr <tt> $v (var, cond, [name])  </tt> @td �� ��, ��� � <tt>$(var),</tt> �� ��������� ������ � ����������� �� ������� @c cond.    <i>[name] @d �������������� ����������.</i>
//!          @tr <tt> $v_(var, cond, [name])  </tt> @td �� ��, ��� � <tt>$v(var),</tt> �� ��� ����� ������.                                    <i>[name] @d �������������� ����������.</i>
//!          @tbr
//!          @tr <tt> $do(code)               </tt> @td ������ ������ ����, ����� ���������� ����� ����.
//!          @tr <tt> $DO(code)               </tt> @td �� ��, ��� � <tt>$do(code),</tt> �� � ������ (������� ����� �������).
//!          @tr <tt> $Do(code)               </tt> @td �� ��, ��� � <tt>$do(code),</tt> �� � ������ (txMessageBox).
//!          @tbr
//!          @tr <tt> $$$ (expr)              </tt> @td ������ ���������, ��� ����������, ������ � ������� ��������. @n
//!                                                     ���� ��������� �������� �������� "�������", �� ������ � ������,
//!                                                     ���������� �������� expr ��� ����� ����� ������.
//!          @tr <tt> $$$_(expr)              </tt> @td �� ��, ��� � <tt>$$$(expr),</tt>  �� ������ ������ ���� ��� ����� ������.
//!          @tbr
//!          @tr <tt> $$$$ (code)             </tt> @td �� ��, ��� � <tt>$$$(expr),</tt>  �� ��� ���������� ��� ������ ���� (��� �������� ��������).
//!          @tr <tt> $$$$_(code)             </tt> @td �� ��, ��� � <tt>$$$$(expr),</tt> �� ������ ������ ���� ��� ����� ������.
//!          @tbr
//!          @tr <tt> $$                      </tt> @td ������ �������������� � ����.
//!          @tr <tt> $$_                     </tt> @td ������ �������������� � ���� (������ ��� ������� � ����� ������).
//!          @tr <tt> $meow (msg)             </tt> @td �� ��, ��� � $$, �� ��� � �������� ��������� @c msg.
//!          @tbr
//!          @tr <tt> $test (cond)            </tt> @td ������ ���������� ����� ��������� ������ � ����������� �� ������� @c cond.
//!          @tr <tt> $unittest (code, expected) </tt> @td ������ ���������� <b>����-�����</b> @c code � ��������� ����������� @c expected.
//!          @tbr
//!          @tr <tt> $n                      </tt> @td ������� ������ (������ @c '\\n').
//!          @tr <tt> $nn                     </tt> @td ������  ������ (������ @c '\\n\\n').
//!          @tr <tt> $t                      </tt> @td ���������      (������ @c '\\t').
//!          @endtable
//!
//! @title   ��������� ��������� �������� �������: @table
//!          @tr @c $d @td ������-�����     ���� @td @td @c $D @td �����-�����     ����
//!          @tr @c $b @td ������-�����     ���� @td @td @c $B @td �����-�����     ����
//!          @tr @c $g @td ������-�������   ���� @td @td @c $G @td �����-�������   ����
//!          @tr @c $c @td ������-��������� ���� @td @td @c $C @td �����-��������� ����
//!          @tr @c $r @td ������-�������   ���� @td @td @c $R @td �����-�������   ����
//!          @tr @c $m @td ������-��������� ���� @td @td @c $M @td �����-��������� ����
//!          @tr @c $y @td ������           ���� @td @td @c $Y @td �����-������    ����
//!          @tr @c $h @td �����            ���� @td @td @c $H @td ����������      ����
//! @endtable
//! @title @table
//!          @tr @c $o @td OK               @td ������-�������   �� �������        @td
//!          @td @c $O @td OK bold          @td ������           �� �������        @td
//!          @tr @c $i @td Information      @td ������-�����     �� �����          @td
//!          @td @c $I @td Information bold @td ������           �� �����          @td
//!          @tr @c $w @td Warning          @td ������-��������� �� ���������      @td
//!          @td @c $W @td Warning bold     @td ������           �� ���������      @td
//!          @tr @c $e @td Error            @td ������-�������   �� �������        @td
//!          @td @c $E @td Error bold       @td ������           �� �������        @td
//!          @tr @c $f @td Fatal            @td ������           �� ������-������� @td
//!          @td @c $F @td Fatal bold       @td ���������        �� ������-������� @td
//!          @tr @c $l @td Location         @td ������           �� �����-�����    @td
//!          @td @c $L @td Location bold    @td ������-�����     �� �����-�����    @td
//! @endtable
//! @title @table
//!          @tr @c $T (cond) @td ������-������� @b ��� ������-�������, � ����������� �� ������� @c cond.
//! @endtable
//! @title @table
//!          @tr @c $s  @td ��������� ��������. ��� ������ �� @c { ����� ���� @c } �������� �����������������.
//!          @tr @c $s* @td ��������� �������� � ���������� ���� (�������� ��������� ����� �����, ��. ����).
//!                         ������: @c $sg - ��������� �������� � ���������� ������-������� ����.
//! @endtable
//!
//! <b>��� ����� ����-����?</b> � ��� ���: <a href=http://google.com/search?q=����-������������+C%2B%2B>
//! www.google.com/search?q=����-������������+C++.</a> <b>��� ����� ������ ������ ����.</b>
//!
//! @see     assert(), asserted, __TX_FILELINE__, __TX_FUNCTION__, TX_ERROR
//!
//! @note    ���� ��� ������ (�������������������) �������� �������. ��������� � �������� ����� TXLib.h,
//!          ����� __TX_DEBUG_MACROS � ��. ����.
//!
//! @usage @code
//!          $g  // green
//!          int x = 5;
//!          int y = $(x) + 1;
//!          $(  x = $(y) + 2 );
//!
//!          int xx[] = { 10, 20, 30 };
//!          $(xx);
//!
//!          $r  // red
//!          double xy = $( pow (x, y) );
//!
//!          $meow ("Computing hypothenuse...")
//!          double h  = $$$(( $(x) = x*x, y = y*y, sqrt ($(x+y)) ));
//!
//!          $$ $$P;
//!          $$$( txCreateWindow (800, 600) );
//!
//!          $d  // default color
//!          $$$$( if ($(xy) < $(h)) { $sE return $(h); } );  // Save color, print h in error color, restore color
//!
//!          $T (h <  10); $(h);  // Print h again, but in success color (h < 10)...
//!          $T (h <= 10); $(h);  // ...or error color (otherwize)
//!          $n                   // New line
//!
//!          $Do (bool isPositive = (h > 0));
//!          $test (isPositive); $n                          // Print a test result
//!
//!          #ifndef _MSC_VER
//!          bool ok = ( $unittest (strlen ("abc"), 3) );    // Checks in unit-test style, thanks GCC
//!          #endif
//!
//!          $unittest (strlen ("abc"), 3);                  // Checks in unit-test style, Microsoft compatible way.
//!                                                          // No return result from $unittest here, sorry (:
//!          $$ $$p;
//! @endcode
//}----------------------------------------------------------------------------------------------------------------

#ifndef __TX_DEBUG_MACROS
#define __TX_DEBUG_MACROS  ("������ ���������� $-��������")

//! @cond INTERNAL
//-----------------------------------------------------------------------------------------------------------------

#define $H            txSetConsoleAttr (FOREGROUND_BLACK        | BACKGROUND_BLACK);
#define $B            txSetConsoleAttr (FOREGROUND_BLUE         | BACKGROUND_BLACK);
#define $G            txSetConsoleAttr (FOREGROUND_GREEN        | BACKGROUND_BLACK);
#define $C            txSetConsoleAttr (FOREGROUND_CYAN         | BACKGROUND_BLACK);
#define $R            txSetConsoleAttr (FOREGROUND_RED          | BACKGROUND_BLACK);
#define $M            txSetConsoleAttr (FOREGROUND_MAGENTA      | BACKGROUND_BLACK);
#define $Y            txSetConsoleAttr (FOREGROUND_DARKYELLOW   | BACKGROUND_BLACK);
#define $d            txSetConsoleAttr (FOREGROUND_LIGHTGRAY    | BACKGROUND_BLACK);
#define $D            txSetConsoleAttr (FOREGROUND_DARKGRAY     | BACKGROUND_BLACK);
#define $b            txSetConsoleAttr (FOREGROUND_LIGHTBLUE    | BACKGROUND_BLACK);
#define $g            txSetConsoleAttr (FOREGROUND_LIGHTGREEN   | BACKGROUND_BLACK);
#define $c            txSetConsoleAttr (FOREGROUND_LIGHTCYAN    | BACKGROUND_BLACK);
#define $r            txSetConsoleAttr (FOREGROUND_LIGHTRED     | BACKGROUND_BLACK);
#define $m            txSetConsoleAttr (FOREGROUND_LIGHTMAGENTA | BACKGROUND_BLACK);
#define $y            txSetConsoleAttr (FOREGROUND_YELLOW       | BACKGROUND_BLACK);
#define $h            txSetConsoleAttr (FOREGROUND_WHITE        | BACKGROUND_BLACK);

#define $i            txSetConsoleAttr (FOREGROUND_LIGHTCYAN    | BACKGROUND_BLUE);
#define $I            txSetConsoleAttr (FOREGROUND_YELLOW       | BACKGROUND_BLUE);
#define $o            txSetConsoleAttr (FOREGROUND_LIGHTGREEN   | BACKGROUND_GREEN);
#define $O            txSetConsoleAttr (FOREGROUND_YELLOW       | BACKGROUND_GREEN);
#define $e            txSetConsoleAttr (FOREGROUND_WHITE        | BACKGROUND_RED);
#define $E            txSetConsoleAttr (FOREGROUND_YELLOW       | BACKGROUND_RED);
#define $w            txSetConsoleAttr (FOREGROUND_LIGHTMAGENTA | BACKGROUND_MAGENTA);
#define $W            txSetConsoleAttr (FOREGROUND_YELLOW       | BACKGROUND_MAGENTA);
#define $f            txSetConsoleAttr (FOREGROUND_BLACK        | BACKGROUND_LIGHTRED);
#define $F            txSetConsoleAttr (FOREGROUND_MAGENTA      | BACKGROUND_LIGHTRED);
#define $l            txSetConsoleAttr (FOREGROUND_BLACK        | BACKGROUND_DARKGRAY);
#define $L            txSetConsoleAttr (FOREGROUND_LIGHTGRAY    | BACKGROUND_DARKGRAY);

#define $T( cond )    txSetConsoleAttr ((cond)? FOREGROUND_LIGHTGREEN : FOREGROUND_LIGHTRED );

#define $s            _txSaveConsoleAttr TX_JOIN (__txSavedConsoleAttrs, __LINE__);

#define $sH           $s $H
#define $sB           $s $B
#define $sG           $s $G
#define $sC           $s $C
#define $sR           $s $R
#define $sM           $s $M
#define $sY           $s $Y
#define $sd           $s $d
#define $sD           $s $D
#define $sb           $s $b
#define $sg           $s $g
#define $sc           $s $c
#define $sr           $s $r
#define $sm           $s $m
#define $sy           $s $y
#define $sh           $s $h

#define $si           $s $i
#define $sI           $s $I
#define $so           $s $o
#define $sO           $s $O
#define $se           $s $e
#define $sE           $s $E
#define $sw           $s $w
#define $sW           $s $W
#define $sf           $s $f
#define $sF           $s $F
#define $sl           $s $l
#define $sL           $s $L

#define $sT( cond )   $s $T (cond)

#define $test(cond)   { if (!!(cond)) { $o std::cerr << "[PASSED] " __TX_FILELINE__ ": " #cond; } \
                        else          { $e std::cerr << "[FAILED] " __TX_FILELINE__ ": " #cond; } $d; }

#define $status(cond) $test (cond)

#define $unittest( code, expected )                                                                                             \
    {                                                                                                                           \
    const _tx_decltype (code)     & _result   = (code);       /* Should use auto, but g++ 4.7.2 default std is < 2011 */        \
    const _tx_decltype (expected) & _expected = (expected);                                                                     \
                                                                                                                                \
    if (_result == _expected)                                                                                                   \
        { $so std::cerr << "[PASSED] " __TX_FILELINE__ ": " #code; }                                                            \
    else                                                                                                                        \
        { $se std::cerr << "[FAILED] " __TX_FILELINE__ ": " #code " == (" << _result << "), should be (" << _expected << ")"; } \
                                                                                                                                \
    $n;                                                                                                                         \
    (_result == _expected);                                                                                                     \
    }

//=================================================================================================================

#ifdef _GCC_VER

#define $V(  var, ...)       (               _txDumpVar ((var),  "[",             __VA_ARGS__ "]\n") )
#define $V_( var, ...)       (               _txDumpVar ((var),  "[",             __VA_ARGS__ "] " ) )
#define $V__(var, ...)       (               _txDumpVar ((var),  "[",             __VA_ARGS__ "]"  ) )

#define $(   var, ...)       (               _txDumpVar ((var),  "[" #var " = ",  __VA_ARGS__ "]\n") )
#define $_(  var, ...)       (               _txDumpVar ((var),  "[" #var " = ",  __VA_ARGS__ "] " ) )
#define $__( var, ...)       (               _txDumpVar ((var),  "[" #var " = ",  __VA_ARGS__ "]"  ) )

#define $x(  var, ...)       (               _txDumpVar ((var),  "[" #var " = ",  __VA_ARGS__ "]\n", ::std::ios_base::showbase | ::std::ios_base::hex) )
#define $x_( var, ...)       (               _txDumpVar ((var),  "[" #var " = ",  __VA_ARGS__ "] ",  ::std::ios_base::showbase | ::std::ios_base::hex) )

#define $v(  var, cond, ...) { { $st (cond); _txDumpVar ((var),  "[" #var " = ",  __VA_ARGS__ "]" ); } $n; }
#define $v_( var, cond, ...) {   $st (cond); _txDumpVar ((var),  "[" #var " = ",  __VA_ARGS__ "]" );       }

#else

#define $V(  var, ...)       (               _txDumpVar ((var),  "[",            #__VA_ARGS__ "]\n") )
#define $V_( var, ...)       (               _txDumpVar ((var),  "[",            #__VA_ARGS__ "] " ) )
#define $V__(var, ...)       (               _txDumpVar ((var),  "[",            #__VA_ARGS__ "]"  ) )

#define $(   var, ...)       (               _txDumpVar ((var),  "[" #var " = ", #__VA_ARGS__ "]\n") )
#define $_(  var, ...)       (               _txDumpVar ((var),  "[" #var " = ", #__VA_ARGS__ "] " ) )
#define $__( var, ...)       (               _txDumpVar ((var),  "[" #var " = ", #__VA_ARGS__ "]"  ) )

#define $x(  var, ...)       (               _txDumpVar ((var),  "[" #var " = ", #__VA_ARGS__ "]\n", ::std::ios_base::showbase | ::std::ios_base::hex) )
#define $x_( var, ...)       (               _txDumpVar ((var),  "[" #var " = ", #__VA_ARGS__ "] ",  ::std::ios_base::showbase | ::std::ios_base::hex) )

#define $v(  var, cond, ...) { { $st (cond); _txDumpVar ((var),  "[" #var " = ", #__VA_ARGS__ "]" ); } $n; }
#define $v_( var, cond, ...) {   $st (cond); _txDumpVar ((var),  "[" #var " = ", #__VA_ARGS__ "]" );       }

#endif

#define $$                   { txOutputDebugPrintf ("\f\n"); { $sC txOutputDebugPrintf ("\f" "[%s (%d) %s]", __FILE__, __LINE__, __TX_FUNCTION__);                                   } txOutputDebugPrintf ("\f\n"); }
#define $$_                  { txOutputDebugPrintf ("\f\n"); { $sC txOutputDebugPrintf ("\f" "[" "(%d) %s]",           __LINE__, __func__);                                          } txOutputDebugPrintf ("\f\n"); }
#define $meow(...)           { txOutputDebugPrintf ("\f\n"); { $sc txOutputDebugPrintf ("\f" "[%s (%d) %s]", __FILE__, __LINE__, __func__); txOutputDebugPrintf ("\f " __VA_ARGS__); } txOutputDebugPrintf ("\f\n"); }
#define $meow_               { txOutputDebugPrintf ("\f\n"); { $sc txOutputDebugPrintf ("\f" "[%s (%d) %s]", __FILE__, __LINE__, __func__); txOutputDebugPrintf ("\f");              } txOutputDebugPrintf ("\f\n"); }

#define $$$(   ... )         ( ::std::cerr << "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]\n", _txDumpVar ((__VA_ARGS__),"\n[" __TX_FILELINE__ ": " #__VA_ARGS__ ": ", ", DONE]\n\n") )
#define $$$_(  ... )         ( ::std::cerr << "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]\n", _txDumpVar ((__VA_ARGS__),  "[" __TX_FILELINE__ ": " #__VA_ARGS__ ": ", ", DONE]\n\n") )

#define $$$$(  ... )         { ::std::cerr << "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]\n"; _txDumpVarSuffix         ("\n[" __TX_FILELINE__ ": " #__VA_ARGS__        " DONE]\n\n"); { __VA_ARGS__; } }
#define $$$$_( ... )         { ::std::cerr << "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]\n"; _txDumpVarSuffix         (  "[" __TX_FILELINE__ ": " #__VA_ARGS__        " DONE]\n\n"); { __VA_ARGS__; } }
#define $do(   ... )           ::std::cerr << "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]\n";                                                                                           __VA_ARGS__
#define $DO(   ... )           ::std::cerr << "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]...\n"; $p;                                                                                    __VA_ARGS__
#define $Do(   ... )           ::std::cerr << "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]...\n";                                                                                        \
                               txMessageBox ( "\n[" __TX_FILELINE__ ": " #__VA_ARGS__ "]...\n", __TX_FUNCTION__);                                                                      __VA_ARGS__

#define $n                   { ::std::cerr << "\n";   }
#define $nn                  { ::std::cerr << "\n\n"; }
#define $t                   { ::std::cerr << "\t";   }

//-----------------------------------------------------------------------------------------------------------------

// This will never be documented, he-he. Read the source, Luke.

#if defined (_DEBUG)
    #define $debug       if (1)
    #define $printf      if (1)
    #define $PRINTF      if (1)
#else
    #define $debug       if (0)
    #define $printf      if (0)
    #define $PRINTF      if (0)
#endif

#define $$d              $debug
#define $$w              $$$$
#define $$s              __TX_FILELINE__
#define $$b              DebugBreak()
#define $$p              { if (txMessageBox (__TX_FILELINE__ "\n\n" "[������] - ����������� ���������,\n" "[������] - ���������", \
                                                              __TX_FUNCTION__, MB_ICONINFORMATION | MB_RETRYCANCEL) == IDCANCEL) ::exit (2); }
#define $$P              (     txMessageBox (__TX_FILELINE__, __TX_FUNCTION__, MB_ICONINFORMATION | MB_YESNOCANCEL) )
#define $ppp             { { $sy; fprintf (stderr, "[%s ""%s: ""������� ����� ������� ��� �����������]", __TX_FILELINE__, __TX_FUNCTION__); } $P; { $sy; fprintf (stderr, "...\n"); } }
#define $pp              { { $sy; fprintf (stderr, "[%04d %s: ""������� ����� ������� ��� �����������]", __LINE__,        __TX_FUNCTION__); } $P; { $sy; fprintf (stderr, "...\n"); } }
#define $p               { { $sy; fprintf (stderr, "[%s ""%s(): ������� ����� ������� ��� �����������]", __TX_FILELINE__, __func__);        } $P; { $sy; fprintf (stderr, "...\n"); } }
#define $ppp_            { { $sy; fprintf (stderr, "[%s ""%s]",                                          __TX_FILELINE__, __TX_FUNCTION__); } $P; { $sy; fprintf (stderr, "...\n"); } }
#define $pp_             { { $sy; fprintf (stderr, "[%04d %s]",                                          __LINE__,        __TX_FUNCTION__); } $P; { $sy; fprintf (stderr, "...\n"); } }
#define $p_              { { $sy; fprintf (stderr, "[%s ""%s()]",                                        __TX_FILELINE__, __func__);        } $P; { $sy; fprintf (stderr, "...\n"); } }
#define $P               ( ((int(*)()) (_getch)) () )  // Avoid "return value not used"

//-----------------------------------------------------------------------------------------------------------------

struct _txSaveConsoleAttr
    {
    unsigned attr_;

             _txSaveConsoleAttr()           : attr_ (txGetConsoleAttr ()) {}
    explicit _txSaveConsoleAttr (WORD attr) : attr_ (txGetConsoleAttr ()) { txSetConsoleAttr (attr);  }
            ~_txSaveConsoleAttr()                                         { txSetConsoleAttr (attr_); }
    };

//-----------------------------------------------------------------------------------------------------------------

struct _txDumpVarSuffix
    {
    typedef _txDumpVarSuffix this_t;

    const char* suffix_;

    explicit _txDumpVarSuffix (const char suffix[] = "") : suffix_ (suffix) { assert (suffix); }
            ~_txDumpVarSuffix()                          { ::std::cerr << suffix_; }

            _txDumpVarSuffix (const this_t&) _tx_delete;
    this_t& operator =       (const this_t&) _tx_delete;
    };

//-----------------------------------------------------------------------------------------------------------------

#define ARGS__  const char* prefix, const char* suffix, std::ios_base::fmtflags flags,                             int deep
#define ARGS_   const char* prefix, const char* suffix, std::ios_base::fmtflags flags = std::ios_base::fmtflags(), int deep = 0
#define VALS_   prefix, suffix, flags, deep

template <typename T, typename StreamT> const T&    _txDumpVal (const T&  value, StreamT& stream, ARGS_);

//-----------------------------------------------------------------------------------------------------------------

template <typename T> inline const T&               _txDumpVar (const T&            value,          ARGS_)      { _txDumpVal (value, std:: cerr, VALS_); return value; }
template <typename T> inline       T&               _txDumpVar (      T&            value,          ARGS_)      { _txDumpVal (value, std:: cerr, VALS_); return value; }

template <int N>      inline const char           (&_txDumpVar (const char        (&value) [N],     ARGS_)) [N] { _txDumpVal (value, std:: cerr, VALS_); return value; }
template <int N>      inline       char           (&_txDumpVar (      char        (&value) [N],     ARGS_)) [N] { _txDumpVal (value, std:: cerr, VALS_); return value; }

template <int N>      inline const wchar_t        (&_txDumpVar (const wchar_t     (&value) [N],     ARGS_)) [N] { _txDumpVal (value, std::wcerr, VALS_); return value; }
template <int N>      inline       wchar_t        (&_txDumpVar (      wchar_t     (&value) [N],     ARGS_)) [N] { _txDumpVal (value, std::wcerr, VALS_); return value; }

                      inline const wchar_t&         _txDumpVar (const wchar_t&      value,          ARGS_)      { _txDumpVal (value, std::wcerr, VALS_); return value; }
                      inline       wchar_t&         _txDumpVar (      wchar_t&      value,          ARGS_)      { _txDumpVal (value, std::wcerr, VALS_); return value; }

                      inline const wchar_t*&        _txDumpVar (const wchar_t*&     value,          ARGS_)      { _txDumpVal (value, std::wcerr, VALS_); return value; }
                      inline       wchar_t*&        _txDumpVar (      wchar_t*&     value,          ARGS_)      { _txDumpVal (value, std::wcerr, VALS_); return value; }

                      inline const std::wstring&    _txDumpVar (const std::wstring& value,          ARGS_)      { _txDumpVal (value, std::wcerr, VALS_); return value; }
                      inline       std::wstring&    _txDumpVar (      std::wstring& value,          ARGS_)      { _txDumpVal (value, std::wcerr, VALS_); return value; }

//-----------------------------------------------------------------------------------------------------------------

template <typename T, typename StreamT> inline void _txDumpVal (const T&            value, StreamT& stream)     {                     stream <<         value;                                    }
template             <typename StreamT> inline void _txDumpVal (const char          value, StreamT& stream)     {                     stream <<  "'" << value <<  "'";                            }
template             <typename StreamT> inline void _txDumpVal (const wchar_t       value, StreamT& stream)     {                     stream << L"'" << value << L"'";                            }
template             <typename StreamT> inline void _txDumpVal (const char*         value, StreamT& stream)     { if (value)          stream <<  '"' << value <<  '"'; else stream <<  "(null)";  }
template             <typename StreamT> inline void _txDumpVal (const wchar_t*      value, StreamT& stream)     { if (value)          stream << L'"' << value << L'"'; else stream << L"(null)";  }
template             <typename StreamT> inline void _txDumpVal (const std::string&  value, StreamT& stream)     { if (value.length()) stream <<  '"' << value <<  '"'; else stream <<  "(empty)"; }
template             <typename StreamT> inline void _txDumpVal (const std::wstring& value, StreamT& stream)     { if (value.length()) stream << L'"' << value << L'"'; else stream << L"(empty)"; }

//-----------------------------------------------------------------------------------------------------------------

template <typename T, typename StreamT>
inline const T& _txDumpVal (const T& value, StreamT& stream, ARGS__)
    {
    if (_TX_ARGUMENT_FAILED (&value))  return value;
    if (_TX_ARGUMENT_FAILED (&stream)) return value;
    if (_TX_ARGUMENT_FAILED ( prefix)) return value;
    if (_TX_ARGUMENT_FAILED ( suffix)) return value;

    $sc;
    if (!deep) stream << prefix;

    std::ios_base::fmtflags old = stream.flags ((flags)? flags : stream.flags());

    if (!_txIsBadReadPtr (&value))
        {
        _txDumpVal (value, stream);
        }
    else
        {
        $sE; stream << "<�������� ����� " << &value << ">";
        }

    stream.flags (old);

    if (!deep) stream << ((*suffix == ']')? "" : ": ") << suffix;

    return value;
    }

//-----------------------------------------------------------------------------------------------------------------

template <typename T, int N>
inline T (&_txDumpVar (T (&value) [N], ARGS_)) [N]
    {
    if (_TX_ARGUMENT_FAILED (&value))  return value;
    if (_TX_ARGUMENT_FAILED ( prefix)) return value;
    if (_TX_ARGUMENT_FAILED ( suffix)) return value;

    std::ostream& stream = std::cerr;

    $sc; if (!deep) std::cerr << prefix;
    $C;  std::cerr << ((deep)? " {" : "{");

    if (!_txIsBadReadPtr (value))
        {
        for (int i = 0; ; i++)
            {
            { $sC; stream << "[" << i << "]="; }

            _txDumpVar (value[i], prefix, suffix, flags, deep+1);

            if (i >= N-1) break;

            stream << ", ";
            }
        }
    else
        {
        $sE; stream << "<�������� ����� " << &value << ">";
        }

    $C; std::cerr << "}";
    $c; if (!deep) std::cerr << ((*suffix == ']')? "" : ": ") << suffix;

    return value;
    }

#undef ARGS__
#undef ARGS_
#undef VALS_

//=================================================================================================================

inline std::ostream& operator << (std::ostream& stream, const POINT& point)
    {
    if (_TX_ARGUMENT_FAILED (&stream)) return stream;
    if (_TX_ARGUMENT_FAILED (&point))  return stream;

    if (&point) stream << "{ x: " << point.x << ", y: " << point.y << " }";
    else        stream << "(null)";

    return stream;
    }

inline std::ostream& operator << (std::ostream& stream, const SIZE& size)
    {
    if (_TX_ARGUMENT_FAILED (&stream)) return stream;
    if (_TX_ARGUMENT_FAILED (&size))   return stream;

    if (&size) stream << "{ cx: " << size.cx << ", cy: " << size.cy << " }";
    else       stream << "(null)";

    return stream;
    }

inline std::ostream& operator << (std::ostream& stream, const RECT& rect)
    {
    if (_TX_ARGUMENT_FAILED (&stream)) return stream;
    if (_TX_ARGUMENT_FAILED (&rect))   return stream;

    if (&rect) stream << "{ left: "  << rect.left  << ", top: "    << rect.top    <<
                         ", right: " << rect.right << ", bottom: " << rect.bottom << " }";

    else       stream << "(null)";

    return stream;
    }

//-----------------------------------------------------------------------------------------------------------------
//! @endcond

#endif

//}
//=================================================================================================================

//! @cond INTERNAL

//=================================================================================================================
//{          TXAPI calls tracing
//           ����������� ������� TXAPI
//=================================================================================================================

#ifndef   FOR_DOXYGEN_ONLY

#if defined (_MSC_VER)
#undef  _txLocCurSet
#define _txLocCurSet()                 __txLocCurSet (__FILE__, __LINE__, NULL)
#endif

#define txAlphaBlend(...)              ( _txLocCurSet(), txAlphaBlend          (__VA_ARGS__) )
#define txArc(...)                     ( _txLocCurSet(), txArc                 (__VA_ARGS__) )
#define txBegin(...)                   ( _txLocCurSet(), txBegin               (__VA_ARGS__) )
#define txBitBlt(...)                  ( _txLocCurSet(), txBitBlt              (__VA_ARGS__) )
#define txChord(...)                   ( _txLocCurSet(), txChord               (__VA_ARGS__) )
#define txCircle(...)                  ( _txLocCurSet(), txCircle              (__VA_ARGS__) )
#define txClear(...)                   ( _txLocCurSet(), txClear               (__VA_ARGS__) )
#define txClearConsole(...)            ( _txLocCurSet(), txClearConsole        (__VA_ARGS__) )
#define txColor(...)                   ( _txLocCurSet(), txColor               (__VA_ARGS__) )
#define txCreateCompatibleDC(...)      ( _txLocCurSet(), txCreateCompatibleDC  (__VA_ARGS__) )
#define txCreateDIBSection(...)        ( _txLocCurSet(), txCreateDIBSection    (__VA_ARGS__) )
#define txCreateExtraWindow(...)       ( _txLocCurSet(), txCreateExtraWindow   (__VA_ARGS__) )
#define txCreateWindow(...)            ( _txLocCurSet(), txCreateWindow        (__VA_ARGS__) )
#define txDC(...)                      ( _txLocCurSet(), txDC                  (__VA_ARGS__) )
#define txDeleteDC(...)                ( _txLocCurSet(), txDeleteDC            (__VA_ARGS__) )
#define txDemangle(...)                ( _txLocCurSet(), txDemangle            (__VA_ARGS__) )
#define txDestroyWindow(...)           ( _txLocCurSet(), txDestroyWindow       (__VA_ARGS__) )
#define txDisableAutoPause(...)        ( _txLocCurSet(), txDisableAutoPause    (__VA_ARGS__) )
#define txDrawText(...)                ( _txLocCurSet(), txDrawText            (__VA_ARGS__) )
#define txEllipse(...)                 ( _txLocCurSet(), txEllipse             (__VA_ARGS__) )
#define txEnd(...)                     ( _txLocCurSet(), txEnd                 (__VA_ARGS__) )
#define txExtractColor(...)            ( _txLocCurSet(), txExtractColor        (__VA_ARGS__) )
#define txFillColor(...)               ( _txLocCurSet(), txFillColor           (__VA_ARGS__) )
#define txFloodFill(...)               ( _txLocCurSet(), txFloodFill           (__VA_ARGS__) )
#define txFontExist(...)               ( _txLocCurSet(), txFontExist           (__VA_ARGS__) )
#define txFormat(...)                  ( _txLocCurSet(), txFormat              (__VA_ARGS__) )
#define txGetAsyncKeyState(...)        ( _txLocCurSet(), txGetAsyncKeyState    (__VA_ARGS__) )
#define txGetColor(...)                ( _txLocCurSet(), txGetColor            (__VA_ARGS__) )
#define txGetConsoleAttr(...)          ( _txLocCurSet(), txGetConsoleAttr      (__VA_ARGS__) )
#define txGetConsoleCursorPos(...)     ( _txLocCurSet(), txGetConsoleCursorPos (__VA_ARGS__) )
#define txGetConsoleExtent(...)        ( _txLocCurSet(), txGetConsoleExtent    (__VA_ARGS__) )
#define txGetConsoleFontSize(...)      ( _txLocCurSet(), txGetConsoleFontSize  (__VA_ARGS__) )
#define txGetExtent(...)               ( _txLocCurSet(), txGetExtent           (__VA_ARGS__) )
#define txGetExtentX(...)              ( _txLocCurSet(), txGetExtentX          (__VA_ARGS__) )
#define txGetExtentY(...)              ( _txLocCurSet(), txGetExtentY          (__VA_ARGS__) )
#define txGetFillColor(...)            ( _txLocCurSet(), txGetFillColor        (__VA_ARGS__) )
#define txGetFPS(...)                  ( _txLocCurSet(), txGetFPS              (__VA_ARGS__) )
#define txGetModuleFileName(...)       ( _txLocCurSet(), txGetModuleFileName   (__VA_ARGS__) )
#define txGetPixel(...)                ( _txLocCurSet(), txGetPixel            (__VA_ARGS__) )
#define txGetTextExtent(...)           ( _txLocCurSet(), txGetTextExtent       (__VA_ARGS__) )
#define txGetTextExtentX(...)          ( _txLocCurSet(), txGetTextExtentX      (__VA_ARGS__) )
#define txGetTextExtentY(...)          ( _txLocCurSet(), txGetTextExtentY      (__VA_ARGS__) )
#define txHSL2RGB(...)                 ( _txLocCurSet(), txHSL2RGB             (__VA_ARGS__) )
#define txInputBox(...)                ( _txLocCurSet(), txInputBox            (__VA_ARGS__) )
#define txLine(...)                    ( _txLocCurSet(), txLine                (__VA_ARGS__) )
#define txLoadImage(...)               ( _txLocCurSet(), txLoadImage           (__VA_ARGS__) )
#define txLock(...)                    ( _txLocCurSet(), txLock                (__VA_ARGS__) )
#define txMessageBox(...)              ( _txLocCurSet(), txMessageBox          (__VA_ARGS__) )
#define txMouseButtons(...)            ( _txLocCurSet(), txMouseButtons        (__VA_ARGS__) )
#define txMousePos(...)                ( _txLocCurSet(), txMousePos            (__VA_ARGS__) )
#define txMouseX(...)                  ( _txLocCurSet(), txMouseX              (__VA_ARGS__) )
#define txMouseY(...)                  ( _txLocCurSet(), txMouseY              (__VA_ARGS__) )
#define txNotifyIcon(...)              ( _txLocCurSet(), txNotifyIcon          (__VA_ARGS__) )
#define txOK(...)                      ( _txLocCurSet(), txOK                  (__VA_ARGS__) )
#define txOutputDebugPrintf(...)       ( _txLocCurSet(), txOutputDebugPrintf   (__VA_ARGS__) )
#define txPie(...)                     ( _txLocCurSet(), txPie                 (__VA_ARGS__) )
#define txPixel(...)                   ( _txLocCurSet(), txPixel               (__VA_ARGS__) )
#define txPlaySound(...)               ( _txLocCurSet(), txPlaySound           (__VA_ARGS__) )
#define txPlayVideo(...)               ( _txLocCurSet(), txPlayVideo           (__VA_ARGS__) )
#define txPolygon(...)                 ( _txLocCurSet(), txPolygon             (__VA_ARGS__) )
#define txPrintf(...)                  ( _txLocCurSet(), txPrintf              (__VA_ARGS__) )
#define txQueryPerformance(...)        ( _txLocCurSet(), txQueryPerformance    (__VA_ARGS__) )
#define txRectangle(...)               ( _txLocCurSet(), txRectangle           (__VA_ARGS__) )
#define txRedrawWindow(...)            ( _txLocCurSet(), txRedrawWindow        (__VA_ARGS__) )
#define txRegisterClass(...)           ( _txLocCurSet(), txRegisterClass       (__VA_ARGS__) )
#define txRegisterClass(...)           ( _txLocCurSet(), txRegisterClass       (__VA_ARGS__) )
#define txRegQuery(...)                ( _txLocCurSet(), txRegQuery            (__VA_ARGS__) )
#define txReopenStdio(...)             ( _txLocCurSet(), txReopenStdio         (__VA_ARGS__) )
#define txReopenStdio(...)             ( _txLocCurSet(), txReopenStdio         (__VA_ARGS__) )
#define txRGB2HSL(...)                 ( _txLocCurSet(), txRGB2HSL             (__VA_ARGS__) )
#define txSaveImage(...)               ( _txLocCurSet(), txSaveImage           (__VA_ARGS__) )
#define txSelectFont(...)              ( _txLocCurSet(), txSelectFont          (__VA_ARGS__) )
#define txSelectObject(...)            ( _txLocCurSet(), txSelectObject        (__VA_ARGS__) )
#define txSetColor(...)                ( _txLocCurSet(), txSetColor            (__VA_ARGS__) )
#define txSetConsoleAttr(...)          ( _txLocCurSet(), txSetConsoleAttr      (__VA_ARGS__) )
#define txSetConsoleCursorPos(...)     ( _txLocCurSet(), txSetConsoleCursorPos (__VA_ARGS__) )
#define txSetDefaults(...)             ( _txLocCurSet(), txSetDefaults         (__VA_ARGS__) )
#define txSetFillColor(...)            ( _txLocCurSet(), txSetFillColor        (__VA_ARGS__) )
#define txSetLocale(...)               ( _txLocCurSet(), txSetLocale           (__VA_ARGS__) )
#define txSetPixel(...)                ( _txLocCurSet(), txSetPixel            (__VA_ARGS__) )
#define txSetTextAlign(...)            ( _txLocCurSet(), txSetTextAlign        (__VA_ARGS__) )
#define txSetWindowsHook(...)          ( _txLocCurSet(), txSetWindowsHook      (__VA_ARGS__) )
#define txSleep(...)                   ( _txLocCurSet(), txSleep               (__VA_ARGS__) )
#define txSpeak(...)                   ( _txLocCurSet(), txSpeak               (__VA_ARGS__) )
#define txTextCursor(...)              ( _txLocCurSet(), txTextCursor          (__VA_ARGS__) )
#define txTextOut(...)                 ( _txLocCurSet(), txTextOut             (__VA_ARGS__) )
#define txTransparentBlt(...)          ( _txLocCurSet(), txTransparentBlt      (__VA_ARGS__) )
#define txTriangle(...)                ( _txLocCurSet(), txTriangle            (__VA_ARGS__) )
#define txUnlock(...)                  ( _txLocCurSet(), txUnlock              (__VA_ARGS__) )
#define txUpdateWindow(...)            ( _txLocCurSet(), txUpdateWindow        (__VA_ARGS__) )
#define txUseAlpha(...)                ( _txLocCurSet(), txUseAlpha            (__VA_ARGS__) )
#define txVersion(...)                 ( _txLocCurSet(), txVersion             (__VA_ARGS__) )
#define txVersionNumber(...)           ( _txLocCurSet(), txVersionNumber       (__VA_ARGS__) )
#define txWindow(...)                  ( _txLocCurSet(), txWindow              (__VA_ARGS__) )
#define tx_fpreset(...)                ( _txLocCurSet(), tx_fpreset            (__VA_ARGS__) )
#define tx_glGetError(...)             ( _txLocCurSet(), tx_glGetError         (__VA_ARGS__) )
#define _txDump(...)                   ( _txLocCurSet(), _txDump               (__VA_ARGS__) )
#define _txStackBackTrace(...)         ( _txLocCurSet(), _txStackBackTrace     (__VA_ARGS__) )

#endif

//}
//=================================================================================================================

//! @endcond
//}
//=================================================================================================================

//-----------------------------------------------------------------------------------------------------------------
//{          The namespaces
//-----------------------------------------------------------------------------------------------------------------

/*! @cond INTERNAL */

_TX_END_NAMESPACE

/*! @endcond */

using namespace TX;                    // Allow easy usage of TXLib functions

using ::std::cin;                      // Predefined usings to avoid "using namespace std"
using ::std::cout;
using ::std::cerr;
using ::std::string;
using ::std::wcin;
using ::std::wcout;
using ::std::wcerr;
using ::std::wstring;

//}
//-----------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------
//{          Compiler- and platform-specific
//           ��������� � ������������ � ����������
//-----------------------------------------------------------------------------------------------------------------
//! @cond INTERNAL

#if defined (_GCC_VER)

    #pragma GCC optimize               "strict-aliasing"

    #pragma GCC pop_options
    #pragma GCC diagnostic pop

    #endif

#if defined (_CLANG_VER)

    #pragma clang diagnostic pop

    #endif

//-----------------------------------------------------------------------------------------------------------------

#if defined (_MSC_VER)

    #pragma warning (pop)              // Restoring maximum level

    #endif

#if defined (__INTEL_COMPILER)

    #pragma warning (default:  174)    // Remark: expression has no effect
    #pragma warning (default:  304)    // Remark: access control not specified ("public" by default)
    #pragma warning (default:  444)    // Remark: destructor for base class "..." is not virtual
    #pragma warning (default:  522)    // Remark: function redeclared "inline" after being called
    #pragma warning (default: 1684)    // Conversion from pointer to same-sized integral type (potential portability problem)

    #pragma warning (disable:  981)    // Remark: operands are evaluated in unspecified order

    #endif

//! @endcond
//}
//-----------------------------------------------------------------------------------------------------------------

#endif // __TXLIB_H_INCLUDED

//=================================================================================================================
// EOF
//=================================================================================================================
                                                                                                                   
                                                                                                                   
          
















