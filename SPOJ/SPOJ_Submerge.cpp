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
vi tin, low;

set<int> ap;
int t = 0;
void dfs(int v, int p = - 1) {
	visited[v] = true;
	tin[v]=low[v]=t++;
	int st_size = 0;

	for(auto to : adj[v]) {
		if(to == p) continue;
		if(!visited[to]) {
			++st_size;
			dfs(to, v);
			low[v] = min(low[v], low[to]);
			if(p != -1 && low[to] >= tin[v]) {
				ap.insert(v);
			}
		} else {
			low[v] = min(tin[to], low[v]);
		}
	}

	if(p == -1 && st_size > 1) {
		ap.insert(v);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	while(cin >> n >> m && n > 0) {
		adj = vector<vi>(n);
		visited = vector<bool> (n, false);
		tin = low = vi(n);
		ap.clear();

		rep(i, 0, m) {
			int a, b;
			cin >> a >> b;
			--a;--b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		rep(i, 0, n) {
			if(!visited[i]) dfs(i);
		}

		cout << ap.size() << '\n';
	}
	return 0;
}