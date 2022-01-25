#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double L, R;
    cin >> L >> R;
    double diag = L * sqrt(2);

    if(diag <= 2*R) cout << "fits\n";
    else cout << "nope\n";
    return 0;
}