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
    vi nums(n);
    for(int i = 0; i < n; ++i) scanf("%d", &nums[i]);
    priority_queue<pii> pq;
    vector<pii> order;

    int sum = 0;
    for(int i = 0; i < n; ++i){
            if(nums[i] > 0) pq.push({nums[i], i + 1});
            sum+=nums[i];
    }
    if(sum % 2){
        printf("no\n"); return;
    }
    while(pq.size() >= 2){
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        a.first--; b.first--;
        order.push_back({a.second, b.second});
        if(a.first) pq.push(a);
        if(b.first) pq.push(b);
    }
    if(pq.size() > 0) printf("no\n");
    else {
        printf("yes\n");
        for(auto p : order){
            printf("%d %d\n", p.first, p.second);
        }
    }
}
int main(){
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}