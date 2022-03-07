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

int n, m;
bool fillB(vector<vector<char>> &grid, int i, int j){
    grid[i][j] = '.';
    for(int k = i; k >= 0; k--){
        for(int t = j; t >=0; t--){
            if(grid[k][t] == 'B') break;
            else if (grid[k][t] == 'R'){
                return false;
            }
            else grid[k][t] = 'B';
        }
    }

    return true;
}

bool fillR(vector<vector<char>> &grid, int i, int j){
    grid[i][j] = '.';
    for(int k = i; k < n; k++){
        for(int t = j; t < m; t++){
            if (grid[k][t] == 'B'){
                return false;
            }
            else if(grid[k][t] != 'R')grid[k][t] = 'R';
        }
    }

    return true;
}
void solve(){
    cin >> n >> m;
    vector<vector<char>> grid (n);
    for(int i = 0; i < n; ++i) grid[i].resize(m);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 'B'){
                if(!fillB(grid, i, j)){
                    cout << "0\n";
                    return;
                }
            }
            else if(grid[i][j] == 'R'){
                if(!fillR(grid, i, j)){
                    cout << "0\n";
                    return;
                }
            }
        }
    }

    cout << "fill done: \n";
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << grid[i][j];
        }
        cout << '\n';
    }
    int ans = n * m;

    vector<vi> dp(n);
    for(int i = 0; i < n; ++i) dp[i].resize(m, 0);

    
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 'B') dp[i][j] = 0;
            else if (grid[i][j] == '.'){
                int top = 1, left = 1, extra = 0;
                if(i && dp[i-1][j] != 'B') top = dp[i-1][j];
                if(j&& dp[i][j-1] != 'B') left = dp[i][j-1];
                if(i && j) extra = dp[i-1][j-1];

                dp[i][j] = top * left - extra;
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] != '.') ans--;
        }
    }

    cout << ans << '\n';
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