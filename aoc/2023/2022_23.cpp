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
int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<vector<string>> rnds;
	while(getline(cin, str)) {
		rnds.push_back({});
		while(getline(cin, str)) {
			if(str == "") break;

			rnds.back().push_back(str);
		}
	}

	int T = rnds.size();
	vector<vector<vi>> poscnt(T);

	rep(t, 0, T) {
		poscnt[t].resize(sz(vstr[t]));
		int n = rnds[t].size();
		int m = rnds[t][0].size();
		rep(i, 0, n) poscnt[t][i] = vi(m, 0);
		rep(i, 0, n) {
			rep(j, 0, m) {
				if(rnds[t][i][j] == '#') {
					rep(di, -1, 1) {
						if(!di) continue;
					}
				}
			}
		}
	}


	return 0;
}