#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


ll binpow(ll n, ll k, ll p) {
    if(k == 0) return 1 % p;
    if(k == 1) return n % p;

    ll half = binpow(n, k / 2, p);

    return (((half * half) % p) * (k%2? n : 1)) % p;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << binpow(a, b, c) << '\n';
	return 0;
}