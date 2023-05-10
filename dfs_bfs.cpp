#include <iostream>

#include <vector>

#include <queue>

#include <stack>

using namespace std;
class Graph {
  private: int V;
  vector < int > * adj;
  public: Graph(int V) {
    this -> V = V;
    adj = new vector < int > [V];
  }
  void add_edge(int u, int v) {
    adj[u].push_back(v);
  }
  void BFS(int s) {
    vector < bool > visited(V, false);
    queue < int > q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
      s = q.front();
      cout << s << " ";
      q.pop();
      for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[ * i]) {
          visited[ * i] = true;
          q.push( * i);
        }
      }
    }
  }
  void DFS(int s) {
    vector < bool > visited(V, false);
    stack < int > stk;
    stk.push(s);
    while (!stk.empty()) {
      s = stk.top();
      stk.pop();
      if (!visited[s]) {
        cout << s << " ";
        visited[s] = true;
      }
      for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
        if (!visited[ * i])
          stk.push( * i);
      }
    }
  }
};
int main() {
  Graph g(4);
  g.add_edge(1, 2);
  g.add_edge(0, 1);
  g.add_edge(2, 3);
  g.add_edge(0, 2);
  g.add_edge(2, 0);
  g.add_edge(3, 3);
  cout << "BFS traversal starting from vertex 2: ";
  g.BFS(2);
  cout << "\nDFS traversal starting from vertex 2: ";
  g.DFS(2);
  return 0;
}