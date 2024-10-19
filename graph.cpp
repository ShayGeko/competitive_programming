#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<vi> adj;

void dfs(int v) {

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


	int n, m;
	cin >> n >> m;

	
	adj = vector<vi>(n);
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0);
	return 0;
}