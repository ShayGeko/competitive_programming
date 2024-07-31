#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<vector<ll>> matrix;

matrix create(int n) {
    return matrix(n, vector<ll>(n, 0));
}

matrix identity(int n) {
    matrix m = create(n);

    rep(i, 0, n) m[i][i] = 1;

    return m;
}
const int p = 1000;
matrix operator* (matrix A, matrix B) {
    int n = sz(A);
    matrix C(n, vector<ll>(n, 0));
    rep(i, 0, n) {
        rep(j, 0, n) {
            rep(ij, 0, n) {
                C[i][j] += (A[i][ij] * B[ij][j]) %p;
            }

            C[i][j] %= p;
        }
    }
    return C;
};

void print(matrix &A) {
    rep(i, 0, sz(A)) {
        rep(j, 0, sz(A)) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

matrix I;
matrix bin_pow (matrix A, ll k) {
    if(k == 0) return I;
    if(k == 1) return A;

    matrix half = bin_pow(A, k / 2);
    matrix rem = (k%2) ? A : I;

    return (half * half) * rem;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll n, k;
    cin >> n >> k;
    I = identity(n);

    matrix A = create(n);
    for(auto &x : A) for(auto &y : x) cin >> y;

    auto ans = bin_pow(A, k);

    for(auto &x : ans) {
        for(auto &y : x) {
            cout << (y+p)%p << " ";
        }
        cout << '\n';
    }

    return 0;
}