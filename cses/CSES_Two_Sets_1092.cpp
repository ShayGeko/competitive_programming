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
	rep(i, 0, n) nums[i] = i + 1;

	ll sum = 0;
	rep(i, 0, n) sum += nums[i];

	if(sum % 2) {
		cout << "NO\n";
		return 0;
	}

	ll l = 0, r = 0;
	reverse(nums.begin(), nums.end());

	vector<int> Left, Right;

	rep(i, 0, n) {
		if(l + nums[i] <= sum / 2) {
			Left.push_back(nums[i]);
			l += nums[i];
		} else {
			Right.push_back(nums[i]);
		}
	}

	cout << "YES\n";
	cout << Left.size() << '\n';
	for(auto x : Left) cout << x << " "; cout << '\n';
	cout << Right.size() << '\n';
	for(auto x : Right) cout << x << " "; cout << '\n';

	return 0;
}