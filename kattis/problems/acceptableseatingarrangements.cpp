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
    vector<vi> st(n, vi(m)), nd(n, vi(m));
    // read
    for(auto &x : st) for(auto &y : x) cin >> y;
    for(auto &x : nd) for(auto &y : x) cin >> y;

    // create ordered maps val -> cur_pos and val -> desired_pos
    map<int, pii> cur, wanted;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cur[st[i][j]] = {i,j};
            wanted[nd[i][j]] = {i,j};
        }
    }

    // go through vals in increasing order (for each in the map)
    // if cur[val] != wanted[val]
    // if can do the swap, do the swap right away
    // update cur[val] and cur[st[wanted[val]]]
    // otherwise, try to insert the val at desired position in val's row and repeat

    for(auto &[v, pos] : cur) {
        auto [i, j] = pos;
        auto [ii, jj] = wanted[v];
        int to_swap = st[ii][jj];

        // todo: fix RUNTIME
        int prev = st[i][j-1], nxt = st[i][j+1];
        while(j < m - 1 && to_swap > st[i][j+1]) {
            ++j;
        }
        if(to_swap < nxt) {
            st[i][j] = to_swap;
            st[ii][jj] = v;
            cur[v]= {ii,jj};
            cur[to_swap] = {i, j};
        }

    }

	return 0;
}