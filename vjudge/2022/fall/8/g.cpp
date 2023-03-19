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
ostream &operator << (ostream& os, pii &p){
    cout << p.first << " " << p.second;
    return os;
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;

bool check(vector<pii> rect){
    if(rect[1].second != rect[2].second) return false;
    
    if(rect[0].first == rect[1].first + rect[2].first  && rect[0].second + rect[1].second == rect[0].first){
        return true;
    }

    if(rect[0].second == rect[1].second && rect[0].first + rect[1].first + rect[2].first == rect[0].second){

        return true;
    }

    return false;
}
void print(vector<pii> rect){
    cout << " DEBUG| " << rect[0] << " | " << rect[1] << " | " << rect[2] << '\n';
}
void solve(){
    vector<pii> rect(3);
    cin >> rect[0] >> rect[1] >> rect[2];
    for(int t = 1; t <= 3; ++t){
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                for(int k = 0; k < 2; ++k){
                    if(check(rect)){
                        cout << "YES\n";
                        return;
                    }
                    swap(rect[2].first, rect[2].second);
                }
                swap(rect[1].first, rect[1].second);
            }
            swap(rect[0].first, rect[0].second);
        }
        if(t < 3) swap(rect[0], rect[t]);
    }
    cout << "NO\n" << '\n';
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