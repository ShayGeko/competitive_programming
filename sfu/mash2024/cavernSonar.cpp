#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef pair<double, double> pdd;

pdd operator+ (pdd a, pdd b) {
	return {a.first + b.first, a.second + b.second};
}
pdd operator- (pdd a, pdd b) {
	return {a.first - b.first, a.second - b.second};
}
pdd operator/ (pdd a, double b) {
	return {a.first / b, a.second / b};
}
ostream& operator<< (ostream &out, pdd &a) {
	out << a.first << " " << a.second;
	return out;
}
pdd bsearch1(double l, double r, double y) {
	while(abs(r-l) > 1e-6) {
		auto m = (r + l) / 2.;
		double dist;
		cout << fixed << setprecision(8) << "? " <<  m << " " << y << endl;
		cin >> dist;
		// dist = checker(m, y);
		if(dist <= -0.5) {
			r = m;
		} else {
			l = m;
		}
	}
	return {l, y};
}
pdd bsearch2(double l, double r, double x) {
	while(abs(r-l) > 1e-6) {
		auto m = (r + l) / 2.;
		cout << fixed << setprecision(8) <<  "? " << x << " " << m << endl;
		double dist;
		cin >> dist;
		// dist = checker(x, m);
		if(dist <= -0.5) {
			r = m;
		} else {
			l = m;
		}
	}
	return {x, l};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	double _;
	cin >> _;
	pdd L = bsearch1(0, -4000, 0),
	R = bsearch1(0, 4000, 0);
	pdd cx = (L + R) / 2.;
	double cent_x = cx.first;
	pdd U = bsearch2(0, 4000, cent_x);
	pdd D = bsearch2(0,-4000, cent_x);
	pdd O = (U + D) / 2;
	cout << fixed << setprecision(8) << "! " << O << endl;

	return 0;
}