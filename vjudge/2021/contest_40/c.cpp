#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+1;
const int INF = 1e9;

vector<int> p, size;
vector<long long> sum;
map<int, int> relocation;
bool relocated[maxn];
int getRoot(int v){
    if(p[v] == -1) return v;
    return p[v] = getRoot(p[v]);
}
void unite(int v, int u){
    int a = getRoot(v);
    int b = getRoot(u);
    if(size[a] >= size[b]){
        p[b] = a;
        size[a] += size[b];
        sum[a]+= sum[b];
    }
    else{
        p[a] = b;
        size[b] += size[a];
        sum[b]+= sum[a];
    }
}
void move(int v, int u){
    int a = getRoot(v);
    int b = getRoot(u);
    if(a == b) return;

    relocated[v] = true;
    p.push_back(u);
    size.push_back(1);
    relocation.insert({v, p.size() - 1});
    size[a]--;
    sum[a]-=v;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    p.push_back(-1);
    size.push_back(1);
    sum.push_back(0);

    for(int i = 1; i <= n; ++i){
        p.push_back(-1);
        size.push_back(1);
        sum.push_back(i);
    }
    int requestType;
    int p, q;
    for(int i = 0; i < m; ++i){
        cin >> requestType;
        switch(requestType){
            case 1:{
                cin >> p >> q;
                unite(p, q);
            }
            break;
            case 2:{
                cin >> p >> q;
                move(p, q);
            }
            break;
            case 3:{
                cin >> p;
                int rp = getRoot(p);
                cout << size[rp] << " " << sum[rp] << '\n';
            }
            default: break;
        }
    }
    return 0;
}