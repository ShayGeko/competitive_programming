#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string str;
int cnt = 0;
int x;
vi nums;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	vi nums;
	int sum = 0;
	vector<string> vals = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	while(true) {
		getline(cin, str);
		if(str == "") break;
		vi cc;
		for(int i = 0; i < sz(str); ++i) {
			char c = str[i];
			if(c >= '0' && c <= '9') cc.push_back(c-'0');
			else for(int j = 0; j < sz(vals); ++j) {
				string s = vals[j];
				if(str.substr(i, sz(s)) == s) {
					cc.push_back(j+1);
				}
			}
		}
		int b = cc[0]*10 + cc.back();
		sum += b;
	}
	cout << sum << '\n';
	return 0;
}