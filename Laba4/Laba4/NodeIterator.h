#pragma once
#include"NodeConstIterator.h"
#include"EdgeReverseIterator.h"

template <typename T>
class NodeIterator :public NodeConstIterator<T>
{
    Graph<T>* graph;
public:
    NodeIterator(Graph<T>* graph) :graph(graph), NodeConstIterator<T>(*graph)
    {};
    void erase()
    {
        graph->RemoveVertex(this->getCurrent());
        NodeIterator<int> itr(graph);
        *this = itr;
    }
};
