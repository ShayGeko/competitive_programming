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

unordered_map<string, vector<string>> adj, tr_adj;
unordered_map<string, bool> visited;

vector<string> tsorted;
vector<string> names;

void solve(){
    vector<string> grid(8);
    
    fora(i, 8) cin >> grid[i];

    vpii pos;

    fora(i, 8) fora(j, 8) if(grid[i][j] == '*') pos.push_back({i, j});
    vb diag1(15, false), diag2(15, false), row(8, false), col(8, false);

    for(auto t : pos){
        int i = t.first, j = t.second;
        if(row[i] || col[j] || diag1[7 - (i - j)] || diag2[i+j]) {
            cout << "invalid\n";
            return;
        }
        row[i] = col[j] = diag1[7 - (i - j)] = diag2[i+j] = true;
    }

    if(sz(pos) == 8) cout << "valid\n";
    else cout << "invalid\n";
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