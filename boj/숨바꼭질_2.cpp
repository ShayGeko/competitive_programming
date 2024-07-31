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

    int n, k;
    cin >> n >> k;

    vi dp(n+k+1, 0);
    vector<bool> vis(n+k+1, false);
    vi level(n+k+1, 1e9);
    level[n] = 0;
    vis[n] = true;
    
    dp[n] = 1;


    queue<int> q;
    q.push(n);
    int cnt = 0;
    while(q.size()) {
        auto v = q.front();q.pop();

        if(v == k) {
            cout << level[v] << "\n" << dp[v] << '\n';
            break;
        }

        auto process = [&](int to) {
            if(!vis[to]) {
                vis[to]=true;
                level[to] = level[v]+1;
                dp[to] = dp[v];
                q.push(to);
            } else if(level[to] > level[v]) {
                dp[to] += dp[v];
            } 
        };
        if(v < k) process(v+1);
        if (2 * v <= n + k) process(2*v);
        if(v > 0) process(v-1);
    }


	return 0;
}