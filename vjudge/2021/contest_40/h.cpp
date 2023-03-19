#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
const int INF = 1e9;

long long t[4*maxn];

long long getMax(int v, int tl, int tr, int l, int r){
     if(l > r) return 0;
    if(tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;

    return max(getMax(v * 2, tl, tm, l, min(tm, r)), getMax(v * 2 + 1, tm + 1, tr, max(l, tm+1), r));
}
void update (int v, int tl, int tr, int pos, long long new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}
int h[maxn], b[maxn];
long long maxb[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
    set<int> heights;

    for(int i = 0; i < n; ++i){
        long long maxi = getMax(1, 0, n, 0, h[i] - 1);
        update(1, 0, n, h[i], maxi + b[i]);
    }

    cout << getMax(1, 0, n, 0, n) << '\n';
    return 0;
}