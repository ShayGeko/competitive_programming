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
int dp[400][400];
int nums[400];
int compute(int i, int j){
    if(dp[i][j]) return dp[i][j];

    if(i == j) return dp[i][j] = nums[i];
    

    for(int k = i + 1; k < j; ++i){

    }
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> nums[i];


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