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

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    rep(i, 0, n) cin >> grid[i];


    vector<bool> visited(26, false);
    int ans = 0;
    function<void(int, int, int)> brute = [&](int i, int j, int cnt) {
        bool flag = false;
        rep(di, -1, 2) rep(dj, -1, 2) {
            int ii = i + di, jj = j + dj;
            if(di ^ dj && (-di)^dj && ii >=0 && ii < n && jj >= 0 && jj < m) {
                char c = grid[ii][jj] -'A';
                if(!visited[c]) {
                    flag = true;
                    visited[c] = true;
                    brute(ii, jj, cnt + 1);
                    visited[c] = false;
                }
            }
        }
        if(!flag) ans = max(ans, cnt);
    };

    visited[grid[0][0]-'A'] = true;
    brute(0, 0, 1);

    cout << ans << '\n';

	return 0;
}