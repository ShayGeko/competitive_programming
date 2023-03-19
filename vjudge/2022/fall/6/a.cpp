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
    double m, c;
    cin >> m >> c;

    point_t a = {0, c};
    point_t b = {1, m + c};

    vector<point_t> points(n);
    vector<int> power(n);

    for(int i = 0; i < n; ++i){
        cin >> points[i];
        cin >> power[i];
    }

    long long l = 0, r = 0;
    for(int i = 0; i < n; ++i){
        point_t c = points[i];
        if((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x) > 0){
            l += power[i];
        }
        else r += power[i];
    }
    if(l < r) swap(l, r);

    cout << l << '\n';
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