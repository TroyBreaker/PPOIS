#pragma once
#include"EdgeReverseIterator.h"
#include"EdgeConstIterator.h"

template <typename T>
class EdgeIterator :public EdgeConstIterator<T>
{
    Graph<T>* graph;
public:
    EdgeIterator(Graph<T>* graph) :graph(graph), EdgeConstIterator<T>(*graph)
    {};
    void erase()
    {
        pair<T, T> DeletedPair = this->getCurrent();
        graph->RemoveEdge(DeletedPair.first, DeletedPair.second);
        EdgeIterator<int> itr(graph);
        *this = itr;
    }
};