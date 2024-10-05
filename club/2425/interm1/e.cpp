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
	vi nums(n);
	rep(i, 0, n) {
		cin >> nums[i];
	}

	vector<bool> dp(k+1, false);
	for(auto x : nums) dp[x] = 1;

	rep(i, 1, k+1) {
		rep(j, 0, n) {
			if(nums[j] > i) continue;
			if(!(dp[i-nums[j]])) {
				dp[i] = true;
				break;
			}
		}
	}

	if(dp[k]) cout << "First\n";
	else cout << "Second\n";

	return 0;
}