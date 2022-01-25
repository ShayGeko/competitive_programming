#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100, MAXW = 1e5 + 1;

long long knapsack[MAXW];
bool reachable[MAXW];
int w[MAXN], v[MAXN];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

   int n, W;
   cin >> n >> W;

   for(int i = 0; i < n; ++i){
        cin >> w[i] >> v[i];
   }

   reachable[0] = true;
   for(int i = 0; i < n; ++i){
        for(int j = W; j >=0; j--){
            if(reachable[j] && j + w[i] <= W){
                reachable[j + w[i]] = true;
                knapsack[j + w[i]] = max(knapsack[j + w[i]], knapsack[j] + v[i]);
            }
        }
   }

   long long ans = 0;
   for(int i = 0; i <= W; ++i){
        ans = max(ans, knapsack[i]);
   }
   cout << ans << '\n';

    return 0;
}