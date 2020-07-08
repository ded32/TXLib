//{=========================================================================== 
//! @file       Examples\Demo\LDView_\LDView_GraphView.h
//!
//! @brief      Этюд "Визуализатор графов", Graph view representation
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//!             $Version: 00173a, Revision: 166 $
//!             $Date: 2020-07-08 18:50:10 +0400 $
//!             $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//              $Copyright: (C) Ded (Ilya Dedinsky, http://txlib.ru) <mail@txlib.ru> $
//}===========================================================================

#ifndef __LDVIEW_GRAPHVIEW_H

//-----------------------------------------------------------------------------

#include "LDView_tools.h"
using a_bit_of_vector_algebra::vec2d;
using a_bit_of_vector_algebra::Distance;

#include "LDView_graph.h"

//-----------------------------------------------------------------------------

struct GraphView_t
    {
    Graph_t graph;

    POINT vertex_   [Graph_t::MaxSize];
    POINT selfEdge_ [Graph_t::MaxSize];
    int   active_;

    static const int VertexSize   = 10;
    static const int SelfEdgeSize = 15;

    enum { ViewVertices = 1, ViewEdges = 2, ViewAll = -1U };

    bool  ok() const;
    bool  vertexOk (int vertex) const;
    bool  dump (FILE* log = stdout) const;

    void  draw (unsigned what = ViewAll) const;

    int   addVertex (POINT pos = MousePos);
    int   connectTo (POINT pos = MousePos);
    int   activateVertex (int vertex);
    int   activateVertex (POINT pos = MousePos);

    int   vertexByPos      (POINT pos = MousePos) const;
    bool  isVertexSelected (int vertex,       POINT pos = MousePos) const;
    bool  isEdgeSelected   (int from, int to, POINT pos = MousePos) const;
    POINT center() const;
    };

//-----------------------------------------------------------------------------

bool GraphView_t::ok() const
    {
    return graph.ok() &&
           (active_ == EOF || graph.vertexOk (active_));
    }

//-----------------------------------------------------------------------------

bool GraphView_t::vertexOk (int vertex) const
    {
    assert (ok());

    return graph.vertexOk (vertex);
    }

//-----------------------------------------------------------------------------

bool GraphView_t::dump (FILE* log) const
    {
    graph.dump (log);

    return !ferror (log);
    }

//-----------------------------------------------------------------------------

void GraphView_t::draw (unsigned what) const
    {
    assert (ok());

    txSelectFont ("Arial", 12);
    txSetTextAlign();

    if (what & ViewEdges)
        for (int i = 0; i < graph.size_; i++)
            for (int j = 0; j < graph.size_; j++)
                if (graph.adjacency_[i][j])
                    {
                    bool sel = isEdgeSelected (i, j);
                    COLORREF color = (sel)? TX_YELLOW : TX_WHITE;
                    int      thick = (sel)? 3         : 1;

                    if (i == j)
                        {
                        COLORREF fillColor = txGetFillColor();

                        txSetFillColor (TX_TRANSPARENT);
                        LabelCircle (selfEdge_[i], SelfEdgeSize, color, thick);

                        txSetFillColor (fillColor);
                        }
                    else
                        LabelLine (vertex_[i], vertex_[j], color, thick);
                    }

    if (what & ViewVertices)
        for (int i = 0; i < graph.size_; i++)
            {
            bool sel = isVertexSelected (i),
                 act = (i == active_);

            COLORREF color = (sel)?        TX_YELLOW : TX_WHITE;
            int      thick = (sel || act)? 3         : 1;

            LabelCircle (vertex_[i], VertexSize, color, thick, "%d", i);
            }
    }

//-----------------------------------------------------------------------------

int GraphView_t::addVertex (POINT pos)
    {
    assert (ok());

    vertex_[graph.size_] = pos;

    return graph.addVertex();
    }

//-----------------------------------------------------------------------------

int GraphView_t::connectTo (POINT pos)
    {
    assert (ok());

    int v = vertexByPos (pos);
    if (v == EOF) return v;

    graph.connect (active_, v);

    if (active_ == v)
        {
        vec2d d = vec2d (vertex_[v]) - center();
        selfEdge_[v] = vertex_[v] + norm (d) * SelfEdgeSize;
        }

    return v;
    }

//-----------------------------------------------------------------------------

int GraphView_t::activateVertex (int vertex)
    {
    assert (ok());

    return active_ = vertex;
    }

//-----------------------------------------------------------------------------

int GraphView_t::activateVertex (POINT pos)
    {
    assert (ok());

    return activateVertex (vertexByPos (pos));
    }

//-----------------------------------------------------------------------------

int GraphView_t::vertexByPos (POINT pos) const
    {
    assert (ok());

    for (int i = 0; i < graph.size_; i++)
        if (isVertexSelected (i, pos)) return i;

    return EOF;
    }

//-----------------------------------------------------------------------------

bool GraphView_t::isVertexSelected (int vert, POINT pos) const
    {
    assert (ok());

    return Distance (pos, vertex_[vert]) <= VertexSize;
    }

//-----------------------------------------------------------------------------

bool GraphView_t::isEdgeSelected (int from, int to, POINT pos) const
    {
    assert (ok());

    if (from != to)
        {
        return Distance (pos, vertex_[from], vertex_[to]) <= VertexSize;
        }
    else
        {
        double d = Distance (pos, selfEdge_[from]);
        return SelfEdgeSize - VertexSize/2 <= d && d <= SelfEdgeSize + VertexSize/2;
        }
    }

//-----------------------------------------------------------------------------

POINT GraphView_t::center() const
    {
    vec2d c (0);

    for (int i = 0; i < graph.size_; i++) c = c + vertex_[i];

    return c / graph.size_;
    }

//-----------------------------------------------------------------------------

#endif



