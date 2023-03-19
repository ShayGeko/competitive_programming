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
    
    int m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a - 1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    dfs(0);
    bool connected = true;;
    for(int i = 0; i < n; ++i){
        if(!used[i]){
            connected = false;
            cout << i + 1 << '\n';
        }
    }
    if(connected) cout << "Connected\n";
    
    return 0;
}