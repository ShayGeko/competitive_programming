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
	
	int n, k, l;
	cin >> n >> k >> l;
	vi nums(n);
	for(auto &x : nums) cin >> x;

	sort(all(nums));

	vi common_div_cnt(1e6+2, 0);
	vi maxSpeed(1e6+2, 0);

	int ans; 
	for(auto x : nums) {
		int curHighest = 0;
		rep(div, 1, min(x+1, (int)(sqrt(x)+1))) { 
			if(x % div == 0) {
				// keep k slowest rabits for each common div
				if(common_div_cnt[div] < k) {
					++common_div_cnt[div];
					maxSpeed[div] = max(x, maxSpeed[div]);
				}
				if(div != x/div && common_div_cnt[x/div] < k) {
					++common_div_cnt[x/div];
					maxSpeed[x/div] = max(x, maxSpeed[x/div]);
				}
			}
		}
	}

	int mini = 1e9;
	rep(i, 1, sz(common_div_cnt)) {
		if(common_div_cnt[i] >= k) {
			mini = min(mini, l  * maxSpeed[i] / i);
		}
	}

	cout << mini << '\n';

	return 0;
}