#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dec(n);
        vector<int> inc (n);
        int length = 1;
        // max growing subsequence on a suffix starting from i
        vector<int> maxDecByIndex(n);
        maxDecByIndex[n - 1] = 1;
        int cur;
        for(int i = n - 2; i >= 0; i--){
            auto it = lower_bound(dec.begin(), dec.begin() + length, nums[i]);
            *it = nums[i];
            cur = it - dec.begin() + 1;
            if(length < cur){
                 ++length;
            }
            maxDecByIndex[i] = cur;
        }
        length = 1;
        inc[0] = nums[0];
        int maxMnt = 3;
        for(int i = 1; i < n - 1; ++i){
            auto it = lower_bound(inc.begin(), inc.begin() + length, nums[i]);
            *it = nums[i];
            cur = it - inc.begin() + 1;
            if(length < cur) ++length;
            if(cur >= 2 && maxDecByIndex[i] >= 2) maxMnt = max(cur + maxDecByIndex[i] - 1, maxMnt);
        }
        
        return n - maxMnt;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    Solution* s = new Solution();

    cout << s->minimumMountainRemovals(nums);

    delete s;
    return 0;
}


