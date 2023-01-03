#include <bits/stdc++.h>

using namespace std;

// Header files, namespaces,
// macros as defined above
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

istream &operator >> (istream& is, pii &p){
    cin >> p.first >> p.second;
    return is;
}

pii operator + (pii& a, pii &b){
    return {a.first + b.first, a.second + b.second};
}
const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

vi d;

string str;
int getDepth(int v){
    if(d[v]) return d[v];
    d[v] = 1;

    if(str[v] == 'L'){
        getDepth(v+1);
        d[v] += d[v+1];
    }

    return d[v];
}
void solve(){
    int n;
    cin >> n;
    cin >> str;

    d.resize(n, 0);

    for(int i = 0; i < n; ++i){
        if(d[i] == 0) getDepth(i);
    }
 
    ordered_set houses;

    for(int i = 1; i <= n; ++i)
        houses.insert(i);

    for(int i = 0; i < n; ++i){
        auto house_num = houses.find_by_order(d[i] - 1);

        cout << *house_num << '\n';
        houses.erase(house_num);
    }

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