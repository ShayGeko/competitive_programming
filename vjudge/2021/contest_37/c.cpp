#include <bits/stdc++.h>

using namespace std;
const int MAXN = 400;

char arr[MAXN][MAXN];
long long gcdExtended(long long a, long long b, long long* x, long long* y);

long long modInverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        long long res = (x % m + m) % m;
        return res;
    }
}
long long gcdExtended(long long a, long long b, long long* x, long long* y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    long long x1, y1;
    long long gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    long long t = 1;
    long long n = 1;
    long long x, y;
    char op;
    while(n != 0 && t != 0){
        cin >> n >> t;
        while(t--){
            cin >> x >> op >> y;
            switch(op){
                case '*':{
                    cout << (x * y) % n << '\n';
                }
                break;
                case '/': {
                    if(y == 0) cout << "-1\n";
                    else{
                        y = modInverse(y, n);
                        if(y == -1){
                            cout << "-1\n";
                        }
                        else cout << (x * y) %n << '\n';
                    }
                }
                break;
                case '+': {
                    cout << (x + y) % n << '\n';
                }
                break;
                case '-':{
                    cout << (x - y + n) %n << '\n';
                }
                default:
                break;
            }
        }
    }

    return 0;
}