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
	cin.exceptions(cin.failbit);

    int n, m, target;
    cin >> n >> m >> target;
    --target;

    vector<vector<pii>> adj(n), rev_adj(n);

    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        adj[a].emplace_back(b, c);
        rev_adj[b].emplace_back(a, c);
    }

    vi D1(n, 1e9), D2(n, 1e9);

    auto dijkstra = [](vector<vector<pii>> &adj, vi &D, int target) {
        D[target] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, target});

        while(!pq.empty()) {
            auto [d, v] = pq.top(); pq.pop();
            if(D[v] < d) continue;

            for(auto [to, cost] : adj[v]) {
                if(D[to] > d + cost) {
                    D[to] = d + cost;
                    pq.push({d+cost, to});
                }
            }
        }
    };

    dijkstra(adj, D1, target);
    dijkstra(rev_adj, D2, target);
    int maxi = 0;
    // cout << "-----------------------------------\n";
    rep(i, 0, n) {
        // cout << i << " " << D1[i] << " " << D2[i] << '\n';
        maxi = max(maxi, D1[i] + D2[i]);
    }
    cout << maxi << '\n';
	return 0;
}