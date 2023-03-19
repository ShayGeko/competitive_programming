#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int r = nums[0];
        int cnt = 1;
        for(int i = 0; r < n - 1; ++i){
            for(int j = i, prev_r = i = r; j <= prev_r; ++j){
                if(r < j + nums[j]) r = j + nums[j];
            }
            ++cnt;
        }
        
        return cnt;
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    Solution* solution = new Solution();
    
    vector <int> data;
    int n;
    int temp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        data.push_back(temp);
    }

    cout << solution->jump(data) << '\n';

    delete solution;
    return 0;
}