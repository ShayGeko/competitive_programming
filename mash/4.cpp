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

istream &operator >> (istream& is, pii &p){
    is >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
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

vvi adj;
vb food(0);
int n;
pair<bool, ll> dfs(int v, int p, int depth){
    vi adj1;
    for(int i = 0; i < n; ++i){
        if(i == v || i == p) continue;

        if(adj[v][i]){
            adj1.push_back(i);
        }
    }

    ll sum = 0;
    forc(to, adj1){
        auto res = dfs(to, v, adj[v][to]);
        if(res.first){
            sum += res.second + adj[v][to];
        }
    }

    if(sum == 0){
        if(food[v]) return {true,depth};
        else return {false, 0};
    }
    else{
        return {true, sum + depth};
    }
}
void solve(){
    int k;
    cin >> n >> k;

    adj.resize(n);
    food.resize(n, false);
    fora(i, n){
        adj[i].resize(n, 0);
    }
    rep(i, 0, n - 1){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
    }

    rep(i, 0, k){
        int a;
        cin >> a;
        food[a-1] = true;
    }

    cout << dfs(0, -1, 0).second << '\n';
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