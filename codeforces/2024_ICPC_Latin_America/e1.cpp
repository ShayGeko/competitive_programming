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
 
	int n;
	cin >> n;
 
	vector<array<int, 2>> events(n);
	rep(i, 0, 2*n) {
		char c; int x;
		cin >> c >> x;
 
		events[x-1][c != '+'] = i;
	}
 
	vector<vi> notCompatible(n);
	rep(i, 0, n) {
		rep(j, i+1, n) {
			auto [a1, a2] = events[i];
			auto [b1, b2] = events[j];
 
			if((a1 < b1 && b2 < a2) || (b1 < a1 && a2 < b2) || a1 > b2 || b1 > a2) {
			} else {
				notCompatible[i].push_back(j);
				notCompatible[j].push_back(i);
			}
		}
	}
 
	vector<bool> isCompatible(n, true);
	vector<bool> isA(n, true);
	rep(i, 0, n) {
		if(isCompatible[i]) {
			for(auto x : notCompatible[i]) {
				isCompatible[x] = false;
				
				// only time isA[x] is true when x is incompatible with i
				// is if x was not yet processed. O.w. i would not be compatible
				if(isA[x]) {
					isA[x] = false;
 
					for (auto y : notCompatible[x]) {
						if(!isA[y]) {
							cout << "*\n";
							return 0;
						}
					}
				}
			}
		} else {
			for(auto x : notCompatible[i]) {
				if(!isA[x]) {
					cout << "*\n";
					return 0;
				}
			}
		}
	}
 
	rep(i, 0, n) {
		if(isA[i]) cout << "G";
		else cout << "S";
	}
	cout << '\n';
 
 
	return 0;
}

/*

5
+1 +2 -1 +3 -2 +4 -3 -4 +5 -5


5
+1 + 2 +3 +4 +5 -4 -5 -2 -3 -1
*/