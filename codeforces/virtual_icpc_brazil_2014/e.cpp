#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4 + 1;
const int INF = 1e9;

bool used[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;
    int temp;
    for(int i = 0; i < m; ++i){
        cin >> temp;
        used[temp] = true;
    }
    if(n == m) cout << "*\n";
    else{
        for(int i = 1; i <= n; ++i){
            if(!used[i]) cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}