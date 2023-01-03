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

    vi t(n), d(n);
    
    for(int i = 0; i < n; ++i){
        cin >> t[i] >> d[i];
    }
    for(int i = n - 1; i > 0; i--) t[i] = t[i] - t[i-1];
    int cnt = 0;
    ll sum = 0;
    priority_queue<int> damages;

    for(int i = 0; i < n; ++i){
        damages.push(d[i]);
        sum = sum + t[i] - d[i];
        if(sum < 0){
            int max_dmg = damages.top();
            damages.pop();
            sum += max_dmg;
            ++cnt;
        }
    }

    cout << cnt << '\n';

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