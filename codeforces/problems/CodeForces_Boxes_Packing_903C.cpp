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


	int n;
	cin >> n;
	vi nums(n);
	for(auto & x : nums) cin >> x;

	map<int, int> boxes;

	sort(nums.rbegin(), nums.rend());

	for(auto x : nums) {
		bool inserted = false;
		for(auto [bb, cnt] : boxes) {
			if(bb > x) {
				if(cnt == 1) {
					boxes.erase(bb);
				} else boxes[bb]--;

				++boxes[x];
				inserted = true;
				break;
			}
 		}
		if(!inserted) boxes[x]++;
	}

	int total = 0;
	for(auto [bb, cnt] : boxes) total += cnt;

	cout << total << '\n';
	return 0;
}