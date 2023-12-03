#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


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
	ll aim = 0, d= 0, h = 0;
	while(cin >> str >> a) {
		if(str == "forward") {
			d += a;
			h += aim*a;
		} else if(str == "up") aim -=a;
		else aim+=a;
	}

	cout << d * h << '\n';
	return 0;
}