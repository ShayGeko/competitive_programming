#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef struct node {
	node *l, *r;
	int Tl, Tr;
	int val;
	node (int Tl, int Tr, int val) : l(NULL), r(NULL), Tl(Tl), Tr(Tr), val(val){}
	node (node * a) : l(a->l), r(a->r), Tl(a->Tl), Tr(a->Tr), val(a->val) {}
	node (node* a, int inc) : l(a->l), r(a->r), Tl(a->Tl), Tr(a->Tr), val(a->val + inc) {}
	void add(int ind, int x) {
		if(Tl == Tr) {
			val += x;
			return;
		}
		
		if (ind <= Tl + (Tr - Tl)/ 2) {
			if(!l) {
				l = new node(Tl, Tl + (Tr - Tl)/ 2, 0);
			} else l = new node (l);
			l->add(ind, x);
		} else {
			if(!r) {
				r = new node(Tl + (Tr - Tl)/ 2 + 1, Tr, 0);
			} else r = new node(r);
			r->add(ind, x);
		}
		
		val = 0;
		if(l) val += l->val;
		if(r) val += r->val;
		return;
	}

	int query(int ql, int qr) {
		if(ql > qr) return 0;
		if(Tl == ql && Tr == qr) {
			return val;
		}

		int ans = 0;
		if(l) ans += l->query(ql, min(l->Tr, qr));
		if(r) ans += r->query(max(r->Tl, ql), qr);

		return ans;
	}
} Node;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vi nums(n);
	for(auto &x : nums) cin >> x;

	vector<Node*> roots;
	roots.push_back(new Node(0, 1e9+1, 0));

	for(auto x : nums) {
		auto newroot = new Node(roots.back());
		newroot->add(x, 1);
		roots.push_back(newroot);
	}
	int q;
	cin >> q;
	rep(t, 0, q) {
		int i, j, k;
		cin >> i >> j >> k;

		int upper = roots[j]->query(k+1, 1e9+1);
		int lower = roots[i-1]->query(k+1, 1e9+1);

		cout << upper - lower << '\n';
	}
	return 0;
}