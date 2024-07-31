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

    int n; cin >> n;
    vi nums(n);
    for(auto &x : nums) cin >> x;
    const int inf = 1e9;
    vi mpos(n);

    vi dp(n+1, inf);
    dp[0] = 0;

    rep(i, 0, n) {
        auto it = lower_bound(all(dp), nums[i]);
        *it = nums[i];
        mpos[i] = it - dp.begin();
    }

    dp = vi(n, inf);
    dp[0] = 0;
    reverse(all(nums));

    int longest = 0;
    rep(i, 0, n) {
        auto it = lower_bound(all(dp), nums[i]);
        *it = nums[i];
        int cur = it - dp.begin();
        
        longest = max(longest, mpos[n-1 - i] + cur - 1);
    }

    cout << longest << '\n';
	return 0;
}