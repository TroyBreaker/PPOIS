#include "gtest/gtest.h"
#include "Graph.h"
//using namespace NotOrientedGraph;

TEST(TestCaseName, GraphAddVertex)
{
	Graph<int> graph({ 1, 2, 3 });
	graph.AddVertex(4);
	EXPECT_EQ(4, graph.AmountOfVertices());
	EXPECT_TRUE(graph.PresenceOfVertex(4));
}

TEST(TestCaseName, Iterators)
{
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(2, 3);
	graph.AddEdge(2, 1);
	graph.AddEdge(1, 3);
	//NodeConstIterator<int> iter( graph);
	//NodeConstIterator<int> iter2(graph);
	//iter2++;
	//iter.end();
	////iter2 = iter.back();
	EdgeReverseIterator<int> iter(&graph);
	EdgeReverseIterator<int> iter2(&graph);
	iter2++;
	iter2.erase();
	iter.rend();
	iter--;
	iter2 = iter.rback();

	EdgeConstIterator<int> it1(graph);
	EdgeConstIterator<int> it2(graph);
	it2.end();
	it1 = it2.back();

	/*NodeAdjacentConstIterator<int> adj1(graph, iter2);
	adj1++;
	adj1.end();

	EdgeAdjacentConstIterator<int> adjEdge(graph, iter2);
	EdgeAdjacentConstIterator<int> adjEdge2(graph, iter2);
	adjEdge++;
	adjEdge--;
	adjEdge2 = adjEdge.next();*/

	/*NodeIterator<int> itr(&graph);
	itr.erase();*/

	EdgeIterator<int> edgeitr(&graph);
	edgeitr.erase();



	typename vector<int>::iterator it;
	graph.AddEdge(2, 3);
	graph.AddEdge(2, 1);
	graph.AddEdge(1,3);
	it = graph.begin();
	it = graph.next(it);
	it = graph.RemoveByIterator(it);
	EXPECT_EQ(3, *it);
	try {
		it = graph.previous(it);
	}
	catch (const exception& ex)
	{
	}
	it = graph.next(it);
	EXPECT_EQ(3, *it);
	it = graph.end();
	it = graph.previous(it);
	it = graph.previous(it);
	cout << graph;
	EXPECT_EQ(1, *it);
}

TEST(TestCaseName, GraphAddEdge) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 3);
	try {
		bool presense = graph.PresenceOfEdge(1, 3);
		EXPECT_TRUE(presense);
	}
	catch (const exception& ex)
	{}
}

TEST(TestCaseName, GraphRemoveVertexAndEmpty) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(3, 2);
	graph.AddEdge(1, 3);
	graph.RemoveVertex(1);
	EXPECT_TRUE(!graph.PresenceOfVertex(1));
}

TEST(TestCaseName, GraphRemoveEdge) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(3, 2);
	graph.AddEdge(2, 3);
	Graph<int>gr = graph;
	graph.RemoveEdge(2, 3);
	try {
		bool presense = graph.PresenceOfEdge(3, 2);
		EXPECT_TRUE(!presense);
	}
	catch (const exception& ex)
	{}
}

TEST(TestCaseName, GraphClear) {
	Graph<int> graph({ 1, 2 });
	graph.clear();
	EXPECT_TRUE(graph.empty());
}

TEST(TestCaseName, GraphOperator) {
	Graph<int> graph1({ 1, 2,3,4 });
	graph1.AddEdge(1, 3);
	graph1.AddEdge(1, 2);
	Graph<int> graph2({ 1, 2,3 });
	graph2.AddEdge(1, 3);
	graph2.AddEdge(1, 2);
	EXPECT_TRUE((graph1 > graph2));
	EXPECT_TRUE((graph2 < graph1));
	graph1.RemoveVertex(4);
	EXPECT_TRUE((graph2 == graph1));
}

TEST(TestCaseName, GraphVertexDegree) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 3);
	EXPECT_EQ(-1, graph.DegreeOfVertex(8));
	EXPECT_EQ(2, graph.DegreeOfVertex(1));
}

TEST(TestCaseName, GraphEdgeDegree) {
	Graph<int> graph({ 1, 2,3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 3);
	pair<int, int> degree;
	degree = graph.DegreeOfEdge(1, 3);
	EXPECT_EQ(2, degree.first);
	EXPECT_EQ(1, degree.second);
}

TEST(TestCaseName, GraphEdgeAmount) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(2, 3);
	graph.AddEdge(3, 1);
	EXPECT_EQ(3, graph.AmountOfEdges());
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
