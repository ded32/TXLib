//{===========================================================================
//! @file       Examples\Demo\LDView\_LDView_Graph.h
//              (C) Ilya Dedinsky, http://ded32.net.ru, 2010
//!
//! @brief      Этюд "Визуализатор графов", Graph representation
//!
//!             Библиотека Тупого Художника (The Dumb Artist Library, TX Library, TXLib).
//!
//! @version    [Version 0.01 alpha, build 72]
//! @author     Copyright (C) Ded, 2005-10 (Ilya Dedinsky, http://ded32.net.ru)
//! @date       2010
//}===========================================================================

#ifndef __LDVIEW_GRAPH_H

//-----------------------------------------------------------------------------

struct Graph_t
    {
    static const int MaxSize = 10;

    int  adjacency_ [MaxSize][MaxSize];
    int  weight_    [MaxSize][MaxSize];
    int  size_;

    bool ok() const;
    bool vertexOk (int vertex) const;
    bool dump (FILE* log = stdout) const;

    int  addVertex();
    void connect (int from = EOF, int to = EOF);
    bool connected (int from, int to);
    };

//-----------------------------------------------------------------------------

bool Graph_t::ok() const
    {
    return 0 <= size_ && size_ <= MaxSize;
    }

//-----------------------------------------------------------------------------

bool Graph_t::vertexOk (int vertex) const
    {
    assert (ok());

    return 0 <= vertex && vertex <= size_;
    }

//-----------------------------------------------------------------------------

bool Graph_t::dump (FILE* log) const
    {
    assert (log);

    fprintf (log, "\n"
                  "Graph_t (%s)\n"
                  "    {\n", (ok()? "ok" : "<<<BAD>>>"));

    fprintf (log, "    size = %d\n", size_);

    fprintf (log, "    adjacency = \n"
                  "        {\n");

    for (int j = 0; j < size_; j++) fprintf (log, "%s%d", (j? "" : "           "), j%10);

    for (int i = 0; i < size_; i++)
        {
        fprintf (log, "\n        %d [", i%10);
        for (int j = 0; j < size_; j++) fprintf (log, "%c", adjacency_ [i][j]? (i != j)? 'x' : 'o' : '\xB7');
        fprintf (log, "]");
        }

    fprintf (log, "\n" "        }\n"
                       "    }\n");

    return !ferror (log);
    }

//-----------------------------------------------------------------------------

int Graph_t::addVertex()
    {
    assert (ok());

    return ++size_;
    }

//-----------------------------------------------------------------------------

void Graph_t::connect (int from, int to)
    {
    assert (ok());

    assert (from == EOF || vertexOk (from));
    assert (to   == EOF || vertexOk (to));

    if (from == EOF) { for (int i = 0; i < size_; i++) connect (i, EOF);  return; }
    if (to   == EOF) { for (int i = 0; i < size_; i++) connect (from, i); return; }

    adjacency_ [from][to] = 1;
    adjacency_ [to][from] = 1;
    }

//-----------------------------------------------------------------------------

bool Graph_t::connected (int from, int to)
    {
    assert (ok());

    assert (vertexOk (from));
    assert (vertexOk (to));

    return adjacency_ [from][to];
    }

//-----------------------------------------------------------------------------

#endif
