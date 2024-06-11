#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a +b ; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		if(e <= b) return 0;
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

struct Node {
	Node *l, *r;
	int Tl, Tr;
	vector<int> st;
	Tree t;

	
	Node(int Tl, int Tr): l(NULL), r(NULL), Tl(Tl), Tr(Tr) {}

	void build(vi &nums) {
		if(Tl >= sz(nums)) return;
		if(Tl == Tr) {
			st = vi{nums[Tl]};
		} else {
			int m = (Tl + Tr) / 2;
			l = new Node(Tl, m);
			r = new Node(m+1, Tr);

			l->build(nums);
			r->build(nums);

			st.clear();
			merge(all(l->st), all(r->st), back_inserter(st));
		}
		t = Tree(sz(st));
		rep(i, 0, sz(st)) {
			t.update(i, st[i]);
		}
	}

	pair<ll, int> query (int ql, int qr, int x) {
		if(ql > qr) return {0, 0};
		if(ql == Tl && qr == Tr) {
			auto it = upper_bound(all(st), x);
			auto pos = distance(st.begin(), it) - 1;
			return {t.query(0, pos+1), pos+1}; // inclusive
		}

		int m = (Tl + Tr) / 2;
		auto [a1, b1] = l->query(ql, min(qr, m), x);
		auto [a2, b2] = r->query(max(m+1, ql), qr, x);
		return {a1 + a2, b1 + b2};
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


	int n, q;
	cin >> n >> q;

	vi nums(n);
	for(auto &x : nums) cin >> x;

	vector<ll> prsum(n+1);
	prsum[0] = 0;
	rep(i, 0, n) prsum[i+1] = prsum[i] + nums[i];

	Node* st = new Node(0, n-1);

	st->build(nums);

	rep(i, 0, q) {
		int l, r, e;
		cin >> l >> r >> e;
		--l;--r;

		auto [x, cnt] = st->query(l, r, e);
		ll ans  = prsum[r+1] - prsum[l];
		cout << ans - x - ((ll)r-l+1 - cnt) * e << '\n';
	}
	return 0;
}