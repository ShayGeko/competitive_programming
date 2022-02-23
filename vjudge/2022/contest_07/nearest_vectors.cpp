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
    int n;
    cin >> n;
    pair<long double, long double> v;
    
    vector<pair<long double, int>> angles;

    for(int i = 0; i < n; ++i){
        cin >> v.first >> v.second;
        long double x = v.first, y = v.second;
        long double at = atan2(v.second,v.first);

        angles.push_back({at, i + 1});

    }

    sort(angles.begin(), angles.end());

    long double mini = 10;
    int a, b;
    for(int i = 1; i < n; ++i){
        if(angles[i].first - angles[i-1].first < mini){
            mini = min(mini, angles[i].first - angles[i-1].first);
            a = angles[i-1].second;
            b = angles[i].second;
        }
    }
    if(angles[0].first - angles[n - 1].first + atan(1)*8 < mini){
            a = angles[0].second;
            b = angles[n-1].second;
    };

    cout << a << " " << b << '\n';

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