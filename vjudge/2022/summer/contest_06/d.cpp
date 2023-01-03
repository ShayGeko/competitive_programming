#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9 + 7;

int bin_pow2(int k){
    if(k == 0) return 1;
    if(k == 1) return 2;

    int num = bin_pow2(k / 2);
    num = ((ll) num * num) % p;
    if(k % 2) num = (num * 2) % p;

    return num;
}
void solve(){
    int n;
    cin >> n;
    vector<int[3]> nums (n);
    int a;
    nums[0][0] = nums[0][1] = nums[0][2] = 0;
    cin >> a;
    nums[0][a - 1]++;
    for(int i = 1; i < n; ++i){
        cin >> a;
        for(int j = 0; j < 3; ++j) nums[i][j] = nums[i-1][j];
        nums[i][a-1] = nums[i-1][a-1]++;
    }
    int sum;
    
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    //cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}