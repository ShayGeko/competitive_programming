#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	vi cnt(26, 0);
	for(auto c : s) cnt[c-'A']++;

	int ans = 0;
	rep(i, 0, 26) {
		if(cnt[i] > i)++ans;
	}

	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}