#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string s;
	cin >> s;

	auto man = manacher(s);

	string best;
	int ans = 0;
	bool odd;
	int pos;

	rep(i, 0, sz(s)) {
		if(man[0][i] * 2 > ans) {
			ans = man[0][i] * 2;
			pos = i;
			odd = false;
		}
		if(man[1][i] * 2 + 1 > ans) {
			ans = man[1][i] * 2 + 1;
			pos = i;
			odd = true;
		}
	}
	
	// rep(i, 0, 2) {
	// 	for(auto x : man[i]) cout << x << " ";
	// 	cout << '\n';
	// }
	// cout << ans << " " << odd << " " << pos << '\n';
	int start = pos - ans/2;

	// cout << start << "\n";
	string prnt = s.substr(start, ans);
	cout << prnt << '\n';

	return 0;
}