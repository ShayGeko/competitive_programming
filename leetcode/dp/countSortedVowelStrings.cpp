class Solution {
public:
    int ans[51][5] = {0};
    int countVowelStrings(int n) {
        
        return countVowelStringsSmaller(n, 4);
    }
    int countVowelStringsSmaller(int n, int c){
        if(ans[n][c] > 0) return ans[n][c];
        if(n == 1) return ans[n][c] = c+1;
        
        int ret = 0;
        for(int i = 0; i <= c; ++i) ret+=countVowelStringsSmaller(n-1,i);
        
        return ans[n][c] = ret;
    }
};