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

	int n, lph;
	cin >> n >> lph;

	vi dp(lph * 5 + 1, 0);
	vector<bool> reachable(lph*5 +1, false);
	reachable[0] = true;

	vi nums(n);
	for(auto &x : nums) cin >> x;

	int total = lph *5;
	for(auto x : nums) {
		for(int i = total - x; i >= 0; i--) {
			if(reachable[i]) {
				dp[i + x] = max(dp[i+x], dp[i] + 1);
				reachable[i+x] = true;
			}
		}
	}

	int maxi = 0;
	for(auto x : dp) maxi = max(maxi, x);
	cout << maxi << '\n';

	return 0;
}