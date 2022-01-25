#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int k, sum, a;
    while(t--){
        sum = 0;
        cin >> k;
        for(int i = 0; i < k; ++i){
            cin >> a;
            sum+=a;
        }

        cout << sum - k + 1 << '\n';

    }
    return 0;
}