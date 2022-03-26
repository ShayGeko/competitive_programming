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
    double a, b, c, d;
    cin >> a >> b >> c >> d;

    double x = (d - b) / (a - c);
    double x1 = -a /  2.;
    double y1 = -a /  2.;
    double x2 = -c / 2;
    cout << x << " " << x*x + a*x + b<< '\n';

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