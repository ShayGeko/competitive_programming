#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 1e5;
const int INF = 2e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, c, t1, t2;
    cin >> n >> c >> t1 >> t2;
    vi dist(2*n);
    vector<int [2]> dp(2*n);
    vector<int [2]> remainder(2*n);
    int temp;
    for(int i = 0; i < n; ++i){
        cin >> dist[i];
        dist[i+n] = c + dist[i];
    }
    int ans = INF;
    for(int j = 0; j <= n-1; ++j){
        dp[j][0] = t1;
        dp[j][1] = t2;
        remainder[j][0] = t1;
        remainder[j][1] = t2;
        for(int i = j + 1; i < n + j; ++i){
            int d = dist[i] - dist[i-1];
            if( d<= remainder[i-1][0]){
                dp[i][0] = dp[i-1][0];
                remainder[i][0] = remainder[i-1][0] - d;
            }
            else{
                dp[i][0] = dp[i - 1][0] + t1;
                if(d > remainder[i-1][1]){
                    dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + t1;
                }
                else dp[i][0] = dp[i - 1][0] + t1;
                remainder[i][0] = t1;
            }
            if(d <= remainder[i-1][1]){
                dp[i][1] = dp[i-1][1];
                remainder[i][1] = remainder[i-1][1] - d;
            }
            else{
                if(d > remainder[i-1][0]){
                    dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + t2;
                }
                else dp[i][1] = dp[i - 1][1] + t2;
                remainder[i][1] = t2;
            }
        }
        ans = min(ans, min(dp[j + n-1][0], dp[j + n-1][1]));
    }
    if(ans == INF) cout << 0 << '\n';
    else cout << ans << '\n';
    return 0;
}