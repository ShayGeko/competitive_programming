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
    int a1, a2;
    double expa = 0, expb = 0;
    int b1, b2;
    for(int i = 0; i < 2; ++i){
        cin >> a1 >> a2;
        expa += (a2 + a1) / 2.0;
    }
    for(int i = 0; i < 2; ++i){
        cin >> b1 >> b2;
        expb += (b2 + b1) / 2.0;
    }
    if(expa > expb) cout << "Gunnar\n";
    else if(expa == expb) cout << "Tie\n";
    else cout << "Emma\n";
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