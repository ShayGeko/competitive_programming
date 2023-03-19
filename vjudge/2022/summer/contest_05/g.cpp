#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 1e9;

int n;
typedef struct node{
    vector<node*> concaters;
    string str;

    node(string &str): str(str){}
    void concat(node* x){
        concaters.push_back(x);
    }
    void print(){
        cout << str;
        for(auto conc : concaters){
            conc->print();
        }
    }
} concater;


vector<concater*> concaters;
void solve(){
    int n;
    string str;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> str;
        concaters.push_back(new concater(str));
    }
    int a, b;
    for(int i = 1; i < n - 1; ++i){
        cin >> a >> b;
        concaters[a-1]->concat(concaters[b-1]);
    }
    cin >> a >> b;
    concaters[a-1]->concat(concaters[b-1]);
    concaters[a-1]->print();
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    
    while(t--){
        solve();
    }
    return 0;
}