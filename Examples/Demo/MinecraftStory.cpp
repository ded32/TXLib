//{===========================================================================
//! @file       Examples\Demo\MinecraftStory.cpp
//!
//! @brief      Мультфильм "Minecraft Story"
//!
//!             Зачетная работа за 3 четверть 7 класса
//!
//! @date       2013
//! @author     Васильев Валерий, 7 класс
//          (C) Васильев Валерий, 7 класс, 2013
//}===========================================================================

#include "TXLib.h"

// Прототипы

void MainDraw (COLORREF color);
void Grass (COLORREF color, int Up);
void Ground (COLORREF color);
void Tree (COLORREF color, int Up, COLORREF Trunk, int UpLeaf, int Width1, int Width2, int Up1, int Up2, int Apples, int R);
void House (int Open, int Crack, int Pipe, COLORREF ColorSmoke, int Fire, int Height, int Length);
void Sun (int x, int y, COLORREF color, double Size, double Length);
void Cloud (int x, int y, COLORREF color, COLORREF colorbg, double Size, int Height, int Length, int Length2);
void Creeper (int x, int y, double Size, COLORREF color, int Eye, COLORREF EyeColor, int Neck, COLORREF Foot);
void Man (int x, int y, double Size, int Turn, COLORREF pants, COLORREF shirt, COLORREF Hair, double PantsUp);
void Boom (int x, int y, COLORREF color, double Size, double Length);
void Scenery();
void Scenery2();
void Scenery3();
void Scenery4();
void RunToTree();
void RunFromTree();
void CreeperAppears();
void ManTurn();
void RunFromCreeper();
void Rise1();
void Rise2();
void CreeperDraw();
void CreeperRun();
void CreeperJump();
void Boom();
void AddCrack();
void Wait();
void DoorOpen();
void ManDraw();
void Descent1();
void Descent2();
void RunToTreeNight();
void CreepersAdd();
void ManTurn2();
void CreepersAdd2();
void ManTurn3();
void Booms();
void Clear();
void FinishTitles();
void FinishTitles2();
void CreeperDescent();
void CreeperRun2();
void BigBoom();
void BLACKEND();
void StartTitles();
void Credits();

// Вызовы

int main()
    {
    txCreateWindow (1280, 720);
    txBegin();

    StartTitles();

    RunToTree();
    RunFromTree();
    CreeperAppears();
    ManTurn();
    RunFromCreeper();
    Rise1();
    Rise2();
    CreeperDraw();
    CreeperRun();
    CreeperJump();
    Boom();
    AddCrack();
    Wait();
    DoorOpen();
    ManDraw();
    Descent1();
    Descent2();
    RunToTreeNight();
    CreepersAdd();
    ManTurn2();
    CreepersAdd();
    ManTurn3();
    Booms();

    Clear();
    FinishTitles();
    FinishTitles2();
    CreeperDescent();
    CreeperRun2();
    BigBoom();

    BLACKEND();

    txEnd();
    return 0;
    }

// Функции

void MainDraw (COLORREF color)
    {
    txClear();
    txSetFillColor (color);
    txFloodFill (2, 2);
    }

void Grass (COLORREF color, int Up)
    {
    txSetColor (TX_BLACK);   // трава
    txLine (0, 640 - Up, 1280, 640 - Up);
    txLine (0, 660, 1280, 660);
    txLine (0, 640, 0, 660);
    txLine (1280, 640, 1280, 660);
    txSetFillColor (color);
    txFloodFill (1, 641);
    }

void Ground (COLORREF color)
    {
    txSetColor (TX_BLACK);   // земля
    txLine (0, 661, 0, 720);
    txLine (1280, 661, 1280, 720);
    txLine (0, 720, 1280, 720);
    txSetFillColor (color);
    txFloodFill (1, 661);
    }

void Tree (COLORREF color, int Up, COLORREF Trunk, int UpLeaf, int Width1, int Width2, int Up1, int Up2, int Apples, int R)
    {
    txSetColor (TX_BLACK);   // дерево
    txLine (200, 640, 280, 640);
    txLine (200, 640, 200, 400 - Up);
    txLine (280, 640, 280, 400 - Up);
    txLine (200, 400 - Up, 280, 400 - Up);
    txSetFillColor (Trunk);
    txFloodFill (201, 639);
    txSetColor (TX_BLACK);
    txLine (199, 480 - Up2, 40 - Width2, 480 - Up2);
    txLine (40 - Width2, 480 - Up2, 40 - Width2, 320);
    txLine (40 - Width2, 320, 120, 320);
    txLine (120 , 320, 120, 240 - UpLeaf);
    txLine (120, 240 - UpLeaf, 360, 240 - UpLeaf);
    txLine (360, 240 - UpLeaf, 360, 320);
    txLine (360, 320, 440 + Width1, 320);
    txLine (440 + Width1, 320, 440 + Width1, 480 - Up1);
    txLine (440 + Width1, 480 - Up1, 280, 480 - Up1);
    txSetFillColor (color);
    txFloodFill (381, 479);

    txSetColor (RGB (229, 38, 24));
    txCircle (185 * Apples, 280 * Apples, R * Apples);
    txCircle (325 * Apples, 350 * Apples, R * Apples);
    txCircle (410 * Apples, 410 * Apples, R * Apples);
    txCircle (130 * Apples, 430 * Apples, R * Apples);
    txSetFillColor (RGB (229, 38, 24));
    txCircle (0, 0, 2);
    txFloodFill (185 * Apples, 280 * Apples);
    txFloodFill (325 * Apples, 350 * Apples);
    txFloodFill (410 * Apples, 410 * Apples);
    txFloodFill (130 * Apples, 430 * Apples);
    }

void House (int Open, int Crack, int Pipe, COLORREF ColorSmoke, int Fire, int Height, int Length)
    {
    txSetColor (TX_BLACK);   // дом
    txLine (1120, 640, 1120, 320);
    txLine (1120, 320, 1280, 320);
    txLine (1500, 320, 1500, 640);
    txLine (1500, 640, 1120, 640);
    txSetFillColor (RGB (220, 220, 220));
    txFloodFill (1121, 639);
    txLine (1120, 320, 1040, 320);
    txLine (1040, 320, 1040, 300);
    txLine (1040, 300, 1060, 300);
    txLine (1060, 300, 1060, 280);
    txLine (1060, 280, 1080, 280);
    txLine (1080, 280, 1080, 260);
    txLine (1080, 260, 1100, 260);
    txLine (1100, 260, 1100, 240);
    txLine (1100, 240, 1500, 240);
    txLine (1500, 240, 1500, 320);
    txSetFillColor (RGB (238, 197, 145));
    txFloodFill (1041, 319);
    txLine (1040, 640, 1040, 600);
    txLine (1040, 600, 1080, 600);
    txLine (1080, 600, 1080, 560);
    txLine (1080, 560, 1120, 560);
    txLine (1120, 560, 1120, 640);
    txLine (1120, 640, 1040, 640);
    txSetFillColor (RGB (238, 197, 145));
    txFloodFill (1041, 639);
    txSetColor (RGB (205, 170, 125));
    txLine (1120 - 60 * Open, 560, 1120 - 60 * Open, 400);
    txLine (1120 - 60 * Open, 400, 1125 - 5 * Open, 400);
    txLine (1125 - 5 * Open, 400, 1125 - 5 * Open, 560);
    txLine (1125 - 65 * Open, 560, 1120, 560);
    txSetFillColor (RGB (208, 170, 125));
    txFloodFill (1121 - 60 * Open, 559);
    txFloodFill (1121 - 30 * Open, 559);
    txSetColor (TX_BLACK);
    txLine (1120, 485, 1115, 485);
    txLine (1115, 485, 1115, 480);
    txLine (1115, 480, 1120, 480);
    txLine (1120, 480, 1120, 485);
    txSetFillColor (TX_BLACK);
    txFloodFill (1116, 484);
    txLine (1200 - Length, 400 - Height, 1360, 400 - Height);
    txLine (1360, 400, 1360, 480);
    txLine (1360, 480, 1200 - Length, 480);
    txLine (1200 - Length, 480, 1200 - Length, 400 - Height);
    txSetFillColor (RGB (255, 255, 255));
    txFloodFill (1201, 479);

    txLine (1190 * Crack, 515 * Crack, 1250 * Crack, 590 * Crack);
    txLine (1250 * Crack, 590 * Crack, 1245 * Crack, 615 * Crack);
    txLine (1215 * Crack, 550 * Crack, 1195 * Crack, 590 * Crack);
    txLine (1225 * Crack, 560 * Crack, 1250 * Crack, 550 * Crack);

    txLine (1230 * Pipe, 240 * Pipe, 1230 * Pipe, 210 * Pipe);
    txLine (1230 * Pipe, 210 * Pipe, 1240 * Pipe, 210 * Pipe);
    txLine (1240 * Pipe, 210 * Pipe, 1240 * Pipe, 240 * Pipe);
    txLine (1240 * Pipe, 240 * Pipe, 1230 * Pipe, 240 * Pipe);
    txSetFillColor (RGB (138, 78, 18));
    txFloodFill (1231 * Pipe, 211 * Pipe);

    txSetColor (ColorSmoke);
    txLine (1235, 205, 1245, 190);
    txLine (1245, 190, 1230, 175);
    txLine (1230, 175, 1245, 160);
    txLine (1245, 160, 1230, 145);

    txSetColor (TX_BLACK);
    txLine (1120, 380, 1100, 340);
    txLine (1120, 370, 1110, 340);
    txLine (1100, 340, 1110, 340);
    txSetFillColor (RGB (138, 78, 18));
    txFloodFill (1105, 341);

    txSetColor (RGB (210, 70, 9));
    txLine (1102 * Fire, 339 * Fire, 1095 * Fire, 330 * Fire);
    txLine (1095 * Fire, 330 * Fire, 1105 * Fire, 325 * Fire);
    txLine (1105 * Fire, 325 * Fire, 1115 * Fire, 330 * Fire);
    txLine (1115 * Fire, 330 * Fire, 1108 * Fire, 340 * Fire);
    txSetFillColor (RGB (210, 70, 9));
    txFloodFill (1105 * Fire, 327 * Fire);
    }

void Sun (int x, int y, COLORREF color, double Size, double Length)
    {
    txSetColor (color);  // солнце
    txSetFillColor (color);
    txCircle (x + (950 - 950) *Size, y + (90 - 90) *Size, 50 * Size);

    txLine (x + (950 - 950) *Size,  y + (150 - 90) *Size, x + (950 - 950) *Size,  y + (210 - 90) *Size - 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (30 - 90) *Size,  x + (950 - 950) *Size,  y + (0 - 90) *Size);
    txLine (x + (890 - 950) *Size,  y + (90 - 90) *Size,  x + (830 - 950) *Size + 25 * Length, y + (90 - 90) *Size);
    txLine (x + (1010- 950) *Size,  y + (90 - 90) *Size,  x + (1070- 950) *Size - 25 * Length, y + (90 - 90) *Size);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (860 - 950) *Size + 25 * Length, y + (170- 90) *Size - 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (1040- 950) *Size - 25 * Length, y + (170- 90) *Size - 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (860 - 950) *Size + 25 * Length, y + (10 - 90) *Size + 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (1040- 950) *Size - 25 * Length, y + (10 - 90) *Size + 25 * Length);
    }

void Cloud (int x, int y, COLORREF color, COLORREF colorbg, double Size, int Height, int Length, int Length2)
    {
    txSetColor (colorbg);  // облако
    txLine (x + (230 - 340) *Size, y + (30 - 70) *Size - Height, x + (390 - 340) *Size, y + (30 - 70) *Size - Height) ;
    txLine (x + (390 - 340) *Size, y + (30 - 70) *Size - Height, x + (390 - 340) *Size, y + (70 - 70) *Size) ;
    txLine (x + (390 - 340) *Size, y + (70 - 70) *Size, x + (430 - 340) *Size + Length, y + (70 - 70) *Size);
    txLine (x + (430 - 340) *Size + Length, y + (70 - 70) *Size, x + (430 - 340) *Size + Length, y + (110 - 70) *Size);
    txLine (x + (430 - 340) *Size + Length, y + (110 - 70) *Size, x + (270 - 340) *Size, y + (110 - 70) *Size);
    txLine (x + (270 - 340) *Size, y + (110 - 70) *Size, x + (270 - 340) *Size, y + (70 - 70) *Size - Length2);
    txLine (x + (270 - 340) *Size, y + (70 - 70) *Size - Length2, x + (230 - 340) *Size, y + (70 - 70) *Size - Length2);
    txLine (x + (230 - 340) *Size, y + (70 - 70) *Size - Length2, x + (230 - 340) *Size, y + (30 - 70) *Size - Height) ;
    txSetFillColor (color);
    txFloodFill (x + (250 - 340) *Size, y + (40 - 70) *Size);
    }

void Creeper (int x, int y, double Size, COLORREF color, int Eye, COLORREF EyeColor, int Neck, COLORREF Foot)
    {
    txLine (x + (590 - 620) *Size, y + (640 - 590) *Size, x + (590 - 620) *Size, y + (610 - 590) *Size); // крипер
    txLine (x + (590 - 620) *Size, y + (610 - 590) *Size, x + (610 - 620) *Size, y + (610 - 590) *Size);
    txLine (x + (610 - 620) *Size, y + (610 - 590) *Size, x + (610 - 620) *Size, y + (640 - 590) *Size);

    txLine (x + (610 - 620) *Size, y + (640 - 590) *Size * Neck, x + (590 - 620) *Size, y + (640 - 590) *Size * Neck);
    txLine (x + (610 - 620) *Size, y + (610 - 590) *Size * Neck, x + (630 - 620) *Size, y + (610 - 590) *Size * Neck);
    txLine (x + (630 - 620) *Size, y + (610 - 590) *Size * Neck, x + (650 - 620) *Size, y + (610 - 590) *Size * Neck);
    txLine (x + (650 - 620) *Size, y + (610 - 590) *Size * Neck, x + (650 - 620) *Size, y + (640 - 590) *Size * Neck);
    txLine (x + (650 - 620) *Size, y + (640 - 590) *Size * Neck, x + (630 - 620) *Size, y + (640 - 590) *Size * Neck);
    txLine (x + (630 - 620) *Size, y + (640 - 590) *Size * Neck, x + (630 - 620) *Size, y + (610 - 590) *Size * Neck);
    txLine (x + (630 - 620) *Size, y + (610 - 590) *Size * Neck, x + (630 - 620) *Size, y + (560 - 590) *Size * Neck);
    txLine (x + (630 - 620) *Size, y + (560 - 590) *Size * Neck, x + (610 - 620) *Size, y + (560 - 590) *Size * Neck);
    txLine (x + (610 - 620) *Size, y + (560 - 590) *Size * Neck, x + (610 - 620) *Size, y + (610 - 590) *Size * Neck);
    txLine (x + (610 - 620) *Size, y + (560 - 590) *Size * Neck, x + (600 - 620) *Size, y + (560 - 590) *Size * Neck);
    txLine (x + (600 - 620) *Size, y + (560 - 590) *Size * Neck, x + (600 - 620) *Size, y + (520 - 590) *Size * Neck);
    txLine (x + (600 - 620) *Size, y + (520 - 590) *Size * Neck, x + (640 - 620) *Size, y + (520 - 590) *Size * Neck);
    txLine (x + (640 - 620) *Size, y + (520 - 590) *Size * Neck, x + (640 - 620) *Size, y + (560 - 590) *Size * Neck);
    txLine (x + (640 - 620) *Size, y + (560 - 590) *Size * Neck, x + (630 - 620) *Size, y + (560 - 590) *Size * Neck);
    txLine (x + (590 - 620) *Size, y + (635 - 590) *Size, x + (610 - 620) *Size, y + (635 - 590) *Size);
    txLine (x + (630 - 620) *Size, y + (635 - 590) *Size, x + (650 - 620) *Size, y + (635 - 590) *Size);
    txSetColor (TX_BLACK);

    txLine (x - 15 * Eye, y - 65 * Eye, x - 10 * Eye, y - 65 * Eye);
    txLine (x - 10 * Eye, y - 65 * Eye, x - 10 * Eye, y - 60 * Eye);
    txLine (x - 10 * Eye, y - 60 * Eye, x - 15 * Eye, y - 60 * Eye);
    txLine (x - 15 * Eye, y - 60 * Eye, x - 15 * Eye, y - 65 * Eye);

    txLine (x + 15 * Eye, y - 65 * Eye, x + 10 * Eye, y - 65 * Eye);
    txLine (x + 10 * Eye, y - 65 * Eye, x + 10 * Eye, y - 60 * Eye);
    txLine (x + 10 * Eye, y - 60 * Eye, x + 15 * Eye, y - 60 * Eye);
    txLine (x + 15 * Eye, y - 60 * Eye, x + 15 * Eye, y - 65 * Eye);

    txSetFillColor (EyeColor);
    txFloodFill ( (x - 14) *Eye, (y - 64) *Eye);
    txFloodFill ( (x + 14) *Eye, (y - 64) *Eye);

    txSetFillColor (Foot);
    txFloodFill (x + (591 - 620) *Size, y + (636 - 590) *Size);
    txFloodFill (x + (631 - 620) *Size, y + (636 - 590) *Size);
    txSetFillColor (color);
    txFloodFill (x + (591 - 620) *Size, y + (611 - 590) *Size);
    txFloodFill (x + (631 - 620) *Size, y + (611 - 590) *Size);
    txFloodFill (x + (611 - 620) *Size, y + (609 - 590) *Size);
    txFloodFill (x + (601 - 620) *Size, y + (559 - 590) *Size);
    }

void Scenery()
    {
    Grass (RGB (50, 205, 50), 0);
    Ground (RGB (136, 69, 19));
    Tree (RGB (84, 139, 84), 10, RGB (184, 134, 11), 50, 20, 0, 0, 10, 0, 10);
    House (0, 0, 1, TX_BLACK, 1, 10, 15);
    }

void Scenery2()
    {
    Grass (RGB (50, 205, 50), 0);
    Ground (RGB (136, 69, 19));
    Tree (RGB (84, 139, 84), 10, RGB (184, 134, 11), 50, 20, 0, 0, 10, 1, 10);
    }

void Scenery3()
    {
    Grass (RGB (50, 205, 50), 0);
    Ground (RGB (136, 69, 19));
    Tree (RGB (84, 139, 84), 10, RGB (184, 134, 11), 50, 20, 0, 0, 10, 1, 10);
    House (0, 0, 1, TX_BLACK, 1, 10, 15);
    }

void Scenery4()
    {
    Grass (RGB (50, 205, 50), 0);
    Ground (RGB (136, 69, 19));
    Tree (RGB (84, 139, 84), 10, RGB (184, 134, 11), 50, 20, 0, 0, 10, 0, 10);
    }

void Man (int x, int y, double Size, int Turn, COLORREF pants, COLORREF shirt, COLORREF Hair, double PantsUp)
    {
    txLine (x + (800 - 810) *Size * Turn, y + (640 - 570) *Size, x + (800 - 810) *Size * Turn, y + (520 - 570) *Size); // человек
    txLine (x + (800 - 810) *Size * Turn, y + (520 - 570) *Size, x + (821 - 810) *Size * Turn, y + (520 - 570) *Size);
    txLine (x + (820 - 810) *Size * Turn, y + (640 - 570) *Size, x + (820 - 810) *Size * Turn, y + (540 - 570) *Size);
    txLine (x + (800 - 810) *Size * Turn, y + (580 - 570) *Size * PantsUp, x + (820 - 810) *Size * Turn, y + (580 - 570) *Size * PantsUp);
    txLine (x + (800 - 810) *Size * Turn, y + (635 - 570) *Size, x + (820 - 810) *Size * Turn, y + (635 - 570) *Size);
    txLine (x + (800 - 810) *Size * Turn, y + (640 - 570) *Size, x + (820 - 810) *Size * Turn, y + (640 - 570) *Size);
    txLine (x + (800 - 810) *Size * Turn, y + (520 - 570) *Size, x + (790 - 810) *Size * Turn, y + (520 - 570) *Size);
    txLine (x + (790 - 810) *Size * Turn, y + (520 - 570) *Size, x + (790 - 810) *Size * Turn, y + (480 - 570) *Size);
    txLine (x + (790 - 810) *Size * Turn, y + (480 - 570) *Size, x + (830 - 810) *Size * Turn, y + (480 - 570) *Size);
    txLine (x + (830 - 810) *Size * Turn, y + (480 - 570) *Size, x + (830 - 810) *Size * Turn, y + (520 - 570) *Size);
    txLine (x + (830 - 810) *Size * Turn, y + (520 - 570) *Size, x + (820 - 810) *Size * Turn, y + (520 - 570) *Size);
    txLine (x + (820 - 810) *Size * Turn, y + (520 - 570) *Size, x + (850 - 810) *Size * Turn, y + (550 - 570) *Size);
    txLine (x + (800 - 810) *Size * Turn, y + (520 - 570) *Size, x + (840 - 810) *Size * Turn, y + (560 - 570) *Size);
    txLine (x + (850 - 810) *Size * Turn, y + (550 - 570) *Size, x + (839 - 810) *Size * Turn, y + (561 - 570) *Size);
    txLine (x + (790 - 810) *Size * Turn, y + (495 - 570) *Size, x + (800 - 810) *Size * Turn, y + (495 - 570) *Size);
    txLine (x + (800 - 810) *Size * Turn, y + (495 - 570) *Size, x + (800 - 810) *Size * Turn, y + (490 - 570) *Size);
    txLine (x + (800 - 810) *Size * Turn, y + (490 - 570) *Size, x + (830 - 810) *Size * Turn, y + (490 - 570) *Size);
    txSetFillColor (TX_BLACK);
    txFloodFill (x + (801 - 810) *Size * Turn, y + (639 - 570) *Size);
    txSetFillColor (pants);
    txFloodFill (x + (801 - 810) *Size * Turn, y + (634 - 570) *Size);
    txSetFillColor (shirt);
    txFloodFill (x + (801 - 810) *Size * Turn, y + (559 - 570) *Size);
    txSetFillColor (RGB (222, 184, 135));
    txFloodFill (x + (820 - 810) *Size * Turn, y + (536 - 570) *Size);
    txFloodFill (x + (829 - 810) *Size * Turn, y + (491 - 570) *Size);
    txSetFillColor (Hair);
    txFloodFill (x + (791 - 810) *Size * Turn, y + (494 - 570) *Size);
    }

void Boom (int x, int y, COLORREF color, double Size, double Length)
    {
    txSetColor (color);  // Бум!
    txSelectFont ("Times New Roman", 40 * Size);
    txTextOut (x + (900 - 950) *Size, y + (70 - 90) *Size, "BOOM!");

    txLine (x + (950 - 950) *Size,  y + (150 - 90) *Size, x + (950 - 950) *Size,  y + (210 - 90) *Size - 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (30 - 90) *Size,  x + (950 - 950) *Size,  y + (0 - 90) *Size);
    txLine (x + (890 - 950) *Size,  y + (90 - 90) *Size,  x + (830 - 950) *Size + 25 * Length,  y + (90 - 90) *Size);
    txLine (x + (1010 - 950) *Size, y + (90 - 90) *Size,  x + (1070 - 950) *Size - 25 * Length, y + (90 - 90) *Size);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (860 - 950) *Size + 25 * Length,  y + (170 - 90) *Size - 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (1040 - 950) *Size - 25 * Length, y + (170 - 90) *Size - 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (860 - 950) *Size + 25 * Length,  y + (10 - 90) *Size + 25 * Length);
    txLine (x + (950 - 950) *Size,  y + (90 - 90) *Size,  x + (1040 - 950) *Size - 25 * Length, y + (10 - 90) *Size + 25 * Length);
    }

// Сцены

void RunToTree()
    {
    int t = 0;

    while (t <= 100)
        {
        txClear();
        Scenery3();

        Cloud (340 - t * 8, 70, TX_WHITE, TX_BLACK, 1.2, 0, 30, 15);
        Cloud (750 - t * 10, 160, RGB (247, 245, 245), TX_BLACK, 1, 20, 0, 0);

        Man (810 - 3 * t, 570 - t % 10, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        Sun (1150 + (int) (1.4 * t), 90 + (int) (0.1 * t), RGB (247, 225, 82), 1, 0);
        txSetFillColor (RGB (175 - t, 238 - t, 238 - t));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void RunFromTree()
    {
    int t = 0;

    while (t <= 80)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Man (510 + 3 * t, 570 - t % 10, 1, 1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        Sun (1290 + (int) (1.4 * t), 100 + (int) (0.1 * t), RGB (247, 225, 82), 1, 0);
        txSetFillColor (RGB (75 - 0.95 * t, 138 - t, 138 - t));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void CreeperAppears()
    {
    int t = 0;

    while (t <= 10)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Man (750 + 3 * t, 570 - t % 10, 1, 1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        txSetColor (TX_BLACK);
        Creeper (420 + 4 * t, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void ManTurn()
    {
    int t = 0;

    while (t <= 5)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Man (780, 570, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        Creeper (460, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void RunFromCreeper()
    {
    int t = 0;

    while (t <= 50)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Man (780 + 5 * t, 570 - t % 15, 1, 1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        txSetColor (TX_BLACK);
        Creeper (460 + 5 * t, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Rise1()
    {
    int t = 0;

    while (t <= 1)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Man (1050, 530, 1, 1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        txSetColor (TX_BLACK);
        Creeper (720, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Rise2()
    {
    int t = 0;

    while (t <= 2)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Creeper (730, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        House (1, 0, 1, TX_BLACK, 1, 10, 15);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void CreeperDraw()
    {
    int t = 0;

    while (t <= 5)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Creeper (740, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void CreeperRun()
    {
    int t = 0;

    while (t <= 80)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Creeper (740 + t * 3, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void CreeperJump()
    {
    int t = 0;

    while (t <= 30)
        {
        txClear();
        Scenery();

        txSetColor (TX_BLACK);
        Creeper (980, 590 - t % 5, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Boom()
    {
    int t = 0;

    while (t <= 5)
        {
        txClear();
        Scenery();

        Boom (980, 550, RGB (230, 127, 24), 1, 1);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void AddCrack()
    {
    int t = 0;

    while (t <= 10)
        {
        txClear();
        Scenery4();

        txSetColor (TX_BLACK);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Wait()
    {
    int t = 0;

    while (t <= 20)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void DoorOpen()
    {
    int t = 0;

    while (t <= 2)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        House (1, 1, 1, TX_BLACK, 0, 10, 15);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void ManDraw()
    {
    int t = 0;

    while (t <= 2)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (1080, 490, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Descent1()
    {
    int t = 0;

    while (t <= 2)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (1050, 530, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Descent2()
    {
    int t = 0;

    while (t <= 2)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (1020, 570, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void RunToTreeNight()
    {
    int t = 0;

    while (t <= 50)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (1020 - 5 * t, 570 - t % 5, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void CreepersAdd()
    {
    int t = 0;

    while (t <= 3)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (770, 570, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        Creeper (560, 580, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (610, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (520, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void ManTurn2()
    {
    int t = 0;

    while (t <= 3)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (770, 570, 1, 1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        Creeper (560, 580, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (610, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (520, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void CreepersAdd2()
    {
    int t = 0;

    while (t <= 3)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (770, 570, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        Creeper (560, 580, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (610, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (520, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);

        Creeper (920, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (970, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (880, 570, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (1040, 550, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void ManTurn3()
    {
    int t = 0;

    while (t <= 3)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (770, 570, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);
        Creeper (560, 580, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (610, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (520, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);

        Creeper (920, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (970, 590, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (880, 570, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        Creeper (1040, 550, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Booms()
    {
    int t = 0;

    while (t <= 3)
        {
        txClear();
        Scenery2();

        txSetColor (TX_BLACK);
        Man (770, 570, 1, -1, RGB (33, 29, 146), RGB (30, 148, 178), RGB (139, 69, 19), 1);
        House (0, 1, 1, TX_BLACK, 0, 10, 15);
        txSetColor (TX_BLACK);

        Boom (560, 580, RGB (230, 127, 24), 1, 1);
        Boom (610, 590, RGB (230, 127, 24), 1, 1);
        Boom (520, 590, RGB (230, 127, 24), 1, 1);

        Boom (920, 590, RGB (230, 127, 24), 1, 1);
        Boom (970, 590, RGB (230, 127, 24), 1, 1);
        Boom (880, 570, RGB (230, 127, 24), 1, 1);
        Boom (1040, 550, RGB (230, 127, 24), 1, 1);

        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void Clear()
    {
    txClear();
    Grass (RGB (50, 205, 50), 0);
    Ground (RGB (136, 69, 19));
    txSetFillColor (RGB (0, 58, 58));
    txFloodFill (5, 5);
    }

void FinishTitles()
    {
    int t = 0;

    while (t <= 5)
        {
        txClear();
        Grass (RGB (50, 205, 50), 0);
        Ground (RGB (136, 69, 19));
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);
        txSetColor (TX_WHITE);
        txSelectFont ("Berlin Sans FB Demi", 200);
        txTextOut (420, 160, "THE END!");
        txSleep (100);
        t++;
        }
    }

void Credits()
    {
    txSetColor (TX_WHITE);
    txSelectFont ("Berlin Sans FB Demi", 50);
    txTextOut (420, 160, "Мультик сделан Васильевым Валерой");
    txTextOut (570, 210, "в 2013 году,");
    txTextOut (490, 260, "по мотивам игры Minecraft");
    }

void FinishTitles2()
    {
    int t = 0;

    while (t <= 10)
        {
        txClear();
        Grass (RGB (50, 205, 50), 0);
        Ground (RGB (136, 69, 19));
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        Credits();

        txSleep (100);
        t++;
        }
    }

void StartTitles()
    {
    int t = 0;

    while (t <= 85)
        {
        txClear();
        Grass (RGB (50, 205, 50), 0);
        Ground (RGB (136, 69, 19));
        txSetFillColor (RGB (175, 238, 238));
        txFloodFill (5, 5);
        txSetColor (TX_BLACK);
        txSelectFont ("Impact", 200);
        txTextOut (-700 + t * 10, 100, "Minecraft");
        txSetColor (TX_BLACK);
        txSelectFont ("Gabriola", 200);
        txTextOut (2000 - t * 15, 250, "Story");
        txSleep (100);
        t++;
        }

    txSleep (3000);
    }

void CreeperDescent()
    {
    int t = 0;

    while (t <= 12)
        {
        txClear();
        Grass (RGB (50, 205, 50), 0);
        Ground (RGB (136, 69, 19));

        Credits();

        txSetColor (TX_BLACK);
        Creeper (500, 0 + 10 * t, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void CreeperRun2()
    {
    int t = 0;

    while (t <= 30)
        {
        txClear();
        Grass (RGB (50, 205, 50), 0);
        Ground (RGB (136, 69, 19));

        Credits();

        txSetColor (TX_BLACK);
        Creeper (500 + 5 * t, 120 - t % 5, 1, RGB (69, 139, 0), 1, TX_BLACK, 1, TX_BLACK);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void BigBoom()
    {
    int t = 0;

    while (t <= 3)
        {
        txClear();
        Grass (RGB (50, 205, 50), 0);
        Ground (RGB (136, 69, 19));

        Credits();

        Boom (650, 120, RGB (230, 127, 24), 2, 1);
        txSetFillColor (RGB (0, 58, 58));
        txFloodFill (5, 5);

        txSleep (100);
        t++;
        }
    }

void BLACKEND()
    {
    txClear();
    txSetFillColor (TX_BLACK);
    txFloodFill (5, 5);
    }
