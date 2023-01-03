#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    ull n, k;
    cin >> n >> k;
    vector<ull> m(n), w(n);
    for(int i = 0; i < n; ++i){
        cin >> m[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> w[i];
    }
    sort(m.rbegin(), m.rend());
    sort(w.rbegin(), w.rend());
    if(w[0] < m[0]) swap(w[0], m[0]);

    if(w[0]-m[0] < k){
        k -= w[0] - m[0];
        m[0] = w[0];
        w[0] += k/2;
        m[0] += k/2;
        w[0] += k%2;
    }
    else m[0]+=k;
    ull sum = 0;

    for(int i = 0; i < n; ++i){
        sum = (sum + (w[i]*m[i]) % p)%p;
    }

    cout << sum << '\n';
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