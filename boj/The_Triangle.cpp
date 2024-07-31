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

    vector<vi> nums(n);

    rep(i, 0, n) {
        nums[i] = vi(i+1);
        for(auto &x : nums[i]) cin >> x;
    }

    vector<vi> dp(n);
    rep(i, 0, n) dp[i] = vi(n+1,0);

    rep(j, 0, n) dp[n-1][j] = nums[n-1][j];
    for(int i = n-2; i>= 0; i--) {
        rep(j, 0, n) {
           dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + nums[i][j];
        }
    }


    cout << dp[0][0] << '\n';



	return 0;
}