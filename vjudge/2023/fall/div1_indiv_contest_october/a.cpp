#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr int INF = 1e9;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vector<vi> adj(n);
	vi inspection(n);

	rep(i, 0, n) cin >> inspection[i];

	
	vector<vi> d(n, vi(n, INF));
	rep(i, 0, n) {
		rep(j, 0, n) {
			cin >> d[i][j];
			if(i != j) d[i][j] += inspection[j];
		}
	}

	vector<vi> flights(m, vi(3));
	rep(i, 0, m) {
		int a,b,c;
		cin >> a >> b >> c;
		flights[i] = {a-1, b-1, c};
	}

	vector<vi> d1 = d;
	// what does the fox say?
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				d1[i][j] = min(d1[i][j], d1[i][k] + d1[k][j]);
			}
		}
	}

	// map end of flight to start of flight if possible to get from end node to start node before flight start 
	Dinic dinic(m*2 + 2);
	int s = 2*m, t = 2*m+1;
	rep(i, 0, m) {
		dinic.addEdge(s, i, 1);
		dinic.addEdge(i+m, t, 1);
	}
	rep(i, 0, m) {
		rep(j, 0, m) {
			if(i == j) continue;
			auto& f1 = flights[i], f2 = flights[j];
			
			// start time of i + duration of i + unscheduled flight time between dest[i] to start[j]
			if(f1[2] + d[f1[0]][f1[1]] + d1[f1[1]][f2[0]] <= f2[2]) {
				dinic.addEdge(i, j + m, 1);
			}
		}
	}

	int flow = dinic.calc(s, t);

	cout << m - flow << '\n';


	return 0;
}