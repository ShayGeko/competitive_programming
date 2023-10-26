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
	rep(i,0,n) {
		cin >> nums[i];
	}

	map<int, int> last;
	set<int> st;
	last[nums[0]] = 0;
	st.insert(nums[0]);
	int l = 0;
	int cur = 1, best = 1;
	rep(r, 1, n) {
		if(st.count(nums[r])) {
			best = max(best, cur);
			int k = last[nums[r]];
			assert(k >= l);
			cur -= k - l;
			for(; l < k; ++l) {
				st.erase(nums[l]);
			}
		} else {
			st.insert(nums[r]);
			++cur;
		}
		last[nums[r]] = r;
	}
	best = max(best, cur);
	cout << best << '\n';

	return 0;
}