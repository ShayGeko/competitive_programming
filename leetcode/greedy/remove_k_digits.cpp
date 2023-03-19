#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> s;
        int n = num.length();
        for(int i = 0; i < n; ++i){
            while(k && !s.empty() && num[i] < s.back()){
                s.pop_back();
                k--;
            }
            s.push_back(num[i]);
        }
        int i = 0;
        string ans;
        while(k--)s.pop_back();
        
        while(i < s.size() && s[i] == '0') ++i;
        for(; i < s.size(); ++i) ans += s[i];
        
        return ans.empty()? "0" : ans;
    }
};