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
    vi nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    vi dp(2001);

    dp[0] = 1;
    for(auto num : nums){
        for(int i = 1000; i >= 0; i--) if(dp[i]) dp[i + num] = 1;
    }
    int i = 0;

    while(i <= 1000 && !(dp[1000 - i] || dp[1000 + i])) ++i;

    if(dp[1000 + i]) cout << 1000 + i << '\n';
    else cout << 1000 - i << '\n';
    

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