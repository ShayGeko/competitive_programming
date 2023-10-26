#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef int T;
struct AllPathsDijkstra {
    const T INF = 1e9+1;
    const vector<vector<pair<int, T>>> &adjList;
    vector<pair<T, vector<T>>> dpar;
    int s, t, n;
    AllPathsDijkstra(const vector<vector<pair<int, T>>> &adjList, int s,
                     int t = -1)
        : adjList(adjList), s(s), t(t), n(adjList.size()) {
        dpar = vector<pair<T, vector<T>>>(adjList.size(), {INF, {}});
    }
    vector<pair<T, vector<T>>> &compute() {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
        dpar[s].first = 0;
        pq.emplace(0, s);
        while (!pq.empty()) {
            auto [v,d] = pq.top(); pq.pop();
            if (v == t) break;
            // if cur is worse than  
            if (d > dpar[v].first) continue;
            for (auto [to, cost] : adjList[v]) {
                T newdist = d + cost;
                if (dpar[to].first > newdist) {
                    dpar[to] = {newdist, {v}};
                    pq.emplace(newdist, to);
                } else if (dpar[to].first == newdist)
                    dpar[to].second.push_back(v);
            }
        }
        return dpar;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n, m, k;
    cin >> n >> m >> k;
    vi path(k);
    for (auto &x : path) {
        cin >> x;
        x--;
    }
    vector<vector<pii>> adjList(n);
    rep(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adjList[a].emplace_back(b, c);
        adjList[b].emplace_back(a, c);
    }

    // Am I going crazy
    AllPathsDijkstra apd(adjList, 0, n - 1);
    auto &dpar = apd.compute();

    bool found = false;
    for (auto &x : path) {
        found = found || (dpar[x].second.size() > 1);
    }
    cout << (found ? "yes" : "no") << endl;

    return 0;
}