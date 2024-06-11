#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template <class T>
struct Point{
	typedef Point<T> P;

	T x, y;

    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T cross(P b) {
		return x * b.y - y * b.x;
	}
	T dot(P b) {
		return x * b.x + y * b.y;
	}

	friend istream& operator>> (istream& in, P &b) {
		in >> b.x >> b.y;
		return in;
	}
};


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


	int t; cin >> t;
	while(t--) {
		Point<double> a, b, c, d;
		cin >> a >> b >> c >> d;

		// if(a == c || a == d || b == c || b == d) {
		// 	cout << "YES\n";
		// 	continue;
		// }

		double BAC = (b - a).cross(c-a), BAD = (b-a).cross(d-a);

		double DCB = (d - c).cross(b-c), DCA = (d - c).cross(a-c);

		auto check = [](double a1, double a2, double b1, double b2) {
			return min(a1, a2) >= max(b1, b2) && max(a1, a2) <= min(b1, b2);
		};
		auto sgn = [](double x) {
			return x < 0 ? -1 : (x == 0 ? 0 : 1);
		};
		cout << sgn(BAC) << " " << sgn(BAD) << " " << sgn(DCB) << " " << sgn(DCA) << '\n';
		if((BAC * BAD < 0 && DCB * DCA < 0) 
			|| (BAC * BAD == 0 && DCB * DCA == 0 && check(a.x, b.x, c.x, d.x) && check(a.y, b.y, c.y, d.y))) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}