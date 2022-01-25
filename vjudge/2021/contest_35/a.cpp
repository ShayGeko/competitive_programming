#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;

    int t;

    

    int a, b, c;
    cin >> t;
    
    while(t--){
        cin >> str;
        a = b = c = 0;
        for(char i : str){
            if(i == 'A') ++a;
            else if(i == 'B') ++b;
            else if(i == 'C') ++c;
        }
        if(b == (a + c)){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}