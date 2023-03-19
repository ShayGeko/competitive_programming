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
    string s;
    cin >> s;

    vi dp(26, INF);

    for(int i = 0; i < s.size(); ++i){
        *(lower_bound(dp.begin(), dp.end(), s[i])) = s[i];
    }

    int i = 0;
    while(i < 26 && dp[i] != INF) ++i;
    cout << 26 - i << '\n';
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