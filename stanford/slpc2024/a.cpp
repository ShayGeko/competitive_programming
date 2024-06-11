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

	double r;
	cin >> r;

	const double pi = acos(-1);
	double a = sqrt(pi * r * r);
	cout << fixed << setprecision(8) <<  a << '\n';
	return 0;
}