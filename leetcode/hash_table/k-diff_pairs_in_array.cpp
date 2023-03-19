#include <set>
#include <algorithm>
#include <vector> 
class Solution {
public:
    int findPairs(std::vector<int>& nums, int k) {
        std::set<int> values;
        std::set<std::pair<int,int>> pairs;
        for(auto num : nums){
            auto it = values.find(num - k);
            if(it != values.end()){
                pairs.insert({*it, num});
            }
            it = values.find(num + k);
            if(it != values.end()){
                pairs.insert({std::min(*it, num), std::max(*it, num)});
            }
            
            values.insert(num);
        }
        
        return pairs.size();
    }
};