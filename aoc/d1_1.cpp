#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int cur = 0;
    cin >> cur;
    int prev = cur;
    int cnt = 0;
    while(cin >> cur){
        cnt+= cur > prev;
        prev = cur;
    }
    cout << cnt << '\n';

    return 0;
}
