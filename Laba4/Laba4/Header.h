#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <set>
//#include "Node.h"

template<typename T>

class Graph {

public:
    typedef std::vector<int> NodeList;
    typedef std::vector<NodeList> Matrix;

private:
    std::vector<Node<T>> nodes;
    Matrix matrix;
    int numberOfNode = -1;
    int numberOfEdge = 0;
    std::set<int> uniqueName;
public:
    Graph() {}

    /**
     * add new node
     * @param value value
     */
    void addNode(T value, int uniqueName) {
        if (!this->uniqueName.insert(uniqueName).second)
            throw "Node with such unique name is already exists";
        Node<T> temp(uniqueName, value);
        nodes.push_back(temp);
        numberOfNode++;
        for (auto& node : matrix) {
            node.push_back(0);
        }
        matrix.push_back(NodeList(numberOfNode + 1, 0));
    }

    /**
     * add new edge
     * @param from first node
     * @param to second node
     */
    void addEdge(int from, int to) {
        if (isNode(from) && isNode(to) && !isEdge(from, to)) {
            numberOfEdge++;
            matrix[from][to] = 1;
        }
        else {
            throw std::invalid_argument("edge already exists");
        }
    }

    /**
     * set value
     * @param numberNode node number
     * @param value value
     */
    void setValue(int numberNode, const T& value) {
        if (isNode(numberNode))
            nodes[numberNode].setValue(value);
        else {
            throw std::out_of_range("no such node");
        }
    }

    /**
     * get node degree
     * @param nodeNum number of node
     * @return degree
     */
    int getNodeDegree(int nodeNum) {
        if (isNode(nodeNum)) {
            int degree = 0;
            for (const auto& value : matrix[nodeNum]) {
                if (value != 0)
                    degree++;
            }
            return degree;
        }
        else {
            throw std::out_of_range("no such node");
        }
    }

    /**
     * delete node
     * @param nodeNum node num
     */
    void deleteNode(int nodeNum) {
        if (isNode(nodeNum)) {
            int numberOfEdgeInThisNode = 0;
            numberOfEdge -= getNodeDegree(nodeNum);
            matrix.erase(matrix.begin() + nodeNum);
            for (const auto& node : matrix) {
                if (node[nodeNum] != 0)
                    numberOfEdgeInThisNode++;
            }

            numberOfEdge -= numberOfEdgeInThisNode;

            for (auto& node : matrix) {
                node.erase(node.begin() + nodeNum);
            }
            uniqueName.erase(nodes[nodeNum].getUniqueName());
            nodes.erase(nodes.begin() + nodeNum);
            numberOfNode--;
        }
        else {
            throw std::out_of_range("no such node");
        }
    }

    /**
     * delete edge
     * @param from first node
     * @param to second node
     */
    void deleteEdge(int from, int to) {
        if (isEdge(from, to)) {
            matrix[from][to] = 0;
            numberOfEdge--;
        }
        else {
            throw std::invalid_argument("no such edge");
        }
    }

    /**
     * @brief Get the Number Of Edge object
     *
     * @return int
     */
    int getNumberOfEdge() {
        return numberOfEdge;
    }

    /**
     * @brief Get the Number Of Node object
     *
     * @return int
     */
    int getNumberOfNode() const {
        return numberOfNode + 1;
    }

    /**
     * get value
     * @param nodeNum node num
     * @return T value
     */
    T getValue(int nodeNum) const {
        if (!isNode(nodeNum))
            throw std::invalid_argument("no such edge");
        return nodes[nodeNum].getValue();;
    }

    /**
     * @brief check is empty matrix
     *
     * @return true
     * @return false
     */
    bool isEmpty() {
        return matrix.empty();
    }

    /**
     * @brief clear matrix
     *
     */
    void clear() {
        nodes.clear();
        matrix.clear();
        numberOfEdge = 0;
        numberOfNode = -1;
    }

    /**
     * operator ==
     * @param graph graph
     * @return true of false
     */
    bool operator==(const Graph& graph) {
        if (this->numberOfNode != graph.numberOfNode || this->numberOfEdge != graph.numberOfEdge)
            return false;
        bool flag = false;
        for (int i = 0; i < numberOfNode; i++) {
            for (size_t j = 0; j < graph.numberOfNode; j++)
            {
                if (nodes[i] == graph.nodes[j])
                    flag = true;
            }
            if (!flag)
                return false;
            flag = false;
        }
        int nodeNumber1;
        int nodeNumber2;

        for (size_t i = 0; i < numberOfNode; i++)
        {
            nodeNumber1 = findNumberInSecond(graph, i);
            for (size_t j = 0; j < numberOfNode; j++)
            {
                nodeNumber2 = findNumberInSecond(graph, j);
                if (matrix[i][j] != graph.matrix[nodeNumber1][nodeNumber2])
                    return false;
            }

        }
        return true;
    }

    /**
     * operator !=
     * @param graph graph
     * @return true of false
     */
    bool operator!=(const Graph& graph) {
        return !operator==(graph);
    }

    /**
     * get edge degree
     * @param from first node
     * @param to second node
     * @return pair<first degree, second degree>
     */
    std::pair<int, int> getEdgeDegree(int from, int to) {
        if (!isNode(from) || !isNode(to))
            throw std::out_of_range("no such node");
        if (!isEdge(from, to))
            throw std::invalid_argument("no such edge");
        std::pair<int, int> degree(getNodeDegree(from), getNodeDegree(to));
        return degree;
    }

    class NodeAdjacentIterator {
    private:
        Node<T> current;
        std::vector<Node<T>> adjacentNodes;
        int position = 0;

    public:
        /**
         * @brief Construct a new Node Adjacent Iterator object
         *
         * @param nodeNum number of node
         * @param graph graph
         */
        NodeAdjacentIterator(int nodeNum, Graph& graph) {
            if (!graph.isNode(nodeNum))
                throw std::out_of_range("no such node");

            for (int i = 0; i < graph.getNumberOfNode(); i++) {
                if (graph.isEdge(nodeNum, i))
                    adjacentNodes.push_back(graph.nodes[i]);
            }
            current = adjacentNodes[0];
        }

        /**
         * @brief set current on first node
         *
         */
        void begin() {
            current = adjacentNodes[0];
        }

        /**
         * @brief set current on next node
         *
         */
        void next() {
            position++;
            if (position > adjacentNodes.size() - 1)
                throw std::out_of_range("no such node");

            current = adjacentNodes[position];
        }

        /**
         * @brief set current on previous node
         *
         */
        void back() {
            position--;
            if (position < 0)
                throw std::out_of_range("no such node");

            current = adjacentNodes[position];
        }

        /**
         * @brief operator +
         *
         * @param n number of nodes
         * @details set current on +n nodes
         */
        void operator+(int n) {
            if (position + n > adjacentNodes.size() - 1)
                throw std::out_of_range("no such node");
            position += n;
            current = adjacentNodes[position];
        }

        /**
         * @brief operator -
         *
         * @param n number of nodes
         * @details set current on -n nodes
         */
        void operator-(int n) {
            if (position - n < 0)
                throw std::out_of_range("no such node");
            position -= n;
            current = adjacentNodes[position];
        }
        /**
         * check has next
         * @return true or false
         */
        bool hasNext() {
            return (position + 1 <= adjacentNodes.size() - 1);
        }

        /**
         * check has prev
         * @return true or false
         */
        bool hasPrev() {
            return (position - 1 >= 0);
        }

        /**
         * @brief Get the Current iterator
         *
         * @return node
         */
        int getCurrent() {
            return current.getValue();
        }
    };


    class NodeIteratorConst {
    protected:
        Node<T> current;
        std::vector<Node<T>> nodes;
        int position = 0;
        Graph* graph;
    public:
        /**
         * @brief Construct a new Node Iterator Const object
         *
         * @param nodeNum number of node
         * @param graph graph
         */
        NodeIteratorConst(Graph& graph) {
            this->graph = &graph;
            for (int i = 0; i < graph.getNumberOfNode(); i++) {
                nodes.push_back(graph.nodes[i]);
            }
            current = nodes[0];
        }

        /**
         * @brief set current on first node
         *
         */
        void begin() {
            current = nodes[0];
        }

        /**
         * @brief set current on next node
         *
         */
        void next() {
            position++;
            if (position > nodes.size() - 1)
                throw std::out_of_range("no such node");

            current = nodes[position];
        }

        /**
         * @brief set current on previous node
         *
         */
        void back() {
            position--;
            if (position < 0)
                throw std::out_of_range("no such node");

            current = nodes[position];
        }

        /**
         * @brief operator +
         *
         * @param n number of nodes
         * @details set current on +n nodes
         */
        void operator+(int n) {
            if (position + n > nodes.size() - 1)
                throw std::out_of_range("no such node");
            position += n;
            current = nodes[position];
        }

        /**
         * @brief operator -
         *
         * @param n number of nodes
         * @details set current on -n nodes
         */
        void operator-(int n) {
            if (position - n < 0)
                throw std::out_of_range("no such node");
            position -= n;
            current = nodes[position];
        }

        /**
         * check has next
         * @return true or false
         */
        bool hasNext() {
            return (position + 1 <= nodes.size() - 1);
        }

        /**
         * check has prev
         * @return true or false
         */
        bool hasPrev() {
            return (position - 1 >= 0);
        }

        /**
         * @brief Get the Current iterator
         *
         * @return node
         */
        Node<T> getCurrent() {
            return current;
        }

    };

    class NodeIterator : public NodeIteratorConst {
    public:
        /**
         * Node Iterator constructor
         * @param graph graph
         */
        NodeIterator(Graph& graph) : NodeIteratorConst(graph) {}

        /**
         * delete node by Node Iterator
         */
        void deleteNode() {
            int temp = NodeIteratorConst::position;
            if (NodeIteratorConst::hasNext())
                NodeIteratorConst::current = NodeIteratorConst::nodes[NodeIteratorConst::position + 1];
            else if (NodeIteratorConst::hasPrev()) {
                NodeIteratorConst::current = NodeIteratorConst::nodes[NodeIteratorConst::position - 1];
                temp -= 1;
            }
            else {
                temp = -1;
            }
            NodeIteratorConst::graph->deleteNode(NodeIteratorConst::position);
            NodeIteratorConst::nodes.erase(NodeIteratorConst::nodes.begin() + NodeIteratorConst::position);
            NodeIteratorConst::position = temp;
        }

        /**
         * change value by node iterator
         * @param value value
         */
        void setValue(T value) {
            NodeIteratorConst::graph->nodes[NodeIteratorConst::position].setValue(value);
            NodeIteratorConst::nodes[NodeIteratorConst::position].setValue(value);
            NodeIteratorConst::current = NodeIteratorConst::nodes[NodeIteratorConst::position];
        }
    };

    class ReverseNodeIterator : public NodeIterator {
    public:
        /**
         * constructor Reverse node iterator
         * @param graph
         */
        ReverseNodeIterator(Graph& graph) : NodeIterator(graph) {
            std::vector<Node<T>> temp = NodeIteratorConst::nodes;
            NodeIteratorConst::nodes.clear();
            for (int i = temp.size() - 1; i >= 0; i--) {
                NodeIteratorConst::nodes.push_back(temp[i]);
            }

        }
    };

    class ReverseNodeAdjacentIterator : public NodeAdjacentIterator {
    public:
        /**
         * constructor of Reverse Adjacent Iterator
         * @param nodeNum number of node
         * @param graph graph
         */
        ReverseNodeAdjacentIterator(int nodeNum, Graph& graph) : NodeAdjacentIterator(nodeNum, graph) {
            std::vector<Node<T>> temp = NodeAdjacentIterator::adjacentNodes;
            NodeIteratorConst::adjacentNodes.clear();
            for (int i = temp.size() - 1; i >= 0; i--) {
                NodeIteratorConst::adjacentNodes.push_back(temp[i]);
            }
        }
    };

    class AdjacentEdgeIteratorConst {
    protected:
        std::vector<int> numberEdge;
        int nodeNum;
        int position = 0;
        Graph* graph;
    public:
        /**
         * constructor of Edge Iterator Const
         * @param nodeNum number of node
         * @param graph graph
         */
        AdjacentEdgeIteratorConst(int nodeNum, Graph& graph) {
            this->graph = &graph;
            if (!graph.isNode(nodeNum))
                throw std::out_of_range("no such node");
            this->nodeNum = nodeNum;
            this->graph = &graph;
            for (int i = 0; i < graph.matrix[nodeNum].size(); i++) {
                if (graph.matrix[nodeNum][i] == 1)
                    numberEdge.push_back(i);
            }
        }

        /**
         * check has next
         * @return true or false
         */
        bool hasNext() {
            return (position + 1 <= numberEdge.size() - 1);
        }

        /**
         * check has prev
         * @return true or false
         */
        bool hasPrev() {
            return (position - 1 >= 0);
        }

        /**
         * next edge
         */
        void next() {
            if (!hasNext())
                throw std::out_of_range("no such edge");
            position++;
        }

        /**
         * prev edge
         */
        void back() {
            if (!hasPrev())
                throw std::out_of_range("no such edge");
            position--;
        }

        /**
         * get value
         * @return pair<value of first node, value of second node>
         */
        std::pair<T, T> getValue() {
            std::pair<T, T> value(graph->nodes[nodeNum].getValue(), graph->nodes[numberEdge[position]].getValue());
            return value;
        }
    };

    class AdjacentEdgeIterator : public AdjacentEdgeIteratorConst {
    public:
        /**
         * constructor of Edge Iterator
         * @param nodeNum number of node
         * @param graph graph
         */
        AdjacentEdgeIterator(int nodeNum, Graph& graph) : AdjacentEdgeIteratorConst(nodeNum, graph) {}

        /**
         * delete edge by edge iterator
         */
        void deleteEdge() {
            int temp = AdjacentEdgeIteratorConst::position;
            if (AdjacentEdgeIteratorConst::hasPrev())
                temp -= 1;
            else
                temp = -1;
            AdjacentEdgeIteratorConst::graph->deleteEdge(AdjacentEdgeIteratorConst::nodeNum, AdjacentEdgeIteratorConst::position);
            AdjacentEdgeIteratorConst::numberEdge.erase(AdjacentEdgeIteratorConst::numberEdge.begin() + AdjacentEdgeIteratorConst::position);
            AdjacentEdgeIteratorConst::position = temp;
        }
    };

    class AdjacentReversEdgeIterator : public AdjacentEdgeIterator {
        /**
         * constructor Reverse edge iterator
         * @param nodeNum number of node
         * @param graph graph
         */
        AdjacentReversEdgeIterator(int nodeNum, Graph& graph) : AdjacentEdgeIterator(nodeNum, graph) {
            std::vector<int> temp = AdjacentEdgeIterator::nodeNum;
            AdjacentEdgeIterator::nodeNum.clear();
            for (const auto& edge : temp) {
                AdjacentEdgeIterator::nodeNum.push_back(edge);
            }
        }
    };
    class EdgeIteratorConst {
    protected:
        std::vector<std::pair<int, int>> numberEdge;
        int position = 0;
        Graph* graph;
    public:
        /**
         * constructor of Edge Iterator Const
         * @param nodeNum number of node
         * @param graph graph
         */
        EdgeIteratorConst(Graph& graph) {
            this->graph = &graph;
            this->graph = &graph;
            for (int i = 0; i < graph.matrix.size(); i++) {
                for (int j = 0; j < graph.matrix[i].size(); ++j) {
                    if (graph.matrix[i][j] == 1)
                        numberEdge.push_back(std::make_pair(i, j));
                }
            }
        }

        /**
         * check has next
         * @return true or false
         */
        bool hasNext() {
            return (position + 1 <= numberEdge.size() - 1);
        }

        /**
         * check has prev
         * @return true or false
         */
        bool hasPrev() {
            return (position - 1 >= 0);
        }

        /**
         * next edge
         */
        void next() {
            if (!hasNext())
                throw std::out_of_range("no such edge");
            position++;
        }

        /**
         * prev edge
         */
        void back() {
            if (!hasPrev())
                throw std::out_of_range("no such edge");
            position--;
        }

        /**
         * get value
         * @return pair<value of first node, value of second node>
         */
        std::pair<T, T> getValue() {
            std::pair<T, T> value(graph->nodes[numberEdge[position].first].getValue(), graph->nodes[numberEdge[position].second].getValue());
            return value;
        }
    };
    class EdgeIterator : public EdgeIteratorConst {
    public:
        /**
         * constructor of Edge Iterator
         * @param nodeNum number of node
         * @param graph graph
         */
        EdgeIterator(Graph& graph) : EdgeIteratorConst(graph) {}

        /**
         * delete edge by edge iterator
         */
        void deleteEdge() {
            int temp = EdgeIteratorConst::position;
            if (EdgeIteratorConst::hasPrev())
                temp -= 1;
            else
                temp = -1;
            EdgeIteratorConst::graph->deleteEdge(EdgeIteratorConst::numberEdge[EdgeIteratorConst::position].first, EdgeIteratorConst::numberEdge[EdgeIteratorConst::position].second);
            EdgeIteratorConst::numberEdge.erase(EdgeIteratorConst::numberEdge.begin() + EdgeIteratorConst::position);
            EdgeIteratorConst::position = temp;
        }
    };

    class ReversEdgeIterator : public EdgeIterator {
        /**
         * constructor Reverse edge iterator
         * @param nodeNum number of node
         * @param graph graph
         */
        ReversEdgeIterator(Graph& graph) : EdgeIterator(graph) {
            std::reverse(EdgeIteratorConst::numberEdge.begin(), EdgeIteratorConst::numberEdge.end());
        }
    };

private:
    /**
     * @brief check is node in matrix
     *
     * @param nodeNum number of node
     */
    bool isNode(int nodeNum) const {
        return (nodeNum > 0 || nodeNum < numberOfNode);

    }

    int findNumberInSecond(const Graph& graph, int i) {
        int nodeNumber;
        for (size_t j = 0; j < graph.numberOfNode; j++)
        {
            if (nodes[i] == graph.nodes[j])
                nodeNumber = j;
        }
        return nodeNumber;
    }

public:
    /**
     * @brief check is edge in graph
     *
     * @param from first node
     * @param to second node
     * @return true
     * @return false
     */
    bool isEdge(int from, int to) const {
        if (!isNode(from) || !isNode(to))
            throw std::out_of_range("no such node");
        return matrix[from][to] != 0;
    }
};

/**
 * @brief operator <<
 *
 * @param os
 * @param graph
 * @return std::ostream&
 */
template<typename Temp>
std::ostream& operator<<(std::ostream& os, Graph<Temp>& graph) {
    for (size_t i = 0; i < graph.getNumberOfNode(); i++) {
        for (size_t j = 0; j < graph.getNumberOfNode(); j++) {
            if (graph.isEdge(i, j))
                os << i << " -> " << j << "\n";
        }
    }

    return os;
}