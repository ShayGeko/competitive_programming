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
void toposort(string &v){
    visited[v] = true;

    for(auto to : adj[v]){
        if(!visited[to]) toposort(to);
    }

    tsorted.push_back(v);
}

unordered_map<string, int> scc;
void add_to_scc(string &v, int k){
    visited[v] = true;
    scc[v] = k;
    for(auto to : tr_adj[v]){
        if(!visited[to]) add_to_scc(to, k);
    }
}
void solve(){
    int n;
    cin >> n;

    names.resize(n);
    string s, temp;
    
    getline(cin, s);
    
    fora(i, n){
        getline(cin, s);
        stringstream ss(s);
        ss >> s >> temp;
        names[i] = s;

        adj[temp].push_back(s);
        adj[s].push_back(temp);

        tr_adj[temp].push_back(s);
        tr_adj[s].push_back(temp);

        while(ss >> temp){
            adj[temp].push_back(s);
            tr_adj[s].push_back(temp);
        }
    }

    for(auto v : names)
        if(!visited[v]) toposort(v);

    
    for(auto v : tsorted){
        visited[v] = false;
    }

    int k = 0;
    for(int i = sz(tsorted) - 1; i >= 0; i--){
        if(!visited[tsorted[i]]) add_to_scc(tsorted[i], k++);
    }

    vi scc_size(k, 0);
    int maxi = 0;
    for(auto v : names){
        imax(maxi, ++scc_size[scc[v]]);
    }


    cout << n - maxi << '\n';
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