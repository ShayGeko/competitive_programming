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

	// 15 interesting places
	// compute shortest paths between all P, then can probably forget about other nodes
	// dp [mask][curentnode][taxiflag]

	// we also don't really care about the time spent at an interesting place
	// we will spend that amount with any path, so can just add total sum to the best answer

	int N, P, M, G, T;
	cin >> N >> P >> M >> G >> T;

	vi places(P);
	vi vistime(P);
	rep(i, 0, P) {
		cin >> places[i] >> vistime[i];
	}

	vector<vector<pii>> adj(N);
	rep(i, 0, M) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	const ll INF = 1e18;

	// shortest path costs between all P nodes
	vector<vector<ll>> pd(P, vector<ll>(P));
	// shortest path from 0 to P nodes
	vector<ll> start(P, INF);

	// Djikstra from all interesting places
	rep(i, 0, P) {
		vector<ll> d(N, INF);
		priority_queue<pair<ll, int>> pq;
		vector<bool> visited(N, false);

		d[places[i]] = 0;

		pq.push({0, places[i]});
		while(!pq.empty()) {
			auto [cc, v] = pq.top();pq.pop();
			if(cc > d[v] || visited[v]) continue;
			visited[v] = true;

			for(auto &[to, cost] : adj[v]) {
				if(d[to] > cc + cost) {
					d[to] = cc + cost;
					pq.push({d[to], to});
				}
			}
		}

		rep(j, 0, P) pd[i][j] = d[places[j]];
		start[i] = d[0];
	}

	const int maxmask = 1<<P;
	
	// mask curnode taxiflag
	vector<vector<vector<ll>>> dp(maxmask + 1, vector<vector<ll>>(P, vector<ll>(2, INF)));

	rep(i, 0, P) {
		dp[1 << i][i][0] = start[i];
		dp[1<<i][i][1] = T;
	}

	rep(m, 0, maxmask) {

		// // I think this is needed - update the costs within the mask
		// // at this point we know best ways to get to dp[m][i][t] by getting to i and setting ith bit
		// // but then maybe for some j dp[m][j][t] is worse than dp[m][i][t] + pd[i][j]?
		// rep(i, 0, P) {
		// 	if(! ((1 << i) & m)) continue;
		// 	rep(j, 0, P) {
		// 		if(! ((1 << j) & m)) continue;
		// 		if(i == j) continue;
		// 		rep(t, 0, 2) {
		// 			if(dp[m][i][t] == INF) continue;
		// 			dp[m][j][t] = min(dp[m][j][t], dp[m][i][t] + pd[i][j]);
		// 		}
		// 		// there's no way it's good to take a taxi between already visited nodes
		// 		if (dp[m][i][0] < INF) dp[m][j][1] = min(dp[m][j][1], dp[m][i][0] + T);
		// 	}
		// }

		// now all values are optimal within the mask
		// update values outside of mask
		rep(v, 0, P) {
			// v is part of mask
			if(((1<<v) & m) == 0) continue;

			rep(to, 0, P) {
				// to is not part of the mask
				int nextmask = (1 << to) | m;
				if(nextmask == m) continue;

				// updates without taxi
				rep(t, 0, 2) {
					if(dp[m][v][t] == INF) continue;

					dp[nextmask][to][t] = min(dp[nextmask][to][t], dp[m][v][t] + pd[v][to]);
				}
				// updates with taxi
				dp[nextmask][to][1] = min(dp[nextmask][to][1], dp[m][v][0] + T);
			}
		}
	}

	ll best = INF, besttaxi = INF;
	rep(i, 0, P) {
		if(start[i] < INF) {
			// if there is no path from 0 to i, need at least 2 taxis to complete the route
			best = min(best, dp[maxmask-1][i][0] + start[i]);
			besttaxi = min(best, dp[maxmask-1][i][1] + start[i]);
		}
	}
	ll visitsum = 0;
	rep(i, 0, P) visitsum += vistime[i];

	if(best + visitsum <= (ll)G) {
		cout << "possible without taxi\n";
	} else if(besttaxi + visitsum <= (ll)G) {
		cout << "possible with taxi\n";
	} else {
		cout << "impossible\n";
	}

	return 0;
}