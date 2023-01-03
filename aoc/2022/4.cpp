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

    int a1, b1, a2, b2;
    char c;

    int cnt = 0;
    while(cin >> a1){
        cin >> c >> b1;
        cin >> c >> a2 >> c >> b2;

        if(a1 <= a2 && b1 >= a2) ++cnt;
        else if(a2 <= a1 && b2 >= a1) ++cnt;
    }
    cout << cnt << '\n';
}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}