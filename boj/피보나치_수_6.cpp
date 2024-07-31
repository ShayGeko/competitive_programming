#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef array<array<ll, 2>, 2> matrix;

const matrix I = {{
	{ 1, 0},
	{0, 1}
}};

/*

 |A1 A2||B1 B2| = | A1*B1 + A2 * B3
 |A3 A4||B3 B4| =

*/
const int p = 1e9+7;
matrix operator* (matrix A, matrix B) {
	matrix C ={0};
	rep(i, 0, 2) {
		rep(j, 0, 2) {

			rep(ij, 0, 2) {
				C[i][j] += A[i][ij] * B[ij][j];
			}

			C[i][j] %= p;
		}
	}
	return C;
};

void print(matrix &A) {
	rep(i, 0, 2) {
		rep(j, 0, 2) {
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}
}
matrix bin_pow (matrix A, ll k) {
	if(k == 0) return I;
	if(k == 1) return A;

	matrix half = bin_pow(A, k / 2);
	matrix rem = (k%2) ? A : I;;

	return (half * half) * rem;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n;
	cin >> n;

	matrix fib = {{
		{0, 1},
		{1, 1}
	}};

	auto fib_n = bin_pow(fib, n);

	
	ll ans = fib_n[0][0] * 0 + fib_n[0][1] * 1;

	cout << ans % p << '\n';

	return 0;
}