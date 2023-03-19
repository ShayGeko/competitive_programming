#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        int len = 1;
        queue<string> q;
        q.push(beginWord);
        q.push("F");
        string cur;
        while(q.size() > 1){
            cur = q.front();
            q.pop();
            if(cur == "F"){
                ++len;
                cur = q.front();
                q.pop();
                q.push("F");
            }
            for(int i = 0; i < beginWord.length(); ++i){
                char k = cur[i];
                char c = 'a';
                for(char t = 0; t <26; ++t){
                    cur[i] = c + t;
                    if(dict.find(cur) != dict.end()){
                        if(cur == endWord) return len+1;
                        else{
                            q.push(cur);
                            dict.erase(cur);
                        }
                    }   
                }
                cur[i] = k;
             }
        }
        
        return 0;
    }
};