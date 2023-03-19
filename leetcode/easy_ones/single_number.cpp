#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int extra = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            extra ^= nums[i];   
        }
        
        return extra;
    }
};