#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 2e5;
const int INF = 1e9;
vi graph[maxn];
int n;
bool used[maxn];
bool connected[maxn];
bool connected2[maxn];
int dfs(int v, int p, bool t){
    int ch = 1;
    connected[v] = true;
    if(t) used[v] = true;
    for(auto to : graph[v]){
        if(!used[to] && to != p) ch += dfs(to, v, !t);
    }

    return ch;
}
void norm_dfs(int v){
    connected[v] = true;
    
    for(auto to : graph[v]){
        if(!connected[to]) norm_dfs(to);
    }
}
bool check(int v){
    connected2[v] = true;
    if(!used[v]){
        return false;
    } 
    bool allHacked = true;
    for(auto to : graph[v]){
        if(!connected2[to]){
            allHacked &= check(to);
        }
    }

    return allHacked;
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
    int cnt = 0;
    int i = 0;
    while(dfs(i++, -1, true) == 1){++cnt;}
    
    bool full = check(i);
    if(!full) ++cnt;
    for(int i = 0; i < n; ++i){
        if(!connected[i]){
            ++cnt;
            dfs(i, -1, true);
            check(i);
        }
    }
    cout << cnt << '\n';
    return 0;
}