class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        
        int cnt = 0;
        int cur = 0;
        int sum = 0;
        while(num >= 10){
            while(num){
                cur+= num % 10;
                num /= 10;
            }
            num = cur;
            cur = 0;
        }
        
        return num;
    }
};