#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi stree;
vector<bool> vis;
vector<vi> adj;
void dfs(int v) {
	vis[v] = true;
	stree[v] = 0;
	for(auto to : adj[v]) {
		if(!vis[to]) {
			dfs(to);
			stree[v] += stree[to] + 1;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	
	int m = n - 1;

	adj = vector<vi>(n);
	vis = vector<bool>(n, false);
	stree = vi(n);
	vi colors(n);

	rep(i, 0, n) cin >> colors[i];

	vector<pii> edges;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);

		edges.push_back({a, b});
	}

	dfs(0);

	rep(i, 0, n) cout << stree[i] << ' ';
	cout << '\n';
	int ans = 0;
	
	for(auto [a, b] : edges) {
		if(stree[a] < stree[b]) swap(a, b);
		if(colors[a] == colors[b]) {
			cout << (n - stree[b] - 1) * (stree[b] + 1); 
		}
	}

	cout << ans << '\n';

	return 0;
}