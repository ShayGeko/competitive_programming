#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream& operator>> (istream& is, pii& p){
    int a, b;
    is >> a >> b;
    p = {a, b};

    return is;
}
const int maxn = 1e5;
const int INF = 1e9;

typedef struct Tnode {
    Tnode *tl, *tr;
    int l, r;
    int cnt;
    
    Tnode(int l, int r): tl(NULL), tr(NULL), l(l), r(r), cnt(0) {}

    void flip(int ind){
        if(l ==r){
            cnt = 1 - cnt;
            return;
        }
        int m = (l + r) / 2;
        if(ind <= m){
            if(!tl) tl = new Tnode(0, m);
            tl->flip(ind);
        }
        else{
            if(!tr) tr = new Tnode(m+1, r);
            tr->flip(ind);
        }

        cnt = (tl? tl->cnt : 0) + (tr? tr->cnt : 0);
    }
    int bitNum(int L, int R){
        if(L > R) return 0;
        if(l == L && R == r) return cnt;

        return (tl? tl->bitNum(L, min(tl->r, R)) : 0) + (tr ? tr->bitNum(max(tr->l, L), R) : 0);

    }
} segtree;

void solve(){
    int n, m;
    cin >> n >> m;

    segtree* tree = new segtree(1, n);

    char request;
    for(int i = 0; i < m; ++i){
        cin >> request;
        if(request == 'F'){
            int ind;
            cin >> ind;
            tree->flip(ind);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << tree->bitNum(l, r) << '\n';
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;

    while(t--){
        solve();
    }
    return 0;
}