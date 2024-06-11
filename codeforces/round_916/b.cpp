#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n, k;
	cin >> n >> k;

	vi nums(n);
	rep(i, 0, k) nums[i] = i + 1;
	rep(i, k, n) nums[i] = n + k - i;

	for(auto x : nums) cout << x << " ";
	cout << '\n';
} 
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}