#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n, p;
    cin >> n >> p;

    bool allZero = true, allFull = true;

    vi nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        if(nums[i] != 0) allZero = false;
        if(nums[i] != 100) allFull = false;
    }

    if(p == 100 && !allFull){
        cout << "impossible" << endl;
        return;
    }

    
    ll sum = 0;
    for(auto num : nums) sum += num;
    ll psum = p*n;
    int k = 0;
    while(sum < psum){
        sum += 100;
        psum +=p;
        ++k;
    }
    cout << k << endl;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}