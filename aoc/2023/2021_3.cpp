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
	while(cin >> str) {
		vstr.push_back(str);
	}

	string str;

	ll g=0, e=0;
	for(int j = 0; j < vstr[0].size(); ++j) {
		int a = 0;
		for(int i = 0; i < vstr[i].size(); ++i) {
			str = vstr[i];
			if(str[j] == '1') ++a;
		}
		a = (a >= vstr.size());
		g |= a;
		g *= 2;
		e |=1-a;
		e *= 2;
	}
	cout << g << " " << e << '\n';
	cout << g * e << '\n';


	return 0;
}