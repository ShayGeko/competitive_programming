#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;
vector<int> graph[MAXN];
int used[MAXN];
int LRN[MAXN][2];
void dfs(int v){
    used[v] = true;
    LRN[v][1] = 1;
    LRN[v][0] = 0;
    for(auto to : graph[v]){
        if(!used[to]) {
            dfs(to);
            LRN[v][0] += LRN[to][1];
            LRN[v][1] += min(LRN[to][0], LRN[to][1]);
        }
    }
}
int main(){
    int n;

    while(cin >> n){
        if(n == 0) break;
        int j;
        for(int i = 0; i < n; ++i){
            cin >> j;
            graph[i].clear();
            used[i] = 0;
            int to;
            while(j--){
                cin >> to;
                graph[i].push_back(to - 1);
            }
        }
        int counter = 0;

        dfs(0);
        counter += max(min(LRN[0][0], LRN[0][1]), 1);

        cout << counter << '\n';
    }
    return 0;
}