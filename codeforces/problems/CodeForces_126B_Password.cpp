#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi pi(const string& s) {
	vi p(sz(s));
	rep(i,1,sz(s)) {
		int g = p[i-1];
		while (g && s[i] != s[g]) g = p[g-1];
		p[i] = g + (s[i] == s[g]);
	}
	return p;
}

vi match(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s), res;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
	return res;
}

vi Z(const string& S) {
	vi z(sz(S));
	int l = -1, r = -1;
	rep(i,1,sz(S)) {
		z[i] = i >= r ? 0 : min(r - i, z[i - l]);
		while (i + z[i] < sz(S) && S[i + z[i]] == S[z[i]])
			z[i]++;
		if (i + z[i] > r)
			l = i, r = i + z[i];
	}
	return z;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s;
	cin >> s;

	string FAIL = "Just a legend";
	if(s.length() <= 2) cout << FAIL << '\n';
	else {
		auto pref = pi(s);
		vector<bool> match(sz(s)+1, false);
		int j = sz(s);
		while(j && pref[j-1]) {
			j = pref[j-1];
			match[j] = true;
		}

		vi matches;
		rep(i, 1, sz(s) - 1) {
			if(pref[i] && match[pref[i]]) {
				matches.push_back(pref[i]);
			}
		}

		if(matches.empty()) {
			cout << FAIL << '\n';
		} else {
			auto maxi = 0;
			for(auto x : matches) maxi = max(maxi, x);
			rep(i, 0, maxi) cout << s[i];
			cout << '\n';
		}
	}

	return 0;
}