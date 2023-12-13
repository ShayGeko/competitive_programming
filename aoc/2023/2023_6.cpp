#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<vi> vvi;
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
	vll time, dist;
	getline(cin, str);
	ss sin(str);
	sin >> word;
	while(sin >> num) {
		time.push_back(num);
	}
	getline(cin, str);
	sin = ss (str);
	sin >> word;
	while(sin >> num) {
		dist.push_back(num);
	}

	ll ans = 1;
	rep(i, 0, sz(time)) {
		cnt = 0;
		for(ll t = 0; t < time[i]; ++t) {
			if(t * (time[i] - t) >= dist[i]) ++cnt;
		}
		ans *=cnt;
	}
	cout << ans << '\n';
}
void p2() {
	string time, dist;
	getline(cin, str);
	ss sin(str);
	sin >> word;
	while(sin >> num) {
		time += to_string(num);
	}
	getline(cin, str);
	sin = ss (str);
	sin >> word;
	while(sin >> num) {
		dist += to_string(num);
	}

	ll ans = 1;
	ll tim = stoll(time), distance = stoll(dist);
	cnt = 0;
	for(ll t = 0; t < tim; ++t) {
		if(t * (tim - t) >= distance) ++cnt;
	}
		ans *=cnt;
	cout << cnt << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string part;
	getline(cin, part);

	if(part == "1") p1();
	else p2();
	return 0;
}