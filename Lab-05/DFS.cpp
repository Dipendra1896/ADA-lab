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
    // Depth-First Search (DFS) traversal
    void DFS(int start)
    {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        stack<int> stack;               // Create a stack for DFS
        stack.push(start);              // Push the current source node
        while (!stack.empty())
        {
            int current = stack.top(); // Pop a vertex from stack and print it
            stack.pop();

            if (!visited[current])
            {
                cout << current << " ";
                visited[current] = true;
            }
            // Get all adjacent vertices of the popped vertex current
            // If an adjacent vertex has not been visited, then push it to the stack
            for (int i = adj[current].size() - 1; i >= 0; --i)
            {
                int neighbor = adj[current][i];
                if (!visited[neighbor])
                {
                    stack.push(neighbor);
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
    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    return 0;
}