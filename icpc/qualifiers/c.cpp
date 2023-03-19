#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n;
    cin >> n;

    long long prod = 1;

    int i = 0;

    long long num = 1;
    while(prod * primes[i] <= n && prod * primes[i] > 0){
        prod*= primes[i];
        num*= primes[i] - 1;
        ++i;
    }
    num = prod - num;
    for(int j = 0; j <= i; ++j){
        if(prod % primes[j] == 0 && num % primes[j] == 0){
            prod/=primes[j];
            num /= primes[j];
        }
    }
    cout << num << "/" << prod << '\n';
    return 0;
}