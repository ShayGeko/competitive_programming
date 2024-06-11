#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a, b;
vector<int> used;
vector<vector<int>> adj;
vi ans;
bool dfs(int v) {
	used[v] = 1;
	a--;

	if(a == b) {
		ans.push_back(v);
		return true;
	}

	for(auto to : adj[v]) {
		if(!used[to]) {
			if(dfs(to)) {
				ans.push_back(v);
				return true;
			}
		}
	}
	used[v] = 2;
	++b;
	return a == b;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;
	adj = vector<vi>(n);
	used = vi(n, 0);
	a = n;

	rep(i, 0, m) {
		int x, y;
		cin >> x >> y;
		x--;y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	if(dfs(0)) {
		reverse(all(ans));
		cout << ans.size() << " " << a << '\n';
		for(auto x : ans) cout << x+1 << ' ';
		cout << '\n';
		vi aa, bb;
		rep(i, 0, n) {
			if(used[i] == 0) aa.push_back(i);
			else if(used[i] == 2) bb.push_back(i);
		}

		for(auto x : aa) cout << x+1 << " ";
		cout << '\n';
		for(auto x : bb) cout << x+1 << " ";
		cout << '\n';
	} else {
		assert(false);
	}

	cout.flush();
	return 0;
}