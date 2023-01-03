#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

int n;
ll dfs(vvi &graph, int v, int mask){
    mask = mask | (1 << v);
    if(mask == (1 << n) - 1){
         if(graph[v][0]) return 1;
         else return 0;
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        if(graph[v][i] && !(mask & (1 << i))){
            ans = (ans + dfs(graph, i, mask));
        }
    }

    return ans;
}
void solve(){
    int k;
    cin >> n >> k;

    vi temp(n, 1);
    vvi graph(n, temp);

    for(int i = 0; i < k; ++i){
        int a,b;
        cin >> a >> b;
        graph[a-1][b-1] = 0;
        graph[b-1][a-1] = 0;
    }
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < n; ++j){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    ll ans = dfs(graph, 0, 1);


    cout << (ans / 2) % 9901  << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    
    for(int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}