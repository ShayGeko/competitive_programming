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

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	int l = 0, r = n;

	while(l < r) {
		int m = (l + r) / 2;

		int ll = -m, rr = m;
		int cnt = 0;
		rep(i, max(0, ll), rr + 1) cnt += s[i] == '0';

		int best = s[(ll+rr)/2] == '0' ? cnt : 0;
		++ll;++rr;
		for(; rr < n + m; ++ll, ++rr) {
			if(ll > 0) cnt -= s[ll-1]=='0';
			if(rr < n) cnt += s[rr] == '0';
			if(s[(ll + rr) / 2] == '0') {
				best = max(best, cnt);
			}
		}

		if(best < k+1) {
			l = m+1;
		} else {
			r = m;
		}
	}

	cout << r << '\n';

	return 0;
}