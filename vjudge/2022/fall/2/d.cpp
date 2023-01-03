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

vi nextplayer;

void make_set(int v){
    nextplayer[v] = -1;
}
int find(int v){
    if(nextplayer[v] == -1) return v;

    return nextplayer[v] = find(nextplayer[v]);
}
void unite(int a, int b){
    a = find(a);
    b = find(b);

    nextplayer[a] = b;
}

void solve(){
    int n, d, e;
    cin >> n >> e >> d;

    vi defuse(d);
    vi expl(e);
     for(int i = 0; i < e; ++i){
        cin >> expl[i];
    }
    for(int i = 0; i < d; ++i){
        cin >> defuse[i];
    }

    int ce = 0, cd = 0;

    int cnt = n;

    vi saves(n, 0);
    nextplayer.resize(n, 0);
    for(int i = 0; i < n; ++i) make_set(i);
    while(cnt > 1 && ce < e){
        if(cd >= d || defuse[cd] > expl[ce]){
            int player = find(expl[ce] % cnt);

            if(saves[player]) saves[player]--;
            else{
                cnt--;
                unite(player, (player + 1) % n);

                cout << "DEBUG | " << "Player #" << player << " exploded\n";
                cout << "DEBUG | nextplayer: ";
                for(auto np : nextplayer){
                    cout << np << " ";
                }
                cout << '\n';

                
                ce++;
            }
        }
        else{
            int player = find(defuse[cd] % cnt);
            saves[player] = min(5, saves[player] + 1);
            cd++;
        }
    }

    if(cnt == 1) cout << find(0) << endl;
    else cout << "-1" << endl;

}
int main(){
    int t = 1;

    // cin >> t;
    
    while(t--){
        solve();
    }
    return 0;
}