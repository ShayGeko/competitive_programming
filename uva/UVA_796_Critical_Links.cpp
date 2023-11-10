#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> adj;
vector<bool> visited;
vector<int> tin, flag;
int t = 0;

vector<pii> bridges;
void dfs(int v, int p = -1) {
	tin[v]=flag[v]=++t;
	visited[v]=true;

	for(auto to : adj[v]) {
		if(to == p) continue;
		// tree edge
		if(!visited[to]) {
			dfs(to, v);
			flag[v] = min(flag[v], flag[to]);
			if(flag[to] > tin[v]) {
				bridges.push_back({min(v, to), max(v, to)});
			}
		}
		else {
			// back edge
			flag[v]=min(flag[v], tin[to]);
		}	
	}
}
int main() {

	int n;
	while(cin >> n) {;
		adj = vector<vi>(n);
		visited = vector<bool>(n, false);
		tin = flag =  vi(n);
		bridges.clear();
		t = 0;
		rep(i, 0, n){
			int v;
			cin >> v;
			char _;
			int deg;
			cin >> _ >> deg >> _;
			adj[v].reserve(deg);
			rep(i, 0, deg) {
				int b;
				cin >> b;
				adj[v].push_back(b);
				adj[b].push_back(v);
			} 
		}
		for(int v = 0; v < n; ++v) {
			if(!visited[v]) dfs(v);
		}
		sort(all(bridges));
		cout << bridges.size() << " critical links" << endl;
		rep(i, 0, sz(bridges)) {
			cout << bridges[i].first << " - " << bridges[i].second << endl;
		}
		cout << endl;
	}
	return 0;
}