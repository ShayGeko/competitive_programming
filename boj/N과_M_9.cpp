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

    vi nums(n);
    for(auto & x : nums) cin >> x;

    if(n < m) return 0;

    sort(all(nums));
    vi prev(m, 0);
    do {
        bool flag = true;
        rep(i, 0, m) {
            if(nums[i] != prev[i]) {
                flag = false;
                break;
            }
        }
        if(flag) continue;
        rep(i, 0, m) {
            cout << nums[i] << " ";
        }cout << '\n';
        prev = nums;
    } while(next_permutation(all(nums)));
        

	return 0;
}