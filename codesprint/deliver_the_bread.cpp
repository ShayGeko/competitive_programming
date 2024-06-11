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
	// cin.exceptions(cin.failbit);

	ll n, k, d, q;

	cin >> n >> k >> d >> q;

	vi D(n), K(n);

	for(auto &x : D) cin >> x;
	for(auto &x : K) cin >> x;

	int logK = log2(k) + 2;
	vector<vector<int>> Next(n, vi(logK));
	vector<vector<ll>> Dist(n, vector<ll>(logK));

	vector<vector<pair<int, int>>> D_by_k(k);

	rep(i, 0, n) {
		D_by_k[K[i]].push_back({D[i], i});
	}

	rep(i, 0, k) {
		sort(all(D_by_k[i]));
	}

	// Compute the base case of Next[0..n-1][0], Dist[0..n-1][0]

	auto get_next_dist_and_idx = [&](int bread, int pos) {
		auto& next_D = D_by_k[(bread+1)%k];
		// next customer can be at the current location, and no customer at prev location has idx > n
		auto it = upper_bound(all(next_D),pii{pos-1, n});

		// we get .end() if pos > all next_D, so reset the loop
		auto [next_pos, next_idx] =  it == next_D.end() ? (next_D[0]) : (*it);
		ll dist = (d + next_pos - pos) % d;

		return pair<ll, int>{dist, next_idx};
	};

	rep(i, 0, n) {
		int bread = K[i];
		int pos = D[i];

		auto [dist, next_idx] = get_next_dist_and_idx(bread, pos);
		assert(dist >= 0);
		Dist[i][0] = dist;
		Next[i][0] = next_idx;
	}

	// Bin lifting:

	rep(j, 1, logK) {
		rep(i, 0, n) {
			Dist[i][j] = Dist[i][j-1] + Dist[Next[i][0]][j-1];
			assert(Dist[i][j] >= 0);
			Next[i][j] = Next[Next[i][j-1]][j-1];
		}
	}




	rep(i, 0, q) {
		int pos, bread, q_k;
		cin >> pos >> bread >> q_k;

		if(!q_k) {
			cout << "0\n";
			continue;
		}

		// get location of first customer and dist to them
		auto [dist, cur] = get_next_dist_and_idx((k+bread-1)%k, pos);
		
		// cout << dist << " " << cur << '\n';
		assert(dist >= 0);
		unsigned long long tdist = dist;
		// cout << tdist << '\n';
		q_k--;
		
		int j = 0;
		while(q_k) {
			while(!(q_k & (1 << j))) ++j;

			tdist += Dist[cur][j];
			cur = Next[cur][j];
			// cout << tdist << " " << cur << '\n';
			q_k ^= (1<<j);
		}

		cout << tdist << '\n';
	}


	return 0;
}