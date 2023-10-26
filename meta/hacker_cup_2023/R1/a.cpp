#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	cin >> t;


	for(int i = 0; i < t; ++i) {
		int n;
		cin >> n;

		vector<double> nums(n);

		rep(j, 0, n) {
			cin >> nums[j];
		}

		sort(all(nums));

		cout << "Case #" << i +1 << ": ";
		if(n <= 3) cout << 0 << '\n';
		else if(n == 5) {
			cout << fixed <<  max(
				((nums[4] + nums[3]) / 2. - (nums[2] + nums[0]) / 2.), 
				((nums[4] + nums[2]) / 2. - (nums[1] + nums[0]) / 2.)
			);
		}
		else cout << fixed << ((nums[n-1] + nums[n-2]) / 2. - (nums[1] + nums[0]) / 2.);

		cout << '\n';
	}
	return 0;
}