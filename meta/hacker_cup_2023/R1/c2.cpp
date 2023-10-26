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

	rep(z, 0, t) {
		int n, m;
		cin >> n;
		string s;
		cin >> s;
		cin >> m;

		vi nums(m);
		rep(i, 0, m) cin >> nums[i];

		unordered_set<int> pressed;

		rep(i, 0, s.size()) {
			if(s[i] == '1') {
				pressed.insert(i+1);
				for(int j = i; j < n; j += i + 1) {
					s[j] = '1'-s[j] + '0';
				}
			}
		}
		

		ll ans = 0;

		rep(i, 0, m) {
			if(pressed.count(nums[i])) {
				pressed.erase(nums[i]);
			} else pressed.insert(nums[i]);

			ans += pressed.size();
		}

		cout << "Case #" << z+1 << ": "<< ans << '\n';
	}

	return 0;
}