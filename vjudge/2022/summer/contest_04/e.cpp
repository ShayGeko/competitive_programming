#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int maxn = 16;
const int INF = 1e9;

vi edges;
int d[3601];
void bfs(int k){
    queue<int> q;
    int cur;
    q.push(0);
    d[0] = 0;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(auto btn : edges){
            if(cur + btn <= 3600 && cur + btn > 0 && !d[cur + btn]) {
                q.push(cur + btn);
                d[cur + btn] = d[cur] + 1;
                if(cur + btn == k){
                    return;
                }
            }
            else if(cur + btn > 3600){
                if(!d[3600]){
                    d[3600] = d[cur] + 1;
                    if(k == 3600) return;
                    q.push(3600);
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    int n,k;
    int temp;
    int cnt;
    while(t--){
        cin >> n >> k;
        edges.clear();
        for(int i = 0; i < n; ++i){
            cin >> temp;
            edges.push_back(temp);
        }
        if(k == 0){
            cout << "0 0\n";
            continue;
        }
        memset(d, 0, sizeof(d));
        bfs(k);
        if(d[k]){
            cout << d[k]<< " " <<  0 << '\n';
        }
        else{
            cnt = 1;
            while(!d[k + cnt] && k + cnt <= 3600){
                ++cnt;
            }
            cout << d[k + cnt] << " " << cnt << '\n';
        }
    }
    return 0;
}