#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

vvll dp;
vvi opt;


void solve(){
    int n;
    cin >> n;

    vi a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vll prefsum(n+1);
    prefsum[0] = 0;
    prefsum[1] = a[0];
    for(int i = 2; i <= n; ++i){
        prefsum[i] = prefsum[i-1] + a[i-1];
    }
    dp.resize(n, vll(n, 0));
    opt.resize(n, vi(n));
    
    for(int i = 0; i < n; ++i) {
        dp[i][i] = a[i];
        opt[i][i] = i;
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = i + 1; j < n; ++j){
            dp[i][j] = LONG_LONG_MAX;
            for(int k = opt[i][j-1]; k <= min(j-1, opt[i+1][j]); ++k){
                ll sum =  prefsum[j+1] - prefsum[i] + dp[i][k] + dp[k+1][j];
                if(dp[i][j] > sum){
                    dp[i][j] = sum;
                    opt[i][j] = k;
               }
            }
        }
    }

    cout << dp[0][n-1] - prefsum[n]<< '\n';
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