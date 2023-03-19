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
    int n, k;
    cin >> n >> k;
    vi nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];

    priority_queue<int> st;

    for(int i = 0; i < k; ++i){
        st.push(-nums[i]);
    }

    ll time = 0;
    ll sum = 0;
    for(int i = k; i < n; ++i){
        time -= st.top();
        st.pop();
        sum += time;

        st.push(-nums[i]);
    }

    while(!st.empty()){
        time -= st.top();
        st.pop();
        sum += time;
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