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

map<string, int> mstr;

char c, _;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	string str;

	while(getline(cin, str)) {
		vstr.push_back(str);
	}
	int n = vstr.size();
	int m = vstr[0].size();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if((!isdigit(vstr[i][j])) && (vstr[i][j] != '.')) {
				
				int cnt1 = 0;
				ll ans = 1;
				for(int ii = i-1; ii <= i+1; ++ii) {
					for(int jj = j-1; jj <= j+1; ++jj) {
						if(!ii && !jj) continue;

						if(isdigit(vstr[ii][jj])) {
							++cnt1;
							int l = jj;
							while(l-1 >= 0 && isdigit(vstr[ii][l-1])) --l;
							int r = jj;
							while(r+1 < m && isdigit(vstr[ii][r+1])) ++r;

							string temp = vstr[ii].substr(l, r - l + 1);
							// cnt += stoi(temp);
							ans *= stoi(temp);
							jj = r;
						}
					}
				}


				if(cnt1 == 2) {
					cnt += ans;
				}

			} 
		}
	}

	cout << cnt << '\n';

	return 0;
}