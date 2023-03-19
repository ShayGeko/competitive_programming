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
    ll n;
    cin >> n;
    
    double a[2] = {100, 0}, b[2] = {0, 100};

    if(n < 5000){
        if(n <= 2){
            cout << a[n-1] << " " << b[n-1] << '\n';
            return;
        }
        for(int i = 2; i < n; ++i){
            double a1 = (a[0] + a[1])/2;
            a[0] = a[1];
            a[1] = a1;

            double b1 = (b[0] + b[1])/2;
            b[0] = b[1];
            b[1] = b1;
        }

        cout  << fixed << setprecision(7) << a[1] << " " << b[1] << '\n';
    }
    else cout << fixed << setprecision(7) << 33.3333333 << " " << 66.6666666 << '\n';
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