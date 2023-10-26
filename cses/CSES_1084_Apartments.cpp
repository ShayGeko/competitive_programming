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

	int n,m,k;
	cin >> n >> m >> k;

	vi a(n), b(m);

	rep(i, 0, n) cin >> a[i];
	rep(i, 0, m) cin >> b[i];
	sort(all(a));
	sort(all(b));

	// two-pointer
	// if there is no appartment for a-i + k, then
	// for a_i+1 there is no need to search before a_i+k, as that wouldve been already taken
	int r = 0, ans = 0;
	rep(l, 0, n) {
		while(r < m && b[r] < a[l] - k){
			++r;
		} 
		//first el b[r] +k >= a[l]
		if(r < m && b[r] <= a[l] + k) {
			++ans;
			++r;
		}
	}

	cout << ans << '\n';

	return 0;
}