#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define has(a, b) (a.find(b) != a.end())
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

template <class T>
istream &operator >> (istream& is, pair<T, T> &p){
    is >> p.first >> p.second;
    return is;
}
template <class T>
ostream &operator << (ostream& os, pair<T, T> &p){
    os << p.first << " " << p.second;
    return os;
}
template <class T>
pair<T, T> operator + (pair<T,T> &a, pair<T,T> &b){
    return {a.first + b.first, a.second + b.second};
}

template <class T>
pair<T, T> operator - (pair<T,T> &a, pair<T,T> &b){
    return {a.first - b.first, a.second - b.second};
}

template<class T>
vector<T> operator+(const vector<T> &a, const vector<T> &b){
    assert(sz(a) == sz(b));

    vector<T> res(a);
    fora(i, sz(b)){
        res[i] += b[i];
    }

    return res;
}

const int maxn = 1e5;
//const int INF = 2e9;
const int p = 1e9+7;

#include <bits/extc++.h>

const int INF = numeric_limits<int>::max() / 4;
typedef vector<int> VL;


struct MCMF {
    int N;
    vector<vi> ed, red;
    vector<VL> cap, flow, cost;
    vi seen;
    VL dist, pi;
    vector<pii> par;

    MCMF(int N) :
            N(N), ed(N), red(N), cap(N, VL(N)), flow(cap), cost(cap),
            seen(N), dist(N), pi(N), par(N) {}

    void addEdge(int from, int to, int cap, int cost) {
        this->cap[from][to] = cap;
        this->cost[from][to] = cost;
        ed[from].push_back(to);
        red[to].push_back(from);
    }

    void path(int s) {
        fill(all(seen), 0);
        fill(all(dist), INF);
        dist[s] = 0; int di;

        __gnu_pbds::priority_queue<pair < int, int>> q;
        vector<decltype(q)::point_iterator> its(N);
        q.push({0, s});

        auto relax = [&](int i, int cap, int cost, int dir) {
            int val = di - pi[i] + cost;
            if (cap && val < dist[i]) {
                dist[i] = val;
                par[i] = {s, dir};
                if (its[i] == q.end()) its[i] = q.push({-dist[i], i});
                else q.modify(its[i], {-dist[i], i});
            }
        };

        while (!q.empty()) {
            s = q.top().second;
            q.pop();
            seen[s] = 1;
            di = dist[s] + pi[s];
            for (int i: ed[s])
                if (!seen[i])
                    relax(i, cap[s][i] - flow[s][i], cost[s][i], 1);
            for (int i: red[s])
                if (!seen[i])
                    relax(i, flow[i][s], -cost[i][s], 0);
        }
        rep(i, 0, N)
            pi[i] = min(pi[i] + dist[i], INF);
    }

    pair<int, int> maxflow(int s, int t) {
        int totflow = 0, totcost = 0;
        while (path(s), seen[t]) {
            int fl = INF;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                fl = min(fl, r ? cap[p][x] - flow[p][x] : flow[x][p]);
            totflow += fl;
            for (int p,r,x = t; tie(p,r) = par[x], x != s; x = p)
                if (r) flow[p][x] += fl;
                else flow[x][p] -= fl;
        }
        rep(i,0,N) rep(j,0,N) totcost += cost[i][j] * flow[i][j];
        return {totflow, totcost};
    }

    // If some costs can be negative
    void setpi(int s) { // (otherwise, leave this out)
        fill (all(pi), INF); pi[s] = 0;
        int it = N, ch = 1; int v;
        while(ch-- && it--)
            rep(i, 0, N) if(pi[i] != INF)
                    for(int to : ed[i]) if (cap[i][to])
                            if((v = pi[i] + cost[i][to]) < pi[to])
                                pi[to] = v, ch = 1;
        assert(it >= 0); // negative cost cycle
    }
};

void solve(int n){
    {string s;getline(cin, s);}
    vector<string> grid(5);
    rep(i, 0, 5) {
        getline(cin, grid[i]);
    }

    int N = 2*n*5 + 2;
    MCMF mcmf(N);
    int s = N - 2, t = N - 1;

    for(int i = 0; i < 5; ++i) {
        if (grid[i][0]=='@') {
            mcmf.addEdge(s, 2 * n * i, 1, 0);
        }
    }

    int cur_entrance, cur_exit;
    rep(i, 0, 5) {
        cur_entrance = i * 2*n;
        cur_exit = cur_entrance + 1;
        rep(j, 0, n) {
            if(j) {
                mcmf.addEdge(cur_entrance, cur_exit, 1, grid[i][j] - '0');
                // go left from cur
                mcmf.addEdge(cur_exit, cur_entrance - 2, 1, 0);
                // go right from prev
                mcmf.addEdge(cur_exit - 2, cur_entrance, 1, 0);
            } else mcmf.addEdge(cur_entrance, cur_exit, 1, 0);
            if(i) {
                // go up from cur
                mcmf.addEdge(cur_exit, cur_entrance - 2 * n, 1, 0);
                // go down from above
                mcmf.addEdge(cur_exit - 2*n, cur_entrance, 1, 0);
            }
            cur_entrance+=2;
            cur_exit+=2;
        }
    }
    cur_exit = 2*n - 1;
    rep(i, 0, 5) {
        mcmf.addEdge(cur_exit, t, 1, 0);
        cur_exit+=2*n;
    }


    auto ans = mcmf.maxflow(s, t);

    cout << ans.second << '\n';
}

int main(){
//    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

//     cin >> t;
    
    while(cin >> t && t > 0){
        solve(t);
    }
    cout.flush();
    
    return 0;
}

/*
27
@00100000000000102000000000
@00100000000000102111000000
000010000000011002110000000
@00011110000100002111000000
000000000011100002000000000
3
@10
@00
@00
000
000
12
024841026058
@03990540049
@01108404608
030789005500
@95750159143
0

 */