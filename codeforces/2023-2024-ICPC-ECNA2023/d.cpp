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

	ll avg = 0;

	vi a(5), b(5);
	rep(i, 0, 5) {
		cin >> a[i]>> b[i];
	}
	int n, k;
	cin >> n >> k;

	rep(i, 0, 5) {
		avg += a[i] * b[i];
	}

	cout << avg / 5 * n / k << '\n';

	return 0;
}