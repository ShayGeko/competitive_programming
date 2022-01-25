#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 1e9;

int grid[MAXN][MAXN];
int untouchable[MAXN][MAXN];
int front[MAXN], side[MAXN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> grid[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        int max_front = 0, max_side = 0;
        for(int j = 1; j < m; ++j){
            if(grid[i][j] > max_front) max_front = grid[i][j];
            if(grid[j][i] > max_side) max_side = grid[j][i];
        }
        front[i] = max_front;
        side[i] = max_side;
    }

    return 0;
}