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
const int INF = 2e9;
const int p = 1e9+7;

vector<vpii> graph;
vi d;
vector<vpii> parents;

void dijkstra(int s){
    priority_queue<pii, vpii, less<pii>> pkue;

    pkue.push({0, s});

    while(!pkue.empty()){
        auto [dist, v] = pkue.top();pkue.pop();
        if(dist > d[v]) continue;

        for(auto [to, cost]: graph[v]){
            if(d[to] > dist + cost){
                d[to] = dist + cost;
                pkue.push({d[to], to});
                parents[to].clear();
                parents[to].push_back({v, cost});
            }
            else if(d[to] == dist + cost){
                parents[to].push_back({v, cost});
            }
        }
    }
}
set<tuple<int,int,int>> inclRoads;
void computeInclRoads(int v){
    for(auto &[pr, cost] : parents[v]){
        inclRoads.insert({pr,v, cost});
        computeInclRoads(pr);
    }
    
}
void solve(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--;t--;
    graph.resize(n);
    d = vi(n, INF);
    parents.resize(n);

    d[s] = 0;

    int a, b,c;
    int tsum = 0;
    rep(i, 0, m){
        cin >> a >> b >> c;
        a--;b--;
        graph[a].emplace_back(b,c);
        graph[b].emplace_back(a,c);
        tsum += c;
    }

    dijkstra(s);
    computeInclRoads(t);
    int sum = 0;
    for(auto &[v, to, len] : inclRoads){
        sum += len;
    }
    
    cout << tsum - sum << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}