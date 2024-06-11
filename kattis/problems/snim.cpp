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
	// cin.exceptions(cin.failbit);

	int k; cin >> k;
	vi S(k);
	for(auto &x : S) cin >> x;

	sort(all(S));

	vi dp(10001);

	rep(i, 0, 10001) {
		set<int> mex;

		for(int j = 0; j < sz(S) && S[j] <= i; ++j) {
			mex.insert(dp[i-S[j]]);
		}

		int k = 0;
		int prev = -1;
		for(auto x : mex) {
			if(x == k) {
				++k; ++prev;
			} else {
				break;
			}
		}
		dp[i] = prev+1;
	}


	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi nums(n);
		for(auto &x : nums) cin >> x;

		int ans = 0;
		for(auto x : nums) ans ^= dp[x];

		if(!ans) cout << "L";
		else cout << "W";
	}
	cout << '\n';

	return 0;
}