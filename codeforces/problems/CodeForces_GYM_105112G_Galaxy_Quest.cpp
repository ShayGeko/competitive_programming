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
	// cin.exceptions(cin.failbit);

	int n, m, q;
	cin >> n >> m >> q;

	vector<array<long double, 3>> coords(n);

	for(auto &x : coords) cin >> x[0] >> x[1] >> x[2];
	vector<vector<pair<int, double>>> graph(n);

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		long double dx =coords[a][0] - coords[b][0];
		long double dy = coords[a][1] - coords[b][1];
		long double dz = coords[a][2] - coords[b][2];
		long double d = sqrt(dx*dx + dy*dy +dz*dz);
		graph[a].emplace_back(b, sqrt(d));
		graph[b].emplace_back(a, sqrt(d));
	}

	vector<long double> D(n, 1e18);
	D[0] = 0;

	priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;

	pq.push({0,0});

	// cout << "starting dijkstra\n";
	while(!pq.empty()) {
		auto [x, v] = pq.top();pq.pop();

		if(D[v] < x)  continue;

		for(auto [to, cost] : graph[v]){
			if(D[to] > x + cost) {
				D[to] = x + cost;
				pq.push({x+cost, to});
			}
		}
	}



	rep(i, 0, q) {
		int v; long double T;
		cin >> v >> T; --v;

		
		long double b = T / D[v];

		if(b < 2) {
			cout << "impossible\n";
			continue;
		}

		long double c = (b - sqrt(b*b - 4)) / 2.;

		cout << fixed << setprecision(8) << 2 * D[v] * c << '\n';
	}

	return 0;
}