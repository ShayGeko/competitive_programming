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

vvi adj;
vi parent;
vi answer;

void getAnswer(int v, int fin) {
    answer.push_back(v);
    if(v==fin) return;

    getAnswer(parent[v], fin);
    
}
vb used;
bool dfs(int v) {
    used[v] = true;

    for(auto to : adj[v]) {
        if(to == parent[v]) continue;

        if(used[to]) {
            getAnswer(v, to);
            return true;
        }
        else {
            parent[to]=v;
            if(dfs(to))return true;
        }
    }

    return false;
}
void solve(){
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    used = vb(n, false);
    parent = vi(n, -1);

    rep(i, 0, m) {
        int a,b;
        cin >> a >> b;
        a--;b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, 0, n) {
        if(answer.empty() && !used[i]) dfs(i);
    }

    if(answer.size()) {
        cout << answer.size() + 1 << '\n';
        for(auto v: answer) {
            cout << v + 1 << " ";
        }
        cout << answer[0] + 1 << '\n';
    } else {
        cout << "IMPOSSIBLE\n";
    }

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