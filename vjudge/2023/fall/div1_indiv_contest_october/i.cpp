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

	int m,n,t;
	cin >> m >> n >> t;

	if((t == 1 && n > 12) || (t == 2 && n > 30) || (t == 3 && n > 200) || (t == 4 && n > 1000)) {
		cout << "TLE\n";
	} else {
		long long tim;

		if(t == 1) {
			tim = 1;
			rep(i, 1, n+1) tim *= i;
		} else if (t == 2) {
			tim = 1;
			tim <<= n;
		} else if (t == 3) {
			tim = pow((ll) n, 4);
		} else if(t == 4) {
			tim = pow((ll) n, 3);
		} else if(t == 5) {
			tim = pow((ll) n, 2);
		} else if(t == 6) {
			tim = ceil((double)n * log2(n));
		} else {
			tim = n;
		}

		if(tim > m) {
			cout << "TLE\n";
		} else {
			cout << "AC\n";
		}
	}
	return 0;
}