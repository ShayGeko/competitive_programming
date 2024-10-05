#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> adj;
vector<vi> capacity;

vi reachable;
vector<bool> isReachable;
vi p;
int n;
int bfs(int s, int t) {
	p = vi(n, -1);
	reachable.clear();
	isReachable = vector<bool>(n, false);
	p[s] = -2;
	queue<pair<int, int>> q;

	q.push({s, 1e9});

	while(!q.empty()) {
		auto [v, flow] = q.front();q.pop();
		reachable.push_back(v);
		isReachable[v]=true;

		for(auto to : adj[v]) {
			if(p[to] == -1 && capacity[v][to] > 0) {
				int newflow = min(flow,capacity[v][to]);
				p[to] = v;
				if(to == t) {
					return newflow;
				}
				q.push({to, newflow});
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

	capacity = vector<vi>(n, vi(n, 0));
	adj = vector<vi>(n);

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a;--b;

		adj[a].push_back(b);
		adj[b].push_back(a);
		capacity[a][b] = 1;
		capacity[b][a] = 1;
	}

	int tot_flow = 0;
	while(int flow = bfs(0, n-1)) {
		// cout << flow << '\n';
		tot_flow += flow;

		int cur = n - 1;
		do {
			int prev = p[cur];

			capacity[prev][cur] -= flow;
			capacity[cur][prev] += flow;
			cur = prev;
		} while(cur != 0);
	}

	
	vector<pii> mincut;
	for(auto x : reachable) {
		for(auto to : adj[x]) {
			if(!isReachable[to]) {
				mincut.push_back({x, to});
			}
		}
	}

	assert(mincut.size() == tot_flow);
	cout << mincut.size() << '\n';
	for(auto [a, b] : mincut) {
		cout << a+1 << " " << b + 1 << '\n';
	}

	return 0;
}