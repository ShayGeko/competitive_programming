#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vi> adj(n);
  vi deg(n);
  vi vis(n);

  rep(i, 0, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++, deg[b]++;
  }

  queue<int> q;
  queue<pii> roots;
  vector<vi> child(n);

 // q has leaves in it
  rep(i, 0, n) {
    if (deg[i] == 1) {
      q.push(i);
    }
  }


  while (sz(q)) {
    auto z = q.front();
    q.pop();

    vis[z] = true;
    // degree is 0 when all other vertices were already popped
    // so roots is like "centroids"?
    if (deg[z] == 0) {
      roots.emplace(z, -1);
      continue;
    }

    for (auto x: adj[z]) {
      if (!vis[x]) {
        // right coz z is "outer" than x
        child[x].push_back(z);
        // oh I see
        if (--deg[x] == 1) {
          q.push(x);
        }
      }
    }
  }

  vector<pii> out;

  while (sz(roots)) {
    auto [z,p] = roots.front();
    roots.pop();

    for(auto x : adj[z]){
      if(sz(adj[x]) == 1){
        out.emplace_back(x, z);
      }

      if(x != p){
        roots.emplace(x,z);
      }
    }
  }

  rep(i, 0, n) {
    if (!vis[i]) {
      for (auto a: child[i]) {
        out.emplace_back(i, a);
      }
    }
  }
  
  sort(all(out));

  cout << sz(out) << endl;
  for (auto [a, b]: out) {
    cout << a + 1 << ' ' << b + 1 << '\n';
  }

  return 0;
}