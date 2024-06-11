#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


pair<ll, int> best(vi &nums, vector<vi> &best_split, vector<vector<ll>> &dp,  int l, int r) {
	if(dp[l][r] >= 0) return {dp[l][r], best_split[l][r]};
	if(l == r) return {nums[l], -1};
	if(l == r - 1) {
		ll a = nums[l] + nums[r];
		ll b = nums[l] * nums[r];

		if(a > b) return {a, -1};
		else return {b, 0};
	}


	cout << "best " << l << " " << r << '\n';
	ll sum = 0;
	rep(i, l, r+1) sum += nums[i];
	ll ans = sum;
	int best_idx = -1;
	rep(i, l, r) {
		ll left = best(nums, best_split, dp,  l, i).first;
		ll right = best(nums, best_split, dp, i+1, r).first;

		if(left * right > ans) {
			ans = left * right;
			best_idx = i;
		}
	}
	best_split[l][r] = best_idx;
	dp[l][r] = ans;
	return {ans, best_idx};
}

vector<vi> get_terms(vi &nums, vector<vi> &best_split, int l, int r) {
	if(l == r) {return {{nums[l]}};}

	vector<vi> terms;

	auto split = best_split[l][r];

	if(split == -1) {
		vi term;	
		rep(i,l, r+1) term.push_back(nums[i]);
		terms.push_back(term);
	} else {
		auto terms1 = get_terms(nums, best_split, l, split);
		auto terms2 = get_terms(nums, best_split, split+1, r);

		for(auto x : terms1) terms.push_back(x);
		for(auto x : terms2) terms.push_back(x);
	}

	return terms;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

	int n;
	cin >> n;
	vi nums(n);

	int one_cnt = 0;
	int two_cnt = 0;
	for (auto &x : nums) {
		cin >> x;
		one_cnt += x == 1;
		two_cnt += x == 2;
	}

	sort(all(nums));


	int k = min(one_cnt + two_cnt + 1, n); 
	vector<vi> terms;
	rep(i, 0, k) {
		if(one_cnt >= 3 && two_cnt >= 3) {
			terms.push_back({1,2});
			i+=1;one_cnt--;two_cnt--;
		} else if(one_cnt >= 3) {
			terms.push_back({1,1,1});
			i+=2;one_cnt-=2;
		} else if(two_cnt >= 3) {
			terms.push_back({2});
			two_cnt--;	
		}else {
			int m = k - i;
			vi nums1;
			rep(j, 0, one_cnt) nums1.push_back(1);
			rep(j, 0, two_cnt) nums1.push_back(2);
			if(nums[k-1] > 2) nums1.push_back(nums[k-1]);

			vector<vi> bsplit(m, vi(m, -1));
			vector<vector<ll>> bnum(m,  vector<ll>(m, -1));

			auto [ans, split] = best(nums1, bsplit,bnum, 0, m-1);
			
			auto terms1 = get_terms(nums1, bsplit, 0, m-1);

			for(auto x : terms1) terms.push_back(x);
			break;

		}
	}
	rep(i, k, n) terms.push_back({nums[i]});

	rep(i, 0, sz(terms)) {
		if(terms[i].size() > 1) cout << "(";
		rep(j, 0, sz(terms[i])) {
			if(j > 0) cout << "+";
			cout << terms[i][j];
		}
		if(terms[i].size() > 1) cout << ")";

		
		if(i < sz(terms) - 1) cout << "*";
	}
	cout << '\n';


	return 0;
}