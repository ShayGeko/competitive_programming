#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i = 0; i < n; ++i) cin >> t[i];

    int num1 = 0, num2 = 0;
    int maxi = 0;
    bool lastIs1 = t[0] == 1;

    for(auto k : t){
        if(lastIs1){
            if(k == 1) ++num1;
            else{
                if(num2)  maxi = max(maxi, min(num1, num2));
                num2 = 1;
                lastIs1 = false;
            }
        }
        else{
            if(k == 2) ++num2;
            else{
                if(num1) maxi = max(maxi, min(num1, num2));
                num1 = 1;
                lastIs1 = true;
            }
        }
    }
    maxi = max(maxi, min(num1, num2));
    cout << 2 * maxi << '\n';
    return 0;
}