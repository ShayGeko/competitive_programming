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

	string str;
	getline(cin, str);
	
	string s = "";
	for(auto c : str) if(isalpha(c)) s += tolower(c);

	int n = sz(s);
	rep(i, 0, n) {
		rep(j, i + 1, n) {
			int l = i, r = j;
			bool isPal = true;

			while(l < r && isPal) {
				isPal = s[l++] == s[r--];
			}
			if(isPal) {
				cout << "Palindrome\n";
				return 0;
			}
		}
	}

	cout << "Anti-palindrome\n";

	return 0;
}