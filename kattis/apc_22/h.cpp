#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
ll p;

ll bin_pow(ll n, ll k){
    if(k == 0) return 1;
    if(k == 1) return n;

    ll half = bin_pow(n, k / 2);
    ll ans = (ll(half) * half) % p;
    if(k % 2) ans = (ans * n) % p;

    return ans;
}
void solve(){
    ll n;
    cin >> n >> p;
    if(n == 0) cout << 2 % p << '\n';
    else if (n == 1) cout << 4 % p << '\n';
    else{
        ll k = 4;
        ll pw = bin_pow(2, n - 1);
        cout << ((pw*k) % p + pw - 1) % p  << '\n';
    }
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