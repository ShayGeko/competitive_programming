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


void solve(int n){
    vvi transitions(8);
    transitions[0] = vi{1, 4, 7};
    transitions[1]= vi {0, 6};
    transitions[2]= vi {5};
    transitions[3]= vi {4};
    transitions[4]= vi {0, 3};
    transitions[5]= vi {2};
    transitions[6]= vi {1};
    transitions[7]= vi {0};

    // dp[col][mask]
    vi temp(8, 0);
    vvi dp(n+1, temp);

    dp[0][0] = 1; 
    for(int i = 0; i < n; ++i){
        for(int mask = 0; mask < 8; ++mask){
            for(auto t : transitions[mask]){
                dp[i + 1][t] += dp[i][mask];
            }
        }
    }

    cout << dp[n][0] << '\n';

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    
    while(cin >> t){
        if(t == -1) break;
        solve(t);
    }
    return 0;
}