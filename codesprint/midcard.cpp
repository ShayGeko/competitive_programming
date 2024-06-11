#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (int)a; i < (int)b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



vector<ll> seg_func(vector<ll> &ar, vector<ll> &br) {
    ll m = 1000000007;
    int na = ar.size();
    int nb = br.size();
    vector<ll> cr(min(na+nb-1,101),0);
    int n = cr.size();
    rep(a,0,na) {
        rep(b,0,min(nb, n-a)) {
            ll prod = ar[a]*br[b];
            assert(prod >= 0);
            prod %= m;
            cr[a+b] = (prod + cr[a+b]) % m;
        }
    }
    rep(i, 0, sz(cr)) {
        assert(cr[i] >= 0);
    }
    return cr;
}

// set up seg tree
vector<vector<vector<ll>>> create_tree(vector<ll> &ar) {
    int n = ar.size();
    
    vector<vector<ll>> basear;
    rep(i,0,n) {
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


ll query(vector<vector<vector<ll>>> &seg,int l, int r, int k) {
    vector<ll> ans;
    ans.push_back(1);
    int li = l;
    int ri = r;
    rep(i,0,seg.size()) {
        if (li > ri) {
            break;
        }
        if (li % 2 == 1) {
            ans = seg_func(ans,seg[i][li]);
            li++;
        }
        if (ri % 2 == 0) {
            ans = seg_func(ans,seg[i][ri]);
            ri--;
        }
        li /= 2;
        ri /= 2;
    }
    rep(i, 0, k+1) {
        assert(ans[i] >= 0);
    }
    return ans[k];
}


// update function reimplemented in main, change to actually use pointers
void update(vector<vector<vector<ll>>> &seg, int index, vector<ll> val) {
    unsigned int i = index;
    seg[0][i] = val;
    rep(ii,1,seg.size()) {
        i /= 2;
        if (i == seg[ii].size()) {
            break;
        }
        seg[ii][i] = seg_func(seg[ii-1][i*2],seg[ii-1][i*2+1]);
    }
    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n,c,t;
    cin >> n >> c >> t;

    vector<ll> ar;
    rep(snth,0,n) {
        ll a,b;
        cin >> a >> b;
        ar.push_back(b-a+1);
    }
    vector<vector<vector<ll>>> sar = create_tree(ar);
    
    rep(snt,0,t) {
        int command;
        int d1,d2,d3;
        cin >> command;
        cin >> d1 >> d2 >> d3;
        const int mod = 1e9 + 7;
        if (command == 0) {
            ll a = query(sar,d1-1,d2-1,d3);
            assert(a >= 0);
            assert (a <= mod);
            cout << a << '\n';
        }
        else {
            update(sar,d1-1,{1,d3-d2+1});
        }
    }
    return 0;
}