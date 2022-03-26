#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n, m;
    cin >> n >> m;
    char field[101][101];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            field[i][j] = '.';
        }
    }
    int k;
    cin >> k;
    char patches[101][101][101];
    vector<pair<int, int>> dimensions;
    int r, c;
    for(int t = 0; t < k; ++t){
        cin >> r >> c;
        dimensions.push_back({r, c});
        for(int i= 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                cin >> patches[t][i][j];
            }
        }
    }
    cin >> k;
    int p, h, w;
    while(k--){
        cin >> r >> c >> p;
        int h = dimensions[p - 1].first;
        int w = dimensions[p - 1].second;
        for(int i = 0; r + i < n && i < h; ++i){
            for(int j = 0; c + j < m && j < w; ++j){
                field[r + i][c + j] = patches[p-1][i][j];
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << field[i][j];
        }
        cout << '\n';
    }
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