//{===========================================================================
//! @file       Examples/Example03/proto.h
//!
//! @brief      [TXNetwork] ������� ����, ������������ TXNetwork.
//!
//!             ���������� ���� ����� ���������� (TXNetwork).
//!
//!             ������ ��������� ��� ������� ���� "��������".
//!
//!             Copyright: (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>
//}===========================================================================
// proto.h

#include "TXNetwork.h"
#include "TXLib.h"

//1. server -> client: Player_t
//2. server <- client: Player_t
//3. server -> client: Ball_t

struct Player_t
    {
    int x, y;
    int action;
    };

struct Ball_t
    {
    int  x,  y;
    int vx, vy;
    };

