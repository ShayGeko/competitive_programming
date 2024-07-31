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

    int n, m;
    cin >> n >> m;
    

    vector<vector<pii>> adj(n);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >>b >> c;
        --a;--b;
        adj[a].push_back({b, c});
    }

    const int inf = 1e9+7;
    vector<ll> d(n, inf);
    int a, b;
    cin >> a >>b;
    --a; --b;
    d[a] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, a});

    // vi p(n);
    while(!pq.empty()) {
        auto [cost, v] = pq.top();pq.pop();

        if(v == b) {
            cout << cost << '\n';
            break;
        }
        if(cost > d[v]) continue;

        for(auto [to, dist] : adj[v]) {
            if((ll)cost + dist < d[to]) {
                d[to] = cost + dist;
                pq.push({d[to], to});
                // p[to] = v;
            }
        }
    }

    // int cur = b;

    // do {
    //     cout << cur << " " << d[cur] << '\n';
    //     cur = p[cur];
    // } while(cur != a);

	return 0;
}