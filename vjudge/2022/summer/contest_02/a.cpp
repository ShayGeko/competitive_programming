#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
const int INF = 1e9;
const int P = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    double c;
    int l;
    double cost = 0;
    cin >> c;
    cin >> l;
    double a, b;
    for(int i = 0; i < l; ++i){
        cin >> a >> b;
        cost += c * a * b;
    }
    cout << fixed << setprecision(6) << cost << '\n';
    return 0;
}