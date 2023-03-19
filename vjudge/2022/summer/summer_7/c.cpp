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
    int n, k;
    cin >> n >> k;
    vi numbers(n);
    for(int i = 0; i < n; ++i) cin >> numbers[i];

    vi cnt(n, 0);
    
    for(auto t : numbers) ++cnt[t-1];
    
    int sumColor = 0;
    vi colors(n, 0);
    for(int i = 0; i < n; ++i){
        colors[i] = min(cnt[i], k);
        sumColor+=min(cnt[i], k);
    }

    int colorUse = sumColor / k;

    vi remaining(k, colorUse);
    vi coloring(n, 0);
    for(int i = 0; i < n; ++i){
        int ind = numbers[i] - 1;
        int col = colors[ind];
        while(col && !remaining[col - 1]) col--;

        coloring[i] = col;
        if(col) {
            remaining[--col]--;
        }
        colors[ind] = col;
    }

    for(auto col : coloring){
        cout << col << ' ';
    }
    cout << '\n';
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