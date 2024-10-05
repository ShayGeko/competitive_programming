#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<vi> dp;

int lcs(string &a, string &b, int i, int j) {
	if(i <0 || j < 0) return 0;
	if(dp[i][j] >=0) return dp[i][j];

	if(a[i] == b[j]) return dp[i][j] = lcs(a, b, i-1, j-1) + 1;
	else return  dp[i][j] = max(lcs(a, b, i-1, j), lcs(a,b,i, j-1));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	string a, b;
	cin >> a >> b;

	dp = vector<vi>(sz(a), vi(sz(b), -1));


	int ans = lcs(a, b, sz(a)-1, sz(b)-1);

	int i = sz(a)-1, j = sz(b)-1;

	string str = "";

	while(i >= 0 && j >= 0) {
		if(a[i] == b[j]) {
			str += a[i];
			--i;--j;
		} else {
			if(i && dp[i-1][j] == dp[i][j])--i;
			else --j;
		}
	}
	reverse(all(str));

	cout << str << '\n';

	return 0;
}