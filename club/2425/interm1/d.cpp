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
	
	vector<vi> act(n, vi(3));
	rep(i, 0, n) {
		rep(j, 0, 3) cin >> act[i][j];
	}

	vector<vi> dp(n, vi(3, 0));
	rep(i, 0, 3) dp[0][i] = act[0][i];

	rep(i, 1, n) {
		rep(j, 0, 3) {
			rep(k, 0, 3) {
				if(j == k) continue;
				dp[i][j] = max(dp[i][j], dp[i-1][k] + act[i][j]);
			}
		}
	}

	int maxi = 0;
	rep(i, 0, 3) maxi = max(maxi, dp[n-1][i]);
	cout << maxi << '\n';

	return 0;
}