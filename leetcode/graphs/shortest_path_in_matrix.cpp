#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        
        const int n = grid.size();
        const pair<int, int> end = {n - 1, n - 1},lim = {-1, -1};
        pair<int, int> cur = {0, 0};
        
        queue<pair<int, int>> q;
        q.push(cur);
        q.push(lim);
        int cnt = 1;
        pair<int, int> temp;
        while(q.size() > 1){
            cur = q.front();
            q.pop();
            if(cur == lim){
                ++cnt;
                q.push(cur);
                continue;
            }
            if(cur == end) return cnt;
            for(int i = -1; i<=1; ++i){
                for(int j = -1; j <= 1; ++j){
                    if(i == 0 && j == 0) continue;
                    temp = {cur.first + i, cur.second + j};
                    if(temp.first < 0 || temp.first >= n) continue;
                    else if(temp.second < 0 || temp.second >= n) continue;
                    else if(!grid[temp.first][temp.second]){
                        grid[temp.first][temp.second] = 1;
                        q.push(temp);
                    }
                }
            }
        }
        
        return -1;
    }
};