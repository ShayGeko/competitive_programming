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
		} else if(one_cnt > 4) {
			terms.push_back({1,1,1});
			i+=2;one_cnt-=3;
		} else if(two_cnt >= 3) {
			terms.push_back({2});
			two_cnt--;	
		}else { 
			while(two_cnt && one_cnt) {
				if(one_cnt == 2 && two_cnt == 1) { // 1 1 1 1 4 -> (1 + 1) (1 + 1) 4
												   // 1 1 1 1 2 (1 + 1 + 1) (1 + 2)
					terms.push_back({1,1,2});
					one_cnt-=2;
					two_cnt-=1;
				} else {
					terms.push_back({1, 2});
					one_cnt--;two_cnt--;
				}
			}
			bool added = false;
			if(!one_cnt) rep(j, 0, two_cnt) terms.push_back({2});
			else if(!two_cnt && one_cnt) {
				if(one_cnt == 4) {
					terms.push_back({1,1});
					terms.push_back({1,1});
				}
				else if(one_cnt == 3) terms.push_back({1,1,1});
				else if(one_cnt == 2) terms.push_back({1,1});
				else {
					if(nums[k-1] > 2) {
						terms.push_back({1, nums[k-1]});
						added= true;
					}
					else terms.push_back({1});
				}
			}
			if(!added && nums[k-1] > 2) terms.push_back({nums[k-1]});
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