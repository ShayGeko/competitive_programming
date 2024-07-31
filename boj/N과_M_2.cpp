#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool add(vi& nums, int n, int j, int maxi) {
    if(nums[j] == maxi && !j) return false;
    if(nums[j] == maxi) {
        nums[j] = min(maxi, nums[j-1]+2);
        bool res = add(nums, n, j-1, nums[j]-1);
        if(res) {
            nums[j] = nums[j-1] + 1;
            return true;
        } else return false;
    }
    else {
        ++nums[j];
        return true;
    }
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    int n, m;
    cin >> n >> m;

    vi nums(m, 1);

    if(n < m) return 0;

    rep(i, 0, m) nums[i] = i + 1;
    do {
        for(auto x : nums) cout << x << " ";cout << '\n';
    }while(add(nums, n, m-1, n));
        

	return 0;
}