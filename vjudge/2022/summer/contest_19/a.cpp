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
    int a;
    int b;
    int c;
} line_t;

void solve(){
    int n, m, r;
    cin >> n >> m >> r;

    vector<pii> candles(n);
    vector<line_t> lines(m);

    for(int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        candles[i] = {x,y};
    }

    for(int i = 0; i < m; ++i){
        line_t line;
        cin >> line.a >> line.b >> line.c;
        lines[i] = line;
    }

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