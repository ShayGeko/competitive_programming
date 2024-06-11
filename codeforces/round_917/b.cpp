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
	cin >> n;
	string s;
	cin >> s;

	vector<bool> visited(26, false);
	ll ans = 0;
	rep(i, 0, sz(s)){
		if(!visited[s[i] -'a']) {
			ans += sz(s) - i;
			visited[s[i]-'a']=true;
		}
	}
	cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}