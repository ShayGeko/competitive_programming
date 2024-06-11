#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct PushRelabel {
    struct Edge {
        int dest, back;
        ll f, c;
    };
    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge*> cur;
    vector<vi> hs;
    vi H;
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
    void addEdge(int s, int t, ll cap, ll rcap = 0) {
        if (s == t) return;
        g[s].push_back({t, sz(g[t]), 0, cap});
        g[t].push_back({s, sz(g[s]) - 1, 0, rcap});
    }
    void addFlow(Edge& e, ll f) {
        Edge& back = g[e.dest][e.back];
        if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
        e.f += f;
        e.c -= f;
        ec[e.dest] += f;
        back.f -= f;
        back.c += f;
        ec[back.dest] -= f;
    }
    ll calc(int s, int t) {
        int v = sz(g);
        H[s] = v;
        ec[t] = 1;
        vi co(2 * v);
        co[0] = v - 1;
        rep(i, 0, v) cur[i] = g[i].data();
        for (Edge& e : g[s]) addFlow(e, e.c);
        for (int hi = 0;;) {
            while (hs[hi].empty())
                if (!hi--) return -ec[s];
            int u = hs[hi].back();
            hs[hi].pop_back();
            while (ec[u] > 0)  // discharge u
                if (cur[u] == g[u].data() + sz(g[u])) {
                    H[u] = 1e9;
                    for (Edge& e : g[u])
                        if (e.c && H[u] > H[e.dest] + 1)
                            H[u] = H[e.dest] + 1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        rep(i, 0, v) if (hi < H[i] && H[i] < v)-- co[H[i]],
                            H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1)
                    addFlow(*cur[u], min(ec[u], cur[u]->c));
                else
                    ++cur[u];
        }
    }
    bool leftOfMinCut(int a) { return H[a] >= sz(g); }
};


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int g,c, t;
	cin >> g >> c >> t;

	vi cakes(c), ingr(g), tools(t);
	for(auto &x : cakes) cin >> x;
	for(auto &x : ingr) cin >> x;
	for(auto &x : tools) cin >> x;

	// remove cost of ingredients from cake profit
	rep(i, 0, c) {
		rep(j, 0, g) {
			int x;
			cin >> x;
			cakes[i] -= x * ingr[j];
		}
	}

	PushRelabel pr(2 + c + t);
	int source = c + t, sink = c + t + 1;

	rep(i, 0, c) {
		pr.addEdge(source, i, cakes[i]);
	}
	rep(i, 0, t) {
		pr.addEdge(i + c, sink, tools[i]);
	}

	constexpr int INF = INT_MAX;
	rep(i, 0, c) {
		int k;
		cin >> k;
		rep(j, 0, k) {
			int x;
			cin >> x; x--;
			pr.addEdge(i, c + x, INF);
		}
	}

	auto flow = pr.calc(source, sink);

	ll ans = 0;
	rep(i, 0, c) {
		if (pr.leftOfMinCut(i)) {
			ans += cakes[i];
			// cout << i  << " left\n";
		} else {
			// cout << i + c << " right\n";
		}
	}
	rep(i, 0, t) {
		if(pr.leftOfMinCut(i+c)) {
			// cout << i + c << " left\n";
			ans -= tools[i];
		} else {
			// cout << i + c << " right\n";
		}
	}

	cout << ans << '\n';


	return 0;
}