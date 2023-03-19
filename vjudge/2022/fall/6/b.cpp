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

typedef struct {
    double x;
    double y;
} point_t;

istream &operator >> (istream& is, point_t &p){
    cin >> p.x >> p.y;
    return is;
}
void solve(){
    int n;
    cin >> n;

    vi tt(n);

    for(int i = 0; i < n; ++i){
        cin >> tt[i];
    }

    int g = 360;

    int prev = tt[0];
    for(auto t : tt){
        g = __gcd(g, t - prev);
        prev = t;
    }
    g = __gcd(g, 360 + tt[0] - tt.back());
    // cout << 360 / g << '\n';
    cout << 360 / g - n<< '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

   cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}