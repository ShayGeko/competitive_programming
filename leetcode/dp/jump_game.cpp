class Solution {
public:
    bool canJump(vector<int>& nums) {
        int r = 0;
        int n = nums.size();
        for(int pos = 0; pos <= r && r < n -1; ++pos){
            r = max(pos + nums[pos], r);
        }
        
        return r >= n - 1;
    }
};