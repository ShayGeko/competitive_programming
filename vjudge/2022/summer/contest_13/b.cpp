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
    int a, b, c, d, t;
    cin >> a >> b >> c >> d >> t;

    int mini = abs(c - a) + abs(d - b);
    if(t >= mini && (t-mini) % 2 == 0) cout << "Y\n";
    else cout << "N\n";
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