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
        vi A(n);for(auto &x : A) cin >> x;
        sort(all(A));

        vi gc(n);
        gc[0]=A[0];
        rep(i, 1, n) {
            gc[i] = gcd(gc[i-1], A[i]); 
        }
        rep(i, 0, n) cout << gc[i] << " ";
        cout << '\n';


        // usually want to put the two co-prime numbers front
        // if there are two co-prime numbers,
        // 1e9+7, 1e9+9, 2, 4, 8, 16 .. 

        // a_i is bounded.... 
        // knapsack ??

        // can find all possible GCD combos
    }
	return 0;
}