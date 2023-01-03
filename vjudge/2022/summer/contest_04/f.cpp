#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 2e5;
const int INF = 1e9;
vi graph[maxn];
int n;
bool used[maxn];
void dfs(int v){
    used[v] = true;
    for(auto to : graph[v]){
        if(!used[to]) dfs(to);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int sum = 0;
        vector<bool> used(n);
        int a, b, c;
        for(int i = 0; i < m; ++i){
            cin >> a >> b >> c;
            used[b-1] = true;
        }
        int i = 0;
        while(used[i]) ++i;
        ++i;
        for(int j = 1; j <= n; ++j){
            if(j == i) continue;
            cout << i << " " << j << '\n';
        }
    }
    return 0;
}