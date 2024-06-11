#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int p = 1e9 + 7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int w, n;
	cin >> w >> n;

	vector<vector<char>> grid(2,  vector<char>(w));
	rep(i, 0, 2) rep(j, 0, w) cin >> grid[i][j];

	int maxmask = 1 << n;
	// [width][colors used][top color][bottom color] -> O(w*2^n * n^2)
	vector<vector<vector<vector<ll>>>> dp(w, vector(maxmask, vector(n, vector<ll>(n, 0))));

	char a = grid[0][0];
	char b = grid[1][0];

	// a == . -> can put any, ow put a

	rep(i, 0, n) {
		if(a != '.' && a-'1' != i) continue;
		rep(j, 0, n) {
			if(b != '.' && b-'1' != j) continue;
			int mask = (1 << i) | (1 << j);
			dp[0][mask][i][j] = 1;
		}
	}

	rep(i, 1, w) {
		// dp[i][a][b]
		// if dp[i-1][a-1]

		rep(pmask, 1, maxmask) {
			rep(pa, 0, n) {
				rep(pb, 0, n) {
					rep(a, 0, n) {
						if(grid[0][i] != '.' && grid[0][i] - '1' != a) {
							continue;
						}
						if(pa != a && pb != a) {
							// color change
							if(pmask & (1 << a)) {
								// color already used and that slice ended
								continue;
							}
						}
						rep(b, 0, n) {
							if(grid[1][i] != '.' && grid[1][i] - '1' != b) {
								continue;
							}
							// try to place (a, b) given previos <pmask, pa, pb>
							
							if(pa != b && pb != b) {
							// color change
								if(pmask & (1 << b)) {
									// color already used and that slice ended
									continue;
								}
							}
							// diagonal piece is invalid
							else if(pa != pb && ((pa != a && pa == b) || (pb != b && pb == a))){
								continue;
							}

							
							// otherwise can place (a,b)
							ll &cur = dp[i][pmask | (1 << a) | (1 << b)][a][b]; 
							cur = (cur + dp[i-1][pmask][pa][pb]) % p;
						}
					}
				}
			}
		}
	}
	int fullmask = (1<<n) - 1;

	ll ans = 0;
	
	rep(a, 0, n) {
		rep(b, 0, n) {
			ans = (ans + dp[w-1][fullmask][a][b]) % p;
		}
	}

	cout << ans % p << '\n';
	return 0;
}
