//{=============================================================================
//  Библиотека TXNetwork - TXNetwork.h
//  Copyright (C) Vova Yurovsky, 7 класс - Source code
//                Vova Yurovsky, 8 класс - Help
//}=============================================================================

//{================================DOXYGEN======================================
//! @file       TXNetwork.h
//!
//! @mainpage
//! @brief      Библиотека сети тупых художников TXNetwork
//!
//! @par        Описание
//!             TXNetwork - Расширение TXLib'a для "работы с сетью", связи между компьютерами по сети.
//!             Философия библиотеки наследуется от TXLib'a, следовательно, не все есть в готовом виде,
//!             что хотелось бы использовать. Оставшееся делайте ручками. :)
//!
//!             А также сообщайте мне обо всем (e-mail: vova@txlib.ru).
//!
//! @version    0.6.3a
//!
//! @author     Copyright (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>, 7-8 класс
//! @date       2015-2016
//!
//! @par
//!             Библиотека создает свой тип (класс C++) TX_SOCKET. Он по использованию похож на HDC Win32
//!             и TXLib'a. Работать с ним надо только через функции этого класса.
//! @par
//!             Также есть примеры. Смотри в файлах в папке Examples.
//! @par
//!             Так как библиотека находится на стадии тестирования, то просьба писать мне (автору) обо всех
//!             с ней проблемах по адресу: <vova@txlib.ru>.
//!
//! @par        Как и с чем это использовать?
//!             Библиотека TXNetwork использует другие библиотеки, которые используют технологию раздельной
//!             компиляции. Для работы TXNetwork @b нужно в настройках линкера @b указать компоновку
//!             с библиотекой @c @b ws2_32. @nn
//!             В Code::Blocks настройки линкера находятся  "Settings/Compiler". Далее выбираете вкладку
//!             "Linker Settings", и смотрите в левую панель. Если там уже указано @c "ws2_32", то все хорошо.
//!             Иначе нажмите кнопку "Add", и введите это название. Нажмите "ОК". Теперь TXNetwork
//!             @strike котов @endstrike готов к работе с вами. @nn
//!             Либо в командной строке компилятора надо указать опцию @c -l @c ws2_32.
//! @par
//!
//! @warning  - <b>Библиотека находится в состоянии альфа-тестирования. Обо всех ошибках сообщайте
//!             на почту vova@txlib.ru.</b>
//!
//! @warning  - <b>При использовании совместно с TXLib:
//!             Подключайте TXNetwork <b>ПЕРЕД</b> TXLib'ом </b>.
//!
//! @warning  - <b>TXNetwork удаляет определение (\#undef) __STRICT_ANSI__ для совместимости с TXLib'ом</b>
//!
//! @section    Contents Разделы системы помощи
//! @par
//!           - @ref TXSocket "Компоненты TXNetwork"
//!           - @ref TXNERCO  "Коды ошибок TXNetwork"
//!
//! @section    SimpleExample Очень простой пример
//!
//! @par        Файл: proto.h
//!             общие структуры и константы клиента и сервера
//! @include   "Examples/Example00/proto.h"
//!
//! @par        Файл: server.cpp
//!             Смотрите помощь по функциям TXNetwork - нажимайте на светло-синенькое :)
//! @include   "Examples/Example00/server.cpp"
//!
//! @par        Файл: client.cpp
//!             Смотрите помощь по функциям TXNetwork - нажимайте на светло-синенькое :)
//! @include   "Examples/Example00/client.cpp"
//!
//! @par
//!          -  @ref Example0      "Подробное описание простейшего примера."
//!
//! @section    OtherExamples       Другие примеры:
//!
//! @par
//!          -  @ref Example1      "Первый пример"
//!          -  @ref Example2      "Второй пример"
//!          -  @ref Example3      "Третий пример"
//!          -  @ref Example4      "Четвертый пример"
//!          -  @ref ExampleYours  "Твой личный пример!"
//!
//! @defgroup   TXSocket            Сокет TXNetwork
//! @defgroup   TXNERCO             Коды ошибок TXNetwork
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
//! @brief   Широковещательный IP-адрес TXNetwork'a
//!
//! IP-адрес, с которого все компьютеры принимают сообщения, посланые на этот адрес.

#define TX_BROADCAST    "255.255.255.255"
#define TX_BROADCAT      TX_BROADCAST       // For compatibility with other cats. ^^ :)

//! @ingroup TXSocket
//! @brief   Стандартный порт TXNetwork'a
//!
//! Стандартный номер порта. Учти, юный программист, что на один порт может быть повешен только один сокет!

#define TX_STD_PORT     27050

//! @ingroup TXSocket
//! @brief   IP-адрес компьютера, на которм запущен компьютер.
//!
//! IP-адрес твоего компьютера. Он верен только с точки зрения самого компьютера.

#define TX_LOCALHOST    "127.0.0.1"

//! @ingroup TXNERCO
//! @brief   Сокет не создан.
//!
//! Возвращается txnAssert'ом.

#define TXN_NOT_CREATED 101

//! @ingroup TXNERCO
//! @brief   Сокет в порядке.
//!
//! Возвращается txnAssert'ом.

#define TXN_OK          100

//! @ingroup TXNERCO
//! @brief   Ошибка сокета.
//!
//! Возвращается функциями класса TX_SOCKET при приеме/передаче данных.

#define TXN_ERROR       -1

//! @ingroup TXSocket
//! @brief   Типы сокета.

enum sock_type
    {
    TX_SERVER   =  1,  //!< Сокет является сервером, создается первым.
    TX_CLIENT   =  2,  //!< Сокет является клиентом.
    TX_BLOCK    =  3,  //!< Сокет блокирует выполнение программы во время приема/передачи.
    TX_NONBLOCK =  4,  //!< Сокет не блокирует выполнение программы во время приема/передачи.
    TX_NOTYPE   = -1   //!< Если не знаешь или не уверен.
    };
//!

//! @ingroup TXSocket
//! @brief   Cокет TXLib'a.
//!
//! Сокет - Основное понятие, на основе которого строится работа с сетью для любого программиста
//! (кроме разработчиков сетевого оборудования и операционных систем. А TXSocket - частный случай
//! для @strike школьника @endstrike пользователя TXNetwrok.

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
     *  @brief   Создаёт сокет TXNetwork.
     *
     *  @param   type      Тип сокета: клиент (TX_CLIENT) или сервер (TX_SERVER).
     *  @param   IP        IP-адрес компьютера, с которым будет создан сокет.
     *                     Если тип сокета @p type - TX_SERVER, то этот параметр может быть пустой строкой.
     *  @param   port      Порт компьютеров, на котором будет "висеть" сокет.
     *  @param   blocking  Тип сокета (блокирующий или неблокирующий).
     *  @param   useTCP    Если false, то используется протокол UDP. Иначе TCP.
     *  @param   OueueSize @strike Черная магия @endstrike Размер очереди обрабатываемых клиентов для listen. Use Google, Luck
     *
     *  @return  Сокет TXNetwork'a.
     *
     *  @par     Пример
     *  @code
     *           txCreateSocket (TX_CLIENT, "192.168.0.1", 107);   // Подключаемся по telnet'у
     *  @endcode
     *  @code
     *           txCreateSocket (TX_SERVER, "",          27051);   // Поднимаем сервер своей игры. Ю-ху!
     *  @endcode
     */

    TX_SOCKET txCreateSocket (sock_type type, const char* IP = NULL, int port = TX_STD_PORT,
                              sock_type blocking = TX_BLOCK, bool useTCP = true, const unsigned OueueSize = 0x10);

    //! @ingroup TXSocket
    //! @brief   Функция для отправки данных через сокет
    //!
    //! @brief   Cокет TXLib'a.
    //!
    //! @param   to        Сокет, через который нужно передать данные.
    //! @param   buf       Буфер, который будет передан.
    //! @param   size_buf  Размер буфера.
    //!
    //! @return  Код ошибки. Подробнее см. MSDN.
    //! @par     Пример 1
    //! @code
    //!          TX_SOCEKT game_server = txCreateSocket (...);    // Создаем сокет
    //!          ...
    //!
    //!          int x = 0, y = 0;
    //!          ...
    //!
    //!          char coordinates[200] = "";                      // Создаем строку для параметров
    //!          sprintf (coordinates, "x = %d, y = %d", x, y);   // Печатаем значения параметров в строку
    //!
    //!          txSendTo (game_server, coordinates, 200);        // Передаем координаты как текст
    //! @endcode
    //!
    //! @par     Пример 2
    //! @code
    //!          struct Point { int x, y };                       // Тут поступаем умнее, создаем структуру
    //!          ...                                              // для хранения координат
    //!
    //!          TX_SOCEKT game_server = txCreateSocket (...);    // Создаем сокет
    //!          ...
    //!
    //!          Point p = { 100, 200 };                          // Создаем точку с координатами x = 100, y = 200
    //!
    //!          txSendTo (game_server, &p, sizeof (p));          // Передаем данные как структуру
    //! @endcode

    int txSendTo (TX_SOCKET& to, const void* buf, int size_buf);

    //! @ingroup TXSocket
    //! @brief   Функция для приема данных через сокет
    //!
    //! @brief   Cокет TXLib'a.
    //!
    //! @param   to        Сокет, через с которого нужно принять данные.
    //! @param   buf       Буфер, который в будет записан массив.
    //! @param   size_buf  Размер буфера.
    //!
    //! @return  Код ошибки. Подробнее см. MSDN.
    //! @par     Пример 1
    //! @code
    //!          TX_SOCEKT game_server = txCreateSocket (...);      // Создаем сокет
    //!          ...
    //!
    //!          int x = 0, y = 0;
    //!          ...
    //!
    //!          char coordinates[200] = "";                        // Создаем строку для параметров
    //!
    //!          txRecvFrom (game_server, coordinates, 200);        // Принимаем координаты
    //!          sscanf (coordinates, " x = %d , y = %d", &x, &y);  // Извлекаем координаты из полученной строки
    //!                                                             // (следи за каждым пробелом!).
    //! @endcode
    //!
    //! @par     Пример 2
    //! @code
    //!          struct Point { int x, y };                       // Тут поступаем умнее, создаем структуру
    //!          ...                                              // для хранения координат
    //!
    //!          TX_SOCEKT game_client = txCreateSocket (...);    // Создаем сокет
    //!          ...
    //!
    //!          Point p = {};                                    // Создаем переменную для приема координат
    //!          ...
    //!
    //!          txRecvFrom (game_server, &p, sizeof (p));        // Принимаем данные
    //!
    //!          DrawGameObject (p.x, p.y);                       // Используем данные
    //! @endcode

    int txRecvFrom (TX_SOCKET& to, void* buf, int size_buf);

    //! @ingroup TXSocket
    //! @brief   Функция для проверки сокета
    //!
    //! @brief   Cокет TXLib'a.
    //!
    //! @param   asr  Сокет, который нужно проверить.
    //!
    //! @return  Код ошибки.

    int txnAssert (TX_SOCKET& asr);

    //! @ingroup TXSocket
    //! @brief   Функция для изменения типа (синхронный - не синхронный) сокета.
    //!
    //! @brief   Cокет TXLib'a.
    //!
    //! @param   to        Сокет, тип которого нужно изменить.
    //! @param   blocking  Новый тип блокировки сокета.
    //!
    //! @return  Наличие ошибки.

    int txChangeSockType (TX_SOCKET& to, sock_type blocking);

    //! @ingroup TXSocket
    //! @brief   Функция, которая возвращает сокет winsock'а.
    //!
    //! @brief   Cокет TXLib'a.
    //!
    //! @param   what  Сокет TXLib'a, сокет которого нужно вернуть.
    //! @param   main  Часть сокета TXLib'a, короую нужно вернуть.
    //!
    //! @return  Указатель на сокет winsock'a.

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

    #define __MODULE "TXNetwork appilication using small TXLib.\n"                   // Ты это не видел. Забудь :)

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
    #define __DESCRIPTION  "Маленькое мышиное приложение, использующее великий TXNetwork и маленький TXLib" "\n" \
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
