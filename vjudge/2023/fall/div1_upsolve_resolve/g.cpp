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
	vi d(n);
	vector<vi> t(3, vi(n));
	rep(i, 0, n) cin >> d[i];
	rep(i, 0, 3) rep(j, 0, n) cin >> t[i][j];

	// 0 collides with 1 if starts at i and j
	vector<vector<vector<vector<bool>>>> collides(3, 
		vector<vector<vector<bool>>>(3,
		  vector<vector<bool>>(n,
		  	 vector<bool>(n, false))));
	// pre-compute collisions for each pair
	
	rep(a, 0, 3) {
		rep(b, 0, 3) {
			if(a == b) continue;
			
			vi prsum1(n), prsum2(n);


			rep(i, 0, n) {
				vi ttget1(n), ttleave1(n);

				ttget1[i] = 0;
				ttleave1[i] = t[a][i];
				rep(k, i+1, n) {
					ttget1[k] = ttleave1[k-1] + d[k-1];
					ttleave1[k] = ttget1[k] + t[a][k];
				}
				rep(k, 0, i) {
					ttget1[k] = ttleave1[(n+k-1)%n] + d[(n+k-1)%n];
					ttleave1[k] = ttget1[k] + t[a][k];
				}
				rep(j, i + 1, n) {
					vi ttget2(n), ttleave2(n);

					ttget2[j] = 0;
					ttleave2[j] = t[b][j];
					rep(k, j+1, n) {
						ttget2[k] = ttleave2[k-1] + d[k-1];
						ttleave2[k] = ttget2[k] + t[b][k];
					}
					rep(k, 0, j) {
						ttget2[k] = ttleave2[(n+k-1)%n] + d[(n+k-1)%n];
						ttleave2[k] = ttget2[k] + t[b][k];
					}

					// check if a collides with b:
					rep(k, i, n + i) {
						if (ttget1[k%n] >= ttget2[k%n] && ttget1[k%n] < ttleave2[k%n]) {
							collides[a][b][i][j]=true;
							collides[b][a][j][i]=true;
							break;
						}
					}
					if(collides[a][b][i][j]) continue;
					// check if b collides with a
					rep(k, j, n + j) {
						if (ttget2[k%n] >= ttget1[k%n] && ttget2[k%n] < ttleave1[k%n]) {
							collides[a][b][i][j]=true;
							collides[b][a][j][i]=true;
							break;
						}
					}
				}
			}

		}
	}

	// for each i, j, k figure out in O(1) if this works

	rep(i, 0, n) {
		rep(j, 0, n) {
			if(i == j) continue;
			rep(k, 0, n) {
				if(i == k || j == k) continue;

				if(!collides[0][1][i][j] && !collides[1][2][j][k] && !collides[2][0][k][i]) {
                    cout << i+1 << " " << j + 1 << " " << k + 1 << '\n';
                    return 0;
                }
			}
		}
	}
	cout << "impossible\n";
	return 0;
}