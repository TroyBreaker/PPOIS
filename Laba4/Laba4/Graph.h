#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


namespace NotOrientedGraph {
    template <typename T>
    class Graph {
    public:
        typedef vector<T> VertexList;
        typedef vector<vector<T>> AdjacencyList;
        typedef typename VertexList::iterator vertex_iterator;
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
            return (other_vertices.size() == vertex_list.size()) ? true : false;
        }
        bool operator>(Graph<T> other)
        {
            VertexList other_vertices = other.GetVertexList();
            return (vertex_list.size() > other_vertices.size()) ? true : false;
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
                EdgeAmount += adjacency_list[Current].size();
            return EdgeAmount / 2;
        }

        /**
    * @brief Method that return degree of vertex in graph (degree is an amount of adjacent vertices)
    * @param vertex
    * @return degree of vertex in graph
    */
        int DegreeOfVertex(T vertex) const {
            int index;
            try {
                index = IndexOfVertex(vertex);
            }
            catch (const exception* ex)
            {
                cout << ex->what() << endl;
                return -1;
            }
            int degree = 0;
            for (int j = 0; j < adjacency_list[index].size(); j++)
                degree++;
            return degree;
        }
        /**
    * @brief Method that return degree of edge in graph (degree is an amount of such edge)
    * @param first incident vertex of edge
    * @param second incident vertex of edge
    * @return degree of edge in graph
    */
        vector<int> DegreeOfEdge(T first, T second) const {
            try {
                if (!PresenceOfEdge(first, second)) {
                    throw std::exception("there is no such edge");
                }
            }
            catch (const exception& ex)
            {
                cout << ex.what() << endl;
                return { -1,-1 };
            }
            int first_index = DegreeOfVertex(first);
            int second_index = DegreeOfVertex(second);
            return { first_index ,second_index };
        }

        /**
    * @brief Method that add vertex in graph
    * @param new vertex
    */
        void AddVertex(T vertex) {
            try {
                if (PresenceOfVertex(vertex)) {
                    throw std::exception("invalid vertex to add");
                }
            }
            catch (const exception& ex) {
                cout << ex.what() << endl;
                return;
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
            int first_index, second_index;
            try {
                first_index = IndexOfVertex(first);
                second_index = IndexOfVertex(second);
            }
            catch (const exception* ex) {
                cout << ex->what() << endl;
                return;
            }
            adjacency_list[first_index].push_back(second);
            adjacency_list[second_index].push_back(first);
        }
        /**
    * @brief Method that delete vertex in graph
    * @param vertex you want to delete
    */
        void RemoveVertex(T vertex) {
            int index;
            try {
                index = IndexOfVertex(vertex);
            }
            catch (const exception* ex) {
                cout << ex->what() << endl;
                return;
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
            try {
                if (!PresenceOfEdge(first, second)) {
                    throw std::exception("there is no such edge");
                }
            }
            catch (const exception& ex)
            {
                cout << ex.what() << endl;
                return;
            }
            int first_index, second_index;
            first_index = IndexOfVertex(first);
            second_index = IndexOfVertex(second);

            for (int i = 0; i < adjacency_list[first_index].size(); i++) {
                if (adjacency_list[first_index][i] == second) {
                    adjacency_list[first_index].erase(adjacency_list[first_index].begin() + i);
                    i--;
                }
            }
            for (int i = 0; i < adjacency_list[second_index].size(); i++) {
                if (adjacency_list[second_index][i] == first) {
                    adjacency_list[second_index].erase(adjacency_list[second_index].begin() + i);
                    i--;
                }
            }
        }
        /**
        * @brief Method that check presence of vertex in graph
        * @param vertex
        * @return true if vertex exist, false in other case
        */
        bool PresenceOfVertex(T vertex) {
            for (vertex_iterator it = this->begin(); it != this->end(); it++)
                if (vertex == *it) {
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
            int first_index;
            try {
                first_index = IndexOfVertex(first);
            }
            catch (const exception* ex)
            {
                cout << ex->what() << endl;
                return 0;
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
            else
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

        vertex_iterator begin() { return vertex_list.begin(); }
        vertex_iterator end() { return vertex_list.end(); }

    private:
        //! vector of vertices
        VertexList vertex_list;
        //! adjacency list is presented ih the form of vector of vectors of vertices
        AdjacencyList adjacency_list;

        int IndexOfVertex(T vertex) const
        {
            for (int i = 0; i < vertex_list.size(); i++)
                if (vertex_list[i] == vertex)
                    return i;
            throw new exception("invalid vertex");
        }
       template <typename U> friend
            ostream& operator<<(ostream& os, const Graph<U>& graph);
    };
    template <typename U>
    ostream& operator<<(ostream& os, Graph<U>& graph) {        
        for (typename vector<U>::iterator it = graph.begin(); it != graph.end(); it++)
            os << *it;
        return os;
    }
}
