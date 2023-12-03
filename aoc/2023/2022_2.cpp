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

	char a, b;


	// Y > A, Z > B, X > C
	while(true) {
		getline(cin, str);
		if(str == "" )break;
		char a = str[0], b = str[2];
		a-='A', b -='X';

		if(b == 1) cnt += 3 + a + 1;
		else if(b == 2) cnt += 6 + (a + 1) % 3 + 1;
		else cnt += (3 + a - 1) % 3 + 1;
	}

	cout << cnt << '\n';

	return 0;
}