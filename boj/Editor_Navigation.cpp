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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vi nums(n);
        for(auto &x : nums) cin >> x;

        int sr, sc;
        cin >> sr >> sc;
        int er, ec;
        cin >> er >> ec;
        --sr;--er;

        queue<pii> q;

        q.push({sr, sc});
        q.push({-1, -1});
        vector<vector<bool>> visited(121, vector<bool>(81, false));
        // vector<vector<pii>> p(121, vector<pii>(80));
        visited[sr][sc];
        int cost = 0;
        while(!q.empty()) {
            auto [r, c] = q.front();q.pop();
            if(t == 1) {
                // cout << r << " " << c << '\n';
            }
            if(r == -1) {
                ++cost;
                q.push({-1, -1});
                continue;
            }
            if(r == er && c == ec) {
                break;
            }
            int rn, cn;
            
            bool should = true;
            auto update = [&]() {
                if(should && !visited[rn][cn]) {
                    q.push({rn, cn});
                    visited[rn][cn] = true;
                    // p[rn][cn] = {r, c};
                }
                should = true;
            };
            
            // right
            if (c < nums[r]){
                rn = r, cn = c + 1;
            }
            else if(c == nums[r] && r < n - 1) {
                rn = r + 1; cn = 0;
            } else should = false;
            update();

            // up
            if(r > 0) {
                rn = r - 1;
                cn = min(c, nums[rn]);
            } else should = false;
            update();

            // left
            if(c > 0) {
                rn = r;
                cn = c - 1;
            } else if (r > 0){
                rn = r - 1;
                cn = nums[rn];
            } else should = false;
            update();

            // down
            if(r < n - 1) {
                rn = r + 1;
                cn = min(c, nums[rn]);
            } else should = false;
            update();
        }
        cout << cost << '\n';
    }

	return 0;
}