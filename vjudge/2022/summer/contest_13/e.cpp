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

int n;
vvi adj;

/*
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
*/
vector<char> coloring;
int getHeight(int v, int p, int depth = 0){
    for(auto to : adj[v]){
        if(to == p) continue;
        depth = max(depth, getHeight(to, v, depth) + 1);
    }
    cout << v << " " << depth + 1 << '\n';
    return depth;
}
void color(int v, int p, char c){
    coloring[v] = c;
    for(auto to : adj[v]){
        if(to == p) continue;
        color(to, v, c + 1);
    }
}
void outputColoring(){
    for(auto c : coloring){
        cout << c << " ";
    }
    cout << '\n';
}
void solve(){
    cin >> n;
    adj.resize(n);
    for(int i = 0; i < n - 1; ++i){
        int a,b;
        cin >> a >> b;
        adj[a - 1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    // leaves
    queue<int> q;
    cout << "leaves: ";
    for(int i = 0; i < n; ++i){
        if(adj[i].size() == 1){
            cout << i << " ";
            q.push(i);
        }
    }
    cout << '\n';
    vector<bool> used(n, false);
    while(q.size() > 1){
        auto v = q.front();
        // cout << v << '\n';
        q.pop();
        used[v] = true;
        for(auto to: adj[v]){
            if(!used[to]){
                q.push(to);
                used[to] = true;
            }
        }
    }
    
    coloring.resize(n);
    int v = q.front();
    cout << v << '\n';
    cout << getHeight(v, -1) << '\n';
    q.pop();
    if(getHeight(v, -1) <= 26){
        color(v, -1, 'A');
        outputColoring();
    }
    else if(q.size() == 1){    
        int v = q.front();
        q.pop();
        cout << v << '\n';
        cout << getHeight(v, -1) << '\n';
        if(getHeight(v, -1) <= 26){
            color(v, -1, 'A');
            outputColoring();
        }
        else cout << "Impossible\n";
    }
}
int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}