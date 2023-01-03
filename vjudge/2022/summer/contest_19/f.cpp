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
    int n, p, q;
    cin >> n >> p >> q;
    p++; q++;
    vi p_path(p), q_path(q);
    for(int i = 0; i < p; ++i) cin >> p_path[i];
    for(int i = 0; i < q; ++i) cin >> q_path[i];

    unordered_map<int, int> pos_p; 

    for(int i = 0; i < p; ++i){
        pos_p[p_path[i]] = i;
    }

    vi order_q(q);

    int cnt = 1;

    for(int i = 0; i < q; ++i){
        if(pos_p.count(q_path[i])) order_q[i] = pos_p[q_path[i]];
        else order_q[i] = -cnt++;
    }

    vi dp(q, INF);

    dp[0] = -1;

    int maxi = 0;
    for(auto cur : order_q){
        int ins = upper_bound(dp.begin(), dp.end(), cur) - dp.begin();
        dp[ins] = cur; 
        if(ins > maxi) maxi = ins;
    }
    
    cout << maxi << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    cin >> t;
    
    int testnum = 1;
    while(t--){
        cout << "Case " << testnum++ << ": ";
        solve();
    }
    return 0;
}