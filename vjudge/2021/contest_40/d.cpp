#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
set<int> closed;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int n, s, k;
    while(t--){
        cin >> n >> s >> k;

        int temp;
        closed.clear();
        for(int i = 0; i < k; ++i){
            cin >> temp;
            closed.insert(temp);
        }
        if(closed.find(s) == closed.end()){
            cout << "0\n";
            continue;
        }

        int cnt = 1;
        while((s - cnt <= 0 || closed.find(s - cnt) != closed.end()) && (s + cnt > n || closed.find(s + cnt) != closed.end())) ++cnt;
        cout << cnt << '\n';
    }
    return 0;
}