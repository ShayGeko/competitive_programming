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

	vector<vi> adj(n);
	vi inDeg(n, 0);
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		adj[b].push_back(a);
		++inDeg[a];
	}

	vi topoSort;
	topoSort.reserve(n);

	queue<int> q;
	vector<bool> visited(n, false);

	rep(v, 0, n) if(!inDeg[v]) q.push(v);

	while(!q.empty()) {
		auto v = q.front();q.pop();
		topoSort.push_back(v);

		for(auto to : adj[v]) {
			if(--inDeg[to] == 0) {
				q.push(to);
			}
		}
	}

	reverse(all(topoSort));

	vi dp(n, 0);

	dp[0] = 1;
	const int p = 1e9+7;
	
	for(auto v : topoSort) {
		for(auto from : adj[v]) {
			dp[v] = (dp[v] + dp[from]) % p;
		}
	}

	cout << dp[n-1] << '\n';

	return 0;
}