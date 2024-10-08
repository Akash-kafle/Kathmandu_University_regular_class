#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>

template <typename T>
extern void print(const T &value)
{
    std::cout << value << ' ';
}

class Graph
{
public:
    Graph(bool directed);

    bool isEmpty() const;
    bool isDirected() const;
    void addVertex(int newVertex, int value = 0);
    void addEdge(int vertex1, int vertex2, int weight);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVertices() const;
    int numEdges() const;
    int indegree(int vertex) const;
    int outdegree(int vertex) const;
    int degree(int vertex) const;
    std::vector<int> neighbours(int vertex) const;
    bool neighbour(int vertex1, int vertex2) const;
    // std::unordered_map<int, int> min_spanning_tree(int start) const; // Yet to be implemented
    std::unordered_map<int, std::unordered_map<int, int>> getVertices() const
    {
        return vertices;
    }
    bool removed(int vertex) const
    {
        return removed_vertices.find(vertex) != removed_vertices.end();
    }

private:
    std::unordered_map<int, std::unordered_map<int, int>> vertices;
    std::unordered_set<int> removed_vertices;
    bool directed;
    int edge_count;
};

void BFT(const Graph &graph, int start);
void DFT(const Graph &graph, int start);