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
	cin >> n;

	vector<vi> foods(3);
	rep(i, 0, 3) {
		foods[i].reserve(n);
		rep(j, 0, n) {
			int x;
			cin >> x;
			foods[i].push_back(x);
		}
	}

	int q;
	cin >> q;
	
	typedef tuple<vi&, pii, int> cuisine;
	vector<cuisine> cuisines;
	
	// food[m], m, food, {l, r}, type
	typedef tuple<int, int, int> binsearch_item;

	auto func = [](vector<cuisine> &cuisines, int k){
		while(true) {
			vector<binsearch_item> items;
			int sum = 0;
			for (auto& [food, lr, type] : cuisines) {
				auto& [l, r] = lr;
				if(l > r) {
					continue;
				}
				int m = (l + r + 1) / 2;
				sum += m - l + 1; // zero indexed
				items.push_back({food[m], m, type});
			}
			if(items.size() == 1) {
				auto& [fm, m, type] = items.back();
				auto &[org_food, lr, ol_type] = cuisines[type-1]; 
				auto &[l, r] = lr;
				return pii {type, l + k - 1};
			}

			sort(all(items));
			if(sum > k) {
				// decrease the largest m
				auto& [fm, m, type] = items.back();
				auto &[org_food, lr, ol_type] = cuisines[type-1]; 
				auto &[l, r] = lr;
				r = m - (m == r);
			} else {
				// increase the smallest m
				auto& [fm, m, type] = items.front();
				auto &[org_food, lr, ol_type] = cuisines[type-1]; 
				auto &[l, r] = lr;
				k -= m - l + (l == m);
				l = m+ (l == m);
			}
		} 
		return pii{-1,-1};
	};


	while(q--) {
		int r1, r2, r3, k;
		cin >> r1 >> r2 >> r3 >> k;

		cuisines = {
			cuisine{foods[0], pii{0, r1-1}, 1},
			cuisine{foods[1], pii{0, r2-1}, 2},
			cuisine{foods[2], pii{0, r3-1}, 3}
		};

		auto [type, pos] = func(cuisines, k);
		cout << type << " " << pos + 1 << '\n';
	}


	return 0;
}