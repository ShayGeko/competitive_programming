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

	int t;
	cin >> t;
	rep(i, 0, t) {
		int n;
		cin >> n;

		vi ans;

		
		bool possible = true;

		int tmp = n;
		int k = 2;
		int sum = 0;
		while(tmp > 1) {
			if(sum + k > 41) {
				possible = false;
				break;
			}
			while(tmp % k == 0) {
				ans.push_back(k);
				tmp /= k;
				sum += k;
			}
			++k;
		}

		int ones = 41 - sum;

		int l = 0, r = ans.size() -1;

		while(l < r) {
			if(ans[l]*ans[r] + sum - ans[l] - ans[r] <= 41) {
				sum -= ans[l] + ans[r];
				sum += ans[l]*ans[r];
				ans[r] = ans[l]*ans[r];
				++l;
			} else r--;
		}

		rep(a, sum+1, 42) {
			ans.push_back(1);
		}


		cout << "Case #" << i+1 << ": ";
		if(!possible) {
			cout << "-1\n";
		} else {
			cout << ans.size() - l << " ";
			rep(i, l, ans.size()) cout << ans[i] << " ";
			cout << '\n';
		}
	}

	return 0;
}