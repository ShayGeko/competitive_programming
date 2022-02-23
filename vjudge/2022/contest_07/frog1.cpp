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
    int n;
    cin >> n;
    vi arr(n), dp(n, INF);
    for(int i = 0; i < n; ++i) cin >> arr[i];
    dp[0] = 0;
    dp[1] = abs(arr[1] - arr[0]);
    for(int i = 2; i < n; ++i){
        dp[i] = min(dp[i-2]+abs(arr[i]-arr[i-2]), dp[i-1] + abs(arr[i] - arr[i-1]));
    }

    cout << dp[n-1] << '\n';
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