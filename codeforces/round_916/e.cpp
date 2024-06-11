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
	vi a(n), b(n);
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;

	vector<ll> ans(2, 0);
	auto comp = [](pii x, pii y) {
		return x.first + x.second < y.first + y.second;
	};
	priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);

	rep(i, 0, n) {
		pq.push({a[i], b[i]});
	}

	bool mod = false;
	while(pq.size()) {
		auto [A, B] = pq.top();pq.pop();
		if(mod) ans[mod] += B-1;
		else ans[mod] += A-1;
		mod = !mod;
	}

	cout << ans[0] - ans[1] << '\n';
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