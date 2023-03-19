#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 2;

long long b[MAXN];
long long psum[MAXN];
bool check(int n, long long sum, int check_i, int &extra){
    for(int i = 0; i < n + 1; ++i){
        if(sum - b[i] == 2 * b[check_i]){
            extra = i;
            return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        for(int i = 0; i < n + 2; ++i){
            cin >> b[i];
        }
        sort(b, b + n + 2);
        long long sum = 0;
        for(int i = 0; i < n + 2; ++i){
            sum += b[i];
        }
        int extra;
        bool works = check(n, sum, n + 1, extra);
        if(!works) {
            swap(b[n], b[n+1]);
            works = check(n, sum, n + 1, extra);
        }

        if(works){
            swap(b[extra], b[n]);
            for(int i = 0; i < n; ++i) cout << b[i] << " ";
            cout << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}