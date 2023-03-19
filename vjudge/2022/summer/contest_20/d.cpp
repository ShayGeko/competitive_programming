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

typedef struct {
    long double x, y, z;
} point_t;

istream &operator >> (istream& is, point_t &p){
    cin >> p.x >> p.y >> p.z;
    return is;
}
const int maxn = 1e5;
const int INF = 2e9;
const long double LD_INF = INFINITY;
const int p = 1e9+7;
void solve(){
    int n;
    long double d;
    cin >> n >> d;

    vector<pair<point_t, point_t>> ufo(n);

    for(int i = 0; i < n; ++i) cin >> ufo[i].first >> ufo[i].second;

    long double t_min = LD_INF;
    bool alarm = false;
    pii collision; 
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            vector<long double> dif = {
                ufo[i].first.x - ufo[j].first.x,
                ufo[i].first.y - ufo[j].first.y,
                ufo[i].first.z - ufo[j].first.z };
            vector<long double> difv = {
                ufo[i].second.x - ufo[j].second.x,
                ufo[i].second.y - ufo[j].second.y,
                ufo[i].second.z - ufo[j].second.z };

            long double a = 0,b = 0, c = 0;
            
            for(auto df : dif) c += df*df;
            c-= d*d;

            for(int i = 0; i < 3; ++i){
                b+= dif[i] * difv[i];
            }
            b*=2;

            for(auto dfv : difv) a += dfv*dfv;

            long double t;

            if(a == 0 && b == 0) continue;
            else if(a == 0) t = -c / b;
            else if (b*b - 4 * a * c < 0) continue;
            else {
                long double t1 = (-b - sqrt(b*b - 4 * a * c)) / (2. * a);
                long double t2 = (-b + sqrt(b*b - 4 * a * c)) / (2. * a);

                if(t2 < t1) swap(t1, t2);

                if(t1 > 0) t = t1;
                else t = t2;
            }

            if(t > 0. && t < t_min){
                collision = {i+1,j+1};
                t_min = t;
                alarm = true;
            }
        }
    }

    if(alarm){
        cout << "ALARM!\n";
        cout << fixed << setprecision(3) << t_min <<  " " << collision.first << " " << collision.second << '\n';
    }
    else cout << "OK\n";

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