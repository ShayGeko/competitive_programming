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
	while(t--) {
		int n;
		cin >> n;
		vi nums(n);
		for(auto &x : nums) cin >> x;
		sort(all(nums));
		int i = (n -1) / 2, j = (n+1)/2;

		do {
			cout << nums[i--] << " " << nums[j++] << " "; 
		} while(i >= 0 && j < n);
		if(i == 0) cout << nums[i];
		cout << '\n';
	}

	return 0;
}