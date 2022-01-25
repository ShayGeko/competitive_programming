class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int maxSum = nums[0], minSum = nums[0], curMin = 0, curMax = 0;
        
        int total = 0;
        for(auto num : nums){
            curMax = max(num, curMax + num);
            maxSum = max(curMax, maxSum);
            curMin = min(num, curMin + num);
            minSum = min(curMin, minSum);
            total += num;
        }
        
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};