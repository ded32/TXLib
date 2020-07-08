//{===========================================================================
//! @file       Examples/Example04/client.cpp
//!
//! @brief      [TXNetwork] Четвертый пример использования TXNetwork - много шариков.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             Синхронные шарики на многих компьютерах c использованием broadcast'a и UDP.
//!
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include "proto.h"

int main()
{
txCreateWindow (1024, 768);

Ball_t ball = {0, 0, 0, 0};

TX_SOCKET ball_server = txCreateSocket (TX_CLIENT, TX_BROADCAST, TX_STD_PORT, TX_BLOCK, false);

if (txnAssert (ball_server) == TXN_NOT_CREATED)
    {
    printf ("Can't create listener. Maybe, port are busy.\n");
    return -1;
    }

while (true)
    {
    txRecvFrom (ball_server, &ball, sizeof(ball));

    if (ball.x == -100 && ball.y == -100)
        break;

    txSetFillColor (TX_LIGHTRED);
    txSetColor (TX_LIGHTRED);

    txCircle (ball.x, ball.y, 10);

    txSleep (25);
    txSetFillColor (TX_BLACK);
    txClear ();
    }

return 0;
}
