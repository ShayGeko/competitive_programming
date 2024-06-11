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

struct Edge
{
    int from, to, capacity, cost;
};

vector<vector<int>> adj, cost, capacity;

const int INF = 1e9;

void shortest_paths(int n, int v0, vector<int>& d, vector<int>& p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int v : adj[u]) {
            if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
        cost[e.from][e.to] = e.cost;
        cost[e.to][e.from] = -e.cost;
        capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int cost = 0;
    vector<int> d, p;
    while (flow < K) {
        shortest_paths(N, s, d, p);
        if (d[t] == INF)
            break;

        // find max flow on that path
        int f = K - flow;
        int cur = t;
        while (cur != s) {
            f = min(f, capacity[p[cur]][cur]);
            cur = p[cur];
        }

        // apply flow
        flow += f;
        cost += f * d[t];
        cur = t;
        while (cur != s) {
            capacity[p[cur]][cur] -= f;
            capacity[cur][p[cur]] += f;
            cur = p[cur];
        }
    }

    if (flow < K)
        return -1;
    else
        return cost;
}

void solve(int n){
    {string s;getline(cin, s);}
    vector<string> grid(5);
    rep(i, 0, 5) {
        getline(cin, grid[i]);
    }

    int N = 2*n*5 + 2;
    int s = N - 2, t = N - 1;

    vector<Edge> edges;
    int K = 0;
    for(int i = 0; i < 5; ++i) {
        if (grid[i][0]=='@') {
            ++K;
            edges.push_back({s, 2 * n * i, 1, 0});
        }
    }

    int cur_entrance, cur_exit;
    rep(i, 0, 5) {
        cur_entrance = i * 2*n;
        cur_exit = cur_entrance + 1;
        rep(j, 0, n) {
            if(j) {
                edges.push_back({cur_entrance, cur_exit, 1, grid[i][j] - '0'});
                // go left from cur
                edges.push_back({cur_exit, cur_entrance - 2, 1, 0});
                // go right from prev
                edges.push_back({cur_exit - 2, cur_entrance, 1, 0});
            } else edges.push_back({cur_entrance, cur_exit, 1, 0});
            if(i) {
                // go up from cur
                edges.push_back({cur_exit, cur_entrance - 2 * n, 1, 0});
                // go down from above
                edges.push_back({cur_exit - 2*n, cur_entrance, 1, 0});
            }
            cur_entrance+=2;
            cur_exit+=2;
        }
    }
    cur_exit = 2*n - 1;
    rep(i, 0, 5) {
        edges.push_back({cur_exit, t, 1, 0});
        cur_exit+=2*n;
    }


    auto ans = min_cost_flow(N, edges, K, s, t);

    cout << ans << '\n';
}

int main(){
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
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