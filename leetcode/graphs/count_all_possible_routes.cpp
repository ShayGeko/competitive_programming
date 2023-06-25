#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-all-possible-routes/
class Solution {
public:
    const int p = 1e9+7;
    int n;
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        n = locations.size();
        vector<vector<int>> dp(n, vector<int>(fuel+1, -1));
    
        return rec_count(dp, locations, start, fuel, finish);
    }
    int rec_count(vector<vector<int>> &dp, vector<int>& locations, int v, int fuel, int finish){
        if(dp[v][fuel] >= 0) return dp[v][fuel];


        long long ans = 0;
        for(int i = 0; i < n; ++i){
            if(i == v) continue;

            int cost = abs(locations[v]-locations[i]);
            if(fuel - cost >= 0){
                ans += rec_count(dp, locations, i, fuel - cost, finish);
            }
        }

        if(v == finish){
            ++ans;
        }
        ans%=p;
        return dp[v][fuel] = ans;
    }
};

int main() {
    Solution s;
    vector<int> locations(100);
    int start = 1, finish = 2, fuel = 200;

    for(int i = 1; i <= 100; ++i) locations[i-1]=i;
    cout << s.countRoutes(locations, start, finish, fuel) << endl;
}