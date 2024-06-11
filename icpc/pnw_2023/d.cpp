#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, m, mset = inf, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){m = lo + (hi-lo)/2;} // Large interval of -inf

	int query(int L, int R) {
		if (R < lo || hi < L) return inf;
		if (L == lo && hi == R) return val;
		push();
		int mini = inf;
		if(m >= L && l != nullptr) mini = l->query(L, min(m, R));
		if(m < R)  mini = min(mini, r->query(max(L, m+1), R));
		return mini + madd;
	}
	void add(int L, int R, int x) {
		if (R < lo || hi < L) return;
		if (L == lo && hi == R) {
			if(lo == hi) val += x;
			else  madd += x;
		}
		else {
			spawn_kids(),
			push();
			
			l->add(L, min(m, R), x), r->add(max(L, m+1), R, x);
			val = min(l->val, r->val);
		}
	}
	void spawn_kids() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
	}
	void push() {
		if(mset == inf && madd == 0) return;
		if (!l) {
			l = new Node(lo, m); r = new Node(m+1, hi);
		}
		if (madd)
			l->add(lo,m,madd), r->add(m+1,hi,madd), madd = 0;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int r, c,d,n;
	cin >> r >> c >> d >> n;

	vector<pii> students(n);

	for(auto &[a,b] : students) cin >> a >> b;

	map<int, Node*> segments;
	int dsq = d*d;
	auto  mbin_search1 = [&](int l, int r, int dsq, int y) {
		int dy;
		while(l-r > 1) {
			cout << l << " " << r << '\n';
			int m = r + (l - r) / 2;

			dy = m - y;

			if(dsq + dy*dy <= dsq) {
				l = m;
			} else r = m + 1;
		}
		return dy;
	};
	auto  mbin_search2 = [&](int l, int r, int dsq, int y) {
		int dy;
		while(r - l > 1) {
			cout << l << " " << r << '\n';
			int m = l + (r - l) / 2;

			dy = m - y;

			if(dsq + dy*dy <= dsq) {
				l = m;
			} else r = m - 1;
		}
		return dy;
	};

	// for every student, insert an interval in each column of discretized circle
	for(auto [a, b] : students) {
		ll top = b,btm = b;
		rep(i, max(1, a-d), min(c, a+d)) {
			int dx = abs(i-a);
			ll dxs = dx*dx;
			if(segments[i] == nullptr) {
				segments[i] = new Node(1, c+1);
			}

			bool sgn = i > a;
			int neg = 1 - sgn * 2;
			while(top >=1 && dxs + (top-b)*(top-b) <d*d)top-=neg;
			if((top-b)*(top-b) > d*d)top+=neg;

			while(btm <= r && dxs + (btm-b)*(btm-b) <d*d)btm+=neg;
			if((btm-b)*(btm-b) > d*d)btm-=neg;

			segments[i]->add(top, btm, 1);
			segments[a]->add(b,b,inf); // can never sit at occupied place
		}

	}

	// go through every column and find the minimum on entire segment
	int mini = 1e9;
	rep(i, 1, c+1) {
		auto st = segments[i];
		if(st == nullptr) {
			cout << "0\n";
			return 0;
		} else {
			int qans = st->query(1, r+1);
			mini = min(mini, qans);
		}
	}

	cout << mini << '\n';


	return 0;
}