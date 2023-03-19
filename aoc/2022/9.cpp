#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

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

int tt = 2500;

vector<pii> rope(10, {tt/2, tt/2});

bool isTouch(int ih, int jh, int it, int jt){
    return abs(it - ih) < 2 && abs(jt - jh) < 2;
}
void solve(){
    vector<pair<char, int>> cm;

    char c;
    int m;
    while(cin >> c){
        cin >> m;
        cm.push_back({c,m});
    }
    
    cout << "done reading\n";

    vector<vector<bool>> vvb (tt, vector<bool>(tt, false));

    vvb[tt/2][tt/2] = true;

    for(auto mv : cm){
        char c = mv.first;
        // cout << "next step " << mv.first << " " << mv.second << '\n';
        for(int t = 0; t < mv.second; ++t){
            if(c == 'R') {
                rope[0].second++;
            }
            else if(c == 'L') rope[0].second--;
            else if(c == 'U') rope[0].first++;
            else if(c == 'D') rope[0].first--;

            // cout << "BEFORE: ";
            // for(auto k: rope){
            //     cout << k << " | ";
            // }
            // cout << '\n';
            for(int k = 1; k < 10; ++k){
                int ih = rope[k-1].first, jh = rope[k-1].second, it = rope[k].first, jt = rope[k].second;
                if(!isTouch(ih, jh, it, jt)){
                    // cout << "not touching\n";
                    int j = jh - jt;
                    int i = ih - it;
                    if(abs(j) > 1) j/=2;
                    if(abs(i) > 1) i/=2;
    
                    rope[k].first+=i;
                    rope[k].second+=j;
                }
            }
            int it = rope[9].first, jt = rope[9].second;
            vvb[it][jt] = true;

            // cout << "AFTER: ";
            // for(auto k: rope){
            //     cout << k << " | ";
            // }
            // cout << '\n';
            // for(int i = 0; i < tt; ++i){
            //     for(int j = 0; j < tt; ++j){
            //         if(vvb[i][j]){
            //             cout << '#';
            //         }
            //         else cout << '.';
            //     }
            //     cout << '\n';
            // }
            // cout << "\n";
        }
        //cout << "=============================\n";
    }

    cout << "here\n";
    int cnt = 0;
    for(int i = 0; i < tt; ++i){
        for(int j = 0; j < tt; ++j){
            if(vvb[i][j]){
                ++cnt;
                //cout << '#';
            }
            //else cout << '.';
        }
        //cout << '\n';
    }

    cout << cnt << '\n';
}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    cout.flush();
    
    return 0;
}