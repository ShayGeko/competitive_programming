class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> states(n+1, false);
        
        
        for(int i = 0; i < n; ++i){
            if(states[i]) continue;
            
            for(int j = 1; i + j*j <= n; ++j){
                states[i + j*j] = true;
            }
        }
        
        return states[n];
    }
};