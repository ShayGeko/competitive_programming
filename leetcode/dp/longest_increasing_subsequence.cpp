#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc (n);
        int length = 1, cur;
        inc[0] = nums[0];
        for(int i = 1; i < n; ++i){
            auto it = lower_bound(inc.begin(), inc.begin() + length, nums[i]);
            *it = nums[i];
            cur = it - inc.begin() + 1;
            if(length < cur) ++length;
        }
        return length;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    Solution* s = new Solution();

    cout << s->lengthOfLIS(nums);

    delete s;
    return 0;
}


