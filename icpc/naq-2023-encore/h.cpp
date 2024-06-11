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
	
	ll n,k,p;
	cin >> n >> k >> p;


	set<ll> ans;
	rep(i, 1, min((ll)(sqrt(n)+1), k+1)) {
		if(n % i == 0) {
			if(n / i <= p && i <= k) ans.insert(i);
			if(i <= p && n/i <= k) ans.insert(n/i);
		}
	}

	cout << ans.size() << '\n';
	for(auto x : ans) cout << x << '\n';



	return 0;
}