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

	set<int> a;
	vi nums;
	int x;
	while(cin >> x) {
		nums.push_back(x);
	}

	rep(i, 0, sz(nums)) rep(j, i+1, sz(nums)) {
		rep(k, j +1, sz(nums)) {
			if(nums[i] + nums[j] + nums[k] == 2020) {
				cout << '\n' << nums[i] *nums[j] * nums[k] << '\n';
				return 0;
			}
		}
	}

	return 0;
}