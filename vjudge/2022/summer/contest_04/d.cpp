#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 2e5;
const int INF = 1e9;
vi graph[maxn];
int n;
bool used[maxn];
int bfs(queue<int> q){
    int cnt = 1;
    int cur;
    while(q.size() > 1){
        cur = q.front();
        q.pop();
        if(cur == -1){
            ++cnt;
            q.push(-1);
        }
        else{
            used[cur] = true;
            for(auto to : graph[cur]){
                if(!used[to]) q.push(to);
            }
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin >> n;
    queue<int> q;
    int p;
    for(int i = 0; i < n; ++i){
        cin >> p;
        if(p == -1){
            q.push(i);
        }
        else{
            graph[p - 1].push_back(i);
        }
    }
    q.push(-1);

    cout << bfs(q) << '\n';
    
    return 0;
}