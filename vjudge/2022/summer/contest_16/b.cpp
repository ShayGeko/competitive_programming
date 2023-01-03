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
void solve(){
    int r, c, n;
    cin >> r >> c >> n;

    queue<pii> q;
    int x, y;
    
    bool used[100][100] = {0};
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        x--;
        y--;
        q.push({x, y});
        used[x][y] = true;
    }
    q.push({-1, -1});

    int cnt = 1;
    pii temp = {-1, -1};
    while(q.size() > 1){
        auto v = q.front();
        q.pop();
        if(v == temp){
            q.push({-1,-1});
            ++cnt;
            continue;
        }
        if(v.first > 0 && !used[v.first - 1][v.second]){
            q.push({v.first - 1, v.second});
            used[v.first - 1][v.second] = true;
        }
        if(v.first < r - 1 && !used[v.first + 1][v.second]){
            q.push({v.first + 1, v.second});
            used[v.first + 1][v.second] = true;
        }
        if(v.second > 0 && !used[v.first][v.second - 1]){
            q.push({v.first, v.second - 1});
            used[v.first][v.second - 1] = true;
        }
        if(v.second < c - 1 && !used[v.first][v.second + 1]){
            q.push({v.first, v.second + 1});
            used[v.first][v.second + 1] = true;
        }
    }
    cout << cnt << '\n';
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