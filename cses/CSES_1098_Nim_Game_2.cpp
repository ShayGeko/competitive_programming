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
		vi stones(n);

		for(auto &x : stones) cin >> x;

		int ans = 0;

		for(auto x : stones) {
			auto nim_val = x % 4;
			ans ^= nim_val;
		}

		if(ans == 0) cout << "second\n";
		else cout << "first\n";
	}

	return 0;
}