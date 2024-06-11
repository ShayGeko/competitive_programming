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

	int n;
	cin >> n;

	if(n < 4 && n > 1) {
		cout << "NO SOLUTION\n";
	} else if(n == 4) {
		cout << "3 1 4 2\n";
		}else {
		vi nums(n);

		if(n % 2 == 0) {
		rep(i,0, n /2) {
			nums[2*i] = i + 1;
			nums[2*i + 1] = n/2 + i + 1;
		}
		nums[n-1] = n;
		} else {
			rep(i,0, n /2) {
			nums[2*i] = i + 1;
			nums[2*i + 1] = n/2 + i + 2;
		}
		nums[n-1] = n/2 + 1;
		}
		for(auto x : nums) cout << x << " ";
	}


	return 0;
}