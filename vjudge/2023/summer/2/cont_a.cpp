#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

long double EPS = 1E-6;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, salt, sweet;
  cin >> n;

  vector<pii> t(n); // salt, sweet
  for (auto &&x : t)
    cin >> x.first;
  for (auto &&x : t)
    cin >> x.second;

  cin >> salt >> sweet;

  // check singles
  rep(i, 0, n) {
    if (t[i].first == salt && t[i].second == sweet) {
      cout << "Yes" << endl;
      rep(k, 0, i) cout << 0 << ' ';
      cout << 1 << ' ';
      rep(k, i + 1, n) cout << 0 << ' ';
      return 0;
    }
  }

  // check every pair
  rep(i, 0, n) {
    rep(j, i + 1, n) {
      long double m1, m2;
      if (t[i].first == t[j].first) {
        m1 = m2 =
            (sweet - t[j].second) / (long double)(t[i].second - t[j].second);
      } else if (t[i].second == t[j].second) {
        m1 = m2 = (salt - t[j].first) / (long double)(t[i].first - t[j].first);
      } else {
        m1 = (salt - t[j].first) / (long double)(t[i].first - t[j].first);
        m2 = (sweet - t[j].second) / (long double)(t[i].second - t[j].second);
      }
      if (m1 < 0 || m1 > 1 || m2 < 0 || m2 > 1)
        continue;

      long double avg = (m1 + m2) / 2;

      long double sa = avg * t[i].first + (1 - avg) * t[j].first;
      long double sw = avg * t[i].second + (1 - avg) * t[j].second;
      if (abs(sa - salt) <= EPS * salt) {
        if (abs(sw - sweet) <= EPS * sweet) {
          cout << "Yes" << endl;
          cout << fixed << setprecision(15);

          rep(k, 0, i) cout << 0 << ' ';
          cout << avg << ' ';
          rep(k, i + 1, j) cout << 0 << ' ';
          cout << 1 - avg << ' ';
          rep(k, j + 1, n) cout << 0 << ' ';

          return 0;
        }
      }
    }
  }

  cout << "No";
}