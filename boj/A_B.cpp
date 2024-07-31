#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    ll a, b;
    cin >> a >> b;

    queue<ll> q;

    q.push(a);
    q.push(-1);

    map<ll, bool> visited;
    visited[a] = true;
    int cnt = 1;
    while(q.size() > 1) {
        ll v = q.front();q.pop();

        // cout << v << '\n';
        if(v == b) {
            cout << cnt << '\n';
            return 0;
        }
        if(v == -1) {
            q.push(-1);
            ++cnt;
            continue;
        }

        ll A = v * 2;
        ll B = v * 10 + 1;

        if(A <= b && !visited[A]) q.push(A);
        if(B <= b && !visited[B]) q.push(B);
    }

    cout << -1 << '\n';


	return 0;
}