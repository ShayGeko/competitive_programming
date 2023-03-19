#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> squares;
        for(int i = 1; i <= sqrt(n) + 1; ++i){
            squares.push_back(i*i);
        }
        vector<bool> states(n+1);
        
        states[0] = false;
        
        for(int i = 1; i <= n; ++i){
            auto it = upper_bound(squares.begin(), squares.end(), i);
            bool winnable = true;
            for(auto t = squares.begin(); t != it; t++){
                winnable &= states[i - *t];
            }
            states[i] = !winnable;
        }
        
        return states[n];
    }
};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    Solution* solution = new Solution();

    int n;
    int temp;
    cin >> n;

    cout << solution->winnerSquareGame(n) << '\n';

    delete solution;
    return 0;
}