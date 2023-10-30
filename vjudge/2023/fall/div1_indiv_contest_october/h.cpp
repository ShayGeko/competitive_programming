#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int gc = 0;

set<string> reachable;


void crossOutReachable(string &s) {
	string tmp = s;

	rep(i, 0, 10) {
		rep(a, 'a','z'+1){
			tmp[i] = a;
			reachable.insert(tmp);
		}
		tmp[i]=s[i];
	}
}

string getNext(string &s) {
	// just need to find something adjacent to s that is not yet in the reachable set
	
	string tmp = s;
	rep(i, 0, 10) {
		rep(a, 'a','z'+1){
			if(a == s[i]) continue;
			tmp[i] = a;

			if(reachable.find(tmp) == reachable.end()) return tmp;
		}
		tmp[i]=s[i];
	}

	// I pray to CompProg Gods that we dont get here, I aint gonna prove this
	assert(false);
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	string str(10, 'a');
	rep(i, 0, n) {
		cout << str << '\n';
		string newStr = getNext(str);
		crossOutReachable(str);
		str = newStr;
	}
	cout.flush();
	return 0;
}