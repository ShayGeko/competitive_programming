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
void solve(int h, int t){
    if(h == 1 && t == 0) cout << "-1\n";
    else{
        bool hodd = h%2, todd = t%2;
        int cnt = 0;
        if(todd){
            ++cnt;
            todd = false;
            ++t;
        }
        if((h + t / 2) % 2){
            cnt+=2;
            t+=2;
        }
        cnt += (h + t/2) / 2 + t / 2;
        cout << cnt << '\n';
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    //cin >> t;
    pii term = {0,0}, cur;
    while(cin >> cur && cur != term){
        solve(cur.first, cur.second);
    }
    return 0;
}