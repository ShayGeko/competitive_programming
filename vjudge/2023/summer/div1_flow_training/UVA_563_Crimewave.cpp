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

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
                lvl = ptr = vi(sz(q));
                int qi = 0, qe = lvl[s] = 1;
                while (qi < qe && !lvl[t]) {
                    int v = q[qi++];
                    for (Edge e : adj[v])
                        if (!lvl[e.to] && e.c >> (30 - L))
                            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
                while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
            } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve(){
    int n, m, st;
    cin >> n >> m >> st;

    int nodesInLayer = n * m;
    Dinic dinic(2 * nodesInLayer + 2);
    int s = 2 * nodesInLayer, t = 2*nodesInLayer + 1;
    rep(i, 0, st) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        dinic.addEdge(s, a*m + b, 1);
    }

    rep(i, 0, n) {
        rep(j, 0, m) {
            if(i == 0 || j == 0 || i == n-1 || j == m-1) {
                // grid edges are ways out - connect to sink
                dinic.addEdge(nodesInLayer + i*m + j, t, 1);
            }

            dinic.addEdge(i*m + j, nodesInLayer + i*m + j, 1);

            rep(di, -1, 2) {
                rep(dj, -1, 2) {
                    if(!di ^ !dj) {
                        int i1 = i+di, j1 = j+dj;
                        if(i1 >= 0 && i1 < n && j1 >= 0 && j1 < m) {
                            // add edge to neighbors, from exit node to entrance node
                            dinic.addEdge(nodesInLayer + i*m + j, i1*m + j1, 1);
                        }
                    }
                }
            }
        }
    }

    int reachable = dinic.calc(s, t);

    if(reachable == st) cout << "possible\n";
    else  cout << "not possible\n";

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

     cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}

/*
 *
2
6 6 10
4 1
3 2
4 2
5 2
3 4
4 4
5 4
3 6
4 6
5 6
5 5 5
3 2
2 3
3 3
4 3
3 4
 */