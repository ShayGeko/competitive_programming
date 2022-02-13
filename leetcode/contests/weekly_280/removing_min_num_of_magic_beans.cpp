#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for(auto bean : beans) sum += bean;
        
        long long cur = 0;
        long long mini = sum;
        for(int i = 0; i < beans.size();++i){
            sum -= beans[i];
            if(cur + (sum - beans[i] * (beans.size() - 1 - i)) < mini) 
                mini = cur + (sum - beans[i] * (beans.size() - 1 - i));
            cur += beans[i];
        }
        return mini;
    }
};