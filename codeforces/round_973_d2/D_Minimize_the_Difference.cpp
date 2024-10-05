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
        int n;
        cin >> n;
        vector<ll> A(n);

        for(auto &x : A) cin >> x;

        // min cannot be bigger than A[0]
        // max cannot be smaller than A[n-1]
        // if max is before min,
        // can always decrease the answer

        // otherwise can only improve the answer
        // if there is a number smaller than max after max
        // or a number greater than min before min
        ll mini = A[0], maxi = A[0];
        int posmin = 0, posmax = 0;
        rep(i, 0, n) {
            if(A[i] < mini) {
                posmin = i;
                mini = A[i];
            }
            if (A[i] > maxi) {
                posmax = i;
                maxi = A[i];
            }
        }

        vector<ll> psum(n+1);
        psum[0] = 0;
        rep(i, 0, n) psum[i+1] = psum[i] + A[i];

        // can increase min by psum[posmin] - posmin * min
        // without 

        multiset<ll> st (all(A));
        // can decrease posmax by
        // maxi - max(posmax+1, n-1);
    }

	return 0;
}