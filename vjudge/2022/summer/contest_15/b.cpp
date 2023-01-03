#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vi nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    sort(nums.begin(), nums.end());

    bool pos = true;
    bool reducible = false;
    for(int i = n - 1; i >= 1; i--){
        if(nums[i - 1] < nums[i] - 1){
            if(reducible) continue;
            pos = false;
            break;
        }
        else{
            reducible = true;
        }
    }
    if(n == 1 && nums[0] > 1) pos = false;

    if(pos) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}