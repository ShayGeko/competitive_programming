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

void solve(){
    string s;
    int a;

    char c;
    int i = 0;
    string s1,s2;
    vector<vll> items;
    vi divisible;
    
    vpii conditions;
    vector<vector<string>> op;
    stringstream sin;

    vll cnt;
    while(true){
        getline(cin, s);
        if(s == "") break;

        sin = stringstream(s);
        items.push_back(vll());
        cnt.push_back(0);
        sin >> s >>a >> c;
        cout << s << " " << a << c << '\n';

        getline(cin, s1);
        cout << s1 << '\n';
        sin = stringstream(s1);
        sin >> s >> s;

        cout << s << '\n';
        while(sin >> a){
            sin >> c;
            items.back().push_back(a);
            cout << a << " ";
        
        }
        cout << '\n';

        //operation
        string s2;
        getline(cin, s);
        sin = stringstream(s);
        sin >> s >> s >> s;
        sin >> s >> s1 >> s2;
        
        op.push_back({s, s1, s2});

        for(int i = 0; i < 3; ++i){
            cout << op.back()[i] << " ";
        }
        cout << '\n';

        // divisible
        
        getline(cin, s);
        sin = stringstream(s);
        sin >> s >> s >> s >> a;
        divisible.push_back(a);
        cout << a << '\n';

        conditions.push_back({0,0});

        getline(cin, s);
        sin = stringstream(s);
        sin >> s >> s >> s >> s >> s >> a;
        cout << s << " " << a << '\n';
        conditions.back().first=a;

        getline(cin, s);
        sin = stringstream(s);
        sin >> s >> s >> s >> s >> s >> a;
        cout << s << " " << a << '\n';
        conditions.back().second=a;

        cout << conditions.back() << '\n';

        getline(cin, s);
    }

    cout << "here\n";
    for(int t = 0; t < 2; ++t){
        cout << "round " << t << '\n';
        for(int i = 0; i < items.size(); ++i){
            cout << "   monkey " << i << '\n';
            for(auto it : items[i]){
                cnt[i]++;
                int a = it, b = it;
                if(op[i][0] != "old") a = stoi(op[i][0]);
                if(op[i][2] != "old") b = stoi(op[i][2]);


                ll worry = a;
                if(op[i][1] == "*"){
                    worry *= b;
                }
                else worry += b;

                // cout << "new worry 1: " << worry << '\n';
                worry /= 3;
                // cout << "new worry 2: " << worry << '\n';

                if(worry % divisible[i] == 0){
                    cout << "true ";
                    items[conditions[i].first].push_back(worry);
                }
                else {
                    cout << "false ";
                    items[conditions[i].second].push_back(worry);
                }
            }
            items[i].clear();
            cout << '\n';
        }
        for(auto item : items){
            cout << "size: " << item.size() << '\n';
            for(auto it: item){
                cout << it << " ";
            }
            cout << '\n';
        }
        cout << "-----------------------------\n";
    }
    
    for(auto k : cnt){
        cout << k << '\n';
    }
    sort(cnt.rbegin(), cnt.rend());

    cout << (ll) cnt[0] * cnt[1] << '\n';

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