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
	
	ll s;
	cin >> s;

	long double lo = 0, hi = max(10. * sqrt(s), 4.);

	auto f1 = [&](double r) {
		ll s1 = 0;
		for(int x = floor(r); x > 0; x--) {
			int y = (int) sqrt(r*r - x*x);
			s1 += y;
		}
		return s1;
	};
	auto f = [&](double r) {
		return f1(r)*4 > s;
	};
	while(hi - lo > 1e-8) {
		double m = (hi + lo) / 2.;

		if(f(m)) hi = m;
		else lo = m;
	}

	cout << fixed << setprecision(8) << hi << '\n';

	return 0;
}