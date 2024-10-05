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
		// cout << v << " " << flow << '\n';
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
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

	int l, r, k;
	cin >> l >> r >> k;
	n = l + r + 2;

	adj = vector<vi>(n);
	capacity = vector<vi> (n, vi(n, 0));
	rep(i, 0, k) {
		int a, b;
		cin >> a >> b;
		b += l;
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);

		capacity[a][b] = 1;

		// cout << "Connecting " << a << " " << b << '\n';
	}

	int s = n-2, t = n - 1;

	rep(i, 0, l) {
		capacity[s][i] = 1;
		adj[s].push_back(i);
		adj[i].push_back(s);
		// cout << "Connecting " << s << " " << i << '\n';
	}
	rep(i, 0, r) {
		adj[t].push_back(i + l);
		adj[i+l].push_back(t);
		capacity[i + l][t] = 1;
		// cout << "Connecting " << i+l << " " << t << '\n';
	}

	
	int tot_flow = 0;
	while(int flow = bfs(s, t)) {
		// cout << flow << '\n';
		tot_flow += flow;

		int cur = n - 1;
		do {
			int prev = p[cur];

			capacity[prev][cur] -= flow;
			capacity[cur][prev] += flow;
			cur = prev;
		} while(cur != s);
	}

	vector<pii> pairs;
	rep(i, 0, l){
		rep(j, l, l+r) {
			if(capacity[j][i] == 1) {
				pairs.push_back({i+1, j-l+1});
			}
		}
	}

	cout << pairs.size() << '\n';
	for(auto [a, b] : pairs) {
		cout << a << " " << b << '\n';
	}


	return 0;
}