#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to, weight;
};

class Graph {
private:
    int V;
    vector<vector<Edge>> adj;

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int from, int to, int weight) {
        adj[from].push_back({to, weight});
    }

    vector<int> dijkstra(int start) {
        vector<int> dist(V, INF);
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (const Edge& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    int V, E, start;
    cout << "Ingrese el numero de vertices: ";
    cin >> V;
    cout << "Ingrese el numero de aristas: ";
    cin >> E;

    Graph g(V);

    cout << "Ingrese las aristas (desde, hacia, peso):" << endl;
    for (int i = 0; i < E; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        g.addEdge(from, to, weight);
    }

    cout << "Ingrese el vertice de inicio: ";
    cin >> start;

    vector<int> distances = g.dijkstra(start);

    cout << "Distancias mas cortas desde el vertice " << start << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (distances[i] == INF)
            cout << "Vertice " << i << ": INF" << endl;
        else
            cout << "Vertice " << i << ": " << distances[i] << endl;
    }

    return 0;
}
