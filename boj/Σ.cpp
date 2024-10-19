#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int p = 1e9+7;

ll bin_pow(int n, int k) {
    if(k == 0) return 1;
    if(k == 1) return n;

    ll half = bin_pow(n, k/2);
    return (((half * half) % p) * (k%2? n : 1)) % p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll sum = 0;
    int n;
    cin >> n;

    rep(i, 0, n) {
        ll k, s;
        cin >> k >> s;

        ll inv = bin_pow(k, p-2);

        sum =  (sum + (ll (inv) * s) % p) % p;
    }

    cout << (p + sum) % p << '\n';


	return 0;
}