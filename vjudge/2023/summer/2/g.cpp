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

vector<int> next_node;
void dfs(int node, vvi &adj, int dp[], bool vis[])
{
    // Mark as visited
    vis[node] = true;
    dp[node] = 1;
    // Traverse for all its children
    for(auto to: adj[node]) {
 
        // If not visited
        if (!vis[to])
            dfs(to, adj, dp, vis);
 
        // Store the max of the paths
        if(dp[node] < dp[to]+1){
            next_node[node] = to;
            dp[node] = 1 + dp[to];
        }
    }
}
// Function that returns the longest path
int findLongestPath(vvi &adj, int n)
{
    // Dp array
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    next_node.resize(n);
 
    // Visited array to know if the node
    // has been visited previously or not
    bool vis[n + 1];
    memset(vis, false, sizeof vis);
 
    // Call DFS for every unvisited vertex
    for (int i = 0; i < n; i++) {
        if (!vis[i])
            dfs(i, adj, dp, vis);
    }
 
    int ans = 0;
 
    // Traverse and find the maximum of all dp[i]
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    vpii tree(n);
    for(auto &x : tree) cin >> x;

    vvi adj(n+2);
    rep(i, 0, n) rep(j,i+1, n){
        auto &[d1, r1] = tree[i];
        auto &[d2,r2] = tree[j];
        if(d2 - r2 > d1 && d1 + r1 < d2) adj[i].push_back(j);
    }
    rep(i, 0, n){
        adj[n].push_back(i);
        adj[i].push_back(n+1);
    }

    int ans = findLongestPath(adj, n+2)-2;

    cout << n - ans << '\n';

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