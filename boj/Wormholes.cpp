#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



const ll inf = LLONG_MAX;
struct Ed { int a, b, w; int s() { return a < b ? a : -a; }};
struct Node {ll dist = inf; int prev= -1;};

bool bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
    nodes[s].dist = 0;
    int n = sz(nodes);
    bool hasCycle = false;

    rep(i, 0, n) {
        hasCycle = false;
        for (Ed ed : eds) {
            Node &cur = nodes[ed.a], &dest = nodes[ed.b];
            if (cur.dist == inf) continue;
            ll d = cur.dist + ed.w;
            if (d < dest.dist) {
                dest.prev = ed.a;
                dest.dist = d;
                hasCycle = true;
                if (i == n - 1) {
                    return true; // Negative cycle detected
                }
            }
        }
    }

    return false;  // No negative cycles
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t;
    cin >> t;

    while(t--) {
        int n, m, w;
        cin >> n >> m >> w;

        vector<Node> nodes(n);
        vector<Ed> eds;
        eds.reserve(2*m + w);
        vector<Ed> wormholes(w);

        rep(i, 0, m) {
            int a, b, c;
            cin >> a >> b >> c;
            --a;--b;
            eds.push_back({a, b, c});
            eds.push_back({b, a, c});
        }

        rep(i, 0, w) {
            int a, b, c;
            cin >> a >> b >> c;
            --a;--b;
            eds.push_back({a, b, -c});
        }

        bool hasNegCycle = false;

        rep(i, 0, n) {
            if(nodes[i].dist == inf) {
                if(hasNegCycle = bellmanFord(nodes, eds, i))
                    break;
            }
        }

        cout << (hasNegCycle ? "YES" : "NO") << '\n';
    }
	return 0;
}