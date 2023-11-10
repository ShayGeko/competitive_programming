#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
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

	vi a(n), b(n);

	rep(i, 0, n) cin >> a[i];
	rep(i,0,n) cin >> b[i];

	ll l = 0, r = 2e9+2;

	while(r>l) {
		ll m = (l + r+1) / 2;

		ll kk = k;

		bool possible = true;
		rep(i, 0 && possible, n) {
			if(kk < 0 || kk < m * a[i] - b[i]) {
				possible = false;
			}
			else {
				kk -= max(0LL, m * a[i] - b[i]);
			}
		}

		if(possible) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	cout << l << '\n';
	return 0;
}