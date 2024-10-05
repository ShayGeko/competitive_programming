#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);


    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vi> adj(n);
        rep(i, 0, n-1) {
            int a, b;
            cin >> a >> b;
            --a;--b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int st, fi;
        cin >> st >> fi;
        --st;--fi;

        vi par(n);
        
        vector<pii> h(n, false);
        function<pii(int,int)> dfs = [&](int v, int p=-1) {
            par[v] = p;
            pii he = {1,1};
            for(auto to :adj[v]) {
                if(to == p) continue;
                auto [hh, cnt] = dfs(to, v);
                ++hh;
                if(hh > he.first) he = {hh, cnt};
                else if(hh == he.first) he.second +=cnt;
            }

            return h[v] = he;
        };

        auto [tot, cnt] = dfs(0, -1);
        if(h[st] > h[fi]) swap(st, fi);

        // rep(i, 0, n) cout << h[i] << '\n';
        int cur = st;
        while(par[cur] != 0) {
            cur = par[cur];
        }
        int pst = cur;


        int al = 0;
        for(auto to : adj[0]) {
            if(to == pst) continue;

             if(al< h[to].first) to = h[to].first;
        }
        al = max(al, h[0].first - h[st].first);
        if(p[st] == 0 && h[st].second > 1)
        // cout << tot << '\n';

        cur = st;
        while(true){
            if(h[cur] >= tot) cout << "Bob\n";
            else cout << "Alice\n";
            if(cur == fi) break;
        }

    }
	return 0;
}