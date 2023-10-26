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

	int n, m;
	cin >> n >> m;
	multiset<int> st;
	rep(i, 0, n) {
		int a;
		cin >> a;
		st.insert(-a);
	}
	rep(i, 0, m) {
		int b;
		cin >> b;

		auto it = st.lower_bound(-b);
		if(it == st.end()){
			cout << -1 << '\n';
		} else {
			cout << -(*it) << '\n';
			st.erase(it);
		}
	}

	return 0;
}