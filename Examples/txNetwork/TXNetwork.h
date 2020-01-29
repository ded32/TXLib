//{=============================================================================
//  ���������� TXNetwork - TXNetwork.h
//  Copyright (C) Vova Yurovsky, 7 ����� - Source code
//                Vova Yurovsky, 8 ����� - Help
//}=============================================================================

//{================================DOXYGEN======================================
//! @file       TXNetwork.h
//!
//! @mainpage
//! @brief      ���������� ���� ����� ���������� TXNetwork
//!
//! @par        ��������
//!             TXNetwork - ���������� TXLib'a ��� "������ � �����", ����� ����� ������������ �� ����.
//!             ��������� ���������� ����������� �� TXLib'a, �������������, �� ��� ���� � ������� ����,
//!             ��� �������� �� ������������. ���������� ������� �������. :)
//!
//!             � ����� ��������� ��� ��� ���� (e-mail: vova@txlib.ru).
//!
//! @version    0.6.3a
//!
//! @author     Copyright (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>, 7-8 �����
//! @date       2015-2016
//!
//! @par
//!             ���������� ������� ���� ��� (����� C++) TX_SOCKET. �� �� ������������� ����� �� HDC Win32
//!             � TXLib'a. �������� � ��� ���� ������ ����� ������� ����� ������.
//! @par
//!             ����� ���� �������. ������ � ������ � ����� Examples.
//! @par
//!             ��� ��� ���������� ��������� �� ������ ������������, �� ������� ������ ��� (������) ��� ����
//!             � ��� ��������� �� ������: <vova@txlib.ru>.
//!
//! @par        ��� � � ��� ��� ������������?
//!             ���������� TXNetwork ���������� ������ ����������, ������� ���������� ���������� ����������
//!             ����������. ��� ������ TXNetwork @b ����� � ���������� ������� @b ������� ����������
//!             � ����������� @c @b ws2_32. @nn
//!             � Code::Blocks ��������� ������� ���������  "Settings/Compiler". ����� ��������� �������
//!             "Linker Settings", � �������� � ����� ������. ���� ��� ��� ������� @c "ws2_32", �� ��� ������.
//!             ����� ������� ������ "Add", � ������� ��� ��������. ������� "��". ������ TXNetwork
//!             @strike ����� @endstrike ����� � ������ � ����. @nn
//!             ���� � ��������� ������ ����������� ���� ������� ����� @c -l @c ws2_32.
//! @par
//!
//! @warning  - <b>���������� ��������� � ��������� �����-������������. ��� ���� ������� ���������
//!             �� ����� vova@txlib.ru.</b>
//!
//! @warning  - <b>��� ������������� ��������� � TXLib:
//!             ����������� TXNetwork <b>�����</b> TXLib'�� </b>.
//!
//! @warning  - <b>TXNetwork ������� ����������� (\#undef) __STRICT_ANSI__ ��� ������������� � TXLib'��</b>
//!
//! @section    Contents ������� ������� ������
//! @par
//!           - @ref TXSocket "���������� TXNetwork"
//!           - @ref TXNERCO  "���� ������ TXNetwork"
//!
//! @section    SimpleExample ����� ������� ������
//!
//! @par        ����: proto.h
//!             ����� ��������� � ��������� ������� � �������
//! @include   "Examples/Example00/proto.h"
//!
//! @par        ����: server.cpp
//!             �������� ������ �� �������� TXNetwork - ��������� �� ������-��������� :)
//! @include   "Examples/Example00/server.cpp"
//!
//! @par        ����: client.cpp
//!             �������� ������ �� �������� TXNetwork - ��������� �� ������-��������� :)
//! @include   "Examples/Example00/client.cpp"
//!
//! @par
//!          -  @ref Example0      "��������� �������� ����������� �������."
//!
//! @section    OtherExamples       ������ �������:
//!
//! @par
//!          -  @ref Example1      "������ ������"
//!          -  @ref Example2      "������ ������"
//!          -  @ref Example3      "������ ������"
//!          -  @ref Example4      "��������� ������"
//!          -  @ref ExampleYours  "���� ������ ������!"
//!
//! @defgroup   TXSocket            ����� TXNetwork
//! @defgroup   TXNERCO             ���� ������ TXNetwork
//!
//}=============================================================================

#ifndef TXN_H
#define TXN_H

//{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wswitch-enum"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wsign-conversion"
//}

//{ Includes (##-INTERNAL-##)
//! @cond INTERNAL

#ifdef __TXLIB_H_INCLUDED

#error -----------------------------------------------------------------------
#error Do not include TXLib before TXNetwork.
#error -----------------------------------------------------------------------

#endif

#ifndef WINVER

#define WINVER 0x0501

#endif

#ifndef _WIN32_IE

#define _WIN32_IE WINVER

#endif

#if (WINVER < 0x0501)

#error -------------------------------------------------------------------------
#error TXNetwork requires WINVER 0x0501 or above. To define WINVER:
#error #define WINVER MEOW
#error #define MEOW   0x0501
#error -------------------------------------------------------------------------

#endif

#if (_WIN32_IE < 0x0501)

#error -------------------------------------------------------------------------
#error TXNetwork requires _WIN32_IE 0x0501 or above. To define _WIN32_IE:
#error #define _WIN32_IE CAT
#error #define CAT   0x0501
#error -------------------------------------------------------------------------

#endif

#pragma GCC system_header

#undef  __STRICT_ANSI__

#include <ws2tcpip.h>
#include <stdio.h>
#include <assert.h>

//! @endcond
//}

//{ defines, typedefs

//! @ingroup TXSocket
//! @brief   ����������������� IP-����� TXNetwork'a
//!
//! IP-�����, � �������� ��� ���������� ��������� ���������, �������� �� ���� �����.

#define TX_BROADCAST    "255.255.255.255"
#define TX_BROADCAT      TX_BROADCAST       // For compatibility with other cats. ^^ :)

//! @ingroup TXSocket
//! @brief   ����������� ���� TXNetwork'a
//!
//! ����������� ����� �����. ����, ���� �����������, ��� �� ���� ���� ����� ���� ������� ������ ���� �����!

#define TX_STD_PORT     27050

//! @ingroup TXSocket
//! @brief   IP-����� ����������, �� ������ ������� ���������.
//!
//! IP-����� ������ ����������. �� ����� ������ � ����� ������ ������ ����������.

#define TX_LOCALHOST    "127.0.0.1"

//! @ingroup TXNERCO
//! @brief   ����� �� ������.
//!
//! ������������ txnAssert'��.

#define TXN_NOT_CREATED 101

//! @ingroup TXNERCO
//! @brief   ����� � �������.
//!
//! ������������ txnAssert'��.

#define TXN_OK          100

//! @ingroup TXNERCO
//! @brief   ������ ������.
//!
//! ������������ ��������� ������ TX_SOCKET ��� ������/�������� ������.

#define TXN_ERROR       -1

//! @ingroup TXSocket
//! @brief   ���� ������.

enum sock_type
    {
    TX_SERVER   =  1,  //!< ����� �������� ��������, ��������� ������.
    TX_CLIENT   =  2,  //!< ����� �������� ��������.
    TX_BLOCK    =  3,  //!< ����� ��������� ���������� ��������� �� ����� ������/��������.
    TX_NONBLOCK =  4,  //!< ����� �� ��������� ���������� ��������� �� ����� ������/��������.
    TX_NOTYPE   = -1   //!< ���� �� ������ ��� �� ������.
    };
//!

//! @ingroup TXSocket
//! @brief   C���� TXLib'a.
//!
//! ����� - �������� �������, �� ������ �������� �������� ������ � ����� ��� ������ ������������
//! (����� ������������� �������� ������������ � ������������ ������. � TXSocket - ������� ������
//! ��� @strike ��������� @endstrike ������������ TXNetwrok.

//}

// The Classes
//{

//! @cond INTERNAL

class txSmartSocket_
{
SOCKET sock;
unsigned int num_of_ref;

txSmartSocket_ (const txSmartSocket_& var) = delete;
txSmartSocket_& operator= (txSmartSocket_& what) = delete;

public:
    txSmartSocket_ ():
    sock(INVALID_SOCKET),
    num_of_ref(0)
    {}

    txSmartSocket_ (SOCKET var):
    sock (var),
    num_of_ref (1)
    {}

    txSmartSocket_ (txSmartSocket_&& var):
    sock(var.sock),
    num_of_ref(var.num_of_ref)
    {
    var.sock = NULL;
    var.num_of_ref = 0;
    }

    ~txSmartSocket_()
    {
    if (sock);
        closesocket(sock);
    }

SOCKET& operator*();

txSmartSocket_* Create();
txSmartSocket_* Delete();
};

//! @endcond

class TX_SOCKET
    {
    //! @cond INTERNAL

    bool      _broadcats;  // ^_^
    bool      _TCP;
    bool      _init;
    sock_type _type;

    txSmartSocket_* _sock;
    sockaddr_in _sock_addr;

    txSmartSocket_* _client_sock_for_serv;
    sockaddr_in _client_addr;

    sock_type _type_;

    bool _txInitAsServer (const char*,    u_short port, sock_type type, bool useTCP, const unsigned OueueSize);
    bool _txInitAsClient (const char* IP, u_short port, sock_type type, bool useTCP, const unsigned);

    public:

    TX_SOCKET():
        _broadcats(),
        _TCP (true),
        _init (false),
        _type (TX_NOTYPE),
        _sock(),
        _sock_addr(),
        _client_sock_for_serv(),
        _client_addr(),
        _type_ (TX_BLOCK)
        {}

    TX_SOCKET (const TX_SOCKET& that):
        _broadcats (that._broadcats),
        _TCP (that._TCP),
        _init (that._init),
        _type (that._type),
        _sock (_init? that._sock -> Create() : NULL),
        _sock_addr (that._sock_addr),
        _client_sock_for_serv (that._client_sock_for_serv? that._client_sock_for_serv -> Create() : NULL),
        _client_addr (that._client_addr),
        _type_ (that._type_)
        {}

    TX_SOCKET (sock_type type, const char* IP, int port, sock_type blocking, bool useTCP, const unsigned OueueSize):
        _broadcats(),
        _TCP (useTCP),
        _init (false),
        _type (type),
        _sock (0),
        _sock_addr(),
        _client_sock_for_serv(),
        _client_addr(),
        _type_ (blocking)
        {
        if (IP == NULL)
            {
            if (type == TX_SERVER)
                _broadcats = false;
            else
                return;
            }
        else
            {
            assert (IP);
            _broadcats = ! (strcmp (IP, TX_BROADCAST));          // TX_BROADCAT :)
            }

        switch (_type)
            {
            case TX_CLIENT:   if (! (this->*(_broadcats? &TX_SOCKET :: _txInitAsServer : &TX_SOCKET :: _txInitAsClient))
                                    (IP, (u_short) port, _type_, useTCP, OueueSize)) return;
                              break;

            case TX_SERVER:   if (! (this->*(_broadcats? &TX_SOCKET :: _txInitAsClient : &TX_SOCKET :: _txInitAsServer))
                                    (IP, (u_short) port, _type_, useTCP, OueueSize)) return;
                              break;

            case TX_BLOCK:
            case TX_NONBLOCK: return;

            case TX_NOTYPE:   break;

            default:          break;
            }

        _init = true;
        }

    ~TX_SOCKET()
        {
        if (_sock) _sock -> Delete();
        if (_client_sock_for_serv) _client_sock_for_serv -> Delete();
        }

        friend int txSendTo   (TX_SOCKET& to, const void* buf, int size_buf);
        friend int txRecvFrom (TX_SOCKET& to, void* buf, int size_buf);
        friend int txnAssert  (TX_SOCKET& asr);
        friend int txChangeSockType   (TX_SOCKET& to, sock_type blocking);
        friend SOCKET* txGetWinSocket (TX_SOCKET& what, bool main = true);
    //! @endcond
    };

//}

// prototypes
//{
    /** @ingroup TXSocket
     *  @brief   ������ ����� TXNetwork.
     *
     *  @param   type      ��� ������: ������ (TX_CLIENT) ��� ������ (TX_SERVER).
     *  @param   IP        IP-����� ����������, � ������� ����� ������ �����.
     *                     ���� ��� ������ @p type - TX_SERVER, �� ���� �������� ����� ���� ������ �������.
     *  @param   port      ���� �����������, �� ������� ����� "������" �����.
     *  @param   blocking  ��� ������ (����������� ��� �������������).
     *  @param   useTCP    ���� false, �� ������������ �������� UDP. ����� TCP.
     *  @param   OueueSize @strike ������ ����� @endstrike ������ ������� �������������� �������� ��� listen. Use Google, Luck
     *
     *  @return  ����� TXNetwork'a.
     *
     *  @par     ������
     *  @code
     *           txCreateSocket (TX_CLIENT, "192.168.0.1", 107);   // ������������ �� telnet'�
     *  @endcode
     *  @code
     *           txCreateSocket (TX_SERVER, "",          27051);   // ��������� ������ ����� ����. �-��!
     *  @endcode
     */

    TX_SOCKET txCreateSocket (sock_type type, const char* IP = NULL, int port = TX_STD_PORT,
                              sock_type blocking = TX_BLOCK, bool useTCP = true, const unsigned OueueSize = 0x10);

    //! @ingroup TXSocket
    //! @brief   ������� ��� �������� ������ ����� �����
    //!
    //! @brief   C���� TXLib'a.
    //!
    //! @param   to        �����, ����� ������� ����� �������� ������.
    //! @param   buf       �����, ������� ����� �������.
    //! @param   size_buf  ������ ������.
    //!
    //! @return  ��� ������. ��������� ��. MSDN.
    //! @par     ������ 1
    //! @code
    //!          TX_SOCEKT game_server = txCreateSocket (...);    // ������� �����
    //!          ...
    //!
    //!          int x = 0, y = 0;
    //!          ...
    //!
    //!          char coordinates[200] = "";                      // ������� ������ ��� ����������
    //!          sprintf (coordinates, "x = %d, y = %d", x, y);   // �������� �������� ���������� � ������
    //!
    //!          txSendTo (game_server, coordinates, 200);        // �������� ���������� ��� �����
    //! @endcode
    //!
    //! @par     ������ 2
    //! @code
    //!          struct Point { int x, y };                       // ��� ��������� �����, ������� ���������
    //!          ...                                              // ��� �������� ���������
    //!
    //!          TX_SOCEKT game_server = txCreateSocket (...);    // ������� �����
    //!          ...
    //!
    //!          Point p = { 100, 200 };                          // ������� ����� � ������������ x = 100, y = 200
    //!
    //!          txSendTo (game_server, &p, sizeof (p));          // �������� ������ ��� ���������
    //! @endcode

    int txSendTo (TX_SOCKET& to, const void* buf, int size_buf);

    //! @ingroup TXSocket
    //! @brief   ������� ��� ������ ������ ����� �����
    //!
    //! @brief   C���� TXLib'a.
    //!
    //! @param   to        �����, ����� � �������� ����� ������� ������.
    //! @param   buf       �����, ������� � ����� ������� ������.
    //! @param   size_buf  ������ ������.
    //!
    //! @return  ��� ������. ��������� ��. MSDN.
    //! @par     ������ 1
    //! @code
    //!          TX_SOCEKT game_server = txCreateSocket (...);      // ������� �����
    //!          ...
    //!
    //!          int x = 0, y = 0;
    //!          ...
    //!
    //!          char coordinates[200] = "";                        // ������� ������ ��� ����������
    //!
    //!          txRecvFrom (game_server, coordinates, 200);        // ��������� ����������
    //!          sscanf (coordinates, " x = %d , y = %d", &x, &y);  // ��������� ���������� �� ���������� ������
    //!                                                             // (����� �� ������ ��������!).
    //! @endcode
    //!
    //! @par     ������ 2
    //! @code
    //!          struct Point { int x, y };                       // ��� ��������� �����, ������� ���������
    //!          ...                                              // ��� �������� ���������
    //!
    //!          TX_SOCEKT game_client = txCreateSocket (...);    // ������� �����
    //!          ...
    //!
    //!          Point p = {};                                    // ������� ���������� ��� ������ ���������
    //!          ...
    //!
    //!          txRecvFrom (game_server, &p, sizeof (p));        // ��������� ������
    //!
    //!          DrawGameObject (p.x, p.y);                       // ���������� ������
    //! @endcode

    int txRecvFrom (TX_SOCKET& to, void* buf, int size_buf);

    //! @ingroup TXSocket
    //! @brief   ������� ��� �������� ������
    //!
    //! @brief   C���� TXLib'a.
    //!
    //! @param   asr  �����, ������� ����� ���������.
    //!
    //! @return  ��� ������.

    int txnAssert (TX_SOCKET& asr);

    //! @ingroup TXSocket
    //! @brief   ������� ��� ��������� ���� (���������� - �� ����������) ������.
    //!
    //! @brief   C���� TXLib'a.
    //!
    //! @param   to        �����, ��� �������� ����� ��������.
    //! @param   blocking  ����� ��� ���������� ������.
    //!
    //! @return  ������� ������.

    int txChangeSockType (TX_SOCKET& to, sock_type blocking);

    //! @ingroup TXSocket
    //! @brief   �������, ������� ���������� ����� winsock'�.
    //!
    //! @brief   C���� TXLib'a.
    //!
    //! @param   what  ����� TXLib'a, ����� �������� ����� �������.
    //! @param   main  ����� ������ TXLib'a, ������ ����� �������.
    //!
    //! @return  ��������� �� ����� winsock'a.

    SOCKET* txGetWinSocket (TX_SOCKET& what, bool main/* = true*/);

//}

// definitions (##--INTERANL--##)
//{
//! @cond INTERNAL

// txSmartSocket_
//{

SOCKET& txSmartSocket_ :: operator*()
{
return sock;
}

txSmartSocket_* txSmartSocket_ :: Create()
{
num_of_ref++;

return this;
}

txSmartSocket_* txSmartSocket_ :: Delete()
{
if (num_of_ref == 0 && sock != INVALID_SOCKET)
    delete this;
else
    num_of_ref--;

return this;
}

//}

// TX_SOCKET
//{

bool TX_SOCKET :: _txInitAsServer (const char*, u_short port, sock_type blocking, bool useTCP, const unsigned OueueSize)
    {
    addrinfo hints    = {};
    hints.ai_family   = AF_INET;
    hints.ai_socktype = (useTCP? SOCK_STREAM : SOCK_DGRAM);
    hints.ai_flags    = AI_PASSIVE;

    addrinfo *servinfo = NULL;

    int _port_ = port;

    char str[6] = "";

    sprintf (str, "%d", _port_);

    int err = getaddrinfo (NULL, str, &hints, &servinfo);
    if (err == -1) return false;

    _sock = NULL;
    for (addrinfo* p = servinfo; p; p = p->ai_next)
        {
        _sock = new txSmartSocket_ (socket (p->ai_family, p->ai_socktype, p->ai_protocol));

        if (_sock == NULL)
            {
            return false;
            }

        if ( (int) **_sock == -1)
            {
            delete _sock;
            continue;
            }

        if (bind (**_sock, p->ai_addr, int (p->ai_addrlen)) == -1)
            {
            delete _sock;
            continue;
            }

        break;
        }

    if (_sock == NULL)
        {
        return false;
        }

    if (!**_sock)
        {
        delete _sock;
        return false;
        }

    freeaddrinfo (servinfo);

    if (useTCP)
        {
        if (listen (**_sock, OueueSize)) return false;

        int client_addr_size = sizeof (_client_addr);

        _client_sock_for_serv = new txSmartSocket_(accept (**_sock, (sockaddr* ) &_client_addr, &client_addr_size));

        if (_client_sock_for_serv == NULL)

        if (**_client_sock_for_serv == 0)
            {
            delete _client_sock_for_serv;
            return false;
            }
        }

    if (blocking == TX_NONBLOCK)
        {
        u_long nonblocking = 1;
        if (ioctlsocket (**_client_sock_for_serv, FIONBIO, &nonblocking) == SOCKET_ERROR)
            {
            delete _client_sock_for_serv;
            return false;
            }
        }

    return true;
    }

bool TX_SOCKET :: _txInitAsClient (const char* IP, u_short port, sock_type blocking, bool useTCP, const unsigned)
    {
    hostent* he = gethostbyname (IP);

    _sock = new txSmartSocket_ (useTCP? socket (AF_INET, SOCK_STREAM, IPPROTO_IP) :
                                        socket (AF_INET, SOCK_DGRAM, _broadcats? 0 : IPPROTO_UDP));
    if (_sock == NULL)
        return false;

    if (**_sock == INVALID_SOCKET)
        {
        delete _sock;

        return false;
        }

    char broadcast = _broadcats;
    if (_broadcats) if (setsockopt (**_sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof (broadcast)) == -1)
        return false;

    _sock_addr = {};

    _sock_addr.sin_family = AF_INET;
    _sock_addr.sin_port   = htons (port);
    _sock_addr.sin_addr   = * (in_addr*) he->h_addr;

    if (useTCP)
        if (connect (**_sock, (sockaddr* ) &_sock_addr, sizeof (_sock_addr)) != 0)
        {
        delete _sock;
        return false;
        }

    if (blocking == TX_NONBLOCK)
        {
        u_long nonblocking = 1;
        if (ioctlsocket (**_sock, FIONBIO, &nonblocking) == SOCKET_ERROR)
            {
            delete _sock;
            return false;
            }
        }

    return true;
    }

//}

int txSendTo (TX_SOCKET& to, const void* buf, int size_buf)
    {
    int answ = 0;

    if (to._broadcats)
        {
        answ = sendto (**(to._sock), (const char*) buf, size_buf, 0, (sockaddr *) &to._sock_addr, sizeof (to._sock_addr));
        return answ;
        }

    else if (to._TCP)
        {
        switch (to._type)
            {
            case TX_SERVER:   answ = send (**(to._client_sock_for_serv), (const char*) buf, size_buf, 0); break;
            case TX_CLIENT:   answ = send (**(to._sock),                 (const char*) buf, size_buf, 0); break;

            case TX_BLOCK:
            case TX_NONBLOCK: return TXN_ERROR;

            case TX_NOTYPE:   return 0;

            default:          return 0;
            }
        }

    else
        answ = sendto (**(to._sock), (const char*) buf, size_buf, 0, (sockaddr*) &to._sock_addr, sizeof (to._sock_addr));

    return answ;
    }

int txRecvFrom (TX_SOCKET& to, void* buf, int size_buf)
    {
    int answ = 0;

    if (to._broadcats)
        {
        int SIZE_OF_STRUCTURE_FOR_XXX_WINDOWS = sizeof (to._sock_addr);
        answ = recvfrom (**(to._sock), (char*) buf, size_buf, 0, (sockaddr*) &to._sock_addr, &SIZE_OF_STRUCTURE_FOR_XXX_WINDOWS);
        }

    else if (to._TCP)
        {
        switch (to._type)
            {
            case TX_SERVER:   answ = recv (**(to._client_sock_for_serv), (char*) buf, size_buf, 0); break;
            case TX_CLIENT:   answ = recv (**(to._sock),                 (char*) buf, size_buf, 0); break;

            case TX_BLOCK:
            case TX_NONBLOCK: return TXN_ERROR;

            case TX_NOTYPE:   return 0;

            default:          return 0;
            }
        }
    else
        {
        int SIZE_OF_STRUCTURE_FOR_XXX_WINDOWS = sizeof (to._sock_addr);
        answ = recvfrom (**(to._sock), (char*) buf, size_buf, 0, (sockaddr*) &to._sock_addr, &SIZE_OF_STRUCTURE_FOR_XXX_WINDOWS);
        }

    return answ;
    }

TX_SOCKET txCreateSocket (sock_type type, const char* IP/* = NULL*/,
                          int port /* = TX_STD_PORT*/, sock_type blocking /* = TX_BLOCK*/, bool useTCP /* = true*/, const unsigned OueueSize/* = 0x10*/)
    {
    return TX_SOCKET (type, IP, port, blocking, useTCP, OueueSize);
    }

int txnAssert (TX_SOCKET& asr)
    {
    return (asr._init)? TXN_OK : TXN_NOT_CREATED;
    }

int txChangeSockType (TX_SOCKET& to, sock_type blocking)
    {
    u_long mode = 0;

    switch (blocking)
        {
        case TX_BLOCK:    mode = 0; break;
        case TX_NONBLOCK: mode = 1; break;

        default:          return false;
        };

    if (ioctlsocket (*txGetWinSocket (to), FIONBIO, &mode) == SOCKET_ERROR) return false;

    to._type_ = blocking;

    return true;
    }

SOCKET* txGetWinSocket (TX_SOCKET& what, bool main/* = true*/)
    {
    SOCKET* ret = NULL;

    switch (what._type)
        {
        case TX_CLIENT: ret = &**(what._sock);                                          break;
        case TX_SERVER: ret = main? &**(what._sock) : &**(what._client_sock_for_serv);  break;

        default:        ret = &**(what._sock);                                          break;
        }

    return ret;
    }

//! @endcond
//}

// Dark side (Yes, we have cookies) (##--INTERANL--##)
//{
//! @cond INTERNAL

int  _txInitTX_NETWORK();
void _txDestTX_NETWORK();

WSADATA main_wsa_data = {};
int int_for_init = _txInitTX_NETWORK();

int _txInitTX_NETWORK()
    {
    WSAStartup (0x0202, &main_wsa_data);
    atexit (_txDestTX_NETWORK);

    return 0;
    }

void _txDestTX_NETWORK()
    {
    WSACleanup();
    }

#if !defined (__MODULE)

    #define __MODULE "TXNetwork appilication using small TXLib.\n"                   // �� ��� �� �����. ������ :)

#endif

#if defined (__MODULE) || defined (__VERSION) || defined (__DESCRIPTION) || defined (__AUTHOR)

    #ifndef __MODULE
    #define __MODULE       "TXNetwork appilication using small TXLib." "\n" \
                           "#define __MODULE to set the name.\n"
    #endif

    #ifndef __VERSION
    #define __VERSION      "sqrt (-1)" "\n" \
                           "#define __VERSION to set the string value.\n"
    #endif

    #ifndef __DESCRIPTION
    #define __DESCRIPTION  "��������� ������� ����������, ������������ ������� TXNetwork � ��������� TXLib" "\n" \
                           "#define __DESCRIPTION to override project role.\n"
    #endif

    #ifndef __AUTHOR
    #define __AUTHOR       "_RedMan_, 2015" "\n" \
                           "#define __AUTHOR to override this name."
    #endif

#endif

// OMG!!! You found this!!! +------\
//                          +-----||
//                                ||
//                                ||
//                                \/
//             .-----------------------------.
//            /  _   _   _      *  __  __   /|
//           /  / \ / \ / \ |_/ | |_  (_   / |
//          /   \_  \_/ \_/ | \ | |__ ,_/ /  |
//         :.____________________________/   /
//         |  .--.   .--.   .--.   .--.  |  /
//         | (    ) (    ) (    ) (    ) | /
//         |  '--'   '--'   '--'   '--'  |/
//         '-----------------------------'
//

//! @endcond

//}

#pragma GCC diagnostic pop

#endif
