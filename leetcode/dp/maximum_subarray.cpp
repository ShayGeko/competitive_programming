class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur, maxi;
        
        cur = maxi = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(cur >= 0) cur+= nums[i];
            else cur = nums[i];
            
            maxi = max(maxi, cur);
        }
        
        return maxi;
    }
};