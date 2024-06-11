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

	int n, K, D, q;
	cin >> n >> K >> D >> q;

	
	vector<pii> DK(n);
	rep(i, 0, n) cin >> DK[i].first;
	rep(i, 0, n) cin >> DK[i].second;

	set<pii> DKset(all(DK));
	sort(all(DK));

	vector<int> next;
	vector<vector<pii>> D_by_K(K);
	rep(i, 0, n){
		auto [d, k] = DK[i];
		D_by_K[k].push_back({d,i});
	} 

	rep(i, 0, n) {
		int next_k = ((DK[i].second) + 1) % K;
		int d = DK[i].first;

		auto it = upper_bound(all(D_by_K[next_k]), pii{d,0});
		if(it == D_by_K[next_k].end()) it= D_by_K[next_k].begin();
		next[i] = (*it).second;
	}

	int cycle_start;
	vector<bool> visited(n, false);
	int cur = 0;
	visited[cur] = true;
	while(!visited[cur]) {
		cur = next[cur];
	}
	cycle_start = cur;
	vector<bool> is_main_cycle(n, false);

	vector<tuple<int, int, int>> main_cycle;
	vi cycle_pos(n);

	int i =0 ;
	do {
		is_main_cycle[cur]=true;
		main_cycle.push_back({DK[cur].first, DK[cur].second, cur});
		cycle_pos[cur]=i++;
		cur = next[cur];
	} while(cur != cycle_start);

	vector<ll> pr_sum(2 * sz(main_cycle) + 1);
	pr_sum[0] = 0;
	int ldist = 0;
	rep(i, 1, sz(pr_sum)) {
		auto [d, k, idx] = main_cycle[i];
		pr_sum[i] = pr_sum[i-1] + ((d -ldist + D) % D); // prefix sum on distances, wraps around
	}
	map<int, int> dp;

	rep(j, 0, q) {
		int start, bread, k;

		int next_k = (k+1) % K;
		int d = start;

		auto it = upper_bound(all(D_by_K[next_k]), pii{d,0});
		if(it == D_by_K[next_k].end()) it= D_by_K[next_k].begin();
		auto [d, i] = *it;
		if(is_main_cycle[i]) {
			int cpos = cycle_pos[i];
			if(cpos == 0) cpos += main_cycle.size();
			cout << pr_sum[cpos + k]-pr_sum[cpos-1];
		} else {
			
		}
	}






	// for each K, store all distances sorted. Then lowerbound to get the next one.


	


	while(q--) {
		int st, top, total;
		cin >> st >> top >> total;


	}

	return 0;
}