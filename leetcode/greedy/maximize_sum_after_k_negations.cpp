class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int index[201] = {};
        
        for(auto num : nums) index[num + 100]++;
        
        for(int i = -100; i <= 100 && k; ++i){
            if(index[i + 100]){
                if(i < 0){
                    int dif = min(index[i+100], k);
                    index[-i+100] += dif;
                    index[i+100] -= dif;
                    k-=dif; 
                }
                else{
                    if(k%2){
                        index[-i+100]++;
                        index[i+100]--;
                        break;
                    }
                }
            }
        }
        
        int sum = 0;
        
        for(int i = -100; i <= 100; ++i){
            if(index[i+100]) sum+= i*index[i+100];
        }
        
        return sum;
    }
};