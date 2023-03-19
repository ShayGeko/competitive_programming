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

vll binsum;
void solve(){
    ll n;
    cin >> n;
    ll cnt = 0;
    ll pw = 1;
    while(pw < n) {pw*=2; cnt++;}
    if(pw != n) cnt--;
    cout << n * (n + 1) / 2 - 2 * ((1ll << (cnt+1)) - 1)  << '\n';

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