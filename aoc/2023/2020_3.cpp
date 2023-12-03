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

char c, _;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;

	vector<string> vstr;
	while(getline(cin, str) && str != "") {
		vstr.push_back(str);
	}


	vector<pii> slopes = {{1, 1}, {3, 1}, {5, 1}, {7, 1}, {1, 2}};
	ll ans = 1;
	for(auto [a, b] : slopes) {
		int i = 0, j = 0;
		cnt = 0;
		while(i < vstr.size() && j < vstr[i].size()) {
			if(vstr[i][j] == '#') ++cnt;
			j+=a;
			j%=vstr[i].size();
			i+=b;
		}
		cout << cnt << '\n';
		ans *= cnt;
	}
	cout << ans << '\n';
	return 0;
}