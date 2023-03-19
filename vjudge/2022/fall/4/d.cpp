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
vector<bool> used;
vector<bool> inStack;
vi top_sort;
int n, m;
void solve(){
    int n, m, z;
    cin >> n >> m >> z;
    vector<vector<ull>> graph(n, vector<ull>(n, ULLONG_MAX));


    int a, b;
    ull c;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        a--;b--;
        graph[b][a] = min(graph[b][a], c);
        graph[a][b] = graph[b][a];
    }

    for(int i = 0; i < n; ++i) graph[i][i] = 0;
    
    for(int k = 0; k < n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if (graph[i][k] < ULLONG_MAX && graph[k][j] < ULLONG_MAX){
                    ull sum = graph[i][k] + graph[k][j];
                    graph[i][j] = min(graph[i][j], sum);
                }
            }
        }
    }

    for(int i = 0; i < z; ++i){
        cin >> a >> b;
        a--; b--;

        if(graph[a][b] < ULLONG_MAX) cout << graph[a][b];
        else cout << -1;
        cout << '\n';
    }
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