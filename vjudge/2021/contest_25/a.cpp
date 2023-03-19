#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    for(int i = 0; i < t; ++i){
        cin >> n;
        if(n > 30){
            cout << "YES\n";
            switch(n){
                case 36: 
                    cout << "5 6 10 15\n";
                    break;
                case 40: 
                    cout << "5 6 14 15\n";
                    break;
                case 44: 
                    cout << "6 10 13 15\n";
                    break;
                default:
                    cout << "6 10 14 " << n - 30 << '\n';
            }
        }
        else cout << "NO\n";
    }
}