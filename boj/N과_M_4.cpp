#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool add(vi& nums, int n, int j) {
    if(j < 0) return false;
    
    if(nums[j] < n) {
        ++nums[j];
        return true;
    }
    else {
        bool res = add(nums, n, j - 1);
        if(res) nums[j] = nums[j-1];
        return res;
    }
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    int n, m;
    cin >> n >> m;

    vi nums(m, 1);

    // rep(i, 0, m) nums[i] = i + 1;
    do {
        for(auto x : nums) cout << x << " ";cout << '\n';
    }while(add(nums, n, m-1));
        

	return 0;
}