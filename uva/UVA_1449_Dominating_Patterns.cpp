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

unordered_map<string, int> mp;

int match_cnt(const string& s, const string& pat) {
	vi p = pi(pat + '\0' + s);
	int cnt = 0;
	rep(i,sz(p)-sz(s),sz(p))
		if (p[i] == sz(pat)) ++cnt;
	return cnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t;
	while(cin >> t && t != 0) {
		vector<string> ptrns(t);
		rep(i, 0, t) cin >> ptrns[i];
		string txt;
		cin >> txt;

		vector<string> ans;
		int cnt = 0;

		for(auto &x: ptrns) {
			int mcnt = match_cnt(txt, x);
			if(mcnt > cnt) {
				ans.clear();
				ans.push_back(x);
				cnt = mcnt;
			} else if(mcnt == cnt) ans.push_back(x);
		}

		cout << cnt << '\n';
		for(auto &x : ans) cout << x << '\n';
	}
	return 0;
}