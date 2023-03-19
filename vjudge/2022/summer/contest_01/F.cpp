#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;
const long long INF = 1e9;
const int p = 1e9 + 7;
int N;
int graph[maxn][maxn];
void multiply(int A[maxn][maxn], int B[maxn][maxn], int res[maxn][maxn]){
    int temp[maxn][maxn];

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            temp[i][j] = 0;
            for(int k = 0; k < N; ++k){
                temp[i][j] = (temp[i][j] + ((long long)A[i][k] * B[k][j]) % p) % p;
            }
        }
    }for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            res[i][j] = temp[i][j];
        }
    }
}
void matrix_pow(int A[maxn][maxn], int res[maxn][maxn], long long n){
    if(n == 1){
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                res[i][j] = A[i][j];
            }
        }
        return;
    }
    matrix_pow(A, res, n/2);
    multiply(res, res, res);
    if(n % 2){
        multiply(res, A, res);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    N = n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    int paths_k[maxn][maxn];
    matrix_pow(graph, paths_k, k);
    int sum = 0;
    for(int i = 0; i < n;++i){
        for(int j = 0; j < n; ++j){
            sum = (sum + paths_k[i][j]) % p;
        }
    }
    cout << sum << '\n';
    return 0;
}