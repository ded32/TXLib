//!===========================================================================
//! @file       Examples/Example00/proto.h
//!
//! @brief      [TXNetwork] ������, ������� ���������� ������, �������� �������������.
//!
//!             ���������� ���� ����� ���������� (TXNetwork).
//!
//!             ������ �������� ��������� ��� ��������� ������.
//!
//!             Copyright: (C) _RedMan_ (Vova Yurovsky) <vova@txlib.ru>
//!===========================================================================
// proto.h

// 1. server -> client: Message (char[Message_size])
// 2. server <- client: Message (char[Message_size])

#include "TXNetwork.h"
#include "TXLib.h"

const size_t Message_size = 256;
