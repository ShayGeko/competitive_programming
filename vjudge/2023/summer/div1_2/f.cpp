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


vvi bridges;
vi stree_size, stree_edge_cnt;
vb visited;
int n, m;
int timer = 0;

vi tin, tout;

typedef struct {
    bool inDeadendSubtree = false;
    bool isAns = false;
    int from;
    int to;
} edge;

map<pii, edge> edges;

vvi adj;
void dfs(int v, int p) {
    visited[v]=true;
    stree_size[v] = 1;
    stree_edge_cnt[v] = sz(adj[v]) - (p==-1?0:1);
    tin[v]=tout[v]=timer++;

    for(auto to : adj[v]) {
        if(to == p) {
            continue;
        }
        if(!visited[to]) {
            dfs(to, v);
            tout[v] = min(tout[v], tout[to]);

            if(tout[to] > tin[v]) {
                bridges.push_back({v, to});
            }

            stree_size[v]+=stree_size[to];
            stree_edge_cnt[v]+=stree_edge_cnt[to];
        } else{
            tout[v] = min(tout[v], tin[to]);
        }
    }
}

bool canBeDeadend(edge &e) {
    int a = e.from, b = e.to;
    for(auto  from : adj[a]) {
        if(from == b) continue;
        if(edges[{from, a}].inDeadendSubtree) {
            e.inDeadendSubtree=true;
            
            break;
        }
    }
    
    return !e.inDeadendSubtree;
}
void solve(){
    cin >> n >> m;

    adj = vvi(n);

    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

        edges[{a, b}] = {false, false, a, b};
        edges[{b, a}] = {false, false, b, a};
    }
    
    stree_size = stree_edge_cnt = vi(n);
    visited = vb(n);
    tin = tout = vi(n);

    vvi ans;
    rep(i, 0, n) {
        if(!visited[i]) {
            bridges.clear();
            dfs(i, -1);


            // "forward" direction
            // if A->B and B->C are both bridges
            // B->C is earlier in the list of bridges
            for(int i = sz(bridges) - 1; i>= 0; --i) {
                auto &bridge = bridges[i];
                if(stree_edge_cnt[bridge[1]] == stree_size[bridge[1]]-1){
                    auto &cur_edge = edges[{bridge[0], bridge[1]}];
                    if(canBeDeadend(cur_edge)){
                        
                        cur_edge.inDeadendSubtree = true;
                        cur_edge.isAns=true;
                        // ans.push_back({bridge[0], bridge[1]});
                    }
                }
            }

            // "backwards" direction
            // if A<-B and B<-C are both bridges
            // B<-C is earlier in the list of bridges
            for(auto &bridge: bridges) {
                // i is the "root" of the component
                // A->B size of "reverse" subtree of A is [total - subtree(B)]; 
                int edge_cnt = stree_edge_cnt[i] - stree_edge_cnt[bridge[1]] - 1;
                int subtree_size = stree_size[i] - stree_size[bridge[1]];
                if(edge_cnt == subtree_size-1){
                    auto &cur_edge = edges[{bridge[1], bridge[0]}];
                    if(canBeDeadend(cur_edge)){
                        
                        cur_edge.inDeadendSubtree = true;
                        cur_edge.isAns=true;

                        for(auto to : adj[bridge[0]]) {
                            if(to == bridge[1]) continue;
                            auto &child_edge = edges[{bridge[0], to}];
                            if(child_edge.isAns){
                                child_edge.isAns=false;
                            }
                        }
                        // ans.push_back({bridge[0], bridge[1]});
                    }
                }
            }
        }
    }

    rep(i, 0, n) {
        for(auto j : adj[i]) {
            if(edges[{i,j}].isAns) ans.push_back({i, j});
        }
    }
    sort(all(ans));

    cout << ans.size() << '\n';
    for(auto &de: ans) {
        cout << de[0] + 1<< " " << de[1] + 1 << '\n';
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