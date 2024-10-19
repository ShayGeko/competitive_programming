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
        cin >> a >> b >> c;
        --a;--b;
        adj[a].push_back({b, c});
    }

    int a, b;
    cin >> a >> b;
    --a;--b;
    const int inf = 1e9;
    vi d(n, inf);

    d[a] = 0;
    vi p(n, -1);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, a});
    while(!pq.empty()) {
        auto [cost, v] = pq.top();pq.pop();

        if(cost > d[v]) continue;

        for(auto [to, c] : adj[v]) {
            if(cost + c < d[to]) {
                d[to] = cost + c;
                pq.push({d[to], to});
                p[to] = v;
            }
        }
    }

    vi path;
    int cur = b;
    do {
        path.push_back(cur+1);
        cur = p[cur];
    } while(cur != -1);

    reverse(all(path));
    cout << d[b] << '\n';
    cout << sz(path) << '\n';
    for(auto x : path) cout << x << " ";
    cout << '\n';


	return 0;
}