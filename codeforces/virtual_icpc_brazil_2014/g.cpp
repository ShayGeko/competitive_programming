#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int maxn = 1e5;
const int INF = 1e9;

int n, m;
vvi matrix;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    cin >> n >> m;

    matrix.resize(n);
    for(int i = 0; i < n; ++i){
        matrix[i].resize(m);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> matrix[i][j];
        }
    }

    int temp;
    int lower, upper, rownum, colnum;
    vi rows;
    vi columns;
    bool fine = true;
    for(auto row : matrix){
        if(!fine) break;
        temp = row[0];
        rownum = (temp + m - 1) / m;
        rows.push_back(rownum);
        lower = (rownum - 1) * m + 1;
        upper = rownum * m;
        for(int i = 0; i < m && fine; ++i){
            if(row[i] < lower || row[i] > upper) fine = false;
        }
    }
    for(int i = 0; fine && i < m; ++i){
        temp = matrix[0][i];
        colnum = temp % m;
        for(int j = 1; j < n && fine; ++j){
            if(matrix[j][i] % m != colnum) fine = false;
        }
        if(colnum == 0) colnum = m;
        columns.push_back(colnum);
    }
    if(!fine){
        cout << '*';
        return 0;
    }
    int rowswaps = 1;
    int colswaps = 1;
    for(int i = 0; i < n; ++i){
        if(rows[i] != (i + 1)) ++rowswaps;
    }
    for(int i = 0; i < m; ++i){
        if(columns[i] != (i + 1)) ++colswaps;
    }
    cout << rowswaps / 2 + colswaps/ 2 ;
    return 0;
}