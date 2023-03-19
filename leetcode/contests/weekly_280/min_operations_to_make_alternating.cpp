#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> evens;
        unordered_map<int, int> odds;
        
        for(int i = 0; i < nums.size(); ++i){
            if(i%2) odds[nums[i]] ++;
            else evens[nums[i]]++;
        }
        pair<int, int> max_odds = {0, 0};
        pair<int, int> max_evens = {0, 0};
        for(auto t : evens){
            if(t.second > max_evens.second){
                max_evens = t;
            }
        }
        for(auto t : odds){
            if(t.second > max_odds.second){
                max_odds = t;
            }
        }
        
        pair<int, int> second_odds = {0, 0};
        pair<int, int> second_evens = {0, 0};
        odds[max_odds.first] = 0;
        evens[max_evens.first] = 0;
        for(auto t : evens){
            if(t.second > second_evens.second){
                second_evens = t;
            }
        }
        for(auto t : odds){
            if(t.second > second_odds.second){
                second_odds = t;
            }
        }
        if(max_odds.first != max_evens.first){
          return nums.size() - max_evens.second - max_odds.second;
        }
        else return nums.size() - max(max_evens.second + second_odds.second, second_evens.second + max_odds.second);
    }
};