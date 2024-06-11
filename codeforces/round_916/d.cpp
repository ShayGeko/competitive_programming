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
	vi a(n), b(n), c(n);

	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	for(auto &x : c) cin >> x;

	int x=0, y=1, z=2;
	int bx = x, by = y, bz = z;
	ll bsum = a[x] + b[y] + c[z];
	rep(i, 0, 3) {
			rep(j, 0, 3) {
				if(i == j) continue;
				rep(k, 0, 3) {
					if(k == i || k == j) continue;
					if((ll)a[i] + b[j] + c[k] > bsum) {
						bx = i; by = j; bz = k;
						bsum = (ll) a[i] + b[j] + c[k];
					}
				}
			}
		}
	x = bx;y=by;z=bz;
	rep(v, 3, n) {
		int bx = x, by = y, bz = z;
		ll bsum = a[x] + b[y] + c[z];
		// get the best out of these 4 tuples
		vi o = vi{x, y, z, v};
		rep(i, 0, 4) {
			rep(j, 0, 4) {
				if(i == j) continue;
				rep(k, 0, 4) {
					if(k == i || k == j) continue;
					if((ll)a[o[i]] + b[o[j]] + c[o[k]] > bsum) {
						bx = o[i]; by = o[j]; bz = o[k];
						bsum = (ll) a[bx] + b[by] + c[bz];
					}
				}
			}
		}

		x = bx;
		y = by;
		z = bz;
	}

	cout << (ll)a[x] + b[y] + c[z] << '\n';
} 
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}