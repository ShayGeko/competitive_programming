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

    vi available(n);
    rep(i, 0, n) {
        cin >> available[i];
    }
    sort(all(available));

    vi av;
    av.push_back(available[0]);
    for(auto x : available) if(x != av.back()) av.push_back(x);
    vi nums(m, 1);

    n = sz(av);

    // cout << n << '\n';
    // rep(i, 0, m) nums[i] = i + 1;
    vi prev(m, -1);
    do {
        bool flag = true;
        rep(i, 0, m) {
            if(av[nums[i] - 1] != av[prev[i] - 1]) {
                flag = false;
                break;
            }
        }
        if(flag) continue;
        // for(auto x : nums) cout << x << " "; cout << " || ";
        for(auto x : nums) cout << av[x-1] << " ";cout << '\n';
        prev = nums;
    }while(add(nums, n, m-1));
        

	return 0;
}