#include <bits/stdc++.h>

using namespace std;
const int MAXN = 500;

int arr[MAXN];
int psum[MAXN];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int n, l, r;
    long long s;
    while(t--){
        cin >> n >> l >> r >> s;
        int len = r - l + 1;
        int min = (len + 1)*len / 2;
        int max = (n - len + 1 + n) * len / 2;

        if(s < min || s > max) cout << "-1\n";

        // (k - 1 + k - 1 - len + 1)*(l-1) / 2 >= s - k >= len * (len - 1) / 2;
        // d = s - min. min = 1, 2, 3
        // min + d / len -> 3, 4, 5
        // distribute d % len between last (d%len)
    }

    return 0;
}