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

	int n, m;
	vector<ll> nums;
	while(cin >> n) {
		cin >> m;
		nums.clear();
		nums.resize(m);
		for(auto &x : nums) cin >> x;

		ll ans = 0;
		rep(mask, 0, 1 << m) {
			ll lcm = 1;
			ll gcd;
			rep(i, 0, m) {
				int bit = 1 << i;
				if(mask & bit) {
					gcd = __gcd(lcm, nums[i]);
					lcm = nums[i] / gcd * lcm;
				}
				if(lcm > n) break;
			}

			if(__builtin_popcount(mask) % 2 == 0) {
				ans += n / lcm;
			}
			else {
				ans -= n / lcm;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}