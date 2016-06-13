//{===========================================================================
//! @file       Examples\Demo\Movie.cpp
//!
//! @brief      Мультфильм "Путь программиста"
//!
//!             Зачетная работа при поступлении в профильную физмат-группу
//!             7 класса с углубленным изучением программирования.
//!
//! @date       2009
//! @author     Никита Уваров, 6 класс
//          (C) Никита Уваров, 6 класс, 2009
//}===========================================================================

#include "TXLib.h"

#if !defined (_TX_VER) || (_TX_VER < 0x172a0000)
#error Must use TXLib.h version >= 1.72 to compile this. -- Ded
#endif

//============================================================================

// Utilities

COLORREF mixColor (COLORREF first, COLORREF second, int percentage);
COLORREF getTransparentColor (COLORREF toSet, COLORREF back, int alpha);

RECT convert (int cameraX, int cameraY, RECT object);
bool in (RECT in, POINT toCheck);
bool needToDraw (RECT what);

int centerOutByLeftCorner (const char* toCenter);

POINT getPoint (int x, int y);
POINT getPointOnEllipse (int x, int y, int w, int h, double angle);

int sqr (int a);
int getRandom (int min, int max);
int getMainLoopBasedValue (int mainLoop, int from, int to);

double DELAY = -1;
int    SPEED =  1;

void doSleep (int time);

// Loading and deleting

void doHDCPreparations();
void deleteDCs();

FILE* sourceFile      = NULL;
HDC*  sourceCodeParts = NULL;
int   partsAmount     = 0;

void initIO();
HDC  readNextSourceCodePart();
void readCodePro();
void releaseScrollingSource();

// Trigonometric pack

int pointOfRest_x = 0, pointOfRest_y = 0;
double sinTable[360] = {0}, cosTable[360] = {0};

void calculateTables();

int trigonometricGetNormalAngle (int angle);
int trigonometricGetAngleOfLine (int x, int y, int x2, int y2);

void trigonometricSetPointOfRest (int x, int y);
void trigonometricMove (int angle, int lenght);
void trigonometricDrawLine (int angle, int lenght);
void trigonometricDrawLineAndReturn (int angle, int lenght);

// Lightning engine

struct Lightning;

void lightningEngineLoop();
void drawElectra (int x, int y, int angle, int nOfSteps, int stepLenght, int randomness, int thickness, COLORREF center, COLORREF border, int chance);

// Matrix engine & Assembler randomizing system

const char* oneRegisterCommands[] = { "push", "pop", "not", "inc", "dec" };
const char* twoRegisterCommands[] = { "mov", "add", "sub", "mul", "div", "or", "and", "xor" };
const char* functionNames[]       = { "hello", "f", "label", "forHelp", "Ded", "function", "main" };
const char* registers[]           = { "AX", "BX", "CX", "DX", "SI", "DI" };

const char* getRandomRegister();
const char* getRandomCommand();

int*   matrixElementsYPositions = NULL;
char** matrixElementsNames      = NULL;
int    matrixElementsNumber     = 0;

void matrixFireball (int x, int y, const char* text, int len, int textHeight, COLORREF color);
void matrixEngineInit (int count);
void matrixEngineLoop (int spd, COLORREF col);
void destroyBinaryStairsAndMatrix();

// Binary stairs

char** binaryStairsGrounds = NULL;
int    binaryStairsHeight  = 0;

const char* getStairsGround (int lenght);
void generateBinaryStairs (int difference, int flats);
void drawBinaryStairs (int x, int y, COLORREF color);

// Graphics

// Graphic utilities

void drawGradientLine (int x, int y, int x2, int y2, int thickness, COLORREF border, COLORREF center);
void drawGradientRectangle (int x, int y, int x2, int y2, COLORREF topColor, COLORREF downColor);
void drawGradientCircle (int x, int y, int radius, COLORREF centerColor, COLORREF borderColor);
void drawStripedCircle (int x, int y, int stripeRadius, int numberOfPairs, COLORREF fisrtStripe, COLORREF secondStripe);
void drawPies (int x, int y, int xsize, int ysize, int pieAngle, int angleOffset, COLORREF color, COLORREF special, COLORREF border, int thickness);

// Graphics

void drawStickMan (int x, int y, int height, int hairIntensivity, int hairLenght, int walkingPosition,
                   int leftBase, int leftSpecial, int rightBase, int rightSpecial, int direction, int walkingAngle,
                   COLORREF bodyColor, COLORREF hairColor, COLORREF headColor, COLORREF eyeColor, int rotation, int bodyRot);

void drawTurtle (int x, int y, int width, int height, COLORREF shellColor, COLORREF stripesColor);
void drawTurtleBody (int x, int y, int width, int height, int walkingPos, COLORREF body, COLORREF border, COLORREF eye, COLORREF eyeBorder, HDC shell);
void prepareTurtleShell (int width, int height, COLORREF baseColor, COLORREF specials, COLORREF border, int thickness);
void drawStyledTurtleShell (int x, int y, int xStart, int yStart, int xFinal, int yFinal, int numberOfPies, int pieRadius, int offsetAngle, COLORREF color, COLORREF special, COLORREF border, int thickness);

void drawPortalSystem (int x, int y, int radius, int everyRadius, int vertexCount, int bonus, COLORREF color, COLORREF alter, COLORREF back);
void drawPortal (int x, int y, int radius, int each, int bonusRot, COLORREF color, COLORREF alter);

void drawFlag (int x, int y, int stickHeight, const char* text, COLORREF fill, COLORREF border);

void drawTree (int x, int y, int trunkWidth, int trunkHeight, int leafRowNumber, int leafsize, COLORREF borderColor, COLORREF fillColor, HDC fruit);
void drawFruitRow (int x, int y, int leafNumber, int leafsize, HDC fruit);
void drawLeafRow (int x, int y, int leafNumber, int leafsize);
void drawLeafPart (int x, int y, int size);

int rainLoop = 0;

void drawRain (int columnsSpace, int tearsSpace, int tearsLenght, int animationFrame, int thickness, COLORREF color);
void drawTearsRow (int x, int y, int tearsLenght, int space, int offset);
void drawCloud (int x, int y, int width, int height, int everyAngle, int everyWidth, int everyHeight, COLORREF color);

void drawBaloon (int x, int y, int radius, int sizeOfStripe, COLORREF centerStripe, COLORREF secondStripe, COLORREF base, COLORREF border);
void drawMountain (int x, int y, int width, int height, int snowHeight, COLORREF ground, COLORREF snow, COLORREF border);
void drawPrintingEffect (int x, int y, const char* whatToPrint, int howMany, COLORREF color);
void printEffect (int x, int y, const char* text, int lenght, int delay);

// Scenery graphics & animations

int getTurtleWalkPosition (int rawPosition);

void drawScene (int cameraX, int cameraY);

void drawBaloonOnFirstScene (int baloonx, int baloony, int camx, int camy, int baloonsize);
void drawTurtlesOnFirstScene (int x, int y, int slide);
void drawEverythingWeather();
void slideClouds (int space, int y);

void prepareMountains (COLORREF skyUp, COLORREF skyDown, COLORREF grassUp, COLORREF grassDown);
void walkMountains (POINT* mountains, int elems, int manHeight);
void walkLine (int x, int y, int x2, int y2, int step, int size);
void electraSplash();

int logoPositionIdentifier = 0;
void drawLogo();

void drawASMFlag (int x, int y);

void lastTextEngineLoop (COLORREF color);
void setTextSpeed (int spd);
void selectFont (const char* name, int size, int bold);

// Scenery

void fromLogoToCPP();
void fromAssemblerAndUpToTheVeryEnd();

// Other variables

HDC sunnyBackground_1 = NULL,
    sunnyBackground_2 = NULL,
    sunnyBackground_3 = NULL,
    mountains_1       = NULL,
    mountains_2       = NULL,
    mountains_3       = NULL,
    trueSunny_up      = NULL;

HDC orange = NULL,
    pear   = NULL,
    apple  = NULL;

HDC shellForLeaderTurtle = NULL,
    shellForSecondTurtle = NULL,
    shellForKid          = NULL;

HDC leftCloudlySlide  = NULL,
    rightCloudlySlide = NULL;

int PASCAL_LOGO_WIDTH = 0;

const COLORREF
    SUNNYSKY_UP          = RGB (67 , 101, 255),
    SUNNYSKY_DOWN        = RGB (213, 213, 255),
    SUN_CENTER           = RGB (255, 255, 142),
    SUN_BORDER           = RGB (255, 255, 0  ),
    SUNNYGROUND_UP       = RGB (54 , 255, 78 ),
    SUNNYGROUND_DOWN     = RGB (91 , 188, 0  ),
    GREEN_LIGHT          = RGB (168, 230, 29 ),
    GREEN_MEDIUM         = RGB (157, 187, 97 ),
    GREEN_DARK           = RGB (37 , 177, 76 ),
    LIGHT_ORANGE         = RGB (229, 170, 122),
    TRUNK_MINIMUM        = RGB (250, 180, 150),
    TRUNK_MAXIMUM        = RGB (255, 255, 255),
    NORMAL_BROWN         = RGB (156, 90 , 60 ),
    CLEAR_RED            = RGB (255, 0  , 0  );

HDC scene[9][2] = {{0}};

int main()
    {
    const char* title  = "Programmer's Way - Путь Программиста";

    txCreateWindow (800, 600);
    SetWindowText (txWindow(), title);
    txBegin();

    printf ("\nStarting: %s...\n", title);
    Sleep (500);
    doSleep (0);

    calculateTables();
    doHDCPreparations();

    txSetFillColor (TX_BLACK);
    txClear();

    for (int i = 0; i < 50; i++) printf ("\n");
    txTextCursor (false);

    fromLogoToCPP();
    fromAssemblerAndUpToTheVeryEnd();

    txEnd();
    return 0;
    }

void doSleep (int time)
    {
    if (DELAY < 0)
        {
        double performance = txQueryPerformance();

        DELAY = performance * 2.5;
        SPEED = (int) (10/DELAY + 1.5);
        }

    double delay = (GetAsyncKeyState (VK_RIGHT)? 0 : DELAY);

    txSleep (time * delay);

    while (GetAsyncKeyState (VK_DOWN)) txSleep (10);

    if (GetAsyncKeyState (VK_LEFT)) MessageBox (txWindow(), "You need a time machine to do this    ", "Reality", MB_ICONEXCLAMATION);
    }

COLORREF mixColor (COLORREF first, COLORREF second, int percentage)
    {
    return RGB (txExtractColor (first, TX_RED)   + (txExtractColor (second, TX_RED)   - txExtractColor (first, TX_RED))   / 100 * percentage,
                txExtractColor (first, TX_GREEN) + (txExtractColor (second, TX_GREEN) - txExtractColor (first, TX_GREEN)) / 100 * percentage,
                txExtractColor (first, TX_BLUE)  + (txExtractColor (second, TX_BLUE)  - txExtractColor (first, TX_BLUE))  / 100 * percentage);
    }

int sqr (int a)
    {
    return a * a;
    }

void drawGradientLine (int x, int y, int x2, int y2, int thickness, COLORREF border, COLORREF center)
    {
    for (int n = thickness; n > 0; n--)
        {
        txSetColor (getTransparentColor (border, center, 100 / n), n);
        txLine (x, y, x2, y2);
        }
    }

void electraSplash()
    {
    txSetFillColor (TX_BLACK);
    txClear();

    drawElectra (0, 0, 126, 50, 20, 45, 5, TX_YELLOW, TX_WHITE, 50);
    doSleep (20);
    }

void slideClouds (int space, int y)
    {
    txTransparentBlt (txDC(), - (space / 2 + 400), y, 800, 600, leftCloudlySlide,  0, 0, TX_BLACK);
    txTransparentBlt (txDC(),    space / 2 + 400,  y, 800, 600, rightCloudlySlide, 0, 0, TX_BLACK);
    }

void drawStyledTurtleShell (int x, int y, int xStart, int yStart, int xFinal, int yFinal, int numberOfPies, int pieRadius, int offsetAngle, COLORREF color, COLORREF special, COLORREF border, int thickness)
    {
    int yChange = (xStart - xFinal) / numberOfPies;
    int xChange = (yStart - yFinal) / numberOfPies;

    for (int i = 0; i < numberOfPies; i++)
        drawPies (x, y, xStart-xChange*i, yStart-yChange*i, pieRadius, i*offsetAngle, color, special, border, thickness);

    txEllipse (x-xStart/xFinal, y-yStart/yFinal, x+xStart/xFinal, y+yStart/yFinal);
    }

void drawPortalSystem (int x, int y, int radius, int everyRadius, int vertexCount, int bonus, COLORREF color, COLORREF alter, COLORREF back)
    {
    drawGradientCircle (x, y, radius, color, back);

    int numberSign = 1;
    for (int r = radius; r > 0; r -= everyRadius)
        {
        drawPortal (x, y, r, 360 / vertexCount, numberSign * bonus, color, alter);
        numberSign = -numberSign;
        }
    }

void drawLogo()
    {
    logoPositionIdentifier += SPEED;

    int positionBonus = 0;
    if      (logoPositionIdentifier > 500) return;
    else if (logoPositionIdentifier > 300) positionBonus = 500 - logoPositionIdentifier;
    else if (logoPositionIdentifier > 200) positionBonus = 200;
    else                                   positionBonus = logoPositionIdentifier;

    positionBonus *= 4;

    txSetColor (TX_BLUE);
    txSelectFont ("Comic Sans MS", 80, 25, 1000);
    txTextOut (-100 - txGetTextExtentX ("Programmer's Way") + positionBonus, 100, "Programmer's Way");
    txTextOut (900 - positionBonus, 200, "Путь Программиста");
    }

struct Lightning
    {
    int x, y;
    int angle;
    int state;
    COLORREF color;
    };

Lightning lightnings[5] = {{0}};

void lightningEngineLoop()
    {
    for (int i = 0; i < 5; i++)
        {
        if (lightnings[i].state > 0)
            {
            lightnings[i].state--;
            drawElectra (lightnings[i].x, lightnings[i].y, lightnings[i].angle, getRandom (7, 15), getRandom (10, 20), 60, 4, lightnings[i].color, TX_WHITE, 30);
            }
        else if (getRandom (1, 200) == 1)
            {
            Lightning random = { getRandom ( 50, 750),
                                 getRandom (  0, 150),
                                 getRandom (135, 225),
                                 getRandom (  2,  10),
                                 getRandom (  1,   2) == 1? TX_YELLOW : TX_CYAN };

            lightnings[i] = random;
            }
        }
    }

int getRandom (int min, int max)
    {
    return min + rand() % (max - min + 1);
    }

RECT convert (int cameraX, int cameraY, RECT object)
    {
    RECT result = { object.left   - cameraX,
                    object.top    - cameraY,
                    object.right  - cameraX,
                    object.bottom - cameraY };

    return result;
    }

bool in (RECT in, POINT toCheck)
    {
    return toCheck.x >= in.left  &&
           toCheck.x <= in.right &&
           toCheck.y >= in.top   &&
           toCheck.y <= in.bottom;
    }

bool needToDraw (RECT what)
    {
    RECT screen = {0, 0, 800, 600};

    POINT topLeft     = { what.left,  what.top    },
          topRight    = { what.right, what.top    },
          bottomRight = { what.right, what.bottom },
          bottomLeft  = { what.left,  what.bottom };

    return in (screen, topLeft)     |
           in (screen, bottomRight) |
           in (screen, topRight)    |
           in (screen, bottomLeft);
    }

void drawScene (int cameraX, int cameraY)
    {
    txBitBlt (txDC(),     - (cameraX % 800),     - (cameraY % 600), 800, 600, scene[cameraX / 800]    [cameraY / 600],     0, 0);
    txBitBlt (txDC(), 800 - (cameraX % 800),     - (cameraY % 600), 800, 600, scene[cameraX / 800 + 1][cameraY / 600],     0, 0);
    txBitBlt (txDC(),     - (cameraX % 800), 600 - (cameraY % 600), 800, 600, scene[cameraX / 800]    [cameraY / 600 + 1], 0, 0);
    txBitBlt (txDC(), 800 - (cameraX % 800), 600 - (cameraY % 600), 800, 600, scene[cameraX / 800 + 1][cameraY / 600 + 1], 0, 0);
    }

int getTurtleWalkPosition (int rawPosition)
    {
    if (rawPosition > 20) return 40 - rawPosition;
    else                  return      rawPosition;
    }

void drawFlag (int x, int y, int stickHeight, const char* text, COLORREF fill, COLORREF border)
    {
    txSelectFont ("Comic Sans MS", 20);

    int width  = txGetTextExtentX (text) + 20,
        height = txGetTextExtentY (text) + 10;

    txSetColor (border);
    txSetFillColor (fill);
    txLine      (x, y, x, y-stickHeight);
    txRectangle (      x, y-stickHeight, x+width, y-stickHeight+height);

    txSetColor (TX_YELLOW);
    txTextOut (x+10, y-stickHeight+5, text);
    }

void drawBaloonOnFirstScene (int baloonx, int baloony, int camx, int camy, int baloonSize)
    {
    RECT baloon = { baloonx - baloonSize,
                    baloony - baloonSize * 2,
                    baloonx + baloonSize,
                    baloony + baloonSize * 2 };

    baloon = convert (camx, camy, baloon);

    if (needToDraw (baloon))
        {
        drawBaloon (baloon.left + (baloon.right-baloon.left)/2,
                    baloon.top + (baloon.bottom-baloon.top)/2,
                    baloonSize, 20, CLEAR_RED, SUN_BORDER, TX_YELLOW, NORMAL_BROWN);

        txSetColor (TX_GREEN);
        txSelectFont ("Comic Sans MS", 60);
        txTextOut (baloonx - camx- PASCAL_LOGO_WIDTH / 2, baloony - camy - 25, "Pascal");
        }
    }

void drawTurtlesOnFirstScene (int x, int y, int slide)
    {
    int walkPosition = getTurtleWalkPosition (slide % 40);

    drawTurtleBody (x,       y,      250, 125, walkPosition, TX_GREEN, GREEN_DARK, TX_YELLOW, TX_BROWN, shellForLeaderTurtle);
    drawTurtleBody (x - 200, y + 50, 160,  80, walkPosition, TX_GREEN, GREEN_DARK, TX_YELLOW, TX_BROWN, shellForSecondTurtle);
    drawTurtleBody (x - 300, y + 90,  80,  40, walkPosition, TX_GREEN, GREEN_DARK, TX_YELLOW, TX_BROWN, shellForKid);

    drawFlag (x + 158, y + 14 + walkPosition / 3, 175, "ЛогоМиры", CLEAR_RED, TX_GREEN);

    drawLogo();
    }

void drawEverythingWeather()
    {
    drawRain (30, 20, 30, rainLoop % 10 * 5, 1, TX_BLUE);
    slideClouds (-167, -72);
    lightningEngineLoop();

    rainLoop++;
    }

COLORREF getTransparentColor (COLORREF toSet, COLORREF back, int alpha)
    {
    // Red-back, green-back, blue-back
    int r  = txExtractColor (toSet, TX_RED  ), rb = txExtractColor (back, TX_RED  ),
        g  = txExtractColor (toSet, TX_GREEN), gb = txExtractColor (back, TX_GREEN),
        b  = txExtractColor (toSet, TX_BLUE ), bb = txExtractColor (back, TX_BLUE );

    return RGB (r + (rb - r) / 100 * alpha,
                g + (gb - g) / 100 * alpha,
                b + (bb - b) / 100 * alpha);
    }

void drawElectra (int x, int y, int angle, int nOfSteps, int stepLenght, int randomness, int thickness, COLORREF center, COLORREF border, int chance)
    {
    txSetColor (center, thickness);

    int currentX = x,
        currentY = y;

    for (int a = 0; a < nOfSteps; a++)
        {
        int normalAngle = trigonometricGetNormalAngle (getRandom ((angle - randomness) / 5, (angle + randomness) / 5) * 5),
            lenght = getRandom (stepLenght * 4/5, stepLenght);

        int nextX = (int) (currentX + sinTable[normalAngle] * lenght),
            nextY = (int) (currentY + cosTable[normalAngle] * lenght);

        drawGradientLine (nextX, nextY, currentX, currentY, thickness, border, center);

        currentX = nextX;
        currentY = nextY;

        if (getRandom (1,100) < chance)
            drawElectra (currentX, currentY, angle + getRandom (0, 180) - 90, nOfSteps / 2, stepLenght / 2, randomness / 2, thickness * 2/3, center, border, chance / 3);
        }
    }

void prepareMountains (COLORREF skyUp, COLORREF skyDown, COLORREF grassUp, COLORREF grassDown)
    {
    txSetFillColor (TX_BLACK);
    txClear();

    drawGradientRectangle (0,   0, 800, 200, skyUp,   skyDown);
    drawGradientRectangle (0, 200, 800, 600, grassUp, grassDown);

    drawMountain (300, 600, 700, 460, 200, TX_ORANGE, RGB (220,220,255), TX_GRAY);
    drawMountain (100, 600, 700, 460, 200, TX_ORANGE, RGB (220,220,255), TX_GRAY);
    drawMountain (700, 600, 500, 550, 200, TX_ORANGE, RGB (220,220,255), TX_GRAY);
    drawMountain (500, 600, 500, 570, 200, TX_ORANGE, RGB (220,220,255), TX_GRAY);

    txDeleteDC (mountains_1);

    mountains_1 = txCreateCompatibleDC (800, 600);
    txBitBlt (mountains_1, 0, 0, 800, 600, txDC(), 0, 0);

    scene[3][1] = mountains_1;
    scene[4][1] = mountains_1;
    scene[5][1] = mountains_1;
    }

void walkLine (int x, int y, int x2, int y2, int step, int manSize)
    {
    int lineAngle  = trigonometricGetAngleOfLine (x, y, x2, y2),
        lineLenght = (int) (sqrt (1.0*sqr (x2-x) + 1.0*sqr (y2-y))),
        stepNumber = lineLenght/step;

    int cameraX, cameraY;
    int bodyRotNormal = 90 - (lineAngle > 90 ? 90 : lineAngle);

    for (int stepIndex = 0; stepIndex < stepNumber; stepIndex += SPEED)
        {
        trigonometricSetPointOfRest (x, y);
        trigonometricMove (lineAngle, stepIndex * step);
        trigonometricMove (lineAngle - 90, manSize * 7/20);

        cameraX = pointOfRest_x - 400;
        cameraY = pointOfRest_y - 300;

        int handsAngle = stepIndex * step % 40;
        if (handsAngle > 20) handsAngle = 40 - handsAngle;

        drawScene (cameraX, cameraY);

        drawStickMan (400, 300, manSize, 90, 10, stepIndex * step % 90, 180 - handsAngle, 180 - handsAngle, 180 + handsAngle, 180 + handsAngle, 90, 90, TX_BLACK, NORMAL_BROWN, TX_WHITE, TX_WHITE, lineAngle - 90, bodyRotNormal);
        drawBaloonOnFirstScene (3100, 400, cameraX, cameraY, 150);
        drawFlag (3700 - cameraX, 633 - cameraY, 150, "C++", RGB (111, 49, 152), TX_YELLOW);
        drawEverythingWeather();

        doSleep (4);
        }
    }

void walkMountains (POINT* mountains, int elems, int manHeight)
    {
    for (int mountainIndex = 0; mountainIndex < elems-1; mountainIndex++)
        {
        walkLine (mountains[mountainIndex    ].x,
                  mountains[mountainIndex    ].y,
                  mountains[mountainIndex + 1].x,
                  mountains[mountainIndex + 1].y,
                  1, manHeight);

        electraSplash();
        }
    }

void fromLogoToCPP()
    {
    int cameraX = 0,
        cameraY = 600,
        t       = 0;

    for (; cameraX < 1600; cameraX += SPEED, doSleep (2))
        {
        drawScene (cameraX, cameraY);
        drawTurtlesOnFirstScene (350 - cameraX / 5, 1050 - cameraY, cameraX);
        drawStickMan (480 - cameraX / 5, 375 + 48, 120, 90, 10, 0, 185, 185, 148, 45, 60, 45, TX_BLACK, NORMAL_BROWN, TX_WHITE, TX_WHITE, 0, 0);
        drawBaloonOnFirstScene (2000, 700, cameraX, cameraY, 150);
        }

    for (t = 0; t < 40; t += SPEED, doSleep (10))
        {
        drawScene (cameraX, cameraY);
        drawTurtlesOnFirstScene (350 - cameraX / 5, 1050 - cameraY, cameraX);
        drawStickMan (480 - cameraX / 5 + t*6, 375 - t*2 + 48, 120, 30, 10, t * 3 % 90, 185, 185, 90 + t * 2, 90 + t * 2, 60, 90, TX_BLACK, NORMAL_BROWN, TX_WHITE, TX_WHITE, 0, 0);
        drawBaloonOnFirstScene (2000, 700, cameraX, cameraY, 150);
        }

    for (t = 0; t < 200; t += SPEED, doSleep (5))
        {
        txBitBlt (txDC(), 0, t - 600, 800, 600, trueSunny_up, 0, 0);
        drawScene (cameraX + t / 2, cameraY-t);
        drawTurtlesOnFirstScene (350 - cameraX / 5, 1050 - cameraY, cameraX);
        drawStickMan (400, 285 + 48 + t/25, 120 + t/10, 30, 10, 0, 185, 185, 170, 170, 60, 90, TX_BLACK, NORMAL_BROWN, TX_WHITE, TX_WHITE, 0, 0);
        drawBaloonOnFirstScene (2000 + t, 700 - t*2, cameraX, cameraY, 150);

        cameraY -= 2 * SPEED;
        cameraX += SPEED;
        }

    cameraX += t/2;
    cameraY -= t;

    double vel = 0.1;

    for (t = 0; t < 430; t += SPEED, doSleep (5))
        {
        drawScene (cameraX, cameraY);
        drawStickMan (400, 285+56, 140, 30, 10, 0, 185, 185, 170, 170, 60, 90, TX_BLACK, NORMAL_BROWN, TX_WHITE, TX_WHITE, 0, 0);
        drawBaloonOnFirstScene (cameraX + 400, cameraY + 100, cameraX, cameraY, 150);
        slideClouds (800 - t * 9/4, -t / 6);

        cameraX = (int) (cameraX + vel * 2 * SPEED);
        cameraY = (int) (cameraY + vel     * SPEED);
        vel    += 0.005                    * SPEED;
        }

    cameraX = 2700;
    cameraY = 300;

    prepareMountains (TX_DARKGRAY, TX_LIGHTGRAY, TX_GREEN, TX_LIGHTGREEN);

    txClear();
    drawGradientRectangle (0, 0, 800, 600, TX_BLACK, TX_DARKGRAY);

    txDeleteDC (trueSunny_up);
    trueSunny_up = txCreateCompatibleDC (800, 600);
    txBitBlt (trueSunny_up, 0, 0, 800, 600, txDC(), 0, 0);

    txSleep (300);

    for (int x = 0; x < 8; x++) scene[x][0] = trueSunny_up;

    POINT path[10] = {{ 3100, 651 },
                      { 3181, 821 },
                      { 3233, 827 },
                      { 3301, 740 },
                      { 3377, 840 },
                      { 3427, 840 },
                      { 3500, 740 },
                      { 3568, 829 },
                      { 3619, 813 },
                      { 3700, 633 }};

    walkMountains (path, 10, 140);

    txSleep (200);

    cameraX = 3300;
    cameraY = 277;

    for (t = 0; t < 180; t += 5, doSleep (15))
        {
        drawScene (cameraX, cameraY);
        drawFlag (400, 356, 150, "C++", RGB (111, 49, 152), TX_YELLOW);

        drawPortalSystem (400, 286, ((t > 90)? 180 - t     : t), 9, 8, t * 5, TX_WHITE, TX_WHITE, TX_GRAY);
        drawStickMan     (400, 300, ((t > 90)? 230 - t*6/5 : 30), 30, 10 - t/18, 45, 185, 185, 165, 165, 60, 90, TX_BLACK, NORMAL_BROWN, TX_WHITE, TX_WHITE, 0, 0);

        drawEverythingWeather();
        }

    for (; t < 200; t += 1, doSleep (20))
        drawRain (15, 15, 30, t % 10, 1, getRandom (1, 2) == 1 ? TX_BLUE : TX_LIGHTBLUE);

    txSleep (200);

    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, 800, 600);

    deleteDCs();
    }

void drawPies (int x, int y, int xSize, int ySize, int pieAngle, int angleOffset, COLORREF color, COLORREF special, COLORREF border, int thickness)
    {
    txSetFillColor (color);
    txSetColor (border, thickness);

    for (int n = 0; n < (360 / pieAngle); n++)
        {
        txSetFillColor ((n % 2 == 0)? color : special);
        txPie (x - xSize/2, y - ySize/2, x + xSize/2, y + ySize/2, n * pieAngle + angleOffset, pieAngle);
        }
    }

void deleteDCs()
    {
    txDeleteDC (sunnyBackground_1);
    txDeleteDC (sunnyBackground_2);
    txDeleteDC (sunnyBackground_3);

    txDeleteDC (pear);
    txDeleteDC (apple);
    txDeleteDC (orange);

    txDeleteDC (shellForLeaderTurtle);
    txDeleteDC (shellForSecondTurtle);
    txDeleteDC (shellForKid);
    }

void doHDCPreparations()
    {
    // ==================================================

    drawGradientCircle (15,15,10, LIGHT_ORANGE, TX_ORANGE);

    orange = txCreateCompatibleDC (30,30);
    txBitBlt (orange, 0, 0, 30, 30, txDC(), 0, 0);

    txSetColor (TX_TRANSPARENT);
    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, 100, 100);

    // ==================================================

    txSetFillColor (SUN_BORDER);
    txCircle (15, 15, 10);
    txCircle (15, 7, 6);

    pear = txCreateCompatibleDC (30,30);
    txBitBlt (pear, 0, 0, 30, 30, txDC(), 0, 0);

    // ==================================================

    txSetColor (TX_TRANSPARENT);
    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, 100, 100);

    txSetFillColor (TX_GREEN);
    txCircle (15, 15, 10);
    drawGradientCircle (12, 12, 5, TX_LIGHTGREEN, TX_GREEN);

    apple = txCreateCompatibleDC (30, 30);
    txBitBlt (apple, 0, 0, 30, 30, txDC(), 0, 0);

    // ==================================================

    drawGradientRectangle (0,0,800,200, SUNNYSKY_UP, SUNNYSKY_DOWN);
    drawGradientRectangle (0,200,800,600, SUNNYGROUND_UP, SUNNYGROUND_DOWN);
    drawTree (400, 300, 35, 55, 3, 15, TX_RED, TX_ORANGE, apple);
    drawTree (200, 200, 50, 70, 4, 12, TX_ORANGE, LIGHT_ORANGE, orange);
    drawTree (250, 450, 50, 100, 4, 16, TX_ORANGE, LIGHT_ORANGE, pear);
    drawTree (700, 200, 60, 40, 1, 25, TX_BROWN, LIGHT_ORANGE, apple);
    drawTree (600, 440, 35, 40, 2, 20, TX_BROWN, LIGHT_ORANGE, pear);

    sunnyBackground_1 = txCreateCompatibleDC (800, 600);
    txBitBlt (sunnyBackground_1, 0, 0, 800, 600, txDC(), 0, 0);

    // ==================================================

    drawGradientRectangle (0, 0, 800, 200, SUNNYSKY_UP, SUNNYSKY_DOWN);
    drawGradientRectangle (0, 200, 800, 600, SUNNYGROUND_UP, SUNNYGROUND_DOWN);
    drawTree (150, 200, 30, 80, 3, 17, TX_RED, TX_ORANGE, apple);
    drawTree (350, 450, 30, 60, 4, 15, TX_BROWN, TX_ORANGE, pear);
    drawTree (450, 190, 20, 50, 4, 12, TX_RED, NORMAL_BROWN, apple);
    drawTree (650, 350, 20, 50, 3, 15, TX_RED, NORMAL_BROWN, orange);

    sunnyBackground_2 = txCreateCompatibleDC (800, 600);
    txBitBlt (sunnyBackground_2, 0, 0, 800, 600, txDC(), 0, 0);

    // ==================================================

    drawGradientRectangle (0, 0, 800, 200, SUNNYSKY_UP, SUNNYSKY_DOWN);
    drawGradientRectangle (0, 200, 800, 600, SUNNYGROUND_UP, SUNNYGROUND_DOWN);
    drawTree (150, 250, 30, 80, 4, 13, TX_RED, TX_ORANGE, orange);
    drawTree (350, 450, 30, 60, 3, 18, TX_BROWN, TX_ORANGE, apple);
    drawTree (450, 200, 20, 50, 3, 15, TX_RED, NORMAL_BROWN, pear);

    drawMountain (700, 600, 500, 550, 200, TX_ORANGE, RGB (220,220,255), TX_GRAY);

    sunnyBackground_3 = txCreateCompatibleDC (800, 600);
    txBitBlt (sunnyBackground_3, 0, 0, 800, 600, txDC(), 0, 0);

    // ==================================================

    prepareMountains (SUNNYSKY_UP, SUNNYSKY_DOWN, SUNNYGROUND_UP, SUNNYGROUND_DOWN);

    txClear();

    // ==================================================

    drawGradientRectangle (0,0,800,600, TX_BLUE, SUNNYSKY_UP);

    trueSunny_up = txCreateCompatibleDC (800, 600);
    txBitBlt (trueSunny_up, 0, 0, 800, 600, txDC(), 0, 0);

    shellForLeaderTurtle = txCreateCompatibleDC (250, 125);
    prepareTurtleShell (250, 125, LIGHT_ORANGE, NORMAL_BROWN, TX_YELLOW, 2);
    txTransparentBlt (shellForLeaderTurtle, 0, 0, 250, 125, txDC(), 0, 62);

    shellForSecondTurtle = txCreateCompatibleDC (160, 80);
    prepareTurtleShell (160, 80, GREEN_MEDIUM, TX_CYAN, TX_BLUE, 2);
    txTransparentBlt (shellForSecondTurtle, 0, 0, 160, 80, txDC(), 0, 40);

    shellForKid = txCreateCompatibleDC (80, 40);
    prepareTurtleShell (80, 40, TX_RED, TX_LIGHTRED, NORMAL_BROWN, 1);
    txTransparentBlt (shellForKid, 0, 0, 80, 40, txDC(), 0, 20);

    txSelectFont ("Comic Sans MS", 60);
    PASCAL_LOGO_WIDTH = txGetTextExtentX ("Pascal");

    // ==================================================

    txSetFillColor (TX_BLACK);
    txClear();

    leftCloudlySlide = txCreateCompatibleDC (800, 600);
    drawCloud (600, 100, 200, 100, 40, 80, 40, TX_GRAY);
    drawCloud (550, 50, 200, 100, 40, 80, 40, TX_LIGHTGRAY);
    drawCloud (650, 75, 200, 100, 40, 80, 40, TX_DARKGRAY);
    drawCloud (605, 200, 200, 100, 40, 80, 40, TX_LIGHTGRAY);
    drawCloud (450, 120, 200, 100, 40, 80, 40, TX_GRAY);
    drawCloud (380, 175, 200, 100, 40, 80, 40, TX_DARKGRAY);
    drawCloud (380, 25, 200, 100, 40, 80, 40, TX_DARKGRAY);
    drawCloud (300, 125, 200, 100, 40, 80, 40, TX_LIGHTGRAY);
    txBitBlt (leftCloudlySlide, 0, 0, 800, 600, txDC(), 0, 0);

    txSetFillColor (TX_BLACK);
    txClear();

    rightCloudlySlide = txCreateCompatibleDC (800, 600);
    drawCloud (370, 100, 200, 100, 40, 80, 40, TX_LIGHTGRAY);
    drawCloud (320, 50 , 200, 100, 40, 80, 40, TX_DARKGRAY);
    drawCloud (420, 75 , 200, 100, 40, 80, 40, TX_GRAY);
    drawCloud (375, 200, 200, 100, 40, 80, 40, TX_DARKGRAY);
    drawCloud (220, 120, 200, 100, 40, 80, 40, TX_LIGHTGRAY);
    drawCloud (150, 175, 200, 100, 40, 80, 40, TX_GRAY);
    drawCloud (150, 25 , 200, 100, 40, 80, 40, TX_GRAY);
    drawCloud (500, 25 , 200, 100, 40, 80, 40, TX_LIGHTGRAY);
    drawCloud (500, 175, 200, 100, 40, 80, 40, TX_LIGHTGRAY);
    txBitBlt (rightCloudlySlide, 0, 0, 800, 600, txDC(), 0, 0);

    // ==================================================

    for (int x = 0; x < 7; x++) scene[x][0] = trueSunny_up;

    scene[0][1] = sunnyBackground_1;
    scene[1][1] = sunnyBackground_2;
    scene[2][1] = sunnyBackground_3;
    scene[4][1] = mountains_1;
    scene[5][1] = sunnyBackground_3;
    scene[6][1] = sunnyBackground_3;
    }

void drawGradientRectangle (int x, int y, int x2, int y2, COLORREF topColor, COLORREF downColor)
    {
    int height = y2 - y;

    double currentRed   = txExtractColor (topColor, TX_RED),
           currentGreen = txExtractColor (topColor, TX_GREEN),
           currentBlue  = txExtractColor (topColor, TX_BLUE);

    double redChange    = (txExtractColor (downColor, TX_RED  ) - currentRed  ) / height,
           greenChange  = (txExtractColor (downColor, TX_GREEN) - currentGreen) / height,
           blueChange   = (txExtractColor (downColor, TX_BLUE ) - currentBlue ) / height;

    for (int yPos = y; yPos < y2; yPos++)
        {
        txSetColor (RGB (currentRed, currentGreen, currentBlue));
        txLine (x, yPos, x2, yPos);

        currentRed   += redChange;
        currentGreen += greenChange;
        currentBlue  += blueChange;
        }
    }

void drawGradientCircle (int x, int y, int radius, COLORREF centerColor, COLORREF borderColor)
    {
    if (radius == 0) radius = 1;

    double currentRed   = txExtractColor (borderColor, TX_RED),
           currentGreen = txExtractColor (borderColor, TX_GREEN),
           currentBlue  = txExtractColor (borderColor, TX_BLUE);

    double redChange    = (txExtractColor (centerColor, TX_RED  ) - currentRed  ) / radius,
           greenChange  = (txExtractColor (centerColor, TX_GREEN) - currentGreen) / radius,
           blueChange   = (txExtractColor (centerColor, TX_BLUE ) - currentBlue ) / radius;

    for (int r = 0; r <= radius; r++)
        {
        txSetFillColor (RGB (currentRed, currentGreen, currentBlue));
        txSetColor     (RGB (currentRed, currentGreen, currentBlue));

        txCircle (x, y, radius-r);

        currentRed   += redChange;
        currentGreen += greenChange;
        currentBlue  += blueChange;
        }
    }

void drawStripedCircle (int x, int y, int stripeRadius, int numberOfPairs, COLORREF fisrtStripe, COLORREF secondStripe)
    {
    int maxRadius = stripeRadius * numberOfPairs * 2;

    for (int n = 0; n < numberOfPairs; n++)
        {
        txSetFillColor (secondStripe);
        txCircle (x,y,maxRadius-n*stripeRadius*2);

        txSetFillColor (fisrtStripe);
        txCircle (x,y,maxRadius-n*stripeRadius*2-stripeRadius);
        }
    }

void drawLeafPart (int x, int y, int size)
    {
    txSetColor (TX_TRANSPARENT);

    txSetFillColor (GREEN_DARK);
    txCircle (x-0.3*size, y+0.7*size, size);

    txSetFillColor (GREEN_MEDIUM);
    txCircle (x-0.5*size, y-0.5*size, size);

    txSetFillColor (GREEN_LIGHT);
    txCircle (x+0.7*size, y-0.3*size, size);
    }

void drawLeafRow (int x, int y, int leafNumber, int leafSize)
    {
    int space     =  leafSize * 2/3;
    int totalSize = (leafSize * 2) * leafNumber + space * leafNumber;

    for (int i = 0; i < leafNumber; i++)
        drawLeafPart (x - totalSize / 2 + i * (leafSize * 2 + space) + leafSize * 3/2, y, leafSize);
    }

void drawFruitRow (int x, int y, int leafNumber, int leafsize, HDC fruit)
    {
    int space     =  leafsize * 2/3;
    int totalsize = (leafsize * 2) * leafNumber + space * leafNumber;

    for (int i = 0; i < leafNumber-1; i++)
        txTransparentBlt (txDC(), x - totalsize/2 + i * (leafsize*2 + space) + leafsize*1.8, y-15, 30, 30, fruit, 0, 0, TX_BLACK);
    }

void drawTree (int x, int y, int trunkWidth, int trunkHeight, int leafRowNumber, int leafSize, COLORREF borderColor, COLORREF fillColor, HDC fruit)
    {
    int circleDiameter = (int) (sqrt (2.0 * trunkWidth * trunkWidth) + 1.5);

    txSetFillColor (fillColor);

    txSetColor (borderColor, 2);
    txArc (x - circleDiameter / 2, y + trunkHeight - (circleDiameter + trunkWidth) / 2,
           x + circleDiameter / 2, y + trunkHeight + (circleDiameter - trunkWidth) / 2, 225, 90);

    txSetColor (TX_TRANSPARENT);
    txPie (x - circleDiameter / 2, y + trunkHeight - (circleDiameter + trunkWidth) / 2,
           x + circleDiameter / 2, y + trunkHeight + (circleDiameter - trunkWidth) / 2, 225, 90);

    POINT treePolygon[5] = {{ x - trunkWidth / 4, y               },
                            { x + trunkWidth / 4, y               },
                            { x + trunkWidth / 2, y + trunkHeight },
                            { x - trunkWidth / 2, y + trunkHeight },
                            { x - trunkWidth / 4, y               }};

    txPolygon (treePolygon, 5);

    txSetColor (borderColor, 2);
    txLine (x - trunkWidth / 4, y, x - trunkWidth / 2, y + trunkHeight);
    txLine (x + trunkWidth / 4, y, x + trunkWidth / 2, y + trunkHeight);

    txSetFillColor (fillColor);

    drawLeafRow (x, y, leafRowNumber, leafSize);

    int i = 0;
    for (i = 0; i < leafRowNumber; i++)
        drawLeafRow (x, y - leafSize *7/4 * (i+1), leafRowNumber + 1, leafSize);

    for (i = leafRowNumber; i >= 0; i--)
        drawLeafRow (x, y - leafSize *7/4 * (leafRowNumber*2 - i), i+1, leafSize);

    drawFruitRow (x, y, leafRowNumber, leafSize, fruit);

    for (i = 0; i < leafRowNumber; i++)
        drawFruitRow (x, y - leafSize *7/4 * (i+1), leafRowNumber + 1, leafSize, fruit);

    for (i = leafRowNumber; i >= 0; i--)
        drawFruitRow (x, y - leafSize *7/4 * (leafRowNumber*2 - i), i+1, leafSize, fruit);
    }

void prepareTurtleShell (int width, int height, COLORREF baseColor, COLORREF specials, COLORREF border, int thickness)
    {
    txSetColor (TX_TRANSPARENT);
    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, width, height);

    txSetFillColor (TX_WHITE);
    txEllipse (0, 0, width, height * 2);

    HDC mask = txCreateCompatibleDC (width, height);
    txBitBlt (mask, 0, 0, width, height, txDC(), 0, 0);

    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, width, height * 2);
    txSetFillColor (TX_WHITE);
    txEllipse (0, 0, width, height);

    HDC mask_down = txCreateCompatibleDC (width, height);
    txBitBlt (mask_down, 0, 0, width, height, txDC(), 0, 0);

    txSetFillColor (TX_BLACK);
    txRectangle (0, 0, width, height*2);

    drawStyledTurtleShell (width/2, height/2, height *5/2, width, height/5, width/10,
                           7, 20, width/25, baseColor, specials, border, thickness);

    txTransparentBlt (txDC(), 0, height/2, width, height, mask,      0, 0, TX_WHITE);
    txTransparentBlt (txDC(), 0, height/2, width, height, mask_down, 0, 0, TX_WHITE);

    txDeleteDC (mask);
    txDeleteDC (mask_down);
    }


void drawTurtleBody (int x, int y, int width, int height, int walkingPos, COLORREF body, COLORREF border, COLORREF eye, COLORREF eyeBorder, HDC shell)
    {
    txSetFillColor (body);
    txSetColor (border, 2);

    POINT polygon[5] = {{ x + width *7/8, y + height *7/8                },
                        { x + width,      y + height *7/8                },
                        { x + width *6/5, y + height *1/5 + walkingPos/2 },
                        { x + width,      y + height *1/5 + walkingPos/2 },
                        { x + width *7/8, y + height *7/8                }};

    txPolygon (polygon, 5);

    txEllipse (x - walkingPos/3, y + height *3/4, x + width, y + height);
    txEllipse (x + width, y + walkingPos/2, x + width*1.3, y + height*0.4 + walkingPos/2);

    txSetColor (TX_TRANSPARENT);
    txPolygon (polygon, 5);

    txSetFillColor (eye);
    txSetColor (eyeBorder);
    txEllipse (x + width * 1.1, y + height * 0.05 + walkingPos/2 + walkingPos/5,
               x + width * 1.2, y + height * 0.3  + walkingPos/2 - walkingPos/3);

    txSetFillColor (eyeBorder);
    txCircle (x + width * 1.15, y + height * 0.15 + walkingPos / 2, 2);

    txSetFillColor (body);
    txSetColor (border, 2);
    txCircle (x + width * 0.9 - walkingPos, y + height, width / 16);
    txCircle (x + width * 0.8 + walkingPos, y + height, width / 16);
    txCircle (x + width * 0.3 - walkingPos, y + height, width / 16);
    txCircle (x + width * 0.2 + walkingPos, y + height, width / 16);

    txTransparentBlt (txDC(), x + width/20, y + height/10 + walkingPos/3, width-1, height,
                      shell, 0, 0, TX_BLACK);
    }


void drawTurtle (int x, int y, int width, int height, COLORREF shellColor, COLORREF stripesColor)
    {
    txSetColor (stripesColor, 1);
    txSetFillColor (shellColor);
    txPie (x - width / 2, y - height, x + width / 2, y + height, 0, 180);

    txSetColor (TX_TRANSPARENT);
    txSetFillColor (stripesColor);

    txEllipse (x - width * 4 / 22, y - height * 17/22, x + width * 4/22, y - height*5/22);
    txEllipse (x - width * 2 / 22, y - height * 4/22, x + width * 2/22, y);
    txEllipse (x - width * 2 / 22, y - height, x + width * 2/22, y - height*18/22);
    txEllipse (x - width * 4 / 22, y - height * 17/22, x + width*4/22, y - height * 5/22);
    }

void drawBaloon (int x, int y, int radius, int sizeOfStripe, COLORREF centerStripe, COLORREF secondStripe, COLORREF base, COLORREF border)
    {
    txSetColor (border, 1);
    txSetFillColor (base);

    POINT baseFigure[5] = {{ x - radius / 2  , y + radius * 3/2 },
                           { x + radius / 2  , y + radius * 3/2 },
                           { x + radius * 2/5, y + radius * 2   },
                           { x - radius * 2/5, y + radius * 2   },
                           { x - radius / 2  , y + radius * 3/2 }};

    txPolygon (baseFigure, 5);

    int number = 0;
    for (number = 0; number < radius / sizeOfStripe; number++)
        {
        txSetColor (border, 1);
        txLine (x - radius + number * sizeOfStripe,     y, x - radius/2 + number * sizeOfStripe / 2, y + radius * 1.5);
        txLine (x + radius - number * sizeOfStripe - 1, y, x + radius/2 - number * sizeOfStripe / 2, y + radius * 1.5);

        txSetColor (TX_BLACK, 1);
        txSetFillColor ((number % 2 == 0)? centerStripe : secondStripe);

        txEllipse (x - radius + number * sizeOfStripe, y - radius, x + radius - number * sizeOfStripe, y + radius);
        }

    txSetFillColor ((number % 2 == 0)? centerStripe : secondStripe);
    txEllipse (x - sizeOfStripe / 2, y - radius, x + sizeOfStripe / 2, y + radius);

    txSetColor (border);
    txLine (x, y + radius, x, y + radius * 1.5);
    }

void calculateTables()
    {
    for (int x = 0; x < 360; x++)
        {
        sinTable[x] = sin (x * txPI / 180);
        cosTable[x] = cos (x * txPI / 180);
        }
    }

void trigonometricSetPointOfRest (int x, int y)
    {
    pointOfRest_x = x;
    pointOfRest_y = y;
    }

int trigonometricGetNormalAngle (int ang)
    {
    int angle = ang;

    while (angle <   0) angle += 360;
    while (angle > 360) angle -= 360;

    return (angle <= 180)? 180 - angle : 540 - angle;
    }

void trigonometricDrawLine (int angle, int lenght)
    {
    int ang = trigonometricGetNormalAngle (angle);
    int endx = (int) (pointOfRest_x + sinTable[ang] * lenght);
    int endy = (int) (pointOfRest_y + cosTable[ang] * lenght);

    txLine (pointOfRest_x, pointOfRest_y, endx, endy);

    pointOfRest_x = endx;
    pointOfRest_y = endy;
    }

void trigonometricDrawLineAndReturn (int angle, int lenght)
    {
    int ang = trigonometricGetNormalAngle (angle);
    int endx = (int) (pointOfRest_x + sinTable[ang] * lenght);
    int endy = (int) (pointOfRest_y + cosTable[ang] * lenght);

    txLine (pointOfRest_x, pointOfRest_y, endx, endy);
    }

void trigonometricMove (int angle, int lenght)
    {
    int ang = trigonometricGetNormalAngle (angle);

    pointOfRest_x = (int) (pointOfRest_x + sinTable[ang] * lenght);
    pointOfRest_y = (int) (pointOfRest_y + cosTable[ang] * lenght);
    }

int trigonometricGetAngleOfLine (int x, int y, int x2, int y2)
    {
    return (int) (180 - (atan2 (1.0 * (x2 - x), 1.0 * (y2 - y)) * 180 / txPI));
    }

void drawStickMan (int x, int y, int height, int hairIntensivity, int hairLenght, int walkingPosition,
                   int leftBase, int leftSpecial, int rightBase, int rightSpecial, int direction, int walkingAngle,
                   COLORREF bodyColor, COLORREF hairColor, COLORREF headColor, COLORREF eyeColor, int rotation, int bodyRot)
    {
    txSetColor     (bodyColor);
    txSetFillColor (headColor);

    trigonometricSetPointOfRest (x, y);
    trigonometricDrawLine (180 - walkingAngle / 2 + walkingPosition + rotation, height *2/5);
    trigonometricDrawLine ( 90 - walkingAngle / 2 + walkingPosition + rotation, height /20);

    int angleBetweenLegs = walkingPosition;
    if (angleBetweenLegs > walkingAngle / 2) angleBetweenLegs = walkingAngle - angleBetweenLegs;

    trigonometricSetPointOfRest (x, y);
    trigonometricDrawLine (180 + walkingAngle / 2 - walkingPosition + rotation, height / 5);
    trigonometricDrawLine (180 + walkingAngle / 2 - walkingPosition + angleBetweenLegs + rotation, height/5);
    trigonometricDrawLine ( 90 + walkingAngle / 2 - walkingPosition + angleBetweenLegs + rotation, height/20);

    trigonometricSetPointOfRest (x, y);
    trigonometricDrawLine (bodyRot + rotation, height * 2/5);

    int neckX = pointOfRest_x,
        neckY = pointOfRest_y;

    txSetColor (hairColor);

    trigonometricSetPointOfRest (neckX, neckY);
    trigonometricMove (bodyRot + rotation, height / 10);

    int headx = pointOfRest_x,
        heady = pointOfRest_y;

    int space      = 90 / hairIntensivity;
        hairLenght = hairLenght + height / 10;

    for (int number = 0; number < hairIntensivity + 1; number++)
        trigonometricDrawLineAndReturn (direction - 135 + space * number + rotation, hairLenght);

    txSetColor (bodyColor);
    txSetFillColor (headColor);
    txCircle (headx, heady, height / 10);

    trigonometricSetPointOfRest (headx, heady);
    trigonometricMove (direction      + rotation, height / 20);
    trigonometricMove (direction - 90 + rotation, height / 50);

    txSetFillColor (eyeColor);
    txCircle (pointOfRest_x,     pointOfRest_y, height / 50);
    txCircle (pointOfRest_x + 1, pointOfRest_y, height / 125);

    trigonometricSetPointOfRest (headx, heady);
    trigonometricMove     (direction + 15 + rotation, height / 20);
    trigonometricDrawLine (direction + 15 + rotation, height / 20);

    trigonometricSetPointOfRest (neckX, neckY);
    trigonometricDrawLine (leftBase    + rotation, height / 5);
    trigonometricDrawLine (leftSpecial + rotation, height / 5);

    trigonometricSetPointOfRest (neckX, neckY);
    trigonometricDrawLine (rightBase    + rotation, height / 5);
    trigonometricDrawLine (rightSpecial + rotation, height / 5);
    }

POINT getPoint (int x, int y)
    {
    POINT p = {x, y};
    return p;
    }

void drawMountain (int x, int y, int width, int height, int snowHeight, COLORREF ground, COLORREF snow, COLORREF border)
    {
    POINT mountain[3] = {{ x - width/2, y          },
                         { x + width/2, y          },
                         { x,           y - height }};

    txSetFillColor (ground);
    txSetColor (border, 2);
    txPolygon (mountain, 3);

    trigonometricSetPointOfRest (x, y - height);
    trigonometricMove (trigonometricGetAngleOfLine (x, y - height, x - width / 2, y), snowHeight);

    int pointX = pointOfRest_x,
        pointY = pointOfRest_y;

    int snowWidth = (x - pointOfRest_x) * 2;
    int snowSpace = height / 40;
    int snowPointsNumber = snowWidth/snowSpace;

    POINT* snowPolygon = new POINT [snowPointsNumber + 4];

    snowPolygon [0] =
    snowPolygon [snowPointsNumber + 3] = getPoint (x, y - height);
    snowPolygon [1]                    = getPoint (pointX, pointY);

    for (int snowVertexNumber = 0; snowVertexNumber < snowPointsNumber; snowVertexNumber++)
        snowPolygon[snowVertexNumber + 2] = getPoint (pointX + (snowVertexNumber + 1) * snowSpace,
                                            getRandom (pointY - height / 15, pointY + height / 15));

    snowPolygon[snowPointsNumber + 2] =
    snowPolygon[snowPointsNumber + 1] = getPoint (pointX+snowWidth, pointY);

    txSetFillColor (snow);
    txPolygon (snowPolygon, snowPointsNumber + 4);

    delete[] snowPolygon;
    }

void drawTearsRow (int x, int y, int tearsLenght, int space, int offset)
    {
    int numberOfTears = (x + offset) / (tearsLenght + space) + 1;

    for (int n = 0; n < numberOfTears; n++)
        txLine (x + offset - n * (tearsLenght + space),
                y - offset + n * (tearsLenght + space),
                x + offset - n * (tearsLenght + space) - tearsLenght,
                y - offset + n * (tearsLenght + space) + tearsLenght);
    }

POINT getPointOnEllipse (int x, int y, int w, int h, double angle)
    {
    double trueAngle = 360- (angle-90) * txPI / 180;

    POINT p = { (int) (x + w / 2 * cos (trueAngle)),
                (int) (y + h / 2 * sin (trueAngle)) };
    return p;
    }

void drawRain (int columnsSpace, int tearsSpace, int tearsLenght, int animationFrame, int thickness, COLORREF color)
    {
    txSetColor (color, thickness);

    int number = 1400 / columnsSpace;
    int space = 0;

    for (int n = 0; n < number; n++)
        {
        drawTearsRow (space, 0, getRandom (tearsLenght - 4, tearsLenght), tearsSpace, tearsLenght + tearsSpace - animationFrame + n % 25);
        space += getRandom (columnsSpace - 1, columnsSpace + 4);
        }
    }

void drawCloud (int x, int y, int width, int height, int everyAngle, int everyWidth, int everyHeight, COLORREF color)
    {
    txSetColor (TX_TRANSPARENT);
    txSetFillColor (color);
    txEllipse (x - width / 2, y - height / 2, x + width / 2, y + height / 2);

    for (int n = 0; n < 360 / everyAngle; n++)
        {
        POINT p = getPointOnEllipse (x, y, width, height, n * everyAngle);
        txEllipse (p.x - everyWidth / 2, p.y - everyHeight / 2, p.x + everyWidth / 2, p.y + everyHeight / 2);
        }
    }

void drawPortal (int x, int y, int radius, int each, int bonusRot, COLORREF color, COLORREF alter)
    {
    txSetColor (color);

    trigonometricSetPointOfRest (x, y);
    trigonometricMove (bonusRot, radius);

    int lastx = pointOfRest_x,
        lasty = pointOfRest_y;

    int n = 360 / each;

    for (int a = 1; a <= n; a++)
        {
        trigonometricSetPointOfRest (x, y);
        trigonometricMove (a * each + bonusRot, radius);

        drawElectra (pointOfRest_x, pointOfRest_y,
                     trigonometricGetAngleOfLine (pointOfRest_x, pointOfRest_y, lastx, lasty),
                     5, 10, 45, 2,
                     color, alter, 0);

        txLine (pointOfRest_x, pointOfRest_y, lastx, lasty);

        lastx = pointOfRest_x;
        lasty = pointOfRest_y;
        }
    }

// Assembler randomizing system

const char* getRandomRegister()
    {
    return registers [rand() % sizearr (registers)];
    }

const char* getRandomCommand()
    {
    char* buf = new char[20];

    if (rand() % 20 == 0)
        switch (rand() % 2)
            {
            case 0:  sprintf (buf, "call %s", functionNames [rand() % sizearr (functionNames)]);
                     return buf;

            case 1:  sprintf (buf, "jump %s", functionNames [rand() % sizearr (functionNames)]);
                     return buf;

            default: break;
            }
    else
        switch (rand() % 2)
            {
            case 0:  sprintf (buf, "%s %s, %s", twoRegisterCommands [rand() % sizearr (twoRegisterCommands)],
                                                getRandomRegister(), getRandomRegister());
                     return buf;

            case 1:  sprintf (buf, "%s %s",     oneRegisterCommands [rand() % sizearr (oneRegisterCommands)],
                                                getRandomRegister());
                     return buf;

            default: break;
            }

    return strcpy (buf, "nop");
    }

// ============================

void matrixFireball (int x, int y, const char* text, int len, int textHeight, COLORREF color)
    {
    txSetTextAlign  (TA_CENTER);

    int yBonus = 0;
    for (int a = 0; a < len; a++)
        {
        txSelectFont ("Comic Sans MS", textHeight + a, false, false, false);
        txSetTextAlign (TA_CENTER);
        txSetColor (color);

        const char str[2] = { text[a], 0 };
        txTextOut (x, y + yBonus, str);

        yBonus += (textHeight + a) * 4/5;
        }
    }

void matrixEngineInit (int count)
    {
    matrixElementsNumber     = count;
    matrixElementsYPositions = new int   [count];
    matrixElementsNames      = new char* [count];

    for (int x = 0; x < count; x++)
        {
        matrixElementsYPositions[x] = getRandom (-200, 500);
        matrixElementsNames[x]      = new char [20];

        const char* command = getRandomCommand();
        strcpy (matrixElementsNames[x], command);
        delete[] (const char*) command;
        }
    }

void matrixEngineLoop (int spd, COLORREF col)
    {
    txSetTextAlign (TA_BASELINE | TA_LEFT);
    txSelectFont ("Comic Sans MS", 100, false, false, false);

    for (int a = 0; a < matrixElementsNumber; a++)
        {
        matrixElementsYPositions[a] += spd;

        if (matrixElementsYPositions[a] >  600 ||
            matrixElementsYPositions[a] < -600)
            {
            delete matrixElementsNames[a];
            matrixElementsNames[a] = new char[20];

            matrixElementsYPositions[a] = -getRandom (400, 800);

            const char* randomCommand = getRandomCommand();
            strcpy (matrixElementsNames[a], randomCommand);
            delete[] (const char*) randomCommand;
            }

        matrixFireball (a * 40, matrixElementsYPositions[a],       matrixElementsNames[a],                                      10, 20, col);
        matrixFireball (a * 40, matrixElementsYPositions[a] + 300, matrixElementsNames[a < matrixElementsNumber-1 ? a+1 : a-1], 10, 20, col);
        }
    }

const char* getStairsGround (int lenght)
    {
    char* ret = new char[lenght + 1];
    ret[lenght] = 0;

    for (int i = 0; i < lenght; i++) ret[i] = (char) getRandom (48, 49);

    return ret;
    }

void generateBinaryStairs (int difference, int flats)
    {
    binaryStairsGrounds = new char* [flats];
    binaryStairsHeight  = flats;

    for (int i = 0; i < flats; i++)
        {
        binaryStairsGrounds[i]   = new char        [(i + 1 ) * difference + 1];

        const char* stairsGround = getStairsGround ((i + 1 ) * difference);
        strcpy (binaryStairsGrounds[i], stairsGround);
        delete[] (const char*) stairsGround;
        }
    }

void destroyBinaryStairsAndMatrix()
    {
    int i = 0;

    for (i = 0; i < binaryStairsHeight; i++) delete binaryStairsGrounds[i];
    delete binaryStairsGrounds;

    delete matrixElementsYPositions;

    for (i = 0; i < matrixElementsNumber; i++) delete matrixElementsNames[i];
    delete matrixElementsNames;
    }

void drawBinaryStairs (int x, int y, COLORREF color)
    {
    txSetTextAlign (TA_RIGHT);
    txSelectFont ("Comic Sans MS", 20, false, false, false);
    txSetColor (color);

    for (int i = 0; i < binaryStairsHeight; i++)
        txTextOut (x, y + i * 20, binaryStairsGrounds[i]);
    }

void drawASMFlag (int x, int y)
    {
    txSetTextAlign (TA_BASELINE | TA_LEFT);

    txTextOut (x, y,       "111111111");
    txTextOut (x, y + 20,  "11ASM11");
    txTextOut (x, y + 40,  "111111111");
    txTextOut (x, y + 60,  "1");
    txTextOut (x, y + 80,  "1");
    txTextOut (x, y + 100, "1");
    }

void initIO()
    {
    sourceFile = fopen (__FILE__, "r");
    if (sourceFile == 0) TX_THROW ("Cannot open source file");
    }

void readCodePro()
    {
    txSetDefaults();
    txSetFillColor (TX_BLACK);
    txSetColor (RGB (0, 150, 0));
    txClear();

    initIO();

    fseek (sourceFile, 0, SEEK_END);
    unsigned fileSize = MIN (ftell (sourceFile), 10000);
    fseek (sourceFile, 0, SEEK_SET);

    char* allData = new char [fileSize + 100];
    int numberOfStrings = 0;

    try {
        unsigned i = 0;

        for (i = 0; i < fileSize; i++)
            {
            allData[i] = (char) fgetc (sourceFile);
            if (allData[i] == '\n') numberOfStrings++;
            }

        fileSize += (unsigned) strlen (strcpy (&allData[i-1], "\n    ...\n"));
        numberOfStrings += 2;

        partsAmount = numberOfStrings / 30 + 1;

        sourceCodeParts = new HDC [partsAmount + 1];
        for (i = 0; i < partsAmount + 1u; i++) sourceCodeParts[i] = NULL;

        int lastStringYID    = 0;
        int lastStringLength = 0;
        int lastSourcePart   = 0;

        for (i = 0; i < fileSize; i++)
            {
            if ((allData[i] == '\n') || (i == fileSize-1))
                {
                allData[i] = 0;
                if (i != fileSize-1) txTextOut (0, lastStringYID * 20, allData + (i - lastStringLength));

                lastStringYID++;
                lastStringLength = 0;

                if (lastStringYID == 30 || i >= fileSize-1)
                    {
                    HDC nHDC = txCreateCompatibleDC (800, 600);
                    txBitBlt (nHDC, 0, 0, 800, 600, txDC(), 0, 0);
                    sourceCodeParts[lastSourcePart] = nHDC;
 
                    lastSourcePart++;
                    lastStringYID = 0;

                    txClear();
                    }
                }
            else
                lastStringLength++;
            }

        fclose (sourceFile);
        
        sourceCodeParts[lastSourcePart] = txCreateCompatibleDC (800, 600);
        }

    catch (...)
        {}

    delete[] allData;
    }

void printEffect (int x, int y, const char* text, int lenght, int delay)
    {
    doSleep (delay);

    for (int i = 0; i < lenght; i++)
        {
        char buf[2] = { text[i] };
        txTextOut (x + txGetTextExtentX (text) * i / lenght * 1.2, y, buf);

        doSleep (delay);
        }
    }

void releaseScrollingSource()
    {
    for (int i = 0; i < partsAmount; i++) txDeleteDC (sourceCodeParts[i]);

    delete[] sourceCodeParts;
    sourceCodeParts = NULL;
    }

void fromAssemblerAndUpToTheVeryEnd()
    {
    matrixEngineInit (20);
    generateBinaryStairs (10, 10);
    readCodePro();

    // Smooth matrix color change
    int period = 20;
    int change = 1;
    int greenCooficient = 150;

    COLORREF stickColor = RGB (200, 255, 200);

    for (int t = 0; t < 210; t += SPEED)
        {
        int tMan = (t < 200)? t : 200;

        trigonometricSetPointOfRest (50, 520);
        trigonometricMove (77, tMan * 7/2);

        txSetFillColor (TX_BLACK);
        txClear();

        matrixEngineLoop (100, RGB (0, greenCooficient, 0));
        drawBinaryStairs (800, 400, TX_GREEN);
        drawASMFlag (720, 300);
        drawStickMan (pointOfRest_x, pointOfRest_y, 120, 30, 10, (tMan * 6 % 90), 185, 185, 90, 90, 60, 90,
                     TX_GREEN, NORMAL_BROWN, stickColor, TX_WHITE, -20 + tMan / 10, 0);

        doSleep (15);

        greenCooficient += change;
        period--;

        if (period == 0)
            {
            period = getRandom (5, 40);
            change = getRandom (1, 2) == 1 ? 1 : -1;

            if      (greenCooficient + period * change <  10) change = -change;
            else if (greenCooficient + period * change > 240) change = -change;
            }
        }

    destroyBinaryStairsAndMatrix();

    txSetFillColor (TX_BLACK);
    txClear();
    printEffect (20, 20,  "Critical Error!", 15, 10/SPEED);
    printEffect (20, 60,  "Critical Error!", 15, 10/SPEED);
    printEffect (20, 100, "Rebooting...",    12, 10);
    txSleep (3000);

    setTextSpeed (10 - SPEED);
    double sourceCodeYScrolled = 0;

    for (; sourceCodeYScrolled < partsAmount * 600; sourceCodeYScrolled += SPEED)
        {
        txSetFillColor (TX_BLACK);
        txClear();

        int roundY = (int) sourceCodeYScrolled;

        HDC hDC = txDC();
        txBitBlt (hDC, 0,     - (roundY % 600), 800, 600, sourceCodeParts[roundY / 600    ], 0, 0);
        txBitBlt (hDC, 0, 600 - (roundY % 600), 800, 600, sourceCodeParts[roundY / 600 + 1], 0, 0);

        lastTextEngineLoop (mixColor (TX_BLACK, RGB (0, 200, 0), roundY < 100 ? roundY : 100));

        doSleep (4);
        }

    releaseScrollingSource();
    }

void drawPrintingEffect (int x, int y, const char* whatToPrint, int howMany, COLORREF color)
    {
    txSetColor (color);

    int charWidthTotal = 0;

    for (int i = 0; i < howMany; i++)
        {
        const char toPrintNow[2] = { whatToPrint[i], 0 };
        txTextOut (x + charWidthTotal, y, toPrintNow);

        charWidthTotal += txGetTextExtentX (toPrintNow);
        }
    }

int centerOutByLeftCorner (const char* toCenter)
    {
    int ts = txGetTextExtentX (toCenter);
    return 400 - ts / 2;
    }

int getMainLoopBasedValue (int mainLoop, int from, int to)
    {
    return mainLoop + from > to ? to : from + mainLoop;
    }

int textEngineIndex = 0;

const char* theEnd    = "The end...";
const char* createdBy = "Created by Nikita Uvarov";

int lenghtOfTheEnd    = (int) strlen (theEnd),
    lenghtOfCreatedBy = (int) strlen (createdBy);

int textEngineSpeed = 1;

void setTextSpeed (int spd)
    {
    textEngineSpeed = spd;
    }

void lastTextEngineLoop (COLORREF color)
    {
    txSelectFont ("Comic Sans MS", 50, 25, 1000);

    drawPrintingEffect (centerOutByLeftCorner (theEnd),    200, theEnd,    getMainLoopBasedValue (textEngineIndex / textEngineSpeed, 0, lenghtOfTheEnd + 1), color);
    drawPrintingEffect (centerOutByLeftCorner (createdBy), 320, createdBy, getMainLoopBasedValue (textEngineIndex / textEngineSpeed, -lenghtOfTheEnd * 3 / 2, lenghtOfCreatedBy + 1), color);

    textEngineIndex += SPEED;
    }
