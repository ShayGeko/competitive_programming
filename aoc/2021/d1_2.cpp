#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
int a[3];
int sum(){
    return a[0] + a[1] + a[2];
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> a[0] >> a[1] >> a[2];
    int i = 0;
    int temp;
    int prev = sum();
    int cur;
    int cnt;
    while(cin >> temp){
        a[i] = temp;
        i = (i + 1) % 3;
        cur = sum();
        cnt+= cur>prev;
        prev = cur;
    }
    cout << cnt << '\n';

    return 0;
}
