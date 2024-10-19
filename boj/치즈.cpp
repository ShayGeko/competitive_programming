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

    n+=2;
    m+=2;
    vector<vi> grid(n, vi(m, 0));
    rep(i, 1, n - 1) {
        rep(j, 1, m - 1) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> melted(n, vector<bool>(m));
    deque<pii> q;
    rep(i, 0, n) {
        melted[i][0] = melted[i][m-1] = true;
        q.push_back({i, 0}); q.push_back({i, m-1});
    }
    rep(j, 0, m) {
        melted[0][j] = melted[n-1][j] = true;
        q.push_back({0, j}); q.push_back({n-1, j});
    }

    q.push_back({-1, -1});
    int time = 0;

    vector<vi> cnt(n, vector<int> (m, 4));
    auto melt = [&](int i, int j) {
        if(melted[i][j]) return;
        if(grid[i][j] == 0) {
            cnt[i][j] = 0;
            q.push_front({i, j});
            melted[i][j] = true;
        } else {
            if(--cnt[i][j] <= 2) {
                q.push_back({i, j});
                melted[i][j] = true;
            }
        }
    };
    while(q.size() > 1) {
        auto [i, j] = q.front();q.pop_front();

        if(i == -1) {
            ++time;
            q.push_back({-1, -1});
            continue;
        }
        cnt[i][j] = 0;

        if(i) melt(i-1, j);
        if(j) melt(i, j - 1);
        if(i < n - 1) melt(i+1, j);
        if(j < m - 1) melt(i, j + 1);
    }

    cout << time  << '\n';

	return 0;
}