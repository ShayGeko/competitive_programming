#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;

struct Kuhn{
    int n;
    vector<vector<int>> cap;
    vector<vi> adj;
    vector<bool> vis;
    Kuhn(int n): n(n+1), cap(n+1, vi(n+1, 0)), adj(n+1) {}
    void add_edge(int u, int v, int c){
        adj[u].push_back(v);
        adj[v].push_back(u);
        cap[u][v] += c;
    }
    bool dfs(int v, int t){
        if (v == t) return 1;
        for(auto e: adj[v]){
            if (!cap[v][e] || vis[e]) continue;
            vis[e] = true;
            if (dfs(e, t)) {
                cap[v][e] -= 1;
                cap[e][v] += 1;
                return 1;
            }
        }
        return 0;
    }
    int flow(int s, int t){
        int tot = 0;
        while(true){
            // rep(i,0,n){
            //     rep(j,0,n){
            //         cout << cap[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            vis.assign(n, 0);
            int f = dfs(s, t);
            if (!f) break;
            tot += f;
        }
        return tot;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int s, r, f, t;
	cin >> s >> r >> f >> t;

	vi st, fc;
	map<string, int> st_name;
	rep(i, 1, r+1) {
		string s;
		cin >> s;
		st_name[s] = i;
		st.push_back(i);
	}
	rep(i, r+1, r+f+1) {
		string s;
		cin >> s;
		st_name[s] = i;
		fc.push_back(i);
	}

	Kuhn kuhn (2*s + 2*t + 2);

	int N = 2*s + 2*t, half = s + t;
	int src = N, sink = N + 1;
	rep(i, 0 , r) {
		kuhn.add_edge(src, i, 1);
	}
	rep(i, r, f) {
		kuhn.add_edge(i+half, sink, 1);
	}

	int known = s + r;
	rep(i, 0, t) {
		int k;
		cin >> k;

		kuhn.add_edge(s + i, s + i + half, 1e9);
		rep(i, 0, k) {
			string ss;
			cin >> ss;
			if(st_name.find(ss) == st_name.end()) {
				st_name[ss]=known++;
			}


			// connect 
			kuhn.add_edge(st_name[ss], s + i, 1);
			kuhn.add_edge( 2*s + i, st_name[ss],  1);

			// transportation limit
			kuhn.add_edge(s+i, 2*s + i, 1);
		}
	}

	rep(i, 0, s) {
		kuhn.add_edge(i + half, i, 1e9);
	}

	cout << kuhn.flow(src,sink) << '\n';
}