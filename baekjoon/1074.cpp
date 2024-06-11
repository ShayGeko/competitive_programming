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

	int N;
	cin >> N;
	int i, j;
	cin >> i >> j;

	int ans = 0;
	do {
		int mid = 1 << (N -= 1);
		int sq = mid*mid;
		if(i >= mid) {
			if(j >= mid) {
				// cout << "4th\n";
				ans += sq * 3;
			} else {
				// cout << "3d\n";
				ans += sq * 2;
			}
		} else {
			if(j >= mid){
				// cout << "2nd\n";
				ans += sq;
			} else {
				// cout << "1st\n";
			}
		}
		// cout << ans << '\n';

		int mask = mid - 1;
		i &= mask;
		j &= mask;
	} while(i || j);
	cout << ans << '\n';
	return 0;
}