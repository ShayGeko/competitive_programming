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

trInfo mergeNodes(trInfo &l, trInfo &r) {
    vi dummy = {};
    vi &a = l.vals;
    vi &b = r.vals;
    trInfo res = {
        .possible = l.possible || r.possible
    };
    res.vals = vi(min(70, sz(a) + sz(b)));
    int x = sz(a);
    merge(all(a), b.begin(), b.begin() + min(sz(b), 70-sz(a)), res.vals.begin());
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

	int n;
	cin >> n;

	ordered_set<int> xx, yy;
    vector<vi> pts(n);
	vector<pii> ab(n);
	for(auto &x : ab) {
		cin >> x.first >> x.second;

		xx.insert(x.first);
		yy.insert(x.second);

	}

	// compress the coords
	for(auto &z : ab) {
		auto &[x, y] = z;
		x = xx.order_of_key(x);
		y = yy.order_of_key(y);
	}

	sort(all(ab));

	xSegTree.resize(xx.size() * 4);
    ySegTrees.resize(yy.size() * 4);

	xyBuild(1, 0, sz(xx) - 1);



	return 0;
}