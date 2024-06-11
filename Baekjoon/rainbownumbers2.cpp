#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int p = 998244353;
vector<ll> dp;
ll bin_pow(ll n, int k) {
	if(dp[k] > 0) return dp[k];
	if(k == 0) return 1;
	if (k == 1) return n;

	ll a = bin_pow(n, k/2);

	return dp[k] = (((a * a) % p) * ((k % 2) ? n : 1LL)) % p;
}
ll calc(string &s, int i) {
	if(sz(s) == 1) return s[0] - '0';
	if(i == sz(s) - 1) {
		if(i > 0 && s[i] >= s[i-1]) return s[i] - '0'; // cant take prev
		else return s[i] -'0' + 1; // can take 0 or 1 for 1
	}
	
	ll first, second;
	if (i > 0) {
		if(s[i] > s[i-1]) {
			first = max(s[i]- 1 -'0', 0); // cant take itself and the prev
			second = calc(s, i+1);
		} else if(s[i] == s[i-1]) {
			first = max(s[i] -'0', 0); // cant take itself
			second = 0; // cannot take itself if prev was taken
		} else {
			first = max(s[i] -'0', 0); // cant take itself
			second = calc(s, i+1);
		}
	} else {
		first = first = max(s[i] - 1 -'0', 0); // cant take itself or 0
		second = calc(s, i+1);
	}

	// issue:
	// 10 -> can take 09
	// 12345 -> cant take 099...
	// cout << i << " " << first << " * " << bin_pow(9, sz(s) - 1 - i) << " " << second << '\n';
	return (first * bin_pow(9, sz(s) - 1 - i) + second) % p;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	dp = vector<ll>(1e5, 0);

	string L, U;
	cin >> L >> U;

	ll hi = calc(U, 0);
	ll lo = calc(L, 0);

	// add up lower degree numbers
	rep(i, 1, sz(U)) hi += bin_pow(9, i);
	rep(i, 1, sz(L)) lo += bin_pow(9, i);
	bool isRainbow = true;

	// rep(i, 0, 4) cout << bin_pow(9, i) << " ";
	// cout << '\n';
	rep(i, 1, sz(L)) if(L[i] == L[i-1]) {
		isRainbow = false;
		break;
	}
	// cout << hi << " " << lo << '\n';
	cout << (hi - lo + isRainbow + p) % p << '\n';
	return 0;
}