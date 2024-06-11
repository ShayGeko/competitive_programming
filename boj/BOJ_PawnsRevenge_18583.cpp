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

	int n;
	cin >> n;

	vector<string> grid(n);
	rep(i, 0, n) cin >> grid[i];

	rep(i, 0, n) rep(j, 0, n) {
		if(grid[i][j] == 'K') {


			rep(ii, -1, 2) {
				rep(jj, -1, 2) {
					if(i +ii >= 0 && i + ii < n && j + jj >= 0 && j + jj < n) {
						if(grid[i+ii][j + jj] == '*') {
							grid[i+ii][j+jj] = '#';
						}
					}
				}
			}

		}
	}

	int cnt = 0;

	bool possible = true;
	rep(i, 0, n-1) {
		rep(j, 0, n) {
			if(grid[i][j] == '*') {
				if(grid[i+1][j-1] == '@') continue;

				if(grid[i+1][j+1] == '-') {
					grid[i+1][j+1] = '@';
					++cnt;
				} else if(grid[i+1][j-1] == '-') {
					grid[i+1][j-1] = '-';
					++cnt;
				} else {
					possible = false;
					break;
				}
			}
		}
	}

	rep(j, 0, n) {
		if(grid[n-1][j] == '*') {
			possible = false;
			break;
		}
	}

	if(possible) cout << cnt << '\n';
	else cout << "-1\n";

	return 0;
}