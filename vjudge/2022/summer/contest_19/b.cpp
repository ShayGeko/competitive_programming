#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

ll getSum(vi& p, int mask){
    ll sum = 0;
    for(int i = 1, k = 1; i < p.size(); ++i, k <<=1){
        if(mask & k) sum+=p[i];
    }

    return sum;
}
void solve(){
    int n;
    cin >> n;
    vi p(n);
    ll total = 0;

    for (int i = 0; i < n; ++i){
        cin >> p[i];
        total += p[i];
    }

    ll mini = total;
    int maxmask = (1 << n ) - 1;

    for(int mask = 1; mask <= maxmask; ++mask){
        ll cur = getSum(p, mask);
        mini = min(mini, abs(cur - (total - cur)));
    }

    cout << mini << '\n';
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