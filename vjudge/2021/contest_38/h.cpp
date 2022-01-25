#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
const int INF = 1e9;

typedef struct{
    int to;
    int cost;
} road;

int items[maxn];
int n, m;

vector<road> roads[maxn];
pair<int, int> dp[maxn];
int p[maxn];

void dijkstra(){
    priority_queue<pair<int,int>> q;
    dp[0].first = 0;
    dp[0].second = items[0];

    for(int i = 1; i < n; ++i) {
        dp[i].first = INF;
        dp[i].second = items[i];
    }

    q.push({0, 0});

    for(int i = 1; i < n; ++i)
    while(!q.empty()){
        pair<int, int> v = q.top(); q.pop();
        v.first = -v.first;
        if(v.first > dp[v.second].first) continue;

        for(auto r : roads[v.second]){
            if(dp[r.to].first > dp[v.second].first + r.cost){
                dp[r.to].first = dp[v.second].first + r.cost;
                dp[r.to].second = dp[v.second].second + items[r.to];
                q.push({-dp[r.to].first, r.to});
            }
            else if(dp[r.to].first == dp[v.second].first + r.cost){
                if(dp[r.to].second < dp[v.second].second + items[r.to])
                    dp[r.to].second = dp[v.second].second + items[r.to];
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> items[i];
    }
    cin >> m;
    int a, b, c;
    road r;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        a--;
        b--;
        r.to = b;
        r.cost = c;
        roads[a].push_back(r);
        r.to = a;
        roads[b].push_back(r);
    }

    dijkstra();

    if(dp[n-1].first == INF) cout << "impossible\n";
    else cout << dp[n - 1].first << " " << dp[n-1].second << '\n';

    return 0;
}