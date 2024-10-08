#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const double EPS = 1E-9;

struct pt {
    double x, y;
};

struct seg {
    pt p, q;
    int id;

    double get_y(double x) const {
        if (abs(p.x - q.x) < EPS)
            return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};

bool intersect1d(double l1, double r1, double l2, double r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + EPS;
}

int vec(const pt& a, const pt& b, const pt& c) {
    double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg& a, const seg& b)
{
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg& a, const seg& b)
{
    double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - EPS;
}

struct event {
    double x;
    int tp, id;

    event() {}
    event(double x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator<(const event& e) const {
        if (abs(x - e.x) > EPS)
            return x < e.x;
        return tp > e.tp;
    }
};

set<seg> s;
vector<set<seg>::iterator> where;

set<seg>::iterator prev(set<seg>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<seg>::iterator next(set<seg>::iterator it) {
    return ++it;
}

pair<int, int> solve(const vector<seg>& a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(e.begin(), e.end());

    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); ++i) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, a[id]))
                return make_pair(prv->id, id);
            where[id] = s.insert(nxt, a[id]);
        } else {
            set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            s.erase(where[id]);
        }
    }

    return make_pair(-1, -1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	
	vector<seg> segments;

	segments.reserve(n);

	vector<event> timeline; timeline.reserve(2*n);
	rep(i, 0, n) {
		T s1, s2, e1, e2;
		cin >> s1 >> s2 >> e1 >> e2;
		P st = P(s1,s2), en =  P(e1, e2);

		if(en < st) swap(st, en);
		segments.push_back({st, en});

		timeline.push_back({st.x, 0, i, st.y});
		timeline.push_back({en.x, 1, i, en.y});
	}
	sort(all(timeline));

	set<pair<T, int>> sweepline;

	pii ans = {-1, -1};

	auto check_intersect = [&](int id, int other_id) {
		auto &[cur_s, cur_e] = segments[id];
		auto &[prv_s, prv_e] = segments[other_id];

		auto intersections = segInter(cur_s, cur_e, prv_s, prv_e);
		if(intersections.size()) {
			if(id > other_id) swap(id, other_id);
			ans = {id, other_id};
			return true;
		}

		return false;
	};
	for(auto &[x,isEnd, id, y] : timeline) {
		auto [cur_s, cur_e] = segments[id];
		if(isEnd) {
			auto it = sweepline.find({cur_s.y, id});
			auto nxt = sweepline.erase(it);

			if(nxt != sweepline.begin() && nxt != sweepline.end()) {
				auto prv = prev(nxt);

				auto [__, id_a] = *prv;
				auto [___, id_b] = *nxt;

				if(check_intersect(id_a, id_b)) {
					break;
				}
			}
		} else {
			auto [it, _] = sweepline.insert({y, id});
			auto nxt = next(it), prv = prev(it);

			if(it != sweepline.begin()) {
				auto other = prev(it);
				auto [__, other_id] = *other;

				if(check_intersect(id, other_id)) {
					break;
				}
			}

			if(nxt != sweepline.end()) {
				auto [__, other_id] = *nxt;

				if(check_intersect(id, other_id)) {
					break;
				}
			}
		}
	}


	if(ans.first == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans.first + 1 << " " << ans.second + 1 << '\n';
	}
 
	return 0;
}