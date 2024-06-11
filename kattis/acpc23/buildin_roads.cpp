#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct DSU {
    vi p;
    vi d;
    DSU(int n) : p(vi(n)), d(vi(n, 1)) {
        rep(i, 0, n) p[i] = i;
    };

    int find(int a) {
        return (p[a] == a) ? a : p[a] = find(p[a]);
    }
    void unite (int a, int b) {
        auto ra = find(a), rb = find(b);

        if(d[ra] < d[rb]) swap(ra, rb);
        d[ra] += d[rb];
        p[rb] = ra;
    };
};

typedef long double d; // for N ~ 1e7; long double for N ~ 1e9
pair<ll, ll> approximate(d x, ll N) {
    ll LP = 0, LQ = 1, P = 1, Q = 0, inf = LLONG_MAX; d y = x;
    for (;;) {
        ll lim = min(P ? (N-LP) / P : inf, Q ? (N-LQ) / Q : inf),
                a = (ll)floor(y), b = min(a, lim),
                NP = b*P + LP, NQ = b*Q + LQ;
        if (a > b) {
            // If b > a/2, we have a semi-convergent that gives us a
            // better approximation; if b = a/2, we *may* have one.
            // Return {P, Q} here for a more canonical approximation.
            return (abs(x - (d)NP / (d)NQ) < abs(x - (d)P / (d)Q)) ?
                   make_pair(NP, NQ) : make_pair(P, Q);
        }
        if (abs(y = 1/(y - (d)a)) > 3*N) {
            return {NP, NQ};
        }
        LP = P; P = NP;
        LQ = Q; Q = NQ;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    // [from] -> to pitch gravel
    vector<vi> edges;

    ll sum = 1;
    rep(i, 0, m) {
        int a, b, p, g;
        cin >> a >> b >> p >> g;

        --a;--b;
        sum += p + g;
        edges.push_back({a, b, p, g});
    }

    // bin search on min possible P/G
    // set edges to be p_i _ g_i * P/G
    // sum p_i / g_i = P/G, so sum pi / (g_i * P/G) = 1
    // meaning sum pi - g_i * (P/G) = 0
    // bigger ratio -> negative value, smaller - positive
    d l = 0, r = sum;

    d delta = min((d)1e-19, 1. / (d) sum / 10.);

    vector<tuple<d, int, int>> kruEdge(sz(edges));

    DSU dsu(n);
    int i = 0;
    while(r - l > delta && i < 400) {
        ++i;
        d x = (l + r) / (d)2.;


        rep(i, 0, sz(edges)) {
            auto& edge = edges[i];
            kruEdge[i] = {(d)edge[2]-x*edge[3], edge[0], edge[1]};
        }
        rep(i, 0, n) {
            dsu.p[i] = i;
            dsu.d[i] = 1;
        }
        sort(all(kruEdge));
        d tcost = 0;
        for(auto &[cost, u, v] : kruEdge) {
            if(dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                tcost += cost;
            }
        }

        if(tcost < -delta) {
            r = x;
        } else if(tcost <= delta && tcost >= -delta) {
            l = x;
            r=x;
            break;
        }
        else l = x;
    }

    auto [a, b] = approximate(l, n*1e5);

    ll gc = gcd(a, b);
    a/=gc;
    b/=gc;

    cout << a << "/" << b << '\n';

    return 0;
}