#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
void solve(){
    string s;

    ll maxi = 0;
    int t;
    priority_queue<ll> pr;
    while(true){
        getline(cin, s);
        if(s.empty()) break;
        ll cur = 0;
        
        while(!s.empty()){
            t = stoi(s);
            cur +=t;
            
            getline(cin, s);
        }

        pr.push(cur);
    }

    ll sum = 0;
    for(int i = 0; i <3; ++i){
        ll t = pr.top();
        pr.pop();
        sum+=t;
    }
    cout << sum << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}