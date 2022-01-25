#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int a;
    int b;
} cell;
typedef struct{
    int left;
    int right;
    int top;
    int bottom;
    int front;
    int back;
} cube;
typedef struct{
    cell cel;
    cube cub;
} position;


const int maxn = 20;
char grid[maxn][maxn];
int dp[maxn][maxn][7][7];
bool visited[maxn][maxn][7][7];


cube left(cube a){
    cube l;
    l.top = a.right;
    l.bottom = a.left;
    l.front = a.front;
    l.back = a.back;
    l.left = a.top;
    l.right = a.bottom;

    return l;
}
cube right(cube a){
    cube l;
    l.top = a.left;
    l.bottom = a.right;
    l.front = a.front;
    l.back = a.back;
    l.left = a.bottom;
    l.right = a.top;

    return l;
}
cube up(cube a){
    cube l;
    l.top = a.front;
    l.bottom = a.back;
    l.front = a.bottom;
    l.back = a.top;
    l.left = a.left;
    l.right = a.right;

    return l;
}
cube down(cube a){
    cube l;
    l.top = a.back;
    l.bottom = a.front;
    l.front = a.top;
    l.back = a.bottom;
    l.left = a.left;
    l.right = a.right;

    return l;
}
pair<int, int> start, home;
int n;
void walk(){
   queue<position> q;
    cell c;
    c.a = start.first;
    c.b = start.second;
    cube cub;
    cub.top = 1;
    cub.right = 2;
    cub.bottom = 6;
    cub.left = 5;
    cub.back = 4;
    cub.front = 3;
    position pos;
    pos.cub = cub;
    pos.cel = c;
    q.push(pos);

    visited[c.a][c.b][1][5] = true;

    vector<pair<int, int>> steps = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<cube (*)(cube)> cube_rotations = {&up, &left, &down, &right};

    while(!q.empty()){
        auto pos = q.front();
        q.pop();

        auto v = pos.cel;
        auto c = pos.cub;
        // go over 4 possible rotations: up, left, down, right
        for(int i = 0; i < 4; ++i){
            auto cel = v;
            // get the corresponding adjacent cell
            cel.a += steps[i].first;
            cel.b += steps[i].second;
            // out of bounds
            if(cel.a < 0 || cel.a > n - 1 || cel.b < 0 || cel.b > n - 1) continue;
            // cant go here
            if(grid[cel.a][cel.b] == '*') continue;

            // get the new cube configuration
            auto rotate = cube_rotations[i];
            cube cub = rotate(c);
            if(!visited[cel.a][cel.b][cub.top][cub.left]){
                visited[cel.a][cel.b][cub.top][cub.left] = true;
                position new_pos;
                new_pos.cel = cel;
                new_pos.cub = cub;
                q.push(new_pos);
            }
        }
    }

}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j){
                cin >> grid[i][j];
                if(grid[i][j] == 'S') start = {i,j};
                else if (grid[i][j] == 'H') home = {i, j};
                for(int k = 1; k <= 6; ++k)
                    for(int l = 1; l <= 6; ++l)
                        visited[i][j][k][l] = false;
            }

        walk();

        bool possible = false;
        for(int i = 1; i <= 6; ++i)
            // when 5 is bottom, 2 is top
            possible |= visited[home.first][home.second][2][i];

        if(possible) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}