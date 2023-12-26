#pragma once
#include"EdgeReverseIterator.h"

template <typename T>
class EdgeConstIterator {
private:
    pair<T, T> current;
    vector<pair<T, T>> AllEdges;
    int position = 0;
    EdgeConstIterator()
    {}
public:
    EdgeConstIterator(Graph<T> graph) {
        AllEdges = graph.GetEdges();
        if (AllEdges.empty())
        {
            throw exception("No edges");
            position = -1;
        }
        else
            current = AllEdges[0];
    }

    void begin() {
        current = AllEdges[0];
        position = 0;
    }

    void end()
    {
        current = AllEdges[AllEdges.size() - 1];
        position = AllEdges.size() - 1;
    }

    EdgeConstIterator next() {
        EdgeConstIterator temp;
        if (position + 1 > AllEdges.size())
            throw exception("no such edge");
        temp.position = position + 1;
        temp.current = AllEdges[position + 1];
        temp.AllEdges = AllEdges;
        return temp;
    }

    EdgeConstIterator back() {
        EdgeConstIterator temp;
        if (position - 1 < 0)
            throw exception("no such edge");
        temp.position = position - 1;
        temp.current = AllEdges[position - 1];
        temp.AllEdges = AllEdges;
        return temp;
    }

    EdgeConstIterator& operator+(int n) {
        if (position + n > AllEdges.size() - 1)
            throw exception("no such edge");
        position += n;
        current = AllEdges[position];
        return *this;
    }

    EdgeConstIterator& operator-(int n) {
        if (position - n < 0)
            throw exception("no such edge");
        position -= n;
        current = AllEdges[position];
        return *this;
    }

    EdgeConstIterator& operator++(int n) {
        *this = this->next();
        return *this;
    }

    EdgeConstIterator& operator--(int n) {
        *this = this->back();
        return *this;

    }

    pair<T, T> getCurrent() {
        return current;
    }
};
