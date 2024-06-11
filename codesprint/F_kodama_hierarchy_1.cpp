#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/*
5
1 5
2 1
3 2
4 3
5 4

*/
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	vector<pii> ab(n);
	for(auto &x : ab) cin >> x.first >> x.second;

	sort(all(ab));

	vector<int> b(n);
	rep(i, 0, n) b[i] = ab[i].second;

	// find shortest maximal increasing subsequence
	vector<int> dp(n+1, 1e9+1);
	vi idx(n+1, 1e9);
	int k = 0;
	dp[0] = -1;
	idx[0]=-1;
	
	vector<bool> terminal(n, true);
	vector<int> LIS(n);

	vector<vi> history(n+1);
	vector<vi> history_idx(n+1);
	rep(i, 0, n) {
		auto t = b[i];
		auto it = lower_bound(dp.begin(), dp.begin() + k + 1, t);
		auto pos = distance(dp.begin(), it);
		
		// (a,b)
		// 2 5
		// 4 1


		// (2, 1) (3, 1)* (3, 2) -> (2, 1) (3,2)
		// (3, 1) (3, 2)* (4, 2) -> (2, 1) (3,2)
 		if(pos > 1) {
			if (idx[pos] > n){
				auto ppos = pos-1;
				// label all values less than cur as non-terminal in last cell's history
				auto it1 = lower_bound(history[ppos].rbegin(), history[ppos].rend(), t);
				it1 = prev(it1);
				auto pos1 = distance(history[ppos].rbegin(), it1);
				
				pos1 = sz(history[ppos]) - pos1 -1;
				rep(j, pos1, sz(history[ppos])) {
					terminal[history_idx[ppos][j]] = false;
				}
			}
		}

		dp[pos] = t;
		idx[pos]=i;
		history[pos].push_back(t);
		history_idx[pos].push_back(i);
		k = max(k, (int)pos + 1);
		LIS[i] = pos;
		
	}

	int ans = 1e9;
	rep(i, 0, n) {
		if(terminal[i]) ans = min(ans, LIS[i]);
	}

	cout << ans << '\n';


	return 0;
}