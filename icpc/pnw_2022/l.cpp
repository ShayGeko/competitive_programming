#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<pii>> tile_coord(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            tile_coord[a--].emplace_back(i, j);
        }
    }
    
    vector<vll> dist_min(k);
    dist_min[0] = vll(tile_coord[0].size(), 0);
    for (int i = 1; i < k; i++) {
        dist_min[i] = vll(tile_coord[i].size(), LLONG_MAX);
    }
    
    // {distance, {group # (1..k), # within group}}
    priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, less <pair<ll, pii>>> pr;

    pr.push({0,{0,0}});

    while(!pr.empty()){
        auto cur = pr.top();
        
        int group = cur.second.first,
            index = cur.second.second;
        pr.pop();
        while(!pr.empty() && dist_min[group][index] < cur.first){
            cur = pr.top();
            pr.pop();
            group = cur.second.first,
            index = cur.second.second;
        }
        
        if(group == k){
            cout << cur.first << "\n";
            return;
        }
        ll try_dist;
        for(int i = 0; i < tile_coord[group + 1].size(); ++i){
            try_dist = 
                min(
                    abs(tile_coord[group+1][i].first - tile_coord[group][index].first),
                    abs(tile_coord[group+1][i].second-tile_coord[group][index].second)
                );
            if(dist_min[group][index] > try_dist){
                dist_min[group][index] = try_dist;
                pr.push({dist_min[group][index], {group + 1, i}});
            }
        }
    }
    
    long long min_path_len = LLONG_MAX;
    for (int j = 0; j < tile_coord[k-1].size(); j++) {
        min_path_len = min(min_path_len, dist_min[k-1][j]);
    }
    
    if (min_path_len == LLONG_MAX) {
        cout << -1 << endl;
    }
    else {
        cout << min_path_len << endl;
    }
    
    
    return 0;
}