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

	int n, x;
	cin >> n >> x;
	vi nums(n);
	rep(i,0,n) cin >> nums[i];

	sort(all(nums));

	int r = n - 1;
	int ans = 0;
	vector<bool> used(n, false);
	rep(l, 0, n) {
		if(used[l]) continue;
		while(r > l && nums[r] + nums[l] > x) r--;
		if(r > l) {
			used[r] = true;
			r--;
		}
		++ans;
	}
	cout << ans << '\n';
	return 0;
}