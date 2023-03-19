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
    vector<ll> h(n);

    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }


    ll maxi = 0;

    int i = 0;
    ll mini = h[0];
    while(i < n){
        while(i + 1 < n && h[i+1] >= h[i]){ ++i;}
        ll curm = h[i];
        while(i + 1 < n && h[i+1] <= h[i]) {++i;}

        mini = max(mini, h[i]);
        maxi = max(maxi, curm - mini);

        mini = h[i];
        
        ++i;
    }

    cout << maxi << '\n';
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