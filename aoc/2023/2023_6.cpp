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

typedef unsigned long long ull;

string str;
int cnt = 0, a, b, x;
vi nums;
vector<string> vstr;

string word;
char c, _;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	getline(cin, str);
	stringstream ss(str);
	string tim ="", distance="";
	ss >> word;
	int n;
	while(ss >> n) {
		tim+= to_string(n);
	}

	getline(cin, str);
	ss = stringstream(str);
	ss >> word;
	while(ss >> n) {
		distance+= to_string(n);
	}

	n = sz(distance);

	int cnt = 0;

	ll dist = stoll(distance);
	ll time = stoll(tim);
	ll ans = 1;
	cnt = 0;
	for(ll t =0; t < time; ++t) {
		if((time - t) * t >=dist) ++cnt;
	}

	cout << cnt << '\n';
	return 0;
}