#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pll> vpll;
typedef pair<string, int> psi;
typedef pair<string, ll> psll;
typedef vector<psi> vpsi;
typedef vector<psll> vpsll;
typedef map<string, int> msi;
typedef map<string, ll> msll;
typedef map<char, int> mci;
typedef map<char, ll> mcll;
typedef stringstream ss;

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


string str, word;
ll cnt = 0, a, b, x, num;
vi nums;
vector<string> vstr;

char c, _;

void p1() {
	string dir;
	getline(cin, dir);
	getline(cin, str);

	map<string, pair<string, string>> mp;
	while(getline(cin, str)) {
		ss sin(str);
		string node, nl, nr;
		sin >> node >> _ >> nl >> nr;
		nl = nl.substr(1, nl.size() - 2);
		nr = nr.substr(0, nr.size() - 1);

		mp[node] = {nl, nr};
	}

	int k = 0;
	vector<string> cur = {"11A", "22A"};
	
}

map<pair<string, int>, int> memo;
map<string, pair<string, string>> mp;
string dir;
ll compute(string s, int k) {
		if(s.back() == 'Z') return memo[{s, k}] = 0;
		if(memo[{s, k}] != 0) return memo[{s, k}];
		if(dir[k % sz(dir)] == 'L') return memo[{s, k}] = compute(mp[s].first, k + 1);
		else memo[{s, k}] = compute(mp[s].second, k+1);
	};
void p2() {
	getline(cin, dir);
	getline(cin, str);

	
	vector<string> cur;
	vector<string> zcur;
	while(getline(cin, str)) {
		ss sin(str);
		string node, nl, nr;
		sin >> node >> _ >> nl >> nr;
		if(node.back() == 'A') cur.push_back(node);
		else if(node.back() == 'Z') zcur.push_back(node);
		nl = nl.substr(1, nl.size() - 2);
		nr = nr.substr(0, nr.size() - 1);

		mp[node] = {nl, nr};
	}

	int k = 0;
	vector<ll> times(sz(cur));
	vector<ll> ztimes(sz(cur));

	rep(i, 0, sz(cur)) {
		k = 0;
		string s = cur[i];
		while(s.back() != 'Z') {
			if(dir[k%sz(dir)] == 'L') s = mp[s].first;
			else s = mp[s].second;
			++k;
		}
		times[i] = k;
	}

	ull gc = times[0];
	ull prod = 1;

	set<ll> tt(all(times));
	for(auto t : tt) {
		prod *= t;
		gc = __gcd(gc, t);
	}
	for(auto t : times) cout << t << " ";

	cout << k << '\n';
	cout << gc << " " << prod / gc << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string part;
	getline(cin, part);

	if(part == "1") p1();
	else p2();
	return 0;
}