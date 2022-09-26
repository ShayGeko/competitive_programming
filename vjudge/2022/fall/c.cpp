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
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;
    return os;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vector<pii> segments(n);

    for(int i = 0; i < n; ++i){
        cin >> segments[i];
    }

    sort(segments.begin(), segments.end(), [](pii &a, pii&b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    
    // for(auto seg : segments){
    //     cout << "DEBUG| " << seg << '\n';
    // }
    int cnt = 0;
    int i = 0;
    while(i < n){
        auto cur = segments[i];
        ++cnt;
        ++i;
        while(i < n && segments[i].first <= cur.second) {
            ++i;
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