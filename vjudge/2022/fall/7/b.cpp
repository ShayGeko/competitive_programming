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

string instructions[3] = {"Forward", "Left", "Right"};

pii dest;
bool solve_path(vector<string> instr){
    pii cur = {0, 0};
    int dir = 0;

    for(auto in : instr){
        if(in == "Left") dir = (dir + 4 - 1) % 4;
        else if (in == "Right") dir = (dir + 1) % 4;
        else{
            switch(dir){
                case 0: cur.second +=1;
                break;
                case 1: cur.first+=1;
                break;
                case 2: cur.second-=1;
                break;
                case 3: cur.first-=1;
                default:;
            }
        }
        // cout << "DEBUG| " << cur.first << " " << cur.second << '\n';
    }

    // cout << cur.first << " " << cur.second << '\n';
    return cur == dest;
}
void solve(){
    cin >> dest.first >> dest.second;
    int t;
    cin >> t;

    vector<string> instr(t);
    for(int i = 0; i < t; ++i) cin >> instr[i];

    // cout << solve_path(instr) << '\n';

    for(int i = 0; i < t; ++i){
        string temp = instr[i];
        for(int j = 0; j < 3; ++j){
            instr[i] = instructions[j];
            if(solve_path(instr)){
                cout << i + 1 << " " << instr[i] << '\n';
                return;
            }
        }
        instr[i] = temp;
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