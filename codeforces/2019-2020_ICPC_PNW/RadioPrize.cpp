#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<vector<bool>> computed;
// for stree [A -> B] : (#nodes, sum_tax, sum_dist, sum_wdist)
vector<vector<vector<ll>>> info;
vector<vector<pii>> adj;
vector<ll> tax;


int compute_call_cnt = 0;
void compute(int u, int i) {
	auto [v, edge_cost] = adj[u][i];
	++compute_call_cnt;

	// nodes sumtax sumdist sum_wdist
	vector<ll> cur(4, 0);
	rep(j, 0, sz(adj[v])/2) {
		auto [to, toll] = adj[v][j];
		if(to == u) continue;
		else {
			if(!computed[v][j]) {
				compute(v, j);
			}

			rep(t, 0, 2) cur[t] += info[v][j][t];
			// im not crazy im not crazy
			rep(t, 2, 4) cur[t] += info[v][j][t];
		}
	}
	// IM NOT CRAZY IM NOT CRAZY
	rep(j, sz(adj[v])/2, sz(adj[v])) {
		auto [to, toll] = adj[v][j];
		if(to == u) continue;
		else {
			if(!computed[v][j]) {
				compute(v, j);
			}

			rep(t, 0, 2) cur[t] += info[v][j][t];
			// im not crazy im not crazy
			rep(t, 2, 4) cur[t] += info[v][j][t];
		}
	}
	// add current node
	++cur[0];
	cur[1] += tax[v];
	// shift costs by edge [v, u];
	cur[2] +=  cur[0] * edge_cost;
	cur[3] +=  cur[1] * edge_cost;

	info[u][i] = cur;
	computed[u][i]=true;
}
ll getCost(int u) {
	ll cost = 0;

	rep(i, 0, sz(adj[u])/2) {
		auto [v, toll] = adj[u][i];
		if(!computed[u][i]) compute(u, i);
		// t_u * dist + wdist
		cost += tax[u] * info[u][i][2] + info[u][i][3];
	}
	rep(i, sz(adj[u])/2, sz(adj[u])) {
		auto [v, toll] = adj[u][i];
		if(!computed[u][i]) compute(u, i);
		// t_u * dist + wdist
		cost += tax[u] * info[u][i][2] + info[u][i][3];
	}

	return cost;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	adj.resize(n);
	tax.resize(n);
	computed.resize(n);
	info.resize(n);

	for(auto &x : tax) cin >> x;
	int a, b, c;
	rep(i, 0, n-1) {
		cin >> a >> b >> c;
		--a;
		--b;
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	rep(i,0, n) {
		computed[i].resize(sz(adj[i]), false);
		info[i].resize(sz(adj[i]));
	}

	vector<ll> costs(n);
	rep(i, 0, n) costs[i] = getCost(i);
	for(int i = 0; i < n; ++i) cout << costs[i] << '\n';

	// cout << "------------\n";
	// cout << compute_call_cnt << '\n';
	// assert(compute_call_cnt == (n-1)*2);

	return 0;
}