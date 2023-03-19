#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;
vector<int> graph[maxn];
vector<int> top_sorted;
bool used[maxn];
int dp[maxn];
void dfs(int v){
    used[v] = true;

    for(auto to: graph[v]){
        if(!used[to]) dfs(to);
    }

    top_sorted.push_back(v);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    for(int i = 0; i < n; ++i){
        if(!used[i]) dfs(i);
    }
    reverse(top_sorted.begin(), top_sorted.end());
    for(auto v: top_sorted){
        for(auto to: graph[v]){
            dp[to] = max(dp[to], dp[v] + 1);
        }
    }
    int max = dp[0];

    for(int i = 0; i < n; ++i){
        if(dp[i] > max) max = dp[i];
    }

    cout <<   max << '\n';
    return 0;
}