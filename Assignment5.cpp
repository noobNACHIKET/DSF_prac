#include <iostream>
#include <vector>
#include <climits>
using namespace std;
const int V = 6; // number of vertices
int min_distance(int dist[], bool visited[]) {
 int min_dist = INT_MAX, min_index;
 for (int v = 0; v < V; v++) {
 if (!visited[v] && dist[v] <= min_dist) {
 min_dist = dist[v];
 min_index = v;
 }
 }
 return min_index;
}
void dijkstra(int graph[V][V], int src) {
 int dist[V];
 bool visited[V];
 for (int i = 0; i < V; i++) {
 dist[i] = INT_MAX;
 visited[i] = false;
 }
 dist[src] = 0;
 for (int i = 0; i < V - 1; i++) {
 int u = min_distance(dist, visited);
 visited[u] = true;
 for (int v = 0; v < V; v++) {
 if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
 dist[u] + graph[u][v] < dist[v]) {
 dist[v] = dist[u] + graph[u][v];
 }
 }
 }
 cout << "Shortest distances from source " << src << ":\n";
 for (int i = 0; i < V; i++) {
 cout << i << ": " << dist[i] << "\n";
 }
}
int main() {
 int graph[V][V] = {
 {0, 4, 2, 3, 1, 2},
 {2, 5, 4, 3, 2, 4},
 {1, 3, 0, 6, 4, 1},
 {4, 2, 3, 0, 5, 6},
 {2, 1, 4, 1, 0, 3},
 {3, 6, 2, 5, 3, 0}
};
 dijkstra(graph, 0);
 return 0;
}