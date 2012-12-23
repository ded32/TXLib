//{===========================================================================
//           Библиотека DirectTX - Demo/BumpedLogo.cpp
//           Copyright (C) Nikita Uvarov, 7 класс
//}===========================================================================

/**\file     Demo/BumpedLogo.cpp
 *
 * \brief    Пример для DirectTX - 3D Environmental map
 *
 * \version  [v 0.2]
 *
 * \author   Copyright (C) Nikita Uvarov, 7 класс
 * \date     2009
 */

#include "..\DirectTX.cpp"

const int SizeX = 600,
          SizeY = 400;

struct Normal
    {
    int nx, ny;
    };

char          Buffer          [SizeX] [SizeY] = {};

bool          TextMap         [SizeX] [SizeY] = {};
char          TextMapSmoothed [SizeX] [SizeY] = {};
DirectTXColor EnvironmentMap  [SizeX] [SizeY] = {};
Normal        NormalMap       [SizeX] [SizeY] = {};

void CreateTextMap()
    {
    txSetTextAlign (TA_CENTER | TA_BASELINE);
    txSelectFont ("Arial", 90); txTextOut (SizeX/2, SizeY/2 - 10, "DirectTX");
    txSelectFont ("Arial", 40); txTextOut (SizeX/2, SizeY/2 + 40, "Your dreams now");

    for (int y = 0; y < SizeY; y++)
    for (int x = 0; x < SizeX; x++)
        {
        TextMap         [x][y] = (txGetPixel (x, y) != TX_BLACK);
        TextMapSmoothed [x][y] = (TextMap    [x][y] ?  128 : 0);
        }
    }

void DistortTextMap()
    {
    for (int y = 0; y < SizeY; y++)
    for (int x = 0; x < SizeX; x++)
        {
        char random  = rand() % 20 - 10;
        if (0 < TextMapSmoothed [x][y] + random && TextMapSmoothed [x][y] + random < 255)
                TextMapSmoothed [x][y] += random;
        }
    }

void SmoothTextMap()
    {
    for (int y = 1; y < SizeY-1; y++)
    for (int x = 1; x < SizeX-1; x++)
        Buffer [x] [y] = (TextMapSmoothed [x-1] [y  ] +
                          TextMapSmoothed [x+1] [y  ] +
                          TextMapSmoothed [x  ] [y-1] +
                          TextMapSmoothed [x  ] [y+1] +
                          TextMapSmoothed [x-1] [y-1] +
                          TextMapSmoothed [x-1] [y+1] +
                          TextMapSmoothed [x+1] [y-1] +
                          TextMapSmoothed [x+1] [y+1]) / 8;

    for (int y = 1; y < SizeY-1; y++)
    for (int x = 1; x < SizeX-1; x++)
        TextMapSmoothed [x] [y] = (Buffer [x-1] [y  ] +
                                   Buffer [x+1] [y  ] +
                                   Buffer [x  ] [y-1] +
                                   Buffer [x  ] [y+1] +
                                   Buffer [x-1] [y-1] +
                                   Buffer [x-1] [y+1] +
                                   Buffer [x+1] [y-1] +
                                   Buffer [x+1] [y+1]) / 8;
    }

void CreateEnvironmentMap()
    {
    for (int y = 0; y < SizeY; y++)
    for (int x = 0; x < SizeX; x++)
        {
        float nx  = (x - 150) / 100.0f;
        float ny  = (y - 100) / 100.0f;
        float nz  = 1 - hypot (nx, ny);

        if (nz < 0) nz = 0;

        EnvironmentMap [x][y] = DirectTXColor ((int) (nz * 255), 0, 0);
        }
    }

void CreateNormalMap()
    {
    for (int y = 1; y < SizeY-1; y++)
    for (int x = 1; x < SizeX-1; x++)
        {
        NormalMap [x][y] .nx = TextMapSmoothed [x-1][y  ] - TextMapSmoothed [x+1][y  ];
        NormalMap [x][y] .ny = TextMapSmoothed [x  ][y-1] - TextMapSmoothed [x  ][y+1];
        }
    }

void DrawBumpedText()
    {
    int lightX = txMouseX(),
        lightY = txMouseY();

    for (int y = 1; y < SizeY-1; y++)
    for (int x = 1; x < SizeX-1; x++)
        {
        int trueNx = (lightX + NormalMap [x][y] .nx - x + 150);
        int trueNy = (lightY + NormalMap [x][y] .ny - y + 100);

        if (trueNx < 0 || trueNx > SizeX ||
            trueNy < 0 || trueNy > SizeY)
            trueNx = trueNy = 0;

        DirectTXPutPixel (x, y, EnvironmentMap [trueNx] [trueNy]);
        }
    }

int main()
    {
    DirectTXCreateWindow (SizeX, SizeY, "DirectTX Demo... [Esc] to exit");

    DirectTXBegin();

    CreateTextMap();
    SmoothTextMap();
    DistortTextMap();
    CreateEnvironmentMap();
    CreateNormalMap();

    DirectTXSetFillColor (DirectTXColor (0, 0, 0));
    DirectTXDrawRectangle (0, 0, SizeX, SizeY);

    DirectTXFlush();
    DirectTXEnd();

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        DirectTXBegin();

        DrawBumpedText();

        DirectTXFlush();
        DirectTXEnd();
        }
    }
