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
void solve(){
    vector<int> s;
    queue<int> q;
    priority_queue<int> pq;

    bool is = true, iq = true, ipq = true;


    int r, num;
    int cur;
    int cnt = 3;
    for(int i = 0; i < n; ++i){
        cin >> r >> num;
        if(r == 1){
            if(is) s.push_back(num);
            if(iq) q.push(num);
            if(ipq) pq.push(num);
        }
        else{
            if(is){
                if(!s.size()) {
                    is = false;
                }
                else{
                cur = s.back();
                s.pop_back();
                is = cur == num;
                }
                if(!is) cnt--;
            }
            if(iq){
                if(!q.size()) {
                    iq = false;
                }
                else{
                cur = q.front();
                q.pop();
                iq = cur == num;
                }
                if(!iq) cnt--;
            }
            if(ipq){
                
                if(!pq.size()) {
                    ipq = false;
                }
                else{
                cur = pq.top();
                pq.pop();
                ipq = cur == num;
                }
                if(!ipq) cnt--;
            }
        }
    }

    if(!(is || iq || ipq)) cout << "impossible\n";
    else if(cnt > 1) cout << "not sure\n";
    else if(is) cout << "stack\n";
    else if(iq) cout << "queue\n";
    else cout << "priority queue\n";
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    
    while(cin >> n){
        solve();
    }
    return 0;
}