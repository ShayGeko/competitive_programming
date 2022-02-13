class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerSet;
        
        int n = nums.size();
        int mask = (1 << n) - 1;
        
        vector<int> v;
        for(int i = 0; i <= mask; ++i){
            int cur = 1, temp = i;
            v.clear();
            for(int j = 0; j < n; ++j){
                if(cur & i) {
                    v.push_back(nums[j]);
                }
                cur = cur << 1;
            }
            powerSet.push_back(v);
        }
        
        return powerSet;
    }
};