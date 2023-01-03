#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i = 1; i <=t; ++i){
        int r, c;
        cin >> r >> c;
        
        cout << "Case #" << i << ":\n";
        
        // row 1:
        cout << "..";
        for(int j = 0; j <= 2*(c-1); ++j){
            cout << ((j % 2)? '-' : '+');
        }
        cout << '\n';
        // row 2:
        cout << "..";
        for(int j = 0; j <= 2*(c-1); ++j){
            cout << ((j % 2)? '.' : '|');
        }
        cout << '\n';
        
        for(int k = 2; k <= 2*r; ++k){
            if(k % 2 == 0){
                for(int j = 0; j <= 2*c; ++j){
                    cout << ((j % 2)? '-' : '+');
                }
            }
            else {
                for(int j = 0; j <= 2*c; ++j){
                    cout << ((j % 2)? '.' : '|');
                }
            }
            cout << '\n';
        }
    }
}