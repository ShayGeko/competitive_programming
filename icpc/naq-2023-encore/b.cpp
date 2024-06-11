#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int p = 9302023;
void add(vector<vector<pii>> &dp, int i, int j, int col) {
	auto [a1, a2] = dp[j][0];
	auto [b1, b2] = dp[j][1];

	if(pii{a1, a2} > pii{b1, b2}) {
		swap(a1, b1);
		swap(a2, b2);
	}
	
	auto &[c1, c2] = dp[i][col];
	if(a1 == b1 && a1 == c1 - 1) {
		c2 += a2 + b2;
	} else if(a1 + 1 < c1) {
		c1 = a1 + 1;
		c2 = a2;
		if(a1 == b1) c2 += b2;
	} else if(a1 == c1 - 1) {
		c2 += a2;
	}

	c2 %= p;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	vector<string> moves = 
	{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	
	string s;
	cin >> s;

	int n = sz(s);
	vector<vector<pii>> dp(n+3, vector<pii>(2, {1e9,0}));

	dp[0][0] = {0,1};
	rep(i, 1, 3) dp[i][0] = {i, 1};

	if(n > 2) {
	string cur = s.substr(0,2);
	int len = 2;
	rep(i, 3, n+1) {
		add(dp, i, i-1, 0); // don't collase
		string thr = s.substr(i-3, 3);
		if(thr == "one" || thr == "two" || thr == "six") {
			add(dp, i, i-3, 1); // collapse
		}
		if(i >= 4) {
			string four = s.substr(i-4, 4);
			if(four == "zero" || four == "four" || four == "five" || four == "nine") {
				add(dp, i, i-4, 1);
			}
		}
		if(i >= 5) {
			string five = s.substr(i-5, 5);
			if(five == "three" || five == "seven" || five == "eight") {
				add(dp, i, i-5, 1);
			}
		}
	}
	}

	auto [a1, a2] = dp[n][0];
	auto [b1, b2] = dp[n][1];

	if(a1 == b1) {
		cout << a1 << "\n" << (a2 + b2) % p << '\n';
	} else {
		if(a1 > b1) {
			swap(a1, b1);
			swap(a2, b2);	
		}
		cout << a1 << "\n" << a2 << '\n';
	}
	return 0;
}