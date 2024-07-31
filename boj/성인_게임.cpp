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

    vector<int> dp(2, 1);
    int last = 1;
    const int p = 1e9+7;
    while(t--) {
        int N;
        cin >> N;

        N<<=1;
        ++N;
        if(N > last) {
            dp.resize(N+1);

            rep(i, last+1, N+1) {
                if(i % 2 == 0) {
                    dp[i] = ((dp[i-2] << 1) % p + dp[i-1])%p;
                } else {
                    dp[i] = (((dp[i-3] << 1) % p +  (dp[i-2] << 1) % p) % p + dp[i-1])%p;
                }
            }
            last = N;

        }
        // rep(i, 0, N+1) {
        //     cout << dp[i] << " ";
        // } cout << '\n';
        cout << dp[N] << '\n';
    }


    vi nums = {1,2,3, 3, 2, 1};

    sort(nums.begin(), nums.end());
    sort(all(nums));

    
	return 0;
}