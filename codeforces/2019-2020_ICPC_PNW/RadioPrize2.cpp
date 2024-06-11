#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// for stree [A -> B] : (#nodes, sum_tax, sum_dist, sum_wdist)
map<pii, tuple<int, int, ll, ll>> info;
vector<tuple<int, int, ll, ll>> sum_info;
vector<int> dummy_count;

vector<vector<pii>> adj;
vi tax;
tuple<int, int, ll, ll> compute(int u, int v, int edge_cost) {

	auto &[snodes, stax, sum_dist, sum_wdist] 
		= sum_info[v];
	
	// dummy count is >1 -> 1 -> 0, as we dont compute back edge the first time
	if(dummy_count[v] > 0) {
		for(auto [to, toll] : adj[v]) {
			if(to != u) { // skip backedge
				if(!info.count({v, to})) {
					auto [nodes, tax, dist, wdist] = 
						compute(v, to, toll);
					snodes += nodes;
					stax += tax;
					sum_dist += dist;
					sum_wdist += wdist;
					dummy_count[v]--;
				}
			}
		}
	}

	auto [n, t, sd, swd] = sum_info[v];
	auto [bnodes, btax, bdist, bwdist] = info[{v, u}];
	// remove backedge:
	n -= bnodes;
	t -= btax;
	sd -= bdist;
	swd -= bwdist;

	// add current node
	++n;
	t += tax[v];
	// shift costs by edge [v, u];
	sd += edge_cost * n;
	swd += edge_cost * t;

	info[{u,v}] = {n, t, sd, swd};
	return {n,t,sd,swd};
}
ll getCost(int u, int p = -1) {
	ll cost = 0;
	// sum the cost from all subtrees if rooted at u
	for (auto [v, toll] : adj[u]) {
		// compute cost if not computed
		if(!info.count({u,v})) compute(u, v, toll);

		// add cost from subtree
		auto [nodes, stax, sdist, sum_wdist] = info[{u,v}];
		cost += tax[u] * sdist + sum_wdist;
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
	
	dummy_count.resize(n);
	sum_info.resize(n, {0,0,0,0});
	rep(i, 0, n) dummy_count[i] = sz(adj[i]);

	vector<ll> costs(n);
	rep(i, 0, n) costs[i] = getCost(i);

	for(auto x : costs) cout << x << '\n';

	return 0;
}