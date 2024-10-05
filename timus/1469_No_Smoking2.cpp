#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


// ===========================CODEBOOK==========================
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

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

// ======================END CODEBOOK==========================


int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	
	typedef int T;
	typedef Point<T> P;
	vector<pair<P, P>> segments;

	segments.reserve(n);

    // x, type, idx, y
	typedef tuple<T, bool, int, T> event;

	vector<event> timeline;
    timeline.reserve(2*n);
	rep(i, 0, n) {
		T s1, s2, e1, e2;
		cin >> s1 >> s2 >> e1 >> e2;
		P st = P(s1,s2), en =  P(e1, e2);

		if(en < st) swap(st, en);
		segments.push_back({st, en});

		timeline.push_back({st.x, 0, i, st.y});
		// timeline.push_back({en.x, 0, i, en.y});
		timeline.push_back({en.x, 1, i, en.y});
	}

    // sort timeline by x coord and by start/end -> start goes before end
	sort(all(timeline));

    typedef tuple<T, int> sweep_event;
    set<sweep_event> sweep;


    auto intersect = [&](int ida, int idb) {
        if(ida == idb) return false;
        auto [a1, a2] = segments[ida];
        auto [b1, b2] = segments[idb];

        if(segInter(a1, a2, b1,b2).size()) {
            cout << "YES\n";
            if(ida > idb) swap(ida, idb);
            cout << ida +1 << " " << idb + 1 << '\n';
            return true;
        } return false;
    };
    for(auto e : timeline) {
        auto [x, isDelete, idx, y] = e;

        if(!isDelete) {
            auto [it, _] = sweep.insert({y, idx});


            if (it != sweep.begin()) {
                auto prv = prev(it);
                // check intersect cur prev
                auto [c_y, c_id] = *it;
                auto [p_y, p_id] = *prv;

                if(intersect(c_id, p_id)) return 0;

            }
            if(next(it) != sweep.end())  {
                // check intersect cur nxt
                auto nxt = next(it);
                auto [c_y, c_id] = *it;
                auto [n_y, n_id] = *nxt;

                if(intersect(c_id, n_id)) return 0;
            }
        } else {
            // get the segm by id
            auto segm = segments[idx];
            auto [st_x, st_y] = segm.first;
            auto [en_x, en_y] = segm.second;

            auto it = sweep.find({en_y, idx});

            auto prv = it, nxt = it;

            if(it != sweep.begin()) prv = prev(it);
            if(next(it) != sweep.end()) nxt = next(it);

            if(prv != nxt) {
                auto [ya, ida] = *prv;
                auto [yb, idb] = *nxt;

                if(intersect(ida, idb)) return 0;
            }
        }
    }

    cout << "NO\n";
	return 0;
}