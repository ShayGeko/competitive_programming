class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = sortedStr(n);
        
        for(int i = 0; i < 32; ++i){
            if(str == sortedStr(1 << i)) return true;
        }
        
        return false;
    }
    string sortedStr(int n){
        string str = to_string(n);
        
        sort(str.begin(), str.end());
        
        return str;
    }
};