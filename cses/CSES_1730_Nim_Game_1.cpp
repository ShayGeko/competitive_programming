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
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi stones(n);
		for(auto &x : stones) cin >> x;

		int a = 0;
		for(auto x : stones) a ^= x;

		if(a) cout << "first\n";
		else cout << "second\n";
	}
	return 0;
}