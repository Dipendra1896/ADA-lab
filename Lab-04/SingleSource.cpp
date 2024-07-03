#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
// Define the structure to represent an edge in the graph
struct Edge
{
    int src, dest, weight;
};
// Function to print the solution
void printSolution(const vector<int> &dist, int V)
{
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}

// The main function that finds shortest distances from src to all other vertices using Bellman-Ford algorithm 
void BellmanFord(const vector<Edge> &edges, int V, int E, int src)
{
    // Initialize distance array
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    // Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; ++i)
    {
        for (int j = 0; j < E; ++j)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }
    // Check for negative-weight cycles
    for (int i = 0; i < E; ++i)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "Graph contains a negative weight cycle" << endl;
            return;
        }
    }
    // Print the solution
    printSolution(dist, V);
}
int main()
{
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    vector<Edge> edges = {
        {0, 1, -1}, {0, 3, 4}, {1, 2, 3}, {1, 4, 2}, {1, 4, 2}, {3, 2, 5}, {3, 2, 1}, {5, 3, -3}};
    int src = 0; // Source vertex
    BellmanFord(edges, V, E, src);

    return 0;
}