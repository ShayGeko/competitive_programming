#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 1;
const int INF = 1e9;
priority_queue<int> r;
vector<int> removals[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, d;
    cin >> d >> n;
    for(int i = 1; i <= n; ++i){
        r.push(-i);
    }
    char request;
    int num;
    for(int i = 1; i <= n; ++i){
        for(auto rem : removals[i]){
            r.push(-rem);
        }
        cin >> request;
        if(request == 'a'){
            cout << -r.top() << '\n';
            r.pop();
        }
        else{
            cin >> num;
            if(i + d <= n) removals[i + d].push_back(num);
        }
    }
    return 0;
}