#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define has(a, b) (a.find(b) != a.end())
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

template <class T>
istream &operator >> (istream& is, pair<T, T> &p){
    is >> p.first >> p.second;
    return is;
}
template <class T>
ostream &operator << (ostream& os, pair<T, T> &p){
    os << p.first << " " << p.second;
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

template<class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b){
    assert(sz(a) == sz(b));

    vector<T> res(a);
    fora(i, sz(b)){
        res[i] += b[i];
    }

    return res;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;


char grid[110][110];

bool visited[110][110];

vpii moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int reachable = 0;
int n, m;
bool dfs(pii v){
    bool increases = grid[v.first][v.second] == '.';
    if(increases) ++reachable;
    visited[v.first][v.second] = true;

    for(auto mv : moves){
        auto to = v + mv;
        if(to.first < 0 || to.first >= n || to.second < 0 || to.second >= m) continue;
        if(visited[to.first][to.second]) continue;
        if(grid[to.first][to.second] != ' ' && grid[to.first][to.second] != '.') continue;

        increases |= dfs(to);
    }

    return increases;
}
vpii sources;
void solve(){
    cin >> n >> m;

    string s;
    getline(cin, s);
    int tot_cnt = 0;
    fora(i, n){
        getline(cin, s);
        fora(j, m) {
            grid[i][j] = s[j];
            if(grid[i][j] >= 'A' && grid[i][j] <= 'W') sources.push_back({i, j});
            else if(grid[i][j] == '.') ++tot_cnt;
        }
    }
    int minsource = 0;
    for(auto s : sources){
        if(!visited[s.first][s.second] && dfs(s)) ++minsource;
    }

    cout << minsource << " " << tot_cnt - reachable << '\n';

}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}