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

	for(auto & x : nums) cin >> x;

	const int inf = 1e9 + 7;
	vi dp(n+1, inf);


	for(auto x : nums){
		auto it = lower_bound(all(dp), x);
		*it = x;
	}

	int ans = 0;
	while(ans < n && dp[ans] < inf) ++ans;

	cout << ans << '\n';

	return 0;
}