
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    double i = 1;
    double ans = 0;
    while(n >= 1){
        ans += i / n;
        n-=1;
    }
    cout << fixed << setprecision(6) <<  ans << '\n';
    return 0;
}