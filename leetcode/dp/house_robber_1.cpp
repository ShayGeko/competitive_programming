#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
map<int, int> count;
class Solution {
public:
    int dp[101][2];
    int rob(vector<int>& nums) {
        int n = nums.size();

        dp[0][1] = nums[0];
        dp[1][1] = nums[1];
        dp[0][0] = nums[0];

        for(int i = 2; i < n; ++i){
            dp[i][1] = nums[i] + dp[i-1][0];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }

        return max(dp[n-1][1], dp[n-1][0]);
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

    cout << solution->rob(data) << '\n';

    delete solution;
    return 0;
}