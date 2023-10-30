#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int P = 998244353;

unsigned long long bin_pow(int n, int k) {
    if(k == 0) return 1;
    if(k == 1) return n;

    unsigned long long a = bin_pow(n, k/2);

    unsigned long long dbl = (a * a) % P;

    return (dbl * (k%2? n: 1)) %P;
}

vector<ll> pow2(4e5 + 5);


vector<vi> adj;
vector<vi> bp[2];
vector<bool> col,vis;
bool dfs( int v) {
    vis[v] = true;
    bp[col[v]].back().push_back(v);
    for(auto to : adj[v]){
        if(vis[to] && col[to] == col[v]) {
            return false;
        } else if(!vis[to]) {
            col[to] = !col[v];
            if(!dfs(to)) return false;
        }
    }

    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;

    adj=vector<vi> (n);

    rep(i, 0, m) {
        int a , b;
        cin >> a >> b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    vis = vector<bool> (n, false);
    col = vector<bool> (n);

    
    bp[0].clear();
    bp[1].clear();

    // create bipartite connected components
    rep(i, 0, n) {
        if(!vis[i]) {
            bp[0].push_back({});
            bp[1].push_back({});
            
            if(!dfs(i)) {
                cout << "0\n";
                return;
            };
        }
    }

    unsigned long long ans = 1; 
    rep(i, 0, sz(bp[0])) {
        ans = (ans * (
                ( 
                    pow2[sz(bp[0][i])] + pow2[sz(bp[1][i])] 
                ) %P
            )
        ) %P;
    }

    cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    pow2[0] = 1;
    rep(i, 1, 4e5+5) {
        pow2[i] = (pow2[i-1] * 2) % P;
    }
    while(t--) {
        solve();
    }
    cout.flush();
	return 0;
}