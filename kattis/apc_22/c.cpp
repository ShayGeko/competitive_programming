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

unordered_map<int, int> diag1;
unordered_map<int, int> diag2;
void dfs(){
    
}
void solve(){
    int n;
    cin >> n;
    vi nums(n);
    int sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
        sum+=nums[i];
    }
    set<int> s;
    for(auto num : nums){
        s.insert(sum - num);
    }
    cout << s.size() << '\n';
    for(auto num : s){
        cout << num << " ";
    }
    cout << '\n';

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