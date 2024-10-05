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
        int x, y;
        int n;
        cin >> n;
        cin >> x >> y;

        int ps = min(x, y);
        cout << (n + ps - 1) / ps << '\n';
    }
	return 0;
}