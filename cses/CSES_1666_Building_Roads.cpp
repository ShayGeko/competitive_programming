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
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue<int> q;
	vector<bool> visited(n, false);

	vi con;
	rep(i, 0, n) {
		if(!visited[i]) {
			con.push_back(i);
			q.push(i);
			visited[i]=true;
			while(!q.empty()) {
				int v = q.front();q.pop();
				for(auto to : adj[v]) {
					if(!visited[to]) {
						visited[to]=true;
						q.push(to);					
					}
				}
			}
		}
	}

	cout << con.size() - 1 << '\n';
	rep(i, 1, con.size()) {
		cout << con[i-1]+1 << " " << con[i]+1 << '\n';
	}
	return 0;
}