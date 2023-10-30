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

	rep(i, 0, n) cin >> nums[i];

	vi prgcd(n), sfgcd(n);
	prgcd[0] = nums[0];
	sfgcd[n-1] = nums[n-1];

	rep(i, 1, n) {
		prgcd[i] = __gcd(prgcd[i-1], nums[i]);
		sfgcd[n-1-i] = __gcd(sfgcd[n-i], nums[n-1-i]);
	}

	int ans = sfgcd[1];
	rep(i, 1, n-1) {
		ans = max(ans, __gcd(prgcd[i-1], sfgcd[i+1]));
	}
	ans = max(ans, prgcd[n-2]);

	cout << ans << '\n';
	return 0;
}