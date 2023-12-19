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

	int n, k;
	cin >> n >> k;

	vi nums(n);
	vi remaining(k+1, 0);
	for(auto &x : nums) {
		cin >> x;
		remaining[x]++;
	}

	vi st;
	set<int> added;
	for(auto x : nums) {
		if(added.count(x)) remaining[x]--;
		else {
			while(st.size() && remaining[st.back()] && st.back() > x){
				added.erase(st.back());
				st.pop_back();
			}
			st.push_back(x);
			added.insert(x);
			remaining[x]--;
		}
	}

	for(auto x : st) cout << x << " ";
	cout << '\n';
	return 0;
}