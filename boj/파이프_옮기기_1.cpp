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

    size_t n;
    cin >> n;
    vector<vi> nums(n, vi(n));
    for(auto &x : nums) for(auto &y : x) cin >> y;

    vector<vector<vi>> dp(n, vector(n, vi(3, 0)));
    dp[0][1][0] = 1; // start is always empty
    rep(i, 1, n) {
        if(nums[0][i]) break;
        dp[0][i][0] += dp[0][i-1][0];
    }
    rep(i, 1, n) {
        rep(j, 1, n) {
            if(nums[i][j]) continue;
            dp[i][j][0] += dp[i][j-1][0];
            dp[i][j][0] += dp[i][j-1][2];

            dp[i][j][1] += dp[i-1][j][1];
            dp[i][j][1] += dp[i-1][j][2];

            
            if(nums[i-1][j] || nums[i][j-1]) continue;
            dp[i][j][2] += dp[i-1][j-1][0] + dp[i-1][j-1][1];
            dp[i][j][2] += dp[i-1][j-1][2];
        }
    }

    int sum = 0;
    rep(k, 0, 3) sum += dp[n-1][n-1][k];
    cout << sum << '\n';

	return 0;
}