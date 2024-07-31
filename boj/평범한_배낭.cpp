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

    int n, k;
    cin >> n >> k;

    vi w(n), c(n);
    rep(i, 0, n) cin >> w[i] >> c[i];

    vi dp(k+1, 0);
    dp[0] = 1;

    rep(i, 0, n) {
        for(int j = k - w[i]; j >= 0; --j) {
            if(dp[j]) dp[j + w[i]] = max(dp[j+w[i]], dp[j] + c[i]); 
        }
    }

    int ma = 0;
    rep(i, 0, k+1) ma = max(ma, dp[i]);

    cout << ma - 1 << '\n';

	return 0;
}