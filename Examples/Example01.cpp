//{=========================================================================== 
//! @file       Examples/Example01.cpp
//!
//! @brief      Простейший пример использования TXLib.
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//! 
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:51:05 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);

    txLine   (320, 290, 320, 220);
    txLine   (320, 290, 280, 350);
    txLine   (320, 290, 360, 350);
    txLine   (320, 230, 270, 275);
    txLine   (320, 230, 400, 220);
    txCircle (320, 190, 30);

    txSelectFont ("Times New Roman", 60);
    txTextOut (240, 400, "Hello, world!");

    return 0;
    }

// Если вам непонятно, что означает та или иная команда в программе, посмотрите в системе
// помощи TXLib Help "Простейший пример" или помощь по этой команде в разделе "Рисование".
// Например, по txLine или txTextOut.
