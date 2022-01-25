#include <bits/stdc++.h>
using namespace std;
const int MAXN = 130;
const int INF = 1e9;

vector<int> adj[MAXN];
int capacity[MAXN][MAXN] = {{0}};
bool used[MAXN];

int flow(int v, int t, int bottleneck){
    if(v == t) return bottleneck;
    used[v] = true;
    for(auto to : adj[v]){
        if(used[to] || capacity[v][to] <= 0) continue;

        int f = flow(to, t, min(bottleneck, capacity[v][to]));

        if(f > 0){
            capacity[to][v]+= f;
            capacity[v][to]-= f;
            return f;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    char a, b;
    int c;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        cin >> c;
        capacity[a][b]+=c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int maxflow = 0;
    int f;
    while((f = flow('A', 'Z', INF)) > 0){
        maxflow +=f;
        memset(used, 0, sizeof(used));
    }
    cout << maxflow << '\n';

    return 0;
}