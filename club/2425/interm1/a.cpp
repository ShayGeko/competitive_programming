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
	vi nums(n);
	for(auto &x : nums) cin >> x;

	vi dp(n);dp[0] = 0;

	dp[1] = abs(nums[0] - nums[1]);
	rep(i, 2, n) {
		dp[i] = min(
			dp[i-1] + abs(nums[i] - nums[i-1]), 
			   dp[i-2] + abs(nums[i] - nums[i-2]));
	}
	cout << dp[n-1];
	return 0;
}