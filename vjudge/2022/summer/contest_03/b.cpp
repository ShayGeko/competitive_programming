#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << '\n';
        return 0;
    }
    int sum = 0;
    int el = 0;
    int i = 1;
    while(true){
        el += i;
        sum += el;
        if(sum >= n) break;
        ++i;
    };
    if(sum == n )cout << i << '\n';
    else cout << i - 1 << '\n';
    return 0;
}