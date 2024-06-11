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
	vi deg(n, 0);

	typedef pii edge;
	map<edge, int> edge_num;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);

		edge_num[{a,b}]=i;
		edge_num[{b,a}] = i;
		++deg[a];++deg[b];
	}

	vector<bool> visited(n, false);
	vi p(n, -1);
	function<void(int)> dfs = [&](int v) {
		visited[v] = true;
		for(auto to : adj[v]) {
			if(!visited[to]) {
				p[to] = v;
				dfs(to);
			}
		}
	};

	dfs(0);
	vi path = {1};
	int cur = 1;
	
	do {
		cur = p[cur];
		path.push_back(cur);
	} while(cur);
	
	fill(all(p), -1);


	rep(i, 0, sz(path) - 1) {
		p[path[i]] = path[i+1];
	}
	reverse(all(path));

	set<int> spath(all(path));
	fill(all(visited), false);

	// find intersection with original path
	function<int(int)> dfs1 = [&](int v) {
		visited[v] = true;

		for(auto to : adj[v]) {
			if(to == p[v]) continue;
			if(to == 1) {
				// one of the branches has a loop
				// path for alice:
				// path -> 1 -> v -> 1
				// path for bob : path1 -> rev(path1) -> rev(path)
				return v;
			}
			if(visited[to]) continue;
			p[to] = v;
			if(spath.find(to) != spath.end()) {
				return to;
			}
			else{
				int k = dfs1(to);
				if(k != -1) return k;
			}
		}

		return -1;
	};

	int intersec = dfs1(1);

	if(intersec == -1) {
		cout << "No solution." << '\n';
	} else {
		
		int cur = intersec;
		bool loop = false;
		vi path3 = path;
		reverse(all(path3));
		if(spath.find(cur) == spath.end()) {
			path.push_back(intersec);
			path.push_back(1);
			loop = true;
		}
		vi path1 = {};
		do {
			cur = p[cur];
			path1.push_back(cur);
		} while(cur != 1);

		if(loop) {
			vi path2 = path1;
			path2.pop_back();
			reverse(all(path2));
			path1.insert(path1.end(), all(path2));
			path1.insert(path1.end(), all(path3));
		}
		vector<bool> key_used(m, false);
		
		vi keysA, keysB;

		rep(i, 1, sz(path)) {
			int key = edge_num[{path[i-1], path[i]}];
			keysA.push_back(key);
			key_used[key]=true;
		}

		// rest of keys that arent used but need to be split
		rep(i, 0, m) {
			if(!visited[i]) keysB.push_back(i);
		}

		for(auto key : keysA) {
			cout << key << " ";
		}
		cout << '\n';
		for(auto key : keysB) cout << key << " ";
		cout << '\n';

		// Alice:
		rep(i, 1, sz(path)) {
			cout << "MOVE " << path[i] << '\n';
			if(path[i] == intersec) {
				for(int j = max(i-2,0); j >= 0; j--) {
					cout << "DROP " << keysA[j] << '\n';
					if(!loop) {
						path1.push_back(path[j]);
					}
				}
			}
		}
		cout << "DONE" << '\n';

		// Bob:
		rep(i, 1, sz(path1)) {
			cout << "MOVE " << path1[i] << '\n';
			if(path1[i] == intersec) {
				cout << "GRAB" << '\n';
			}
		}
		cout << "DONE\n";
	}


	return 0;
}