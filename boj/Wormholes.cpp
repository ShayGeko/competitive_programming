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

    int T;
    cin >> T;
    while(T--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<vi> D(n, vi(n, 2e9));

        rep(i, 0, m + w) {
            int a, b, c;
            cin >> a >> b >> c;
            --a;--b;
            D[a][b] = min(D[a][b], c);
            D[b][a] = D[a][b];
        }

        vi minD(n, 2e9);
        minD[st]
        or(int k = 0; k < n; ++k) {

        }

    }
	return 0;
}