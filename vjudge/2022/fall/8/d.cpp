#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
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


bool used[50][50];
char grid[50][50];
int n, m;
void dfs(int a, int b){
    if(used[a][b]) return;
    used[a][b] = true;

    for(int i = -1; i <= 1; ++i){
        if(i == 0) continue;

        if(a + i >= 0 && a + i < n && grid[a+i][b] != 'W' && !used[a+i][b])
            dfs(a+i, b);
        if(b + i >= 0 && b + i < m && grid[a][b+i] != 'W' && !used[a][b+i])
            dfs(a, b+i);
    }
}
void solve(){
    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 'L' && !used[i][j]){
                dfs(i, j);
                ++cnt;
            }
        }
    }

    cout << cnt << '\n';
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