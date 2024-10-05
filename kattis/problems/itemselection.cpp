#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int n, m, cur,p, q;

    cin >> n >> m >> cur >> p >> q;
    --cur;

    vi pre(p);
    for(auto &x : pre) {
        cin >> x;--x;
    }

    vi wa(q);
    for(auto &x : wa) {
        cin >> x; --x;
    }


    int np = (n +m - 1) / m;
    vi req(np), correct(np), xtra(np); 
    
    int j = 0, k = 0;
    rep(i, 0, np) {
        while(j < wa.size() && k < pre.size() && wa[j] / m == i && pre[k]/m == i) {
            if(wa[j] == pre[k]) {
                ++req[i];
                ++correct[i];
                ++j;++k;
            } else if (wa[j] < pre[k]) {
                ++req[i];
                ++j;
            } else {
                ++xtra[i];
                ++k;
            }
        } 
        while(j < sz(wa) && wa[j]/m == i) {
            ++req[i];
            ++j;
        }
        while(k < sz(pre) && pre[k]/m == i) {
            ++xtra[i];
            ++k;
        }
    }


    
    int mi = np, ma = -1;
    rep(i, 0, np) {
        if(xtra[i] || req[i] != correct[i]) {
            mi = min(mi, i);
            ma = i;
        }
    }
    if(ma == -1) mi = ma = cur;


    int l = mi, r = ma;
    int total = 0;
    int d1 = abs(l - cur), d2 = abs(r - cur);
    int inc = 1;
    if(d1 > d2) {
        swap(l, r);
        swap(d1,d2);
        inc = -1;
    }
    total += d1;
    int i = l;
    while(i != r + inc) {
        // select/unselect individual
        assert(req[i] >= correct[i]);
        int cost = req[i] - correct[i] + xtra[i];
        // unselect all
        cost = min(cost, 1 + req[i]);
        // select all
        cost = min(cost, 1 + m - req[i]); 

        total += cost;
        i += inc;
        // cout << "Cost " << cost << "\n";
    }
    total += abs(r - l); 
    // cout << cur << " " << start << " " << end << '\n';
    // cout << d1 << " " << d2 << '\n';

    cout << total << '\n';


	return 0;
}