#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 23;
vector<vector<bool>> computed(1<<(N+1), vector<bool>(N, false));
vector<vi> dp(1<<(N+1), vi(N, false));
ll count_masks(int k, int i) {
	if(i == N) return 1;
	if(computed[k][i] ) return dp[k][i];
	if(k & (1 << i)) {
		dp[k][i] = count_masks(k, i + 1);
		computed[k][i]=true;
		return dp[k][i];
	}
	else {
		dp[k][i] =
			count_masks(k, i + 1) + count_masks(k|(1 << i), i+1);
		
		computed[k][i] = true;
		return dp[k][i];
	}
}
int main() {
	// cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


	vector<vector<vi>> transitions;
	int a;
	cin >> a;
	int k = (1 << 23);
	cout << k << '\n';
	// cout << count_masks(0, 0) + count_masks(1,0) << '\n';

	return 0;
}