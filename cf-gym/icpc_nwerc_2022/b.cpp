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

	int h1, rr, d1, d2;
	cin >> h1 >> rr >> d1 >> d2;

	// find h2 -> minimize (h1 * d1 + h2 * d2)/2;

	long double l = 0, r = h1;

	auto f = [&](long double h2) {
		auto density = ((h1-h2) * d1 + h2 * d2) / (h1 + h2);
		return (h2/2.0 * (d2 * h2) + (h2 + (h1 - h2)/2) * (d1 * (h1 - h2))) / (h2 * d2 + (h1 - h2)*d1);
	};
	while(r - l > 1e-8) {
		long double m1 = l + (r-l) / 3.0;
		long double m2 = l +  (r - l ) / 3.0 * 2.0;

		auto f1 = f(m1), f2 = f(m2);
		if(f1 == f2) {
			l = m1;
			r = m2;
		} else if(f1 < f2) {
			r = m2;
		} else l = m1;
	}

	cout << fixed << setprecision(10) <<  l << '\n';

	return 0;
}