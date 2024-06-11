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
	// cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vi nums(n);

	int one_cnt = 0;
	for (auto &x : nums) {
		cin >> x;
		one_cnt += x == 1;
	}

	sort(all(nums));


	int k = min(one_cnt + 1, n);
	vector<vi> terms;
	rep(i, 0, k) {
		if(one_cnt > 5) {
			terms.push_back({1,1,1});
			i+=2;one_cnt -= 3;
		} else {
			if(k == n - 1) { // no non-ones
				if(one_cnt == 5) cout << "(1+1+1)*(1+1)";
				else if(one_cnt == 4) cout << "(1+1)+(1+1)";
				else if(one_cnt == 3) cout << "(1+1+1)";
				else if (one_cnt == 2) cout << "(1+1)";
				else if(one_cnt == 1) cout << 1;
			} else {
				// 1 1 1 1 4 -> 2 * 2 * 4
				// 1 1 1 1 3 -> 3 * 4

				

			}
		}
	}
	rep(i, k, n) terms.push_back({nums[i]});

	rep(i, 0, sz(terms)) {
		if(terms[i].size() > 1) cout << "(";
		rep(j, 0, sz(terms[i])) {
			if(j > 0) cout << "+";
			cout << terms[i][j];
		}
		if(terms[i].size() > 1) cout << ")";

		
		if(i < sz(terms) - 1) cout << "*";
	}
	cout << '\n';


	return 0;
}