#include <bits/stdc++.h>

using namespace std;

const int maxn = 21;
const int INF = 1e9;
const int p = 1e9 + 7;
const int max_mask = 1 << maxn;
int a[maxn][maxn];
int dp[max_mask];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
    int all_matched = (1 << (n)) - 1;
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        for (int mask = all_matched - 1; mask >= 0; --mask) {
            if(dp[mask]){
                for(int j = 0; j < n; ++j){
                    if(a[i][j] && !(mask & (1 << j))){
                        dp[mask | (1 << j)] = (dp[mask | (1 << j)] + dp[mask]) % p;
                    }
                }
            }
        }
    }
    cout << dp[all_matched] << '\n';
    return 0;
}