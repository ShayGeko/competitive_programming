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

vector<vector<char>> grid;
vector<vector<pii>> parent;
int n, m;
void bfs(int i, int j){
    queue<pii> ue;
    ue.push({i, j});

    while(!ue.empty()){
        pii cur = ue.front();
        ue.pop();
        i = cur.first, j = cur.second;

        if(i > 0 && grid[i-1][j] == '.'){
            grid[i-1][j] = '#';
            parent[i-1][j] = {i, j};
            ue.push({i-1, j});
        }
        if(j > 0 && grid[i][j-1] == '.'){
            grid[i][j-1] = '#';
            parent[i][j-1] = {i, j};
            ue.push({i, j-1});
        }
        if(i < n - 1 && grid[i+1][j] == '.'){
            grid[i+1][j] = '#';
            parent[i+1][j] = {i, j};
            ue.push({i+1, j});
        }
        if(j < m - 1 && grid[i][j+1] == '.'){
            grid[i][j+1] = '#';
            parent[i][j+1] = {i, j};
            ue.push({i, j+1});
        }
    }
    
}
void solve(){
    cin >> n >> m;

    grid.resize(n, vector<char>(m));
    parent.resize(n, vector<pii>(m));

    pii a, b;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
            if(grid[i][j] == 'A'){
                a = {i, j};
                grid[i][j] = '.';
            }
            else if(grid[i][j] == 'B'){
                b = {i, j};
                grid[i][j] = '.';
            }
        }
    }

    bfs(a.first, a.second);

    if(grid[b.first][b.second] == '#'){
        string path = "";
        pii cur = b;
        while(cur != a){
            pii pr = parent[cur.first][cur.second];
            if(pr.first > cur.first) path += 'U';
            else if(pr.first < cur.first) path += 'D';
            else if(pr.second > cur.second) path += 'L';
            else path += 'R';

            cur = pr;
        }
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.length() << "\n" << path << endl;
    }
    else cout << "NO\n";

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