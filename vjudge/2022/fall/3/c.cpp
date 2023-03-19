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
void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<bool> dp(k+1, false);

    dp[0] = false;

    for(int i = 1; i <= k; ++i){
        bool isLose = true;
        bool canJump = false;
        for(auto v : a){
            if(v > i) break;
            canJump = true;
            isLose &= dp[i-v];
            if(!isLose) break;
        }
        dp[i] = canJump && !isLose;
    }
    if(dp[k]) cout << "First\n";
    else cout << "Second\n";
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