#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    set<string> words;
    string temp;
    string strings[maxn] ;
    char lastChar;
    for(int i = 0; i < n; ++i){
        cin >> strings[i];
    }

    for(int i = 0; i < n; ++i){
        temp = strings[i];
        if(words.find(temp) != words.end()){
            cout << "No\n";
            return 0;
        }
        if(lastChar != temp[0] && i > 0){
            cout << "No\n";
            return 0;
        }
        words.insert(temp);
        lastChar = temp[temp.length() - 1];
    }
    cout << "Yes\n";

    return 0;
}