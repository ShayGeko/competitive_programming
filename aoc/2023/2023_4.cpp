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
ll cnt = 0, a, b, x;
vi nums;
vector<string> vstr;

char c, _;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<set<int>> win;
	vector<set<int>> has;
	
	int n = 199;
	vi scards(n, 1);
	int i = 0;
	while(getline(cin, str)){
		stringstream ss(str);

		string word;
		int num;

		ss >> word >> num >> _;



		win.push_back({});
		has.push_back({});


		while(ss>>c && c != '|') {
			ss.putback(c);
			ss >> num;
			win.back().insert(num);
		}

		ll ans = 0;

		while(ss >> num) {
			has.back().insert(num);
			if(win.back().count(num) >= 1) {
				++ans;
			}
		}

		rep(j, i+1, min((ll)n, i + ans + 1)) {
			scards[j] += scards[i];
		}
		++i;
	}

	rep(i, 0, n) {
		cnt += scards[i];
	}
	cout << cnt << '\n';
	return 0;
}