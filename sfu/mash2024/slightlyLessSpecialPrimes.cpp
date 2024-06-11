#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX_PR = 3e5+1;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int n;
	cin >> n;
	
	vi primes = eratosthenesSieve(n+1);

	int cnt = 0;
	rep(i, 0, sz(primes)-1) {
		int dif = primes[i+1] - primes[i] - 1;
		ll a = (ll)primes[i] * primes[dif];
		ll b = (ll)primes[i+1] * primes[dif];
		if(a + b + 1 <= n && isprime[a+b+1]) {
			++ cnt;
			// cout << a + b + 1 << '\n';
		}
	}

	cout << cnt << '\n';
	return 0;
}