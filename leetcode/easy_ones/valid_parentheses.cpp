#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> m ({{'(', ')'}, {'{', '}'}, {'[', ']'}});
        for(auto c : s){
            switch(c){
                case '(':
                case '{':
                case '[':
                {
                        cout << c << '\n';
                        stack.push_back(c);
                }
                break;
                case ')':
                case '}':
                case ']':
                    {
                        cout << c << '\n';
                        if(stack.empty()) return false;
                        if(m[stack.back()] != c) return false;
                        stack.pop_back();
                    }
                break;
                default:
                break;
            }
        }
        return true;
    }
};

int main(){
    auto s = new Solution();
    string str;
    cin >> str;
    cout << s->isValid(str) << '\n';
    delete s;
}