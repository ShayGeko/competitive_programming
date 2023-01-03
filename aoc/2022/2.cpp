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
    string x = "", y = "";

    char l, r;
    int n = 0;
    int a, b;
    ll cnt = 0;
    while(cin >> l){
        cin >> r;
        a = l - 'A';

        if(r == 'X'){
            b = (3 + a - 1) % 3;
        }
        else if(r == 'Y'){
            b = a;
            cnt+=3;
        }
        else {
            b = (a + 1) % 3;
            cnt+=6;
        }

        cnt += b + 1;
    }

    cout << cnt << endl;

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