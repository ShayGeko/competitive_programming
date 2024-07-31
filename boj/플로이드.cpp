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
    constexpr int INF = 1e8+1;
    vector<vector<int>> D(n, vector<int>(n, INF));

    rep(i, 0, m) {
        int a, b; int c;
        cin >> a >> b >> c;
        --a;--b;
        D[a][b] = min(D[a][b], c);
    }

    rep(i, 0, n) D[i][i] = 0;

    rep(k, 0, n) {
        rep(i, 0, n) {
            rep(j, 0, n) {
                D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
            }
        }
    }

    rep(i, 0, n) {
        rep(j, 0, n) {
            cout << (D[i][j] == INF ? 0 : D[i][j]) << " ";
        }
        cout << '\n';
    }

	return 0;
}