#include <bits/stdc++.h>

using namespace std;


const int maxmask = 4100;
const int INF = 1e9;
string str;
int c[12];
map<string, int> used;
int n;
int get_cost(int i){
    if(i == n) return 0;
    int min_cost = INF;
    for(int size = 1; size <= n - i; ++size){
        int next = 0;
        string substr = str.substr(i, size);
        if(used.count(substr) == 1 && used[substr] > 0) {
            next += 0;
        }
        else next+=c[size];
        used[substr]++;
        next+= get_cost(i + size);
        min_cost = min(min_cost, next);
        used[substr]--;
    }

    return min_cost;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> str;
    n = str.length();
    for(int i = 1; i <= n; ++i) cin >> c[i];

    cout << get_cost(0) << '\n';
    return 0;
}