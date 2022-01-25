class Solution {
public:
    int dp[100][2];
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];
        for(int i = 2; i < n - 1; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i]);
        }
        dp[n - 1][0] = max(dp[n - 2][0], dp[n - 3][0] + nums[n - 1]);
        dp[n - 1][1] = max(dp[n - 2][1], dp[n - 3][1]);
        return max(dp[n-1][0], dp[n-1][1]);
    }
};