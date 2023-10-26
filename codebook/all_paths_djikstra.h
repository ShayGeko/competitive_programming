#include <bits/stdc++.h>
#pragma once

using namespace std;

/*
Computes shortest path from s to t
Returns a list of [(min cost c to get to node, [parents resulting in cost c])]
*/
typedef int T;
constexpr T INF = numeric_limits<T>::max();
vector<pair<T, vector<T>>> allPathsDjikstra(
    const vector<vector<pair<int, T>>> &adjList, int s, int t = -1) {
    int n = adjList.size();
    vector<pair<T, vector<T>>> d_parent(n, {INF, {}});
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> pq;
    d_parent[s].first = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto [v, d] = pq.top();
        pq.pop();
        if (v == t) break;
        if (d > d_parent[v].first) continue;
        for (auto [to, cost] : adjList[v]) {
            T newdist = d + cost;
            if (d_parent[to].first > newdist) {
                d_parent[to] = {newdist, {v}};
                pq.emplace(newdist, to);
            } else if (d_parent[to].first == newdist)
                d_parent[to].second.push_back(v);
        }
    }

    return d_parent;
}