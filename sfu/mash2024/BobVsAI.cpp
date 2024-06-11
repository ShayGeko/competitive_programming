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

	int N, M;
	cin >> N >> M;
	typedef vector<double> vd;
	
	vector<vd> P(M+1, vd(N));
	for(auto &x :P[0]) cin >> x;
	
	rep(i, 1, sz(P)) {
		for(auto &x : P[i]) cin >> x;
	}
	vector<vector<vd>> probs_dp(M+1, vector(N+1, vd(N+1, 0)));

	
	// P(solve j problems) considering the first i problems
	for(int k = 0; k < M + 1; ++k) {
		auto &dp = probs_dp[k];
		dp[0][0] = 1;
		rep(i, 1, N+1) {
			dp[i][0] = dp[i-1][0] * (1-P[k][i-1]);
		}
		rep(i, 1, N+1) {
			rep(j, 1, i+1) {
				// solve j before and dont solve cur, or solve j-1 before and solve cur
				dp[i][j] = dp[i-1][j] * (1-P[k][i-1]) + dp[i-1][j-1] * P[k][i-1];
			}
		}
	}

	vector<vector<long double>> prsum(M+1, vector<long double>(N+1, 0));
	rep(i, 0, M+1) {
		prsum[i][0] = probs_dp[i][N][0];
		rep(j, 1, N+1) {
			prsum[i][j] = prsum[i][j-1] + probs_dp[i][N][j];
		}
	}	

	long double ans = 0;

	rep(i, 1, N+1) {
		// sum Bob solves i, ai all solve less than i
		long double product = 1;
		rep(j, 1, M+1) product *= prsum[j][i-1];
		ans += probs_dp[0][N][i] * product;
	}

	cout << fixed << setprecision(8) << ans << '\n';

	return 0;
}