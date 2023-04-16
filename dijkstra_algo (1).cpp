#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Graph class
class Graph {
    int num_vertices;
    vector<pair<int, int>>* adj_list;

public:
    // Constructor
    Graph(int V) {
        num_vertices = V;
        adj_list = new vector<pair<int, int>>[V];
    }

    // Method to add edge
    void addEdge(int u, int v, int weight) {
        adj_list[u].push_back(make_pair(v, weight));
        adj_list[v].push_back(make_pair(u, weight));
    }

    // Dijkstra's algorithm method
    void dijkstra(int start_vertex) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> distance(num_vertices, INT_MAX);
        pq.push(make_pair(0, start_vertex));
        distance[start_vertex] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto i = adj_list[u].begin(); i != adj_list[u].end(); i++) {
                int v = (*i).first;
                int weight = (*i).second;

                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        cout << "Shortest distances from vertex " << start_vertex << ":" << endl;
        for (int i = 0; i < num_vertices; i++) {
            cout << i << ": " << distance[i] << endl;
        }
    }
};

int main() {
    int num_vertices, num_edges;
    cout << "Enter the number of vertices: ";
    cin >> num_vertices;

    Graph graph(num_vertices);

    cout << "Enter the number of edges: ";
    cin >> num_edges;

    for (int i = 0; i < num_edges; i++) {
        int u, v, weight;
        cout << "Enter edge " << i+1 << " (u v weight): ";
        cin >> u >> v >> weight;

        graph.addEdge(u, v, weight);
    }

    int start_vertex;
    cout << "Enter the starting vertex: ";
    cin >> start_vertex;

    graph.dijkstra(start_vertex);

    return 0;
 }
// enter the number of vertices: 4
// Enter the number of edges: 5
// Enter edge 1 (u v weight): 0 1 1
// Enter edge 2 (u v weight): 0 2 5
// Enter edge 3 (u v weight): 1 2 2
// Enter edge 4 (u v weight): 1 3 6
// Enter edge 5 (u v weight): 2 3 3
// Enter the starting vertex: 0
// Shortest distances from vertex 0:
// 0: 0
// 1: 1
// 2: 3
// 3: 6