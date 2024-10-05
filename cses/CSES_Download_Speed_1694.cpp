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

	rep(i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;--b;

		adj[a].push_back(b);
		adj[b].push_back(a);
		capacity[a][b] += c;
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

	cout << maxflow << '\n';

	return 0;
}