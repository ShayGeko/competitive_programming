#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n, t, a, b;
  cin >> m >> n >> a;
  vector<vector<bool>> isOn(m, vector<bool>(n, false));
  vector<vector<vector<pii>>> transitions(m, vector<vector<pii>>(n));
  vector<vector<int>> line(m);
  line.reserve(n);
  rep(i, 0, m) {
    int z, y;
    cin >> z;
    rep(i, 0, z) {
      cin >> y;
      isOn[z][y] = true;
      line[z].push_back(y);
    }
  }

  rep(i, 0, m){
    rep(j, 0, n){
        
    }
  }

  vi::iterator p[n][100];
  rep(i, 0, n) {
    rep(j, 0, 100) p[i][j] = lines[i].end();

    auto it = lines[i].begin();
    rep(j, 0, sz(lines[i])) { p[i][lines[i][j]] = it++; }
  }

  cin >> t;
  while (t--) {
    cin >> b;

    
  }

  return 0;
}