#include <iostream>

using namespace std;

int main(){
    int n;
    string s;
    
    cin >> n;
    cin >> s;

    for(int i = 1; i < n; ++i){
        if(s[i] != s[i - 1]){
            cout << "YES\n" << s[i-1] << s[i] << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}