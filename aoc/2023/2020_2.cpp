#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

string str;
int cnt = 0;
int x;
vi nums;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	vi nums;

	int a, b;
	char _;

	while(cin >> a) {
		vi ccound(26, 0);
		cin >> _ >> b;
		char c;
		cin >> c >> _;

		cin >> str;

		--a;--b;

		cnt += (str[a]==c) ^ (str[b] == c);
	}

	cout << cnt << '\n';
	return 0;
}