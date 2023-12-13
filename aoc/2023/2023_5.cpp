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
typedef vector<pll> vpll;
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

template <typename  T>
istream &operator >> (istream& is, pair<T, T> &p){
    cin >> p.first >> p.second;
    return is;
}
template <typename  T>
ostream &operator << (ostream& os, pair<T,T> &p){
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
	getline(cin, str);

	vll seeds;
	ss sin(str);
	sin >> word;
	while(sin >> num) seeds.push_back(num);

	vector<vector<vll>> maps(7);
	getline(cin, str);
	rep(i, 0, 7) {
		getline(cin, str); // trash

		while(getline(cin, str) && str != "") {
			sin = ss(str);
			ll a, b, c;
			sin >> a >> b >> c;

			maps[i].push_back(vll{b, b + c - 1, a, a + c - 1});
		}

		sort(all(maps[i]));
	}

	
	vector<vll> cur(8);
	cur[0] = seeds;

	rep(i, 0, 7) {
		for(auto x : cur[i]) {
			bool found = false;
			for(auto mp : maps[i]) {
				ll from1 = mp[0], from2=mp[1];
				if(x >= from1 && x <= from2) {
					found = true;
					cur[i+1].push_back(mp[2] + x - from1);
					break;
				}
			}
			if(!found) cur[i+1].push_back(x);
			
		}
		
	}

	// cout << "--------------------\n";
	// rep(i, 0, 8) {
	// 	for(auto x : cur[i]) cout << x << " ";
	// 	cout << '\n';
	// 	if(i < 7) for(auto x : maps[i]) cout << "(" << x[0] << ", " << x[1]  << "), " ;
	// 	cout << '\n';
	// 	if(i < 7) for(auto x : maps[i]) cout << "(" << x[2] << ", " << x[3] << "), " ;
	// 	cout << '\n';
	// 	cout << "--------------------------------\n";
	// }
	sort(all(cur[7]));

	cout << cur[7][0] << '\n';
}

void p2() {
	getline(cin, str);

	vector<pair<ull, ull>> seeds;
	ss sin(str);
	sin >> word;
	ull a, b;
	while(sin >> a >> b) seeds.push_back({a, a+b-1});

	vector<vector<vull>> maps(7);
	getline(cin, str);
	rep(i, 0, 7) {
		getline(cin, str); // trash

		while(getline(cin, str) && str != "") {
			sin = ss(str);
			ull a, b, c;
			sin >> a >> b >> c;

			maps[i].push_back(vull{b, b + c - 1, a, a + c - 1});
		}

		sort(all(maps[i]));
	}

	
	vector<vector<pair<ull, ull>>> cur(8);
	cur[0] = seeds;

	rep(i, 0, 7) {
		for(auto [xl, xr] : cur[i]) {
			vector<pair<ull, ull>> found;
			for(auto mp : maps[i]) {
				ull fl = mp[0], fr=mp[1], tl = mp[2], tr = mp[3];
				if((xl >= fl && xl <= fr) || (xr >= fl && xr <= fr)) {
					found.push_back({max(fl, xl), min(fr, xr)});
					cur[i+1].push_back({tl + max(fl, xl) - fl, tl + min(fr, xr) - fl});
				}
			}
			sort(all(found));
			ull l = xl, r = xr;

			for(auto [fl, fr]: found) {
				if(l < fl) cur[i+1].push_back({l, fl - 1});
				l = fr + 1;
				// cur[i+1].push_back({fl, fr});
			}
			if(l < xr) cur[i+1].push_back({l, r});
		}
	}

	// cout << "--------------------\n";
	// rep(i, 0, 8) {
	// 	sort(all(cur[i]));
	// 	for(auto x : cur[i]) cout << x.first << " " << x.second << ", ";
	// 	cout << '\n';
	// 	if(i < 7) for(auto x : maps[i]) cout << "(" << x[0] << ", " << x[1]  << "), " ;
	// 	cout << '\n';
	// 	if(i < 7) for(auto x : maps[i]) cout << "(" << x[2] << ", " << x[3] << "), " ;
	// 	cout << '\n';
	// 	cout << "--------------------------------\n";
	// }
	sort(all(cur[7]));

	cout << cur[7][0] << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string part;
	getline(cin, part);

	if(part == "1") p1();
	else if(part == "2") p2();
	else {
		cout << "\033[1;31minvalid input. Make sure first line is \"1\" or \"2\" to specify part\n\033[0m\n";
		while(getline(cin, str)) {};
	}
	return 0;
}