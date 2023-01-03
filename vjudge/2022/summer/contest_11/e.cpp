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

bool holey[12][12] = {false};
int getNums(int row, vector<int> &cols, vector<int> &diag1, vector<int> &diag2){
    if(row == n) return 1;
    int cnt = 0;
    for(int col = 0; col < n; ++col){
        if(holey[row][col]) continue;
        else if(cols[col] && diag1[row + col] && diag2[n - 1 + row - col]){
            cols[col] = diag1[row+col] = diag2[n - 1 + row-col] = 0;
            cnt += getNums(row + 1, cols, diag1, diag2);
            cols[col] = diag1[row+col] = diag2[n - 1 + row-col] = 1;
        }
    }
    return cnt;
}
void solve(int m){

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j) 
            holey[i][j] = false;
    }
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        holey[a][b] = true;
    }

    vector<int> cols(n, 1), diag1(2*n - 1, 1), diag2(2*n - 1, 1); 

    int total = getNums(0, cols, diag1, diag2);

    cout << total << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    int m;
    while(cin >> n){
        cin >> m;
        if(n == 0 && m == 0) return 0;
        solve(m);
    }
    return 0;
}