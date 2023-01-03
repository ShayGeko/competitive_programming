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
    vi a(6), b(6);
    for(int i = 0; i < 6; ++i) cin >> a[i];
    for(int i = 0; i < 6; ++i) cin >> b[i];

    double sum = 0;
    double same_cnt = 0;
    for(int i = 0; i < 6; ++i){
        for(int j = 0; j < 6; ++j){
            if(a[i] > b[j]) ++sum;
            else if(a[i] == b[j]) ++same_cnt;
        }
    }


    cout << fixed << setprecision(5) << sum / (36. - same_cnt) << '\n';
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