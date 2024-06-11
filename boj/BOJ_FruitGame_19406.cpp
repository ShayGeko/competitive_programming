#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	// @ b @ b b * @ b b @ b

	// @ b * b @ -> b
	// @ b* @ b -> @
	// Sprague Grundy? DP? Graph?

	// DP[i][j][t] = 
	//    ! max(dp[i][j-1][1-t], dp[i-1][j][1-t]) if A[i], A[j] != t
	// 	    ! (dp[i][j-1][1-t] && dp[i-1][j][1-t]	

	// ABBACBBABBBBBB
    
	// AAABBCBBABBB


	return 0;
}