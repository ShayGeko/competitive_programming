#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

typedef vector<bool> vb;

vb visited, removed;
vi nexthop, d;
vector<vi> adj;

int dfs(int v) {
    if(d[v] >= 0) return d[v];
    visited[v] = true;
//    cout << "DFS " << v << '\n';
    int a = 0;
    for(auto to : adj[v]) {
        if(removed[to]) continue;
        if(dfs(to) > a) {
            nexthop[v] = to;
            a = d[to];
        }
    }

    return d[v] = a+1;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;
    adj= vector<vi>(n);

    rep(i, 0, n) {
        int k;
        cin >> k;
        while(k--) {
            int a; cin >> a;

            adj[i].push_back(a);
        }
    }

    int cnt = n;

    visited = vb(n), removed = vb(n, false);
    nexthop=vi(n);
    d = vi(n, 0);

    int ans = 0;
    while(cnt > 0) {
        fill(all(visited), false);
        fill(all(d), 0);
        fill(all(nexthop), -1);
        int maxi = 0;
        rep(v, 0, n) {
            if(!removed[v] && !visited[v]) {
//                cout << "Looking for path starting at " << v << '\n';
                if(dfs(v) > d[maxi]) maxi = v;
            }
        }

        cnt -= d[maxi];
        int v = maxi;
       cout << "TAKING PATH FROM " << v << ": ";
        do {
           cout << "(" <<  v << ", " << d[v] << ") ";
            removed[v] = true;
            v = nexthop[v];
        } while(v != -1);
       cout << '\n';
        ++ans;
    }

    cout << ans << '\n';
}