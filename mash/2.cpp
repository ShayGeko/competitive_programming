#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <unordered_set>
#include <list>

using namespace std;

class Graph {
public:
    map<int, bool> visited;
    map<int, list<int>> adj;
 
    void a(int v, int w);
    void DFS(int v);
    bool r();
};
 
void Graph::a(int v, int w) {
    adj[v].push_back(w);
}
 
void Graph::DFS(int v)
{
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

bool Graph::r() {
    for (auto v : visited) {
        if (v.second == false) return false;
        visited[v.first] = false;
    }
    return true;
}
 
int main() {
    int n, m;
    bool flag = true;
    Graph g;

    cin >> n >> m;

    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        g.a(v1,v2);
    }

    for (int i = 1; i <= n; i++) {
        g.DFS(i);
        if (!g.r()) {
            flag = false;
            break;        
        }
    }

    if (flag) cout << "YES\n";
    else cout << "NO\n";
}