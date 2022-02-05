#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

const int maxn = 1e5;
const int INF = 1e9;
int n, m;
vector<pair<int,int>> graph[maxn];

int solve_night(){
    vi d(n, INF);
    d[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
    q.push({0, 0});

    pair<int,  int> cur;
    while(!q.empty()){
        cur = q.top();
        q.pop();
        if(cur.first > d[cur.second]) continue;

        for(auto to : graph[cur.second]){
            if(d[to.first] > cur.first + to.second){
                q.push({cur.first + to.second, to.first});
                d[to.first] = cur.first + to.second;
            }
        }
    }
    if(d[n-1] && d[n-1] % 12 == 0){
        return (d[n-1] / 12 - 1) * 24 + 12 + d[n-1] % 12;
    }
    return d[n-1] / 12 * 24 + d[n-1] % 12;
}
int solve_day(){
    vector<pair <int, int>> dd(n, {INF, INF});
    priority_queue <pair <pair <int, int>, int>, vector <pair <pair <int, int>, int>>, greater <pair <pair <int, int>, int>>> qd;

    dd[0] = {0, 0};
    qd.push({{0,0}, 0});


    pair<int, int> temp;
    while(!qd.empty()){
        auto cur = qd.top();
        qd.pop();
        if(cur.first > dd[cur.second]) continue;

        for(auto to : graph[cur.second]){
            temp = {cur.first.first,  cur.first.second +  to.second};

            if(temp.second == 12){
                temp.first += 1;
                temp.second = 0;
            }
            else if(temp.second > 12){
                temp.first += 1;
                temp.second = to.second;
            }

            if(dd[to.first] > temp){
                qd.push({temp, to.first});
                dd[to.first] = temp;
            }
        }
    }
    if(dd[n-1].first && dd[n-1].second == 0){
        return 24 * (dd[n-1].first - 1) + 12;
    }
    return 24 * dd[n-1].first + dd[n-1].second;
}
void solve(){
    int a, b, c;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int night = solve_night();
    int day = solve_day();

    cout << day - night << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}