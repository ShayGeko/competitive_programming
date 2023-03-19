#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define has(a, b) ((a).find(b) != (a).end())
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

vi tin, low;
int timer = 0;
set<pii> bridges;
vb visited;
void get_bridges(int v, int p){
    low[v] = tin[v] = timer++;
    visited[v] = true;

    for(auto to : adj[v]){
        if(to == p) continue;

        // back edge
        if(visited[to]){
            imin(low[v], tin[to]);
        }
        // tree edge
        else{
            get_bridges(to, v);
            imin(low[v], low[to]);

            if(tin[v] < low[to]){
                bridges.insert({v, to});
            }
        }
    }

}

set<pii> used_edges;
void print_directions(int v, int p){
    visited[v] = true;

    for(auto to : adj[v]){
        if(to == p) continue;
        if(!visited[to]){
            cout << v+1 << " " << to+1 << '\n';
            if(bridges.count({v, to}) || bridges.count({to, v})){
                cout << to+1 << " " << v+1 << '\n';
            }
            
            print_directions(to, v);
        }
        else {
            if(tin[to] < tin[v])
                cout << to + 1 << " " << v + 1 << '\n';
        }
    }
}
void solve(int n, int m){
    adj.clear();
    adj.resize(n);
    int a, b;
    fora(i, m){
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }

    // time-in and "time-out" with back-edges
    tin = vi(n);
    low = vi(n);

    visited = vb(n, false);

    bridges.clear();
    get_bridges(0, -1);

    // for(auto br : bridges){
    //     cout << "BRIDGE: " <<  br.first << " " << br.second << '\n';
    // }

    fora(i, n) visited[i] = false;

    print_directions(0, -1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        cout << t++ << "\n\n";
        solve(n, m);
        cout << "#\n";
    }
    cout.flush();
    
    return 0;
}