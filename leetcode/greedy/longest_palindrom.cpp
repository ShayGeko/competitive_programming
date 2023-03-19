class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnt;
        bool odd = false;
        
        int pairs = 0;
        for(auto c : s){
            cnt[c]++;
        }
        for(auto p : cnt){
            pairs += p.second / 2;
            if(!odd && p.second % 2)
                odd = true;
        }
        
        return 2*pairs + odd;
    }
};