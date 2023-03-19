#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;

const int maxn = 1e5;
const int INF = 1e9;

void solve(){
    int m, n;

    cin >> m >> n;
    vi v(n);
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j) cin >> v[j];
    }

    if(m >= 8) cout << "satisfactory\n";
    else cout << "unsatisfactory\n";
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