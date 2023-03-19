#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define has(a, b) (a.find(b) != a.end())
#define imin(a, b) a = min(a, b)
#define imax(a, b) a = max(a, b)

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define fora(i, n) for(int i = 0; i < n; i++)
#define forb(i, n) for(int i = 1; i <= n; i++)
#define forc(a, b) for(const auto &a : b)
#define ford(i, n) for(int i = n; i >= 0; i--)


typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

istream &operator >> (istream& is, pii &p){
    is >> p.first >> p.second;
    return is;
}
ostream &operator << (ostream& os, pii &p){
    os << p.first << " " << p.second;
    return os;
}
template <class T>
ostream &operator << (ostream& os, vector<T> &p){
    for(auto t : p){
        os << t << " ";
    }
    return os;
}
template <class T>
pair<T, T> operator + (pair<T,T> &a, pair<T,T> &b){
    return {a.first + b.first, a.second + b.second};
}

template <class T>
pair<T, T> operator - (pair<T,T> &a, pair<T,T> &b){
    return {a.first - b.first, a.second - b.second};
}

const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;


// dp[cur][mask][time]
unordered_map<string, vvi> dp;
void solve1(){

    string s;
    map<string, int> flowRates;
    map<string, set<string>> tunnelMap;
    int cnt = 0;
    int cnt1 = 0;
    vector<string> goodValves;
    vector<string> allValves;
    while(true){
        getline(cin, s);
        if(s == "") break;
        stringstream sin(s);

        string valveName;
        int flowRate;

        string temp;
        sin.ignore(256, ' ');
        sin >> valveName;
        sin.ignore(256,  '=');
        sin >> flowRate;

        cout << valveName << " " << flowRate << '\n';

        sin >> temp >> temp >> temp >> temp >> temp;

        set<string> tunnels; 
        char c1, c2;
        while(sin >> c1){
            sin >> c2;
            string s1 = "";
            s1 += c1;
            s1 += c2;
            tunnels.insert(s1);
            sin.ignore(1);
        }
        tunnelMap[valveName] = tunnels;

        // cout << tunnels << '\n';
        cnt ++;

        allValves.push_back(valveName);
        if(flowRate){
            goodValves.push_back(valveName);
            flowRates[valveName] = flowRate;
            cnt1++;
        }
    }

    cout << "lox1\n";
    sort(all(goodValves));

    int n = goodValves.size();
    int m = (1 << n);

    cout << n << " " << m << '\n';
    vi tflow(m, 0);

    rep(i, 0, m){
        rep(j, 0, n){
            int bit = 1<<j;
            if(i & bit)tflow[i]+=flowRates[goodValves[j]];
        }
    }

    
    rep(j, 0, n){
        cout << goodValves[j] << " : " <<  tflow[1<<j] << '\n';   
    }
    for(int i = 0; i < 10; ++i){
        cout << tflow[i] << " ";
    }
    cout << '\n';
    string start = "AA";

    // int start =
    
    cout << "lox2\n";
    for(auto v : allValves){
        dp[v] = vvi(m, vi(30, -INF));
    }
    dp["AA"][0][0] = 0;

    unordered_map<string, unordered_map<string, int>> dist;

    cout << "lox3\n";
    for(auto from : allValves){
        for(auto to : allValves){
            if(from == to) dist[from][to] = 0;
            else if(tunnelMap[from].count(to) == 1){
                dist[from][to] = 1;
            }
            else dist[from][to] = INF;
        }
    }

    cout << " \\ ";
    for(auto v : goodValves){
        cout << v << " ";
    }
    cout << '\n';
    for(auto from : goodValves){
        cout << from << " ";
        for(auto to : goodValves){
            cout << setw(2) << ((dist[from][to] == INF)? 99 : dist[from][to]) << " ";
        }
        cout << '\n';
    }

    cout << "lox4\n";
    for(auto k : allValves){
        for(auto i : allValves){
            for(auto j : allValves){
                if(dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout << " \\ ";
    for(auto v : goodValves){
        cout << v << " ";
    }
    cout << '\n';
    for(auto from : goodValves){
        cout << from << " ";
        for(auto to : goodValves){
            cout << setw(2) << ((dist[from][to] == INF)? 99 : dist[from][to]) << " ";
        }
        cout << '\n';
    }


    /////////////////////////////////////////// DP //////////////////////////////////
    cout << "lox5\n";
    rep(cur, 0, sz(goodValves)){
        string to = goodValves[cur];
        dp[to][1<<cur][dist["AA"][to]] = 0;
    }

    fora(t, 10){
        fora(i, sz(goodValves)){
            string v = goodValves[i];
            int k = dp[v][1 << i][t];
            cout << setw(2) << (k >= 0? k : 99) << " ";
        }
        cout << '\n';
    }
    cout << "lox\n";
    rep(t, 0, 30) rep(mask, 0, m)  rep(i, 0, sz(goodValves)){
        string from = goodValves[i];
        if(dp[from][mask][t] >= 0){
            
            imax(dp[from][mask][t+1], dp[from][mask][t] + tflow[mask]);

            rep(j, 0, sz(goodValves)){
                string to = goodValves[j];
                int bit = 1<<j;

                // if valve is already on skip
                if(mask & bit)continue;

                // if can get there only after 30 mins skip
                if(t + dist[from][to] >= 30) continue;

                dp[to][mask|bit][t + dist[from][to]] = max(
                    dp[to][mask|bit][t + dist[from][to]],
                    dp[from][mask][t] + dist[from][to]*tflow[mask]);
            }
        }
    }

    cout << "loxend\n";
    int maxi = 0;
    string cur;
    rep(mask, 0, m){
        rep(i, 0, sz(goodValves)){
            string from = goodValves[i];
            if(maxi < dp[from][mask][29]){
                cur = from;
                maxi = dp[from][mask][29];
            }
        }
    }
    int t = 29;

    vector<string> path;
    while(t >= 0){

    }   

    cout << maxi << '\n';
}
void solve2(){

}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    solve1();
    //solve2();


    cout.flush();
    return 0;
}