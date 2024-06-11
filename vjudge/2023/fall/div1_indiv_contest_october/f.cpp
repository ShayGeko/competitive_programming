#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e3;
int t[MAXN][MAXN];
int A[MAXN][MAXN];
int n, m;

bool hasTriangle(vector<int> &a) {
	if(sz(a) < 3) return false;
	int l = 0, r = 2;

	do {
		if(a[r] < a[l] + a[l+1]) return true;
		++l;++r;
	} while(r <= sz(a));

	return false;
}

typedef struct Node_y {
	bool possible = false;
	int TL, TR;
	Node_y *l, *r;
	vector<int> vals;

	bool mergeNodes(Node_y *aa, Node_y * bb) {
		possible = aa && aa->possible || bb && bb->possible;
		if(possible) return;

		vi dummy = {};
		vi &a = aa? aa->vals : dummy;
		vi &b = bb? bb->vals : dummy;
		vals.reserve(min(61, sz(a) + sz(b)));
		int x = sz(a);
		merge(all(a), b.begin(), b.begin() + min(sz(b), 61-sz(a)), all(vals));
		possible = hasTriangle(vals);
	}
	bool mergeChildren() {
		return mergeNodes(l, r);
	}
} yNode;
yNode* createYNode(int TL, int TR);

vector<yNode*> roots;
void yBuild (yNode* v, int vx, int lx, int rx) {
	if(v->TL == v->TR) {
		if(lx == rx) {
			v->vals = {A[lx][v->TL]};
		} else {
			v->mergeNodes(roots[vx>>1], roots[(vx>>1)|1]);
		}
	} else {
		int m = (v->TL + v->TR) >> 1;
		if(!v->l) v->l = createYNode(v->TL, m);
		if(!v->r) v->r = createYNode(m+1, v->TR);
		yBuild(v->l,vx, lx,rx);
		yBuild(v->r, vx, lx,rx);

		v->mergeChildren();
	}
}
void xBuild(int vx, int lx, int rx) {
	if(lx != rx) {
		int mx = (lx + rx) >> 1;
		xBuild(vx<<1, lx, mx);
		xBuild((vx<<1)|1, mx+1, rx);
	}
	yBuild(roots[vx], vx, lx, rx);
}

bool yQuery(yNode* v, int ly, int ry) {
	if(!v || ly > ry) {
		return false;
	}
	if(ly == v->TL && ry == v->TR) {
		return v->possible;
	}
	return yQuery(v->l, ly, min(v->r->TR, ry))
		|| yQuery(v->r, max(v->r->TL, ly), ry)
		|| v->mergeChildren();
}

int xQuery (int vx, int xTL, int xTR, int lx, int rx, int ly, int ry) {
	if(lx > rx) {
		return 0;
	}
	if(lx == xTL && rx == xTR) {
		return yQuery(roots[vx], ly, ry);
	}

	int xTM = (xTL + xTR) >> 1;
	return xQuery(vx>>1, xTL, xTM, lx, min(rx, xTM), ly, ry)
		+ xQuery((vx>>1)|1, xTM+1, xTR, max(lx, xTM+1), rx, ly, ry);
}

void ySet(yNode *v, int vx, int lx, int rx, int x, int y, int val) {
	if(v->TL == v->TR) {
		if(lx == rx) {
			v->vals = {val};
		} else {
			v->mergeNodes(roots[vx>>1], roots[(vx>>1)|1]);
		}
	} else {
		int m = (v->TL + v->TR) >> 1;

		if(m >= y) {
			if(!v->l) v->l = createYNode(v->TL, m);
			ySet(v->l, vx, lx, rx, x, y, val);
		} else {
			if(!v->r) v->r = createYNode(m+1, v->TR);
			ySet(v->r, vx, lx, rx, x, y, val);
		}
	}

}
void xSet(int vx, int lx, int rx, int x, int y, int val) {
	if(lx != rx) {
		int mx = (lx + rx) >> 1;
		if(mx >= x) {
			xSet(vx<<1, lx, mx, x, y, val);
		} else {
			xSet((vx<<1)|1, mx+1, rx, x, y, val);
		}
	}
	ySet(roots[vx], vx, lx, rx, x,y,val);
} 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	set<int> xx, yy;
	vector<vi> pts(n);

	rep(i, 0, n) {
		int a, b, c;
		cin >> a >> b >> c;

		pts[i] = {a, b, c};
		xx.insert(a);
		yy.insert(b);
	}
	return 0;
}