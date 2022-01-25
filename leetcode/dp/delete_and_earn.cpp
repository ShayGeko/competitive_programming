class Solution {
public:
    int count[10001];
    int dp[10001][2];
    int compute(int num){
        return count[num] * num;
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxnum = 0;
        for(auto num : nums){
            ++count[num];
            if(num > maxnum) maxnum = num;
        }
        dp[1][1] = count[1];
        dp[1][0] = 0;
        for(int i = 2; i <= maxnum; ++i){
            dp[i][1] = compute(i) + dp[i-1][0];
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        }
        
        return max(dp[maxnum][0], dp[maxnum][1]);
    }
};