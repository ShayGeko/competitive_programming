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

void insertSegment(pair<ull, ull> pr, set<pair<ull, ull>> &st) {
	ull l = pr.first, r = pr.second;

	auto it = st.begin();
	bool inserted = false;
	while(it != st.end()) {
		auto [L, R] = *it;
		auto nxt = next(it);
		if(l > R+1) {
			it = nxt;
			continue;
		}

		if((l >= L && l <= R+1) || (r >= L-1 && r <= R)) {
			l = min(l, L);
			r = max(r, R);
			st.erase(it);
		}
		it = nxt;
	}

	if(!inserted) {
		st.insert({l, r});
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);


	string sds;
	vector<pair<ull, ull>> seeds;

	getline(cin, sds);

	stringstream ssdss(sds);
	ssdss >> str;

	ull n1, n2;
	while(ssdss >> n1 >> n2) {
		seeds.push_back({n1, n1 + n2 - 1});
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
	sort(all(seeds));
	rep(i, 0, 7) {
		sort(all(mp[i]));
	}
	vector<set<pair<ull, ull>>> cur(8);
	for(auto sed : seeds) insertSegment(sed, cur[0]);
	vector<vector<bool>> contained(7);
	rep(i, 0, 7) contained[i] = vector<bool>(sz(mp[i]), false);
	rep(i, 1, 8) {
		// map current level to next level
		for(auto [x, y] : cur[i-1]) {
			set<pair<ull, ull>> matched;
			vector<pair<ull, ull>> unmatched;
			for(int j = 0; j < mp[i-1].size(); ++j) {
				if(contained[i-1][j]) continue; // don't duplciate output segments

				auto v = mp[i-1][j];
				if(x <= v[0] && y >= v[1]) { // if segment is fully inside [x,y], insert full output segment
					contained[i-1][j] = true;
					insertSegment({v[2], v[3]}, cur[i]);
					
					// split(unmatched, {v[2], v[3]});
					insertSegment({v[0], v[1]}, matched);
				}
				else if((y >= v[0] && y <= v[1]) || (x >=v[0] && x <= v[1])) {
					insertSegment({v[2] + max(x, v[0]) - v[0],  min(v[3], v[2] + y - v[0])}, cur[i]);
					// split(unmatched, {max(x, v[0]), min(y, v[1])});
					insertSegment({max(x, v[0]), min(y, v[1])}, matched);
				}
			}

			// find the unmatched segments by iterating through matched ones:
			ull l = x;
			ull last = 0;
			for(auto [L, R] : matched) {
				if(l < L) unmatched.push_back({l, L-1});
				l = R + 1;
			}
			if(l <= y) unmatched.push_back({l, y});

			for(auto seg : unmatched) { // when something is not matched, it maps to itself
				insertSegment(seg, cur[i]);
			}
		}
	}

	cout << (*cur[7].begin()).first << '\n';
	return 0;
}

// NOT 1332461953 (too high)
// not 7956471 7956471 7956471
// not 1276666937

// 71915072
// 0 BAD
// 3347258382
// 0 BAD!!!!
// 0 BAD :(