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
vb visited;
vvi con_com;
void dfs1(int v, int p = -1) {
    visited[v] = true;
    con_com.back().push_back(v);
    for(auto to : adj[v]){
        if(to != p) dfs1(to, v);
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    
    adj = vvi(n);
    visited = vb(n);
    
    int a, b;
    rep(i, 0, m){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // get cc
    rep(i, 0, n) {
        if(!visited[i]){
            con_com.push_back(vi{});
            dfs1(i);
        }
    }

    // get centroid+depth
    // get max path within cc
    vi edge_cnt(n);
    queue<int> q;
    vi depth(n, 0);
    vi max_path(n, 0);

    vi centroids (sz(con_com));

    int ans = 0;
    rep(cc, 0, sz(con_com)) {
        for(auto v: con_com[cc]) {
            edge_cnt[v] = sz(adj[v]);
            if(edge_cnt[v] <= 1) q.push(v);

            visited[v] = false;
        }

        while(q.size() > 1) {
            auto v = q.front();q.pop();

            for(auto to: adj[v]) {
                if(visited[to]) continue;

                edge_cnt[to]--;
                max_path[to] = max(max_path[to], depth[to] + depth[v]+1);
                depth[to] = max(depth[to], depth[v] + 1);
                if(edge_cnt[to] == 1) {
                    q.push(to);
                     visited[v] = true;
                }
            }
        }

        int centroid = q.front();q.pop();
        centroids[cc] = centroid;
        ans = max(ans, max_path[centroid]);
    }

    // find centroid with max subtree depth
    int maxi = 0;
    rep(i, 1, sz(con_com)){
        if(depth[centroids[i]] > depth[centroids[maxi]]) maxi = i;
    }
    int maxi2 = maxi?0:1;
    int maxi3 = maxi>1?1:2;
    maxi3 = min(maxi3, sz(con_com)-1);

    rep(i, 0, sz(con_com)){
        if(i == maxi) continue;
        if(depth[centroids[i]] > depth[centroids[maxi2]]) maxi2 = i;
    }
    rep(i, 0, sz(con_com)){
        if(i == maxi || i == maxi2) continue;
        if(depth[centroids[i]] > depth[centroids[maxi3]]) maxi3 = i;
    }

    // create a hub topology with max depth centroid in the middle
    rep(i, 0, sz(con_com)) {
        if(i == maxi) continue;
        ans = max(ans, depth[centroids[i]] + depth[centroids[maxi]] + 1);
    }

    if(sz(con_com) >=3)
        ans = max(ans, depth[centroids[maxi2]] + depth[centroids[maxi3]] + 2);
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