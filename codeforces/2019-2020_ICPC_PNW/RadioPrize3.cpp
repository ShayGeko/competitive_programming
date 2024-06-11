#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// for stree [A -> B] : (#nodes, sum_tax, sum_dist, sum_wdist)
map<pii, array<ll, 4>> info;
vector<array<ll, 4>> stree_info;
vector<ll> ans;

vector<vector<pii>> adj;
vi tax;

void dfs1(int v, int p=-1) {
	array<ll, 4> cur = {1,tax[v],0,0};
	auto& [nodes, sum_tax, sum_dist, sum_wdist]  = cur;
	for(auto [to, toll] : adj[v]) {
		if(to != p) {
			dfs1(to, v);
			// get subtree
			auto [to_n, to_st, to_sd, to_swd] = stree_info[to];
			// add shifted to cur
			nodes += to_n;
			sum_tax += to_st;
			sum_dist += (ll) to_n * toll + to_sd;
			sum_wdist += (ll) to_st * toll + to_swd;
		}
	}

	stree_info[v] = cur;
}

void dfs2(int u, int p=-1, const array<ll, 4> &ut = {0,0,0,0}) {
	auto cur = ut;
	auto &[cn, cst, csd, cswd] = cur;

	rep(i, 0, 4) cur[i] += stree_info[u][i];

	ans[u] = csd * tax[u] + cswd;
	for(auto [to, toll] : adj[u]) {
		if(to != p) {
			auto [to_n, to_st, to_sd, to_swd] = stree_info[to];
			// subtract current subtree
			cn -= to_n;
			cst -= to_st;
			csd -= (ll) to_n * toll + to_sd;
			cswd -= (ll) to_st * toll + to_swd;
			
			// shift backside subtree by the edge
			csd += cn * toll;
			cswd += cst * toll;

			dfs2(to, u, cur);
			
			// shift back
			csd -= cn * toll;
			cswd -= cst * toll;

			// add the subtree back
			cn += to_n;
			cst += to_st;
			csd += (ll) to_n * toll + to_sd;
			cswd += (ll) to_st * toll + to_swd;
		}
	}
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
	
	stree_info.resize(n);
	ans.resize(n);

	dfs1(0);
	dfs2(0);


	for(auto x : ans) cout << x << '\n';

	return 0;
}