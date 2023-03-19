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
void solve(){
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    vi dif[5];
    for(int i = 0; i < 5; ++i) dif[i].resize(5, 0);

    dif[1][0] = dif[3][0] = 1;

    vi strcnt (n, 0);
    strcnt[0] = 2;
    for(int i = 1; i < n; ++i){
        dif[0][i] = dif[1][i-1];
        dif[1][i] = (dif[0][i-1] + dif[2][i-1]) % m;
        dif[2][i] = (dif[1][i-1] + dif[3][i-1]) % m;
        dif[3][i] = (dif[2][i-1] + dif[4][i-1]) % m;
        dif[4][i] = dif[3][i-1];
        for(int j = 0; j < 5; ++j){
            strcnt[i] = (strcnt[i] + dif[j][i]) % m;
        }
    }
    int l = 0, r = strcnt[n - 1];

    for(auto c : s){
        if(c == 'L') r/=2;
    }
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