class Solution {
public:
    char findTheDifference(string s, string t) {
        char sum = 0;
        for(int i = 0; i < t.length(); ++i){
            sum+=t[i];
            sum-=s[i];
        }
        sum+=t.back();
        return sum;
    }
};