#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


const int MAXN = 1e5;
vector<vector<pii>> xSegTree;

vector<vector<pii>> xyPts;


typedef struct _ {
	bool possible=false;
	vector<int> vals;
} trInfo;

vector<vector<trInfo>> ySegTrees;

bool hasTriangle(vector<int> &a) {
	if(a.size() > 70) return true;
	if(sz(a) < 3) return false;
	int l = 0, r = 2;

	do {
		if((ll)a[r] < (ll)a[l] + a[l+1]) return true;
		++l;++r;
	} while(r < sz(a));

	return false;
}
trInfo mergeNodes(trInfo &l, trInfo &r) {
	vi dummy = {};
	vi &a = l.vals;
	vi &b = r.vals;
	trInfo res = {
		.possible = l.possible || r.possible
	};
	res.vals = vi(min(100, sz(a) + sz(b)));
	int x = sz(a);
	merge(all(a), b.begin(), b.begin() + min(sz(b), 100-sz(a)), res.vals.begin());
	res.possible = hasTriangle(res.vals);

	return res;
}

void yBuild(int vx, int vy, int ly, int ry) {
	if(ly == ry) {
		ySegTrees[vx][vy] = trInfo{
			.possible = false,
			.vals = {xSegTree[vx][ly].second}
		};
	} else {
		int my = (ly + ry) >> 1;

		yBuild(vx, vy<<1, ly, my);
		yBuild(vx, (vy << 1) | 1, my+1, ry);

		// inconsistency between ySegTrees[vx][vy] and ySegTrees[vx][ly]
		ySegTrees[vx][vy] = mergeNodes(ySegTrees[vx][vy << 1], ySegTrees[vx][(vy << 1)|1]);
	}
}
void xyBuild(int vx, int tl, int tr) {
	if(tl > tr) return;
	if(tl == tr) {
		xSegTree[vx] = xyPts[tl];
	} else {
		int tm = (tl + tr) >> 1;

		int lIdx = vx << 1;
		int rIdx = lIdx | 1;
		xyBuild(lIdx, tl, tm);
		xyBuild(rIdx, tm + 1, tr);

		xSegTree[vx].resize(sz(xSegTree[lIdx]) + sz(xSegTree[rIdx]));
		merge(all(xSegTree[lIdx]), all(xSegTree[rIdx]), xSegTree[vx].begin());
	}

	ySegTrees[vx].resize(4*sz(xSegTree[vx]));
	yBuild(vx, 1, 0, sz(xSegTree[vx])-1);
}
trInfo yQuery (int vx, int vy, int TL, int TR, int l, int r) {
	if(l > r || TL > r || TR < l) {
		return {
			.possible = false,
			.vals = {}
		};
	}
	if(TL == l && TR == r) {
		return ySegTrees[vx][vy];
	} else {
		int TM = (TL + TR) >> 1;

		auto left = yQuery(vx, vy<<1, TL, TM, l, min(TM, r));
		auto right = yQuery(vx, (vy << 1) | 1, TM+1, TR, max(l, TM+1), r);

		return mergeNodes(left, right);
	}
}

trInfo xyQuery (int vx, int TL, int TR, int x1, int x2, int y1, int y2) {
	if(x1 > x2) {
		return {
			.possible = false,
			.vals = {}
		};
	}

	if(TL == x1 && TR == x2) {
		int l = lower_bound(all(xSegTree[vx]), pii{y1, 0}) - begin(xSegTree[vx]);
		int r = min(sz(xSegTree[vx]) - 1, (int)(lower_bound(all(xSegTree[vx]), pii{y2, 1e5+1}) - begin(xSegTree[vx])));
		return yQuery(vx, 1, 0, sz(xSegTree[vx]) - 1, l, r);
	}

	int TM = (TL + TR) >> 1;

	auto left = xyQuery(vx << 1, TL, TM, x1, min(TM, x2), y1, y2);
	auto right = xyQuery((vx << 1) | 1, TM + 1, TR, max(TM+1, x1), x2, y1, y2);
	return mergeNodes(left,right);
} 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	ordered_set<int> xx, yy;
	vector<vi> pts(n);

	rep(i, 0, n) {
		int a, b, c;
		cin >> a >> b >> c;

		pts[i] = {a, b, c};
		xx.insert(a);
		yy.insert(b);
	}

	xyPts = vector<vector<pii>> (sz(xx));

	rep(i, 0, n) {
		int x = xx.order_of_key(pts[i][0]);
		int y = yy.order_of_key(pts[i][1]);

		xyPts[x].push_back({y, pts[i][2]});
	}

	rep(i, 0, sz(xx)) {
		sort(all(xyPts[i]));
	}

	xSegTree.resize(xx.size() * 4);
	ySegTrees.resize(xx.size() * 4);

	// build segtree of vi zz, where query(v, x1, x2, TL, TR) -> all pts that have x in [x1, x2] sorted by y;
	// then, for each of those nodes, build a seg tree where query (v, x1, x2, y1, y2, TL, TR) returns
	// wheteher there is a triangle using pts with y in y1 y2, from a node with pts within [x1, x2];
	xyBuild(1, 0, sz(xx) - 1);

	rep(i, 0, m) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		auto lbx1 = xx.lower_bound(x1),
		 ubx2 = xx.upper_bound(x2),
		 lby1 = yy.lower_bound(y1),
		 uby2 = yy.upper_bound(y2);

		int xx1,xx2,yy1,yy2;

		xx1 = lbx1 == xx.end() ? xx.size()-1 : xx.order_of_key(*lbx1);
		xx2 = ubx2 == xx.end() ? xx.size()-1 : xx.order_of_key(*ubx2) - 1;
		yy1 = lby1 == yy.end() ? yy.size()-1 : yy.order_of_key(*lby1);
		yy2 = uby2 == yy.end() ? yy.size()-1 : yy.order_of_key(*uby2) - 1;

		auto info = xyQuery(1, 0, xx.size() - 1, xx1, xx2, yy1, yy2);

		cout << hasTriangle(info.vals) << '\n';
	}

	return 0;
}

/*
9 18
1 1 2
1 3 1
1 5 3
3 1 6
3 3 5
3 5 6
5 1 5
5 3 9
5 5 4
0 0 2 3
2 2 5 5
-1 -1 10 10
-4 -4 -1 -1
1 1 4 4
0 0 0 0
0 0 1 1
0 0 2 2
0 0 3 3
0 0 4 4
0 0 5 5
0 0 6 6
1 1 6 6
2 2 6 6
3 3 6 6
4 4 6 6
5 5 6 6
6 6 6 6
*/