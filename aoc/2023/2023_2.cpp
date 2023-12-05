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
	
	string str;


	map<string, int> comp = {
		{"red", 12}, {"green", 13}, {"blue", 14}
	};
	int i = 1;
	while(getline(cin, str)) {
		if(str.size() < 2) cout << "|" << str << "|" << '\n';
		if(str == "") break;
		stringstream ss(str);
		map<string, int> mp;

		string col;
		int num;
		ss >> col >> num >> _;
		while(ss >> num >> col ) {
			if(col == "green" || col == "blue" || col == "red") {
			} else {
				col = col.substr(0, sz(col) - 1);
			}
			
			mp[col] = max(mp[col], num);
		}

	 	bool flag = true;
		int ans = 1;
		for(auto [col1, num1] : comp) {
			// if(mp[col1] > comp[col1]) {
			// 	flag = false;
			// 	break;
			// }
			ans *= mp[col];
		} 
		// if(flag) {
		// 	cout << i << '\n';
		// 	cnt += i;
		// }
		cnt +=ans;
		
		++i;
	}

	cout << cnt << '\n';
	return 0;
}