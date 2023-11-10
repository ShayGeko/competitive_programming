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
	cin >> n, m;

	vi A(n), B(m);
	rep(i, 0, n) {
		cin >> A[i];
	}
	rep(i, 0, m) cin >> B[i];

	sort(all(A));
	sort(all(B));

	int bb = lower_bound(all(B), A[0]) - B.begin();
	int aa = lower_bound(all(A), B.back()) - A.begin();

	int l = min(A.front(), B.back()), r = max(A.front(), B.back())
	

	return 0;
}