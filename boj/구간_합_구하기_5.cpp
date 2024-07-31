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

    vector<vi> nums(n, vi(n));
    for(auto &x : nums) for(auto &y :x) cin >> y;

    vector<vector<int>> prsum(n+1, vector<int>(n+1, 0));

    rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            prsum[i][j] = prsum[i-1][j] + prsum[i][j-1] 
                        - prsum[i-1][j-1] + nums[i-1][j-1];
        }
    }

    
    int a, b, c, d;
    rep(i, 0, m) {
        cin >> a >> b >> c >> d;
        --a;--b;
        cout << prsum[c][d] - prsum[a][d] - prsum[c][b] + prsum[a][b];
        cout << '\n';
    }

	return 0;
}