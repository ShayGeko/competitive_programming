#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
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
	int cnt = 0;
	rep(i, 0, n) rep(j, 0, m) {
		if(grid[i][j] == '.' && !visited[i][j]) {
			++cnt;
			
			queue<pii> q;
			vector<pii> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

			q.push({i, j});
			visited[i][j] = true;
			while(!q.empty()) {
				auto [ci, cj] = q.front();q.pop();

				for(auto [di, dj] : moves) {
					int newi = ci + di, newj = cj + dj;
					if(newi >= 0 && newi < n && newj >= 0 && newj < m && grid[newi][newj] == '.' && !visited[newi][newj]) {
						q.push({newi, newj});
						visited[newi][newj]=true;
					}
				}
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}