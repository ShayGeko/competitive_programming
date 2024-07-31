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

    vi dp(n + 1, 1e9);

    dp[0] = 0;

    int ans = 0;
    rep(i, 0, n) {
        auto it = lower_bound(all(dp), nums[i]);

        int idx =  it - dp.begin();
        dp[idx] = nums[i];
        ans = max(ans, idx);
    }


    cout << ans << '\n';


	return 0;
}