#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cnt(target+1);
        
        cnt[0] = 1;
        
        vector<vector<vector<int>>> cmb(target+1);
        cmb[0] = {{0}};
        vector<int> temp;
        for(auto c : candidates){
            for(int i =  0; i + c <= target; ++i){
                if(i == 0){
                    temp = {c};
                    cmb[c].push_back(temp);
                }
                else if(cmb[i].size()){
                    for(auto b : cmb[i]){
                        temp = b;
                        temp.push_back(c);
                        cmb[i+c].push_back(temp);
                    }
                }
            }
        }
        return cmb[target];
    }
};