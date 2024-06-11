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
	for(auto &x : nums) cin >> x;

	vector<ll> dp(n, 1e15);

	dp[0] = nums[0];

	multiset<int> foods;
	ll sum = 0;
	rep(i, 0, n) {
		foods.insert(nums[i]);
		if(foods.size() > 7) {
			auto it = foods.find(nums[i-7]);
			foods.erase(it);
		}

		sum += *foods.begin();
	}
	cout << sum << '\n';
	return 0;
}