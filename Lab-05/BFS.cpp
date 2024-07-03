#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// Graph class using adjacency list representation
class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    // Function to add an edge to the graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w); // Add w to v's list
    }
    // Breadth-First Search (BFS) traversal
    void BFS(int start)
    {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        queue<int> queue;               // Create a queue for BFS
        visited[start] = true;          // Mark the current node as visited and enqueue it
        queue.push(start);
        while (!queue.empty())
        {
            int current = queue.front(); // Dequeue a vertex from queue and print it
            cout << current << " ";
            queue.pop();
            // Get all adjacent vertices of the dequeued vertex current
            // If an adjacent vertex has not been visited, then mark it visited and enqueue it
            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
        cout << endl;
    }
    
};
    // Main function
    int main()
    {
        // Create a graph given in the example
        Graph g(6);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(2, 4);
        g.addEdge(3, 5);
        g.addEdge(4, 5);
        cout << "BFS starting from vertex 0: ";
        g.BFS(0);
        return 0;
    }