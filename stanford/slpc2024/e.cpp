#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vector<bool>> visited;
vector<vi> adj;

void dfs(int v, bool par) {
	visited[v][par] = true;

	for(auto to : adj[v]) {
		if(!visited[to][!par]) {
			dfs(to, !par);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	adj = vector<vi>(n);
	rep(i, 0, n) visited.push_back(vector<bool>(2, false));
	int s, t;
	cin >> s >> t;
	--s;--t;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a;--b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	visited[s][0] = true;

	dfs(s, 0);

	if(visited[t][1]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}

	return 0;
}