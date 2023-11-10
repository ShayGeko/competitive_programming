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

	ll beds, pillows , k;
	cin >> beds >> pillows >> k;

	ll l = 0, r = pillows;

	while(l < r) {
		ll m = (l+r+1) / 2;

		bool possible = true;

		ll lremainder = max(0LL,k -1 - (m-1)), rremainder = max(0LL, beds - k - (m-1));
		ll lsteps = min(k-1, m-1), rsteps = min(m-1, beds-k);
		ll llast = max(1LL, m - (k-1)), rlast = max(1LL,  (m-beds+k));
		ll left = lremainder + (m-1 +llast)  * lsteps/ 2;
		ll right = rremainder + (m-1 + rlast)  * rsteps/ 2;

		if(m + left + right <= pillows) {
			l = m;
		} else {
			r = m - 1;
		}
	}

	cout << l << '\n';

	return 0;
}