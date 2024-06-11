#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int n, int k) {
	vector<vi> nums(n, vi(2));

	for(auto &x : nums) cin >> x[0] >> x[1];

	// pos #closed config (00 01 10)

	ll sum = 0;
	for(auto x : nums) sum += x[0] + x[1];
	if(k == 0) {
		cout << sum << '\n';
		return;
	}
	vector<vector<vi>> dp(n, vector<vi>(k+1, vi(3, 1e9)));

	dp[0][0][0] = 0;
	dp[0][1][1] = nums[0][0];
	dp[0][1][2] = nums[0][1];

	rep(i, 1, n) {
		dp[i][0][0] = 0;
		rep(j, 1, min(i+1, k) + 1) {
			int mini = 1e9;
			rep(t, 0, 3) {
				mini = min(mini, dp[i-1][j][t]);
			}

			dp[i][j][0] = mini;

			// can get to 01 either from 00 or from 01
			dp[i][j][1] = nums[i][0] + min(dp[i-1][j-1][0], dp[i-1][j-1][1]);
			dp[i][j][2] = nums[i][1] + min(dp[i-1][j-1][0], dp[i-1][j-1][2]);
		}
	}

	

	int mini = 1e9;
	rep(i, 0, 3) mini = min(mini, dp[n-1][k][i]);

	// cout << sum << " " << mini << '\n';
	cout << max(0LL, sum - mini) << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, k;
	while(cin >> n >> k && n > 0) {
		solve(n, k);
	}
}