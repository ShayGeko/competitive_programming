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
	for(auto &x : nums) cin >> x;

	if(n == 1) {
		cout << 0 << '\n';
		return 0;
	}

	typedef array<int, 4> peak;

	auto calc = [&]() -> pair<ll, ll> {
		vector<peak> peaks(n);
		peaks[0] = {nums[0], 0, nums[1], 0};
		rep(i, 1, n- 1) {
			peaks[i] = {nums[i], nums[i-1], nums[i+1], i};
		}
		peaks[n-1] = {nums[n-1], nums[n-2], 0, n-1};

		vector<peak> st;
		ll ftop = 0, fbot = 1;
		rep(i, 0, n) {
			auto &x = peaks[i]; 
			while(st.size() && st.back()[0] < x[0]) {
				st.pop_back();
			}
			// check previous peak > cur
			if(st.size()) {
				auto [ph, _, pr, ind] = st.back();
				
				if(ind == i - 1) { // decreasing slope -> no view
					st.push_back(x);
					continue;
				}

				// for a segment A - B with a point x at it:
				// AB/XB = 1 / len, since A and B are adjacent milestones
				ll ftop1 = ((ll)i - ind - 1) * (ph - pr) + (x[0]-pr);
				ll fbot1 = ph-pr;
				// new > old
				if(ftop1 * fbot > ftop * fbot1) {
					ftop = ftop1;
					fbot = fbot1;
				}
			}
			st.push_back(x);
		}

		return {ftop, fbot};
	};

	auto [a1, a2] = calc();
	reverse(all(nums));
	auto [b1, b2] = calc();

	if(b1 * a2 > a1 * b2) {
		swap(a1, b1);
		swap(a2, b2);
	}

	ll gc = gcd(a1, a2);
	a1 /= gc;
	a2 /= gc;
	
	cout << a1;
	if(a2 != 1) {
		cout << "/" << a2;
	}
	cout << "\n";
	 
	return 0;
}