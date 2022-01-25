#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
const int maxt = 43201;
int d[maxn];
int t[maxn];

int operations[maxt];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; ++i){
        cin >> d[i] >> t[i];
    }

    for(int i = 0; i < n; ++i){
        ++operations[t[i]];
        ++operations[t[i] - d[i]];
        ++operations[t[i] - 2*d[i]];
    }
    int ans = 0;
    for(int i = 0; i <= maxt; ++i){
        ans = max(ans, operations[i]);
    }
    cout << (ans + 1) / 2 << '\n';
    return 0;
}