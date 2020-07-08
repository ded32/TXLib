//{===========================================================================
//! @file       Examples/Example03/server.cpp
//!
//! @brief      [TXNetwork] Простая игра, использующая TXNetwork.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             Пример сетевой игры "Арканоид".
//!             Запускайте сначала сервер, потом клиент.
//!
//!             Copyright: (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>
//}===========================================================================
// server.cpp

#include "proto.h"

void RunGame          (TX_SOCKET peer_sock);
void DrawPlayer       (Player_t player, COLORREF color);
void DrawBall         (Ball_t  ball);
void MoveBall         (Ball_t* ball);
void BallInterPlayers (Ball_t* ball, Player_t player1, Player_t player2);

int main()
    {
    txCreateWindow (1024, 768);
    txBegin();

    txSetColor (TX_LIGHTGREEN);
    txSetTextAlign (TA_CENTER);
    txTextOut (500, 380, "I am a server!");
    txTextOut (500, 450, "Waiting for client...");
    txSleep (0);

    TX_SOCKET client = txCreateSocket (TX_SERVER, "", TX_STD_PORT, TX_BLOCK, false);

    if (txnAssert (client) == TXN_NOT_CREATED)
        {
        printf ("ERROR: BAD SOCKET!!!");
        return -1;
        }

    RunGame (client);

    return 0;
    }

void RunGame (TX_SOCKET peer_sock)
    {
    Player_t me   = {512,  20, 0};
    Player_t peer = {512, 748, 0};

    Ball_t ball = {100, 100, 15, 15};

    DWORD timer = 0;

    while (!GetAsyncKeyState (VK_ESCAPE) && peer.action != -1)
        {
        txSetFillColor (TX_BLACK);
        txClear();

        txSetColor (TX_LIGHTGREEN);
        txTextOut (500, 380, "I am a server!");
        txTextOut (500, 450, "Use [Left], [Right]. [Escape] to exit.");

        if (GetAsyncKeyState (VK_LEFT)  && me.x >   50) me.x -= 15;
        if (GetAsyncKeyState (VK_RIGHT) && me.x < 1019) me.x += 15;

        MoveBall (&ball);

        DrawBall (ball);
        DrawPlayer (me,   TX_LIGHTGREEN);
        DrawPlayer (peer, TX_PINK);

        BallInterPlayers (&ball, peer, me);

        timer = GetTickCount();

        txSendTo   (peer_sock, &me,   sizeof (me));
        txRecvFrom (peer_sock, &peer, sizeof (peer));
        txSendTo   (peer_sock, &ball, sizeof (ball));

        while (GetTickCount() - timer < 15);
            txSleep (0);
        }

    me.action = -1;
    txSendTo (peer_sock, &me, sizeof (me));
    }

void DrawPlayer (Player_t player, COLORREF color)
    {
    txSetColor     (color);
    txSetFillColor (color);

    txRectangle (player.x - 100, player.y - 10, player.x + 100, player.y + 10);
    }

void DrawBall (Ball_t ball)
    {
    txSetColor     (TX_LIGHTCYAN);
    txSetFillColor (TX_LIGHTCYAN);

    txCircle (ball.x, ball.y, 20);
    }

void MoveBall (Ball_t* ball)
    {
    if (ball->x <    0) { ball->vx = -ball->vx; ball->x =    0; }
    if (ball->x > 1024) { ball->vx = -ball->vx; ball->x = 1024; }
    if (ball->y <    0) { ball->vy = -ball->vy; ball->y =    0; }
    if (ball->y >  768) { ball->vy = -ball->vy; ball->y =  768; }

    ball->x += ball->vx;
    ball->y += ball->vy;
    }

void BallInterPlayers (Ball_t* ball, Player_t player1, Player_t player2)
    {
    if (player1.x - 100 < ball->x && ball->x < player1.x + 100 && player1.y - 25 < ball->y)
        ball->vy = -ball->vy;

    if (player2.x - 100 < ball->x && ball->x < player2.x + 100 && player2.y + 25 > ball->y)
        ball->vy = -ball->vy;
    }
