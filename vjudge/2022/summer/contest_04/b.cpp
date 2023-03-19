#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a, b;
    cin >> a >> b;

    if(b % 2 == 0){
        cout << "possible\n";
    }
    else cout << "impossible\n";
    
    return 0;
}