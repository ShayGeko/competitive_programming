#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;

vi ord;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vi coin(n), time(n);
  ord.resize(n);
  for (auto &&x : coin)
    cin >> x;
  for (auto &&x : time)
    cin >> x;
  for (auto &&x : ord)
    cin >> x;

  sort(all(coin), [](int x, int y) { return ord[x] < ord[y]; });

  if (n == 1) {
    cout << fixed << setprecision(6) << 0.5 << endl << 1;
  } else if (n == 2 && coin[0] == coin[1]) {
    cout << fixed << setprecision(6) << 0.25 << endl << ord[0] << ' ' << ord[1];
  } else {
    if ((ll)coin[0] < accumulate(coin.begin() + 1, coin.end(), 0LL)) {
      cout << fixed << setprecision(6) << 1 << endl;
      rep(i, 1, n) cout << ord[i] << ' ';
      cout << ord[0];
    } else if ((ll)coin[0] == accumulate(coin.begin() + 1, coin.end(), 0LL)) {
      cout <<  fixed << setprecision(6) << 0.5 << endl;
      cout << ord[0] << ' ';
      rep(i, 2, n) cout << ord[i] << ' ';
      cout << ord[1];
    } else if ((ll)coin[0] > accumulate(coin.begin() + 1, coin.end(), 0LL)) {
      cout << fixed << setprecision(6) <<  0.5 << endl;
      rep(i, 0, n) cout << ord[i] << ' ';
    }
  }

  return 0;
}