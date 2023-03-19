#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 1e5;
const int INF = 1e9;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        set<string> a;
        int n;
        string s;
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> s; 
            a.insert(s);
        }
        cout << a.size() << '\n';
    }
    return 0;
}