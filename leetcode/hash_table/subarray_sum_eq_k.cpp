#include <unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        unordered_map<int, int> freq;
        freq[0] = 1;
        
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum+=nums[i];
            if(freq.find(sum-k) != freq.end())
                cnt+= freq[sum-k];
            freq[sum]++;
        }
        
        return cnt;
    }
};