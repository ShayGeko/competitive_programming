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

vector<vvi> cost;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }

    string s;
    cin >> s;

    
    cost = vector<vvi>(n, vvi(m, vi(s.size() + 1, INF)));

    vi r, e;

    int best = INF;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j] == 'R')
                r = {i, j, 0};
            else if(grid[i][j] == 'E')
                e = {i, j};
        }
    }

    cost[r[0]][r[1]][r[2]] = 0;

    priority_queue<vector<int>> pr;

    // cost, i, j, pos
    vi inState = {0, r[0], r[1], r[2]};

    unordered_map<char, pii> moves = {
        {'D',{1, 0}},
        {'R',{0, 1}},
        {'U', {-1, 0}},
        {'L', {0, -1}}
    };

    pr.push(inState);

    while(!pr.empty()){
        auto v = pr.top(); pr.pop();
        while(cost[v[1]][v[2]][v[3]] < v[0]){
            v = pr.top();
            pr.pop();
        }


        if(v[1] == e[0] && v[2] == e[1]){
            best = min(best, v[0]);
            continue;
        }

        
        if(v[3] >= s.size()) continue;

        // add a move
        for(auto t : moves){
            auto mv = t.second;
            auto temp = v;
            temp[1] += mv.first;
            temp[2] += mv.second;
            temp[0]++;

            // don't add a move if bumping
            if(temp[1] >= 0 && temp[1] < n && temp[2] >= 0 && temp[2] < m){
                if(grid[temp[1]][temp[2]] != '#'){
                    if(cost[temp[1]][temp[2]][temp[3]] > temp[0]){
                        pr.push(temp);
                        cost[temp[1]][temp[2]][temp[3]] = temp[0];
                    }
                }
            }
        }

        // take a move

        if(v[3] < s.size()){
        auto temp = v;
        // get the next instruction
        auto mv = moves[s[v[3]]];
        temp[1]+=mv.first;
        temp[2]+=mv.second;
        temp[3]++;

        // bumping into stuff
        if(temp[1] < 0 || temp[1] >= n || temp[2] < 0 || temp[2] >= m || grid[temp[1]][temp[2]] == '#'){
                temp[1] = v[1];
                temp[2] = v[2];
        }
        if(cost[temp[1]][temp[2]][temp[3]] > temp[0]){
            pr.push(temp);
            cost[temp[1]][temp[2]][temp[3]] = temp[0];
        }
        }
        // delete a move
        auto temp = v;
        temp[0]++;
        temp[3]++;

        if(cost[temp[1]][temp[2]][temp[3]] > temp[0]){
            pr.push(temp);
            cost[temp[1]][temp[2]][temp[3]] = temp[0];
        }
    }

    cout << best << '\n';


    // int mini = INF;
    // 
    // for(int i = 0; i < n; ++i){
    //     for(int j = 0; j < m; ++i){
    //         int mini = INF;
    //         for(int t = 0; t < s.size(); ++t){
    //             mini = min(mini, cost[i][j][t]);
    //         }
    //     }
    // }
    // cout << '\n';
    // 
    // cout << mini << '\n';
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