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

    int T; cin >> T;

    while(T--) {
        int n;
        cin >> n;
        vi nums(n), coords(n);
        for(auto &x : coords) cin >> x;
        for(auto &x : nums) cin >> x;

        vector<ll> prsum(n);
        partial_sum(all(nums), prsum.begin());

        vector<ll> sufsum(n);
        partial_sum(nums.rbegin(), nums.rend(), sufsum.rbegin());

        vector<ll> pref_func(n);
        pref_func[0]=0;
        rep(i, 1, n) {
            pref_func[i] = pref_func[i-1] + (ll) prsum[i-1] * (coords[i] - coords[i-1]);
        }
        vector<ll> suf_func(n);
        suf_func[n-1] = 0;
        for(int i = n-2; i >= 0; i--) {
            suf_func[i] = suf_func[i+1] + (ll) sufsum[i+1] * (coords[i+1] - coords[i]);
        }

        ll mini = LLONG_MAX;
        int idx = 0;
        rep(i, 0, n) {
            if(mini >suf_func[i] + pref_func[i] ) {
                mini = suf_func[i] + pref_func[i];
                idx = i;
            }
        }
        cout << coords[idx] << '\n';
    }
	return 0;
}