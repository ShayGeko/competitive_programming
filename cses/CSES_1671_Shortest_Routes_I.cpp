#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

constexpr ll INF = 1e16;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	vector<vector<pii>> adj(n);

	rep(i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;--b;
		adj[a].push_back({b, c});
	}

	vector<ll> D(n, INF);
	D[0] = 0;

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	pq.push({0, 0});

	while(!pq.empty()) {
		auto [dist, v] = pq.top();pq.pop();

		if(dist > D[v]) continue;

		for(auto& [to, cost] : adj[v]) {
			ll newdist = dist + (ll)cost;
			if(newdist < D[to]) {
				pq.push({newdist, to});
				D[to] = newdist;
			}
		}
	}

	rep(i, 0, n) {
		cout << D[i] << " ";
	}
	cout << '\n';
	return 0;
}