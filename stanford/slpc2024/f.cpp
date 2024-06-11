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

	vi a(n), b(n);
	rep(i, 0, n) cin >> a[i] >> b[i];

	unordered_map<ll, int> su, di;
	map<pii, int> pr;

	rep(i, 0, n) {
		++su[(ll)a[i]+b[i]];
		++di[(ll)a[i]-b[i]];
		++pr[{a[i], b[i]}];
	}


	// for any sum, find how many other sums equal this

	// for every dif, find how many other difs equal this
	ll ans = 0;
	rep(i, 0, n) {
		ll dup = pr[{a[i], b[i]}] - 1;
		ll sum = su[(ll)a[i] + b[i]] - 1;
		ll dif = di[(ll)a[i] - b[i]] - 1;

		ans += sum + dif - dup;
	}
	ll nn = n;
	assert((nn*(nn-1) - ans) % 2 == 0);
	cout << (nn*(nn-1) - ans) / 2 << '\n';
	return 0;
}