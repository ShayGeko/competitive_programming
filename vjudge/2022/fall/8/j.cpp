#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> h[2];
    pii th;
    for(int i = 0; i < n; ++i){
        cin >> th;
        (th.first < 0? h[0] : h[1]).push_back({abs(th.first), th.second});
    };

    
    ll ans = 0;
    for(auto hs : h){
        sort(hs.rbegin(), hs.rend());

        for(int i = 0; i < hs.size(); ++i){
            ans += (ll) hs[i].first * ((hs[i].second + k - 1) / k);
            if(hs[i].second % k){
                ll rem = k - (hs[i].second % k);
                int j = i + 1;
                while(rem && j < hs.size()){
                    if(hs[j].second < rem){
                        rem -= hs[j].second;
                        j++;
                    }
                    else{
                        hs[j].second -= rem;
                        rem = 0;
                    }
                }
                i = j - 1;
            }
        }
    }
    ans *= 2;
    cout << ans << '\n';
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