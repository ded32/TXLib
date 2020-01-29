//{===========================================================================
//! @file       Examples/Example01/client.cpp
//!
//! @brief      ������ ������ ������������� TXNetwork.
//!
//!             ���������� ���� ����� ���������� (TXNetwork).
//!
//!             ��� ���������� ������.
//!             ���������� ������� ������, ����� ������.
//!             ���� ������ ����������� �� �� ��� �� ������, ��� � ������,
//!             ���� ������� @strike �� ������� @endstrike IP-����� ������� � ������ IP.
//!
//!             $Copyright: (C) _RedMan_ (Vova Yrovsky) <vova@txlib.ru> $
//}===========================================================================

#include "proto.h"

#define IP "localhost" //������� IP ����� �����.

int main()
{
txCreateWindow (1024, 768);

Ball_t ball = {0, 0, 0, 0};

printf ("Searching for server...\n");

TX_SOCKET ball_server = txCreateSocket (TX_CLIENT, IP);

if (txnAssert(ball_server) == TXN_NOT_CREATED)
    {
    printf("Can't find server on this IP.\n");
    return -1;
    }

printf ("Start draw meow.\n");

while (true)
    {
    txRecvFrom (ball_server, &ball, sizeof(ball));

    txSetFillColor(TX_RED);
    txSetColor(TX_RED);

    if (ball.x == -100 && ball.y == -100)
        break;

    txCircle(ball.x, ball.y, 10);

    txSleep(1);
    txSetFillColor(TX_BLACK);
    txClear();
    }

return 0;
}
