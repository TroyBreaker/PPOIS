#include"EdgeIterator.h"

    template <typename T>
    class Graph {
    public:
        typedef vector<T> VertexList;
        typedef vector<vector<T>> AdjacencyList;
        typedef typename VertexList::iterator vertex_iterator;
        typedef typename VertexList::const_iterator vertex_const_iterator;
        typedef typename VertexList::reverse_iterator vertex_reverse_iterator;
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
            return (other_vertices.size() == vertex_list.size());
        }
        bool operator>(Graph<T> other)
        {
            VertexList other_vertices = other.GetVertexList();
            return (vertex_list.size() > other_vertices.size());
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
        std::pair <int, int> DegreeOfEdge(T first, T second) const {
            try {
                PresenceOfEdge(first, second);
            }
            catch (const exception& ex)
            {
                cout << ex.what() << endl;
                return std::make_pair(-1, -1);
            }
            int first_index = DegreeOfVertex(first);
            int second_index = DegreeOfVertex(second);
            return std::make_pair(first_index, second_index);
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

            vertex_iterator deleted = this->begin() + index;
            vertex_iterator AdjacentWithDeleted = adjacency_list[index].begin();

            for (; AdjacentWithDeleted != adjacency_list[index].end(); AdjacentWithDeleted++)
            {
                for (int Current = 0; Current < vertex_list.size(); Current++)
                {
                    if (*deleted == vertex_list[Current])continue;
                    if (*AdjacentWithDeleted == vertex_list[Current])
                    {
                        vertex_iterator AdjacentWithCurrent = adjacency_list[Current].begin();
                        for (; AdjacentWithCurrent != adjacency_list[Current].end();)
                        {
                            if (*deleted == *AdjacentWithCurrent)
                            {
                                AdjacentWithCurrent = adjacency_list[Current].erase(AdjacentWithCurrent);
                            }
                            else
                                AdjacentWithCurrent++;
                        }
                    }
                }
            }
            adjacency_list.erase(adjacency_list.begin() + index);
            vertex_list.erase(deleted);
        }


        vertex_iterator RemoveByIterator(vertex_iterator deleted)
        {      
            int index;
            try {
                index = IndexOfVertex(deleted);
            }
            catch (const exception* ex) {
                cout << ex->what() << endl;
                return deleted;
            }
            vertex_iterator AdjacentWithDeleted = adjacency_list[index].begin();

            for (; AdjacentWithDeleted != adjacency_list[index].end(); AdjacentWithDeleted++)
            {
                for (int Current = 0; Current < vertex_list.size(); Current++)
                {
                    if (*deleted == vertex_list[Current])continue;
                    if (*AdjacentWithDeleted == vertex_list[Current])
                    {
                        vertex_iterator AdjacentWithCurrent = adjacency_list[Current].begin();
                        for (; AdjacentWithCurrent != adjacency_list[Current].end();)
                        {
                            if (*deleted == *AdjacentWithCurrent)
                            {
                                AdjacentWithCurrent = adjacency_list[Current].erase(AdjacentWithCurrent);
                            }
                            else
                                AdjacentWithCurrent++;
                        }
                    }
                }
            }
            adjacency_list.erase(adjacency_list.begin() + index);
            vertex_list.erase(deleted);
            vertex_iterator it = std::next(vertex_list.begin(), index);
            return it;
        }


        /**
  * @brief Method that remove edge from graph
  * @param first incident vertex of edge you want to remove
  * @param second incident vertex of edge you want to remove
  */
        void RemoveEdge(T first, T second) {
            try {
                PresenceOfEdge(first, second);
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
            for (typename VertexList::const_iterator it = this->begin(); it != this->end(); it++)          //const
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
                    break;
                }
            }
            if (isHasEdge) {
                return true;
            }
            else
                throw std::exception("there is no such edge");
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
        vertex_iterator next(vertex_iterator it)
        {
            if(it==this->end()-1)
                throw std::exception("current iterator is the last");
            return it+1; 
        }
        vertex_iterator previous(vertex_iterator it)
        {
            if (it == this->begin())
                throw std::exception("current iterator is the first");
            return it - 1;
        }


        vertex_const_iterator const_begin() { return vertex_list.begin(); }
        vertex_const_iterator const_end() { return vertex_list.end(); }
        vertex_const_iterator const_next(vertex_const_iterator it)
        {
            if (it == this->const_end() - 1)
                throw std::exception("current iterator is the last");
            return it + 1;
        }
        vertex_const_iterator const_previous(vertex_const_iterator it)
        {
            if (it == this->const_begin())
                throw std::exception("current iterator is the first");
            return it - 1;
        }


        vertex_reverse_iterator rbegin() { return vertex_list.rbegin(); }
        vertex_reverse_iterator rend() { return vertex_list.rend(); }

        vector<pair<T, T>> GetEdges()
        {
            vector<pair<T, T>>AllEdges;
            for (int i = 0; i < adjacency_list.size(); i++)
                for (int j = 0; j < adjacency_list[i].size(); j++)
                {
                    AllEdges.push_back(make_pair(vertex_list[i], adjacency_list[i][j]));
                }
            int a = 0;
            vector<pair<T, T>> UniqueEdges;
            for (pair<T, T> pair : AllEdges) {
                if (!IsDuplicate(pair, UniqueEdges)) {
                    UniqueEdges.push_back(pair);
                }
            }
            return UniqueEdges;
        }
        int IndexOfVertex(T vertex) const
        {
            for (int i = 0; i < vertex_list.size(); i++)
                if (vertex_list[i] == vertex)
                    return i;
            throw new exception("invalid vertex");
        }
        vector<T>GetAdjacentNodes(T vertex)
        {
            int index = IndexOfVertex(vertex);            
            return adjacency_list[index];
        }
        
        vector<pair<T, T>> GetAdjacentEdges(T vertex)
        {
            int index = IndexOfVertex(vertex);
            vector<pair<T, T>>AllEdges;
            for (int j = 0; j < adjacency_list[index].size(); j++)
            {
                AllEdges.push_back(make_pair(vertex_list[index], adjacency_list[index][j]));
            }
            return AllEdges;
        }

    private:
        //! vector of vertices
        VertexList vertex_list;
        //! adjacency list is presented ih the form of vector of vectors of vertices
        AdjacencyList adjacency_list;        

        int IndexOfVertex(vertex_iterator vertex) const
        {
            for (int i = 0; i < vertex_list.size(); i++)
            {
                auto it = std::next(vertex_list.begin(), i);
                if (it == vertex)
                    return i;
            }
            throw new exception("invalid iterator");
        }

        bool IsDuplicate(const pair<T, T>& currentPair, const vector<pair<T, T>>& UniqueEdges) {
            for (pair<T, T> p : UniqueEdges) {
                if (p.first == currentPair.second && p.second == currentPair.first) {
                    return true;
                }
            }
            return false;
        }
        template <typename U> friend
            ostream& operator<<(ostream& os, const Graph<U>& graph);        
    };

    template <typename U>
    ostream& operator<<(ostream& os, Graph<U>& graph) {        
        for (typename vector<U>::reverse_iterator it = graph.rbegin(); it != graph.rend(); it++)     //reverse
            os << *it;
        return os;
    }
