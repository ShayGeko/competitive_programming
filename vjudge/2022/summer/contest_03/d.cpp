#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
int n, d;
int f(int x){
    return x + (d + x) / (x + 1);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int temp;
    while(t--){
        cin >> n >> d;
        temp = sqrt(d) - 1;
        if(f(temp) <= n || f(temp + 1) <= n) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}