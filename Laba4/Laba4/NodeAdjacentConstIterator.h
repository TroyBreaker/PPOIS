#pragma once
#include"NodeConstIterator.h"
template <typename T>
class NodeAdjacentConstIterator {
private:
    T current;
    vector<T> AdjacentNodes;
    int position = 0;
    NodeAdjacentConstIterator()
    {}
public:
    NodeAdjacentConstIterator(Graph<T> graph, NodeConstIterator<T> vertex_iterator)
    {
        AdjacentNodes = graph.GetAdjacentNodes(vertex_iterator.getCurrent());
        if (AdjacentNodes.empty())
        {
            throw exception("No nodes");
            position = -1;
        }
        else
            current = AdjacentNodes[0];
    }

    void begin() {
        current = AdjacentNodes[0];
        position = 0;
    }

    void end()
    {
        current = AdjacentNodes[AdjacentNodes.size() - 1];
        position = AdjacentNodes.size() - 1;
    }

    NodeAdjacentConstIterator next() {
        NodeAdjacentConstIterator temp;
        if (position + 1 > AdjacentNodes.size())
            throw exception("no such node");
        temp.position = position + 1;
        temp.current = AdjacentNodes[position + 1];
        temp.AdjacentNodes = AdjacentNodes;
        return temp;
    }

    NodeAdjacentConstIterator back() {
        NodeAdjacentConstIterator temp;
        if (position - 1 < 0)
            throw exception("no such node");
        temp.position = position - 1;
        temp.current = AdjacentNodes[position - 1];
        temp.AdjacentNodes = AdjacentNodes;
        return temp;
    }

    NodeAdjacentConstIterator& operator+(int n) {
        if (position + n > AdjacentNodes.size() - 1)
            throw exception("no such node");
        position += n;
        current = AdjacentNodes[position];
        return *this;
    }

    NodeAdjacentConstIterator& operator-(int n) {
        if (position - n < 0)
            throw exception("no such node");
        position -= n;
        current = AdjacentNodes[position];
        return *this;
    }

    NodeAdjacentConstIterator& operator++(int n) {
        *this = this->next();
        return *this;
    }

    NodeAdjacentConstIterator& operator--(int n) {
        *this = this->back();
        return *this;

    }
};
