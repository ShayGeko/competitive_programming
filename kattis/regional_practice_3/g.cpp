#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e5;
const int INF = 2e9;


typedef struct{
    int x;
    bool isAdd;
    pii segment;
} request;

bool operator< (const request &a, const request &b){
    return a.x < b.x;
}

    
set<pii> sweep_line;
int len = 0;
int addToSweep(pii segment){

    if(sweep_line.size() == 0){
        sweep_line.insert(segment);
        return len+=segment.second - segment.first;
    }

    auto l = sweep_line.lower_bound({segment.first, 0});
    auto r = sweep_line.lower_bound({segment.second, 0});
    if(l == sweep_line.end()){
        l--;
        pii temp = *l;
        if(temp.second > segment.first){
            sweep_line.erase(temp);
            len -= temp.second - temp.first;
            temp.second = max(segment.second, segment.first);
            return len += temp.second - temp.first;
        }
        else {
        sweep_line.insert(segment);
        return len+=segment.second - segment.first;
        }
    }
    else if(r == sweep_line.begin()){
        sweep_line.insert(segment);
        return len+= segment.second - segment.first;
    }
    else{
        if(r == l){
            return len;
        }
        else{
            pii li = *l;
            pii ri = *r;
            sweep_line.erase(li);
            sweep_line.erase(ri);
            pii temp;
            len -= (li.second - li.first);
            len -= (ri.second - ri.first);
            temp.first = li.first;
            temp.second = ri.second;
            sweep_line.insert(temp);
            return len += (temp.second - temp.first);
        }
    }
    
}

void solve(){
    int n;
    int a, b, c, d;
    vector<pair<pii, pii>> rectangles;

    
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c >> d;
        rectangles.push_back({{a,b},{c,d}});
    }
    vector<request> requests;
    for(auto r : rectangles){
        requests.push_back({r.first.second, true, {r.first.first, r.second.first}});
        requests.push_back({r.second.second, false, {r.first.first, r.second.first}});
    }
    sort(requests.begin(), requests.end());

    int ans = 0;
    int prev = requests[0].x;
    multiset<pii> current;
    for(auto r : requests){
        ans += len * (r.x - prev);
        if(r.isAdd){
            addToSweep(r.segment);
            current.insert(r.segment);
        }
        else{
            auto hit = current.find(r.segment);
            current.erase(hit);
            sweep_line.clear();
            pii t = {0,0};
            len = 0;
            for(auto seg : current){
                if(seg.first > t.second){
                    sweep_line.insert(t);
                    len+= t.second - t.first;
                    t.first = seg.first;
                    t.second = seg.second;
                }
                else t.second = max(t.second, seg.second);
            }
            sweep_line.insert(t);
            len+= t.second - t.first;
        }
        prev = r.x;
    }

    cout << ans << '\n';
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