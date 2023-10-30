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

	int n;
	cin >> n;
	vi nums(n);
	for(auto &x : nums) cin >> x;


	vi pmax(n), smin(n);

	pmax[0] = nums[0];
	smin[n-1] = nums[n-1];
	rep(i, 1, n) {
		pmax[i] = max(pmax[i-1], nums[i]);
		smin[n-i-1] = min(smin[n - i], nums[n-1-i]);
	}

	int cnt = 0; 
	rep(i, 0, n-1) {
		if(pmax[i] <= nums[i] && smin[i+1] > nums[i]) ++cnt;
	}
	int i = n-1;
	cnt += pmax[i] <= nums[i];

	cout << cnt << '\n';

	return 0;
}