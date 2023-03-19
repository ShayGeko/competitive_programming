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
    int n;
    cin >> n;

    vi nums(n+1, 0);
    for(int i = 1; i <= n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int mini = INF;
    for(int i = 0; i <= n; ++i){
        mini = min(mini, nums[i] + n - i);
    }

    cout << mini << '\n';
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