#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
const int P = 1e9 + 7;

int nums[1001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int k;
    while(t--){
        cin >> k;
        cout << (k+1) / 10 << '\n';
    }
    return 0;
}