#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	Node *l=nullptr, *r=nullptr;
	ll tL, tR;
	pair<ll, int> val = {-1,0};

	Node(ll tL, ll tR): tL(tL), tR(tR) {}


	void update(ll idx, int x, int y) {
		// cout << tL << " " << tR << '\n';
		if(tL == tR) {
			// only actually update if it is better
			if(x > val.first)
				val = {x, y};
			return;
		}

		ll m = tL + (tR - tL) / 2;

		if(!l) {
			l = new Node(tL, m);
			r = new Node(m+1, tR);
		}

		if(idx <= m) {
			l->update(idx, x, y);
		} else r->update(idx, x, y);

		val = max(l->val, r->val);
	}

	pair<ll,int> query(ll qL, ll qR) {
		// cout << tL << " " << tR << '\n';
		if(qL > qR) return {-1, 0};
		if(qL == tL && qR == tR) return val;

		ll m = tL + (tR - tL) / 2;

		auto leftVal = l? l->query(qL, min(m, qR)) : pair<ll,int>{-1, 0};
		auto rightVal = r? r->query(max(m+1, qL), qR) : pair<ll,int>{-1, 0};

		return max(leftVal, rightVal);
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, d;
	cin >> n >> d;

	vector<ll> H(n+1);
	for(auto &x : H) cin >> x;

	vi parent(n+1);

	const ll inf = 1e15+1;
	Node* node = new Node(0, inf);
	for(int i = n - 1; i >= 0; i--) {
		ll smallBnd = H[i] - d, bigBnd = H[i] + d;
		auto jumpSmall = node->query(0, smallBnd);
		auto jumpBig = node->query(bigBnd, inf);

		auto best = max(jumpSmall, jumpBig);
		if(best.first < 0) {
			parent[i] = i;
		} else parent[i] = best.second;

		node->update(H[i], best.first+1, i);
	}

	vi path;
	int cur = 0;

	while(cur != parent[cur]) {
		path.push_back(cur+1);
		cur = parent[cur];
	}
	path.push_back(cur+1);
	
	cout << path.size() << '\n';
	for(auto x : path) cout << x << " ";
	cout << '\n';

	return 0;
}