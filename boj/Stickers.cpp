#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<char> pre, post, inorder;
vector<char> l, r;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<vi> nums(2, vi(n));

        rep(i, 0, 2) for(auto & x : nums[i]) cin >> x;


        vector<vi> dp(2, vi(n, 0));
        dp[0][0] = nums[0][0];
        dp[1][0] = nums[1][0];

        rep(j, 1, n) {
            rep(i, 0, 2) {
                dp[i][j] = max(dp[i][j-1], dp[1-i][j-1] + nums[i][j]);
            }
        }
        cout << max(dp[0][n-1], dp[1][n-1]) << '\n';
    }

	return 0;
}