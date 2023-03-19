#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> d(n, 1e9);
        vector<vector<pair<int, int>>> adj(n);
        for(auto t : times){
            adj[t[0] - 1].push_back({t[1] - 1, t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k - 1});
        while(!pq.empty()){
            auto v = pq.top();
            pq.pop();
            if(d[v.second] <= v.first) continue;
            d[v.second] = v.first;
            for(auto& to : adj[v.second])
                if(d[to.first] > v.first + to.second) pq.push({v.first + to.second, to.first});
        }
        int maxi = 0;
        
        for(auto t : d) maxi = max(maxi, t);
        
        return (maxi==1e9) ? -1 : maxi;
        
    }
};