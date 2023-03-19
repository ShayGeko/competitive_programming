#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;

double d[maxn], a[maxn];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    double sum = 0;
    double l = 0;
    for(int i = 0; i < n; ++i){
        cin >> d[i] >> a[i];
        sum += d[i] * (-a[i]);
        l += d[i];
    }
    double a_tot = sum / l;
    double v = sqrt(2 * sum);
    if(fabs(a_tot) < 0.000001) v = 0.000000001;
    double t = v / a_tot;
    if( <= 0)
    cout << fixed << setprecision(6) << l << " " << a_tot << " " << sum << " " << v << " " << t << '\n';

    return 0;
}