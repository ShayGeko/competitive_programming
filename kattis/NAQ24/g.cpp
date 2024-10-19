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

	int n;
	cin >> n;

	vector<pii> axels(n);
	
	map<int, vi> saxels;
	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		axels[i] = {a, b};

		saxels[a].push_back(b);
	}
	for(auto &[k, v] : saxels) {sort(all(v)); reverse(all(v));}

	/*
		x -> a/b x -> a/b b/c c/e x

		can do
		a -> b | c
		c -> d | e

		then we get
		x -> a / b x
		  -> (a / b) (c / d) x

		log (a / b) (c / d) x = log 1 + log (a / b) + log(c / d) + .. +
	*/

	long double ans = 0;

	for(auto [k, v] : saxels) {
		for(int i = 0, j = sz(v) -1; i < j; ++i, --j) {
			ans += log((long double)v[i]) - log((long double)v[j]);
		}
	}

	cout << fixed << setprecision(10) << ans << '\n';

	return 0;
}