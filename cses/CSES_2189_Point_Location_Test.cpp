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

	T cross(P b) {
		return x * b.y - y * b.x;
	}
	T dot(P b) {
		return x * b.x + y * b.y;
	}

	friend P operator- (P a, P b) {
		return P(a.x - b.x, a.y - b.y);
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
		Point<double> a, b, c;
		cin >> a >> b >> c;

		auto a1 = a - c;
		auto b1 = b - c;

		auto sign = a1.cross(b1);

		if(sign > 0) {
			cout << "LEFT\n";
		} else if(sign < 0) {
			cout << "RIGHT\n";
		} else {
			cout << "TOUCH\n";
		}
	}
	return 0;
}