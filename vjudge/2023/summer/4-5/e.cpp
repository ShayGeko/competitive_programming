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


vector<vc> grid;
vvi d;
queue<vi> kue;
void solve(){
    int n, m;
    cin >> n >> m;
    d = vvi(n, vi(m, 0));
    grid = vector<vc>(n, vc(m));
    
    rep(i, 0, n) rep(j, 0, m)
        cin >> grid[i][j];

    rep(i, 0, n) rep(j, 0, m){
        if(grid[i][j] == 'X'){
            bool add = false;
            if(i==0 || j == 0 || i == n-1 || j == m-1) add = true;
            else{
                int sum = 0;
                sum = 0 + grid[i-1][j]+grid[i+1][j] +grid[i][j-1]+grid[i][j+1];
                if(sum != 4*'X') add = true; 
            }

            if(add) {
                kue.push({i,j});
                d[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while(!kue.empty()){
        auto v = kue.front();kue.pop();
        int i = v[0], j = v[1];
        ans = max(d[i][j], ans);
        rep(i1, -1, 2) rep(j1, -1, 2) {
            // remove diagonals
            if(abs(i1)==abs(j1)) continue;
            // out of bounds
            if(i+i1 < 0 || j+j1 < 0 || i+i1 == n || j+j1 == m) continue;
            // next layer of dough in reverse order
            // if we put [i, j] after [i1, j1] later both will chipify
            if(grid[i+i1][j+j1] == 'X' && !d[i+i1][j+j1]){
                d[i+i1][j+j1] = d[i][j] + 1;
                kue.push({i+i1, j+j1});
            }
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
    cout.flush();
    
    return 0;
}