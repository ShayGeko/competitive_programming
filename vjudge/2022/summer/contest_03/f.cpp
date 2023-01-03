#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
typedef struct point{
    int b;
    int n;
    point(){};
    point (string s){
        b = 0;
        n = 0;
        for(auto c : s){
            if(c == 'B') ++ b;
            else if(c == 'N') ++n;
        }
    }
    point (int x, int y){
        b = x;
        y = n;
    }
    int dist(point a){
        return max(abs(a.b - b), abs(a.n - n));
    }
} point_t;
ostream& operator<<(ostream& os, const point_t& p){
    os << '(' << p.b << ", " << p.n << ')';
    return os;
}
vector<point_t> points;
int f(point_t &x){
    int maxi = -1;
    for(auto &p : points){
        maxi = max(maxi, x.dist(p));
    }
    return maxi;
}
int double_ternary(int b0, int b1, int n0, int n1){
    int bmid =  
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    points.resize(n);
    string str;
    for(int i = 0; i < n; ++i){
        cin >> str;
        points[i] = point_t(str);
        cout << points[i] << '\n';
    }
    return 0;
}