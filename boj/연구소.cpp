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

    vector<pii> virus;
    vector<pii> empty;
    vector<vi> grid(n, vi(m));
    int walls = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if(grid[i][j] == 2) virus.push_back({i, j});
            else if(!grid[i][j]) empty.push_back({i, j});
            else ++ walls;
        }
    }


    auto cnt_func = [&](){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pii> q;
         auto try_step = [&](int i, int j) {
            if(!vis[i][j] && grid[i][j] != 1) {
                vis[i][j] = true;
                q.push({i, j});
            }
        };
        for(auto [i, j] : virus) {
            try_step(i, j);
        }

        int ans =  0;
        while(!q.empty()) {
            auto [i, j] = q.front();q.pop();
            ++ans;

            if(i) try_step(i-1, j);
            if(i < n - 1) {
                try_step(i+1, j);
            }
            if(j) try_step(i, j - 1);
            if(j < m - 1) try_step(i, j + 1);
        }

        return n * m - ans - walls - 3;
    };
    int k = sz(empty), ans = 0;
    rep(i, 0, k - 2) {
        grid[empty[i].first][empty[i].second] = 1;
        rep(j, i + 1, k - 1) {
            
            grid[empty[j].first][empty[j].second] = 1;
            rep(z, j + 1, k) {
                grid[empty[z].first][empty[z].second] = 1;

                int cur = cnt_func();
                ans = max(ans,cur);
                grid[empty[z].first][empty[z].second] = 0;

            }
            grid[empty[j].first][empty[j].second] = 0;
        }
        
        grid[empty[i].first][empty[i].second] = 0;
    }

    cout << ans << '\n';

	return 0;
}