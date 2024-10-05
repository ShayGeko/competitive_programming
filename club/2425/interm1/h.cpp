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

	int n, W;
	cin >> n >> W;
	vi v(n), w(n);

	rep(i, 0, n) cin >> w[i] >> v[i];

	vector<ll> dp(W+1, 0);
	vector<bool> possible(W+1, 0);
	possible[0] = true; 

	rep(i, 0, n) {
		for(int j = W; j >= 0; j--) {
			if(possible[j] && j + w[i] <= W) {
				dp[w[i] + j] = max(dp[w[i]+j], dp[j] + v[i]);
				possible[w[i]+j] = 1;
			}
		}
	}

	ll maxi = 0;
	rep(i, 0, W+1) {
		// cout << dp[i] << " ";
		maxi = max(maxi, dp[i]);
	}
	cout << '\n';
	cout << maxi << '\n';

	return 0;
}