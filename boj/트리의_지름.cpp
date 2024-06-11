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

    int n;
    cin >> n;
    vector<vector<pii>> adj(n);
    rep(i, 0, n) {
        int k; cin >> k; --k;
        int x, y;
        while(cin >> x) {
            if(x == -1) break;
            cin >> y;
            --x;
            adj[k].emplace_back(x, y);
        }
    }

    
    vi D(n, 0);
    
    queue<pii> q;
    auto bfs = [&](int v) {
        q.push({v, -1});
        while(!q.empty()) {
            auto[v, p] = q.front();q.pop();

            for(auto [to, cost] : adj[v]) {
                if(to == p) continue;
                D[to] = D[v] + cost;
                q.push({to, v});
            }
        }
    };
    bfs(0);
    int v = max_element(all(D)) - D.begin();
    D[v] = 0;
    bfs(v);
    int u = max_element(all(D)) - D.begin();

    cout << D[u] << '\n';


	return 0;
}