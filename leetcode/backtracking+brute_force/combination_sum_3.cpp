#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        getCombinations(result, combination, k, n);
        return result;        
    }
private:
    void getCombinations(vector<vector<int>> &result, vector<int> combination, int k, int n){
        if(combination.size() == k && n == 0){result.push_back(combination); return;}
        else if(combination.size() < k){
            for(int i = combination.empty()? 1 : combination.back() + 1; i <= 9; ++i){
                combination.push_back(i);
                getCombinations(result, combination, k, n - i);
                combination.pop_back();
            }
        }
        
        
    }
};