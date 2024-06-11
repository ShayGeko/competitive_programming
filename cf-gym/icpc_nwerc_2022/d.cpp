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
	
	int h, w;
	cin >> h >> w;

	vector<string> grid(h);
	for(auto &x : grid) cin >> x;

	// 8 pts per cell [4x vertices + 4x middles]
	// 

	// map<pair<int, int> , vector<tuple<double, int, int>>> adj;
	vector<vector<vector<tuple<double, int, int>>>> adj(
		2*h+1, vector<vector<tuple<double, int, int>>>(2*w+1)
	);

	vector<pii> mp = {{0, 1}, {1, 2}, {2, 1}, {1, 0}};
	/*
		(0, 0) (0, 1) (0,2) (0, 3) (0, 4)
		(1, 0) (1, 1) (1,2) (1, 3) (1, 4)
		(2, 0) (2, 2) (2, 2) (2, 3) (2, 4)

	*/
	const double quart = 2. * acos(-1) * 5 / 4.;
	rep(i, 0, 2*h+1) {
		rep(j, 0, 2*w+1) {
			if(i % 2 && j %2) continue;
			// i j
			// i, j + .5

			if(j % 2 == 0) {
				if(i) {
					adj[i][j].push_back({5, i-1, j});
				}
				if(i < 2*h) {
					adj[i][j].push_back({5, i+1, j});
				}
			}
			if(i % 2 == 0) {
				if(j) {
					adj[i][j].push_back({5, i, j-1});
				}
				if(j < 2*w) {
					adj[i][j].push_back({5, i, j+1});
				}
			}

			// top left corner of a cell, connect all diag
			if(i % 2 == 0 && j % 2 == 0 && i != 2*h && j != 2*w && grid[i/2][j/2] == 'O') {
				rep(k, 0, 4) {
					auto [a, b] = mp[k];
					auto [na, nb] = mp[(k+1)%4];
					adj[i+a][j+b].push_back({quart, i+na, j+nb});
					adj[i+na][j+nb].push_back({quart, i+a, j+b});
				}
			}
		}
	}

	// dist i j v
	typedef tuple<double,int,int> node;
	priority_queue<node, vector<node>, greater<>> pq;
	
	vector<vector<double>> D(2*h+1, vector<double>(2*w+1, 1e9));
	pq.push({0, 0, 0});

	D[0][0] = 0;
	// int ops = 0;
	while(!pq.empty()) {
		// ++ops;
		auto [dist, i, j] = pq.top();pq.pop();
		if(D[i][j] < dist) continue;

		if(i == 2*h && j == 2*w) {
			cout << fixed << setprecision(8) <<  dist << '\n';
			break;
		}
		for(auto [ncost, ni, nj] : adj[i][j]) {
			// ++ops;
			if(D[ni][nj] > dist + ncost) {
				D[ni][nj] = dist + ncost;
				pq.push({dist + ncost, ni, nj});
			}
		}
	}
	return 0;
}