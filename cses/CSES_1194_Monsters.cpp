#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
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
    queue<pii> mq, pq;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> parent(n, vector<int>(m, -1));

    vector<pii> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    string label = "DRUL";

    rep(i, 0, n) {
        cin >> grid[i];

        rep(j, 0, m) {
            if (grid[i][j] == 'M') {
                mq.emplace(i, j);
                visited[i][j] = true;
            } else if (grid[i][j] == 'A') {
                pq.emplace(i, j);
                visited[i][j] = true;
            }
        }
    }
	pq.emplace(-1,-1);
    if (mq.size()) mq.emplace(-1, -1);

    {
        auto [pi, pj] = pq.front();
        if (pi == 0 || pi == n - 1 || pj == 0 || pj == m - 1) {
            cout << "YES\n0\n";
            return 0;
        }
    }
    while (pq.size() > 1) {
        while (mq.size()) {
            auto [mi, mj] = mq.front();
            mq.pop();
            if (mi == -1) {
                break;
            }
            for (auto [di, dj] : moves) {
                int ni = mi + di, nj = mj + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (grid[ni][nj] != '.') continue;
                    grid[ni][nj] = 'M';
                    visited[ni][nj] = true;
                    mq.emplace(ni, nj);
                }
            }
        }
        mq.push({-1, -1});  // delimeter

        auto [pi, pj] = pq.front();
        pq.pop();
        while (pi != -1) {
            rep(i, 0, 4) {
                auto [di, dj] = moves[i];
                int ni = pi + di, nj = pj + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    if (grid[ni][nj] != '.') continue;
                    parent[ni][nj] = i;
                    grid[ni][nj] = 'A';
                    pq.emplace(ni, nj);
                } else {
                    cout << "YES\n";

                    vi path;
                    int ci = ni, cj = nj;
                    int mv = i;
                    do {
                        path.push_back(mv);
                        ci -= moves[mv].first;
                        cj -= moves[mv].second;
                        mv = parent[ci][cj];
                    } while (mv >= 0);

                    reverse(all(path));
                    path.pop_back();
                    cout << path.size() << '\n';
                    for (auto mv : path) cout << label[mv];
                    return 0;
                }
            }
			tie(pi, pj) = pq.front();pq.pop();
        }
		pq.push({-1,-1});
    }

    cout << "NO\n";
    return 0;
}