#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



void solve() {
	int n;
    cin >> n;

    vector<vi> adj(n);
    rep(i, 1, n) {
        int x;
        cin >> x;
        x--;
        adj[x].push_back(i);
    }

    vi layers;

    queue<int> q;
    q.push(0);
    q.push(-1);
    layers.push_back(0);
    while(q.size() > 1) {
        auto v = q.front();q.pop();
        if(v == -1) {
            layers.push_back(0);
            q.push(-1);
            continue;
        }
        ++layers.back();

        for(auto to : adj[v]) q.push(to);
    }

    ll ans = 0;

    int leftover = 0;
    for(int i = sz(layers)-1; i>=0; i--) {
        if(layers[i] > 1) {
            int k = layers[i];
            layers[i] += min(layers[i]-1, leftover);
            leftover = max(0, leftover - k + 1);
        }
        ans += layers[i] / 2;
        leftover += layers[i] % 2;
    }

    cout << ans << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}