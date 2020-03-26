//{===========================================================================
//! @file       Examples/Example02/proto.h
//!
//! @brief      Чуть(!) более сложный пример использования TXNetwork - сетевая рисовалка.
//!
//!             Пример протокола для NetPaint - сетевой рисовалки.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================
// proto.h

// 1. server -> client: NetCursor_t
// 2. server <- client: NetCursor_t

#include "TXNetwork.h"
#include "TXLib.h"

enum CursorActions
    {
    CUR_NOP = 0,
    CUR_DRAW = 1,
    CUR_EXIT = -1
    };

struct NetCursor_t
    {
    int     x,     y;
    int old_x, old_y;
    CursorActions action;
    };
