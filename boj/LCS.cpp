#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<vi> dp;
string a, b;
int lcs(int i, int j) {
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(a[i] == b[j]) {
        return dp[i][j] = lcs(i-1, j-1) + 1;
    }
    else {
        int l = lcs(i-1, j);
        int r = lcs(i, j-1);
        return dp[i][j] = max(l, r);
    }
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    cin >> a >> b;
    dp = vector<vi>(sz(a), vi(sz(b), -1));

    int ans = lcs(sz(a)-1, sz(b) - 1);
    cout << ans << '\n';

	return 0;
}