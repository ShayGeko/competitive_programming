#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



vector<bool> visited;
vector<bool> processed;
int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int x, k;
    cin >> x >> k;


    if(x > k) {
        cout << x - k << '\n';
        return 0;
    }

    deque<int> dq;
    dq.push_back(x);
    dq.push_back(-1);

    int cnt = 0;
    int BOUND = 200000;

    visited = vector<bool>(BOUND + 1, false);
    processed= vector<bool>(BOUND + 1, false);


    visited[x] = true;
    while(dq.size() > 1) {
        auto v = dq.front();dq.pop_front();

        if(v == -1) {
            dq.push_back(-1);
            ++cnt;
            continue;
        }
        
        processed[v] = true;


        if(v == k) {
            cout << cnt << '\n';
            break;
        }
        
        if(2 * v <= BOUND && !processed[2*v]) {
            visited[2*v]=true;
            dq.push_front(2*v);
        }

        if(v <= BOUND && !visited[v+1]) {
            dq.push_back(v+1);
            visited[v+1]=true;
        }
        if(v > 0 && !visited[v-1]) {
            dq.push_back(v-1);
            visited[v-1]=true;
        }

    } 
	return 0;
}