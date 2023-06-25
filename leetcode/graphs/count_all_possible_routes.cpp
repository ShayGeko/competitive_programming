#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-all-possible-routes/
class Solution {
public:
    const int p = 1e9+7;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        // [location][len][fuel]
        vector<unordered_map<int, unordered_map<int,int>>> ways(n);
        vector<vector<int>> d(n, vector<int>(n));
        for(int i = 0; i < n; ++i) for(int j = i; j < n; ++j) {
            int dist = locations[i] - locations[j];
            if(dist < 0) dist = -dist;
            d[i][j] = d[j][i] = dist;
        }

        ways[0][start][fuel] = 1;
        int ans = 0;
        // [location, length, fuel] 
        queue<vector<int>> q;
        q.push({start, 0, fuel});
        while(!q.empty()) {
            auto v = q.front();q.pop();
            int v_ways = ways[v[0]][v[1]][v[2]];
            if(v[0] == finish) ans = (ans + v_ways) % p;

            for(int i = 0; i < n; ++i) {
                if(i == v[0]) continue;

                if(v[2]  - d[v[0]][i] >= 0) {
                    vector<int> to = {i, v[1]+1, v[2] - d[v[0]][i]};
                    int& to_ways = ways[to[0]][to[1]][to[2]];
                    
                    if(to_ways == 0) q.push(to);
                    to_ways = (to_ways + v_ways) % p;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> locations = {2,3,6,8,4};
    int start = 1, finish = 3, fuel = 5;
    cout << s.countRoutes(locations, start, finish, fuel) << endl;
}