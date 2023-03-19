#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

const int maxn = 1e5;
const int INF = 1e9;

long long hc, dc, hm, dm;
long long a, w;
int k;
long long f(int x){
    // cout << "testing for: " << x << '\n';
    // cout << "hc: " << hc + (k - x)*a << " " << "dc: " << dc + x * w << '\n';
    // cout << "outcome: " << (hc + (k - x) * a + dm - 1) / dm - (hm + dc + x * w - 1) / ( dc + x * w) << '\n';
    return (hc + (k - x) * a + dm - 1) / dm - (hm + dc + x * w - 1) / ( dc + x * w);
}
ll ternary_search(int lo, int hi){
    //cout << "DEBUG: " << lo << " " << hi << '\n';
    while(hi - lo > 1){
        int mid = (hi + lo) >> 1;
        if(f(mid) > f(mid + 1))
            hi = mid;
        else lo = mid;
    }

    return f(lo + 1);
}
ll get_max(){
    ll maxi = f(0);
    for(int i = 1; i <= k; ++i){
        maxi = max(maxi, f(i));
    }

    return maxi;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> hc >> dc >> hm >> dm;
        cin >> k >> w >> a;

        if(f(0) >= 0 || get_max() >= 0){
            cout << "YES\n";
        }
        else cout << "NO\n";

    }
    return 0;
}