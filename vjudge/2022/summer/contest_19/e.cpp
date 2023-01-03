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
    int x;
    int y;
    int pos; 
} point_t;


const int maxn = 1e5;
const int INF = 2e9;
const int p = 1e9+7;
const long double PI = acos(-1);

long double angle_clockwise(point_t &a){
    long double angle = atan2(a.y, a.x);

    if(angle >= 0) return angle;
    else return angle + 2 * PI;
}
long double non_oriented_angle(point_t &a, point_t &b){
        long double cur = angle_clockwise(b) - angle_clockwise(a);
        if(cur < 0) cur = -cur;
        if(cur > PI) cur = 2*PI - cur;

        return cur;
}
void solve(){
    int n;
    cin >> n;

    vector<point_t> points(n);

    for(int i = 0; i < n; ++i){
        cin >> points[i].x >> points[i].y;
        points[i].pos = i + 1;
    }

    // lambdas in c++ rock!
    // sort points by polar angle
    sort(points.begin(), points.end(), [](point_t a, point_t b){ return angle_clockwise(a) < angle_clockwise(b);});

    long double mini = non_oriented_angle(points[n-1], points[0]);
    int best_i = 0;
    for(int i = 1; i < n; ++i){
        long double cur = non_oriented_angle(points[i], points[i - 1]);

        if(cur < mini){
            best_i = i;
            mini = cur;
        }
    }

    int a = best_i - 1, b = best_i;
    if(best_i == 0){
        a+=n;
    }

    cout << points[a].pos << " " << points[b].pos << '\n';

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