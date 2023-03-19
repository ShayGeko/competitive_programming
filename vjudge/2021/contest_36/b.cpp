#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double n, h;
    cin >> n >> h;

    double part = h / sqrt(n);
    for(int i = 1; i < n; ++i){
        cout << setprecision(12) <<  fixed <<  part * sqrt(i) << " ";
    }
    cout << '\n';

    return 0;
}