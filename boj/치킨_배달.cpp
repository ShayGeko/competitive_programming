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

    vector<vi> grid(n, vi(n));

    for(auto &x : grid) for(auto &y : x) {
        cin >> y;
    }

    vector<pii> houses, shops;

    rep(i, 0, n) {
        rep(j, 0, n) {
            if(grid[i][j] == 1) houses.push_back({i,j});
            else if(grid[i][j] == 2) shops.push_back({i,j});
        }
    }

    auto dist = [&](int i, int j) {
        return abs(houses[i].first - shops[j].first) + abs(houses[i].second - shops[j].second);
    };
    vector<bool> selected(n, false);

    int ans = 1e9;
    function<void(int, int)> brute = [&](int i, int selCnt) {
        if(selCnt == m) {
            int total = 0;

            rep(i, 0, sz(houses)) {
                int mi = 1e9;
                rep(j, 0, sz(shops)) {
                    if(selected[j]) {
                        mi = min(mi, dist(i, j));
                    }
                }
                total+=mi;
            }
            ans = min(ans, total);
            return;
        }



        for(int j = i; j < sz(shops); ++j) {
            selected[j] = true;
            brute(j+1, selCnt + 1);
            selected[j] = false;
        }
    };

    brute(0, 0);
    cout << ans << '\n';
	return 0;
}