//{===========================================================================
//! @file       Examples/Example01/proto.h
//!
//! @brief      [TXNetwork] Первый пример использования TXNetwork.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================
// proto.h

#include "TXNetwork.h"
#include "TXLib.h"

// 1. server -> client: Ball_t

struct Ball_t
    {
    int  x,  y;
    int vx, vy;
    };
