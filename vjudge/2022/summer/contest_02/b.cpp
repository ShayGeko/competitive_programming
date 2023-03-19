#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
const int P = 1e9 + 7;

int nums[1001];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int cnt = 1;
    for(int i = 1; i <= 1000; ++i){
        while(cnt % 3 == 0 || cnt % 10 == 3) ++cnt;
        nums[i] = cnt++;

    }
    int t;
    cin >> t;
    int k;
    while(t--){
        cin >> k;
        cout << nums[k] << '\n';
    }
    return 0;
}