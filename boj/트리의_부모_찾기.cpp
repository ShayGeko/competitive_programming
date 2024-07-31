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

    vector<vi> adj(n);
    rep(i, 0, n - 1) {
        int a, b;

        cin >> a >> b;
        --a;--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi p(n);
    function<void(int)> dfs = [&](int v) {
        for(auto to : adj[v]) {
            if(to == p[v]) continue;
            p[to] = v;
            dfs(to);
        }
    };

    dfs(0);

    rep(i, 1, n) {
        cout << p[i] + 1 << '\n';
    }
	return 0;
}