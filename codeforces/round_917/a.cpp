#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	vi nums(n);

	bool negXor = false, hasNeg = false;
	bool hasZero = false;
	ll maxneg = -1e10;
	int maxnegind = 0;
	for(int i = 0; i < n; ++i) {
		cin >> nums[i];
		ll x = nums[i];
		if(x == 0) hasZero = true;
		else if(x < 0) {
			hasNeg = true;
			negXor = !negXor;
			if(x > maxneg) {
				maxneg = max(maxneg, (ll)x);
				maxnegind = i;
			}
		}
	}

	ll product = 1;

	if(hasZero) {
		cout << 0 << '\n';
	}
	else if(hasNeg) {
		if(negXor) {
			for(auto x : nums) product *= x;
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n' << 1 << " " << 0 << '\n';
		}
	} else {
		cout << 1 << '\n';
		cout << 1 << " " << 0 << '\n';
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}