#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x),end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	vector<string> grid(n);

	rep(i, 0, n) cin >> grid[i];


	vector<vector<bool>> visited(n, vector<bool>(m, false));

	// for cell [i][j], store {{parent_i, parent_j}, move};
	vector<vector<pair<pii, int>>> parent(n, vector<pair<pii, int>>(m));
	int cnt = 0;
	
	queue<pii> q;
	vector<pii> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	string labelLookup = "RLDU";

	pii start, end;

	rep(i, 0, n) rep(j, 0, m) 
		if(grid[i][j] == 'A') start = {i,j};
		else if (grid[i][j] == 'B') end = {i,j};
	
	q.push(start);
	visited[start.first][start.second] = true;

	//bfs
	while(!q.empty()) {
		auto [ci, cj] = q.front();q.pop();

		rep(mv, 0, 4) {
			auto [di, dj] = moves[mv];
			int newi = ci + di, newj = cj + dj;
			if(newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] != '#' && !visited[newi][newj]) {
				q.push({newi, newj});
				visited[newi][newj] = true;
				parent[newi][newj] = {{ci, cj}, mv};
			}
		}
	}

	vi path;
	
	auto cur = end;

	if(!visited[cur.first][cur.second]) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		while(cur != start) {
			auto [prev, mv] = parent[cur.first][cur.second];
			path.push_back(mv);
			cur = prev;
		}
		reverse(path.begin(), path.end());
		cout << path.size() << '\n';
		for(auto mv : path) cout << labelLookup[mv];
		cout << '\n';
	}
	return 0;
}