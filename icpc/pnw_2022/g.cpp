#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int maxn = 501;
const int INF = 2e9;
const int p = 1e9+7;

int djikstra(vector<vector<pii>> &tile_coord, int k){
    vector<vi> dist_min(k+1);
    vector< vector <bool >> used (k+1);
    for(int i = 0; i < k; ++i) used[i].resize(tile_coord[i].size(), false);
    dist_min[0] = vi(tile_coord[0].size(), 0);
    for (int i = 1; i < k; i++) {
        dist_min[i] = vi(tile_coord[i].size(), LLONG_MAX);
    }

    // {distance, {group # (1..k), # within group}}
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater <pair<int, pii>>> pr;

    for(int i = 0; i < tile_coord[0].size(); ++i){
        pr.push({0, {0, i}});
    }
    while(!pr.empty()){
        auto cur = pr.top();
        
        int group = cur.second.first,
            index = cur.second.second;
        
        pr.pop();
        while(!pr.empty() && group != 0 && used[group][index]){
            cur = pr.top();
            pr.pop();
            group = cur.second.first,
            index = cur.second.second;
        }
        used[group][index] = true;
        if(group == k - 1){
            return cur.first;
        }
        int try_dist;
        for(int i = 0; i < tile_coord[group + 1].size(); ++i){
            try_dist = 
                min(
                    abs(tile_coord[group+1][i].first - tile_coord[group][index].first),
                    abs(tile_coord[group+1][i].second - tile_coord[group][index].second)
                );
            try_dist *= try_dist;
            if(dist_min[group+1][i] > try_dist + cur.first){

                dist_min[group+1][i] = try_dist + cur.first;
                pr.push({dist_min[group+1][i], {group + 1, i}});
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int n, k;
    cin >> n >> k;
    vector<vector<pii>> tile_coord(k);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            tile_coord[a-1].push_back({i, j});
        }
    }
    
    int ans = djikstra(tile_coord, k);
    
    cout << ans << '\n';
    
    return 0;
}