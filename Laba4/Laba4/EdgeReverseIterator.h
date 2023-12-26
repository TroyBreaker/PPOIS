#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
using namespace std;

template <typename T>
class Graph;

template <typename T>
class EdgeReverseIterator {
private:
    pair<T, T> current;
    vector<pair<T, T>> AllEdges;
    int position;
    Graph<T>* graph;
    EdgeReverseIterator()
    {}
public:
    EdgeReverseIterator(Graph<T>* graph) {
        this->graph = graph;
        AllEdges = graph->GetEdges();
        if (AllEdges.empty())
        {
            throw exception("No edges");
            position = -1;
        }
        else {
            position = AllEdges.size() - 1;
            current = AllEdges[position];
        }
    }

    void rend() {
        current = AllEdges[0];
        position = 0;
    }

    void rbegin()
    {
        current = AllEdges[AllEdges.size() - 1];
        position = AllEdges.size() - 1;
    }

    EdgeReverseIterator rback() {
        EdgeReverseIterator temp;
        if (position + 1 > AllEdges.size())
            throw exception("no such edge");
        temp.position = position + 1;
        temp.current = AllEdges[position + 1];
        temp.AllEdges = AllEdges;
        temp.graph = graph;
        return temp;
    }

    EdgeReverseIterator rnext() {
        EdgeReverseIterator temp;
        if (position - 1 < 0)
            throw exception("no such edge");
        temp.position = position - 1;
        temp.current = AllEdges[position - 1];
        temp.AllEdges = AllEdges;
        temp.graph = graph;
        return temp;
    }

    EdgeReverseIterator& operator-(int n) {
        if (position + n > AllEdges.size() - 1)
            throw exception("no such edge");
        position += n;
        current = AllEdges[position];
        return *this;
    }

    EdgeReverseIterator& operator+(int n) {
        if (position - n < 0)
            throw exception("no such edge");
        position -= n;
        current = AllEdges[position];
        return *this;
    }

    EdgeReverseIterator& operator--(int n) {
        *this = this->rback();
        return *this;
    }

    EdgeReverseIterator& operator++(int n) {
        *this = this->rnext();
        return *this;

    }
    void operator=(const EdgeReverseIterator<T>& other) {
        this->AllEdges = other.AllEdges;
        this->current = other.current;
        this->graph = other.graph;
        this->position = other.position;
    }
    pair<T, T> getCurrent() {
        return current;
    }

    void erase()
    {
        graph->RemoveEdge(current.first, current.second);
        EdgeReverseIterator<T> itr(graph);
        *this = itr;
    }
};
