#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

const int inf = 1e9;
struct Node {
	int Z = 20;
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0;
	deque<int> val;
	Node(int lo,int hi, int sz = 20):lo(lo),hi(hi), val(sz, 0){} // Large interval of -inf
	Node(vi& v, int lo, int hi, int sz = 20) : lo(lo), hi(hi), val(sz, 0) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			rep(i, 0, Z) val[i] = l->val[i] + r->val[i];
		}
		else if(v[lo] >= 0) ++val[v[lo]];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val[0];
		push();
		return l->query(L, R) +  r->query(L, R);
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R){
			mset = x, madd = 0;
			fill(all(val), 0);
			val[x] = R - L;
		} 
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			rep(i, 0, Z) {
				val[i] = l->val[i] + r->val[i];
			}
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			rep(i, 0, x) {
				// val represents positive difference to pos
				// adding one = removing the dif = 0 guys (dif is -1 for them)
				val.pop_front();
				val.push_back(0);
			}
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			rep(i, 0, Z) {
				val[i] = l->val[i] + r->val[i];
			}
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}

	void cleanup() {
		if(l != nullptr) l->cleanup();
		if(r != nullptr) r->cleanup();
		delete this;
	}
};

void solve() {
	int n, k, d;
	cin >> n >> k >> d;

	vi nums(n);
	rep(i, 0, n) cin >> nums[i];
	vi B(k);
	for(auto &x : B) cin >> x;

	// problem is really about figuring out when to stop with the initial array
	// at some point increasing the score is worse than cashing out and getting 1 every second turn
	vi dif(n);
	int score = 0;
	int posi = 0;
	int maxdif = 0;
	rep(i, 0, n) {
		dif[i] = i + 1 - nums[i];
		maxdif = max(dif[i], maxdif);
		if(!dif[i]) ++score;
		else if(dif[i] > 0) ++posi;
	}
	Node* tr = new Node(dif, 0, sz(dif));
	ll maxscore = 0;

	rep(i, 0, min(max(k, 2000), d)) {
		ll cur = 0;
		// cash out on day i + every second day
		cur = tr->query(0, n) + (d - i-1) / 2;

		maxscore = max(maxscore, cur);

		tr->add(0, B[i % k] + 1, 1);
	}

	cout << maxscore << '\n';
	tr->cleanup();
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}