#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
 
vector<vector<bool>> computed;
vector<vector<int>> nodes;
vector<vector<int>> sum_tax;
vector<vector<int>> sum_dist;
vector<vector<ll>> sum_wdist;

vector<vector<pii>> adj;
vector<ll> tax;
 
 
int compute_call_cnt = 0;
void compute(int u, int i) {
	computed[u][i]=true;
	auto [v, edge_cost] = adj[u][i];
 
	// nodes sumtax sumdist sum_wdist
	rep(j, 0, sz(adj[v])/2) {
		auto [to, toll] = adj[v][j];
		if(to == u) continue;
		else {
			if(!computed[v][j]) {
				compute(v, j);
			}
			
			nodes[u][i] += nodes[v][j];
			sum_tax[u][i] += sum_tax[v][j];
			sum_dist[u][i] += sum_dist[v][j];
			sum_wdist[u][i] += sum_wdist[v][j];
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
 
			nodes[u][i] += nodes[v][j];
			sum_tax[u][i] += sum_tax[v][j];
			sum_dist[u][i] += sum_dist[v][j];
			sum_wdist[u][i] += sum_wdist[v][j];
		}
	}
	// add current node
	++nodes[u][i];
	sum_tax[u][i] += tax[v];
	// shift costs by edge [v, u];
	sum_dist[u][i] +=  nodes[u][i] * edge_cost;
	sum_wdist[u][i] +=  sum_tax[u][i] * edge_cost;
}
ll getCost(int u) {
	ll cost = 0;
 
	rep(i, 0, sz(adj[u])/2) {
		auto [v, toll] = adj[u][i];
		if(!computed[u][i]) compute(u, i);
		// t_u * dist + wdist
		cost += tax[u] * sum_dist[u][i] + sum_wdist[u][i];
	}
	rep(i, sz(adj[u])/2, sz(adj[u])) {
		auto [v, toll] = adj[u][i];
		if(!computed[u][i]) compute(u, i);
		// t_u * dist + wdist
		cost += tax[u] * sum_dist[u][i] + sum_wdist[u][i];
	}
 
	return cost;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
 
	int n;
	cin >> n;
	adj.resize(n);
	tax.resize(n);
	computed.resize(n);
	nodes.resize(n);
	sum_tax.resize(n);
	sum_dist.resize(n);
	sum_wdist.resize(n);
 
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
		nodes[i].resize(sz(adj[i]));
		sum_tax[i].resize(sz(adj[i]));
		sum_dist[i].resize(sz(adj[i]));
		sum_wdist[i].resize(sz(adj[i]));
	}
 
	vector<ll> costs(n);
	rep(i, 0, n) costs[i] = getCost(i);
	for(int i = 0; i < n; ++i) cout << costs[i] << '\n';
 
	// cout << "------------\n";
	// cout << compute_call_cnt << '\n';
	// assert(compute_call_cnt == (n-1)*2);
 
	return 0;
}