class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int l = 0, cum_excess = 0;
        int current = 0;
        int dif;
        for(int i = 0; i < n; ++i){
            dif = gas[i]-cost[i];
            cum_excess += dif;
            current+=dif;
            
            if(current < 0){
                l = i + 1;
                current = 0;
            }
        }
        
        if(cum_excess >= 0) return l;
        
        return -1;
    }
};