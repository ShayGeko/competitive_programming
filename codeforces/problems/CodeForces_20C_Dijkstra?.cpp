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

	vector<ll> d(n, 1e18);
	vector<vector<pii>> adj(n);

	rep(i, 0, m) {
		int a, b, c;
		cin >> a >> b >> c;
		--a;--b;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	priority_queue<pair<int, ll>, vector<pair<int, ll>>, greater<pair<int, ll>>> pq;
	pq.push({0,0});
	d[0] = 0;
	vi p(n);
	p[0] = -1;
	vector<bool> done(n, false);
	while(!pq.empty()) {
		auto [c, v] = pq.top();pq.pop();
		if(c > d[v]) continue;
		done[v]=true;
		if(v == n-1) break; 

		for(auto&  [to, cc] : adj[v]) {
			if(!done[to] && (ll)c + cc < d[to]) {
				p[to] = v;
				d[to] = (ll) c + cc;
				pq.push({(ll) c + cc, to});
			}
		}
	}
	if(done[n-1]) {
		vi path;
		int cur = n-1;
		while(cur != -1) {
			path.push_back(cur);
			cur = p[cur];
		}
		reverse(all(path));
		for(auto x : path) cout << x + 1 << " ";
		cout << '\n';
	}
	else {
		cout << "-1\n";
	}
	return 0;
}