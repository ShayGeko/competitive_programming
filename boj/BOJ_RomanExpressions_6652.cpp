#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<char, int> romanMap = {
	{'O', 0},
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000}
};
int fromRoman(string s) {
	int ans = 0;
	int prev = 0;
	for(auto c : s) {
		int cur = romanMap[c];
		ans += cur;
		if(prev < cur) {
			ans -= prev * 2;
		}
		prev = cur;
	}	

	return ans;
}
string toRoman(int x) {
	if(!x) return "O";
	string ans = "";
	if(x / 1000) {
		int t = x / 1000;
		rep(i, 0, t) ans += 'M';
	}

	vector<array<char, 3>> vals = {
		{'C', 'D', 'M'},
		{'X', 'L', 'C'},
		{'I', 'V', 'X'}
	};
	int i = 0;
	int pw = 1000;
	rep(i, 0, 3) {
		x = x % pw;
		pw /=10;
		auto [one, half, full] = vals[i];
		if(x / pw) {
			int h = x / pw;

			if(h == 9) {ans += one; ans += full;}
			else {
				if(h >= 5) {
					ans += half;
					h-=5;
				}
				if(h == 4) {ans += one; ans += half;}
				else {
					rep(i,0,h) ans+=one;
				}
			}
		}
	}

	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

	vector<int> registers(11);
	vector<bool> isSet(11, false);
	while(true) {
		string s;
		getline(cin, s);
		if(s == "RESET") {
			rep(i, 0, 11) isSet[i] = false;
			// cout << "ANS: ";
			cout << "Ready\n";
			continue;
		}
		if(s == "QUIT") {
			// cout << "ANS: ";
			cout << "Bye\n";
			break;
		}
		stringstream ss(s);
		int reg; char _;
		string expr;
		ss >> reg >> _ >> expr;

		// cout << "PARSED: " << reg << " <- " << expr << '\n';

		char plus = '+', minu = '-';

		string cur = "";
		int left = 0; char op;

		bool isValid = true;
		char lastOp='+';
		expr += '+';
		for(auto c : expr) {
			if(c == '+' || c == '-') {
				int num;
				if(cur == "10" || (cur.size() == 1 && isdigit(cur[0]))){
					num = stoi(cur);
					// num is a register
					// cout << "REGISTER\n";

					if(isSet[num]) {
						if(lastOp == '+') left += registers[num];
						else left -= registers[num];
					} else {
						isValid = false;
						break;
					}
				} else{
					num = fromRoman(cur);
					// cout << " " << cur << " -> " << num << " " << lastOp <<  '\n';
					if(lastOp == '+') left+=num;
					else left-=num;
				}
				cur = "";
				lastOp = c;
			} else {
				cur += c;
			}
		}
		// if(isValid) cout << "EXPR result: " << left << '\n';
		// else cout << "Register error!\n";
		if(left <0 || left > 10000) isValid = false;

		if(isValid) {
			isSet[reg] = true;
			registers[reg] = left;

			string roman = toRoman(left);
			// cout << "ANS: ";
			cout << reg <<'=' << roman << '\n';
		} else {
			// cout << "ANS: ";
			cout << "Error\n";
		}
	}

	return 0;
}