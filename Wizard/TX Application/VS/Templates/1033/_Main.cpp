[!if !PROJECT_SIMPLE]
//========================================================================
//! @file       [!output PROJECT_NAME].cpp
//{=======================================================================
//! 
//! @brief      [!output PROJECT_TITLE]\n
//! @brief      [!output PROJECT_DESCRIPTION]
//! 
//! @version    [0.01 alpha, build 1]
//! @author     Copyright (C) [!output PROJECT_AUTHOR], [!output PROJECT_YEAR] ([!output PROJECT_AUTHOR_NAME], [!output PROJECT_AUTHOR_MAIL])
//! @date       [!output PROJECT_DATE]
//! 
//}=======================================================================

#define __MODULE       "[!output PROJECT_NAME]"
#define __DESCRIPTION  "[!output PROJECT_TITLE]. [!output PROJECT_DESCRIPTION]"
#define __AUTHOR       "[!output PROJECT_AUTHOR]"
#define __VERSION      "0.01 alpha, [!output PROJECT_DATE]"

//========================================================================
[!endif]

#include "TXLib.h"

int main()
    {
    // TODO: Add your code here.

    txCreateWindow (800, 600);

    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txRectangle (10, 10, 790, 590);

    txSetColor (TX_LIGHTCYAN);
    txEllipse (200, 150, 600, 450);
    txEllipse (245, 150, 555, 450);
    txEllipse (290, 150, 510, 450);
    txEllipse (330, 150, 470, 450);
    txEllipse (375, 150, 425, 450);
    txEllipse (200, 150, 600, 450);
    txEllipse (200, 190, 600, 410);
    txEllipse (200, 230, 600, 370);
    txEllipse (200, 270, 600, 330);
    txLine    (200, 300, 600, 300);

    txSetColor (TX_LIGHTGREEN);
    txSelectFont ("Times", 60);
    txSetTextAlign (TA_CENTER);
    txTextOut (400, 480, "Hello, world!");

    txSetColor (TX_YELLOW);
    txSetFillColor (TX_YELLOW);
    txLine   (385, 135, 385, 120);
    txLine   (385, 135, 375, 150);
    txLine   (385, 135, 395, 150);
    txLine   (385, 125, 375, 135);
    txLine   (385, 125, 400, 120);
    txCircle (385, 115, 6);

    txSetFillColor (TX_TRANSPARENT);
    txLine (400, 75, 400, 150);
    txRectangle (400, 75, 450, 115);
    txSelectFont ("Times", 20);
    txTextOut (425, 85, "C++");

    txTextCursor (false);
    return 0;
    }

