#include <bits/stdc++.h>

using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;
    return os;
}
template <class T>
pair<T, T> operator + (pair<T,T> &a, pair<T,T> &b){
    return {a.first + b.first, a.second + b.second};
}

template <class T>
pair<T, T> operator - (pair<T,T> &a, pair<T,T> &b){
    return {a.first - b.first, a.second - b.second};
}



const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;



void solve(){
    vector<string> grid;

    string s;
    while(cin >> s){
        grid.push_back(s);
    }

    
    int n = sz(grid), m = sz(grid[0]);
    
    queue<pii> q;
    vvb used(n, vb(m, false));
    vvi dist(n, vi(m, INF));
    
    pii end;
    rep(i, 0, n){
        rep(j, 0, m){
            if(grid[i][j] == 'S') {
                grid[i][j] = 'a';
            }
            if(grid[i][j] == 'a') {
                q.push({i, j});
                used[i][j] = true;
                dist[i][j] = 0;
            }
            else if(grid[i][j] == 'E') {
                end = {i,j};
                grid[i][j] = 'z';
            }
        }
    }


    vpii moves = {{0,1},{1,0},{-1,0},{0,-1}};
    
    
    while(!q.empty()){
        pii cur = q.front();q.pop();
        for(auto mv : moves){
            auto [i, j] = cur + mv;
            // cout << i << " " << j << '\n';
            if(i >= 0 && i < n && j >= 0 && j < m){
                if(!used[i][j] && grid[i][j] <= grid[cur.first][cur.second] + 1){
                    used[i][j] = true;
                    q.push({i,j});
                    dist[i][j] = dist[cur.first][cur.second] + 1;
                }
            }

        }

    }

    for(auto r : dist){
        for(auto el : r){
            cout << el << " ";
        }
        cout << '\n';
    }
    cout << dist[end.first][end.second] << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}