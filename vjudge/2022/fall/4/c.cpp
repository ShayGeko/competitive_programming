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

vvi adj;
vector<bool> used;
vector<bool> inStack;
vi top_sort;
int n, m;
bool dfs(int v){
    used[v] = true;
    inStack[v] = true;
    for(auto to : adj[v]){
        if(!used[to]){
            if(!dfs(to)) return false;
        }
        else if(inStack[to]) return false;
        else continue;
    }
    top_sort.push_back(v);
    inStack[v] = false;
    return true;
}
void solve(){
    cin >> n >> m;
    adj.resize(n);
    used.resize(n, false);
    inStack.resize(n, false);

    int a, b;

    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
    }

    bool possible = true;
    for(int i = 0; possible && i < n; ++i){
        if(!used[i]) {
            possible &= dfs(i);
        }
    }

    reverse(top_sort.begin(), top_sort.end());

    if(possible){
        for(auto v : top_sort){
            cout << v+1 << " ";
        }
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
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