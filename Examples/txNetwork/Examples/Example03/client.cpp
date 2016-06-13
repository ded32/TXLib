//{===========================================================================
//! @file       Examples/Example03/client.cpp
//!
//! @brief      Простая игра, использующая TXNetwork.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             Пример сетевой игры "Арканоид".
//!             Запускайте сначала сервер, потом клиент.
//!             Если клиент запускается не на той же машине, что и сервер,
//!             надо указать IP-адрес сервера в строке SERVER_IP.
//!
//!             Copyright: (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>
//}===========================================================================

// client.cpp

#include "proto.h"

#define SERVER_IP "127.0.0.1"  // Измените на IP-адрес сервера

void RunGame    (TX_SOCKET peer_sock);
void DrawPlayer (Player_t player, COLORREF color);
void DrawBall   (Ball_t ball);

int main()
    {
    txCreateWindow (1024, 768);
    txBegin();

    txSetColor (TX_LIGHTGREEN);
    txSetTextAlign (TA_CENTER);
    txTextOut (500, 380, "I am a server!");
    txTextOut (500, 450, "Waiting for client...");
    txSleep (0);

    TX_SOCKET client = txCreateSocket (TX_CLIENT, SERVER_IP, TX_STD_PORT, TX_BLOCK, false);

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
    Player_t me   = {512, 748, 0};
    Player_t peer = {512,  20, 0};

    Ball_t ball = {100, 100, 15, 15};

    DWORD timer = 0;

    while (!GetAsyncKeyState (VK_SPACE) && peer.action != -1)
        {
        txSetFillColor (TX_BLACK);
        txClear();

        txSetColor (TX_LIGHTGREEN);
        txTextOut (500, 380, "I am a client!");
        txTextOut (500, 450, "Use [A], [D]. [Space] to exit.");

        if (GetAsyncKeyState ('A') && me.x >   50) me.x -= 15;
        if (GetAsyncKeyState ('D') && me.x < 1019) me.x += 15;

        DrawBall (ball);
        DrawPlayer (me,   TX_LIGHTGREEN);
        DrawPlayer (peer, TX_PINK);

        timer = GetTickCount();

        txRecvFrom (peer_sock, &peer, sizeof (peer));
        txSendTo   (peer_sock, &me,   sizeof (me));
        txRecvFrom (peer_sock, &ball, sizeof (ball));

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

