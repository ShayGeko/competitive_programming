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

	string s;
	cin >> s;
	int a = 0, b= 0;

	string vowels = "aeiou";

	for(auto c : s) {
		if(vowels.find(c) != string::npos) {
			a++; b++;
		} else if (c == 'y'){
			b++;
		}
	}

	cout << a << " " << b << '\n';

	return 0;
}