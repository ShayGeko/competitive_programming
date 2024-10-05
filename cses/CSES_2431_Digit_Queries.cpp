#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// 0..9 2* 10..99 3* 100..999 4* 1000...9999 5 * 10_000...99_999

// 01234567891011121314151617181920212223242599100101102103104105016107108
// 15
// -10 -> 5
// 
char get(vector<ll> & ranges, int k, int offset=0) {
	
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	vector<ll> ranges;
	ranges.push_back(10);
	rep(i, 2, 19) {
		ranges.push_back(ranges.back() + (pow(10, i) - pow(10, i - 1))* i);
	}

	vector<ll> ranges1;
	ll length = 0;
	rep(i, 0, 100001) {
		if(i >= 10 && log10(i) == floor(log10(i))) ranges1.push_back(length);
		string a = to_string(i);
		length += a.size();
	}
	rep(i, 0, 5) {
		cout << ranges[i] << " " << ranges1[i] << '\n';
	} 
	
	return 0;
}