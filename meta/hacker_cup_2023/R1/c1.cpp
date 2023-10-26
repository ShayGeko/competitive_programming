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

		
		sort(all(nums));
		rep(i, 0, m) {
			int k = 1;
			int a = i+1;
			while(a < m && nums[a]==nums[i]) {
				++k;++a;
			}
			if(k%2){
				for(int j = nums[i]-1; j < n; j += nums[i]) {
					s[j] = '1'-s[j] + '0';
				}
			}
			i = a -1;
		}


		int cnt = 0;
		rep(i, 0, n) {
			if(s[i] == '1') {
				++cnt;
				for(int j = i; j < n; j += i + 1) {
					s[j] = '1'-s[j] + '0';
				}
			}
		}
		cout << "Case #" << z+1 << ": "<<cnt << '\n';
	}

	return 0;
}