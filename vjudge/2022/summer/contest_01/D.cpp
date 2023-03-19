#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;
const int INF = 1e9;

int arr[maxn][maxn];
bool used[maxn][maxn];
vector<pair<pair<int,int>, pair<int,int>>> steps;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
        }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(j < m - 1 && arr[i][j] % 2){
                steps.push_back({{i+1, j+1}, {i+1, j+2}});
                arr[i][j]--;
                arr[i][j+1]++;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(i < n - 1 && arr[i][m - 1] % 2){
            steps.push_back({{i+1, m}, {i+2, m}});
            arr[i][m-1]--;
            arr[i+1][m-1]++;
        }
    }
    cout << steps.size() << '\n';
    for(auto step : steps){
        cout << step.first.first << " " << step.first.second << " ";
        cout << step.second.first << " " << step.second.second << '\n';
    }

//    for(int i = 0; i < n; ++i){
//        for(int j = 0; j < m; ++j){
//            cout << arr[i][j] << " ";
//        }
//        cout << '\n';
//    }
    return 0;
}