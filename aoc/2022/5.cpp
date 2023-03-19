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
    vector<string> ss;

    string s;
    while(cin.peek() == '[' || cin.peek() == ' '){
        getline(cin, s);

        ss.push_back(s);
    }

    string nums = ss.back();
    ss.pop_back();

    stringstream sin (nums);
    int a;
    while(sin >> a){}

    cout << a << '\n';
    char c1,c2,c3;

    vector<vector<char>> vcc(a, vector<char>());
    for(int i = ss.size() - 1; i >= 0; i--){
        string str = ss[i];
        for(int j = 0;  j < a; ++j){
            int k = 4*j;
            char c = str[k + 1];
            if(c != ' '){
                vcc[j].push_back(c);
            }
        }
    }


    for(auto vc : vcc){
        for(auto c : vc){
            cout << c << " ";
        }
        cout << '\n';
    }
    int cnt, from, to;

    while(cin >> s){
        cin >> cnt >> s >> from >> s >> to;

        vector<char> t;
        for(int i = 0; i < cnt; ++i){
            t.push_back(vcc[from-1].back());
            vcc[from-1].pop_back();
        }
        while(t.size()){
            vcc[to-1].push_back(t.back());
            t.pop_back();
        }
    }

    for(auto vc : vcc){
        cout << vc.back();
    }
    cout << '\n';
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