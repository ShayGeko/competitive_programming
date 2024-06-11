#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};




int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vector<Point<double>> pts(n);

	for(auto &x : pts) cin >> x.x >> x.y;

	int mask = 1 << n;


	double best = 1e15;
	rep(i, 0, n) {
		rep(j, i+1, n) {
			auto vec = pts[j] - pts[i];
			auto ax = vec / vec.dist();
			auto ay = ax.perp();

			vector<vector<double>> dist(n, vector<double>(n));

			rep(ii, 0, n) {
				rep(jj, 0, n) {
					auto vec1 = pts[ii] - pts[jj];
					double d = abs(vec1.dot(ax)) + abs(vec1.dot(ay));
					dist[ii][jj]=d;
				}
			}
			
			int max_mask = (1<<n) - 1;
			map<pii, double> dp;
			function<double(int, int)> tsp = [&](int mask, int v) {
				if(__builtin_popcount(mask) == 1) return 0.0;
				if(dp[{mask, v}]) return dp[{mask, v}];

				dp[{mask, v}] = 1e15;
				rep(i, 0, n) {
					if(i == v) continue;
					if((mask & (1 << i))) {
						double d = dist[v][i];
						int mask1 = mask ^ (1 << v);

						dp[{mask, v}] = min(dp[{mask, v}], tsp(mask1, i) + d);
					}
				}

				return dp[{mask, v}];
			};

			rep(v, 0, n) best = min(best, tsp(max_mask, v));
		}
	}

	cout << fixed << setprecision(10) <<  best << '\n';

	return 0;
}