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
    vi values(n);
    for(int i = 0; i < n; ++i) cin >> values[i];
    
    ll sum = 0;
    for(int i = 0; i < n; ++i) sum += values[i];
    
    sort(values.begin(), values.end());
    set<ll> badges;
    ll final_sum = 0;

    for(int i = 0; i < n; ++i){
        int cur = values[i];
        
        auto it = badges.find(cur);
        if(it == badges.end()){
            final_sum +=cur;
            badges.insert(cur);
        }
        else{
            // find end of the current run
            auto res = adjacent_find(it,badges.end(), [](int a, int b){ return a+1 != b; } );
            if(res == badges.end()) --res;
            // set the value to (largest in run) + 1
            cur = (*res) + 1;
            final_sum += cur;
            badges.insert(cur);
        }
    }

    cout << final_sum - sum << '\n';
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