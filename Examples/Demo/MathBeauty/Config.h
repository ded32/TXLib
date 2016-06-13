//{===========================================================================
//! @file       Examples\Demo\MathBeauty\Config.h
//!
//! @brief      Построитель графиков, настройки программы
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @date       2018
//! @author     Филипп Куликов, 7 класс
//          (C) Филипп Куликов, 7 класс, 2006
//}===========================================================================

const int LeftOfTheGrafic   =   40,
          TopOfTheGrafic    =   40,
          RightOfTheGrafic  = 1260,
          BottomOfTheGrafic =  660;

const int LenghDesk = RightOfTheGrafic  + 120,
          HightDesk = BottomOfTheGrafic +  40;

const int XofKF  = LeftOfTheGrafic - 15, YofKF  = TopOfTheGrafic + 5;
const int XofSum = LeftOfTheGrafic,      YofSum = TopOfTheGrafic + 5;

const double Ycentre = (BottomOfTheGrafic + TopOfTheGrafic)/2;
const double Xcentre = (RightOfTheGrafic +  LeftOfTheGrafic)/2+10;

const COLORREF ButtonColor =   RGB (75, 135, 100);
const COLORREF CountourColor = RGB (75 * 1.5, 135 * 1.5, 100 * 1.5);
const COLORREF ShadowColor =   RGB (65, 66, 67);
const COLORREF TextColor   =   RGB (255, 255, 0);

const int Step = 20;
