#include<bits/stdc++.h>
using namespace std;

struct Pair {
    int v;       // Destination vertex
    int weight;  // Weight of the edge
};

void bellmanFord(vector<Pair> adjacencyList[], int V, int source) {
    const int INF = 0x7F7F7F7F;
    vector<int> distance(V, INF); // Initialize distances to all nodes as infinity
    vector<int> parent(V, -1);    // To store the shortest path tree

    distance[source] = 0; // Distance to source is 0

    // Relax edges up to (V - 1) times
    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (Pair p : adjacencyList[u]) {
                int v = p.v;
                int weight = p.weight;
                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (Pair p : adjacencyList[u]) {
            int v = p.v;
            int weight = p.weight;
            if (distance[u] != INF && distance[u] + weight < distance[v]) {
                cout << "Graph contains a negative-weight cycle" << endl;
                return;
            }
        }
    }

    // Print the distances
    cout << "Distances: ";
    for (int i = 0; i < V; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;

    // Print shortest paths
    cout << "Paths: " << endl;
    for (int i = 0; i < V; i++) {
        if (distance[i] == INF) continue;
        cout << "Path to " << i << ": ";
        int node = i;
        stack<int> path;
        while (node != -1) {
            path.push(node);
            node = parent[node];
        }
        while (!path.empty()) {
            cout << path.top() << " ";
            path.pop();
        }
        cout << endl;
    }
}

int main() {
    int V = 4; // Number of vertices
    vector<Pair> adjacencyList[V];

    // Graph edges and their respective costs (including negative edge values)
    adjacencyList[0] = {{1, 5}, {2, -2}};  // Node 0 connects to 1 with weight 5, and to 2 with weight -2
    adjacencyList[1] = {{2, -1}, {3, 2}};  // Node 1 connects to 2 with weight -1, and to 3 with weight 2
    adjacencyList[2] = {{3, 1}};           // Node 2 connects to 3 with weight 1
    adjacencyList[3] = {{0, 2}};           // Node 3 connects to 0 with weight 2


    int source = 0; // Source node for the Bellman-Ford algorithm
    bellmanFord(adjacencyList, V, source);

    return 0;
}
