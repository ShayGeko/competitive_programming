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

int findMirror(vector<string> &grid) {
	vector<deque<char>> l(sz(grid)), r(sz(grid));
		rep(i, 0, sz(grid)) {
			rep(j, 0, sz(grid[i])) {
				r[i].push_back(grid[i][j]);
			}
		}
	int vmir = 0;
	while(r[0].size() > 1) {
		int eq = 0;
		rep(i, 0, sz(grid)) {
			l[i].push_back(r[i].front());
			r[i].pop_front();
			// check that l[i] is reflection of r[i]
			auto lptr = prev(end(l[i]));
			auto rptr = begin(r[i]);

			rep(k, 0, min(sz(l[i]), sz(r[i]))) {
				if(*lptr != *rptr) {++eq;}
				lptr = prev(lptr);
				rptr = next(rptr);
			}
		}

		if(eq==1) {
			return l[0].size();
		}
	}

	return -1;
}
void p1() {
	vector<vector<string>> grids;
	vector<string> grid;
	while(getline(cin, str)) {
		if(str == "") {
			grids.push_back(grid);
			grid.clear();
		}
		else grid.push_back(str);
	}
	if(grid.size()) grids.push_back(grid);

	ll ans = 0;
	rep(t, 0, sz(grids)) {
		vector<string> grid = grids[t];
		vector<string> transpose(sz(grid[0]), string(sz(grid), '*'));
		rep(i, 0, sz(grid)) {
			rep(j, 0, sz(grid[i])) {
				transpose[j][i] = grid[i][j];
			}
		}


		
		
		int vsplit = findMirror(grid);
		int hsplit = findMirror(transpose);
		// cout << vsplit << " " << hsplit << '\n';
		ans += (vsplit > 0) ? vsplit : 100LL * hsplit;
	}
	cout << ans << '\n';
}
void p2() {
	vector<vector<string>> grids;
	vector<string> grid;
	while(getline(cin, str)) {
		if(str == "") {
			grids.push_back(grid);
			grid.clear();
		}
		else grid.push_back(str);
	}
	if(grid.size()) grids.push_back(grid);

	ll ans = 0;
	rep(t, 0, sz(grids)) {
		vector<string> grid = grids[t];
		vector<string> transpose(sz(grid[0]), string(sz(grid), '*'));
		rep(i, 0, sz(grid)) {
			rep(j, 0, sz(grid[i])) {
				transpose[j][i] = grid[i][j];
			}
		}
		
		int vsplit = findMirror(grid);
		int hsplit = findMirror(transpose);
		// cout << vsplit << " " << hsplit << '\n';
		ans += (vsplit > 0) ? vsplit : 100LL * hsplit;
	}
	cout << ans << '\n';
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