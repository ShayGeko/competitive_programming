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

    vector<vi> cost(n, vi(3));

    for(auto &x : cost) for(auto &y : x) cin >> y;

    vector<vi> dp(n, vi(3, 1e9));

    dp[0] = cost[0];

    rep(i, 1, n) {
        rep(j, 0, 3) {
            dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]) + cost[i][j];
        }
    }

    int ans = *min_element(all(dp[n-1]));
    cout << ans << '\n';
	return 0;
}