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
    rep(i, 0, n-1) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        adj[a].push_back({b, c});
    }

    vector<pii> best_pair(n);
    vi D(n, 0);
    function<int(int, int)> dfs = [&](int v, int depth) {
        best_pair[v] = {0, 0};
        D[v] = depth;
        int m1 = 0, m2 = 0;
        for(auto to : adj[v]) {
            D[v] = max(dfs(to.first, depth + to.second), D[v]);
            
            if(D[to.first] > m1) {
                m2 = m1;
                m1 = D[to.first];
            }else m2 = max(m2, D[to.first]);
        }
        // cout << v << " " << D[v] << '\n';
        best_pair[v] = {m1-depth, m2-depth};
        return D[v];
    };
    dfs(0, 0);

    int maxi = 0;
    int sum = 0;
    rep(i, 0, n) {
        auto [mi, ma] = best_pair[i];
        if(mi + ma > sum) {
            sum = mi + ma;
            maxi = i;
        }
    }

    cout << sum << '\n';
	return 0;
}