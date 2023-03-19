
#include <bits/stdc++.h>

using namespace std;

const string substitutions[26] = {"@", "8", "(", "|)", "3", "#", "6", "[-]", "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]", "0", "|D", "(,)", "|Z", "$", "\'][\'",
                            "|_|", "\\/", "\\/\\/", "}{", "`/", "2",};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    string str;

    getline(cin, str);
    for(auto c: str){
        if(c >= 'a' && c <= 'z'){
            cout << substitutions[c - 'a'];
        }
        else if(c >= 'A' && c <= 'Z'){
            cout << substitutions[c - 'A'];
        }
        else cout << c;
    }
    return 0;
}