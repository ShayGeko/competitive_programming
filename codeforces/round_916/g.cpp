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

	vector<pii> fila(n, {-1,-1});
	vector<int> bulbs(2*n);
	rep(i, 0, sz(bulbs)) {
		cin >> bulbs[i];
		int x = bulbs[i];
		if(fila[x].first == -1) fila[x].first = i;
		else fila[x].second = i;
	}

	ll cnt = 0;
	ll cur = 1, prod = 1;
	ll p = 998244353;
	int r = -1;
	rep(i, 0, sz(bulbs)) {
		if(i > r) {
			prod = (prod * cur) % p;
			cur = 1;
			r = i;
		}
		
	}
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