#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll getDifSum(vector<ll> &nums, ll x) {
	ll sum = 0;

	for(int t : nums) sum += abs(t - x);

	return sum;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vector<ll> nums(n);

	rep(i, 0, n) {
		cin >> nums[i];
	}
	ll mini = nums[0], maxi = nums[0];
	for(ll x : nums) {
		mini = min(mini, x);
		maxi = max(maxi, x);
	}

	ll l = mini, r = maxi;

	while(r - l > 5) {
		int m1 = (2*l + r) / 3, m2 = (2*r + l) /  3;

		ll y1 = getDifSum(nums, m1), y2 = getDifSum(nums, m2);

		if(y1 == y2) {
			l = m1, r = m2;
		} else if (y1 < y2) {
			r = m2;
		} else {
			l = m1;
		}
	}
	ll by = getDifSum(nums, l);

	rep(x, l+1, r+1) {
		ll y = getDifSum(nums, x);
		if(y < by) {
			by = y;
		}
	}

	cout << by << '\n'; 
	return 0;
}