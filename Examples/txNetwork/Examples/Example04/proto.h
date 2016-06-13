//{===========================================================================
//! @file       Examples/Example04/proto.h
//!
//! @brief      Четвертый пример использования TXNetwork - много шариков.
//!
//!             Библиотека Сети Тупых Художников (TXNetwork).
//!
//!             Пример протокола для многих шариков.
//!
//!             $Copyright: (C) _RedMan_ (Vova Yrovsky) <vova@txlib.ru> $
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

