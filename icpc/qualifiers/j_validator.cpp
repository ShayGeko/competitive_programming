#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    vector<int> stack;

    for(auto c : s){
        if(c == '1'){
            stack.push_back(1);
        }
        if(c == 'd'){
            stack.push_back(stack[stack.size() - 1]);
        }
        if(c == '+'){
            int a = stack.back();
            stack.pop_back();
            int b = stack.back();
            stack.pop_back();
            for(int i = 0; i < stack.size(); ++i){
                stack[i]--;
            }
            stack.push_back(a + b);
        }
    }
    cout << stack.front() << '\n';
    return 0;
}