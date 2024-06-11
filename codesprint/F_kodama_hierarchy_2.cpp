#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
5
1 5
2 1
3 2
4 3
5 4

*/


struct bNode {
	bNode *l = NULL, *r = NULL;
	int SeqLen = 0; // maybe 1?
	int lo, hi;
	bool isTerminal = true;
	bool isTerminalFlag = false;

	
	bNode(int lo, int hi): lo(lo), hi(hi) {}

	void update(int b, int seqLen) {
		if(lo == hi) {
			SeqLen = seqLen;
			isTerminal = false;
		}

		int m = lo + (hi - lo) / 2;
		if(b <= m) {
			if(!l) l = new bNode(lo, m);
			l->update(b, seqLen);

			SeqLen = max(SeqLen, l->SeqLen);
		} else {
			if(!r) r = new bNode(m+1, hi);
			r->update(b, seqLen);
			SeqLen = max(SeqLen, r->SeqLen);
		}
	}

	int query(int ql, int qr) {
		if(ql > qr) return 0;
		if(lo == ql && hi == qr) {
			return SeqLen;
		}

		int m = lo + (hi - lo) / 2;
		int ans = 0;

		if(l) {
			ans = max(l->query(ql, min(m, qr)), ans);
		}
		if(r) {
			ans = max(r->query(max(m+1, ql), qr), ans);
		}
		
		return ans;
	}

};
struct aNode {
	aNode* l = NULL, *r = NULL;
	bNode* nodeb;

	int SeqLen;
	bool isTerminal = false;

	bool isTerminalFlag;

	int lo, hi;

	aNode(int lo, int hi): lo(lo), hi(hi) {}

	void update(int a, int b, int seqLen) {
		if(lo == hi) {
			nodeb->update(b,seqLen);
		}
		int m = lo + (hi - lo) / 2;
		if(b <= m) {
			if(!l) l = new aNode(lo, m);
			l->update(a,b, seqLen);

			SeqLen = max(SeqLen, l->SeqLen);
		} else {
			if(!r) r = new aNode(m+1, hi);
			r->update(a, b, seqLen);
			SeqLen = max(SeqLen, r->SeqLen);
		}
	}
};



const int inf = 1e9;







struct Node1 {
	Node1 *l = 0, *r = 0;
	int lo, hi;
	int mset = inf, madd = 0, val = -inf;
	Node1(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node1(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node1(v, lo, mid); r = new Node1(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node1(lo, mid); r = new Node1(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<pii> ab(n);
	for(auto &x : ab) cin >> x.first >> x.second;

	sort(all(ab));

	vector<int> b(n);
	rep(i, 0, n) b[i] = ab[i].second;

	// find shortest maximal increasing subsequence
	vector<int> dp(n+1, 1e9+1);
	vi idx(n+1, 1e9);
	int k = 0;
	dp[0] = -1;
	idx[0]=-1;
	
	vector<bool> terminal(n, true);
	vector<int> LIS(n);

	vector<vi> history(n+1);
	vector<vi> history_idx(n+1);
	rep(i, 0, n) {
		auto t = b[i];
		auto it = lower_bound(dp.begin(), dp.begin() + k + 1, t);
		auto pos = distance(dp.begin(), it);
		
		// (a,b)
		// 2 5
		// 4 1


		// (2, 1) (3, 1)* (3, 2) -> (2, 1) (3,2)
		// (3, 1) (3, 2)* (4, 2) -> (2, 1) (3,2)
 		if(pos > 1) {
			if (idx[pos] > n){
				auto ppos = pos-1;
				// label all values less than cur as non-terminal in last cell's history
				auto it1 = lower_bound(history[ppos].rbegin(), history[ppos].rend(), t);
				it1 = prev(it1);
				auto pos1 = distance(history[ppos].rbegin(), it1);
				
				pos1 = sz(history[ppos]) - pos1 -1;
				rep(j, pos1, sz(history[ppos])) {
					terminal[history_idx[ppos][j]] = false;
				}
			}
		}

		dp[pos] = t;
		idx[pos]=i;
		history[pos].push_back(t);
		history_idx[pos].push_back(i);
		k = max(k, (int)pos + 1);
		LIS[i] = pos;
		
	}

	int ans = 1e9;
	rep(i, 0, n) {
		if(terminal[i]) ans = min(ans, LIS[i]);
	}

	cout << ans << '\n';


	return 0;
}