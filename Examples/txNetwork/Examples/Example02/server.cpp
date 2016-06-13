//{===========================================================================
//! @file       Examples/Example02/server.cpp
//!
//! @brief      Чуть(!) более сложный пример использования TXNetwork/
//!
//!             NetPaint - сетевая рисовалка.
//!             Запускайте сначала сервер, потом клиент.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             $Copyright: (C) _RedMan_ (Vova Yrovsky) <vova@txlib.ru> $
//}===========================================================================

#include "proto.h"

void NetPaint (TX_SOCKET paint_peer);

void CursorDraw (NetCursor_t cursor, COLORREF color);
void CursorMove (NetCursor_t* cursor);

int main()
{
txCreateWindow (1024, 768);

printf ("Searching for client...\n");

TX_SOCKET paint_peer = txCreateSocket (TX_SERVER, "");

printf ("Start draw meow.\n");

if (txnAssert (paint_peer) == TXN_NOT_CREATED)
    {
    printf ("Can't create socket. Maybe, port are busy.\n");
    return -1;
    }

NetPaint (paint_peer);

return 0;
}

void NetPaint (TX_SOCKET paint_peer)
{
NetCursor_t cursor        = {100, 100, -1, -1, CUR_NOP};
NetCursor_t peer_cursor   = {100, 100, -1, -1, CUR_NOP};

while (!GetAsyncKeyState (VK_ESCAPE))
    {
    if (peer_cursor.action == CUR_EXIT)
        break;

    CursorDraw(cursor, TX_LIGHTGREEN);
    CursorDraw(peer_cursor, TX_LIGHTRED);

    CursorMove (&cursor);

    txSendTo    (paint_peer, &cursor     , sizeof(cursor));
    txRecvFrom  (paint_peer, &peer_cursor, sizeof(peer_cursor));

    txSleep (10);
    }

cursor.action = CUR_EXIT;
txSendTo (paint_peer, &cursor, sizeof(cursor));
}

void CursorMove(NetCursor_t* cursor)
{
cursor->old_x = cursor->x;
cursor->old_y = cursor->y;

cursor->x = txMouseX();
cursor->y = txMouseY();

if (txMouseButtons() == 1)
    cursor->action = CUR_DRAW;
else
    cursor->action = CUR_NOP;
}

void CursorDraw (NetCursor_t cursor, COLORREF color)
{
txSetFillColor (color);
txSetColor     (color, 10);

if (cursor.action == CUR_DRAW)
    txLine (cursor.old_x, cursor.old_y, cursor.x, cursor.y);
}
