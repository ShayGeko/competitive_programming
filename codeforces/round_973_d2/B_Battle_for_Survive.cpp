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
        int n; cin >> n;
        vi nums(n);
        for(auto &x : nums) cin >> x;

        vector<ll> psum(n+1);
        psum[0] = 0;
        rep(i, 0, n) psum[i+1] = psum[i] + nums[i];

        cout << nums.back() + psum[n-2] - nums[n-2] << '\n';    

    }    

	return 0;
}