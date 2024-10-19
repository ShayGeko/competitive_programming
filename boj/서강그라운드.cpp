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

    int n, r, m;
    cin >> n >> r >> m;

    vi reward(n);
    for(auto & x : reward) cin >> x;

    const int inf = 1e9;
    vector<vi> dist(n, vi(n, inf));
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a;--b;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    rep(i, 0, n) dist[i][i] = 0;

    for(int k = 0; k < n; ++k) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                if(dist[i][k] != inf && dist[k][j] != inf)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i, 0, n) {
        int sum = 0;
        rep(j, 0, n) {
            if(dist[i][j] <= r) sum += reward[j];
        }
        ans = max(ans, sum);
    }
    cout << ans << '\n';

	return 0;
}