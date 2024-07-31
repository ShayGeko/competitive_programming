#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    vector<double> weights(n);
    vi force(n);
    for(auto &x : weights) cin >> x;
    for(auto &x :force) cin >> x;
    vector<pair<double, int>> wi(n);
    rep(i, 0, n) {
        wi[i] = {weights[i], i};
    }
    sort(all(wi));
    vi w(n);
    // w[wi[0].second] = 0;
    rep(i, 0, n) {
        w[wi[i].second] = i;
    }

    ll best = 0;
    
    Tree st(n, 0);
    rep(i, 0, n) {
        ll cur = st.query(0, w[i]+1) + force[i];
        best = max(best, cur);
        st.update(w[i], cur);
    }

    ll total = accumulate(all(force), 0);
    cout << total - best << '\n';


	return 0;
}