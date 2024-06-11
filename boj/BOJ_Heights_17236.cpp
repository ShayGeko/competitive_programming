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
	// cin.exceptions(cin.failbit);

	long double ha, hb, hc;
	cin >> ha >> hb >> hc;

	// double A

	// A = a * ha /2 = b * hb /2 = c * hc / 2 = sqrt(s (s-a) (s-b) (s-c))
	// a = 2A / ha, b = 2A / hb, c = 2A / hc
	// s = A ( 1/ha + 1/ hb + 1/ hc)
	// s - a = A (1 / hb + 1 / hc - 1/ha)

	long double invA = 1. / ha, invB = 1. / hb, invC = 1. / hc;
	long double invSum = invA + invB + invC;

	// A = A^2 * sqrt (invSum)(invSum - invA)(invSum - invB)(invSum - invC)
	// A = 1 / sqrt (invSum)(invSum - invA)(invSum - invB)(invSum - invC)?

	long double A = sqrt(invSum * (invSum - 2*invA) * (invSum - 2*invB) * (invSum - 2*invC));
	A = 1. / A;

	cout << fixed << setprecision(7) << A << '\n';

	return 0;
}