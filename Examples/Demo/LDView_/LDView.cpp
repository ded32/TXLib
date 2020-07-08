//{=========================================================================== 
//! @file       Examples\Demo\LDView_\LDView.cpp
//!
//! @brief      Этюд "Визуализатор графов", Main application file
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:50:10 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#define __MODULE       "LDView"
#define __VERSION      "0.1"
#define __DESCRIPTION  "LD Graph view application"
#define __AUTHOR       "Ded"

//-----------------------------------------------------------------------------

#include "LDView_graphView.h"

//-----------------------------------------------------------------------------

void OnscreenHelp (int level);
bool DoDragging (const GraphView_t* graph = NULL);
void DrawBackground();
void DrawTree (vec2d pos, double length, double angle);

//-----------------------------------------------------------------------------

int main()
    {
    txCreateWindow (800, 600);

    txSetFillColor (TX_RED);
    txClear();
    OnscreenHelp (-1);
    txUpdateWindow();

    GraphView_t g = {};

    txBegin();
    for (;;)
        {
        txSetFillColor (TX_RED);
        txClear();

        DrawBackground();
        OnscreenHelp (g.graph.size_);

        switch (UpdateMouse())
            {
            case 1:
                {
                g.activateVertex() != EOF || g.activateVertex (g.addVertex() - 1);
                DoDragging (&g);
                }
                break;

            case 2:
                {
                int v = g.vertexByPos();
                if (v == EOF) break;

                if (g.graph.connected (g.active_, g.vertexByPos())) g.activateVertex();
                g.connectTo();
                if (!GetAsyncKeyState (VK_CONTROL)) g.activateVertex();
                }
                break;

            default: break;
            }

        if (GetAsyncKeyState (VK_ESCAPE) &&
            MessageBox (txWindow(), "Exit LDView?", "LDView", MB_YESNO | MB_ICONQUESTION) == IDYES)
            break;

        if (GetAsyncKeyState ('D'))   g.dump();
        if (GetAsyncKeyState (VK_F1)) system ("start LDView.chm") == 0 ||
                                      system ("start doc/index.htm");

        g.draw (GraphView_t::ViewEdges);

        if (DoDragging()) g.connectTo();

        g.draw (GraphView_t::ViewVertices);

        txSleep (10);
        }

    txEnd();
    _txExit = true;
    }

//-----------------------------------------------------------------------------

bool DoDragging (const GraphView_t* graph)
    {
    static const GraphView_t* g = NULL;
    static int   dragFrom       = EOF;
    static bool  dragFromLeaved = false;

    if (graph)
        {
        g = graph;
        dragFrom = g->vertexByPos();
        dragFromLeaved = false;
        return false;
        }

    if (!g) return false;

    if (g->vertexByPos() != dragFrom)
        dragFromLeaved = true;

    if (txMouseButtons() != 1)
        {
        g = NULL;
        return dragFromLeaved;
        }

    int v = g->vertexByPos();
    POINT pos = (v != EOF)? g->vertex_[v] : MousePos;

    txSetColor (TX_WHITE);
    txLine (g->vertex_ [dragFrom].x, g->vertex_ [dragFrom].y, pos.x, pos.y);
    txCircle (pos.x, pos.y, GraphView_t::VertexSize/2);
    
    return false;
    }

//-----------------------------------------------------------------------------

void OnscreenHelp (int level)
    {
    txSelectFont ("Arial", 20);
    txSetTextAlign();

    POINT c = { txGetExtentX() /2, txGetExtentY() /2 };

    switch (level)
        {
        case -1: txSetColor (RGB (192, 32, 16));
                 txTextOut (c.x, c.y - 10, "Starting...");
                 break;

        case 0:  txSetColor (TX_YELLOW);
                 txTextOut (c.x, c.y - 10, "Press Left mouse button to add a vertex");
                 // break;

        case 1:  txSetColor (TX_WHITE);
                 txTextOut (c.x, c.y + 10, "Press Right mouse button or drag the mouse to add an edge");
                 // break;

        case 2:  txSetColor (TX_WHITE);
                 txTextOut (c.x, c.y + 30, "Press F1 for help");
                 // break;

        default: break;
        }
    }

//-----------------------------------------------------------------------------

void DrawBackground()
    {
    DrawTree (vec2d (0, txGetExtentY()/2), 100, txPI/2);
    }

//-----------------------------------------------------------------------------

void DrawTree (vec2d pos, double length, double angle)
    {
    static const unsigned maxTime = (int) (30 * txQueryPerformance());

    static vec2d    shift  = 0;
    static unsigned time   = 0;

    if (length > 0)
        {
        vec2d center = vec2d (txGetExtent())/2;

        shift = (vec2d (MousePos) - center) / 25;
        pos   = pos + center;

        time  = GetTickCount() + maxTime;
        }
    else
        length *= -1;

    if (length <= 10) return;

    if (txMouseButtons() || GetTickCount() > time) return;
    Sleep (0);

    vec2d p = pos + vec2d (length * Random (0.75, 1.5) * +cos (angle),
                           length * Random (0.75, 1.5) * -sin (angle)) + shift;

    txSetColor (RGB (128-16, 0, 0), (int) (length / 15 + 1));

    txLine (pos.x, pos.y, p.x, p.y);

                    DrawTree (p, -length * Random (0.7, 0.8), angle - Random (-0.2, +0.8) - shift.x/50);
                    DrawTree (p, -length * Random (0.7, 0.8), angle + Random (-0.2, +0.8) - shift.x/50);

    if (rand() % 5) DrawTree (p, -length * Random (0.8, 0.9), angle + Random (-0.5, +0.5) + shift.x/50);
    }

