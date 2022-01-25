#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
typedef struct{
    int to;
    int from;
    int flow;
    int capacity;
} edge;
const int MAXN = 50;
const int INF = 1e9;

int arr[MAXN], minStepsToZero[MAXN];
bool used[MAXN];
bool bfs(int graph[MAXN][MAXN], int s, int t, int p[MAXN]){
    queue<int> k;
    k.push(s);
    int used[MAXN] = {0};
    p[s] = -1;
    int u;
    while(!k.empty()){
      u = k.front();
      k.pop();

      for(int v = 0; v < MAXN; ++v){
          if(!used[v] && )
      }

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int arr[MAXN][MAXN];
    int n, m;
    int k;
    while(t--){
        cin >> n >> m >> k;

    }
    return 0;
}