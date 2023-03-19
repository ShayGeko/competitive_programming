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
    int n, t;
    cin >> n >> t;
    int a,b;
    double mid = (n + 1) / 2.;
    while(t--){
        if(n % 2 == 0) cout << 2 << '\n';
        else cout << 1 << '\n' << (int)mid << " " << (int)mid <<"\n";
        cout << flush;
        while(true){
            cin >> a >> b;
            if(a == 0 && b == 0) break;
            else if(a == -1 && b == -1) return;
            else{
                cout << int(a + 2*(mid-a)) << " " << int(b+2*(mid-b)) << '\n';
                cout << flush;
            }
        }
    }
}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}