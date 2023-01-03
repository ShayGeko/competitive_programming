#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

vvi adj;
vector<pair<ll, ll>> wb;

void dfs(int v, int pr){
    pair<ll, ll> cur = {1, 1};
    for(auto to : adj[v]){
        if(to == pr) continue;
        dfs(to, v);
        cur.first = (cur.first * (wb[to].first + wb[to].second)) %p;
        cur.second = (cur.second * wb[to].first) % p;
    }

    wb[v] = cur;
}
void solve(){
    int n;
    cin >> n;
    adj.resize(n);
    wb.resize(n);

    int a, b;
    for(int i = 0; i < n-1; ++i){
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    dfs(0, -1);

    cout << (wb[0].first + wb[0].second) % p << endl;
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