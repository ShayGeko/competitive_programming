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

    vector<vector<pii>> adj(n);

    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int a, b;
    cin >> a >> b;
    --a;--b;
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

    dijkstra(adj, D1, a);
    int maxi = 0;
    
    if(D1[0] == 1e9 || D1[n-1] == 1e9) {
        cout << -1 << '\n';
        return 0;
    }
    
    vi D2(n, 1e9);
    dijkstra(adj, D2, b);
    if(D2[0] == 1e9 || D2[n-1] == 1e9) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = min(D1[0] + D1[b] + D2[n-1], D2[0] + D2[a] + D1[n-1]);

    cout << ans << '\n';
	return 0;
}