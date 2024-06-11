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
	// cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vector<vi> nums (n, vi(m));
	rep(i, 0, n) {
		rep(j,0,m) {
			cin >> nums[i][j];
		}
	}

	int cnt = 0;
	rep(i, 0, n) {
		rep(j, 0, m) {
			cnt += 2 + 4 * nums[i][j];
			if(i) cnt -= 2 * min(nums[i][j], nums[i-1][j]);
			if(j) cnt -= 2 * min(nums[i][j], nums[i][j-1]);
		}
	}

	cout << cnt << '\n';

	return 0;
}