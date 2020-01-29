//{===========================================================================
//! @file       Examples/Example01/proto.h
//!
//! @brief      ������ ������ ������������� TXNetwork.
//!
//!             ���������� ���� ����� ���������� (TXNetwork).
//!
//!             $Copyright: (C) _RedMan_ (Vova Yrovsky) <vova@txlib.ru> $
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
