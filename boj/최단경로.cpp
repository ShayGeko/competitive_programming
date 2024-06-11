#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;

    int st;
    cin >> st;
    --st;

    vector<vector<pii>> adj(n);

    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        adj[a].push_back({b, c});
    }
    vi D1(n, 1e9);

    auto dijkstra = [](vector<vector<pii>> &adj, vi &D, int start) {
        D[start] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, start});
        while(!pq.empty()) {
            auto [d, v] = pq.top(); pq.pop();
            if(D[v] < d) continue;

            for(auto [to, cost] : adj[v]) {
                int newval = d + cost;
                if(D[to] >newval) {
                    D[to] = newval;
                    pq.push({newval, to});
                }
            }
        }
    };

    dijkstra(adj, D1, st);
    
    for(auto x : D1) {
        if(x == 1e9) cout << "INF\n";
        else cout << x << '\n';
    }
    
	return 0;
}