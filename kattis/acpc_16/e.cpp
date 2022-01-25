#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
char grid[maxn][maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    int n, m;
    for(int k = 1; k <= t; ++ k) {
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                cin >> grid[i][j];
            }

        cout << "Test " << k << '\n';
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}