//{===========================================================================
//! @file       Examples/Example01/server.cpp
//!
//! @brief      [TXNetwork] Первый пример использования TXNetwork.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             Два синхронных шарика.
//!             Запускайте сначала сервер, потом клиент.
//!
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include "proto.h"

void Life (Ball_t* ball);

int main()
{
txCreateWindow (1024, 768);

Ball_t ball = {100, 100, 2, 3};

printf ("Searching for client...\n");

TX_SOCKET ball_client = txCreateSocket (TX_SERVER);

if (txnAssert (ball_client) == TXN_NOT_CREATED)
    {
    printf("Can't open server. Maybe, port are busy.\n");
    return -1;
    }

printf ("Start draw meow.\n");

while (!GetAsyncKeyState(VK_ESCAPE))
    {
    txSendTo (ball_client, &ball, sizeof(ball));

    txSetFillColor (TX_GREEN);
    txSetColor (TX_GREEN);

    txCircle (ball.x, ball.y, 10);
    Life (&ball);

    txSleep (1);
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
