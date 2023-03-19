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
    int paint[3][4];
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 4; ++j) cin >> paint[i][j];
    
    int mins[4];
    for(int i = 0; i < 4; ++i) mins[i] = INF;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 4; ++j) {
              mins[j] = min(mins[j], paint[i][j]);
        }
    };
    int sum = 0;
    for(int i = 0; i < 4; ++i) sum+= mins[i];
    
    
    int dif = sum - 1000000;
    if(dif < 0) cout << "IMPOSSIBLE\n";
    else{
        int i = 0;
        while(i < 4 && dif > 0){
            if(dif <= mins[i]){
                mins[i] -= dif;
                dif = 0;
            }
            else {
                dif -= mins[i];
                mins[i] = 0;
            }
            ++i;
        }
        for(int i = 0; i < 3; ++i) cout << mins[i] << " ";
        cout << mins[3] << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    int n = t;
    while(t--){
        cout << "Case #" << n - t << ":\n";
        solve();
    }
    return 0;
}