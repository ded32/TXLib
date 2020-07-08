//{===========================================================================
//! @file       Examples/Example04/server.cpp
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

void Life (Ball_t* ball);

int main()
{
txCreateWindow (1024, 768);

Ball_t ball = {100, 100, 2, 3};

TX_SOCKET ball_client = txCreateSocket (TX_SERVER, TX_BROADCAST, TX_STD_PORT, TX_BLOCK, false);

if (txnAssert (ball_client) == TXN_NOT_CREATED)
    {
    printf("Can't create server. Maybe, port are busy.\nn");
    return -1;
    }

while (!GetAsyncKeyState (VK_ESCAPE))
    {
    txSendTo (ball_client, &ball, sizeof(ball));

    txSetFillColor (TX_LIGHTGREEN);
    txSetColor (TX_LIGHTGREEN);

    txCircle (ball.x, ball.y, 10);
    Life (&ball);

    txSleep (25);
    txSetFillColor (TX_BLACK);
    txClear();
    }

ball.x = -100;
ball.y = -100;
txSendTo (ball_client, &ball, sizeof(ball));

return 0;
}

void Life (Ball_t* ball)
{
if (ball->x < 0)
    {
    ball->x  = 0;
    ball->vx = -ball->vx;
    }

if (ball->y < 0)
    {
    ball->y  = 0;
    ball->vy = -ball->vy;
    }

if (ball->x > 1024)
    {
    ball->x  = 1024;
    ball->vx = -ball->vx;
    }

if (ball->y > 768)
    {
    ball->y  = 768;
    ball->vy = -ball->vy;
    }

ball->y += ball->vy;
ball->x += ball->vx;
}
