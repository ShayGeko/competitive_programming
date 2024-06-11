#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


map<string, int> dp;

int calc(string s) {
	if(dp.count(s)) return dp[s];
	if(s.empty()) return 0;
	if(sz(s) == 1) return 1;

	int ans = sz(s);
	rep(len, 1, sz(s)/2 + 1) {
		// try to remove repeating prefixes of size len
		int i = len;
		while(i + len <= sz(s) && s.substr(0, len) == s.substr(i, len)) {
			i += len;
		}
		// [start, len] + []
		ans = min(ans, calc(s.substr(0, len)) + (i < sz(s) ? calc(s.substr(i)) : 0));
	}
	// skip first char and repeat
	ans = min(ans, 1 + calc(s.substr(1)));

	return dp[s] = ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s;
	int t = 0;
	while(cin >> s) {
		if(s == "*") break;

		int ans = calc(s);
		cout << ans << '\n';	
	}
	return 0;
}