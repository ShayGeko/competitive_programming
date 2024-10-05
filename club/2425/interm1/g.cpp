#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vector<vi> dp;

int lps(string &a, int i, int j) {
	// cout << i << " " << j << '\n';
	if(i > j) return 0;
	if(i == j) return 1;
	if(dp[i][j] >=0) return dp[i][j];

	if(a[i] == a[j]) return dp[i][j] = lps(a, i+1, j-1) + 2;
	else return  dp[i][j] = max(lps(a, i+1, j), lps(a,i, j-1));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string a = "";
	char c;

	while(cin >> c) {
		 if(isalpha(c)) a+=tolower(c);
	}

	// cout << a << '\n';

	dp = vector<vi>(sz(a), vi(sz(a), -1));
	int ans = lps(a, 0, sz(a)-1);
	cout << sz(a) - ans << '\n';

	return 0;
}