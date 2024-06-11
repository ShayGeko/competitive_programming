#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct PushRelabel {
	struct Edge {
		int dest, back;
		ll f, c;
	};
	vector<vector<Edge>> g;
	vector<ll> ec;
	vector<Edge*> cur;
	vector<vi> hs; vi H;
	PushRelabel (int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}

	void addEdge(int s, int t, ll cap, ll rcap = 0) {
		if(s == t) return;
		g[s].push_back({t, sz(g[t]), 0, cap});
		g[t].push_back({s, sz(g[s]) - 1, 0, rcap});
	}

	void addFlow(Edge & e, ll f) {
		Edge &back = g[e.dest][e.back];
		if(!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
		e.f += f; e.c -= f; ec[e.dest] += f;
		back.f -= f; back.c += f;ec[back.dest] -= f;
	}
	ll calc(int s, int t) {
		int v = sz(g); H[s] = v; ec[t] = 1;
		vi co(2*v); co[0] = v-1;
		rep(i, 0, v) cur[i] = g[i].data();
		for(Edge &e : g[s]) addFlow(e, e.c);

		for(int hi = 0;;) {
			while(hs[hi].empty()) if(!hi--) return -ec[s];
			int u = hs[hi].back(); hs[hi].pop_back();
			while(ec[u] > 0)
				if(cur[u] == g[u].data() + sz(g[u])) {
					H[u] = 1e9;
					for (Edge &e :g[u]) if(e.c && H[u] > H[e.dest]+1)
						H[u] = H[e.dest] + 1, cur[u] = &e;
					if(++co[H[u]], !--co[hi] && hi < v)
						rep(i, 0, v) if(hi < H[i] && H[i] < v)
							--co[H[i]], H[i] = v+1;
					hi = H[u];
				} else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
					addFlow(*cur[u], min(ec[u], cur[u]->c));
				else ++cur[u];
		}
	}
	bool leftOfMinCut(int a) {return H[a] >= sz(g); }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int C, n, m, t;
	cin >> C >> n >> m >> t;

	vector<vi> edges;

	
	PushRelabel pr(n);

	rep(i, 0 , m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;--b;
		edges.push_back(vi{a, b, c});
	}
	ll gains = 0, maxprofit = 0; 
	rep(i, 0, t) {
		PushRelabel pr(n);
		for(auto &e : edges) pr.addEdge(e[0], e[1], e[2], e[2]);
		int a, b, c;
		cin >> a >> b >> c;
		--a;--b;
		edges.push_back(vi{a, b, C+1});
		pr.addEdge(a, b, C+1, C+1);

		ll f = pr.calc(0, 1);

		ll cost = 0;
		vector<vi> mincut; 
		for(auto &e : edges) {
			// check if edge is in min cut
			if(pr.leftOfMinCut(e[0]) ^ pr.leftOfMinCut(e[1])) {
				cost += e[2];
				mincut.push_back(e);
			}
		}
		if(cost <= C) {
			gains += c;
			maxprofit = max(maxprofit, gains - cost);
		}
		else break;
	}

	if(maxprofit == 0) cout << "The only winning move is not to play.\n";
	else cout << maxprofit << '\n';
	return 0;
}