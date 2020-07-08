//{===========================================================================
//! @file       Examples/Example04/proto.h
//!
//! @brief      [TXNetwork] Четвертый пример использования TXNetwork - много шариков.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             Пример протокола для многих шариков.
//!
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include "TXNetwork.h"
#include "TXLib.h"

//1. server -> broadcast: Ball_t
//   client <- broadcast: Ball_t

struct Ball_t
{
int  x,  y;
int vx, vy;
};

