#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a, b;
    cin >> a >> b;
    if(a*b % 2) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}