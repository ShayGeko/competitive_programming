#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(a + b + c == 0 || a + b + c == 3) {
        cout << "*\n";
    }
    else if(a + b + c == 2){
        if(a == 0) cout << "A\n";
        else if (b == 0) cout << "B\n";
        else if (c == 0) cout << "C\n";
    }
    else if(a + b + c == 1){
        if(a == 1) cout << "A\n";
        else if (b == 1) cout << "B\n";
        else if (c == 1) cout << "C\n";
    }
    return 0;
}