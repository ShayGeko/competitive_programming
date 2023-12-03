#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;

    return os;
}

pii operator* (pii a, int b) {
	return {a.first * b, a.second * b};
};
void operator*= (pii&a, int b) {
	a.first*=b;
	a.second*=b;
}
pii operator+ (pii a, int b) {
	return {a.first + b, a.second + b};
}
void operator+= (pii&a, pii b){
	a.first += b.first;
	a.second += b.second;
}


string str;
int cnt = 0, a, b, x;
vi nums;
vector<string> vstr;

char c, _;
ll ans = 0;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	vector<pair<string, int>> comp = {{"red", 12}, {"green", 13}, {"blue", 14}};
	int i = 1;
	int ans = 0;
	while(getline(cin, str)) {
		stringstream ss(str);
		string tmp;
		ss >> tmp >> x >> _;
		map<string, int> m;
		while(ss >> x >> str) {
			if(str == "green" || str == "blue" || str == "red") {

			} else {
				str = str.substr(0, sz(str) - 1);
			}

			m[str] = max(m[str], x);
		}

		ll pw = 1;
		for(auto [str, n] : comp) {
			pw *= m[str];
		}
		ans += pw;
	}

	cout << ans << '\n';
	return 0;
}