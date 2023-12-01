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
	int n;
	vi nums; 

	int x;
	
	int cnt = 0;
	while(cin >> x) {
		nums.push_back(x);
	}
	n = nums.size();
	rep(i, 1, n) {
		if(nums[i] > nums[i-1])++cnt;
	}

	cout << cnt << '\n';

	return 0;
}