#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;

typedef vector<int> lnum;
map<long long, int> invfac;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    // idea 1
    // f = (f + 1) % p;
    // invfac[f] = i; <- map
    // 12: k = (k + a[0]) % p;  k = (k * 10) % p; k = (k + 2) % p;
    // until k != a;
    // return invfac[k];

    string a;
    cin >> a;
    long long f = 1;
    invfac[f] = 1;
    const int p = 1e9 + 7;
    for(int i = 2; i < 1e6; ++i){
        f = (f * i) % p;
        invfac[f] = i;
    }

    long long k = (a[0] - '0');
    for(int i = 1; i < a.length(); ++i){
        k = (k * 10) % p;
        k = (k + a[i] - '0') % p;
    }
    cout << invfac[k] << '\n';
    return 0;
}