#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 20;
int n, m, k;
char fld[MAXN][MAXN];
int getMaxTickHeight(int i, int j){
    int height = 0;
    int l = j - 1, r = j + 1;
    int y = i - 1;
    while (l >= 0 && r < m && y >= 0 && // in bounds
           fld[y][l] == '*' && fld[y][r] == '*') // can make a bigger tick
    {
        // go up and "expand" tick
        l--; r++; y--;
        // increase tick height
        height++;
    }
    return height;
}

void drawTick(bool ticked[MAXN][MAXN], int i, int j, int height){
    int l = j;
    int r = j;
    int y = i;
    while(height-- >= 0){
        ticked[y][l] = ticked[y][r] = true;
        l--;r++; y--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;


    while(t--){
        // input
        cin >> n >> m >> k;
        for(int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cin >> fld[i][j];
        }


        bool ticked[MAXN][MAXN] = {false};
        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j < m; ++j){
                if(fld[i][j] == '*'){
                    int height = getMaxTickHeight(i, j);
                    if(height >= k){
                        drawTick(ticked, i, j, height);
                    }
                }
            }
        }

        bool fldValid = true;
        for(int i = 0; fldValid && i < n; ++i){
            for(int j = 0; fldValid && j < m; ++j){
                if(fld[i][j] == '*' && !ticked[i][j]){
                    fldValid = false;
                }
            }
        }

        if(fldValid) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}