#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<int> p;
vector<vi> adj;
vector<vector<ll>> capacity;
int n;
ll bfs(int s, int t) {
	p = vi(n, -1);
	p[s] = -2;

	queue<pair<int, ll>> q;
	q.push({s, 1e18});

	while(!q.empty()) {
		auto [v, flow] = q.front();q.pop();

		for(auto to : adj[v]) {
			if(p[to] == -1 && capacity[v][to]) {
				p[to] = v;
				ll minflow = min(flow, capacity[v][to]);

				if(to == t) {
					return minflow;
				} else {
					q.push({to, minflow});
				}
			}
		}
	}


	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int m;
	cin >> n >> m;

	capacity = vector<vector<ll>> (n, vector<ll>(n, 0));
	adj = vector<vi>(n);
	vector<vector<bool>> isForward(n, vector<bool>(n, false));

	rep(i, 0, m) {
		int a, b, c;
		cin >> a >> b;
		c = 1;
		--a;--b;

		adj[a].push_back(b);
		adj[b].push_back(a);
		capacity[a][b] += c;
		isForward[a][b] = true;
		// capacity[b][a] = c;
	}

	int s = 0, t = n-1;
	ll maxflow = 0;
	while(ll flow = bfs(s, t)) {
		// cout << flow << '\n';

		int cur = t;

		do {
			// cout << "	" << cur << '\n';
			int prev = p[cur];
			capacity[prev][cur] -= flow;
			capacity[cur][prev] += flow;
			cur = prev;
		} while(cur != s);

		maxflow += flow;
	}

	// cout << maxflow << '\n';

	vector<vi> new_graph(n);
	
	rep(v, 0, n) {
		for(auto to : adj[v]) {
			if(capacity[v][to] == 0 && isForward[v][to]) {
				// cout << "Connecting " << v << " " << to << '\n';
				new_graph[v].push_back(to);
				capacity[v][to] = 1;
				capacity[to][v] = 0;
			};
		}
	}

	// rep(v, 0, n) {
	// 	cout << v + 1 << ": ";
	// 	for(auto to : new_graph[v]) {
	// 		cout << to + 1 << " ";
	// 	}
	// 	cout << '\n';
	// }

	vector<vi> paths(new_graph[0].size());

	vector<bool> visited(n, false);
	vector<vi> used(n, vi(n, false));

	function<bool(int, int)> dfs = [&](int v, int i) {
		paths[i].push_back(v);
		visited[v] = true;
		if(v == t) return true;
		for(auto to : new_graph[v]) {
			if(!visited[to] && !used[v][to]) {
				used[v][to] = true;
				if(dfs(to, i)) return true;
			}
		}

		return false;
	};

	rep(i, 0, sz(new_graph[0])) {
		visited = vector<bool>(n, false);
		dfs(0, i);
	}

	cout << paths.size() << '\n';
	rep(i, 0, sz(paths)) {
		cout << paths[i].size()<< '\n';
		for(auto x : paths[i]) {
			cout << x + 1 << " ";
		}
		cout << '\n';
	}
	return 0;
}