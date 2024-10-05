#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<bool> visited, coloring;
vector<vi> inconsistencyEdges;
bool notBipartite = false;

void dfs(int v, int p) {
	visited[v] = true;
	for(auto to : inconsistencyEdges[v]) {
		if (notBipartite) break;
		if(to == p) continue;
		// incosisntency graph needs to be bipartite
		if(visited[to] && coloring[to] == coloring[v]) {
			notBipartite = true;
			return;
		}
		coloring[to] = !coloring[v];
		dfs(to, v);
	}
};

void bfs(int x) {
	queue<pii> q;

	q.push({x, -1});
	while(!q.empty()) {
		auto [v, p] = q.front();q.pop();
		// cout << v << '\n';

		for(auto to : inconsistencyEdges[v]) {
			if (notBipartite) break;
			if(to == p) continue;
			// cout << " " << to << " ";
			// incosisntency graph needs to be bipartite
			if(visited[to] && coloring[to] == coloring[v]) {
				// cout << "FAIL\n";
				notBipartite = true;
				return;
			}
			else if(visited[to]) continue;
			coloring[to] = !coloring[v];
			visited[to] = true;
			q.push({to, v});
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);
 
	int n;
	cin >> n;

	vector<array<int, 2>> events(n);
	rep(i, 0, 2*n) {
		char c; int x;
		cin >> c >> x;
 
		events[x-1][c != '+'] = i;
	}
 
	inconsistencyEdges = vector<vi> (n);
	rep(i, 0, n) {
		rep(j, i+1, n) {
			auto [a1, a2] = events[i];
			auto [b1, b2] = events[j];
 
			if((a1 < b1 && b2 < a2) || (b1 < a1 && a2 < b2) || a1 > b2 || b1 > a2) {
			} else {
				inconsistencyEdges[i].push_back(j);
				inconsistencyEdges[j].push_back(i);
			}
		}
	}
	
	
	notBipartite = false;
	visited = vector<bool> (n, false);
	coloring = vector<bool> (n, false);
	
	rep(i, 0, n) {
		if(!visited[i]) {
			bfs(i);
		}
	}

	if(notBipartite) {
		cout << "*\n";
	} else {
		rep(i, 0, n) {
			if(coloring[i]) cout << "S";
			else cout << "G";
		}
		cout << '\n';
	}
 
 
	return 0;
}