#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;

    int zeros, ones;
    cin >> t;
    string str;
    while(t--){
        zeros = 0;
        ones = 0;
        cin >> str;
        for(auto c : str){
            if(c == '0')++zeros;
            else ++ones;
        }
        if(min(zeros, ones) % 2) cout << "DA\n";
        else cout << "NET\n";
    }
    return 0;
}