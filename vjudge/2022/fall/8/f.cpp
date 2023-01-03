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
    int n, k, r;
    cin >> n >> k >> r;

    vector<bool> hasCamera(n, false);
    for(int i = 0; i < k; ++i){
        int a;
        cin >> a;
        hasCamera[a-1]=true;
    }

    int sum = 0;
    int needToAdd = 0;
    for(int i = 0; i < r; ++i){
        sum += hasCamera[i];
    }
    while(sum < 2){
        if(!hasCamera[r-1]) hasCamera[r-1]=true;
        else hasCamera[r-2] = true;
        ++sum;
        ++needToAdd;
    }
    for(int i = r; i < n; ++i){
        sum -= hasCamera[i-r];
        sum += hasCamera[i];

        if(sum < 2){
            hasCamera[i] = true;
            ++sum;
            ++needToAdd;
        }
    }

    cout << needToAdd << '\n';
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