#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef tuple<int,int,int> edge_t;
typedef pair<int, edge_t> lcae_t;

vector<vi> node_jmp;
vector<vector<edge_t>> minedge_jmp;
vi depth;
void computeBinLift(vi& P, vector<edge_t>& Pcost){
	int on = 1, d = 1;
	while(on < sz(P)) on *= 2, d++;
	node_jmp = vector<vi>(d, P);
	minedge_jmp = vector(d, Pcost);


	rep(i,1,d) 
		rep(j,0,sz(P)){ // for every power for every node
			node_jmp[i][j] = node_jmp[i-1][node_jmp[i-1][j]];
			minedge_jmp[i][j] = min(minedge_jmp[i-1][j], minedge_jmp[i-1][node_jmp[i-1][j]]);
		}

}

pair<int, edge_t> jmp(int nod, edge_t cost, int steps){
	int oldnod = nod;
	rep(i,0,sz(node_jmp))
		if(steps&(1<<i)) {
			nod = node_jmp[i][nod];
			cost = min(cost, minedge_jmp[i][oldnod]);
		}
	return {nod, cost};
}

pair<int, edge_t> lca(int a, int b, edge_t costA = {1e9,0,0}, edge_t costB = {1e9,0,0}) {
	if (depth[a] < depth[b]) swap(a, b);
	tie(a, costA) = jmp(a, costA, depth[a] - depth[b]);
	if (a == b) return {a, costA};
	for (int i = sz(node_jmp); i--;) {
		int c = node_jmp[i][a], d = node_jmp[i][b];
		edge_t c_cost = minedge_jmp[i][a], d_cost = minedge_jmp[i][b];
		if (c != d) {
			a = c, b = d;
		}
	}
	return {node_jmp[0][a], min(min(costA, costB), minedge_jmp[0][a])};
}

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};



void dfs(vector<vector<pii>> &adj, vi &P, vector<edge_t> &Pcost, int v) {
	for(auto [to,cost] : adj[v]) {
		if(to == P[v]) continue;
		P[to] = v;
		depth[to] = depth[v] + 1;
		Pcost[to] = {cost,v,to};
		dfs(adj, P,Pcost, to);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	// cost u v
	vector<edge_t> edges(m);

	for(auto &[a,b,c] : edges) {
		cin >> b >> c >> a;
		--b;--c;
	}

	sort(all(edges));

	UF uf(n);

	vector<edge_t> mst; mst.reserve(m);
	set<edge_t> other;

	ll mst_cost = 0;
	for(auto &[a, b, c] : edges) {
		if(!uf.sameSet(b, c)) {
			mst.emplace_back(a,b,c);
			uf.join(b,c);
			mst_cost += a;
		}
		else other.insert({a,b,c});
	}

	vector<vector<pii>> adj(n);
	for(auto [c,a, b] : mst) {
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	
	vi P(n, -1);
	vector<edge_t> Pcost(n, {1e9,0,0});
	depth = vi(n, 0);
	dfs(adj, P, Pcost, 0);
	P[0]=0;


	computeBinLift(P, Pcost);
	
	ll ans = mst_cost;
	while(true) {
		ans = mst_cost;
		edge_t remove_edg, trial;
		for(auto [c, a, b] : other) {
			auto [node, edge] = lca(a, b);  
			auto [cost, ar, br] = edge;
			if(mst_cost + c - cost > ans) {
				ans = mst_cost + c - cost;
				remove_edg = edge;
				trial = {c,a,b};
			}
		}

		UF uf1(n);
		auto [rc, ra, rb] = remove_edg;
		auto [tc, ta, tb] = trial;

		ll new_cost = 0;
		for(auto &[c, a, b] : edges) {
			if(c == rc && (min(a,b) == min(ra,rb) && max(a,b) == max(ra,rb))) {
				continue;
			}
			if(uf1.sameSet(a,b)) continue;

			uf1.join(a, b);
			new_cost += c;
		}

		if(new_cost == ans) break;
		else other.erase(trial);
	}

	cout << ans << '\n';

	return 0;
}