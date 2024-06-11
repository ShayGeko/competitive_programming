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

	int schedule = 0;
	map<string, int> times[2];
	set<string> names;
	while(true) {
		getline(cin, s);
		if(s[0] == '-') {++schedule;continue;}
		else if(s[0] == '=') break;

		stringstream ss(s);
		int a, b; string name;
		ss >> a >> b >> name;

		names.insert(name);

		times[schedule][name] += b - a;
	}


	int cnt = 0;
	for(auto nm : names) {
		int prev = times[0][nm];
		int cur = times[1][nm];
		if(prev < cur) {
			++cnt;
			cout << nm << " +" << cur - prev << '\n';
		}
		else if(prev > cur){
			++cnt;
			cout << nm << " " << cur - prev << '\n';
		}
	}

	if(cnt == 0) {
		cout << "No differences found.\n";
	}

	return 0;
}