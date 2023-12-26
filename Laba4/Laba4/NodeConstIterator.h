#pragma once
#include"EdgeReverseIterator.h"
template <typename T>
class NodeConstIterator {
private:
    T current;
    vector<T> AllNodes;
    int position = 0;
    NodeConstIterator()
    {}
public:
    NodeConstIterator(Graph<T> graph) {

        /*if (!graph.isNode(nodeNum))
            throw std::out_of_range("no such node");*/
        AllNodes = graph.GetVertexList();
        if (AllNodes.empty())
        {
            throw exception("No nodes");
            position = -1;
        }
        else
            current = AllNodes[0];
    }

    void begin() {
        current = AllNodes[0];
        position = 0;
    }

    void end()
    {
        current = AllNodes[AllNodes.size() - 1];
        position = AllNodes.size() - 1;
    }

    NodeConstIterator next() {
        NodeConstIterator temp;
        if (position + 1 > AllNodes.size())
            throw exception("no such node");
        temp.position = position + 1;
        temp.current = AllNodes[position + 1];
        temp.AllNodes = AllNodes;
        return temp;
    }

    NodeConstIterator back() {
        NodeConstIterator temp;
        if (position - 1 < 0)
            throw exception("no such node");
        temp.position = position - 1;
        temp.current = AllNodes[position - 1];
        temp.AllNodes = AllNodes;
        return temp;
    }

    NodeConstIterator& operator+(int n) {
        if (position + n > AllNodes.size() - 1)
            throw exception("no such node");
        position += n;
        current = AllNodes[position];
        return *this;
    }

    NodeConstIterator& operator-(int n) {
        if (position - n < 0)
            throw exception("no such node");
        position -= n;
        current = AllNodes[position];
        return *this;
    }

    NodeConstIterator& operator++(int n) {
        *this = this->next();
        return *this;
    }

    NodeConstIterator& operator--(int n) {
        *this = this->back();
        return *this;

    }

    T getCurrent() {
        return current;
    }
};
