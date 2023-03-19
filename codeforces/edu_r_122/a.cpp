#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        if(n % 7 == 0){
            cout << n << '\n';
            continue;
        }
        int temp = n / 10 * 10;
        int temp2 = n - n% 100 + n % 10;
        int i = 1;
        while(i < 10 && (temp + i) % 7) ++i;
        if((temp + i) % 7 == 0) {
            cout << temp + i << '\n';
            continue;
        }
        i = 1;
        temp = n - n% 100 + n % 10;
        while(i < 10 && (temp + 10*i) % 7) ++i;
        if((temp + i) % 7 == 0) {
            cout << temp + i << '\n';
            continue;
        }
        i = 1;
        temp = n % 100;
        while(i < 10 && (temp + 100*i) % 7) ++i;
        if((temp + i) % 7 == 0) {
            cout << temp + i << '\n';
            continue;
        }
        cout << n + 7 - n % 7 << '\n';
    }
    return 0;
}