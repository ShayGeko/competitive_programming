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

    int n, k;
    cin >> n >> k;

    vi candies(n);
    for(auto &x : candies) cin >> x;

    int m = 0;
    for(auto x : candies) m = max(m, x);
    ll sum = accumulate(all(candies), 0LL);
    ll maxi = m;

    ll kk = max(maxi, (sum + k - 1) / k);

    cout << kk * k - sum << '\n';
	return 0;
}