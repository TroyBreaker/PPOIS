#include "gtest/gtest.h"
#include "Graph.h"
using namespace NotOrientedGraph;

TEST(TestCaseName, GraphAddVertex)
{
	Graph<int> graph({ 1, 2, 3 });
	graph.AddVertex(4);
	EXPECT_EQ(4, graph.AmountOfVertices());
	EXPECT_TRUE(graph.PresenceOfVertex(4));
}

TEST(TestCaseName, GraphAddEdge) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 3);
	EXPECT_TRUE(graph.PresenceOfEdge(1, 3));
}

TEST(TestCaseName, GraphRemoveVertexAndEmpty) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(3, 2);
	graph.AddEdge(1, 3);
	graph.RemoveVertex(2);
}

TEST(TestCaseName, GraphRemoveEdge) {
	Graph<int> graph({ 1, 2, 3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(3, 2);
	graph.AddEdge(1, 3);
	Graph<int>gr = graph;
	graph.RemoveEdge(2, 3);
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
	EXPECT_EQ(2, graph.DegreeOfVertex(1));
}

TEST(TestCaseName, GraphEdgeDegree) {
	Graph<int> graph({ 1, 2,3 });
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 3);
	EXPECT_EQ(1, graph.DegreeOfEdge(1, 2));
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
