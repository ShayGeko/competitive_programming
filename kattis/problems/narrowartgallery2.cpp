#include <bits/stdc++.h>

using namespace std;


#define rep(i, a, b) for(int i = 0; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pii, vi> memo;
vi calc(int balls, bool turn) {
  if(balls < 0) return {0, 0};

  pii k = {balls, turn};
  if(memo.find(k) != memo.end())  {
    return memo[k];
  }
  vi ans = {0, 0};
  auto a = calc(balls-1, !turn);
  a[turn]++;
  if(a[turn] > ans[turn]) ans = a;
  if(balls % 2 == 0) {
    auto b = calc(balls / 2, !turn);
    b[turn] += balls / 2;
    if (b[turn] > ans[turn]) ans = b;
  }
  if(balls % 3 == 0) {
    auto c =calc(balls - 2, !turn);
    c[turn] += 2;
    if(c[turn] > ans[turn]) ans = c;
  }
  if(balls % 5 == 0) {
    auto d = calc(balls - 3, !turn);
    d[turn] += 3;
    if(d[turn] > ans[turn]) ans = d;
  }

  return memo[k] = ans;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;

    auto ans = calc(n, false);
    assert(ans.size() == 2);
    cout << ans[0]+15 << " " << ans[1]+15 << '\n';
}