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

typedef unsigned long long ull;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ull n;

	string sds;
	vector<ull> seeds;

	getline(cin, sds);

	stringstream ssdss(sds);
	ssdss >> str;

	while(ssdss >> n) {
		seeds.push_back(n);
	}

	getline(cin, str);

	vector<vector<vector<ull>>> mp(7);

	rep(i, 0, 7){
	getline(cin, str);
		while(getline(cin, str)) {
			if(str == "") break;

			stringstream ss(str);
			ull a, b, c;
			ss >> a >> b >> c;

			mp[i].push_back({b, b + c - 1, a, a + c - 1});
		}
	}

	vector<vector<ull>> cur(7);
	for(auto s : seeds) {
		bool found = false;
		for(auto v : mp[0]) {
			if(s >= v[0] && s <= v[1]) {
				cur[0].push_back(s - v[0] + v[2]);
				found = true;
				break;
			}
		}
		if(!found) {
			cur[0].push_back(s);
		}
	}
	rep(i, 1, 7) {
		// map current level to next level
		for(auto z : cur[i-1]) {
			bool found = false;
			for(auto v : mp[i]) {
				if(z >= v[0] && z <= v[1]) {
					cur[i].push_back(z - v[0] + v[2]);
					found=true;
					break;
				}
			}
			if(!found) cur[i].push_back(z);
		}
	}

	sort(all(cur[6]));

	cout << cur.back()[0] << '\n';
	return 0;
}

// NOT 1332461953 (too high)
// not 7956471 7956471 7956471
// not 1276666937