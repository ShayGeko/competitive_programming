#include <iostream>

using namespace std;

const int MAXN = 1e5 + 1;
int arr[MAXN][3];

int main(){
    int n;

    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> arr[i][j];
        }
    }
    int dp[MAXN][3] = {0};
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 3; ++k){
                if(k == j) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + arr[i][j]);
            }
        }
    }
    int answer = 0;

    for(int i = 0; i < 3; ++i)
        answer = max(answer, dp[n - 1][i]);

    cout << answer << '\n';
    return 0;
}