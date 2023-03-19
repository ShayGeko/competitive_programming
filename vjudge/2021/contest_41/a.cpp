#include <bits/stdc++.h>

using namespace std;
# define M_PI           3.14159265358979323846
const int maxn = 1e5;
const int INF = 1e9;
double px, py;
double x[maxn], y[maxn];
double d_s(double x, double y){
    return x*x + y*y;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    cin >> px >> py;
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
        x[i] -= px;
        y[i] -= py;
    }
    double mi, ma;
    mi = ma = d_s(x[0], y[0]);
    for(int i = 1 ; i< n; ++i){
        mi = min(mi, d_s(x[i], y[i]));
        ma = max(ma, d_s(x[i], y[i]));
    }
    cout << fixed << setprecision(10) << M_PI * (ma - mi) << '\n';
    return 0;
}