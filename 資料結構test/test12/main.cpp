#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start, vector<bool>& visited) {
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }

    void findConnectedComponents() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                cout << "Connected component: ";
                DFS(i, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << "The connected components are:" << endl;
    g.findConnectedComponents();

    return 0;
}
