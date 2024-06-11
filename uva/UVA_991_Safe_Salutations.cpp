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

	int n;
	vector<ll> catalan(11);
	catalan[0] = catalan[1] = 1;
	rep(i, 2, 11) {
		catalan[i] =  2 * (2*i-1)* catalan[i-1]/ (i + 1) ;
	}
	// rep(i, 0, 11) cout << catalan[i] << ' ';
	// cout << '\n';
	cin >> n; cout << catalan[n] << '\n';
	while(cin >> n) {
		cout << "\n" << catalan[n] << endl;
	}

	return 0;
}