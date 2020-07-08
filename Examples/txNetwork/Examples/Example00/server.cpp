//!===========================================================================
//! @file       Examples/Example00/server.cpp
//!
//! @brief      [TXNetwork] ������, ������� ���������� ������, �������� �������������.
//!
//!             ���������� ���� ����� ���������� (TXNetwork).
//!
//!             ������ �������� ��������� ��� ��������� ������.
//!
//!             ������ ����������� ������.
//!
//!             Copyright: (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>
//!===========================================================================
// server.cpp

#include "proto.h"

int main()
{
txCreateWindow (1024, 768);

printf ("Searching for client...\n");
TX_SOCKET client = txCreateSocket (TX_SERVER, "");

char str[Message_size] = "";

printf ("out: ");
scanf ("%s", str);
txSendTo (client, str, Message_size);

txRecvFrom (client, str, Message_size);
printf ("in: %s\n", str);

return 0;
}
