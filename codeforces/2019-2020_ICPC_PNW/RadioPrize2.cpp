#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// for stree [A -> B] : (#nodes, sum_tax, sum_dist, sum_wdist)
unordered_map<pii, tuple<int, int, ll, ll>> info;

vector<vector<pii>> adj;
vi tax;
void compute(int u, int v) {
	int edge_cost;

	int snodes = 0, stax = 0;
	ll sum_dist = 0, sum_wdist = 0;
	for(auto [to, toll] : adj[v]) {
		if(to == u) edge_cost=toll;
		else {
			if(!info.count({v, to})) {
				compute(v, to);
			}
			auto [nodes, tax, dist, wdist] 
				= info[{v, to}];
			snodes += nodes;
			stax += tax;
			sum_dist += dist;
			sum_wdist += wdist;
		}
	}
	// add current node
	++snodes;
	stax += tax[v];
	// shift costs by edge [v, u];
	sum_dist += edge_cost * snodes;
	sum_wdist += edge_cost * stax;

	info[{u,v}] = {snodes, stax, sum_dist, sum_wdist};
}
ll getCost(int u) {
	ll cost = 0;

	for (auto [v, toll] : adj[u]) {
		if(!info.count({u,v})) compute(u, v);

		auto [_, sum_tax, sum_dist, sum_wdist]
			= info[{u, v}];
		cost += tax[u] * sum_dist + sum_wdist;
	}

	return cost;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	adj.resize(n);
	tax.resize(n);

	for(auto &x : tax) cin >> x;
	rep(i, 0, n-1) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}

	vector<ll> costs(n);
	rep(i, 0, n) costs[i] = getCost(i);

	for(auto x : costs) cout << x << '\n';

	return 0;
}