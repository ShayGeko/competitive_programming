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
    int n, k;
    cin >> n >> k;
    vector<double> pr;

    for(int i = 0; i < n; ++i){ cin >> pr[i];}

    sort(pr.rbegin(), pr.rend());

    vector<vector<double>> dp(n, vecor<double>(2*n+1, 0));
    
    dp[0][n] = 1;

    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n; ++j){
            if(j > 0) dp[i+1][j] += dp[i][j+1]*pr[i]
        }
    }



    cout << k << '\n';
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