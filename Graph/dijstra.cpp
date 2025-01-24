#include<bits/stdc++.h>
using namespace std;

// Defining a constant INF with a high value to represent infinity for shortest path calculations
const int INF = 0x7F7F7F7F;

// A structure to represent an edge in the graph
struct Pair
{
    int v;             // The destination vertex
    int cost_u_v;      // The cost (weight) of the edge from the source vertex to destination vertex v
};

// A structure to represent a node and its corresponding shortest distance in the graph
struct NodeDistance
{
    int node;          // The node/vertex ID
    int distance;      // The shortest distance from the source node to this node
};

// A custom comparator structure used by the priority queue to prioritize nodes with shorter distances
struct CompareByDistance
{
    bool operator()(NodeDistance left, NodeDistance right)
    {
        // If the distance to the left node is greater than to the right node, return true (left is "greater")
        return left.distance > right.distance;
    }
};

// A helper function to recursively print the shortest path from the source to the destination
void path_print(int parent[], int destination)
{
    // If the destination is its own parent, print the destination and return (base case)
    if(parent[destination] == destination)
    {
        cout << destination << " ";
        return;
    }
    // Otherwise, recursively print the path from the parent of the destination
    else
    {
        path_print(parent, parent[destination]);
        cout << destination << " ";
    }
}

// Dijkstra's algorithm to compute the shortest paths from the source node to all other nodes
void dijkstra(vector< Pair > adjacencyList[], int source, int V)
{
    // Priority queue (min-heap) to always expand the node with the smallest cumulative distance
    priority_queue< NodeDistance, vector< NodeDistance>, CompareByDistance > PQ;

    // Array to store the shortest distances from source to each node
    int d[V];

    // Array to store the parent of each node (to reconstruct the shortest path)
    int parent[V];

    // Array to track whether the optimal path to each node has been found
    int found_optimal_path[V] = {0};

    // Initialize all distances to infinity, and parents to self (i.e., a node is its own parent initially)
    for(int i = 0; i < V; i++)
    {
        d[i] = INF;   // All nodes initially have infinite distance
        parent[i] = i; // Initially, the parent of each node is the node itself
    }

    // The distance to the source node is 0 (it's the starting point)
    d[source] = 0;

    // Push the source node with distance 0 into the priority queue
    PQ.push({source, d[source]});

    // Set the source node as its own parent (since it's the starting point)
    parent[source] = source;

    // Main loop of Dijkstra's algorithm: process nodes in order of increasing distance
    while(!PQ.empty())
    {
        // Extract the node with the smallest cumulative distance
        NodeDistance nodeDistance = PQ.top();
        PQ.pop();

        int node = nodeDistance.node;  // The current node being processed
        found_optimal_path[node] = 1;  // Mark this node as processed (optimal path found)

        // Explore all neighbors of the current node
        for(Pair p : adjacencyList[node])
        {
            // Relax the edge (u, v) if a shorter path to v through u is found
            if(d[node] + p.cost_u_v < d[p.v])
            {
                // Update the distance to v
                d[p.v] = d[node] + p.cost_u_v;

                // Push the updated node into the priority queue
                PQ.push({p.v, d[p.v]});

                // Update the parent of v (to reconstruct the shortest path)
                parent[p.v] = node;
            }
        }
    }

    // Output the computed shortest distances from the source to all nodes
    cout << "Distance: ";
    for(int i = 0; i < V; i++)
    {
        cout << d[i] << " ";
    }
    cout << endl;

    // Output the parent array, which is used to reconstruct the shortest paths
    cout << "Parent: ";
    for(int i = 0; i < V; i++)
    {
        cout << parent[i] << " ";
    }
    cout << endl;

    // Output the shortest paths from the source to all other nodes
    cout << "Shortest Paths: \n";
    for(int i = 0; i < V; i++)
    {
        cout << source << " to " << i << " : ";
        path_print(parent, i); // Reconstruct and print the shortest path from source to node i
        cout << endl;
    }
}

int main()
{
    int V = 4;  // Number of vertices in the graph

    // Adjacency list to represent the graph
    vector< Pair > adjacencyList[V];

    // Graph edges and their respective costs (pairs of destination vertex and edge weight)
    adjacencyList[0] = {{1, 2}, {2, 5}};  // Node 0 connects to 1 with weight 2, and to 2 with weight 5
    adjacencyList[1] = {{2, 2}, {3, 10}}; // Node 1 connects to 2 with weight 2, and to 3 with weight 10
    adjacencyList[2] = {{3, 6}};          // Node 2 connects to 3 with weight 6
    adjacencyList[3] = {{2, 8}};          // Node 3 connects to 2 with weight 8

    int source = 0; // The source node for the Dijkstra algorithm (node 0)

    // Call Dijkstra's algorithm to compute shortest paths from source to all nodes
    dijkstra(adjacencyList, source, V);

    return 0;
}
