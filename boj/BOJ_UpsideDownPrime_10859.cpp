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
	
	string reverseMap = "012##59#86";
	string invalid = "347";

	bool isValid = true;
	for(auto c : s) {
		if(invalid.find(c) != invalid.npos)  {
			isValid = false;
		}
	}
	if(!isValid) {
		cout << "no\n";
		return 0;
	}

	string s1 = "";
	for(auto c : s) {
		s1 += (reverseMap[c-'0']);
	}

	reverse(all(s1));
	
	ll a = stoll(s);
	ll b = stoll(s1);
	// cout << a << " " << b << '\n';
	if(a == 1) {
		cout << "no\n";
		return 0;
	}
	auto isPrime = [](ll a) {
		for(ll i = 2; i < min((ll)sqrt(a) + 2, a); ++i) {
			if(a % i == 0) {
				// cout << a << " " << i << '\n';
				return false;
			}
		}
		return true;
	};
	bool flagA = isPrime(a), flagB  = isPrime(b);

	if(flagA && flagB) {
		cout << "yes\n";
	} else {
		cout << "no\n";
	}

	return 0;
}