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

    for(auto &x : grid) cin >> x;


    queue<pair<pii, bool>> q;
    q.push({{0,0}, 0});
    vector<vector<bool>> vistmp(n, vector<bool>(n, false));
    
    vector<vector<vector<bool>>> vis = {vistmp, vistmp};

    int time = 1;
    q.push({{-1, -1}, 0});
    vis[0][0][0] = 1;
    while(q.size() > 1) {
        auto [v, wall] = q.front(); q.pop();
        auto [i, j] = v;


        if(i == -1) {
            ++time;
            q.push({{-1, -1}, 0});
            continue;
        }

        if(i == n-1 && j == m-1) {
            cout << time << '\n';
            return 0;
        }

        rep(di, -1, 2) rep(dj, -1, 2) {
            if((!di && !dj) || !(di^dj) || !(-di^dj)) continue;
            int ii = i + di, jj = j + dj;
            if(ii < 0 || ii == n || jj < 0 || jj == m) continue;
            
            if(grid[ii][jj] == '0' && !vis[wall][ii][jj]) {
                vis[wall][ii][jj] = true;
                q.push({{ii, jj}, wall});
            } else if(grid[ii][jj] == '1' && !wall && !vis[!wall][ii][jj]) {
                vis[!wall][ii][jj] = true;
                q.push({{ii, jj}, !wall});
            }

        }

    }

    cout << "-1\n";

	return 0;
}