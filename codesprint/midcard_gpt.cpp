#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll MOD = 1000000007;

vector<ll> seg_func(vector<ll> &ar, vector<ll> &br) {
    int na = ar.size();
    int nb = br.size();
    vector<ll> cr(min(na + nb - 1, 101), 0);
    int n = cr.size();
    rep(a, 0, na) {
        rep(b, 0, min(nb, n - a)) {
            cr[a + b] = (cr[a + b] + (ar[a] * br[b]) % MOD) % MOD;
        }
    }
    return cr;
}

// Set up seg tree
vector<vector<vector<ll>>> create_tree(vector<ll> &ar) {
    int n = ar.size();
    
    vector<vector<ll>> basear;
    rep(i, 0, n) {
        basear.push_back({1, ar[i]});
    }
    
    vector<vector<vector<ll>>> seg;
    seg.push_back(basear);
    while (seg.back().size() != 1) { // generate next layer
        vector<vector<ll>> layer;
        rep(ii,0,seg.back().size()/2) {
            layer.push_back(seg_func(seg.back()[ii*2],seg.back()[ii*2+1]));
        }
        seg.push_back(layer);
    }
    return seg;
}

ll query(vector<vector<vector<ll>>> &seg, int l, int r, int k) {
    vector<ll> ans(1, 1);
    int li = l;
    int ri = r;
    for (int i = 0; i < seg.size(); i++) {
        if (li > ri) break;
        if (li % 2 == 1) {
            ans = seg_func(ans, seg[i][li]);
            li++;
        }
        if (ri % 2 == 0) {
            ans = seg_func(ans, seg[i][ri]);
            ri--;
        }
        li /= 2;
        ri /= 2;
    }
    assert( k < ans.size());
    return ans[k];
}

void update(vector<vector<vector<ll>>> &seg, int index, vector<ll> val) {
    seg[0][index] = val;
    int i = index;
    for (int ii = 1; ii < seg.size(); ii++) {
        i /= 2;
        if (i == seg[ii].size()) break;
        seg[ii][i] = seg_func(seg[ii - 1][i * 2], seg[ii - 1][i * 2 + 1]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, c, t;
    cin >> n >> c >> t;

    vector<ll> ar(n);
    rep(snth, 0, n) {
        ll a, b;
        cin >> a >> b;
        ar[snth] = b - a + 1;
    }

    vector<vector<vector<ll>>> sar = create_tree(ar);
    
    rep(snt, 0, t) {
        int command, d1, d2, d3;
        cin >> command >> d1 >> d2 >> d3;
        if (command == 0) {
            cout << query(sar, d1 - 1, d2 - 1, d3) << "\n";
        } else {
            update(sar, d1 - 1, {1, d3 - d2 + 1});
        }
    }
    return 0;
}
