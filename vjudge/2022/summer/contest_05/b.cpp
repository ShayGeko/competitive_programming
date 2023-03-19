#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vll;

const int maxn = 1e5;
const int INF = 1e9;

void solve(){
    int n;
    cin >> n;
    vector<bool> days(366,false);
    int temp;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        days[temp]=true;
    }
    int num_days = 0;
    int score = 0;
    int cnt = 0;
    int i = 1;
    for(; i <= 365; ++i){
        // add a dirty commit
        if(days[i])++num_days;

        // if overflows today, gotta do a cleanup
        if(score + num_days >= 20){
            ++cnt;
            score = 0;
            num_days = 0;
        }
        
        // debt added at the end of the day
        score +=num_days;
    }
    if(score)++cnt;

    cout << cnt << '\n';
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