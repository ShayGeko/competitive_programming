#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        bool match = true;
        while(match){
            i = readNext(i, s);
            j = readNext(j, t);
            if(i >= 0 && j >= 0)
                match = (s[i] == t[j]);
            else if(i>=0 || j >= 0) match = false;
            else break;
            i--;j--;
        }
        
        return match;
    }
    int readNext(int i, string& s){
        if(i < 0) return i;
        if(s[i] != '#') return i;
        int skip = 0;
        do{
            while(i >= 0 && s[i] == '#'){
                ++skip;
                i--;
            }
            while(i >= 0 && s[i] !='#' && skip > 0){
                i--;
                skip--;
            }
        }
        while(i >= 0 && s[i] =='#');
        
        return i;
    }
};