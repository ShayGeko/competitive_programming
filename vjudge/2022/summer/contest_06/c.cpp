#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 1e9;

void solve(){
    string a, b;
    cin >> a >> b;
    if(a == "0" || b == "0"){
        cout << "0\n";
        return;
    }

    int as = 0, bs = 0;
    for(auto c : a) if(c=='S')++as;
    for(auto c : b) if(c=='S')++bs;

    for(int i = 0; i < as * bs; ++i){
        cout << "S(";
    }
    cout << "0";
    for(int i = 0; i < as * bs; ++i){
        cout << ")";
    }
    cout << '\n';
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