#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int g, t, n;
    cin >> g >> t >> n;
    int k = (g - t) * 9 / 10;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        k -= a;
    }
    cout << k << '\n';
    return 0;
}