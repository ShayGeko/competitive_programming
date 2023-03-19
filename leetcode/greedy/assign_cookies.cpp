class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.rbegin(),g.rend());
        sort(s.rbegin(), s.rend());
        
        int i = 0, j = 0;
        while(j < g.size() && i < s.size()){
            if(s[i] >= g[j]) ++i;
            ++j;
        }
        
        return i;
    }
};