#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

const int maxn = 1e5;
const int INF = 1e9;

int n;
vi b,c;
int k;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    vi num_op(1e3+1);
    num_op[1] = 0;
    for(int i = 2; i <= 1e3; ++i){
        num_op[i] = num_op[i/2] + 1 + i % 2;
    }
    while(t--){
        cin >> n >> k;
        b.resize(n);
        c.resize(n);
        for(int i = 0; i < n; ++i){
            cin >> b[i];
            b[i] = num_op[b[i]];
        }
        for(int i = 0; i < n; ++i){
            cin >> c[i];
        }
        vector<long long> dp (k+1, 0);
        vector<bool> used(k+1, false);
        used[0] = true;
        for(int i = 0; i < n; ++i){
            for(int j = k; j >= b[i]; j--){
                if(used[j - b[i]]){
                    dp[j] = max(dp[j], dp[j - b[i]] + c[i]);
                    used[j] = true;
                }
            }
        }
        long long maxi = 0;
        for(int j = 0; j <= k; ++j){
             maxi = max(maxi, dp[j]);
        }
        cout << maxi << '\n';
    }
    return 0;
}