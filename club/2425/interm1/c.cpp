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
	vector<string> grid(n);
	rep(i, 0, n) cin >> grid[i];

	vector<vector<ll>> dp(n,vector<ll>(n, 0));
	dp[0][0] = grid[0][0] != '*';
	rep(i, 1, n) {
		dp[i][0] = (grid[i][0] == '*') ? 0 : dp[i-1][0];
		dp[0][i] = (grid[0][i] == '*') ? 0 : dp[0][i-1];
	}

	const ll p = 1e9+7;
	rep(i, 1, n) rep(j, 1, n) {
		if(grid[i][j] == '*') dp[i][j] = 0;
		else dp[i][j] = ((ll)dp[i-1][j] + dp[i][j-1]) % p;
	}

	cout << dp[n-1][n-1] << '\n';
	return 0;
}