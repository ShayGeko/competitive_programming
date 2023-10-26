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
		if(n <= 41) {
			ans.push_back(n);
			rep(i, n+1, 42) ans.push_back(1);
		} else {
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

			rep(a, sum+1, 42) {
				ans.push_back(1);
			}
		}

		cout << "Case #" << i+1 << ": ";
		if(!possible) {
			cout << "-1\n";
		} else {
			sort(all(ans));
			cout << ans.size() << " ";
			rep(i, 0, ans.size() - 1) cout << ans[i] << ' ';
			cout << ans.back() << '\n';
		}
	}

	return 0;
}