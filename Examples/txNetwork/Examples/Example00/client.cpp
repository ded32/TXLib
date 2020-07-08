//!===========================================================================
//! @file       Examples/Example00/client.cpp
//!
//! @brief      [TXNetwork] Пример, который пересылает строку, вводимую пользователем.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             Пример простого протокола для пересылки строки.
//!
//!             Сервер запускается первым.
//!             Если клиент запускается не на том же компьютере, что и сервер, то
//!             нужно записать IP адрес сервера в строке SERVER_IP.
//!
//!             Copyright: (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>
//!===========================================================================
// client.cpp

#include "proto.h"

#define SERVER_IP "localhost" //IP адрес писать здесь.

int main()
{
txCreateWindow (1024, 768);

printf ("Searching for server...\n");
TX_SOCKET client = txCreateSocket (TX_CLIENT, SERVER_IP);

char str[Message_size] = "";

txRecvFrom (client, str, Message_size);
printf ("in: %s\nout: ", str);

scanf ("%s", str);
txSendTo (client, str, Message_size);

return 0;
}
