#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n, w;
    cin >> n >> w;

    vi W(n), V(n);
    for(int i = 0; i < n; ++i) cin >> W[i] >> V[i];

    vll dp(w+1, -1);
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = w - W[i]; j >= 0; j--){
            if(dp[j] >= 0) dp[j + W[i]] = max(dp[j+W[i]], dp[j] + V[i]);
        }
    }

    ll maxi = 0;
    for(auto t : dp) maxi = max(maxi, t);
    cout << maxi << '\n';
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