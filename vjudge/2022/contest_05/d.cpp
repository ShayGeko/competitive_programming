#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream& operator>> (istream& is, pii& p){
    int a, b;
    is >> a >> b;
    p = {a, b};

    return is;
}
const int maxn = 1e5;
const int INF = 1e9;

vi d;
vector<bool> used;
int dfs(vvi &graph, int v){
    if(used[v]) return d[v];
    used[v] = true;
    int maxi = 0;
    for(auto to : graph[v]){
        maxi = max(dfs(graph, to), maxi);
    }

    return d[v] = maxi + 1;
}
void solve(){
    int n;
    cin >> n;
    unordered_map<int, int> p;

    vvi graph(n + 1);
    
    int k;
    int resource;
    for(int i = 1; i <= n; ++i){
        cin >> k;
        // read
        for(int j = 0; j < k - 1; ++j){
            cin >> resource;
            if(p[resource] > 0){
                graph[i].push_back(p[resource]);
            }
        }
        // write
        cin >> resource;
        p[resource] = i;
    }
    used = vector<bool> (n+1, false);
    int maxi = 0;
    d.clear();
    d.resize(n+1, 0);
    for(int i = n; i > 0; i--){
        if(!used[i]) maxi = max(maxi, dfs(graph, i));
    }

    cout << maxi << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    for(int i = 1; i <= t; ++i){
        cout << i << " ";
        solve();
    }
    return 0;
}