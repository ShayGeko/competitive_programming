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
    int n, k;
    cin >> n >> k;
    int len = 1 << n;
    vi v(len);
    for(int i = 0; i < len; ++i) cin >> v[i];
    
    sort(v.rbegin(), v.rend());

    int last_in_pool = 1;
    int l = 0, r = 0;
    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; ++i){
        last_in_pool += (1 << i);
        for(; j <= last_in_pool; ++j){
            while(v[i] - v[r] < k && r < last_in_pool) ++r;
            ans += r - i + 1;
        }
        
    }   
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