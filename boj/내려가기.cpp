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

    vector<pair<ll, ll>> dp(3);
    vector<pair<ll, ll>> cur(3);

    int val;
    rep(i, 0, 3) {
        cin >> val;
        dp[i] = {val, val};
    }

    rep(i, 1, n) {
        rep(j, 0, 3) {
            cin >> val;
            cur[j] = dp[j];
            auto& [mi, ma] = cur[j];

            if(j){
                auto [l1,  l2] = dp[j-1];
                mi = min(mi, l1);
                ma = max(ma, l2);
            }
            if(j < 2){
                auto [l1,  l2] = dp[j+1];
                mi = min(mi, l1);
                ma = max(ma, l2);
            }
            mi += val;
            ma += val;
        }
        dp = cur;
    }

    auto [mi, ma] = dp[0];
    rep(i, 1,3) {
        auto [a, b] = dp[i];
        mi = min(mi, a);
        ma = max(ma, b);
    }
    cout << ma << " " << mi << '\n';


	return 0;
}