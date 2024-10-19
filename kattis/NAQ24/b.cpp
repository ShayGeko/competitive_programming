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

	vector<pair<pii, pii>> bar(n);
	rep(i, 0, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >>y2;

		pii a = {x1, y1};
		pii b = {x2, y2};
		if(x1 > x2) swap(a, b);
		bar[i] = {a, b};
	}

	vector<double> intersections;
	for(auto [a, b] : bar) {
		auto [x1, y1] = a;
		auto [x2, y2] = b;

		if (x1 <= 0 && x2 >= 0) {
			// (x2 - x1), (y2 - y1)
			pii c = {x2 - x1, y2 -y1};
			// a + t * c, x = 0
			// x1 + (x2 - x1) * t = 0
			// t = x1 / (x1 - x2)
			// y = y1 + (y2 - t1) * x1 / (x1 - x2);

			double intersect = y1 + (double) (y2 - y1) * x1 / ((double) x1 - x2);

			if(intersect > 0) intersections.push_back(intersect);
		}
	}

	sort(all(intersections));
	
	if(sz(intersections)) cout << fixed << setprecision(10) <<  intersections[0] << '\n';
	else cout << "-1.0" << '\n';


	return 0;
}