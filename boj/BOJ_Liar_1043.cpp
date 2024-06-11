#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	
	int T;
	cin >> T;

	vector<vi> parties(m);
	vector<vi> adj(n);
	vi truth(T);
	for(auto & x : truth) {
		cin >> x;
		--x;
	}
	rep(i, 0, m){
		int k; cin >> k;
		parties[i] = vi(k);
		for(auto &y : parties[i]) {
			cin >> y;
			--y;
			adj[y].push_back(i);
		}
	}

	vector<bool> visited(m, false);
	vector<bool> knows(n, false);
	for(auto &x : truth) knows[x] = true;
	
	queue<int> q;
	for(auto &x : truth) q.push(x);

	while(!q.empty()) {
		int v = q.front();q.pop();

		for(auto p : adj[v]) {
			if(!visited[p]) {
				visited[p] = true;
				for (auto to : parties[p]) {
					if(!knows[to]) {
						q.push(to);
						knows[to] = true;
					}
				}
			}
		}
	}

	int cnt = accumulate(all(visited), 0);

	cout << m - cnt << '\n';
	return 0;
}