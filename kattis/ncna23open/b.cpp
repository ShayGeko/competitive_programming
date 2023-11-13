#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll euclid (ll a, ll b, ll &x, ll&y) {
	if(!b) return x = 1, y = 0, a;
	ll d = euclid(b, a%b, y, x);
	return y-=a/b*x, d;
}

const ll mod = 1e9+7;
struct Mod {
	ll x;
	Mod() : x(0){}
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) {return Mod((x+b.x) % mod);}
	Mod operator- (Mod b) { return Mod((x - b.x + mod) % mod);}
	Mod operator* (Mod b) { return Mod((x*b.x) %mod);}
	Mod operator/ (Mod b) {return *this * invert(b); }
	bool operator< (const Mod b) {return x < b.x;}
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		assert(g == 1);return Mod((x+mod) % mod);
	}
	Mod operator^(ll e) {
		if(!e) return Mod(1);
		Mod r = *this ^ (e/2);r = r*r;
		return e&1 ? *this*r:r;
	}
};

struct Tree {
	typedef Mod T;
	const T unit= T(1);
	T f(T a, T b) {return a * b;}
	vector<T> s; int n;
	Tree (int n = 0, T def = Mod(1)) : s(2*n, def), n(n) {}
	void update (int pos, T val) {
		for(s[pos += n] = val; pos /=2;)
			s[pos] = f(s[pos*2], s[pos*2+1]);
	}
	T query(int b, int e) {
		T ra = unit, rb = unit;
		for(b += n, e += n; b < e; b/=2, e /=2) {
			if(b%2) ra = f(ra, s[b++]);
			if(e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	vector<Mod> digits;
	// + True, * false
	vector<bool> isPlus(n-1);

	rep(i, 0, n*2 - 1) {
		char c;
		cin >> c;
		if(i %2 == 0) digits.push_back(Mod(c-'0'));
		else {
			isPlus[i/2]=c=='+';
		}
	};

	
	// evaluate any run of *
	Tree tr(n+1);
	rep(i, 0, n) {
		tr.update(i, digits[i]);
	}

	// main sum and dual
	vector<Mod> sum(2, 0);
	auto cmp = [](pair<int, Mod> a, pair<int, Mod> b) {
		return a.first < b.first;
	};

	// main set of * runs and dual
	// answer is sum over * runs
	vector<set<pair<int, Mod>, decltype(cmp)>> st(2, 
		set<pair<int, Mod>, decltype(cmp)>(cmp));
	int l = 0, r = 0;
	int dl = 0, dr = 0;
	rep(i, 0, sz(isPlus)) {
		if(isPlus[i]) {
			auto val = tr.query(l, i+1);
			st[0].insert({2*l, val});
			l=i+1;
			sum[0] = sum[0]+val;
		} else {
			auto val = tr.query(dl, i+1); 
			st[1].insert( {2*dl, val});
			sum[1] = sum[1] + val;
			dl=i+1;
		}
	}
	auto val = tr.query(l, n);
	st[0].insert({2*l, val});
	sum[0] = sum[0] + val;
	auto dval = tr.query(dl, n);
	st[1].insert({2*dl, dval});
	sum[1] = sum[1] + dval;

	bool useDual = false;

	cout << sum[0].x << '\n';
	rep(i, 0, m) {
		char q;
		cin >> q;
		if(q == 's') {
			int a, b;
			cin >> a >> b;
			a--;b--;
			if(a > b) swap(a, b);
			else if(a == b) {
				cout << sum[useDual].x << '\n';
				continue;
			}
			auto swapel = [&](int ind, int l, int r) {
				auto aRangept = prev(st[ind].upper_bound({2*l, 0}));
				auto bRangePt = prev(st[ind].upper_bound({2*r, 0}));
				if(aRangept != bRangePt) {
					auto ar = *aRangept;
					auto br = *bRangePt;
					sum[ind] = sum[ind] - ar.second - br.second;
					ar.second = ar.second / digits[l] * digits[r];
					br.second = br.second / digits[r] * digits[l];


					st[ind].erase(aRangept);
					assert(ar.first % 2 == 0);
					st[ind].insert(ar);
					st[ind].erase(bRangePt);
					assert(br.first % 2 == 0);
					st[ind].insert(br);
					
					sum[ind] = sum[ind]+ ar.second + br.second;
				}
			};
			
			// swap in main and dual sets
			swapel(useDual, a, b);
			swapel(!useDual, a, b);
			
			// swap in the segtree
			swap(digits[a], digits[b]);
			tr.update(a, digits[a]);
			tr.update(b, digits[b]);
		} else if(q == 'f') {
			auto splitRuns = [&](set<pair<int, Mod>, decltype(cmp)> &myst, int i, Mod &sm) {
				auto next = myst.upper_bound({2*i+1, 0});
				auto it = prev(next);

				int r = (next == myst.end()) ? 2*n: next->first;
				auto [l, val] = *it;
				myst.erase(it);

				auto lval = tr.query(l/2, i+1);
				auto rval = tr.query(i+1, r/2);
				myst.insert({l, lval});
				assert(l%2 == 0);
				myst.insert({2*(i+1), rval});

				sm = sm - val;
				sm = sm + lval + rval;
			};
			
			auto mergeRuns = [&](set<pair<int, Mod>, decltype(cmp)> &myst, int i, Mod &sm) {
				auto rptr = myst.upper_bound({2*i+1, 0});
				auto lptr = prev(rptr);

				int l = lptr->first;
				auto nxt = next(rptr);
				int r = nxt == myst.end() ? 2*n : nxt->first;

				auto lval = lptr->second;
				auto rval = rptr -> second;
				myst.erase(lptr);
				myst.erase(rptr);

				auto newval = tr.query(l/2, r/2);
				assert(l % 2 == 0);
				myst.insert({l, newval});

				sm = sm - lval - rval + newval;
			};
			
			
			int a;
			cin >> a;
			a--;
			
			if(useDual ^ isPlus[a]) {
				// flip plus in main -> merge adjacent * runs in current
				// split * in dual
				mergeRuns(st[useDual], a, sum[useDual]);
				splitRuns(st[!useDual], a, sum[!useDual]);
			} else {
				// prev op is * -> split run in main, merge in dual
				splitRuns(st[useDual], a, sum[useDual]);
				mergeRuns(st[!useDual], a, sum[!useDual]);
			}
			isPlus[a] = !isPlus[a];
		} else {
			useDual = !useDual; 
		}

		cout << sum[useDual].x <<  '\n';
	}
	return 0;
}