#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	/*
		 1  2  9 10 25 26
		 4  3  8 11 24 27
		 5  6  7 12 23 28
		16 15 14 13 22 29
		17 18 19 20 21 30
		36 35 34 33 32 31
	*/

	int t;
	cin >> t;
	while(t--) {
		int x, y;
		cin >> y >> x;
		ll product = x * y;
		ll wave = max(x, y);
		ll sq = wave * wave;
		
		ll start = (wave-1)*(wave-1) + 1;

		// cout << wave << " " << sq << " " << start << '\n';
		if(wave % 2 == 0) { // counter clockwise
			swap(x, y);			
		}

		if(y == wave) {
			cout << start + x - 1<< '\n';
		} else {
			cout << start + wave - 1 + (wave - y) << '\n';
		}
		// cout << "--------------\n";
	}
	return 0;
}