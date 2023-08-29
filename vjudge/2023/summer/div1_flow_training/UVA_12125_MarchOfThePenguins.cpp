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
    void clear() {
        for(auto &x : adj) x.clear();
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
    int N;
    double D;
    cin >> N >> D;

    vi x(N), y(N), n(N), d(N);
    vvi platforms(N, vi(2));

    int total = 0;
    rep(i, 0, N) {
       cin >> x[i] >> y[i] >> n[i] >> d[i];
       total+=n[i];
    }

    vvi adj(N);

    rep(i, 0, N) {
        rep(j, i+1, N) {
            double dx = x[i]-x[j], dy = y[i]-y[j];
            if(dx*dx+dy*dy <= D*D) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vi ans;
    rep(i, 0, N) {
        // try every node to be the final one
        Dinic dinic(2*N + 2);
        int s = 2*N, t = 2*N + 1;
        dinic.addEdge(i,t, total);

        rep(j, 0, N) {
            dinic.addEdge(s, j, n[j]);
            dinic.addEdge(j, N+j, d[j]);

            for(auto v : adj[j]) {
                dinic.addEdge(N+j, v, total);
            }
        }

        int maxflow = dinic.calc(s, t);

        if(maxflow == total) ans.push_back(i);
    }

    if(ans.size()) {
        for(int i = 0; i < ans.size(); ++i) {
            cout << ans[i];
            if(i < ans.size()-1) cout << " ";
        }
        cout << '\n';
    } else {
        cout << "-1\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t = 1;

     cin >> t;
    
    while(t--){
        solve();
        cout.flush();
    }
    cout.flush();
    
    return 0;
}