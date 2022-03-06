#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;


vi graph[maxn];
int p[maxn];

void dfs(int v){

    for(auto to : graph[v]){
        if(to != p[v]){
            p[to] = v;
            dfs(to);
        }
    }
}

bool are_close(int v, int u){
    int cur = p[v];
    unordered_map<int, int> dist; 
    for(int i = 1; i <= 3 && cur != -1; ++i) {
        dist[cur] = i;
        if(cur == u) return true;
        cur = p[cur];
    }

    cur = p[u];
    for(int i = 1; i <= 3 && cur != -1; ++i) {
        if(cur == v) return true;

        if(dist.find(cur) != dist.end()){
            int t = dist[cur];
            if(t + i <= 3) return true;
            else return false;
        }

        cur = p[cur];
    }

    return false;
}

void solve(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        graph[i].clear();
    }
    vi perm(n);
    int a,b;
    for(int i = 0; i < n - 1; ++i){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i = 0; i < n; ++i) cin >> perm[i];

    p[0] = -1;
    dfs(0);

    for(int i = 0; i < n - 1; ++i){
        if(!are_close(perm[i] - 1, perm[i + 1] - 1)){
            cout << "0\n";
            return;
        }
    }

    cout << "1\n";

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