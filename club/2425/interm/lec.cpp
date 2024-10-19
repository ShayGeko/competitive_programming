#include <bits/stdc++.h>

// #include<set>
using namespace std;

// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define all(x) begin(x), end(x)
// #define sz(x) (int)(x).size()
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);


	multiset<int> st;

	st.insert(2);
	st.insert(4); // 
	st.insert(4);
	st.insert(5);

	// lowerbound 5 -> first >= 5
	auto it = st.lower_bound(4); // the first 4

	auto pr = prev(it); // element before the first 4 
	cout << *pr << '\n';

	it = st.upper_bound(4); // first element greater than 4
	cout << *it << '\n';
	// st.end()
	
	// st.erase(4);
	it = st.lower_bound(4);
	st.erase(it);
	for(auto x : st) cout << x << ' ';
	cout << '\n';
	return 0;
}