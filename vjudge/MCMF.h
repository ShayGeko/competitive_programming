#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#pragma once
const ll INF = numeric_limits<ll>::max() / 4;

#include <bits/extc++.h>

int layer, n;
int lo(int i, int j) {
	return i * n + j;
}
int hi(int i, int j) {
	return i*n + j + layer;
}
struct MCMF {
	struct edge {
		int from, to, rev;
		ll cap, cost, flow;
	};
	int N;
	vector<vector<edge>> ed;
	vi seen;
	vector<ll> dist, pi;
	vector<edge*> par;

	MCMF(int N): N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		if(from == to) return;
		ed[from].push_back(edge {from, to, sz(ed[to]), cap, cost, 0});
		ed[to].push_back(edge {to, from, sz(ed[from]) -1, 0, -cost, 0});
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({0, s});

		while(!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];

			for(edge &e : ed[s]) if(!seen[e.to]) {
				ll val = di - pi[e.to] + e.cost;
				if(e.cap - e.flow > 0 && val < dist[e.to]) {
					dist[e.to] = val;
					par[e.to] = &e;
					if (its[e.to] == q.end())
						its[e.to] = q.push({-dist[e.to], e.to});
					else 
						q.modify(its[e.to], {-dist[e.to], e.to});
				}
			}
		}

		rep(i, 0, N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while(path(s), seen[t]) {
			ll fl = INF;
			for(edge * x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);
			
			totflow += fl;
			for(edge *x = par[t]; x; x = par[x->from]) {
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}

		rep(i, 0, N) for(edge & e : ed[i]) totcost += e.cost * e.flow;
		return {totflow, totcost / 2};
	}

	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
			  for (edge& e : ed[i]) if (e.cap)
				  if ((v = pi[i] + e.cost) < pi[e.to])
					  pi[e.to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	while(cin >> n) {
		vector<string> grid(5);
		rep(i, 0, 5) cin >> grid[i];

		layer = 5 * n;
		int num_v = layer * 2 + 2;

		MCMF mcmf(num_v);
		
		int source = 2 * layer, sink = 2 * layer + 1;
		rep(i, 0, 5) {
			rep(j, 0, n) {
				int cost = j ? grid[i][j] - '0' : 0;
				
				if(j == 0 && grid[i][j] == '@') mcmf.addEdge(source, lo(i, j), 1, 0);
				if(j == n) mcmf.addEdge(hi(i,j), sink, 1, 0);


				mcmf.addEdge(lo(i, j), hi(i, j), 1, cost);

				if (i) mcmf.addEdge(hi(i, j), lo(i-1, j), 1, 0);
				if (i < 5 - 1) mcmf.addEdge(hi(i, j), lo(i+1, j), 1, 0);
				if(j < n - 1) mcmf.addEdge(hi(i, j), lo(i, j+1), 1, 0);
				if (j) mcmf.addEdge(hi(i, j), lo(i, j - 1), 1, 0); 
			}
		}
		auto [mxflo, minco] = mcmf.maxflow(source, sink);

		cout << minco << '\n';
	}

	cout.flush();

	return 0;
}