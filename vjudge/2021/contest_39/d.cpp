#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    string s;
    int counter;
    while(t--){
        counter = 0;
        cin >> s;
        for(auto c: s) ++counter;
        cout << counter << '\n';
    }
    return 0;
}