#pragma once
#include"EdgeReverseIterator.h"
template <typename T>
class EdgeAdjacentConstIterator {
private:
    pair<T, T> current;
    vector<pair<T, T>> AdjacentEdges;
    int position = 0;
    EdgeAdjacentConstIterator()
    {}
public:
    EdgeAdjacentConstIterator(Graph<T> graph, NodeConstIterator<T> vertex_iterator) {
        AdjacentEdges = graph.GetAdjacentEdges(vertex_iterator.getCurrent());
        if (AdjacentEdges.empty())
        {
            throw exception("No edges");
            position = -1;
        }
        else
            current = AdjacentEdges[0];
    }

    void begin()
    {
        current = AdjacentEdges[0];
        position = 0;
    }

    void end()
    {
        current = AdjacentEdges[AdjacentEdges.size() - 1];
        position = AdjacentEdges.size() - 1;
    }

    EdgeAdjacentConstIterator next() {
        EdgeAdjacentConstIterator temp;
        if (position + 1 > AdjacentEdges.size())
            throw exception("no such edge");
        temp.position = position + 1;
        temp.current = AdjacentEdges[position + 1];
        temp.AdjacentEdges = AdjacentEdges;
        return temp;
    }

    EdgeAdjacentConstIterator back() {
        EdgeAdjacentConstIterator temp;
        if (position - 1 < 0)
            throw exception("no such edge");
        temp.position = position - 1;
        temp.current = AdjacentEdges[position - 1];
        temp.AdjacentEdges = AdjacentEdges;
        return temp;
    }

    EdgeAdjacentConstIterator& operator+(int n) {
        if (position + n > AdjacentEdges.size() - 1)
            throw exception("no such edge");
        position += n;
        current = AdjacentEdges[position];
        return *this;
    }

    EdgeAdjacentConstIterator& operator-(int n) {
        if (position - n < 0)
            throw exception("no such edge");
        position -= n;
        current = AdjacentEdges[position];
        return *this;
    }

    EdgeAdjacentConstIterator& operator++(int n) {
        *this = this->next();
        return *this;
    }

    EdgeAdjacentConstIterator& operator--(int n) {
        *this = this->back();
        return *this;

    }
};
