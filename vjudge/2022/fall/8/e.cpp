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
void solve(){
    int n;
    cin >> n;
    vi nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    vvi dp(n, vi(2, 1));
    
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if(nums[i] > nums[j]){
                dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
            else if(nums[i] < nums[j]){
                dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
        }
    }
    int maxi = 0;
    for(auto a : dp){
        maxi = max(maxi, a[0]);
        maxi = max(maxi, a[1]);
    }

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