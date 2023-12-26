#pragma once
#include"EdgeReverseIterator.h"

template <typename T>
class NodeReverseIterator {
private:
    T current;
    vector<T> AllNodes;
    int position;
    Graph<T>* graph;
    NodeReverseIterator()
    {}
public:
    NodeReverseIterator(Graph<T>* graph) {
        this->graph = graph;
        /*if (!graph.isNode(nodeNum))
            throw std::out_of_range("no such node");*/
        AllNodes = graph->GetVertexList();
        if (AllNodes.empty())
        {
            throw exception("No nodes");
            position = -1;
        }
        else {
            position = AllNodes.size() - 1;
            current = AllNodes[AllNodes.size() - 1];
        }
    }

    void rend() {
        current = AllNodes[0];
        position = 0;
    }

    void rbegin()
    {
        current = AllNodes[AllNodes.size() - 1];
        position = AllNodes.size() - 1;
    }

    NodeReverseIterator rback() {
        NodeReverseIterator temp;
        if (position + 1 > AllNodes.size())
            throw exception("no such node");
        temp.position = position + 1;
        temp.current = AllNodes[position + 1];
        temp.AllNodes = AllNodes;
        temp.graph = graph;
        return temp;
    }

    NodeReverseIterator rnext() {
        NodeReverseIterator temp;
        if (position - 1 < 0)
            throw exception("no such node");
        temp.position = position - 1;
        temp.current = AllNodes[position - 1];
        temp.AllNodes = AllNodes;
        temp.graph = graph;
        return temp;
    }

    NodeReverseIterator& operator-(int n) {
        if (position + n > AllNodes.size() - 1)
            throw exception("no such node");
        position += n;
        current = AllNodes[position];
        return *this;
    }

    NodeReverseIterator& operator+(int n) {
        if (position - n < 0)
            throw exception("no such node");
        position -= n;
        current = AllNodes[position];
        return *this;
    }

    NodeReverseIterator& operator--(int n) {
        *this = this->rback();
        return *this;
    }

    NodeReverseIterator& operator++(int n) {
        *this = this->rnext();
        return *this;
    }

    void operator=(const NodeReverseIterator<T>& other) {
        this->AllNodes = other.AllNodes;
        this->current = other.current;
        this->graph = other.graph;
        this->position = other.position;
    }

    T getCurrent() {
        return current;
    }

    void erase()
    {
        graph->RemoveVertex(current);
        NodeReverseIterator<T> itr(graph);
        *this = itr;
    }
};
