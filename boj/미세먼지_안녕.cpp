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

    int n, m, T;
    cin >> n >> m >> T;
    vector<vi> grid(n, vi(m));
    vector<pii> pur;
    rep(i, 0, n) rep(j, 0, m) {
        cin >> grid[i][j];
        if(grid[i][j] == -1) {
            pur.push_back({i, j});
        }
    }

    vector<vi> nxt;
    
    // cout << "==============================================\n";
    rep(t, 0, T) {
        nxt = vector(n, vi(m, 0));

        // diffuse
        rep(i, 0, n) {
            rep(j, 0, m) {
                int val = grid[i][j] / 5;
                nxt[i][j] += grid[i][j];
                if(i && grid[i-1][j] != -1) {
                    nxt[i][j] -= val;
                    nxt[i-1][j] += val;
                }
                if(i < n-1 && grid[i+1][j] != -1) {
                    nxt[i][j] -= val;
                    nxt[i+1][j] += val;
                }
                if(j && grid[i][j-1] != -1) {
                    nxt[i][j] -= val;
                    nxt[i][j-1] += val;
                }
                if(j < m - 1) {
                    nxt[i][j] -= val;
                    nxt[i][j+1] += val;
                }
            }
        }
        grid = nxt;

        // rep(i, 0, n) {
        //     rep(j, 0, m) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        
        // cout << "-----------------------------------------------\n";

        // blow
        vector<vector<pii>> moves = {
            {{-1, 0}, {0, 1}, {1, 0}, {0, -1}},
            {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
        };

        rep(k, 0, 2) {
            auto [x, y] = pur[k];
            int bound = x;

            // cout << "BOUND:" << bound << '\n';
            
            int dir = 0;
            x += moves[k][dir].first;
            y += moves[k][dir].second;
            while(dir < 4) {
                auto [ma, mb] = moves[k][dir];
                
                // if(t == 0) {
                //     cout << x << " " << y << '\n';
                // }
                int nx = x + ma, ny = y + mb;
                if (dir == 2 && x == bound) {
                    ++dir;
                    // cout << "BOUND TURN\n";
                }
                else if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != -1) {
                    grid[x][y] = grid[nx][ny];
                    x = nx, y = ny;
                } else {
                    ++dir;
                    // cout << "TURN\n";
                }
            }
            grid[x][y] = 0;
        }
        // rep(i, 0, n) {
        //     rep(j, 0, m) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << "==============================================\n";
    }
    
    int sum = 0;
    rep(i, 0, n) rep(j, 0, m) {
        if(grid[i][j] > 0) sum += grid[i][j];
    }

    cout << sum << '\n';

	return 0;
}