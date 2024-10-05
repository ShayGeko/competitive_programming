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

    int n;
    cin >> n;

    bool big_flag = true;
    rep(i, 0, 3){
        bool flag = false;
        rep(j, 0, n) {
            int x;
            cin >> x;
            flag |= x == 7;
        }
        big_flag &= flag;
    }

    cout << (big_flag? 777 : 0) << '\n';
	return 0;
}