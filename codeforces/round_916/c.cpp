#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n,k;
	cin >> n >> k;
	
	vi a(n), b(n);
	for(auto & x : a) cin >> x;
	for(auto &x : b) cin >> x;

	priority_queue<ll> pq;

	ll ans = 0;
	ll cur = 0;
	rep(i, 0, min(n, k)) {
		cur += a[i];
		pq.push(b[i]);
		ans = max(ans, cur + pq.top() * (k - i - 1));
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