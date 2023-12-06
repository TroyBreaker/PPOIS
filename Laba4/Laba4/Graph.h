#include <iostream>
#include <vector>
//#include <iterator>
using namespace std;

namespace NotOrientedGraph {
    template <typename T>
    class Graph {
    public:
        typedef vector<T> VertexList;
        typedef vector<vector<T>> AdjacencyList;
        /**
     * @brief Class constructor
     * @param vector of vertices of any type
     */
        Graph(vector<T> vertices) {
            adjacency_list.resize(vertices.size());
            vertex_list = vertices;
        }
        Graph() {}
        
        /**
    * @brief Operator == overloading
    * @param The object we are compared with
    * @return Is it equal
    */
        bool operator==(Graph<T> other)
        {
            VertexList other_vertices = other.GetVertexList();
            AdjacencyList other_adjacency_list = other.GetAdjacencyList();
            if (other_vertices.size() != vertex_list.size()) {
                return 0;
            }            
            return 1;
        }
        bool operator>(Graph<T> other)
        {
            VertexList other_vertices = other.GetVertexList();
            if (vertex_list.size() > other_vertices.size()) {
                return 1;
            }
            else return 0;
        }
        bool operator<(Graph<T> other)
        {
            return !(*this > other);
        }

        /**
    * @brief Operator = overloading
    * @param The object to which we will assign fields 
    * @return address
    */
        Graph<T> operator=(Graph<T> other) {
            vertex_list = other.GetVertexList();
            adjacency_list = other.GetAdjacencyList();
            return *this;
        }
        /**
    * @brief Method that return amount of vertices in graph
    * @return amount of vertices in graph
    */
        int AmountOfVertices() const {
            return vertex_list.size();
        }
        /**
    * @brief Method that return amount of edges in graph
    * @return amount of edges in graph
    */
        int AmountOfEdges() const {
            int EdgeAmount = 0;
            for (int Current = 0; Current < adjacency_list.size(); Current++)
                for (int AdjacentWithCurrent = 0; AdjacentWithCurrent < adjacency_list[Current].size(); AdjacentWithCurrent++) {
                    EdgeAmount ++;
                }
            return EdgeAmount/2;
        }
        /**
    * @brief Method that return degree of vertex in graph (degree is an amount of adjacent vertices)
    * @param vertex
    * @return degree of vertex in graph 
    */
        int DegreeOfVertex(T vertex) const {
            if (!PresenceOfVertex(vertex)) {
                throw std::exception("invalid vertex");
            }
            int degree = 0;
            for (int i = 0; i < vertex_list.size(); i++)
                if (vertex_list[i] == vertex) {
                    for (int j = 0; j < adjacency_list[i].size(); j++)
                        degree++;
                    return degree;
                }
        }
        /**
    * @brief Method that return degree of edge in graph (degree is an amount of such edge)
    * @param first incident vertex of edge
    * @param second incident vertex of edge
    * @return degree of edge in graph
    */
        int DegreeOfEdge(T first, T second) const {
            int index = 0, second_index = 0;
            for (int i = 0; i < vertex_list.size(); i++) {
                if (first == vertex_list[i]) {
                    index = i;
                }
            }
            int degree = 0;
            for (int j = 0; j < adjacency_list[index].size(); j++)
                if(adjacency_list[index][j]==second)
                degree++;

            return degree;
        }
        /**
    * @brief Method that add vertex in graph 
    * @param new vertex
    */
        void AddVertex(T vertex) {
            if (PresenceOfVertex(vertex)) {
                throw std::exception("invalid vertex to add");
            }
            vertex_list.push_back(vertex);
            vector<T> edges_addition;
            adjacency_list.push_back(edges_addition);
        }
        /**
   * @brief Method that add edge in graph
   * @param first incident vertex of new edge
   * @param second incident vertex of new edge
   */
        void AddEdge(T first, T second) {
            if (!PresenceOfVertex(first) || !PresenceOfVertex(second)) {
                throw std::exception("there is no such vertex");
            }
            int first_index = 0, second_index = 0;
            for (int i = 0; i < vertex_list.size(); i++) {
                if (first == vertex_list[i]) {
                    first_index = i;
                }
                if (second == vertex_list[i]) {
                    second_index = i;
                }
            }
            adjacency_list[first_index].push_back(second);
            adjacency_list[second_index].push_back(first);
        }
        /**
    * @brief Method that delete vertex in graph
    * @param vertex you want to delete
    */
        void RemoveVertex(T vertex) {
            if (!PresenceOfVertex(vertex)) {
                throw std::exception("there is no such vertex");
            }
            int index = 0;
            for (int i = 0; i < vertex_list.size(); i++)
                if (vertex_list[i] == vertex) {
                    index = i;
                    break;
                }
            for (int AdjacentWithDeleted = 0; AdjacentWithDeleted < adjacency_list[index].size(); AdjacentWithDeleted++) {
                for (int Current = 0; Current < vertex_list.size(); Current++)
                {
                    if (Current == index)
                        continue;
                    if (vertex_list[Current] == adjacency_list[index][AdjacentWithDeleted])
                    {
                        for (int AdjacentWithCurrent = 0; AdjacentWithCurrent < adjacency_list[Current].size(); AdjacentWithCurrent++)
                        {
                            if (adjacency_list[Current][AdjacentWithCurrent] == vertex_list[index])
                            {
                                adjacency_list[Current].erase(adjacency_list[Current].begin() + AdjacentWithCurrent);
                            }
                        }
                    }
                }
            }
            adjacency_list.erase(adjacency_list.begin() + index);
            vertex_list.erase(vertex_list.begin() + index);
        }
        /**
  * @brief Method that remove edge from graph
  * @param first incident vertex of edge you want to remove
  * @param second incident vertex of edge you want to remove
  */
        void RemoveEdge(T first, T second) {
            if (!PresenceOfEdge(first, second)) {
                throw std::exception("there is no such edge");
            }
            int first_index = 0, second_index = 0;
            for (int i = 0; i < vertex_list.size(); i++) {
                if (first == vertex_list[i]) {
                    first_index = i;
                }
                if (second == vertex_list[i]) {
                    second_index = i;
                }
            }
            for (int i = 0; i < adjacency_list[first_index].size(); i++) {
                if (adjacency_list[first_index][i] == second) {
                    adjacency_list[first_index].erase(adjacency_list[first_index].begin() + i);
                }
            }
            for (int i = 0; i < adjacency_list[second_index].size(); i++) {
                if (adjacency_list[second_index][i] == first) {
                    adjacency_list[second_index].erase(adjacency_list[second_index].begin() + i);
                }
            }
        }
        /**
        * @brief Method that check presence of vertex in graph
        * @param vertex
        * @return true if vertex exist, false in other case
        */
        bool PresenceOfVertex(T vertex) const {
            for (int i = 0; i < vertex_list.size(); i++)
                if (vertex == vertex_list[i]) {
                    return true;
                }
            return false;
        }
        /**
        * @brief Method that check presence of edge in graph
  * @param first incident vertex of edge you want to check
  * @param second incident vertex of edge you want to check
  * @return true if edge exist, false in other case
        */
        bool PresenceOfEdge(T first, T second) const {
            if (!PresenceOfVertex(first) || !PresenceOfVertex(second)) {
                throw std::exception("there is no such vertex");
            }
            int first_index = 0, second_index = 0;
            for (int i = 0; i < vertex_list.size(); i++) {
                if (first == vertex_list[i]) {
                    first_index = i;
                }
            }
            bool isHasEdge = 0;
            for (int i = 0; i < adjacency_list[first_index].size(); i++) {
                if (adjacency_list[first_index][i] == second) {
                    isHasEdge = 1;
                }
            }

            if (isHasEdge) {
                return true;
            }

            return false;
        }
        /**
        * @brief Method that check if graph is empty
        * @return true if graph is empty, false in other case
        */
        bool empty() { return adjacency_list.empty(); }
        /**
        *@brief Method that make graph empty
        */
        void clear() {
            adjacency_list.clear();
            vertex_list.clear();
        }
        /**
        * @brief Getter of adjacency_list
        * @return adjacency_list
        */
        AdjacencyList GetAdjacencyList()
        {
            return adjacency_list;
        }
        /**
        * @brief Getter of vertex_list
        * @return vertex_list
        */
        VertexList GetVertexList()
        {
            return vertex_list;
        }

    private:
        //! vector of vertices
        VertexList vertex_list;
        //! adjacency list is presented ih the form of vector of vectors of vertices
        AdjacencyList adjacency_list;
    };
}