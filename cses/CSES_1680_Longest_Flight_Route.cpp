#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi maxPathStartingAt;
vector<bool> visited;
vector<vi> adj;
vi nextNode;
void dfs(int v) {
	visited[v] = true;
	maxPathStartingAt[v] = 1;

	for(auto to : adj[v]) {
		if(!visited[to]) dfs(to);

		if(maxPathStartingAt[v] < maxPathStartingAt[to] + 1) {
			maxPathStartingAt[v] = maxPathStartingAt[to] + 1;
			nextNode[v] = to;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	
	adj = vector<vi>(n);
	visited =  vector<bool>(n, false);
	maxPathStartingAt = vi(n, 0);
	nextNode = vi(n, -1);

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		adj[--a].push_back(--b);
	}

	int best = 0;
	rep(i, 0, n) {
		if(!visited[i]) {
			dfs(i);
			if(maxPathStartingAt[best] < maxPathStartingAt[i]) {
				best = i;
			};
		}
	}

	vi path;
	int cur = best;
	do {
		path.push_back(cur);
		cur = nextNode[cur];
	} while(cur != -1);

	cout << path.size() << '\n';
	for(auto v : path) cout << v + 1 << ' ';
	cout << '\n';

	return 0;
}