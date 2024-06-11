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
	// cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vector<int> nums(n);
	for(auto & x : nums) cin >> x;

	// Range dp with storing min and max?
	// dp[i, j][0] = max(dp[i+1, j][1], dp[i, j - 1][1])

	const ll INF = 1e18;
	vector<vector<ll>> dp(n+1, vector(n+1, INF));

	function<ll (int, int)> calc = [&](int i, int j) {
		if(i > j) return 0LL;
		if(i == j) {
			return (ll)nums[i];
		};
		// cout << i << " " << j << " " << k << '\n';
		if(dp[i][j] != INF) {
			return dp[i][j];
		}
		
		auto left = nums[i] + min(calc(i+2, j), calc(i+1, j-1));
		auto right = nums[j] + min(calc(i+1, j-1), calc(i, j-2)); 

		
		return dp[i][j] = max(left, right);
	};

	auto ans = calc(0, n-1);

	cout << ans << "\n";


	return 0;
}