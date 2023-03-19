#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

typedef struct {
    int a;
    int b; 
    int weight;
} edge;
istream &operator >> (istream& is, edge &e){
    cin >> e.a >> e.b >> e.weight;
    return is;
}

vi parent;
vi sz;

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}
int find(int v){
    if(parent[v] == v) return v;

    return parent[v] = find(parent[v]);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}
void solve(){
    int m, c;
    cin >> m >> c;
    int n = c * (c-1) / 2;
    vector<edge> edges(n);

    parent.resize(c);
    sz.resize(c);
    for(int i = 0; i < c; ++i){
        make_set(i);
    }

    for(int i = 0; i < n; ++i){
        cin >> edges[i];
    }

    sort(edges.begin(), edges.end(), 
        [](edge &a, edge&b){return a.weight < b.weight;});


    vector<edge> msp;
    for(auto e : edges){
        if(find(e.a) != find(e.b)){
            msp.push_back(e);
            unite(e.a, e.b);
        }
    }

    int needed = c;

    for(auto e : msp) needed += e.weight;

    if(needed <= m) cout << "yes\n";
    else cout << "no\n";
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}