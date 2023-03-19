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
    int n, m;
    cin >> n >> m;
    int x, y, s;
    cin >> x >> y >> s;

    int w = 0, h = 0;
    int cur = 1;
    int a;
    for(int i = 0; i < x; ++i){
        cin >> a;
        // cout << "DEBUG| " << a - cur << " " << (a-cur) / s <<  '\n';
        w += (a - cur)/s;
        cur = a+1;
    }
    w+=(n+1-cur) / s;
    cur = 1;
    for(int i = 0; i < y; ++i){
        cin >> a;
        // cout << "DEBUG| " << a - cur << " " << (a-cur) / s <<  '\n';
        h+=(a-cur)/s;
        cur = a+1;
    }
    
    h+=(m+1-cur) / s;

    // cout << "DEBUG | " << w << " " << h << '\n';
    cout << h * w << '\n';

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