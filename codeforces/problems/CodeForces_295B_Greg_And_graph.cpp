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
	vector<vi> d(n, vi(n));

	rep(i, 0, n)rep(j, 0, n)cin >> d[i][j];

	vi del(n);
	rep(i, 0, n) {
		cin >> del[i];
		--del[i];
	}
	reverse(all(del));

	vector<ll> ans(n, 0);
	rep(t, 0, n) {
		// add v
		int k = del[t];
		
		rep(i, 0, n) {
			rep(j, 0, n) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}

		rep(i, 0, t +1) rep(j, 0, t+1) ans[t] += d[del[i]][del[j]];
	}
	for(int i = n-1; i>=0; --i) {
		cout << ans[i] << " ";
	}
	cout << '\n';

	return 0;
}