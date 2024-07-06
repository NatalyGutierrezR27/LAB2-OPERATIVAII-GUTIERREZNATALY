#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

void floydWarshall(std::vector<std::vector<int>>& graph, int V) {
    std::vector<std::vector<int>> dist(graph);

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Imprimir la matriz de distancias
    std::cout << "Matriz de distancias más cortas:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                std::cout << "INF\t";
            else
                std::cout << dist[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int main() {
    int V = 4; // Número de vértices
    std::vector<std::vector<int>> graph = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(graph, V);

    return 0;
}
